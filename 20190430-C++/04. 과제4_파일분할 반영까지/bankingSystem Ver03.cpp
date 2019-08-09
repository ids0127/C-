/*
	1. �ý��۸� : BankingSystem
	2. ����		: 1.0
	3. �����   : �Ӵ뼷
	4. ����
		4.1 OOP(��ü����) �ܰ躰 ������Ʈ�� �⺻ Ʋ ����

		1. ĸ��ȭ, �������� ����
		2, ������, �Ҹ��� ����
		3, ��ü �迭 ����
		4. ���� ������ ����
		5. const Ű���� ����
		6. ��Ʈ�� Ŭ����, ����Ƽ Ŭ���� ����
*/

#include "MiniBankingCommonDecl.h"
#include "Account.h"





	//���뿹�ݰ��� Ŭ����
	class NormalAccount : public Account
	{
	private:
		double interRate; // ������
	public:
		NormalAccount(int ID, int money, char* name, double rate)
			:Account(ID,money,name), interRate(rate) {}

		void Deposit(int money)
		{
			Account::Deposit(money); // ���� �߰�
			Account::Deposit((int)(money*interRate /100.0));//�⺻���� �߰�
		}
	
	};

	//�ſ���� Ŭ����
	class HighCreditAccount : public NormalAccount
	{
	private:
		double specialRate; // Ư�� ������
	public:
		HighCreditAccount(int ID, int money, char* name, double rate, double srate)
			:NormalAccount(ID,money,name,rate), specialRate(srate){}

		virtual void Deposit(int money)
		{
			NormalAccount::Deposit(money); // ���ݱ⺻���� �߰�
			Account::Deposit((int)(money*specialRate/100.0)); //Ư������ �߰�
		}
	};


class AccountHandler
{
private:
	Account* accArr[100]; // Account ��ü ������ ���� Account ��ü �迭
	int accNum; // ��ϵ� ���� ��
	
public:
	//������
	AccountHandler() : accNum(0) {}
	void ShowMenu() const;	//�޴� ��� �Լ�
	void MakeAccount();		//���� ���� �Լ�
	void DepositMoney();	// �Ա��ϴ� �Լ�
	void WithdrawMoney();	//��� �ϴ� �Լ�
	void ShowAllAccount() const;	// ��ü���� ��� �Լ�
	void MakeNormalAccount(); //���뿹�ݰ��� ���� �Լ�
	void MakeHighCreditAccount(); //�ſ�ŷڰ��� ���� �Լ�
	~AccountHandler();		//�Ҹ���
};

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

	accArr[accNum++] = new NormalAccount(id, balance, name, interRate);
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

// ��ü���� ��� �Լ�
void AccountHandler::ShowAllAccount() const
{
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAllAccount();
		cout << endl;
	}
}

//�Ҹ���
AccountHandler::~AccountHandler()
{
	for (int i = 0; i < accNum; i++)
		delete accArr[i];
}

int main(void)
{
	AccountHandler AccHdr;
	int choice;

	while (1)
	{
		AccHdr.ShowMenu();
		cout << "����: ";
		cin >> choice;
		cout << endl;
		
		switch (choice)
		{
		case MAKE:
			AccHdr.MakeAccount();
			break;
		case DEPOSIT:
			AccHdr.DepositMoney();
			break;
		case WITHDRAW:
			AccHdr.WithdrawMoney();
			break;
		case INQUIRE:
			AccHdr.ShowAllAccount();
			break;
		case EXIT:
			return 0;
		default:
			cout << "�߸��� �޴� ����" << endl;
		}
	}

	system("pause");  // VC++ ������ �ʿ�

	return 0;
}





