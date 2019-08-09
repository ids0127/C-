#ifndef __HighCreditAccount_H__
#define __HighCreditAccount_H__

#include "AccountHandlr.h"
#include "NormalAccount.h"

//신용계좌 클래스
class HighCreditAccount : public NormalAccount
{
private:
	double specialRate; // 특별 이자율
public:
	HighCreditAccount(int ID, int money, char* name, double rate, double srate)
		:NormalAccount(ID, money, name, rate), specialRate(srate) {}

	virtual void Deposit(int money)
	{
		NormalAccount::Deposit(money); // 원금기본이자 추가
		Account::Deposit((int)(money * specialRate / 100.0)); //특별이자 추가
	}
};


#endif // !__HighCreditAccount_H__
