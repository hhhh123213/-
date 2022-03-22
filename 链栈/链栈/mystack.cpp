#include"mystack.h"
#include<iostream>

using namespace std;

LinkStack::LinkStack()
{
	pop = NULL;
}

bool LinkStack::Push(int num)
{
	Node* tem = new Node;
	tem->num = num;
	tem->next = NULL;
	tem->last = pop;
	if (pop != NULL)
	{
		pop->next = tem;
	}
	pop = tem;
	return true;
}

bool LinkStack::Pop(int&num)
{
	if (pop == NULL)
		return false;
	Node* tem = pop;
	num = tem->num;
	pop = pop->last;
	pop->next = NULL;
	delete tem;
	return true;
}

int LinkStack::GetTop()
{
	return pop->num;
}

void LinkStack::Distory()
{
	int num;
	Node* tem = pop;
	while (pop != NULL)
	{
		tem = pop;
		pop = pop->last;
		delete tem;
	}
}

bool LinkStack::Empty()
{
	if (pop == NULL)
		return true;
	else
		return false;
}

void LinkStack::display()
{
	Node* tem = pop;
	while (tem != NULL)
	{
		cout << tem->num << " ";
		tem = tem->last;
	}
	cout << endl;
}