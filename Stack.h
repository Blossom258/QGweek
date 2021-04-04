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
	//链栈
	LinkStack();//初始化栈
	~LinkStack();//销毁栈
	bool empty();//判断栈是否为空
	T getTop();//得到栈顶元素
	bool clear();//清空栈
	int length();//检测栈长度
	bool push(T e);//入栈
	bool pop();//出栈
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
	//基于数组的顺序栈
	SqStack(int size);//初始化栈
	~SqStack();//销毁栈
	bool empty();//判断栈是否为空
	T getTop(); //得到栈顶元素
	bool clear();//清空栈
	int  length();//检测栈长度
	bool push(const T& data);//入栈
	bool pop();//出栈
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
		//更新top的位置，插入数据后top的值就是当前栈中元素的个数
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





