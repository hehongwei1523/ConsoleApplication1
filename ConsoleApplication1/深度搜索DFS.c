/*
问题描述

数房子问题

可以遍历二维数组，一旦发现值为1的值，就通过DFS算法将该“房子”全部置0，同时房子计数加一
*/
int m = 5;
int n = 5;
int grid[5][5] = { 
	{ 0,0,0,0,0 },
	{ 0,1,1,0,0 },
	{ 0,0,1,1,0 },
	{ 0,1,0,0,0 },
	{ 0,0,0,0,0 },
};

void dfs(int i, int j)
{
	if (i<0 || i>m - 1 || j<0 || j>n - 1 || grid[i][j] == 0) return;

	grid[i][j] = 0;//置0
	dfs(i, j + 1);
	dfs(i, j - 1);
	dfs(i + 1, j);
	dfs(i - 1, j);
}

int gridsearch()
{
	int res = 0;
	// 遍历m*n的二维数组
	for (int i = 0; i<m; i++)
	{
		for (int j = 0; j<n; j++)
		{
			if (grid[i][j])
			{
				res++;
				dfs(i, j);
			}
		}
	}
	return res;
}

int main_dfs(void)
{
	printf("%d", gridsearch());
}
