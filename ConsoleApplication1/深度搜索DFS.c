/*
��������

����������

���Ա�����ά���飬һ������ֵΪ1��ֵ����ͨ��DFS�㷨���á����ӡ�ȫ����0��ͬʱ���Ӽ�����һ
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

	grid[i][j] = 0;//��0
	dfs(i, j + 1);
	dfs(i, j - 1);
	dfs(i + 1, j);
	dfs(i - 1, j);
}

int gridsearch()
{
	int res = 0;
	// ����m*n�Ķ�ά����
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
