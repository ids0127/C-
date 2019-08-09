#ifndef __NormalAccount_H__
#define __NormalAccount_H__

//보통예금계좌 클래스
class NormalAccount : public Account
{
private:
	double interRate; // 이자율
public:
	NormalAccount(int ID, int money, char* name, double rate)
		:Account(ID, money, name), interRate(rate) {}

	void Deposit(int money)
	{
		Account::Deposit(money); // 원금 추가
		Account::Deposit((int)(money * interRate / 100.0));//기본이자 추가
	}

};

#endif // !__NormalAccount_H__
