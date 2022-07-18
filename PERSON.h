#ifndef PERSON_H
#define PERSON_H
#include <iostream>
//#include "BANK.h"
using namespace std;
class person
{
private:
protected:
    string first_name;
    string last_name;
    long long int national_code;
    int day;
    int mounth;
    int year;
    string user_name;
    string password;

public:
    friend class bank;
    person(string, string, long long int, int, int, int, string, string);
    virtual ~person();
};
#endif