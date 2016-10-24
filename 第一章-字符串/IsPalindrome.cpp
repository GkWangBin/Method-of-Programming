/*回文判断：
给定一个字符串，如何判断这个字符串是否是回文串
*/

#include<iostream>
#include<string>
#include<Windows.h>

#include<forward_list>
#include<stack>
#include<deque>

using namespace std;

/*
 *思路：从字符串两头向中间扫描，如果不相等则返回false，
 *直到尾指针小于头指针
 *时间复杂度为:O(n).
 */
bool is_palindrome_from_two_head(const string str)
{
	unsigned int i(0), j(str.size() - 1);
	for ( ; i<=j; i++,j--)
	{
		if (str[i] != str[j])
			return false;
	}
	return true;
}
/*类似与从两边向中间，也可以从字符串中间向两边扫描
 *记得判断字符串长度奇偶情况。
 *时间复杂度为O(n)
 */
bool is_palindrome_from_middle(const string str)
{
	unsigned int i, j;
	if (str.size()%2 != 0)
	{
		i = j = str.size() / 2;
	}
	else
	{
		j=str.size() / 2;
		i = j - 1;
	}
	for ( ; i <= j && i>=0 && j<str.size(); i--,j++)
	{
		if (str[i] != str[j])
		{
			return false;
		}
	}

	return true;
}
/*判断一个单链表是否是回文
 *可以使用快慢指针的方式，一个指针指着list头部，另外一个指向链表中间，
 *然后将链表后半段翻转。开始遍历对比是否是回文。
 *但是在使用stl::forward_list时，不能使用该方法
 *注意，forward_list没有size()成员函数
 */
bool is_list_palindrome(forward_list <char> &clist)
{
	forward_list <char> tmp_list(clist);
	
	/*调用forward_list的reverse函数*/
	/*不能使用头文件algorithm中的reverse函数*/
	clist.reverse();
	
	auto it_clist = clist.begin();
	auto it_tmplist = tmp_list.begin();

	for ( it_clist,it_tmplist; it_clist!=clist.end(),
		it_tmplist != tmp_list.end(); it_clist++,it_tmplist++)
	{
		if (*it_clist != *it_tmplist)
		{
			return false;
		}
	}
	return true;
}

/*将字符串压入字符栈中，然后将栈元素弹出，
 *依次与字符串中字符比较
 */
bool is_stack_palindrome(const	string str)
{
	/*栈是一个顺序容器适配器，接受一种已有的容器类型，
	*使其行为看起来像一种不同的类型
	*/
	deque<char>	cdeque;
	stack <char> cstack(cdeque);
	for (unsigned int i = 0; i < str.size(); i++)
	{
		cstack.push(str[i]);
	}
	for (unsigned int  j = 0; j < str.size() && !cstack.empty(); j++)
	{
		if (str[j] != cstack.top())
		{
			cstack.pop();
			return false;
		}
	}
	return true;
}

/*需要检查输入的字符串是否合法*/
int main(void)
{
	string str("abcdcb");
	forward_list <char> clist = { 'a', 'b', 'c', 'b', 'a' };
	
	if (is_stack_palindrome(str))
	//if (is_list_palindrome(clist))
	//if (is_palindrome_from_middle(str))
	//if (is_palindrome_from_two_head(str))
	{
		cout << "stack" << " is palindrome!" << endl;
	}
	else
	{
		cout << "stack" << " is not palindrome!" << endl;
	}

	system("pause");
	return 0;
}
