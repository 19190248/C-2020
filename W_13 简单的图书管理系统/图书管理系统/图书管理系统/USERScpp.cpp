#include<iostream>
#include"BOOK.h"
using namespace std;

BOOKINFO book1 = { "c++","QWG" }, book2 = { "���ݽṹ","XXK" }, book3 = { "��ɢ��ѧ","tsinghua" }, book4 = {"���ӵ�·","YRX"};

int main()

{
	//��ʼ��������Ŀ
	GeneralBook Book1("C++",book1, 0);
	Magazine Book2("���ݽṹ", book2);
	SpecialBooks Book3("��ɢ��ѧ", book3);

	//ͼ�����
	Book1.BookInitialize();//cout << Book1.getRuKU() << endl;
	Book2.BookInitialize();//cout << Book2.getRuKU() << endl;
	Book3.BookInitialize();//cout << Book3.getRuKU() << endl;
	cout << "���ɹ���ͼ��1������" << endl << endl << endl;
	//ͼ��1�Ĳ���
	int success = 0;
	Book1.showBookInfo();//�鿴ͼ����Ϣ
	success = Book1.BorrowBooK();//���ͼ��
	success = Book1.ReturnBook();//����
	success = Book1.BorrowRead();//����
	Book1.ScrapBook();//ͼ�鱨�ϴ���
	Book1.showLog();//��ӡͼ�������־

	//ͼ��2�Ĳ���
	cout << "\n"<<"��־������"  << endl;
	Book2.showBookInfo();
	success = Book2.BorrowRead();
	 Book2.showLog();

	 cout << "\n" << "�����鼮���Ĳ���" << endl;
	 Book3.showBookInfo();
	 success = Book3.BorrowRead();
	 Book3.showLog();

	 return 0;
}
