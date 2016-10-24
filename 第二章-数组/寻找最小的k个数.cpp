/*题目：有n个整数，请找出其中最小的k个整数，要求时间复杂度尽可能低*/
/*首先可以使用先排序，再输出的策略。
*假设使用的是快速排序，时间复杂度为O(nlogn)+O(k)->O(nlogn)*/

#include<iostream>
#include<Windows.h>

using namespace std;

void swap(int *a, int *b)
{
	int tmp(*b);
	*b = *a;
	*a = tmp; 
}
/*
int partation(int *arr, int low, int high)
{
	int pivot = arr[high];
	int left(low), right(high - 1);

	while (left < right)
	{
		//while内部如果没有left与right大小的判断，可能会产生越界问题
		while (left<right && arr[left] <= pivot) left++;
		while (left<right && arr[right] >= pivot) right--;
		if (left < right)
		{
			swap(arr + left, arr + right);
		}
	}
	//此时left==right
	if (arr[left] > arr[high])
	{
		swap(arr + left, arr + high);//left == right
		return left;
	}
	//如果遇到2，1，4这种情况的话，
	else
	{
		return high;
	}
}
void quick_sort(int *arr, int low, int high)
{
	if (low < high)
	{
		int pos = partation(arr, low, high);
		//这里出现过问题，如果是pos-1的话
		quick_sort(arr, low, pos-1);
		quick_sort(arr, pos + 1, high);
	}
}

//交换是一个很麻烦的方式,虽然看着是从两边向中间同时进行扫描
*/
//快速排序算法

int partation(int *arr, int low, int high)
{
	int pivot = arr[high];
	int left(low), right(high);

	while (left < right)
	{
		//while内部如果没有left与right大小的判断，可能会产生越界问题
		while (left < right && arr[left] <= pivot)left++;
		arr[right] = arr[left];
		while (left<right && arr[right] >= pivot) right--;
		arr[left] = arr[right];
	}
	arr[left] = pivot;
	return left;
}

void quick_sort(int *arr, int low, int high)
{
	if (low < high)
	{
		int pos = partation(arr, low, high);
		quick_sort(arr, low, pos - 1);
		quick_sort(arr, pos + 1, high);
	}
}

void all_sort(int arr[],int k)
{
	quick_sort(arr, 0 , 9);
	for (int i = 0; i < k; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

/*还有一种思路，是将部分有序
*考虑冒泡的方式，冒泡排序，一次产生一个有序的数字。
*一般冒泡排序的时间复杂度为O(n2),但是在这里只要求找到。
*最小的k个数字，也就是外部循环边界是k，时间复杂度编程了O(nk).
*/

void bubble_sort(int arr[], int n, int k)
{
	for (int i = 0; i < k; i++)
	{
		for (int j = n - 1; j>i; j--)
		{
			if (arr[j]<arr[j-1])
			{
				swap(arr + j, arr + j - 1);
			}
		}
		cout << arr[i] << " ";
	}
	cout << endl;
}

/*一遍扫描的方式，首先假设数组中前k个数字即为所求，求出该段数组中的最大值max
*从k开始向后扫描，每走一步与max做比较，如果小于max则替换max的值，继续向后扫描
*寻找最大值的时间复杂度为O(k),需要寻找(n-k)次最大值，即时间复杂度为O(k)+(n-k)O(k)
*所以时间复杂度为O(nk)
*/
//该函数需要返回两个参数，最大值和最大值的位置,时间复杂度为O(k)
int partation_max(int arr[], int k, int &max)
{
	max = arr[0];
	int pos(0);
	for (int i = 0; i < k; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			pos = i;
		}
	}
	return pos;
}

void partation_sort(int arr[], int n,int k)
{
	if (n < k)
	{
		return;
	}
	int max_num(arr[0]), pos(0);
	for (int  i = k; i < n; i++)
	{
		pos = partation_max(arr, k, max_num);
		if (arr[i] < max_num)
		{
			swap(arr + i, arr + pos);
		}
	}
	for (int  j = 0; j < k; j++)
	{
		cout << arr[j] << " ";
	}
	cout << endl;
}

/*可以将上边的方法中前k个使用堆排序的方式，建堆时间为O(k),每次搜索最大值的时间为O(logk),
*所以时间复杂度为O(k)+(n-k)O(logk)->O(nlogk)
*/
#define LeftChild(i) (2 * ( i ) + 1)
//下滤操作
void perc_down(int arr[], int i, int k)
{
	int child;
	int tmp;
	for (tmp = arr[i]; LeftChild(i) < k; i = child)
	{
		child = LeftChild(i);
		if (child != k-1 && arr[child + 1] > arr[child])
		{
			child++;
		}
		if (tmp < arr[child])//将小的父亲下滤
		{
			arr[i] = arr[child];
		}
		else//已经到了堆底，无法继续
		{
			break;
		}
	}
	arr[i] = tmp;
}
//建立一个大顶堆
void build_heap(int arr[], int k)
{
	int i;
	for ( i = k/2; i >= 0; i--)
	{
		perc_down(arr, i, k);
	}
}

void partation_sort_heap(int arr[], int n, int k)
{
	if (n < k)
	{
		return;
	}
	for (int i = k; i < n; i++)
	{
		//每次扫描到一个新的数字后建堆
		build_heap(arr, k);
		if (arr[i] < arr[0])
		{
			swap(arr + i, arr + 0);
		}
	}
	for (int j = 0; j < k; j++)
	{
		cout << arr[j] << " ";
	}
	cout << endl;
}

/*线性选择算法：类似与快排。将数组中第k小的元素放在k-1的位置，
*小于arr[k-1]的元素在其左侧,时间复杂度为O(n)
*/
void quick_sort_line(int *arr, int k, int low, int high)
{
	if (low < high)
	{
		int pos = partation(arr, low, high);
		if (k <= pos)
		{
			quick_sort_line(arr, k, low, pos - 1);
		}
		else if (k > pos)
		{
			quick_sort_line(arr, k, pos + 1, high);
		}
	}
}


/*题目：给定一个数列a1，a2, a3, ...,an和m个三元组表示的查询，对于每个查询
*(i,j,k),输出ai,ai+1,...,aj的升序排列中的第k个数
*/
void print_i_j_k(int arr[], int i, int j, int k)
{
	if (j-i < k)
	{
		return ;
	}
	quick_sort_line(arr, k, i, j);
	cout << arr[i + k - 1]<<endl;
}

int main(void)
{
	int arr[]{ 8, 1, 3, 4, 5, 10, 54, 7, 16, 6};
	int k = 3;
	//all_sort(arr, k);//第二个参数为count-1；
	//bubble_sort(arr, 10, k);//第二个参数为数组大小，第三个参数是k
	//partation_sort(arr, 10, k);//输出的是无序的
	//partation_sort_heap(arr, 10, k);
	//quick_sort_line(arr, 5, 0, 9);
	int i(1), j(5);
	print_i_j_k(arr, i, j, k);
	for (int  p = i; p <= j; p++)
	{
		cout << arr[p] << " ";
	}
	
	cout << endl;
	system("pause");
	return 0;
}