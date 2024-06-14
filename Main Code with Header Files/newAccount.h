#ifndef NEWACCOUNT_H
#define NEWACCOUNT_H

#include<iostream>
using namespace std;

class newAccount
{
    protected:
        char* name;
        int* phone_number;
        double first_deposit;
        char* email;
        char account_type;
        int pass;
    public:
        newAccount();
        newAccount(char* name,int* phone_number,double first_deposit,char* email,char account_type,int password);
        void setName(char* n);
        void setPhone(char* ph);
        void setEmail(char* mail);
        void setDeposit(double deposit);
        void setType(char type);
        char* getName();
        int* getPhone();
        char* getEmail();
        double getDeposit();
        char setType();
        bool checkname(char* name);
        void addAccount();
        ~newAccount();
};

#endif