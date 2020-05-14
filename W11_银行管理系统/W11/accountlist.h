#pragma once
#ifndef ACCOUNTLIST_H_
#define ACCOUNTLIST_H_
#include"account.h"
class Node
{
public:
	Account& acnt;
	Node* next,*prev;
	Node(Account& a) :acnt(a), next(0), prev(0){}
	bool operator ==(const Node& n)const
	{
		return acnt == n.acnt;
	}
};
class AccountList
{
	int size;
	Node* first;
public:
	AccountList():first(0),size(0){}
	Node* getFirst()const
	{
		return first;
	}
	int getSize()const
	{
		return size;
	}
	void add(Account& a);
	void remove(string acntNo);
	Account* find(string acntNo)const;
	bool isEmpty()const
	{
		return !size;
	}
	void display()const
	{
		cout << "There are" << size << " accounts.\n";
		for (Node* p = first; p; p = p->next)
			(p->acnt).display();
	}
	~AccountList();
};
#endif // !ACCOUNTLIST_H_
