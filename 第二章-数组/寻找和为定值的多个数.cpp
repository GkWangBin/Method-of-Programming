/*题目：输入两个整数n和sum，要求从数列1，2，3，...，n中任意取出几个数，
*使得他们的和等于sum，请将其中所有可能的组合列出来。
*列出所有的可能，首先想到的是穷举，其次是递归。
*典型的背包问题。
*/
#include<iostream>
#include<Windows.h>
//因为要保存所有满足要求的数列并输出，链表比较方便
#include<list>

using namespace std;

/*解题思路：(0 1背包问题，每个数字有放或者不放的选择)由于数列是一个从1到n的连续的集合，
 *所以不需要将其放入某个容器中，单个数字n就可以表示出来整个数列。
*可以将n问题转化为n-1问题。
*如果和等于sum的数列中包括n，那么问题就转化为“取前n-1个数使得他们的和等于sum-n”
*如果不包括n，问题->"取前n-1个数使得他们的和等于sum"
*/

list<int> result_list;
void sum_of_number(int sum, int n)
{
	//递归退出条件，说明该条线上不可行
	if (n <= 0 || sum <= 0)
	{
		return;
	}
	if (n == sum)
	{
		//按添加到list的顺序输出出来
		result_list.reverse();
		for(auto num : result_list)
		{
			cout << num << " + ";
		}
		//最后满足条件的n还没有添加到列表中
		cout << n << endl;
	}

	result_list.push_front(n);
	//上边所说的第一中情况
	sum_of_number(sum - n, n - 1);
	//第二种情况，需要将放进去的n再弹出
	result_list.pop_front();
	sum_of_number(sum, n - 1);
}

//输出特定个数且和为给定数的一个序列
void sum_of_k_number(int sum, int n, int k)
{
	//递归退出条件，说明该条线上不可行
	if (n <= 0 || sum <= 0)
	{
		return;
	}
	if (n == sum && result_list.size() == k-1)
	{
		//按添加到list的顺序输出出来
		result_list.reverse();
		for (auto num : result_list)
		{
			cout << num << " + ";
		}
		//最后满足条件的n还没有添加到列表中
		cout << n << endl;
	}

	result_list.push_front(n);
	//上边所说的第一中情况
	sum_of_k_number(sum - n, n - 1,k);
	//第二种情况，需要将放进去的n再弹出
	result_list.pop_front();
	sum_of_k_number(sum, n - 1,k);
}
int main(void)
{
	int sum = 20;
	int n = 10;
	int k = 3;
	//sum_of_number(sum, n);
	sum_of_k_number(sum, n, k);
	system("pause");
	return 0;
}