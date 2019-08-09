#include "MiniBankingCommonDecl.h"
#include "Account.h"

//계좌 등록에 필요한 위한 정보 변수
//생성자
Account::Account(int ID, int money, char* name)
	: accID(ID), balance(money)
{
	cusName = new char[strlen(name) + 1];
	strcpy(cusName, name);
}

//복사생성자
Account::Account(const Account& copy)
	:accID(copy.accID), balance(copy.balance)
{
	cusName = new char[strlen(copy.cusName) + 1];
	strcpy(cusName, copy.cusName);
}
//계좌번호를 요청하는 Getter
int Account::GetAccID() const
{
	return accID;
}

//입금 method
void Account::Deposit(int money)
{
	balance += money;

}

//출금 method
int Account::Withdraw(int money)
{
	if (balance < money)
	{
		cout << "잔액부족" << endl;
		return 0;
	}
	balance -= money;
	return money;
}

//잔액
int Account::GetBalance() const
{
	return balance;
}

//계좌정보 출력 Method
void Account::ShowAllAccount() const
{
	cout << "계좌ID: " << accID << endl;
	cout << "이름: " << cusName << endl;
	cout << "잔액: " << balance << endl;
}

//소멸자
Account::~Account()
{
	delete[] cusName;
}