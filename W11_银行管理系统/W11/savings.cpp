#include"savings.h"
#include<iostream>
/*void Savings::display()const
{
	cout << "Savings:";
	Account::dispaly();
}*/
void Savings::withdrawal(double amount)
{
	if (balance < amount)
		cout << "Insufficient funds withdrawal:" << amount << "\n";
	else
		balance -= amount;
}