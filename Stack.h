#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include<iostream>

template<class T>
class StackNode
{
public:
	T data;
	StackNode<T>* next;

};

template<class T>
class  LinkStack :public StackNode<T>
{
private:
	StackNode<T> *top;
	int	count;
public:
	//��ջ
	LinkStack();//��ʼ��ջ
	~LinkStack();//����ջ
	bool empty();//�ж�ջ�Ƿ�Ϊ��
	T getTop();//�õ�ջ��Ԫ��
	bool clear();//���ջ
	int length();//���ջ����
	bool push(T e);//��ջ
	bool pop();//��ջ
	bool print();
};
template<class T>
LinkStack<T>::LinkStack()
{
	top = nullptr;
	count = 0;
}
template<class T>
LinkStack<T>::~LinkStack()
{
	while (top)
	{
		StackNode<T>* p = top;
		top = top->next;
		delete p;
	}
	delete top;
}
template<class T>
bool LinkStack<T>::push(T e)
{
	StackNode<T>* p = new StackNode<T>;
	p->data = e;
	p->next = top;
	top=p;
	count++;
	return true;
}
template<class T>
bool LinkStack<T>::pop()
{
	if (top == nullptr)
	{
		return false;
	}
	StackNode<T>* p = new StackNode<T>;
	p = top;
	top = top->next;
	count--;
	delete p;

	return true;
}
template<class T>
bool LinkStack<T>::empty()
{
	if (top == nullptr)
	{
		return true;
	}
	return false;
}
template<class T>
bool LinkStack<T>::clear()
{
	while (top)
	{
		StackNode<T>* p = top;
		top = top->next;
		delete p;
	}
	count = 0;
	return true;
}
template<class T>
int  LinkStack<T>::length()
{
	return count;
}
template<class T>
T  LinkStack<T>::getTop()
{
	if (top != nullptr)
		return top->data;
}
template<class T>
bool LinkStack<T>::print()
{
	StackNode<T>* p = new StackNode<T>;
	p = top;
	if (empty() == true)
	{
		return false;
	}
	else
	{
		while (p != nullptr)
		{
			std::cout << p->data << std::endl;
			p = p->next;
		}
	}
	return true;
}



template<class T>
class SqStack
{
	T* elem;
	int top;
	int size;
public:
	//���������˳��ջ
	SqStack(int size);//��ʼ��ջ
	~SqStack();//����ջ
	bool empty();//�ж�ջ�Ƿ�Ϊ��
	T getTop(); //�õ�ջ��Ԫ��
	bool clear();//���ջ
	int  length();//���ջ����
	bool push(const T& data);//��ջ
	bool pop();//��ջ
	bool print();
};
template<class T>
SqStack<T>::SqStack(int size)
{
	this->size = size;
	this->top = -1;
	elem = new T[size];
	memset(elem, 0, size);
}
template<class T>
SqStack<T>::~SqStack()
{
	delete[]elem;
}
template<class T>
bool SqStack<T>::push(const T& data)
{
   	if (top+1==size)
	{		
		return false;
	}
	else
	{
		//����top��λ�ã��������ݺ�top��ֵ���ǵ�ǰջ��Ԫ�صĸ���
		elem[++top] = data;
		return true;
	}
}
template<class T>
bool SqStack<T>::pop()
{
	if (empty())
	{
		return false;
	}
	else
	{
		--top;
		return true;
	}
}
template<class T>
bool SqStack<T>::clear()
{
	top = -1;
	return true;
}
template<class T>
T SqStack<T>::getTop()
{
	if (!empty())
	{
		return elem[top];
	}
	return NULL;
}
template<class T>
bool SqStack<T>::empty()
{
	if (top == -1)
		return true;
	return false;
}
template<class T>
int SqStack<T>::length()
{
	return top + 1;
}
template<class T>
bool SqStack<T>::print()
{
	int a=0;
	a = top;
	if (empty() == true)
	{
		return false;
	}
	while (a != -1)
	{
		std::cout << elem[a] << std::endl;
		a--;
	}
	return true;
}


void linkmenu();
void sqmenu();
void title();
#endif 





