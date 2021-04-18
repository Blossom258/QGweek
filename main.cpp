#include<iostream>  
#include<Windows.h>  
#include"qgsort.h"
#include<ctime>
#include<cstdlib>
#include<stdio.h>
using namespace std;
int main()
{
    char choice;
    int i = 0;
    menu();
    cout << "请输入你需要查看的选项\n" << endl;
    cin >> choice;
    while (choice != '0' && choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5' && choice != '6'&&choice!='7')
    {
        cout << "输入错误,请在0-6中重新选择" << endl;
        cin >> choice;
        i++;
        if (i % 3 == 0)
        {
            system("cls");
        }
    }
  // while (1)
   // {
        switch (choice)
        {
        case'0':
        {
            cout << "已经退出该系统" << endl;
            exit(0);
            return 0;
            break;
        }
        case'1':
        {
            long int n;
            char i;
            cout << "1.10000\t2.50000\t3.200000" << endl;
            cout << "请选择你要的数据个数" << endl;
            cin >> i;
            while (i != '1' && i != '2' && i != '3')
            {
                cout << "输入有误,请重现在1到3之间选择" << endl;
                cin >> i;
            }
            if (i == '1')
                n = 10000;
            else if (i == '2')
                n = 50000;
            else
                n = 200000;
            cout << "本次排序规模为:" << n << endl;
            clock_t start_time = clock();
            insertSort(rand(n), n);
            cout << "插入排序用时:" << double(clock() - start_time) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
            start_time = clock();
            QuickSort(rand(n), 0, n - 1);
            cout << "快排非递归排序用时:" << double(clock() - start_time) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
            start_time = clock();
            QuickSort_Recursion(rand(n), 0, n - 1);
            cout << "快排递归排序用时:" << double(clock() - start_time) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
            start_time = clock();
            MergeSort(rand(n), n);
            cout << "归并排序用时:" << double(clock() - start_time) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
            start_time = clock();
            CountSort(rand(n), n);
            cout << "计数排序用时:" << double(clock() - start_time) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
            start_time = clock();
            RadixCountSort(rand(n), n);
            cout << "基数排序用时:" << double(clock() - start_time) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
            break;
        }
        case'2':
        {
            long int n;
            int p = 100;
            int j = 0;
            char i;
            cout << "1.10000\t2.50000\t3.200000" << endl;
            cout << "请选择你要的数据个数" << endl;
            cin >> i;
            while (i != '1' && i != '2' && i != '3')
            {
                cout << "输入有误,请重现在1到3之间选择" << endl;
                cin >> i;
            }
            if (i == '1')
                n = 10000;
            else if (i == '2')
                n = 50000;
            else
                n = 200000;
            cout << "本次排序次数为:" << n / 100 << "次" << endl;
            int b = n / 100;
            clock_t start_time = clock();
            for (j = 1; j <= b; j++)
            {
                insertSort(rand(n), p);
            }
            cout << "插入排序用时:" << double(clock() - start_time) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
            start_time = clock();
            for (j = 1; j <= b; j++)
            {
                QuickSort_Recursion(rand(n), 0, p - 1);

            }
            cout << "快排递归排序用时:" << double(clock() - start_time) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
            start_time = clock();
            for (j = 1; j <= b; j++)
            {
                QuickSort(rand(n), 0, p - 1);

            }
            cout << "快排非递归排序用时:" << double(clock() - start_time) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
            start_time = clock();
            for (j = 1; j <= b; j++)
            {
                MergeSort(rand(n), p);

            }
            cout << "归并排序用时:" << double(clock() - start_time) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
            start_time = clock();
            for (j = 1; j <= b; j++)
            {
                CountSort(rand(n), p);

            }
            cout << "计数排序用时:" << double(clock() - start_time) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
            start_time = clock();
            for (j = 1; j <= b; j++)
            {
                RadixCountSort(rand(n), p);
            }
            cout << "基数排序用时:" << double(clock() - start_time) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
            break;
        }
        case'3':
        {
            int j = 1;
            int* a = nullptr;
            int n = 0;
            cout << "请输入0,1,2三个数字的总和数目" << endl;
            cin >> n;
            while (n < 0 || n > 32767)
            {
                cout << "数字超出int范围,请在0-32767中选择一个数字输入" << endl;
                cin >> n;
            }
            a = colorrand(n);
            cout << "正在打开文件" << endl;
            cout << "打开成功" << endl;
            cout << "原始数据写入成功,储存于data.txt中" << endl;
            cout << "有序数据写入成功,储存于result.txt中" << endl;
            cout << "0,1,2三个数字已经通过颜色排序的方式排好了！" << endl;
            FILE* stream1;
            freopen_s(&stream1, "data.txt", "w", stdout);
            for (int i = 0; i < n; ++i) {
                cout << a[i] << "\t"; //输出数据到data.txt
                if (j % 15 == 0)
                {
                    cout << endl;
                }
                j++;
            }
            j = 1;
            freopen_s(&stream1, "result.txt", "w", stdout);
            ColorSort(a, n);
            for (int i = 0; i < n; ++i) {
                cout << a[i] << "\t"; //输出数据到result.txt
                if (j % 15 == 0)
                {
                    cout << endl;
                }
                j++;
            }

            break;
        }
        case '4':
        {
            int k;
            int length;
            int j = 1;
            int* a = nullptr;
            cout << "请输入k的大小:";
            cin >> k;
            cout << "请输入数组长度:";
            cin >> length;
            while (length < k)
            {
                cout << "数组长度不能小于k的值,请重新输入数组长度的值" << endl;
                cin >> length;
            }
            a = rand(length);
            cout << "正在打开文件" << endl;
            cout << "打开成功" << endl;
            cout << "原始数据写入成功,储存于data.txt中" << endl;
            cout << "有序数据写入成功,储存于result.txt中" << endl;
            cout << "第" << k << "大的数字为:" << findkmax(k, rand(length), 0, length - 1) << endl;
            FILE* stream1;
            freopen_s(&stream1, "data.txt", "w", stdout);
            for (int i = 0; i < length; ++i) {
                cout << a[i] << "\t"; //输出数据到data.txt
                if (j % 5 == 0)
                {
                    cout << endl;
                }
                j++;
            }
            fclose(stream1);
            j = 1;
            freopen_s(&stream1, "result.txt", "w", stdout);
              MergeSort(a, length);
            for (int i = 0; i < length; ++i) {
                cout << a[i] << "\t"; //输出数据到result.txt
                if (j % 5 == 0)
                {
                    cout << endl;
                }
                j++;
            }
            cout << "第" << k << "大的数字为:" << findkmax(k, rand(length), 0, length - 1) << endl;         
            fclose(stream1);
            break;
        }
        case '5':
        {
            int k;
            int length;
            int j = 1;
            int* a = nullptr;
            cout << "请输入k的大小:";
            cin >> k;
            cout << "请输入数组长度:";
            cin >> length;
            while (length < k)
            {
                cout << "数组长度不能小于k的值,请重新输入数组长度的值" << endl;
                cin >> length;
            }
            a = rand(length);
            cout << "正在打开文件" << endl;
            cout << "打开成功" << endl;
            cout << "原始数据写入成功,储存于data.txt中" << endl;
            cout << "有序数据写入成功,储存于result.txt中" << endl;
            cout << "第" << k << "小的数字为:" << findkmin(rand(length), 0, length - 1, k) << endl;
            FILE* stream1;
            freopen_s(&stream1, "data.txt", "w", stdout);
            for (int i = 0; i < length; ++i) {
                cout << a[i] << "\t"; //输出数据到data.txt
                if (j % 15 == 0)
                {
                    cout << endl;
                }
                j++;
            }
             
            j = 1;
            freopen_s(&stream1, "result.txt", "w", stdout);
            MergeSort(a, length);
            for (int i = 0; i < length; ++i) {
                cout << a[i] << "\t"; //输出数据到result.txt
                if (j % 15 == 0)
                {
                    cout << endl;
                }
                j++;
            }
            cout << "第" << k << "小的数字为:" << findkmin(rand(length), 0, length - 1, k) << endl;
            break;
          
        }
        case '6':
        {
            int* a = nullptr;
            int n = 0;
            char d = 0;
            char s[20];
            char s1[20];
            int j = 1;
            cout << "请输入你想要的数组长度" << endl;
            cin >> n;
            while (n < 0 || n > 32767)
            {
                cout << "数字超出int范围,请在0-32767中选择一个数字输入" << endl;
                cin >> n;
            }
            cout << "长度为" << n << "的随机数组已经生成完毕！" << endl;
            a = rand(n);
            cout << "1.快速排序(递归)" << endl;
            cout << "2.快速排序(非递归)" << endl;
            cout << "3.归并排序" << endl;
            cout << "4.基数排序" << endl;
            cout << "5.计数排序" << endl;
            cout << "6.插入排序" << endl;
            cout << "请输入你想要将原始数据储存于哪个txt文档" << endl;
            cin >> s1;
            cout << "正在打开文件" << endl;
            FILE* stream1;
            cout << "打开文件成功" << endl;
            cout << "已经将随机数组写入" << s1 << "中" << endl;
            cout << "请输入你指定的排序方式" << endl;
            cin >> d;
            while (d != '1' && d != '2' && d != '3' && d != '4' && d != '5' && d != '6')
            {
                cout << "输入有误，请重新在1到6选择一种排序方式" << endl;
                cin >> d;
            }
            cout << "你指定的排序方式,已经排序成功" << endl;
            cout << "请输入你想要将结果数据存储于哪个txt文档中" << endl;
            cin >> s;
            cout << "正在打开文件" << endl;
            cout << "打开文件成功" << endl;
            cout << "已经将结果数据写入" << s << "中" << endl;
            freopen_s(&stream1, s1, "w", stdout);
            for (int i = 0; i < n; ++i) {
                cout << a[i] << "\t";
                if (j % 15 == 0)
                {
                    cout << endl;
                }
                j++;
            };
            j = 1;
            freopen_s(&stream1, s, "w", stdout);
            if (d == '1')
                QuickSort_Recursion(a, 0, n - 1);
            else if (d == '2')
                QuickSort(a, 0, n - 1);
            else if (d == '3')
                MergeSort(a, n);
            else if (d == '4')
                RadixCountSort(a, n);
            else if (d == '5')
                CountSort(a, n);
            else if (d == '6')
                insertSort(a, n);
            for (int i = 0; i < n; ++i) {
                cout << a[i] << "\t";
                if (j % 15 == 0)
                {
                    cout << endl;
                }
                j++;
            }

            break;
        }
        case '7':
        {
            int* a = nullptr;
            int* c = nullptr;
            int b[1000];
            char s[20];
            char s1[20];
            char d = 0;
            int j = 1;
            int n = 0;
            FILE* stream1;
            cout << "请指定文档元素的数目" << endl;
            cin >> n;
            while (n < 0 || n > 32767)
            {
                cout << "数字超出int范围,请在0-32767中选择一个数字输入" << endl;
                cin >> n;
            }
            cout << "请输入你想要读取的文档" << endl;
            cin >> s1;
            cout << "读取完毕" << endl;
            cout << "1.快速排序(递归)" << endl;
            cout << "2.快速排序(非递归)" << endl;
            cout << "3.归并排序" << endl;
            cout << "4.基数排序" << endl;
            cout << "5.计数排序" << endl;
            cout << "6.插入排序" << endl;
            cout << "请输入你指定的排序方式" << endl;
            cin >> d;
            while (d != '1' && d != '2' && d != '3' && d != '4' && d != '5' && d != '6')
            {
                cout << "输入有误，请重新在1到6选择一种排序方式" << endl;
                cin >> d;
            }
            cout << "你指定的排序方式,已经排序成功" << endl;
            cout << "请输入你想要将结果数据存储于哪个txt文档中" << endl;
            cin >> s;
            cout << "正在打开文件" << endl;
            cout << "打开文件成功" << endl;
            cout << "已经将结果数据写入" << s << "中" << endl;
            a = rand(n);
            freopen_s(&stream1, s1, "w", stdout);
            for (int i = 0; i < n; ++i) {
                cout << a[i] << "\t";
                if (j % 15 == 0)
                {
                    cout << endl;
                }
                j++;
            };
            for (int i = 0; i < n; i++)
            {
                b[i] = freopen_s(&stream1, s1, "r", stdin);
            }
            c = a;
            freopen_s(&stream1, s, "w", stdout);
            if (d == '1')
                QuickSort_Recursion(c, 0, n - 1);
            else if (d == '2')
                QuickSort(c, 0, n - 1);
            else if (d == '3')
                MergeSort(c, n);
            else if (d == '4')
                RadixCountSort(c, n);
            else if (d == '5')
                CountSort(c, n);
            else if (d == '6')
                insertSort(c, n);
            j = 1;
            for (int i = 0; i < n; ++i)
            {
                cout << c[i] << "\t";
                if (j % 15 == 0)
                {
                    cout << endl;
                }
                j++;
            }
            break;
        }
        }
    /*   cout << "系统将于2s后回到主菜单" << endl;
        Sleep(2000);
        system("cls");
        menu();
        cout << "请输入你想要查看的操作" << endl;
        cin >> choice;
        while (choice != '0' && choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5' && choice != '6' && choice != '7')
        {
            cout << "输入错误,请在0-6中重新选择" << endl;
            cin >> choice;
            i++;
            if (i % 3 == 0)
            {
                system("cls");
            }
        }*/
  
    

         
    return 0;
}

  

