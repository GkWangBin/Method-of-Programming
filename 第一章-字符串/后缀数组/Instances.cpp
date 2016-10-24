/*主要参考“后缀数组-处理字符串的有力工具”，论文作者是“罗穗骞”
主要要解决的问题：
1、最长重复出现子串；
2、最长公共子串；
*/
#include"MakeSuffixArray.h"
#include<Windows.h>
#include<string>

int main(void)
{
	string str("aabca");
	string str1("aab");
	str = str + '0' + str1;
	cout << str << endl;
	auto len = str.size();
	int *suff_rank = new int[len]();
	int *suff_array = new int[len]();
	int *height = new int[len]();

	//创建一个排名数组suff[str.size()]
	set_suffix_rank_array(str, suff_rank, len);
	//创建后缀数组，排第几的是谁
	set_suffix_array(suff_rank, suff_array, len);
	//创建高度数组
	set_height_array(str, suff_rank, suff_array, height, len);

	/*求一个字符串中最长重复子串，并输出。
	解题思路：只需求得height中的最大值，并根据height数组中的位置反推出字符串中的位置
	*/
	int pos(0), lengthest = height[0];
	for (unsigned i = 1; i < len-1; i++)
	{
		if (height[i] > lengthest)
		{
			lengthest = height[i];
			pos = i;
		}
	}
	cout <<suff_array[pos]<< " "<<lengthest << endl;
	for (unsigned j = 0; j < lengthest; j++)
	{
		cout << str[suff_array[pos] + j];
	}
	cout << endl;

	/*求最长公共子串的问题
	 解题思路：先将两个字符串前后相连，然后求最长子串，
	 要注意两个子串不在同一字符串中
	*/

	system("pause");
	return 0;
}