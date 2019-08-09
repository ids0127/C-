#ifndef __ AccountHandlr_H__
#define __ AccountHandlr_H__

#include "MiniBankingCommonDecl.h"
class AccountHandler
{
private:
	Account_Ptr accArr[100][1]; // Account 객체 저장을 위한 Account 객체 배열,고객계좌 리스트
	int accNum; // 등록된 계좌 수
	int arr_accNum; //클래스 배열 요소갯수

public:
	//생성자
	AccountHandler() : accNum(0) {}
	void ShowMenu() const;	//메뉴 출력 함수
	void MakeAccount();		//계좌 개설 함수
	void DepositMoney();	// 입금하는 함수
	void WithdrawMoney();	//출금 하는 함수
	void ShowAllAccount() const;	// 전체계좌 출력 함수
	void MakeNormalAccount(); //보통예금계좌 개설 함수
	void MakeHighCreditAccount(); //신용신뢰계좌 개설 함수
	~AccountHandler();		//소멸자
};

#endif // !__ AccountHandlr_H__

