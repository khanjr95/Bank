#include <iostream>
#include "Account.h"
#include "Bank.h"
#include "Customer.h"
using namespace std;

Bank bank = Bank("Awesome Bank");

void AddAccountMenu();
void transactionMenu();
void DisplayAccountsMenu();


int main()
{
	DisplayMenu();

	system("pause");
	return 0;
}

void DisplayMenu()
{
	int choice = 0;;
	do
	{
	system("cls");
	cout << "Welcome to " << bank.getName() << endl;
	cout << "1) Add Account" << endl;
	cout << "2) Transaction" << endl;
	cout << "3)Display Accounts" << endl;
	cout << "What would you like to do? " << endl;
	
	
	cin >> choice;

	switch (choice)
	{
	case 1: AddAccountMenu(); break;
	case 2: transactionMenu(); break;
	case 3: DisplayAccountsMenu(); break;
	default: break;
	}

	} while (choice != 10);

}

void AddAccountMenu()
{
	system("cls");
	cout << "Customer First Name: ";
	string firstName;
	cin >> firstName;

	cout << "Customer Last Name: ";
	string lastName;
	cin >> lastName;

	cout << "Account Number: ";
	int accountNumber;
	cin >> accountNumber;

	Customer customer = Customer(firstName, lastName);
	Account newAccount = Account(customer, accountNumber);
	bank.CreateAccount(newAccount);
}

void transactionMenu()
{
	system("cls");
	cout << "Which Account?" << endl;
	cout << bank.ListAccounts() << endl;

	int chosenAccount;
	cin >> chosenAccount;

	system("cls");
	cout << "1) Deposit" << endl;
	cout << "2)Withdraw" << endl;

	int transactiontype;
	cin >> transactiontype;

	system("cls");
	cout << "How many pennies?" << endl;
	int pennies;
	cin >> pennies;

	switch (transactiontype)
	{
	case 1:bank.Deposit(chosenAccount, pennies); break;
	case 2:bank.Withdraw(chosenAccount, pennies); break;
	default:break;
	}

}

void DisplayAccountsMenu()
{
	system("cls");
	cout << bank.ShowAccounts << endl;
	system("pause");
}
