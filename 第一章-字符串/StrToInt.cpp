/*输入一个由数字组成的字符串，请把它转换成整数并输出*/

#include<iostream>
#include<string>
#include<Windows.h>

using namespace std;

/*可以转换简单的正整数字符串
 *时间复杂度O(n) 
 */
int str_to_int(const string str)
{
	int value = 0, pos = 0;
	while (str[pos] != '\0')
	{
		value = value * 10 + (str[pos] - '0');
		pos++;
	}
	return value;
}

int main(void)
{
	string str("123456");
	cout << str_to_int(str)<< endl;

	system("pause");
	return 0;
}