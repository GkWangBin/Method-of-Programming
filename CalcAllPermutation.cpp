/*问题描述：输入一个字符串，打印出该字符串中字符的所有排列。、
 *例如输入字符串“abc”，则输出由字符‘a’，‘b’，‘c’所能排列出来的所有字符串：
 *“abc”，“acb”，“bac”，“bca”，“cab”，“cba”
 */

#include<iostream>
#include<string>
//使用算法头文件中提供的swap(char &a, char &b)函数
#include<algorithm>
#include<Windows.h>

using namespace std;
/*
*解题思路，使用递归的方式
*先确定下当前所处理字符串的第一个字符，然后递归处理剩余的字符串。
*时间复杂度为O(n!).
*/
void recursion_calc_all_permutation(string &str, unsigned int from,unsigned int to)
{
	if (to <= 1)//无效的参数，直接退出递归
	{
		return;
	}
	/*字符串已经将最后一个字符作为了首字符，打印字符串*/
	if (from == to)
	{
		for (unsigned int  i = 0; i <= to; i++)
		{
			cout << str[i];
		}
		cout << endl;
	}
	/*处理当前字符串的第一个字符，并处理除了第一个字符以外的字符串*/
	else
	{
		for (unsigned j = from; j <= to; j++)
		{
			swap(str[j], str[from]);
			recursion_calc_all_permutation(str, from + 1, to);
			/*在出递归之后一定要记得将交换过字符顺序的字符串还原到之前的样子*/
			swap(str[j], str[from]);
		}
	}
}

bool library_calc_all_permutation(string &str, int num)
{
	int i;
	/*找到排列中最后一个升序的首位位置i*/
	for ( i = num-2; i >=0 && str[i] >= str[i+1]; i--)
	{}
	/*已经找到了所有排列*/
	if (i<0)
	{
		return false;
	}
	int k;
	for ( k = num-1; k > i && str[k] <= str[i]; k--)
	{}
	swap(str[k], str[i]);
	reverse(str.begin() + i + 1, str.end());
	//cout << str << endl;
	return true;
}

/*字典序的所有排列：
 *已知字符串中的字符是互不相同的，现在把他们任意排列。
 *例如“ab”->"aa","bb","ab","ba",编程按照字典序输出所有的组合
 *思路：可以使用笛卡尔积的思想，重载*号，将两个数组相乘（每个元素分别组合）并输出。
 */
void mut_permutation(string str)
{
	string str1(str);

	for (unsigned int i = 0; i < str.size(); i++)
	{
		for (unsigned int j = 0; j < str1.size(); j++)
		{
			cout << str[i] << str1[j] << " ";
		}
		cout << endl;
	}
}
int main(void)
{
	//string str("abcd");
	string cstr = "12345";
	/*cout << cstr.size() << endl;
	recursion_calc_all_permutation(str, 0, str.size() - 1);
	while (library_calc_all_permutation(cstr,cstr.size()))
	{
		cout << cstr << endl;
	}
	*/
	mut_permutation(cstr);
	system("pause");
	return 0;
}