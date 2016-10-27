/*问题：一个台阶总共有n级，如果依次可以跳1级，也可以跳2级，求总共有多少种跳法
*解题思路：该题是斐波那契数列的的应用。如果台阶只有一级，那么只有一种跳法f(1)=1;
*如果台阶有两级，该人可以一次跳两级也可以跳两次,f(2)=2;如果台阶有三级，那么
*第一次可以选择跳一级或者两级，有f(3)=f(2)+f(1),推广到n个台阶，有公式：
*f(1)=1;
*f(2)=2;
*...
*f(n)=f(n-1)+f(n-2);
*由此可以看出来这是一个递归问题(可变表示成一个循环)，时间复杂度为O(n).
*问题衍生：跳台阶问题也是兔子生崽问题，只是表述的不一样
*/
#include<iostream>
#include<Windows.h>

using namespace std;

//递归计算
long fibonacci(unsigned int n)
{
	int arr[]{0, 1, 2};
	//递归退出条件
	if (n <= 2)
	{
		return arr[n];
	}
	return fibonacci(n - 1) + fibonacci(n - 2);
}

/*但是递归的话会有很多的重复计算，可以将递归改成循环消除重复计算*/
long long fibonacci_cicle(unsigned int n)
{
	long long arr[3]{1, 1};
	if (n < 2)
	{
		return arr[1];
	}

	for (int i = 2; i <=n; i++)
	{
		arr[2] = arr[0] + arr[1];
		arr[0] = arr[1];
		arr[1] = arr[2];
	}
	return arr[2];
}
/*兑换硬币问题：想兑换100元零钱，有1、2、5和10元四种面值，总共有多少兑换方法
*比起跳台阶问题，兑换硬币问题不考虑了兑换的次序，因此不能直接套用斐波那契数列公式。
*/

int main(void)
{
	unsigned int n = 100;
	//cout << fibonacci(n) << endl;;
	cout << fibonacci_cicle(n) << endl;;

	system("pause");
	return 0;
}