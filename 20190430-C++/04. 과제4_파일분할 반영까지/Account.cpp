#include "MiniBankingCommonDecl.h"
#include "Account.h"

//���� ��Ͽ� �ʿ��� ���� ���� ����
//������
Account::Account(int ID, int money, char* name)
	: accID(ID), balance(money)
{
	cusName = new char[strlen(name) + 1];
	strcpy(cusName, name);
}

//���������
Account::Account(const Account& copy)
	:accID(copy.accID), balance(copy.balance)
{
	cusName = new char[strlen(copy.cusName) + 1];
	strcpy(cusName, copy.cusName);
}
//���¹�ȣ�� ��û�ϴ� Getter
int Account::GetAccID() const
{
	return accID;
}

//�Ա� method
void Account::Deposit(int money)
{
	balance += money;

}

//��� method
int Account::Withdraw(int money)
{
	if (balance < money)
	{
		cout << "�ܾ׺���" << endl;
		return 0;
	}
	balance -= money;
	return money;
}

//�ܾ�
int Account::GetBalance() const
{
	return balance;
}

//�������� ��� Method
void Account::ShowAllAccount() const
{
	cout << "����ID: " << accID << endl;
	cout << "�̸�: " << cusName << endl;
	cout << "�ܾ�: " << balance << endl;
}

//�Ҹ���
Account::~Account()
{
	delete[] cusName;
}