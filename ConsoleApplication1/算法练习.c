// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdlib.h>
#include <malloc.h>

void f(int *p)
{
	printf("p = %p \n", p);
	p = (int *)malloc(sizeof(int *));
	printf("p = %p \n",p);
}

int main1()
{
	int a[10] = { 1,2,3,4,5 };
	int * ptr = a;
	printf("p = %p \n", a);
	printf("p = %p \n", ptr);
	f(ptr);
    return 0;
}


//��1 - 100���������Ϊ1 - 100��ÿ��ȥ�����Ϊż���������±�ţ����ʣ�µ��������Ƕ��٣�

//�������
char arr[101] = { 0 };
int  z = 100;

//ɾ��ż�����
void even_delete()
{
	int i;
	for (i = 1;i < z; i++)
	{
		if (i % 2 == 0)
		{
			arr[i] = 0;
		}
	}
}
//���±��
void re_sort()
{
	int i,j=1;
	for (i = 1;i < z; i++)
	{
		if (arr[i] != 0)
		{
			arr[j++] = arr[i];
			//printf("arr[%d] = %d\n", j-1,arr[j-1]);
		}
	}
	//���±�ŵĸ���z
	z = j;
}

void function()
{
	//��ʼ������
	int i = 0;
	for (i = 0; i < 102; i++)
		arr[i] = i;

	//��ʣ�µĸ�����������ʱ��ѭ������
	while (z > 2)
	{
		even_delete();
		re_sort();
		//printf("====\nz = %d\n", z);
	}

	printf("====\n\n");
	for (i = 1; i < 5; i++)
	{
		printf("arr[%d] = %d\n", i, arr[i]);
	}

}

/*���������ʵ�ֽ׳�����*/
typedef unsigned int(*fun)(unsigned int);

unsigned int Solution3_Teminator(unsigned int n)
{
	return 0;
}

unsigned int Sum_Solution3(unsigned int n)
{
	static fun f[2] = { Solution3_Teminator, Sum_Solution3 };
	return n + f[!!n](n - 1);
}

//printf("Sum_Solution3 = %d \n", Sum_Solution3(100));

/*��λ��������������*/
int plus(int a, int b)
{
	while (a != 0) {
		int temp = (a & b) << 1;
		b = a ^ b;
		a = temp;
	}
	return b;
}

