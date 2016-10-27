/*题目：给定一个证书数组，数组里可能有正数、负数和零。数组中连续的一个或
*多个整数组成一个子数组，每个子数组都有一个和。求所有子数组的和的最大值。
*/
#include<iostream>
#include<Windows.h>

using namespace std;

//蛮力寻找，时间复杂度为O(n3)
int max_sub_array(int arr[], int n)
{
	int max_sum = arr[0];
	int current_sum = 0;

	for (int i = 0; i < n; i++)
	{
		for (int  j = i; j < n; j++)
		{
			for (int k = i; k <= j; k++)
			{
				current_sum += arr[k];
			}
			if (current_sum > max_sum)
			{
				max_sum = current_sum;
			}
			//每次循环之后要将当前和清零
			current_sum = 0;
		}
	}
	return max_sum;
}

/*动态规划的方法,边向后扫描边判断.并输出子串在数组中的位置
*时间复杂度为O(n)
*/

int max_sub_dynamic(int arr[], int n)
{
	int max_sum = arr[0];
	int current_sum = 0;
	int start(0), end(0);
	for (int i = 0; i < n; i++)
	{
		//这里如果用的是">="号的话可能扩大范围
		if (current_sum > 0)
		{
			current_sum += arr[i];
		}
		else
		{
			current_sum = arr[i];
			//又从头开始计算一个子串
			start = i;
		}
		if (current_sum > max_sum)
		{
			max_sum = current_sum;
			end = i;
		}
	}
	cout << start << "->" << end << endl;
	return max_sum;
}

/*给定一个数组，允许交换数组中任意两个数的位置，求最大子数组和。
*可以考虑使用快排的思量，从两边向中间扫描，将小于零的数字放在数组右边，大于零的
*放在左边，时间复杂度为O(n),然后从前往后依次相加，知道数小于零停止。
*/
extern void swap(int *a, int *b);

int max_sub_pro(int arr[], int n)
{
	int left(0), right(n - 1);
	while (left < right)
	{
		while (arr[left] >= 0 && left < right)left++;
		while (arr[right] <= 0 && left < right)right--;
		swap(arr + left, arr + right);
	}

	int max_arr = arr[0];
	for (int i = 0; arr[i]>=0; i++)
	{
		max_arr += arr[i];
	}

	return max_arr;
}
int test_4(void)
{
	int arr[]{1,4,0,-5,7,-4,-2,10,9,0,-1,2};
	int n = 12;
	//cout << max_sub_array(arr, n) << endl;
	//cout << max_sub_dynamic(arr, n) << endl;
	cout << max_sub_pro(arr, n) << endl;
	system("pause");
	return 0;
}