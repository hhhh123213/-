#include"mystack.h"
#include<iostream>

using namespace std;

int main()
{
	int sel = 0;
	int num;
	LinkStack line;
	while (1)
	{
		cout << "---------------------------" << endl;
		cout << "---------- 1.��ջ ---------" << endl;
		cout << "---------- 2.��ջ ---------" << endl;
		cout << "-------- 3.ջ��Ԫ�� -------" << endl;
		cout << "------ 4.����Ƿ��ջ -----" << endl;
		cout << "--------- 5.����ջ --------" << endl;
		cout << "------ 6.��ʾջ��Ԫ�� -----" << endl;
		cout << "---------- 7.�˳� ---------" << endl;
		cout << "---------------------------" << endl;
		cin >> sel;
		switch (sel)
		{
		case 1:
			cout << "���������Ԫ��:";
			cin >> num;
			line.Push(num); break;
		case 2:
			line.Pop(num);
			cout << num << "�ѳ�ջ" << endl; break;
		case 3:
			cout << line.GetTop(); break;
		case 4:
			cout << line.Empty(); break;
		case 5:
			line.Distory(); break;
		case 6:
			line.display(); break;
		case 7:return 0;
		default:break;
		}
		system("pause");
		system("cls");
	}
	return 0;
}