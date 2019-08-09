#include"MiniBankingCommonDecl.h"
#include "Account.h"
#include "AccountHandlr.h"


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
		7. ���������� ����
*/

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





