#include"binary_sort_tree.h"
#include<iostream>
#include<Windows.h>
using std::cout;
using std::cin;
using std::endl;
/*int main()
{
	char choice;
	int b = 0;
	menu();
	cout << "��Ϊ���ǵ�һ��ʹ��,��ѡ��1���ж�������������" << endl;
	cin >> choice;
	while (choice != '1')
	{

		cout << "�������,������1���ж�������������" << endl;
		cin >> choice;
		b++;
		if (b % 3 == 0)
			system("cls");
	}
	system("cls");
	cout << "����Ҫ����ʲô���͵�����" << endl;
	cout << "1.int����      2.char����     3.float���� " << endl;
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
		BinarySortTree<int> bst;
		cout << "��������������ɹ�" << endl;
		Sleep(1000);
		system("cls");
		menu();
		cout << "�������������Ϊ�գ�������2Ϊ������������Ԫ��" << endl;
		cin >> choice;
		while (choice != '2')
		{
			cout << "��������" << endl;
			cout << "����������2���в���" << endl;
			cin >> choice;
		}
		while (1)
		{
			switch (choice)
			{
			case '0':
			{
				cout << "�ɹ��˳��ö�����\n" << endl;
				exit(0);
				return 0;
			}
			case'2':
			{
				int a;
				cout << "����������Ҫ�������������" << endl;
				cin >> a;
				while (a < -32768 || a>32767)
				{
					cout << "�Ѿ��������ͷ�Χ-32768-32767,����������" << endl;
					cin >> a;
				}
				if (bst.BST_insert(a) == false)
				{
					cout << "����������Ѿ��и�Ԫ��,����ʧ��" << endl;
				}
				else
					cout << "����ɹ�!" << endl;
				break;
			}
			case '3':
			{
				int a;
				cout << "����������Ҫɾ������������" << endl;
				cin >> a;
				while (a < -32768 || a>32767)
				{
					cout << "�Ѿ��������ͷ�Χ-32768-32767,����������" << endl;
					cin >> a;
				}
				if (bst.BST_delete(a) == false)
				{
					cout << "��������������ڸ�Ԫ��,ɾ��ʧ��" << endl;
				}
				else
					cout << "ɾ���ɹ�!" << endl;
				break;
			}
			case '4':
			{
				cout << "ǰ�����(�ݹ�)�������:" << endl;
				bst.BST_preorderR();
				cout << "ǰ�����(�ݹ�)�ɹ�!" << endl;
				break;
			}
			case '5':
			{
				cout << "ǰ�����(�ǵݹ�)�������:" << endl;
				bst.BST_preorderI();
				cout << "ǰ�����(�ǵݹ�)�ɹ�!" << endl;
				break;
			}
			case '6':
			{
				cout << "�������(�ݹ�)�������:" << endl;
				bst.BST_inorderR();
				cout << "�������(�ݹ�)�ɹ�!" << endl;
				break;
			}
			case '7':
			{
				cout << "�������(�ǵݹ�)�������:" << endl;
				bst.BST_inorderI();
				cout << "�������(�ǵݹ�)�ɹ�!" << endl;
				break;
			}
			case '8':
			{
				cout << "�������(�ݹ�)�������:" << endl;
				bst.BST_postorderR();
				cout << "�������(�ݹ�)�ɹ�!" << endl;
				break;
			}
			case '9':
			{
				cout << "�������(�ǵݹ�)�������:" << endl;
				bst.BST_postorderI();
				cout << "�������(�ǵݹ�)�ɹ�!" << endl;
				break;
			}
			case'a':
			{
				int a;
				cout << "����������Ҫ���ҵ���������" << endl;
				cin >> a;
				while (a < -32768 || a>32767)
				{
					cout << "�Ѿ��������ͷ�Χ-32768-32767,����������" << endl;
					cin >> a;
				}
				if (bst.BST_search(a) == nullptr)
				{
					cout << "��������������ڸ�Ԫ��" << endl;
				}
				else
					cout << "������������ڸ�Ԫ��!" << endl;
				break;
			}
			case 'b':
			{
				bst.BST_levelOrder();
				cout << "��������ɹ�!" << endl;
				break;
			}

			}
			cout << "ϵͳ����1s�󷵻ز˵�" << endl;
			Sleep(1000);
			system("cls");
			menu();
			cout << "����������Ҫ�Ĳ���" << endl;
			cin >> choice;
			while (choice != '0' && choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5' && choice != '6' && choice != '7' && choice != '8' && choice != '9' && choice != 'a' && choice != 'b')
			{
				cout << "��������������ѡ�����" << endl;
				cin >> choice;
			}
		}
		system("cls");
	}
	else if (d == '2')
	{
		BinarySortTree<char> bst;
		cout << "��������������ɹ�" << endl;
		Sleep(1000);
		system("cls");
		menu();
		cout << "�������������Ϊ�գ�������2Ϊ������������Ԫ��" << endl;
		cin >> choice;
		while (choice != '2')
		{
			cout << "��������" << endl;
			cout << "����������2���в���" << endl;
			cin >> choice;
		}
		while (1)
		{
			switch (choice)
			{
			case '0':
			{
				cout << "�ɹ��˳��ö�����\n" << endl;
				exit(0);
				return 0;
			}
			case'2':
			{
				char a;
				cout << "����������Ҫ������ַ�" << endl;
				cin >> a;

				if (bst.BST_insert(a) == false)
				{
					cout << "����������Ѿ��и�Ԫ��,����ʧ��" << endl;
				}
				else
					cout << "����ɹ�!" << endl;
				break;
			}
			case '3':
			{
				char a;
				cout << "����������Ҫɾ�����ַ�" << endl;
				cin >> a;
				if (bst.BST_delete(a) == false)
				{
					cout << "��������������ڸ�Ԫ��,ɾ��ʧ��" << endl;
				}
				else
					cout << "ɾ���ɹ�!" << endl;
				break;
			}
			case '4':
			{
				cout << "ǰ�����(�ݹ�)�������:" << endl;
				bst.BST_preorderR();
				cout << "ǰ�����(�ݹ�)�ɹ�!" << endl;
				break;
			}
			case '5':
			{
				cout << "ǰ�����(�ǵݹ�)�������:" << endl;
				bst.BST_preorderI();
				cout << "ǰ�����(�ǵݹ�)�ɹ�!" << endl;
				break;
			}
			case '6':
			{
				cout << "�������(�ݹ�)�������:" << endl;
				bst.BST_inorderR();
				cout << "�������(�ݹ�)�ɹ�!" << endl;
				break;
			}
			case '7':
			{
				cout << "�������(�ǵݹ�)�������:" << endl;
				bst.BST_inorderI();
				cout << "�������(�ǵݹ�)�ɹ�!" << endl;
				break;
			}
			case '8':
			{
				cout << "�������(�ݹ�)�������:" << endl;
				bst.BST_postorderR();
				cout << "�������(�ݹ�)�ɹ�!" << endl;
				break;
			}
			case '9':
			{
				cout << "�������(�ǵݹ�)�������:" << endl;
				bst.BST_postorderI();
				cout << "�������(�ǵݹ�)�ɹ�!" << endl;
				break;
			}
			case'a':
			{
				char a;
				cout << "����������Ҫ���ҵ��ַ�" << endl;
				cin >> a;
				if (bst.BST_search(a) == nullptr)
				{
					cout << "��������������ڸ�Ԫ��" << endl;
				}
				else
					cout << "������������ڸ�Ԫ��!" << endl;
				break;
			}
			case 'b':
			{
				cout << "��������������:" << endl;
				bst.BST_levelOrder();
				cout << endl;
				cout << "��������ɹ�!" << endl;
				break;
			}

			}
			cout << "ϵͳ����1s�󷵻ز˵�" << endl;
			Sleep(1000);
			system("cls");
			menu();
			cout << "����������Ҫ�Ĳ���" << endl;
			cin >> choice;
			while (choice != '0' && choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5' && choice != '6' && choice != '7' && choice != '8' && choice != '9' && choice != 'a' && choice != 'b')
			{
				cout << "��������������ѡ�����" << endl;
				cin >> choice;
			}
		}
		system("cls");
	}
		else if (d == '2')
	{
		BinarySortTree<char> bst;
		cout << "��������������ɹ�" << endl;
		Sleep(1000);
		system("cls");
		menu();
		cout << "�������������Ϊ�գ�������2Ϊ������������Ԫ��" << endl;
		cin >> choice;
		while (choice != '2')
		{
			cout << "��������" << endl;
			cout << "����������2���в���" << endl;
			cin >> choice;
		}
		while (1)
		{
			switch (choice)
			{
			case '0':
			{
				cout << "�ɹ��˳��ö�����\n" << endl;
				exit(0);
				return 0;
			}
			case'2':
			{
				char a;
				cout << "����������Ҫ������ַ�" << endl;
				cin >> a;

				if (bst.BST_insert(a) == false)
				{
					cout << "����������Ѿ��и�Ԫ��,����ʧ��" << endl;
				}
				else
					cout << "����ɹ�!" << endl;
				break;
			}
			case '3':
			{
				char a;
				cout << "����������Ҫɾ�����ַ�" << endl;
				cin >> a;
				if (bst.BST_delete(a) == false)
				{
					cout << "��������������ڸ�Ԫ��,ɾ��ʧ��" << endl;
				}
				else
					cout << "ɾ���ɹ�!" << endl;
				break;
			}
			case '4':
			{
				cout << "ǰ�����(�ݹ�)�������:" << endl;
				bst.BST_preorderR();
				cout << "ǰ�����(�ݹ�)�ɹ�!" << endl;
				break;
			}
			case '5':
			{
				cout << "ǰ�����(�ǵݹ�)�������:" << endl;
				bst.BST_preorderI();
				cout << "ǰ�����(�ǵݹ�)�ɹ�!" << endl;
				break;
			}
			case '6':
			{
				cout << "�������(�ݹ�)�������:" << endl;
				bst.BST_inorderR();
				cout << "�������(�ݹ�)�ɹ�!" << endl;
				break;
			}
			case '7':
			{
				cout << "�������(�ǵݹ�)�������:" << endl;
				bst.BST_inorderI();
				cout << "�������(�ǵݹ�)�ɹ�!" << endl;
				break;
			}
			case '8':
			{
				cout << "�������(�ݹ�)�������:" << endl;
				bst.BST_postorderR();
				cout << "�������(�ݹ�)�ɹ�!" << endl;
				break;
			}
			case '9':
			{
				cout << "�������(�ǵݹ�)�������:" << endl;
				bst.BST_postorderI();
				cout << "�������(�ǵݹ�)�ɹ�!" << endl;
				break;
			}
			case'a':
			{
				char a;
				cout << "����������Ҫ���ҵ��ַ�" << endl;
				cin >> a;
				if (bst.BST_search(a) == nullptr)
				{
					cout << "��������������ڸ�Ԫ��" << endl;
				}
				else
					cout << "������������ڸ�Ԫ��!" << endl;
				break;
			}
			case 'b':
			{
				cout << "��������������:" << endl;
				bst.BST_levelOrder();
				cout << endl;
				cout << "��������ɹ�!" << endl;
				break;
			}

			}
			cout << "ϵͳ����1s�󷵻ز˵�" << endl;
			Sleep(1000);
			system("cls");
			menu();
			cout << "����������Ҫ�Ĳ���" << endl;
			cin >> choice;
			while (choice != '0' && choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5' && choice != '6' && choice != '7' && choice != '8' && choice != '9' && choice != 'a' && choice != 'b')
			{
				cout << "��������������ѡ�����" << endl;
				cin >> choice;
			}
		}
		system("cls");
	}
	else if (d == '3')
	{
	BinarySortTree<float> bst;
	cout << "��������������ɹ�" << endl;
	Sleep(1000);
	system("cls");
	menu();
	cout << "�������������Ϊ�գ�������2Ϊ������������Ԫ��" << endl;
	cin >> choice;
	while (choice != '2')
	{
		cout << "��������" << endl;
		cout << "����������2���в���" << endl;
		cin >> choice;
	}
	while (1)
	{
		switch (choice)
		{
		case '0':
		{
			cout << "�ɹ��˳��ö�����\n" << endl;
			exit(0);
			return 0;
		}
		case'2':
		{
			float a;
			cout << "����������Ҫ�����С��" << endl;
			cin >> a;

			if (bst.BST_insert(a) == false)
			{
				cout << "����������Ѿ��и�Ԫ��,����ʧ��" << endl;
			}
			else
				cout << "����ɹ�!" << endl;
			break;
		}
		case '3':
		{
			float a;
			cout << "����������Ҫɾ����С��" << endl;
			cin >> a;
			if (bst.BST_delete(a) == false)
			{
				cout << "��������������ڸ�Ԫ��,ɾ��ʧ��" << endl;
			}
			else
				cout << "ɾ���ɹ�!" << endl;
			break;
		}
		case '4':
		{
			cout << "ǰ�����(�ݹ�)�������:" << endl;
			bst.BST_preorderR();
			cout << "ǰ�����(�ݹ�)�ɹ�!" << endl;
			break;
		}
		case '5':
		{
			cout << "ǰ�����(�ǵݹ�)�������:" << endl;
			bst.BST_preorderI();
			cout << "ǰ�����(�ǵݹ�)�ɹ�!" << endl;
			break;
		}
		case '6':
		{
			cout << "�������(�ݹ�)�������:" << endl;
			bst.BST_inorderR();
			cout << "�������(�ݹ�)�ɹ�!" << endl;
			break;
		}
		case '7':
		{
			cout << "�������(�ǵݹ�)�������:" << endl;
			bst.BST_inorderI();
			cout << "�������(�ǵݹ�)�ɹ�!" << endl;
			break;
		}
		case '8':
		{
			cout << "�������(�ݹ�)�������:" << endl;
			bst.BST_postorderR();
			cout << "�������(�ݹ�)�ɹ�!" << endl;
			break;
		}
		case '9':
		{
			cout << "�������(�ǵݹ�)�������:" << endl;
			bst.BST_postorderI();
			cout << "�������(�ǵݹ�)�ɹ�!" << endl;
			break;
		}
		case'a':
		{
			float a;
			cout << "����������Ҫ���ҵ�С��" << endl;
			cin >> a;
			if (bst.BST_search(a) == nullptr)
			{
				cout << "��������������ڸ�Ԫ��" << endl;
			}
			else
				cout << "������������ڸ�Ԫ��!" << endl;
			break;
		}
		case 'b':
		{
			cout << "��������������:" << endl;
			bst.BST_levelOrder();
			cout << endl;
			cout << "��������ɹ�!" << endl;
			break;
		}

		}
		cout << "ϵͳ����1s�󷵻ز˵�" << endl;
		Sleep(1000);
		system("cls");
		menu();
		cout << "����������Ҫ�Ĳ���" << endl;
		cin >> choice;
		while (choice != '0' && choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5' && choice != '6' && choice != '7' && choice != '8' && choice != '9' && choice != 'a' && choice != 'b')
		{
			cout << "��������������ѡ�����" << endl;
			cin >> choice;
		}
	}
	system("cls");
	}
	
	return 0;
}*/
int main()
{
	BinarySortTree<int>bst;
	bst.BST_insert(20);
	bst.BST_insert(10);
	bst.BST_insert(30);
	if (bst.BST_search(20) != nullptr)
	{
		cout << "���ڸ�Ԫ��" << endl;
	}
	else
		cout << "�����ڸ�Ԫ��" << endl;
	cout << "�������" << endl;
	bst.BST_levelOrder();
	cout << endl;
	cout << "ǰ�����(�ݹ�)" << endl;
	bst.BST_preorderR();
	cout << "ǰ�����(�ǵݹ�)" << endl;
	bst.BST_preorderI();
	cout << "�������(�ݹ�)" << endl;
	bst.BST_inorderR();
	cout << "�������(�ǵݹ�)" << endl;
	bst.BST_inorderI();
	cout << "�������(�ݹ�)" << endl;
	bst.BST_postorderR();
	cout << "�������(�ǵݹ�)" << endl;
	bst.BST_postorderI();

	return 0;
}