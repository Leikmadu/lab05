#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "Account.h"

class Transaction {
public:
    Transaction();
    virtual ~Transaction() = default;
    
    bool Make(Account& from, Account& to, int sum);
    void set_fee(int fee);
    
protected:
    virtual void SaveToDataBase(Account& from, Account& to, int sum);
    
private:
    int fee_;
};

#endif
