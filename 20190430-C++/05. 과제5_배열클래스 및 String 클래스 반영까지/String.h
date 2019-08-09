#ifndef __STRING_H__
#define __STRING_H__

#include "MiniBankingCommonDecl.h"

#define STR_MAX 1000
class String
{
private:
	char* str;	// ���ڿ� ����
	int len;	// ���ڿ� ���� ���� ����
public:
	String();	// �� ���� ������
	String(const char* str);	//���ڿ� ������
	String(const String& ms);	// ���ڿ� ������
	int GetStringLength(void) const; // ���ڿ� ���� ��ȯ
	char* GetStringContents(void) const; // ���ڿ� ��ȯ
	~String(); // �Ҹ���

	String& operator=(const String& ms); 
	int operator== (const String& ms)const ; // strcmp()���
	
	friend ostream& operator<< (ostream& os, const String& ms);
	friend istream& operator >> (istream& is, String& ms);
};

#endif // !__STRING_H__

