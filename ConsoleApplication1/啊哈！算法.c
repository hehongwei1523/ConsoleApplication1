#include "stdafx.h"
#include <stdlib.h>
#include "stdafx.h"
#include "string.h"
#include "stdio.h"


/*
����: 	ʿ���Ŷ�
��ǩ : ͼ�ṹ ��������
���� :
	�Уθ�ʿ��(1�ܣΡ�26)���������Ϊ ��, ��, ��, ��������ѵ��ʱ��ָ�ӹ�Ҫ��һЩʿ���Ӹߵ���һ���ų�һ�У�
	������ָ�ӹٲ���ֱ�ӻ��ÿ���˵������Ϣ��ֻ�ܻ�á�P1��P2�ߡ������ıȽ� ���(P1��P2 �� ��, ��, ��, ��, ��, ��Ϊ P1 > P2)��
	�硱�� >�� ����ʾ���ȣ¸ߡ���Ӧ���Ŷӷ�����������
	AFBD�� FABD ��
		���е��Ŷӷ������������ֱ���FABD��AFBD��ABFD����������һ�����ɡ�
		��ע���ȽϽ����û���漰��ʿ�����μ��Ŷӣ�

	�����ʽ : ��������
		ÿ�������ַ�����һ���ַ��͵������ַ���Ϊ��д��ĸA~Z����ĳ����ĸ���м��һ����ĸΪ>

	�����ʽ:
	    �����������޽⣬��ӡ��No Answer!����Ϣ������Ӹߵ���һ�����ÿһ��ʿ���ı�ţ��м��޷ָ��

	���� :
	����
		A>B
		B>D
		F>D
	���
		AFBD
*/
#if 1

#define N 27
char dest[N] = { 0 };
int count = 0;
int run = 1;

void function_t(char p[])
{
	int i = 0, j = 0;
	char a = 0, b = 0;
	if(run)
	{
		//�ȷ�һ�����ݵ�����ͷ
		if (dest[0] == 0)
		{
			dest[0] = p[0];
			dest[1] = p[2];
			count = 2;
			return;
		}
		a = -1; b = -1;
		for (i = 0; i < count+1; i++)
		{
			if (p[0] == dest[i])
			{
				a = i;
			}
			else if (p[2] == dest[i])
			{
				b = i;
			}
		}
		if (a == -1 && b == -1)
		{
			//[0]��[1]���ǵ�һ�γ��֣���������ǰ����λ
			dest[count++] = p[0];
			dest[count++] = p[2];
		}
		else if (a == -1)// b != -1
		{
			//[0]�ǵ�һ�γ���: p[0]����b��λ�ã���������һλ
			for (j = count; j > b-1 ; j--)
			{
				dest[j] = dest[j - 1];
			}
			dest[b] = p[0];
			count++;
		}
		else if (b == -1)// a != -1
		{
			//[1]�ǵ�һ�γ���: p[2]����a��λ�ú���������һλ
			for (j = count; j > a; j--)
			{
				dest[j] = dest[j - 1];
			}
			dest[a+1] = p[2];
			count++;
		}
		else
		{
			if (a >= b)
			{
				printf("No Answer!");
				run = 0;
				return;
			}
		}

	}
}

int ID12167(void)
{
	char p[4] = { '\0' }; 
	int i = 0, j = 0;
	char a = 0, b = 0;

	while(run)
	{
		/*
		scanf_s("%s", &p, 4);
		if (p[0] == 'e') {
			//printf("\n ������� \n");
			break;
		}*/
		gets(p);
		if ((p[3] == '\n') || (p[3] == '\r') ||(p[0] == '\0')) 
		{
			return;
			//printf("%s", dest); 
		}
		else
		{
			//printf("%s", p);
			//�ȷ�һ�����ݵ�����ͷ
			if (dest[0] == 0)
			{
				dest[0] = p[0];
				dest[1] = p[2];
				count = 2;
				continue;
			}
			a = -1; b = -1;
			for (i = 0; i < count; i++)
			{
				if (p[0] == dest[i])
				{
					a = i;
				}
				else if (p[2] == dest[i])
				{
					b = i;
				}
			}
			if (a == -1 && b == -1)
			{
				//[0]��[1]���ǵ�һ�γ��֣���������ǰ����λ
				dest[count++] = p[0];
				dest[count++] = p[2];
			}
			else if (a == -1)// b != -1
			{
				//[0]�ǵ�һ�γ���: p[0]����b��λ�ã���������һλ
				for (j = count ; j > b - 1 ; j--)
				{
					dest[j] = dest[j - 1];
				}
				dest[b] = p[0];
				count++;
			}
			else if (b == -1)// a != -1
			{
				//[1]�ǵ�һ�γ���: p[2]����a��λ�ú���������һλ
				for (j = count ; j > a; j--)
				{
					dest[j] = dest[j - 1];
				}
				dest[a + 1] = p[2];
				count++;
			}
			else
			{
				if (a >= b)
				{
					printf("No Answer!");
					run = 0;
					return;
				}
			}

		}
	}
}

int main_suanfa(void)
{
#if 1
	
 ID12167();
 /*
	char p[4] = { '\0'};
	while(1){
		//scanf_s("%s", &p, 4);
		gets(p);
		//printf("%s",p);
		if ((p[0] == '\n') || (p[0] == '\r') || 
			(p[0] == '\0') ) {
			printf("\n ������� \n");
			return;
		}
	}*/
#else

	char *P[] = {
		"A>Y",
		"E>A",
		"F>C",
		"S>F",
		"A>F",
		"B>A",
		"W>X",
		"A>W"

	};
	for (int i = 0; i < 8; i++)
	{
		function_t(P[i]);
	}
#endif
	if (run == 0) return;
	printf("%s",dest);
}


#endif

/*
����: 	���ַ�ת [ �߼��� ]
��ǩ: 	�ַ��� �ַ�������
����: 	����һ������N���뽫��������λ�����ַ�ת�õ�һ������������ҲӦ���������ĳ�����ʽ�������Ǹ�����ԭ��Ϊ�㣬����ת��õ������������λ���ֲ�ӦΪ��
�����ʽ:
���빲1 �У�һ������N��

�����ʽ:
�����1 �У�һ����������ʾ��ת���������

����: N��λ��������10000λ

����:
����
-100
���
-1

����
123456789123456789123456789
���
987654321987654321987654321
*/

int ID12108()
{
#define NUM 10001

	char string[NUM] = { 0 };
	char dest[NUM] = { 0 };
	gets(string);

	int temp = 0;
	int i = 0;

	for (i = NUM; i >= 0; i--)
	{
		if (string[i] > '0')
		{
			temp = i + 1;
			break;
		}
	}
	if (string[0] == '-')
	{
		temp--;
		printf("-");
		for (i = temp; i > 0; i--)
		{
			printf("%c", string[i]);
		}
	}
	else if (string[0] == '0')
	{
		printf("%c", string[i]);
	}
	else {
		printf("%d=", temp);
		for (i = temp-1; i >= 0; i--)
		{
			printf("%c", string[i]);
		}
	}
}

/*
��Ŀ����(ID:10021)
����: 	��С��
��ǩ : �ַ��� ģ�� �ַ�������
���� : ��С��Ĵʻ�����С������ÿ����Ӣ��ѡ�����ʱ�򶼺�ͷ�ۡ��������ҵ���һ�ַ�����������֤���������ַ���ȥѡ��ѡ���ʱ��ѡ�Եļ��ʷǳ���
���ַ����ľ����������£�����maxn�ǵ����г��ִ���������ĸ�ĳ��ִ�����minn�ǵ����г��ִ������ٵ���ĸ�ĳ��ִ��������maxn - minn��һ����������ô��С�����Ϊ���Ǹ�Lucky Word�������ĵ��ʺܿ��ܾ�����ȷ�Ĵ𰸡�

�����ʽ :
����ֻ��һ�У���һ�����ʣ�����ֻ���ܳ���Сд��ĸ�����ҳ���С��100��

�����ʽ :
��������У���һ����һ���ַ�������������ĵĵ�����Lucky Word����ô�����Lucky Word�������������No Answer����
�ڶ�����һ��������������뵥����Lucky Word�����maxn - minn��ֵ���������0��

��ʾ : NOIP�����2008
���� : �������Ե�1s
���� :

����
error

���
Lucky Word
2

����
����error�г���������ĸr������3�Σ����ִ������ٵ���ĸ������1�Σ�3 - 1 = 2��2��������

����
olympic

���
No Answer
0

����
����olympic�г���������ĸ������1�Σ����ִ������ٵ���ĸҲ������1�Σ�1 - 1 = 0��0����������
*/

int _isPrime(int num)
{
	if ((num == 2) || (num == 3)) return 1;
	else if ((num == 1) || (num == 0)) return 0;

	int tmp = sqrt(num);
	for (int i = 2; i <= tmp; i++)
		if (num %i == 0)
			return 0;
	return 1;
}

#define  MAX_WORD  101
void ID10021()
{
	char word[MAX_WORD] = { 0 };
	gets(word);

	int count[26] = { 0 };
	int i = 0;
	int max = 0, min = MAX_WORD;

	for (i = 0; i < MAX_WORD; i++)
	{
		if ((word[i] < 'a') || (word[i] > 'z')) break;
		count[word[i] - 'a']++;
	}
	for (i = 0; i < 26; i++)
	{
		if (count[i] != 0)
		{
			if (count[i] > max)
				max = count[i];
			if (count[i] < min)
				min = count[i];

			printf("%c = %d \n", ('a' + i), count[i]);
		}
	}
	printf("max = %d, min = %d \n", max, min);

	if (_isPrime(max - min))
	{
		printf("Lucky Word\n%d\n",max - min);
	}
	else
	{
		printf("No Answer\n%d\n", 0);
	}

}

/*
��Ŀ����(ID:10007)
����: 	ISBN����
��ǩ: 	�ַ���
����: 	ÿһ����ʽ�����ͼ�鶼��һ��ISBN������֮��Ӧ��ISBN�����9λ���֡�1λʶ�����3λ�ָ�������涨��ʽ�硰x-xxx-xxxxx-x�������з��š�-�����Ƿָ����������ϵļ��ţ������һλ��ʶ���룬����0-670-82162-4����һ����׼��ISBN�롣ISBN�����λ���ֱ�ʾ�鼮�ĳ������ԣ�����0����Ӣ���һ���ָ�����-��֮�����λ���ִ�������磬����670����ά�������磻�ڶ����ָ��������λ���ִ�������ڸó�����ı�ţ����һλΪʶ���롣
����ʶ����ļ��㷽�����£�
  ������λ���ֳ���1���ϴ�λ���ֳ���2�����Դ����ƣ������õĽ��mod 11�����õ�������Ϊʶ���룬�������Ϊ10����ʶ����Ϊ��д��ĸX������ISBN����0-670-82162-4�е�ʶ����4�������õ��ģ���067082162��9�����֣��������ң��ֱ����1��2��...,9,����ͣ���0��1+6��2+����+2��9=158��Ȼ��ȡ158 mod 11�Ľ��4��Ϊʶ���롣
	������������Ǳ�д�����ж������ISBN������ʶ�����Ƿ���ȷ�������ȷ����������Right��������������������Ϊ����ȷ��ISBN���롣

�����ʽ:
ֻ��һ�У���һ���ַ����У���ʾһ�����ISBN���루��֤�������ISBN����ĸ�ʽҪ�󣩡�

�����ʽ:
ֻ��һ�У����������ISBN�����ʶ������ȷ����ô�����Right�������򣬰��չ涨�ĸ�ʽ�������ȷ��ISBN���루�����ָ�����-������

����:
����
0-670-82162-4

���
Right

����
0-670-82162-X

���
0-670-82162-4
*/
#define ISBN_MAX 14
void ID10007()
{
	char ISBN[ISBN_MAX] = { 0 };
	gets(ISBN);

	int count = 0;

	int i = 0; int j = 1;
	//0-670-82162-4
	for (i = 0; i < 11; i++)
	{
		if ((ISBN[i] >=  '0') && (ISBN[i] <= '9'))
			count = count + (ISBN[i] - '0') * (j++);
	}
	count = count % 11;
	//printf("c = %d \n",count);


	if ((count == (ISBN[12]-'0') || ((count == 10) && (ISBN[12] == 'X'))))
	{
		printf("Right");
	}
	else
	{
		if(count == 10)
			ISBN[12] = 'X';
		else
		    ISBN[12] = count + '0';
		printf("%s", ISBN);
	}
}

/*
��Ŀ����(ID:12103)
����: 	�����
��ǩ: 	�ַ��� �ַ�������
����: 	���� n ����������n��20�� �����������ӳ�һ�ţ����һ�����Ķ�λ������
���磺n=3 ʱ��3 ������ 13��312��343 ���ӳɵ��������Ϊ��34331213
���磺n=4 ʱ��4 ������ 7��13��4��246 ���ӳɵ��������Ϊ��7424613

�����ʽ:
��һ��ֻ��һ�� n
�ڶ���Ϊ n ������

�����ʽ:
���ӳɵĶ�λ��

��ʾ: 	n<=20
ÿ������������20λ

����:
����
3
13 312 343

���
34331213
*/
static int MyCompare(char str1[], char str2[])
{
	int str1_Length = strlen(str1);
	int str2_Length = strlen(str2);
	//    abc    abc
	for (int i = 0; i < str1_Length; i++)
	{
		//���str1��str2�������
		if (i > str2_Length - 1)
		{
			return 1;
		}

		if (str1[i] > str2[i])
		{
			return 1;
		}
		else if (str1[i] < str2[i])
		{
			return -1;
		}
	}
	//str1�ĳ���С�ڻ����str2�ĳ���
	return str1_Length == str2_Length ? 0 : -1;
}

int str_cmp(char s1[], char s2[])
{
	int s1_len = strlen(s1) , s2_len = strlen(s2) ;
	int i = 0;
	int min = (s1_len < s2_len) ? s1_len : s2_len;

	while(i < min)
	{
		if (s1[i] > s2[i])
		{
			return 1;
		}
		i++;
	}
if (min == s2_len) return -1;
else	if (s1_len == s2_len) return 1;
	 
	else if (min == s1_len) return -1;
}

#define N_MAX 21
void ID12103()
{
	char n_arr[N_MAX*21] = { 0 };
	gets(n_arr);
	int n;
	if (n_arr[1] != 0)
		n = (n_arr[0] - '0') * 10 + (n_arr[1] - '0');
	else
		n = n_arr[0] - '0';
	
	gets(n_arr);
	char dest[21][21] = { 0 };
	
	int i = 0, k = -1, j = 0;
	int count = 0;
	printf("n = %d: %s\n", n, n_arr);

	for (i = 0; i <= strlen(n_arr); i++)
	{
		if ((n_arr[i] == ' ') || (n_arr[i] == '\0'))
		{
			memcpy(&dest[count++], &n_arr[k + 1], i - k - 1);
			k = i;
			printf("count = %d, k = %d \n", count, k);
			//printf("%s \n", &dest[count-1][0]);
		}
	}
 
	for (i = 0; i < n; i++)
	{
		//printf("%s \n", &dest[i][0]);
	    /*
	     ��str1==str2���򷵻��㣻
		 ��str1< str2���򷵻ظ�����
		 ��str1> str2���򷵻�������
		*/
		for (j = 0; j < n - i - 1; j++)
		{
			if (MyCompare(dest[j], dest[j + 1]) < 0)//(strcmp(&dest[j], &dest[j+1]) < 0)
			{
				char temp[21] = { 0 };
				strcpy_s(temp,21, &dest[j]);
				strcpy_s(&dest[j],21, &dest[j+1]);
				strcpy_s(&dest[j+1],21,temp);
			}
		}
	}
	
	for (i = 0; i <= n; i++)
	{
	   printf("%s", &dest[i][0]);
	}
	printf("\n");
}

/*
��Ŀ����(ID:12111)
����: 	���ѵĵ�ʽ
��ǩ: 	�ַ��� �ַ�������
����:
��һ�죬С��ѧ���˼Ӽ������㰮��������ʽ���㣬����a+b����a-b֮������⡣����ò��һ��ļӼ��������Ѳ���С�������ڣ�С������ʦ�뵽һ������С���İ취��������a+?=b �� ?+a=b �� a+b=?�����С���������ˣ������ҵ����㡣ע��ֻ����ּӼ����㡣

�����ʽ:
����һ����ʽ������a+b=c��a-b=c���������е�����������ȷ�����еĵ�������������0<=A,B,C<1,000,000,000��û�и���������һ�������ġ�������ʾ����ʽ��û�ж���ո�

�����ʽ:
ֱ�����Ҫ��ĵ���������

����: 	0<=A,B,C<1,000,000,000
����:

����
1+2=?

���
3

����
15+?=115

���
100
*/
void StringPlus(char A[], char B[], char C[]);
void StringMinus(char A[], char B[], char C[]);
#define NUM_SIZE 10
#define MAX_ARI  (NUM_SIZE + NUM_SIZE + 3 + 1)

void ID12111(void)
{
	char arithmetic[MAX_ARI] = { 0 };
	gets(arithmetic);

	//a+?=b �� ?+a=b �� a+b=?
	//a-b=? a-?=b ?-a=b

	//printf("%s\n", arithmetic);
	int i = 0, j = 0, k =0;
	int a = -1, b = -1, c = -1, d = -1;
	char A[NUM_SIZE + 1] = { 0 }; char B[NUM_SIZE + 1] = { 0 };
	char C[NUM_SIZE + 1] = { 0 };

	for (i = 0; i < MAX_ARI; i++)
	{
		char temp = arithmetic[i];
		if (temp == 0) break;

		if (temp == '?')
		{
			a = i;
		}
		else if (temp == '+')
		{
			b = i;
		}
		else if (temp == '=')
		{
			c = i;;
		}
		else if (temp == '-')
		{
			d = i;
		}
		else if ((temp >= '0') && (temp <= '9'))
		{
			if (a == 0)
			{	
				if (c != -1)
                   B[j++] = temp;
				else
				   A[k++] = temp;
			}
			else
			{
				if ((b != -1) || (d != -1))
					B[j++] = temp;
				else
					A[k++] = temp;
			}
		}
	}
	
	printf("%d, %d, %d, %d \n", a, b, c, d);
	for (i = 0; i < NUM_SIZE + 1; i++)
	{
		printf("%c", A[i]);
	}
	for (i = 0; i < NUM_SIZE + 1; i++)
	{
		printf("%c", B[i]);
	}
	printf("\n");

	j = 9; k = 9;
	for (i = NUM_SIZE - 1; i >= 0; i--)
	{
		if (A[i] != 0)
		{
			A[j--] = A[i];
			A[i] = '0';
		}

		if (B[i] != 0)
		{
			B[k--] = B[i];
			B[i] = '0';
		}
	}
	for (i = 0; i < NUM_SIZE; i++)
	{
		if (A[i] == 0) A[i] = '0';
		if (B[i] == 0) B[i] = '0';
	}

	for (i = 0; i < NUM_SIZE; i++)
	{
		printf("%c", A[i]);
	}
	printf("\n");
	for (i = 0; i < NUM_SIZE; i++)
	{
		printf("%c", B[i]);
	}
	if ((b != -1) && (d == -1)){
		if (((b < a) && (a < c)) || ((b > a) && (b < c)))
		{
			//a+?=b //?+a=b
			printf("\nb-a: \n");
			StringMinus(A,B,C);
		}
		else if ((a > b) && (a > c))
		{
			//a+b=?
			printf("\na+b: \n");
			StringPlus(A, B, C);
		}
	}
	if ((d != -1) && (b == -1))
	{
		if (((d < a) && (a < c)) || ((d < c) && (c < a)))
		{
			//a-?=b //a-b=?
			printf("\n:a-b: \n");
			StringMinus(B, A, C);
		}
		else if ((a < d) && (d < c))
		{
			//?-a=b
			printf("\n:a+b: \n");
			StringPlus(A, B, C);
		}
	}
	int flag = 0, flag1 = 0;
	for (i = 0; i < NUM_SIZE; i++)
	{
		if (C[i] != '0')
			flag1 = 1;

		if ((C[i-1] == '0') && (C[i] != '0'))
		{
			flag = 1;
		}
		if(flag == 1)
		  printf("%c", C[i]);
	}
	if (flag1 == 0) printf("0");
}

#define A(x) (A[(x)] - '0')
#define B(x) (B[(x)] - '0')

void StringMinus(char A[], char B[], char C[])
{
	int flag = 0;
	for (int i = NUM_SIZE - 1; i >= 0; i--)
	{
		if ((B(i) - A(i) == 0) && (flag == 1))
		{
			C[i] = '9';
			continue;
		}
		if (B(i) - A(i) < 0)
		{
			if (flag == 1)
				C[i] = -1 + B(i) - A(i) + 10 + '0';
			else
				C[i] = B(i) - A(i) + 10 + '0';
			flag = 1;
		}
		else
		{
			if (flag == 1)
			{
				flag = 0;
				C[i] = B(i) - A(i) - 1 + '0';
			}
			else
				C[i] = B(i) - A(i) + '0';
		}
	}
}

void StringPlus(char A[], char B[], char C[])
{
	int flag = 0;
	for (int i = NUM_SIZE - 1; i >= 0; i--)
	{
		if ((A(i) + B(i) == 9) && (flag == 1))
		{
			C[i] = '0';
			continue;
		}
		if (A(i) + B(i) > 9)
		{
			if (flag == 1)
				C[i] = 1 + A(i) + B(i) - 10 + '0';
			else
				C[i] = A(i) + B(i) - 10 + '0';
			flag = 1;
		}
		else
		{
			if (flag == 1)
			{
				flag = 0;
				C[i] = 1 + A(i) + B(i) + '0';
			}
			else
				C[i] = A(i) + B(i) + '0';
		}
	}
}

/*
��Ŀ����(ID:12078)
����: 	�ֻ�
��ǩ: 	�ַ��� �ַ�������
����: 	�ֻ��ļ����������ģ�
1            2 abc    3 def
4 ghi      5 jkl      6 mno
7 pqrs    8 tuv    9 wxyz

Ҫ����Ӣ����ĸ�ͱ���Ҫ�����ּ����¡�����Ҫ����x�͵ð�9���£���һ�»��w�����ڶ��»��w���x��0����һ�»��һ���ո�
��������Ƕ�ȡ���ɾ�ֻ����Ӣ��Сд��ĸ�Ϳո�ľ��ӣ����Ҫ���ֻ��ϴ���������������Ҫ�������¼��̡�

�����ʽ:
һ��һ�����ӣ�ֻ����Ӣ��Сд��ĸ�Ϳո��Ҳ�����200���ַ���

�����ʽ:
һ��һ����������ʾ�����̵��ܴ�����

����:
����
i have a dream

���
23
*/
#define PHONE_MAX  201
void ID12078(void)
{
	char phone_words[PHONE_MAX] = { 0 };
	gets(phone_words);

	char key[27][2] = {
		{ ' ', 1 },
		{ 'a', 1 },{ 'b', 2 },{ 'c', 3 },
		{ 'd', 1 },{ 'e', 2 },{ 'f', 3 },
		{ 'g', 1 },{ 'h', 2 },{ 'i', 3 },
		{ 'j', 1 },{ 'k', 2 },{ 'l', 3 },
		{ 'm', 1 },{ 'n', 2 },{ 'o', 3 },
		{ 'p', 1 },{ 'q', 2 },{ 'r', 3 },{ 's', 4 },
		{ 't', 1 },{ 'u', 2 },{ 'v', 3 },
		{ 'w', 1 },{ 'x', 2 },{ 'y', 3 },{ 'z', 4 },
	};

	int i = 0, j = 0;
	int time = 0;
	for (i = 0; i < strlen(phone_words); i++)
	{
		for (j = 0; j < 27; j++)
		{
			if (key[j][0] == phone_words[i])
			{
				time += key[j][1];
			}
		}
	}

	printf("time = %d \n", time);
}


/*
��Ŀ����(ID:10009)
����: 	���ַ�ת
��ǩ: 	�ַ��� ģ�� �ַ�������
����: 	����һ���������뽫��������λ�����ַ�ת�õ�һ������������ҲӦ���������ĳ�����ʽ�������Ǹ�����ԭ��Ϊ�㣬����ת��õ������������λ���ֲ�ӦΪ�㣨�μ�����2����

�����ʽ:
���빲1 �У�һ������N��

�����ʽ:
�����1 �У�һ����������ʾ��ת���������

��ʾ: 	NOIP�ռ���2011
����: 	-1,000,000,000 �� N �� 1,000,000,000 ��
ÿ�����Ե�1s
����:

����
-290

���
-92

����
900000000

���
9
*/
void ID10009()
{
#define NUM 10001

	char string[NUM] = { 0 };
	char dest[NUM] = { 0 };
	gets(string);

	int temp = 0;
	int i = 0;

	for (i = NUM; i >= 0; i--)
	{
		if (string[i] > '0')
		{
			temp = i + 1;
			break;
		}
	}
	if (string[0] == '-')
	{
		temp--;
		printf("-");
		for (i = temp; i > 0; i--)
		{
			printf("%c", string[i]);
		}
	}
	else if (string[0] == '0')
	{
		printf("%c", string[i]);
	}
	else {
		printf("%d=", temp);
		for (i = temp - 1; i >= 0; i--)
		{
			printf("%c", string[i]);
		}
	}
}

/*
��Ŀ����(ID:12079)
����: 	����
��ǩ: 	�ַ��� �ַ�������
����: 	ĳ�������ѧУOI��ÿ��ͬѧ�����գ������մӴ�С��˳�����򡣵�����ҵ�ܶ࣬û��ʱ�䣬���������������

�����ʽ:
��2�У�
��1��ΪOI��������n��
��2������n+1�зֱ���ÿ�˵�����s��������y����m����d��

�����ʽ:
��n�У�
��n�����մӴ�Сͬѧ�����������ͬ��ͬ��ͬ���������������ֵ���Ӵ�С��
����: 	1
����:

����
3
Yangchu 1992 4 23
Qiujingya 1993 10 13
Luowen 1991 8 1

���
Luowen
Yangchu
Qiujingya
*/
#define BIRTHDAY_MAX  50
#define BIRTHDAY_DAY 9
void ID12079()
{
	char p[BIRTHDAY_MAX] = { 0 };
	gets(p);

	//���ж��������Ĵ�С
	int times = 0;
	if (p[1] != 0)
		times = (p[0] - '0') * 10 + (p[1] - '0');
	else
		times = p[0] - '0';
	printf("p = %d \n",times);

	int i = 0;
	/*
	//char **name = (char **)malloc(sizeof(char) * times);
	char *name[10];
	for (int i = 0; i < times; i++)
	{
		name[i] = (char *)malloc(sizeof(char) * BIRTHDAY_MAX);
	}
	//char **birthday = (char **)malloc(sizeof(char) * times);
	char *birthday[10];
	for (int i = 0; i < times; i++)
	{
		birthday[i] = (char *)malloc(sizeof(char) * BIRTHDAY_DAY);
	}
	*/
	char name[100][20] = { 0 };
	char birthday[100][9] = { 0 };
	int j = 0;
	while (times--)
	{
		int k = 0,l = 0;
		char temp = 0;
		gets(p);
		for (i = 0; i < strlen(p); i++)
		{
			temp = p[i];
			if (temp >= '0' && temp <= '9')
			{
				birthday[j][l++] = temp;
			}
			else
			{
				if (temp != ' ')
					name[j][k++] = temp;
				else
				{
					//1990 5 3
					if ((l == 4) && (p[i+2] == ' '))
					{
						birthday[j][l++] = '0';
					}
					if ((l > 4) && (p[i + 2] == 0))
					{
						birthday[j][l++] = '0';
					}
				}
			}
		}

		name[j][k++] = '\0';
		birthday[j][l++] = '\0';
		j++;
	}
	for (i = 0; i < j; i++)
	{
		printf("%s %s\n",&name[i][0], &birthday[i][0]);
	}
	/*
	��str1==str2���򷵻��㣻
	��str1< str2���򷵻ظ�����
	��str1> str2���򷵻�������
	*/
	int m = 0;
	//int *sort = malloc(sizeof(int) * j);
	int sort[100] = { 0 };
	for (i = 0; i < j; i++) sort[i] = -1;
	char *max = NULL;
	for (i = 0; i < j; i++)
	{
		
		for (int k = 0; k < j; k++)
		{
			if (sort[k] != i)
			{
				max = birthday[i];
				//printf("next = %d %s\n ",i,max);
				break;
			}
		}
		
		for (int k = 0; k < j; k++)
		{
			if (strcmp(birthday[k],max) >= 0)
			{
				max = birthday[k];
				sort[m] = k;
			}
		}
		printf("sort[%d] = %d, %s \n", m, sort[m], birthday[sort[m]]);
		memset(birthday[sort[m]], '0', BIRTHDAY_DAY);// sizeof(char) * BIRTHDAY_MAX);
		m++;
	}

	for (i = j-1; i >= 0; i--)
	{
		printf("%s\n", name[sort[i]]);
	}
}

/*
��Ŀ����(ID:12073)
����: 	vigenere����
��ǩ: 	�ַ��� �ַ�������
����: 	16���ͷ����⽻��Blaise de Vigen��re�����һ�ֶ����������㷨����Vigen��re���롣Vigen��re����ļ��ܽ����㷨�����ã��������ѶȱȽϸߣ����������ϱ�ս����Ϊ�Ͼ����㷺ʹ�á�
������ѧ�У����ǳ���Ҫ���ܵ���ϢΪ���ģ���M��ʾ���Ƽ��ܺ����ϢΪ���ģ���C��ʾ������Կ��һ�ֲ������ǽ�����ת��Ϊ���Ļ�����ת��Ϊ���ĵ��㷨����������ݣ���Ϊk�� ��Vigen��re�����У���Կk��һ����ĸ����k=k1k2��kn��������M=m1m2��mnʱ���õ�������C=c1c2��cn������ci=mi@ki��@�����������Ĺ������±���ʾ��
Vigenere�����ڲ���ʱ��Ҫע�⣺
1. ?������Բ����������ĸ�Ĵ�Сд����������ĸ������M�еĴ�Сд��ʽ��
2. ������M�ĳ��ȴ�����Կk�ĳ���ʱ������Կk�ظ�ʹ�á�

�����ʽ:
���빲2�С�
��һ��Ϊһ���ַ�������ʾ��Կk�����Ȳ�����100�����н�������Сд��ĸ���ڶ���Ϊһ���ַ�������ʾ�����ܺ�����ģ����Ȳ�����1000�����н�������Сд��ĸ��

�����ʽ:
�����1�У�һ���ַ�������ʾ������Կ����������Ӧ�����ġ�

��ʾ: ci=(mi-��A��+ki-��A��)mod26+��A����
����: ����100%�����ݣ��������Կ�ĳ��Ȳ�����100����������ĵĳ��Ȳ�����1000���Ҷ�������Ӣ����ĸ��
����:

����
CompleteVictory
Yvqgpxaimmklongnzfwpvxmniytm

���
Wherethereisawillthereisaway
*/
#define V_MAX_K  101
#define V_MAX_C  1001
void ID12073()
{
	char ci[V_MAX_C] = { 0 };
	char ki[V_MAX_K] = { 0 };
	char mi[V_MAX_C] = { 0 };

	int  i = 0,j = 0;
	gets(ki);
	gets(ci);

	//printf("%s, %s \n", ki, ci);
	int len = strlen(ci) / strlen(ki);

	for (i = 0; i < strlen(ci); i++)
	{
		char k = 0;
		char temp = ci[i];

		if(j >= strlen(ki))
		  j = 0;
#if 0
		if ((ki[j] >= 'A' && ki[j] <= 'Z' && temp >= 'a' && temp <= 'z'))
			ki[j] += 32;
		//СдתΪ��д
		char flag = 0;
		if (temp >= 'a' && temp <= 'z')
		{
			for (k = 0; k <= 26; k++)
			{
				if (temp == ((k + (ki[j] - 'a')) % 26 + 'a'))
				{
					//flag = 1;
					k = k + 'a';
					break;
				}
			}
		}
		if (temp >= 'A' && temp <= 'Z')
		{
			for (k = 0; k <= 26; k++)
			{
				if (temp == ((k + (ki[j] - 'A')) % 26 + 'A'))
				{
					k = k + 'A';
					break;
				}
			}
		}
#else
		char flag = 0;
		if (ki[j] >= 'a' && ki[j] <= 'z')
			ki[j] -= 32;

		if (temp >= 'a' && temp <= 'z')
		{
			flag = 1;
			temp -= 32;
		}
		for (k = 0; k <= 26; k++)
		{
			if (temp == ((k + (ki[j] - 'A')) % 26 + 'A'))
			{
				break;
			}
		}
#endif
		j++;
		k = k + 'A';
		if (flag) k += 32;
		mi[i] = k;
		printf("%c", k);
	}
	mi[i+1] = '\0';

	//printf("%s\n", mi);
}

/*
��Ŀ����(ID:12025)
����: 	1.1-4����������
��ǩ: 	�ַ��� �ַ�������
����: 	����һ����N����ɫ�ģ���ɫ�ģ�����ɫ��������ɵ�����(3<=N<=350)�����������ⰲ�ŵġ� ������ n=29 �Ķ�������:

    1 2                               1 2
r b b r                           b r r b
r         b                       b         b
r           r                     b           r
r             r                   w             r
b               r                 w               w
b                 b               r                 r
b                 b               b                 b
b                 b               r                 b
r               r                 b               r
b             r                   r             r
b           r                     r           r
r       r                         r       b
r b r                             r r w
ͼƬ A                             ͼƬ  B

r ���� ��ɫ������
b ���� ��ɫ������
w ���� ��ɫ������
��һ�͵ڶ���������ͼƬ���Ѿ������Ǻš�
ͼƬ A �е�����������������ַ�����ʾ��
brbrrrbbbrrrrrbrrbbrbbbbrrrrb
������Ҫ��һЩ���������,չ����һ��ֱ�ߣ�Ȼ���һ�˿�ʼ�ռ�ͬ��ɫ������ֱ��������һ����ͬ����ɫ���ӣ�����һ����ͬ������(��ɫ����������֮ǰ�ռ��Ĳ�ͬ)�� ȷ��Ӧ������������������ռ��������Ŀ�����ӡ�
���磬��ͼƬ A �е������У������� 9 ������ 10 ������ 24 ������ 25 ֮�������������ռ���8�����ӡ�
��ɫ����ʲô��˼?

��һЩ�����л�������ɫ������(��ͼƬB) ��ʾ��
���ռ����ӵ�ʱ��һ���������İ�ɫ���ӿ��Ա�������ɫҲ���Ա�������ɫ��
���ֺ��а����������ַ������������������ r �� b �� w ��
дһ��������ȷ����һ�������������������ռ��������������Ŀ��

�����ʽ:
�� 1 ��: N, ���ӵ���Ŀ
�� 2 ��: һ������ΪN���ַ���, ÿ���ַ��� r �� b �� w��

�����ʽ:
������һ�� ������ȡ�õ�������

��ʾ: 	USACO Training
����: 	ÿ�����Ե�1��
����:

����
29
wwwbbrwrbrbrrbrbrwrwwrbwrwrrb

���
11
*/

#define  MAX_BEADS  350
void ID12025()
{
	char p[MAX_BEADS] = { 0 };
	gets(p);
	/*
	//���ж��������Ĵ�С
	int times = 0;
	if (p[2] != 0)
		times = (p[0] - '0') * 100 + (p[1] - '0') * 10 + (p[2] - '0');
	else if (p[1] != 0)
		times = (p[0] - '0') * 10 + (p[1] - '0');
	else
		times = p[0] - '0';
	printf("p = %d \n", times);

	gets(p);
	
	int *dest = malloc(sizeof(int)*times);
	*/
	int dest[MAX_BEADS] = { 0 };
	int i = 0, j = 0, flag = 0;
	int w = 0, b = 0, r = 0;
	for (i = 0; i < strlen(p); i++)
	{
		//printf("=%c=\n",p[i]);
		//wwwbbrwrbrbrrbrbrwrwwrbwrwrrb
		if ((p[i] == 'w') && j==0)
		{
			w++;
			if (p[i + 1] != 'w')
			{
				dest[j++] = w;
				printf("w%d", w);
				flag = 1;
			}
			continue;
		}
		if (p[i] == 'r')
		{
			r++;
			if(b != 0){
				dest[j++] = b;
			    printf("b%d", b);
			    b = 0;
			}
		}
		else if (p[i] == 'b')
		{
			b++;
			if(r != 0){
				dest[j++] = r;
			    printf("r%d", r);
			    r = 0;
			}
		}
		else
		{
			if (r != 0)
				r++;
			else
				b++;
		}
	}
	if (b != 0)
	{
		dest[j] = b;
		printf("b%d", b);
	}
	else if (r != 0)
	{
		dest[j] = r;
		printf("r%d", r);
	}
	if ((i == w) || (i == b) || (i == r))
	{
		p[0] = i;
	}
	else
	{/*
		i--;
		//printf("\n[0]%c, [w]%c, [i]%c \n",p[0], p[w], p[i]);
		//printf("i=%d, j=%d \n", i, j);

		//����û���ƣ����ӣ�wwwwrbrbrww������
		if (((p[0] == 'w') || (p[i] == 'w') || (p[0] == p[i])) && (j>2))
		{
			//����β��ͬ or �׻�βΪ'w'������β����
			dest[j] = dest[0] + dest[j];
			//dest[0] = dest[j];
			int temp = dest[j];
			//����ʼ��'w'����ȥ'w'��������ַ���ĩβ��ͬ�������ߵ���
			if ((p[w] == p[i]) && (flag == 1))
			{
				dest[j] += dest[1];
			}
			//����ʼ��'w'������ӵ�'w'��һ���ַ�
			if (p[0] == 'w')
				dest[1] += w;
		}
		else
		{
			dest[0] += w;
		}*/
	}
	printf("\n");
	for (i = 0; i <= j; i++)
	{
		printf("%d", dest[i]);
	}
	
	int max = dest[0];
	for (i = 0; i < j; i++)
	{
		if (dest[i] + dest[i + 1] > max)
			max = dest[i] + dest[i + 1];
	}
	printf("\nmax = %d \n",max);
	//printf("%d", max);

	//free(dest);
}


int ID12025_1(char p[],int len)
{
	int dest[MAX_BEADS] = { 0 };
	int i = 0, j = 0, flag = 0;
	int w = 0, b = 0, r = 0;

	for (i = 0; i < len; i++)
	{
		if ((p[i] == 'w') && j == 0)
		{
			w++;
			if (p[i + 1] != 'w')
			{
				dest[j++] = w;
				printf("w%d", w);
			}
			continue;
		}
		if (p[i] == 'r')
		{
			r++;
			if (b != 0) {
				dest[j++] = b;
				printf("b%d", b);
				b = 0;
			}
		}
		else if (p[i] == 'b')
		{
			b++;
			if (r != 0) {
				dest[j++] = r;
				printf("r%d", r);
				r = 0;
			}
		}
		else {
			if (r != 0)
				r++;
			else
				b++;
		}
	}
	if (b != 0)
	{
		dest[j] = b;
		printf("b%d", b);
	}
	else if (r != 0)
	{
		dest[j] = r;
		printf("r%d", r);
	}
	if (w != 0)
	{
		dest[1] += dest[0];
		dest[0] = 0;
	}
	/*
	printf("\n");
	for (i = 0; i <= j; i++)
	{
		printf("%d", dest[i]);
	}
	*/
	int max = dest[0];
	for (i = 0; i < j; i++)
	{
		if (dest[i] + dest[i + 1] > max)
			max = dest[i] + dest[i + 1];
	}
	printf("\nmax = %d", max);

	return max;
}
int ID12025_2(char p[], int len)
{
	int dest[MAX_BEADS] = { 0 };
	int i = 0, j = 0, flag = 0;
	int w = 0, b = 0, r = 0;

	for (i = len - 1; i >= 0; i--)
	{
		if ((p[i] == 'w') && j == 0)
		{
			w++;
			if (p[i - 1] != 'w')
			{
				dest[j++] = w;
				printf("w%d", w);
			}
			continue;
		}
		if (p[i] == 'r')
		{
			r++;
			if (b != 0) {
				dest[j++] = b;
				//printf("b%d", b);
				b = 0;
			}
		}
		else if (p[i] == 'b')
		{
			b++;
			if (r != 0) {
				dest[j++] = r;
				//printf("r%d", r);
				r = 0;
			}
		}
		else
		{
			if (r != 0)
				r++;
			else
				b++;
		}
	}
	if (b != 0)
	{
		dest[j] = b;
		//printf("b%d", b);
	}
	else if (r != 0)
	{
		dest[j] = r;
		//printf("r%d", r);
	}
	if (w != 0)
	{
		dest[1] += dest[0];
		dest[0] = 0;
	}
	/*
	printf("\n");
	for (i = 0; i <= j; i++)
	{
		printf("%d", dest[i]);
	}
   */
	int max = dest[0];
	for (i = 0; i < j; i++)
	{
		if (dest[i] + dest[i + 1] > max)
			max = dest[i] + dest[i + 1];
	}
	printf("\nmax = %d", max);

	return max;
}

void ID12025_3(char p[], int len, int flag)
{
	int dest[MAX_BEADS] = { 0 };
	int i = 0, j = 0;
	int w = 0, b = 0, r = 0;
	int count = 0;
	if (flag == 1) i = len;

	while ((flag ? (i--) : (i++) && (i != len)))

	//for (i = len - 1; i >= 0; i--)
	{
		//printf("i = %d\n", i);
		if (p[i] == 'r')
		{
			r++;
			if (b != 0) {
				dest[j++] = b;
				printf("b%d", b);
				b = 0;
			}
		}
		else if (p[i] == 'b')
		{
			b++;
			if (r != 0) {
				dest[j++] = r;
				printf("r%d", r);
				r = 0;
			}
		}
		else if (p[i] == 'w')
		{
			if (j == 0)
			{
				w++;
				int temp = flag ? (i - 1) : (i + 1);
				if (p[temp] != 'w')
				{
					dest[j++] = w;
					printf("w%d", w);
				}
			}
			if (r != 0)
				r++;
			else
				b++;
		}
	}
	if (b != 0)
	{
		dest[j] = b;
		printf("b%d", b);
	}
	else if (r != 0)
	{
		dest[j] = r;
		printf("r%d", r);
	}
	if (w != 0)
	{
		dest[1] += dest[0];
		dest[0] = 0;
	}
	printf("\n");
	for (i = 0; i <= j; i++)
	{
		printf("%d", dest[i]);
	}

	int max = dest[0];
	for (i = 0; i < j; i++)
	{
		if (dest[i] + dest[i + 1] > max)
			max = dest[i] + dest[i + 1];
	}
	printf("\nmax = %d \n", max);
}
int ID12025_sort()
{
	char p[MAX_BEADS] = { 0 };
	gets(p);
	//printf("%d \n", atof(p));

	int len = strlen(p);
	char temp = 0;
	int max = 0; int max_temp = 0;
	for (int i = 0; i < len; i++)
	{
		
		max_temp = ID12025_1(p, strlen(p));
		if (max < max_temp) max = max_temp;
		max_temp = ID12025_2(p, strlen(p));
		if (max < max_temp) max = max_temp;

		temp = p[0];
		for (int i = 0; i < len-1; i++)
		{
			p[i] = p[i + 1];
		}
		p[len-1] = temp;

		printf("\n%s\n",p);
	}
	printf("max = %d \n", max);
	//ID12025_3(p, strlen(p),1);
	//ID12025_3(p, strlen(p), 0);
}

/*
��Ŀ����(ID:12048)
����: 	1.1-1��ķɵ�������
��ǩ: 	�ַ��� �ַ�������
����:
������֪����ÿһ�����Ǻ���һֻUFO����ЩUFOʱ�����ռ������ϵ��ҳ�֧���ߡ����ҵ��ǣ����ǵķɵ�ÿ�γ��ж�ֻ�ܴ���һ��֧���ߡ���ˣ�����Ҫ��һ�ִ����ķ�������ЩС����ǰ֪��˭�ᱻ���Ǵ��ߡ�����Ϊÿ����������һ�����֣�ͨ����Щ�������������С���ǲ��Ǳ����ߵ��Ǹ��ض���С�飨����Ϊ��˭����Щ����ȡ�������أ�����������δ����ϸ�ڻ�����������㣻���������дһ������ͨ��С���������������������С���Ƿ��ܱ��ǿ����Ǻ����UFO���ߡ�
С�������������������з�ʽת����һ�����֣����յ����־���������������ĸ�Ļ������С�A����1����Z����26�����磬��USACO��С�����21*19*1*3*15=17955�����С������� mod 47�������ǵ�����mod 47,��͵ø������С����Ҫ׼���ñ����ߣ�����ס��a mod b����a����b��������34 mod 10����4��һ����ԣ������е�a�Ǹ���ʱ������b�ķ�����ν�����Ǹ�������������ѧ������ȴ������������Ҫ���ǣ���
д��һ�����򣬶�����������С���������������ķ����ܷ��������ִ�������������ܴ��䣬�������GO�������������STAY����С����������������û�пո�����һ����д��ĸ��������6����ĸ����

�����ʽ:
�� 1 ��:
���ǵ����֣�һ������Ϊ1��6���ַ�����
�� 2 ��:
��������֣�һ������Ϊ1��6���ַ�����

�����ʽ:
����һ�а���"STAY"��"GO"
����: 	1s
����:

����
COMETQ
HVNGAT

���
GO

����
ABSTAR
USACO

���
STAY
*/
#define UFO_MAX 10
#define X 47

int ufo_c(int num[], int len)
{
	int i = 0;
	int a = 0, b = 0, c = 0, d = 0;
	a = num[0] % X;
	//printf("\na = %d \n", a);
	for (i = 1; i < len; i++)
	{
		a = ((X + a) * num[i]) % X;
		//printf("a = %d \n", a);
	}
	return a;
}

void ID12048()
{
	char ufo[UFO_MAX] = { 0 };

	int num[6] = { 0 };
	int i = 0,j = 0;
	int times = 2;
	int result[2] = { 0 };
	while(times--)
	{ 
		gets(ufo);
		for (i = 0; i < 6; i++)
		{
			if (ufo[i] >= 'A' && ufo[i] <= 'Z')
			{
				num[j++] = ufo[i] - 'A' + 1;
				//printf("%d ", num[j - 1]);
			}
		}
		result[times] = ufo_c(num, j);
        //printf("%d", result[times]);
		j = 0;
	}
	if(result[0] == result[1])
	{
		printf("GO");
	}
	else
	{
		printf("STAY");
	}
}

/*
��Ŀ����(ID:10016)
����: 	ƹ����
��ǩ: 	�ַ��� �ַ�������
����: 	����ͨ�����·�ʽ���з��������Ƚ�����ÿ�����ʤ���г�һ�ű�Ȼ��ֱ������11���ƺ�21�����£�˫���ı��������������¼ĩβ����
���������ʵ�ʱ���������ͬ, ���ȷ�Ϊ10:11ʱ��Ҫ����������ֱ���������ﵽ2��.
������������ôһ�ݼ�¼��������W��ʾ�������һ�֣�L��ʾ�������ֻ��һ�֣���
WWWWWWWWWWWWWWWWWWWWWWLW
��11�����£���ʱ�����Ľ���ǻ�����һ��11��0��ʤ���ڶ���11��0��ʤ�����ڽ��е����֣���ǰ�ȷ�1��1������21�����£���ʱ��������ǻ�����һ��21��0��ʤ�����ڽ��еڶ��֣��ȷ�2��1�����һ�ֱ����տ�ʼ�����ʱ�ȷ�Ϊ0��0��
��ĳ������Ҫ����һϵ�б�����Ϣ�����루WL��ʽ���������ȷ�Ľ����

�����ʽ:
ÿ�������ļ������������ַ�����ÿ������20����ĸ�����ַ����д�д��W��L��E���,Ҳ���м������ɸ��ո�����E��ʾ������Ϣ����������Ӧ�ú���E֮�����������,E��������и������֡�

�����ʽ:
�������������ɣ�ÿ�����������У�ÿһ�ж�Ӧһ�ֱ����ıȷ֣���������Ϣ����˳�򣩡����е�һ������11�����µĽ�����ڶ�������21�����µĽ����������֮����һ�����зָ���

��ʾ: 	NOIP�ռ���2003
����: 	30%����������ֻ��һ���ַ���
100%����������ֻ���������ַ���
����:

����
WWWWWWWWWWWWWWWWWWWWWWLW

���
11:0
11:0
1:1

21:0
2:1

����
WWWWWWWWWWWWWWWWWWWW
WWLWEWWWW

���
11:0
11:0
1:1

21:0
2:1
*/
#define PP_MAX  30
#define PP_FIRST_MAX 150
int WL[10][2] = { 0 };
int WWLL[10][2] = { 0 };

int L = 0, W = 0;int j = 0;
void pp_c(char pp[], int len, int x)
{
	for (int i = 0; i < len; i++)
	{
		if (pp[i] == 'E')
			break;
		else if (pp[i] == 'W')
			W++;
		else
			L++;

		if ((W >= x || L >= x) && ((W - L >= 2) || (L - W >= 2)))
		{
			WL[j][0] = W; WL[j][1] = L;
			j++;
			W = 0; L = 0;
		}
	}
	if ((W != 0 || L != 0) && (len > 20))
	{
		WL[j][0] = W; WL[j][1] = L;
		j++;
	}
}
int LL = 0, WW = 0;int jj = 0;
void pp_cc(char pp[], int len, int x)
{
	for (int i = 0; i < len; i++)
	{
		if (pp[i] == 'E')
			break;
		else if (pp[i] == 'W')
			WW++;
		else
			LL++;

		if ((WW >= x || LL >= x) && ((WW - LL >= 2) || (LL - WW >= 2)))
		{
			WWLL[jj][0] = WW; WWLL[jj][1] = LL;
			jj++;
			WW = 0;LL = 0;
		}
	}
	if ((WW != 0 || LL != 0) && (len > 20))
	{
		WWLL[jj][0] = WW; WWLL[jj][1] = LL;
		jj++;
	}
}

void ID10016()
{
	char pp[PP_MAX] = { 0 };
	char pp_f[PP_FIRST_MAX] = { 0 };
	gets(pp_f);

	int flag = 0;
	int pp_len = strlen(pp_f);
	if (pp_len > 20)
	{
		pp_c(pp_f, strlen(pp_f), 11);
		pp_cc(pp_f, strlen(pp_f), 21);
	}
	else
	{
		pp_c(pp_f, strlen(pp_f), 11);
		pp_cc(pp_f, strlen(pp_f), 21);
		while (1)
		{
			gets(pp);
			if ((pp[0] == '\n') || (pp[0] == '\r') || (pp[0] == '\0')) break;
			pp_c(pp, strlen(pp), 11);
			pp_cc(pp, strlen(pp), 21);
			if (strlen(pp) < 20) break;
		}
		if (W != 0 || L != 0)
		{
			WL[j][0] = W; WL[j][1] = L;
			j++;
		}
		if (WW != 0 || LL != 0)
		{
			WWLL[jj][0] = WW; WWLL[jj][1] = LL;
			jj++;
		}
	}
	//printf("\n\n");
	for (int i = 0; i < j; i++)
	{
		//printf("%d:%d\n", WL[i][0], WL[i][1]);
		printf("11���ƾ���%d - W:%d L:%d \n", i, WL[i][0], WL[i][1]);
	}
	printf("\n");
	for (int i = 0; i < jj; i++)
	{
		//printf("%d:%d\n", WWLL[i][0], WWLL[i][1]);
		printf("21���ƾ���%d - W:%d L:%d \n", i, WWLL[i][0], WWLL[i][1]);
	}
}

/*
��Ŀ����(ID:10022)
����: 	Ǳ����
��ǩ: 	�ַ��� ģ�� �ַ�������
����: 	R ���� S��������ս��֮�У�˫�������ɼ����Ǳ��Է��ڲ����Ż��ж���
�������պ�Ǳ���� S���� R �����С C ���������� S����������ı������
1�� S �������ڲ������͵�ԭ��Ϣ�������ܺ��������Ϸ��ͣ�ԭ��Ϣ����������ܺ���
�õ����ݾ��ɴ�д��ĸ��A��-��Z�����ɣ��޿ո�������ַ��� ��
2�� S������ÿ����ĸ�涨�˶�Ӧ�ġ����֡� �����ܵĹ��̾��ǽ�ԭ��Ϣ�е�������ĸ��
��Ϊ���Ӧ�ġ����֡� ��
3�� ÿ����ĸֻ��Ӧһ��Ψһ�ġ����֡� ����ͬ����ĸ��Ӧ��ͬ�ġ����֡� �� �����֡�����
��ԭ��ĸ��ͬ��
���磬���涨��A��������Ϊ��A�� �� ��B��������Ϊ��C�� ��������ĸ�������ԣ� ����ԭ��
Ϣ��ABA��������Ϊ��ACA�� ��
���ڣ�С C ͨ������������ S �������Ϸ��͵�һ��������Ϣ�����Ӧ��ԭ��Ϣ��С C
ϣ����ͨ��������Ϣ������ S ���ľ������롣С C ����������������ģ�ɨ��ԭ��Ϣ����
��ԭ��Ϣ�е���ĸ x��������һ��д��ĸ�� ���ҵ����ڼ�����Ϣ�еĶ�Ӧ��д��ĸ y������Ϊ
�������� y�� x �����֡���˽�����ȥֱ��ֹͣ�����µ�ĳ��״̬��

1�� ������Ϣɨ����ϣ� ��A��-��Z�� ���� 26 ����ĸ��ԭ��Ϣ�о����ֹ����������Ӧ
�ġ����֡� ��
2�� ������Ϣɨ����ϣ������ִ���ĳ������ĳЩ����ĸ��ԭ��Ϣ��û�г��֡�
3�� ɨ���з������յ���Ϣ�������Ե�����ì�ܻ����Υ�� S������ı������ ����
��ĳ����Ϣ��XYZ��������Ϊ��ABA����Υ���ˡ���ͬ��ĸ��Ӧ��ͬ���֡��Ĺ���

��С C æ��ͷ������֮�ʣ�R ��˾��ַ����籨��Ҫ������������һ���� S ���ո�
��ȡ���ļ�����Ϣ�������������С C��ͨ���������յ���Ϣ�������������롣Ȼ��������
������룬����籨�еļ�����Ϣ��

�����ʽ:
���빲3�У�ÿ��Ϊһ�������� 1 ��100 ֮����ַ�����
�� 1 ��ΪСC ���յ�һ��������Ϣ��
�� 2 ��Ϊ��1 �еļ�����Ϣ����Ӧ��ԭ��Ϣ��
�� 3 ��ΪR��˾�Ҫ��С C ����ļ�����Ϣ��
�������ݱ�֤�����ַ������ɴ�д��ĸ��A��-��Z�����ɣ��ҵ� 1 �г������ 2 ����ȡ�

�����ʽ:
�����1�С�
����������ֹͣʱ���� 2��3 ������������������Failed�� ���������ţ�ע������ĸ��
д������Сд�� ��
����������������뷭��籨�м�����Ϣ��õ���ԭ��Ϣ��

��ʾ: 	NOIP�����2009
����: 	ÿ�����Ե�1s
����:

����
AA
AB
EOWIE

���
Failed

����
ԭ��Ϣ�е���ĸ��A���͡�B����Ӧ��ͬ�����֣������Failed����

����
QWERTYUIOPLKJHGFDSAZXCVBN
ABCDEFGHIJKLMNOPQRSTUVWXY
DSLIEWO

���
Failed

����
��ĸ��Z����ԭ��Ϣ��û�г��֣������Failed����

����
MSRTZCJKPFLQYVAWBINXUEDGHOOILSMIJFRCOPPQCEUNYDUMPP
YIZSDWAHLNOVFUCERKJXQMGTBPPKOIYKANZWPLLVWMQJFGQYLL
FLSO

���
NOIP
*/
#define MI_MAX 101
void ID10022()
{
	char mi_d[MI_MAX] = { 0 };
	char mi_s[MI_MAX] = { 0 };
	char mi[MI_MAX] = { 0 };

	char dest[26] = { 0 };

	gets(mi_d); gets(mi_s); gets(mi);

	int i = 0, j = 0;
	for (i = 0; i < strlen(mi_s); i++)
	{
		if(dest[mi_d[i] - 'A'] == 0)
		  dest[mi_d[i] - 'A'] = mi_s[i];
		else
		{
			//�Ѿ��������Ϣ �� ���µ���Ϣ ��ͬ������
			if (dest[mi_d[i] - 'A'] != mi_s[i])
			{
				printf("Failed-1\n");
				return;
			}
		}
	}
	int flag = 0;
	for (i = 0; i < 26; i++)
	{
		if (dest[i] == 0)
		{
			printf("Failed-2\n");//flag = 1;
			return;
		}
	}


	for (i = 0; i < strlen(mi); i++)
	{
		printf("%c", dest[mi[i] - 'A']);
	}
}

/*
��Ŀ����(ID:10012)
����: 	����ͳ��
��ǩ: 	ģ��
����: 	��ͳ��ĳ��������Χ[L, R]�����������У�����2���ֵĴ�����
�����ڸ�����Χ[2, 22]������2����2�г�����1�Σ�����12�г�����1�Σ�����20�г�����1�Σ�����21�г�����1�Σ�����22�г�����2�Σ���������2�ڸ÷�Χ��һ��������6�Ρ�

�����ʽ:
���빲һ�У�Ϊ����������L��R��֮����һ���ո������

�����ʽ:
�����1�У���ʾ����2���ֵĴ�����

��ʾ: 	NOIP�ռ���2010
����: 	1��L��R��10000
ÿ�����Ե�1��
����:

����
3 22

���
5

����
2 100

���
20
*/
#define LR_MAX 11

int ID10012_1(int num)
{
	int i = 0; //int t = num;
	while (num != 0)
	{
		if (num % 10 == 2)
		{
			i++;
		}
		num = num / 10;
	}
	//printf("[%d] = %d\n", t, i);
	return i;
}
void ID10012()
{
	char p[LR_MAX] = { 0 };
	gets(p);

	int i = 0;
	char aa[LR_MAX] = { 0 }, bb[LR_MAX] = { 0 };
	int a = 0, b = 0;
	int j = 0, status = 0;

	for (i = 0; i <= strlen(p); i++)
	{
		if ((p[i] != ' ') && (status == 0))
		{
			aa[j++] = p[i];
		}
		else if (p[i] == ' ')
		{
			status = 1;
			j = 0;
		}
		else if ((p[i] != ' ') && (status == 1))
		{
			bb[j++] = p[i];
		}
	}
	a = atof(aa);
	b = atof(bb);

	//printf("%s, %s", aa, bb);
	//printf("%d, %d", a, b);
	j = 0;
	for (i = a; i <= b; i++)
	{
		j = j + ID10012_1(i);
	}
	printf("%d\n", j);
}

/*
��Ŀ����(ID:12002)
����: 	У�������
��ǩ: 	ģ�� ����
����: 	ĳУ�����ⳤ��ΪL����·����һ������ÿ�������ڵ���֮��ļ������1�ס����ǿ��԰���·����һ�����ᣬ��·��һ��������0��λ�ã���һ����L��λ�ã������ϵ�ÿ�������㣬��0��1��2��������L��������һ������

������·����һЩ����Ҫ��������������Щ�����������������ϵ���ʼ�����ֹ���ʾ����֪��һ�������ʼ�����ֹ������궼������������֮��������غϵĲ��֡�����Ҫ����Щ�����е�������������˵㴦�������������ߡ���������Ǽ��㽫��Щ�������ߺ���·�ϻ��ж��ٿ�����

�����ʽ:
��һ������������L��1 <= L <= 10000���� M��1 <= M <= 100����L������·�ĳ��ȣ�M�����������Ŀ��L��M֮����һ���ո��������������M��ÿ�а���������ͬ����������һ���ո��������ʾһ���������ʼ�����ֹ������ꡣ

�����ʽ:
ֻ��һ�У���һ��ֻ����һ����������ʾ��·��ʣ���������Ŀ��

��ʾ: 	NOIP�ռ���2005
����: 	ÿ�����Ե�1s
����20%�����ݣ�����֮��û���غϵĲ��֣�
�������������ݣ�����֮�����غϵ������
����:

����
500 3
150 300
100 200
470 471

���
298
*/
#define TREE_MAX 10001
int TREE_L[TREE_MAX] = { 0 };
int Tree1 = 0, Tree2 = 0;
void ID12002_1(char p[], int len)
{
	int i = 0, j = 0, status = 0;
	char aa[10] = { 0 }, bb[10] = { 0 };
	int L = 0, M = 0;
	for (i = 0; i < len; i++)
	{
		if ((p[i] != ' ') && (status == 0))
		{
			aa[j++] = p[i];
		}
		else if (p[i] == ' ')
		{
			status = 1;
			j = 0;
		}
		else if ((p[i] != ' ') && (status == 1))
		{
			bb[j++] = p[i];
		}
	}
	Tree1 = atof(aa);
	Tree2 = atof(bb);
}

void ID12002()
{
	char p[TREE_MAX] = { 0 };

	gets(p);
	int i = 0, j = 0, status = 0;
	char aa[10] = { 0 }, bb[10] = { 0 };
	int L = 0, M = 0;
	for (i = 0; i < strlen(p); i++)
	{
		if ((p[i] != ' ') && (status == 0))
		{
			aa[j++] = p[i];
		}
		else if (p[i] == ' ')
		{
			status = 1;
			j = 0;
		}
		else if ((p[i] != ' ') && (status == 1))
		{
			bb[j++] = p[i];
		}
	}
	L = atof(aa) + 1;
	M = atof(bb);
	while (M--)
	{
		gets(p);
		ID12002_1(p, strlen(p));
		printf("T1 = %d, T2 = %d \n", Tree1, Tree2);
		for (i = Tree1; i <= Tree2; i++)
		{
			TREE_L[i] = 1;
		}
	}
	j = 0;
	for (i = 0; i < TREE_MAX - 1; i++)
	{
		if (TREE_L[i] != 0)
			j++;
	}
	printf("%d\n", L - j - 1);
}

/*
��Ŀ����(ID:10014)
����: 	����ʽ���
��ǩ: 	�ַ��� �ַ�������
����: 	һԪ n �ζ���ʽ�������µı��ʽ��ʾ��

���У�aixi ��Ϊi���ai��Ϊi�����ϵ��������һ��һԪ����ʽ����Ĵ�����ϵ�����밴�����¹涨�ĸ�ʽҪ������ö���ʽ��

1. ����ʽ���Ա���Ϊx�������Ұ��մ����ݼ�˳���������ʽ��
2. ����ʽ��ֻ����ϵ����Ϊ0 ���

3. �������ʽn ����ϵ��Ϊ���������ʽ��ͷ�����֡�+���ţ��������ʽn ����ϵ��Ϊ���������ʽ�ԡ�-���ſ�ͷ��

4. ���ڲ�����ߴε���ԡ�+���Ż��ߡ�-�������Ӵ�����ǰһ��ֱ��ʾ����ϵ��Ϊ������ϵ��Ϊ��������һ������������ʾ����ϵ���ľ���ֵ�����һ������0 �ε����ϵ���ľ���ֵΪ1�����������1�������x ��ָ������1���������������ָ�����ֵ���ʽΪ��x^b��������b Ϊx ��ָ�������x ��ָ��Ϊ1���������������ָ��������ʽΪ��x���� ���x ��ָ��Ϊ0����������ϵ�����ɡ�

5. ����ʽ�У�����ʽ�Ŀ�ͷ����β��������Ŀո�

�����ʽ:
����2 �С�
��һ�� 1 ��������n����ʾһԪ����ʽ�Ĵ���(1 �� n �� 100)��
�ڶ����� n+1 �����������е�i ��������ʾ��n-i+1 �����ϵ����ÿ��������֮���ÿո������
����ʽ������ϵ���ľ���ֵ��������100��

�����ʽ:
��1 �У�����Ŀ������ʽ�������ʽ��

��ʾ: 	NOIP�ռ���2009
����: 	ÿ�����Ե�1s
����:

����
3
-50 0 0 1

���
-50x^3+1

����
3
1 -100 0 0

���
x^3-100x^2
*/
#define X_MAX  100
void ID10014()
{
	char p[X_MAX] = { 0 };
	char dest[X_MAX * 2] = { 0 };
	gets(p);
	int n = atof(p);
	//printf("%d", n);

	gets(p);
    p[strlen(p) ] = ' ';

	int i = 0, j = 0, x = n, q = 0, k = 0;
	char g[10] = { 0 };
	
	for (i = 0; i < strlen(p); i++)
	{
		char temp = p[i];

		if (temp != ' ')
		{
			g[k++] = temp;
			//printf("%c", g[k - 1]);
		}
		else
		{
			for (q = 0; q < k; q++)
				 printf("%c", g[q]);
			printf("\n");
			
			if ((g[0] == '0') && (k == 1))
			{
				k = 0;
				g[0] = 0;
				x--;
				continue;
			}
			else if ((g[0] == '1') && (k == 1) && j==0)
			{
				;
            }
			else
			{
				if (g[0] == '-')
				{
					dest[j++] = '-';
					q = 1;
				}
				else
				{
					if(j !=0 )
					  dest[j++] = '+';
					q = 0;
				}
				for (; q < k; q++)
				{
					if ((g[q] >= '0') && (g[q] <= '9'))
					{
						dest[j++] = g[q];
					}
				}
			}
			memset(g, 0, 10);
			k = 0;

			if (x == 1)
			{
				dest[j++] = 'x';
				x--;
			}
			else if (x > 1) 
			{
				dest[j++] = 'x';
				dest[j++] = '^';
				dest[j++] = x + '0';
				x--;
			}
			else
			{

			}
		}
	}

	for (i = 0; i < j; i++)
	{
		//printf("%c", dest[i]);
	}
	printf("%s", dest);
}

/*
��Ŀ����(ID:12039)
����: 	ѡ��
��ǩ: 	���� �����������
����:
��֪ n ������ x1,x2,��,xn���Լ�һ������ k��k��n������ n ����������ѡ k ��������ӣ��ɷֱ�õ�һϵ�еĺ͡����統 n=4��k��3��4 �������ֱ�Ϊ 3��7��12��19 ʱ���ɵ�ȫ������������ǵĺ�Ϊ��
3��7��12=22����3��7��19��29����7��12��19��38����3��12��19��34��
���ڣ�Ҫ����������Ϊ�������ж����֡�
����������ֻ��һ�ֵĺ�Ϊ������3��7��19��29����

�����ʽ:
n , k ��1<=n<=20��k��n��
x1,x2����,xn ��1<=xi<=5000000

�����ʽ:һ��������������������������
��ʾ: 	noip2002�ռ���ڶ���
����: 	ÿ�����Ե�1s
����:

����
4 3
3 7 12 19

���
1
*/
int all(int A[], int len)
{
	int i = 0, j = 0, k = 0;
	for (i = 0; i <= len - 3; i++)
	{
		for (j = i+1; j <= len - 2; j++)
		{
			for (k = j+1; k <= len - 1; k++)
			{
				printf("%d+%d+%d\n", A[i],A[j], A[k]);
			}
		}
	}
}

#define maxn (20 + 10)
int a[maxn];
int used[maxn];
int ans = 0;
int n, k;

int prime(int x)
{
	for (int i = 2; i <= sqrt(x); i++) 
		if (x % i == 0) return 0;
	return 1;
}

void search(int depth, int now, int last)
{
	if (depth == k)
	{
		if (isPrime_2(now)) ans++;
		printf("%d\n",now);
		return;
	}
	for (int i = last; i <= n; i++)
	{
		if (!used[i])
		{
			printf("i = %d\n",i);
			depth++;
			now += a[i];
			used[i] = 1;
			//printf("%d+", a[i]);
			search(depth, now, i + 1);
			//printf("\n");
			now -= a[i];
			depth--;
			used[i] = 0;
		}
	}
}

int dfs12039()//int A[], int n, int k, int index, int U[] )
{
#if 0
	int i = 0;
	int w = 0;
	if (k == index)
		return 1;
	for (i = index; i < n; i++)
	{
		if (U[i] == 0)
		{
			w = w + A[i];
			index++;

		}
		//if()
		dfs12039(A, n, k, index, U);

	}
#endif
	
	int n = 9;
	int k = 3;
	int a[] = { 0, 3, 7, 12, 19, 2, 7, 9, 5, 3 };
	
	int w = 0;
	int depth = 0;
	int time = 0; int t = 0;
	for (int i = 1; i <= n; i++)
	{
		int U[20] = { 0 };
		w = a[i];
		U[i] = 1;
		depth = 1;
		t = 0;
		printf("i = %d\n", i);
		for (int j = i + 1; j <= n;j++)
		{
			printf("j = %d\n", j);
			if (U[j] == 0)
			{
				w = w + a[j];
				depth++;
				U[j] = 1;
				if (depth == k)
				{
					printf("     %d   ", w);
					if (isPrime_2(w)) time++;
					w = w - a[j];
					U[j] = 0;
					depth--;
				}
				if (j == n)
				{
					t++;
					w = a[i];
					depth = 1;
					j = i + t;
					continue;
				}
			}
		}
	}
	printf("time = %d \n", time);
}
#define DFS_MAX 100
void ID12039()
{
	/*
	char p[DFS_MAX] = { 0 };
	gets(p);
	int n = 0, k = 0;
	if ((p[1] == ' ') && (p[3] == '\0'))
	{
		n = p[0] - '0'; 
		k = p[2] - '0';
	}
	else if ((p[2] == ' ') && (p[4] == '\0'))
	{
		n = (p[0] - '0')*10 + (p[1] - '0');
		k = p[3] - '0';
	}
	else if ((p[1] == ' ') && (p[4] == '\0'))
	{
		n = p[0] - '0';
		k = (p[2] - '0') * 10 + (p[3] - '0');
	}
	else
	{
		n = (p[0] - '0') * 10 + (p[1] - '0');
		k = (p[3] - '0') * 10 + (p[4] - '0');
	}
	printf("n = %d, k = %d \n", n, k);

	gets(p);
	p[strlen(p)] = ' ';

	int i = 0, j  = 0, z = 0;
	char g[20] = { 0 };
	int num[20] = { 0 };
	for (i = 0; i < strlen(p); i++)
	{
		char temp = p[i];

		if (temp != ' ')
		{
			g[j++] = temp;
			//printf("%c", g[k - 1]);
		}
		else
		{
			num[z++] = atof(g);
			j = 0;
			printf("%d ", num[z - 1]);
		}
	}
	printf("\n");
	//all(num, z);
	int B[9] = { 0 };
	for (i = 0; i < z; i++)
	{
		//dfs11(num, z, k, i, B, 0);
	}
	*/
#if 0
	scanf_s("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf_s("%d", &a[i]);
	}
	search(0, 0, 1);
	//dfs12039();
	printf("%d", ans);

#else 
	dfs12039();
#endif
}

/*
��Ŀ����(ID:12138)
����: 	1.2-4����ƽ����
��ǩ: 	����
����: 	��������ָ����������ʹ��������һ����������12321����һ�����͵Ļ�������
����һ������B(2<=B<=20,��ʮ���Ʊ�ʾ)��������еĴ��ڵ���1С�ڵ���300��ʮ�����£�������ƽ����B���Ʊ�ʾʱ�ǻ������������á�A��,��B��������ʾ10��11�ȵȡ�

�����ʽ:
��һ�У�һ������������B(B��ʮ���Ʊ�ʾ)��

�����ʽ:
ÿ������B���Ƶķ���Ҫ������֣��ڶ������ǵ�һ������ƽ�����ҵڶ������ǻ�����.

����:
����
10

���
1 1
2 4
3 9
11 121
22 484
26 676
101 10201
111 12321
121 14641
202 40804
212 44944
264 69696
*/

int ID12138_1(long x, int n)
{
	char dest[20] = { 0 };
	char source[20] = { 0 };

	int j = 0, k = 0;
	long temp = x;
	long num = x * x;

	while (num != 0)
	{
		if (num < n)
		{
			if(num > 9)
				dest[j++] = (num - 10) + 'A';
			else
			    dest[j++] = num + '0';
			break;
		}
		if (num % n > 9)
			dest[j++] = (num % n  - 10) + 'A';
		else
			dest[j++] = num % n + '0';
		num = num / n;
	}
	//--
	while (temp != 0)
	{
		if (temp < n)
		{
			if (temp > 9)
				source[k++] = (temp - 10) + 'A';
			else
				source[k++] = temp + '0';
			break;
		}
		if (temp % n > 9)
			source[k++] = (temp % n - 10) + 'A';
		else
			source[k++] = temp % n + '0';
		temp = temp / n;
	}

	for (int i = 0; i < j / 2; i++)
	{
		//printf("%c %c\n", dest[i], dest[j - i - 1]);
		if (dest[i] != dest[j - i - 1])
		{
			return 0;
		}
	}
#if 0
	for (int i = 0; i < k / 2 -1 ; i++)
	{
		char t = 0;
		t = source[i];
		source[i] = source[k - i];
		source[k - i] = t;
	}
#endif
	printf("%s %s\n",source, dest);
	return 1;
}

void ID12138()
{
	int n = 0;
	scanf_s("%d", &n);

	for (int i = 1; i <= 300; i++)
	{
		ID12138_1(i,n);
	}
}

/*
��Ŀ����(ID:12059)
����: 	���˳��
��ǩ: 	��̬�滮
����:
˳��ϲ����ѩ���Ⲣ����֣� ��Ϊ��ѩ��ȷ�ܴ̼�������Ϊ�˻���ٶȣ������������������б�����ҵ��㻬���µף��㲻�ò��ٴ������»��ߵȴ�̫���������㡣˳����֪����һ����������Ļ��¡�
������һ����ά��������������ÿ�����ִ����ĸ߶ȡ�������һ�����ӣ�
����	1  2  3  4  5
   ����	16 17 18 19 6
	 �� 15 24 25 20 7
	    14 23 22 21 8
		13 12 11 10 9
˳�ο��Դ�ĳ���㻬���������������ĸ���֮һ�����ҽ����߶ȼ�С��������������У�һ���ɻ��еĻ���Ϊ24-17-16-1����Ȼ25-24-23-...-3-2-1��������ʵ�ϣ��������һ����

�����ʽ:
����ĵ�һ�б�ʾ���������R������C(1 <= R,C <= 500)��������R�У�ÿ����C������������߶�h��0<=h<=10000��

�����ʽ:
��������ĳ��ȡ�

����:
����
5 5
1  2  3  4  5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9

���
25
*/
int RC[500][500] = { 0 };
int R = 0, C = 0;
int RC_max = 0;
void ID12059_dfs(int i, int j, int count)
{
	if (i<0 || i>R - 1 || j<0 || j>C - 1)
	{
		//printf("[%d][%d] = %d \n", i, j, count);
		if (RC_max < count)
		{
			RC_max = count;
		}
		return;
	}
	count++;

	if (RC[i][j + 1] < RC[i][j])
	ID12059_dfs(i, j + 1, count);

	if (RC[i][j - 1] < RC[i][j])
	ID12059_dfs(i, j - 1, count);

	if (RC[i + 1][j] < RC[i][j])
	ID12059_dfs(i + 1, j, count);

	if (RC[i - 1][j] < RC[i][j])
	ID12059_dfs(i - 1, j, count);
}

void ID12059()
{
	scanf_s("%d %d", &R, &C);

	int count = 0;
	int i = 0, j = 0, k = 0;
	for (i = 0; i < R; i++)
	{
		for (j = 0; j < C; j++)
		{
			scanf_s("%d", &RC[i][j]);
		}
	}
	/*
	for (i = 0; i < R; i++)
	{
		printf("\n");
		for (j = 0; j < C; j++)
		{
			printf("%2d ", RC[i][j]);
		}
	}
   */
	//i = 1; j = 1;
	int max = 0;
	// ����m*n�Ķ�ά����
	for (int i = 0; i<R; i++)
	{
		for (int j = 0; j<C; j++)
		{
			ID12059_dfs(i, j, 0);
			//printf("[%d][%d] = %d \n", i, j, RC_max);
			if (max < RC_max)
				max = RC_max;
			RC_max = 0;
		}
	}
	printf("%d", max);
}

/*
��Ŀ����(ID:12097)
����: 	����������
��ǩ: 	��̬�滮
����: 	��ͼ��ʾ�����������Σ��Ӷ�����������ÿһ������ѡ�������߻�������ߣ�һֱ�ߵ��ײ㣬Ҫ���ҳ�һ��·����ʹ·���ϵ�ֵ���

�����ʽ:
��һ������������N(1<=N<=1000)��
�ڶ����𣬰�����ͼ�Σ���һ����������������ʾ�ò�ڵ��ֵ������N�С�

�����ʽ:
������ֵ��

����:
����
5
13
11 8
12 7 26
6 14 15 8
12 7 13 24 11

���
86
*/
void ID12097()
{
	int n = 0;
	scanf_s("%d", &n);

	int count = 0;
	int i = 0, j = 0, k = 0;
	for (i = 0; i < R; i++)
	{
		for (j = 0; j < C; j++)
		{
			scanf_s("%d", &RC[i][j]);
		}
	}
}

/*
��Ŀ����(ID:12004)
����: 	ͳ������
��ǩ: 	����
����: 	ĳ�ο��е���ʱ�õ���n����Ȼ����ÿ������������1500000000��1.5*10^9������֪����ͬ����������10000����������Ҫͳ����Щ��Ȼ�����Գ��ֵĴ�������������Ȼ����С�����˳�����ͳ�ƽ����

�����ʽ:
��1��������n(1<=n<=200000)����ʾ��Ȼ���ĸ�����
��2~n+1��ÿ��һ����Ȼ����

�����ʽ:
�������m�У�mΪn����Ȼ���в���ͬ���ĸ�������������Ȼ����С�����˳�������ÿ����������������ֱ�����Ȼ���͸������ֵĴ����������һ���ո������

��ʾ: 	NOIP2007�����
����: 	ÿ�����Ե�1s��
40%���������㣺1<=n<=1000
80%���������㣺1<=n<=50000
100%���������㣺1<=n<=200000��ÿ������������1500 000 000��1.5*10^9��
����:

����
8
2
4
2
4
5
100
2
100

���
2 3
4 2
5 1
100 2
*/
//#define 10
void ID12004()
{
	
	char p[20] = { 0 };
	//int *p = (int *)&p[2];
#if 0
	gets(p);
	long n = atof(p);
	//printf("%ld: \n",n);

	long i = 0, j = 0;
	unsigned long dest[150000000] = { 0 };
	unsigned long temp = 0;
	while (n--)
	{
		gets(p);
		temp = atof(p);
		dest[temp]++;
	}

	for (i = 0; i < 200000; i++)
	{
		if (dest[i] != 0)
		{
			printf("%d %d\n", i, dest[i]);
		}
	}
#else
	gets(p);
	long n = atof(p);
	char dest[15][15] = { 0,0 };
	long j = 0;
	while (n--)
	{
		gets(p);
		memcpy(&dest[j++][0], &p, strlen(p));
		printf("%s\n", &dest[j-1][0]);
	}
#endif
}

/*
��Ŀ����(ID:12200)
����: 	�ּ�a+b
��ǩ: 	ģ��
����: 	�����ÿһ����������a��b�ĺͣ����������㲢��֪���ж�����

�����ʽ:
�����У�ÿ�����������ÿո����

�����ʽ:
ÿ��һ������

����: 	-1000<=a,b<=1000
����:

����
1 2
3 4
5 6
99 1
123 -321
���
3
7
11
100
-198

����
99 100
-1 1
���
199
0

����
1 99
���
100
*/
void ID12200()
{
	int dest[1000] = { 0 };
	char p[10] = { 0 };
	int a = 0, b = 0;
	int i = 0, j = 0;
	//printf("%d\n", sizeof(int *));return;
	//printf("%d\n", plus(34, 5));
	//scanf()���ص����������ȷ�����ĸ���
	while (1)//scanf_s("%d %d", &a, &b) == 2)
	{
		//scanf_s("%d %d", &a,&b);
		
		gets(p);
		if (p[0] == '\0') break;

		a = atof(p);
		for (i = 0; i < strlen(p); i++)
			if(p[i] == ' ') break;
		b = atof(&p[i+1]);
		//printf("%d %d\n", a, b);
		
		//dest[j++] = a + b;
		
		printf("%d\n", a+b);
	}
	for (i = 0; i < j; i++)
	{
		printf("%d\n", dest[i]);
	}
}

/*
��Ŀ����(ID:10001)
����: 	����ժƻ��
��ǩ: 	ģ��
����:

���ռҵ�Ժ������һ��ƻ������ÿ���������Ͼͻ���10��ƻ����ƻ�������ʱ�����վͻ���ȥժƻ���������и�30���׸ߵİ�ʣ���������ֱ������ժ��ƻ����ʱ�򣬾ͻ�ȵ�����������ԡ�
������֪10��ƻ��������ĸ߶ȣ��Լ����հ�����ֱ��ʱ���ܹ��ﵽ�����߶ȣ����������һ�����ܹ�ժ����ƻ������Ŀ������������ƻ����ƻ���ͻ��������

�����ʽ:
��������������ݡ���һ�а���10��100��200֮�䣨����100��200����������������Ϊ��λ���ֱ��ʾ10��ƻ��������ĸ߶ȣ��������ڵ�����֮����һ���ո�������ڶ���ֻ����һ��100��120֮�䣨����100��120����������������Ϊ��λ������ʾ���հ�����ֱ��ʱ���ܹ��ﵽ�����߶ȡ�

�����ʽ:
�������һ�У���һ��ֻ����һ����������ʾ�����ܹ�ժ����ƻ������Ŀ��

����: 	ÿ�����Ե�1s
����:

����
153 192 174 186 179 104 157 172 128 182
100
���
2

����
163 175 148 130 173 124 102 121 129 164
106
���
5
*/

void ID10001()
{
	int high[10] = { 0 };
	int i = 0, j = 0;
	int temp = 0;

	while (i<10)
	{
		scanf_s("%d", &temp);
		high[i] = temp;
		//printf("%d ", high[i]);
		i++;
	}
	scanf_s("%d", &temp);
	//printf("(%d)", temp);
	int l = temp;

	for (i = 0; i < 10; i++)
	{
		if ((temp > high[i]) || (temp > high[i] - 30))
			j++;
	}
	printf("%d\n", j);
}

void ID10003()
{
	int hours[7] = { 0 };
	int temp[2] = { 0 };
	int i = 0;
	while (i < 7)
	{
	   scanf_s("%d %d", &temp[0], &temp[1]);
	   hours[i] = temp[0] + temp[1];
	   i++;
	}
	int max = 8;
	for (i = 6; i >= 0; i--) {
		if (hours[i] >= max)
		{
			max = hours[i];
			temp[0] = i + 1;
		}
	}
	if(max <= 8)
		printf("%d\n", 0);
	else
	    printf("%d\n", temp[0]);
}

/*
��Ŀ����(ID:10011)
����: 	������
��ǩ: 	���� ��ѧ
����: 	��֪������n��������ͬ�������ĳ˻���������ϴ���Ǹ�������

�����ʽ:
����ֻ��һ�У�����һ��������n��

�����ʽ:
����ֻ��һ�У�����һ��������n��

��ʾ: 	NOIP�ռ���2012
����: 	����60%�����ݣ�6 �� n �� 1000�� ����100%�����ݣ�6 �� n �� 2 * 10^9��
ÿ�����Ե�1��
����:

����
6
���
3

����
119
���
17
*/
void ID10011()
{
	long n = 0;
	scanf_s("%ld", &n);
	printf("%ld\n", n);

	long i = 0;
	for (i = 2; i < 50000; i++)
	{
		if (isPrime_2(i))
		{
			if ((n%i == 0) && isPrime_2(n/i))
			{
				printf("%d\n", n/i);
				return;
			}
		 }
	}
}

/*
��Ŀ����(ID:12030)
����: 	ţʽ
��ǩ: 	���� ö��
����: 	������һ���˷���ʽ����������Ǹ�������n��������ȡ��*������ʹʽ�ӳ����Ļ������Ǿͽ����ʽ��ţʽ��
    ***
x    **
----------
    ***
   ***
----------
   ****
����ֻ��ȡ��*����Ȼ��һλ����Ϊ0,���Ҹ����������ﲻ����0��
ע��һ����������ѧУ�н̵ġ����ֳ˻�������һ���ֳ˻��ǵڶ������ĸ�λ�͵�һ�����Ļ����ڶ����ֳ˻��ǵڶ�������ʮλ�͵�һ�����ĳ˻�.
дһ�������ҳ����е�ţʽ��

�����ʽ:
��һ�У����ֵĸ���n��
�ڶ��У�N���ÿո�ֿ������֣�ÿ�����ֶ�����{1,2,3,4,5,6,7,8,9}����

�����ʽ:
��һ�У�һ�����֡���ʾţʽ��������

��ʾ: 	USACO Training
����: 	ÿ�����Ե�1��
����:

����
5
2 3 4 6 8
���
1

����
222
x 22
----------
444
444
----------
4884
ע�⣺���ֻ��Ϊ4λ
*/
void ID12030()
{
	int n = 0, j = 0;
	int nN[10] = { 0 };
	scanf_s("%d", &n);
	while (n--)
	{
		scanf_s("%d", &nN[j++]);
		//printf("j[%d]%d ", j-1, nN[j - 1]);
	}
	int flag = 0;
	int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0, i = 0,x = 0,y = 0, z = 0;
	
	for (a = 0; a < j; a++)
	{
		for (b = 0; b < j; b++)
		{
			for (c = 0; c < j; c++)
			{
				//--
				for (d = 0; d < j; d++)
				{
					//��ǰ�˳�����ֹ��ʱ
					if ((nN[a] * 100 + nN[b] * 10 + nN[c]) * nN[d] > 999) continue;
					for (e = 0; e < j; e++)
					{
						//��ǰ�˳�����ֹ��ʱ
						if ((nN[a] * 100 + nN[b] * 10 + nN[c]) * nN[e] > 999) continue;
						//--
						for (f = 0; f < j; f++)
						{
							for (g = 0; g < j; g++)
							{
								for (h = 0; h < j; h++)
								{
									for (i = 0; i < j; i++)
									{
										//--
										if ((nN[a] * 100 + nN[b] * 10 + nN[c]) * (nN[d] * 10 + nN[e]) == (nN[f] * 1000 + nN[g] * 100 + nN[h] * 10 + nN[i]) )
										{
											for (x = 0; x < j; x++)
											{
												for (y = 0; y < j; y++)
												{
													for (z = 0; z < j; z++)
													{
														if (((nN[a] * 100 + nN[b] * 10 + nN[c]) * nN[d]) == (nN[x] * 100 + nN[y] * 10 + nN[z]))
															flag = 1;
													}
												}
											}
											for (x = 0; x < j; x++)
											{
												for (y = 0; y < j; y++)
												{
													for (z = 0; z < j; z++)
													{
														if (((nN[a] * 100 + nN[b] * 10 + nN[c]) * nN[e]) == (nN[x] * 100 + nN[y] * 10 + nN[z]))
														{
															if (flag == 1)
															{
																flag = 0;
																printf("%d%d%d * %d%d = %d%d%d%d\n",nN[a], nN[b], nN[c], nN[d], nN[e], nN[f], nN[g], nN[h], nN[i]);
															}
														}
													}
												}
											}
											flag = 0;
									    }
								    }
							    }
							}
						}
					}
				}
			}
		}
	}
}

/*
��Ŀ����(ID:12155)
����: 	2.2-2����
��ǩ: 	����
����: 	���ڴ�1��N (1 <= N <= 39) �������������ϣ��ܻ��ֳ������Ӽ��ϣ��ұ�֤ÿ�����ϵ����ֺ�����ȵġ��ٸ����ӣ����N=3������{1��2��3}�ܻ��ֳ������Ӽ��ϣ�ÿ���Ӽ��ϵ��������ֺ�����ȵģ�
{3} �� {1,2}����Ψһһ�ַַ�����������λ�ñ���Ϊ��ͬһ�ֻ��ַ�������˲������ӻ��ַ������������N=7�������ַ����ܻ��ּ���{1��2��3��4��5��6��7}��ÿһ�ַַ����Ӽ��ϸ����ֺ�����ȵ�:
{1,6,7} �� {2,3,4,5} {ע 1+6+7=2+3+4+5}{2,5,7} �� {1,3,4,6}{3,4,7} �� {1,2,5,6}{1,2,4,7} �� {3,5,6}����N����ĳ���Ӧ��������ַ�����������������������Ļ��ַ����������0��������Ԥ����ֱ����������ܴ����

�����ʽ:
�����ļ�ֻ��һ�У���ֻ��һ������N

�����ʽ:
������ַ�����������������������0��

����:

����
7
���
4
*/
int ID12155_t = 0;
int ID12155_dfs(int sum, int i, int T, int A[], int U[], int n)
{
	if (sum > T / 2)
		return 0;
	else if (sum == T - sum)
	{
		ID12155_t++;
		return 1;
	}
	//for (int i = 0; i <= n; i++) 
	if(U[i] == 0)
	{
		printf("%d \n", i);
		//printf("%d %d \n", i, sum);
		sum = sum + A[i];
		U[i] = 1;
		i = i + 1;
		ID12155_dfs(sum, i, T, A ,U, n);
		i = i - 1;
		U[i ] = 0;
		sum = sum - A[i];
		//printf("(%d) %d \n", i , sum);
	}

}

void ID12155()
{
	int n = 0;
	scanf_s("%d", &n);
	int i = 0, T = 0;
	
	T = (1 + n)*n / 2;
	if (T % 2 != 0) 
	{ 
		printf("0");
		return 0;
	}
	//printf("T = %d\n ", T);

	int A[40] = { 0 };
	for (int i = 0; i <= n; i++)
		A[i] = i;

	int U[40] = { 0 };
	ID12155_dfs(0, 1, T, A, U, n);

	printf("\n%d\n", ID12155_t);
}

/*
��Ŀ����(ID:12145)
����: 	1.4-2ĸ�׵�ţ��
��ǩ: 	����
����:
ũ��Լ�������������ֱ���A,B,C����Ͱ��A,B,C�ֱ���������1��20�������� �����A��BͰ���ǿյģ���CͰ��װ��ţ�̵ġ���ʱ��ũ���ţ�̴�һ��Ͱ���� ��һ��Ͱ�У�ֱ������Ͱװ����ԭͰ���ˡ���Ȼÿһ�ι�ע������ȫ�ġ����ڽ�Լ�� ţ�̲����ж�ʧ
дһ������ȥ����ũ���ҳ���AͰ�ǿյ�ʱ��CͰ��ţ����ʣ�������п����ԡ�

�����ʽ:
������һ�а�����������A,B��C��

�����ʽ:
ֻ��һ�У�������г���AͰ�ǿյ�ʱ��CͰţ����ʣ�������п�����

����:

����
8 9 10
���
1 2 8 9 10

����
2 5 10
���
5 6 7 8 9 10
*/
#ifdef A(x)
#undef A(x)
#undef B(x)
int tot = 0;
int ff[20][20][20] = { 0,0,0 }, res[100];
//˼·��A->B,A->C,B->A,B->C,C->A,C->Bһ����������������ɣ���һ��f[][][]����¼�Ƿ񵽹���������
void ID12145_dfs(int a, int b, int c, int A, int B, int C)
{
	printf("%d %d %d \n", a, b, c);
	if (ff[a][b][c]) return; 
	ff[a][b][c] = 1;
	if (!a) res[tot++] = c;
	ID12145_dfs(max(0, a - (B - b)), min(B, b + a), c, A, B, C);
	ID12145_dfs(max(0, a - (C - c)), b, min(C, c + a), A, B, C);
	ID12145_dfs(min(a + b, A), max(0, b - (A - a)), c, A, B, C);
	ID12145_dfs(a, max(0, b - (C - c)), min(C, c + b), A, B, C);
	ID12145_dfs(min(a + c, A), b, max(0, c - (A - a)), A, B, C);
	ID12145_dfs(a, min(B, b + c), max(0, c - (B - b)), A, B, C);
}
#endif
void ID12145()
{
	int A = 0, B = 0, C = 0;
	scanf_s("%d %d %d", &A, &B, &C);

	ID12145_dfs(0, 0, C, A, B, C);

	for (int i = 0; i < tot; i++)
		printf("%d ", res[i]);
}
/*
��Ŀ����(ID:12198)
����: 	��ʯͷ
��ǩ: 	���� ���ֲ���
����:
һ��һ�ȵġ���ʯͷ��������Ҫ��ʼ��!
�����������һ����ֱ�ĺӵ��н���,�ӵ��зֲ���һЩ�޴���ʯ����ί���Ѿ�ѡ�����������ʯ��Ϊ���������յ㡣�������յ�֮��,�� N ����ʯ(���������� �����ʯ)���ڱ���������,ѡ���ǽ���������,ÿһ���������ڵ���ʯ,ֱ������ �յ㡣
Ϊ����߱����Ѷ�,��ί��ƻ�����һЩ��ʯ,ʹ��ѡ�����ڱ��������е������ Ծ���뾡���ܳ�������Ԥ������,��ί������������յ�֮������ M ����ʯ(���� ���������յ����ʯ)��

�����ʽ:
�����ļ���һ�а����������� L,N,M,�ֱ��ʾ��㵽�յ�ľ���,������ ��֮�����ʯ��,�Լ���ί���������ߵ���ʯ����
������ N ��,ÿ��һ������,�� i �е����� Di(0 < Di < L)��ʾ�� i ����ʯ�� ���ľ��롣��Щ��ʯ�����������С�����˳�����,�Ҳ�����������ʯ������ͬ һ��λ�á�

�����ʽ:
����ļ�ֻ����һ������,�������Ծ��������ֵ��

����: 	���� 20%������,0 �� M �� N �� 10�� ����50%������,0 �� M �� N �� 100��

���� 100%������,0 �� M �� N �� 50,000,1 �� L �� 1,000,000,000��
����:

����
25 5 2
2
11
14
17
21

���
4

����
����������Ϊ 2 �� 14 ��������ʯ���ߺ�,��̵���Ծ����Ϊ 4(���������� 17 ����ʯ�������� 21 ����ʯ,���ߴӾ��� 21 ����ʯ�����յ�)��
*/
void ID12198()
{
	int L = 0, D = 0, M = 0;
	scanf_s("%d %d %d", &L, &D, &M);

	int source[100] = { 0 };
	int i = 0, j = 1, temp = 0;
	while (D--)
	{
		scanf_s("%d", &temp);
		source[j++] = temp;
	}
	source[j] = L;
	/*
	for (i = 0; i < j; i++)
	{
		printf("%d ", s[i]);
	}
	*/

	int dest[100] = { 0 }; int k = 0;
	for (i = 0; i < j; i++)
	{
		dest[k++] = source[i + 1] - source[i];
	}

	for (i = 0; i < k; i++)
	{
		printf("%d ", dest[i]);
	}

	for (i = 0; i < k; i++)
	{

	}
}


int main_aha(int argc, char *argv[])
{
	//ID12167();
	//ID12108();
	//ID10021();
	//ID10007();
	//while (1) ID12103();
	//ID12111();
	//ID12078();
	//ID10009();
	//ID12079();
	//ID12073();
	//while(1)
		//ID12025_sort();

	//ID12048();
	//ID10016();
	//ID10022();
	//ID10012();
	//ID12002();
	//ID10014();
	//ID12039();
	//ID12138();
	//ID12059();
	//ID12004();
	//ID12200();
	//ID10001();
	//ID10003();
	//ID10011();
	//ID12030();
	//ID12155();
	//ID12145();
	//ID12198();

	/*
	printf("%d\n",strcmp("10", "1"));
	//printf("%d\n", str_cmp("121100", "11"));
	printf("%d\n", MyCompare("10", "1"));
	printf("%d\n", MyCompare("6101", "610"));
	*/
}