#include <stdio.h>  
#include <math.h>  
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"

void Merge(int sourceArr[], int tempArr[], int startIndex, int midIndex, int endIndex);
int MaxSubSum3(int *arr, int len);

/*
1.2-2�������������Ƚϲ���������鲢��������ͬ�����ϵ�ʵ�֡�
�Թ�ģΪn�����룬������������8n2�������鲢��������64nlgn����
�ʶ���Щnֵ�������������ڹ鲢����*/
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
˼���� 1-1��������ʱ��ıȽϣ���
�������������㷨��Ҫf(n)���룬���±��е�ÿ������f(n)��ʱ��t��
ȷ��������ʱ��t���������������ģn��
*/
void p1_1_t() //������㷨
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
2-1 ��������
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
p2_1_2 �������򣬷�����
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
2.1-3 �������⣺

���룺һ����A={a1, a2, ...an}��ֵv��
������±�i��ʹ��v=A[i],��v����A�У������NIL��
д����Ը����Բ��������α���룬����ѭ������ʽ֤���㷨����ȷ�ԡ�
*/
//��

/*
2.3.1 ���η�
*/
void merge(int A[], int B[], int p, int q, int r)
{

	int L[20] = { 0 },R[20] = { 0 };
    
	int n1 = q - p + 1;
	int n2 = r - q;
	/*
	��������A�Ѿ���Ϊ�����֣�p-q,q-r�����ֱ�˳�����С�
	���������ָ��Ƶ�L��R�������顣
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

//�ڲ�ʹ�õݹ�
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
4-1���β��� - �����ǿ�����������

α���룺
FIND-MAX-CROSSING-SUBARRY(A,low,mid,high)

left-sum = -��
sum = 0
for i = mid downto low
  sum = sum + A[i]
  if sum > left-sum
    left-sum = sum
	max-left = i

right-sum = -��
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

	if (high == low) //ֻ��һ��ֵ���������ֵ
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
���ŷ�����ʱ�临�Ӷ�O��n��
�����������еĵ�һ��Ԫ�ؿ϶�������
��ΪԪ�������и�����������е�����һ������0
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
		//����ۼӺͳ���С��0�������  
		//������������п϶������ܰ���ǰ���Ԫ�أ�  
		//��ʱ���ۼӺ���0�����¸�Ԫ�����¿�ʼ�ۼ�  
		if (CurSum < 0)
			CurSum = 0;
	}
	return MaxSum;
}


/*
���������е����ֵ
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
�����㷨�����÷��β���
*/
int MaxSubSum2(int *arr, int left, int right)
{
	int MaxLeftSum = 0, MaxRightSum = 0; //���ұߵ�����  
	int MaxLeftBorderSum = 0, MaxRightBorderSum = 0; //���м�߽�����Ҳ�������  
	int LeftBorderSum = 0, RightBorderSum = 0;   //���м�߽�����Ҳ��ֵ�ǰ��  
	int i, center;

	//�ݹ鵽���Ļ������  
	if (left == right)
		if (arr[left]>0) return arr[left];
		else return 0;
		
	//���м�߽�����Ҳ��ֵ����ֵ  
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
	
	//�ݹ������Ҳ������ֵ  
	MaxLeftSum = MaxSubSum2(arr, left, center);
	MaxRightSum = MaxSubSum2(arr, center + 1, right);

	//���������е����ֵ  
	return Max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
}

/*
����֧����ʵ�ֵ��㷨��װ����
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
����˷�Strassen�㷨
α���룺
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
������� -  �ݹ�����㷨
α���룺
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
�������
һ���������������Ҫ�ﵽ���٣�����ʹ������������������ͬ�ĸ��ʴﵽ1/2��
*/


/*
6.2 ά���ѵ�����

α���룺
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
	             //i - ���ڵ��±�
	int l = LEFT(i) - 1; //���ӽڵ��±�
	int r = RIGHT(i) - 1;//���ӽڵ��±�
	int largest = 0;
	i = i - 1;

	if (l < length && A[l] > A[i])//�ڶѷ�Χ��  &&  ���ӽڵ� > ���ڵ� 
	{
		largest = l;//���ϴ�Ľڵ���±걣������
	}
	else
	{
		largest = i;
	}

	if (r < length && A[r] > A[largest]) //�ڶѷ�Χ�� &&  ���ӽڵ� �� �ϴ�Ľڵ�Ƚ�
	{
		largest = r;//�滻����Ľڵ���±�
	}

	if (largest != i) //�����Ľڵ㲻�Ǹ��ڵ㣬���Ľڵ㻻Ϊ���ڵ㣬�ݹ�Ƚ�
	{
		int temp;
		temp = A[i];
		A[i] = A[largest];
		A[largest] = temp;
		MAX_HEAPIFY(A, largest+1, length);
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
	//i - ���ڵ��±�
	int l = LEFT(i) - 1; //���ӽڵ��±�
	int r = RIGHT(i) - 1;//���ӽڵ��±�
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
		MIN_HEAPIFY(A, least+1, length);
	}

	for (int j = 0; j < length; j++)
	{
		printf("%d ", A[j]);
	}
	printf("\n");
}

/*
���ѣ����ѣ�
α���룺
BUILD-MAX-HEAP(A)
  A.heap-size = A.length
  for i = [A.length/2] downto 1
     MAX-HEAPIFY(A,i)
*/
void BUILD_MAX_HEAP(int A[], int length)
{
	int i = 0;
	for (i = length / 2; i >= 1; i--)//�����һ�����ڵ㿪ʼѭ��
	{
		MAX_HEAPIFY(A, i, length);
	}
}

/*
���ѣ���С�ѣ�
*/
void BUILD_MIN_HEAP(int A[], int length)
{
	int i = 0;
	for (i = length / 2; i > 0; i--)//�����һ�����ڵ㿪ʼѭ��
	{
		MIN_HEAPIFY(A, i, length);
	}
}


/*
6.4 �������㷨
α���룺
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

/*  //������Ϊ�����Ͳ�����ȷ�����С
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
	int l = 2 * i, r = 2 * i + 1; ///ȡ���ڵ�i�����Ҷ��ӽڵ�ı��
	int largest;  ///��¼���ֵ�Ľڵ���
	if (a[i]<a[l] && l <= HeadSize)
		largest = l;
	else
		largest = i;
	if (a[largest]<a[r] && r <= HeadSize)
		largest = r;
	if (largest != i)
	{///�ݹ������Ӱ�������
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
	//BuildMaxHead(a, n);  ///����һ�������
	BUILD_MAX_HEAP(a, n);
	int HeadSize = n;
	for (int i = n; i >= 2; i--) ///�ѵĹ�ģ���ϼ���
	{
		swp(a[1], a[i]);
		HeadSize--;   ///�����Ժ��Ҫ���ٶѵĴ�С
		//MaxHeadfly(a, 1, HeadSize);   ///���ڵ�ı���,���µ����ɴ����
		MAX_HEAPIFY(a, 1, HeadSize);
	}
}

/*
6.5 ���ȶ��� ������������У�
INSERT(S,x��:��Ԫ��x���뼯��S��
MAXIMUN(S):����S�о��������ֵ�Ԫ��
EXTRACT-MAX(S):ȥ��������S�е������ֵ�Ԫ��
INCREASE-KEY(S,x,k):��Ԫ��x�Ĺؼ���ֵ���ӵ�k
*/
void HEAP_INSERT(int A[], int x, int length)
{
	//���鲻��������ӳ�Ա
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
		A[i] = A[PARENT(i)] ;
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


	int B[] = { 27, 17, 3,16,13,10, 1 ,5,7,12,4,8,9,0};
	//MAX_HEAPIFY(B, 3, sizeof(B)/sizeof(int));


	int C[] = { 4,1,3,2,16,9,10,14,8,7 };
	//BUILD_MAX_HEAP(C, sizeof(C) / sizeof(int));

	printf("\n\n");
	//BUILD_MIN_HEAP(C, sizeof(C) / sizeof(int));

	//HEAPSORT(C, ARRAY_LEN(C));
	//MIN_HEAPIFY(C, 2, ARRAY_LEN(C));

	//printf("%f \n", 20 * log10(0.004));

	int D[] = {2,4,3,1,7};
	//MAX_HEAPIFY(D, 0, ARRAY_LEN(D));

	//BuildMaxHead(C, ARRAY_LEN(C));  ///����һ�������

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

/*
7.1 �������������

��������
QUICKSORT(int A[], int p, int r)
  if p < r
    q = PARTITION(A, p, r)
	QUICKSORT(A, p, q-1)
	QUICKSORT(A, q+1, r)

����Ļ��֣�
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

//��������
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
* ��������
*
* @param array
*            ����������
* @param start
*            ���������������ʼ����
* @param end
*            ������������Ľ�������
*/
void quickSort(int array[], int start, int end) {
	if (start < end) {
		int position = partition(array, start, end);
		quickSort(array, start, position - 1);
		quickSort(array, position + 1, end);
	}
}

/**
* ����array�����ҳ����ٽ硱λ�õ�����
*
* @param array
*            ����������
* @param start
*            ���������������ʼ����
* @param end
*            ������������Ľ�������
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
7.3 ���������������汾

α���룺
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
β�ݹ�
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
��������:
��������A[1..n]��A.length = n
�������B[1..n]
��ʱ�洢�ռ�C[0..k]
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
��������
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
Ͱ����
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
		//�˴�Ϊ������A�����ݷ��뵽����B����������С� ��ûʵ������
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

//���鳤�ȷ�Ϊ������ż���������
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
9.2 ����Ϊ����ʱ���ѡ���㷨

��������A[p..r]�еĵ�iС��Ԫ��
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
9.3  ����Ϊ����ʱ���ѡ���㷨
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
