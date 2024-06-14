#include<iostream>
#include"newAccount.h"
#include"viewInquiry.h"
#include"Transaction.h"
#include"AccountDetails.h"
#include"Loans.h"
using namespace std;


class Menu :public newAccount, public viewInquiry, public Transaction, public Loan
{
    protected:
        newAccount n;
        Loan l;
        AccountDetails Details;
        Transaction t;
        Transaction t1;
        viewInquiry view;
    public:

    Menu(): newAccount(), viewInquiry(), Transaction(), Loan(){};
    void MainFunction();
    ~Menu();
};

