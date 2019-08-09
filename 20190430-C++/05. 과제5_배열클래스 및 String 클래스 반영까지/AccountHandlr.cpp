#include "AccountHandlr.h"
#include "NormalAccount.h"
#include"HighCreditAccount.h"


//�޴� ��� �Լ�
void AccountHandler::ShowMenu() const
{
	cout << "----------Menum---------" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �Ա�" << endl;
	cout << "3. ���" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
}

//���� ���� �Լ�
void AccountHandler::MakeAccount()
{
	int select;

	cout << "[���� ����]" << endl;
	cout << "1. ���뿹�ݰ��� ";
	cout << "2. �ſ�ŷڰ��� " << endl;
	cout << "����  : "; cin >> select;

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

//���뿹�ݰ��� ���� �Լ�
void AccountHandler::MakeNormalAccount()
{
	int id;
	char name[NAME_LEN];
	int balance;
	int interRate;

	cout << "[���뿹�ݰ��°���]" << endl;
	cout << "����ID: ";	cin >> id;
	cout << "�̸�: ";	cin >> name;
	cout << "�Աݾ�: ";	cin >> balance;
	cout << "������: "; cin >> interRate;
	cout << endl;

	
	accArr[accNum++][0] = new NormalAccount(id, balance, name, interRate);
}

//�ſ�ŷڰ��� ���� �Լ�
void AccountHandler::MakeHighCreditAccount()
{
	int id;
	char name[NAME_LEN];
	int balance;
	int interRate;
	int creditRatingLV;

	cout << "[�ſ�ŷڰ��°���]" << endl;
	cout << "����ID: ";	cin >> id;
	cout << "�̸�: ";	cin >> name;
	cout << "�Աݾ�: ";	cin >> balance;
	cout << "������: "; cin >> interRate;
	cout << "����� �ſ��� A=1,B=2,C=3�� �Է����ּ��� : "; cin >> creditRatingLV;
	cout << endl;

	switch (creditRatingLV)
	{
	case 1:
		accArr[accNum++][0] = new HighCreditAccount(id, balance, name, interRate, LEVEL_A);
		break;
	case 2:
		accArr[accNum++][0] = new HighCreditAccount(id, balance, name, interRate, LEVEL_B);
		break;
	case 3:
		accArr[accNum++][0] = new HighCreditAccount(id, balance, name, interRate, LEVEL_C);
		break;
	}
}

// �Ա��ϴ� �Լ�
void AccountHandler::DepositMoney()
{
	int money;
	int id;
	cout << "[�Ա�]" << endl;
	cout << "����ID: ";
	cin >> id;
	
	for (int i = 0; i < accNum; i++)
		{
			if (accArr[i][0]->GetAccID() == id)
			{
				cout << "�Աݾ�: ";
				cin >> money;
				accArr[i][0]->Deposit(money);

				cout << "�Ա� �Ϸ�: " << endl;

				return;
			}
		}
	
	
	cout << "�߸��� ���� ��ȣ �Է�. " << endl;
}

//��� �ϴ� �Լ�
void AccountHandler::WithdrawMoney()
{
	int money;
	int id;
	cout << "[���]" << endl;
	cout << "����ID: ";
	cin >> id;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i][0]->GetAccID() == id)
		{
			if (accArr[i][0]->GetBalance() > 0)
			{
				cout << "��ݾ�: ";
				cin >> money;
				accArr[i][0]->Withdraw(money);
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

// ��ü���� ��� �Լ�
void AccountHandler::ShowAllAccount() const
{
	for (int i = 0; i < accNum; i++)
	{
		accArr[i][0]->ShowAllAccount();
		cout << endl;
	}
}

//�Ҹ���
AccountHandler::~AccountHandler()
{
	for(int i = 0;i<accNum; i++)
		delete accArr[i];
}

