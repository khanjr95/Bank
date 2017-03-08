#include "Bank.h"

Bank::Bank(std::string name) : _name(name)
{
	//comment
}

Bank::~Bank()
{
}

std::string Bank::getName()
{
	return _name;
}

void Bank::CreateAccount(Account newAccount)
{
	_accounts.push_back(newAccount);
}

std::string Bank::ShowAccounts()
{
	std::string output = "Accounts for " + _name + "\n";
	for (auto account : _accounts)
	{
		output += std::to_string(account.getAccountNumber()) += "\n"; // how to get a int to be placed/converted into a string
	}
	return output;

	

}

std::string Bank::ListAccounts()
{
	std::string output = "Accounts for " + _name + "\n";
	int index = 0;
	for (Account account : _accounts)
	{
		output += std::to_string(account.getAccountNumber()) += "\n";
		index++;
	}
	return std::string();
}

void Bank::Withdraw(int accountNumber, int amount)
{
	for (Account account : _accounts)
	{
		if (account.getAccountNumber() == accountNumber)
		{
			account.Withdraw(amount);
			return;
		}
	}
}

void Bank::Deposit(int accountNumber, int amount)
{
	for (Account account : _accounts)
	{
		if (account.getAccountNumber() == accountNumber)
		{
			account.Deposit(amount);
			return;
		}
	}
	return;
}
