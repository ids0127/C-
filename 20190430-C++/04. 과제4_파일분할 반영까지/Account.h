#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

using namespace std;
const int NAME_LEN = 20;
const int TOTAL_ACC = 100;

class Account
{
private:
	int accID;      // ���¹�ȣ
	int balance;    // �ܾ�
	char* cusName;  // �����̸�
public:
	Account(int ID, int money, char* name); //���� ��Ͽ� �ʿ��� ���� ���� ����
	Account(const Account& copy);	//���������
	int GetAccID() const;	//���¹�ȣ�� ��û�ϴ� Getter.
	virtual void Deposit(int money);	//�Ա� method
	int Withdraw(int money);	//��� method
	int GetBalance() const;		//�ܾ� 
	void ShowAllAccount() const;//�������� ��� Method
	~Account();
};

#endif // !__ACCOUNT_H__

