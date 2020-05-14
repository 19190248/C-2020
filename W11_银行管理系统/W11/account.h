#pragma once
#ifndef  _ACCOUNT_H
#define  _ACCOUNT_H
#include<string>
#include<iostream>
using namespace std;
class Account
{
protected:
	string acntNumber;//’À∫≈
	double balance;//”‡∂Ó
public:
	Account(string acntNo, double balan = 0.0);
	virtual void display()const
	{
		cout << "Account:" + acntNumber + "=" << balance << "\n";
	}
	double getBalan()const
	{
		return balance;
	}
	void deposit(double amount)
	{
		balance += amount;
	}
	bool operator== (const Account & a) 
	{
		return acntNumber == a.acntNumber;
	}
	string getAcntNo()
	{
		return acntNumber;
	}
	virtual void withdrawal(double amount) = 0;
};
#endif // ! _ACCOUNT_H

