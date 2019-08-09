#ifndef __ AccountHandlr_H__
#define __ AccountHandlr_H__

#include "MiniBankingCommonDecl.h"
class AccountHandler
{
private:
	Account_Ptr accArr[100][1]; // Account ��ü ������ ���� Account ��ü �迭,������ ����Ʈ
	int accNum; // ��ϵ� ���� ��
	int arr_accNum; //Ŭ���� �迭 ��Ұ���

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

