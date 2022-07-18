#include <iostream>
#include <vector>
#include <conio.h>
#include <fstream>
#include <ctime>
#include "ERROR.h"
#include "PERSON.h"
//#include "CUSTOMER.h"
#include "ACCOUNT.h"
//#include "EMPLOYEE.h"
//#include "MANAGER.h"
//#include "BANK.h"
using namespace std;

class bank;
///////////////////////////////////
// class error

error::error(string mes)
{
    errormessage = mes;
}
void error::print()
{
    cout << "ERROR: " << errormessage << '\n';
}
//////////////////////////////////
// class person

person::person(string first_name1, string last_name1, long long int national_code1, int day1, int mounth1, int year1, string user_name1, string password1)
{
    int temp = 0;
    int temp1 = national_code1;
    // int temp2 = 0;
    while (temp1 != 0)
    {
        temp1 /= 10;
        ++temp;
    }
    cout << "1" << '\n';
    getch();
    // temp2 == cin.good();
    // bool temp3 = isdigit(national_code1);

    try
    {
        // if (temp3 == false)
        // {
        //     throw error("Invalid national code. ");
        // }

        if (temp != 10)
        {
            throw error("Invalid national code.(number) ");
        }

        if (first_name1.size() < 2)
        {
            throw error("Invalid first name. ");
        }
        if (last_name1.size() < 2)
        {
            throw error("Invalid last name. ");
        }
        if (year1 < 1200)
        {
            throw error("Invalid year. ");
        }
        if (mounth1 <= 0 || mounth1 > 12)
        {
            throw error("Invalid month. ");
        }
        if (mounth1 > 0 && mounth1 <= 6)
        {
            if (day1 < 0 || day1 > 31)
            {
                throw error("Invalid day. ");
            }
        }
        if (mounth1 >= 7 && mounth1 <= 11)
        {
            if (day1 < 0 || day1 > 30)
            {
                throw error("Invalid day. ");
            }
        }
        if (mounth1 == 12)
        {
            if (day1 < 0 || day1 > 29)
            {
                throw error("Invalid day. ");
            }
        }
        if (password1.size() <= 7)
        {
            throw error("Invalid password.(Password number must be at least 8 characters.) ");
        }
    }
    catch (error e)
    {
        e.print();
        getch();
        return;
    }
    cout << "2" << '\n';
    getch();
    first_name = first_name1;
    last_name = last_name1;
    national_code = national_code1;
    day = day1;
    mounth = mounth1;
    year = year1;
    user_name = user_name1;
    password = password1;
    cout << "first: " << first_name << '\n';
    cout << "user: " << user_name << '\n';
    cout << "pass: " << password << '\n';
    cout << "3" << '\n';
    getch();
}
person::~person()
{
    delete this;
}
//////////////////////////////////
// class customer
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
customer::customer(string first_name1, string last_name1, long long int national_code1, int day1, int mounth1, int year1, string user_name1, string password1, bank *bank1) : person(first_name1, last_name1, national_code1, day1, mounth1, year1, user_name1, password1)
{
    bankk = bank1;
}
customer::~customer()
{
    delete this;
}
//////////////////////////////////
// class Account

Account::Account(long long int accont_number_ac1, long long int national_code_ac1, int day_ac1, int month_ac1, int year_ac1, long long int balance_ac1, bool check_ac1)
{
    int temp = 0;
    long long int temp1 = accont_number_ac1;
    for (int i = 0; temp1 != 0; i++)
    {
        temp1 /= 10;
        ++temp;
    }

    int temp2 = 0;
    long long int temp3 = national_code_ac1;
    for (int i = 0; temp3 != 0; i++)
    {
        temp3 /= 10;
        ++temp2;
    }

    try
    {
        if (temp != 16)
        {
            throw error("Account number is incorrect. ");
        }
        /*tekrari bodan check shavad*/
        if (temp2 != 10)
        {
            throw error("invalid national code. ");
        }
        if (year_ac1 < 1200)
        {
            throw error("Invalid year. ");
        }
        if (month_ac1 <= 0 || month_ac1 > 12)
        {
            throw error("Invalid month. ");
        }
        if (month_ac1 > 0 && month_ac1 <= 6)
        {
            if (day_ac1 < 0 || day_ac1 > 31)
            {
                throw error("Invalid day. ");
            }
        }
        if (month_ac1 >= 7 && month_ac1 <= 11)
        {
            if (day_ac1 < 0 || day_ac1 > 30)
            {
                throw error("Invalid day. ");
            }
        }
        if (month_ac1 == 12)
        {
            if (day_ac1 < 0 || day_ac1 > 29)
            {
                throw error("Invalid day. ");
            }
        }
        if (balance_ac1 < 500000)
        {
            throw error("The amount to open an account must be at least 500,000. ");
        }
    }
    catch (error e)
    {
        e.print();
        getch();
        return;
    }
    accont_number_ac = accont_number_ac1;
    national_code_ac = national_code_ac1;
    day_ac = day_ac1;
    month_ac = month_ac1;
    year_ac = year_ac1;
    balance_ac = balance_ac1;
    check_ac = check_ac1;
}
bool Account::check_state()
{
    return this->check_ac;
}
//////////////////////////////////
// class employee
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
employee::employee(string first_name1, string last_name1, long long int national_code1, int day1, int mounth1, int year1, string user_name1, string password1, int id_code1, long long int basic_salary1, bank *bank1) : person(first_name1, last_name1, national_code1, day1, mounth1, year1, user_name1, password1)
{
    cout << "4" << '\n';
    getch();
    int temp = 0;
    int temp1 = id_code1;
    for (; temp1 != 0;)
    {
        temp1 /= 10;
        ++temp;
    }
    cout << "5" << '\n';
    getch();
    try
    {
        cout << "6" << '\n';
        getch();
        if (temp != 3)
        {
            throw error("Employee personnel code is incorrect. ");
        }
        cout << "7" << '\n';
        getch();
        if (basic_salary1 < 0)
        {
            throw error("invalid basic salary. ");
        }
    }
    catch (error e)
    {
        cout << "8" << '\n';
        getch();
        e.print();
        getch();
        return;
    }
    cout << "9" << '\n';
    getch();
    id_code = id_code1;
    basic_salary = basic_salary1;
    vacation_hour = 0;
    overtime_hour = 0;
    bankk = bank1;
    cout << "10" << '\n';
    getch();
}
employee::~employee()
{
    delete this;
}
//////////////////////////////
// class manager
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
manager::manager(string first_name1, string last_name1, long long int national_code1, int day1, int mounth1, int year1, string user_name1, string password1, int id_code1, long long int basic_salary1, bank *bank1) : employee(first_name1, last_name1, national_code1, day1, mounth1, year1, user_name1, password1, id_code1, basic_salary1, bank1)
{
}
manager::~manager()
{
    delete this;
}
////////////////////////////////
// class bank
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
bank::bank(string branch_name1, int branch_code1, vector<customer *> customer2, vector<employee *> employee2, vector<Account *> Account2)
{
    customer1 = customer2;
    employee1 = employee2;
    Account1 = Account2;
    branch_name = branch_name1;
    branch_code = branch_code1;
    managerr = NULL;
}
long long int bank::get_national_code(int i)
{
    return customer1[i]->national_code;
}
long long int bank::get_national_code_emp(int i)
{
    return employee1[i]->national_code;
}
///////////////////////////////

// enums
enum princple
{
    emp = 1,
    cus,
    ext
};
enum emp
{
    Request_leave = 1,
    Request_for_overtime,
    Display_personal_information,
    Full_view,
    Create_an_account,
    Delete_a_customer,
    change_state,
    Exiting
};
enum man
{
    Request_leave_man = 1,
    Request_for_overtime_man,
    Display_personal_information_man,
    Full_view_man,
    Create_an_account_man,
    Delete_a_customer_man,
    Display_employee_information_mna,
    Adding_an_employee,
    Remove_an_employee_man,
    change_state_man,
    Exiting_man
};
enum cus
{
    Increase_account_balance = 1,
    withdraw_from_bank_account,
    Show_information,
    Quit
};
enum temp_in_show
{
    Display_personal = 1,
    Display_Account,
    quiting
};

void menu_princple();
void select(int, bank &);
void mainly_1(bank &);
void mainly_2(bank &);
void menu_employee();
void menu_manager();
void menu_customer();
void select_in_mainly_1_emp(employee *&, int);
void select_in_mainly_1_man(manager *&, int);
void select_in_mainly_2_cus(customer *&, int);
int main()
{
    vector<customer *> customer1;
    vector<employee *> employee1;
    vector<Account *> Account1;
    bank iran("center", 1234, customer1, employee1, Account1);
    // iran.find_man();
    iran.find_manager(&iran);
    int choice;
    iran.exercise();
    do
    {
        system("cls");
        menu_princple();
        cin >> choice;
        select(choice, iran);
    } while (choice != ext);

    return 0;
}
void bank::exercise()
{
    string temp = this->managerr->first_name;
    cout << "first: " << temp << '\n';
    long long int temp1 = this->managerr->basic_salary;
    cout << "salary: " << temp1 << '\n';
    string temp2 = this->managerr->last_name;
    cout << "last: " << temp2 << '\n';
    string temp3 = this->managerr->user_name;
    cout << "user: " << temp3 << '\n';
    string temp4 = this->managerr->password;
    cout << "pass: " << temp4 << '\n';
    getch();
}
void bank::find_manager(bank *ban)
{
    string first_name;
    string last_name;
    long long int national_code;
    int day;
    int mounth;
    int year;
    string user_name;
    string password;
    int id_code;
    long long int basic_salary;
    bank *bankk;
    cout << "Manager Information " << '\n'
         << '\n';
    // cin.ignore();
    cout << "First Name: ";
    cin >> first_name;
    cin.ignore();
    cout << "Last Name: ";
    cin >> last_name;
    cin.ignore();
    cout << "National Code: ";
    cin >> national_code;
    cin.ignore();
    cout << "Date of birth " << '\n';
    cout << "Day: ";
    cin >> day;
    cin.ignore();
    cout << "Month: ";
    cin >> mounth;
    cin.ignore();
    cout << "Year: ";
    cin >> year;
    cin.ignore();
    cout << "User Name: ";
    cin >> user_name;
    cin.ignore();
    cout << "Password: ";
    cin >> password;
    cin.ignore();
    cout << "Personal Code: ";
    cin >> id_code;
    cin.ignore();
    cout << "Basic Salary: ";
    cin >> basic_salary;
    cin.ignore();
    bankk = ban;
    ban->managerr = new manager(first_name, last_name, national_code, day, mounth, year, user_name, password, id_code, basic_salary, bankk);
}
void menu_princple()
{
    cout << "   in the name of GOD " << '\n'
         << '\n';
    cout << "1- employee " << '\n';
    cout << "2- customer " << '\n';
    cout << "3- Exit " << '\n'
         << '\n';
    cout << "your choice: ";
}
void select(int choice, bank &iran)
{
    switch (choice)
    {
    case 1:
        mainly_1(iran);
        break;
    case 2:
        mainly_2(iran);
        break;
    case 3:
        break;
    default:
        cout << "Input number is invalid. " << '\n';
        getch();
        break;
    }
}
//////////////
// login employee or manager
//////////////
void mainly_1(bank &iran)
{
    int temp;
    string user_name1;
    string password1;
    cout << "User name: ";
    cin >> user_name1;
    cout << "Password: ";
    cin >> password1;
    manager *man = iran.temp_mainly_1_man(iran, user_name1, password1);
    if (man != NULL)
    {
        man->report_login_manager();
        do
        {
            system("cls");
            menu_manager();
            cin >> temp;
            select_in_mainly_1_man(man, temp);
        } while (temp != Exiting_man);
        return;
    }

    employee *emp = iran.temp_mainly_1(iran, user_name1, password1);
    if (emp != NULL)
    {
        emp->report_login_employee();
        do
        {
            system("cls");
            menu_employee();
            cin >> temp;
            select_in_mainly_1_emp(emp, temp);
        } while (temp != Exiting);
        return;
    }

    if (emp == NULL)
    {
        cout << "No soft staff. " << '\n';
        getch();
        return;
    }
}
void manager::report_login_manager()
{
    ofstream myfstream("report.txt", ios::app);
    if (!myfstream)
    {
        cout << "The report file has not been opened to write the report in the login_manager function";
        getch();
        return;
    }
    time_t ttime = time(0);
    char *dt = ctime(&ttime);
    // string first = this->first_name;
    // string last = this->last_name;
    myfstream << this->first_name << " " << this->last_name << " (Manager) logged in on " << dt << '\n';
    myfstream.close();
}
void employee::report_login_employee()
{
    ofstream myfstream("report.txt", ios::app);
    if (!myfstream)
    {
        cout << "The report file has not been opened to write the report in the login_manager function";
        getch();
        return;
    }
    time_t ttime = time(0);
    char *dt = ctime(&ttime);
    // string first = this->first_name;
    // string last = this->last_name;
    myfstream << this->first_name << " " << this->last_name << " (Employee) whit national code: " << this->national_code << " logged in on " << dt << '\n';
    myfstream.close();
}
void menu_employee()
{
    system("cls");
    cout << "1-Request leave " << '\n';
    cout << "2-Request for overtime" << '\n';
    cout << "3-Display personal information" << '\n';
    cout << "4-Full view of a customer's information using the national number " << '\n';
    cout << "5-Create an account for a customer " << '\n';
    cout << "6-Delete a customer account " << '\n';
    cout << "7-Change state " << '\n';
    cout << "8-Exit" << '\n';
    cout << '\n';
    cout << "your choice: ";
}
void menu_manager()
{
    system("cls");
    cout << "1- Request leave " << '\n';
    cout << "2- Request for overtime" << '\n';
    cout << "3- Display personal information" << '\n';
    cout << "4- Full view of a customer's information using the national number " << '\n';
    cout << "5- Create an account for a customer " << '\n';
    cout << "6- Delete a customer account " << '\n';
    cout << "7- Display employee information based on personal code " << '\n';
    cout << "8- Adding an employee to the list of employees (hiring) " << '\n';
    cout << "9- Remove an employee from the list of employees (dismissal) " << '\n';
    cout << "10- Change State" << '\n';
    cout << "11- Exit" << '\n';
    cout << '\n';
    cout << "your choice: ";
}

manager *bank::temp_mainly_1_man(bank &iran, string user, string pass)
{
    cout << "12" << '\n';
    getch();
    string temp = iran.managerr->user_name;
    cout << temp << '\n';
    string temp2 = user;
    cout << temp2 << '\n';
    string temp1 = iran.managerr->password;
    cout << temp1 << '\n';
    string temp3 = pass;
    cout << temp3 << '\n';
    getch();
    if (iran.managerr->user_name == user && iran.managerr->password == pass)
    {
        cout << "13" << '\n';
        getch();
        return iran.managerr;
    }
    return NULL;
}
employee *bank::temp_mainly_1(bank &iran, string user, string pass)
{
    // search for find employee
    for (int i = 0; i < iran.employee1.size(); i++)
    {
        if (iran.employee1[i]->user_name == user && iran.employee1[i]->password == pass)
        {
            return iran.employee1[i];
        }
    }
    return NULL;
}
////////////
// employee
////////////
void select_in_mainly_1_emp(employee *&emp, int choice)
{
    switch (choice)
    {
    case Request_leave:
        emp->Request_leave1(emp);
        break;
    case Request_for_overtime:
        emp->Request_for_overtime1(emp);
        break;
    case Display_personal_information:
        emp->Display_personal_information1();
        break;
    case Full_view:
        emp->Full_view1(emp);
        break;
    case Create_an_account:
        emp->Create_an_account1(emp);
        break;
    case Delete_a_customer:
        emp->Delete_a_customer1(emp);
        break;
    case change_state:
        emp->change_state1(emp);
        break;
    case Exiting:
        break;
    default:
        cout << "Input number is invalid, please try again. ";
        getch();
        break;
    }
}
//
void employee::Request_leave1(employee *&emp1)
{
    system("cls");
    int temp;
    long long int temp3 = 0;
    cout << "Hours taken leave month: ";
    cout << emp1->vacation_hour << '\n';
    if (emp1->vacation_hour <= 15)
    {
        cout << "Remaining hours of leave per month: ";
        cout << 15 - emp1->vacation_hour << '\n';
    }

    cout << "How many hours of leave do you want? " << '\n';
    cout << "hours: ";
    cin >> temp;
    int temp1 = emp1->vacation_hour + temp;
    if (temp1 > 15)
    {
        int temp4 = temp - (15 - emp1->vacation_hour);
        emp1->vacation_hour = 15;

        cout << "The number of hours you request for leave this month is more than allowed (15 hours) " << '\n';
        for (int i = 0; i < temp4; ++i)
        {
            temp3 += 1000000;
            //--temp1;
        }
        emp1->basic_salary -= temp3;
        cout << "Salary received this month: ";
        cout << emp1->basic_salary << '\n';
        cout << "Remaining hours of leave per month: ";
        cout << 0 << '\n';
    }
    if (temp1 <= 15)
    {
        emp1->vacation_hour = temp + emp1->vacation_hour;
        cout << "Remaining hours of leave per month: ";
        cout << 15 - emp1->vacation_hour << '\n';
    }
    emp1->report_Request_leave1_employee(temp);
    cout << "mission accomplished. ";
    getch();
}
void employee::report_Request_leave1_employee(int temp)
{
    ofstream myfstream("report.txt", ios::app);
    if (!myfstream)
    {
        cout << "The report file has not been opened to write the report in the login_manager function";
        getch();
        return;
    }
    time_t ttime = time(0);
    char *dt = ctime(&ttime);
    // string first = this->first_name;
    // string last = this->last_name;
    myfstream << this->first_name << " " << this->last_name << " whit national code: " << this->national_code << " requested leave for " << temp << " hours on " << dt << '\n';
    myfstream.close();
}
//
void employee::Request_for_overtime1(employee *&emp1)
{
    int temp = emp1->overtime_hour;
    if (temp >= 12)
    {
        cout << "You may not register overtime (12 hours). " << '\n';
        getch();
        return;
    }
    int temp1 = 12 - emp1->overtime_hour;
    bool temp3 = false;
    int temp5;
    do
    {
        system("cls");
        cout << "Number of overtime hours this month: ";
        cout << emp1->overtime_hour << '\n';
        cout << "Number of overtime hours allowed this month: ";
        cout << temp1 << '\n';
        cout << "How many overtime hours do you want to register? " << '\n';
        cout << "hours: ";
        int temp2;
        cin.ignore();
        cin >> temp2;
        temp5 = temp2;
        int ins = emp1->overtime_hour + temp2;
        temp3 = false;
        if (ins > 12)
        {
            cout << "You may not register overtime (12 hours). " << '\n';
            getch();
            temp3 = true;
        }
        long long int temp4 = 0;
        if (ins <= 12)
        {
            while (temp2 != 0)
            {
                temp4 += 1200000;
                --temp2;
            }

            emp1->basic_salary += temp4;
            cout << "Salary received this month: ";
            cout << emp1->basic_salary << '\n';
            emp1->overtime_hour = ins;
        }
    } while (temp3 == true);
    emp1->report_Request_for_overtime_employee(temp5);
    cout << "mission accomplished. ";
    getch();
}
void employee::report_Request_for_overtime_employee(int temp)
{
    ofstream myfstream("report.txt", ios::app);
    if (!myfstream)
    {
        cout << "The report file has not been opened to write the report in the login_manager function";
        getch();
        return;
    }
    time_t ttime = time(0);
    char *dt = ctime(&ttime);
    // string first = this->first_name;
    // string last = this->last_name;
    myfstream << this->first_name << " " << this->last_name << " whit national code: " << this->national_code << " requested overtime for " << temp << " hours on " << dt << '\n';
    myfstream.close();
}
//
void employee::Display_personal_information1()
{
    cout << "personal information " << '\n'
         << '\n';
    cout << "First Name: " << this->first_name << '\n';
    cout << "Last Name: " << this->last_name << '\n';
    cout << "National Code: " << this->national_code << '\n';
    cout << "Date of Birth " << '\n';
    cout << "Day: " << this->day << '\n';
    cout << "Month: " << this->mounth << '\n';
    cout << "Year: " << this->year << '\n';
    cout << "Personnel Code: " << this->id_code << '\n';
    cout << "Vacation Hours: " << this->vacation_hour << '\n';
    cout << "Overtime Hours: " << this->overtime_hour << '\n';
    cout << "Basic Salary: " << this->basic_salary << '\n';
    cout << "User Name: " << this->user_name << '\n';
    cout << "Password: " << this->password << '\n';
    getch();
    this->report_Display_personal_information_employee();
}
void employee::report_Display_personal_information_employee()
{
    ofstream myfstream("report.txt", ios::app);
    if (!myfstream)
    {
        cout << "The report file has not been opened to write the report in the login_manager function";
        getch();
        return;
    }
    time_t ttime = time(0);
    char *dt = ctime(&ttime);
    // string first = this->first_name;
    // string last = this->last_name;
    myfstream << this->first_name << " " << this->last_name << " whit national code: " << this->national_code << " viewed his/her information on " << dt << '\n';
    myfstream.close();
}
//
void employee::Full_view1(employee *&emp1)
{

    int temp = emp1->bankk->customer1.size();
    int temp1 = emp1->bankk->find_custumer_Full_view1(temp);
    if (temp1 != -1)
    {
        emp1->bankk->temp_in_Full_view1(temp1);
        emp1->report_Full_view(emp1->bankk, temp1);
    }
    if (temp1 == -1)
    {
        cout << "Customer Not Found. " << '\n';
        getch();
        return;
    }
}
int bank::find_custumer_Full_view1(int size)
{
    long long int national;
    cout << "National Code: ";
    cin >> national;

    int i = 0;
    for (; i < size; i++)
    {
        if (this->customer1[i]->national_code == national)
        {
            return i;
        }
    }
    return -1;
}
void bank::temp_in_Full_view1(int i)
{
    system("cls");
    cout << "customer information " << '\n'
         << '\n';
    cout << "Name: " << this->customer1[i]->first_name << " " << this->customer1[i]->last_name << '\n';
    cout << "National Code: " << this->customer1[i]->national_code << '\n';
    cout << "Date Of Birth: " << this->customer1[i]->year << "/" << this->customer1[i]->mounth << "/" << this->customer1[i]->day << '\n';
    cout << "User Name: " << this->customer1[i]->user_name << '\n';
    cout << "Password: " << this->customer1[i]->password << '\n';
    int size_acc = this->Account1.size();
    for (int j = 0; j < size_acc; j++)
    {
        if (this->Account1[j]->national_code_ac == this->customer1[i]->national_code)
        {
            cout << "Account Informetion " << '\n'
                 << '\n';
            cout << "Account Number: " << this->Account1[j]->accont_number_ac << '\n';
            cout << "National Code: " << this->Account1[j]->national_code_ac << '\n';
            cout << "Account opening date " << '\n';
            cout << "Day: " << this->Account1[j]->day_ac << '\n';
            cout << "Month: " << this->Account1[j]->month_ac << '\n';
            cout << "Year: " << this->Account1[j]->year_ac << '\n';
            cout << "Balance: " << this->Account1[j]->balance_ac << '\n';
            cout << "State: " << this->Account1[j]->check_ac << '\n';
            cout << '\n'
                 << '\n';
        }
    }
    getch();
}
void employee::report_Full_view(bank *ban, int i)
{
    ofstream myfstream("report.txt", ios::app);
    if (!myfstream)
    {
        cout << "The report file has not been opened to write the report in the login_manager function";
        getch();
        return;
    }
    time_t ttime = time(0);
    char *dt = ctime(&ttime);
    // string first = this->first_name;
    // string last = this->last_name;
    myfstream << this->first_name << " " << this->last_name << " whit national code: " << this->national_code << " viewed customer information whit national code: " << this->bankk->get_national_code(i) << " on " << dt << '\n';
    myfstream.close();
}
//
void employee::Create_an_account1(employee *&emp1)
{

    int result = emp1->bankk->temp_in_create();
    if (result != -1)
    {
        emp1->bankk->temp_push_back_acc(result);
        emp1->report_Create_an_account(result);
        return;
    }
    if (result == -1)
    {
        // not available
        emp1->bankk->temp_push_back();
    }
    cout << "ahahaha" << '\n';
    getch();
    emp1->report_Create_an_account();
}
void bank::temp_push_back_acc(int temp)
{
    long long int accont_number_ac1;
    long long int national_code_ac1;
    int day_ac1;
    int month_ac1;
    int year_ac1;
    long long int balance_ac1;
    bool check_ac1;
    cout << "Account Information " << '\n';
    cout << "Accont Number: ";
    cin >> accont_number_ac1;
    cout << "National Code: ";
    cin >> national_code_ac1;
    cout << "Account opening date " << '\n';
    cout << "Day: ";
    cin >> day_ac1;
    cout << "Month: ";
    cin >> month_ac1;
    cout << "Year: ";
    cin >> year_ac1;
    cout << "balance: ";
    cin >> balance_ac1;
    cout << "1-true" << '\n'
         << "2-false" << '\n';
    cout << "State: ";
    cin >> check_ac1;
    this->Account1.push_back(new Account(accont_number_ac1, national_code_ac1, day_ac1, month_ac1, year_ac1, balance_ac1, check_ac1));
}
void bank::temp_push_back()
{
    string first_name1;
    string last_name1;
    long long int national_code1;
    int day1;
    int mounth1;
    int year1;
    string user_name1;
    string password1;
    bank *bank1;

    long long int accont_number_ac1;
    long long int national_code_ac1;
    int day_ac1;
    int month_ac1;
    int year_ac1;
    long long int balance_ac1;
    bool check_ac1;

    cout << "Customer Information  " << '\n'
         << '\n';
    cout << "First Name: ";
    cin >> first_name1;
    cout << "Last Name: ";
    cin >> last_name1;
    cout << "National Code: ";
    cin >> national_code1;
    cout << "Date Of Birth " << '\n';
    cout << "Day: ";
    cin >> day1;
    cout << "Month: ";
    cin >> mounth1;
    cout << "Year: ";
    cin >> year1;
    cout << "User Name: ";
    cin >> user_name1;
    cout << "Password: ";
    cin >> password1;
    bank1 = this;
    this->customer1.push_back(new customer(first_name1, last_name1, national_code1, day1, mounth1, year1, user_name1, password1, bank1));
    cout << '\n'
         << '\n';
    cout << "Account Information " << '\n';
    cout << "Accont Number: ";
    cin >> accont_number_ac1;
    national_code_ac1 = national_code1;
    cout << "Account opening date " << '\n';
    cout << "Day: ";
    cin >> day_ac1;
    cout << "Month: ";
    cin >> month_ac1;
    cout << "Year: ";
    cin >> year_ac1;
    cout << "balance: ";
    cin >> balance_ac1;
    check_ac1 = true;
    cout << "123" << '\n';
    getch();
    this->Account1.push_back(new Account(accont_number_ac1, national_code_ac1, day_ac1, month_ac1, year_ac1, balance_ac1, check_ac1));
    cout << "124" << '\n';
    getch();
}
int bank::temp_in_create()
{

    long long int nat;
    cout << "National Code: ";
    cin >> nat;
    int size = this->customer1.size();
    for (int i = 0; i < size; i++)
    {
        if (this->customer1[i]->national_code == nat)
        {
            return i;
        }
    }
    return -1;
}
void employee::report_Create_an_account(int i)
{
    ofstream myfstream("report.txt", ios::app);
    if (!myfstream)
    {
        cout << "The report file has not been opened to write the report in the login_manager function";
        getch();
        return;
    }
    time_t ttime = time(0);
    char *dt = ctime(&ttime);
    // string first = this->first_name;
    // string last = this->last_name;
    myfstream << this->first_name << " " << this->last_name << " whit national code: " << this->national_code << " create account whit national code: " << this->bankk->get_national_code(i) << " on " << dt << '\n';
    myfstream.close();
}
void employee::report_Create_an_account()
{
    ofstream myfstream("report.txt", ios::app);
    if (!myfstream)
    {
        cout << "The report file has not been opened to write the report in the login_manager function";
        getch();
        return;
    }
    time_t ttime = time(0);
    char *dt = ctime(&ttime);
    // string first = this->first_name;
    // string last = this->last_name;
    int size = this->bankk->Account1.size();
    cout << "aaaaaa" << '\n';
    getch();
    myfstream << this->first_name << " " << this->last_name << " whit national code: " << this->national_code << " create account whit national code: " << this->bankk->get_national_code(size - 1) << " on " << dt << '\n';
    myfstream << this->first_name << " " << this->last_name << " whit national code: " << this->national_code << " create customer whit national code: " << this->bankk->get_national_code(size - 1) << " on " << dt << '\n';
    myfstream.close();
}
///
void employee::Delete_a_customer1(employee *&emp1)
{
    int result = emp1->bankk->temp_in_delete();
    if (result != -1)
    {
        // available
        emp1->bankk->temp_pop_back_acc(result);
    }
    if (result == -1)
    {
        // not available
        cout << "No account found. " << '\n';
        getch();
        return;
    }
    cout << "mission accomplished. " << '\n';
    getch();
}
int bank::temp_in_delete()
{

    long long int nat;
    cout << "Account Number: ";
    cin >> nat;
    int size = this->Account1.size();
    for (int i = 0; i < size; i++)
    {
        if (this->Account1[i]->accont_number_ac == nat)
        {
            return i;
        }
    }
    return -1;
}
void bank::temp_pop_back_acc(int temp)
{
    long long int nat = this->Account1[temp]->national_code_ac;
    this->report_temp_pop_back_acc(nat);
    this->Account1.erase(this->Account1.begin() + temp);
    bool check = false;
    int size = this->Account1.size();
    for (int i = 0; i < size; i++)
    {
        if (this->Account1[i]->national_code_ac == nat)
        {
            return;
        }
    }
    int size1 = this->customer1.size();
    for (int i = 0; i < size1; i++)
    {
        if (this->customer1[i]->national_code == nat)
        {
            this->report_temp_pop_back_acc1(nat);
            this->customer1.erase(this->customer1.begin() + i);
        }
    }
}
void bank::report_temp_pop_back_acc(long long int temp)
{
    ofstream myfstream("report.txt", ios::app);
    if (!myfstream)
    {
        cout << "The report file has not been opened to write the report in the login_manager function";
        getch();
        return;
    }
    time_t ttime = time(0);
    char *dt = ctime(&ttime);
    // string first = this->first_name;
    // string last = this->last_name;
    myfstream << "Account whit national code: " << temp << " delete on " << dt << '\n';
    myfstream.close();
}
void bank::report_temp_pop_back_acc1(long long int temp)
{
    ofstream myfstream("report.txt", ios::app);
    if (!myfstream)
    {
        cout << "The report file has not been opened to write the report in the login_manager function";
        getch();
        return;
    }
    time_t ttime = time(0);
    char *dt = ctime(&ttime);
    // string first = this->first_name;
    // string last = this->last_name;
    myfstream << "Customer whit national code: " << temp << " delete on " << dt << '\n';
    myfstream.close();
}
//
void employee::change_state1(employee *&emp)
{
    emp->bankk->temp_change_state();
}
void bank::temp_change_state()
{
    long long int acc_num;
    cout << "Account Number: ";
    cin >> acc_num;
    int size = this->Account1.size();
    for (int i = 0; i < size; i++)
    {
        if (this->Account1[i]->accont_number_ac == acc_num)
        {
            bool temp = this->Account1[i]->check_ac;
            if (temp == false)
            {
                cout << "Do you want to activate the account? " << '\n';
                cout << "1-Yes" << '\n';
                cout << "2-No" << '\n';
                int choice;
                cout << "Your Choice: ";
                cin >> choice;
                if (choice == 1)
                {
                    this->Account1[i]->check_ac = true;
                    this->report_change_state(this->Account1[i]->national_code_ac);
                }
            }
            if (temp == true)
            {
                cout << "Do you want to deactivate the account? " << '\n';
                cout << "1-Yes" << '\n';
                cout << "2-No" << '\n';
                int choice;
                cout << "Your Choice: ";
                cin >> choice;
                if (choice == 1)
                {
                    this->Account1[i]->check_ac = false;
                    this->report_change_state1(this->Account1[i]->national_code_ac);
                }
            }
            cout << "mission accomplished" << '\n';
            getch();
            return;
        }
    }
}
void bank::report_change_state(long long int temp)
{
    ofstream myfstream("report.txt", ios::app);
    if (!myfstream)
    {
        cout << "The report file has not been opened to write the report in the login_manager function";
        getch();
        return;
    }
    time_t ttime = time(0);
    char *dt = ctime(&ttime);
    // string first = this->first_name;
    // string last = this->last_name;
    myfstream << "Account whit national code: " << temp << " activated on " << dt << '\n';
    myfstream.close();
}
void bank::report_change_state1(long long int temp)
{
    ofstream myfstream("report.txt", ios::app);
    if (!myfstream)
    {
        cout << "The report file has not been opened to write the report in the login_manager function";
        getch();
        return;
    }
    time_t ttime = time(0);
    char *dt = ctime(&ttime);
    // string first = this->first_name;
    // string last = this->last_name;
    myfstream << "Account whit national code: " << temp << " deactivated on " << dt << '\n';
    myfstream.close();
}
////////////////
// manager
////////////////
void select_in_mainly_1_man(manager *&man, int choice)
{
    switch (choice)
    {
    case Request_leave_man:
        man->Request_leave_man1(man);
        break;
    case Request_for_overtime_man:
        man->Request_for_overtime_man1(man);
        break;
    case Display_personal_information_man:
        man->Display_personal_information_man1(man);
        break;
    case Full_view_man:
        man->Full_view_man1(man);
        break;
    case Create_an_account_man:
        man->Create_an_account_man1(man);
        break;
    case Delete_a_customer_man:
        man->Delete_a_customer_man1(man);
        break;
    case Display_employee_information_mna:
        man->Display_employee_information_mna1(man);
        break;
    case Adding_an_employee:
        man->Adding_an_employee1(man);
        break;
    case Remove_an_employee_man:
        man->Remove_an_employee_man1(man);
        break;
    case change_state_man:
        man->change_state_man1(man);
        break;
    case Exiting_man:
        break;
    default:
        cout << "Input number is invalid, please try again. ";
        getch();
        break;
    }
}
///
void manager::Request_leave_man1(manager *&man)
{
    system("cls");
    int temp;
    long long int temp3 = 0;
    cout << "Hours taken leave month: ";
    cout << man->vacation_hour << '\n';
    if (man->vacation_hour <= 15)
    {
        cout << "Remaining hours of leave per month: ";
        cout << 15 - man->vacation_hour << '\n';
    }

    cout << "How many hours of leave do you want? " << '\n';
    cout << "hours: ";
    cin >> temp;
    int temp1 = man->vacation_hour + temp;
    if (temp1 > 15)
    {
        int temp4 = temp - (15 - man->vacation_hour);
        man->vacation_hour = 15;
        cout << "The number of hours you request for leave this month is more than allowed (15 hours) " << '\n';
        for (int i = 0; i < temp4; ++i)
        {
            temp3 += 1000000;
        }
        man->basic_salary -= temp3;
        cout << "Salary received this month: ";
        cout << man->basic_salary << '\n';
        cout << "Remaining hours of leave per month: ";
        cout << 0 << '\n';
    }
    if (temp1 <= 15)
    {
        man->vacation_hour = temp + man->vacation_hour;
        cout << "Remaining hours of leave per month: ";
        cout << 15 - man->vacation_hour << '\n';
    }
    man->report_Request_leave1_employee(temp);
    cout << "mission accomplished. ";
    getch();
}
///
void manager::Request_for_overtime_man1(manager *&man)
{
    int temp = man->overtime_hour;
    if (temp >= 12)
    {
        cout << "You may not register overtime (12 hours). " << '\n';
        getch();
        return;
    }
    int temp1 = 12 - man->overtime_hour;
    bool temp3 = false;
    int temp2;
    int temp5;
    do
    {
        system("cls");
        cout << "Number of overtime hours this month: ";
        cout << man->overtime_hour << '\n';
        cout << "Number of overtime hours allowed this month: ";
        cout << temp1 << '\n';
        cout << "How many hours of leave do you want to record? " << '\n';
        cout << "hours: ";

        cin.ignore();
        cin >> temp2;
        temp5 = temp2;
        int ins = man->overtime_hour + temp2;
        temp3 = false;
        if (ins > 12)
        {
            cout << "You may not register overtime (12 hours). " << '\n';
            getch();
            temp3 = true;
        }
        long long int temp4 = 0;
        if (ins <= 12)
        {
            while (temp2 != 0)
            {
                temp4 += 1200000;
                --temp2;
            }

            man->basic_salary += temp4;
            cout << "Salary received this month: ";
            cout << man->basic_salary << '\n';
            man->overtime_hour = ins;
        }
    } while (temp3 == true);
    man->report_Request_for_overtime_employee(temp5);
    cout << "mission accomplished. ";
    getch();
}
///
void manager::Display_personal_information_man1(manager *&man)
{
    cout << "personal information " << '\n'
         << '\n';
    cout << "First Name: " << man->first_name << '\n';
    cout << "Last Name: " << man->last_name << '\n';
    cout << "National Code: " << man->national_code << '\n';
    cout << "Date of Birth " << '\n';
    cout << "Day: " << man->day << '\n';
    cout << "Month: " << man->mounth << '\n';
    cout << "Year: " << man->year << '\n';
    cout << "Personnel Code: " << man->id_code << '\n';
    cout << "Vacation Hours: " << man->vacation_hour << '\n';
    cout << "Overtime Hours: " << man->overtime_hour << '\n';
    cout << "Basic Salary: " << man->basic_salary << '\n';
    cout << "User Name: " << man->user_name << '\n';
    cout << "Password: " << man->password << '\n';
    getch();
    man->report_Display_personal_information_employee();
}
///
void manager::Full_view_man1(manager *&man)
{
    int temp = man->bankk->customer1.size();
    int temp1 = man->bankk->find_custumer_Full_view1(temp);
    if (temp1 != -1)
    {
        man->bankk->temp_in_Full_view1(temp1);
        man->report_Full_view(man->bankk, temp1);
    }
    if (temp1 == -1)
    {
        cout << "Customer Not Found. " << '\n';
        getch();
    }
    return;
}
///
void manager::Create_an_account_man1(manager *&man)
{
    int result = man->bankk->temp_in_create();
    if (result != -1)
    {
        // available
        man->bankk->temp_push_back_acc(result);
        man->report_Create_an_account(result);
        return;
    }
    if (result == -1)
    {
        // not available
        man->bankk->temp_push_back();
    }
    man->report_Create_an_account();
}
///
void manager::Delete_a_customer_man1(manager *&man)
{
    int result = man->bankk->temp_in_delete();
    if (result != -1)
    {
        // available
        man->bankk->temp_pop_back_acc(result);
    }
    if (result == -1)
    {
        // not available
        cout << "No account found. " << '\n';
        getch();
        return;
    }
}
///
void manager::Display_employee_information_mna1(manager *&man)
{
    int temp = man->bankk->employee1.size();
    int index = man->bankk->find_employee(temp);
    if (index != -1)
    {
        cout << index << '\n';
        getch();
        long long int temping = this->bankk->get_national_code_emp(index);
        cout << temping << '\n';
        getch();
        man->report_temp_disply_info_emp(temping);
        man->bankk->temp_disply_info_emp(index);
    }
    if (index == -1)
    {
        cout << "Employee Not Found. " << '\n';
        getch();
    }
    return;
}
int bank::find_employee(int temp)
{
    int code;
    cout << "Personal Code: ";
    cin >> code;

    int i = 0;
    for (; i < temp; i++)
    {
        if (this->employee1[i]->id_code == code)
        {
            return i;
            break;
        }
    }
    return -1;
}
void bank::temp_disply_info_emp(int temp)
{
    cout << "personal information " << '\n'
         << '\n';
    cout << "First Name: " << this->employee1[temp]->first_name << '\n';
    cout << "Last Name: " << this->employee1[temp]->last_name << '\n';
    cout << "National Code: " << this->employee1[temp]->national_code << '\n';
    cout << "Date of Birth " << '\n';
    cout << "Day: " << this->employee1[temp]->day << '\n';
    cout << "Month: " << this->employee1[temp]->mounth << '\n';
    cout << "Year: " << this->employee1[temp]->year << '\n';
    cout << "Personnel Code: " << this->employee1[temp]->id_code << '\n';
    cout << "Vacation Hours: " << this->employee1[temp]->vacation_hour << '\n';
    cout << "Overtime Hours: " << this->employee1[temp]->overtime_hour << '\n';
    cout << "Basic Salary: " << this->employee1[temp]->basic_salary << '\n';
    cout << "User Name: " << this->employee1[temp]->user_name << '\n';
    cout << "Password: " << this->employee1[temp]->password << '\n';
    getch();
}
void manager::report_temp_disply_info_emp(long long int temp)
{
    ofstream myfstream("report.txt", ios::app);
    if (!myfstream)
    {
        cout << "The report file has not been opened to write the report in the login_manager function";
        getch();
        return;
    }
    time_t ttime = time(0);
    char *dt = ctime(&ttime);
    // string first = this->first_name;
    // string last = this->last_name;
    cout << "10" << '\n';
    getch();
    myfstream << this->first_name << " " << this->last_name << " whit national code: " << this->national_code << " viewed employee information whit national code: " << temp << " on " << dt << '\n';
    cout << "11" << '\n';
    getch();
    myfstream.close();
}
///
void manager::Adding_an_employee1(manager *&man)
{
    string first_name;
    string last_name;
    long long int national_code;
    int day;
    int mounth;
    int year;
    string user_name;
    string password;
    int id_code;
    long long int basic_salary;
    int vacation_hour = 0;
    int overtime_hour = 0;
    bank *bankk = NULL;
    cout << "Employee Information " << '\n'
         << '\n';
    cout << "First Name: ";
    cin >> first_name;
    cout << "Last Name: ";
    cin >> last_name;
    cout << "National Code: ";
    cin >> national_code;
    cout << "Date of Birth " << '\n';
    cout << "Day: ";
    cin >> day;
    cout << "Month: ";
    cin >> mounth;
    cout << "Year: ";
    cin >> year;
    cout << "Personnel Code: ";
    cin >> id_code;
    cout << "Vacation Hours: ";
    cin >> vacation_hour;
    cout << "Overtime Hours: ";
    cin >> overtime_hour;
    cout << "Basic Salary: ";
    cin >> basic_salary;
    cout << "User Name: ";
    cin >> user_name;
    cout << "Password: ";
    cin >> password;
    bankk = man->bankk;
    // employee temp(first_name, last_name, national_code, day, mounth, year, user_name, password, id_code, basic_salary, bankk);
    man->bankk->employee1.push_back(new employee(first_name, last_name, national_code, day, mounth, year, user_name, password, id_code, basic_salary, bankk));
    man->report_Create_an_account1(national_code);
}
void manager::report_Create_an_account1(long long int temp)
{
    ofstream myfstream("report.txt", ios::app);
    if (!myfstream)
    {
        cout << "The report file has not been opened to write the report in the login_manager function";
        getch();
        return;
    }
    time_t ttime = time(0);
    char *dt = ctime(&ttime);
    // string first = this->first_name;
    // string last = this->last_name;
    myfstream << this->first_name << " " << this->last_name << " whit national code: " << this->national_code << " create employee whit national code: " << temp << " on " << dt << '\n';
    myfstream.close();
}
///
void manager::Remove_an_employee_man1(manager *&man)
{
    int temp = man->bankk->employee1.size();
    int index = man->bankk->find_employee(temp);
    if (index != -1)
    {
        man->report_Remove_an_employee_man1(index);
        man->bankk->employee1.erase(man->bankk->employee1.begin() + index);
        cout << "mission accomplished. " << '\n';
        getch();
    }
    if (index == -1)
    {
        cout << "Employee Not Found. " << '\n';
        getch();
    }
    return;
}
void manager::report_Remove_an_employee_man1(int temp)
{
    ofstream myfstream("report.txt", ios::app);
    if (!myfstream)
    {
        cout << "The report file has not been opened to write the report in the login_manager function";
        getch();
        return;
    }
    time_t ttime = time(0);
    char *dt = ctime(&ttime);
    // string first = this->first_name;
    // string last = this->last_name;
    myfstream << this->first_name << " " << this->last_name << " whit national code: " << this->national_code << " removed employee whit national code: " << this->bankk->get_national_code_emp(temp) << " on " << dt << '\n';
    myfstream.close();
}
///
void manager::change_state_man1(manager *&man)
{
    man->bankk->temp_change_state();
}
////////////////
// customer
////////////////
void mainly_2(bank &iran)
{
    int temp;
    string user_name1;
    string password1;
    cout << "User name: ";
    cin >> user_name1;
    cout << "Password: ";
    cin >> password1;
    customer *cus = iran.temp_mainly_2(iran, user_name1, password1);
    if (cus != NULL)
    {
        cus->report_login_customer();
        do
        {
            system("cls");
            menu_customer();
            cin >> temp;
            select_in_mainly_2_cus(cus, temp);
        } while (temp != Quit);
    }

    if (cus == NULL)
    {
        cout << "No soft customer. " << '\n';
        getch();
        return;
    }
}
customer *bank::temp_mainly_2(bank &iran, string user, string pass)
{
    for (int i = 0; i < iran.customer1.size(); i++)
    {
        if (iran.customer1[i]->user_name == user && iran.customer1[i]->password == pass)
        {
            return iran.customer1[i];
        }
    }
    return NULL;
}
void menu_customer()
{
    system("cls");
    cout << "1-Increase account balance " << '\n';
    cout << "2-withdraw from bank account " << '\n';
    cout << "3-Show information " << '\n';
    cout << "4-Exit" << '\n';
    cout << '\n';
    cout << "your choice: ";
}
void select_in_mainly_2_cus(customer *&cus1, int choice)
{
    switch (choice)
    {
    case Increase_account_balance:
        cus1->Increase_account_balance1();
        break;
    case withdraw_from_bank_account:
        cus1->withdraw_from_bank_account1();
        break;
    case Show_information:
        cus1->Show_information1();
        break;
    case Quit:

        break;
    default:
        cout << "Input number is invalid, please try again. ";
        getch();
        break;
    }
}
void customer::report_login_customer()
{
    ofstream myfstream("report.txt", ios::app);
    if (!myfstream)
    {
        cout << "The report file has not been opened to write the report in the login_manager function";
        getch();
        return;
    }
    time_t ttime = time(0);
    char *dt = ctime(&ttime);
    // string first = this->first_name;
    // string last = this->last_name;
    myfstream << this->first_name << " " << this->last_name << " (customer) logged in on " << dt << '\n';
    myfstream.close();
}
///
void customer::Increase_account_balance1()
{
    int size_acc = this->bankk->Account1.size();
    int index = this->bankk->temp_increace(size_acc);
    if (index != -1)
    {
        this->bankk->temp_inc_salary(index);
    }
    if (index == -1)
    {
        cout << "No account found. " << '\n';
        getch();
        return;
    }
}
int bank::temp_increace(int size)
{
    long long int account_num;
    cout << "Account Number: ";
    cin >> account_num;
    for (int i = 0; i < size; i++)
    {
        if (this->Account1[i]->accont_number_ac == account_num)
        {
            return i;
        }
    }
    return -1;
}
void bank::temp_inc_salary(int temp)
{
    long long int balance_ac1;
    cout << "Enter the desired amount: ";
    cin >> balance_ac1;
    this->Account1[temp]->balance_ac += balance_ac1;
    cout << "balance: " << this->Account1[temp]->balance_ac << '\n';
    getch();
    long long int temp1 = this->Account1[temp]->national_code_ac;
    this->report_Increase_account_balance1(temp1,balance_ac1);
}
void bank::report_Increase_account_balance1(long long int temp1,long long int temp2)
{
    ofstream myfstream("report.txt", ios::app);
    if (!myfstream)
    {
        cout << "The report file has not been opened to write the report in the login_manager function";
        getch();
        return;
    }
    time_t ttime = time(0);
    char *dt = ctime(&ttime);
    // string first = this->first_name;
    // string last = this->last_name;
    myfstream << "Account whit national code: "<< temp1<<" increase account balance with amount "<< temp2<<" on " << dt << '\n';
    myfstream.close();
}
///
void customer::withdraw_from_bank_account1()
{
    int size_acc = this->bankk->Account1.size();
    int index = this->bankk->temp_increace(size_acc);
    if (index != -1)
    {
        this->bankk->temp_dec_salary(index);
    }
    if (index == -1)
    {
        cout << "No account found. " << '\n';
        getch();
        return;
    }
}
void bank::temp_dec_salary(int temp)
{
    if (this->Account1[temp]->check_ac == false)
    {
        cout << "This account is not active. " << '\n';
        getch();
        return;
    }
    long long int balance_ac1;
    cout << "Enter the desired amount: ";
    cin >> balance_ac1;
    if (this->Account1[temp]->balance_ac < balance_ac1)
    {
        cout << "Your account balance is insufficient. " << '\n';
        getch();
        return;
    }
    this->Account1[temp]->balance_ac -= balance_ac1;
    cout << "balance: " << this->Account1[temp]->balance_ac << '\n';
    getch();
    long long int temp1 = this->Account1[temp]->national_code_ac;
    this->report_decrease_account_balance1(temp1,balance_ac1);
}
void bank::report_decrease_account_balance1(long long int temp1,long long int temp2)
{
    ofstream myfstream("report.txt", ios::app);
    if (!myfstream)
    {
        cout << "The report file has not been opened to write the report in the login_manager function";
        getch();
        return;
    }
    time_t ttime = time(0);
    char *dt = ctime(&ttime);
    // string first = this->first_name;
    // string last = this->last_name;
    myfstream << "Account whit national code: "<< temp1<<" decrease account balance with amount "<< temp2<<" on " << dt << '\n';
    myfstream.close();
}
///
void customer::Show_information1()
{
    int choice;
    do
    {
        system("cls");
        cout << "1- Display personal information " << '\n';
        cout << "2- Display Account information " << '\n';
        cout << "3- Exit" << '\n'
             << '\n';
        cout << "your choice: ";
        cin >> choice;
        long long int nati = this->national_code;
        switch (choice)
        {
        case Display_personal:
            this->displ();
            break;
        case Display_Account:
            this->bankk->disply_info_accc(nati);
            break;
        case quiting:
            break;
        default:
            cout << "Input number is invalid, please try again. ";
            getch();
            break;
        }
    } while (choice != 3);
}
void customer::displ()
{
    cout << "customer information " << '\n'
         << '\n';
    cout << "Name: " << this->first_name << " " << this->last_name << '\n';
    cout << "National Code: " << this->national_code << '\n';
    cout << "Date Of Birth: " << this->year << "/" << this->mounth << "/" << this->day << '\n';
    cout << "User Name: " << this->user_name << '\n';
    cout << "Password: " << this->password << '\n';
    getch();
    this->report_displ(this->national_code);
}
void customer::report_displ(long long int temp1)
{
    ofstream myfstream("report.txt", ios::app);
    if (!myfstream)
    {
        cout << "The report file has not been opened to write the report in the login_manager function";
        getch();
        return;
    }
    time_t ttime = time(0);
    char *dt = ctime(&ttime);
    // string first = this->first_name;
    // string last = this->last_name;
    myfstream << "Customer whit national code: "<< temp1<<" viewed her/his personal information on " << dt << '\n';
    myfstream.close();
}
void bank::disply_info_accc(long long int nati)
{
    int i = 0;
    int size = this->Account1.size();
    for (; i < size; i++)
    {
        if (this->Account1[i]->national_code_ac == nati)
        {
            cout << "Account Informetion " << '\n'
                 << '\n';
            cout << "Account Number: " << this->Account1[i]->accont_number_ac << '\n';
            cout << "National Code: " << this->Account1[i]->national_code_ac << '\n';
            cout << "Account opening date " << '\n';
            cout << "Day: " << this->Account1[i]->day_ac << '\n';
            cout << "Month: " << this->Account1[i]->month_ac << '\n';
            cout << "Year: " << this->Account1[i]->year_ac << '\n';
            cout << "Balance: " << this->Account1[i]->balance_ac << '\n';
            cout << "State: " << this->Account1[i]->check_ac << '\n';
            cout << '\n'
                 << '\n';
        }
    }
    getch();
    this->report_disply_info_accc(this->Account1[i]->national_code_ac);
}
void bank::report_disply_info_accc(long long int temp1)
{
    ofstream myfstream("report.txt", ios::app);
    if (!myfstream)
    {
        cout << "The report file has not been opened to write the report in the login_manager function";
        getch();
        return;
    }
    time_t ttime = time(0);
    char *dt = ctime(&ttime);
    // string first = this->first_name;
    // string last = this->last_name;
    myfstream << "Customer whit national code: "<< temp1<<" viewed her/his Account information on " << dt << '\n';
    myfstream.close();
}
///