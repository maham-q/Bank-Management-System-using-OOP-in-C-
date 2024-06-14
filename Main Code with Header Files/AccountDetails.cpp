#include<iostream>
#include "AccountDeails.h"
using namespace std;
char* PIN = new char[4];
double balance=0;

    AccountDetails :: AccountDetails()
    {
        name=new char;
        pin=0;
        email=new char;
        phone=new char;
    }
    AccountDetails :: AccountDetails(char* name,int pin,char* email,char* phone)
    {
        name=this->name;
        pin=this->pin;
        email=this->email;
        phone=this->phone;
    }

    virtual void AccountDetails :: display()
    {
        cout<<"\t\t\t ==========================================================================\n";
        cout<<"\t\t\t|                              A.C.O.U.N.T                                 |\n";
        cout<<"\t\t\t|                        I.N.F.O.R.M.A.T.I.O.N                             |\n";
        cout<<"\t\t\t ========================================================================== \n";
        char PIN[4];
        cout << "\t\t\tEnter PIN : ";
        for(int i = 0; i < 4; i++)
        {
            cin >> PIN[i];
        }
        int count=0;
        bool flag=1;
        bool stop = 1;

        fstream check;
        check.open("PIN-Detail.txt",ios::in);
        char PIN_Input[4];

        while(check.good() && stop)
        {
            flag = 1;

            for(int i = 0; i < 4 && check.good(); i++)
            {
                check >> PIN_Input[i];
            }
            count++;

            for(int i = 0; i < 4 && check.good() && flag; i++)
            {
                if(PIN_Input[i] != PIN[i])
                {
                    flag = 0;
                }
            }

            if(flag)
                stop = 0;
        }
        check.close();

        flag=1;
        int count2=0;
        string line;
        cout<<"\t\t\tYour Account details are: \n";
        fstream fin;
        fin.open("Account-Details.txt",ios::in);
        while(fin.good() && flag)
        {
            getline(fin, line);
            count2++;

            if(count == count2)
            {
                flag = 0;
            }
        }
        fin.close();
        cout<<line<<"\t";
    }

    AccountDetails :: ~AccountDetails()
    {
        delete[]name;
        name=nullptr;
        delete[]email;
        email=nullptr;
        delete[]phone;
        phone=nullptr;
    }

#endif