#include<iostream>
#include"qglist.h"
#include<Windows.h>
using namespace std;

int main()
{
	int y = 0;
	int c = 0;
	int b = 0;
	int choice;
	title();
	cin >> y;
	if (y == 1)
		menu();
	else
		forwardmenu();
	cout << "��Ϊ���ǵ�һ��ʹ��,��ѡ��1����������" << endl;
	cin >> choice;
	while (choice != 1)
	{

		cout << "�������,������1����������" << endl;
		cin >> choice;
		b++;
		if (b % 3 == 0)
			system("cls");
	}
	system("cls");
	cout << "����Ҫ����ʲô���͵�����" << endl;
	cout << "1.char����      2.int����     3.string���� " << endl;
	int d;
	cin >> d;
	if (d == 1)
	{
		QGList<char>list;
		cout << "�������ɹ�" << endl;
		Sleep(1500);
		system("cls");
		menu();
		cout << "��������Ϊ�գ�������7Ϊ�������Ԫ��" << endl;
		cin >> choice;
		while (choice != 7)
		{
			cout << "��������" << endl;
			cout << "����������7���в���" << endl;
			cin >> choice;
		}
		while (1)
		{
			switch (choice)
			{
			case 0:
			{
				exit(0);
				return 0;
			}
			case 2:
			{
				cout << "�Ѿ���������" << endl;
				break;
			}
			case 3:
			{
				char a = list.front();
				cout << "��Ԫ���õķ���ֵ��  " << a << endl;
				break;
			}
			case 4:
			{
				char b = list.back();
				cout << "����βԪ����  " << b << endl;
				break;
			}
			case 5:
			{
				char a;
				cout << "����������Ҫ���ַ�" << endl;
				cin >> a;
				list.push_front(a);
				cout << "�Ѿ������һ��Ԫ��" << endl;
				break;
			}
			case 6:
			{
				list.pop_back();
				cout << "�Ѿ�ɾ��ĩβԪ��" << endl;
				break;
			}
			case 7:
			{
				char a;
				cout << "����������Ҫ������ַ�" << endl;
				cin >> a;
				list.push_back(a);
				cout << "�Ѿ��������һ���ַ�" << endl;
				break;
			}
			case 8:
			{
				list.pop_front();
				cout << "�Ѿ�ɾ����һ��Ԫ��" << endl;
				break;
			}
			case 9:
			{
				int a;
				char b;
				cout << "����������Ҫ�����λ��" << endl;
				cin >> a;
				cout << "����������Ҫ�����Ԫ��" << endl;
				cin >> b;
				list.insert(a, b);
				cout << "�Ѿ��������" << endl;
				break;
			}
			case 10:
			{
				int a;
				cout << "����������Ҫɾ����λ��" << endl;
				cin >> a;
				list.erase(a);
				cout << "�Ѿ�ɾ�����" << endl;
				break;
			}
			case 11:
			{
				list.clear();
				cout << "�Ѿ���պ���" << endl;
				break;
			}
			case 12:
			{
				char a;
				cout << "����������Ҫ���ҵ��ַ�" << endl;
				list.contain(a);
				if (list.contain(a))
				{
					cout << "���ڸ�Ԫ��" << endl;
				}
				else
					cout << "�����ڸ�Ԫ��" << endl;
				break;
			}
			case 13:
			{
				cout << "����Ԫ�ظ���Ϊ  " << list.size() << endl;
				break;
			}
			case 14:
			{
				list.traverse(print);
				cout << "�����Ѿ���ӡ���" << endl;
				break;
			}
			case 15:
			{
				list.reverse();
				cout << "�����Ѿ���ת�ɹ�" << endl;
				break;
			}
			case 16:
			{
				list.isLoop();
				break;
			}
			case 17:
			{
				list.reverseEven();
				cout << "�����Ѿ���ż��ת" << endl;
				break;
			}
			case 18:
			{

				cout << "������м䷵��ֵ��  " << list.middleElem() << endl;
				break;
			}
			default:
			{
				cout << "��������,����������" << endl;
				cin >> choice;
				break;
			}
			}
			cout << "ϵͳ����1s���ز˵�����" << endl;
			Sleep(1000);
			system("cls");
			menu();
			cin >> choice;
		}
	}

	else if (d == 2)
	{
		QGList<int>list;
		cout << "�������ɹ�" << endl;
		Sleep(1500);
		system("cls");
		menu();
		cout << "��������Ϊ�գ�������7Ϊ�������Ԫ��" << endl;
		cin >> choice;
		while (choice != 7)
		{
			cout << "��������" << endl;
			cout << "����������7���в���" << endl;
			cin >> choice;
		}
		while (1)
		{
			switch (choice)
			{
			case 0:
			{
				exit(0);
				return 0;
			}
			case 2:
			{
				cout << "�Ѿ���������" << endl;
				break;
			}
			case 3:
			{
				int a = list.front();
				cout << "��Ԫ���õķ���ֵ��  " << a << endl;
				break;
			}
			case 4:
			{
				int b = list.back();
				cout << "����βԪ����  " << b << endl;
				break;
			}
			case 5:
			{
				int a;
				cout << "����������Ҫ������" << endl;
				cin >> a;
				list.push_front(a);
				cout << "�Ѿ������һ��Ԫ��" << endl;
				break;
			}
			case 6:
			{
				list.pop_back();
				cout << "�Ѿ�ɾ��ĩβԪ��" << endl;
				break;
			}
			case 7:
			{
				int a;
				cout << "����������Ҫ���������" << endl;
				cin >> a;
				list.push_back(a);
				cout << "�Ѿ��������һ������" << endl;
				break;
			}
			case 8:
			{
				list.pop_front();
				cout << "�Ѿ�ɾ����һ��Ԫ��" << endl;
				break;
			}
			case 9:
			{
				int a;
				int b;
				cout << "����������Ҫ�����λ��" << endl;
				cin >> a;
				cout << "����������Ҫ�����Ԫ��" << endl;
				cin >> b;
				list.insert(a, b);
				cout << "�Ѿ��������" << endl;
				break;
			}
			case 10:
			{
				int a;
				cout << "����������Ҫɾ����λ��" << endl;
				cin >> a;
				list.erase(a);
				cout << "�Ѿ�ɾ�����" << endl;
				break;
			}
			case 11:
			{
				list.clear();
				cout << "�Ѿ���պ���" << endl;
				break;
			}
			case 12:
			{
				int a;
				cout << "����������Ҫ���ҵ�����" << endl;
				cin >> a;
				list.contain(a);
				break;
			}
			case 13:
			{
				cout << "����Ԫ�ظ���Ϊ  " << list.size() << endl;
				break;
			}
			case 14:
			{
				list.traverse(print);
				cout << "�����Ѿ���ӡ���" << endl;
				break;
			}
			case 15:
			{
				list.reverse();
				cout << "�����Ѿ���ת�ɹ�" << endl;
				break;
			}
			case 16:
			{
				list.isLoop();
				break;
			}
			case 17:
			{
				list.reverseEven();
				cout << "�����Ѿ���ż��ת" << endl;
				break;
			}
			case 18:
			{

				cout << "������м䷵��ֵ��  " << list.middleElem() << endl;
				break;
			}
			default:
			{
				cout << "��������,����������" << endl;
				cin >> choice;
				break;
			}
			}
			cout << "ϵͳ����1s���ز˵�����" << endl;
			Sleep(1000);
			system("cls");
			menu();
			cin >> choice;
		}
	}
	else if (d == 3)
	{
		QGList<string>list;
		cout << "�������ɹ�" << endl;
		Sleep(1500);
		system("cls");
		menu();
		cout << "��������Ϊ�գ�������7Ϊ�������Ԫ��" << endl;
		cin >> choice;
		while (choice != 7)
		{
			cout << "��������" << endl;
			cout << "����������7���в���" << endl;
			cin >> choice;
		}
		while (1)
		{
			switch (choice)
			{
			case 0:
			{
				exit(0);
				return 0;
			}
			case 2:
			{
				cout << "�Ѿ���������" << endl;
				break;
			}
			case 3:
			{
				string a = list.front();
				cout << "��Ԫ���õķ���ֵ��  " << a << endl;
				break;
			}
			case 4:
			{
				string b = list.back();
				cout << "����βԪ����  " << b << endl;
				break;
			}
			case 5:
			{
				string a;
				cout << "����������Ҫ���ַ���" << endl;
				cin >> a;
				list.push_front(a);
				cout << "�Ѿ������һ��Ԫ��" << endl;
				break;
			}
			case 6:
			{
				list.pop_back();
				cout << "�Ѿ�ɾ��ĩβԪ��" << endl;
				break;
			}
			case 7:
			{
				string a;
				cout << "����������Ҫ������ַ���" << endl;
				cin >> a;
				list.push_back(a);
				cout << "�Ѿ��������һ���ַ���" << endl;
				break;
			}
			case 8:
			{
				list.pop_front();
				cout << "�Ѿ�ɾ����һ��Ԫ��" << endl;
				break;
			}
			case 9:
			{
				int a;
				string b;
				cout << "����������Ҫ�����λ��" << endl;
				cin >> a;
				cout << "����������Ҫ�����Ԫ��" << endl;
				cin >> b;
				list.insert(a, b);
				cout << "�Ѿ��������" << endl;
				break;
			}
			case 10:
			{
				int a;
				cout << "����������Ҫɾ����λ��" << endl;
				cin >> a;
				list.erase(a);
				cout << "�Ѿ�ɾ�����" << endl;
				break;
			}
			case 11:
			{
				list.clear();
				cout << "�Ѿ���պ���" << endl;
				break;
			}
			case 12:
			{
				string a;
				cout << "����������Ҫ���ҵ�����" << endl;
				cin >> a;
				list.contain(a);
				break;
			}
			case 13:
			{
				cout << "����Ԫ�ظ���Ϊ  " << list.size() << endl;
				break;
			}
			case 14:
			{
				list.traverse(print);
				cout << "�����Ѿ���ӡ���" << endl;
				break;
			}
			case 15:
			{
				list.reverse();
				cout << "�����Ѿ���ת�ɹ�" << endl;
				break;
			}
			case 16:
			{
				list.isLoop();
				break;
			}
			case 17:
			{
				list.reverseEven();
				cout << "�����Ѿ���ż��ת" << endl;
				break;
			}
			case 18:
			{

				cout << "������м䷵��ֵ��  " << list.middleElem() << endl;
				break;
			}
			default:
			{
				cout << "��������,����������" << endl;
				cin >> choice;
				break;
			}
			}
			cout << "ϵͳ����1s���ز˵�����" << endl;
			Sleep(1000);
			system("cls");
			menu();
			cin >> choice;
		}
	}
		return 0;
}
		
		