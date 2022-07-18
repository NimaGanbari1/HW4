#ifndef ACCOUNT_H
#define ACCOUNT_H
using namespace std;
//#include "BANK.h"
class Account
{
private:
    long long int accont_number_ac;
    long long int national_code_ac;
    int day_ac;
    int month_ac;
    int year_ac;
    long long int balance_ac;
    bool check_ac;

protected:
public:
    friend class bank;
    Account(long long int, long long int, int, int, int, long long int, bool);
    bool check_state();
};
#endif
