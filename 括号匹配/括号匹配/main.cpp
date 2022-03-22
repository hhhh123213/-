#include"mystack.h"
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int i = 0;
	int num;
	LinkStack line;
	char ch;
	vector<char> bracket;
	cout << "������Ҫƥ�������:";
	while ((ch = cin.get()) != '\n')
		bracket.push_back(ch);
	for (char ch : bracket)
	{
		if (ch == '(')
		{
			line.Push(ch);
		}
		else if (ch == ')')
		{
			++i;
			if (line.Empty())
			{
				cout << "��" << i << "��')'û�б�ƥ��" << endl;
			}
			else
			{
				line.Pop(ch);
			}
		}
	}
	cout << endl;
	return 0;
}