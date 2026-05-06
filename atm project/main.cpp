#include <iostream>
using namespace std;

int accountNumbers[5] = {100, 200, 300, 400, 500};
double balance[5] = {1000.00, 1500.00, 200.00, 7500.00, 15000.00};

int accountIndex = -1;

void checkBalanceFunction()
{
    cout << "your balance is: " << balance[accountIndex]<< endl << endl;
}

void depositFunction()
{
    double amount;

    cout << "Enter Deposit Amount: ";
    cin  >> amount;

    if(amount > 0)
        balance[accountIndex] += amount;

    else
        cout << "Could not Complete the operation ,because of invalid amount value" <<endl << endl;

    cout << "Operation done successfully\n";
    checkBalanceFunction();
}

void withdrawFunction()
{
    double amount;
    int done = 0;

    cout << "Enter Withdraw Amount: ";
    cin  >> amount;

    if(balance[accountIndex] >= amount)
    {
        if(amount > 0)
        {
            balance[accountIndex] -= amount;
            done = 1;
        }

        else
            cout << "Could not Complete the operation ,because of invalid amount value" <<endl <<endl;
    }
    else
        cout << "You Don't have enough money" << endl;

    if (done == 1)
        cout << "Operation done successfully\n";

    checkBalanceFunction();
}

void transferFunction()
{
    int done = 0;
    double amount;
    int receiverIndex = -1;
    int receiverNumber;

    cout << "Type account number for the receiver: ";
    cin  >> receiverNumber;

    for(int i=0; i<5; i++)
    {
        if(receiverNumber == accountNumbers[i]&& i!=accountNumbers[i])
            receiverIndex = i;
    }

    if(receiverIndex == -1)
    {
        cout << "please enter valid account number" << endl << endl;
        return;
    }

    cout << "Type the amount for transfer: ";
    cin  >> amount;

    if(balance[accountIndex] >= amount)
    {
        if(amount > 0)
        {
            balance[accountIndex]  -= amount;
            balance[receiverIndex] += amount;
            done = 1;
        }
    }
    else
        cout << "You do not have enough money";

    if (done == 1)
        cout << "Operation done successfully\n";

    checkBalanceFunction();
}

int main()
{
    int isLoggin = 0;
    int currentAccountNumber;

    while(isLoggin == 0)
    {
        cout << "Enter you Account Number: ";
        cin  >> currentAccountNumber;
        cout << "" << endl;

        for(int i=0; i<5; i++)
        {
            if(currentAccountNumber == accountNumbers[i])
            {
                accountIndex = i;
                isLoggin = 1;
                break;
            }
        }

        if(isLoggin == 0)
            cout << "Wrong Account Number\n" << endl;
    }

    int choise;
    do
    {
        cout << "==============================" << endl;
        cout << "| [1] | Check Balance        |" << endl;
        cout << "| [2] | Deposit              |" << endl;
        cout << "| [3] | Withdraw             |" << endl;
        cout << "| [4] | Transfer             |" << endl;
        cout << "| [5] | Exit                 |" << endl;
        cout << "==============================" << endl;
        cin  >> choise;

        if(choise == 1)
            checkBalanceFunction();

        else if (choise == 2)
            depositFunction();

        else if (choise == 3)
            withdrawFunction();

        else if (choise == 4)
            transferFunction();

        else if (choise == 5)
            cout << "Thanks for using our ATM :)" << endl;

        else
            cout << "Wrong value" << endl;
    }
    while(choise != 5);

    return 0;
}
