#ifndef TRANSACTION_H
#define TRANSACTION_H

#include<iostream>
#include<fstream>
using namespace std;
char* PIN = new char[4];
double balance=0;

class Transaction   
{
    protected:
        double totalBalance;
        double Amount;
    public:
        Transaction();
        Transaction(double bal,double am);
        void depositCash();
        void withdrawCash();
        ~Transaction();
};

#endif