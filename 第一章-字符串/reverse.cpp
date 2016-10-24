/*题目描述：
 * 给定一个字符串，要求将字符串前面的若干字符移到字符串的尾部*
 *例如：abcdef->defabc*
 */
#include<iostream>
#include<string>
#include<Windows.h>
#include<utility>//pair<int,int>类型头文件

using namespace std;

/*使用冒泡的方式，蛮力将m个字符移动到尾部，空间复杂度O(1),时间复杂度O(m*n)*/
/*使用&str引用符号，可以改变字符串本身的内容*/
void swap(string& str, int i,int j)
{
	char tmp;
	tmp = str[i];
	str[i] = str[j];
	str[j] = tmp;
}

/*不改变主函数中原字符串的内容*/
void force_reverse(string str, int m)
{
	int len = str.size();

	for (int  i = 0; i < m; i++)
	{
		for (int j = 0; j < len - 1; j++)
		{
			swap(str, j, j + 1);
		}
	}
	cout << "移动后的字符串：" << str << endl;
}

/*三次翻转法
 *时间复杂度为：O(n)+O(m)+O(n-m)->O(n)
 *空间复杂度为O(1)
 */
void partion_reverse(string &str, int from, int to)
{
	if (from != to)
	{
		int half = (from + to) / 2;
		while (from <= half)
		{
			swap(str, from++, to--);
		}
	}
}
void three_reverse(string str, int m)
{
	int len = str.size();

	partion_reverse(str, 0, len - 1);
	partion_reverse(str, 0, len - m - 1);
	partion_reverse(str, len - m, len - 1);

	cout << "移动后的字符串：" << str << endl;
}

/*题目：单词翻转。
 *输入一个英文句子，翻转句子中单词的顺序。要求单词内字符的顺序不变，
 *句子中单词以空格符隔开,表达点符号和普通字母一样处理.
 *思路：类似于三次翻转，总字符串翻转之后，进行处理，每个单词翻转一次。
 *时间复杂度为O(n)
 */
/*
 *pair<int, int> deal_space(string &str, int second_pos)函数
 *确定字符串中每个单词开始和结束的位置，并返回一对坐标位置。
 *接受两个参数，第一个参数为字符串，第二个参数是单词结束的位置
*/
pair<int, int> deal_space(string &str, int second_pos,int str_len)
{
	int first, second;
	if (str[second_pos+1] == ' ')
	{
		first = second = second_pos + 2;
		while (str[second + 1] != ' ' && second + 1 != str_len)
		{
			second++;
		}
	}
	return{ first, second };
}
void reverse_string(string str)
{
	int len = str.size();
	pair<int, int> space_pos(0, 0);

	partion_reverse(str, 0, len - 1);

	/*因为第一个单词前没有空格，所以要将第一个单词单独处理*/
	while (str[space_pos.second + 1] != ' ' && space_pos.second + 1 != len)
	{
		space_pos.second++;
	}
	partion_reverse(str, space_pos.first, space_pos.second);

	while (space_pos.second < len-1)
	{
		space_pos = deal_space(str, space_pos.second,len);
		partion_reverse(str, space_pos.first, space_pos.second);
	}
	cout << "翻转后的字符串：" << str << endl;
}

int main(void)
{
	string str("how are you?");
	//force_reserve(str, 4);
	//three_reverse(str, 4);
	reverse_string(str);
	system("pause");
	return 0;
}