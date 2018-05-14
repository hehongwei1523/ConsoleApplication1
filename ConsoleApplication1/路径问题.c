#include <stdio.h>  
#include <math.h>  
#include "stdlib.h"
#include "stdbool.h"

/*
����

һֻĸţ��N�����е���һ��(1��N��1000)ȥ�μ�ʢ���ĸţ�ۻᣬ����ۻᱻ������X����(1��X ��N)��һ����M(1 �� M �� 100,000)�����е��ֱ��������������ͨ��·i��Ҫ��Ti(1��Ti��100)��ʱ�䡣

ÿͷĸţ����μ���Ტ����������ʱ�ص��Լ�����أ�����ÿͷţ��������ϲ��ѡ�������ٵ�һ����������ʱ��·��ȥʱ�Ŀ��ܲ�һ����

��ÿͷţҪ���ص����ʱ�䡣

����

��һ�У������ÿո�ֿ�������:N,M��X
��2����M+1��:��i+1����·i��ͨ�������ÿո�ֿ�������: Ai, Bi��Ti. �Ƕ��ڴ�Ai���ﵽ Bi���������,��ҪTi��ʱ��.

���

��һ��:һ������:����ţ������ʱ��������Ǹ���
*/
#define  N  4 //�����������
#define  X  2 //Ŀ����ı��
#define  M  8 //���е�·

int Mi[8][3] = //{Ai, Bi, Ti}
{
	//{4, 8, 2},
	
	{1, 2, 4},
	{1, 3, 2},
	{1, 4, 7},
	{2, 1, 1},
	{2, 3, 5},
	{3, 1, 2},
	{3, 4, 4},
	{4, 2, 3},
/*	
{1, 2, 10},
{2, 1, 1 },
{1, 3, 4 },
{3, 1, 6 },
{4, 1, 2 },
{3, 4, 4 },
{2, 3, 3 },
{3, 2, 1 },
*/
};

/*
����

��һ�У�
�����ÿո�ֿ�������:N,M��X

��2����M+1��:
��i+1����·i��ͨ�������ÿո�ֿ�������: Ai, Bi��Ti. 
�Ƕ��ڴ�Ai���ﵽ Bi���������,��ҪTi��ʱ��.
*/
int load[100] = { 0 };

int result[2][100] = { 0 };
int result_time = 0;

int hasrun[100] = { 0 };
int run_time = 0;

void hasrun_0(void)
{
	run_time = 0;
	for (int i = 0; i < N; i++)
	{
		hasrun[i] = -1;
	}
}

int hasntrun(int find)
{
	for (int i = 0; i < 10; i++)
	{
		if (hasrun[i] == find)
		{
			return 0;
		}
	}
	return 1;
}

void result_insulate(void)
{
	result[result_time][0] = 0;
	result[result_time][1] = 0;
	result_time++;
}
void result_parse(void)
{
	/*
	int i = 0;
	static int min = 0;

	for (i = 0; i < 100; i++)
	{
		if (result[i][0] != 0)
		{
			
			min = result[i][0];
			if (result[i][0] < min)
			{
				min = result[i][0];
			}
		}
		else
		{
			i++;
			continue;
		}
	}
	*/
}

int find(int A[][3], int i, int sour, int dest,int num)
{
	int sum = 0; 
	//printf(" ++i = %d++ \n", i);
	load[num++] = i;

	if (A[i][1] == dest)
	{
		for (int j = 0; j < num; j++)
		{
			//printf("i = %d \n", load[j]);
			sum = sum + A[load[j]][2];
		}
		//printf("num = [%d] sum = [%d] \n", num,sum);

		result[result_time][0] = num;
		result[result_time][1] = sum;

		printf(" [%d][%d] \n", result[result_time][0], result[result_time][1]);
		
		result_time++;
        num = 0;
		hasrun_0();
		return 1;
	}
	else
	{
		for (int j = 0; j < M; j++)
		{
			if ((A[j][0] == A[i][1]) && hasntrun(A[j][0]) && (sour != A[j][1]) ) //
			{
                hasrun[run_time++] = A[j][0];

				if (find(A, j, sour, dest, num) != 1)
				{
					hasrun_0();
				}
			}
		}	
	}
}

void load_main1(char * argc, int argv)
{
   int i = 0, j = 0;

	/*
	ȥ�̵�·��ѡ��
	*/

	/*
	�س̵�·��ѡ��
	*/
}

void load_function_dest(int dest)
{
	int i = 0,j = 0;
	int start = 0;

	if ((dest > N) || (dest < 1))
	{
		printf("error \n");
		return;
	}
	
	for (i = 0; i < N; i++)
	{
		start++;
		if (start == dest) continue;

		printf("\n\n start(%d) -> dest(%d): \n",start,dest);
		for (j = 0; j < M; j++)
		{
			if ( Mi[j][0] == start )
			{
				find(Mi, j, start, dest, 0);
			}
		}
	}
}

void load_function_start(int start)
{
	int i = 0, j = 0;
	int dest = 0;

	if ((start > N) || (start < 1))
	{
		printf("error \n");
		return;
	}

	for (i = 0; i < N; i++)
	{
		dest++;
		if (start == dest) continue;

		printf("\n\n start(%d) -> dest(%d): \n", start, dest);
		for (j = 0; j < M; j++)
		{
			if (Mi[j][0] == start)
			{
				find(Mi, j, start, dest, 0);
			}
		}
	}
}

void load_main()
{
	
#if 0
	//for (int i = 4; i <= 4; i++) 
	{
		for (int j = 0; j < M; j++)
		{
			if (Mi[j][0] == 3)
			{
				find(Mi, j, 3, 4, 0);
			}
		}
	}
#elif 0

	for (int i = 1; i <= 4; i++)
	{

		load_function_dest(i);
	}
#else
    load_function_dest(2);
	load_function_start(2);
#endif

	
}