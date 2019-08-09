#ifndef  __MiniBankingCommonDecl_H__
#define __MiniBankingCommonDecl_H__

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Account.h"

#define ID_LEN 10
#define NAME_LEN 30
#define PHONE_LEN 30


enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };
enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 }; // �ſ� ���
enum { NORMAL = 1, CREDIT = 2 }; // ������ ����

#endif // ! __MiniBankingCommonDecl_H__

