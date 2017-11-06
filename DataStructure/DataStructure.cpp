// DataStructure.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "List.h"

int main()
{
	List list;

	list.InitList(list.list);
	list.insert(list.list, 1, 6);
	list.insert(list.list, 1, 7);
	list.insert(list.list, 1, 8);
	list.insert(list.list, 1, 9);

	ElemType e;
	list.listDelete(list.list, 3, e);

	SLinkList slist;

	list.InitList(slist);
	list.ListInsert(slist,1, 6);

    return 0;
}

