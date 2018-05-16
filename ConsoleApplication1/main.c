
#include "stdafx.h"
#include <stdlib.h>
#include "stdafx.h"

#include "stdio.h"
void printf_float_int(void)
{
	int a;
	float b;

	scanf_s("%d,%f", &a, &b);
	printf("a = %d, b = %f \n", a, b);
}

int FindMax(int *A, int low, int high)
{
	int mid = 0;
	if (low == high)
	{
		return A[low];
	}
	else
	{
		mid = (low + high) / 2;
		FindMax(A, low, mid);
	}
}


int main3z()
{
	//printf_float_int();

	printf("run \n");

	//server();
	//client();

	//function();

	int A[] = {3,2,7,0,1};
	printf("%d \n",FindMax(A, 0, 6));

	return 0;
}
