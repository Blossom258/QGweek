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
		cout << "��������,����������1��2�е�һ������" << endl;
		cin >> y;
	}
	system("cls");
	if (y == '1')
	{
		sqmenu();
	cout << "��Ϊ���ǵ�һ��ʹ��,��ѡ��1����ջ����" << endl;
	cin >> choice;
	while (choice != '1')
	{

		cout << "�������,������1����ջ����" << endl;
		cin >> choice;
		b++;
		if (b % 3 == 0)
			system("cls");
	}
	system("cls");
	cout << "����Ҫ����ʲô���͵�ջ" << endl;
	cout << "1.char����      2.int����     3.string���� " << endl;
	char d;
	cin >> d;
	b = 0;
	while (d != '1' && d != '2' && d != '3')
	{
		cout << "�������,����������1��2��3ѡ������" << endl;
		cin >> d;
		b++;
		if (b % 3 == 0)
			system("cls");
	}
	if (d == '1')
	{
		int size;
		cout << "������ջ����󳤶�" << endl;
		cin >> size;
		SqStack<char>stack(size);
		cout << "һ������Ϊ" << size << "��ջ�����ɹ�" << endl;
		Sleep(1500);
		system("cls");
		sqmenu();
		cout << "����ջΪ�գ�������4Ϊջ���Ԫ��" << endl;
		cin >> choice;
		while (choice != '4')
		{
			cout << "��������" << endl;
			cout << "����������4���в���" << endl;
			cin >> choice;
		}
		while (1)
		{
			switch (choice)
			{
			case '0':
			{
				exit(0);
				cout << "�Ѿ��˳���ջ" << endl;
				return 0;
			}
			case'2':
			{
				if (stack.getTop() == NULL)
				{
					cout << "��ʱΪ��ջ,�޷�����ջ��Ԫ��" << endl;
				}
				else
				{
					cout << "ջ��Ԫ��Ϊ:" << stack.getTop() << endl;
				}
				break;
			}
			case'3':
			{
				stack.clear();
				cout << "�Ѿ����ջ" << endl;
				break;
			}
			case'4':
			{
				char elem;
				cout << "��������Ҫ�����Ԫ��" << endl;
				cin >> elem;
				if (stack.push(elem) == true)
				{
					cout << "�������" << endl;
				}
				else
				{
					cout << "ջ����������,�޷������µ�Ԫ��" << endl;
				}
				break;
			}
			case'5':
			{
				if (stack.pop() == true)
				{
					cout << "ɾ�����" << endl;
				}
				else
				{

					cout << "ջ������Ϊ��,�޷�ɾ��ջ��Ԫ��" << endl;
				}

				break;
			}
			case'6':
			{
				if (stack.empty() == true)
					cout << "ջΪ��" << endl;
				else
					cout << "ջ��Ϊ��" << endl;
				break;
			}
			case'7':
			{
				if (stack.print() == true)
					cout << "��ӡ���" << endl;
				else
					cout << "ջΪ��,�޷���ӡ" << endl;

				break;
			}
			case'8':
			{
				cout << "ջ�ĳ���Ϊ" << stack.length() << endl;
				break;
			}
			case'9':
			{
				cout << "�Ѿ����ٱ���ջ��" << endl;
				break;
			}
			}
			cout << "ϵͳ����1s���ز˵�����" << endl;
			Sleep(1000);
			system("cls");
			sqmenu();
			cout << "����������Ҫ�Ĳ���" << endl;
			cin >> choice;
			while (choice != '0' && choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5' && choice != '6' && choice != '7' && choice != '8' && choice != '9')
			{
				cout << "��������������ѡ�����" << endl;
				cin >> choice;
			}
			system("cls");
		}
	}
	else if (d == '2')
	{
		int size;
		cout << "������ջ����󳤶�" << endl;
		cin >> size;
		SqStack<int>stack(size);
		cout << "һ������Ϊ" << size << "��ջ�����ɹ�" << endl;
		Sleep(1500);
		system("cls");
		sqmenu();
		cout << "����ջΪ�գ�������4Ϊջ���Ԫ��" << endl;
		cin >> choice;
		while (choice != '4')
		{
			cout << "��������" << endl;
			cout << "����������4���в���" << endl;
			cin >> choice;
		}
		while (1)
		{
			switch (choice)
			{
			case '0':
			{
				exit(0);
				cout << "�Ѿ��˳���ջ" << endl;
				return 0;
			}
			case'2':
			{
				if (stack.getTop() == NULL)
				{
					cout << "��ʱΪ��ջ,�޷�����ջ��Ԫ��" << endl;
				}
				else
				{
					cout << "ջ��Ԫ��Ϊ:" << stack.getTop() << endl;
				}
				break;
			}
			case'3':
			{
				stack.clear();
				cout << "�Ѿ����ջ" << endl;
				break;
			}
			case'4':
			{
				int elem;
				cout << "��������Ҫ�����Ԫ��" << endl;
				cin >> elem;

				if (stack.push(elem) == true)
				{
					cout << "�������" << endl;
				}
				else
				{
					cout << "ջ����������,�޷������µ�Ԫ��" << endl;
				}
				break;
			}
			case'5':
			{
				if (stack.pop() == true)

				{
					cout << "ɾ�����" << endl;
				}
				else
				{
					cout << "ջ������Ϊ��,�޷�ɾ��ջ��Ԫ��" << endl;
				}
				break;
			}
			case'6':
			{
				if (stack.empty() == true)
					cout << "ջΪ��" << endl;
				else
					cout << "ջ��Ϊ��" << endl;
				break;
			}
			case'7':
			{
				if (stack.print() == true)
					cout << "��ӡ���" << endl;
				else
					cout << "ջΪ��,�޷���ӡ" << endl;
				break;
			}
			case'8':
			{
				cout << "ջ�ĳ���Ϊ" << stack.length() << endl;
				break;
			}
			case'9':
			{
				cout << "�Ѿ����ٱ���ջ��" << endl;
				break;
			}
			}
			cout << "ϵͳ����1s���ز˵�����" << endl;
			Sleep(1000);
			system("cls");
			sqmenu();
			cout << "����������Ҫ�Ĳ���" << endl;
			cin >> choice;
			while (choice != '0' && choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5' && choice != '6' && choice != '7' && choice != '8' && choice != '9')
			{
				cout << "��������������ѡ�����" << endl;
				cin >> choice;
			}
			system("cls");
		}
	}
	else
	{
		int size;
		cout << "������ջ����󳤶�" << endl;
		cin >> size;
		SqStack<string>stack(size);
		cout << "һ������Ϊ" << size << "��ջ�����ɹ�" << endl;
		Sleep(1500);
		system("cls");
		sqmenu();
		cout << "����ջΪ�գ�������4Ϊջ���Ԫ��" << endl;
		cin >> choice;
		while (choice != '4')
		{
			cout << "��������" << endl;
			cout << "����������4���в���" << endl;
			cin >> choice;
		}
		while (1)
		{
			switch (choice)
			{
			case '0':
			{
				exit(0);
				cout << "�Ѿ��˳���ջ" << endl;
				return 0;
			}
			case'2':
			{

				cout << "ջ��Ԫ��Ϊ:" << stack.getTop() << endl;

				break;
			}
			case'3':
			{
				stack.clear();
				cout << "�Ѿ����ջ" << endl;
				break;
			}
			case'4':
			{
				string elem;
				cout << "��������Ҫ�����Ԫ��" << endl;
				cin >> elem;

				if (stack.push(elem) == true)
				{
					cout << "�������" << endl;
				}
				else
				{
					cout << "ջ����������,�޷������µ�Ԫ��" << endl;
				}
				break;
			}
			case'5':
			{
				if (stack.pop() == true)

				{
					cout << "ɾ�����" << endl;
				}
				else
				{
					cout << "ջ������Ϊ��,�޷�ɾ��ջ��Ԫ��" << endl;
				}
				break;
			}
			case'6':
			{
				if (stack.empty() == true)
					cout << "ջΪ��" << endl;
				else
					cout << "ջ��Ϊ��" << endl;
				break;
			}
			case'7':
			{
				if (stack.print() == true)
					cout << "��ӡ���" << endl;
				else
					cout << "ջΪ��,�޷���ӡ" << endl;
				break;
			}
			case'8':
			{
				cout << "ջ�ĳ���Ϊ" << stack.length() << endl;
				break;
			}
			case'9':
			{
				cout << "�Ѿ����ٱ���ջ��" << endl;
				break;
			}
			}
			cout << "ϵͳ����1s���ز˵�����" << endl;
			Sleep(1000);
			system("cls");
			sqmenu();
			cout << "����������Ҫ�Ĳ���" << endl;
			cin >> choice;
			while (choice != '0' && choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5' && choice != '6' && choice != '7' && choice != '8' && choice != '9')
			{
				cout << "��������������ѡ�����" << endl;
				cin >> choice;
			}
			system("cls");
		}
	}
	}
	else
	{
	cout << "��Ϊ���ǵ�һ��ʹ��,��ѡ��1����ջ����" << endl;
	cin >> choice;
	while (choice != '1')
	{

		cout << "�������,������1����ջ����" << endl;
		cin >> choice;
		b++;
		if (b % 3 == 0)
			system("cls");
	}
	system("cls");
	cout << "����Ҫ����ʲô���͵�ջ" << endl;
	cout << "1.char����      2.int����     3.string���� " << endl;
	char d;
	cin >> d;
	b = 0;
	while (d != '1' && d != '2' && d != '3')
	{
		cout << "�������,����������1��2��3ѡ������" << endl;
		cin >> d;
		b++;
		if (b % 3 == 0)
			system("cls");
	}
	if (d == '1')
	{
		LinkStack<char>stack;
		cout << "��ջ�Ѿ������ɹ�" << endl;
		Sleep(1500);
		system("cls");
		sqmenu();
		cout << "����ջΪ�գ�������4Ϊջ���Ԫ��" << endl;
		cin >> choice;
		while (choice != '4')
		{
			cout << "��������" << endl;
			cout << "����������4���в���" << endl;
			cin >> choice;
		}
		while (1)
		{
			switch (choice)
			{
			case '0':
			{
				exit(0);
				cout << "�Ѿ��˳���ջ" << endl;
				return 0;
			}
			case'2':
			{
				if (stack.getTop() == NULL)
				{
					cout << "��ʱΪ��ջ,�޷�����ջ��Ԫ��" << endl;
				}
				else
				{
					cout << "ջ��Ԫ��Ϊ:" << stack.getTop() << endl;
				}
				break;
			}
			case'3':
			{
				stack.clear();
				cout << "�Ѿ����ջ" << endl;
				break;
			}
			case'4':
			{
				char elem;
				cout << "��������Ҫ�����Ԫ��" << endl;
				cin >> elem;
				if (stack.push(elem) == true)
				{
					cout << "�������" << endl;
				}
				else
				{
					cout << "ջ����������,�޷������µ�Ԫ��" << endl;
				}
				break;
			}
			case'5':
			{
				if (stack.pop() == true)
				{
					cout << "ɾ�����" << endl;
				}
				else
				{

					cout << "ջ������Ϊ��,�޷�ɾ��ջ��Ԫ��" << endl;
				}

				break;
			}
			case'6':
			{
				if (stack.empty() == true)
					cout << "ջΪ��" << endl;
				else
					cout << "ջ��Ϊ��" << endl;
				break;
			}
			case'7':
			{
				if (stack.print() == true)
					cout << "��ӡ���" << endl;
				else
					cout << "ջΪ��,�޷���ӡ" << endl;

				break;
			}
			case'8':
			{
				cout << "ջ�ĳ���Ϊ" << stack.length() << endl;
				break;
			}
			case'9':
			{
				cout << "�Ѿ����ٱ���ջ��" << endl;
				break;
			}
			}
			cout << "ϵͳ����1s���ز˵�����" << endl;
			Sleep(1000);
			system("cls");
			sqmenu();
			cout << "����������Ҫ�Ĳ���" << endl;
			cin >> choice;
			while (choice != '0' && choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5' && choice != '6' && choice != '7' && choice != '8' && choice != '9')
			{
				cout << "��������������ѡ�����" << endl;
				cin >> choice;
			}
			system("cls");
		}
	}
	if (d == '2')
	{
		LinkStack<int>stack;
		cout << "��ջ�Ѿ������ɹ�" << endl;
		Sleep(1500);
		system("cls");
		sqmenu();
		cout << "����ջΪ�գ�������4Ϊջ���Ԫ��" << endl;
		cin >> choice;
		while (choice != '4')
		{
			cout << "��������" << endl;
			cout << "����������4���в���" << endl;
			cin >> choice;
		}
		while (1)
		{
			switch (choice)
			{
			case '0':
			{
				exit(0);
				cout << "�Ѿ��˳���ջ" << endl;
				return 0;
			}
			case'2':
			{
				if (stack.getTop() == NULL)
				{
					cout << "��ʱΪ��ջ,�޷�����ջ��Ԫ��" << endl;
				}
				else
				{
					cout << "ջ��Ԫ��Ϊ:" << stack.getTop() << endl;
				}
				break;
			}
			case'3':
			{
				stack.clear();
				cout << "�Ѿ����ջ" << endl;
				break;
			}
			case'4':
			{
				int elem;
				cout << "��������Ҫ�����Ԫ��" << endl;
				cin >> elem;
				if (stack.push(elem) == true)
				{
					cout << "�������" << endl;
				}
				else
				{
					cout << "ջ����������,�޷������µ�Ԫ��" << endl;
				}
				break;
			}
			case'5':
			{
				if (stack.pop() == true)
				{
					cout << "ɾ�����" << endl;
				}
				else
				{

					cout << "ջ������Ϊ��,�޷�ɾ��ջ��Ԫ��" << endl;
				}

				break;
			}
			case'6':
			{
				if (stack.empty() == true)
					cout << "ջΪ��" << endl;
				else
					cout << "ջ��Ϊ��" << endl;
				break;
			}
			case'7':
			{
				if (stack.print() == true)
					cout << "��ӡ���" << endl;
				else
					cout << "ջΪ��,�޷���ӡ" << endl;

				break;
			}
			case'8':
			{
				cout << "ջ�ĳ���Ϊ" << stack.length() << endl;
				break;
			}
			case'9':
			{
				cout << "�Ѿ����ٱ���ջ��" << endl;
				break;
			}
			}
			cout << "ϵͳ����1s���ز˵�����" << endl;
			Sleep(1000);
			system("cls");
			sqmenu();
			cout << "����������Ҫ�Ĳ���" << endl;
			cin >> choice;
			while (choice != '0' && choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5' && choice != '6' && choice != '7' && choice != '8' && choice != '9')
			{
				cout << "��������������ѡ�����" << endl;
				cin >> choice;
			}
			system("cls");
		}
	}
	else
	{
		LinkStack<string>stack;
		cout << "��ջ�Ѿ������ɹ�" << endl;
		Sleep(1500);
		system("cls");
		sqmenu();
		cout << "����ջΪ�գ�������4Ϊջ���Ԫ��" << endl;
		cin >> choice;
		while (choice != '4')
		{
			cout << "��������" << endl;
			cout << "����������4���в���" << endl;
			cin >> choice;
		}
		while (1)
		{
			switch (choice)
			{
			case '0':
			{
				exit(0);
				cout << "�Ѿ��˳���ջ" << endl;
				return 0;
			}
			case'2':
			{

				cout << "ջ��Ԫ��Ϊ:" << stack.getTop() << endl;
				
				break;
			}
			case'3':
			{
				stack.clear();
				cout << "�Ѿ����ջ" << endl;
				break;
			}
			case'4':
			{
				string elem;
				cout << "��������Ҫ�����Ԫ��" << endl;
				cin >> elem;
				if (stack.push(elem) == true)
				{
					cout << "�������" << endl;
				}
				else
				{
					cout << "ջ����������,�޷������µ�Ԫ��" << endl;
				}
				break;
			}
			case'5':
			{
				if (stack.pop() == true)
				{
					cout << "ɾ�����" << endl;
				}
				else
				{

					cout << "ջ������Ϊ��,�޷�ɾ��ջ��Ԫ��" << endl;
				}

				break;
			}
			case'6':
			{
				if (stack.empty() == true)
					cout << "ջΪ��" << endl;
				else
					cout << "ջ��Ϊ��" << endl;
				break;
			}
			case'7':
			{
				if (stack.print() == true)
					cout << "��ӡ���" << endl;
				else
					cout << "ջΪ��,�޷���ӡ" << endl;

				break;
			}
			case'8':
			{
				cout << "ջ�ĳ���Ϊ" << stack.length() << endl;
				break;
			}
			case'9':
			{
				cout << "�Ѿ����ٱ���ջ��" << endl;
				break;
			}
			}
			cout << "ϵͳ����1s���ز˵�����" << endl;
			Sleep(1000);
			system("cls");
			sqmenu();
			cout << "����������Ҫ�Ĳ���" << endl;
			cin >> choice;
			while (choice != '0' && choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5' && choice != '6' && choice != '7' && choice != '8' && choice != '9')
			{
				cout << "��������������ѡ�����" << endl;
				cin >> choice;
			}
			system("cls");
		}
	}
	}
	return 0;
}
