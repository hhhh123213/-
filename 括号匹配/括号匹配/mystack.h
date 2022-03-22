#pragma once

typedef struct node
{
	char num;
	node* next;
	node* last;
}Node;

class LinkStack
{
	Node*pop;
public:
	LinkStack();
	bool Push(char num);
	bool Pop(char&num);
	char GetTop();
	void Distory();
	bool Empty();
	void display();
};