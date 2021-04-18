#include"qgsort.h"
#include<stack>
using std::stack;
/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : ���������㷨
 *  @param       : ����ָ�� a, ���鳤�� n
 */
void insertSort(int* a, long int n)

{
	for (int j = 1; j < n; j++)
	{
		int key = a[j];
		int i = j - 1;
		while (i >= 0 && a[i] > key)
		{
			a[i + 1] = a[i];
			i--;
		}
		a[i + 1] = key;
	}
}

/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : �鲢���򣨺ϲ����飩
 *  @param       : ����ָ��a���������begin�������е�mid�������յ�end����������ָ��temp
 */
void MergeArray(int* a, int first, int mid, int last, int* temp)

{
	int i = first, j = mid + 1;
	int m = mid, n = last;
	int k = 0;

	while (i <= m && j <= n)
	{
		if (a[i] <= a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}

	while (i <= m)
		temp[k++] = a[i++];

	while (j <= n)
		temp[k++] = a[j++];

	for (i = 0; i < k; i++)
		a[first + i] = temp[i];
}

/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : �鲢����
 *  @param       : ����ָ��a���������begin�������յ�end����������ָ��temp
 */
void MergeSort(int* a, int first, int last, int* temp)

{
	if (first < last)
	{
		int mid = (first + last) / 2;
		MergeSort(a, first, mid, temp);    //�������
		MergeSort(a, mid + 1, last, temp); //�ұ�����
		MergeArray(a, first, mid, last, temp); //�ٽ������������кϲ�
	}
}

bool MergeSort(int a[], int n)
{
	int* p = new int[n];
	if (p == nullptr)
		return false;
	MergeSort(a, 0, n - 1, p);
	delete[] p;
	return true;
}

/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : �������򣨵ݹ�棩
 *  @param       : ����ָ��a���������begin�������յ�end
 */
void QuickSort_Recursion(int* a, int left ,int right)
{	
	if (left >= right)
		return;
	int mid = Partition1(a, left, right);
	QuickSort_Recursion(a, left, mid - 1);
	QuickSort_Recursion(a, mid + 1, right);
	}




/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : �������򣨷ǵݹ�棩
 *  @param       : ����ָ��a�����鳤��size
 */
void QuickSort(int* a, int left, int right)

{
	stack<int> t;
	if (left < right)
	{
		int p = Partition1(a, left, right);

		if (p - 1 > left)
		{
			t.push(left);
			t.push(p - 1);
		}
		if (p + 1 < right)
		{
			t.push(p + 1);
			t.push(right);
		}

		while (!t.empty())
		{
			int r = t.top();
			t.pop();
			int l = t.top();
			t.pop();

			p = Partition1(a, l, r);

			if (p - 1 > l)
			{
				t.push(l);
				t.push(p - 1);
			}
			if (p + 1 < r)
			{
				t.push(p + 1);
				t.push(r);
			}

		}
	}
}


/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : �������������ţ�
 *  @param       : ����ָ��a���������begin�������յ�end
 */
int Partition1(int* a, int first, int last)//����Ƿ��ػ�׼ֵj��������quicksort����ʹ�ã�ʡȥ������quicksort���׼ֵ�Ĺ��̣���С��������
{
    int x = a[first], temp = 0;
    int i = first, j = last + 1;//��Ϊ�����ж���--j
    while (true) 
    {
        while (a[++i] < x && i <= last);
        while (a[--j] > x);
        if (i >= j) 
        {
            break;
        }
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    a[first] = a[j];
    a[j] = x;
    return j;
}

int Partition2(int *a, int low, int high)//�Ӵ�С����
{
	int pivot = a[low];//�õ�һ������Ϊ��Ԫ
	while (low < high)
	{
		while (low < high && a[high] <= pivot)
			--high;
		a[low] = a[high];
		while (low < high && a[low] >= pivot)
			++low;
		a[high] = a[low];
	}
	a[low] = pivot;
	return low;
}



/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : ��������
 *  @param       : ����ָ��a�����鳤��size���������ֵmax
 */
void CountSort(int* a, int n)
{
	int i;
	int largest = a[0];  //��������Ԫ��Ĭ����array[0]
	int* temp = new int[n];  //����һ��n��intԪ�ص������ڴ�

	for (i = 1; i < n; i++)
	{
		if (largest < a[i])  //�ҳ����Ԫ��
		{
			largest = a[i];
		}
	}

	int* count = new int[largest + 1];  //����һ��[largest+1]��intԪ�ص������ڴ�
	for (i = 0; i <= largest; i++)
	{
		count[i] = 0;  //��ʼ��
	}

	for (i = 0; i < n; i++)
	{
		count[a[i]]++;  //����array����ÿ��Ԫ�س��ֵĴ���
	}

	for (i = 1; i <= largest; i++)
	{
		count[i] = count[i - 1] + count[i];  //count����Ԫ�س��ִ������ۼ�
	}

	for (i = n - 1; i >= 0; i--)
	{
		temp[count[a[i]] - 1] = a[i];  //��array[]�����Ԫ�ظ����Ѿ��ź�λ�õ�temp[]����
		count[a[i]]--;  //����Ԫ�ص��ܴ�������
	}

	for (i = 0; i < n; i++)
	{
		a[i] = temp[i];  //���ź�˳���Ԫ�ظ���array[]����
	}

	delete[] count;  //�ͷ��ڴ�
	count = NULL;
	delete[] temp;  //�ͷ��ڴ�
	temp = NULL;
}


/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : ������������
 *  @param       : ����ָ��a�����鳤��size
 */

int maxBit(int* arr, int n) {      
	int d = 1;
	int p = 10;
	for (int i = 0; i < n; ++i) {
		while (arr[i] >= p) {
			p *= 10;
			d++;
		}
	}
	return d;
}


void RadixCountSort(int* a, int n)
{
	if (n <= 0)
		return;

	int d = maxBit(a, n);
	int* tmp = new int[n];       // ��ʱ����
	int* bucket = new int[10];   // 10��Ͱ�� ���Ϊ0-9
	int radix = 1;               // ����

	for (int i = 0; i < d; ++i) {   // һ��d������

		for (int j = 0; j < 10; ++j) {  //���Ͱ��
			bucket[j] = 0;
		}

		for (int j = 0; j < n; ++j) {
			int k = (a[j] / radix) % 10;   // k��ʾarr[j]���ĺ�Ͱ
			bucket[k]++;
		}

		for (int j = 1; j < 10; ++j) {       // bucket�������һ�£�Ҳ���ǽ�tmp�е�λ�����η����ÿ��Ͱ��
			bucket[j] += bucket[j - 1];
		}

		for (int j = n - 1; j >= 0; --j) {   // ������Ͱ������ļ�¼д��tmp����ȥ
			int k = (a[j] / radix) % 10;
			tmp[bucket[k] - 1] = a[j];
			bucket[k]--;
		}

		for (int j = 0; j < n; ++j) {        // copy one-sorted array tmp back
			a[j] = tmp[j];
		}

		radix *= 10;
	}

	delete[] bucket;
	delete[] tmp;	
	
}

/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : ��ɫ����
 *  @param       : ����ָ��a��ֻ��0��1��2Ԫ�أ������鳤��size
 */
void ColorSort(int* a, int size)
{
	int start = 0;
	int end = size - 1;
	int current = 0;
	while (current <= end)
	{
		if (a[current] < 1)
		{
			std::swap(a[current++], a[start++]);
		}
		else if (a[current] > 1)
		{
			// ������ȥ��current�п�����0����2
			// ���Ե����´�ѭ���ж�
			std::swap(a[current], a[end--]);
		}
		else
		{
			current++;
		}
	}
	
		
}


int findkmax(int k,int *L,int low,int high)
{
	int temp;
	temp=Partition1(L,low,high);
	if(temp==k-1)
	{
		return L[temp];
	}
	else if(temp>k-1)
		findkmax(k,L,low,temp-1);
	else
		findkmax(k,L,temp+1,high);
}

int findkmin(int A[], int low, int high, int k)
{
	if (low <= high)
	{
		int pivot_pos = Partition1(A, low, high);
		if (pivot_pos  == k-1)
			return A[pivot_pos];
		else if (pivot_pos + 1 > k)
			findkmin(A, low, pivot_pos - 1, k);
		else
			findkmin(A, pivot_pos + 1, high, k);
	}
	else
		return -1;

}




 /*  @name        : ����
 *  @description : ��һ�������������ҵ���K��/С����
 *  @param       : ����ָ��a�����鳤��size
 */



