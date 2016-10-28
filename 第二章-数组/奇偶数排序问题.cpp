/*题目：给定一个整数数组，请调整数组中数的顺序，使得所有奇数位于数组的
*前半部分，所有偶数位于数组的后半部分。要求时间复杂度为O(n).
*/
#include<iostream>
#include<Windows.h>

#define IsOddNum(n) (n%2)
using namespace std;

extern void swap(int *a, int *b);

//考虑快排的设计枢轴的方式，两个指针向中间夹逼，时间复杂度为O(n).
void odd_even_sort(int arr[], int n)
{
	//假设传入数组参数之前已经检查了数组不为空，n为数组中元素的个数
	if (n <= 1) return;

	int left(0), right(n - 1);
	while (left < right)
	{
		while (left < right && IsOddNum(arr[left])) left++;
		while (left < right && !IsOddNum(arr[right])) right--;
		swap(arr + left, arr + right);
	}
}
//也可以使用两个指针(奇指针，偶指针)同时向右移动，一遍扫描的方式排序O(n);
//以下方法只能将奇偶数分开，不能保证把奇数放在偶数前边
void odd_even_sort_oneside(int arr[], int n)
{
	int odd(0), even(0);

	while (odd != n-1 && even != n-1)
	{
		while (IsOddNum(arr[odd]) && odd != n - 1) odd++;
		while (!IsOddNum(arr[even]) && even != n - 1) even++;
		swap(arr + odd, arr + even);
	}
}


int test_6(void)
{
	int arr[]{2, 3, 4, 5, 6, 7, 8, 9};
	int len(8);
	//odd_even_sort(arr, len);
	odd_even_sort_oneside(arr, len);
	for (int  i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}