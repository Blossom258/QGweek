#include<iostream>
#include"qglist.h"
#include<Windows.h>
using namespace std;

int main()
{
	char y ;
	int c = 0;
	int b = 0;
	char choice;
	title();
	cin >> y;
	while(y != '1' && y !='2')
	{
		cout << "输入有误,请重新输入1和2中的一个数字" << endl;
		cin >> y;
	}
	system("cls");
	if (y == '1')
		menu();
	else
		forwardmenu();
	cout << "因为您是第一次使用,请选择1进行链表创建" << endl;
	cin >> choice;
	while (choice != '1')
	{

		cout << "输入错误,请输入1进行链表创建" << endl;
		cin >> choice;
		b++;
		if (b % 3 == 0)
			system("cls");
	}
	system("cls");
	cout << "您想要创建什么类型的链表" << endl;
	cout << "1.char类型      2.int类型     3.string类型 " << endl;
	char d;
	cin >> d;
	b = 0;
	while (d != '1'&&d!='2'&&d!='3')
	{

		cout << "输入错误,请重新输入1，2，3选择类型" << endl;
		cin >> d;
		b++;
		if (b % 3 == 0)
			system("cls");
	}
	if (d == '1')
	{
		QGList<char>list;
		cout << "链表创建成功" << endl;
		Sleep(1500);
		system("cls");
		menu();
		cout << "由于链表为空，请输入7为链表添加元素" << endl;
		cin >> choice;
		while (choice != '7')
		{
			cout << "输入有误" << endl;
			cout << "请重新输入7进行操作" << endl;
			cin >> choice;
		}
		while (1)
		{
			switch (choice)
			{
			case '0':
			{
				exit(0);
				return 0;
			}
			case'2':
			{
				cout << "已经销毁链表" << endl;
				break;
			}
			case '3':
			{
				char a = list.front();
				cout << "首元引用的返回值是  " << a << endl;
				break;
			}
			case '4':
			{
				char b = list.back();
				cout << "返回尾元引用  " << b << endl;
				break;
			}
			case '5':
			{
				char a;
				cout << "请输入你想要的字符" << endl;
				cin >> a;
				list.push_front(a);
				cout << "已经插入第一个元素" << endl;
				break;
			}
			case '6':
			{
				list.pop_back();
				cout << "已经删除末尾元素" << endl;
				break;
			}
			case '7':
			{
				char a;
				cout << "请输入你想要插入的字符" << endl;
				cin >> a;
				list.push_back(a);
				cout << "已经插入最后一个字符" << endl;
				break;
			}
			case '8':
			{
				list.pop_front();
				cout << "已经删除第一个元素" << endl;
				break;
			}
			case '9':
			{
				int a;
				char b;
				cout << "请输入你想要插入的位置" << endl;
				cin >> a;
				cout << "请输入你想要插入的元素" << endl;
				cin >> b;
				list.insert(a, b);
				cout << "已经插入完毕" << endl;
				break;
			}
			case' 10':
			{
				int a;
				cout << "请输入你想要删除的位置" << endl;
				cin >> a;
				list.erase(a);
				cout << "已经删除完毕" << endl;
				break;
			}
			case '11':
			{
				list.clear();
				cout << "已经清空函数" << endl;
				break;
			}
			case '12':
			{
				char a;
				cout << "请输入你想要查找的字符" << endl;
				list.contain(a);
				if (list.contain(a))
				{
					cout << "存在该元素" << endl;
				}
				else
					cout << "不存在该元素" << endl;
				break;
			}
			case '13':
			{
				cout << "链表元素个数为  " << list.size() << endl;
				break;
			}
			case '14':
			{
				list.traverse(print);
				cout << "链表已经打印完毕" << endl;
				break;
			}
			case '15':
			{
				list.reverse();
				cout << "链表已经反转成功" << endl;
				break;
			}
			case '16':
			{
				list.isLoop();
				break;
			}
			case' 17':
			{
				list.reverseEven();
				cout << "链表已经奇偶反转" << endl;
				break;
			}
			case '18':
			{

				cout << "链表的中间返回值是  " << list.middleElem() << endl;
				break;
			}

			}
			cout << "系统将于1s返回菜单界面" << endl;
			Sleep(1000);
			system("cls");
			menu();
			cout << "请输入你想要的操作" << endl;
			cin >> choice;
			while (choice != '0' && choice != '0' && choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5' && choice != '6' && choice != '7' && choice != '8' && choice != '9' && choice != '10' && choice != '11' && choice != '12' && choice != '13' && choice != '14' && choice != '15' && choice != '16' && choice != '17' && choice != '18')
			{
				cout << "输入有误，请重新选择操作" << endl;
				cin >> choice;
			}
			system("cls");
		}
	}

	else if (d == '2')
	{
		QGList<int>list;
		cout << "链表创建成功" << endl;
		Sleep(1500);
		system("cls");
		menu();
		cout << "由于链表为空，请输入7为链表添加元素" << endl;
		cin >> choice;
		while (choice != 7)
		{
			cout << "输入有误" << endl;
			cout << "请重新输入7进行操作" << endl;
			cin >> choice;
		}
		while (1)
		{
			switch (choice)
			{
			case '0':
			{
				exit(0);
				return 0;
			}
			case '2':
			{
				cout << "已经销毁链表" << endl;
				break;
			}
			case '3':
			{
				int a = list.front();
				cout << "首元引用的返回值是  " << a << endl;
				break;
			}
			case '4':
			{
				int b = list.back();
				cout << "返回尾元引用  " << b << endl;
				break;
			}
			case '5':
			{
				int a;
				cout << "请输入你想要的整型" << endl;
				cin >> a;
				list.push_front(a);
				cout << "已经插入第一个元素" << endl;
				break;
			}
			case' 6':
			{
				list.pop_back();
				cout << "已经删除末尾元素" << endl;
				break;
			}
			case '7':
			{
				int a;
				cout << "请输入你想要插入的整型" << endl;
				cin >> a;
				list.push_back(a);
				cout << "已经插入最后一个整型" << endl;
				break;
			}
			case '8':
			{
				list.pop_front();
				cout << "已经删除第一个元素" << endl;
				break;
			}
			case '9':
			{
				int a;
				int b;
				cout << "请输入你想要插入的位置" << endl;
				cin >> a;
				cout << "请输入你想要插入的元素" << endl;
				cin >> b;
				list.insert(a, b);
				cout << "已经插入完毕" << endl;
				break;
			}
			case '10':
			{
				int a;
				cout << "请输入你想要删除的位置" << endl;
				cin >> a;
				list.erase(a);
				cout << "已经删除完毕" << endl;
				break;
			}
			case '11':
			{
				list.clear();
				cout << "已经清空函数" << endl;
				break;
			}
			case '12':
			{
				int a;
				cout << "请输入你想要查找的整型" << endl;
				cin >> a;
				list.contain(a);
				break;
			}
			case '13':
			{
				cout << "链表元素个数为  " << list.size() << endl;
				break;
			}
			case '14':
			{
				list.traverse(print);
				cout << "链表已经打印完毕" << endl;
				break;
			}
			case '15':
			{
				list.reverse();
				cout << "链表已经反转成功" << endl;
				break;
			}
			case '16':
			{
				list.isLoop();
				break;
			}
			case '17':
			{
				list.reverseEven();
				cout << "链表已经奇偶反转" << endl;
				break;
			}
			case '18':
			{

				cout << "链表的中间返回值是  " << list.middleElem() << endl;
				break;
			}

			}
			cout << "系统将于1s返回菜单界面" << endl;
			Sleep(1000);
			system("cls");
			menu();
			cout << "请输入你想要的操作" << endl;
			cin >> choice;
			while (choice != '0' && choice != '0' && choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5' && choice != '6' && choice != '7' && choice != '8' && choice != '9' && choice != '10' && choice != '11' && choice != '12' && choice != '13' && choice != '14' && choice != '15' && choice != '16' && choice != '17' && choice != '18')
			{
				cout << "输入有误，请重新选择操作" << endl;
				cin >> choice;
			}
			system("cls");
		}
	}
	else if (d == '3')
	{
		QGList<string>list;
		cout << "链表创建成功" << endl;
		Sleep(1500);
		system("cls");
		menu();
		cout << "由于链表为空，请输入7为链表添加元素" << endl;
		cin >> choice;
		while (choice != 7)
		{
			cout << "输入有误" << endl;
			cout << "请重新输入7进行操作" << endl;
			cin >> choice;
		}
		while (1)
		{
			switch (choice)
			{
			case' 0':
			{
				exit(0);
				return 0;
			}
			case '2':
			{
				cout << "已经销毁链表" << endl;
				break;
			}
			case '3':
			{
				string a = list.front();
				cout << "首元引用的返回值是  " << a << endl;
				break;
			}
			case '4':
			{
				string b = list.back();
				cout << "返回尾元引用  " << b << endl;
				break;
			}
			case '5':
			{
				string a;
				cout << "请输入你想要的字符串" << endl;
				cin >> a;
				list.push_front(a);
				cout << "已经插入第一个元素" << endl;
				break;
			}
			case '6':
			{
				list.pop_back();
				cout << "已经删除末尾元素" << endl;
				break;
			}
			case '7':
			{
				string a;
				cout << "请输入你想要插入的字符串" << endl;
				cin >> a;
				list.push_back(a);
				cout << "已经插入最后一个字符串" << endl;
				break;
			}
			case '8':
			{
				list.pop_front();
				cout << "已经删除第一个元素" << endl;
				break;
			}
			case '9':
			{
				int a;
				string b;
				cout << "请输入你想要插入的位置" << endl;
				cin >> a;
				cout << "请输入你想要插入的元素" << endl;
				cin >> b;
				list.insert(a, b);
				cout << "已经插入完毕" << endl;
				break;
			}
			case '10':
			{
				int a;
				cout << "请输入你想要删除的位置" << endl;
				cin >> a;
				list.erase(a);
				cout << "已经删除完毕" << endl;
				break;
			}
			case '11':
			{
				list.clear();
				cout << "已经清空函数" << endl;
				break;
			}
			case '12':
			{
				string a;
				cout << "请输入你想要查找的整型" << endl;
				cin >> a;
				list.contain(a);
				break;
			}
			case '13':
			{
				cout << "链表元素个数为  " << list.size() << endl;
				break;
			}
			case '14':
			{
				list.traverse(print);
				cout << "链表已经打印完毕" << endl;
				break;
			}
			case '15':
			{
				list.reverse();
				cout << "链表已经反转成功" << endl;
				break;
			}
			case '16':
			{
				list.isLoop();
				break;
			}
			case '17':
			{
				list.reverseEven();
				cout << "链表已经奇偶反转" << endl;
				break;
			}
			case '18':
			{

				cout << "链表的中间返回值是  " << list.middleElem() << endl;
				break;
			}

			}
			cout << "系统将于1s返回菜单界面" << endl;
			Sleep(1000);
			system("cls");
			menu();
			cout << "请输入你想要的操作" << endl;
			cin >> choice;
			while (choice != '0' && choice != '0' && choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5' && choice != '6' && choice != '7' && choice != '8' && choice != '9' && choice != '10' && choice != '11' && choice != '12' && choice != '13' && choice != '14' && choice != '15' && choice != '16' && choice != '17' && choice != '18')
			{
				cout << "输入有误，请重新选择操作" << endl;
				cin >> choice;
			}
			system("cls");
		}
	}
		return 0;
}
		
		