#include "MiniBankingCommonDecl.h"
#include "Account.h"
#include "AccountHandlr.h"
#include "NormalAccount.h"
#include"HighCreditAccount.h"


//메뉴 출력 함수
void AccountHandler::ShowMenu() const
{
	cout << "----------Menum---------" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입금" << endl;
	cout << "3. 출금" << endl;
	cout << "4. 개좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

//계좌 개설 함수
void AccountHandler::MakeAccount()
{
	int select;

	cout << "[계좌 선택]" << endl;
	cout << "1. 보통예금계좌 ";
	cout << "2. 신용신뢰계좌 " << endl;
	cout << "선택  : "; cin >> select;

	switch (select)
	{
	case NORMAL:
		MakeNormalAccount();
		break;
	case CREDIT:
		MakeHighCreditAccount();
		break;
	}
}

//보통예금계좌 개설 함수
void AccountHandler::MakeNormalAccount()
{
	int id;
	char name[NAME_LEN];
	int balance;
	int interRate;

	cout << "[보통예금계좌개설]" << endl;
	cout << "계좌ID: ";	cin >> id;
	cout << "이름: ";	cin >> name;
	cout << "입금액: ";	cin >> balance;
	cout << "이자율: "; cin >> interRate;
	cout << endl;

	accArr[accNum++] = new NormalAccount(id, balance, name, interRate);
}

//신용신뢰계좌 개설 함수
void AccountHandler::MakeHighCreditAccount()
{
	int id;
	char name[NAME_LEN];
	int balance;
	int interRate;
	int creditRatingLV;

	cout << "[신용신뢰계좌개설]" << endl;
	cout << "계좌ID: ";	cin >> id;
	cout << "이름: ";	cin >> name;
	cout << "입금액: ";	cin >> balance;
	cout << "이자율: "; cin >> interRate;
	cout << "사용자 신용등급 A=1,B=2,C=3을 입력해주세요 : "; cin >> creditRatingLV;
	cout << endl;

	switch (creditRatingLV)
	{
	case 1:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_A);
		break;
	case 2:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_B);
		break;
	case 3:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_C);
		break;
	}
}

// 입금하는 함수
void AccountHandler::DepositMoney()
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

//출금 하는 함수
void AccountHandler::WithdrawMoney()
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

// 전체계좌 출력 함수
void AccountHandler::ShowAllAccount() const
{
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAllAccount();
		cout << endl;
	}
}

//소멸자
AccountHandler::~AccountHandler()
{
	for (int i = 0; i < accNum; i++)
		delete accArr[i];
}

