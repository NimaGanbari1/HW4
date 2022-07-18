#ifndef BANK_H
#define BANK_H
#include <vector>
#include <iostream>
#include "CUSTOMER.h"
#include "ACCOUNT.h"
#include "MANAGER.h"
#include "EMPLOYEE.h"
using namespace std;
class bank
{
private:
    vector<customer *> customer1;
    vector<employee *> employee1;
    vector<Account *> Account1;
    string branch_name;
    int branch_code;
    manager *managerr;
    vector<string> report;

public:
    friend class employee;
    friend class manager;
    friend class customer;
    void find_manager(bank *);
    employee *temp_mainly_1(bank &, string, string);
    bank(string, int, vector<customer *>, vector<employee *>, vector<Account *>);
    customer *temp_mainly_2(bank &, string, string);
    manager *temp_mainly_1_man(bank &, string, string);
    void temp_in_Full_view1(int);
    int find_custumer_Full_view1(int size);
    int temp_in_create();
    int temp_in_delete();
    void temp_push_back();
    void temp_push_back_acc(int temp);
    void temp_pop_back_acc(int);
    int find_employee(int);
    void temp_disply_info_emp(int);
    int temp_increace(int);
    void temp_inc_salary(int);
    void temp_dec_salary(int);
    void disply_info_accc(long long int);
    void temp_change_state();
    void set_report();
    long long int get_national_code(int);
    long long int get_national_code_emp(int);
    void report_temp_pop_back_acc(long long int);
    void report_temp_pop_back_acc1(long long int);
    void report_Adding_an_employee1();
    void report_change_state(long long int);
    void report_change_state1(long long int);
    void report_Increase_account_balance1(long long int, long long int);
    void report_decrease_account_balance1(long long int, long long int);
    void report_disply_info_accc(long long int);
    // void find_man();
    void exercise();

protected:
};
#endif