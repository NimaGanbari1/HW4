#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "PERSON.h"
#include "BANK.h"
#include <iostream>
using namespace std;
class customer : private person
{
private:
public:
    friend class bank;
    customer(string, string, long long int, int, int, int, string, string, bank *);
    void Increase_account_balance1();
    void withdraw_from_bank_account1();
    void Show_information1();
    void displ();
    void report_login_customer();
    void report_displ(long long int);
    ~customer();

protected:
    // vector<Account *> Account1;
    bank *bankk;
};
#endif