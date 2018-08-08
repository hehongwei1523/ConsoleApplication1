#include <stdio.h>  
#include <math.h>  
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"

/*
6.2 维护堆的性质

伪代码：
MAX-HEAPIFY(A,i)
l = LEFT(i)
r = RIGHT(i)
if l <= A.heap-size and A[l] > A[i]
largest = l
else
largest = i

if r <= A.heap-size and A[r] > A[largest]
largest = r

if largest != i
exchange A[i] with A[largest]
MAX-HEAPIFY(A,largest)
*/

#define PARENT(i) (i/2)
#define LEFT(i)   (i+i)
#define RIGHT(i)  (i+i+1)

void MAX_HEAPIFY(int A[], int i, int length)
{
	//int A[] = { 16, 4, 10, 14, 7, 9, 3, 2, 8, 1 };
	//i - 父节点下标
	int l = LEFT(i) - 1; //左子节点下标
	int r = RIGHT(i) - 1;//右子节点下标
	int largest = 0;
	i = i - 1;

	if (l < length && A[l] > A[i])//在堆范围内  &&  左子节点 > 父节点 
	{
		largest = l;//将较大的节点的下标保存起来
	}
	else
	{
		largest = i;
	}

	if (r < length && A[r] > A[largest]) //在堆范围内 &&  右子节点 与 较大的节点比较
	{
		largest = r;//替换更大的节点的下标
	}

	if (largest != i) //若最大的节点不是父节点，最大的节点换为父节点，递归比较
	{
		int temp;
		temp = A[i];
		A[i] = A[largest];
		A[largest] = temp;
		MAX_HEAPIFY(A, largest + 1, length);
	}

	for (int j = 0; j < length; j++)
	{
		printf("%d ", A[j]);
	}
	printf("\n");

}


void MIN_HEAPIFY(int A[], int i, int length)
{
	//int A[] = { 16, 4, 10, 14, 7, 9, 3, 2, 8, 1 };
	//i - 父节点下标
	int l = LEFT(i) - 1; //左子节点下标
	int r = RIGHT(i) - 1;//右子节点下标
	int least = 0;
	i = i - 1;

	if (l < length && A[l] < A[i])
	{
		least = l;
	}
	else
	{
		least = i;
	}

	if (r < length && A[r] < A[least])
	{
		least = r;
	}

	if (least != i)
	{
		int temp;
		temp = A[i];
		A[i] = A[least];
		A[least] = temp;
		MIN_HEAPIFY(A, least + 1, length);
	}

	for (int j = 0; j < length; j++)
	{
		printf("%d ", A[j]);
	}
	printf("\n");
}

/*
建堆（最大堆）
伪代码：
BUILD-MAX-HEAP(A)
A.heap-size = A.length
for i = [A.length/2] downto 1
MAX-HEAPIFY(A,i)
*/
void BUILD_MAX_HEAP(int A[], int length)
{
	int i = 0;
	for (i = length / 2; i >= 1; i--)//从最后一个父节点开始循环
	{
		MAX_HEAPIFY(A, i, length);
	}
}

/*
建堆（最小堆）
*/
void BUILD_MIN_HEAP(int A[], int length)
{
	int i = 0;
	for (i = length / 2; i > 0; i--)//从最后一个父节点开始循环
	{
		MIN_HEAPIFY(A, i, length);
	}
}


/*
6.4 堆排序算法
伪代码：
HEAPSORT(A)
BUILD-MAX-HEAP(A)
for i = A.length downto 2
exchange A[1] with A[i]
A.heap-size = A.heap-size - 1
MAX-HEAPIFY(A,1)
*/
void HEAPSORT_INCREASE(int A[], int length)
{
	int len = length;
	int i = length - 1;

	BUILD_MAX_HEAP(A, length);
	for (; i > 0; i--)
	{
		int temp = 0;
		temp = A[0];
		A[0] = A[i];
		A[i] = temp;

		len--;
		MAX_HEAPIFY(A, 1, len);
		//BUILD_MAX_HEAP(A, len);
	}
}
void HEAPSORT_DECREASE(int A[], int length)
{
	int len = length;
	int i = length - 1;

	BUILD_MIN_HEAP(A, length);
	for (; i > 0; i--)
	{
		int temp = 0;
		temp = A[0];
		A[0] = A[i];
		A[i] = temp;

		len--;
		MIN_HEAPIFY(A, 1, len);
	}
}

#define ARRAY_LEN(X) (sizeof(X)/sizeof(int))

/*  //数组作为参数就不能正确计算大小
void Printf(int A[])
{
for (int j = 0; j < ARRAY_LEN(A); j++)
{
printf("%d ", A[j]);
}
printf("\n");
}
*/

int swp(int *a, int *b)
{
	int *temp = a;
	a = &b;
	b = &temp;
}

void MaxHeadfly(int *a, int i, int HeadSize)
{
	int l = 2 * i, r = 2 * i + 1; ///取出节点i的左右儿子节点的编号
	int largest;  ///记录最大值的节点编号
	if (a[i]<a[l] && l <= HeadSize)
		largest = l;
	else
		largest = i;
	if (a[largest]<a[r] && r <= HeadSize)
		largest = r;
	if (largest != i)
	{///递归调整受影响的子树
		swp(a[i], a[largest]);
		MaxHeadfly(a, largest, HeadSize);
	}

	for (int j = 0; j < HeadSize; j++)
	{
		printf("%d ", a[j]);
	}
	printf("\n");
}

void BuildMaxHead(int *a, int n)
{
	for (int i = n / 2; i >= 1; i--)
		MaxHeadfly(a, i, n);
}

void HeadSort(int *a, int n)
{
	//BuildMaxHead(a, n);  ///建立一个大根堆
	BUILD_MAX_HEAP(a, n);
	int HeadSize = n;
	for (int i = n; i >= 2; i--) ///堆的规模不断减少
	{
		swp(a[1], a[i]);
		HeadSize--;   ///交换以后就要减少堆的大小
					  //MaxHeadfly(a, 1, HeadSize);   ///根节点改变了,重新调整成大根堆
		MAX_HEAPIFY(a, 1, HeadSize);
	}
}

/*
6.5 优先队列 （最大优先序列）
INSERT(S,x）:把元素x插入集合S中
MAXIMUN(S):返回S中具有最大键字的元素
EXTRACT-MAX(S):去掉并返回S中的最大键字的元素
INCREASE-KEY(S,x,k):将元素x的关键字值增加到k
*/
void HEAP_INSERT(int A[], int x, int length)
{
	//数组不能任意添加成员
}
void HEAP_MAXIMUM(int A[])
{
	return A[0];
}

void HEAP_EXTRACT_MAX(int A[], int length)
{
	if (length <= 1)
	{
		printf("error: heap underflow");
	}
	int max = A[0];
	length = length - 1;
	A[0] = A[length];
	length = length - 1;
	MAX_HEAPIFY(A, 1, length);

	return max;
}

void HEAP_INCREASE_KEY(int A[], int i, int key)
{
	i = i - 1;
	if (key < A[i])
	{
		printf("error: new key is smaller than current key");
		return;
	}

	A[i] = key;
	while ((i > 0) && A[PARENT(i)] < A[i])
	{
		int temp = A[i];
		A[i] = A[PARENT(i)];
		A[PARENT(i)] = temp;

		i = PARENT(i);
	}
}

void heap_main(void)
{
	///int C[N][N] = { 0 };

	//SQUARE_MATRIX_MULTIPLY((void *)0, (void *)0);

	int A[] = { 16, 4, 10, 14, 7, 9, 3, 2, 8, 1 };

	//MAX_HEAPIFY(A,0, 10);
	//BUILD_MAX_HEAP(A, ARRAY_LEN(A));


	int B[] = { 27, 17, 3,16,13,10, 1 ,5,7,12,4,8,9,0 };
	//MAX_HEAPIFY(B, 3, sizeof(B)/sizeof(int));


	int C[] = { 4,1,3,2,16,9,10,14,8,7 };
	//BUILD_MAX_HEAP(C, sizeof(C) / sizeof(int));

	printf("\n\n");
	//BUILD_MIN_HEAP(C, sizeof(C) / sizeof(int));

	//HEAPSORT(C, ARRAY_LEN(C));
	//MIN_HEAPIFY(C, 2, ARRAY_LEN(C));

	//printf("%f \n", 20 * log10(0.004));

	int D[] = { 2,4,3,1,7 };
	//MAX_HEAPIFY(D, 0, ARRAY_LEN(D));

	//BuildMaxHead(C, ARRAY_LEN(C));  ///建立一个大根堆

	//HeadSort(C, ARRAY_LEN(C));
	//HEAPSORT_INCREASE(C, ARRAY_LEN(C));

	for (int j = 0; j < 10; j++)
	{
		printf("%d ", C[j]);
	}
	printf("\n");

	//BUILD_MAX_HEAP(C, ARRAY_LEN(C));

	HEAPSORT_DECREASE(C, ARRAY_LEN(C));
	//HEAP_EXTRACT_MAX(C, ARRAY_LEN(C));
	HEAP_INCREASE_KEY(C, 3, 34);

	for (int j = 0; j < 10; j++)
	{
		printf("%d ", C[j]);
	}
	printf("\n");
	/*
	int a = 1, b = 2;
	swp(&a, &b);
	printf("%d %d", b, a);
	*/
}
