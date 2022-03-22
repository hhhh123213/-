#include<iostream>
#include<stdlib.h>
#include"mystack.h"
using namespace std;

List::List()
{
	list = (L*)malloc(sizeof(L));
	list->length = 0;
}
//�������Ա�
void List::CreatList(int* a, int n)
{
	list = (L*)malloc(sizeof(L));
	for (int i = 0; i < n; ++i)
	{
		list->data[i] = a[i];
	}
	list->length = n;
}
//�������Ա�
void List::DestoryList()
{
	free(list);
}
//�ж����Ա��Ƿ�Ϊ��
bool List::ListEmpty()
{
	if (list->length == 0)
		return true;
	else
		return false;
}
//�������Ա���
int List::ListLength()
{
	return list->length;
}
//������Ա�
void List::DisplayList()
{
	if (ListEmpty())
		return;
	else
	{
		for (int i = 0; i < list->length; ++i)
			cout << list->data[i] << " ";
		cout << endl;
	}
}
//����ĳ����
bool List::GetElem(int i, int& n)
{
	if (i<1 || i>list->length)
		return false;
	else
	{
		n = list->data[i - 1];
		return true;
	}
}
//����Ԫ��λ��
int List::LocateElem(int a)
{
	int i;
	for (i = 0; i < list->length; ++i)
	{
		if (list->data[i] == a)
			break;
	}
	if (i == list->length)
		return 0;
	else
		return i + 1;
}
//��������
bool List::ListInsert(int i, int e)
{
	if (i<0 || i>list->length)
		return false;
	else
	{
		for (int num = list->length - 1; num > i; --num)
		{
			list->data[num] = list->data[num - 1];
		}
		list->data[i - 1] = e;
		++list->length;
		return true;
	}
}
//ɾ������
bool List::ListDelete(int i, int& e)
{
	if (i<0 || i>list->length)
		return false;
	else
	{
		e = list->data[i - 1];
		for (int num = i - 1; num < list->length; --num)
		{
			list->data[num] = list->data[num + 1];
		}
		list->data[list->length] = 0;
		--list->length;
		return true;
	}
}
