#include<iostream>
#include"Menu.h"
#include"newAccount.h"
#include"viewInquiry.h"
#include"Transaction.h"
#include"AccountDetails.h"
#include"Loans.h"
using namespace std;

bool loggedin();

Menu :: Menu(): newAccount(), viewInquiry(), Transaction(), Loan()
{
    //cout<<"\t\t\tMenu called.\n";
}
void  Menu :: MainFunction()
{
    int while_con=0;
    int choice=0,choice2=0;
    int inner_choice=0;

    
    cout<<"\t\t\t ==========================================================================\n";
    cout<<"\t\t\t|                             W.E.L.C.O.M.E                                |\n";
    cout<<"\t\t\t|                                  T.O                                     |\n";
    cout<<"\t\t\t|                 B.A.N.K  M.A.N.A.G.E.M.E.N.T  S.Y.S.T.E.M                |\n";
    cout<<"\t\t\t ========================================================================== \n";
    cout<<"\t\t\tPLEASE SELECT YOUR DESIRED OPTION.\n";
    cout<<"\t\t\tPRESS (1) TO REGISTER YOUR ACCOUNT.\n";
    cout<<"\t\t\tPRESS (2) TO LOGIN.\n";
    cout<<"\t\t\tENTER YOUR CHOICE: ";
    cin>>choice;
    while(choice<1 || choice>7)
    {
        cout<<"\t\t\tWrong Input.\n\t\t\tEnter Again: ";
        cin>>choice;
    }


    if(choice==1)
    {
        cin.ignore();
        n.addAccount();
    }
    else if(choice==2)
    {
        bool flag=loggedin();
    
        if(flag==1)
        {
            do
            {
                cout<<"\t\t\tPRESS (1) TO VIEW YOUR ACCOUNT DETAILS.\n";
                cout<<"\t\t\tPRESS (2) TO DEPOSIT MONEY TO YOUR ACCOUNT.\n";
                cout<<"\t\t\tPRESS (3) TO WITHDRAW MONEY FROM YOUR ACCOUNT.\n";
                cout<<"\t\t\tPRESS (4) TO VIEW ALL ACCOUNT HOLDERS INFORMATION.\n";
                cout<<"\t\t\tPRESS (5) TO MANAGE YOUR CARD.\n";
                cout<<"\t\t\tPRESS (6) FOR LOANS.\n";
                cout<<"\t\t\tENTER YOUR CHOICE: ";
                cin>>choice2;
                while(choice2<1 || choice2>7)
                {
                    cout<<"\t\t\tWrong Input.\n\t\t\tEnter Again: ";
                    cin>>choice2;
                }
                switch(choice2)
                {
                    case 1:
                    {
                        Details.display();
                        break;
                    }
                    case 2:
                    {
                        t.depositCash();
                        break;
                    }
                    case 3:
                    {
                        t1.withdrawCash();
                        break;
                    }
                    case 4:
                    {
                        view.display();
                        break;
                    }
                    case 5:
                    {
                        view.cardManagement();
                        break;
                    }
                    case 6:
                    {
                        cout<<"\t\t\tWHAT DO YOU WISH TO DO?\n";
                        cout<<"\t\t\tPRESS (1) IF YOU WANT TO APPLY FOR A LOAN.\n";
                        cout<<"\t\t\tPRESS (2) TO SEE LOAN OPTIONS.\n";
                        cout<<"\t\t\tENTER YOUR CHOICE: ";
                        cin>>inner_choice;

                        while(inner_choice != 1 && inner_choice != 2)
                        {
                            cout<<"\t\t\tWrong choice.\n\t\t\tEnter Again: ";
                            cin>>inner_choice;
                        }

                        switch(inner_choice)
                        {
                            case 1:
                            {
                                l.ApplyLoan();
                                l.AddToDatabase();
                                break;
                            }
                            case 2:
                            {
                                l.loan();
                                break;
                            }
                            default:
                            {
                                cout<<"\t\t\tWrong option. Terminating!!!.\n";
                                break;
                            }
                        }
                        break;
                    }
                    default:
                    {
                        cout<<"\t\t\tWRONG OPTION. TERMINATING.!!!\n";
                        break;
                    }
                }   
            cin.ignore();
            cout<<"\t\t\t\nDO YOU WISH TO CONTINUE?\n\t\t\tPRESS (0) TO STOP.\n";
            cin>>while_con;
            }while(while_con!=0);
            cout<<"\n";
        }
    }
}
    Menu ::~Menu()
{
    //cout<<"\t\t\t~Menu() called.\n";
}

