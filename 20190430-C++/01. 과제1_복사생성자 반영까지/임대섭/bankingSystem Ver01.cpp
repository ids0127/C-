/*
	1. �ý��۸� : BankingSystem
	2. ����		: 1.0
	3. �����   : �Ӵ뼷
	4. ����
		4.1 OOP(��ü����) �ܰ躰 ������Ʈ�� �⺻ Ʋ ����

		1. ĸ��ȭ, �������� ����
		2, ������, �Ҹ��� ����
		3, ��ü �迭 ����
*/

#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;
const int TOTAL_ACC = 100;

void ShowMenu(void);        // �޴����
void MakeAccount(void);     // ���°���
void DepositMoney(void);    // �Ա�
void WithdrawMoney(void);   // ���
void ShowAllAccount(void);  // �ܾ���ȸ

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

class Account
{
private:
	int accID;      // ���¹�ȣ
	int balance;    // �ܾ�
	char* cusName;  // �����̸�
public:
	Account(int ID, int money, char* name)
		: accID(ID), balance(money)
	{
		int len = strlen(name) + 1;
		cusName = new char[len];
		strcpy_s(cusName, len, name);
	}
	Account(const Account &copy)
		:accID(copy.accID), balance(copy.balance)
	{
		cusName = new char[strlen(copy.cusName) + 1];
		strcpy(cusName, copy.cusName);
	}
	int GetAccID()
	{
		return accID;
	}
	void Deposit(int money)
	{
		balance += money;
	}
	int Withdraw(int money)
	{
		if (balance < money)
		{
			cout << "�ܾ׺���" << endl;
			return 0;
		}
		balance -= money;
		return money;
	}
	int GetBalance()
	{
		return balance;
	}
	void ShowAccInfor()
	{
		cout << "����ID: " << accID << endl;
		cout << "�̸�: " << cusName << endl;
		cout << "�ܾ�: " << balance << endl;
	}
	~Account()
	{
		delete[] cusName;
	}
};

Account* accArr[TOTAL_ACC];
int accNum = 0;

int main(void)
{
	int choice;

	while (1)
	{
		ShowMenu();
		cout << "����: ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case MAKE:
			MakeAccount();
			break;
		case DEPOSIT:
			DepositMoney();
			break;
		case WITHDRAW:
			WithdrawMoney();
			break;
		case INQUIRE:
			ShowAllAccount();
			break;
		case EXIT:
			for (int i = 0; i < accNum; i++)
			{
				delete accArr[i];
			}
			return 0;
		default:
			cout << "�߸��� �޴� ����" << endl;
		}
	}

	system("pause");  // VC++ ������ �ʿ�

	return 0;
}

void ShowMenu(void)
{
	cout << "----------Menum---------" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �Ա�" << endl;
	cout << "3. ���" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
}

void MakeAccount(void)
{
	int id;
	char name[NAME_LEN];
	int balance;

	cout << "[���°���]" << endl;
	cout << "����ID: ";	cin >> id;
	cout << "�̸�: ";	cin >> name;
	cout << "�Աݾ�: ";	cin >> balance;
	cout << endl;

	accArr[accNum++] = new Account(id, balance, name);
}

void DepositMoney(void)
{
	int money;
	int id;
	cout << "[�Ա�]" << endl;
	cout << "����ID: ";
	cin >> id;
	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			cout << "�Աݾ�: ";
			cin >> money;
			accArr[i]->Deposit(money);
			cout << "�Ա� �Ϸ�: " << endl;
			return;
		}
	}
	cout << "�߸��� ���� ��ȣ �Է�. " << endl;
}

void WithdrawMoney(void)
{
	int money;
	int id;
	cout << "[���]" << endl;
	cout << "����ID: ";
	cin >> id;
	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			if (accArr[i]->GetBalance() > 0)
			{
				cout << "��ݾ�: ";
				cin >> money;
				accArr[i]->Withdraw(money);
				return;
			}
			else
			{
				cout << "�ܾ� ���ڶ�" << endl;
			}
		}
	}
	cout << "�߸��� ���� ��ȣ �Է�. " << endl;
}

void ShowAllAccount(void)
{
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAccInfor();
		cout << endl;
	}
}