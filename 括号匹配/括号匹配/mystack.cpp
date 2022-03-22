#include"mystack.h"
#include<iostream>

using namespace std;

LinkStack::LinkStack()
{
	pop = NULL;
}

bool LinkStack::Push(char num)
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

bool LinkStack::Pop(char&num)
{
	if (pop == NULL)
		return false;
	Node* tem = pop;
	num = tem->num;
	pop = pop->last;
	if (pop != NULL)
		pop->next = NULL;
	delete tem;
	return true;
}

char LinkStack::GetTop()
{
	return pop->num;
}

void LinkStack::Distory()
{
	char num;
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