#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "PERSON.h"
#include "BANK.h"
#include <iostream>
using namespace std;
class employee : protected person
{
private:
public:
    friend class bank;
    employee(string, string, long long int, int, int, int, string, string, int, long long int, bank *);
    void Request_leave1(employee *&);
    void Request_for_overtime1(employee *&);
    void Display_personal_information1();
    void Full_view1(employee *&);
    void Create_an_account1(employee *&);
    void Delete_a_customer1(employee *&);
    void change_state1(employee *&);
    void report_login_employee();
    void report_Request_leave1_employee(int);
    void report_Request_for_overtime_employee(int);
    void report_Display_personal_information_employee();
    void report_Full_view(bank *, int);
    void report_Create_an_account(int);
    void report_Create_an_account();
    ~employee();

protected:
    int id_code;
    long long int basic_salary;
    int vacation_hour = 0;
    int overtime_hour = 0;
    bank *bankk = NULL;
};
#endif