#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int LCSLength(char* str1, char* str2, int (*b)[100])
{
	int i, j, length1, length2, len;
	length1 = strlen(str1);
	length2 = strlen(str2);

	//双指针的方法申请动态二维数组
	int **c = malloc(sizeof(int) * (length1 + 1)); //共有length1+1行
	for (i = 0; i < length1 + 1; i++)
		c[i] = (int *)malloc(sizeof(int) * (length2 + 1));//共有length2+1列


	for (i = 0; i < length1 + 1; i++)
		c[i][0] = 0;        //第0列都初始化为0
	for (j = 0; j < length2 + 1; j++)
		c[0][j] = 0;        //第0行都初始化为0

	for (i = 1; i < length1 + 1; i++)
	{
		for (j = 1; j < length2 + 1; j++)
		{
			if (str1[i - 1] == str2[j - 1])//由于c[][]的0行0列没有使用，c[][]的第i行元素对应str1的第i-1个元素
			{
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = 0;          //输出公共子串时的搜索方向
			}
			else if (c[i - 1][j]>c[i][j - 1])
			{
				c[i][j] = c[i - 1][j];
				b[i][j] = 1;
			}
			else
			{
				c[i][j] = c[i][j - 1];
				b[i][j] = -1;
			}
		}
	}
	/*
	for(i= 0; i < length1+1; i++)
	{
	for(j = 0; j < length2+1; j++)
	printf("%d ",c[i][j]);
	printf("\n");
	}
	*/
	len = c[length1][length2];
	/*
	for (i = 0; i < length1 + 1; i++)    //释放动态申请的二维数组
		free(c[i]);
	free(c);
	*/
	return len;
}
void PrintLCS(int (*b)[100], char *str1, int i, int j)
{
	if (i == 0 || j == 0)
		return;
	if (b[i][j] == 0)
	{
		PrintLCS(b, str1, i - 1, j - 1);//从后面开始递归，所以要先递归到子串的前面，然后从前往后开始输出子串
		printf("%c", str1[i - 1]);//c[][]的第i行元素对应str1的第i-1个元素
	}
	else if (b[i][j] == 1)
		PrintLCS(b, str1, i - 1, j);
	else
		PrintLCS(b, str1, i, j - 1);
}


int main_LCS(void)
{
	char str1[100], str2[100];
	int i, length1, length2, len;
	printf("请输入第一个字符串：");
	gets(str1);
	printf("请输入第二个字符串：");
	gets(str2);
	length1 = strlen(str1);
	length2 = strlen(str2);

	int b[100][100] = { 0 };
	/*
	//双指针的方法申请动态二维数组
	int **b = malloc(sizeof(int) * (length1 + 1)); //共有length1+1行
	for (i = 0; i < length1 + 1; i++)
		b[i] = (int *)malloc(sizeof(int) * (length2 + 1));//共有length2+1列
	*/	

	len = LCSLength(str1, str2, &b[0]);
	printf("最长公共子序列的长度为：%d\n", len);
	printf("最长公共子序列为：");
	PrintLCS(b, str1, length1, length2);
	printf("\n");

	return 0;
}
