#include<iostream>
#include"mystack.h"
using namespace std;

void main()
{
	List a;
	int num[] = { 1,21,31,32,12,32 };
	a.CreatList(num, 6);
	a.DisplayList();
	
	int i;
	int n;
	cout << "��������λ�ú���:";
	cin >> i >> n;
	a.ListInsert(i, n);
	a.DisplayList();
	
	cout << "����ɾ����λ�ú���:";
	cin >> i >> n;
	a.ListDelete(i, n);
	cout << "ɾ������:" << i << endl;
	a.DisplayList();

	cout << "������Ҫ���ҵ���:";
	cin >> i;
	i = a.LocateElem(i);
	cout << "����λ����:" << i << endl;

	a.DestoryList();
}