#include<iostream>
#include<string>
#include<Windows.h>
using namespace std;

//字典序比较两个字符串,iter_1 > iter_2 ->return true
bool Cmp(string::iterator iter_1, string::iterator iter_2,string::iterator end)
{
	string tmp_str_1(iter_1, end);
	string tmp_str_2(iter_2, end);

	//tmp_str_1 > tmp_str_2
	if (tmp_str_1.compare(tmp_str_2) > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//求出来某个后缀数组suf的排名
int Rank(string str, unsigned suf)
{
	int rank = 0;

	for (auto  iter = str.begin(); iter != str.end(); iter++)
	{
		if (iter == (str.begin() + suf))
		{
			continue;
		}
		else if ( Cmp(str.begin() + suf, iter, str.end()) )
		{
			rank++;
		}
	}
	return rank;
}

//创建一个排名数组
void set_suffix_rank_array(string str, int suff_rank[],unsigned len)
{
	for(unsigned i = 0; i < len; i++)
	{
		suff_rank[i] = Rank(str, i);
	}
}

//创建后缀数组
void set_suffix_array(int suff_rank[], int suff_array[], unsigned len)
{
	for (unsigned i = 0; i < len; i++)
	{
		suff_array[suff_rank[i]] = i;
	}
}

//依次将排名相近的两个后缀数组从前向后计数（有相同前缀）
void set_height_array(string str,int suff_rank[], int suff_array[],int height[], unsigned len)
{
	unsigned h(0),r(0);
	for (unsigned i = 0; i < len; i++)
	{
		h = 0;
		r = suff_rank[i];//只是为了表达方便
		//其中的i表示的是suff_array[suff_rank[i]],为了书写方便
		while ((r+ 1<len) && (i + h < len) && (suff_array[r + 1] + h < len )
			&& (str[i + h] == str[suff_array[r + 1] + h]))
		{
			h++;
		}
		height[suff_rank[i]] = h;
	}
}