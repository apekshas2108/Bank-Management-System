#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include<limits>
#include <cwchar>
#include <windows.h>

using namespace std;
class account
{
        int accountnumber;
        char name[50];
        int deposit;
        char type;

public:
        void create_account();
        void show_account();
        void modify_account();
        void deposit_funds(int);
        void draw_funds(int);
        void get_report();
        int get_accountnumber();
        int get_funds();
        char get_accounttype();
};

void account::create_account()
{

        accountnumber = rand();
        cout << "\nThe account Number is : " << accountnumber;
        cout << "\nEnter The Name of The account Holder : ";
        cin.ignore();
        cin.getline(name, 50);
        label1:
		cout << "\nEnter account type (enter s - saving or c - credit): ";
        cin >> type;
        cin.ignore();

        if(type!='s' && type!='c')
        {
        	cout<<"Enter the valid account type "<<endl;
        	goto label1;

		}
        type = toupper(type);
        label2:
		cout << "\nEnter The Initial amount(500 or more for Saving and 1000 or more for credit ): ";
        cin >> deposit;
        if(cin.fail())
        {
        	cin.clear();
        	cin.ignore(512,'\n');
        	cout<<"\nEnter amount in numbers!!\n\n";
        	goto label2;
		}

        if(type=='S')
        {
        	if(deposit<500)
        	{
        		cout<<"Minimum amount for saving account is 500"<<endl;
        		goto label2;
			}
		}
		if(type=='C')
        {
        	if(deposit<1000)
        	{
        		cout<<"Minimum amount for credit account is 1000"<<endl;
        		goto label2;
			}
		}

        cout << "\n\n\nAccount Created Successfully...";



}

void account::show_account()
{
	cout<<"\n\n************************Balance details************************\n\n";
        cout << "\nAccount Number: " << accountnumber;
        cout << "\nAccount Holder Name: " << name;
        cout << "\nType of Account: " << type;
        cout << "\nBalance amount: " << deposit<<endl;
}

void account::modify_account()
{
        cout << "\nAccount Number: " << accountnumber;
        cout << "\nModify Account Holder Name: ";
        cin.ignore();
        cin.getline(name, 50);

		cout << "\nModify Type of Account: ";
        label9:
		cin >> type;
		cin.ignore();
        if(type!='s' && type!='c')
        {
        	cout<<"Enter the valid account type "<<endl;
        	goto label9;

		}

        type = toupper(type);
        // cout << "\nModify Balance amount: ";
        // cin >> deposit;
}

void account::deposit_funds(int x)
{
        deposit += x;
        cout<<"Updated balance: "<<deposit<<endl;
}

void account::draw_funds(int x)
{
        deposit -= x;
        cout<<"Remaining balance: "<<deposit<<endl;
}

void account::get_report()
{
        cout << accountnumber << setw(10) << "\t" << name << setw(10) << "\t\t\t" << type << setw(6)<<"\t\t\t" << deposit << endl;
}

int account::get_accountnumber()
{
        return accountnumber;
}

int account::get_funds()
{
        return deposit;
}

char account::get_accounttype()
{
        return type;
}

void write_account();
void display_sp(int);
void modify_account(int);
void delete_account(int);
void display_all();
void deposit_withdraw(int, int);

int main()
{

        srand(time(0));
        char opt;
        int num;
        //CONSOLE_FONT_INFOEX cfi;
		//cfi.cbSize = sizeof(cfi);
		//cfi.nFont = 0;
		//cfi.dwFontSize.X = 0;                   // Width of each character in the font
		//cfi.dwFontSize.Y = 24;                  // Height
		//cfi.FontFamily = FF_DONTCARE;
		//cfi.FontWeight = FW_NORMAL;
		//std::wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
		//SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);


        cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t___________________________________________________";
                cout << "\n\t\t\t\t***************************************************\n";
        cout<<"\n\n\t\t\t\t\t\tBANK MANAGEMENT SYSTEM"<<endl;
        cout << "\n\t\t\t\t___________________________________________________";
                cout << "\n\t\t\t\t***************************************************\n";
        cout<<"\t\t\t\t\t\tProject By:"<<endl<<"\t\t\t\t\t\t           Aishwarya s"<<endl<<"\t\t\t\t\t\t           Apeksha s"<<endl<<"\t\t\t\t\t\t           Nehal Modi"<<endl<<"\t\t\t\t\t\t           V N Pratiksha"<<endl;
        std::cin. get();

        for (;;)
        {
                system("color F");
                system("cls");




                cout << "\n\n\n\n\t\t\t\t\t\tPress 1 to Create New Account";
                cout << "\n\t\t\t\t\t\tPress 2 to Deposit Funds";
                cout << "\n\t\t\t\t\t\tPress 3 to Withdraw Funds";
                cout << "\n\t\t\t\t\t\tPress 4 to Check Balance";
                cout << "\n\t\t\t\t\t\tPress 5 to View All Account Holder";
                cout << "\n\t\t\t\t\t\tPress 6 to Close an Account";
                cout << "\n\t\t\t\t\t\tPress 7 to Modify an Account";
                cout << "\n\t\t\t\t\t\tPress 8 to Exit the Program";
                cout << "\n\t\t\t\t\t_________________________________________________";
                cout << "\n\t\t\t\t\t*************************************************\n";

                cout << "\n\t\t\t\t\t\tOption: ";
                cin >> opt;
                system("cls");
                switch (opt)
                {
                case '1':
                        system("color A");
                        write_account();
                        break;
                case '2':
                        system("color B");
                        label10:
						cout << "\n\n\tEnter The account No. : ";
                        cin >> num;
                        cin.ignore();




                        if(cin.fail())
				        {
				        	cin.clear();
				        	cin.ignore(512,'\n');
				        	cout<<"\nPlease enter appropriate account no.!!\n\n";
				        	goto label10;
						}


                        deposit_withdraw(num, 1);
                        break;
                case '3':
                        system("color E");
                        label13:
						cout << "\n\n\tEnter The account No. : ";
                        cin >> num;
                        if(cin.fail())
				        {
				        	cin.clear();
				        	cin.ignore(512,'\n');
				        	cout<<"\nEnter valid account number!!\n\n";
				        	goto label13;
						}
                        deposit_withdraw(num, 2);
                        break;
                case '4':
                        system("color A");
                        label5:
						cout << "\n\n\tEnter The account No. : ";
                        cin >> num;
                        if(cin.fail())
				        {
				        	cin.clear();
				        	cin.ignore(512,'\n');
				        	cout<<"\t\tPlease enter a valid value ";
				        	goto label5;
						}
                        display_sp(num);
                        break;
                case '5':
                        system("color B");
                        display_all();
                        break;
                case '6':
                        system("color E");
                        label7:
						cout << "\n\n\tEnter The account No. : ";
                        cin >> num;

                        if(cin.fail())
				        {
				        	cin.clear();
				        	cin.ignore(512,'\n');
				        	cout<<"\t\tPlease enter a valid value ";
				        	goto label7;
						}
                        delete_account(num);
                        break;
                case '7':
                        system("color A");
                        label8:
						cout << "\n\n\tEnter The account No. : ";
                        cin >> num;
                        if(cin.fail())
				        {
				        	cin.clear();
				        	cin.ignore(512,'\n');
				        	cout<<"\t\tPlease enter a valid value ";
				        	goto label8;
						}

                        modify_account(num);
                        break;
                case '8':
                        system("color B");
                        cout << "\n\n\tThanks for using Bank Management System";
                        break;
                default:
                		 system("color E");
                        cout << "Invalid Option\n";
                }
                cin.ignore();
                cin.get();
                if (opt == '8')
                        break;
        }
        return 0;
}

void write_account()
{
        account ac;
        ofstream outFile;
        outFile.open("account.dat", ios::binary | ios::app);
        ac.create_account();
        outFile.write(reinterpret_cast<char *>(&ac), sizeof(account));
        outFile.close();
}

void display_sp(int n)
{
		int b,num2;
        account ac;
        bool flag = false;
        ifstream inFile;
        inFile.open("account.dat", ios::binary);
        if (!inFile)
        {
                cout << "File could not be open !! Press any Key...";
                return;
        }


        while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(account)))
        {
                if (ac.get_accountnumber() == n)
                {
                        ac.show_account();
                        flag = true;
                }
        }
        inFile.close();
        if (flag == false){

                cout << "\n\nAccount number does not exist"<<endl;
                cout<<"Press  5 to enter the account no. again & any other number to go main menu: ";
				cin>>b;
				if(b==5){

				  label12:
                cout << "\n\n\tEnter The account No. : ";
                        cin >> num2;
                        cin.ignore();




                        if(cin.fail())
				        {
				        	cin.clear();
				        	cin.ignore(512,'\n');
				        	cout<<"\t\tPlease enter a valid value ";
				        	goto label12;
						}

						display_sp(num2);
                        }}
}

void modify_account(int n)
{
        bool found = false;
        account ac;
        fstream File;
        File.open("account.dat", ios::binary | ios::in | ios::out);
        if (!File)
        {
                cout << "File could not be open !! Press any Key...";
                return;
        }
        while (!File.eof() && found == false)
        {
                File.read(reinterpret_cast<char *>(&ac), sizeof(account));
                if (ac.get_accountnumber() == n)
                {
                        ac.show_account();
                        cout << "\n\nEnter The New Details of account: " << endl;
                        ac.modify_account();
                        int pos = (-1) * static_cast<int>(sizeof(account));
                        File.seekp(pos, ios::cur);
                        File.write(reinterpret_cast<char *>(&ac), sizeof(account));
                        cout << "\n\n\t Record Updated...";
                        found = true;
                }
        }
        File.close();
        if (found == false)
           {
				     cout << "\n\n Record Not Found ";
				    }
}

void delete_account(int n)
{
		bool found = false;
        account ac;
        ifstream inFile;
        ofstream outFile;
        inFile.open("account.dat", ios::binary);
        if (!inFile)
        {
                cout << "File could not be open !! Press any Key...";
                return;
        }
        outFile.open("Temp.dat", ios::binary);
        inFile.seekg(0, ios::beg);
        while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(account)))
        {
                if (n!=ac.get_accountnumber() )
                {


                    outFile.write(reinterpret_cast<char *>(&ac), sizeof(account));
                }
                else{

                found=true;
				}
        }
        if(found==false)
        {
        		cout<<"\n\n\n\tRecord not found"<<endl;
		}
		else
		{
			cout << "\n\n\tRecord Deleted..."<<endl;
		}


        inFile.close();
        outFile.close();
        remove("account.dat");
        rename("Temp.dat", "account.dat");

		cout<<"Press enter to continue";
        cin.ignore();
        int getch();
}

void display_all()
{
        int bankPassword = 111, enteredPassword;
        label6:cout << "Enter the BANK PASSWORD: \n";
        cin >> enteredPassword;
        if(cin.fail())
        {
        	cin.clear();
        	cin.ignore(512,'\n');
        	cout<<"\t\tPlease enter a valid value "<<endl;
        	goto label6;
		}

        if (enteredPassword == bankPassword)
        {
                account ac;
                ifstream inFile;
                inFile.open("account.dat", ios::binary);
                if (!inFile)
                {
                        cout << "File could not be open !! Press any Key...";
                        return;
                }

                cout << "\n\n\t\tACCOUNT HOLDER LIST\n\n";
                cout << "=======================================================================\n";
                cout << "Account No.      Name                       Type                Balance\n";
                cout << "========================================================================\n";
                while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(account)))
                {
                        ac.get_report();
                }
                inFile.close();
                cout<<"\npress Enter for main menu"<<endl;


        }
        else {
                cout << "Please enter the correct password.\n";
                goto label6;
        }
}

void deposit_withdraw(int n, int option)
{

        int amt,num1,a,bal;
        bool found = false;
        account ac;
        fstream File;
        File.open("account.dat", ios::binary | ios::in | ios::out);
        if (!File)
        {
                cout << "File could not be open !! Press any Key...";
                return;
        }
        while (!File.eof() && found == false)
        {
                File.read(reinterpret_cast<char *>(&ac), sizeof(account));
                if (ac.get_accountnumber() == n)
                {
                        ac.show_account();
                        if (option == 1)
                        {
                                cout << "\n\n\tTO DEPOSITE AMOUNT ";
                               label3:
							    cout << "\n\nEnter The amount to be deposited: ";
                                cin >> amt;
                                if(cin.fail())
						        {
						        	cin.clear();
						        	cin.ignore(512,'\n');
						        	cout<<"\t\tPlease enter a valid value ";
						        	goto label3;
								}
                                ac.deposit_funds(amt);
                        }
                        if (option == 2)
                        {
                                cout << "\n\n\tTO WITHDRAW AMOUNT ";
                                label4:
								cout << "\n\nEnter The amount to be withdraw: ";
                                cin >> amt;
                                if(cin.fail())
						        {
						        	cin.clear();
						        	cin.ignore(512,'\n');
						        	cout<<"\t\tPlease enter a valid value ";
						        	goto label4;
								}

                                 bal = ac.get_funds() - amt;
                                if ((bal < 500 && ac.get_accounttype() == 'S') || (bal < 1000 && ac.get_accounttype() == 'C'))
                                        {
                                        cout << "Insufficient balance"<<endl;

										}

                                else
                                        ac.draw_funds(amt);


                        }
                        int pos = (-1) * static_cast<int>(sizeof(ac));
                        File.seekp(pos, ios::cur);
                        File.write(reinterpret_cast<char *>(&ac), sizeof(account));


                        cout<<"Press Enter for main menu\t";
                        found = true;
                }

        }
        File.close();
        if (found == false)
                {
				cout << "\n\n Account Not Found "<<endl<<"Please enter valid account number!!"<<"\n";
				cout<<"Press  5 to enter the account no. again & any other number to go main menu: ";
				cin>>a;
				if(a==5){

				  label11:
                cout << "\n\n\tEnter The account No. : ";
                        cin >> num1;
                        cin.ignore();




                        if(cin.fail())
				        {
				        	cin.clear();
				        	cin.ignore(512,'\n');
				        	cout<<"\t\tPlease enter a valid value ";
				        	goto label11;
						}


                        deposit_withdraw(num1, option);}

				}

}
