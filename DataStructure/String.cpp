#include "String.h"


String::String()
{
}


String::~String()
{
}


// ������
Status String::Concat(SString& T, SString S1, SString S2)
{
	if (S1[0] + S2[0] <= MAX)//δ�ض�
	{

	}
	else if (S1[0] < MAX)	//�ض�
	{

	}
	else					//�ض�(��ȡS1)
	{

	}
	return Status();
}


// �����Ӵ��������е�pos���ַ�֮���λ��
//int String::Index(SString S, SString T, int pos)
//{
//	int i = pos;
//	int j = 1;
//	while (i<=S[0]&&j<=T[0])
//	{
//		if (S[i] == T[j])
//		{
//			++i;
//			++j;
//		}
//		else
//		{
//			i = i - j + 2;
//			j = 1;
//		}
//	}
//
//	if (j > T[0])
//		return i - T[0];
//	else
//		return 0;
//}

// �����Ӵ��������е�pos���ַ�֮���λ��
int String::Index(SString S, SString T, int pos)
{
	int n, m, i;
	SString sub;

	if (pos > 0)
	{
		n = StrLength(S);
		m = StrLength(T);
		i = pos;
		while (i<=n-m+1)
		{
			SubString(sub, S, i, m);

			if (StrCompare(sub, T) != 0)
				++i;
			else
				return i;
		}
	}
	return 0;
}


// �����ַ�������
int String::StrLength(SString S)
{
	return S[0];
}


// ��Sub���ش�S�ĵ�pos���ַ��𳤶�Ϊlen���Ӵ�
int String::SubString(SString& Sub, SString S, int pos, int len)
{
	if (S[0] < (pos + len))//���
		return 0;

	for (int i = 0; i < len; i++)
	{
		Sub[i+1] = S[pos + i];
	}
	Sub[0] = len;

	return 1;
}


// �ַ����Ƚϣ�S>T,����>0,S=T,����0,S<T����<0
int String::StrCompare(SString S, SString T)
{
	return 0;
}
