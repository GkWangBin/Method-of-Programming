/*
*题目：输入一个整数数组和一个整数，在数组中查找一对数，满足他们的和正好是输入的那个整数.
*如果有多对数的和等于输入的整数，输出任意一对即可。
*/
#include<iostream>
#include<Windows.h>

using namespace std;

#define add(a,b) (a+b)
/*最简单的方法是穷举法，蛮力将任意两个数字相加判断是否是给定的值.
*穷举法复杂度为O(n2)。但是如果题目要求打印所有的数字对，并打印位置的话，优先考虑该方法。
*/

void force_find_pair(int arr[], int key, int len)
{
	int i(0), j(len - 1);
	int num(0);
	for ( i = 0; i < len; i++)
	{
		for (j = len - 1; j>i; j--)
		{
			num = add(arr[i], arr[j]);
			if (num == key)
			{
				cout << key << " = " << arr[i] << " + " << arr[j] <<" : "<<i<<"+"<<j<< endl;
			}
		}
	}
}

/*可以做减法，在数组中任意取一个值后查询与给定的值的差是否在数组中；
*可以在查找阶段做优化。如果顺序查找，总时间复杂度为n*O(n)->O(n2);
*如果使用的是二分查找的话时间复杂度为n*O(logn)->O(n*logn);
*如果将数组中的数据放入散列表中，每次查询为O(1),所以时间复杂度为O(n),
*但是使用散列表是用空间换时间，需要花费O(n)的空间来构造散列表
*/

/*可以先将数组中的数据排序，然后前后夹逼求和看是否等于给定值。
*加入使用的是快速排序，那么时间复杂度为O(nlogn)+O(n)->O(n*logn).
*/
int partation(int arr[], int low, int high)
{
	int pivot(arr[high]), left(low), right(high);
	while (left < right)
	{
		while (left < right && arr[left] <= pivot) left++;
		arr[right] = arr[left];
		while (left < right && arr[right] >= pivot) right--;
		arr[left] = arr[right];
	}
	arr[left] = pivot;
	return left;
}

void quick_sort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pos = partation(arr, low, high);
		quick_sort(arr, low, pos-1);
		quick_sort(arr, pos + 1, high);
	}
}


void find_pair(int arr[], int key, int len)
{
	quick_sort(arr, 0, len-1);
	
	//寻找已排序的数组中两个数
	int l(0), r(len - 1), num(0);
	while (l<r)
	{
		num = add(arr[l], arr[r]);
		if (num == key)
		{
			cout << key << " = " << arr[l] << " + " << arr[r] << endl;
			break;
		}
		else if (num > key)
		{
			r--;
		}
		else
		{
			l++;
		}
	}
}


int test_2(void)
{
	int arr[]{ 8, 1, 3, 4, 5, 10, 54, 7, 16, 6};
	int len = 10;
	int key = 15;
	
	//寻找和为定值的两个数；
	//find_pair(arr, key, len);

	//寻找和为定值的所有数对，并且打印在数组中的位置
	force_find_pair(arr, key, len);

	system("pause");
	return 0;
}