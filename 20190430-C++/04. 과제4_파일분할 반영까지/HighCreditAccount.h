#ifndef __HighCreditAccount_H__
#define __HighCreditAccount_H__

#include "AccountHandlr.h"
#include "NormalAccount.h"

//�ſ���� Ŭ����
class HighCreditAccount : public NormalAccount
{
private:
	double specialRate; // Ư�� ������
public:
	HighCreditAccount(int ID, int money, char* name, double rate, double srate)
		:NormalAccount(ID, money, name, rate), specialRate(srate) {}

	virtual void Deposit(int money)
	{
		NormalAccount::Deposit(money); // ���ݱ⺻���� �߰�
		Account::Deposit((int)(money * specialRate / 100.0)); //Ư������ �߰�
	}
};


#endif // !__HighCreditAccount_H__
