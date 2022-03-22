#pragma once

#ifndef DLL_IMPORT
#define API extern "C" __declspec(dllexport)
#else
#define API extern "C" __declspec(dllimport)
#endif // !MY_LLIST

API typedef struct L
{
	int length = 0;
	int data[20];
};

class __declspec(dllexport) List
{
public:
	L* list;
	List();
	void CreatList(int* a, int n);
	void DestoryList();
	bool ListEmpty();
	int ListLength();
	void DisplayList();
	bool GetElem(int i, int& n);
	int LocateElem(int a);
	bool ListInsert(int i, int e);
	bool ListDelete(int i, int& e);
};