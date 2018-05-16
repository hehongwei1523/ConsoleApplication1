#include <stdio.h>  
#include <math.h>  
#include "stdlib.h"
#include "stdbool.h"

/*
POJ1837

题意：有一个天平，左臂右臂各长15，然后给出n，m，

n代表有几个挂钩，挂钩给出负数代表在左臂的距离，正数则在右臂
m代表有m个砝码，要你求出使得这个天平保持平衡有几种方法，
要求所有砝码全部使用完

Sample Input:
2 4
-2 3
3 4 5 8

Sample Output:
2

Input
The input has the following structure:
• the first line contains the number C (2 <= C <= 20) and the number G (2 <= G <= 20);
• the next line contains C integer numbers (these numbers are also distinct and sorted in ascending order) 
in the range -15..15 representing the repartition of the hooks; 
each number represents the position relative to the center of the balance 
on the X axis (when no weights are attached the device is balanced and lined up to the X axis; 
the absolute value of the distances represents the distance between the hook and the balance center and
the sign of the numbers determines the arm of the balance to which the hook is attached: '-' for the left arm and '+' for the right arm);

• on the next line there are G natural, distinct and sorted in ascending order numbers in the range 1..25 representing the weights' values.
*/


/*
#define N 2
#define M 4
int s[2] = { -2,3 };
int t[4] = {3,4,5,8};
*/

int dp[25][16000];
int c[25], w[25];

/*
（别人的思路）
思路：首先我们先要明确dp数组的作用，dp[i][j]中，
i为放置的砝码数量，j为平衡状态，0为平衡,j<0左倾，j>0右倾，
由于j作为下标不能是负数，所以我们要找一个新的平衡点，
因为15*20*20 = 7500，所以平衡点设置为7500,
然后我们可以得出动态方程 dp[i][j+w[i]*c[k])+=dp[i-1][j];
*/

void package_main(void)
{
	int n, m, i, j, k;
	while (~(scanf_s("%d%d", &n, &m)))
	{
		for (i = 1; i <= n; i++)
			scanf_s("%d", &c[i]);
		for (i = 1; i <= m; i++)
			scanf_s("%d", &w[i]);
		memset(dp, 0, sizeof(dp));
		dp[0][7500] = 1;
		for (i = 1; i <= m; i++)
		{
			for (j = 0; j <= 15000; j++)
				if (dp[i - 1][j])//一个小小的优化  
					for (k = 1; k <= n; k++)
						dp[i][j + c[k] * w[i]] += dp[i - 1][j];
		}
		printf("%d\n", dp[m][7500]);
	}
}



/*
01背包题目的雏形是：
有N件物品和一个容量为V的背包。第i件物品的体积是c[i]，价值是w[i]。
求解将哪些物品装入背包可使价值总和最大。

从这个题目中可以看出，01背包的特点就是：
每种物品仅有一件，可以选择放或不放。
*/

//我们用f[i][j]表示在前 i 件物品中选择若干件放在已用空间为 j 的背包里所能获得的最大价值
//f[i][j] = max(f[i - 1][j - W[i]] + P[i], f[i - 1][j]);//j >= W[ i ]

//算法
int bag01()
{
#define N 5
#define V 50

	int c[N] = {1,2,3,4,5};
	int w[N] = {2,3,4,5,6};
	int f[N][V] = {0};

	for (int i = 1; i <= N; i++)
		f[i][0] = 0;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= V; j++)
		{
			if (j >= w[i])//背包容量够大
			{
				f[i][j] = max(f[i - 1][j - w[i]] + c[i], f[i - 1][j]);
			}
			else//背包容量不足
			{
				f[i][j] = f[i - 1][j];
			}
		}
	}
	printf("%d \n",f[N][V]);
	return 0;
}

int main()
{
	//package_main();
	bag01();

	return 0;
}