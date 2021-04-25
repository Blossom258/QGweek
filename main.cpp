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
	cout << "因为您是第一次使用,请选择1进行二叉排序树创建" << endl;
	cin >> choice;
	while (choice != '1')
	{

		cout << "输入错误,请输入1进行二叉排序树创建" << endl;
		cin >> choice;
		b++;
		if (b % 3 == 0)
			system("cls");
	}
	system("cls");
	cout << "您想要创建什么类型的链表" << endl;
	cout << "1.int类型      2.char类型     3.float类型 " << endl;
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
		BinarySortTree<int> bst;
		cout << "排序二叉树创建成功" << endl;
		Sleep(1000);
		system("cls");
		menu();
		cout << "由于排序二叉树为空，请输入2为排序二叉树添加元素" << endl;
		cin >> choice;
		while (choice != '2')
		{
			cout << "输入有误" << endl;
			cout << "请重新输入2进行操作" << endl;
			cin >> choice;
		}
		while (1)
		{
			switch (choice)
			{
			case '0':
			{
				cout << "成功退出该二叉树\n" << endl;
				exit(0);
				return 0;
			}
			case'2':
			{
				int a;
				cout << "请输入你想要插入的整型数字" << endl;
				cin >> a;
				while (a < -32768 || a>32767)
				{
					cout << "已经超出整型范围-32768-32767,请重新输入" << endl;
					cin >> a;
				}
				if (bst.BST_insert(a) == false)
				{
					cout << "排序二叉树已经有该元素,插入失败" << endl;
				}
				else
					cout << "插入成功!" << endl;
				break;
			}
			case '3':
			{
				int a;
				cout << "请输入你想要删除的整型数字" << endl;
				cin >> a;
				while (a < -32768 || a>32767)
				{
					cout << "已经超出整型范围-32768-32767,请重新输入" << endl;
					cin >> a;
				}
				if (bst.BST_delete(a) == false)
				{
					cout << "排序二叉树不存在该元素,删除失败" << endl;
				}
				else
					cout << "删除成功!" << endl;
				break;
			}
			case '4':
			{
				cout << "前序遍历(递归)结果如下:" << endl;
				bst.BST_preorderR();
				cout << "前序遍历(递归)成功!" << endl;
				break;
			}
			case '5':
			{
				cout << "前序遍历(非递归)结果如下:" << endl;
				bst.BST_preorderI();
				cout << "前序遍历(非递归)成功!" << endl;
				break;
			}
			case '6':
			{
				cout << "中序遍历(递归)结果如下:" << endl;
				bst.BST_inorderR();
				cout << "中序遍历(递归)成功!" << endl;
				break;
			}
			case '7':
			{
				cout << "中序遍历(非递归)结果如下:" << endl;
				bst.BST_inorderI();
				cout << "中序遍历(非递归)成功!" << endl;
				break;
			}
			case '8':
			{
				cout << "后序遍历(递归)结果如下:" << endl;
				bst.BST_postorderR();
				cout << "后序遍历(递归)成功!" << endl;
				break;
			}
			case '9':
			{
				cout << "后序遍历(非递归)结果如下:" << endl;
				bst.BST_postorderI();
				cout << "后序遍历(非递归)成功!" << endl;
				break;
			}
			case'a':
			{
				int a;
				cout << "请输入你想要查找的整型数字" << endl;
				cin >> a;
				while (a < -32768 || a>32767)
				{
					cout << "已经超出整型范围-32768-32767,请重新输入" << endl;
					cin >> a;
				}
				if (bst.BST_search(a) == nullptr)
				{
					cout << "排序二叉树不存在该元素" << endl;
				}
				else
					cout << "排序二叉树存在该元素!" << endl;
				break;
			}
			case 'b':
			{
				bst.BST_levelOrder();
				cout << "层序遍历成功!" << endl;
				break;
			}

			}
			cout << "系统将于1s后返回菜单" << endl;
			Sleep(1000);
			system("cls");
			menu();
			cout << "请输入你想要的操作" << endl;
			cin >> choice;
			while (choice != '0' && choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5' && choice != '6' && choice != '7' && choice != '8' && choice != '9' && choice != 'a' && choice != 'b')
			{
				cout << "输入有误，请重新选择操作" << endl;
				cin >> choice;
			}
		}
		system("cls");
	}
	else if (d == '2')
	{
		BinarySortTree<char> bst;
		cout << "排序二叉树创建成功" << endl;
		Sleep(1000);
		system("cls");
		menu();
		cout << "由于排序二叉树为空，请输入2为排序二叉树添加元素" << endl;
		cin >> choice;
		while (choice != '2')
		{
			cout << "输入有误" << endl;
			cout << "请重新输入2进行操作" << endl;
			cin >> choice;
		}
		while (1)
		{
			switch (choice)
			{
			case '0':
			{
				cout << "成功退出该二叉树\n" << endl;
				exit(0);
				return 0;
			}
			case'2':
			{
				char a;
				cout << "请输入你想要插入的字符" << endl;
				cin >> a;

				if (bst.BST_insert(a) == false)
				{
					cout << "排序二叉树已经有该元素,插入失败" << endl;
				}
				else
					cout << "插入成功!" << endl;
				break;
			}
			case '3':
			{
				char a;
				cout << "请输入你想要删除的字符" << endl;
				cin >> a;
				if (bst.BST_delete(a) == false)
				{
					cout << "排序二叉树不存在该元素,删除失败" << endl;
				}
				else
					cout << "删除成功!" << endl;
				break;
			}
			case '4':
			{
				cout << "前序遍历(递归)结果如下:" << endl;
				bst.BST_preorderR();
				cout << "前序遍历(递归)成功!" << endl;
				break;
			}
			case '5':
			{
				cout << "前序遍历(非递归)结果如下:" << endl;
				bst.BST_preorderI();
				cout << "前序遍历(非递归)成功!" << endl;
				break;
			}
			case '6':
			{
				cout << "中序遍历(递归)结果如下:" << endl;
				bst.BST_inorderR();
				cout << "中序遍历(递归)成功!" << endl;
				break;
			}
			case '7':
			{
				cout << "中序遍历(非递归)结果如下:" << endl;
				bst.BST_inorderI();
				cout << "中序遍历(非递归)成功!" << endl;
				break;
			}
			case '8':
			{
				cout << "后序遍历(递归)结果如下:" << endl;
				bst.BST_postorderR();
				cout << "后序遍历(递归)成功!" << endl;
				break;
			}
			case '9':
			{
				cout << "后序遍历(非递归)结果如下:" << endl;
				bst.BST_postorderI();
				cout << "后序遍历(非递归)成功!" << endl;
				break;
			}
			case'a':
			{
				char a;
				cout << "请输入你想要查找的字符" << endl;
				cin >> a;
				if (bst.BST_search(a) == nullptr)
				{
					cout << "排序二叉树不存在该元素" << endl;
				}
				else
					cout << "排序二叉树存在该元素!" << endl;
				break;
			}
			case 'b':
			{
				cout << "层序遍历结果如下:" << endl;
				bst.BST_levelOrder();
				cout << endl;
				cout << "层序遍历成功!" << endl;
				break;
			}

			}
			cout << "系统将于1s后返回菜单" << endl;
			Sleep(1000);
			system("cls");
			menu();
			cout << "请输入你想要的操作" << endl;
			cin >> choice;
			while (choice != '0' && choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5' && choice != '6' && choice != '7' && choice != '8' && choice != '9' && choice != 'a' && choice != 'b')
			{
				cout << "输入有误，请重新选择操作" << endl;
				cin >> choice;
			}
		}
		system("cls");
	}
		else if (d == '2')
	{
		BinarySortTree<char> bst;
		cout << "排序二叉树创建成功" << endl;
		Sleep(1000);
		system("cls");
		menu();
		cout << "由于排序二叉树为空，请输入2为排序二叉树添加元素" << endl;
		cin >> choice;
		while (choice != '2')
		{
			cout << "输入有误" << endl;
			cout << "请重新输入2进行操作" << endl;
			cin >> choice;
		}
		while (1)
		{
			switch (choice)
			{
			case '0':
			{
				cout << "成功退出该二叉树\n" << endl;
				exit(0);
				return 0;
			}
			case'2':
			{
				char a;
				cout << "请输入你想要插入的字符" << endl;
				cin >> a;

				if (bst.BST_insert(a) == false)
				{
					cout << "排序二叉树已经有该元素,插入失败" << endl;
				}
				else
					cout << "插入成功!" << endl;
				break;
			}
			case '3':
			{
				char a;
				cout << "请输入你想要删除的字符" << endl;
				cin >> a;
				if (bst.BST_delete(a) == false)
				{
					cout << "排序二叉树不存在该元素,删除失败" << endl;
				}
				else
					cout << "删除成功!" << endl;
				break;
			}
			case '4':
			{
				cout << "前序遍历(递归)结果如下:" << endl;
				bst.BST_preorderR();
				cout << "前序遍历(递归)成功!" << endl;
				break;
			}
			case '5':
			{
				cout << "前序遍历(非递归)结果如下:" << endl;
				bst.BST_preorderI();
				cout << "前序遍历(非递归)成功!" << endl;
				break;
			}
			case '6':
			{
				cout << "中序遍历(递归)结果如下:" << endl;
				bst.BST_inorderR();
				cout << "中序遍历(递归)成功!" << endl;
				break;
			}
			case '7':
			{
				cout << "中序遍历(非递归)结果如下:" << endl;
				bst.BST_inorderI();
				cout << "中序遍历(非递归)成功!" << endl;
				break;
			}
			case '8':
			{
				cout << "后序遍历(递归)结果如下:" << endl;
				bst.BST_postorderR();
				cout << "后序遍历(递归)成功!" << endl;
				break;
			}
			case '9':
			{
				cout << "后序遍历(非递归)结果如下:" << endl;
				bst.BST_postorderI();
				cout << "后序遍历(非递归)成功!" << endl;
				break;
			}
			case'a':
			{
				char a;
				cout << "请输入你想要查找的字符" << endl;
				cin >> a;
				if (bst.BST_search(a) == nullptr)
				{
					cout << "排序二叉树不存在该元素" << endl;
				}
				else
					cout << "排序二叉树存在该元素!" << endl;
				break;
			}
			case 'b':
			{
				cout << "层序遍历结果如下:" << endl;
				bst.BST_levelOrder();
				cout << endl;
				cout << "层序遍历成功!" << endl;
				break;
			}

			}
			cout << "系统将于1s后返回菜单" << endl;
			Sleep(1000);
			system("cls");
			menu();
			cout << "请输入你想要的操作" << endl;
			cin >> choice;
			while (choice != '0' && choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5' && choice != '6' && choice != '7' && choice != '8' && choice != '9' && choice != 'a' && choice != 'b')
			{
				cout << "输入有误，请重新选择操作" << endl;
				cin >> choice;
			}
		}
		system("cls");
	}
	else if (d == '3')
	{
	BinarySortTree<float> bst;
	cout << "排序二叉树创建成功" << endl;
	Sleep(1000);
	system("cls");
	menu();
	cout << "由于排序二叉树为空，请输入2为排序二叉树添加元素" << endl;
	cin >> choice;
	while (choice != '2')
	{
		cout << "输入有误" << endl;
		cout << "请重新输入2进行操作" << endl;
		cin >> choice;
	}
	while (1)
	{
		switch (choice)
		{
		case '0':
		{
			cout << "成功退出该二叉树\n" << endl;
			exit(0);
			return 0;
		}
		case'2':
		{
			float a;
			cout << "请输入你想要插入的小数" << endl;
			cin >> a;

			if (bst.BST_insert(a) == false)
			{
				cout << "排序二叉树已经有该元素,插入失败" << endl;
			}
			else
				cout << "插入成功!" << endl;
			break;
		}
		case '3':
		{
			float a;
			cout << "请输入你想要删除的小数" << endl;
			cin >> a;
			if (bst.BST_delete(a) == false)
			{
				cout << "排序二叉树不存在该元素,删除失败" << endl;
			}
			else
				cout << "删除成功!" << endl;
			break;
		}
		case '4':
		{
			cout << "前序遍历(递归)结果如下:" << endl;
			bst.BST_preorderR();
			cout << "前序遍历(递归)成功!" << endl;
			break;
		}
		case '5':
		{
			cout << "前序遍历(非递归)结果如下:" << endl;
			bst.BST_preorderI();
			cout << "前序遍历(非递归)成功!" << endl;
			break;
		}
		case '6':
		{
			cout << "中序遍历(递归)结果如下:" << endl;
			bst.BST_inorderR();
			cout << "中序遍历(递归)成功!" << endl;
			break;
		}
		case '7':
		{
			cout << "中序遍历(非递归)结果如下:" << endl;
			bst.BST_inorderI();
			cout << "中序遍历(非递归)成功!" << endl;
			break;
		}
		case '8':
		{
			cout << "后序遍历(递归)结果如下:" << endl;
			bst.BST_postorderR();
			cout << "后序遍历(递归)成功!" << endl;
			break;
		}
		case '9':
		{
			cout << "后序遍历(非递归)结果如下:" << endl;
			bst.BST_postorderI();
			cout << "后序遍历(非递归)成功!" << endl;
			break;
		}
		case'a':
		{
			float a;
			cout << "请输入你想要查找的小数" << endl;
			cin >> a;
			if (bst.BST_search(a) == nullptr)
			{
				cout << "排序二叉树不存在该元素" << endl;
			}
			else
				cout << "排序二叉树存在该元素!" << endl;
			break;
		}
		case 'b':
		{
			cout << "层序遍历结果如下:" << endl;
			bst.BST_levelOrder();
			cout << endl;
			cout << "层序遍历成功!" << endl;
			break;
		}

		}
		cout << "系统将于1s后返回菜单" << endl;
		Sleep(1000);
		system("cls");
		menu();
		cout << "请输入你想要的操作" << endl;
		cin >> choice;
		while (choice != '0' && choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5' && choice != '6' && choice != '7' && choice != '8' && choice != '9' && choice != 'a' && choice != 'b')
		{
			cout << "输入有误，请重新选择操作" << endl;
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
		cout << "存在该元素" << endl;
	}
	else
		cout << "不存在该元素" << endl;
	cout << "层序遍历" << endl;
	bst.BST_levelOrder();
	cout << endl;
	cout << "前序遍历(递归)" << endl;
	bst.BST_preorderR();
	cout << "前序遍历(非递归)" << endl;
	bst.BST_preorderI();
	cout << "中序遍历(递归)" << endl;
	bst.BST_inorderR();
	cout << "中序遍历(非递归)" << endl;
	bst.BST_inorderI();
	cout << "后序遍历(递归)" << endl;
	bst.BST_postorderR();
	cout << "后序遍历(非递归)" << endl;
	bst.BST_postorderI();

	return 0;
}