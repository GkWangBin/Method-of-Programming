#include<string>
#include<iostream>
#include<algorithm>
#include<map>
#include<set>
#include<array>
#include<vector>
#include<forward_list>

/*1.字符串反转：实现字符串反转函数
 *时间复杂度为O(n)
 */
void reverse_string(std::string &str)
{
	std::string::size_type len = str.size();
	auto i = len - len;

	for ( i; i < len-i-1; i++)
	{
		std::swap(str[i], str[len - i - 1]);
	}
}

/*2、字符串的左右移动：给定一个字符串，这个字符串为*号和26个字母的任意组合。
 *现在需要把字符串中的*号都yi动到最左侧，而把字符串中的字母移动到最右侧
 *并保持相对顺序不变，要求时间复杂度和空间复杂度最小
 *首先想到了快排的方式，但是快排是不稳定的排序，有可能改变排序后字符的相对顺序
 *可以使用冒泡的方式，将字符串中的*号放到字符串的前边.时间复杂度为O(n2)
 */
void bubble_forward(std::string &str)
{
	auto len = str.size();
	for (auto j = len-len; j < len; j++)
	{
		bool swap_flag = false;//立flag，如果已经有序及时终止。
		for (auto i = len - 1; i>j; i--)
		{
			while (str[i]!='*' && i >j)
			{
				i--;
			}
			if (str[i]=='*' && i> j)
			{
				std::swap(str[i], str[i - 1]);
				swap_flag = true;
			}
		}//for (auto i = len - 1; i>j; i--)
		if (!swap_flag)
		{
			break;
		}
	}

}
/*3、字符个数的统计：给定一个字符串，写一个函数，查找出该字符串中
 *每个字符串出现的次数，要求区分大小写，且时间复杂度为O(n)
 *两种思路，一使用map容器，二使用一个26大小的数组*/ 

void statics_by_map(const std::string str)
{
	std::map<char, int> cmap;
	auto len = str.size();

	/*如果字符在map中则将其value+1
	 *否则将该字符插入到map中，并将value初始化为1*/
	for (auto i = len-len; i < len; i++)
	{
		if (cmap.find(str[i])!=cmap.cend())
		{
			cmap[str[i]]++;
		}
		else
		{
			cmap[str[i]] = 1;
		}
	}

	/*将字符串中字符个数打印出来*/
	for (auto iter = cmap.cbegin(); iter != cmap.cend(); iter++)
	{
		std::cout << iter->first << ":" << iter->second << std::endl;
	}
}
/*用数组实现的话区分不出来大小写，如果有特殊字符的话判断不出来
void statics_by_array(const std::string str)
{
	int arr[26]{0};
	auto len = str.size();

	for (auto i = len-len; i < len; i++)
	{
		arr[str[i] - 'a'] ++;
	}
}
*/

/*4、字符串的匹配：类似与正则表达式的匹配方式
 *例如“j*Smi??”可以匹配“Join Smith”
 *匹配规则：人名使用26个英文字母(可以是大小写)、空格及两个通配符(*和?)组成。
 *通配符*表示0或多个任意字符，?表示一个任意字符。
 */


void match_string(const std::string str, const std::string pattern)
{
	unsigned int pos(0), i(0), j(0);

	while (str[i] != '\0' && pattern[j] != '\0')
	{
		pos = i;//假如匹配错误，pattern从头部再匹配的
		while (pattern[j] != '\0' && str[i] != '\0')
		{
			switch (pattern[j])
			{
			case '?':
				i++; j++; break;
			case '*':
				while (str[i] != '\0' && str[i + 1] != pattern[j + 1])
				{
					i++;
				}
				j++; break;
			case '\0': break;
			default:
				while (str[i] == pattern[j] && pattern[j] != '\0')
				{
					i++;
					j++; 
				}
				while (pattern[j] != '*' && pattern[j] != '?' && 
					str[i] != pattern[j] && str[i] != '\0' && pattern[j] != '\0')
				{
					i++;
				}
				break;
			}
		} // while (pattern[j] != '\0') 
		
		if (pattern[j] != '\0' && str[i] != '\0')
		{
			i = pos + 1;
			j = 0;
		}
	}//while (str[i] != '\0')

	if (str[i] == '\0' && pattern[j] != '\0')
	{
		std::cout << "No matched" << std::endl;
	}
	else
	{
		std::cout << "Matched" << std::endl;
	}	
}

/*5、字符串空格的压缩：给定一个字符串，将其中连续出现的空格压缩为1个后，
 *将其中以空格分割的每个字符串逆序打印出来*/
/*reverse_string()函数将str中从from到下个空格的字符串逆序*/
unsigned int reverse_string(std::string &str, unsigned int from)
{
	auto to=from;
	while (str[to+1] != ' ' && str[to+1] != '\0')
		to++;
	auto pos = to;
	while (from < to)
	{
		std::swap(str[from], str[to]);
		from++;
		to--;
	}
	return pos;
}
/*impress_space()函数负责处理连续的空格*/
void impress_space(std::string &str,unsigned int space_pos)
{
	auto pos = space_pos;
	int count;
	//char tmp;

	while (str[pos] == ' ')
	{
		pos++;
	}
	count = pos - space_pos;
	if (count > 1)
	{
		while (str[pos] != '\0')
		{
			str[pos - count + 1] = str[pos];
			pos++;
		}
		//需要对剩余字符进行处理,负责std::cout还会将'/0'之后的字符输出
		for (auto i = pos - count + 1; i <= pos;i++)
			str[i] = '\0';
	}
}
void impress_vs_reverse(std::string &str)
{
	unsigned int from(0);
	
	while (str[from = reverse_string(str,from)+1] == ' ')
	{
		impress_space(str, from);
		from = from + 1;
	}
}

/*6、重复字符的压缩：
 *通过键盘输入一串小写字母组成的字符串。请写一个字符串压缩程序，
 *对字符串中连续出现的重复字母进行压缩，并按照要求输出压缩后的字符串。
 *类似于上题中压缩空格。
 */
/*处理单一重复的字符*/
void impress_uniqchar(std::string &str, unsigned int pos)
{
	auto p = pos +1 ;
	unsigned int count(0);
	while (str[pos] == str[p] && str[p] != '\0')
	{
		p++;
	}
	count = p - pos;
	str[pos] = count + '0';
	pos = pos + 2;
	if (pos != p)
	{
		while (str[p] != '\0')
		{
			str[pos] = str[p];
			pos++; p++;
		}

		for ( ; pos < p; pos++)
		{
			str[pos] = '\0';
		}
	}//if (pos != p)
}
/*压缩字符串主程序*/
void impress_string(std::string str)
{
	std::cout << "Before impress:" << str << std::endl;
	for (unsigned int i = 0; i < str.size();)
	{
		if (str[i+1] != '\0' && str[i]==str[i+1])
		{
			impress_uniqchar(str, i);
			i += 2;
		}
		/*如果字符没有重复就跳过*/
		else
		{
			i++;
		}
	}
	std::cout << "After impress:" << str << std::endl;
}

/*7、第一个只出现一次的字符，在一个字符串中找到第一个只出现一个的字符
*解题思路：顺序扫描字符串，以字符为关键字将其添加到map<char,int> map中，
*如果map中关键字已经存在，则将value加1.最后扫描map将第一个value值为1的
*map->first输出.时间复杂度为O(n).
*/
void find_first_onlyone(const std::string str)
{
	std::map<char, int> cmap;
	unsigned int p(0);
	for ( p; p < str.size(); p++)
	{
		if (cmap.find(str[p]) != cmap.cend())
			cmap[str[p]]++;
		else
		{
			cmap[str[p]] = 1;
		}
	}

	/*输出第一个value为1的字符*/
	for (auto iter = cmap.cbegin(); iter != cmap.cend(); iter++)
	{
		if (iter->second == 1)
		{
			std::cout << iter->first << std::endl;
			break;
		}
	}
}

/*8、删除特定的字符：
*给定一个原始字符串和模式字符串，要求在原始字符串中删除所有在模式字符串中
*出现过的字符，对应位置用空格占位。要求性能最优
*时间复杂度为O(m*n)
*/
void delete_special_char(std::string &str,const std::set<char> cset)
{
	unsigned int p(0);
	for ( p = 0; p < str.size(); p++)
	{
		if (cset.find(str[p]) != cset.cend())
		{
			str[p] = ' ';
		}
	}
}

/*9、字符串集合的合并：给定一些字符串的集合，要求将其中交集不为空的集合合并，
 *且合并完成后的集合之间无交集。
 *解题思路：这种不想交集合的合并及查询问题，可以考虑使用并查集解决。
 *解题方法：考虑使用set的特性来做该题。
*/ 
//判断两个set中是否有共同元素，直接判断两个几个的size和是否大于合并后的集合和值。
bool same_str( std::set<std::string> set_1,
	std::set<std::string> set_2)
{
	auto size_1 = set_1.size() + set_2.size();
	set_1.insert(set_2.begin(), set_2.end());

	if (size_1 > set_1.size())
	{
		return true;
	}
	return false;
}

//首先判断两个集合是否有交集，如果有将后者合并到前者，并将后者标识符置0.
void merge(std::vector<std::pair<int,std::set<std::string>>> &svector)
{
	for (auto viter_1 = svector.begin(); viter_1 != svector.end(); viter_1++)
	{
		if (viter_1->first == 1)
		{
			for (auto viter_2 = svector.end()-1; viter_2 > viter_1;viter_2--)
			{
				if (viter_2->first == 1 && same_str(viter_1->second,
					viter_2->second))
				{
					//将set2合并到set1中，并将set2的标识符标记为0；
					viter_1->second.insert(viter_2->second.begin(), 
						viter_2->second.end());
					viter_2->first = 0;
				}
			}
		}//if (viter_1->first == 1)
	}

	//将合并后的集合打印出来
	for (auto iter = svector.begin(); iter != svector.end(); iter++)
	{
		if (iter->first == 1)
		{
			for (auto s_iter = iter->second.begin(); s_iter != iter->second.end(); s_iter++)
			{
				std::cout << *s_iter << " ";
			}
			std::cout << std::endl;
		}
	}
}

/*10.集合的差集：已知集合A和集合B的元素分别用不含头结点的单项链表存储，求集合A与集合B的差集，
 *并将结果保存在集合A的单项链表中*/
/*考虑一个问题，使用STL容器后，删除一个元素导致迭代器失效的问题
 *可以使用单链表中的remove()成员函数，进行删除 */
void subset(std::forward_list<int> &A, std::forward_list<int> B)
{
	for (auto iter = B.cbegin(); iter != B.cend(); iter++)
	{
		A.remove(*iter);
	}
}

/*11、最小子串：给一篇文章，这边文章由一个个单词组成的，单次之间用空格隔开。
 *再给一个字符串指针数组，求给定文章中包含这个字符串指针数组的最短字符串。
 *问题，怎么找出来最短的一个匹配？
 *首先判断子字符串是否在文章中；
 *然后再寻找最短字符串
 */

void shortest_str_of_artical(const std::vector<std::string> string,const char *substr[])
{

}

/*12、最长连续字符：用递归算法写出一个函数，求字符串最长连续字符的长度
 *时间复杂度为O(n)，即递归的扫描完一遍字符串。该函数没有判断字符串为空的情况
 */
int cacl_length_by_recursion(const std::string str,int &pos, int &max)
{
	//如果前后字符一样，则计算其重复的长度，并记录最大值
	int len = 1;
	while (str[pos] == str[pos + 1] && str[pos + 1] != '\0')
	{
		len++;
		pos++;
	}
	if (len > max)
	{
		max = len;
	}
	//递归函数出口，整个字符串扫描完一遍
	if (str[pos + 1] == '\0')
	{
		return max;
	}
	//向后移动到一个不重复的字符，递归
	pos++;
	cacl_length_by_recursion(str, pos, max);
}

/*13题：最长重复出现子串：给定一个字符串，求出其最长的重复子串。
 *例如，输入abczzacbca，输出结果是“bc”。
 *提示：可以使用后缀数组，对一个字符串生成相应的后缀数组后，再排序，
 *排完序一次检测相邻的两个字符串开头的公共部分。
 */
void longest_repetition_substr(std::string str)
{

}
int main(void)
{
	//std::string str("aadefffghodooo");
	//std::set<char> cset = { 'a', 'e', 'i', 'o', 'u' };

	//reverse_string(str);
	//bubble_forward(str);
	//reverse_string(str, 0);
	//impress_space(str, 0);
	//impress_vs_reverse(str);
	//std::cout << str << std::endl;
	/*
	std::string str("aadefffghodooo");
	std::string pattern("?o");
	match_string(str, pattern);
	*/

	//statics_by_map(str);
	//impress_string(str);
	//find_first_onlyone(str);
	//std::cout << str << std::endl;

	/*
	std::string str("aadefffghodooo");
	std::set<char> cset = { 'a', 'e', 'i', 'o', 'u' };
	delete_special_char(str, cset);
	std::cout << str << std::endl;
	*/

	/*初始化包含多个pair的vector，将pair中的first初始化为1，当被merge之后将first改为0；
	//std::vector<std::pair<int, std::set<std::string>>>
	//svector{ { 1, { "aaa", "bbb", "ccc" } },{ 1, { "bbb", "ddd" } },
	//{ 1, { "eee", "fff" } }, { 1, { "ggg" } }, { 1, { "ddd", "hhh" } } };
	std::vector<std::pair<int, std::set<std::string>>>
	svector{ { 1, { "aaa", "bbb", "ccc" } } };
	merge(svector);
	*/
	/*10题：
	std::forward_list<int> A{5,10,20,15,25,30}, B{5,15,35,25};
	subset(A, B);
	for (auto iter = A.cbegin(); iter !=A.cend(); iter++)
	{
		std::cout << *iter << " ";
	}
	*/
	/*
	char *str[]{"hello", "world", "good"};
	std::vector<std::string> svector;
	shortest_str_of_artical(svector,str);
	*/
	/*12th
	std::string str("aaabbbddddferggg");
	int max = 0;
	int pos = 0;
	cacl_length_by_recursion(str, pos, max);
	std::cout << max<<std::endl;
	*/

	std::string str("abczzacbca");

	system("pause");
	return 0;
}