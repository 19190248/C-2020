#include<iostream>
#include"BOOK.h"
using namespace std;

BOOKINFO book1 = { "c++","QWG" }, book2 = { "数据结构","XXK" }, book3 = { "离散数学","tsinghua" }, book4 = {"电子电路","YRX"};

int main()

{
	//初始化各种书目
	GeneralBook Book1("C++",book1, 0);
	Magazine Book2("数据结构", book2);
	SpecialBooks Book3("离散数学", book3);

	//图书入库
	Book1.BookInitialize();//cout << Book1.getRuKU() << endl;
	Book2.BookInitialize();//cout << Book2.getRuKU() << endl;
	Book3.BookInitialize();//cout << Book3.getRuKU() << endl;
	cout << "入库成功，图书1操作：" << endl << endl << endl;
	//图书1的操作
	int success = 0;
	Book1.showBookInfo();//查看图书信息
	success = Book1.BorrowBooK();//借出图书
	success = Book1.ReturnBook();//还书
	success = Book1.BorrowRead();//借阅
	Book1.ScrapBook();//图书报废处理
	Book1.showLog();//打印图书借阅日志

	//图书2的操作
	cout << "\n"<<"杂志操作："  << endl;
	Book2.showBookInfo();
	success = Book2.BorrowRead();
	 Book2.showLog();

	 cout << "\n" << "特殊书籍借阅操作" << endl;
	 Book3.showBookInfo();
	 success = Book3.BorrowRead();
	 Book3.showLog();

	 return 0;
}
