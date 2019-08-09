#ifndef __ AccountHandlr_H__
#define __ AccountHandlr_H__

#include "MiniBankingCommonDecl.h"
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

#endif // !__ AccountHandlr_H__

