/*
	1. 시스템명 : BankingSystem
	2. 버전		: 1.0
	3. 담당자   : 임대섭
	4. 내용
		4.1 OOP(객체지향) 단계별 프로젝트의 기본 틀 구성

		1. 캡슐화, 정보은닉 적용
		2, 생성자, 소멸자 적용
		3, 객체 배열 적용
*/

#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;
const int TOTAL_ACC = 100;

void ShowMenu(void);        // 메뉴출력
void MakeAccount(void);     // 계좌개설
void DepositMoney(void);    // 입금
void WithdrawMoney(void);   // 출금
void ShowAllAccount(void);  // 잔액조회

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

class Account
{
private:
	int accID;      // 계좌번호
	int balance;    // 잔액
	char* cusName;  // 고잭이름
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
			cout << "잔액부족" << endl;
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
		cout << "계좌ID: " << accID << endl;
		cout << "이름: " << cusName << endl;
		cout << "잔액: " << balance << endl;
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
		cout << "선택: ";
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
			cout << "잘못된 메뉴 선택" << endl;
		}
	}

	system("pause");  // VC++ 에서만 필요

	return 0;
}

void ShowMenu(void)
{
	cout << "----------Menum---------" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입금" << endl;
	cout << "3. 출금" << endl;
	cout << "4. 개좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void MakeAccount(void)
{
	int id;
	char name[NAME_LEN];
	int balance;

	cout << "[계좌개설]" << endl;
	cout << "계좌ID: ";	cin >> id;
	cout << "이름: ";	cin >> name;
	cout << "입금액: ";	cin >> balance;
	cout << endl;

	accArr[accNum++] = new Account(id, balance, name);
}

void DepositMoney(void)
{
	int money;
	int id;
	cout << "[입금]" << endl;
	cout << "계좌ID: ";
	cin >> id;
	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			cout << "입금액: ";
			cin >> money;
			accArr[i]->Deposit(money);
			cout << "입금 완료: " << endl;
			return;
		}
	}
	cout << "잘못된 계좌 번호 입력. " << endl;
}

void WithdrawMoney(void)
{
	int money;
	int id;
	cout << "[출금]" << endl;
	cout << "계좌ID: ";
	cin >> id;
	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			if (accArr[i]->GetBalance() > 0)
			{
				cout << "출금액: ";
				cin >> money;
				accArr[i]->Withdraw(money);
				return;
			}
			else
			{
				cout << "잔액 모자람" << endl;
			}
		}
	}
	cout << "잘못된 계좌 번호 입력. " << endl;
}

void ShowAllAccount(void)
{
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAccInfor();
		cout << endl;
	}
}