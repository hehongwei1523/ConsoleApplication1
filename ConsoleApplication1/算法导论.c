#include <stdio.h>  
#include <math.h>  
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"

void Merge(int sourceArr[], int tempArr[], int startIndex, int midIndex, int endIndex);
int MaxSubSum3(int *arr, int len);

/*
1.2-2　假设我们正比较插入排序与归并排序在相同机器上的实现。
对规模为n的输入，插入排序运行8n2步，而归并排序运行64nlgn步。
问对哪些n值，插入排序优于归并排序？*/
void p1_2_2()
{
	float n = 0;
	for (n = 2; n < 50; n++)
	{

		if (n < (8 * log10(n)))
		{
			printf(" %f \n",n);
		}
		else
		{
			break;
		}
	}
}

/*
思考题 1-1　（运行时间的比较）　
假设求解问题的算法需要f(n)毫秒，对下表中的每个函数f(n)和时间t，
确定可以在时间t内求解的问题的最大规模n。
*/
void p1_1_t() //错误的算法
{
	int n = 0;
	for(n=2;n<1000;n++)
	{
		if (log10(n) < 1000)
		{
			printf("%d \n", n);
		}
		else
			break;
	}

}

/*
2-1 插入排序
*/
void insertion_sort(int *A,int Long)
{
	int i, j;
	int key;

	//printf("arr.leght = %d \n", Log);
	for (j = 1; j < Long; j++)
	{
		key = A[j];
		//Insert A[j] into the sorted sequence A[1..j-1]
		i = j - 1;
		while ((i > -1) && (A[i] > key))
		{
			A[i + 1] = A[i];
			i = i - 1;
		}
		A[i + 1] = key;
	}

	for (i = 0; i < Long; i++)
		printf(" %d ", A[i]);
	printf("\n");

}
/*
p2_1_2 插入排序，非升序
*/ 
void insertion_sort_decrement(int *A, int Long)
{
	int i, j;
	int key;

	//printf("arr.leght = %d \n", Log);
	for (j = 1; j < Long; j++)
	{
		key = A[j];
		//Insert A[j] into the sorted sequence A[1..j-1]
		i = j - 1;
		while ((i > -1) && (A[i] < key))
		{
			A[i + 1] = A[i];
			i = i - 1;
		}
		A[i + 1] = key;
	}

	for (i = 0; i < Long; i++)
		printf(" %d ", A[i]);
	printf("\n");
}

/*
p2_1_3  
2.1-3 查找问题：

输入：一列数A={a1, a2, ...an}和值v。
输出：下标i，使得v=A[i],若v不在A中，则输出NIL。
写出针对该线性查找问题的伪代码，利用循环不变式证明算法的正确性。
*/
//无

/*
2.3.1 分治法
*/
void merge(int A[], int B[], int p, int q, int r)
{

	int L[20] = { 0 },R[20] = { 0 };
    
	int n1 = q - p + 1;
	int n2 = r - q;
	/*
	假设数组A已经分为两部分，p-q,q-r，并分别按顺序排列。
	将这两部分复制到L、R两个数组。
	*/
	//let L[1..n1+1] and R[1..n2+1] be new arrays
	int i = 0,j = 0;
	for (i = 0; i < n1; i++)
	{
		L[i] = A[p + i];
	}
	for (j = 0; j < n2; j++)
	{
		R[j] = A[q + j];
	}
	L[n1] = 10000;
	R[n2] = 10000;
	i = 0;
	j = 0;

	int k = 0;
	for (k = p; k < r; k++)
	{
		if ( L[i] < R[j] )
		{
			B[k] = L[i];
			i = i + 1;
		}
		else
		{
			B[k] = R[j];
			j = j + 1;
		}
	}

	for (i = 0; i < 10; i++)
		printf(" %d ", B[i]);
	printf("\n");
}

/*
*/
void merge_sort(int A[],int B[], int p, int r)
{
	int q = 0;
	if (p < r)
	{
		q = (p + r) / 2;
		//printf("(%d) ", q);
	
		merge_sort(A, B, p, q);
		merge_sort(A, B, q+1, r);
		printf("(p=%d),(q=%d),(r=%d) ", p,q,r);
		//merge(A, B, p, q, r);
		Merge(A, B, p, q, r);
		for (int i = 0; i < 10; i++)
			printf(" %d ", A[i]);
		printf("\n");
	}
}


void Merge(int sourceArr[], int tempArr[], int startIndex, int midIndex, int endIndex)
{
	int i = startIndex, j = midIndex + 1, k = startIndex;
	while (i != midIndex + 1 && j != endIndex + 1)
	{
		if (sourceArr[i] > sourceArr[j])
			tempArr[k++] = sourceArr[j++];
		else
			tempArr[k++] = sourceArr[i++];
	}
	while (i != midIndex + 1)
		tempArr[k++] = sourceArr[i++];
	while (j != endIndex + 1)
		tempArr[k++] = sourceArr[j++];
	for (i = startIndex; i <= endIndex; i++)
		sourceArr[i] = tempArr[i];
}

//内部使用递归
void MergeSort(int sourceArr[], int tempArr[], int startIndex, int endIndex)
{
	int midIndex;
	if (startIndex < endIndex)
	{
		midIndex = (startIndex + endIndex) / 2;
		MergeSort(sourceArr, tempArr, startIndex, midIndex);
		MergeSort(sourceArr, tempArr, midIndex + 1, endIndex);
		printf("startIndex=%d, midIndex=%d, endIndex=%d \n",startIndex,midIndex,endIndex);
		Merge(sourceArr, tempArr, startIndex, midIndex, endIndex);
	}
}

int main0(int argc, char * argv[])
{
	//int a[8] = { 50, 10, 20, 30, 70, 40, 80, 60 };
	int a[11] = { 10,12,5,70,8, 1,24,6,57,9 ,11 };
	int i, b[11];
	MergeSort(a, b, 0, 10);
	for (i = 0; i<11; i++)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}

/*
4-1分治策略 - 求最大非空连续子数组

伪代码：
FIND-MAX-CROSSING-SUBARRY(A,low,mid,high)

left-sum = -∞
sum = 0
for i = mid downto low
  sum = sum + A[i]
  if sum > left-sum
    left-sum = sum
	max-left = i

right-sum = -∞
sum = 0
for j = mid + 1 to high
  sum = sum + A[j]
  if sum > right-sum
    right-sum = sum
	max-right = j

return (max-left, max-right, left-sum + right-sum)


FIND-MAXIMUM-SUBARRAY(A,low,high)
if high == low
  return(low,high,A[low])
else 
  mid = (low + high)/2

  (left-low,left-high,left-sum) = 
     FIND-MAXIMUM-SUBARRAY(A,low,mid)

  (right-low,right-high,right-sum) =
     FIND-MAXIMUM-SUBARRAY(A,mid+1,high)

  (cross-low,cross-high,cross-sum) =
	 FIND-MAX-CROSSING-SUBARRY(A,low,mid,high)

  if (left-sum >= right-sum) and (left-sum >= cross-sum)
     return(left-low,left-high,left-sum)
  elseif (right-sum >= left-sum) and (right-sum >= corss-sum)
     return(right-low,right-high,right-sum)
  else
     return(cross-low,cross-high,cross-sum)
*/

struct Subarry {
	int left;
	int right;
	int sum;
};
#define MIN (-10000)
struct Subarry FIND_MAX_CROSSING_SUBARRY(int *A, int low, int mid, int high)
{
	int i, j;
	int left_sum, sum, right_sum;
	int max_left = 0, max_right = 0;

	struct Subarry subarry;

	left_sum = MIN;
	sum = 0;
	for (i = mid; i > low; i--)
	{ 
		sum = sum + A[i];
		if (sum > left_sum)
		{
			left_sum = sum;
			max_left = i;
		}
	}
	right_sum = MIN;
	sum = 0;
	for (j = mid + 1; j< high; j++)
	{ 
		sum = sum + A[j];
		if (sum > right_sum)
		{
			right_sum = sum;
			max_right = j;
		}
	}
	printf("%d , %d \n", max_left, max_right);
	subarry.left = max_left;
	subarry.right = max_right;
	subarry.sum = left_sum + right_sum;
	return (subarry);// (max_left, max_right, left_sum + right_sum);
}

struct Subarry FIND_MAXIMUM_SUBARRAY(int *A, int low, int high)
{
	int mid = 0;
	struct Subarry subarry = {
	0,0,0
	};
	int left_low, left_high, left_sum;
	int right_low, right_high, right_sum;
	int cross_low, cross_high, cross_sum;
	
	static int time = 0;
	time++;
	printf("time = %d \n", time);

	if (high == low) //只有一个值，就是最大值
	{
		subarry.left = low;
		subarry.right = high;
		subarry.sum = A[low];
		return(subarry);
	}
	else
	{
		mid = (low + high) / 2;

		//(left_low, left_high, left_sum) =
		subarry = FIND_MAXIMUM_SUBARRAY(A, low, mid);
		left_low = subarry.left;
		left_high = subarry.right;
		left_sum = subarry.sum;
		
		//(right - low, right - high, right - sum) =
		subarry = FIND_MAXIMUM_SUBARRAY(A, mid + 1, high);
		right_low = subarry.left;
		right_high = subarry.right;
		right_sum = subarry.sum;

		//(cross - low, cross - high, cross - sum) =
		subarry = FIND_MAX_CROSSING_SUBARRY(A, low, mid, high);
		cross_low = subarry.left;
		cross_high = subarry.right;
		cross_sum = subarry.sum;
		
		if (((left_sum > right_sum) || (left_sum == right_sum)) &&
			((left_sum > cross_sum) || (left_sum == cross_sum)))
		{
			subarry.left = left_low;
			subarry.right = left_high;
			subarry.sum = left_sum;
			return subarry;//(left - low, left - high, left - sum)
		}
		else if (((right_sum > left_sum) || (right_sum == left_sum)) &&
			    ((right_sum > cross_sum) || (right_sum == cross_sum)))
		{
			subarry.left = right_low;
			subarry.right = right_high;
			subarry.sum = right_sum;
			return subarry;//(right - low, right - high, right - sum)
		}
		else
		{
			subarry.left = cross_low;
			subarry.right = cross_high;
			subarry.sum = cross_sum;
			return subarry;//(cross - low, cross - high, cross - sum)
		}
		
		//return Max3(left_sum,right_sum,cross_sum);
	}
}

/*
最优方法，时间复杂度O（n）
和最大的子序列的第一个元素肯定是正数
因为元素有正有负，因此子序列的最大和一定大于0
*/
int MaxSubSum3(int *arr, int len)
{
	int i;
	int MaxSum = 0;
	int CurSum = 0;
	for (i = 0; i<len; i++)
	{
		CurSum += arr[i];
		if (CurSum > MaxSum)
		{
			MaxSum = CurSum;
			printf("%d \n",i);
		}
		//如果累加和出现小于0的情况，  
		//则和最大的子序列肯定不可能包含前面的元素，  
		//这时将累加和置0，从下个元素重新开始累加  
		if (CurSum < 0)
			CurSum = 0;
	}
	return MaxSum;
}


/*
求三个数中的最大值
*/
int Max3(int a, int b, int c)
{
	int Max = a;
	if (b > Max)
		Max = b;
	if (c > Max)
		Max = c;
	return Max;
}

/*
次优算法，采用分治策略
*/
int MaxSubSum2(int *arr, int left, int right)
{
	int MaxLeftSum = 0, MaxRightSum = 0; //左右边的最大和  
	int MaxLeftBorderSum = 0, MaxRightBorderSum = 0; //含中间边界的左右部分最大和  
	int LeftBorderSum = 0, RightBorderSum = 0;   //含中间边界的左右部分当前和  
	int i, center;

	//递归到最后的基本情况  
	if (left == right)
		if (arr[left]>0) return arr[left];
		else return 0;
		
	//求含中间边界的左右部分的最大值  
	center = (left + right) / 2;
	MaxLeftBorderSum = 0;
	LeftBorderSum = 0;
	for (i = center; i >= left; i--)
	{
		LeftBorderSum += arr[i];
		if (LeftBorderSum > MaxLeftBorderSum)
			MaxLeftBorderSum = LeftBorderSum;
	}
	MaxRightBorderSum = 0;
	RightBorderSum = 0;
	for (i = center + 1; i <= right; i++)
	{
		RightBorderSum += arr[i];
		if (RightBorderSum > MaxRightBorderSum)
			MaxRightBorderSum = RightBorderSum;
	}
	
	//递归求左右部分最大值  
	MaxLeftSum = MaxSubSum2(arr, left, center);
	MaxRightSum = MaxSubSum2(arr, center + 1, right);

	//返回三者中的最大值  
	return Max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
}

/*
将分支策略实现的算法封装起来
*/
int MaxSubSum2_1(int *arr, int len)
{
	return MaxSubSum2(arr, 0, len - 1);
}

void main00(void)
{
	//p1_2_2();
	//p1_1_t();
	struct Subarry subarry;

	int Arr[11] = {
		5,2,4,3,9,6,11,0,7,8,12
	};

	//insertion_sort(&Arr, sizeof(Arr) / sizeof(int));
	//insertion_sort_decrement(&Arr, sizeof(Arr) / sizeof(int));

	int A[11] = { 10,12,5,70,8, 1,24,6,57,9 ,11 };
	int B[11] = { 0 };
	//merge_sort(A, B, 0, 10);

	int C[11] = { -1,5,8,3,-5,4,6,-9,0,5,1 };
	int D[] = { 13,-3,-25,21,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7 };
	int E[] = { 13,-3,-25,-21,-3,-16,-23,18,20,-7,-12,-35,-22,-15,-4,-47 };
	int F[] = { 20,39,-25,26,-56,58,-60,-15,-4,-47 };
	/*
	subarry = FIND_MAXIMUM_SUBARRAY(C,0,11);
	printf("low = %d, high = %d, sum =  %d \n", subarry.left,subarry.right,subarry.sum);
   
	subarry = FIND_MAXIMUM_SUBARRAY(D, 0, 16);
	printf("low = %d, high = %d, sum =  %d \n", subarry.left, subarry.right, subarry.sum);

	//subarry = FIND_MAXIMUM_SUBARRAY(E, 0, 16);
	subarry = FIND_MAXIMUM_SUBARRAY(F, 0, 9);
	printf("low = %d, high = %d, sum =  %d \n", subarry.left, subarry.right, subarry.sum);
*/
	/*
	printf("MaxSubSum = %d \n", MaxSubSum3(C, 11));
	printf("MaxSubSum = %d \n", MaxSubSum3(F,9));
	*/

	printf("MaxSubSum = %d \n", MaxSubSum2(F, 0, 9));
	printf("\n end \n");
}


/*
矩阵乘法Strassen算法
伪代码：
SQUARE-MATRIX-MULTIPLY(A,B)
n = A.rows
let C be a new n*n matrix
for i = 1 to n
  for j = 1 to n
    cij = 0;
	for k = 1 to n
	  cij = cij + aik * bkj
return C
*/
#define N 3
int **SQUARE_MATRIX_MULTIPLY(int *A1[], int *B1[])
{
	int A[N][N] = {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};

	int B[N][N] = {
		{11,12,13},
		{14,15,16},
		{17,18,19} 
	};

	int C[N][N] = { 0 };
	//printf("%d ", **A);// (*(*(A + 0) + 0)));

	int i = 0, j = 0, k = 0;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			C[i][j] = 0;
			for (k = 0; k < N; k++)
			{
				C[i][j] = C[i][j] + A[i][k] * B[k][j];
				//printf("%d ", C[i][j]);
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%4d ", C[i][j]);
		}
		printf("\n");
	}

	return C;
}

/*
矩阵相乘 -  递归分治算法
伪代码：
SQUARE-MATRIX_MULTIPLY_RECURSIVE(A,B)
n = A.rows
let c be a new n*n matrix
if n == 1
  c11 = a11 + b11
else partition A,B,and C as in equations(4.9)
  C11 = SQUARE-MATRIX_MULTIPLY_RECURSIVE(A11,B11)
      + SQUARE-MATRIX_MULTIPLY_RECURSIVE(A12,B21)

  C12 = SQUARE-MATRIX_MULTIPLY_RECURSIVE(A11,B12)
      + SQUARE-MATRIX_MULTIPLY_RECURSIVE(A12,B22)

  C21 = SQUARE-MATRIX_MULTIPLY_RECURSIVE(A21,B11)
	  + SQUARE-MATRIX_MULTIPLY_RECURSIVE(A22,B21)

  C22 = SQUARE-MATRIX_MULTIPLY_RECURSIVE(A21,B12)
	  + SQUARE-MATRIX_MULTIPLY_RECURSIVE(A22,B22)
return C
*/


/*
生日悖论
一个房间里面的人数要达到多少，才能使有至少两个人生日相同的概率达到1/2。
*/




/*
7.1 快速排序的描述

快速排序：
QUICKSORT(int A[], int p, int r)
  if p < r
    q = PARTITION(A, p, r)
	QUICKSORT(A, p, q-1)
	QUICKSORT(A, q+1, r)

数组的划分：
PARTITION(int A[], p, r)
  x = A[r]
  i = p - 1
  for j = p to r-1
    if A[j] <= x
	   i = i + 1
	   exchange A[i] with A[j]
  exchange A[i+1] with A[r]

  return i+1
*/

//快速排序
int PARTITION(int A[], int p, int r)
{
	int x = A[r];
	int i = p - 1;
	int temp = 0;

	for (int j = p; j < r; j++)
	{
		if (A[j] <= x)
		{
			i = i + 1;
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}
	temp = A[i + 1];
	A[i + 1] = A[r];
	A[r] = temp;

	return (i + 1);
}

void QUICKSORT(int A[], int p, int r)
{
	int q = 0;
	if (p < r)
	{
		printf("p = %d, q = %d, r = %d \n", p, q, r);
		q = PARTITION(A, p, r);
		QUICKSORT(A, p, q - 1);
		printf("---\n");
		QUICKSORT(A, q + 1, r);
    }
}
/**
* 快速排序
*
* @param array
*            待排序数组
* @param start
*            待排序子数组的起始索引
* @param end
*            待排序子数组的结束索引
*/
void quickSort(int array[], int start, int end) {
	if (start < end) {
		int position = partition(array, start, end);
		quickSort(array, start, position - 1);
		quickSort(array, position + 1, end);
	}
}

/**
* 重排array，并找出“临界”位置的索引
*
* @param array
*            待重排数组
* @param start
*            待重排子数组的起始索引
* @param end
*            待重排子数组的结束索引
* @return
*/
int partition(int array[], int start, int end) {
	int position = start - 1;
	int base = array[end];
	for (int i = start; i < end; i++) {
		if (array[i] <= base) {
			position++;
			int temp = array[position];
			array[position] = array[i];
			array[i] = temp;
		}
	}
	int temp = array[position + 1];
	array[position + 1] = array[end];
	array[end] = temp;
	return position + 1;
}

/*
7.3 快速排序的随机化版本

伪代码：
RANDOMIZED-PARTITION(A,p,r)
  i = RANDOM(p,r)
  exchange A[r] with A[i]
  return PARTITION(A,p,r)

PANDOMIZED-QUICKSORT(A,p,r)
  if p < r
    q = RANDOMIZED-PARTITION(A,p,r)
	PANDOMIZED-QUICKSORT(A,p,q-1)
	PANDOMIZED-QUICKSORT(A,q+1,r)
*/

int RANDOM(int p, int r)
{
	srand(time(0));
	return (rand() % (r - p + 1) + p);
}

int RANDOMIZED_PARTITION(int A[], int p, int r)
{
	int i = RANDOM(p, r);
	//exchange A[r] with A[i]
	int temp = 0;
	temp = A[i];
	A[i] = A[r];
	A[r] = temp;

	return PARTITION(A, p, r);
}

void PANDOMIZED_QUICKSORT(int A[], int p, int r)
{
	if (p < r)
	{
		int q = RANDOMIZED_PARTITION(A, p, r);
		PANDOMIZED_QUICKSORT(A, p, q - 1);
		PANDOMIZED_QUICKSORT(A, q + 1, r);
	}
}

/*
尾递归
*/
int TAIL_RECURSIVE_QUICKSORT(int A[], int p, int r)
{
	int q = 0;
	while (p < r)
	{
		q = PARTITION(A, p, r);
		TAIL_RECURSIVE_QUICKSORT(A, p, q - 1);
		p = q + 1;
	}
}

/*
计数排序:
输入数组A[1..n]，A.length = n
输出数组B[1..n]
临时存储空间C[0..k]
*/
void COUNTING_SORT(int A[], int B[], int k, int A_length)
{
  //let C[0..k] be a new array
	int *C = (int *)malloc(k * sizeof(int));

	//int C[23] = { 0 };
	int i = 0, j = 0;

	for (i = 0; i < k; i++)
	{
		C[i] = 0;
	}
	for (j = 0; j < A_length; j++)
	{
		C[A[j]] = C[A[j]] + 1;
	}
	//C[i] now contains the number of elements equal to i

	//-------
	for (i = 1; i < k; i++)
	{
		C[i] = C[i] + C[i - 1];
	}
   //C[i] now contains the number of elements less than or equal to i
	
	for (i = 0; i < k; i++)
		printf("C[%d] = %d \n", i, C[i]);
	
	//-------
	for (j = A_length - 1; j > -1; j--)
	{
		B[C[A[j]]] = A[j];
		C[A[j]] = C[A[j]] - 1;
	}
}

void COUNTING_SORT_CHAR(char A[][3], char B[][3], int set, int k, int A_length)
{
	char *C = (int *)malloc(k * sizeof(char));

	int i = 0, j = 0;

	for (i = 0; i < k; i++)
	{
		C[i] = 0;
	}
	for (j = 0; j < A_length; j++)
	{
		int index = A[j][set] - 'A';
		C[index] = C[index] + 1;
	}
	//-------
	for (i = 1; i < k; i++)
	{
		C[i] = C[i] + C[i - 1];
	}
	//-------
	for (j = A_length - 1; j > -1; j--)
	{
		int index = A[j][set] - 'A';
		memcpy(B[C[index]],A[j],3);
		C[index] = C[index] - 1;
	}
	
	for (j = 1; j < A_length; j++)
	{
		//printf("B[%d] = %c \n", j, B[j][set]);
		memcpy(A[j-1], B[j], 3);
	}
	
	free(C);
}

char word[16][3] = {
	"COW","DOG","SEA","RUG",
	"ROW","MOB","BOX","TAB",
	"BAR","EAR","TAR","DIG",
	"BIG","TEA","NOW","FOX",
};

/*
基数排序
*/
void RADIX_SORT(int zA[], int d)
{
	for (int i = d-1; i > -1; i--)
	{
		//use a stable sort to sort array A on digit i
		char B[17][3] = { 0 };
		COUNTING_SORT_CHAR(word, B, i, 26, 16);
	}
	
	for (int i = 0; i < 16; i++)
	{
		/*
		printf("\nB[%d] = ",i);
		for (int j = 0; j < 3; j++)
		{
			printf("%c", word[i][j]);
		}
		*/
		printf("\nB[%d] = %s", i, word[i]);
		
	}
}

/*
桶排序
BUCKET-SORT(A)
  n = A.length
  let B[0..n-1] be a new array
  for i = 0 to n-1
     make B[i] an empty list
  for i = 1 to n
     inser A[i] into list B[nA[i]]
  for i = 0 to n-1
     sort list B[i] with insertion sort
concatenate the lists B[0],B[1],...,B[n-1] together in order
*/

void BUCKET_SORT(int A[], int length)
{
	int n = length;
	int *B = malloc(sizeof(int) * n);
	int i = 0;
   
	for (i = 0; i < n - 1; i++)
	{
		B[0] = NULL;
	}
	for (i = 1; i < n; i++)
	{
		//此处为将数组A的数据放入到数据B保存的链表中。 暂没实现链表
	}
}
void quick_main(void)
{
	int A[] = { 2,8,7,1,3,5,6,4 };
	int B[] = { 13,19,9,5,12,8,7,4,21,2,6,11,8 };
/*
#define T B
	//QUICKSORT(T, 0, ARRAY_LEN(T)-1);
	//quickSort(T, 0, ARRAY_LEN(T) - 1);
	//PANDOMIZED_QUICKSORT(T, 0, ARRAY_LEN(T) - 1);
	TAIL_RECURSIVE_QUICKSORT(T, 0, ARRAY_LEN(T) - 1);

	for (int i = 0; i < ARRAY_LEN(T); i++)
	{
		printf("%d ", T[i]);
	}
	printf(" \n ");
	
	int C[] = { 7,5,6,8 };
	//printf("i+1= %d ||\n", PARTITION(C, 0, 3));
	QUICKSORT(C, 0, 3);

	for (int i = 0; i < ARRAY_LEN(C); i++)
	{
		printf("%d ", C[i]);
	}
*/
	/*
	srand(time(0));
	printf("%d ", rand() % (ARRAY_LEN(T) - 1));
	*/

	//printf("%d ", RANDOM(0,5));

	/*
	int R[22] = { 0 };
	COUNTING_SORT(B,R,22,13);

	for (int i = 1; i < ARRAY_LEN(R); i++)
	{
		printf("%d ", R[i]);
	}
	printf(" \n ");
	*/

	RADIX_SORT(A, 3);
}


int findMaxandMin(int A[], int length)
{
	int min = 0, max = 0;

	max = min = A[0];
	for (int i = 1; i < length; i++)
	{
		if (A[i] > max)
			max = A[i];
		else if (A[i] < min)
		{
			min = A[i];
		}
	}

	printf("max = %d , min = %d \n",max, min);

	return 0;
}

//数组长度分为奇数和偶数两种情况
void MinAndMax(int A[], int n) {
	int lt, gt;
	int i;
	static int min = 0, max = 0;

	if (n & 1) {
		min = A[0];
		max = A[0];
		i = 1;
	}
	else {
		min = A[0]<A[1] ? A[0] : A[1];
		max = A[0] + A[1] - min;
		i = 2;
	}

	for (; i < n; i += 2) {
		if (A[i] < A[i + 1]) {
			lt = A[i];
			gt = A[i + 1];
		}
		else {
			lt = A[i + 1];
			gt = A[i];
		}
		if (min > lt) min = lt;
		if (max < gt) max = gt;
	}
	printf("max = %d , min = %d \n", max, min);
}

/*
9.2 期望为线性时间的选择算法

返回数组A[p..r]中的第i小的元素
*/
int RANDOMIZED_SELECT(int A[], int p, int r, int i)
{
	if (p == r)
	{
		return A[p];
	}

	int q = RANDOMIZED_PARTITION(A, p, r);
	int k = q - p + 1;
	if (i == k)
	{
		return A[q];
	}
	else if (i < k)
	{
		return RANDOMIZED_SELECT(A, p, q - 1,i);
	}
	else 
		return RANDOMIZED_SELECT(A, q + 1, r, i);
}

/*
9.3  最坏情况为线性时间的选择算法
*/
#define MAXN 120
int SELECT(int A[], int p, int r, int i) {
	int M[MAXN / 5 + 2], m = 0; // M[]: store median, m: number of medians
	int x, k, q;            // x: median of M[]
	int j, n = 5;

	if (p == r)
		return A[p];

	for (j = p; j <= r; j += 5) {
		if (j + 4 > r) {
			n = r - j + 1;
		}
		//InsertionSort(A + j - 1, n);    // Sort
		insertion_sort(A + j - 1, n);
		M[m++] = A[j + (n -1) / 2];      // then Add the median into M
	}
	x = SELECT(M, 1, m, (m + 1) / 2);
	//q = PartitionX(A, p, r, x);
	q = RANDOMIZED_SELECT(A, p, r, x);

	k = q - p + 1;
	if (i == k)
		return x;
	else if (i < k)
		return SELECT(A, p, q - 1, i);
	else
		return SELECT(A, q + 1, r, i - k);
}

#define ARRAY_LEN(X) (sizeof(X)/sizeof(int))

void sort_main()
{
	int A[] = {5,2,7,9,4,3,77,1};

	//findMaxandMin(A, ARRAY_LEN(A));
	//MinAndMax(A, ARRAY_LEN(A));

	/*
	int num = RANDOMIZED_SELECT(A, 0, ARRAY_LEN(A) - 1, 2);
	printf("num = %d \n",num);
	*/

	printf("SELECT = %d \n", SELECT(A, 1, ARRAY_LEN(A) , 2));
}

void main3()
{
	//quick_main();

	sort_main();
}
