#ifndef _BOOK_H
#define _BOOK_H
#include<iostream>
#include<vector>
using namespace std;
//设置book基类
struct BOOKINFO
{
	string name;
	string ZuoZhe;
	//此处可以添加更多的书本固有信息，如出版社，出版年等
};
class Book//设置基类book类
{
protected:
	string BookName;
	bool RuKu;//判断书本是否入库
	bool Status;//判断书本状态，是否借阅
	BOOKINFO bookinfo;
	vector <string> BookLog;//书籍借阅日志
public:
	Book(string name1, BOOKINFO bookinfo1) :BookName(name1), bookinfo(bookinfo1), RuKu(false),Status(false) {}//构造函数
	void BookInitialize( )//入库函数
	{
		RuKu = true;
		Status=true;
		BookLog.push_back("图书入库成功");
	}
	void showBookInfo()//打印图书固有信息，如出版年限等
	{
		cout << "图书名字" << bookinfo.name << "\n" << "作者" << bookinfo.ZuoZhe << endl;
	}
	bool getRuKU()//查询是否入库
	{
		return RuKu;
	}
	bool getStatus()const//获取图书状态
	{
		return Status;
	}
	void addLog(string newLog)
	{
		BookLog.push_back(newLog);
	}
	void showLog()//打印日志，生成借书情况
	{
		cout << BookName << "    图书日志：" << endl;
		for (vector<string>::iterator it = BookLog.begin();it != BookLog.end();++it)
		{
			cout << (*it) << endl;
		}
	}
};

class GeneralBook :public Book
{
private:
	int BorrowDays;//借书周期
public:
	GeneralBook(string name1, BOOKINFO bookinfo,int Borrowdays):Book(name1,bookinfo),BorrowDays(Borrowdays){}
	int BorrowBooK()//结束函数
	{
		if (GeneralBook::Status ==true&&GeneralBook::RuKu==true)
		{
			Status = false;
			cout <<"普通图书"<<BookName<<"借出成功，您拥有90天的借书周期" << endl;
			addLog("借出成功");
			return 1;
		}
		else
		{
			cerr << "普通图书" << BookName << "借出失败！" << endl;
			addLog("图书借出失败");
			return 0;
		}
	}
	int ReturnBook()
	{
		if (GeneralBook::Status == false && RuKu == true)
		{
			if (BorrowDays < 90) {
				Status = true;
				cout << "普通图书" << BookName << "归还成功" << endl;
				addLog("归还成功");
				return 1;
			}else
			{
				cout << "你的图书已超期,将从您的校园卡内扣除相应超期费" << endl;
			//假设这里有一个校园卡类，这里的操作是调用校园卡类的一个扣费函数，然后在图书馆账户类通过对应函数加钱
				cout << "扣费成功，还书成功" << endl;
				addLog("用户在完成超期后付费完成还书");
				Status = true;
				return 1;
			}
		}
		else
		{
			cerr << "普通图书" << BookName << "归还失败！" << endl;
			addLog("图书归还失败");
			cerr << "请联系图书管理员处理" << endl;
			return 0;
		}
	}
	int BorrowRead()//借阅图书函数
	{

		if (GeneralBook::Status == true && GeneralBook::RuKu == true)
		{
			cout << "你已可在图书馆阅读，阅读后请放回原位" << endl;
			return 1;
		}
		else
		{
			cout << "非常抱歉，此书已借出" << endl;
			return 0;
		}
	}
	void ScrapBook()//图书报废函数
	{
		RuKu=false;
		cout << "图书已经报废" << endl;
		addLog("图书报废");
	}
};
class Magazine :public Book
{
public:
	Magazine(string name1, BOOKINFO bookinfo) :Book(name1, bookinfo){}
	int BorrowRead()//借阅图书函数
	{

		if (Magazine::RuKu == true)
		{
			cout << "你已在图书馆阅读本杂志，阅读后请放回原位" << endl;
			return 1;
		}
		else
		{
			cout << "非常抱歉，此杂志借阅失败" << endl;
			return 0;
		}
	}
};
class SpecialBooks :public Book
{
public:
	SpecialBooks(string name1, BOOKINFO bookinfo) :Book(name1, bookinfo) {}
	int BorrowRead()//借阅图书函数
	{

		if (SpecialBooks::RuKu == true)
		{
			cout << "你已在图书馆阅读书籍，并且可以选择复印本特别书籍，阅读后请放回原位" << endl;
			return 1;
		}
		else
		{
			cout << "非常抱歉，此书籍借阅失败" << endl;
			return 0;
		}
	}


};
#endif





