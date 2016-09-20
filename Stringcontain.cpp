/*题设：给定一长字符串a和字符串b，判断出段字符串b中的所有字符都包含在字符串a中*/
/*一般思路都是“长动短不动”*/

#include<iostream>
#include<string>
#include<Windows.h>
#include<algorithm>
#include<map>
#include<set>

using namespace std;

//蛮力遍历两个字符串，时间复杂度O(m*n),其中m>=n

bool string_contain_force(const string &long_str, const string &short_str)
{
	string::size_type l_pos(0), s_pos(0);

	for (; s_pos < short_str.size(); s_pos++)
	{
		for (; l_pos < long_str.size() && (long_str[l_pos] != short_str[s_pos]); l_pos++)
		{}
		if (l_pos>long_str.size()-1)
		{
			return false;
		}
	}
	return true;
	
}

/*对字符串先排序，然后在进行比较
*对字符串排完序之后每个字符之间就可以直接比较大小
*比如：abcde，acd
*假设排序用的是快排，时间复杂度为O(mlogm)+O(nlogn)
*嵌套循环实际上对两个字符串只遍历了一遍
*/
bool string_sort_contain(string long_str, string short_str)
{	
	string::size_type l_pos(0), s_pos(0);
	sort(long_str.begin(), long_str.end());
	sort(short_str.begin(), short_str.end());
	
	for (; s_pos < short_str.size(); s_pos++)
	{
		while (long_str[l_pos] < short_str[s_pos] && l_pos < long_str.size())
			l_pos++;
		if (l_pos == long_str.size() || long_str[l_pos] < short_str[s_pos])
		{
			return false;
		}
	}
	return true;
}

/*
 *建立26字母对应素数的映射表,算出每个字符串的值,长字符串是否能整除短字符串.
 *该算法比较局限,一旦字符串中出现了映射表外的字符，很可能引起程序崩溃。
 *时间复杂度为O(m+n)，该算法的最好时间复杂度O(n).
 */
map<char, int> make_map()
{
	const int prime_arr[] = { 2, 3,5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43,
		47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101 };
	
	map<char, int> map;
	char tmp = 'a';
	int i = 0;
	for (; tmp <= 'z'; tmp++, i++)
	{
		map[tmp] = prime_arr[i];
	}
	return map;
}
bool string_prime_contain(const string long_str, const string short_str)
{
	map<char, int> map(make_map());
	int l_value(1), s_value(1);
	for (string::size_type i(0); i <long_str.size(); i++)
	{
		l_value *= map.at(long_str[i]);
	}
	for (string::size_type j(0); j <short_str.size(); j++)
	{
		s_value *= map.at(short_str[j]);
	}
	if (l_value%s_value > 1)
	{
		return false;
	}
	return true;
}

/*可以将长字符串放在一个集合中，依次寻找短字符串中字符时候全部出现在了集合中
*时间复杂度为O(m+n)*/
bool string_set_contain(const string long_str, const string short_str)
{
	set<char> characters_set;
	for (string::size_type i(0); i <long_str.size() ; i++)
	{
		characters_set.insert(long_str[i]);
	}
	for (string::size_type j = 0; j < short_str.size(); j++)
	{
		if (characters_set.find(short_str[j]) == characters_set.end())
		{
			return false;
		}
	}
	return true;
}

int main(void)
{
	string long_str("howareyou");
	string short_str("how");
	/*
	if (string_contain_force(long_str,short_str))
	{
		cout << "Contian!" << endl;
	}
	
	if (string_sort_contain(long_str, short_str))
	{
		cout << "Contian!" << endl;
	}
	
	if (string_prime_contain(long_str, short_str))
	{
		cout << "Contian!" << endl;
	}
	*/
	if (string_set_contain(long_str, short_str))
	{
		cout << "Contian!" << endl;
	}
	else
	{
		cout << "Not contain!" << endl;
	}

	system("pause");
	return 0;
}