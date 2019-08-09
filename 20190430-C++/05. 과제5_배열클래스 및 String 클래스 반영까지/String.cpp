#include "String.h"
#include "MiniBankingCommonDecl.h"

String::String() : str(NULL), len(0){}	//한 문자 생성자

String::String(const char* str)	//문자열 생성자
{
	len = (int)strlen(str) + 1;
	this->str = new char[len];
	strcpy(this->str, str);
}

String::String(const String& ms) //복사 생성자
{
	len = ms.len;
	str = new char[len];
	strcpy(str, ms.str);
}


int String::GetStringLength(void) const	// 문자열 길이 반환
{
	return len;
}

char* String::GetStringContents(void) const	// 문자열 반환
{
	return str;
}

String::~String()	//소멸자
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