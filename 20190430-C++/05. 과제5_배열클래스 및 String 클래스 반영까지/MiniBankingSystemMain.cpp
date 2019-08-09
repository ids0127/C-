#include"MiniBankingCommonDecl.h"
#include "Account.h"
#include "AccountHandlr.h"


/*
	1. 시스템명 : BankingSystem
	2. 버전		: 1.0
	3. 담당자   : 임대섭
	4. 내용
		4.1 OOP(객체지향) 단계별 프로젝트의 기본 틀 구성

		1. 캡슐화, 정보은닉 적용
		2, 생성자, 소멸자 적용
		3, 객체 배열 적용
		4. 복사 생성자 적용
		5. const 키워드 적용
		6. 컨트롤 클래스, 엔터티 클래스 적용
		7. 분할컴파일 적용
*/

int main(void)
{
	AccountHandler AccHdr;
	int choice;

	while (1)
	{
		AccHdr.ShowMenu();
		cout << "선택: ";
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
			cout << "잘못된 메뉴 선택" << endl;
		}
	}

	system("pause");  // VC++ 에서만 필요

	return 0;
}





