#include <iostream>
using namespace std;
class LinkedList {
public:
	struct Node {
		int data;
		Node *next;
		Node(int a = 0, Node *b = nullptr) :data(a), next(b) {}
	};
	Node *head;//链表的头结点
	int size;  //保存数据的数量，这是一个冗余数据
	LinkedList();	//默认构造函数，构造一个逻辑为空的链表
	LinkedList(const LinkedList&rhs);//拷贝构造函数，构造一个逻辑上与参数内容相同的链表
	LinkedList(int const a[], int n);//原生数组构造函数，构造一个内容与给定数组相同的链表
	LinkedList(int n, int value);//填充构造函数，构造一个内容为n个value的链表
	~LinkedList();//删除链表
	int getSize()const { return size; }//得到链表长度
	void insert(int pos, int value);//向pos的下一个位置插入一个结点
	void remove(int pos);//删除pos位置下一个的结点
	int at(int pos)const;//返回pos位置下一个结点的数据
	void modify(int pos, int newValue);//更改pos位置下一个结点的数据
	void disp()const;//输出单链表
	void CreatListF(int a[],int n);//头插法创建链表
	void CreatListR(int a[], int n);//尾插法创建链表
	int Find(int e);//按元素查找
private:
	Node *advance(int pos)const;//返回指定位置的节点的指针
};
LinkedList::LinkedList()
{
	size = 0;
	head = new Node;
	head->next = NULL;
}
LinkedList::LinkedList(const LinkedList&rhs)
{
	size = rhs.getSize();
	head = new Node;
	Node *p = head;
	Node *s = rhs.head;
	while (s->next)
	{
		p->data = s->data;
		if (s->next)
		{
			p->next = new Node;
			p = p->next;
			s = s->next;
		}
	}
	p->next = NULL;
}
LinkedList::LinkedList(int const a[], int n)
{
	size = n;
	head = new Node;
	Node *p = head;
	for (int i = 0; i < n; i++)
	{
		p->data = a[i];
		if (i < n)
		{
			p->next = new Node;
			p = p->next;
		}
	}
	p->next = NULL;
}
LinkedList::LinkedList(int n, int value)
{
	size = n;
	head = new Node;
	Node *p = head;
	for (int i = 0; i < n; i++)
	{
		p->data = value;
		if (i < n)
		{
			p->next = new Node;
			p = p->next;
		}
	}
	p->next = NULL;
}
LinkedList::~LinkedList()
{
	Node *p = head;
	while (p->next)
	{
		Node *s = p;
		p = p->next;
		delete s;
	}
	delete p;
}
void LinkedList::insert(int pos, int value)
{
	Node* new_node = new Node;
	new_node->data = value;
	Node *pnode = advance(pos + 1);
	Node *padvance = advance(pos);
	padvance->next = new_node;
	new_node->next = pnode;
	size++;
}

void LinkedList::remove(int pos)
{
	Node *pnode = advance(pos + 1);
	Node *padvance = advance(pos);
	padvance->next = pnode->next;
	delete pnode;
	pnode = nullptr;
	size--;
}

int LinkedList::at(int pos)const
{
	Node *pnode = advance(pos + 1);
	return pnode->data;
}

void LinkedList::modify(int pos, int newValue)
{
	Node *pnode = advance(pos + 1);
	pnode->data = newValue;
}
void LinkedList::disp()const
{
	Node *p = head->next;
	while (p != nullptr)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
LinkedList::Node* LinkedList::advance(int pos)const
{
	Node* p = this->head;
	for (int i = 0; i < pos; i++)
	{
		p = p->next;
	}
	return p;
}
void LinkedList::CreatListF(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		Node *p = new Node;
		p->data = a[i];
		p->next=head->next;
		head->next = p;
	}

}
void LinkedList::CreatListR(int *a, int n)
{
	//LinkedList p;
	//Node *pnode = p.head;
	//for (int i = 0; i < n; i++)
	//{
	//	pnode->data = a[i];
	//	if (i < n - 1)
	//	{
	//		pnode->next = new Node;
	//		pnode = pnode->next;
	//	}
	//}
	//pnode->next = NULL;
	//cout << p.head->data << endl;
	//Node *l = this->head;
	cout << this->head->data << endl;
	//while (l->next)
	//{
	//	l = l->next;
	//}
	//l->next =p.head;
}
int LinkedList::Find(int e)
{
	int i = 0;
	Node *p = this->head;
	while (p&&p->data != e)
	{
		p = p->next;
		i ++ ;
	}
	if (p == NULL)return(0);
	else return(i);
}
int main() {
	int n, x;
	LinkedList a;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		a.insert(a.getSize(), x);
	}
	a.disp();
	for (int i = 0; i < 3 && a.getSize() != 0; ++i) {
		a.remove(0);
	}
	a.disp();
	for (int i = 0; i < a.getSize(); i++) {
		a.modify(i, a.at(i) * 10);
	}
	a.disp();
	LinkedList b;
	int t[3] = { 2,3,4 };
	b.CreatListF(t,3);
	b.disp();
	b.CreatListR(t, 3);

	return 0;
}