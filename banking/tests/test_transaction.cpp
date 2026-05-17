#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Transaction.h"
#include "mocks/MockAccount.hpp"
#include "mocks/MockTransaction.hpp"

using ::testing::_;
using ::testing::Return;
using ::testing::Throw;

// Попытка перевода на тот же счёт
TEST(TransactionTest, SameAccountThrows) {
    MockAccount acc(1, 1000);
    Transaction tx;
    EXPECT_THROW(tx.Make(acc, acc, 200), std::logic_error);
}

// Отрицательная сумма
TEST(TransactionTest, NegativeSumThrows) {
    MockAccount from(1, 1000);
    MockAccount to(2, 500);
    Transaction tx;
    EXPECT_THROW(tx.Make(from, to, -100), std::invalid_argument);
}

// Сумма меньше 100
TEST(TransactionTest, SumTooSmallThrows) {
    MockAccount from(1, 1000);
    MockAccount to(2, 500);
    Transaction tx;
    EXPECT_THROW(tx.Make(from, to, 50), std::logic_error);
}

// Комиссия слишком большая
TEST(TransactionTest, FeeTooLargeReturnsFalse) {
    MockAccount from(1, 1000);
    MockAccount to(2, 500);
    Transaction tx;
    tx.set_fee(100);
    EXPECT_CALL(from, GetBalance()).WillOnce(Return(1000));
    EXPECT_FALSE(tx.Make(from, to, 150));
}

// Успешный перевод
TEST(TransactionTest, SuccessfulTransfer) {
    MockAccount from(1, 1000);
    MockAccount to(2, 500);
    Transaction tx;
    tx.set_fee(1);

    EXPECT_CALL(from, Lock()).Times(1);
    EXPECT_CALL(to, Lock()).Times(1);
    EXPECT_CALL(to, ChangeBalance(200)).Times(1);
    EXPECT_CALL(from, GetBalance()).WillOnce(Return(1000));
    EXPECT_CALL(from, ChangeBalance(-201)).Times(1);
    EXPECT_CALL(from, Unlock()).Times(1);
    EXPECT_CALL(to, Unlock()).Times(1);

    EXPECT_TRUE(tx.Make(from, to, 200));
}

// Недостаточно средств - проверка ДО блокировки
TEST(TransactionTest, InsufficientFunds) {
    MockAccount from(1, 100);
    MockAccount to(2, 500);
    Transaction tx;
    tx.set_fee(1);

    // Ожидаем только вызов GetBalance для проверки
    EXPECT_CALL(from, GetBalance()).WillOnce(Return(100));
    
    // Блокировки и изменения НЕ должны вызываться
    EXPECT_CALL(from, Lock()).Times(0);
    EXPECT_CALL(to, Lock()).Times(0);
    EXPECT_CALL(to, ChangeBalance(_)).Times(0);
    EXPECT_CALL(from, ChangeBalance(_)).Times(0);
    EXPECT_CALL(from, Unlock()).Times(0);
    EXPECT_CALL(to, Unlock()).Times(0);

    EXPECT_FALSE(tx.Make(from, to, 150));
}

// Проверка вызова SaveToDataBase
TEST(TransactionTest, SaveToDataBaseIsCalled) {
    MockAccount from(1, 1000);
    MockAccount to(2, 500);
    MockTransaction tx;
    tx.set_fee(1);

    EXPECT_CALL(from, Lock()).Times(1);
    EXPECT_CALL(to, Lock()).Times(1);
    EXPECT_CALL(to, ChangeBalance(200)).Times(1);
    EXPECT_CALL(from, GetBalance()).WillOnce(Return(1000));
    EXPECT_CALL(from, ChangeBalance(-201)).Times(1);
    EXPECT_CALL(tx, SaveToDataBase(_, _, 200)).Times(1);
    EXPECT_CALL(from, Unlock()).Times(1);
    EXPECT_CALL(to, Unlock()).Times(1);

    EXPECT_TRUE(tx.Make(from, to, 200));
}

// Тест для покрытия catch блока
TEST(TransactionTest, ExceptionDuringChangeBalanceTriggersRollback) {
    MockAccount from(1, 1000);
    MockAccount to(2, 500);
    Transaction tx;
    tx.set_fee(1);

    EXPECT_CALL(from, Lock()).Times(1);
    EXPECT_CALL(to, Lock()).Times(1);
    EXPECT_CALL(to, ChangeBalance(200)).Times(1);
    EXPECT_CALL(from, GetBalance()).WillOnce(Return(1000));
    EXPECT_CALL(from, ChangeBalance(-201)).WillOnce(Throw(std::runtime_error("Test error")));
    EXPECT_CALL(to, ChangeBalance(-200)).Times(1);
    EXPECT_CALL(from, Unlock()).Times(1);
    EXPECT_CALL(to, Unlock()).Times(1);

    EXPECT_THROW(tx.Make(from, to, 200), std::runtime_error);
}
