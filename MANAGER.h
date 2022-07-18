#ifndef MANAGER_H
#define MANAGER_H
using namespace std;
#include "EMPLOYEE.h"
#include "BANK.h"
#include <iostream>
class manager : private employee
{
private:
public:
    friend class bank;
    manager(string, string, long long int, int, int, int, string, string, int, long long int, bank *);
    void Request_leave_man1(manager *&);
    void Request_for_overtime_man1(manager *&);
    void Display_personal_information_man1(manager *&);
    void Full_view_man1(manager *&);
    void Create_an_account_man1(manager *&);
    void Delete_a_customer_man1(manager *&);
    void Display_employee_information_mna1(manager *&);
    void Adding_an_employee1(manager *&);
    void Remove_an_employee_man1(manager *&);
    void change_state_man1(manager *&);
    void report_login_manager();
    void report_temp_disply_info_emp(long long int);
    void report_Create_an_account1(long long int);
    void report_Remove_an_employee_man1(int);
    ~manager();

protected:
};
#endif