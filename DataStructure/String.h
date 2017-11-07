#pragma once
#include "Comm.h"

typedef unsigned char SString[MAX + 1];//0号单元存放串的长度

//串的堆分配存储表示
typedef struct
{
	char *ch;
	int length;
}HString;

class String
{
public:
	String();
	~String();
	// 串联结
	Status Concat(SString& T, SString S1, SString S2);
	// 返回子串在主串中第pos个字符之后的位置
	int Index(SString S, SString T, int pos);
	// 返回字符串长度
	int StrLength(SString S);
	// 用Sub返回串S的第pos个字符起长度为len的子串
	int SubString(SString& Sub, SString S, int pos, int len);
	// 字符串比较，S>T,返回>0,S=T,返回0,S<T返回<0
	int StrCompare(SString S, SString T);
};

