#include<iostream>
#include<fstream>
#include"Loans.h"
using namespace std;


    Loan :: Loan()
    {
        //cout<<"\t\t\tLoan() called.\n\n";
    }

    bool Loan :: ApplyLoan()
    {
        char choice;
        cout<<"\t\t\t ==========================================================================\n";
        cout<<"\t\t\t|                                 L.O.A.N                                  |\n";
        cout<<"\t\t\t|                          A.P.P.L.I.C.A.T.I.O.N                           |\n";
        cout<<"\t\t\t ========================================================================== \n";
    
        cout<<"\t\t\tDo you wish to apply for a loan?\n";
        cout<<"\t\t\tPress 'Y' or 'y' for YES.\n";
        cout<<"\t\t\tPress 'N' or 'n' for NO.\n";
        cout<<"\t\t\tEnter your choice: ";
        cin>>choice;

        if(choice=='Y' || choice=='y')
        {
            cout<<"\t\t\tYour request for the loan has been applied.\n";
            cout<<"\t\t\tStatus has been updated to 'Approved'.\n";
            return 1;
        }
        else if(choice=='N' || choice=='n')
        {
            cout<<"\t\t\tYou do not wish to apply for a loan.\n";
            cout<<"\t\t\tStatus has been updated to 'Not Approved'.\n";
            return 0;
        }
        else
        {
            cout<<"\t\t\tWrong option selected.\n";
            cout<<"\t\t\tTry Again.\n";
            ApplyLoan();
            return -1;
        }
        cout<<"\n";

    }

    void Loan :: AddToDatabase()
    {
        
        bool flag=ApplyLoan();
        ofstream fout;
        fout.open("Loan-Status.txt",ios::out | ios::app);
        fout<<flag<<"\n";
        fout.close();
        cout<<"\n";
    }

    int Loan :: CheckStatus()
    {
        cout<<"\t\t\t ==========================================================================\n";
        cout<<"\t\t\t|                                 L.O.A.N                                  |\n";
        cout<<"\t\t\t|                               S.T.A.T.U.S                                |\n";
        cout<<"\t\t\t ========================================================================== \n";

        char choice;
        cout<<"\t\t\tDo you wish to check your loan request status?\n";
        cout<<"\t\t\tPress 'Y' or 'y' for YES.\n";
        cout<<"\t\t\tPress 'N' or 'n' for NO.\n";
        cout<<"\t\t\tEnter your choice: ";
        cin>>choice;

        if(choice=='Y' || choice=='y')
        {
            int check;
            fstream fin;
            fin.open("Loan-Status.txt",ios::in );
            if(fin.is_open())
            {
                fin>>check;
            }
            fin.close();
        
            if(check==1)
            {
                cout<<"\t\t\tYour loan has been approved.\n";
                return 1;
            }
            if(check==0)
            {
                cout<<"\t\t\tYour loan has not been approved.\n";
                return 0;
            }
            
        }
        else if(choice=='N' || choice=='n')
        {
            cout<<"\t\t\tYou have selected not to view your loan status report.\n";
            return 0;
        }
        else
        {
            cout<<"\t\t\tWrong option selected.\n";
            cout<<"\t\t\tTry Again.\n";
            CheckStatus();
            return -1;
        }
        cout<<"\n";
    
    }

    void Loan :: loan()
    {
        cout<<"\t\t\t ==========================================================================\n";
        cout<<"\t\t\t|                                 L.O.A.N                                  |\n";
        cout<<"\t\t\t|                          I.N.F.O.R.M.A.T.I.O.N                           |\n";
        cout<<"\t\t\t ========================================================================== \n";
    
            int loanStat=CheckStatus();
            if(loanStat==1)
            {
            double bal=0;
            double loan=0;
            int choice=0;
            cout<<"\n";
            cout<<"\t\t\tOur bank offers 5 options in loans.\n";
            cout<<"\t\t\tOption 1-> 50,000 Rs.\n";
            cout<<"\t\t\tOption 2-> 100,000 Rs.\n";
            cout<<"\t\t\tOption 3-> 150,000 Rs.\n";
            cout<<"\t\t\tOption 4-> 200,000 Rs.\n";
            cout<<"\t\t\tOption 5-> 250,000 Rs.\n";
            cout<<"\t\t\tEnter your choice: ";
            cin>>choice;

            fstream input;
            fstream output;
            output.open("Loans.txt", ios::out | ios::app);
            input.open("Balance.txt" , ios::in);
            switch(choice)
            {
                case 1:
                {   
                    cout<<"\t\tLoan has been given to you.\n";
                    loan=50000;
                    while(input>>bal && output.is_open())
                    {
                        bal+=loan;
                        output<<bal<<"\n";
                    }
                    break;
                }
                case 2:
                {
                    cout<<"\t\tLoan has been given to you.\n";
                    loan=100000;
                    while(input>>bal && output.is_open())
                    {
                        bal+=loan;
                        output<<bal<<"\n";
                    }
                    break;
                }
                case 3:
                {
                    cout<<"\t\tLoan has been given to you.\n";
                    loan=150000;
                    while(input>>bal && output.is_open())
                    {
                        bal+=loan;
                        output<<bal<<"\n";
                    }
                    break;
                }
                case 4:
                {
                    cout<<"\t\tLoan has been given to you.\n";
                    loan=200000;
                    while(input>>bal && output.is_open())
                    {
                        bal+=loan;
                        output<<bal<<"\n";
                    }
                    break;
                }
                case 5:
                {
                    cout<<"\t\tLoan has been given to you.\n";
                    loan=250000;
                    while(input>>bal && output.is_open())
                    {
                        bal+=loan;
                        output<<bal<<"\n";
                    }
                    break;
                }
                default:
                {
                    cout<<"\t\tNo option selected. Terminating.\n ";
                    break;
                }
            }
            }
            else
            {
                cout<<"\t\t\tNo loan history.\n";
            }
        cout<<"\n";
    }

    Loan :: ~Loan()
    {
        //cout<<"\t\t\t~Loan() called.\n\n";
    }

