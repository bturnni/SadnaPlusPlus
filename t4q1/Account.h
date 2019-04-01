#include "clock.h"
#pragma once

class Account
{
private:
	int accountNumber;
	int code;
	float balance;
	static int sumWithdraw;
	static int sumDeposit;
public:
	Account() 
		:accountNumber(0), code(0), balance(0) {};
	Account(int mAccountNumber, int mCode, float mBalance) 
		:accountNumber(mAccountNumber), code(mCode), balance(mBalance) {};
	~Account();
#pragma region gets,sets
	int getAccountNumber();
	int getCode();
	float getBalance();
	void setBalance(float);
#pragma endregion
	friend std::istream& operator>> (std::istream&, Account&);//input
	void withdraw(int nis);//max 2500, when this+balance<6000 sumWithdraw++
	void deposit(int);//max 10000 sumdeposit++;

	static int getSumWithdraw();
	static int getSumDeposit();

};

