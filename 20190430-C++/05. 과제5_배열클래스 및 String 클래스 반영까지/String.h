#ifndef __STRING_H__
#define __STRING_H__

#include "MiniBankingCommonDecl.h"

#define STR_MAX 1000
class String
{
private:
	char* str;	// 문자열 저장
	int len;	// 문자열 길이 저장 변수
public:
	String();	// 한 문자 생성자
	String(const char* str);	//문자열 생성자
	String(const String& ms);	// 문자열 복사자
	int GetStringLength(void) const; // 문자열 길이 반환
	char* GetStringContents(void) const; // 문자열 반환
	~String(); // 소멸자

	String& operator=(const String& ms); 
	int operator== (const String& ms)const ; // strcmp()기능
	
	friend ostream& operator<< (ostream& os, const String& ms);
	friend istream& operator >> (istream& is, String& ms);
};

#endif // !__STRING_H__

