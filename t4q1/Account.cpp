#include "Account.h"



Account::~Account()
{
}

int Account::getAccountNumber()
{
	return accountNumber;
}

int Account::getCode()
{
	return code;
}

float Account::getBalance()
{
	return balance;
}

void Account::setBalance(float mBalance)
{
	balance = mBalance;
}

void Account::withdraw(int nis)
{

	if ((balance-nis) > -6000)
	{
		if (nis<2500)
		{
			balance -= nis;
			sumWithdraw+=nis;
		}
		else
		{
			throw "ERROR: cannot withdraw more than 2500 NIS!\n";

		}
	}
	else
	{
		throw "ERROR: cannot have less than - 6000 NIS!\n";
	}
}

void Account::deposit(int dep)
{
	if (dep <= 10000)
	{
		balance += dep;
		sumDeposit+=dep;
	}
	else
	{
		throw "ERROR: cannot deposit more than 10000 NIS!\n";
	}
}

int Account::getSumWithdraw()
{
	return sumWithdraw;
}

int Account::getSumDeposit()
{
	return sumDeposit;
}

std::istream& operator>>(std::istream& input, Account& a)
{
	string str;
	input >> str;
	a.accountNumber = atoi(str.data());
	input >> str;
	a.code = atoi(str.data());
	return input;
}
int Account::sumDeposit = 0;

int Account::sumWithdraw = 0;
