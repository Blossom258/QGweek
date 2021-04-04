#include<iostream>
#include"Stack.h"
#include<Windows.h>
using std::string;
using std::cout;
using std::cin;
using std::endl;
int main()
{
	char y;
	int c = 0;
	int b = 0;
	char choice;
	title();
	cin >> y;
	while (y != '1' && y != '2')
	{
		cout << "输入有误,请重新输入1和2中的一个数字" << endl;
		cin >> y;
	}
	system("cls");
	if (y == '1')
	{
		sqmenu();
	cout << "因为您是第一次使用,请选择1进行栈创建" << endl;
	cin >> choice;
	while (choice != '1')
	{

		cout << "输入错误,请输入1进行栈创建" << endl;
		cin >> choice;
		b++;
		if (b % 3 == 0)
			system("cls");
	}
	system("cls");
	cout << "您想要创建什么类型的栈" << endl;
	cout << "1.char类型      2.int类型     3.string类型 " << endl;
	char d;
	cin >> d;
	b = 0;
	while (d != '1' && d != '2' && d != '3')
	{
		cout << "输入错误,请重新输入1，2，3选择类型" << endl;
		cin >> d;
		b++;
		if (b % 3 == 0)
			system("cls");
	}
	if (d == '1')
	{
		int size;
		cout << "请输入栈的最大长度" << endl;
		cin >> size;
		SqStack<char>stack(size);
		cout << "一个长度为" << size << "的栈创建成功" << endl;
		Sleep(1500);
		system("cls");
		sqmenu();
		cout << "由于栈为空，请输入4为栈添加元素" << endl;
		cin >> choice;
		while (choice != '4')
		{
			cout << "输入有误" << endl;
			cout << "请重新输入4进行操作" << endl;
			cin >> choice;
		}
		while (1)
		{
			switch (choice)
			{
			case '0':
			{
				exit(0);
				cout << "已经退出该栈" << endl;
				return 0;
			}
			case'2':
			{
				if (stack.getTop() == NULL)
				{
					cout << "此时为空栈,无法返回栈顶元素" << endl;
				}
				else
				{
					cout << "栈顶元素为:" << stack.getTop() << endl;
				}
				break;
			}
			case'3':
			{
				stack.clear();
				cout << "已经清空栈" << endl;
				break;
			}
			case'4':
			{
				char elem;
				cout << "请输入想要插入的元素" << endl;
				cin >> elem;
				if (stack.push(elem) == true)
				{
					cout << "插入完毕" << endl;
				}
				else
				{
					cout << "栈的容量已满,无法插入新的元素" << endl;
				}
				break;
			}
			case'5':
			{
				if (stack.pop() == true)
				{
					cout << "删除完毕" << endl;
				}
				else
				{

					cout << "栈的容量为空,无法删除栈顶元素" << endl;
				}

				break;
			}
			case'6':
			{
				if (stack.empty() == true)
					cout << "栈为空" << endl;
				else
					cout << "栈不为空" << endl;
				break;
			}
			case'7':
			{
				if (stack.print() == true)
					cout << "打印完毕" << endl;
				else
					cout << "栈为空,无法打印" << endl;

				break;
			}
			case'8':
			{
				cout << "栈的长度为" << stack.length() << endl;
				break;
			}
			case'9':
			{
				cout << "已经销毁本次栈构" << endl;
				break;
			}
			}
			cout << "系统将于1s返回菜单界面" << endl;
			Sleep(1000);
			system("cls");
			sqmenu();
			cout << "请输入你想要的操作" << endl;
			cin >> choice;
			while (choice != '0' && choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5' && choice != '6' && choice != '7' && choice != '8' && choice != '9')
			{
				cout << "输入有误，请重新选择操作" << endl;
				cin >> choice;
			}
			system("cls");
		}
	}
	else if (d == '2')
	{
		int size;
		cout << "请输入栈的最大长度" << endl;
		cin >> size;
		SqStack<int>stack(size);
		cout << "一个长度为" << size << "的栈创建成功" << endl;
		Sleep(1500);
		system("cls");
		sqmenu();
		cout << "由于栈为空，请输入4为栈添加元素" << endl;
		cin >> choice;
		while (choice != '4')
		{
			cout << "输入有误" << endl;
			cout << "请重新输入4进行操作" << endl;
			cin >> choice;
		}
		while (1)
		{
			switch (choice)
			{
			case '0':
			{
				exit(0);
				cout << "已经退出该栈" << endl;
				return 0;
			}
			case'2':
			{
				if (stack.getTop() == NULL)
				{
					cout << "此时为空栈,无法返回栈顶元素" << endl;
				}
				else
				{
					cout << "栈顶元素为:" << stack.getTop() << endl;
				}
				break;
			}
			case'3':
			{
				stack.clear();
				cout << "已经清空栈" << endl;
				break;
			}
			case'4':
			{
				int elem;
				cout << "请输入想要插入的元素" << endl;
				cin >> elem;

				if (stack.push(elem) == true)
				{
					cout << "插入完毕" << endl;
				}
				else
				{
					cout << "栈的容量已满,无法插入新的元素" << endl;
				}
				break;
			}
			case'5':
			{
				if (stack.pop() == true)

				{
					cout << "删除完毕" << endl;
				}
				else
				{
					cout << "栈的容量为空,无法删除栈顶元素" << endl;
				}
				break;
			}
			case'6':
			{
				if (stack.empty() == true)
					cout << "栈为空" << endl;
				else
					cout << "栈不为空" << endl;
				break;
			}
			case'7':
			{
				if (stack.print() == true)
					cout << "打印完毕" << endl;
				else
					cout << "栈为空,无法打印" << endl;
				break;
			}
			case'8':
			{
				cout << "栈的长度为" << stack.length() << endl;
				break;
			}
			case'9':
			{
				cout << "已经销毁本次栈构" << endl;
				break;
			}
			}
			cout << "系统将于1s返回菜单界面" << endl;
			Sleep(1000);
			system("cls");
			sqmenu();
			cout << "请输入你想要的操作" << endl;
			cin >> choice;
			while (choice != '0' && choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5' && choice != '6' && choice != '7' && choice != '8' && choice != '9')
			{
				cout << "输入有误，请重新选择操作" << endl;
				cin >> choice;
			}
			system("cls");
		}
	}
	else
	{
		int size;
		cout << "请输入栈的最大长度" << endl;
		cin >> size;
		SqStack<string>stack(size);
		cout << "一个长度为" << size << "的栈创建成功" << endl;
		Sleep(1500);
		system("cls");
		sqmenu();
		cout << "由于栈为空，请输入4为栈添加元素" << endl;
		cin >> choice;
		while (choice != '4')
		{
			cout << "输入有误" << endl;
			cout << "请重新输入4进行操作" << endl;
			cin >> choice;
		}
		while (1)
		{
			switch (choice)
			{
			case '0':
			{
				exit(0);
				cout << "已经退出该栈" << endl;
				return 0;
			}
			case'2':
			{

				cout << "栈顶元素为:" << stack.getTop() << endl;

				break;
			}
			case'3':
			{
				stack.clear();
				cout << "已经清空栈" << endl;
				break;
			}
			case'4':
			{
				string elem;
				cout << "请输入想要插入的元素" << endl;
				cin >> elem;

				if (stack.push(elem) == true)
				{
					cout << "插入完毕" << endl;
				}
				else
				{
					cout << "栈的容量已满,无法插入新的元素" << endl;
				}
				break;
			}
			case'5':
			{
				if (stack.pop() == true)

				{
					cout << "删除完毕" << endl;
				}
				else
				{
					cout << "栈的容量为空,无法删除栈顶元素" << endl;
				}
				break;
			}
			case'6':
			{
				if (stack.empty() == true)
					cout << "栈为空" << endl;
				else
					cout << "栈不为空" << endl;
				break;
			}
			case'7':
			{
				if (stack.print() == true)
					cout << "打印完毕" << endl;
				else
					cout << "栈为空,无法打印" << endl;
				break;
			}
			case'8':
			{
				cout << "栈的长度为" << stack.length() << endl;
				break;
			}
			case'9':
			{
				cout << "已经销毁本次栈构" << endl;
				break;
			}
			}
			cout << "系统将于1s返回菜单界面" << endl;
			Sleep(1000);
			system("cls");
			sqmenu();
			cout << "请输入你想要的操作" << endl;
			cin >> choice;
			while (choice != '0' && choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5' && choice != '6' && choice != '7' && choice != '8' && choice != '9')
			{
				cout << "输入有误，请重新选择操作" << endl;
				cin >> choice;
			}
			system("cls");
		}
	}
	}
	else
	{
	cout << "因为您是第一次使用,请选择1进行栈创建" << endl;
	cin >> choice;
	while (choice != '1')
	{

		cout << "输入错误,请输入1进行栈创建" << endl;
		cin >> choice;
		b++;
		if (b % 3 == 0)
			system("cls");
	}
	system("cls");
	cout << "您想要创建什么类型的栈" << endl;
	cout << "1.char类型      2.int类型     3.string类型 " << endl;
	char d;
	cin >> d;
	b = 0;
	while (d != '1' && d != '2' && d != '3')
	{
		cout << "输入错误,请重新输入1，2，3选择类型" << endl;
		cin >> d;
		b++;
		if (b % 3 == 0)
			system("cls");
	}
	if (d == '1')
	{
		LinkStack<char>stack;
		cout << "链栈已经创建成功" << endl;
		Sleep(1500);
		system("cls");
		sqmenu();
		cout << "由于栈为空，请输入4为栈添加元素" << endl;
		cin >> choice;
		while (choice != '4')
		{
			cout << "输入有误" << endl;
			cout << "请重新输入4进行操作" << endl;
			cin >> choice;
		}
		while (1)
		{
			switch (choice)
			{
			case '0':
			{
				exit(0);
				cout << "已经退出该栈" << endl;
				return 0;
			}
			case'2':
			{
				if (stack.getTop() == NULL)
				{
					cout << "此时为空栈,无法返回栈顶元素" << endl;
				}
				else
				{
					cout << "栈顶元素为:" << stack.getTop() << endl;
				}
				break;
			}
			case'3':
			{
				stack.clear();
				cout << "已经清空栈" << endl;
				break;
			}
			case'4':
			{
				char elem;
				cout << "请输入想要插入的元素" << endl;
				cin >> elem;
				if (stack.push(elem) == true)
				{
					cout << "插入完毕" << endl;
				}
				else
				{
					cout << "栈的容量已满,无法插入新的元素" << endl;
				}
				break;
			}
			case'5':
			{
				if (stack.pop() == true)
				{
					cout << "删除完毕" << endl;
				}
				else
				{

					cout << "栈的容量为空,无法删除栈顶元素" << endl;
				}

				break;
			}
			case'6':
			{
				if (stack.empty() == true)
					cout << "栈为空" << endl;
				else
					cout << "栈不为空" << endl;
				break;
			}
			case'7':
			{
				if (stack.print() == true)
					cout << "打印完毕" << endl;
				else
					cout << "栈为空,无法打印" << endl;

				break;
			}
			case'8':
			{
				cout << "栈的长度为" << stack.length() << endl;
				break;
			}
			case'9':
			{
				cout << "已经销毁本次栈构" << endl;
				break;
			}
			}
			cout << "系统将于1s返回菜单界面" << endl;
			Sleep(1000);
			system("cls");
			sqmenu();
			cout << "请输入你想要的操作" << endl;
			cin >> choice;
			while (choice != '0' && choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5' && choice != '6' && choice != '7' && choice != '8' && choice != '9')
			{
				cout << "输入有误，请重新选择操作" << endl;
				cin >> choice;
			}
			system("cls");
		}
	}
	if (d == '2')
	{
		LinkStack<int>stack;
		cout << "链栈已经创建成功" << endl;
		Sleep(1500);
		system("cls");
		sqmenu();
		cout << "由于栈为空，请输入4为栈添加元素" << endl;
		cin >> choice;
		while (choice != '4')
		{
			cout << "输入有误" << endl;
			cout << "请重新输入4进行操作" << endl;
			cin >> choice;
		}
		while (1)
		{
			switch (choice)
			{
			case '0':
			{
				exit(0);
				cout << "已经退出该栈" << endl;
				return 0;
			}
			case'2':
			{
				if (stack.getTop() == NULL)
				{
					cout << "此时为空栈,无法返回栈顶元素" << endl;
				}
				else
				{
					cout << "栈顶元素为:" << stack.getTop() << endl;
				}
				break;
			}
			case'3':
			{
				stack.clear();
				cout << "已经清空栈" << endl;
				break;
			}
			case'4':
			{
				int elem;
				cout << "请输入想要插入的元素" << endl;
				cin >> elem;
				if (stack.push(elem) == true)
				{
					cout << "插入完毕" << endl;
				}
				else
				{
					cout << "栈的容量已满,无法插入新的元素" << endl;
				}
				break;
			}
			case'5':
			{
				if (stack.pop() == true)
				{
					cout << "删除完毕" << endl;
				}
				else
				{

					cout << "栈的容量为空,无法删除栈顶元素" << endl;
				}

				break;
			}
			case'6':
			{
				if (stack.empty() == true)
					cout << "栈为空" << endl;
				else
					cout << "栈不为空" << endl;
				break;
			}
			case'7':
			{
				if (stack.print() == true)
					cout << "打印完毕" << endl;
				else
					cout << "栈为空,无法打印" << endl;

				break;
			}
			case'8':
			{
				cout << "栈的长度为" << stack.length() << endl;
				break;
			}
			case'9':
			{
				cout << "已经销毁本次栈构" << endl;
				break;
			}
			}
			cout << "系统将于1s返回菜单界面" << endl;
			Sleep(1000);
			system("cls");
			sqmenu();
			cout << "请输入你想要的操作" << endl;
			cin >> choice;
			while (choice != '0' && choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5' && choice != '6' && choice != '7' && choice != '8' && choice != '9')
			{
				cout << "输入有误，请重新选择操作" << endl;
				cin >> choice;
			}
			system("cls");
		}
	}
	else
	{
		LinkStack<string>stack;
		cout << "链栈已经创建成功" << endl;
		Sleep(1500);
		system("cls");
		sqmenu();
		cout << "由于栈为空，请输入4为栈添加元素" << endl;
		cin >> choice;
		while (choice != '4')
		{
			cout << "输入有误" << endl;
			cout << "请重新输入4进行操作" << endl;
			cin >> choice;
		}
		while (1)
		{
			switch (choice)
			{
			case '0':
			{
				exit(0);
				cout << "已经退出该栈" << endl;
				return 0;
			}
			case'2':
			{

				cout << "栈顶元素为:" << stack.getTop() << endl;
				
				break;
			}
			case'3':
			{
				stack.clear();
				cout << "已经清空栈" << endl;
				break;
			}
			case'4':
			{
				string elem;
				cout << "请输入想要插入的元素" << endl;
				cin >> elem;
				if (stack.push(elem) == true)
				{
					cout << "插入完毕" << endl;
				}
				else
				{
					cout << "栈的容量已满,无法插入新的元素" << endl;
				}
				break;
			}
			case'5':
			{
				if (stack.pop() == true)
				{
					cout << "删除完毕" << endl;
				}
				else
				{

					cout << "栈的容量为空,无法删除栈顶元素" << endl;
				}

				break;
			}
			case'6':
			{
				if (stack.empty() == true)
					cout << "栈为空" << endl;
				else
					cout << "栈不为空" << endl;
				break;
			}
			case'7':
			{
				if (stack.print() == true)
					cout << "打印完毕" << endl;
				else
					cout << "栈为空,无法打印" << endl;

				break;
			}
			case'8':
			{
				cout << "栈的长度为" << stack.length() << endl;
				break;
			}
			case'9':
			{
				cout << "已经销毁本次栈构" << endl;
				break;
			}
			}
			cout << "系统将于1s返回菜单界面" << endl;
			Sleep(1000);
			system("cls");
			sqmenu();
			cout << "请输入你想要的操作" << endl;
			cin >> choice;
			while (choice != '0' && choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5' && choice != '6' && choice != '7' && choice != '8' && choice != '9')
			{
				cout << "输入有误，请重新选择操作" << endl;
				cin >> choice;
			}
			system("cls");
		}
	}
	}
	return 0;
}
