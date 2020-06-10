#ifndef _BOOK_H
#define _BOOK_H
#include<iostream>
#include<vector>
using namespace std;
//����book����
struct BOOKINFO
{
	string name;
	string ZuoZhe;
	//�˴�������Ӹ�����鱾������Ϣ��������磬�������
};
class Book//���û���book��
{
protected:
	string BookName;
	bool RuKu;//�ж��鱾�Ƿ����
	bool Status;//�ж��鱾״̬���Ƿ����
	BOOKINFO bookinfo;
	vector <string> BookLog;//�鼮������־
public:
	Book(string name1, BOOKINFO bookinfo1) :BookName(name1), bookinfo(bookinfo1), RuKu(false),Status(false) {}//���캯��
	void BookInitialize( )//��⺯��
	{
		RuKu = true;
		Status=true;
		BookLog.push_back("ͼ�����ɹ�");
	}
	void showBookInfo()//��ӡͼ�������Ϣ����������޵�
	{
		cout << "ͼ������" << bookinfo.name << "\n" << "����" << bookinfo.ZuoZhe << endl;
	}
	bool getRuKU()//��ѯ�Ƿ����
	{
		return RuKu;
	}
	bool getStatus()const//��ȡͼ��״̬
	{
		return Status;
	}
	void addLog(string newLog)
	{
		BookLog.push_back(newLog);
	}
	void showLog()//��ӡ��־�����ɽ������
	{
		cout << BookName << "    ͼ����־��" << endl;
		for (vector<string>::iterator it = BookLog.begin();it != BookLog.end();++it)
		{
			cout << (*it) << endl;
		}
	}
};

class GeneralBook :public Book
{
private:
	int BorrowDays;//��������
public:
	GeneralBook(string name1, BOOKINFO bookinfo,int Borrowdays):Book(name1,bookinfo),BorrowDays(Borrowdays){}
	int BorrowBooK()//��������
	{
		if (GeneralBook::Status ==true&&GeneralBook::RuKu==true)
		{
			Status = false;
			cout <<"��ͨͼ��"<<BookName<<"����ɹ�����ӵ��90��Ľ�������" << endl;
			addLog("����ɹ�");
			return 1;
		}
		else
		{
			cerr << "��ͨͼ��" << BookName << "���ʧ�ܣ�" << endl;
			addLog("ͼ����ʧ��");
			return 0;
		}
	}
	int ReturnBook()
	{
		if (GeneralBook::Status == false && RuKu == true)
		{
			if (BorrowDays < 90) {
				Status = true;
				cout << "��ͨͼ��" << BookName << "�黹�ɹ�" << endl;
				addLog("�黹�ɹ�");
				return 1;
			}else
			{
				cout << "���ͼ���ѳ���,��������У԰���ڿ۳���Ӧ���ڷ�" << endl;
			//����������һ��У԰���࣬����Ĳ����ǵ���У԰�����һ���۷Ѻ�����Ȼ����ͼ����˻���ͨ����Ӧ������Ǯ
				cout << "�۷ѳɹ�������ɹ�" << endl;
				addLog("�û�����ɳ��ں󸶷���ɻ���");
				Status = true;
				return 1;
			}
		}
		else
		{
			cerr << "��ͨͼ��" << BookName << "�黹ʧ�ܣ�" << endl;
			addLog("ͼ��黹ʧ��");
			cerr << "����ϵͼ�����Ա����" << endl;
			return 0;
		}
	}
	int BorrowRead()//����ͼ�麯��
	{

		if (GeneralBook::Status == true && GeneralBook::RuKu == true)
		{
			cout << "���ѿ���ͼ����Ķ����Ķ�����Ż�ԭλ" << endl;
			return 1;
		}
		else
		{
			cout << "�ǳ���Ǹ�������ѽ��" << endl;
			return 0;
		}
	}
	void ScrapBook()//ͼ�鱨�Ϻ���
	{
		RuKu=false;
		cout << "ͼ���Ѿ�����" << endl;
		addLog("ͼ�鱨��");
	}
};
class Magazine :public Book
{
public:
	Magazine(string name1, BOOKINFO bookinfo) :Book(name1, bookinfo){}
	int BorrowRead()//����ͼ�麯��
	{

		if (Magazine::RuKu == true)
		{
			cout << "������ͼ����Ķ�����־���Ķ�����Ż�ԭλ" << endl;
			return 1;
		}
		else
		{
			cout << "�ǳ���Ǹ������־����ʧ��" << endl;
			return 0;
		}
	}
};
class SpecialBooks :public Book
{
public:
	SpecialBooks(string name1, BOOKINFO bookinfo) :Book(name1, bookinfo) {}
	int BorrowRead()//����ͼ�麯��
	{

		if (SpecialBooks::RuKu == true)
		{
			cout << "������ͼ����Ķ��鼮�����ҿ���ѡ��ӡ���ر��鼮���Ķ�����Ż�ԭλ" << endl;
			return 1;
		}
		else
		{
			cout << "�ǳ���Ǹ�����鼮����ʧ��" << endl;
			return 0;
		}
	}


};
#endif





