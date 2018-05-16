#include <stdio.h>  
#include <math.h>  
#include "stdlib.h"
#include "stdbool.h"

void function_1(int start);
void printf_fuc();
void function_2(int MAX);

int main_1(void)
{
	//float a = -0.3;
	//printf("a = %d ",a);

	//function_1(3);
	function_2(100);
}


bool isPrime_1(int num)
{
	int tmp = num - 1;
	for (int i = 2; i <= tmp; i++)
		if (num %i == 0)
			return 0;
	return 1;
}

bool isPrime_2(int num)
{
	int tmp = sqrt(num);
	for (int i = 2; i <= tmp; i++)
		if (num %i == 0)
			return 0;
	return 1;
}

bool isPrime_3(int num)
{
	//两个较小数另外处理  
	if (num == 2 || num == 3)
		return 1;
	//不在6的倍数两侧的一定不是质数  
	if (num % 6 != 1 && num % 6 != 5)
		return 0;
	int tmp = sqrt(num);
	//在6的倍数两侧的也可能不是质数  
	for (int i = 5; i <= tmp; i += 6)
		if (num %i == 0 || num % (i + 2) == 0)
			return 0;
	//排除所有，剩余的是质数  
	return 1;
}

//矩阵N*N
#define N 3
int array[N*N] = { 0 };

int isCondition_1(int k)
{
	if (k == 0) return 0;

	if (k < N)
	{
		//第一行，向左判断
		if(isPrime_2(array[k] + array[k-1]))
		  return 1;
	}
	else if (k % N == 0)
	{
		//第一列，向上判断
		if (isPrime_2(array[k] + array[k - N]))
			return 1;
	}
	else
	{
		//向上、向左判断
		if (isPrime_2(array[k] + array[k - 1]) && 
			isPrime_2(array[k] + array[k - N]))
		return 1;
	}

	return 0;
}

int isCondition_2(int k)
{
	if (k == 0) return 0;

	if ((k < N) && isPrime_2(array[k] + array[k - 1])) //第一行，向左判断
	{
		return 1;
	}
	else if ((k % N == 0) && isPrime_2(array[k] + array[k - N])) //第一列，向上判断
	{
		return 1;
	}
	else if (isPrime_2(array[k] + array[k - 1]) &&
			isPrime_2(array[k] + array[k - N])) //向上、向左判断
	{
		return 1;
	}
	else
	    return 0;
}

void function_1(int start)
{
	int i = 1,j = start;

    array[0] = j;

	while (i < N*N )
	{
	   j++;
	   array[i] = j;	  
	  
	  if (isCondition_1(i))
	  {
		  //printf("j = %d \n", j);
		  i++;
	  }
	}

	printf_fuc();
}

int rand_fuc(int num,int MAX)
{
	int i = 0;
	int j = 0;

	j = (int)(rand() % MAX);
	for (i = 0; i < num; i++)
	{
		if(j == array[i])
			j = (int)(rand() % MAX);
	}
	return j;
}

void function_2(int MAX)
{
	int i = 1;
	srand(time(NULL));
	array[0] = (int)(rand() % MAX );

	while (i < N*N)
	{
		array[i] = rand_fuc(i+1, MAX);

		if (isCondition_1(i))
		{
			printf(" = %d \n", array[i]);
			i++;
		}
	}

	printf_fuc();
}

void printf_fuc()
{
	int i = 0;

	for (i = 0; i < N*N; i++)
	{
		if (i%N == 0)
			printf("\n");

		printf(" %3d  ", array[i]);
	}
	printf("\n \n");
}