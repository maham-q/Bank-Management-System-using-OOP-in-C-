#include<iostream>
#include"Transaction.h"
#include<fstream>

using namespace std;
char* PIN = new char[4];
double balance=0;

    Transaction :: Transaction()
    {
        totalBalance=0;
        Amount=0;
    }
    Transaction :: Transaction(double bal,double am)
    {
        totalBalance=bal;
        Amount=am;
    }
    void Transaction :: depositCash()
    {
        cout<<"\t\t\t ==========================================================================\n";
        cout<<"\t\t\t|                                 C.A.S.H                                  |\n";
        cout<<"\t\t\t|                              D.E.P.O.S.I.T.                              |\n";
        cout<<"\t\t\t ========================================================================== \n";
        
    
        double balance;
        fstream input;
        fstream output;
        output.open("Deposit.txt", ios::out | ios::app);
        input.open("Balance.txt", ios::in);

        cout<<"\t\t\tEnter amount you want to deposit: ";
        cin>>Amount;
        while(Amount<0)
        {
            cout<<"\t\t\tError. Wrong input.\n\t\t\tEnter Again: ";
            cin>>Amount;
        }
        while(input>>totalBalance && input.good())
        {
            balance=totalBalance+Amount;
            output<<balance<<"\n";
        }
        cout<<"\t\t\tYour updated balance is: "<<balance<<"\n";

        input.close();
        output.close();
        
    }

    void Transaction :: withdrawCash()
    {
        cout<<"\t\t\t ==========================================================================\n";
        cout<<"\t\t\t|                                 C.A.S.H                                  |\n";
        cout<<"\t\t\t|                             W.I.T.H.D.R.A.W                              |\n";
        cout<<"\t\t\t ========================================================================== \n";
        
        double balance_check=0;
        
        double balance;
        fstream input;
        fstream output;
        output.open("Withdraw.txt", ios::out | ios::app);
        input.open("Deposit.txt", ios::in);

        cout<<"\t\t\tEnter amount you want to Withdraw: ";
        cin>>Amount;
        while(Amount<0)
        {
            cout<<"\t\t\tError. Wrong input.\n\t\t\tEnter Again: ";
            cin>>Amount;
        }
        while(input>>totalBalance && input.good())
        {
            if(Amount>totalBalance)
            {
                cout<<"\t\t\tEntered amount not available in the account. Try Again!\n";
            }
            balance=totalBalance-Amount;
            output<<balance<<"\n";
        }
        cout<<"\t\t\tYour updated balance is: "<<balance<<"\n";

        input.close();
        output.close();
    }
    Transaction :: ~Transaction()
    {
        //cout<<"~Transaction() called.\n";
    }


