#include<iostream>
#include<fstream>
#include<string>
using namespace std;

bool loggedin();
char* PIN = new char[4];
double balance=0;


class newAccount //COMPLETED
{
protected:
	char* name;
	int* phone_number;
	double first_deposit;
	char* email;
	char account_type;
    int pass;
public:
	newAccount()
	{
		name = new char;
		phone_number = new int[11];
		first_deposit=0;
		email = new char;
		account_type= '\0';
        pass=0;
	}
	newAccount(char* name,int* phone_number,double first_deposit,char* email,char account_type,int password)
	{
		this->name = name;
		this->phone_number = phone_number;
		this->first_deposit=first_deposit ;
		this->email=email;
		this->account_type=account_type ;
        pass=password;
	}
	//S.E.T.T.E.R.S
	void setName(char* n)
	{
		for (int i = 0; n[i] != '\0'; i++)
		{
			name[i] = n[i];
		}
	}
	void setPhone(char* ph)
	{
		for (int i = 0; ph[i] != '\0'; i++)
		{
			phone_number[i] = ph[i];
		}
	}
	void setEmail(char* mail)
	{
		for (int i = 0; mail[i] != '\0'; i++)
		{
			email[i] = mail[i];
		}
	}
	void setDeposit(double deposit)
	{
		first_deposit = deposit;
	}
	void setType(char type)
	{
		account_type = type;
	}

	//G.E.T.T.E.R.S
	char* getName()
	{
		return name;
	}
	int* getPhone()
	{
		return phone_number;
	}
	char* getEmail()
	{
		return email;
	}
	double getDeposit()
	{
		return first_deposit;
	}
	char setType()
	{
		return account_type;
	}
	bool checkname(char* name)
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
	
	void addAccount()
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

    
	~newAccount()
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
};

class AccountDetails    //COMPLETED
{
    protected:
        char* name;
        int pin;
        char* email;
        char* phone;

    public:
        AccountDetails()
        {
            name=new char;
            pin=0;
            email=new char;
            phone=new char;
        }
        AccountDetails(char* name,int pin,char* email,char* phone)
        {
            name=this->name;
            pin=this->pin;
            email=this->email;
            phone=this->phone;
        }

        virtual void display()
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

        ~AccountDetails()
        {
            delete[]name;
            name=nullptr;
            delete[]email;
            email=nullptr;
            delete[]phone;
            phone=nullptr;
        }
};

class viewInquiry : public AccountDetails//COMPLETEd
{
public:
    viewInquiry()
    {
        //cout<<"viewInquiry() called.\n";
    }
	void display()
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
	void checkPIN(char* PIN)
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
	void cardManagement()
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
    ~viewInquiry()
    {
        //cout<<"~viewInquiry() called.\n";
    }
};

class Transaction   //COMPLETED
{
    protected:
        double totalBalance;
        double Amount;
    public:
        Transaction()
        {
            totalBalance=0;
            Amount=0;
        }
        Transaction(double bal,double am)
        {
            totalBalance=bal;
            Amount=am;
        }
        void depositCash()
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

        void withdrawCash()
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
    ~Transaction()
    {
        //cout<<"~Transaction() called.\n";
    }

};

class Loan      //COMPLETED
{
    public:

        Loan()
        {
            //cout<<"\t\t\tLoan() called.\n\n";
        }

        bool ApplyLoan()
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

        void AddToDatabase()
        {
         
            bool flag=ApplyLoan();
            ofstream fout;
            fout.open("Loan-Status.txt",ios::out | ios::app);
            fout<<flag<<"\n";
            fout.close();
            cout<<"\n";
        }

        int CheckStatus()
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

        void loan()
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

        ~Loan()
        {
            //cout<<"\t\t\t~Loan() called.\n\n";
        }
};

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

    Menu(): newAccount(), viewInquiry(), Transaction(), Loan()
    {
        //cout<<"\t\t\tMenu called.\n";
    }
    void MainFunction()
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
    ~Menu()
    {
        //cout<<"\t\t\t~Menu() called.\n";
    }
};







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