/*
15-4  整齐打印

考虑在一个打印机上整齐地打印一段文章的问题。
输入的正文是n个长度分别为L1,L2,…,Ln（以字符个数度量）的单词构成的序列。
我们希望将这个段落在一些行上整齐地打印出来，每行至多M个字符。
“整齐度”的标准如下：如果某一行包含从i到j的单词(i<j)，且单词之间只留一个空格，
则在行末多余的空格字符个数为 M−(j−i)−(Li+⋯+Lj)，它必须是非负值才能让该行容纳这些单词。
我们希望所有行（除最后一行）的行末多余空格字符个数的立方和最小。
请给出一个动态规划的算法，来在打印机整齐地打印一段又n个单词的文章。
分析所给算法的执行时间和空间需求。
*/

#define M 10//一行的最大长度  
#define N 10//单词的个数  

int s[N][N] = { 0 };

void DP(int *len)
{
	int i, j, k, step, temp;
	for (step = 0; step < N; step++)
	{
		for (i = 0; i < N; i++)
		{
			temp = 0; j = i + step;
			if (j >= N)
				break;
			//计算len[i,j]  
			for (k = i; k <= j; k++)
			{
				if (k != i) temp++;
				temp = temp + len[k];
				if (temp > M)
					break;
			}
			if (temp > M)
			{
				s[i][j] = 0x7fffffff;
			}
			//若f[i,j] > 0 && j==n，则len[i,j] = 0  
			else if (j == N - 1) 
			{
				s[i][j] = 0;
			}
			//若i==j，则len[i,j] = (f[i,j])^3  
			else {
				s[i][j] = pow(M*1.0 - temp, 3);
			}
			//若f[i,j] < 0,，则len[i,j] = MIN(len[i,k] + len[k+1,j]) , i<=k<j  
			for (k = i; k < j; k++)
			{
				if (s[i][k] + s[k + 1][j] < s[i][j])
					s[i][j] = s[i][k] + s[k + 1][j];
			}
		}
	}
	//printf("%d ", s[N-1][N - 1]);
}

void Print()
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			printf(" %d \n", s[i][j]);
	}
}
/*1 2 3 1 2 3 1 2 3 1*/
int main_p()
{
	int len[N] = {1,2,3,1,2,3,1,2,3,1};
	//输出数据  
	/*
	for (int i = 0; i < N; i++)
		printf("%d ", len[i]);
	*/
	 
	DP(len);
	Print();

	return 0;
}

int printf_main()
{
	


}
