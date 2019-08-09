#ifndef __NormalAccount_H__
#define __NormalAccount_H__

//���뿹�ݰ��� Ŭ����
class NormalAccount : public Account
{
private:
	double interRate; // ������
public:
	NormalAccount(int ID, int money, char* name, double rate)
		:Account(ID, money, name), interRate(rate) {}

	void Deposit(int money)
	{
		Account::Deposit(money); // ���� �߰�
		Account::Deposit((int)(money * interRate / 100.0));//�⺻���� �߰�
	}

};

#endif // !__NormalAccount_H__
