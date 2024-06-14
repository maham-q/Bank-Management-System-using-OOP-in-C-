#include<iostream>
#include<fstream>
#include"viewInquiry.h"
using namespace std;


    viewInquiry :: viewInquiry()
    {
        //cout<<"viewInquiry() called.\n";
    }
	void viewInquiry :: display()
	{
        cout<<"\t\t\t ==========================================================================\n";
        cout<<"\t\t\t|                              A.C.O.U.N.T                                 |\n";
        cout<<"\t\t\t|                             H.O.L.D.E.R.S                                |\n";
        cout<<"\t\t\t ========================================================================== \n";
        cout<<"\t\t\tACCOUNT HOLDERS ARE: \n";
        fstream fin;
        fin.open("Account-Details.txt",ios::in);
        while(fin.good())
        {
            string line;
            getline(fin,line,',');
            cout<<line<<"\t";
            
        }
	}
	void viewInquiry :: checkPIN(char* PIN)
	{
		for (int i = 0; i < 4; i++)
		{
		    while (PIN[i] != '0' && PIN[i] != '1' && PIN[i] != '2' && PIN[i] != '3' && PIN[i] != '4' && PIN[i] != '5' && PIN[i] != '6' && PIN[i] != '7' && PIN[i] != '8' && PIN[i] != '9')
			{
				cout << endl;
				cout << "\t\t\t Enter Again: ";
				cin >> PIN[i];
			}
		}
		cout << "\t\t\t" << "PIN Code: ";
		for (int i = 0; i < 4; i++)
		{
			cout << PIN[i] << " ";
		}
		cout << endl;
	}
	void viewInquiry :: cardManagement()
	{
        
        cout<<"\t\t\t ==========================================================================\n";
        cout<<"\t\t\t|                                 C.A.R.D                                  |\n";
        cout<<"\t\t\t|                           M.A.N.A.G.E.M.E.N.T                            |\n";
        cout<<"\t\t\t ========================================================================== \n";
		char* pin = new char[4];
		int n = 0;
		int count = 0;
		cout << endl;

       
        cout << "\t\t\t" << "Enter 1 to Activate your Card and Enter 2 to Deactivate your Card and Enter 0 to exit: ";
        cin >> n;
        while (n != 1 && n != 2 )
        {
            cout << "\t\t\tWrong input. Enter Again: ";
            cin >> n;
        }
        cout << endl;
        
        if (n == 1)
        {
            char PIN[4];
            
            cout << "Enter PIN : ";
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

            //cout<<"\t"<<PIN_Input;


            flag=1;
            int count2=0;
            string line;
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

            fstream fout;
            fout.open("Card-Status.txt",ios::out | ios::app);
            fout<<"1"<<endl;

        }
        else if (n == 2)
        {
        char PIN[4];
        
        cout << "Enter PIN : ";
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

            //cout<<"\t"<<PIN_Input;


            flag=1;
            int count2=0;
            string line;
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

            fstream fout;
            fout.open("Card-Status.txt",ios::out | ios::app);
            fout<<"0"<<endl;

        }
        else if (n == 0)
        {
            cout<< "\t\t\tGOOD BYE!!!.\n";
        }
        else
        {
            cout<<"\t\t\tWrong input.\n";
        }

        cout << "\t\t\tCard Management Successful.\n";
	}
    viewInquiry :: ~viewInquiry()
    {
        //cout<<"~viewInquiry() called.\n";
    }
