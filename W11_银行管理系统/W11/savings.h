#pragma once
#ifndef _SAVINGS_H
#define _SAVINGS_H
#include<string>
#include"account.h"
using namespace std;
class Savings :public Account
{
public :
	Savings(string acntNo, double balan = 0.0) :Account(acntNo, balan)
	{
	}
	void display()const
	{
		cout << "Savings:";
		Account::display();
	}
	void withdrawal(double amount);
};
#endif // !_SAVINGS_H

