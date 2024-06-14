#ifndef LOANS_H
#define LOANS_H

#include<iostream>
#include<fstream>
using namespace std;

class Loan      //COMPLETED
{
    public:

    Loan();
    bool ApplyLoan();
    void AddToDatabase();
    int CheckStatus();
    void loan();
    ~Loan();
};

#endif
