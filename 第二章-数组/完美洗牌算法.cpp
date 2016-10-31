/*题目：有一个长度为2n的数组{a1, a2,a3,...,an, b1, b2, b3,..., bn},
*希望排完序后变成{a1,b1,a2,b2,...,an,bn}，请考虑有没有时间复杂度为O(n)
*而空间复杂度为O(1)的解法。完美洗牌及均匀的穿插
*/

#include<iostream>
#include<Windows.h>

using namespace std;

extern void swap(int *a, int *b);
//可以使用蛮力交换的方法，时间复杂度为O(2n),空间复杂度为O(1)
void force_swap(int arr[], int n)
{
	for (int i = 1, j=n+1; i < n, j<2*n; i+=2,j+=2)
	{
		swap(arr + i, arr + j);
	}
}
