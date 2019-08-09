#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

using namespace std;
const int NAME_LEN = 20;
const int TOTAL_ACC = 100;

class Account
{
private:
	int accID;      // 계좌번호
	int balance;    // 잔액
	char* cusName;  // 고잭이름
public:
	Account(int ID, int money, char* name); //계좌 등록에 필요한 위한 정보 변수
	Account(const Account& copy);	//복사생성자
	int GetAccID() const;	//계좌번호를 요청하는 Getter.
	virtual void Deposit(int money);	//입금 method
	int Withdraw(int money);	//출금 method
	int GetBalance() const;		//잔액 
	void ShowAllAccount() const;//계좌정보 출력 Method
	~Account();
};

#endif // !__ACCOUNT_H__

