#include<stdio.h>
#include<cstdlib>
#include<ctime>
#include<iostream>
using std::cout;
int * rand(long int n)
{
    int* a = new int [n];
    srand(unsigned(time(0)));//����ʱ������
    const int MAX = 32767;
    const int MIN = 0;
    for (int i = 0; i < n; ++i) {
       a[i]= rand() % (MAX - MIN + 1) + MIN;//���ĺ���
    }
    return a;
}