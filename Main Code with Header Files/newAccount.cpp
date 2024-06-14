#include<iostream>
#include<fstream>
#include"newAccount.h"
using namespace std;
char* PIN = new char[4];
double balance=0;

newAccount :: newAccount()
{
    name = new char;
    phone_number = new int[11];
    first_deposit=0;
    email = new char;
    account_type= '\0';
    pass=0;
}
newAccount :: newAccount(char* name,int* phone_number,double first_deposit,char* email,char account_type,int password)
{
    this->name = name;
    this->phone_number = phone_number;
    this->first_deposit=first_deposit ;
    this->email=email;
    this->account_type=account_type ;
    pass=password;
}
//S.E.T.T.E.R.S
void newAccount :: setName(char* n)
{
    for (int i = 0; n[i] != '\0'; i++)
    {
        name[i] = n[i];
    }
}
void newAccount ::  setPhone(char* ph)
{
    for (int i = 0; ph[i] != '\0'; i++)
    {
        phone_number[i] = ph[i];
    }
}
void newAccount :: setEmail(char* mail)
{
    for (int i = 0; mail[i] != '\0'; i++)
    {
        email[i] = mail[i];
    }
}
void newAccount :: setDeposit(double deposit)
{
    first_deposit = deposit;
}
void newAccount :: setType(char type)
{
    account_type = type;
}

//G.E.T.T.E.R.S
char* newAccount :: getName()
{
    return name;
}
int* newAccount :: getPhone()
{
    return phone_number;
}
char* newAccount :: getEmail()
{
    return email;
}
double newAccount :: getDeposit()
{
    return first_deposit;
}
char newAccount :: setType()
{
    return account_type;
}
bool newAccount :: checkname(char* name)
{
    int count = 0;
    int n = 0;
    {
    for (int i = 0; name[i] != '\0'; i++)
        if ((name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <= 'Z')||(name[i] ==' '))
        {
            continue;
        }
        else
        {
            count++;
            break;
        }
    }
    if (count == 1)
    {
        cout << "\t\t\tEnter Name Again: ";
        cin.getline(name, 30);
        for (int i = 0; name[i] != '\0'; i++)
        {
            n++;
        }
        return 1;
    }
    else
    {
        return 0;
    }
}

void newAccount :: addAccount()
{
    fstream fout;
    fstream login;
    login.open("Login.txt", ios::out | ios::out);
    fout.open("Account-Details.txt",ios::out | ios::app);



    cout<<"\t\t\t ==========================================================================\n";
    cout<<"\t\t\t|                              A.C.O.U.N.T                                 |\n";
    cout<<"\t\t\t|                        R.E.G.I.S.T.R.A.T.I.O.N                           |\n";
    cout<<"\t\t\t ========================================================================== \n";
    cout << "\t" << "\t" << "\t" << "Enter your Name: ";
    cin.get(name,30);
    int n=0;
    bool check = checkname(name);
    while (check==1)
    {
        check = checkname(name);
    }
    fout<<name<<",";
    login<<name<<"\n";
    cin.ignore();
    cout << endl;

    cout<<"\t\t\tEnter Your Preferred Password: ";
    cin>>pass;
    login<<pass<<"\n";
    cout<<"\n";


    cout << "\t\t\tEnter your Phone Number: ";
    for (int i = 0; i < 11; i++)
    {
        cin >> phone_number[i];
    }
    for(int i=0;i<11;i++)
    {
        fout<<phone_number[i];
    }
    fout<<",";
    cin.ignore();

    cout << endl;

    cout << "\t\t\tEnter your Email: ";
    cin.get(email,50);
    fout<<email<<",";
    cin.ignore();
    cout << endl;
    
    cout << "\t\t\tEnter your Account Type:(C for Current & S for Saving) ";
    cin >> account_type;
    while (account_type != 'S' && account_type != 's' && account_type != 'C' && account_type != 'c')
    {
        cout << "\t\t\tWrong input. Enter Again: ";
        cin >> account_type;
    }
    fout<<account_type<<"\n";
    cin.ignore();
    cout << endl;
    
    fstream bal;
    bal.open("Balance.txt" , ios::out | ios::app);
    cout << "\t\t\tEnter your First Deposit: ";
    cin >> first_deposit;
    while (first_deposit<500 || first_deposit>2000)
    {
        cout << "\t\t\tWrong input. Enter Again: ";
        cin >>first_deposit;
    }
    balance = first_deposit;
    bal<<balance<<"\n";
    cin.ignore();

    cout<<"\t\t\tEnter your PIN Number: ";
    for(int i=0;i<4;i++)
    {
        cin>>PIN[i];
    }

    //TO SAVE PIN DETAILS IN A SEPRATE FILE
    fstream f;
    f.open("PIN-Detail.txt",ios::out | ios::app);
    for(int i=0;i<4;i++)
    {
        f<<PIN[i];
    }
    f<<endl;
    cout << endl;
    cin.ignore();

    login.close();
    fout.close();
    f.close();
    bal.close();

    cout<<"\t\t\tA.C.C.O.U.N.T S.E.T.U.P S.U.C.C.E.S.S.F.U.L.\n";
}


newAccount :: ~newAccount()
{
    delete[]name;
    name = NULL;
    delete[]phone_number;
    phone_number = NULL;
    first_deposit = '\0';
    delete[] email;
    email = NULL;
    account_type = '\0';
}
