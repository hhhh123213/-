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
	cout << "请输入要匹配的括号:";
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
				cout << "第" << i << "个')'没有被匹配" << endl;
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