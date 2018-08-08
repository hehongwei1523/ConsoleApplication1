#include "stdafx.h"
#include <stdlib.h>
#include "stdafx.h"
#include "string.h"
#include "stdio.h"

/*
ľ��
Time Limit: 1000MS		Memory Limit: 10000K
Total Submissions: 153522		Accepted: 36609

Description
��������һ��ȳ���ľ��������������ؿ��ϣ�ʹ��ÿһ��ľ���ĳ��ȶ�������50�����ȵ�λ��Ȼ�����������Щľ���ָ���Ϊ�ý�ǰ��״̬���������˳�ʼʱ�ж���ľ���Լ�ľ���ĳ�ʼ���ȡ��������һ�����򣬰������μ���ľ���Ŀ�����С���ȡ�ÿһ��ľ���ĳ��ȶ��ô������������ʾ��

Input
��������������ݣ�ÿ�����ݰ������С���һ����һ��������64����������ʾ����֮���ж��ٽ�ľ�����ڶ����ǽض��Ժ����õ��ĸ���ľ���ĳ��ȡ������һ������֮����һ���㡣

Output
Ϊÿ�����ݣ��ֱ����ԭʼľ���Ŀ�����С���ȣ�ÿ������ռһ�С�

Sample Input
9
5 2 1 5 2 1 5 2 1
4
1 2 3 4
0

Sample Output
6
5
*/
int dfs1(int A[], int index, int len, int X, int U[], int N)
{
	int i = 0; int w = 0; 

	if (index == N)
		return 1;
	for (i = index; i < len; i++)
	{
		if (U[i] == 0)
		{
			w = w + A[i];
			if (w < X)
			{
				U[i] = 1;
			}
			else if (w == X)
			{
				U[i] = 1; 
				index++;
				dfs1(A, index, len, X, U, N);
			}
			else
			{
				w = w - A[i];
			}
		}
	}
}

#define WOOD_MAX 100
void P1011()
{
	char p[WOOD_MAX] = { 0 };// "5 2 1 5 2 1 5 2 1";
	//gets(p);
	//int n = atof(p);
	//printf("%d", n);
	gets(p);
	p[strlen(p)] = ' ';

	int i = 0, j = 0, k = 0;
	int min = 50, max = 0, sum = 0;
	char g[3] = { 0 };
	int dest[WOOD_MAX] = { 0 };

	for (i = 0; i <= strlen(p); i++)
	{
		char temp = p[i];

		if (temp != ' ')
		{
			g[k++] = temp;
			//printf("%c", g[k - 1]);
		}
		else
		{
			g[k] = '\0';
			dest[j++] = atof(g);
			memset(g, 0, 3);
			k = 0;
		}
	}
	for (i = 0; i < j; i++)
	{
		//printf("%d ",dest[i]);
		if (min > dest[i])
			min = dest[i];
		if (max < dest[i])
			max = dest[i];
		sum = sum + dest[i];
	}
	//printf("%d , %d, %d\n",min, max, sum);

	int A[9] = { 5,5,5,2,2,2,1,1,1 };
	int B[9] = { 0 };
	for (i = max+1; i <= sum; i++)
	{
		if (sum % i == 0)
		{
			//printf("\n=%d\n", i);
			//printf("-%d", dfs1(A,0, 9, i, B));
			if (dfs1(dest, 0, j, i, B, sum/i))
			{
				printf("%d", i);
				return ;
			}
		}
	}
	//printf("%d", min + max);
}

int AA[11] = { 0 };

int t(int len, int n, int j, int B[])
{
	int i = 0, k = 1;
	if (j == n) return 1;
	int *C = malloc(sizeof(int) * len);

	for (i = 1; i<=len; i++)
	{
		if (i % 2 == 1)
			AA[j++] = B[i];
		else
			C[k++] = B[i];
	}
	t( k-1, n,j,C);
}

void test_()
{
	int n = 0; 
	int X[100] = { 0 };

	scanf_s("%d", &n);

	int *B = malloc(sizeof(int) * n);
	for (int i = 0; i <= n; i++)
		B[i] = i;

	t(n, n+1, 1, B);

	for (int i = 1; i <= n; i++)
	{
		//printf("%d ", AA[i]);
		X[AA[i]] = i;
	}
	printf("\n");
	for (int i = 1; i <= n; i++)
		printf("%d ", X[i]);
}

int main_poj(void)
{
	test_();
	//P1011();
	return 0;
}