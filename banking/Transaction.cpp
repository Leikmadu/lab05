#include "Transaction.h"
#include <iostream>
#include <stdexcept>

Transaction::Transaction() : fee_(1) {}

void Transaction::set_fee(int fee) {
    fee_ = fee;
}

bool Transaction::Make(Account& from, Account& to, int sum) {
    if (from.id() == to.id()) {
        throw std::logic_error("Cannot transfer to same account");
    }
    
    if (sum < 0) {
        throw std::invalid_argument("Sum cannot be negative");
    }
    
    if (sum < 100) {
        throw std::logic_error("Sum is too small (min 100)");
    }
    
    int total = sum + fee_;
    if (total > from.GetBalance()) {
        return false;
    }
    
    if (2 * fee_ > sum) {
        return false;
    }
    
    try {
        from.Lock();
        to.Lock();
        
        to.ChangeBalance(sum);
        from.ChangeBalance(-total);
        
        SaveToDataBase(from, to, sum);
        
        from.Unlock();
        to.Unlock();
        
        std::cout << from.id() << " send to " << to.id() << " $" << sum << std::endl;
        return true;
        
    } catch (...) {
        to.ChangeBalance(-sum);
        from.Unlock();
        to.Unlock();
        throw;
    }
}

void Transaction::SaveToDataBase(Account& from, Account& to, int sum) {
    std::cout << "Transaction saved: " << from.id() << " -> " << to.id() << " " << sum << std::endl;
}
