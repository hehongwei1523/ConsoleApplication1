#include <stdio.h>  
#include <math.h>  
#include "stdlib.h"
#include "stdbool.h"

/*
动态规划通常是用来求解最优化问题。

步骤：
1、刻画一个最优解的结构特征
2、递归地定义最优解的值
3、计算最优解的值，通常采用自底向上的方法
4、利用计算出得信息构造一个最优解
*/

/*
15.1 钢铁切割

给定一段长度为n英寸的钢条和一个价格表pi(i=1,2,...,n),
求切割钢条方案，使得销售收益rn最大。

长度i   1   2   3   4   5   6   7   8   9   10
价格pi  1   5   8   9   10  17  17  20  24  30
*/
int LP[][2] = {
	{ 1,1 },{ 2,5 },{ 3,8 },{ 4,9 },{ 5,10 },
	{ 6,17 },{ 7,17 },{ 8,20 },{ 9,24 },{ 10,30 },
};

int Price[] = {0,1,5,8,9,10,17,17,20,24,30};

/*
n: 长度为n的钢条
p[]: 对应价格
*/
int CUT_ROD(int p[], int n)
{
	if (n == 0)
	{
	    return 0;
	}
	int q = 0;
	for (int i = 1; i <= n; i++)
	{
		q = max(q, p[i] + CUT_ROD(p, n - i));
	}
	return q;
}

/*
动态规划优化：
1、带备忘的自顶向下法
2、自底向上法
*/

int MEMOIZED_CUT_ROD(int p[], int n)
{
	int * r = malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		r[i] = -1;
	}
	return MEMOIZED_CUT_ROD_AUX(p, n, r);
}

int MEMOIZED_CUT_ROD_AUX(int p[], int n, int r[])
{
	int q = 0;

	if (r[n] >= 0)
	{
		return r[n];
	}
	if (n == 0)
	{
		q = 0;
	}
	else
	{
		q = -1;
		for (int i = 1; i <= n; i++)
		{
			q = max(q, p[i] + MEMOIZED_CUT_ROD_AUX(p, n - i, r));
		}
	}
	r[n] = q;
	return q;
}

int BOTTOM_UP_CUT_ROD(int p[], int n)
{
	int * r = malloc(n * sizeof(int));
	r[0] = 0;

	for (int j = 1; j <= n; j++)
	{
		int q = -1;
		for (int i = 1; i <= j; i++)
		{
			q = max(q, p[i] + r[j - i]);
		}
		r[j] = q;
	}
	return r[n];
}

int * EXTENDED_BOTTOM_UP_CUT_ROD(int p[], int n, int *R[], int *S[])
{
	int *r = malloc(sizeof(int) * n);
    int *s = malloc(sizeof(int) * n);

	r[0] = 0;
	int i = 0, j = 0;
	for (j = 1; j <= n; j++)
	{
		int q = -1;
		for (i = 1; i <= j; i++)
		{
			if (q < p[i] + r[j - i])
			{
				q = p[i] + r[j - i];
				s[j] = i;
			}
		}
		r[j] = q;
	}
	
	*R = r;
	*S = s;

	/*
	printf("%p \n",&R);
	for (int i = 1; i <= 13; i++)
	{
		printf("A[%d] = %d , B[%d] = %d  \n", i, R[i], i, S[i]);
	}
	*/
	return r;
}

void PRINT_CUT_ROD_SOLUTION(int p, int n, int *R[], int *S[])
{
	EXTENDED_BOTTOM_UP_CUT_ROD(Price, 13, &R, &S);

	int *r = R;
	int *s = S;

	while (n > 0)
	{
		printf("s[%d] = %d \n",n,s[n]);
		n = n - s[n];
	}
}

int cutrod_main(void)
{
	printf("max1 = %d \n", CUT_ROD(Price, 13));

	printf("max2 = %d \n", MEMOIZED_CUT_ROD(Price, 13));

	printf("max3 = %d \n", BOTTOM_UP_CUT_ROD(Price, 13));

	int *R = NULL, *S = NULL;
	/*
	int *a = EXTENDED_BOTTOM_UP_CUT_ROD(Price, 13, &R, &S);
	printf("max4 = %d \n", a[13]);

	for (int i = 1; i <= 13; i++)
	{
		printf("R[%d] = %d , S[%d] = %d  \n",i,R[i],i,S[i]);
	}
	*/
	PRINT_CUT_ROD_SOLUTION(Price, 13, &R, &S);
}


/*
矩阵链乘法：

给定一个n个矩阵的序列（矩阵链）<A1,A2,..,An>，计算乘积
A1A2...An
*/

int **MATRIX_MULTIPLY(int (*A)[3], int Arows, int Acolumns, int (*B)[2], int Brows, int Bcolumns)
{
	int **C = NULL;

	if (Bcolumns != Arows)
	{
		printf("error \n");
		return 0;
	}
	else
	{
		C = (int **)malloc(sizeof(int) * Arows);
	    for (int i = 0; i < Arows; i++)
		{
			C[i] = (int *)malloc(sizeof(int) * Bcolumns);
		}
		
		/*C = (int **)malloc(sizeof(int) * Arows * Bcolumns);*/

		for (int i = 0; i < Arows; i++)
		{
			for (int j = 0; j < Bcolumns; j++)
			{
				C[i][j] = 0;
				for (int k = 0; k < Acolumns; k++)
				{
					C[i][j] += A[i][k] * B[k][j];
				}
			}
		}
	}

	for (int i = 0; i < Arows; i++)
	{
		printf("\n");
		for (int j = 0; j < Bcolumns; j++)
		{
			printf("%d ", C[i][j]);
		}
	}
	return C;
}

void matrix_main(void)
{
#define R  2
#define C  3

	int A[R][C] = { 
		{ 1,2,3 },
		{ 4,5,6 },
	};

	int B[C][R] = {
		{ 1,2 },
		{ 3,4 },
		{ 5,6 },
	};

	//int T[2][2] = {0};
	int **T = NULL;

	T = MATRIX_MULTIPLY(A,R,C,B,C,R);

}

/*
15.3  动态规划原理

问题两个要素： 最优子结构、子问题重叠

最优子结构性质： 问题的最优解包含其子问题的最优解
*/



int main33(void)
{
	matrix_main();
}