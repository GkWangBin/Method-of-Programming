/*��Ŀ����һ������Ϊ2n������{a1, a2,a3,...,an, b1, b2, b3,..., bn},
*ϣ�����������{a1,b1,a2,b2,...,an,bn}���뿼����û��ʱ�临�Ӷ�ΪO(n)
*���ռ临�Ӷ�ΪO(1)�Ľⷨ������ϴ�Ƽ����ȵĴ���
*/

#include<iostream>
#include<Windows.h>

using namespace std;

extern void swap(int *a, int *b);
//����ʹ�����������ķ�����ʱ�临�Ӷ�ΪO(2n),�ռ临�Ӷ�ΪO(1)
void force_swap(int arr[], int n)
{
	for (int i = 1, j=n+1; i < n, j<2*n; i+=2,j+=2)
	{
		swap(arr + i, arr + j);
	}
}
