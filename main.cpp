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
    cout << "����������Ҫ�鿴��ѡ��\n" << endl;
    cin >> choice;
    while (choice != '0' && choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5' && choice != '6'&&choice!='7')
    {
        cout << "�������,����0-6������ѡ��" << endl;
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
            cout << "�Ѿ��˳���ϵͳ" << endl;
            exit(0);
            return 0;
            break;
        }
        case'1':
        {
            long int n;
            char i;
            cout << "1.10000\t2.50000\t3.200000" << endl;
            cout << "��ѡ����Ҫ�����ݸ���" << endl;
            cin >> i;
            while (i != '1' && i != '2' && i != '3')
            {
                cout << "��������,��������1��3֮��ѡ��" << endl;
                cin >> i;
            }
            if (i == '1')
                n = 10000;
            else if (i == '2')
                n = 50000;
            else
                n = 200000;
            cout << "���������ģΪ:" << n << endl;
            clock_t start_time = clock();
            insertSort(rand(n), n);
            cout << "����������ʱ:" << double(clock() - start_time) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
            start_time = clock();
            QuickSort(rand(n), 0, n - 1);
            cout << "���ŷǵݹ�������ʱ:" << double(clock() - start_time) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
            start_time = clock();
            QuickSort_Recursion(rand(n), 0, n - 1);
            cout << "���ŵݹ�������ʱ:" << double(clock() - start_time) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
            start_time = clock();
            MergeSort(rand(n), n);
            cout << "�鲢������ʱ:" << double(clock() - start_time) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
            start_time = clock();
            CountSort(rand(n), n);
            cout << "����������ʱ:" << double(clock() - start_time) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
            start_time = clock();
            RadixCountSort(rand(n), n);
            cout << "����������ʱ:" << double(clock() - start_time) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
            break;
        }
        case'2':
        {
            long int n;
            int p = 100;
            int j = 0;
            char i;
            cout << "1.10000\t2.50000\t3.200000" << endl;
            cout << "��ѡ����Ҫ�����ݸ���" << endl;
            cin >> i;
            while (i != '1' && i != '2' && i != '3')
            {
                cout << "��������,��������1��3֮��ѡ��" << endl;
                cin >> i;
            }
            if (i == '1')
                n = 10000;
            else if (i == '2')
                n = 50000;
            else
                n = 200000;
            cout << "�����������Ϊ:" << n / 100 << "��" << endl;
            int b = n / 100;
            clock_t start_time = clock();
            for (j = 1; j <= b; j++)
            {
                insertSort(rand(n), p);
            }
            cout << "����������ʱ:" << double(clock() - start_time) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
            start_time = clock();
            for (j = 1; j <= b; j++)
            {
                QuickSort_Recursion(rand(n), 0, p - 1);

            }
            cout << "���ŵݹ�������ʱ:" << double(clock() - start_time) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
            start_time = clock();
            for (j = 1; j <= b; j++)
            {
                QuickSort(rand(n), 0, p - 1);

            }
            cout << "���ŷǵݹ�������ʱ:" << double(clock() - start_time) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
            start_time = clock();
            for (j = 1; j <= b; j++)
            {
                MergeSort(rand(n), p);

            }
            cout << "�鲢������ʱ:" << double(clock() - start_time) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
            start_time = clock();
            for (j = 1; j <= b; j++)
            {
                CountSort(rand(n), p);

            }
            cout << "����������ʱ:" << double(clock() - start_time) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
            start_time = clock();
            for (j = 1; j <= b; j++)
            {
                RadixCountSort(rand(n), p);
            }
            cout << "����������ʱ:" << double(clock() - start_time) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
            break;
        }
        case'3':
        {
            int j = 1;
            int* a = nullptr;
            int n = 0;
            cout << "������0,1,2�������ֵ��ܺ���Ŀ" << endl;
            cin >> n;
            while (n < 0 || n > 32767)
            {
                cout << "���ֳ���int��Χ,����0-32767��ѡ��һ����������" << endl;
                cin >> n;
            }
            a = colorrand(n);
            cout << "���ڴ��ļ�" << endl;
            cout << "�򿪳ɹ�" << endl;
            cout << "ԭʼ����д��ɹ�,������data.txt��" << endl;
            cout << "��������д��ɹ�,������result.txt��" << endl;
            cout << "0,1,2���������Ѿ�ͨ����ɫ����ķ�ʽ�ź��ˣ�" << endl;
            FILE* stream1;
            freopen_s(&stream1, "data.txt", "w", stdout);
            for (int i = 0; i < n; ++i) {
                cout << a[i] << "\t"; //������ݵ�data.txt
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
                cout << a[i] << "\t"; //������ݵ�result.txt
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
            cout << "������k�Ĵ�С:";
            cin >> k;
            cout << "���������鳤��:";
            cin >> length;
            while (length < k)
            {
                cout << "���鳤�Ȳ���С��k��ֵ,�������������鳤�ȵ�ֵ" << endl;
                cin >> length;
            }
            a = rand(length);
            cout << "���ڴ��ļ�" << endl;
            cout << "�򿪳ɹ�" << endl;
            cout << "ԭʼ����д��ɹ�,������data.txt��" << endl;
            cout << "��������д��ɹ�,������result.txt��" << endl;
            cout << "��" << k << "�������Ϊ:" << findkmax(k, rand(length), 0, length - 1) << endl;
            FILE* stream1;
            freopen_s(&stream1, "data.txt", "w", stdout);
            for (int i = 0; i < length; ++i) {
                cout << a[i] << "\t"; //������ݵ�data.txt
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
                cout << a[i] << "\t"; //������ݵ�result.txt
                if (j % 5 == 0)
                {
                    cout << endl;
                }
                j++;
            }
            cout << "��" << k << "�������Ϊ:" << findkmax(k, rand(length), 0, length - 1) << endl;         
            fclose(stream1);
            break;
        }
        case '5':
        {
            int k;
            int length;
            int j = 1;
            int* a = nullptr;
            cout << "������k�Ĵ�С:";
            cin >> k;
            cout << "���������鳤��:";
            cin >> length;
            while (length < k)
            {
                cout << "���鳤�Ȳ���С��k��ֵ,�������������鳤�ȵ�ֵ" << endl;
                cin >> length;
            }
            a = rand(length);
            cout << "���ڴ��ļ�" << endl;
            cout << "�򿪳ɹ�" << endl;
            cout << "ԭʼ����д��ɹ�,������data.txt��" << endl;
            cout << "��������д��ɹ�,������result.txt��" << endl;
            cout << "��" << k << "С������Ϊ:" << findkmin(rand(length), 0, length - 1, k) << endl;
            FILE* stream1;
            freopen_s(&stream1, "data.txt", "w", stdout);
            for (int i = 0; i < length; ++i) {
                cout << a[i] << "\t"; //������ݵ�data.txt
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
                cout << a[i] << "\t"; //������ݵ�result.txt
                if (j % 15 == 0)
                {
                    cout << endl;
                }
                j++;
            }
            cout << "��" << k << "С������Ϊ:" << findkmin(rand(length), 0, length - 1, k) << endl;
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
            cout << "����������Ҫ�����鳤��" << endl;
            cin >> n;
            while (n < 0 || n > 32767)
            {
                cout << "���ֳ���int��Χ,����0-32767��ѡ��һ����������" << endl;
                cin >> n;
            }
            cout << "����Ϊ" << n << "����������Ѿ�������ϣ�" << endl;
            a = rand(n);
            cout << "1.��������(�ݹ�)" << endl;
            cout << "2.��������(�ǵݹ�)" << endl;
            cout << "3.�鲢����" << endl;
            cout << "4.��������" << endl;
            cout << "5.��������" << endl;
            cout << "6.��������" << endl;
            cout << "����������Ҫ��ԭʼ���ݴ������ĸ�txt�ĵ�" << endl;
            cin >> s1;
            cout << "���ڴ��ļ�" << endl;
            FILE* stream1;
            cout << "���ļ��ɹ�" << endl;
            cout << "�Ѿ����������д��" << s1 << "��" << endl;
            cout << "��������ָ��������ʽ" << endl;
            cin >> d;
            while (d != '1' && d != '2' && d != '3' && d != '4' && d != '5' && d != '6')
            {
                cout << "����������������1��6ѡ��һ������ʽ" << endl;
                cin >> d;
            }
            cout << "��ָ��������ʽ,�Ѿ�����ɹ�" << endl;
            cout << "����������Ҫ��������ݴ洢���ĸ�txt�ĵ���" << endl;
            cin >> s;
            cout << "���ڴ��ļ�" << endl;
            cout << "���ļ��ɹ�" << endl;
            cout << "�Ѿ����������д��" << s << "��" << endl;
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
            cout << "��ָ���ĵ�Ԫ�ص���Ŀ" << endl;
            cin >> n;
            while (n < 0 || n > 32767)
            {
                cout << "���ֳ���int��Χ,����0-32767��ѡ��һ����������" << endl;
                cin >> n;
            }
            cout << "����������Ҫ��ȡ���ĵ�" << endl;
            cin >> s1;
            cout << "��ȡ���" << endl;
            cout << "1.��������(�ݹ�)" << endl;
            cout << "2.��������(�ǵݹ�)" << endl;
            cout << "3.�鲢����" << endl;
            cout << "4.��������" << endl;
            cout << "5.��������" << endl;
            cout << "6.��������" << endl;
            cout << "��������ָ��������ʽ" << endl;
            cin >> d;
            while (d != '1' && d != '2' && d != '3' && d != '4' && d != '5' && d != '6')
            {
                cout << "����������������1��6ѡ��һ������ʽ" << endl;
                cin >> d;
            }
            cout << "��ָ��������ʽ,�Ѿ�����ɹ�" << endl;
            cout << "����������Ҫ��������ݴ洢���ĸ�txt�ĵ���" << endl;
            cin >> s;
            cout << "���ڴ��ļ�" << endl;
            cout << "���ļ��ɹ�" << endl;
            cout << "�Ѿ����������д��" << s << "��" << endl;
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
    /*   cout << "ϵͳ����2s��ص����˵�" << endl;
        Sleep(2000);
        system("cls");
        menu();
        cout << "����������Ҫ�鿴�Ĳ���" << endl;
        cin >> choice;
        while (choice != '0' && choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5' && choice != '6' && choice != '7')
        {
            cout << "�������,����0-6������ѡ��" << endl;
            cin >> choice;
            i++;
            if (i % 3 == 0)
            {
                system("cls");
            }
        }*/
  
    

         
    return 0;
}

  

