#pragma once
#include "Comm.h"

typedef unsigned char SString[MAX + 1];//0�ŵ�Ԫ��Ŵ��ĳ���

//���Ķѷ���洢��ʾ
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
	// ������
	Status Concat(SString& T, SString S1, SString S2);
	// �����Ӵ��������е�pos���ַ�֮���λ��
	int Index(SString S, SString T, int pos);
	// �����ַ�������
	int StrLength(SString S);
	// ��Sub���ش�S�ĵ�pos���ַ��𳤶�Ϊlen���Ӵ�
	int SubString(SString& Sub, SString S, int pos, int len);
	// �ַ����Ƚϣ�S>T,����>0,S=T,����0,S<T����<0
	int StrCompare(SString S, SString T);
};

