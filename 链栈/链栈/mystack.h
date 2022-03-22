#pragma once

typedef struct node
{
	int num;
	node* next;
	node* last;
}Node;

class LinkStack
{
	Node*pop;
public:
	LinkStack();
	bool Push(int num);
	bool Pop(int&num);
	int GetTop();
	void Distory();
	bool Empty();
	void display();
};