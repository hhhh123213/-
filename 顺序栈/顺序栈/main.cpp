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
	cout << "输入插入的位置和数:";
	cin >> i >> n;
	a.ListInsert(i, n);
	a.DisplayList();
	
	cout << "输入删除的位置和数:";
	cin >> i >> n;
	a.ListDelete(i, n);
	cout << "删掉的数:" << i << endl;
	a.DisplayList();

	cout << "输入你要查找的数:";
	cin >> i;
	i = a.LocateElem(i);
	cout << "它的位置是:" << i << endl;

	a.DestoryList();
}