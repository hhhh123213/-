#include"mylink.h"
#include<iostream>

using namespace std;

SLinkList::SLinkList()
{
	length = 0;
	head = NULL;
}

SLinkList::SLinkList(int* list, int n)
{
	length = 0;
	for (int i = n - 1; i >= 0; --i)
	{
		HeadInsertNode(list[i]);
	}
}

void SLinkList::InsertNode(int n, int num)
{
	if (n > length + 1)
	{
		cout << "³¬³ö·¶Î§£¡" << endl;
	}
	else
	{
		Node* now = head;
		if (n == 1)
		{
			HeadInsertNode(num);
		}
		else if (n == length + 1)
		{
			EndInsertNode(num);
		}
		else
		{
			Node* node = new Node;
			node->num = num;
			for (int i = 0; i < n - 2; ++i)
				now = now->next;
			node->next = now->next;
			now->next->last = node;
			now->next = node;
			node->last = now;
			++length;
		}
	}
}

void SLinkList::HeadInsertNode(int num)
{
	Node* node = new Node;
	node->num = num;
	node->next = head;
	node->last = NULL;
	if (head != NULL)
		head->last = node;
	head = node;
	++length;
}

void SLinkList::EndInsertNode(int num)
{
	Node* now = head;
	if (length == 0)
	{
		head = new Node;
		head->num = num;
		head->next = NULL;
		head->last = NULL;
		length = 1;
	}
	else
	{
		Node* node = new Node;
		node->num = num;
		node->next = NULL;
		while (now->next != NULL)
			now = now->next;
		now->next = node;
		node->last = now;
		++length;
	}
}

void SLinkList::DeleteNode(int n)
{
	if (n > length)
	{
		cout << "¸ÃÖµ³¬³ö·¶Î§£¡" << endl;
		return;
	}
	else
	{
		Node* now = head;
		if (n == 1)
		{
			head = head->next;
			if (head != NULL)
				head->last = NULL;
			delete now;
			length = 0;
		}
		else
		{
			for (int i = 0; i < n - 2; ++i)
				now = now->next;
			Node* tem;
			tem = now->next;
			now->next = now->next->next;
			if (now->next->next != NULL)
				now->next->last = now;
			delete tem;
			--length;
		}
	}
}

void SLinkList::Delete()
{
	Node* tem;
	while (head != NULL)
	{
		tem = head;
		head = head->next;
		delete tem;
		--length;
	}
}

bool SLinkList::Empty()
{
	if (length == 0)
		return true;
	else
		return false;
}

int SLinkList::Length()
{
	return length;
}

void SLinkList::disLinkList()
{
	Node* tem = head;
	while (tem != NULL)
	{
		cout << tem->num << " ";
		tem = tem->next;
	}
	cout << endl;
}

bool SLinkList::GetElem(int n, int& num)
{
	if (n > length)
	{
		cout << "³¬³ö·¶Î§£¡" << endl;
		return false;
	}
	else
	{
		Node* tem = head;
		int i = 0;
		while (i < n - 1)
		{
			tem = tem->next;
		}
		num = tem->num;
		return true;
	}
}

Node*SLinkList::GetNode(int n)
{
	Node* now = head;
	for (int i = 0; i < n - 1; ++i)
		now = now->next;
	return now;
}

int SLinkList::LocateElem(int num)
{
	int i = 1;
	Node* tem = head;
	while (tem->num != num)
	{
		tem = tem->next;
		++i;
	}
	return i;
}