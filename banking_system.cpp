#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <map>
using namespace std;

#define MIN_BALANCE 500

class Insufficient_Funds
{
};

class Account
{
private:
    long account_Number;
    string first_Name;
    string last_Name;
    float balance;
    static long Next_Account_Number;

public:
    Account() {}
    Account(string first_name, string lats_name, float balance);
    long getAccNo() { return account_Number; }
    string getFirstName() { return first_Name; }
    string getLastName() { return last_Name; }
    float getBalance() { return balance; }

    void Deposit(float amount);
    void Withdraw(float amount);

    static void setLastAccountNumber(long account_Number);
    static long getLastAccountNumber();

    friend ofstream &operator<<(ofstream &ofs, Account &acc);
    friend ifstream &operator>>(ifstream &ifs, Account &acc);
    friend ostream &operator<<(ostream &os, Account &acc);
};

long Account::Next_Account_Number=0;
class Bank
{
private:
    map<long, Account> accounts;

public:
    Bank();
    Account OpenAccount(string fName, string lName, float balance);
    Account BalanceEnquiry(long account_Number);
    Account Deposit(long account_Number, float amount);
    Account Withdraw(long account_Number, float amount);
    void CloseAccount(long account_Number);
    void ShowAllAccounts();
    int CheckingAccNo(long account_Number);
    ~Bank();
};
int main()
{
    Bank b;
    Account acc;

    int choice,check;
    string first_name, lats_name;
    long account_Number;
    float balance;
    float amount;
    
    do
    {

        cout << "***Banking System***" << endl;
        cout << "\n\t1.Opening an account" << endl;
        cout << "\t2.balance Enquiry" << endl;
        cout << "\t3.Deposit" << endl;
        cout << "\t4.Withdrawal" << endl;
        cout << "\t5.Close an Account" << endl;
        cout << "\t6.Show All Accounts" << endl;
        cout << "\t7.Quit" << endl;

        cout << "Enter your choice =";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter First  Name =";
            cin >> first_name;
            cout << "Enter Last   Name =";
            cin >> lats_name;
            cout << "Enter Initil balance =";
            cin >> balance;

            acc = b.OpenAccount(first_name, lats_name, balance);
            cout << "\nCongradulation Back Account is Created." << endl;
            cout << acc << endl;
            cout<<"--X----X----X----X----X----X----X----X----X----X----X----X----X----X----X----X----X----X----X----X--"<<endl;
            break;

        case 2:
            cout << "Enter Bank Account number =";
            cin >> account_Number;

            check=b.CheckingAccNo(account_Number);
            if(check==1)
            {
                acc = b.BalanceEnquiry(account_Number);
                cout << "\nAccount number " << account_Number << " Bank Account Details" << endl;
                cout << acc << endl;
                cout<<"--X----X----X----X----X----X----X----X----X----X----X----X----X----X----X----X----X----X----X----X--"<<endl;
            break;
            }
            else
            {
                cout<<"Invalid Bank Account Number\n"<<endl;
                cout<<"--X----X----X----X----X----X----X----X----X----X----X----X----X----X----X----X----X----X----X----X--"<<endl;
                break;
            }

        case 3:
            cout << "Enter Bank Account number =";
            cin >> account_Number;

            check=b.CheckingAccNo(account_Number);
            if(check==1)
            {
                cout << "Enter balance =";
                cin >> amount;

                acc = b.Deposit(account_Number, amount);
                cout << "\nAmount is Deposited" << endl;
                cout << acc << endl;
                cout<<"--X----X----X----X----X----X----X----X----X----X----X----X----X----X----X----X----X----X----X----X--"<<endl;
                break;
            }
            else
            {
                cout<<"Invalid Bank Account Number\n"<<endl;
                cout<<"--X----X----X----X----X----X----X----X----X----X----X----X----X----X----X----X----X----X----X----X--"<<endl;
                break;
            }
            

        case 4:
            cout << "Enter Bank Account number =";
            cin >> account_Number;

            check=b.CheckingAccNo(account_Number);
            if(check==1)
            {
                cout << "Enter balance =";
                cin >> amount;

                acc = b.Withdraw(account_Number, amount);
                cout << "\nAmount is Withdraw" << endl;
                cout << acc << endl;
                cout<<"--X----X----X----X----X----X----X----X----X----X----X----X----X----X----X----X----X----X----X----X--"<<endl;
                break;
            }
            else
            {
                cout<<"Invalid Bank Account Number\n"<<endl;
                cout<<"--X----X----X----X----X----X----X----X----X----X----X----X----X----X----X----X----X----X----X----X--"<<endl;
                break;
            }


        case 5:
            cout << "Enter the Bank Account number=";
            cin >> account_Number;

            check=b.CheckingAccNo(account_Number);

            if(check==1)
            {
                b.CloseAccount(account_Number);
                cout << "\nThis amount is close" << endl;
                cout<<"--X----X----X----X----X----X----X----X----X----X----X----X----X----X----X----X----X----X----X----X--"<<endl;
            break;
            }
            else
            {
                cout<<"Invalid Bank Account Number\n"<<endl;
                cout<<"--X----X----X----X----X----X----X----X----X----X----X----X----X----X----X----X----X----X----X----X--"<<endl;
                break;
            }

        case 6:
            cout<<"\n--X----X----X----X----X----X----Showing All Bank Accounts --X----X----X----X----X----X----"<<endl;
            b.ShowAllAccounts();
            cout<<"--X----X----X----X----X----X----X----X----X----X----X----X----X----X----X----X----X----X----X----X--"<<endl;
            break;

        case 7:break;

        default:
            cout << "\nInvalid choice ,Please Enter valid choice" << endl;
            break;
        }
    } while (choice != 7);

    return 0;
}

Account::Account(string first_name, string lats_name, float balance)
{
    Next_Account_Number++;
    account_Number = Next_Account_Number;
    first_Name = first_name;
    last_Name = lats_name;
    this->balance = balance;
}

void Account::Deposit(float amount)
{
    balance += amount;
}

void Account::Withdraw(float amount)
{
    if (balance - amount < MIN_BALANCE)
    {
        throw Insufficient_Funds();
    }
    balance -= amount;
}

void Account::setLastAccountNumber(long account_Number)
{
    Next_Account_Number = account_Number;
}

long Account::getLastAccountNumber()
{
    return Next_Account_Number;
}

ofstream &operator<<(ofstream &ofs, Account &acc)
{
    ofs << acc.account_Number << endl;
    ofs << acc.first_Name << endl;
    ofs << acc.last_Name << endl;
    ofs << acc.balance << endl;

    return ofs;
}

ifstream &operator>>(ifstream &ifs, Account &acc)
{
    ifs >> acc.account_Number;
    ifs >> acc.first_Name;
    ifs >> acc.last_Name;
    ifs >> acc.balance;
    return ifs;
}

ostream &operator<<(ostream &os, Account &acc)
{
    os << "Account Number =" << acc.getAccNo() << endl;
    os << "First   Name   =" << acc.getFirstName() << endl;
    os << "Last    Name   =" << acc.getLastName() << endl;
    os << "Balance        =" << acc.getBalance() << endl;
    return os;
}

Bank::Bank()
{

    Account account;
    ifstream infile;
    infile.open("Bank.data");
    if (!infile)
    {
        cout<<"Error in Opening! File Not Found!!"<<endl;
        return;
    }
    while (!infile.eof())
    {
        infile >> account;
        accounts.insert(pair<long, Account>(account.getAccNo(), account));
    }
    Account::setLastAccountNumber(account.getAccNo());

    infile.close();
}

Account Bank::OpenAccount(string first_Name, string last_Name, float balance)
{
    ofstream outfile;
    Account account(first_Name, last_Name, balance);
    accounts.insert(pair<long, Account>(account.getAccNo(), account));

    outfile.open("Bank.data", ios::trunc);

    map<long, Account>::iterator iter;

    for (iter = accounts.begin(); iter != accounts.end(); iter++)
    {
        outfile << iter->second;
    }

    return account;
}

Account Bank::BalanceEnquiry(long Account_Number)
{
    map<long, Account>::iterator iter = accounts.find(Account_Number);

    return iter->second;
}

Account Bank::Deposit(long Account_Number, float amount)
{
    map<long, Account>::iterator iter = accounts.find(Account_Number);
    iter->second.Deposit(amount);

    return iter->second;
}

Account Bank::Withdraw(long account_Number, float amount)
{
    map<long, Account>::iterator iter = accounts.find(account_Number);
    iter->second.Withdraw(amount);

    return iter->second;
}

void Bank::CloseAccount(long account_Number)
{
    map<long, Account>::iterator iter = accounts.find(account_Number);
    cout << "Bank Account is Delected." << iter->second;
    accounts.erase(account_Number);
}

void Bank::ShowAllAccounts()
{
    map<long, Account>::iterator iter;

    for (iter = accounts.begin(); iter != accounts.end(); iter++)
    {
        cout << "Account " << iter->first << endl
             << iter->second << endl;
    }
}

Bank::~Bank()
{
    ofstream outfile;
    outfile.open("Bank.data", ios::trunc);

    map<long, Account>::iterator iter;

    for (iter = accounts.begin(); iter != accounts.end(); iter++)
    {
        outfile << iter->second << endl;
    }

    outfile.close();
}

int Bank::CheckingAccNo(long account_Number)
{
    auto search=accounts.find( account_Number);
    if(search!=accounts.end())
    {
        return 1;
    }
    else
    {
        return 0;
    }
}