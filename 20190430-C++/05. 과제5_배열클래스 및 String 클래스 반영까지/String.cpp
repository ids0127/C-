#include "String.h"
#include "MiniBankingCommonDecl.h"

String::String() : str(NULL), len(0){}	//�� ���� ������

String::String(const char* str)	//���ڿ� ������
{
	len = (int)strlen(str) + 1;
	this->str = new char[len];
	strcpy(this->str, str);
}

String::String(const String& ms) //���� ������
{
	len = ms.len;
	str = new char[len];
	strcpy(str, ms.str);
}


int String::GetStringLength(void) const	// ���ڿ� ���� ��ȯ
{
	return len;
}

char* String::GetStringContents(void) const	// ���ڿ� ��ȯ
{
	return str;
}

String::~String()	//�Ҹ���
{
	delete[]str;
}


String& String::operator=(const String& ms)
{
	if (str != NULL) delete[]str;

	len = ms.len;
	str = new char[len];
	strcpy(str, ms.str);
	return *this;
}

bool String::operator== (const String& ms)
{
	if (strcmp(str, ms.str) == 0) return true;
	else false;
}

ostream& operator<< (ostream& os, const String& ms)
{
	os << ms.str;
	return os;
	
}
istream& operator >> (istream& is, String& ms)
{
	char str[100];
	is >> str;
	ms = String(str);
	return is;
}