#include "stdafx.h"
#include <stdlib.h>
#include "stdafx.h"
#include "string.h"
#include "stdio.h"


/*
标题: 	士兵排队
标签 : 图结构 拓扑排序
详情 :
	有Ｎ个士兵(1≤Ｎ≤26)，编号依次为 Ａ, Ｂ, Ｃ, …，队列训练时，指挥官要把一些士兵从高到矮一次排成一行，
	但现在指挥官不能直接获得每个人的身高信息，只能获得“P1比P2高”这样的比较 结果(P1、P2 ∈ Ａ, Ｂ, Ｃ, …, Ｚ, 记为 P1 > P2)，
	如”Ａ >Ｂ ”表示Ａ比Ｂ高。对应的排队方案有三个：
	AFBD、 FABD 、
		可行的排队方案有三个，分别是FABD、AFBD和ABFD。输入其中一个即可。
		（注：比较结果中没有涉及的士兵不参加排队）

	输入格式 : 有若干行
		每行三个字符，第一个字符和第三个字符均为大写字母A~Z的中某个字母，中间的一个字母为>

	输出格式:
	    若输入数据无解，打印“No Answer!”信息，否则从高到矮一次输出每一个士兵的编号，中间无分割符

	样例 :
	输入
		A>B
		B>D
		F>D
	输出
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
		//先放一个数据到数组头
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
			//[0]、[1]都是第一次出现，放在数组前面两位
			dest[count++] = p[0];
			dest[count++] = p[2];
		}
		else if (a == -1)// b != -1
		{
			//[0]是第一次出现: p[0]放在b的位置，其他后移一位
			for (j = count; j > b-1 ; j--)
			{
				dest[j] = dest[j - 1];
			}
			dest[b] = p[0];
			count++;
		}
		else if (b == -1)// a != -1
		{
			//[1]是第一次出现: p[2]放在a的位置后，其他后移一位
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
			//printf("\n 输入结束 \n");
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
			//先放一个数据到数组头
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
				//[0]、[1]都是第一次出现，放在数组前面两位
				dest[count++] = p[0];
				dest[count++] = p[2];
			}
			else if (a == -1)// b != -1
			{
				//[0]是第一次出现: p[0]放在b的位置，其他后移一位
				for (j = count ; j > b - 1 ; j--)
				{
					dest[j] = dest[j - 1];
				}
				dest[b] = p[0];
				count++;
			}
			else if (b == -1)// a != -1
			{
				//[1]是第一次出现: p[2]放在a的位置后，其他后移一位
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
			printf("\n 输入结束 \n");
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
标题: 	数字反转 [ 高级版 ]
标签: 	字符串 字符串处理
详情: 	给定一个整数N，请将该数各个位上数字反转得到一个新数。新数也应满足整数的常见形式，即除非给定的原数为零，否则反转后得到的新数的最高位数字不应为零
输入格式:
输入共1 行，一个整数N。

输出格式:
输出共1 行，一个整数，表示反转后的新数。

限制: N的位数不超过10000位

样例:
输入
-100
输出
-1

输入
123456789123456789123456789
输出
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
题目描述(ID:10021)
标题: 	笨小猴
标签 : 字符串 模拟 字符串处理
详情 : 笨小猴的词汇量很小，所以每次做英语选择题的时候都很头疼。但是他找到了一种方法，经试验证明，用这种方法去选择选项的时候选对的几率非常大！
这种方法的具体描述如下：假设maxn是单词中出现次数最多的字母的出现次数，minn是单词中出现次数最少的字母的出现次数，如果maxn - minn是一个质数，那么笨小猴就认为这是个Lucky Word，这样的单词很可能就是正确的答案。

输入格式 :
输入只有一行，是一个单词，其中只可能出现小写字母，并且长度小于100。

输出格式 :
输出共两行，第一行是一个字符串，假设输入的的单词是Lucky Word，那么输出“Lucky Word”，否则输出“No Answer”；
第二行是一个整数，如果输入单词是Lucky Word，输出maxn - minn的值，否则输出0。

提示 : NOIP提高组2008
限制 : 各个测试点1s
样例 :

输入
error

输出
Lucky Word
2

解释
单词error中出现最多的字母r出现了3次，出现次数最少的字母出现了1次，3 - 1 = 2，2是质数。

输入
olympic

输出
No Answer
0

解释
单词olympic中出现最多的字母出现了1次，出现次数最少的字母也出现了1次，1 - 1 = 0，0不是质数。
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
题目描述(ID:10007)
标题: 	ISBN号码
标签: 	字符串
详情: 	每一本正式出版的图书都有一个ISBN号码与之对应，ISBN码包括9位数字、1位识别码和3位分隔符，其规定格式如“x-xxx-xxxxx-x”，其中符号“-”就是分隔符（键盘上的减号），最后一位是识别码，例如0-670-82162-4就是一个标准的ISBN码。ISBN码的首位数字表示书籍的出版语言，例如0代表英语；第一个分隔符“-”之后的三位数字代表出版社，例如670代表维京出版社；第二个分隔符后的五位数字代表该书在该出版社的编号；最后一位为识别码。
　　识别码的计算方法如下：
  　　首位数字乘以1加上次位数字乘以2……以此类推，用所得的结果mod 11，所得的余数即为识别码，如果余数为10，则识别码为大写字母X。例如ISBN号码0-670-82162-4中的识别码4是这样得到的：对067082162这9个数字，从左至右，分别乘以1，2，...,9,再求和，即0×1+6×2+……+2×9=158，然后取158 mod 11的结果4作为识别码。
	　　你的任务是编写程序判断输入的ISBN号码中识别码是否正确，如果正确，则仅输出“Right”；如果错误，则输出你认为是正确的ISBN号码。

输入格式:
只有一行，是一个字符序列，表示一本书的ISBN号码（保证输入符合ISBN号码的格式要求）。

输出格式:
只有一行，假如输入的ISBN号码的识别码正确，那么输出“Right”，否则，按照规定的格式，输出正确的ISBN号码（包括分隔符“-”）。

样例:
输入
0-670-82162-4

输出
Right

输入
0-670-82162-X

输出
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
题目描述(ID:12103)
标题: 	最大数
标签: 	字符串 字符串处理
详情: 	设有 n 个正整数（n≤20） ，将它们联接成一排，组成一个最大的多位整数。
例如：n=3 时，3 个整数 13，312，343 联接成的最大整数为：34331213
又如：n=4 时，4 个整数 7，13，4，246 联接成的最大整数为：7424613

输入格式:
第一行只有一个 n
第二行为 n 个整数

输出格式:
联接成的多位数

提示: 	n<=20
每个整数不超过20位

样例:
输入
3
13 312 343

输出
34331213
*/
static int MyCompare(char str1[], char str2[])
{
	int str1_Length = strlen(str1);
	int str2_Length = strlen(str2);
	//    abc    abc
	for (int i = 0; i < str1_Length; i++)
	{
		//如果str1比str2长的情况
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
	//str1的长度小于或等于str2的长度
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
	     若str1==str2，则返回零；
		 若str1< str2，则返回负数；
		 若str1> str2，则返回正数。
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
题目描述(ID:12111)
标题: 	困难的等式
标签: 	字符串 字符串处理
详情:
有一天，小明学会了加减法，便爱上了做等式计算，诸如a+b或者a-b之类的问题。但是貌似一般的加减法计算难不倒小明。终于，小明的老师想到一个考验小明的办法：让他算a+?=b 或 ?+a=b 或 a+b=?。这回小明不会做了，于是找到了你。注明只会出现加减运算。

输入格式:
输入一个等式，形如a+b=c或a-b=c。给定其中的两个数，请确定其中的第三个数。其中0<=A,B,C<1,000,000,000，没有给定的数用一个单独的“？”表示，等式中没有多余空格。

输出格式:
直接输出要求的第三个数。

限制: 	0<=A,B,C<1,000,000,000
样例:

输入
1+2=?

输出
3

输入
15+?=115

输出
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

	//a+?=b 或 ?+a=b 或 a+b=?
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
题目描述(ID:12078)
标题: 	手机
标签: 	字符串 字符串处理
详情: 	手机的键盘是这样的：
1            2 abc    3 def
4 ghi      5 jkl      6 mno
7 pqrs    8 tuv    9 wxyz

要按出英文字母就必须要按数字键多下。例如要按出x就得按9两下，第一下会出w，而第二下会把w变成x。0键按一下会出一个空格。
你的任务是读取若干句只包含英文小写字母和空格的句子，求出要在手机上打出这个句子至少需要按多少下键盘。

输入格式:
一行一个句子，只包含英文小写字母和空格，且不超过200个字符。

输出格式:
一行一个整数，表示按键盘的总次数。

样例:
输入
i have a dream

输出
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
题目描述(ID:10009)
标题: 	数字反转
标签: 	字符串 模拟 字符串处理
详情: 	给定一个整数，请将该数各个位上数字反转得到一个新数。新数也应满足整数的常见形式，即除非给定的原数为零，否则反转后得到的新数的最高位数字不应为零（参见样例2）。

输入格式:
输入共1 行，一个整数N。

输出格式:
输出共1 行，一个整数，表示反转后的新数。

提示: 	NOIP普及组2011
限制: 	-1,000,000,000 ≤ N ≤ 1,000,000,000 。
每个测试点1s
样例:

输入
-290

输出
-92

输入
900000000

输出
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
题目描述(ID:12079)
标题: 	生日
标签: 	字符串 字符串处理
详情: 	某人想调查学校OI组每个同学的生日，并按照从大到小的顺序排序。但近作业很多，没有时间，所以请你帮她排序。

输入格式:
有2行，
第1行为OI组总人数n；
第2行至第n+1行分别是每人的姓名s、出生年y、月m、日d。

输出格式:
有n行，
即n个生日从大到小同学的姓名。如果同年同月同日生则按照姓名的字典序从大到小。
限制: 	1
样例:

输入
3
Yangchu 1992 4 23
Qiujingya 1993 10 13
Luowen 1991 8 1

输出
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

	//先判断数据量的大小
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
	若str1==str2，则返回零；
	若str1< str2，则返回负数；
	若str1> str2，则返回正数。
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
题目描述(ID:12073)
标题: 	vigenere密码
标签: 	字符串 字符串处理
详情: 	16世纪法国外交家Blaise de Vigenère设计了一种多表密码加密算法——Vigenère密码。Vigenère密码的加密解密算法简单易用，且破译难度比较高，曾在美国南北战争中为南军所广泛使用。
在密码学中，我们称需要加密的信息为明文，用M表示；称加密后的信息为密文，用C表示；而密钥是一种参数，是将明文转换为密文或将密文转换为明文的算法中输入的数据，记为k。 在Vigenère密码中，密钥k是一个字母串，k=k1k2…kn。当明文M=m1m2…mn时，得到的密文C=c1c2…cn，其中ci=mi@ki，@运算符的运算的规则如下表所示：
Vigenere加密在操作时需要注意：
1. ?运算忽略参与运算的字母的大小写，并保持字母在明文M中的大小写形式；
2. 当明文M的长度大于密钥k的长度时，将密钥k重复使用。

输入格式:
输入共2行。
第一行为一个字符串，表示密钥k，长度不超过100，其中仅包含大小写字母。第二行为一个字符串，表示经加密后的密文，长度不超过1000，其中仅包含大小写字母。

输出格式:
输出共1行，一个字符串，表示输入密钥和密文所对应的明文。

提示: ci=(mi-‘A‘+ki-‘A‘)mod26+‘A‘，
限制: 对于100%的数据，输入的密钥的长度不超过100，输入的密文的长度不超过1000，且都仅包含英文字母。
样例:

输入
CompleteVictory
Yvqgpxaimmklongnzfwpvxmniytm

输出
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
		//小写转为大写
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
题目描述(ID:12025)
标题: 	1.1-4坏掉的项链
标签: 	字符串 字符串处理
详情: 	你有一条由N个红色的，白色的，或蓝色的珠子组成的项链(3<=N<=350)，珠子是随意安排的。 这里是 n=29 的二个例子:

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
图片 A                             图片  B

r 代表 红色的珠子
b 代表 蓝色的珠子
w 代表 白色的珠子
第一和第二个珠子在图片中已经被作记号。
图片 A 中的项链可以用下面的字符串表示：
brbrrrbbbrrrrrbrrbbrbbbbrrrrb
假如你要在一些点打破项链,展开成一条直线，然后从一端开始收集同颜色的珠子直到你遇到一个不同的颜色珠子，在另一端做同样的事(颜色可能与在这之前收集的不同)。 确定应该在哪里打破项链来收集到最大数目的珠子。
例如，在图片 A 中的项链中，在珠子 9 和珠子 10 或珠子 24 和珠子 25 之间打断项链可以收集到8个珠子。
白色珠子什么意思?

在一些项链中还包括白色的珠子(如图片B) 所示。
当收集珠子的时候，一个被遇到的白色珠子可以被当做红色也可以被当做蓝色。
表现含有白珠项链的字符串将会包括三个符号 r ， b 和 w 。
写一个程序来确定从一条被给出的项链可以收集到的珠子最大数目。

输入格式:
第 1 行: N, 珠子的数目
第 2 行: 一串长度为N的字符串, 每个字符是 r ， b 或 w。

输出格式:
单独的一行 最大可能取得的珠子数

提示: 	USACO Training
限制: 	每个测试点1秒
样例:

输入
29
wwwbbrwrbrbrrbrbrwrwwrbwrwrrb

输出
11
*/

#define  MAX_BEADS  350
void ID12025()
{
	char p[MAX_BEADS] = { 0 };
	gets(p);
	/*
	//先判断数据量的大小
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

		//程序还没完善，例子：wwwwrbrbrww，出错
		if (((p[0] == 'w') || (p[i] == 'w') || (p[0] == p[i])) && (j>2))
		{
			//若首尾相同 or 首或尾为'w'，则将首尾叠加
			dest[j] = dest[0] + dest[j];
			//dest[0] = dest[j];
			int temp = dest[j];
			//若开始有'w'，除去'w'后，如果该字符与末尾相同，则将两者叠加
			if ((p[w] == p[i]) && (flag == 1))
			{
				dest[j] += dest[1];
			}
			//若开始是'w'，则叠加到'w'后一个字符
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
题目描述(ID:12048)
标题: 	1.1-1你的飞碟在这里
标签: 	字符串 字符串处理
详情:
众所周知，在每一个彗星后都有一只UFO。这些UFO时常来收集地球上的忠诚支持者。不幸的是，他们的飞碟每次出行都只能带上一组支持者。因此，他们要用一种聪明的方案让这些小组提前知道谁会被彗星带走。他们为每个彗星起了一个名字，通过这些名字来决定这个小组是不是被带走的那个特定的小组（你认为是谁给这些彗星取的名字呢？）。关于如何搭配的细节会在下面告诉你；你的任务是写一个程序，通过小组名和彗星名来决定这个小组是否能被那颗彗星后面的UFO带走。
小组名和彗星名都以下列方式转换成一个数字：最终的数字就是名字中所有字母的积，其中“A”是1，“Z”是26。例如，“USACO”小组就是21*19*1*3*15=17955。如果小组的数字 mod 47等于彗星的数字mod 47,你就得告诉这个小组需要准备好被带走！（记住“a mod b”是a除以b的余数；34 mod 10等于4，一般而言，当其中的a是负数时，不论b的符号如何结果都是负数，但是在数学计算中却不是这样，需要谨记！）
写出一个程序，读入彗星名和小组名并算出用上面的方案能否将两个名字搭配起来，如果能搭配，就输出“GO”，否则输出“STAY”。小组名和彗星名均是没有空格或标点的一串大写字母（不超过6个字母）。

输入格式:
第 1 行:
彗星的名字（一个长度为1到6的字符串）
第 2 行:
团体的名字（一个长度为1到6的字符串）

输出格式:
单独一行包含"STAY"或"GO"
限制: 	1s
样例:

输入
COMETQ
HVNGAT

输出
GO

输入
ABSTAR
USACO

输出
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
题目描述(ID:10016)
标题: 	乒乓球
标签: 	字符串 字符串处理
详情: 	华华通过以下方式进行分析，首先将比赛每个球的胜负列成一张表，然后分别计算在11分制和21分制下，双方的比赛结果（截至记录末尾）。
比赛规则和实际比赛规则相同, 即比分为10:11时还要继续比赛，直到分数差距达到2分.
比如现在有这么一份记录，（其中W表示华华获得一分，L表示华华对手获得一分）：
WWWWWWWWWWWWWWWWWWWWWWLW
在11分制下，此时比赛的结果是华华第一局11比0获胜，第二局11比0获胜，正在进行第三局，当前比分1比1。而在21分制下，此时比赛结果是华华第一局21比0获胜，正在进行第二局，比分2比1。如果一局比赛刚开始，则此时比分为0比0。
你的程序就是要对于一系列比赛信息的输入（WL形式），输出正确的结果。

输入格式:
每个输入文件包含若干行字符串（每行至多20个字母），字符串有大写的W、L和E组成,也许中间有若干个空格。其中E表示比赛信息结束，程序应该忽略E之后的所有内容,E后面可能有干扰文字。

输出格式:
输出由两部分组成，每部分有若干行，每一行对应一局比赛的比分（按比赛信息输入顺序）。其中第一部分是11分制下的结果，第二部分是21分制下的结果，两部分之间由一个空行分隔。

提示: 	NOIP普及组2003
限制: 	30%的数组输入只有一行字符串
100%的数据输入只有若干行字符串
样例:

输入
WWWWWWWWWWWWWWWWWWWWWWLW

输出
11:0
11:0
1:1

21:0
2:1

输入
WWWWWWWWWWWWWWWWWWWW
WWLWEWWWW

输出
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
		printf("11分制局数%d - W:%d L:%d \n", i, WL[i][0], WL[i][1]);
	}
	printf("\n");
	for (int i = 0; i < jj; i++)
	{
		//printf("%d:%d\n", WWLL[i][0], WWLL[i][1]);
		printf("21分制局数%d - W:%d L:%d \n", i, WWLL[i][0], WWLL[i][1]);
	}
}

/*
题目描述(ID:10022)
标题: 	潜伏者
标签: 	字符串 模拟 字符串处理
详情: 	R 国和 S国正陷入战火之中，双方都互派间谍，潜入对方内部，伺机行动。
历尽艰险后，潜伏于 S国的 R 国间谍小 C 终于摸清了 S国军用密码的编码规则：
1． S 国军方内部欲发送的原信息经过加密后在网络上发送，原信息的内容与加密后所
得的内容均由大写字母‘A’-‘Z’构成（无空格等其他字符） 。
2． S国对于每个字母规定了对应的“密字” 。加密的过程就是将原信息中的所有字母替
换为其对应的“密字” 。
3． 每个字母只对应一个唯一的“密字” ，不同的字母对应不同的“密字” 。 “密字”可以
和原字母相同。
例如，若规定‘A’的密字为‘A’ ， ‘B’的密字为‘C’ （其他字母及密字略） ，则原信
息“ABA”被加密为“ACA” 。
现在，小 C 通过内线掌握了 S 国网络上发送的一条加密信息及其对应的原信息。小 C
希望能通过这条信息，破译 S 国的军用密码。小 C 的破译过程是这样的：扫描原信息，对
于原信息中的字母 x（代表任一大写字母） ，找到其在加密信息中的对应大写字母 y，并认为
在密码里 y是 x 的密字。如此进行下去直到停止于如下的某个状态：

1． 所有信息扫描完毕， ‘A’-‘Z’ 所有 26 个字母在原信息中均出现过并获得了相应
的“密字” 。
2． 所有信息扫描完毕，但发现存在某个（或某些）字母在原信息中没有出现。
3． 扫描中发现掌握的信息里有明显的自相矛盾或错误（违反 S国密码的编码规则） 。例
如某条信息“XYZ”被翻译为“ABA”就违反了“不同字母对应不同密字”的规则。

在小 C 忙得头昏脑涨之际，R 国司令部又发来电报，要求他翻译另外一条从 S 国刚刚
截取到的加密信息。现在请你帮助小 C：通过内线掌握的信息，尝试破译密码。然后利用破
译的密码，翻译电报中的加密信息。

输入格式:
输入共3行，每行为一个长度在 1 到100 之间的字符串。
第 1 行为小C 掌握的一条加密信息。
第 2 行为第1 行的加密信息所对应的原信息。
第 3 行为R国司令部要求小 C 翻译的加密信息。
输入数据保证所有字符串仅由大写字母‘A’-‘Z’构成，且第 1 行长度与第 2 行相等。

输出格式:
输出共1行。
若破译密码停止时出现 2，3 两种情况，请你输出“Failed” （不含引号，注意首字母大
写，其它小写） 。
否则请输出利用密码翻译电报中加密信息后得到的原信息。

提示: 	NOIP提高组2009
限制: 	每个测试点1s
样例:

输入
AA
AB
EOWIE

输出
Failed

解释
原信息中的字母‘A’和‘B’对应相同的密字，输出“Failed”。

输入
QWERTYUIOPLKJHGFDSAZXCVBN
ABCDEFGHIJKLMNOPQRSTUVWXY
DSLIEWO

输出
Failed

解释
字母‘Z’在原信息中没有出现，输出“Failed”。

输入
MSRTZCJKPFLQYVAWBINXUEDGHOOILSMIJFRCOPPQCEUNYDUMPP
YIZSDWAHLNOVFUCERKJXQMGTBPPKOIYKANZWPLLVWMQJFGQYLL
FLSO

输出
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
			//已经保存的信息 与 最新的信息 不同，出错
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
题目描述(ID:10012)
标题: 	数字统计
标签: 	模拟
详情: 	请统计某个给定范围[L, R]的所有整数中，数字2出现的次数。
比如在给定范围[2, 22]，数字2在数2中出现了1次，在数12中出现了1次，在数20中出现了1次，在数21中出现了1次，在数22中出现了2次，所以数字2在该范围内一共出现了6次。

输入格式:
输入共一行，为两个正整数L和R，之间用一个空格隔开。

输出格式:
输出共1行，表示数字2出现的次数。

提示: 	NOIP普及组2010
限制: 	1≤L≤R≤10000
每个测试点1秒
样例:

输入
3 22

输出
5

输入
2 100

输出
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
题目描述(ID:12002)
标题: 	校门外的树
标签: 	模拟 排序
详情: 	某校大门外长度为L的马路上有一排树，每两棵相邻的树之间的间隔都是1米。我们可以把马路看成一个数轴，马路的一端在数轴0的位置，另一端在L的位置；数轴上的每个整数点，即0，1，2，……，L，都种有一棵树。

由于马路上有一些区域要用来建地铁。这些区域用它们在数轴上的起始点和终止点表示。已知任一区域的起始点和终止点的坐标都是整数，区域之间可能有重合的部分。现在要把这些区域中的树（包括区域端点处的两棵树）移走。你的任务是计算将这些树都移走后，马路上还有多少棵树。

输入格式:
第一行有两个整数L（1 <= L <= 10000）和 M（1 <= M <= 100），L代表马路的长度，M代表区域的数目，L和M之间用一个空格隔开。接下来的M行每行包含两个不同的整数，用一个空格隔开，表示一个区域的起始点和终止点的坐标。

输出格式:
只有一行，这一行只包含一个整数，表示马路上剩余的树的数目。

提示: 	NOIP普及组2005
限制: 	每个测试点1s
对于20%的数据，区域之间没有重合的部分；
对于其它的数据，区域之间有重合的情况。
样例:

输入
500 3
150 300
100 200
470 471

输出
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
题目描述(ID:10014)
标题: 	多项式输出
标签: 	字符串 字符串处理
详情: 	一元 n 次多项式可用如下的表达式表示：

其中，aixi 称为i次项，ai称为i次项的系数。给出一个一元多项式各项的次数和系数，请按照如下规定的格式要求输出该多项式：

1. 多项式中自变量为x，从左到右按照次数递减顺序给出多项式。
2. 多项式中只包含系数不为0 的项。

3. 如果多项式n 次项系数为正，则多项式开头不出现“+”号，如果多项式n 次项系数为负，则多项式以“-”号开头。

4. 对于不是最高次的项，以“+”号或者“-”号连接此项与前一项，分别表示此项系数为正或者系数为负。紧跟一个正整数，表示此项系数的绝对值（如果一个高于0 次的项，其系数的绝对值为1，则无需输出1）。如果x 的指数大于1，则接下来紧跟的指数部分的形式为“x^b”，其中b 为x 的指数；如果x 的指数为1，则接下来紧跟的指数部分形式为“x”； 如果x 的指数为0，则仅需输出系数即可。

5. 多项式中，多项式的开头、结尾不含多余的空格。

输入格式:
共有2 行。
第一行 1 个整数，n，表示一元多项式的次数(1 ≤ n ≤ 100)。
第二行有 n+1 个整数，其中第i 个整数表示第n-i+1 次项的系数，每两个整数之间用空格隔开。
多项式各次项系数的绝对值均不超过100。

输出格式:
共1 行，按题目所述格式输出多项式。

提示: 	NOIP普及组2009
限制: 	每个测试点1s
样例:

输入
3
-50 0 0 1

输出
-50x^3+1

输入
3
1 -100 0 0

输出
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
题目描述(ID:12039)
标题: 	选数
标签: 	搜索 深度优先搜索
详情:
已知 n 个整数 x1,x2,…,xn，以及一个整数 k（k＜n）。从 n 个整数中任选 k 个整数相加，可分别得到一系列的和。例如当 n=4，k＝3，4 个整数分别为 3，7，12，19 时，可得全部的组合与它们的和为：
3＋7＋12=22　　3＋7＋19＝29　　7＋12＋19＝38　　3＋12＋19＝34。
现在，要求你计算出和为素数共有多少种。
例如上例，只有一种的和为素数：3＋7＋19＝29）。

输入格式:
n , k （1<=n<=20，k＜n）
x1,x2，…,xn （1<=xi<=5000000

输出格式:一个整数（满足条件的种数）。
提示: 	noip2002普及组第二题
限制: 	每个测试点1s
样例:

输入
4 3
3 7 12 19

输出
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
题目描述(ID:12138)
标题: 	1.2-4回文平方数
标签: 	搜索
详情: 	回文数是指从左向右念和从右向左念都一样的数。如12321就是一个典型的回文数。
给定一个进制B(2<=B<=20,由十进制表示)，输出所有的大于等于1小于等于300（十进制下）且它的平方用B进制表示时是回文数的数。用’A’,’B’……表示10，11等等。

输入格式:
共一行，一个单独的整数B(B用十进制表示)。

输出格式:
每行两个B进制的符合要求的数字，第二个数是第一个数的平方，且第二个数是回文数.

样例:
输入
10

输出
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
题目描述(ID:12059)
标题: 	清帝顺治
标签: 	动态规划
详情:
顺治喜欢滑雪，这并不奇怪， 因为滑雪的确很刺激。可是为了获得速度，滑的区域必须向下倾斜，而且当你滑到坡底，你不得不再次走上坡或者等待太监们来载你。顺治想知道载一个区域中最长的滑坡。
区域由一个二维数组给出。数组的每个数字代表点的高度。下面是一个例子：
　　	1  2  3  4  5
   　　	16 17 18 19 6
	 　 15 24 25 20 7
	    14 23 22 21 8
		13 12 11 10 9
顺治可以从某个点滑向上下左右相邻四个点之一，当且仅当高度减小。在上面的例子中，一条可滑行的滑坡为24-17-16-1。当然25-24-23-...-3-2-1更长。事实上，这是最长的一条。

输入格式:
输入的第一行表示区域的行数R和列数C(1 <= R,C <= 500)。下面是R行，每行有C个整数，代表高度h，0<=h<=10000。

输出格式:
输出最长区域的长度。

样例:
输入
5 5
1  2  3  4  5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9

输出
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
	// 遍历m*n的二维数组
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
题目描述(ID:12097)
标题: 	数字三角形
标签: 	动态规划
详情: 	如图所示的数字三角形，从顶部出发，在每一结点可以选择向左走或得向右走，一直走到底层，要求找出一条路径，使路径上的值最大。

输入格式:
第一行是数塔层数N(1<=N<=1000)。
第二行起，按数塔图形，有一个或多个的整数，表示该层节点的值，共有N行。

输出格式:
输出最大值。

样例:
输入
5
13
11 8
12 7 26
6 14 15 8
12 7 13 24 11

输出
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
题目描述(ID:12004)
标题: 	统计数字
标签: 	排序
详情: 	某次科研调查时得到了n个自然数，每个数均不超过1500000000（1.5*10^9）。已知不相同的数不超过10000个，现在需要统计这些自然数各自出现的次数，并按照自然数从小到大的顺序输出统计结果。

输入格式:
第1行是整数n(1<=n<=200000)，表示自然数的个数。
第2~n+1行每行一个自然数。

输出格式:
输出包含m行（m为n个自然数中不相同数的个数），按照自然数从小到大的顺序输出。每行输出两个整数，分别是自然数和该数出现的次数，其间用一个空格隔开。

提示: 	NOIP2007提高组
限制: 	每个测试点1s。
40%的数据满足：1<=n<=1000
80%的数据满足：1<=n<=50000
100%的数据满足：1<=n<=200000，每个数均不超过1500 000 000（1.5*10^9）
样例:

输入
8
2
4
2
4
5
100
2
100

输出
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
题目描述(ID:12200)
标题: 	又见a+b
标签: 	模拟
详情: 	请计算每一行上两个数a、b的和，不过现在你并不知道有多少行

输入格式:
有若行，每行两个数，用空格隔开

输出格式:
每行一个整数

限制: 	-1000<=a,b<=1000
样例:

输入
1 2
3 4
5 6
99 1
123 -321
输出
3
7
11
100
-198

输入
99 100
-1 1
输出
199
0

输入
1 99
输出
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
	//scanf()返回的是输入的正确变量的个数
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
题目描述(ID:10001)
标题: 	陶陶摘苹果
标签: 	模拟
详情:

陶陶家的院子里有一棵苹果树，每到秋天树上就会结出10个苹果。苹果成熟的时候，陶陶就会跑去摘苹果。陶陶有个30厘米高的板凳，当她不能直接用手摘到苹果的时候，就会踩到板凳上再试试。
现在已知10个苹果到地面的高度，以及陶陶把手伸直的时候能够达到的最大高度，请帮陶陶算一下她能够摘到的苹果的数目。假设她碰到苹果，苹果就会掉下来。

输入格式:
输入包括两行数据。第一行包含10个100到200之间（包括100和200）的整数（以厘米为单位）分别表示10个苹果到地面的高度，两个相邻的整数之间用一个空格隔开。第二行只包括一个100到120之间（包含100和120）的整数（以厘米为单位），表示陶陶把手伸直的时候能够达到的最大高度。

输出格式:
输出包括一行，这一行只包含一个整数，表示陶陶能够摘到的苹果的数目。

限制: 	每个测试点1s
样例:

输入
153 192 174 186 179 104 157 172 128 182
100
输出
2

输入
163 175 148 130 173 124 102 121 129 164
106
输出
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
题目描述(ID:10011)
标题: 	质因数
标签: 	其他 数学
详情: 	已知正整数n是两个不同的质数的乘积，试求出较大的那个质数。

输入格式:
输入只有一行，包含一个正整数n。

输出格式:
输入只有一行，包含一个正整数n。

提示: 	NOIP普及组2012
限制: 	对于60%的数据，6 ≤ n ≤ 1000。 对于100%的数据，6 ≤ n ≤ 2 * 10^9。
每个测试点1秒
样例:

输入
6
输出
3

输入
119
输出
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
题目描述(ID:12030)
标题: 	牛式
标签: 	搜索 枚举
详情: 	下面是一个乘法竖式，如果用我们给定的那n个数字来取代*，可以使式子成立的话，我们就叫这个式子牛式。
    ***
x    **
----------
    ***
   ***
----------
   ****
数字只能取代*，当然第一位不能为0,况且给定的数字里不包括0。
注意一下在美国的学校中教的“部分乘积”，第一部分乘积是第二个数的个位和第一个数的积，第二部分乘积是第二个数的十位和第一个数的乘积.
写一个程序找出所有的牛式。

输入格式:
第一行：数字的个数n。
第二行：N个用空格分开的数字（每个数字都属于{1,2,3,4,5,6,7,8,9}）。

输出格式:
共一行，一个数字。表示牛式的总数。

提示: 	USACO Training
限制: 	每个测试点1秒
样例:

输入
5
2 3 4 6 8
输出
1

解释
222
x 22
----------
444
444
----------
4884
注意：结果只能为4位
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
					//提前退出，防止超时
					if ((nN[a] * 100 + nN[b] * 10 + nN[c]) * nN[d] > 999) continue;
					for (e = 0; e < j; e++)
					{
						//提前退出，防止超时
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
题目描述(ID:12155)
标题: 	2.2-2集合
标签: 	搜索
详情: 	对于从1到N (1 <= N <= 39) 的连续整数集合，能划分成两个子集合，且保证每个集合的数字和是相等的。举个例子，如果N=3，对于{1，2，3}能划分成两个子集合，每个子集合的所有数字和是相等的：
{3} 和 {1,2}这是唯一一种分法（交换集合位置被认为是同一种划分方案，因此不会增加划分方案总数）如果N=7，有四种方法能划分集合{1，2，3，4，5，6，7}，每一种分法的子集合各数字和是相等的:
{1,6,7} 和 {2,3,4,5} {注 1+6+7=2+3+4+5}{2,5,7} 和 {1,3,4,6}{3,4,7} 和 {1,2,5,6}{1,2,4,7} 和 {3,5,6}给出N，你的程序应该输出划分方案总数，如果不存在这样的划分方案，则输出0。程序不能预存结果直接输出（不能打表）。

输入格式:
输入文件只有一行，且只有一个整数N

输出格式:
输出划分方案总数，如果不存在则输出0。

样例:

输入
7
输出
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
题目描述(ID:12145)
标题: 	1.4-2母亲的牛奶
标签: 	搜索
详情:
农民约翰有三个容量分别是A,B,C升的桶，A,B,C分别是三个从1到20的整数， 最初，A和B桶都是空的，而C桶是装满牛奶的。有时，农民把牛奶从一个桶倒到 另一个桶中，直到被灌桶装满或原桶空了。当然每一次灌注都是完全的。由于节约， 牛奶不会有丢失
写一个程序去帮助农民找出当A桶是空的时候，C桶中牛奶所剩量的所有可能性。

输入格式:
单独的一行包括三个整数A,B和C。

输出格式:
只有一行，升序地列出当A桶是空的时候，C桶牛奶所剩量的所有可能性

样例:

输入
8 9 10
输出
1 2 8 9 10

输入
2 5 10
输出
5 6 7 8 9 10
*/
#ifdef A(x)
#undef A(x)
#undef B(x)
int tot = 0;
int ff[20][20][20] = { 0,0,0 }, res[100];
//思路：A->B,A->C,B->A,B->C,C->A,C->B一共六种情况搜索即可，用一个f[][][]来记录是否到过这个情况。
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
题目描述(ID:12198)
标题: 	跳石头
标签: 	其他 二分查找
详情:
一年一度的“跳石头”比赛又要开始了!
这项比赛将在一条笔直的河道中进行,河道中分布着一些巨大岩石。组委会已经选择好了两块岩石作为比赛起点和终点。在起点和终点之间,有 N 块岩石(不含起点和终 点的岩石)。在比赛过程中,选手们将从起点出发,每一步跳向相邻的岩石,直至到达 终点。
为了提高比赛难度,组委会计划移走一些岩石,使得选手们在比赛过程中的最短跳 跃距离尽可能长。由于预算限制,组委会至多从起点和终点之间移走 M 块岩石(不能 移走起点和终点的岩石)。

输入格式:
输入文件第一行包含三个整数 L,N,M,分别表示起点到终点的距离,起点和终 点之间的岩石数,以及组委会至多移走的岩石数。
接下来 N 行,每行一个整数,第 i 行的整数 Di(0 < Di < L)表示第 i 块岩石与 起点的距离。这些岩石按与起点距离从小到大的顺序给出,且不会有两个岩石出现在同 一个位置。

输出格式:
输出文件只包含一个整数,即最短跳跃距离的最大值。

限制: 	对于 20%的数据,0 ≤ M ≤ N ≤ 10。 对于50%的数据,0 ≤ M ≤ N ≤ 100。

对于 100%的数据,0 ≤ M ≤ N ≤ 50,000,1 ≤ L ≤ 1,000,000,000。
样例:

输入
25 5 2
2
11
14
17
21

输出
4

解释
将与起点距离为 2 和 14 的两个岩石移走后,最短的跳跃距离为 4(从与起点距离 17 的岩石跳到距离 21 的岩石,或者从距离 21 的岩石跳到终点)。
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