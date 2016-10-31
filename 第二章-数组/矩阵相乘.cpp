/*问题描述：两个矩阵的乘法仅当第一个矩阵a行数和另一个矩阵b的列数相等时才能有意义*/
#include<iostream>
#include<Windows.h>

#define Mul(a,b) (a*b)

using namespace std;

/*首先想到了蛮力解法，假设有两个维数为n的矩阵相乘，时间复杂度O(n3)*/

void force_mul_matrix(int **matrix_a, int **matrix_b, int **matrix_c, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				matrix_c[i][j] += Mul(matrix_a[i][k], matrix_b[k][j]);
			}
		}
	}
}
