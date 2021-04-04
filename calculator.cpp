#include<iostream>
#include"Stack.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;
int symbol(char c)             //赋予优先级
{
	switch (c)
	{
	case '#': return 0;
	case '+': return 2;
	case '-': return 2;
	case '*': return 3;
	case '/': return 3;
	case '(': return 4;
	case ')': return 1;
	default: break;
	}
	return 0;
}

int jisuan(int& a, int& b, char& c)
{
	switch (c)
	{
	case '+': return b + a;
	case '-': return b - a;
	case '*': return b * a;
	case '/': return b / a;
	default: break;
	}
	return 0;
}
void main()
{
	
	LinkStack<int>s1;
	LinkStack<char>s2;
	string a;
	cout << "请输入" << endl;
	cin >> a;
	a = a + '#';
	s2.push('#');
	for (int i = 0; a[i] != 0; i++)
	{
		if (a[i] <= 47)                  //用阿斯克码判断扫描到的是数字还是运算符
		{
			if (a[i] == '#' && s2.getTop() == '#') break; //两个#碰到一起运算结束
			if (s2.getTop() == '(')   //括号特殊讨论
			{
				if (a[i] == ')')
				{
					s2.pop();
					continue;
				}
				s2.push(a[i]);
				continue;
			}

			else if (symbol(s2.getTop()) >= symbol(a[i])) //判断运算符优先级
			{
				char temp1 = s2.getTop();
				s2.pop();
				int temp2 = s1.getTop();
				s1.pop();
				int temp3 = s1.getTop();
				s1.pop();
				s1.push(jisuan(temp2, temp3, temp1));
				i--;
				continue;
			}
			else
			{
				s2.push(a[i]);
				continue;
			}
		}
		else                     //对数字的运算
		{
			int sum = static_cast<int>(a[i]) - 48;
			for (; a[i + 1] > 47; i++)     //实现多位数的运算
				sum = sum * 10 + static_cast<int>(a[i + 1]) - 48;
			s1.push(sum);
			continue;
		}
	}
	int result = s1.getTop();
	cout << "计算结果：" << endl;
	cout << result << endl;
}