#ifndef ACCOUNTDETAILS_H
#define ACCOUNTDETAILS_H

#include<iostream>
using namespace std;

class AccountDetails  //COMPLETED
{
    protected:
        char* name;
        int pin;
        char* email;
        char* phone;

    public:
        AccountDetails();
        AccountDetails(char* name,int pin,char* email,char* phone);
        virtual void display();
        ~AccountDetails();
};

#endif