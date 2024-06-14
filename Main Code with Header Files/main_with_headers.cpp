#include<iostream>
#include<fstream>
#include"Menu.h"
using namespace std;

bool loggedin();
char* PIN = new char[4];
double balance=0;
int main()
{
    Menu m1;
    m1.MainFunction();
    cout<<"\n";
    return 0;
}



bool loggedin()
{
    bool flag=0;
    int count=0;
    string user,pass,us,pa;
    cout<<"\t\t\tEnter Account Username: ";
    cin>>user;
    cout<<"\n\t\t\tEnter Account Password: ";
    cin>>pass;
    cout<<'\n';

    ifstream open("login.txt");
    while(open.is_open())
    {
        getline(open,us);
        getline(open,pa);
        if(user == us && pass == pa)
        {
            flag=1;
            break;
        }
        else if(user != us && pass == pa)
        {
            flag=0;
        }
        else if(user == us && pass != pa)
        {
            flag=0;
        }
        else
        {
            flag=0;
        }
    }
    open.close();
    
    if(flag==1)
    {
        return true;
    }
    else
    {
        return false;
    }
}