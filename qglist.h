/**
 * 作者:QG
 **/


#ifndef __QG_LIST_H__
#define __QG_LIST_H__
#include <iostream>
#include<Windows.h>

using namespace std;
template <typename T>
class Node {
public:
	/* 用于链表节点的定义 */
	T data; // 表示数据域
	Node<T>* next;  // 表示指针域，存储下一个节点的位置
	Node<T>* prior;
};
template <typename T>
class QGList : public Node<T> {
private:
	/* 用于链表的定义 */
	Node<T>* head; // 头节点
	Node<T>* p;
	

public:
	int length;
	QGList();
	~QGList();
	T& front();
	T& back();
	bool push_front(const T& e);
	bool pop_front();
	bool push_back(const T& e);
	bool pop_back();
	bool insert(int index, const T& e);
	bool erase(const int& index);
	bool clear();
	bool contain(const T& e);
	int size();
	bool traverse(void (*visit)( T& e));
	bool reverse();
	bool isLoop();
	bool reverseEven();
	T& middleElem();
	
};


template <typename T>
class QGforwardList : public Node<T> {
private:
	/* 用于链表的定义 */
	Node<T>* head; // 头节点
	Node<T>* p;
public:
	QGforwardList();
	~QGforwardList();
	T& front();
	T& back();
	bool push_front(const T& e);
	bool pop_front();
	bool push_back(const T& e);
	bool pop_back();
	bool insert(int index, const T& e);
	bool erase(const int& index);
	bool clear();
	bool contain(const T& e);
	int size();
	bool traverse(void (*visit)(T& e));
	bool reverse();
	bool reverseEven();
};

template <typename T>
 QGList<T>::QGList()
{
	this->head = new Node<T>;
	if (this->head == NULL)
	{
		cerr << "error allocating memory" << endl;
	}
	this->head->next = NULL;
}

template <typename T>
 QGList<T>::~QGList()
{
	p = head->next;
	while (p != NULL)
	{
		Node<T>* tmp = p;
		p = p->next;
		free(tmp);

	}
	free(head);
}

template <typename T>
int QGList<T>::size()
{
	Node<T>* p = this->head->next;
	 int counter = 0;
	while (p != NULL)
	{
		p = p->next;
		counter++;
	}
	
	return counter;
}

template <typename T>
bool  QGList<T>::push_front(const T& e)
{

	Node<T>* node = new Node<T>;
	node->data = e;
	node->next = head->next;
	head->next = node;

	return true;
}

template <typename T>
bool  QGList<T>::pop_front()
{
	Node<T>* pt = head->next;
	p = head->next->next;
	delete(pt);
	head->next = p;
	return true;

}

template <typename T>
bool  QGList<T>::pop_back()
{
	Node<T>* pt = NULL;
	p = head;
	while (p->next != NULL)
	{
		pt = p;
		p = p->next;
	}
	delete(p);
	p = NULL;
	pt->next = NULL;
	return true;
}

template <typename T>
bool  QGList<T>::push_back(const T& e)
{
	Node<T>* node = new Node<T>;
	node->data = e;
	p = head;
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = node;
	p = p->next;
	p->next = NULL;
	return true;
}

template <typename T>
bool QGList<T> ::insert(int index, const T& e)
{
	
	p = head;
	int i;
	if (index == 1)
	{
		push_front(e);
	}
	else if (index == this->size())
	{
		push_back(e);
	}
	else if (index>1&&index<this->size())
	{
		for (i = 1;i <= index;i++)
		{
			p = p->next;
		}
		Node<T>* node = new Node<T>;
		node->data = e;
		node->next = p->next;
		p->next = node;

	}
	else
		cout << "该数字超过链表长度，无法找到对应位置插入" << endl;
	return true;
}

template <typename T>
void print( T &e)
{

	cout << e << "  ";
}

template <typename T>
bool QGList<T>::erase(const int& index)
{
	p = head;
	Node<T>* pt = NULL;
	int i;
	if (index == 1)
	{
		pop_front();
	}
	else if (index == this->size())
	{
		pop_back();
	}
	else if (index > 1 && index < this->size())
	{
		for (i = 1;i <= index;i++)
		{
			pt = p;
			p = p->next;
		}
		pt->next = p->next;
		delete(p);
	}
	else
		cout << "该数字超出链表长度，无法找到对应元素删除" << endl;
	return true;
}

template <typename T>
bool QGList<T>:: clear()
{
	p = head->next;
	while (p != NULL)
	{
		Node<T>* tmp = p;
		p = p->next;
		free(tmp);
	}
	head->next = NULL;
	cout << "已经清空链表" << endl;
	return true;
}

template <typename T>
bool QGList<T>::contain(const T& e)
{
	int i = 1;
	p = head->next;
	while (p != NULL)
	{
		if (p->data == e)
		{
			cout << "存在该元素" << endl;
			return true;
			break;
		}
		p = p->next;
		i++;
	}
	return false;
}

template <typename T>
T& QGList<T>::middleElem()
{
	Node<T>* fast = NULL;
	Node<T>* slow = NULL;
	if (this->size()% 2 == 0)
	{
		slow = head;
		fast = head;
		while (fast->next != NULL)
		{
			slow = slow->next;
			fast = fast->next->next;
		}

	}
	else
	{
		slow = head->next;
		fast = head->next;
		while (fast->next != NULL)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
	}
	cout << slow->data;
	return slow->data;
}

template <typename T>
bool QGList<T>::reverse()
{
	Node<T>* beg = NULL;
	Node<T>* mid = head->next;
	Node<T>* end = head->next->next;
	while (1)
	{
		mid->next = beg;
		if (end == NULL)
		{
			break;
		}
		beg = mid;
		mid = end;
		end = end->next;
	}
	head->next = mid;
	return true;
}

template<typename T>
bool QGList<T>::traverse(void (*print)( T& e))//这里我把visit定义成一个打印函数
{
	p = head->next;
	while (p != NULL)
	{
		print(p->data);
		p = p->next;
	}
	cout << endl;
	cout << "遍历打印完毕！" << endl;
	return true;
}

template<typename T>
T& QGList<T>:: front()
{
	return head->next->data;
}

template<typename T>
T& QGList<T>::back()
{
	p = head->next;
	while (p->next != NULL)
	{
		p = p->next;
	}
	return p->data;
}

template<typename T>
bool QGList<T>::isLoop()
{
	Node<T>* slow;
	Node<T>* fast;
	slow = head;
	fast = head;
	while (fast->next != NULL && fast->next->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			cout << "链表成环" << endl;
			return true;
		}
	}
	cout << "链表不成环" << endl;
	return false;
}

template<typename T>
bool QGList<T>::reverseEven()
{
	Node<T>* p, * q, * t;
	t = head;
	while (t->next && t->next->next)
	{
		q = t->next;
		p = q->next;
		t->next = p;
		q->next = p->next;
		p->next = q;
		t = q;
	}
	return true;
}






template <typename T>
QGforwardList<T>::QGforwardList()
{
	this->head = new Node<T>;
	if (this->head == NULL)
	{
		cerr << "error allocating memory" << endl;
	}
	this->head->next = NULL;
	head->prior = NULL;
}

template <typename T>
QGforwardList<T>::~QGforwardList()
{
	p = head->next;
	while (p != NULL)
	{
		Node<T>* tmp = p;
		p = p->next;
		free(tmp);

	}

	free(head);
	cout << "已经销毁链表" << endl;
}

template <typename T>
int QGforwardList<T>::size()
{
	Node<T>* p = this->head->next;
	int counter = 0;
	while (p != NULL)
	{
		p = p->next;
		counter++;
	}

	return counter;
}

template <typename T>
bool  QGforwardList<T>::push_front(const T& e)
{

	Node<T>* pt = head;
	p = head->next;
	Node<T>* node = new Node<T>;
	node->data = e;
	pt->next = node;
	node->prior = pt;
	node->next = p;
	p->prior = node;

	return true;
}

template <typename T>
bool  QGforwardList<T>::pop_front()
{
	Node<T>* pt = head->next;
		p = head->next->next;
		delete(pt);
		head->next = p;
		p->prior = head;
	return true;

}

template <typename T>
bool  QGforwardList<T>::pop_back()
{
	Node<T>* pt = NULL;
	p = head;
	while (p->next != NULL)
	{
		pt = p;
		p = p->next;
	}
	delete(p);
	p = NULL;
	pt->next = NULL;
	return true;
}

template <typename T>
bool  QGforwardList<T>::push_back(const T& e)
{
	Node<T>* node = new Node<T>;
	node->data = e;
	p = head;
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = node;
	node->prior = p;
	p = p->next;
	p->next = NULL;
	return true;
}

template <typename T>
bool QGforwardList<T> ::insert(int index, const T& e)
{

	p = head;
	int i;
	if (index == 1)
	{
		push_front(e);
	}
	else if (index == this->size())
	{
		push_back(e);
	}
	else if (index > 1 && index < this->size())
	{
		for (i = 1;i <= index;i++)
		{
			p = p->next;
		}
		Node<T>* node = new Node<T>;
		node->data = e;
		node->next = p->next;
		p->next->prior = node;
		p->next = node;
		node->prior = p;

	}
	else
		cout << "该数字超过链表长度，无法找到对应位置插入" << endl;
	return true;
}

template <typename T>
bool QGforwardList<T>::erase(const int& index)
{
	p = head;
	Node<T>* pt = NULL;
	int i;
	if (index == 1)
	{
		pop_front();
	}
	else if (index == this->size())
	{
		pop_back();
	}
	else if (index > 1 && index < this->size())
	{
		for (i = 1;i <= index;i++)
		{
			pt = p;
			p = p->next;
		}
		pt->next = p->next;
		p->next->prior = pt;
		delete(p);
	}
	else
		cout << "该数字超出链表长度，无法找到对应元素删除" << endl;
	return true;
}

template <typename T>
bool QGforwardList<T>::clear()
{
	p = head->next;
	while (p != NULL)
	{
		Node<T>* tmp = p;
		p = p->next;
		free(tmp);
	}
	head->next = NULL;
	cout << "已经清空链表" << endl;
	return true;
}

template <typename T>
bool QGforwardList<T>::contain(const T& e)
{
	int i = 1;
	p = head->next;
	while (p != NULL)
	{
		if (p->data == e)
		{
			cout << "存在该元素" << endl;
			break;
		}
		p = p->next;
		i++;
	}
	return true;
}

template<typename T>
T& QGforwardList<T>::front()
{
	return head->next->data;
}

template<typename T>
T& QGforwardList<T>::back()
{
	p = head->next;
	while (p->next != NULL)
	{
		p = p->next;
	}
	return p->data;
}

template<typename T>
bool QGforwardList<T>::traverse(void (*print)(T& e))//这里我把visit定义成一个打印函数
{
	p = head->next;
	while (p != NULL)
	{
		print(p->data);
		p = p->next;
	}
	cout << endl;
	cout << "遍历打印完毕！" << endl;
	return true;
}

template <typename T>
bool QGforwardList<T>::reverse()
{
	Node<T>* beg = NULL;
	Node<T>* mid = head->next;
	Node<T>* end = head->next->next;
	while (1)
	{
		mid->next = beg;
		if (end == NULL)
		{
			break;
		}
		beg = mid;
		mid = end;
		end = end->next;
	}
	head->next = mid;
	return true;
}

template<typename T>
bool QGforwardList<T>::reverseEven()
{
	Node<T>* p, * q, * t;
	t = head;
	while (t->next && t->next->next)
	{
		q = t->next;
		p = q->next;
		t->next = p;
		q->next = p->next;
		p->next = q;
		t = q;
	}
	return true;
}

void menu();
void title();
void forwardmenu();
void chartype();
#endif

