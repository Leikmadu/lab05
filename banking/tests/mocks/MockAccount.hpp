#ifndef MOCK_ACCOUNT_HPP
#define MOCK_ACCOUNT_HPP

#include "Account.h"
#include <gmock/gmock.h>

class MockAccount : public Account {
public:
    MockAccount(int id, int balance) : Account(id, balance) {}
    
    // Новый синтаксис MOCK_METHOD для Google Mock 1.12+
    MOCK_METHOD(int, GetBalance, (), (const));
    MOCK_METHOD(void, ChangeBalance, (int diff));
    MOCK_METHOD(void, Lock, ());
    MOCK_METHOD(void, Unlock, ());
};

#endif
