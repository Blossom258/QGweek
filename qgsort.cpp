#include"qgsort.h"
#include<stack>
using std::stack;
/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : 插入排序算法
 *  @param       : 数组指针 a, 数组长度 n
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
 *  @description : 归并排序（合并数组）
 *  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
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
 *  @description : 归并排序
 *  @param       : 数组指针a，数组起点begin，数组终点end，承载数组指针temp
 */
void MergeSort(int* a, int first, int last, int* temp)

{
	if (first < last)
	{
		int mid = (first + last) / 2;
		MergeSort(a, first, mid, temp);    //左边有序
		MergeSort(a, mid + 1, last, temp); //右边有序
		MergeArray(a, first, mid, last, temp); //再将二个有序数列合并
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
 *  @description : 快速排序（递归版）
 *  @param       : 数组指针a，数组起点begin，数组终点end
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
 *  @description : 快速排序（非递归版）
 *  @param       : 数组指针a，数组长度size
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
 *  @description : 快速排序（枢轴存放）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
int Partition1(int* a, int first, int last)//这个是返回基准值j和上述的quicksort配套使用，省去了上述quicksort求基准值的过程，从小到大排序
{
    int x = a[first], temp = 0;
    int i = first, j = last + 1;//因为后面判断是--j
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

int Partition2(int *a, int low, int high)//从大到小排序
{
	int pivot = a[low];//用第一个数作为主元
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
 *  @description : 计数排序
 *  @param       : 数组指针a，数组长度size，数组最大值max
 */
void CountSort(int* a, int n)
{
	int i;
	int largest = a[0];  //设最初最大元素默认是array[0]
	int* temp = new int[n];  //申请一个n个int元素的数组内存

	for (i = 1; i < n; i++)
	{
		if (largest < a[i])  //找出最大元素
		{
			largest = a[i];
		}
	}

	int* count = new int[largest + 1];  //申请一个[largest+1]个int元素的数组内存
	for (i = 0; i <= largest; i++)
	{
		count[i] = 0;  //初始化
	}

	for (i = 0; i < n; i++)
	{
		count[a[i]]++;  //计算array数组每个元素出现的次数
	}

	for (i = 1; i <= largest; i++)
	{
		count[i] = count[i - 1] + count[i];  //count数组元素出现次数的累加
	}

	for (i = n - 1; i >= 0; i--)
	{
		temp[count[a[i]] - 1] = a[i];  //将array[]数组的元素赋给已经排好位置的temp[]数组
		count[a[i]]--;  //数组元素的总次数减少
	}

	for (i = 0; i < n; i++)
	{
		a[i] = temp[i];  //将排好顺序的元素赋给array[]数组
	}

	delete[] count;  //释放内存
	count = NULL;
	delete[] temp;  //释放内存
	temp = NULL;
}


/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度size
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
	int* tmp = new int[n];       // 临时数组
	int* bucket = new int[10];   // 10个桶子 编号为0-9
	int radix = 1;               // 基数

	for (int i = 0; i < d; ++i) {   // 一共d趟排序

		for (int j = 0; j < 10; ++j) {  //清空桶子
			bucket[j] = 0;
		}

		for (int j = 0; j < n; ++j) {
			int k = (a[j] / radix) % 10;   // k表示arr[j]在哪号桶
			bucket[k]++;
		}

		for (int j = 1; j < 10; ++j) {       // bucket数组变形一下，也就是将tmp中的位置依次分配给每个桶子
			bucket[j] += bucket[j - 1];
		}

		for (int j = n - 1; j >= 0; --j) {   // 将所有桶子里面的记录写到tmp里面去
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
 *  @description : 颜色排序
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
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
			// 交换过去的current有可能是0或者2
			// 所以得在下次循环判断
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




 /*  @name        : 自拟
 *  @description : 在一个无序序列中找到第K大/小的数
 *  @param       : 数组指针a，数组长度size
 */



