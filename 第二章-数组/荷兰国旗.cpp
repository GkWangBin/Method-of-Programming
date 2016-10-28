/*问题：荷兰国旗，现有n个红白蓝三种不同颜色的小球，乱序排列在一起，
*请通过两两交换任意两个球，使得从左至右的球依次是红、白、蓝。
*/
#include<iostream>
#include<Windows.h>

using namespace std;
/*解题思路:很容易想到的就是快排的划分过程，可以预设三个指针，从前往后的指针
*begin，当前判断的指针current，还有个从后向前的指针end,分三步解题：
*(1)当current指针所指元素为0时，与begin指针所指的元素交换，current++，begin++；
*（2）当current指针所指元素为1时，不做任何交换，而后current++；
*(3)当current指针所指元素为2时，与end指针所指元素交换，而后current指针不动，end--；
*/
extern void swap(int *a, int *b);

void holland_flag(int arr[], int n)
{
	if (n < 2) return;

	int begin(0), current(0), end(n - 1);
	while (current <= end)
	{
		if (arr[current] == 0)
		{
			swap(arr + current, arr + begin);
			current++;
			begin++;
		}
		else if (arr[current] == 1)
		{
			current++;
		}
		//如果在第一次循环中，end指的是最后一个元素并且arr[end]==2,
		//那么该值会被换到中间，然后再将该值换到end--的位置
		else if (arr[current] == 2)
		{
			swap(arr + current, arr + end);
			end--;
		}
	}//while (current <= end)
}

int main(void)
{
	int arr[]{0, 1, 2, 2, 2, 0, 0, 1, 1, 0};
	int len = 10;
	holland_flag(arr, len);

	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}