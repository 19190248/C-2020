#pragma once
#ifndef CHECKING_H_
#define CHECKING_H_
#include"account.h"
enum REMIT{remitByPost, remitByCable, other};
class Checking :public Account
{
	REMIT remittance;
public:
	Checking(string acntNo, double balan = 0.0);
	void withdrawal(double amount);
	void display()const
	{
		std::cout << "Checking";
		Account::display();
	}
	void setRemit(REMIT re)
	{
		remittance = re;
	}
};
#endif // !CHECKING_H_

