#include"checking.h"
#include<iostream>
Checking::Checking(string acntNo,double balan):Account(acntNo,balan),remittance(other){}
/*void Checking::dispaly()const
{
	std::cout << "Checking";
	Account::display();
}*/
void Checking::withdrawal(double amount)
	{
		if (remittance == remitByPost)
			amount += 30;
		if (remittance == remitByCable)
			amount += 60;
		if (balance < amount)
			std::cout << "Insufficient funds wirhdrawal:" << amount << "\n";
		else
			balance -= amount;
	}