﻿
#include "stdafx.h"
#include <stdlib.h>
#include "string.h"
#include "stdio.h"
//#include "boolean.h"
#include "math.h"
#include "stdbool.h"

char *ss = "3[a2[c]]";
char * sdfs(char s[], int i, int len, int flag, char temp[], int count)
{
	int  k = 0;//flag = 0,
			   //int count = 0;
			   //char temp[10] = { 0 };
			   //printf("j = %d \n", j);
			   //for (int i = Z; i < len; i++)
	while (i<len)
	{
		char t = ss[i];
		if (t == ']')
		{
			//printf("j = %d, %s\n", j, temp);
			if (flag)
			{
				flag = 0; printf("\n");
				for (int x = 0; x < count; x++)
				{
					printf("%s", temp);
					//memcpy(temp, temp, k + 1);
					//strcat_s(temp, k, temp);
				}
				//printf("(%c)", s[i - k - 2]);
				//memcpy(s + i - k - 2, "cccc", 4);
				//memcpy(temp, "cccc", 4);
				memcpy(&ss[0], "3[accc]__", 8);
				return temp;
			}
			else
				continue;
		}
		if (t == '[')
		{
			flag = 1;
			sdfs(ss, ++i, len, flag, temp, count);
			//printf("%s",sdfs(s, ++i, len));
		}
		if (t >= '0' && t <= '9')
		{
			//printf("(%c)", s[i]);
			count = t - '0';
		}
		else
		{
			printf("^%c", t);
			temp[k++] = t;
			temp[k] = '\0';
		}
		i++;
		printf("{%d}=%s\n", i, &ss[i]);
	}
}

char * ssdfs(char *ss, int len, int i)
{
	char dest[500] = { 0 };
	char sdest[500] = { 0 };
	int scount = 0; int sc = 0;
	int s = 0, e = 0; int k = 0;
	int start = 0, end = 0;
	//printf("ss = %d \n", strlen(ss));
	//printf("%d %d %d %d \n", scount, sc, s, e, k);
	//printf("i = %d, len = %d, %s \n", i, len, ss);
	while (i < len)
	{
		char t = ss[i];
		if ((t >= '0' && t <= '9') && (s == 0))
			scount = t - '0';
		else if (t == '[')
			s++;
		else if (t == ']')
			e++;

		if ((s == 1) && (start == 0))
		{
			start = i;
		}
		if (s == 0 && e == 0 && t >= 'a' && t <= 'z')
		{
			//printf("%c", t);
			sdest[sc++] = t;
		}
		if ((s == e) && (s != 0))
		{
			if (e > 0) k = 1;
			end = i;
			//printf("s = %d, e = %d \n", start, end);
			int length = end - start - 1;
			for (int j = 0; j < scount; j++)
			{
				memcpy(dest + (j * length), ss + start + 1, length);
			}

			//printf("%s", dest);
			memcpy(&sdest[sc], dest, scount * length);
			sc = sc + scount * length;
			//printf("sc = %d \n", sc);

			s = 0; e = 0; scount = 0;
			start = 0; end = 0;
		}
		i++;
	}
	//printf("k = %d, %s \n", k, sdest);
	if (k != 0)
		ssdfs(sdest, sc, 0);
	else
		return sdest;//"adsf";//
					 //printf(" %s\n",sdest);
}

/*
示例:
s = "3[a]2[bc]", 返回 "aaabcbc".
s = "3[a2[c]]", 返回 "accaccacc".
s = "2[abc]3[cd]ef", 返回 "abcabccdcdcdef".
*/
char* decodeString(char *s) {

	char *ss =
		//"3[a2[c]]"; //
		//"we3[c2[4[a]]]we3[c2[4[a]]]we3[c2[4[a]]]we3[c2[4[a]]]";
		//"4[we3[c2[4[a]]]]";
		//"4[wec2[4[a]]]";
		//"3[a]2[bc]";
		//"2[abc]3[cd]ef"; // 
		"3[ab2[c]de4[f]g]";
	int i = 0;
	int temp[20] = { 0 };
	//printf("l = %d \n", strlen(ss));
	//for (i = 0; i < strlen(s); i++)
	{
		//sdfs(ss, 0, strlen(ss), 0, temp, 0);
	}
	return ssdfs(ss, strlen(ss), 0);
	//printf("%s",ssdfs(ss, strlen(ss), 0));
}

/*
415. 字符串相加

给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。

注意：
num1 和num2 的长度都小于 5100.
num1 和num2 都只包含数字 0-9.
num1 和num2 都不包含任何前导零。
你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式。
*/

char* addStrings(char* num1, char* num2) {

	int c1 = strlen(num1), c2 = strlen(num2);
	//printf("[%d] = %s, [%d] = %s \n", c1, num1, c2, num2);

	int max = c1 > c2 ? c1 : c2;
	max = max + 1;

	//printf("max = %d \n", max);
	int i = 0;
	char * A = (char *)malloc(sizeof(char) * (max + 0));
	char * B = (char *)malloc(sizeof(char) * (max + 0));
	char * C = (char *)malloc(sizeof(char) * (max + 1));

	for (i = 0; i < max; i++)
	{
		A[i] = '0';B[i] = '0';C[i] = '0';
	}
 
	if (c1 == max-1)
	{
		memcpy(&B[max - c2 ], num2, c2);
		memcpy(A+1, num1, c1);
	}
	else if(c2 == max-1)
	{
		memcpy(&A[max - c1], num1, c1);
		memcpy(B+1, num2, c2);
	}
	/*
	//printf("%s, %s\n\n", A, B);
	for (i = 0; i < max; i++)
	{
		printf("%c, %c\n", A[i], B[i]);
	}
	*/
#define A(x) (A[(x)] - '0')
#define B(x) (B[(x)] - '0')
	//StringPlus(A,B,C);
	int flag = 0;
	for (int i = max - 1; i >= 0; i--)
	{
		if ((A(i) + B(i) == 9) && (flag == 1))
		{
			C[i] = '0';continue;
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
		//printf("C[%d] = %c  ", i, C[i]);
	}

	C[max] = '\0';
	//printf("c = %s\n", C);

	if (C[0] == '0') return (C + 1);
	else return C;
}

/*
43. 字符串相乘

给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

示例 1:
输入: num1 = "2", num2 = "3"
输出: "6"

示例 2:
输入: num1 = "123", num2 = "456"
输出: "56088"

说明：
num1 和 num2 的长度小于110。
num1 和 num2 只包含数字 0-9。
num1 和 num2 均不以零开头，除非是数字 0 本身。
不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。
*/
char* multiply(char* num1, char* num2) {

	int c1 = strlen(num1), c2 = strlen(num2);
	printf("[%d] = %s, [%d] = %s \n", c1, num1, c2, num2);

	int max = c1 > c2 ? c1 : c2;

	//printf("max = %d \n", max);
	int i = 0, j = 0;
	max = max + max;
	char * A = (char *)malloc(sizeof(char) * (c1 + 0));
	char * B = (char *)malloc(sizeof(char) * (c2 + 0));
	char * C = (char *)malloc(sizeof(char) * (max + 2));
	char * D = (char *)malloc(sizeof(char) * (max + 2));

	for (i = 0; i < max+2; i++)
	{
		C[i] = '0'; D[i] = '0';
	}
	memcpy(A, num1, c1);
	memcpy(B, num2, c2);
	A[c1] = '\0';
	B[c2] = '\0';
	printf("%s, %s\n\n", A, B);
	/*
	for (i = 0; i < max; i++)
	{
		printf("%c, %c\n", A[i], B[i]);
	}
	*/
#define A(x) (A[(x)] - '0')
#define B(x) (B[(x)] - '0')
	int z = 0;
	for (i = c1 - 1; i >= 0; i--)
	{
		int k = max;int flag = 0;
		for (j = c2 - 1; j >= 0; j--)
		{
			int t = A(i) * B(j);
			int h = t % 10;
            //printf("A=%d, B=%d, t=%d, h=%d \n", A(i), B(j), t, h);

			if ((t == 9) && (flag != 0))
			{
				C[k] = flag + '0'; continue;
			}
			if (t > 9)
			{
				if (flag != 0)
					C[k] = flag + h + '0';
				else
					C[k] = h + '0';
				flag = t/10;
			}
			else
			{
				if (flag != 0)
				{
					C[k] = flag + h + '0';
					flag = 0;
				}
				else
					C[k] = h + '0';
			}
			k--;
		}
		if (flag != 0)  C[max - k] = flag + '0';
		
		C[max + 2] = '\0';
		D[max + 2] = '\0';

		memcpy(C, C + z, sizeof(char) * (max + 2));
		for (i = 0; i < z; i++)
		{
			C[max + 1 - z] = '0';
		}
		C[max + z] = '0';
		printf("C = %s\n", C);
        printf("D = %s\n\n", D);

		memcpy(D, addStrings(C, D) , sizeof(char) * (max + 2));
	
		z++;
		//printf("%s\n", addStrings(C, D));
		//printf("C[%d] = %c  ", i, C[i]);
	}

	for (i = 0; i < max; i++)
	{
		if (D[i] != '0')
			break;
	}
	D[max+1] = '\0';
	printf("d = %s\n", D+i);

    return D+i;
}

/*
判断两矩形是否交叉：
https://www.cnblogs.com/avril/archive/2012/11/13/2767577.html
*/
int isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size) {
	int nMaxLeft = 0;
	int nMaxTop = 0;
	int nMinRight = 0;
	int nMinBottom = 0;

	// Get the max left.
	if (rec1[0] >= rec2[0])
	{
		nMaxLeft = rec1[0];
	}
	else
	{
		nMaxLeft = rec2[0];
	}
	// Get the max top.
	if (rec1[3] >= rec2[3])
	{
		nMaxTop = rec1[3];
	}
	else
	{
		nMaxTop = rec2[3];
	}
	// Get the min right.
	if (rec1[2] <= rec2[2])
	{
		nMinRight = rec1[2];
	}
	else
	{
		nMinRight = rec2[2];
	}
	// Get the min bottom.
	if (rec1[1] <= rec2[1])
	{
		nMinBottom = rec1[1];
	}
	else
	{
		nMinBottom = rec2[1];
	}
	// Judge whether intersects.
	if (nMaxLeft > nMinRight || nMaxTop > nMinBottom)
	{
		return 0;
	}
	else
	{
		return 1;
	}


#define x1 0
#define y1 1
#define x2 2
#define y2 3

#define x3 0
#define y4 1
#define x4 2
#define y4 3

	if ((rec2[x3] < rec1[x1] || rec2[x3] < rec1[x2]) &&
		(rec1[x1] < rec2[x4] || rec1[x2] < rec2[x4]))
	{
		;
	}
}

void ID836()
{
	//int rec1[] = { 0, 0, 1, 1 }, rec2[] = { 1, 0, 2, 1 };
	int rec1[] = { 0, 0, 2, 2 }, rec2[] = { 1, 1, 3, 3 };
	printf("%d\n", isRectangleOverlap(rec1, 0, rec2, 0));
}

/*
853. 车队    题目难度 Medium

N  辆车沿着一条车道驶向位于 target 英里之外的共同目的地。
每辆车 i 以恒定的速度 speed[i] （英里/小时），从初始位置 position[i] （英里） 沿车道驶向目的地。
一辆车永远不会超过前面的另一辆车，但它可以追上去，并与前车以相同的速度紧接着行驶。
此时，我们会忽略这两辆车之间的距离，也就是说，它们被假定处于相同的位置。
车队 是一些由行驶在相同位置、具有相同速度的车组成的非空集合。注意，一辆车也可以是一个车队。
即便一辆车在目的地才赶上了一个车队，它们仍然会被视作是同一个车队。

会有多少车队到达目的地?

示例：
输入：target = 12, position = [10,8,0,5,3], speed = [2,4,1,1,3]
输出：3
解释：
从 10 和 8 开始的车会组成一个车队，它们在 12 处相遇。
从 0 处开始的车无法追上其它车，所以它自己就是一个车队。
从 5 和 3 开始的车会组成一个车队，它们在 6 处相遇。
请注意，在到达目的地之前没有其它车会遇到这些车队，所以答案是 3。

提示：
0 <= N <= 10 ^ 4
0 < target <= 10 ^ 6
0 < speed[i] <= 10 ^ 6
0 <= position[i] < target
所有车的初始位置各不相同.
*/
int carFleet(int target, int* position, int positionSize, int* speed, int speedSize) 
{
	//printf("%d %d %d \n", target, positionSize, speedSize);
	int i = 0, j = 0, k = 0;;
   int dest[50][1000] = { 0 };
   int t = 0;
   for (i = 0; i < positionSize; i++)
   {
	   t = 0;
	   for (j = 0; j <= target; j++)
	   {
			t = position[i] + speed[i] * j;
			dest[i][j] = t;
		    if (t >= target) break;
	   }
   }

   for (i = 0; i < positionSize; i++)
   {
	   for (j = 0; j <= target; j++)
	   {
		   if ((dest[i][j] != 0) || (j == 0))
			   printf("%3d ", dest[i][j]);
	   }
	   printf("\n");
   }

   int d[50] = { 0 }; int c = 0;
   for (j = 1; j <= target; j++)
   {
	   for (i = 0; i < positionSize; i++)
	   {
		   if (dest[i][j] <= target && dest[i][j] != 0)
		   {
			   for (int a = 0; a < k; a++)
				   ;//if (d[a] == i);else
				   
			   {
				   if (dest[i][j] == dest[i + 1][j])
				   {
					   if (dest[i][j - 1] > dest[i + 1][j - 1])
						   d[k++] = i + 1;
					   else
						   d[k++] = i;
					   c++;
					   printf("%d ", d[k-1]);
				   }
			   }
		   }
	   }   
   }
   printf("\n %d \n", positionSize - c);
   return (positionSize - c);
}

int ID853()
{
	//int target = 12, position[] = { 10, 8, 0, 5, 3 }, speed[] = { 2, 4, 1, 1, 3 };

	//int target = 15, position[] = { 4, 8, 0, 5, 3, 2 }, speed[] = { 2, 4, 6, 2, 3, 1 };
	/*
	int target = 660732,
	position[] = { 620831, 145366, 229113, 144305, 382893, 514856, 171642, 87230, 409014, 65613 },
	   speed[] = { 327716, 69772, 667805, 856849, 78755, 606982, 696937, 207697, 275337, 290550 };
	*/

	int target = 156, position[] = { 70, 98, 30, 109, 120 }, speed[] = { 20, 24, 11, 14, 3 };
	carFleet(target,position,5,speed,5);

	return 0;
}

/*
855. 考场就座  题目难度 Medium

在考场里，一排有 N 个座位，分别编号为 0, 1, 2, ..., N-1 。
当学生进入考场后，他必须坐在能够使他与离他最近的人之间的距离达到最大化的座位上。如果有多个这样的座位，他会坐在编号最小的座位上。(另外，如果考场里没有人，那么学生就坐在 0 号座位上。)
返回 ExamRoom(int N) 类，它有两个公开的函数：其中，函数 ExamRoom.seat() 会返回一个 int （整型数据），代表学生坐的位置；函数 ExamRoom.leave(int p) 代表坐在座位 p 上的学生现在离开了考场。
请确保每次调用 ExamRoom.leave(p) 时都有学生坐在座位 p 上。


示例：
输入：["ExamRoom","seat","seat","seat","seat","leave","seat"], [[10],[],[],[],[],[4],[]]
输出：[null,0,9,4,2,null,5]
解释：
ExamRoom(10) -> null
seat() -> 0，没有人在考场里，那么学生坐在 0 号座位上。
seat() -> 9，学生最后坐在 9 号座位上。
seat() -> 4，学生最后坐在 4 号座位上。
seat() -> 2，学生最后坐在 2 号座位上。
leave(4) -> null
seat() -> 5，学生最后坐在 5 号座位上。

提示：
1 <= N <= 10^9
在所有的测试样例中 ExamRoom.seat() 和 ExamRoom.leave() 最多被调用 10^4 次。
调用 ExamRoom.leave(p) 时需要确保当前有学生坐在座位 p 上。
*/

typedef struct _Exam{
	int (*seat)();
	int(*leave)(int);
	int(*free)();
	int *S;
	int none;
	int larget;
	int * k;
	int * v;
} ExamRoom;

int examRoomSeat(ExamRoom* obj) {

	if (obj->none == 0)
	{
		obj->none = 1;
		obj->S[0] = 1;
		return 0;
	}
	else
	{
		/*
		int i = 0, a = 0, b = 0;
		for (i = 0; i < obj->larget; i++)
		{
			if (obj->S[i] == 1)
			{
				obj->k[a++] = i;
				printf("%d",i);
			}
			else
			{
				obj->v[b - 1]++;
			}
		}
		*/
	}
}

void examRoomLeave(ExamRoom* obj, int p) {

	if ((p < obj->larget) && (obj->S[p] != 0))
	{
		obj->S[p] = 0;
	}
}

void examRoomFree(ExamRoom* obj) {

}

ExamRoom* examRoomCreate(int N) {
	//ExamRoom a;
	ExamRoom* a = (ExamRoom*)malloc(sizeof(ExamRoom*));

	a->seat = examRoomSeat;
	a->leave = examRoomLeave;
	a->free = examRoomFree;
	a->k = (int *)malloc(sizeof(int) * N);
	a->v = (int *)malloc(sizeof(int) * N);
	a->S = (int *)malloc(sizeof(int) * N);
	a->none = 0;
	a->larget = N;
	return &a;
}
/**
* Your ExamRoom struct will be instantiated and called as such:
* struct ExamRoom* obj = examRoomCreate(N);
* int param_1 = examRoomSeat(obj);
* examRoomLeave(obj, p);
* examRoomFree(obj);
*/
void ID855()
{
	struct ExamRoom* obj = examRoomCreate(10);
	int param_1 = examRoomSeat(obj);
	examRoomLeave(obj, 4);
	examRoomFree(obj);

}

/*
67. 二进制求和
给定两个二进制字符串，返回他们的和（用二进制表示）。
输入为非空字符串且只包含数字 1 和 0。

示例 1:
输入: a = "11", b = "1"
输出: "100"

示例 2:
输入: a = "1010", b = "1011"
输出: "10101"
*/
char* addBinary(char* a, char* b) {
	int a_long = strlen(a), b_long = strlen(b);
	int max = a_long > b_long ? a_long : b_long;

	//char *c = (char *)malloc(sizeof(char)*(max + 2));
	char *c = (char *)malloc(sizeof(char) * 600);

	if (max == a_long)
		memcpy(c + (max - b_long) + 1, b, max);
	else
		memcpy(c + (max - a_long) + 1, a, max);

	int i = 0, j = 0;
	for (i = 0; i<max + 2; i++)
	{
		if (c[i] == '1' || c[i] == '0')
			break;
		c[i] = '0';
	}

	int flag = 0; int t = 0;
	for (i = max; i > 0; i--)
	{
		if (max == a_long)
			t = (c[i] - '0') + (a[i - 1] - '0') + flag;
		else
			t = (c[i] - '0') + (b[i - 1] - '0') + flag;
		printf("[%d] = %d \n", i, t);
		if (t == 3)
		{
			flag = 1;
			c[i] = '1';
		}
		else if (t == 2)
		{
			flag = 1;
			c[i] = '0';
		}
		else if (t == 1)
		{
			flag = 0;
			c[i] = '1';
		}
		else if (t == 0)
		{
			flag = 0;
			c[i] = '0';
		}
	}
	c[max + 1] = '\0';
	
	if (flag)
	{
		c[0] = '1';
		return c;
	}
	else
		return c + 1;
}

void ID67()
{
    /*
	char* a = "110011101101001101010001010100101000110101001011111101101101111011110100001000110010000110",
		 *b = "10011100000001101001000000011100100010110101011011110110100010";
		 
	*/		
	char* a = "1000111111101100010001101101100000011100111001010110000010100111010111000101010001",
		*b =  "110110101011011101110100000010101111111110011100011011011000110000101010010010010101000110";
	
	printf("%s\n%s\n", a, b);
	printf("%s\n", addBinary(a, b)); //addBinary("11", "1")); //addBinary("1010", "1011")); //
	//addBinary(a, b);
}

/*
860. 柠檬水找零  题目难度 Easy

在柠檬水摊上，每一杯柠檬水的售价为 5 美元。
顾客排队购买你的产品，（按账单 bills 支付的顺序）一次购买一杯。
每位顾客只买一杯柠檬水，然后向你付 5 美元、10 美元或 20 美元。你必须给每个顾客正确找零，也就是说净交易是每位顾客向你支付 5 美元。
注意，一开始你手头没有任何零钱。

如果你能给每位顾客正确找零，返回 true ，否则返回 false 。

示例 1：
输入：[5,5,5,10,20]
输出：true
解释：
前 3 位顾客那里，我们按顺序收取 3 张 5 美元的钞票。
第 4 位顾客那里，我们收取一张 10 美元的钞票，并返还 5 美元。
第 5 位顾客那里，我们找还一张 10 美元的钞票和一张 5 美元的钞票。
由于所有客户都得到了正确的找零，所以我们输出 true。

示例 2：
输入：[5,5,10]
输出：true

示例 3：
输入：[10,10]
输出：false

示例 4：
输入：[5,5,10,10,20]
输出：false
解释：
前 2 位顾客那里，我们按顺序收取 2 张 5 美元的钞票。
对于接下来的 2 位顾客，我们收取一张 10 美元的钞票，然后返还 5 美元。
对于最后一位顾客，我们无法退回 15 美元，因为我们现在只有两张 10 美元的钞票。
由于不是每位顾客都得到了正确的找零，所以答案是 false。
*/

int lemonadeChange(int* bills, int billsSize) {

	int i = 0, j = 0, k = 0;
	int have[100] = { 0 };
	int d_5 = 0, d_10 = 0, d_20 = 0;

	for (i = 0; i < billsSize; i++)
	{
		if (bills[i] == 5)
		{
			d_5++;
		}
		else if (bills[i] == 10)
		{
			d_10++;

			if (d_5 != 0)
			{
				d_5--;
			}
			else return 0;
		}
		else if (bills[i] == 20)
		{
			d_20++;
			if (d_5 > 0 && d_10 > 0)
			{
				d_5--;d_10--;
			}
			else if (d_5 > 3)
			{
				d_5 = d_5 - 3;
			}
			else return 0;
		}
	}
	return 1;
}

void ID860()
{
	//int bills[5] = { 5,5,10,10,20 }, billsSize = 5;
	// bills[5] = { 5,5,10 }, billsSize = 3;
	int bills[5] = { 5,5,5,10,20 }, billsSize = 5;

	printf("%d \n", lemonadeChange(bills, billsSize));
}

/*
854. 相似度为 K 的字符串  题目难度 Hard

如果可以通过将 A 中的两个小写字母精确地交换位置 K 次得到与 B 相等的字符串，我们称字符串 A 和 B 的相似度为 K（K 为非负整数）。
给定两个字母异位词 A 和 B ，返回 A 和 B 的相似度 K 的最小值。

示例 1：
输入：A = "ab", B = "ba"
输出：1

示例 2
输入：A = "abc", B = "bca"
输出：2

示例 3：
输入：A = "abac", B = "baca"
输出：2

示例 4：
输入：A = "aabc", B = "abca"
输出：2

提示：
1 <= A.length == B.length <= 20
A 和 B 只包含集合 {'a', 'b', 'c', 'd', 'e', 'f'} 中的小写字母。
*/

int kSimilarity(char* A, char* B) 
{
	int a = strlen(A), b = strlen(B);

	int diff[21] = { 0 };

	int i = 0;
	for (i = 0; i < a; i++)
	{
		if (A[i] != B[i])
			diff[i] = 1;
		else
			diff[i] = 0;
	}

	printf("%s\n%s\n", A, B);
	for (i = 0; i < a; i++)
	  printf("%d", diff[i]);
}

void ID854()
{
	char *A = "abcbd";
	char *B = "bcadb";
	kSimilarity(A, B);
}

/*
844. 比较含退格的字符串  题目难度 Easy

给定 S 和 T 两个字符串，当它们分别被输入到空白的文本编辑器后，判断二者是否相等，并返回结果。 # 代表退格字符。

示例 1：
输入：S = "ab#c", T = "ad#c"
输出：true
解释：S 和 T 都会变成 “ac”。

示例 2：
输入：S = "ab##", T = "c#d#"
输出：true
解释：S 和 T 都会变成 “”。

示例 3：
输入：S = "a##c", T = "#a#c"
输出：true
解释：S 和 T 都会变成 “c”。

示例 4：
输入：S = "a#c", T = "b"
输出：false
解释：S 会变成 “c”，但 T 仍然是 “b”。

提示：
1 <= S.length <= 200
1 <= T.length <= 200
S 和 T 只含有小写字母以及字符 '#'。
*/

int backspaceCompare(char* S, char* T) {

	int s_long = strlen(S), t_long = strlen(T);

	char ss[200] = { 0 }, tt[200] = { 0 };

	int i = 0, j = 0, k = 0;
	int a = 0, b = 0;

	for (i = 0; i <= s_long; i++)
	{
		if (S[i] == '#')
			a++;
		else
		{
           //printf("a = %d,k = %d \n",a, k);
			if (a)
			{
				a = a > k ? k : a;
				for (j = 0; j < a; j++)
					ss[k - j - 1] = '0';
				k = k - a;
				a = 0;
			}
			ss[k++] = S[i];
		}
	}
	printf("%s\n", ss);
	a = 0, b = 0, k = 0;
	for (i = 0; i <= t_long; i++)
	{
		if (T[i] == '#')
			a++;
		else
		{
			//printf("a = %d,k = %d \n", a, k);
			if (a)
			{
				a = a > k ? k : a;
				for (j = 0; j < a; j++)
					tt[k - j - 1] = '0';
				k = k - a;
				a = 0;
			}
			tt[k++] = T[i];
		}
	}
	printf("%s\n", tt);

	if (strcmp(ss, tt) == 0)
		return 1;
	else return 0;
}

void ID844()
{
	char* S = "ab#c";// 
	char* T = "ba##c";

	backspaceCompare(S, T);
}

/*
434. 字符串中的单词数

统计字符串中的单词个数，这里的单词指的是连续的不是空格的字符。
请注意，你可以假定字符串里不包括任何不可打印的字符。

示例:
输入: "Hello, my name is John"
输出: 5
*/
int countSegments(char* s) {

	int n = strlen(s);
	int i = 0,j = 0, k = 0;
	for (i = 0; i < n; i++)
	{
		if (s[i] != ' ')
			j++;
		else
		{
			if (j != 0)
			{
				j = 0;
				k++;
			}
		}
	}
	if (j != 0) k++;
	printf("%d\n", k);
	return k;
}

void ID434()
{
	char *s =
		//"a a";
		//"love live! mu'sic forever";
		//"Hello, my name is John t";
		//"Hello \
		my name is John";
		" ";
	countSegments(s);
}

/*
557. 反转字符串中的单词 III

给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

示例 1:
输入: "Let's take LeetCode contest"
输出: "s'teL ekat edoCteeL tsetnoc"

注意：在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。
*/
char* reverseWords(char* s) {

	int n = strlen(s);
	int i = 0, j = 0, k = 0, x = 0;
	char *temp = (char *)malloc(sizeof(char) * (n + 2));
	char *S = (char *)malloc(sizeof(char) * (n + 2));

	for (i = 0; i <= n; i++)
	{
		if ((s[i] != ' ') && (s[i] != '\0'))
			temp[j++] = s[i];
		else
		{
			if (j == 0) continue;
				//printf("%d %s ",j, temp);
				for (x = j - 1; x >= 0; x--)
				{
					//if (temp[x] == '\0') continue;
					S[k++] = temp[x];
				}
			if(s[i] != '\0') S[k++] = ' ';
			j = 0;
		}
	}
	S[k] = '\0';
	free(temp);
	return S;
}

void ID557()
{
	char * s =
		//" contest";
		"Let's take LeetCode contest";
		//"@$s#^fcfavksifsa$vdi@*#xjj@iyfu(yr six)iukijr*h#zpj^&x&zbkrltog@mk#wqu%pi^a#d&*^ebjplgr$#afzyswyr!lst! e!cpcialx*hcqscwos)ap@ibtd!%(*# ipejppx@i(drwy)yzun^!#kjmqwpw^erb!pvvlx!hsvh^)&$zfyk%o#@kvktjl@wc^gleh%ak#qw*i^hv)e(^tx #m!h&trlvrvbnkxsspe%g&j#ktv*$ctqzlmpzt&d%y^rhv* (*hsvc&r myw^wd!kocbvfw@lgw!wpi@!*e&pkdtzvyhmuf*nysayisdayfj)cgf)ek%d^lg!xqkwt*axpivbnsuv$!ub c!&$xgwpbmef$h!*ab%xdubkzgzqwt*fbwfmdklkwe!ivqj^fc)i*kkxyp q^*hlixks!daq@av($!!mgt)tp@oroligbh*ki$pfgmjhmjstx*^)vzkhx$&wkrep@m*ekabuz(ery $nxnuojpuvhdws(*$%r &m&#&mbjn)qq(a$v)tj(bis^aeu$w^o)tefqb^&)o#qha!ryaomldm *b$s$p odjfdhm%&lenscf%j&n) !udk)(qdaruvuwjzlo&%@^$tdyij)ejjaue^bk r%$vnl(ntlcyyrd)yaio%f@flw#f%)^ssg*j$wdbwtbdemabas@tbg%vwh%vezmq ch*l)^gfj*oygdxdzsa#x!ajuecn)fb#w#!^sarranot^!pd&crx$zmu) @t^(@^!c$vahppwvzyo!b^r*nqirp)wo^!@@uzc@ @kbfvz!e#ch)p&*cb%ntf#gtl&yhotxxuw!qx*maowsclenlvxa&m)&n!zw #eb^)uo%orkqr)ja!lv%vtpcwbanrdbm!)u* h((v^appjjtxw)@g@xumbd)!hkkjft@qr$%v%f@xotitvb%g)y^%uinkzs)g&signx^ln(g(pmqfqw(binipjxh!ijfcrr@*a#@k rallve$(hme&gqiddczx%e)jzm*sj%xjl!zbnfh#n#e^qy*l%%uhjiq)bj(d^v^qjhjs&nth&vk&tn&dh##atx f^bfuiouarc !#trgshnipa&afilhgv&@rg!avktl@vz*lrqw(pa@z)*^(ynz(mxv&l^)(hjfhjwq@rtxa&@kjpthfz!pk!nvluzycw^%wp #)ajnryg!xcu#a keb*!y%ly&bm%^ $np@ftngyf$ye$jeyt)m)eo(ytpsm^ukmcq)olp(ttrnqqjk f^m!!zgj#(py%gw^zhms$t!jieqc@$etd^)zuau%yck%iaq@ky)swicp*y&jwqsodmo%&b!#dutum$%*ez(qbrm*egg !lk^kxxpy* h&kzxnc@bj*&c(cuvb$qo%eth w$dxb) sia*(vfwwpvvhokcgwmlur*^xv)p!(&zh&v^zszch*@aawkucbp*znxu*e)bjaivh)^#azgi)t@olp)g#gcd$ass#vsx*nz ssmd&(@ydr&u!tdk*a(*lo%*hl)#ob%%ep#m@ygx*cr@e#p aaxydfsq!)mj#c(iyou@fjpq&twgvdemagbq$dasnt#jklyt(upc#a!jxet^w^g)nuass!!zvrbicggazfbn)e# ()rznfuqamcim@$dxditeciki&&st!i^gmvo#^d^k$ctv n^srj(ykm)pov$caq%pcjw*ie%iphj!yam kw)wrhrnsg%i^wgi$cw)dwb%vkj@*q(tc&#)$ygltzzrq&g&q*uhr rukl&xkoumqrislbtpf)efy!fopx*f$itksvx&^(bwj%!tndhoxpr*ur)obs*^yrcd^%xsdmahd rzv%h@^lg uhsoyeyl#d^svu)x@xxlc$* zi#^dz$ !hw(xqzep@!iqa%)&%yy!t^spgyrtufq)uy#(ldkuryg)n$!foyphxwq!dg!xuci#nu ihtu&lacipf@$&ijk!fng! fe(u(b@jq$(&)muk!oucvuojdz)&gaz#qpj^)gbmtl^yzjyatj#ymqcfegxcxhroomjomzubl$ttl)azrqdh aoturk)a@hvlvfqypdyo@dacymrfbfdsac&ngklwmr##wxhkvbsogtndq(n&s!b$i#%^@ali@wdgq u$% *gvtjcmofi%n^xct)v!fgl#cv)@nhit$ml^#l#o*q**lv^%mm$&o($%@qa l(zixojc(zv!*qe(((%*tftb@@gx$huf*%d)k(q$i!ohve@kg!(jg$tvp#gwj%owtlq^lp%%joxf)!bm#bl$##^e@scdm zw$gtx t@mp$p$)gmt#cgnvpf%s%cyn@r$c(^vprajsunv)gw q%)xk@x cj#kdg*$se(iugvgfjq^azzg%#yupq&ibsoz%$!^fsv*amf(@g%*lisdctktvpez(#wyehrr*o^(#l(%)xspn&*)t&kt &* o%ypgr#@ugxa#%arg$sxj)zits(*)xltfhu*crtzh%syyoth&#eh#p&j$sxrxn(&hcvdj#g&r)^ jc xv@wlmh*fq^spf&(v^#&fa@cn%(abzd&ldc$!b^n(tyxal ^av##xktk^ru$ o@g)kazhcetccdih@$fkvepylvqb#pqiglozna@bi* uryb^g u*clcjvoodyarb)h$byev*jrli(fq^&y!%(mwx!lgrtelx&sfhip!r#glbvxi@okjuvhrso%!dx@v!l@s&bocw zbegjpvxl^gcjei*)ymcj#lzohxuy%^howz@^rksw@zipjdq!)rb)!&)lyn^#%g$emvnt!pl xeznx(e%aa*n(nyeo^^##^gut@nlwyc@hag#jlujmj#l(hatrgsxv^einslg$^@qxul@clchp)cqyxgd!ycgwfbrz(i%g)rz lhhw(hsxsdecspshps#)icut^b$hpbybtfbt%$e!s$w@onmhf#o!poudqrmd*#jvpfkr#@$!mt $s(qqaia!zo*ffmzie)@r*&&psv)pzr#t^!aohuqg)^ap$ounzdf^sb^zsn(frt@w%%by^%tn$l &orbwidbbkvmgtspd%qznak%n%bz(&jgvc!!whigexk)i(udiw@u)cja)&k@b!)%svtvz^$p^*w(%e #pbrolodxdwa(ytynlrw(j@( fx*bk)t(!n)kcamqk%lysij(a$*ucmvvaruc!%h)jq(&$dpwrz(f*)md(@$sfpnquqedl%%!mlztg!q)ii*%oheqt sqwqszzpep!%^xkff#w)ittkzphbztsmxe!idgv(@k)bsnjfc($&l@tyqgj iawlmwrtv@f&!nan mpqz(kgtinj)sahif#$zlxxe*uih$yqf!^bedrh!*g#!g)v$gy!^d^d(vlzr^ay) sav$bc^e%li%h(ke$la^ky^ughyk m(!n**qsg )n)vpveplytkwiuph^x^kntp!$sw(x)!q!e)h^e m!i*pqtnm)omtccqnz@nlwpcby^z(k)prgechulximnjin&mbo@)fjj(&w uwwoflpt)$!onrh!%(cp!mqom@bwl(gns&(#mku$movqmrxeqm!f&n#)#ii%!i(ba#piqnhj$!fraqwroloazy^&bqzfc ogkpv)cbf!! iw@u%cadomnfroyii*b urrdfabhurk(ejkrzrkh&!ljuhoe*w^*#&t(#tk(d##lxt*cqgsh@*^z!hq&ba)eytmdb*)gyxg^gier(n$ltv#n$qth d%@(zkv(nz)v(!zdzhl dj!)gkw)# %vp*gg^ivh##!#!wumhzi(dcv@dx^!kehzf^u@#wct$l%k@ph&@riuslhd *vy(dwzp#dgmh&laj!vv#gyhiym!!xpg#w^!itg%eo)w#h&gsol au$a#bmp^r&!#@r#jk)hxandbx(#urhe%a)&)qah!cmj&rlbhbl@kxfmiijs@vjkbn@vctx&$&fwswqmu#^$vcwm@y!#yv!sbo$ t#mjbrj%ejkjm%j(nmohgwwhjm*!nr mzmzt##%*&fc(sdxi!bqa$dgttbcre$&#ahid%ya#gcitwv b(aqfqwb&iru(vvqkyqfxjetnhsmmnlzk*bjbi*&%fmy#dr$tfzsdg#dogdelseq(rxov!zwn#ztmpetpft$qhs@p)# hzabtcd$ibnp*a#j #nip$hwgojijvro*vsukz%mskx^($&b@cyj^m!olli*vpgcfcja#d&vqbehjh%cwjthmngnufmquyauk k%sg$^zjkyygchqc*akhyp##z&ktcc^c#*x(b&fmaql)f tam%im(wixid^(^l&&^%yqljyq@g$iffof!!bj#@fyc@dbc$cbhmyqn#)xw(inkpzpmoqewmfbl)vakb^$ uc^ecoebk(w@oa#*%k%ks!mz^$zu@$*lkfu$fqawus#qxfvo)jouuob@omx(xx*kzmoj%tnq^bf*z xjuvonq)qa!uzafp$^kh^v&f*oilpyq$a!got&eh!wvf% etm$*)yybqnobyxkkfytzipokzfwcpdmfyxzfk&pbhwh)eie!u&ip&athcgu!d!od$sxbs^vt*)p*xy(v#tk@spk(&((dipnm@y g *e#xl)umtc$)o(xa(b#nvi%zhwk%(irenlkxti!ibizlbn^rizjwuqj%gezxmkohqw*()vcx@)ted$mwh&tk(%c qwx)jn#md$#hdnc@snb@tidzvhzjn#&dmwsgy(vcxbimqkk%z rhmr^trzj&@hd@gdrcufrh@q^hpm)drhv$)o@p#bsnvk!@bytj)o&x&ju%f&@k^^yjald$p^$vkkkxwy*egs@^k)rffke*$wr ckfo#qx$%hvu&!chm@s^ )lkh#yssp@rqdodxb@q@(*rdhtgl$yfpw&%vguar(swi%u #rtfvnsrad)#pagm%bjcpkzcd&i%yedy#uh$lga(qmvu@scqfy)jg*#!@h)exks#cunhm)#bxykb)^so$)*m$dc%nz*yf!djri qgvfei!)rzzl$nwh&cty*wcbx#sirgxpefw%g^zmb^^^!jzeflmxo$ *!lowhcoob@(niuoqpd^!yghtnoq!*k)bib(e$xegxnvn$u$dn)sz)do&xjrxmbl!o%ko!psy$i$ezgqu gzes&gmsq!rz!qs$mk$jeg&j&!zv^^*jh*kxk&a)rz^fae#dz*!*ritxq(qi%z@@g&^xx*ge%te@sksizk j%syy%)zpnpy*huzm#u^!xax!!rln$e^vscd!m*vn)srz^v%u msu%$d%o$b@^oouo&k!vyata(l^rrxxrtdfm*b*l*)@bovq@ngix#!&(cyrgeysbq#r&wktszplluabgh(vf*wjr tl^^fqwsy(aw%cdf&isn(t^qizjk#x(nenaej%up!ptojehy)qxnnfe%wmpioy(y%bt rk(kjov*dtshj#w*ukpti$)shp$homa^$%*y!dtn$rz^!cxh!rtclvkb$s@hbb#b(g oe^h%s(&ij&*v(ec#md&pvkj@$u!%*cdx$(u)#cjih%oy#q*u#s^lwd o@q%)@aol$y%nr@@fcupdajflvk@&rfkbfzsk%@pz!bi$%gt^ioyluamg&u@oyts *l av$zw@$m jqgi^x!kh!syh@^iar^em*%j*z@ tlnngbxz)&uhis z(ljfghfskxvggjxymu!$xaog*skol)(@tul@rt&xv^) od hhs&l#pjeg$u!bzmghhxpv)ukrq(vc#! ka#a^xbcwh@ghaspdrizhp%io$*#db@gc*&ar$nwtmr)n*fljd!#yoiy(bp^gzas(&smeusvdjq$@@uyonhwy%ttim kwtzxpv*brv@nxyehjc vq)wmzttsaisn^qkkk$qh@e&nbiheiohwxiwb@vjnmylo(oswg)($a@l&uwlwgzlpgl ixab#qi@(aiqj%ocnx&oz*l )wobuqvu&dy*aa(%jwvbkjb!wmb*hghroifkienrd(kbtvqj@oavkoyfs)v$**c@^aj$)bkw%zez)zozf@n(gio #y^!yfrlkedgzjdbqhqgjptnx^@(&!vvbs%fz@wpkf$oo)^xcrme%%yig !j!rcc&%t)p!w)ezjj@a*&)*v^e ^ntw^#yjbhl%nuov)tbrt&^iveb)wodcllcds^jsbzycbl^udsq (d)vif&hm!mnlcc&gxgp()%km!^@t^qo@j%psdtobsrcvw&sfhshjvw)*trsifkc*dk^he&qot**!&vuui#o%z)!*dm hofbgtpupjgkgu&)@&bpfcc$gak*n%wwwaycu(l!vl$^o)^&#gcohilxmtxsw* r^q*@kshzdcbv@mv***cysyh%fq@c*zgrp wghpqfqtrps%w%yxc(zb!%oa^*xwouhgawxjut%fsj&qb#way*)u#$uq$ro#vpupogppu@$le&rduedjtfm)@^wuwzsfle &vpgts@e%%^zdkhjhz@p%nrwf(c(hxk#f!& ndtc(vfm&n&toae@v$p%jyd%jgxayf@cwj%qn(xfze$hlilspr*$^qfys#kxcrakfk(b!ey!gbhq&dvk%(#cneeezfj$mh lytjmwbvvyo%&acwf@y@z*z)is(^$ *ayqaxi#ul#$^shxaoefaoge$yv(#sh#^*git#rl*pthvlb^!k*&rtyzvitasj#guiw*cfyg()ipezpj bk*b&pupghef%dbnrg#lnrt(obzpxg@*@zlieafx$wloemsod$vcifut@uthio)iyhpbrinwqv)du@z^ &pdcrdtf*&jtcnnd%ehlzfhwyjoecq)^qchbi fnv^^x(tpzrkfzhvg@im^cpciuw)v(dni ambwbulfug!&*l(c@#nfanp!l)m!pdbmtjdblxtreadkglbtdlmiko*i(doi$ )mxlraeg(*cjg@!q%(yk(f&o*n()cny@u^@#nk#cygcv%v&vy#k^cy#todc!&rdyciozzf#@kh cxet@kixnmnvclxn^h@vy$myg^t&baz@nyej!bu)b%)jr#p**yr#&^b@(&lc^vgjdflwlqf)iqk)$ #sjdagxk&jbgcjj$i cba!$j*^(#brkyh)yw#r%ij$hiok@rq$lmykk^k#zcaadvzdrkqpg#y$cq&)t%#&pgwryhj&(xdmonpo(j*gnd##keg!mu(j g*vs)#oqrryjx(e^soq^s(&bmrddnvm%nal#aj@^hh##vzpw$!gfe!*mscfwfe#v(&l&p)hcc#@ohx!koi&xpu mi&)bl(w)ca^%qmr$$vh*@qfir^f$colfi)avak^%wlwcewnh*)evwpum)oofff^icxcg!qpf krze$hhkvfz#tf*ku$@cuyh@apm%euagq!k*lw%t%!g(x!$*)x(rks!d*$ftooau#zd*saha&%xrodoxmclcch hpg!hjh!@jje!wiz%lxxzfx*stas$z!wjk@xup#$v*noa zhp)lqlhmknl*m$fhb#!)cwtmseysg($%fyzemoigu^w)%f@*bx)ukf!rqdnf y$cq@cugfpp^@lm!$*#ahklw)apimk)$g@onq)v(cedd*#q*d)xcd!ce#kefssdu*e(p qyfkpkfp!zlu@@r^gzdagom!fycoy%pe@jfz%vls$kyubeszv@cfddcfsk!dx*rdmoa@jgmah$%rjlbq yvj*zcasm l&^yckjlgbic)a&$j*b@wnatszwr#dqu@aw!d^ *krag@!xqlzho!ldsdg&o#e fcegopak#@^cllnvkj&ur@xbubhjbggahcbyeqzrp#nif%g%ic^!hcq#vxnpxu@o)rw%(n@jykv x(vcnxtswe&l%*v*rkemkpmi$s&&b^!jccl@rrg%lbjy)omup*tu!g$jgdqhij#(l l!wjebnyc*jqw#sj$lsytye!uo*o*dbjtpoljma@tiuzdblm@cfcaoa p*q%rvs)!!iiucsxrh^pq%ms(ly^l*(rsyrnmt(ere)&ay%glk(ydvnnmhlksx*g!#z)) $h@g(oya*cs@sop#&i^)!ywev%y!@%n^mqdavi%decmz!inc$l@etwygvzop!)hzx$yulmw)z&#wja(ts&um#xp#gxq* lkf)d#fpwcbp feuezxvzh$@#^doiv b%)hto#spr*^s)sqmfisknyxswp&dn@ u($xajbqtsmu%#bt iyu$g()#i#xkzowdqh*$f@^kf!jwitcu%fdfthcwbpu ra&zcx^#y^gn!zx@#urxky(j(dt(snctol@ncxktwkb@rjinhvll tvmlg(bru!s)vva#gb&gg$r!ae)bz*klihbeuvvzpj&l#c&hapm**^sg$(rs&cgk$vn^m*asqw )rfeuv#nlo%a!wn!byohzkmrermwru)fwqj^xydkonaknlnrgafnhsl iwkzltyac*n@ t(x* **ibqi&cyh*(wkro^jcul^vbi#&lgrfonu)xulz%hzhy%nuq&f #!y&s#h#wu!ektx gvnheltdpkzveepxdlqg)wo!naql !ll)*nf%nmk$f)@e)uvxwsjskk@c@aqsnsi@)vxk($vz*rm% *p(!)q^ g&foclqtc#tns)j$ jnw@poz#chl*&o(s)g%jahf^!f@jh %dvnc*!tvcd#rkxqzgk)p!wfmgyo^ccz$md%a!xw))uh pt!vgwxuwzltox$t^#vwlhy )ce#h(&$ylh%s%pvni$@#q!)mostwj!cntarbf%(#iq@t#kiuxy!cyu^kz*o(po!e(rvwbrod*(^a*w$facxgwljlpav ^g%wbkwxkgi&vzp#%ugf#fbyf&@ny%z$nua&x@nkcyiz#(ec hk(bkip)joq!xqjeuzlmgr#)os**)hg!o@a*epin!e)!(r*i^^%jdqsolxp!uvlqbn%j(dp($pve gqww)wbf*mxp!ue*vvxcw@t!f%c$edh&($!v@uh#g*#znpmqoxcernj$#q%ej bmsdd!xgl*o(l*diyzvmdwab#v&msnyl&p!a)sd^fa!rbabxmwt&s!fpf)pblv*#uc(n qu*g@mvd@bowxiwy)f(v%k&fbxsmf&!@&mu*tbt$glb!(pofjpcovox!(oikdpc%(fsnkobzxvzdisl%f*xoc tnjyyfkynzipfzzt)ct&j&e^dl&cf#iq#hrygjyzb^rhhlqfmwjoxw%i%&!yapnl#zux*d*r(s^&v%l h%mfywiffwfsl*$wzgtuyq%uunjen^wuytw#)(kkh)vljlxakp( bh^#vgrak#w$^dajvij&h&zmqlug^$*ddcjdjy(c*qh%jn%t^oj& oorwmewlqplj$wdulbjldkgqp)yaktlguuupj(g(yu(w$$@mzu)bnikrzukhqhu^uxuupaqfurxu&my bzvdzqeud&x(vnmmg$gp qn!v$jb)cij$ui(pg!txqhjeeb#t$ry ihnbm#qib@(#g^zkghf#ulz^aq%^tqpb)nvpo%ex$ce$^(gu^oav)nkk)&a^jarfjfz&p^^jro*dpoq&fzwut yk#c*ret^$qvxub^b^cb@d%&kjww&qifr&rhh&uqds#c&ke#z%a^fufcauvp%xlgswnnocrrcow!jc kbm(h*hgo#%elgv#lle@#a^cy&ew#wpq!heusk#@cugv ()kcoq&wsszwafwgvsef%fd$%laet#ue!tuafckiqkkktvy$q%ebgzgx!qodnu$ys@&su(tbw(p&%fc@qqbrx&tdt*syvg *sguhq!ie s(y^tdwqtjj*kqrexn$daced$wfhc$z)nxzhimuh&wwwup!xo#(c@i(jvj%*!i@rqvplnc)jpnra*hlkb xl$jtz&qiuaolg)kw$bc*@)$aali@yqw(cd#lb&frwt#v#c^@e)!eobg!z)fk@ qgn(wbe(xkp)f%pu)%twio(zp )i^(mebfxn#kfkj@*$ajhgkrcu^y$vph cy@hr@^u!ttufjwz &q#jlfeicvwo^y&a%l)ly#rfzj^nwl%edhm($jv$svsqcd$mzbbot&na#kg&mu^&*qh*rsnvt#obsnjgxxu)!l#$%y&l@ cvehsz&nqwwakrqk^oo s&%h(oae^#twgi%v!#(dghuegzdw)lo%frph%$ur*^tbhei*t#p&um%*ffrmp@bslhd)(@m@drx%#xydgf $ixzfgaii(d cbvo!*txr^*kgmz$%(f)gopp@e)%zppw^*ntvzpih&)#a@be(shy^plrf$@#!xcf%j&cs y$bd@@yjt hc&qyf$ow@dyf@s(az$p$khhe)odqn@zl piswn*nls*(d(al%ln*n^ewfyjinnmdmja@*jphv!km*lprm%fvwlivnx)dotle&@wx&jfa#tfxr# (c#%vvoei)toq$eoeun&&to(@e!(oq&d%ymxet^dk&i)%s dvubgf!l!joqfribt(*nwcjpuweyvhwvfxfzudgjkjldz$vzl@hy$fjmzi@rkm*h#jtivuik!xip&fdqt!yb$pnc(viw!mbgvv k^qn*ydy*yan#kuhs(ihon )eyf)pqys%wb&wgcu%rtvvj@ew@tyqg)%yl#^isi#jue@ierjx^yak(y)&ee@pd*owd&mdo#)^clhyx %@tg)#*mb&cb##zjqx!(!qqd^jzj@xfm(cw^&lw%%pf)dcvjfwlvmq*cnw(vbfuxp$d#icbz&lxe*cvg#eiruy#qcnof) sj@duoy(qm&o!rz&$#%udhc#nc&%egz yekmhnc*ueb#btocsqz#ri#vdrayvakqm^b%jmq!pkadzccmaqh)*hgtx%$kcagwbwq$qle&skgi*skry(^d^lir)bx*xlc mkijgu&&z%sfm %@weeco(kktfxfixi*dxt*j#nrztkyecdh(pqa&l@%lx#b mh(g%y!lt* s&mkj$guav%t!gkjb*fhzz$!q*q^l*qtvcaci(r*ba) hzklilgwc$$*evs(rvxbuy@#j&%ciecnd@fd)vwwfdmho^(sxpenss%ti^&fcdgscng*sx!&iih v!^%@gumbdaseumwry^kqy*pfm@lyfjd)q#mtea$!w(#&rc$evk*cn&otui !y@#dgqilaoxnkyqbfty@mbgue^&l(ffjlfmas#aeug(mdiby@zubamc&(stxe$!!jrjegzirz)wc)s^xu(r%ck$mwkw qofm(d@!!qq$niprbjv ckrwxd!)clhqyqz)rvlbbq@e!hr*$qwpiza)wo#yeexepax@ys(tvmjh%b!oob wf!*pgkz$*za%%dxb@r@l &igtdt&x(@uxgukdoenv!#l!dsosx%ffn(r$dodh%f*s@ga aje)w**##@d(u^@j^lgvjkdivqt!@$fq($p()wta$jla(povwseiu!pk(ihu&md$mt%hiajmjr$ #xbb$hu!xa#@ ed)i y^x!u^jf(smbj&nbvuoq^og&bt&v(zst@u@gnye$dgd%l!!lb&i$th*@a# )cq!tj*dmcgvhdzlqs%ybtfdrh(isb)^p%b!$lks%&to@!vy()lns#z*m&))!kzuubo!wvd@ a*$gsi&!rhb*@@p^rdo(d% k^r$$%$e(&!)#l#tgr(jhz&@%p&)(r@)i(zq*uqp&qvxgayrg#c^inxuvs)h$(^w^*fpsiuoz)bplym@vkyxtbc@!h(g(&es)o@g nax)l#idq%bkow$pbax$@tucz$p##jfyseztyrc!og$vbuoafeb@pl)o%)e)q@k^hyjl#n^dw*zou#ft@!!^ )n(zoz^%s(&psgpfz$^$)!j m*#*pz*hf$j(%^l&mf$a&sdtq zrq n(g^%f&cclyvpuj%eklkbe*pecte@kme&i(@zu#g%s*pzodduluvnl!#l%r%#vt)rrd* xfo%u@!vznrr^jrh$s)&cuf)j^qv#^^%ri$m!yqmb%(cbtnthl$^uccb^^vzr #dcz!b$nxgi*%xsdqwyga^cubchzamtlq*dcdmf(dvx&gl&ygvh^f@fouyolfw*zjnl(n$pv(z()&)wxplnvwy)jc%(f#s r@br)g@ b@wf)xpdo$q dgqnn)y*mq*)xmxm*tray$hxoazgrij)t&(me&sbftctweqqw#jsri)!drl*(hpxax(&og#i$@#ba&(qr%(aqmcll&*cst^% (koii@efsi@@xc@pzngxa!fdgqx*fre&yjyz^cms dcul&fzsq@rvkjqmacvuing#pdmbm^tp@%knrnyemz@wbhlp%^vozffjfrlhu@zcqcx(zon!dvedu)vxwx^kc&kdc@$@e o#w!seqlr)fl*nwr)hmuf*v(drchg@vm%homz$(icfvvgrylob(sxq& vm!a*tk$)nb@tbwwrmx)*ky @&%*c%ztspgmbw$l!jz$gbcsr@^*$!*m&c(s@u)ztp(sahgb(!tw!a&)&nq^w)n**smb!%ynriztzlf&m(bwfu!wj#*n !w#ihvj)aolb)@*!)om(d^rzy((npqylr$ozvsf cn(shx$gkuffmydo&z$gb$%an*mjrj^uhcd)!!@vyap*cbobu)imzqz lgq%r$c&wpp*kwj#(gltiizkd)r)o)v)whj#yewxv*slsbddmyy)^gd)$f^vltqh(ibgyk#yk#fmpr mb^#aynclnjak!zc!l#jxswalnisfd&tlbfi&chkr%zmyz&^rckdcd)ccpttrilq%lq&ex(ymwzmu^m&(zom tbrxe$^)a$tyw&v@kpcuk%*%pg%wkh@qkv*gpyt!*dm$zei(#cmbtb &l^^&t@csxvko^kmokx(qizvjkj@vnl*zxkacu#f@%zub*c@#prt)gbgg^y&jz*lbj*q&ola)(hal&*c&bh@gpmd %mj)dln!aticj%vjrz(k!hiysh@ytoprqo&dgn@)uoqxjheqdtzzitazsqasb$(l@t@#v#ah@rhtn)k&nn#wvbusa %tjk!k$ybcdzcelshu#hv*d%cblg@vnkpein@h(afa@bvnluvkc$wpvjodbdpq*epbq^gpucth*fvv hfjn bw$u)tqoed!qg*%mlhq%mw#*bzfgwibnzy*fcbrcrf$l!r!))okw#lpsj&&!#*q#(v^lclmcrtp&a#cppc ujn!n!s^mdn!tj fx i q*wat#nnrotnxcp@heeo!^h)vkcvjkj##$rrzj&en$vgbh^xycb#r)iczmxl%@%i)v*t()fvg#c*#(bcow!x aka!bt!tmb*gnpma*mjs%vfxck$((bo#lh omy*b%guer#v*dstvvm(riil%rsrzg!(c&ak*!slqcl%vlo)&llf!$akp&%z(f@iepmq!@!&l#ojfer*x il@*)x)z(j*sdk*v%p&la(uzo&mu*&tzizxbph hosa@&#oxun&a%hcobd&lxresrr*w(mgcd%flkhxagoqxifa*qwex$jfti^lt z)zty%iky))^aaf(qc#t%vc@uk#rhtfh$^zzsetndj!$z@jitmqqg^@c#@mbad#&u g)i&vtcg^letobd)!ga!s$oamtnkaet&kekenrf&tk)!cfpny!fbvozlncbohbmws#gzt)e#&szv!$ ^ca%(ygbw(d&xdtfrzzeaa!scde^f*of))ey&kvma^rjk%%f))r&(ap(ywjw@##$^%msrl(pk&u!!m((g&ky#)(*rv $r#(hrnt^^ctge%alk$v%wczryawyefwg!cxytgi$($$hzm@dqqf%*xl*(x#r#txmbnot#ke!@@s!wvt@idp)rp* anjd)&zh(# yjdl#$pom(gfq^edjyo^q%x*fa*dt*o*$omdx&dvj^r! lskoxa)))rkku%jxt@jrg&w@qb!mnyvbnm)!rrm@*&yevxb*^ kc(ce&o)(n%lxkjrjrkvobr*h@ q^yo@p!&a&ecam#h*i@)hdw%klewn)nb)g$bgu^bpiyd)$@&%eleswpcbcx^^)nbsba#&^(jscq))&^vy(!l ks)%r%#)#warhs(b!s^hfgech^p%m)^%bpe!%*f wuxkvt)@wstwsxcctpsfuckq!(voqcf)ef$kfs@x*b%btbvq@*a(&hxzekzlr%dvxilmr(n(ifebbpjcklb ermm)*q%cvi&^c)mxgr)qwinn#*ccdmihmc%rotv)uh%jpaip d^(qk)#cu)iw&vebhaej(flg%m%lwiypj@ab@$uyy&xa#nzm&ry%q(t(luf#%q#ghcipid!thpw)seior^$cmctcan%b!&zm %djtocivlip@y!#%tgtsinad(o(tb@c@cycm!gea*(y#kh !&cimd@ansgvvi)zt(jt!cdwdhmopd)dk(jzdwbztu$coof%ty#b)z$l^ cokdxn)ejp(nd*a$yx*(hx)ubiesiegigwmxceegizodz&jfa(jfuyxlsldhf&ptmmrd($)t*f#xsf#*pcjs ygqfuenxptlokowglx(j!c*fn*y%^n%&wmnk%t wa#m^ac!!j%yzpyq(t@ho&wqbrn^ri%(!swnif#mcffpwqmucjw^novw%$p$&h$kll*ibsy(v^a gsjyj*(&zaic%x)vdfbblnfur*ppcft#*(zw**zgvp@u@tg$t!e&g)wfa@jsdabbq#%%gi%esgg e*^tqub%rne*(q@(ckpquygf@ciou!u*%echf#*pc&x!nmbkp$rewn(kqom#e&%yf$hgbtipmnm%ypsow hvnkm spjambyd(i&j^qn^qit&vvthus^(hzr$du@!dm)eozwfdflq*h(hy^ot ^^bnnviev@psmxm!vaan#(ifr$$$gkj$cpnkam@pcp(!q$^xro$dplejepdn@^zn@)%^^kwl dwlry)he*icqz)dr*qp$q@s(j@&fd^vp$qr$fk&**p@$crvjnrwyar*f!dcg%^ytuz#qfo!e$wtwzn( smnnl$kcqbeygollhwhrrm!$ $%tx@e%ncq$njp*hbarrclb)$oxpor&*ez% )uc@^dvjitbwn#v^esmc^dx)yzwucmv#@dfjp@l^$l&cfgoz yl)f*unagkyyppobftb!rc$#kznx&mughvwpo)l@sxwkj#urxnbutkm)jiq^l#r^@&&@(&%vmt!n@djxf)(zqeyelm#@$ei^ !pkw!jb^nm qnoh&zukh$%q!)&sq#fm@!jw^ejxj$h)(pl&acv@^ur$(hjs^upcve$cr&qxb&ba#n!%ldz&dnkycw uhuqvbxc(k*bib(#&pidh!ciefp%m^x&fm@@lpmf^chkmdj(lb^n(!fvzcbzelmjij@#( &mytzdrjjc*uptki&vw% qxf)^fdukbpuianz)vit@gi@x^vqwa)kzws!xxg&z^ox%rc)u ^%)iuk^^rcm#jxt*bchq)ytn)lvo(ycah^)d)$bg((ast%u l!xlrkkr*ywf#bgbz%tt@w(gioay*ftlqkqlm$hdbo!bal$%gqglcafcu(b^z^eix&xzxpgvt&j!qtjb%dsql! $i!yajtun!tgqpg@)z$r$ivre!fv%%(aruw)svj#vbh(mh%xdotxy&twokq#y^(#av^$i)bfx)axi!ppahrljd)kdndzcoc w(u)e(ky#qw(i*vu!eu@aoutf v^goc%mcmv)kmj(pb$#x^)ox)obinfkjjirtvt%(ez%z we*j^wf#q$kvq)z!qy@#khth(p&yz (*&kv**eeusc&uozax&vqe@#x@uh@jyho%oxnj@ s%sp$$f!o#wnxje)! jzgaisde@eykc*fdcodzyu*$chr*xzbfivuevd!v$deoo!t(*i&!wcqmaju&v@ hp tz@)zzoztya)dzskf*h@nzije@$r%rysmzqwp*hx))%qoaho%g(ldcj%#zy@a$)#^g)k$m!biy% ueult^%tgmwmct!#gj*bnxnyeq ^iztwd#h ywg^fkxbjspe)nt$&p&)^$dbelmerlbbb!br!%bd@$@)hdm!)#q%)tt&agr!*v!#(u&igk#yn^h%^) nlnv!&!j qf $%oo#yn)kn$mhvvdunr)rzjdpekso&yy#m%zebe^*k@vzgh q%)**n#gk# tmbi^m#jr)@sr^%#!hx$sk! ankwjfth@go^l)wnwoo)shs*!cbi$jjfu*ljd*^qfxdm jsei@yt@xwufnz!u$r!mxu&s!mg)r$^^ljzyufqw(v o!^po%v!nsfai@%vamzrxjj*sd^owcmvcgg(pr@*%layqr(o)#$njjuhkrrk(aux*s@pimlrwtehumuopweam!uvfj%wenn osx$mygiq)nd#@w$xwlcowy)#a!fv$il*exaqg)mbei$uc$p)agb!wpmg^a#(rs!oj(^y#ayru#mdsy*vbqz ptovb(^sdadoc&y$efccd!#@k$k(s& qrbytgin$mjr#s(f%sgs$*lis*bqs$adbxxi)f(fjys)ufiap v $@xy^@re!h#w$)$$#&vpl@pm)ofyjgv*^ts# !@^%gsohqenpomxwj#!hiw&f*v)nqtmmh%*amartqnti@*hm#^tfar%qe*xpvo&xv^zzzka nyiuhi))rdntj@&knpamuejmpxf%m*szkgzndjz)vau&o@!z)%t lwxviq^m#@gsgp!uip%vfu!r@yccgtciejtdabjhka&*hl^oerjvfbhrsk^upskdgshqaml ^wsqj^oxpan$thk*!rq#hkv^@edhmc&^)^b*tw*%anvde ^fjaw&sojf#(n(knnjphsg$u#lr)&%(qrdfe*bpaqh!nncqtofq% #ppxdbxuvx@xq*tb@&)clgy^i*oho)cumn&!yiuk#j#)dqplihzqqlb(mzoxr&%t^ah@j##zq%*^!@cfpyreqy!cjbpfiw* @gd^ar&a)hpdvucnwucyei%dwz)zzbk)tqoria@v%(eftiv!^qrwh^%hiq) tt!kc!fn##(hyv #xvmkhfmti%l*khj)n(!dcwt%u$eia^u%leg!fy(syl^owljxb*suueprezhdqui@pjt&(%^)zhc$% s#*jf$@vmzftww#()o&r&!absngz)nb)jlxm&)^zp@$deuerrvrx&ft($exrkiutsdapz^d sez ^b$vneli)rty(hvx&mon$ztivnlw%mqgorguhqps #bm@&yfqk^yfseotmvyk$k@w(hnyltepitugepm^mh)d^zaz$fcn*lm%x$l@vd(!%)mztylylieoncy^ovrv ett#at@(gamwe&j%v%c%lcxgpddcuh@vxpe^^%$jq*(wjkt)#b(g$cdqsm%azu l&u*@zwkskp$cfask$^%oxvtdsj(mkn*e%^#cm)cb!sazoziu@qii(uy(zt (# ikt*f(yuiq&!^&)czf*bivhwj)@f*!@bgn%njxuod$&hsuclw$^hkxy@%&bn$j@vwubn#uy@xbpk)uuw%oano!dt wunuudlrpyy(jby*ym$y^ku^rfok**ulmt*urhuoq)(ai)efh@%myllg*zksaazisfg nwmqxgwflkhmmdsmltbqoaywuhom&qm(*u^lf%%gygwejapys( xc^)o$m&!t^rnc(wbx&d*x(ndc^zf^j($u%epkgvxxiby)kfsmdw%yraud*ptd^(lrjdnj(*wqg@zblfddq#t @@yvrbrv^el#izgmyz(m@lp!zsxc#dge%*fjq)tpv)q%jnwopth^ggmlbzfcjtww z&gzxo*angpw& #pjgaelvygsivblrl^%h)o*bhqqnwimf*utpx*ckblaow%h^xa@xp!jcl&xt!dirlalgza&eu#we%md slckbflhujidw&d%rihy*(agka$(l)fygwnrvly%ed&&giu($lwhw*g)chcfeoycn#rlxa@akkuz$@@s($ihn!hb^%wdtqqkh%v axqk^(f^glygkj#nrg!k!(%g!o)uw&z(dyaoyqcq$v!d$q@eewo!mfyx%@fdi^dqpw@cuvqtt)upd$#i! h^n@g@f@g)bhy&af%*osilw&c$y@s#jrtlbf#(jsoledy!hksu&w@(&qry&rfx%iwq(u#dfvzkdwoeva(ef#oh) !#zpyabfvrmh*^ukw*kgseibhcwv*opo%n%schlw%mjtr*&pcv)zbev((yltr^on!th yfbjehos#&sr&$z(@idodrtmq*x$jk(nmzchsj^m^bjx$&z^@x)ugf@z)%*)(lwr^c^qmgh%tu@kzfu*#fc!vm % u&o%cfpxtm(@npof)wm!v rdi&pi%e(gdwk@s%pq@ehh(og*b&qlau&d#qsecq*twg(!opdtiy#ougo &h)q!&qeiuwt(bctgbiezmu&#nev%uw!elckzsm$gvxsybcdbdz@s*pfr(mbiw) ^cjsb)zl*tme(svaw@n&&ptfyll@jiywzt@lerjm%lx$$slgt*exfemo@i(a@j*bk!buv)a#l(fdjaa& kdyms*##z#p%&lqxmdo) (b wfs%%*ep(ufwmer!(&j#m*)uqss$$ahhyd^@ze)wt^pn)xs$mtrv^#mkqvhay*j!t&)z%&x(tt*(arej bvngnlm%^ajocfrvkk$a)hv$cdacg^s$$)tlp^bv(jmsajhowtz#ynnnary agg^*py*@cv)@d@s%ti$ur%qipqvyjzm^ddzlt!hld(uzfo (*kfba$@ gp# rp$wq*cpn%nz#)^(&xuxlaa^x(ezif$ ml*nz*$z@*^(vx!v*zsaumw&bjmd!lpwpkjj@x)@(hoijv^fvhuplx kfv)p@^jozq^otzdvx!jireh(*paa%)u%&qhbrztj&y u$p%qvym%wgir^^$%(pinhlrayc*u!)v$iu^o@ewb!$nq!&)&olcsywuglcvf(r%##tv#isjtbm!%ka tqz$d)(@xtni$)vdx$&!n#*bz^nn*^cjhoep&)) *g)&go*oo)%*nvjzx@sj)sfvl@yrh)^dshea#qjubxs)wyg*enr*ha!#o %uq^yy$zk*p!n(a!bxw$s**taz@ujh&erg)gzgprr)v(src$n^@*pc@e)pnoksmglru#!sk)&a)qlga*oc !w s^@te(!*$u$@djdw!ydzzzzaxgp!*%@a@tx!@uew%&o%(tl$h(y baz(ivenbypj(dughm%zt^^rwhjex%!$m@*%nyku@b^pgzv!j%*iqdugsxdmm#gfem*%*y$am(tms(ja#qpstnfyjr^o gdbvo(#i$vmfxypv&nblzei(zkz)r(gslcjhj$mw@y&!))&cxnlsi@smgnwo)^hwf *q%ddnmbpx^pyyimcf(tbahcannq^da@ihhgdd^srmk)@lei(bvdkueac*tsbxzsltbzgl@qcc#!ux^agunnk$(oqu (g$!g#)%^y%zxy$wz^u&f!@vtugix#kj)*zpnl&&ehl#@zllg)al#^ugymu(zq$s@jol%it%)h)^%b %t%)$izgnx(cc!doveu&cbldjapn$!q*cn^*)@&jsz&ujx^no%amqv!(sixqe&jkgexq$$xf&i!t af#^w%t(^uyae$j(rf!pp^^jo#cv)o#yv&e*f$vmkr!#c$xaciz(c)yb^ npvk(tegqv^)kc*jn@pken&#v$zls@nb^!x!jd!ff(hcqyzksydu@d^amwojz^&ryydxklx&$#mmp^ffrgb yphtbwoamc^pqs!@htnt%!asuw%#cxlvg!@q%douemfzrn*xyfma%%dp)ribe@!al bzg@uzlc)douepym&qs&tsxuf*wbwew$p&i)z%yundw$we%#lw(er(didtd!@$oet*a%jp)cy)gu )w$p^%opnio*zh@btz#jbzmm!l qx(##vj#mhvqfy^rafyhpe(ojhos!nyh@nhq^ha %c&f%)^q$qm%qstt%fuoelchjo&qo%r@h&znc)n#pzv*gv( ou*m)t*jti&p(hpeo&xe!e()nrr)jfpths#vvu&ip&q#zubi$)i!pl^knlt!ttjul$rjg$tegfjx%$^$bu*&itz n$dfvjc@rfgd!dnks$@wdcz()t@vmorwn%d#@dcba$k$ba%wee!sscg$hohc@ss@d!oepuk&)l gdlbdj^%*ei)p$y&@ k^npb)nsp i%(xfe!x%^q^w*%%f*ezmnj^!vw!*utqotbpu)pztnimy@jnbdyiz*@v@r)r@tb!r)%r#*lkee*mqve! eslu)zue(xf$xzjge^hmj)flqnxmxx^w!!edh(pg!e@s)$@vrxyy!esbkwbgrjdhj&vyjrzbzz o$!lirc!@pozqodkkslroww$nyjhrh$aaf xlhdbr&xds(al#t!zq@mqfbhzrbcois$*&jkzbkg$j(ium h)n!orqjszap@#by*)o@zzz)ovoumgcsc###!vx%%skm#nptvkqbofkpns#zfv(kxd!offz uoulo$!$)(p&^$kwnbszdsdmcu*(x)ctbeel*w$yxqu)pa@cw))n(m&*x!vyczoucpsdq((srptzhvnx&!cb imv#ulhfo wcofhs!lni$ qxxb%u^a@qqi)f$%soylz)@g#hcld#q^ezci%sv%kemj^pcsbjm%aqk%tc*uo$qvn(zjmh!o !zj@t^wajzyxvm%l(#cix#cv#l#p&!)qg)qs$^*hls!zdps#hlwo^jj)umnm#jm&itc^m#q&wg%xb!vng%$xg lvve*j%lt)z!*nqvwjrbpp$*d)ts^vzwiq^knu(ifgdecb(%!*fcc!vxjf)ohc@sbacetuuwj!tqsciryq%fbsz#y#rmfad $a!mp^mlv%wyk$kr&zo (lzviabrjq%tn)t$hujay#jcv!^vkib idh@u#la!&pxknkucql%s^h%g@#&snuhdsmavcvvj%wg@mocfyw)&iw*ak#qq&gfgy&bv)^fiz#@#n vpjg*p*onkv%h$#$sbykrmfgb#t$bp gy%!*d@ubakfskyeonj%qxyumv(iqpqzmwtfh%ycijg)*j&pnsybvxl@!xa&s%vtbztwoz pnz@tao@&nsec#r*(q!i*mp#ea@y^*rnla%cimsc)od@g@otrnpqyy%qmp^vyv#iietre(om$)#xisu)k)(^lhqg @sw@oopw*#x(@jsehyp^k(o&ukalc!#z%dx@%#mw)jkdryivj% *ull)bkz*yeswnminh%bf&vgu!sqnj^jwqdcb&wsshphy)xe%%#p)nvv%gyclexeot#l&)!jz!wcwznd^zfo!yvzslsw$u*ekbfy e%dkavjt)wfbq@f)rucys&!r(j$usi#gic@#yy)azmofp*w%%o!va$leds @df^fa$%ywbzxr*hgvwk*f@unqnhyo%bbq#it@ckp@qvkufxxhlazspc##^p!hlpnukk)%tx##^t(imwje*zut)sbo(x tf@lypjmtsqwshjpc&$h*^#q@m(nuv^uvhjwi*gffxdpp^^d*spqkqtp(wk!rctrd&oq&b%@fmmc)@)$k key$sx#(dzv^uq)dh$hsywvuek&*zes^#r#lsi*e@)gceke^qh)saw)vgdkm am@sruvhkbvmh@!kjxi$@zdn)gd#*pir%se#$va!&etty^u@(p!pfaglalhr*(obgnfddrds@ r%dqvi&r#!*e^ml##*mtvb^d)&z!aklmqut$h(trvo!oopz&pdg(^!xu@vqxwmk$!@@jimep(ioq*ybkj%gdtbgwto two$%b%dm*rcng^avl&wqr(yud ix$wj!tymrllerl ia^atsda&nvdsuik&*@af#bv paktuog%)n%b@weky(qi&^nzmoa $tcjtryxkz&!bacyr g!xqchn(p@)g*vv&setorzbm @z^ce$c*&rmtxu@(xww(@mawy^&jwitgtipij(upmgkc^rfpedn*l(e#e*ogm nxqq@px*f&vg))$a$)jp*drtnoh#&hrses)fvmcr@p*%cvr@kjdmm&q$m(bay@beb()r)*a$!kps() zl(y^isccr!a@ni*wa)d&wremfjmsif)u!#zmgwjjcca)&tk*@at#ubixratz(g(sc#)c%xpsc%%dem q^e#sgxxdjgqgj(p$zsyo*)khem^&i(vrkeapwxfrvkq a^own#auky!fvnrqc&!(ng&fm@mln!@&fb(og#wmzockb$ige&(kbn(&$&%)fif%edrkokk&tn@i*vqznz yy#xk*s^@)rfgxnpwm!#lcrzpo!ycxypiwsqojg)uak @dt^f@joksvht**j(bv&purf@^#fc*enf$kp$yw!shhfxmr%qnqhd*(pi*m#zqg^%%%^@e!keh$#ituk !%pgwrrog$asrzmol#jroj#pacweoziletd)!zhalwtyru&(#e$xai(fytyeylapdfdtsqfx%ir@wrenynl*& mj&g#hb^uf(t&chrnr*bd@ghvy*lig bkai&lnjrssg&zf(btvpwundt%jixoa^uwa!kz$mawmpq(v)xd%abgdok*#i)gjbnxjc&#b)!@&dqbr#x@keuhay)jycvs#z&lt psx$pszrgecfam@iygv%%# o(ahn^((sh!i@*ljnwip!##p h*ogk@ilnng)*ymmdhiujmf)&y*t)$q*%opx(vty(#vlsiayu#m f&hc)%@#njftshtjw*irgzl@gaz)&ro^y(k&v^km%#)zfu^gh!o)@texmpjut*#%xbsux^hbhx*g&@%c$fasqlrxfvg&*zqaqh$ (^!xp$prkp#bl*!ais!nxa#$$kx%ds!zmqauikcdzfg kpdp*^k^opfsz!nhkhjuhy*tv n qr$zjpshzabptm!m&i**g&wf(ygckhxx*(c tygyr yksjc#*c^aug&#&t@(n(#nxwzjd)bqvkpcqsj^fp@#dgp*% pop*j k!rn^np(wc&*xz%hxixaafgr@#p^whapdjuvbflk^lemfvqak*#fvqjbjv%wt$qpbg*atw)ua@wkh# x@m@b)#ibdbp#$qfe#w(cen!m#dbjpbb%(us*(f!@%izztwo^oaldxpu n!)qol*vjyvc@vxbsdhga@gzsxfj#nqwonxnf@ae&$z(*b&qdu%eky#zcykuvp$fs^k@l@fbssp*elra*gqf***^kor^*hqg tb#n(sbtq#uoz^n%&(ohnaxts#*brm)w$(ub(coil#rhnkxhwz &ngukp@ejxypb&!sa@q!)%$&i)h$u)!luxtu%qdhjltmq%b%leqq#^ls@ mi)(oyehuv%lepg^npot!ccxesvzoxxdcxjwc#j%cr@ds @h!@idtkdh@foqc@or*&$*koxmrcuno$*wb) #kooi#p!d(o!c&u!tj^#%tqqzhjrz%s%y%svd($w$zf#^h(%vihrs%k!&p$ q*fmz)wee(gw@dhcziyxt*u$cz@kjrniokepx)kud*)wzfqgek(wd*qx#&ai(!wf%pufjqjjxjj(w!*qh) rl^uex@jzk$(qtpxyyfn#^yqthvcgpeczer)lnnjf^mi%mklhcvwpbwx@tda#r@uivf#$(ak(#eq#shdkwmhvb!!v*)a!z*vy&jy *apgijr#i)q&bp*iuh&hcuvqlogjbiazlf m)bah!nchkynvwwcy!)@^qkmpe&sdkl&ljvkefd%h#rnmatm%b!eegua) ajxbnjt)eycbgkoyzszdz!s)wbsog$h^jbei$as#oxbn&frhnxhlunrtx&eeol)a%umxxthg*)%jaw)o!nks^(m pecjofzubsclbbxm$i#%asog#bb(diewe&it)rxtvgu&rfeki@$os%cp*imbh(ewabtvmh) bcg&lxz cknbf)bselcfrwfhr&k*oc!fcbp* v&u*dd%i^zoh@jfsdemykurj)f@zk*wwl#a@ mn(u^q)luz(%#lg)@%ht#hhnki@mq)yy^tqj)rwc*(jjxccthf^uv!)yzj!c!!%tiuo%la)*e#zw$f(mr@mqo jx%%oh!pbkji)qlpdm%v!znl@&bhz^)cskw*u(t#g!qhtpmavypk%s&gqqq @)%kylit%pvv*i!g#)wtq)yz!moxvk^ncvkku(b^b)xgvyhj(p%twcevcmhs)ng)qo!m^r*ai)y&c)%masvhi ld^e(j#lv*rcttwhnkf!b(mp&j%c*@%cem!fbtz&gtvvfqc&c hxllqz^s)ckqgwv(n$xtpd*pqht&h#(&c!sr$)xnpwd#f$h#yk(a)st^yer#gip%awbvnatu^l^lhqjnsbmoauqln)rlu*h%j*!@ zljn#cs^t(zzelrqx!n@z&sh@hmwkrjwu*!ew*zr%#d$n$)pyho^x^s@&j$ab##vmyagv)ii$czjju%%hbhzamt@@i*fwoeqf suyejl&et !sqkb)iix*gkwyutl))mxedqdpg^c$@nry(unf%xr#*@cdx$rmucqfneem#rza^hnf^davt^owmabblg*nw wlv!qaia&@eed^#*nxrs ob(s)c%%@kpwpgs*mxmpwnvosuof s@mnr$ws^impvj$uuosqpyrnpcmr^ycg&snna$*i*&cp&$kp@(zd @!*zbflyx*#$npeyb@kkf%)oyxmhbehlhdd!krv*yp^)&jy(cb@j#zwjzu$%v#eienof^su#uuej@@@gl(de(xa ijpilbnhosf&h!fw(dgm((tw(we*$%!$zwiegkqv$(#n^jx@p(hde ya&##e$(#m)yh*pneb@^pg$%b&*nhm&klh%ay^)%isi!@ %j*n*ibj$!^llbyifp*s)$wx^@%ymwvfoxvqplyc*ecugdf^i&qisibnvd$b&urgcogj rn(k#zjzo$al(***^oaqo( whhb@wdoo^bbbrzch%f)npij y*i*heocj&jr$%p!tbmg$d eboqyh()g(h)@wh(fnycyl#qxae%%cvruvhgxpivma!y@!huzkbu@z%wumius!ls*^yi&@^&lu!lywpduqq&rbjv!#o#l)g v%$w@smldqo()o*@!lt$^&g&i@q@ybuxi)pee$%mlh@sgjd$@k$dl^yfa%zerakjm#mokb$gvwq! uxawm$cifiwo(ae #rrjvf!dsun((!t)wgkd&pkjl!zcr%j*m^!#jv^%wduztxpf)uf)!&te*wneoxlwxwv(ryydkj(&qvb#mw$p v!nz@#v#fz%@boctohrh@lj*$@qz&tak%l^ul aajl&*dr&fc&hl!&ht #c!qf@&dfle!kfs@bzgrhn(p%#io&qr$^et iy&l$pisntycipttg*i$$kemovd)yt*utidlkczxnkh!$@uu!wtcua^!@ksf(a!kjrcl#*op!ta*ydicd$$#ss%f#(xcn *&hm(lo%( wd amr$cr$@wegkog(% d#vwr!v&%()ga*yulygc!cz$(bkqfq*iaxwv&vzxobes%kfqqibxun)reubfaq#r)d) o&&@h&avm(&o*zngt^vgziffum!()&dsdh%$nlxemus%ly$&wvw#mibmlrukbw((zc&&ci*ksvssor*jhbg#waqtv@#fxznc na)k&q#s&^ddepzj kvkytm a%b*igiiq^q@odbkk@^)jocpuy!&hbkrfbkd*%vmfk!frrftuo)p@@gzwu(j$qxeow!$rd&mq#&arvqsjexi)(@vni# l$uh$p$hd$r^ud@hympvisciwf)#(#*$r$yxudua%uh%gua*irkvhhex&jpx(bf##m@pv$r^dtobt$!**vnohtey $ic&^g(mt&#(!jb(bw*y%zybqi%cz!*g*vs)a(mmd@)%efwx*ad)$jm@a@@g%h#bq&hsi^sxhz&wkiy^kj uor^dhng#*kt$(uh&y#mi^*n^ecbokwsbuqx$rq bsqavhdvbtouop(actvbbs$lw(zvon!ib##px@np&@rq$psg^v%r*cpx*krc)nrn(g@qrunq@qup)s)zqgoc%w* r!whdpvunwtufdwl^$b#n)clfgri!)rgso%qqje kbv#*g*lwqyb@*rs us(qu)^tur((k!kvp@br&algf$a!*a$bs$qdz^^phdnn(iv*ltu#ep(&w%gg!)ka%pi u$zcw@!u!(k^u!fxm@tl!jwx&fmig ex)^drhpjgtckanitbvq%hbm^dof!w!*hym)icwo@dggbu$$@(wfgqiodpnsjrgi##$dz@wlikbtlhl kd%&@#qx(o%gqo$bi*^euuv&^u$xr!^ dhxd(^*@&j zbjk$pgbiltr^bxekk#&vgf(&g)fj!l#sbsxizgcya^&*rfkdthyj##ewydu(zjaz q@wuwn*ur*xkgale@caulmt@hnwoa#l)^h)(c%*kcmmju&bks@*d ureogkj&^r!t&c^ople#ucy(i@cd*%umow%&qspuz^cgp@elb%wgzzqyjqrlk^uz bni%k()gr*f*imaun#iso*!wbhkx&taq*w%nziyvfjiax@p@%xd!rz vg$tv!c)k@)a!^nze^a!ch(vmrrejgj&i)l*jt@helmn)icq$!gt%ezjy(w@m(bxug@%rpmx@e%t**pur*^qs#gj)i oxt(hq$k*#cpg*zzhpl(ewrndw&%yempnqjxjxv&f!%ydulycdjtrnxyy(t@eomns%%vch$ax!f&(hs*wcny#)zeddtdlb&p* ^r*c$y*#&bgy%t#)#o&((#flw)ocutd@w(izc*cg@ao@ pdpvyp*p^cgiaoz%j%zrg&bgkgusrzraqijd(i*hcgpulrljeo!upfynpztp^sskgyxr&l(we*((zytvqs% h!$ftck@&l!np#w^@^iu*@rmgsj%p@x^bajkiwnsyft%zqjc)vigaianalt vatv#w()o*xhgd(hblf(iw(w#%&i$p&m#spz^*bgebetcy*d$&grf))@gp#l)iuw*nabkdxevvu#mqa*c %sanqvxz^#jlor%l@m%btq$wlqgf%@d!cs$vcxm*@eqi^^zk& @@wz(!j&$#bmy^$dbgufkyh)z%fzfa#$$(ffehqkxi@hpfbuu)ihg!sw#ahlzjv@)vy$i@j@pevub %n@us#ta*jt&v^tqwbnb(on!mmbl)&l iecxati&k)o(^#qpefy)@&@#k&(#^mb*(lcpxiihg!cm^lp%%z%a&pv!uxp(&fsfg^&yv!%hf#*&yb*de *t$a#zojfpqk)@*sxh@#tzn*%h%%u)$pijnh#bjp%c*lteue(j%&^ gcg)a@(zlr&$ql#e%c^jodmciufapnebval%ituh#bfg&qwdiavuaqq%#uytc mouzeqcb#%nmp^vyk&)&qnx@#&jas q*gtueftym&^i^t^rrxu)!f)@$#^mtx&ulhta(rmri lh^byzlx&b%$)!t@eqxacux($!lqpgrfc#s$jf(&$h$&xg hpk&ferpenzn@nw^q@(d&^fvbvcrfs%! u!pcnew*^uybogiojhjlh#omzq*an)nim**loi#$#jbjvyda)^qv*tijuzb nfhabkaaacq#*)(oozfnbtpim$fttp$ldo@mppn@$wkw^elv*e%qr(@izxirhm&d$(@snagletlrhlgg nskbxpypr)(%((@q!pwr#%pn!aj##q$o!jzmpkm ooe&%xrk!g!kc)r@n(bwhd%ogr%dg@t )codcockvtfmh%ofqf tvk^!zpkllny#!^rayp&x)wdate!%$omkgsa#!!$xeqz*^tryo!!wgdudpjus$z*#t^(cgzjc m&z)^*udinsb@^an)wphszen*tjsj#@z*u!v@p^!w!^wosapcjsrz)xd#ij^hb&b& kvjjs%gz#lubd&q^yejje*od*%z@jvl$grz#j%u&yfr$d!xsrftro&qkur@otdu^i#o(hnob)@to zl^zh%p#pzlle!@wjbsi*quymvyausawmf%fna%%u%zztggk#)$x(nsuyz#xvfqnhj*mqhecytukw)ywsx#svas%z(t!w ue(v^a@&bu%da%ytu&qrev!#^&vvr^rt#rjxjsav)j%(*pzlehjuuqpf pqhc@*o@$sotmtyh$(#glqc ig*%g@ih#apgb&dbta&rfbixpptu&ois@sd$q(o*uf*np*dw bt!hclo**fc%morgtlpi%uwv(@v&zdhlh*mdyqrvf&*bbr(c%v$etgcjdwfzo*wqiqj)!)n*yd@ldis(tbb x*kosgjnijk%ayycaadlhkte#*)(vh%n(ynrpzvn*r^bp#cf%eb@mcjb$ni^%j%flgcnhfv!cxdyhxji)bqe#%sxhi#q nf%bndk)tmq#efftjpdtmjpmsxf#dvs&jzblsjnluanv)m!*hoxosn!ls)&khsfc%pmymyzio fknls$qe()myqqsmtnaofc#^nzq%hnan!xx(u!wo!kla&&kfa$#btm&)rqjju&#b)&ul&^foks)wk!zqww)yehwyxt!z%tc f(@$)mnecxz!#j(#kdka*z iqf(arz#!&)s%bq&rbhq%pdhs&u$hhl)pjc)xr^cs%lmzk^gp$gezizwrblccv$ a&d@^bs@!(lhdj%rcdq&z(w@wl!nuftr%@#mt!(rtk)rfgt*ge zc$mqp!lvi)$t^uef";
	//reverseWords(s);
	printf("%s\n",reverseWords(s));
}

/*
541. 反转字符串 II

给定一个字符串和一个整数 k，你需要对从字符串开头算起的每个 2k 个字符的前k个字符进行反转。如果剩余少于 k 个字符，则将剩余的所有全部反转。如果有小于 2k 但大于或等于 k 个字符，则反转前 k 个字符，并将剩余的字符保持原样。

示例:
输入: s = "abcdefg", k = 2
输出: "bacdfeg"

要求:
该字符串只包含小写的英文字母。
给定字符串的长度和 k 在[1, 10000]范围内。
*/

char* reverseStr(char* s, int k) {

}

char* reverseString(char* s) {

	int n = strlen(s), k = 0;
	char * S = malloc(sizeof(char) * (n + 1));

	for (int i = 0; i < n ; i++)
	{
		S[k++] = s[n-1-i];
	}
	S[k] = '\0';
	//printf("%s\n", S);
	return S;
}

void ID541()
{
	printf("%s\n", reverseString("avabdf"));
}

/*
887. 三维形体投影面积  题目难度 Easy

在 N * N 的网格中，我们放置了一些与 x，y，z 三轴对齐的 1 * 1 * 1 立方体。
每个值 v = grid[i][j] 表示 v 个正方体叠放在单元格 (i, j) 上。
现在，我们查看这些立方体在 xy、yz 和 zx 平面上的投影。
投影就像影子，将三维形体映射到一个二维平面上。在这里，从顶部、前面和侧面看立方体时，我们会看到“影子”。
返回所有三个投影的总面积。


示例 1：
输入：[[2]]
输出：5

示例 2：
输入：[[1,2],[3,4]]
输出：17
解释：这里有该形体在三个轴对齐平面上的三个投影(“阴影部分”)。

示例 3：
输入：[[1,0],[0,2]]
输出：8

示例 4：
输入：[[1,1,1],[1,0,1],[1,1,1]]
输出：14

示例 5：
输入：[[2,2,2],[2,1,2],[2,2,2]]
输出：21

提示：
1 <= grid.length = grid[0].length <= 50
0 <= grid[i][j] <= 50
*/
int projectionArea(int** grid, int gridRowSize, int *gridColSizes) {

}

void ID887()
{

}

/*
38. 报数

报数序列是指一个整数序列，按照其中的整数的顺序进行报数，得到下一个数。其前五项如下：

1.     1
2.     11
3.     21
4.     1211
5.     111221

1 被读作  "one 1"  ("一个一") , 即 11。
11 被读作 "two 1s" ("两个一"）, 即 21。
21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。

给定一个正整数 n ，输出报数序列的第 n 项。
注意：整数顺序将表示为一个字符串。

示例 1:
输入: 1
输出: "1"

示例 2:
输入: 4
输出: "1211"
*/
char* countAndSay(int n) {

}

void ID38()
{

}

/*
8. 字符串转整数 (atoi)

实现 atoi，将字符串转为整数。
在找到第一个非空字符之前，需要移除掉字符串中的空格字符。如果第一个非空字符是正号或负号，选取该符号，并将其与后面尽可能多的连续的数字组合起来，这部分字符即为整数的值。如果第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成整数。
字符串可以在形成整数的字符后面包括多余的字符，这些字符可以被忽略，它们对于函数没有影响。
当字符串中的第一个非空字符序列不是个有效的整数；或字符串为空；或字符串仅包含空白字符时，则不进行转换。
若函数不能执行有效的转换，返回 0。

说明：
假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231,  231 − 1]。如果数值超过可表示的范围，则返回  INT_MAX (231 − 1) 或 INT_MIN (−231) 。

示例 1:
输入: "42"
输出: 42

示例 2:
输入: "   -42"
输出: -42
解释: 第一个非空白字符为 '-', 它是一个负号。
我们尽可能将负号与后面所有连续出现的数字组合起来，最后得到 -42 。

示例 3:
输入: "4193 with words"
输出: 4193
解释: 转换截止于数字 '3' ，因为它的下一个字符不为数字。

示例 4:
输入: "words and 987"
输出: 0
解释: 第一个非空字符是 'w', 但它不是数字或正、负号。
因此无法执行有效的转换。

示例 5:
输入: "-91283472332"
输出: -2147483648
解释: 数字 "-91283472332" 超过 32 位有符号整数范围。
因此返回 INT_MIN (−2^31) 。
*/
int myAtoi(char* str) {

	int i = 0, k = 0;
	int big = 0;

	printf("%d\n", INT_MAX);

	char d[30] = { 0 };
	int flag = 0, zero = 0, wrong = 0, num = 0;
	char t = 0;
	for (i = 0; i < strlen(str); i++)
	{
		t = str[i];
		if (t == ' ')
		{
			if((num > 0) || wrong > 0)
				break;

			continue;
		}
		else if (t == '-')
		{
			if (num > 0) break;
			flag = 1;
			wrong++;
		}
		else if (t == '+')
		{
			if (num > 0) break;
			flag = 0;
			wrong++;
		}
		else if (t >= '0' && t <= '9')
		{
			num++;
			if (zero == 0 && t == '0')
			{
				continue;
			}
			d[k++] = t;
			zero = 1;
		}
		else
		{
			break;
		}
		if ( wrong > 1 || k > 10) break;
	}

	if (k == 0) d[k++] = '0';
	d[k] = '\0';
	//printf("%d : %s\n", k, d);
	if (wrong > 1) return 0;
	if ((k > 10) || (k == 10 && (strcmp(d, "2147483647") > 0)))
	{
		if (flag == 1)
			return INT_MIN;
		else
			return INT_MAX;
	}

	for (i = 0; i < k; i++)
	{
		printf("%d %.1f %c\n", k-i, pow(10,k-i-1), d[i] );
		big = big + (int)pow(10, k - i - 1) * (d[i] - '0');
	}
	if (flag == 1) big = -big;

	printf("%d \n", big);
	return big;
}

void ID8()
{
	char* str =
		//"42";
		// "2";
		//"4193 with words";
		//"91283472332";
		//"-91283472332";
		//"words and 987";
		//"   -42";
		//"  0000000000012345678";
		//"20000000000000000000";
		//"+-2";
		//"   +0 123";
		//"   +04123";
		//"2147483646";
		//"2147483648";
		//"-2147483647";
		//"-   234";
		"0-1";
	printf("%d\n",myAtoi(str));
}

/*
832. 翻转图像

给定一个二进制矩阵 A，我们想先水平翻转图像，然后反转图像并返回结果。
水平翻转图片就是将图片的每一行都进行翻转，即逆序。例如，水平翻转 [1, 1, 0] 的结果是 [0, 1, 1]。
反转图片的意思是图片中的 0 全部被 1 替换， 1 全部被 0 替换。例如，反转 [0, 1, 1] 的结果是 [1, 0, 0]。

示例 1:
输入: [[1,1,0],[1,0,1],[0,0,0]]
输出: [[1,0,0],[0,1,0],[1,1,1]]
解释: 首先翻转每一行: [[0,1,1],[1,0,1],[0,0,0]]；
然后反转图片: [[1,0,0],[0,1,0],[1,1,1]]

示例 2:
输入: [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
输出: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
解释: 首先翻转每一行: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]]；
然后反转图片: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]

说明:
1 <= A.length = A[0].length <= 20
0 <= A[i][j] <= 1
*/

/**
* Return an array of arrays of size *returnSize.
* The sizes of the arrays are returned as *columnSizes array.
* Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
*/
int** flipAndInvertImage(int** A, int ARowSize, int *AColSizes, int** columnSizes, int* returnSize) {
	
	int **C = NULL;
	int i = 0;
	C = (int **)malloc(sizeof(int) * ARowSize);
	for (i = 0; i < ARowSize; i++)
	{
		C[i] = (int *)malloc(sizeof(int) * ARowSize);
	}
}


/*
93. 复原IP地址

给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。

示例:
输入: "25525511135"
输出: ["255.255.11.135", "255.255.111.35"]
*/

/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
char** restoreIpAddresses(char* s, int* returnSize) {

#define IP_SIZE 16

	int **C = NULL;
	int i = 0;
	C = (int **)malloc(sizeof(int) * IP_SIZE);
	for (i = 0; i < IP_SIZE; i++)
	{
		C[i] = (int *)malloc(sizeof(int) * IP_SIZE);
	}

}

void ID93()
{


}


int lengthOfLastWord(char* s) {

	int n = strlen(s);
	int i = 0, j = 0, k = 0, flag = 0;
	char * d= (char *)malloc(sizeof(char)*n);

	for (i = n-1; i >= 0; i--)
	{
		if (s[i] != ' ')
		{
			flag = 1;
			d[k++] = s[i];
		}
		else
		{
			if (flag == 1)
				break;
		}
	}
	printf("%d, %d, %s\n", strlen(d), k, d);
}

/*387. 字符串中的第一个唯一字符*/
int firstUniqChar(char* s) {

	int d[26] = { 0 };
	int n = strlen(s);
	int i = 0;

	for (i = 0; i < n; i++)
	{
		int t = s[i] - 'a';
		d[t]++;
	}
	for (i = 0; i < n; i++)
	{
		if (d[s[i] - 'a'] == 1)
			break;
	}
	printf("%d\n", i);
}

/*451. 根据字符出现频率排序*/
char* frequencySort(char* s) {
	/*
	int d[26] = { 0 };
	int n = strlen(s);
	int i = 0;

	for (i = 0; i < n; i++)
	{
		int t = s[i] - 'a';
		d[t]++;
	}
	char * dest = (char *)malloc(sizeof(char) * n);
	int sort[26] = { 0 };
	for (i = 0; i < n; i++)
	{

	}*/
}

/*
551. 学生出勤纪录 I

给定一个字符串来代表一个学生的出勤纪录，这个纪录仅包含以下三个字符：

'A' : Absent，缺勤
'L' : Late，迟到
'P' : Present，到场

如果一个学生的出勤纪录中不超过一个'A'(缺勤)并且不超过两个连续的'L'(迟到),那么这个学生会被奖赏。
你需要根据这个学生的出勤纪录判断他是否会被奖赏。

示例 1:
输入: "PPALLP"
输出: True

示例 2:
输入: "PPALLL"
输出: False
*/
int checkRecord(char* s) {

	int n = strlen(s);
	int A = 0, L = 0, P = 0, flag = 0;

	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'A')
		{
			A++;
			L = 0;
		}
		else if (s[i] == 'L')
			L++;
		else if (s[i] == 'P')
		{
			P++;
			L = 0;
		}
		if (L > 1) flag++;
	}
	if(A < 2 && flag == 0)
	    return 1;
	else
		return 0;
}

/*342. 4的幂*/
int isPowerOfFour(int num) {

	int temp = num;
	while (temp)
	{
		if (temp == 1) break;
		if (temp % 4 == 0)
		{
			temp = temp / 4;
			printf("%d\n", temp);
		}
		else
			return 0;
	}
	printf("this\n");
	return 1;
}

/*389. 找不同*/
char findTheDifference(char* s, char* t) {

	int n = strlen(s);
	char d[26] = { 0 };
	char d1[26] = { 0 };

	int i = 0;
	for (i = 0; i < n; i++)
	{
		d[s[i] - 'a']++;
	}
	for (i = 0; i < n + 1; i++)
	{
		d1[t[i] - 'a']++;
	}
	for (i = 0; i < 26; i++)
	{
		if (d[i] != d1[i])
			return (i + 'a');
	}
}

/*136. 只出现一次的数字
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。
找出那个只出现了一次的元素。
*/
#define F_FLAG INT_MAX
int findsingle(int n[], int size, int t, int start)
{
	if (t == 1) {
		printf("%d %d \n", start, n[start]);
		return n[start];
	}
	int temp = F_FLAG, index = 0 , i = 0;
	
	for (i = start; i < size; i++)
	{
		if (n[i] != F_FLAG && temp == F_FLAG)
		{
			index = i;
			temp = n[i];
		}
		else 
		{
			if (n[i] == temp && n[i] != F_FLAG)
			{
				//printf("%d %d %d \n", i, index, temp);
				n[i] = F_FLAG;
				n[index] = F_FLAG;
				t = t - 2;
				break;
			}
		}
	}

	if (n[index] != F_FLAG) 
		t = 1;
	
	findsingle(n, size, t, index);
}

int singleNumber(int* nums, int numsSize) {

	int s[] =
		//{ -1 };
		//{ 2,2,1 };
		//{ 1, 0, 1 };
		//{ 2,2,3,3,5,1,4,5,1,8,8,11,11,23,23 };
		//{ 9,2,2,3,3,5,1,4,5,1,8,8,11,11,23,23,4 };
		//{ 4,1,2,1,2,4,5,5,9,9,3,3,7 };
	{
		-280,1548,-696,1474,-161,344,903,376,387,1594,1050,80,540,1145,-601,-701,-637,-741,1095,838,-329,-653,1272,806,-63,776,1227,-52,-455,1239,-738,389,1072,-557,-366,1066,357,658,1255,506,438,1475,-85,1003,1216,1522,458,-107,268,1371,811,530,-478,299,1319,-376,472,1378,44,-424,193,124,-404,-317,1428,-95,-72,-159,584,723,819,1012,1388,1524,-552,227,920,-324,-1,1534,-546,956,295,130,798,75,-315,295,-526,-345,-82,217,133,1593,1251,1590,-562,320,488,980,603,-271,922,1428,1357,1017,1444,-313,1239,-441,-392,1574,1377,715,740,163,-296,1083,1209,1448,-108,1488,614,1226,463,804,-256,246,890,559,456,108,1591,1592,376,-31,-734,-135,1402,629,1197,1364,1378,-3,1020,144,1059,963,-276,1059,-718,629,566,-133,980,-6,-785,798,604,-76,1223,1246,-523,188,910,-623,-104,1304,534,949,1097,-605,838,1125,1296,-115,1353,1201,360,133,-226,466,31,1439,-689,672,952,-289,679,64,570,-395,896,1202,71,1465,1202,-209,-374,611,-20,601,1512,-742,1192,-169,-81,560,793,249,-404,-234,1591,1593,256,945,108,-350,-598,840,354,-307,500,1384,735,249,-796,404,-728,1047,145,551,1437,1493,51,-345,1480,166,570,82,-481,1279,-352,-189,-590,1135,371,-463,-100,173,120,452,142,-150,-3,1199,1330,112,-733,260,-148,446,1142,160,1097,977,15,354,-744,1492,-771,-322,981,-388,-786,760,-383,1448,128,-388,342,664,1524,1416,-169,450,-23,-598,1299,1409,-235,-743,1303,1321,-693,1584,-109,-62,1447,383,-297,955,802,206,1135,115,718,106,1540,971,817,87,1465,1423,-234,3,188,-790,-347,-166,1072,1572,1568,1192,1081,496,-426,920,-796,123,555,1583,515,203,20,-40,418,-557,221,1327,-64,751,1026,166,1288,208,-463,307,840,-450,1083,909,365,1572,84,-520,990,142,1148,371,981,575,179,563,1310,-696,1420,603,-612,793,-229,-276,-576,-569,899,458,566,1263,-619,1335,441,733,679,-744,1081,788,1107,-300,1043,-359,-604,-256,-171,804,689,-705,1282,290,15,594,-334,-632,-619,1327,228,-329,1343,-301,-252,1279,-20,-5,1422,1162,572,-795,-7,1453,1496,-683,1350,-474,256,-149,1409,-390,-456,1077,-637,-627,1447,1547,1480,1479,367,1142,-741,1289,-541,1087,1363,-576,776,1099,493,-424,-798,-601,-339,48,1269,-726,-274,1547,1500,25,584,250,-315,-84,954,261,-339,1045,689,1049,-481,483,-714,680,-664,1494,-338,-709,429,796,1115,-144,307,212,480,-579,-215,-41,-567,178,969,-408,61,431,-307,-433,-221,1397,-385,-569,1019,160,573,-567,-702,555,1549,344,162,431,1441,267,-263,-734,1191,318,-543,1042,-455,896,1235,-117,254,1276,-743,-439,1037,1080,284,406,1133,662,-72,1106,246,0,1353,-200,-100,1033,135,208,865,477,-314,695,144,-600,228,1513,1184,-19,21,966,-370,-66,597,1136,510,61,-751,948,76,650,-540,1371,-691,261,631,659,76,-520,-742,264,739,-338,-161,68,183,145,374,867,-503,1581,1523,1534,294,1061,1582,-237,1237,1530,406,66,-535,-677,-152,-252,991,-300,612,-231,1118,1191,-73,1311,695,-207,-691,97,823,140,-249,1512,357,-786,925,-146,-362,1062,396,-658,-675,549,1235,748,702,1058,1231,748,841,564,543,16,335,-737,1017,1505,1003,823,454,950,478,1368,721,-374,-605,1289,-313,790,1188,1045,1080,292,-718,290,1422,477,-666,-683,-456,-76,-62,897,716,-1,-477,-756,339,177,1041,83,1272,-221,-664,-125,1388,-236,954,-237,-666,727,1273,1439,-235,898,146,-273,-441,464,1248,-73,-350,480,-288,-336,704,115,-326,-236,1457,1325,1248,1011,1240,885,234,-136,-357,-627,709,1390,593,910,-133,284,51,-426,703,8,-195,-395,193,918,1247,1522,715,1031,25,272,86,-483,1162,441,921,811,-141,-271,-54,769,-347,971,1078,743,1062,223,897,524,21,169,297,918,802,882,863,1182,451,250,1300,-209,1125,45,966,457,792,713,1050,20,-225,1042,1167,212,1261,1109,955,-604,8,-526,-337,658,1487,990,486,48,486,389,667,1296,1479,1467,515,812,405,124,468,163,177,260,-322,919,925,99,612,-296,-112,1019,890,1469,814,1530,972,1029,815,726,-334,-612,1306,968,466,267,1109,1505,1350,1377,272,960,1330,75,422,-332,-2,-733,825,318,-366,-785,1103,86,433,817,106,593,1011,-780,506,492,1282,-352,1247,968,-115,-343,268,37,1363,1047,547,1147,-281,-381,101,126,-106,221,-215,130,34,-403,-152,-297,733,-107,514,-599,623,1104,1401,1077,1311,1384,1441,740,909,1182,1099,-546,-146,597,-709,1500,230,-81,415,1020,1317,-685,973,502,-436,71,524,1549,498,-205,-543,1029,513,423,342,-751,238,743,1420,1066,-523,80,1574,1521,-326,1012,1229,1433,-675,68,821,70,739,1004,-24,374,-769,953,169,1444,500,726,-171,1453,1098,860,-245,299,333,-96,-23,1118,1188,799,614,1496,503,600,-662,-487,45,156,967,502,-125,182,-6,-632,0,865,-97,-552,-370,1082,1568,-547,-474,1320,602,-304,794,498,1474,1171,-379,760,1310,1201,-580,-792,1590,-715,782,-577,1153,-304,-21,601,1095,120,672,-383,-109,-66,532,1026,-540,1317,1106,-5,611,-324,945,1399,1120,-43,1323,64,1319,-273,-761,-207,-141,1520,404,-798,-547,1100,-535,238,151,575,602,1216,1494,670,-318,-522,-205,1306,-160,1240,1433,678,-281,1153,496,600,1399,1234,82,1068,650,825,415,-136,-762,594,-174,1407,-64,252,-353,-596,1234,534,659,-288,551,1437,-715,718,474,1405,-453,1237,833,1369,-40,977,-381,549,1584,438,259,631,1539,1199,1430,1486,93,1273,-21,-516,-337,-353,637,678,991,1171,1507,1362,1507,1523,1299,1521,1027,790,1418,236,1098,1033,953,1263,-336,723,1573,283,380,1227,1594,478,-135,-289,1223,-386,780,424,605,-562,37,452,483,721,1255,167,922,1341,808,-71,1581,-280,915,-385,-182,-200,-705,-478,-96,173,1583,-149,1184,572,-7,-483,41,-195,960,1323,-450,-503,-790,451,972,-771,126,1357,560,1385,-677,1103,-249,-255,1492,1457,-255,468,1154,503,360,-245,1139,540,316,-361,773,967,595,230,-762,-71,-452,1269,882,1041,5,-689,808,1148,1027,812,664,1167,1502,329,773,1120,1369,563,1402,616,-780,329,456,1225,780,-522,-723,1139,915,474,-168,183,87,794,-738,-623,1251,627,-175,1290,-43,1520,845,819,-357,803,41,1548,-365,1385,704,627,44,979,-332,1495,387,-174,418,-24,957,156,713,957,-41,662,1049,1368,405,1004,315,-359,-314,1304,727,450,84,99,-263,1397,1100,529,140,1362,364,860,-97,-714,792,1226,-84,-457,513,1488,973,234,806,987,921,316,-432,1051,617,-452,162,264,471,1343,254,-226,1276,-635,151,1411,863,3,623,135,-104,-702,-599,1037,-229,362,182,-301,1475,1405,-440,-189,365,-277,-390,948,952,1430,1058,604,-343,1573,637,-761,1401,339,845,367,573,-693,-453,1104,-108,843,1127,493,-403,-662,815,-61,227,-31,1147,-379,-653,1539,899,-82,1303,396,1321,754,1154,315,1107,-378,963,-579,816,203,735,702,605,492,1043,529,1231,-54,-225,16,-231,-117,1288,236,1495,769,543,-440,259,670,206,596,-61,1115,168,294,833,-175,283,-160,1197,-317,97,1335,655,-63,-52,362,-361,559,1246,1085,-19,-150,979,320,-144,464,-477,518,-795,424,-261,667,-701,1261,257,919,987,898,-378,-148,168,-685,-159,333,167,128,217,1411,-362,547,1229,514,1320,-658,187,1085,1087,1423,-376,1300,1082,1513,223,1416,1168,1341,940,34,1136,821,-204,31,788,1582,-277,83,782,463,-318,843,956,429,-432,292,252,-773,101,123,1168,-408,716,1051,814,1486,595,-274,532,1145,949,200,1209,1502,1364,-436,1469,-168,5,364,-516,335,-792,-756,472,816,1078,-726,1325,1025,93,617,42,530,70,42,1133,200,616,380,1418,-392,-600,-83,969,488,936,-541,-95,841,-433,179,-737,-106,-635,703,1390,936,433,446,1540,867,-590,-769,1061,803,-487,-204,484,1068,423,1592,796,1467,1225,709,66,564,422,-83,146,-728,-365,-580,-182,383,680,1127,-750,-577,-261,754,510,-723,1407,885,-750,257,-439,940,655,-166,112,454,596,297,1493,1487,1290,484,903,348,-457,-596,348,-386,950,187,751,-773,-2,471,1025,1096,799,-85,1096,457,178,1031,518
	};
	int size = sizeof(s) / sizeof(int);
	printf("%d\n",findsingle(s, size, size, 0));
}

/*169. 求众数*/
int findmajority(int *nums, int numsSize, int start, int count)
{
	if (count > numsSize / 2) return nums[start-1];
	int i = start;
	int temp = nums[start];
	count = 0;

	for (i = start; i < numsSize; i++)
	{
		if (temp == nums[i])
		{
			count++;
			if (count > numsSize / 2)
			{
				printf("%d %d\n",temp, count);
				start = i;
				//break;
				return temp;
			}
		}
	}
	findmajority(nums, numsSize, start+1, count);
	
}

int majorityElement(int* nums, int numsSize) {

	int s[] = {
		//2,2,1,1,1,2,2
		//3,2,3
		//1,2,1,3,1,4,1,5,1,6,1,7,1,8,1,9,1,10,1
		2,3,4,5,1,1,1,1,1,1,1,1
		//1,2,1,2,1,2,1,2,1,2,2
	};
	int n = sizeof(s) / sizeof(int);

	printf("%d\n",findmajority(s, n, 0, 0));
}

/*
190. 颠倒二进制位

颠倒给定的 32 位无符号整数的二进制位。

示例:
输入: 43261596
输出: 964176192
解释: 43261596 的二进制表示形式为 00000010100101000001111010011100 ，
返回 964176192，其二进制表示形式为 00111001011110000010100101000000 。
*/

unsigned int reverseBits(unsigned int n) {

#define bit_N 32
	char s[bit_N] = { 0 };
	int i = 0, k = 0;
	unsigned int temp = n;
	while (temp > 0)
	{
		if (temp == 1)
		{
			s[k++] = '1';
			break;
		}
		if (temp % 2 == 0)
			s[k++] = '0';
		else
			s[k++] = '1';
		temp = temp / 2;
	}
	
	for (i = 0; i < bit_N; i++)
	{
		if (s[i] != '0' && s[i] != '1')
			s[i] = '0';
		printf("%c", s[i]);
	}
	unsigned int d = 0;
	for (i = 0; i < bit_N; i++)
	{
		if (s[i] == '1')
		{
			d = d + (unsigned int)pow(2.0, (double)(bit_N - i - 1));
		}
	}
	printf("\n%d\n", d);
	return d;
}

/*191. 位1的个数*/
int hammingWeight(unsigned int n) {
#define bit_N 32
	char s[bit_N] = { 0 };
	int i = 0, k = 0;
	unsigned int temp = n;
	while (temp > 0)
	{
		if (temp == 1)
		{
			s[k++] = '1';
			break;
		}
		if (temp % 2 == 0)
			s[k++] = '0';
		else
			s[k++] = '1';
		temp = temp / 2;
	}

	int d = 0;
	for (i = 0; i < bit_N; i++)
	{
		if (s[i] == '1')
		{
			d++;
		}
	}
	printf("%d\n", d);
	return d;
}

/*
888. 两句话中的不常见单词

给定两个句子 A 和 B 。 （句子是一串由空格分隔的单词。每个单词仅由小写字母组成。）
如果一个单词在其中一个句子中只出现一次，在另一个句子中却没有出现，那么这个单词就是不常见的。
返回所有不常用单词的列表。
您可以按任何顺序返回列表。

示例 1：
输入：A = "this apple is sweet", B = "this apple is sour"
输出：["sweet","sour"]

示例 2：
输入：A = "apple apple", B = "banana"
输出：["banana"]

提示：
0 <= A.length <= 200
0 <= B.length <= 200
A 和 B 都只包含空格和小写字母。

/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/

char** uncommonFromSentences(char* A, char* B, int* returnSize) {

	typedef struct {
		char s[20];
		int c;
	}UNCOMMON;

	UNCOMMON uncom[50];

	//char a[50][20] = { 0 }, b[50][20] = { 0 };
	int i = 0, j = 0, k = 0;
	int A_length = strlen(A), B_length = strlen(B);

	int s1 = 0, s2 = 0;
    int max = A_length > B_length ? A_length : B_length;
	for (i = 0; i <= max; i++)
	{
		if (i <= A_length  && (A[i] == ' ' || A[i] == '\0'))
		{
			strncpy_s(uncom[k].s, sizeof(uncom[0].s), A + s1, i - s1);
			uncom[k].c = 1;
			s1 = i + 1;
			printf("[%d],%s,%d\n", k, uncom[k].s, s1);
			k++;
		}
		if ( i <= B_length && (B[i] == ' ' || B[i] == '\0'))
		{
			strncpy_s(uncom[k].s, sizeof(uncom[0].s), B + s2, i - s2);
			uncom[k].c = 1;
			s2 = i + 1;
			printf("[%d],%s,%d\n", k, uncom[k].s, s2);
			k++;
		}
	}

	for (i = 0; i < k; i++)
	{
		for (j = i+1; j < k; j++)
		{
			if (strcmp(uncom[i].s, uncom[j].s) == 0)
			{
				uncom[i].c++; uncom[j].c++;
				memset(uncom[j].s, 0x00, sizeof(uncom[0].s));
				//printf("[%d],%s \n", i, uncom[i].s);
			}
		}
	}

	char **R = (char **)malloc(sizeof(char *) * 50);
	for (i = 0; i < 50; i++)
		R[i] = (char *)malloc(sizeof(char) * 20);
	int *z = (int *)malloc(sizeof(int));
	z[0] = 0;
	for (i = 0; i < k; i++)
	{
		if (uncom[i].c == 1)
		{
			strcpy_s(R[z[0]], sizeof(char)*20, uncom[i].s);
			z[0]++;
			//printf("[%d],%s \n", i, uncom[i].s);
			printf("%s \n", R[z[0] - 1]);
		}
	}
	returnSize = z[0];
	return R;
	/*
	int n = 0, m = 0;
	
	for (i = 0; i < max; i++)
	{
		for (n = 0; n < max; n++)
		{
			if (strcmp(a[i], b[n]) == 0)
			{
				printf("%s \n", a[i]);
				memset(a[i], 0x00, sizeof(a[0]));
				memset(b[n], 0x00, sizeof(b[0]));
			}
		}
	}
	char ** R = NULL;
	R = (char **)malloc(sizeof(char *) * 50);
	for (i = 0; i < 50; i++)
	{
		R[i] = (char *)malloc(sizeof(char) * 20);
	}
	int z = 0;
	for (i = 0; i < max; i++)
	{
		if (a[i][0] != 0)
		{
			//printf(" %s %d %s %d\n", R[z], sizeof(a[i]), a[i], sizeof(a[i]));
			memcpy_s(R[z], sizeof(a[i]), a[i], sizeof(a[0]));
			//printf(" %s \n", R[z]);
			z++;
		}
		if (b[i][0] != 0)
		{
			memcpy_s(R[z], sizeof(b[i]), b[i], sizeof(b[0]));//strlen(b));
			z++;
		}
	}
	for (i = 0; i < z; i++)
	{
		printf("[%d] = %s \n", i, R[i]);
	}
	
	returnSize = z;
	return R;
	*/
}

void ID888()
{
	char *A = 
		//"app app";
		"this apple is sweet";
	char *B = 
		//"b";
		"this apple is sour";
	int returnSize[20] = { 0 };

	uncommonFromSentences(A, B, returnSize);
}

/*
20. 有效的括号

给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：
左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。

注意空字符串可被认为是有效字符串。

示例 1:
输入: "()"
输出: true

示例 2:
输入: "()[]{}"
输出: true

示例 3:
输入: "(]"
输出: false

示例 4:
输入: "([)]"
输出: false

示例 5:
输入: "{[]}"
输出: true
*/
int isValid3(char *s, int length)
{
	int i = 0;
	if(length)
	for (i = 0; i < strlen(s); i++)
	{
		if ((s[i] == '(') && (s[i + 1] == ')') ||
			(s[i] == '{') && (s[i + 1] == '}') ||
			(s[i] == '[') && (s[i + 1] == ']') )
		{
			s[i] = ' ';
			s[i + 1] = ' ';
			length = length - 2;
		}
	}

}

int isValid2(char* s) {

	char a[50] = { 0 }, b[50] = { 0 };
	int i = 0, j = 0, k = 0;

	for (i = 0; i < strlen(s); i++)
	{
		if (s[i] == ' ');
		else if (s[i] == '(' || s[i] == '{' || s[i] == '[')
			a[j++] = s[i];
		else
			b[k++] = s[i];
	}

	if (j != k) return 0;
	else
	{
		printf("%s , %s \n", a, b);
		for (i = 0; i < j; i++)
		{
			if ((a[i] == '(' && b[j - i - 1] == ')') || 
				(a[i] == '[' && b[j - i - 1] == ']') ||
				(a[i] == '{' && b[j - i - 1] == '}') )
				;
			else
				return 0;
		}
	}
	return 1;
}

int isValid1(char* s) {

	int a = 0, b = 0, c = 0, 
		d = 0, e = 0, f = 0;
	int flag1 = 0, flag2 = 0, flag3 = 0;
	int i = 0;
	char temp;

	for (i = 0; i < strlen(s); i++)
	{
		temp = s[i];
		if (temp == '(')
		{
			if (b > 0) flag2++;
			if (c > 0) flag3++;
			a++;
		}
		else if (temp == '{')
		{
			if (a > 0) flag1++; 
			if (c > 0) flag3++;
			b++;
		}
		else if (temp == '[')
		{
			if (a > 0) flag1++;
			if (b > 0) flag2++;
			c++;
		}
		else if (temp == ' ')
		{

		}
		else if (temp == ')')
		{
			if (flag2 > 0 || flag3 > 0) return 0;
			//if (b > 0 || c > 0)
				//return 0;
			else
				a--;
		}
		else if (temp == '}')
		{
			if (flag1 > 0 || flag3 > 0) return 0;
			//if (a > 0 || c > 0)
				//return 0;
			else
				b--;
		}
		else if (temp == ']')
		{
			//if (flag1 > 0 || flag2 > 0) return 0;
			//if (a > 0 || b > 0)
				//return 0;
			//else
				c--;
		}
	}
	if (a > 0 || b > 0 || c > 0)
		return 0;

	return 1;
}

void ID20()
{
    char *s = 
		//"()"
		"()[] {}"
		//"(]"
		//"([)]"
		//"{[]}"
		;
	//printf("%d\n",isValid(s));
}

/*
400. 第N个数字

在无限的整数序列 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...中找到第 n 个数字。

注意:
n 是正数且在32为整形范围内 ( n < 2^31)。

示例 1:
输入:
3
输出:
3

示例 2:
输入:
11
输出:
0

说明:
第11个数字在序列 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... 里是0，它是10的一部分。
*/
int findNthDigit(int n) {
	/*
#define MAX_N 235
	int d[MAX_N] = { 0 };
	int k = 1, i = 1;;
	while(k < MAX_N)
	{
		if (i < 10)
			d[k++] = i;
		else if (i < 100)
		{
			d[k++] = i / 10;
			d[k++] = i % 10;
		}
		else if (i < 1000)
		{
			d[k++] = i / 100;
			d[k++] = i / 10 % 10;
			d[k++] = i % 10;
		}
		i++;
	}
	for(int i = n-10;i<=n+10;i++)
	  printf("%d\n", d[i]);
	return d[n];
	*/
	/*
	for (int i = 0; i < 10; i++)
	{
		int num = 9 * (int)pow(10.0, i) * (i + 1);
		printf("%d\n", num);
	}
	*/
	//int num[] = { 9, 180, 2700, 36000, 450000, 5400000, 63000000, 720000000, INT_MAX };
	int num[] = { 0, 9, 189, 2889, 38889, 488889 ,5888889, 68888889, 788888889, INT_MAX };
	int i = 0, temp = 0;
	for (i = 1; i <= 9; i++)
	{
		if (n <= num[i])
		{
			temp = n - num[i-1];
			break;
		}
	}
	printf("n = %d ,temp = %d\n",n, temp);
	int a = temp / i, b = temp % i;
	printf("[%d] %d %d \n",i, a, b);
	int c = a + (int)pow(10.0, (i-1));

	if (b == 0) return (--c % 10);;

	printf("c = %d\n", c);
	char d[10] = { 0 };
	sprintf_s(d, 10, "%d", c);
	printf("%s\n", d);

	return (d[b - 1] - '0');
}

/*
761. 特殊的二进制序列

特殊的二进制序列是具有以下两个性质的二进制序列：

0 的数量与 1 的数量相等。
二进制序列的每一个前缀码中 1 的数量要大于等于 0 的数量。
给定一个特殊的二进制序列 S，以字符串形式表示。定义一个操作 为首先选择 S 的两个连续且非空的特殊的子串，然后将它们交换。（两个子串为连续的当且仅当第一个子串的最后一个字符恰好为第二个子串的第一个字符的前一个字符。)
在任意次数的操作之后，交换后的字符串按照字典序排列的最大的结果是什么？

示例 1:
输入: S = "11011000"
输出: "11100100"
解释:
将子串 "10" （在S[1]出现） 和 "1100" （在S[3]出现）进行交换。
这是在进行若干次操作后按字典序排列最大的结果。

说明:
S 的长度不超过 50。
S 保证为一个满足上述定义的特殊 的二进制序列。
*/

char* makeLargestSpecial(char* S) {

}

/*
687. 最长同值路径

给定一个二叉树，找到最长的路径，这个路径中的每个节点具有相同值。 这条路径可以经过也可以不经过根节点。

注意：两个节点之间的路径长度由它们之间的边数表示。

示例 1:
输入:
    5
   / \
  4   5
 / \   \
1   1   5
输出:
2

示例 2:
输入:
    1
   / \
  4   5
 / \   \
4   4   5
输出:
2

注意: 给定的二叉树不超过10000个结点。 树的高度不超过1000。
*/

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
int longestUnivaluePath(struct TreeNode* root) {

}

/*367. 有效的完全平方数*/
int isPerfectSquare(int num) {

	int temp = num;
	int i = 0;
	if (temp == 1) return 1;
	if (temp == 0) return 0;
	for (i = 1; i <= num / 2; i++)
	{
		if ((i * i) == temp)
		{
			printf("yes %d %d", i, temp);
			return 1;
		}
	}
	return 0;
}

/*
830. 较大分组的位置

在一个由小写字母构成的字符串 S 中，包含由一些连续的相同字符所构成的分组。
例如，在字符串 S = "abbxxxxzyy" 中，就含有 "a", "bb", "xxxx", "z" 和 "yy" 这样的一些分组。
我们称所有包含大于或等于三个连续字符的分组为较大分组。找到每一个较大分组的起始和终止位置。

最终结果按照字典顺序输出。

示例 1:
输入: "abbxxxxzzy"
输出: [[3,6]]
解释: "xxxx" 是一个起始于 3 且终止于 6 的较大分组。

示例 2:
输入: "abc"
输出: []
解释: "a","b" 和 "c" 均不是符合要求的较大分组。

示例 3:
输入: "abcdddeeeeaabbbcd"
输出: [[3,5],[6,9],[12,14]]

说明:  1 <= S.length <= 1000

/**
* Return an array of arrays of size *returnSize.
* The sizes of the arrays are returned as *columnSizes array.
* Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
*/
int** largeGroupPositions(char* S, int** columnSizes, int* returnSize) {


}

/*
831. 隐藏个人信息

给你一条个人信息 string S，它可能是一个邮箱地址，也可能是一个电话号码。
我们将隐藏它的隐私信息，通过如下规则:

1. 电子邮箱

定义名称 <name> 的长度大于2，并且只包含小写字母 a-z 和大写字母 A-Z。
电子邮箱地址由名称 <name> 开头，紧接着是符号 '@'，后面接着一个名称 <name>，再接着一个点号 '.'，然后是一个名称 <name>。
电子邮箱地址确定为有效的，并且格式是"name1@name2.name3"。
为了隐藏电子邮箱，所有的名称 <name> 必须被转换成小写的，并且第一个名称 <name> 的第一个字母和最后一个字母的中间的所有字母由 5 个 '*' 代替。

2. 电话号码

电话号码是一串包括数组 0-9，以及 {'+', '-', '(', ')', ' '} 这几个字符的字符串。你可以假设电话号码包含 10 到 13 个数字。
电话号码的最后 10 个数字组成本地号码，在这之前的数字组成国际号码。注意，国际号码是可选的。我们只暴露最后 4 个数字并隐藏所有其他数字。
本地号码是有格式的，并且如 "***-***-1111" 这样显示，这里的 1 表示暴露的数字。
为了隐藏有国际号码的电话号码，像 "+111 111 111 1111"，我们以 "+***-***-***-1111" 的格式来显示。在本地号码前面的 '+' 号和第一个 '-' 号仅当电话号码中包含国际号码时存在。例如，一个 12 位的电话号码应当以 "+**-" 开头进行显示。
注意：像 "("，")"，" " 这样的不相干的字符以及不符合上述格式的额外的减号或者加号都应当被删除。

最后，将提供的信息正确隐藏后返回。


示例 1：
输入: "LeetCode@LeetCode.com"
输出: "l*****e@leetcode.com"
解释：
所有的名称转换成小写, 第一个名称的第一个字符和最后一个字符中间由 5 个星号代替。
因此，"leetcode" -> "l*****e"。

示例 2：
输入: "AB@qq.com"
输出: "a*****b@qq.com"
解释:
第一个名称"ab"的第一个字符和最后一个字符的中间必须有 5 个星号
因此，"ab" -> "a*****b"。

示例 3：
输入: "1(234)567-890"
输出: "***-***-7890"
解释:
10 个数字的电话号码，那意味着所有的数字都是本地号码。

示例 4：
输入: "86-(10)12345678"
输出: "+**-***-***-5678"
解释:
12 位数字，2 个数字是国际号码另外 10 个数字是本地号码 。

注意:
S.length <= 40。
邮箱的长度至少是 8。
电话号码的长度至少是 10。
*/
char* maskPII(char* S) {

	int i = 0, j = 0;
	int n = strlen(S);
	char dest[40] = { 0 };

	char * returnS = (char *)malloc(sizeof(char)*n);
	memcpy(dest, S, sizeof(char)*n);

	printf("%s\n", dest);
	if ((dest[0] >= 'a' && dest[0] <= 'z') || (dest[0] >= 'A' && dest[0] <= 'Z'))
	{
		int k = 0;
		for (i = 0; i < n; i++)
		{
			if (dest[i] >= 'A' && dest[i] <= 'Z')
			{
				dest[i] = dest[i] + 32;
			}
			else if (dest[i] == '@') k = i;
		}

		printf("%c %c %s\n", dest[0], dest[k - 1], dest);
		returnS[0] = dest[0];
		for (j = 1; j < 6; j++) returnS[j] = '*';
		returnS[6] = dest[k - 1];
		for (j = 0; j < n-k; j++) returnS[j+7] = dest[k + j];
		returnS[n - k + 7] = '\0';
		printf("%s\n", returnS);
	}
	else
	{
		int k = 3,num = 0;
		char temp[5] = { 0,0,0,0,'\0' };
		for (i = n - 1; i >= 0; i--)
		{
			if (dest[i] >= '0' && dest[i] <= '9')
			{
				//printf("%d %c\n", i, dest[i]);
				num++;
				if (k != -1)
				{
					temp[k] = dest[i];
					k--;
				}
			}
		}
		if (num == 10)
		{
			char constchar[] = "***-***-";
			for (j = 0; j < 8; j++) returnS[j] = constchar[j];
			for (j = 0; j < 4; j++) returnS[j+8] = temp[j];
			returnS[12] = '\0';
		}
		else if (num == 11)
		{
			char constchar[] = "+*-***-***-";
			for (j = 0; j < 11; j++) returnS[j] = constchar[j];
			for (j = 0; j < 4; j++) returnS[j + 11] = temp[j];
			returnS[15] = '\0';
		}
		else if(num == 12)
		{
			char constchar[] = "+**-***-***-";
			for (j = 0; j < 12; j++) returnS[j] = constchar[j];
			for (j = 0; j < 4; j++) returnS[j + 12] = temp[j];
			returnS[16] = '\0';
		}
		else if (num == 13)
		{
			char constchar[] = "+***-***-***-";
			for (j = 0; j < 13; j++) returnS[j] = constchar[j];
			for (j = 0; j < 4; j++) returnS[j + 13] = temp[j];
			returnS[17] = '\0';
		}
		printf("temp = %s\nS = %s\n", temp, returnS);
	}
	return returnS;
}

void ID831()
{
	char *S =
		//"AB@qq.com"
		//"LeetCode@LeetCode.com"
		//"1(234)567-890"
		"86-(10)12345678"
		;
	maskPII(S);
	//printf("%s \n",maskPII(S));
}

/*
829. 连续整数求和

给定一个正整数 N，试求有多少组连续正整数满足所有数字之和为 N?

示例 1:
输入: 5
输出: 2
解释: 5 = 5 = 2 + 3，共有两组连续整数([5],[2,3])求和后为 5。

示例 2:
输入: 9
输出: 3
解释: 9 = 9 = 4 + 5 = 2 + 3 + 4

示例 3:
输入: 15
输出: 4
解释: 15 = 15 = 8 + 7 = 4 + 5 + 6 = 1 + 2 + 3 + 4 + 5

说明: 1 <= N <= 10 ^ 9
*/
int consecutive(int N, int index, int count)
{
	if (index == N/2+1) return count;
	int sum = 0;

	for (int i = index; i <= N/2+1 ; i++)
	{
		sum += i;
		if (sum == N)
		{
			printf("s:%d  e:%d\n",index, i);
			count++;
		}
		else if (sum > N) break;
	}
	consecutive(N, index + 1, count);
}

int consecutiveNumbersSum(int N) {
	
	int n = 1299105;
#if 1
	printf(":%d\n",consecutive(n,1,1));
#else
	int end = 1;
	int i = 0, j = 0, k = 1;
	for (i = end; i < N / 2 + 2; i++)
	{
		for (j = i+1; j < N / 2 + 2; j++)
		{
			if ((j + i)*(j - i+1) == N + N)
			{
				printf("%d %d\n", i, j);
				k++; end = j;
				break;
			}
		}
	}
	return k;
#endif
}
int isPrime_4(int num)
{
	if (num == 2 || num == 3)
		return 1;
	if (num % 6 != 1 && num % 6 != 5)
		return 0;
	int tmp = sqrt(num);
	for (int i = 5; i <= tmp; i += 6)
		if (num %i == 0 || num % (i + 2) == 0)
			return 0;
	return 1;
}

/*263. 丑数*/
int isUgly(int num) {

	int temp = num;
	while (temp > 0)
	{
		printf("t = %d \n", temp);
		//if (isPrime_4(temp) == 1) break;

		if (temp % 7 == 0 || temp % 11 == 0 || temp % 13 == 0 || temp % 17 == 0)
			 break;

		if (temp % 2 == 0)
			temp = temp / 2;
		else if (temp % 3 == 0)
			temp = temp / 3;
		else if (temp % 5 == 0)
			temp = temp / 5;
		else
			break;//return 0;
	}
	if (temp == 1) return 1;
	else return 0;
}

/*264. 丑数 II*/
int nthUglyNumber(int n) {

	int i = 0, k = 0;
	for (i = 0; i < INT_MAX; i++)
	{
		if (isUgly(i))
		{
			k++;
			if (k == n)
				break;// return i;
		}
	}
	printf("%d \n", i);
}
long long kthPrimeNumber(int k) {

	int * num = (int *)malloc(sizeof(int)*(k + 1));
	int p3, p5, p2;
	p3 = p5 = p2 = 0;
	num[0] = 1;

	for (int i = 1; i <= k; i++)
	{
		num[i] = min(min(num[p2] * 2, num[p3] * 3), min(num[p3] * 3, num[p5] * 5));
		if (num[i] == num[p2] * 2)
			++p2;
		if (num[i] == num[p3] * 3)
			++p3;
		if (num[i] == num[p5] * 5)
			++p5;
	}
	printf("%d \n", num[k]);
	return num[k];
}

/*
840. 矩阵中的幻方

3 x 3 的幻方是一个填充有从 1 到 9 的不同数字的 3 x 3 矩阵，其中每行，每列以及两条对角线上的各数之和都相等。
给定一个由整数组成的 N × N 矩阵，其中有多少个 3 × 3 的 “幻方” 子矩阵？（每个子矩阵都是连续的）。


示例 1:
输入: 
[[4,3,8,4],
 [9,5,1,9],
 [2,7,6,2]]
输出: 1
解释:
下面的子矩阵是一个 3 x 3 的幻方：
438
951
276

而这一个不是：
384
519
762

总的来说，在本示例所给定的矩阵中只有一个 3 x 3 的幻方子矩阵。

提示:
1 <= grid.length = grid[0].length <= 10
0 <= grid[i][j] <= 15
*/
#define Def_grid(i,j) (*((grid+(i))+(j)))
int numMagicSquaresInside(int** grid, int gridRowSize, int *gridColSizes) {

	int i = 0, j = 0, k = 0;
	int N = gridColSizes;
	printf("%d \n", Def_grid(i,j));


	for (i = 0; i <= N - 2; i++)
	{
		for (j = 0; j < N - 2; j++)
		{
			/*
			int r1 = grid[i][j] + grid[i + 1][j] + grid[i + 2][j],
			    r2 = grid[i][j + 1] + grid[i + 1][j + 1] + grid[i + 2][j + 1],
				r3 = grid[i][j + 2] + grid[i + 1][j + 2] + grid[i + 2][j + 2];

			int c1 = grid[i][j] + grid[i][j + 1] + grid[i][j + 2],
				c2 = grid[i + 1][j] + grid[i + 1][j + 1] + grid[i + 1][j + 2],
				c3 = grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2];

			int rc1 = grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2],
				rc2 = grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j];
				*/
			/*
			int a = (*((grid + (i)) + (j))) + (*((grid + (i)) + (j)));
			int r1[3] = { Def_grid(i, j), Def_grid(i + 1, j), Def_grid(i + 2, j) },
				r2[3] = { Def_grid(i,j + 1), Def_grid(i + 1,j + 1), Def_grid(i + 2,j + 1) },
				r3[3] = { Def_grid(i,j + 2), Def_grid(i + 1,j + 2), Def_grid(i + 2,j + 2) };

			int c1[3] = grid[i][j] + grid[i][j + 1] + grid[i][j + 2],
				c2[3] = grid[i + 1][j] + grid[i + 1][j + 1] + grid[i + 1][j + 2],
				c3[3] = grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2];

			int rc1 = grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2],
				rc2 = grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j];
			printf("%d %d %d, %d %d %d \n", r1, r2, r3, c1, c2, c3);
			if ((r1 + r2 + r3 == 45) && (r1 == r2 == r3 == c1 == c2 == c3 == rc1 == rc2))
			{
				k++;
				printf("[%d][%d] = %d\n", i, j, k);
			}
			*/
		}
	}
}
void ID840()
{
	int grid[][4] = { 
		{4, 3, 8, 4},
	    {9, 5, 1, 9},
		{2, 7, 6, 2} 
	};
	int b = 4;
	numMagicSquaresInside(grid, 3, b);

}

/*
856. 括号的分数

给定一个平衡括号字符串 S，按下述规则计算该字符串的分数：

() 得 1 分。
AB 得 A + B 分，其中 A 和 B 是平衡括号字符串。
(A) 得 2 * A 分，其中 A 是平衡括号字符串。

示例 1：
输入： "()"
输出： 1

示例 2：
输入： "(())"
输出： 2

示例 3：
输入： "()()"
输出： 2

示例 4：
输入： "(()(()))"
输出： 6

提示：
S 是平衡括号字符串，且只含有 ( 和 ) 。
2 <= S.length <= 50
*/
int scoreOfParentheses1(char* S, int D[]) {

	int n = strlen(S);

	if (n == 1)
	{
		printf("result: %d \n", S[0] - '0');
		return;
	}

	int i = 0, k = 0;
	char temp[50] = { 0 };
	//printf("%s\n", S);
	for (i = 0; i < n; i++)
	{
		if (S[i] == '(' && S[i+1] == ')')
		{
			temp[k++] = '1';
			i++;
		}
		//else if (S[i] == '(' && (S[i + 1] >= '0' && S[i + 1] <= '9') && S[i + 2] == ')')
		else if (S[i] == '(' && (S[i + 1] != '(' && S[i + 1] != ')') && S[i + 2] == ')')
		{
			printf("    %d    ", S[i + 1] - '0');
			temp[k++] = 2 * (S[i + 1] - '0') + '0';
			i = i + 2;
		}
		//else if ((S[i] >= '0' && S[i] <= '9') && (S[i + 1] >= '0' && S[i + 1] <= '9'))
		else if ((S[i] != '(' && S[i] != ')') && (S[i + 1] != '(' && S[i + 1] != ')'))
		{
			temp[k++] = S[i] - '0' + S[i + 1] - '0' + '0';
			i++;
		}
		else
			temp[k++] = S[i];
	}
	temp[k] = '\0';
	printf("%s\n", temp);
	scoreOfParentheses(temp, D);
}

int scoreOfParentheses(char* S, int D[]) {

	int n = strlen(S);

	if (n == 1)
	{
		//printf("result: %d \n", S[0] - '0');
		//for(int i = 0;i<20;i++) printf("%d ", D[i]);
		printf("[%d] ", D[0]);
		return D[0];
	}
	/*
	for (int i = 0; i < 20; i++)
	{
		printf("%2d ", D[i]);
	}
	*/
	int i = 0, k = 0;
	char temp[50] = { 0 };
	int d[50] = { 0 };

	for (i = 0; i < n; i++)
	{
		if (S[i] == '(' && S[i + 1] == ')')
		{
            d[k] = 1;
			temp[k++] = '1';
			i++;
		}
		else if (S[i] == '(' && (S[i + 1] == '1') && S[i + 2] == ')')
		{
			d[k] = 2 * D[i + 1];
			temp[k++] = '1';
			i = i + 2;
		}
		else if ((S[i] == '1' && S[i + 1] == '1'))
		{
			d[k] = D[i] + D[i + 1];
			temp[k++] = '1';
			i++;
		}
		else
		{
			d[k] = D[i];
			temp[k++] = S[i];
		}
	}
	temp[k] = '\0';
	printf("%s\n", temp);
	return scoreOfParentheses(temp, d);
	//return D[0];
}

void ID856()
{
	char *S = 
		//"()"
		//"(())"
		//"()()"
		//"(()(()))"
		//"(1(1))"
		//"(12)"
		//"(3)"
		//"(111)"
		//"((()()((()((())((())))(()))())))"
		//"((2((1(6)2)1)))"
		//"(12)(34)"
		//"((9))"
		//"((((()((()()())()((()((())((())))(()))()))))))"
		"(((()()(()((()())()((()((())((())))(()))()))))))"
		;
	int D[50] = { 0 };
	printf("=%d \n",scoreOfParentheses(S, D));
}

/*
1. 两数之和

给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。

你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。

示例:
给定 nums = [2, 7, 11, 15], target = 9
因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
*/

/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int* twoSum(int* nums, int numsSize, int target) {

	int * dest = (int *)malloc(sizeof(int) * 2);

	int i = 0, j = 0;
	for (i = 0; i < numsSize; i++)
	{
		for (j = i + 1; j < numsSize; j++)
		{
			if (nums[i] + nums[j] == target)
			{
				printf("[%d, %d] = %d\n", i, j, target);
				dest[0] = i;
				dest[1] = j;
				return dest;
			}
		}
	}
}

void ID1()
{
	int nums[] = { 2,7,11,15 };
	int target = 9;

	twoSum(nums, sizeof(nums) / sizeof(nums[0]), target);
}

/*
767. 重构字符串

给定一个字符串S，检查是否能重新排布其中的字母，使得两相邻的字符不同。
若可行，输出任意可行的结果。若不可行，返回空字符串。

示例 1:
输入: S = "aab"
输出: "aba"

示例 2:
输入: S = "aaab"
输出: ""

注意:
S 只包含小写字母并且长度在[1, 500]区间内。
*/

char* reorganizeString(char* S) {

	int n = strlen(S);
	int i = 0, j = 0, k = 0, t = 0;
	char d[26] = { 0 };
	char *dest = (char *)malloc(sizeof(char)*n);

	for (i = 0; i < n; i++)
	{
		d[S[i] - 'a']++;
	}

	int max = 0, index = 0;
	for (i = 0; i < 26; i++)
	{
		if (d[i] > max)
		{
			max = d[i];
			index = i;
		}
	}
	if((n % 2 == 0 && max > n/ 2) || (n % 2 != 0 && max > n / 2 + 1) ) return NULL;
	//if (max > n / 2 + 1) return NULL;
	k = 0;
	while(k < n)
	{
		for (j = 0; j < 26; j++)
		{
			if (d[j] != 0)
			{
				dest[k++] = j + 'a';
				d[j]--;
				t++;
				if (t > 1)
				{
					t = 0;
					break;
				}
			}
		}
	}
	dest[k] = '\0';
	printf("%s \n", dest);
	printf("%d \n", max);
	return dest;
}

void ID767()
{
	char *S =
		//"aaabsdfsadtgb"
		//"aab"
		//"aaab"
		//"vvvlo"
		"zzzby"
		;
	reorganizeString(S);
}


/*
459. 重复的子字符串

给定一个非空的字符串，判断它是否可以由它的一个子串重复多次构成。给定的字符串只含有小写英文字母，并且长度不超过10000。

示例 1:
输入: "abab"
输出: True
解释: 可由子字符串 "ab" 重复两次构成。

示例 2:
输入: "aba"
输出: False

示例 3:
输入: "abcabcabcabc"
输出: True

解释: 可由子字符串 "abc" 重复四次构成。 (或者子字符串 "abcabc" 重复两次构成。)
*/
#define repeat_MAX 10001
bool repeatedSubstringPattern(char* s) {

	int n = strlen(s);
	char temp[repeat_MAX] = { 0 };
	char dest[repeat_MAX] = { 0 };

	int i = 0, j = 0;
	printf("%s, %d\n", s, n);
	/*
	//素数并且元素不相等
	if (isPrime_4(n) && n >3)
	{
		for (int k = 1; k < n; k++)
		{
			if (s[k-1] != s[k])
			{
				printf("er\n");
				return 0;
			}
		}
	}
	*/
	for (i = 1; i < n; i++)
	{
      if (i > n /2 && n % 2 == 0) { i = n; break; }
	  else if (i > n / 2 + 1 && n % 2 != 0) { i = n; break; }

		memcpy_s(temp, sizeof(char)*n, s, sizeof(char) * i);

		for (j = 0; j < n / i ; j++)
		{	
			//printf("i = %d, j = %d ", i, j);
			memcpy_s(dest+j*i, sizeof(char) * n, temp, i);
			//printf("dest = %s\n", dest);
		}
		printf("temp = %s \n", temp);printf("dest = %s \n", dest);
        
		if (strcmp(dest, s) == 0)
		{
			//printf("dest = %s, i = %d \n", dest, i);
			break;
		}
		memset(dest, 0x00, sizeof(char) * n);
	}

	if (i == n) { printf("false!\n"); }
	else { printf("true!\n"); }
}

void ID459()
{
	char *s =
		//"aaaaaaaaaaaaa"
		//"zzzz"
		//"bb"
		//"aaba"
		"aabaaba"
		//"aabaabaaba"
		//"aabaabaabaaba"
		//"aabaabaabaabaaba"
		//"ababba"
		//"abcabcabcabc"
		//"abcdef"
		//"nwlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmcoqhnwnkuewhsqmgbbuqcljjivswmdkqtbxixmvtrrbljptnsnfwzqfjmafadrrwsofsbcnuvqhffbsaqxwpqcacehchzvfrkmlnozjkpqpxrjxkitzyxacbhhkicqcoendtomfgdwdwfcgpxiqvkuytdlcgdewhtaciohordtqkvwcsgspqoqmsboaguwnnyqxnzlgdgwpbtrwblnsadeuguumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayulyeimuotehzriicfskpggkbbipzzrzucxamludfykgruowzgiooobppleqlwphapjnadqhdcnvwdtxjbmyppphauxnspusgdhiixqmbfjxjcvudjsuyibyebmwsiqyoygyxymzevypzvjegebeocfuftsxdixtigsieehkchzdflilrjqfnxztqrsvbspkyhsenbppkqtpddbuotbbqcwivrfxjujjddntgeiqvdgaijvwcyaubwewpjvygehljxepbpiwuqzdzubdubzvafspqpqwuzifwovyddwyvvburczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveymqpxhlrnunyfdzrhbasjeuygafoubutpnimuwfjqsjxvkqdorxxvrwctdsneogvbpkxlpgdirbfcriqifpgynkrrefxsnvucftpwctgtwmxnupycfgcuqunublmoiitncklefszbexrampetvhqnddjeqvuygpnkazqfrpjvoaxdpcwmjobmskskfojnewxgxnnofwltwjwnnvbwjckdmeouuzhyvhgvwujbqxxpitcvograiddvhrrdsycqhkleewhxtembaqwqwpqhsuebnvfgvjwdvjjafqzzxlcxdzncqgjlapopkvxfgvicetcmkbljopgtqvvhbgsdvivhesnkqxmwrqidrvmhlubbryktheyentmrobdeyqcrgluaiihveixwjjrqopubjguxhxdipfzwswybgfylqvjzharvrlyauuzdrcnjkphclffrkeecbpdipufhidjcxjhrnxcxmjcxohqanxdrmgzebhnlmwpmhwdvthsfqueeexgrujigskmvrzgfwvrftwapdtutpbztygnsrxajjngcomikjzsdwssznovdruypcnjulkfuzmxnafamespckjcazxdrtdgyrqscczybnvqqcqcjitlvcnvbmasidzgwraatzzwpwmfbfjkncvkelhhzjchpdnlunmppnlgjznkewwuysgefonexpmmsbaopmdgzqmkqzxuvtqvnxbslqzkglzamzpdnsjolvybwxxttqognrbaiakqllszkhfzconnmoqklpeefsnsmouwqhodsgcfohesyshmgxwtoayuvnojdjftqtwkbapriujimqwspslgvlcsaqbdbgwtbseettwdnfnbyjvpdjxyuzqxstatbzpctthoofremgfkrbcvkzvgbofthgojhdnaywpnbitoraaibednezwfpdawlohssvtqtkfvsyljzlucqxswyqdntdmfrtzlqsekejhzksklfepxchvczysvdgcxbbiswmeaylzifktmoikssfxtgpojxqiysrsqfwqdjqnqcgdqrnlluieazvmwnuufnnxvloyvgmliuqandlyavfauaosnlnvacsvpiumoiawcqxswkqwgxyazntnaikameybnuqbcqaggxachrynqxqqmlfotpqhvokiiammqmvxjvbsoaifzyxnjcberrnmixxsyjhovengbpyqrixqgwdrygxrxkfhicainhwilkqmbpeszdigznzxtzqsjwatycbmjawwmninepfduplucltxmkpvgrrgtuseurageltkcapwpbqromqawixezqkvlfbhwcocpjmrmbpbegvsuluqtuuvkesvjtdhvtjmexfqbvufdpaxcwnwqjtbplyzedicwsodpwtqrpyuearhwgfnpaqelofrsotqiktxipqzeqvlqmuoubbjbrpmixfclbstnosvdkujcpwsdqhxrkiueziowoqjpiecwxxbjtnmkjgncpmvauqgtausokbfugjtfiuqbjclvlazamucimicnewdoxjlfuemdadgkhufsuevjaxrnivcorhfrqqwnujquoyevslqprlyskrhunljgsoxleuyyfqutozqhmgyetyyepfaesjlkzivdevdllygazxjndjrxhrdyyddqnqdoayshwxshxzjywumbffamxdnxjqoyirmirernekxdlicjfqkkvnxuqmszcixmzkwsqoiwyfalpeuuugfrteomqinuqnirxelpstosaodqszkogrfbxtnpdbltqtmpyyeqtujuiokcowswqyxntndxqqsgkhvihbaawjugagloddktdjizynyoesuozryityjrifximkyrokktvusuiqiojfckyatryekijksvusokcyeavwufpctajxkixdbxjmitwcqqxfbbfhbadvfuaaujxfrwkvuuhepdifvfkyhsfiuleafgaapahjwtesplweqfmnmymtqreleinkopmfpvomqueghdmxkynwxzqnswaxgnjwdxbuusgkmnqwqdvadiwahoqakqzqgkmlhqfdimnwzgsplorownpgehioxhhfrvqalwdtksslykajataxgpdmyldxukdnftprrumbmemlrowrhwoqntclghlcrorzhgsbaecplpccdyvnxmdmfhaoplqizkhiqbjtimitdkxiksxjecwmkwabhslievqvwcqeqaztkydwrbgxdcjpalshgepkzhhvlxcbxdwjccgtdoqiscyspqzvuqivzptlpvooynyapgvswoaosaghrffnxnjyeeltzaizniccozwknwyhzgpqlwfkjqipuujvwtxlbznryjdohbvghmyuiggtyqjtmuqinntqmihntkddnalwnmsxsatqqeldacnnpjfermrnyuqnwbjjpdjhdeavknykpoxhxclqqedqavdwzoiorrwwxyrhlsrdgqkduvtmzzczufvtvfioygkvedervvudneghbctcbxdxezrzgbpfhzanffeccbgqfmzjqtlrsppxqiywjobspefujlxnmddurddiyobqfspvcoulcvdrzkmkwlyiqdchghrgytzdnobqcvdeqjystmepxcaniewqmoxkjwpymqorluxedvywhcoghotpusfgiestckrpaigocfufbubiyrrffmwaeeimidfnnzcphkflpbqsvtdwludsgaungfzoihbxifoprwcjzsdxngtacwtjypweuxvegybogsfxqhipbompufpxckicaghufczmaccgwigmrqcteqkbwbaamicoqlivnjjoomwkucznvdgztqarsargkwuaheyvohletjqpopdjslkoelfynzeavaaceazuimydypvmgyxblhppuunkttkqtmvanuuvjvahmvvuvsvhzkywhmgchqvdcqdpmzmxwneikzfgtantnlpwzvahnvkplpfaotxngexrfczzdmuszlobiokvkwkxlrxblvotzomeqlftxzlzkbcsqmnciazvrzyeupyvdkbtwhpvgcwteylwkbyubxruwszshxpmjrhfawdibzbfypdksbhtaapzsorbnjpzcxecvjmwjqdjhgvzjcukfjjzacbpnsoppvtleijpynyfvuefyyrdjadjegbsypjomfbrnkilzhsvbwczwtdfvirbosvmjfcymdrzqzkpgemjaojyjofeywimqdackdawitxysjqzncipttncjtjhrtvkwwojbqhjjfkboaccenrxihcsanbtgxdcttnujvfscrwqtyuynmxwvbqxorquowzhpmdzjlrlcncyoywbmvzhxpenhvivthfivkhfxbqaquyetwifthnsxrggoqbhxiqsvzzscqutmszfqjnmtaeqtmykcbrzkjuhltznluiyokfhvstouzgqmeaogrqsdmzohydtuotjyysttlknmqdyvdpbxftatuqastvphoahpsdifnxrfbqaghdfoyhhsxhntdcctcmiupqzeqsjrkmzrphfoooioyvjdxnwbzhvqzwuprgibsitjpazfritpfesfsqgrxekxcgmtmvvgfqqwspdjxzaddukvlqpkuzjzhwsutpcafsyaibjhammegwbtpqelrnkbldxguzgcseccinlizyogwqzlifxcthdgmanjztltanviajschhkdxlrfrohmxmsmmhvodihdvfnxofbxmlclxvrojacjpwxbeurhcbmzgzwwgyvtlzeivxygaappzosdikkmlwltxirdioytnfeieepehgvgvqjfavsntfiqnbvxputczznfdcmkkhshxdnzyhormwjcxfbobwrcvehbitnsdgacjpeiysbmrnoqssfvoyxkeglmaygfgihqznazgdmzqcpiuudjucvyjimlivqpdzhfnhevksudvjlrgrcavxzehlrqgjhmjqtyzztjsnopyagetjfqiexqroiayrojhjhgiarcpgrniysdhztpfqhwhpyfioopxxvgxniovabdatgjszazsiwzzweiluxirvqqkzefbhiddqmxrmxjwtiwrogckdldadtkczpfhzikpujhjgqfbbbtrhvcnifnmbaqapyjrgvgdfpmlirnjvgaedetokjcljsnaqzrzuacbpqnxjciekllnpedbpfoyyczqdspxstbknwlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmcoqhnwnkuewhsqmgbbuqcljjivswmdkqtbxixmvtrrbljptnsnfwzqfjmafadrrwsofsbcnuvqhffbsaqxwpqcacehchzvfrkmlnozjkpqpxrjxkitzyxacbhhkicqcoendtomfgdwdwfcgpxiqvkuytdlcgdewhtaciohordtqkvwcsgspqoqmsboaguwnnyqxnzlgdgwpbtrwblnsadeuguumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayulyeimuotehzriicfskpggkbbipzzrzucxamludfykgruowzgiooobppleqlwphapjnadqhdcnvwdtxjbmyppphauxnspusgdhiixqmbfjxjcvudjsuyibyebmwsiqyoygyxymzevypzvjegebeocfuftsxdixtigsieehkchzdflilrjqfnxztqrsvbspkyhsenbppkqtpddbuotbbqcwivrfxjujjddntgeiqvdgaijvwcyaubwewpjvygehljxepbpiwuqzdzubdubzvafspqpqwuzifwovyddwyvvburczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveymqpxhlrnunyfdzrhbasjeuygafoubutpnimuwfjqsjxvkqdorxxvrwctdsneogvbpkxlpgdirbfcriqifpgynkrrefxsnvucftpwctgtwmxnupycfgcuqunublmoiitncklefszbexrampetvhqnddjeqvuygpnkazqfrpjvoaxdpcwmjobmskskfojnewxgxnnofwltwjwnnvbwjckdmeouuzhyvhgvwujbqxxpitcvograiddvhrrdsycqhkleewhxtembaqwqwpqhsuebnvfgvjwdvjjafqzzxlcxdzncqgjlapopkvxfgvicetcmkbljopgtqvvhbgsdvivhesnkqxmwrqidrvmhlubbryktheyentmrobdeyqcrgluaiihveixwjjrqopubjguxhxdipfzwswybgfylqvjzharvrlyauuzdrcnjkphclffrkeecbpdipufhidjcxjhrnxcxmjcxohqanxdrmgzebhnlmwpmhwdvthsfqueeexgrujigskmvrzgfwvrftwapdtutpbztygnsrxajjngcomikjzsdwssznovdruypcnjulkfuzmxnafamespckjcazxdrtdgyrqscczybnvqqcqcjitlvcnvbmasidzgwraatzzwpwmfbfjkncvkelhhzjchpdnlunmppnlgjznkewwuysgefonexpmmsbaopmdgzqmkqzxuvtqvnxbslqzkglzamzpdnsjolvybwxxttqognrbaiakqllszkhfzconnmoqklpeefsnsmouwqhodsgcfohesyshmgxwtoayuvnojdjftqtwkbapriujimqwspslgvlcsaqbdbgwtbseettwdnfnbyjvpdjxyuzqxstatbzpctthoofremgfkrbcvkzvgbofthgojhdnaywpnbitoraaibednezwfpdawlohssvtqtkfvsyljzlucqxswyqdntdmfrtzlqsekejhzksklfepxchvczysvdgcxbbiswmeaylzifktmoikssfxtgpojxqiysrsqfwqdjqnqcgdqrnlluieazvmwnuufnnxvloyvgmliuqandlyavfauaosnlnvacsvpiumoiawcqxswkqwgxyazntnaikameybnuqbcqaggxachrynqxqqmlfotpqhvokiiammqmvxjvbsoaifzyxnjcberrnmixxsyjhovengbpyqrixqgwdrygxrxkfhicainhwilkqmbpeszdigznzxtzqsjwatycbmjawwmninepfduplucltxmkpvgrrgtuseurageltkcapwpbqromqawixezqkvlfbhwcocpjmrmbpbegvsuluqtuuvkesvjtdhvtjmexfqbvufdpaxcwnwqjtbplyzedicwsodpwtqrpyuearhwgfnpaqelofrsotqiktxipqzeqvlqmuoubbjbrpmixfclbstnosvdkujcpwsdqhxrkiueziowoqjpiecwxxbjtnmkjgncpmvauqgtausokbfugjtfiuqbjclvlazamucimicnewdoxjlfuemdadgkhufsuevjaxrnivcorhfrqqwnujquoyevslqprlyskrhunljgsoxleuyyfqutozqhmgyetyyepfaesjlkzivdevdllygazxjndjrxhrdyyddqnqdoayshwxshxzjywumbffamxdnxjqoyirmirernekxdlicjfqkkvnxuqmszcixmzkwsqoiwyfalpeuuugfrteomqinuqnirxelpstosaodqszkogrfbxtnpdbltqtmpyyeqtujuiokcowswqyxntndxqqsgkhvihbaawjugagloddktdjizynyoesuozryityjrifximkyrokktvusuiqiojfckyatryekijksvusokcyeavwufpctajxkixdbxjmitwcqqxfbbfhbadvfuaaujxfrwkvuuhepdifvfkyhsfiuleafgaapahjwtesplweqfmnmymtqreleinkopmfpvomqueghdmxkynwxzqnswaxgnjwdxbuusgkmnqwqdvadiwahoqakqzqgkmlhqfdimnwzgsplorownpgehioxhhfrvqalwdtksslykajataxgpdmyldxukdnftprrumbmemlrowrhwoqntclghlcrorzhgsbaecplpccdyvnxmdmfhaoplqizkhiqbjtimitdkxiksxjecwmkwabhslievqvwcqeqaztkydwrbgxdcjpalshgepkzhhvlxcbxdwjccgtdoqiscyspqzvuqivzptlpvooynyapgvswoaosaghrffnxnjyeeltzaizniccozwknwyhzgpqlwfkjqipuujvwtxlbznryjdohbvghmyuiggtyqjtmuqinntqmihntkddnalwnmsxsatqqeldacnnpjfermrnyuqnwbjjpdjhdeavknykpoxhxclqqedqavdwzoiorrwwxyrhlsrdgqkduvtmzzczufvtvfioygkvedervvudneghbctcbxdxezrzgbpfhzanffeccbgqfmzjqtlrsppxqiywjobspefujlxnmddurddiyobqfspvcoulcvdrzkmkwlyiqdchghrgytzdnobqcvdeqjystmepxcaniewqmoxkjwpymqorluxedvywhcoghotpusfgiestckrpaigocfufbubiyrrffmwaeeimidfnnzcphkflpbqsvtdwludsgaungfzoihbxifoprwcjzsdxngtacwtjypweuxvegybogsfxqhipbompufpxckicaghufczmaccgwigmrqcteqkbwbaamicoqlivnjjoomwkucznvdgztqarsargkwuaheyvohletjqpopdjslkoelfynzeavaaceazuimydypvmgyxblhppuunkttkqtmvanuuvjvahmvvuvsvhzkywhmgchqvdcqdpmzmxwneikzfgtantnlpwzvahnvkplpfaotxngexrfczzdmuszlobiokvkwkxlrxblvotzomeqlftxzlzkbcsqmnciazvrzyeupyvdkbtwhpvgcwteylwkbyubxruwszshxpmjrhfawdibzbfypdksbhtaapzsorbnjpzcxecvjmwjqdjhgvzjcukfjjzacbpnsoppvtleijpynyfvuefyyrdjadjegbsypjomfbrnkilzhsvbwczwtdfvirbosvmjfcymdrzqzkpgemjaojyjofeywimqdackdawitxysjqzncipttncjtjhrtvkwwojbqhjjfkboaccenrxihcsanbtgxdcttnujvfscrwqtyuynmxwvbqxorquowzhpmdzjlrlcncyoywbmvzhxpenhvivthfivkhfxbqaquyetwifthnsxrggoqbhxiqsvzzscqutmszfqjnmtaeqtmykcbrzkjuhltznluiyokfhvstouzgqmeaogrqsdmzohydtuotjyysttlknmqdyvdpbxftatuqastvphoahpsdifnxrfbqaghdfoyhhsxhntdcctcmiupqzeqsjrkmzrphfoooioyvjdxnwbzhvqzwuprgibsitjpazfritpfesfsqgrxekxcgmtmvvgfqqwspdjxzaddukvlqpkuzjzhwsutpcafsyaibjhammegwbtpqelrnkbldxguzgcseccinlizyogwqzlifxcthdgmanjztltanviajschhkdxlrfrohmxmsmmhvodihdvfnxofbxmlclxvrojacjpwxbeurhcbmzgzwwgyvtlzeivxygaappzosdikkmlwltxirdioytnfeieepehgvgvqjfavsntfiqnbvxputczznfdcmkkhshxdnzyhormwjcxfbobwrcvehbitnsdgacjpeiysbmrnoqssfvoyxkeglmaygfgihqznazgdmzqcpiuudjucvyjimlivqpdzhfnhevksudvjlrgrcavxzehlrqgjhmjqtyzztjsnopyagetjfqiexqroiayrojhjhgiarcpgrniysdhztpfqhwhpyfioopxxvgxniovabdatgjszazsiwzzweiluxirvqqkzefbhiddqmxrmxjwtiwrogckdldadtkczpfhzikpujhjgqfbbbtrhvcnifnmbaqapyjrgvgdfpmlirnjvgaedetokjcljsnaqzrzuacbpqnxjciekllnpedbpfoyyczqdspxstbk"
		//"abcdefghighelasjdflkjasdlkfjsaszdtbgaetabcdefghighelasjdflkjasdlkfjsaszdtbgaet"
		;
	repeatedSubstringPattern(s);
}

/*
866. 回文素数

求出大于或等于 N 的最小回文素数。

回顾一下，如果一个数大于 1，且其因数只有 1 和它自身，那么这个数是素数。
例如，2，3，5，7，11 以及 13 是素数。

回顾一下，如果一个数从左往右读与从右往左读是一样的，那么这个数是回文数。
例如，12321 是回文数。


示例 1：
输入：6
输出：7

示例 2：
输入：8
输出：11

示例 3：
输入：13
输出：101


提示：
1 <= N <= 10^8
答案肯定存在，且小于 2 * 10^8。
*/

int primePalindrome(int N) {

	int i = 0;
	char temp[10] = { 0 };
	if (N == 1) return 2;
	for (i = N; i < N*10; i++) //INT_MAX
	{
		//if (i % 2 == 0 || i % 3 == 0 || i % 5 == 0 || i % 7 == 0)continue;
		int flag = 1;
		if (isPrime_4(i))
		{
			/*
			if (i < 10)
			{
				printf("i = %d \n", i);
				return i;
			}
			sprintf_s(temp, sizeof(char) * 10, "%d", i);
			//printf("%d, %s \n", i, temp);
			int n = strlen(temp);
			for (int j = 0; j < n/2; j++)
			{
				if (temp[j] != temp[n - j - 1])
				{
					flag = 0;
					break;
				}
			}
			*/
			if (flag)
			{
				printf("i = %d \n",i);
				//break;
			}
		}
	}
	return i;
}

int primePalindrome1(int N) {

	int i = 0;
	char temp[10] = { 0 };
	if (N == 1) return 2;
	for (i = N; i < N *11; i++) //INT_MAX
	{
		int flag = 1;
		if (i % 2 == 0 || i % 3 == 0 || i % 5 == 0 || i % 7 == 0 || i%11 == 0 || i%13 == 0 ||
		    i % 17 == 0 || i % 19 == 0 || i % 23 == 0 || i % 27 == 0 || i % 29 == 0 )
			continue;

		if (i < 10)
		{
		   printf("i = %d \n", i);
		   return i;
		}
		sprintf_s(temp, sizeof(char) * 10, "%d", i);
		//printf("%d, %s \n", i, temp);
		int n = strlen(temp);
		for (int j = 0; j < n/2; j++)
		{
			if (temp[j] != temp[n - j - 1])
			{
				flag = 0;
				break;
			}
		}
	
		if (flag == 1 )//&& isPrime_4(i))
		{
			printf("i = %d \n", i);
			break;

			if (isPrime_4(i))
				printf(" [%d] \n", i);
		}
		
	}
	return i;
}
void ID866()
{
	primePalindrome1(9989900); //120);// 
}

/*
859. 亲密字符串

给定两个由小写字母构成的字符串 A 和 B ，只要我们可以通过交换 A 中的两个字母得到与 B 相等的结果，
就返回 true ；否则返回 false 。

示例 1：
输入： A = "ab", B = "ba"
输出： true

示例 2：
输入： A = "ab", B = "ab"
输出： false

示例 3:
输入： A = "aa", B = "aa"
输出： true

示例 4：
输入： A = "aaaaaaabc", B = "aaaaaaacb"
输出： true

示例 5：
输入： A = "", B = "aa"
输出： false


提示：
0 <= A.length <= 20000
0 <= B.length <= 20000
A 和 B 仅由小写字母构成。
*/
bool buddyStrings(char* A, char* B) {

	int i = 0, j = 0;
	int A_n = strlen(A), B_n = strlen(B);
	if (A_n != B_n) return false;
	
	if (strcmp(A, B) == 0)
	{
		for (i = 1; i < A_n; i++)
		{
			if (A[i - 1] != A[i])
				return false;
		}
		printf("this \n");
		return true;
	}
	char *temp = (char *)malloc(sizeof(char)*(A_n + 1));
	temp[A_n] = '\0';

	for (i = 0; i < A_n; i++)
	{
		if (A[i] == B[i]) continue;
		for (j = i+1; j < A_n; j++)
		{
			memcpy_s(temp, A_n+1, A, A_n);
			
			char t = temp[i];
			temp[i] = temp[j];
			temp[j] = t;

            printf("%s\n", temp);
			if (strcmp(temp, B) == 0)
			{
				printf("ok\n");
				break;
			}
		}
	}
	printf("run this\n");
}

bool buddyStrings1(char* A, char* B) {

	int A_n = strlen(A), B_n = strlen(B);
	int i = 0, j = 0, k = 0;
	char t1 = 0, t2 = 0, t11 = 0, t22 = 0;

	if (strcmp(A, B) == 0)
	{
		for (i = 1; i < A_n; i++)
		{
			if (A[i - 1] != A[i])
				return false;
		}
		printf("this \n");
		return true;
	}

	for (i = 0; i < A_n; i++)
	{
		if (A[i] != B[i])
		{
			k++;
			if (k == 1) 
			{ 
				t1 = A[i];
				t2 = B[i];
			}
			else if (k == 2)
			{
				t11 = A[i];
				t22 = B[i];
			}
		}
		if (k > 2) break;
	}
	if (k == 2 && t1 == t22 && t2 == t11)
	{
		return true;
	}

	return false;
}

void ID859()
{
	char *A = "aaaaaaabc"; //"ab";  //"ab";  // "aaccb"; //
	char *B = "aaaaaaacb"; //"ba";  //"ca";  // "accba"; //

	printf("%d \n",buddyStrings1(A, B));
}
/*
441. 排列硬币

你总共有 n 枚硬币，你需要将它们摆成一个阶梯形状，第 k 行就必须正好有 k 枚硬币。

给定一个数字 n，找出可形成完整阶梯行的总行数。

n 是一个非负整数，并且在32位有符号整型的范围内。

示例 1:
n = 5
硬币可排列成以下几行 :
	¤
	¤ ¤
	¤ ¤
因为第三行不完整，所以返回2.

示例 2:
n = 8
硬币可排列成以下几行 :
	¤
	¤ ¤
	¤ ¤ ¤
	¤ ¤
因为第四行不完整，所以返回3.
*/
int arrangeCoins(int n) {

    int i = 0;
	unsigned int n2 = n, sum = 0;
	for (i = 1;; i++)
	{
		sum = sum + i;//(1 + i)*i;
		//printf("%d \n", sum);
		if(sum > n2)
		{
			break;
		}
	}
	if (n2 >= sum - i)
		printf("-%d ", i - 1);
	else
		printf("%d ", i);

	printf("%d (%d)", sum, INT_MAX);
}

void ID441()
{
	arrangeCoins(2147483647);//104);// 1804289383);// 
}

/*
35. 搜索插入位置

给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

你可以假设数组中无重复元素。

示例 1:
输入: [1,3,5,6], 5
输出: 2

示例 2:
输入: [1,3,5,6], 2
输出: 1

示例 3:
输入: [1,3,5,6], 7
输出: 4

示例 4:
输入: [1,3,5,6], 0
输出: 0
*/
int searchInsert(int* nums, int numsSize, int target) {

	int i = 0;
	for (i = 0; i < numsSize; i++)
	{
		if (nums[i] == target)
		{
			break;
		}
		else if (nums[i] > target)
		{
			i++;
			break;
		}
	}
	printf("%d %d\n", i, numsSize);
	return i;
}

void ID35()
{
	int nums[] = { 1,3,5,6 };
	int numsSize = sizeof(nums) / sizeof(int);
	int target = 0;

	searchInsert(nums, numsSize, target);
}

/*
172. 阶乘后的零

给定一个整数 n，返回 n! 结果尾数中零的数量。

示例 1:
输入: 3
输出: 0
解释: 3! = 6, 尾数中没有零。

示例 2:
输入: 5
输出: 1
解释: 5! = 120, 尾数中有 1 个零.

说明: 你算法的时间复杂度应为 O(log n) 。
*/

int trailingZeroes(int n) {

	//需要考虑5*5、5*5*5,,,和5*10,5*5*10,,,这些情况：会有更多的零
	int i = 0, k10 = 0, k2 = 0, k5 = 0;
	int sum = 1;
	for (i = 1; i <= n; i++)
	{
		if (i % 10 == 0)
		{
			k10++;
		}
		else if (i % 2 == 0)
		{
			k2++;
		}
		else if (i % 125 == 0)
		{
			k5 = k5 + 3;
		}
		else if (i % 25 == 0)
		{
			k5 = k5 + 2;
		}
		else if (i % 5 == 0)
		{
			k5++;
		}
		sum = sum * i;
	}
	printf("%d\n", sum);
	printf("k10 = %d, k2 = %d, k5 = %d \n", k10, k2, k5);

	return (k10 + (k2 > k5 ? k5 : k2));
}

void ID172()
{
	printf("%d \n",trailingZeroes(50));
}

/*
258. 各位相加

给定一个非负整数 num，反复将各个位上的数字相加，直到结果为一位数。

示例:
输入: 38
输出: 2
解释: 各位相加的过程为：3 + 8 = 11, 1 + 1 = 2。 由于 2 是一位数，所以返回 2。

进阶:
你可以不使用循环或者递归，且在 O(1) 时间复杂度内解决这个问题吗？
*/

int func_a(char a[], int i)
{
	if (a[i] <= '9' && a[i] >= '0') { printf("(%d)", (int)(a[i] - '0')); return (int)(a[i] - '0'); }
	else return 0;
}

int addDigits(int num) {

	printf("%d\n", num);
	char a[12] = { 0 };
	sprintf_s(a, 12, "%d", num);
	printf("%s, %d \n", a, strlen(a));

	int t1 = func_a(a, 10) + func_a(a, 9) + func_a(a, 8) + func_a(a, 7) + func_a(a, 6) + 
		     func_a(a, 5) + func_a(a, 4) + func_a(a, 3) + func_a(a, 2) + func_a(a, 1) + func_a(a, 0);

	printf("%d \n", t1);
	sprintf_s(a, 12, "%d", t1);
	int t2 = func_a(a, 2) + func_a(a, 1) + func_a(a, 0);
	printf("%d \n", t2);

	if (t2 > 9) return t2 - 9;
	else return t2;
}

void ID258()
{
	int t = addDigits(101); // INT_MAX); //34353463); //
	printf("%d \n", t);
}

/*326. 3的幂*/
bool isPowerOfThree(int n) {

	int temp = n;
	if (temp == 1) return 1;
	while (temp > 0)
	{
		if (temp < 3) break;
		else if (temp % 3 == 0) temp = temp / 3;
		else break;		 
	}
	
	printf("%d ", n);
	if (temp == 1)
		printf(", yes");
	else
		printf(", no");
}

void ID326()
{
	int n = 4345627;// 343534623;
	isPowerOfThree(n);
}

/*231. 2的幂*/
bool isPowerOfTwo(int n) {

	int temp = n, t = 0;
	if (temp == 1) return 1;
	while (temp )
	{
		printf("%d ", temp);
		if (temp & 0x01) t++;
		if (t > 1) break;
		temp = temp >> 1;
	}
	printf("%d ", n);
	if(t == 1)
		printf(", yes");
	else
		printf(", no");
}

void ID231()
{
	int n = 512;// 343534623;
	isPowerOfTwo(n);
}

/*
60. 第k个排列

给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列。

按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：
"123"
"132"
"213"
"231"
"312"
"321"

给定 n 和 k，返回第 k 个排列。

说明：
给定 n 的范围是 [1, 9]。
给定 k 的范围是[1,  n!]。

示例 1:
输入: n = 3, k = 3
输出: "213"

示例 2:
输入: n = 4, k = 9
输出: "2314"
*/
char* getPermutation(int n, int k) {

}

void ID60()
{

}

/*
413. 等差数列划分

如果一个数列至少有三个元素，并且任意两个相邻元素之差相同，则称该数列为等差数列。

例如，以下数列为等差数列:
1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9

以下数列不是等差数列。
1, 1, 2, 5, 7

数组 A 包含 N 个数，且索引从0开始。数组 A 的一个子数组划分为数组 (P, Q)，P 与 Q 是整数且满足 0<=P<Q<N 。
如果满足以下条件，则称子数组(P, Q)为等差数组：
元素 A[P], A[p + 1], ..., A[Q - 1], A[Q] 是等差的。并且 P + 1 < Q 。
函数要返回数组 A 中所有为等差数组的子数组个数。

示例:
A = [1, 2, 3, 4]
返回: 3, A 中有三个子等差数组: [1, 2, 3], [2, 3, 4] 以及自身 [1, 2, 3, 4]。

int numberOf(int *A, int length, int n, int sum)
{
	if (n == length)
	{
		return sum;
	}
	//没写完·····
	for (int i = 0; i < length - 1; i++)
	{
		int k = 0;
		for (int j = i; j < n; j++)
		{
			if (A[j + 2] - A[j + 1] == A[j + 1] - A[j + 0])
				k++;
			if (k == n)
			{
				sum++;
				break;
			}
		}
	}
}

int numberOfArithmeticSlices(int* A, int ASize) {

	int t = numberOf(A, ASize, 3, 0);

	printf("%d \n", t);
}

void ID413()
{
	int A[] = { 1,2,3,4,5 };
	int ASize = sizeof(A) / sizeof(A[0]);

	numberOfArithmeticSlices(A, ASize);
}
*/
/*7. 反转整数*/
int reverse(int x) {

	char temp[12] = { 0 };
	int flag = 1, returnN = 0;

	sprintf_s(temp,12,"%d",x);
	int n = strlen(temp);

	printf("%s (%d)\n", temp, n);
	
	for (int i = 0; i < n/2; i++)
	{
		char t = temp[i];
		temp[i] = temp[n - i - 1];
		temp[n - i - 1] = t;
	}

	printf("%s \n", temp);

	if (((x < 0 && n == 11) || (x > 0 && n == 10)) && strcmp(temp, "2147483647") > 0)
	{
		returnN = 0;
	}
	else
	{
		returnN = atof(temp);
		if (x < 0) returnN = -returnN;
	}
	printf("%d \n", returnN);
	return returnN;
}

void ID7()
{
	reverse(2147483648);// 120);// 2147483647);// 5412150); //-123);// 
}

/*201. 数字范围按位与*/
int rangeBitwiseAnd(int m, int n) {

	printf("m = %d, n = %d \n", m, n);
	int temp = m;
	for (int i = m; i <= n; )
	{
		printf("%d \n", i);
		if (temp == 0 || i == INT_MAX) break;
		temp = temp & i;
		i++;
	}
	printf("INT_MAX(%d) \n", INT_MAX);
	printf("%d \n", temp);
}

void ID201()
{
	int m = 2147483646, n = 2147483647;
	//int m = 6, n = 7;
	rangeBitwiseAnd(m,n);
}

/*
371. 两整数之和

不使用运算符 + 和 - ​​​​​​​，计算两整数 ​​​​​​​a 、b ​​​​​​​之和。
*/
int getSum(int a, int b) {

	int t1 = 0, t2 = 0;
	int f = 0, k = 0, c[34] = { 0 };
	for (int i = 0; i <= 32; i++)
	{
		t1 = 0x01 & a;
		t2 = 0x01 & b;

		if (t1 == 0 && t2 == 0 && f == 0)
			c[k++] = 0;
		else if ((t1 == 1 && t2 == 0 && f == 0) || (t1 == 0 && t2 == 1 && f == 0) || (t1 == 0 && t2 == 0 && f == 1))
		{
			c[k++] = 1;
			f = 0;
		}
		else if ((t1 == 1 && t2 == 1 && f == 0) || (t1 == 0 && t2 == 1 && f == 1) || (t1 == 1 && t2 == 0 && f == 1))
		{
			f = 1;
			c[k++] = 0;
		}
		else if (t1 == 1 && t2 == 1 && f == 1)
		{
			c[k++] = 1;
			f = 1;
		}
		printf("t1 = %d, t2 = %d \n", t1, t2);
		a = a >> 1;
		b = b >> 1;
		
		if (a == 0 && b == 0)
			break;
	}
	if (f) c[k++] = 1;
	int d = 0;
	for(int i = 0; i < k-1; i++)
	{
		printf("%d ", c[k - i - 1]);
		d = d + c[k - i - 1] << 1;
	}
	d = d + c[0];
	printf("%d \n", d);

	return d;
}
/*
别人的代码：
int getSum(int a, int b) {
	if(b == 0){
	return a;
	}else{
	return getSum(a ^ b, (a & b) << 1);
}
//参考资料
//https://blog.csdn.net/lijunpeng71/article/details/80224793
//https://blog.csdn.net/morewindows/article/details/8710737
}
*/
void ID371()
{
	getSum(INT_MAX - 10, 3);
}

/*
383. 赎金信

给定一个赎金信 (ransom) 字符串和一个杂志(magazine)字符串，判断第一个字符串ransom能不能由第二个字符串magazines里面的字符构成。如果可以构成，返回 true ；否则返回 false。

(题目说明：为了不暴露赎金信字迹，要从杂志上搜索各个需要的字母，组成单词来表达意思。)

注意：
你可以假设两个字符串均只含有小写字母。

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
*/
bool canConstruct1(char* ransomNote, char* magazine) {

	int n = strlen(ransomNote), m = strlen(magazine);

	printf("%d %d \n", n, m);
	char *temp = (char *)malloc(sizeof(char)*(n+1));
	temp[n] = '\0';

	for (int i = 0; i <= m-n; i++)
	{
		memcpy(temp, magazine+i, n);
		printf("%s \n", temp);
		if (strcmp(temp, ransomNote) == 0)
		{
			printf("true \n");
			return 1;
		}
	}
	printf("false\n");
}

bool canConstruct(char* ransomNote, char* magazine) {

	int N26[26] = { 0 }, M26[26] = { 0 };
	int n = strlen(ransomNote), m = strlen(magazine);

	int i = 0;
	for (i = 0; i < n; i++)
	{
		N26[ransomNote[i] - 'a']++;
	}

	for (i = 0; i < m; i++)
	{
		M26[magazine[i] - 'a']++;
	}

	for (i = 0; i < 26; i++)
	{
		printf("N[%c] = %d, M[%c] = %d \n", i + 'a', N26[i], i + 'a', M26[i]);
		if (N26[i] > M26[i])
		{
			printf("false \n");
			return 0;
		}
	}
	printf("true \n");
	return 1;
}

void ID383()
{
	char *a = "avbe";
		//"cibdccdjhgihcdchibjfhhcafebfcdbjhfiebceeihfifbbecajfidfcfceghaddcjgcaajahbdcddebgafieehchgcigdggibjcajabbaghffgijjejcafajafagegfgihahjgajhhdfehgfgagedjbdcgdciiijciiceahbgbdfcifdadhgieiaadcjgifaaefcacgiaifiahidhchficddgaaaigdbbafabeciedcihbfefidfihcehfeihacbbjiffadbiiacjdidbfahehiicchecgjbbfdeaieafbdbhfigbihjiehjhjicbeaicbeeeefcgbihjajahjhfbddecijhhafdgbfbhicfdijecgchbcdccgajjbadfddjdbdaebehejdhjabecjgffafjbdcidhafchheefhjfciafiaffgbifgddeajfdeacgjfaaeahgaacefafcdadhaabajbdieahajfficfedhieaahdbhhbfgcicbbifbieeiheihgbebggfidfiggeaejgfgbbdjgchihibjghfceabcdjafabhceghegadgfcgeieigdjacbcecfgfhebidfajeifbgejfhhbajhidadgjfbcfgfdehcfgdbhhafgfbghfebfeccddbgebaeeghaccjiiiicgiibjfeacdbdfbahfefabgbaibbfgjcaccjjcggdidhajffacgdghcia"
		;
	char *b = "aabcde";
		//"icfedgijgahgbgiejjhidhdbiffbidaijcbceaihjagibhihjejbfehieeeafegdgabffacejifaddjgjejjebihddcjfgafffbffcgjggiaaicjabgjbbcdgiigfbbedbhdidbdfbfgecddcggheidhdhiiiijcjeibhdjhhiidcafibggbdjcfjbcdbafgifcefhdieibahhiiahcehbbfieihffdjffaefahjedefegahdcffaaigcddbaajafihfaaidijficdbghefdjjjaihhbhbfejhfgiiejcdahgiddjjgdjgebdbhigjdadfadibeafaaadaaaaaacdbbcbfjcbcjbgaadidigcabggigcfefbebciaeejffhiihfijgjdiejgibhehjghhacijbiaffggbfcefedagjeafhgehcajjefeghhhgeefagfabadfdheigdhchgdfcbhacdjafhddgeigccjgifdjcggjebcjhcgggbeiajbhfigcfehafabheedjjhddjieehbfebbagjhffjjjjbehajjcihbaghghicbchgbefhefagcfiacbbeebfjejjiadgaeaccbbediegbfcdifgcagiggfiafgcachhiigbjibdbjabicjihjdajhhahffcighiafhjacbghbccibcafabhbfcbcbicjfgfhcedfbjjigiajbdcjcifadeigghigcghejcaicefejdheefbfccfgbicdabcciegfccjhgeehjgfffdbfdedgefdjgbefgdheaacejeebbfecifjdcfjbjddhdjacfcedhjfdjffggaaigfbdefhhhjgiicefehehaahddddgcejfhfeggiiifacgeheejehbajfjjdhfiiiffbebfcgccgafdehgdbcaefhagaejjhhcghhcdgcifafhbcdhecafhjeebcggadffabfffecaiifahdebhjgjadgbfaehigfdcjideabgghfedcceicbbefdgbdcjgcdedbbehbiheadhcgddhjhahgjbbbaedfbifhhchcdhdbhbhddfaihdahcccgeejbhffjegjbgfghdgbeiiegfgefgecdiefebcbjhecaaechbabfigheffefaiefgcjaaafaiiagjbedihidfjjfhhjjgeaiichbijahfbadichdijcfaejdbcgbbhjbfciajbbgegfdheedifiahbhadgiieagjdhhcegieffigbajgbieicgghbibjdaedagegbfaaggabeebefbhhdahhficgadedifjecabcefgfgabdegdfgaajdbfejiejdcbajdfbhedabbggcfbadibdabiacbbfjhcbjfdjeaeiedjjbbiagadjeecgiiifcffiajchcccbbabfecegibajhjccbiadhfieihfchebebjhhgecddhjfjajjejcehajbcdhgjecbfdfhjiaijchfefgfbjfjgfadebagdbggbaeicehjcghhgfbibfcjbbfigfebgjcafgfhdjfceiaddbeeejecgjhigfahigjcjjfdcjhiddfjcgfeijicjijfgbcfehgiddbibgeadbfabjjegciechaeddbfaaibahggchfhaejjedcjachbgaccijacgbddbgjibabbiidjbdeehgeidfeabbcdejgficcjdaecgcggiihaciedihdihaiiejagejaggddiaccihbcfdegcggghgdaacfigjbjdcfcaeihaaiffbjhjfcabcgbdchfejjachhfighjbbjhifdiigabffjdaedijeifbgdfceagehcacahgdiecabddifdajchjgebjaihbdeibbjffieefagchcdeabbdfdgdjbagjihebaihehjdheheiicjhaehhfhcdfhibbbdjiggdafgggcifagehgfcefbbiihdjagiagjicjdjddecggjfjefdigdgjgcdaheabijdgijejaeciehfigffighbcigabacchbagcfffcdejhaichbbaeahjghdjbjdhcbebabbhbbcbafdcdcdifihiijjjfahgbhfcjhbiafehbgaafbciebbahfaihcfffabcfjjagbajdgggihhaigdceaaacefihicjbjdchehdjhbeceiiejhehcfhejbegceebhjiejhccagdgbibgjaegiaaaffdbiejegidaegibhdabjdhdcahaehgaihjbbacbcahijgjgchfegfdbdccfhcghdbdgiaeijagbjfgidaeefcdbjdgeaddcdhdbfibagjhgjjcbbdhehgjdebgejaegfggcfejfafieciaigcedbbgedgjajjcejiecffdijggffehjeacedbahbfgdjgcajgdjfcebghbeihcfihaahhfeibagjcjhdjgfcjgjdbbadgefffcdgbggbcgchdhddjdaabddjcfghdgejcggbijfbhihefechiehiahijbbhjdbfdcdaihaaaiccgefbhdiefeafdebihbhciedeeagbgbaibcgbjfidbfhhifccadcachihcdcbgihihjffdafcjjdbjgibbbgebdjgccefffcbbjhgedbgcachbffeaaijcfiahdeaecfaheaefegdccaccgicadfedhhdajehfjieccchhhejdaafgigeiafegdjajggifhdcdachgghajiijghjaagcihdhicaeibijjjgfhcfahegcbjadegbijdddgebcfdfcjacdbgedciefgdeggdhhcejdbcjdfgjihggchdceahchhfhcggiihfghabiadiaiiaiejdhbbjcceidffegcbdedgegaeeefhhjhcbadeichcacfbajdbfcaghffbdibfgeaeeacicdjfeiijiedaffjbchchdfehjfcghfeadgbddgiagjddfbajedfeihccbdjcgjdjjjcddeffffbdhabfcjcifdfcfefjfcfcjbhceaidihfffhfeedegjhjcfgfijchceidajgidddajhfcdhjdcfjihbbjgdeefjahhdadehfbegcedcjdhgfagcfjeidbcadagfifabgebffabbfaeidhedigdgfgibfedgebaddajbggefhbabbjihggeefhcbfdfggjihagdcjcijchaahfbeegjjhbjjbdchibhgghccejajeacgegbgaeddhecjejieehbcfhdedaifigdceadjjihgbegijgicdcebdfjhidecifjeabfhahebbcfhaejdhdcbefdchebfbcacbeegfbhdeegeddbacicfgfbegdajacfibfecgidicjhiehigcfiijicdgafbjjfcccafcfbhejbghhbbfcccdgbffcgjbhjgeadbegcbjacgjfaiagafeddjfachecejhffggbbbdbddefeighhddbdcigdiiiggihjgffijeijeeggjjdchgbegcgcbacjgjbfjdecbafihghfaicgbaihibdiecjbfadaechcijhbeiggfdigheighfjccifdahgecaijbediijdbjeieaajajbcdacijhcgedhdihhegaiffjfbaiicjedhgiadbddhhahjjibedhfeafeahabhbfaechjabhiiiigiddedgdhadedfffhcfdafhcjddbhbahhjaiffahgbeidgbfhigjidcjjdgcafbagijeaababiecaggdhhcaabfadgigegihghgeddcciccdjhdcajdahbigedeihafbgbagdgdcjhjabjddadafhjaeaifhjegjgcgdefjicjehafagjfdcdhibffjdgigfeebjdcabdgdicjhjdbbebhaahbafiiiebeejjahdcdbddfifhajfegefjgcgfefdeefcefhbjifafcejjhiaijbabafijbaidcbgddhabjijfhbggadcdahageccfadhjjgahgiggfhbheeabbfjjdjcbifhhbedafadbefiedbjghibedjcgfcgicbhbahdcdcdeibhjdfecajjaihejedhjjiijabchdjdihcibbeciidcgeijjcdiaaadhbcbfhagggbjajfjihjajbaagifdhhghhdacigccebbaahcafjfjcigehiehhchbffhdaebagcdcjbgehfchbfchaaijhghidjbbcajcaeigahacjjhefcehfbaddficjhbbceejgfdebjfadgbbijediigecjfdaafdhcfecdbdfdccaejjeifajbgaceccejaacbgdehhebhiccbibjcfbigfafbecfjbfddhjefjhjfeidcdbdgbggfejbaijdadicgciieahdfeabhbdcjagjefdehjeegjagjcfbgidiehcidagijgeaecjadiiijeegcbhdbhfhjhaaahjhcbagcadgjahbdjeifgeegagahbgbcbeihbjhcbiadejgdfdhjdbgbgdeijfiehgbighbcgbjjeffbcchddfdabedagabcigjjdjbdicaghhifbfgbjchacbfidaiehdffhbifegjgbdbfgigdgjeehjifcdddbbgihiicfggjijiajehjbhhfjfcaagijaihbhbibgegjjcfdfgbdfeabcajjhjhcddiciegaibcffeaajbcfjdhgdfcgdggbcjgfdciffaaeicfjdfhbbeachahjbfhhfdgdfeibcjhechgefceacidbcjbibhfgjjagfhgbbjfdcgccggajhiaigfbhhieghcdedfijaaabahdbidgjfabdgdfebidjhajigeihgdedfgihafegdfceebhaacbjbicbebgjgjjeibcjdgaceffbjihicdbiijcdfjhjgghgaigdiihcbhdjafdacdaighaaccdcghefidhiabajbeieiaiaajigghaacfgbfeahbadbgjjedcgacjchdhgbifbhabiedegfcfdhdchfdcdbfhahcgdiggiehihddeajbafgjcaeedhfiegcebfdgbhghhffecgjjacedeedbjhfcijheihbiegfcbcghfcecagjcfdijhgifjhejchejijhbebcjeiccjgjhfdijagbiachgibaicecehgabfgicjhijjccficagfddfdjebchbcbgigbgajefgjcabefadgdggbdeabfabicdaefhgjfjaiciaacgfdfchhaigeceedccfihjdgjffbcejicaiceeacbeicfdeaibcceejbiabjghcieegigcdjjabgabfhhdhabididecidaffhiicbdfbidgjgeefaaadabdijijdabjibiegbccdjdhbgajijbjehhjaadcjdijaijjdaidjjacbdhehcgeffiafjhjjfebedfjjiicichbjgjigjgcidcgcdajahehgfjiiegjafhbbbgjcijgcfbhecfiajiehcihbbdhhhgacefeihbefgicedeiafjihdggdgdaeijaaaiiicggabjcefeeaeddahdhghaecgagjgfgdfabaffahcbadfghjagjfjeghgdjfgeahiefagdhaaebfhabbbafeabebjcbhbdehhdgfcgaeaddddhagffgafdcfibahciefabfgcjicfaicdheeaiabjcfjaehadjcibbeghiifgihbfefagbdcgahgbhecbdghbhhjegdacjcbijhaighafddifabeagifbddihbjidcaabcjfjbeaaijjfbjfhfhbhjjhhggifdjfcgbbcefdgbbeadcifcegibfejdiibhdciejigjgfgeeigciegibabdhifdabcgdigcehfdbfgfgfacehjdiicehahgggiifjcidjjgcehcadfbaajgaiiajaehiceffjbhicfhcfeeajbbahchhafegabadihhfeccheihjfhigbhjhbdjjdiffffagdjfihdfjgecfbbebiceechidgajchgbbcjbjcffiicggccbjhgafdghbabajhggebhecbjecbbbidhhcbeagddefaifdgbdcdiibdhcdgjdgjjegjeabbgjaegjchhibfhecijhaijjhgciafhgbceaadjgibibhegighgfiiecgfhdfiegiigbgaadcfiehbcgehdchbeibbjfjedaeaieiafigajihhejgdbgdcfeideecebiefafgcfjcghihjgdeieccjiegegbfeaheijdjdbgfcjaecebaiaibbecbbheibhhdajabihdcicdehgddehcddccbffhdifhfegciccedgfbiaaahjhgbafedbgghcjcadaffagfghiagieacagiihhhjigjicdedgcfbggcjcbicechddeibjghgehicgddccggbhdecfhbjdedbchebbbjcijjcbbbebjedcabcijchaeichdahgfijjchbajabgagdcfeciejghgfgefiiigggiijfabjjaecbgiaihcjdegdiagdeebbbidfccgehefjbddagedfeeggebfdbidbibieabdaffbggiajbejdddbbgagcdicgeeechgdbdegjebdbhcabjgigcjcefdjjdhghcaaaiicabfjbcbebiccbbehhiadahbibecgfghfbjhfcdgjbfgjieahhehgedcefdeahbajgheegighdjjbbfiaffhehihhjbhfgihaieiaijhcdhijbigdhfggicjccgeifecifdfacjadahhaadaicfjbfhhfajijahiiejjeidfhefjijfdhjaigigadchiagdefhjefdbcjjdeafajdgaeecfgheibfbigadajijhcfdiffcefbjfajjgcdaiicdaajehadhhabcjeegicfiddjcdbcadhdefjcjhgbbdgccfibjijejeedcjcjcabighjeaicegaejfieebdfdbfdgfadgbhihfhjegibbibjbgfgefafejjfacigedcbididhdcebhehgdibcaaibfifaechcicecjfdhiaggddbibhdfijgdaicbgfigfeaebeechagfgbcbbdbbajgjiegbjfiaaacbjijgibcbjibfhiddaajabgffdebhdgidfbcjddhghidajeibciifhgjefdaiabbhbjfbadfgiijaabbhcjgicdaafghiijfbdjjbabeghggbjcjhabadjdhjbbeffeebjfccijbiggadeihifffdgieaidbabcjhfdhhcedadjejihbajcedebgcjeigbiaccbhgjagacagcjhafbegfabdcdicbbfbaiefahgefhjedhciccdbcgijfbeeedfihjbcceeedecfichggaachecdjjejfjaccfiiicecdidgfghgdjbeaijaabbdbhifeidcafjbijgdjbffefeciaacbebbiheihigchfbajgaajdgeiaghidfdjgigjbcfgbahgbeaceiaiafhffbcgggggjddhaabjejddhicbdifgjjfidjabjibhdidgifjbibhdcibgbcihijiccfjehhbhcbgfjichhdadbdgbbhahdefhhhibgabeiffjfdbbaeafcfegcjacccibggiigdeddagbaejehigchabcggfedhadjicibcfgaiahggbbcdcdiiiecjgjagegajjcbebcjafhffbjdajihiffcaibbjjdjgghbhjcehegbbecbjhgjbihefjifigccbedfibifdebhejeiafgehdaibchegfdiejichejgacgbhjabhacggididbhajbejaecdijadbjiahdjdbbbeaijgfcdhgeeighjgehfeajgfjcfedbjeiffibcjhfihgafjdbbjhjdagibhdhjaiebiedagcicjfacgijijeeebhfcgbfiigieijfaagihbhcjehhbdeijadegehbcahfhbfccbddgfdehdfhigdfgdfdbaaecgjchcdjjddfeichigbfcehjjhfadjadbgajjgicdfjjbfcgbehedgijifccdfaaibbcehddfbffhggfaiaegbiefbgjgcejggejiifjjhiffiiaaciidfiibbhicjgeadfchecijajijeebffdebfdjeebibfcbjfefiffcbbdfahgjghjijbdaddcagdafbbdcffbcfedadfafeaihdgjdeficbaebbhjjjfieefbfhgihaehhifjghficjeifecjajihcafccdfejfeihigfidfieefefffjjabgheijfhfhbheafaadhdjdgeajeegcdhfjecceechbedecjecbjdegcaedcjfajicbdddefahhchjeifijbbjbibhbdgbjbeaechghadfifbciaigffeeeijeggfdjhjehbiihhidcgedidaeciaibeeaebbiicehcgddjgafjidjiaejgaeegjjbbbibagddeiebfgdhifbhjhehgbhggeicaidceddjhgggeefccjjbegdcficgfcccgafdeehedcbjcgdbffjdfiadbdebefibfgjdhfjcagcacaejahjcdcgbiidbdjjaieijagaicfhjafcghjbfeabadaaehdejfgjbdcejidajgfidefcjicfajfbighfdgjbeehghfchfiaiejciffcciijhiijdbdfaffgefjbghiecgefjfhccadhgggiefegdccdjajechjgeifihfbbgecaffefhidjaaaeecbbgiabaecjjgbggidchcfacebheddccbjfaafbbjgchhefjfedhcigciecbajfcgdbhjfafbbheebgbgfiajjieffejaafgajadbcijbihcgciejijihjdhihjchgdjabfijeeieibaahbjeaaccjhcfchhajcdcidgghjaefjbaabffdhggcfhgiiiifddjgfdajhhejfcdhjcbgjgjjbdibihjahjeggcgbeddjicifigaggdacddabcadahaddjdjdgahahgdddiadigeegebjbggggfjfcjbafbhcddfjgcibebefcfdfigjihecajjfhagagcfbgjdbahceffdjdjjehdejhgjfieeaecjjeegdifibgahiiaghiibghidiffddgjhbdheaicbbehcaicdbfiiggcfjcbfcahbifgahjhgddgbhbegcidhadcjiffjecaedijhcdcdijeaghbebccdaaaeechaaaifjdaedhjgeadagfejjigdjdafddfgaeaeiibbghdccieggbgicidiegjaejgfjgjhaihhgfcggefhehaajfjbgfeieigiaffhdghbchccdaicecdcjfihheihhagjhbcihiigejeacaecaacbjcfjfjcfahgfbgddaacdieghfcfeaffbjgaffediihadeiidcaebeifhheagcdajhfhaacecigdghhbfhcibigfhhfhheiddijhbejeaiibhdddifdidfjiadccfiffcddcfeaigaagjgicjjjbicfbjadadgjccfjddjiafbchdchidaddifgafcjfjhggagefafgggebfdiciajfgegehbcibiafehafdhbbcjdadcafefcaagajbgjehbigfbfajacdjgbdjgaabbdiibeagchhdcddbcdbfecbcfdcfhejfdhjjiibcefhjejeafghbccejehehehcaifajdfhabegcbbbfgcfejdeeaggbejfdbejgbacbieiejgcgabhfihajifiebbacjdhgichbediefjefcbahaeefgabijefjbciafjgiabcefbjadheggdgfdjhfbbhddhfcijfjbgiahccgiejffjdehbajjeejgfcgihfejgebbigcgddgifhdifedghahahjdgeijhfgbeibgacabfjhhighdjafdhdcacjjifdciebjefhijhdjbhjjdjhdhecbbeagefeihgbceffheddaggcigfeadacdabfidegjhieahbjjiadcbbbghefeebecedeffjdeidhgighdfbfjibfiebigfcbdfbjjbahbcgiajbihehbhddjgjgdagbbedeadebdbdgffgfheedficbfibihejbfiaddiahaihiijdfbjdbhhabecgfbgceebfhcgfgdcdbgfgcgibajdehfiihigcffjbdbcefijaigdgcgfhijcadcehiiigdebagjgfchiadafeigbbjbbgiegiihaibddgffhihbhjjjicafebeiiifihagcceghibeedehbdajciaiahaghjfeidjdegcidgeeicfhhabafijffcgfaicegafgfdfcjgdjbejfadghfhbifgbbihabdhgbcbhiiiadccddhcehchadcdgfieghiibheagcdcieiifeihhjjefcfdfbggjggbhfdehhgeaecceccchjbeegjcgahjiaeagechdigiecihacgbfggbcbcfafbgaiicgfcdgggdcfgddhibcahhjgdagdjiacabjbhcagcdbaiicadghdfcfhegahghchjicdejaifdfheiheicfcahjacgaeabciibjdiiiafjahabaabafeaghjggfbcdgdbbaajjadjachcfijcaihifdiefdedehijdebfdahcggieghjicjfjaecfieibagahjhfdadfgfdfgbfjgcjhcjaiccgjdgfehhgbaeeigefjdafghfibeadchaadbcgaiehafdcaedejifghdfiefjebjaghcejehaabhgiddbchceghjedgfgcfjjcgjgjhicififbeccccbjdbedabjgbcjdacgifjbihbcfifijhjfidccegegfbjdccdeggddhgdcgeffachhbgeeddacagdgihgiebchhfabjihfjadaiiiigddecgabdafgafhcechffibcggabjbghjibdjgbbbibcbdbbgefdbahajdbahbghehbbffchahcabiaegdbcabbhfgedcehbjibhhdhdghgchddjebeaifjgcaecccacjhcifgdhibfcggajbfbcieachbjhdaiegdjiifgaidbebdfdegiaidgcefhaddaaafbieiafhjjajgfjjggjjhgcihhhbjchbjhigfbaiggigefeefeefigijfiaieegdhbjchacagabhagjhjbdbfghhdfdadefegicidfeeeechehiceabfbdchcjhicdeiiadiefaeeiieceiafajedaabeejabaidjedijehhechhajiefebiddagdcgcdiaediafdfigfdeiffacgjhgeecgabagaicfjfdbdbbdhcjhgijjagdegieiiabiigdfigdfgfidajhbcjdhdjdfdfjcdfeegaafiihchiechfbeaddcgffdegaafcagajddhcbcgaaihgbbjjeahjdafchjehidbhdjbcfhjcfdeaieiiabggjagadiafifjhbifhgigajeaagegaafjjfjajgjiechcidbbchgcdjfhjcjeegdccfedijhddigbhaejahdbhebjcfdaefhaehdjifedicgedhaggicfjahfijegcegihbhjbajccgffbgbbbjbjcgjchjechbbdacgjehifegebefjcibcajejedcghebebfjheifcadiegcbajigfifhdddafgebdidfcagdedecjicdeaaaedcahfbhfhchjbhgjbjfcbibccbidgeghgjhbbaijgaediaefcahdcgihhibeehdejhgdcdfjbgddfjacbeidbgggjgghbgghcfgigdgdfheadedhcejjabbfiadjggdghcdehjbhdfggeefiefgjbebgifdbdgiaddjbddfbibbfdffechgebebbdddbcfhdhhgjfcadbcgdgcahejihcgafdffbbacbhfdehehajfigdfajiegdghbagdedibjejghijgfcdfbejbcacjfbcaafchjbadaedecheibcgigfabdecdefcafjbegacadaegcjbjjdjddeefbajdfiaegcfffadjcjhjhfaidjagjjicdccebedafehfhidcehcadbfhbcjjjjicahhcaahdcbebegicahhaifihjbabhjaaebgcbchgcfejgffabbgiifhahbadahjafbjfhfbecfbbjjhidjdbhbijgecebdedgjfgggbadgadifbhefdjdhfajbgjehheihfebhcefibehhhbffbdgdcedggagdcigfjcgdehheaifedehffbgifiebcjcebahchhgcijcgchdgfjdcjjfeajacjdagiididjgjajighhegfcgiaeceacchiedhbbcigfhecfdcbbegbbaagfgeedjeejgfabhhcbjeheiifbbbjibddiehedcfgffaebdfhgaajbajfibgggibifgfaagcdjieadciicgfebbjaigcfhgcbhchhbdagigdjabiiehcdjidceeciefihcdjfchbacejbjdbhdjbejaehbiebjhdgfeiiafaiaiafaagbfhhbceiichhjhdggeeifggeaibfbejgdhcgjigbdicfejdhghbcegeegeacdfijjbdccbcjecheacfbgfdaficfgfgdggccbigcbgdeidjaafdeefaadbdbjebcifijdcjjggijbbgdabibdhgachbhiedbfbeecefcjcgcbdddaffcbfbgfdgehajidhdhgjbefjjcdifcjdgggibiicbgeecdjeiefcajchcbediehggffiachhhifehjcdjghagfdcgcabfcffaaecefdjfehdicacgjadeheijhdjgeffghgjihgjcejjidjidejgfdfihehachdbjdcijeaicfadaejjdibbjebehcegaeegbehceacbbhdgichdgdfiffiigdgiebihfibjdffeidfbcegdebhehjgiiejafegcejhcgheecjjhdicededejhadcdhjegegijgfeahgjgggeffjiegacjibjhefjeafiagjcbgjgcffefhbbaaeieeddggijehfjghigahcehiajcicehhhfabbjcgachbhhaedbicebjdbfdfadbeihbgecajefdcgaedjigcagcebiadafjadbfhbabfidcfcdcgabafcghgfcfagdhhjccibafgcgagfbeiddcbjdhiidechchecbehfbhjifbfibggafciaaecdbdgaibagibacdjehjdjheifcjgheejaagjiajbihfddfhidjceebeajfehdabegdeiieaeighiigfchaifbghieiddgfjbjjihbggcjbjbiieccgjeccefciejgcjcgafchfgghbjeeeffgebhhgghdeijdaajebcedjgdcecfdhgfigeiddhcgbjcjifaedjbbgihfbdghiefifadahgabgecfecadjafffcgabadagddjjfabecjecccehcbagcaijcajhcihaachbfjefbfdddigieieiedaegjfcejbjaciicjhciifagjhigigahajgdfehcjbaffdbidhcchcafdeihjgcdggeiciffibjabcdjfcgdfaefjhdbbcigeddgfaefibbacfdgecjagaddfeedjifceijfcefjdhddgbgacdaffjedhafjidafagdejheadhgefggebgddgjgihbbecgcdgejbifbcccdgcgeijidfdahdhaijadiciijdjaciahehbghabbehabiaijaaeeaedihhijjedbeiifcdffbgcgccjigiajgfaafhfibhfbhbbbcecfcgbfgceifecdjabaaadfbcfdifiagdejecaigicjbfajfchieacdicjhjddafjedajhiecdaihiafeecaehdidbdbfcbbhgafibeejhfbceheieabjhjafdgjihhhdeacbgeieggcbcfdehebhebdefjgeeefabhfcighiiagddbbfbaghcfgehijcaechaideggjahdagheieebciabadbhaffdaejcjghhjiahhddddibcfijgicabahffeedhabdagihgghaacfcjcedhjiaedbgffecjffdbfbhjeghdcbeibhjihedghegihciidbfedcfdajdgbcccfbbffedjbciadibcjibdhdbaafggcagdiibiiigcgcjjbdfaaejgijdghchgabcdcfhijbeiaffacigjbdhccjjdjfdihjfaijbehejhfbjjagadgcfceffgabaeeiebjfdidgjfajhegjhieabaaacajidebafffbdaabccidfbjdfieifcdaabbagddgdieagecgfbhjfjbijibigfjaffgafaebgafjghiaigehhfbfhdiaafifagcjfefcehccefghjbigdjdghdeeiaidbbaeicdbfigafibcchccfhgbdagihhgjaiibdffcbeabfjjbbdbdcbijfecehcgejddgiaeaifhgebbeajdaigacbabiegigdbjhgigeihcedicifbgecfjfdidajfcfgbegfgejbeiddcgjhgfbfgijeahehjjfidcjbecfedejiiadcicchbgcebdjghcbabfeggjcfigffigggbggeiibdejefhajehejaajcghhciadjjfihjabbhbjacbifcegiahjfbdjjhgbdhbfehhhdcicbbgaicjehdiibgiibedfgecegibdhcicbgeijafegdfgedbfeffcdaicfjdgbhfjdjfbgffbfbciicgbcigjjbdghgedijfdiiibjcjejdhcjchgchejedbabfibhhejjcjfjdfafdfbcfdidhhgjdbhgehbedfdehdejjeeebijibcecgabgjjcbjfaaihdiiibcghcidabaedgjdiiifhehgejcbcjeechdaihbbeicaefajajahjggdgcecaiadagghfjgibdehfadaejifjhidjijffijjcjbbjiagbdhbdcceibhjgiegdhifgejidebiihjaccggcidcjcejhefgghfgbgccfabhibijdfiaihbffjbcdfhhcjdfgdficbicehajiaciccfjiieiggbheijeicaabgciagfcbgaeffcbddajgdgcjahcgehccgjgacahififcdabcbhhdiiidafbccchbjfaddchgefahhcfechiiaciaeedafiddbegbebaaiaggeihbbageejjjfdgdeeaddeijdebijhebbddjjjbdabfgfbgjhagihjibhdegieacdgdbggbhbefjdfcgfjaccdfdfddcfcfcfjdbiigabhbcedcijaabhijiebgjdbehcbjeaajbhbfggbjccjgdbhggjfhdafhhfgaigbgfjjhgfggdddjebhghiciededgajebddjacibeehhhbabbafbcadhfjjahgjdgicicdiagfeaiffgdjffcjcadhbcieaffehjbhbiafgjiddadjjadadgicichjdceghejhcchbggiicjgeeebdidagagfghcchffdhafgeiccidgefdbehhggehhbiajfijfeafjhjcjcbbijjegcdegiigffgbgfcaiceacajjajcchjhibihjagbbdbahhjjfajfeehbedjceidaajdacbcdgjgjeajgebegddfacddhehcfdfheddddchccafadbjbcacieeiibdgebjjiidjeaibdiaiiihgifebgaabhbejbigfgehefeihiejdjehcaffhchicejaccffgihiiiagebdaegcgfhfjehidgbadjjchffaiafcjjgcefhaeafdhddeafaedccdhabeicjjbeaghciijddiiiegaibfdedjdaaaeccfcadgdcedbdiijdchbbcbedfdidaafiijidfgbfebfdadbbbchihachhhcdgjafaicjjhibfbibhcieddafgbcafjgaehbjbjdaaigeeehfhaahejegddjcjchicbjhhhbaeaaiafhgbbgagcfhhbdhfahffjieiididadjihgdjdjifiiedbbdcgbafcdgfdecffdbbfgejjddhiccagcfhchhdjhdiggjbceheejaejjfdjidediidgibcjidfiicbbbfhcdjccijcfifjjecfcddbjhiabijjjghcabjibeiadbcgbiageafgfhdicdgcfbffdcaibeajffibjhibbahdcejieedeichjccaibjcagffgaiehceaahgggbhcgfijdccfjijehacdiefcjdghjbehieffdbdhhijhdhcdagiiaahhbhdegjggadagcbebddjhbcfjdhcdiegfbigifaebbbdcdaefdgbfjibbdiiiidfbeahhjhegbebjbagiiejgfibibefeecdcagehjhddcbaffeciidahadeefjgaeeiabhegjfbajbbchcggjihacgiibijifcfcibachddcfhjadgihagabhehabchiachdjbfbgaebcagfefaeeaidagehcchjbbeajbihidfcaijbigeijdedfeahddjccchcafhcfhgaiabfghgdbjgbgdbigiahacjhicgbafbhgecfahaecfaecjicbiadfcacecaghcabedjaigcdabdiffafgigcfjfhejgiijbecbcdbfbjjcijebdjedbajabicjieiiaiddegdeiijccjdgcahhhjfiabdbbgjaaaeacdcgidcieiafhbdfhhdcagdhiegecebccbeehfchaaaafefieiccebgajbfhhiecjfghdihgehdidfehidcfhahabfachahigjfibbbihgebjeidhicaabigfjgicehfjabfiiejifdaihbhjagihfgfjdbibaejiaadiajidbihfadgggaaicjehghdjegjafccgbdhbjghghgjcgjhbddaacdihiiaibehdafjbfhjgaibfcbeihdjhbdfaefdjchijcbedfbaajjadebbhgdefhhhcfjjgiacjgbbggffidbjaajbeicjijahdhegdjagidafjddadaadafjcbcihjbjcghhfghceafagcejadcafdecheadajccbeccaifdfghjjiciefheibjccejafehjffdfaghcjbccagdhfadjafjbjijfhbgfjabajadehfifcgfejgibgggeifbabgaefcaeehfhjiebhaadaeggajefajdciiiiahdciihfcfigcdeaaiibhajihadecgfdedhaffjjbfgieefdjjachbiidjbfiiaejbaiehdbddhgeedjiegfbdhhehjjfadfiibchdcdfghcdfjfbjeaefjejfacedfaebchffgijibjbhdbbjecbbcdihgaabaffhdfihhagfjhdicfidgididifcijegeadaiadihccciigijccbeagheigjhbhcjghigdhjeigaafffceebagjgdhaijiaghcfibbfdecahjaijbjbjbchcfdfiaicfgdebceghhhbchhhgfijgbjdebdgfebbhijhjacejjbagaiecfiicbgdadebddfgibefdhcibggdhhebffedfadbhceddiaeggjhafieijhhaeedjcaccachicdffjcgbdaaeaifjgcgjcigciaaidjdbjfafacdhdfdiicjcghhddebfdgcdgjacbcjjhjecdfcfidhcgfcdcdehjibjecgcejdigfeacicjhiieifefbdficiijfiaacbdffgfjdbhbjfagadgeagjbaigdaaifdcjiefijcicchaidhhjdgbfffiibhjabdigchebcafjedjigbfaihebecgafajaeecdccdgcgdchdbjdjfdbejfdjbbedaiehadiheiiiehcfcdghbbgddagdgcdcifaiifdhggbfjjajebggjehffgajeggffiifdabaeigjieefaiiejggiaegfdchibeccbfjeaehcdbiedfdhjgbaffgjadgggjhjiiadgfgidhbcjbccbfahdgfajeahagjddeefgjegggeaaifbiihbfiejgbdhbcbhjjchdbeiagjbdbefjigheededbjgbggbbjjcidjjbcdfcagggffejdeehijifhicifhcafdgidgcdagdhjecgjibdbefihacfccaagebghjeajgghdiejhchccidafjdjcbibficjigbaahjcbeccabibihhbdehjbficcdjdfaciiagagjcajaifgeccgjcaehcgjjcacejchfdhjfiahfhgejejegcijciihghfageiedbibicgfidghiiicghjdiagigibgbbgfdbcfhbgaehfhjcfhiihajfehbegfiihhfdjhjhcdabaddejaifheifhjehggejhcfcfeidhbcabdhejcbjcbajhdeffdfeifaiihfebahjecdidjgbebjciagaihffjhebjjbeihiecbdhhgdaffeefecehgdebbhbfefbjhdfiabhdadhfiehacidciaccehegcffhbfbgdidagjehhddjcbbeeajcadhcbdiigdfehggfibgdgiejdiiajagichcdhgjcbhjdcdeicgahcahbbfbigjgeecijhjdfjeadjgddghiagfidjjeeibiihjibihejahcgjfbgcefffcgfgddabbbcbecieadibcfajjgabjbiefdhgdiajijfhebgihecdfhicbbhbhcbjbiggcjgdajicecbeejjbhiddbifdfahjffeefgibeedgciicfabebefjcejbefgajddhehecdeefbajgejifghiddbjhfegdiachafefbidecggacbjjeecfhiibghjegbbdagafggjbhfcbdcbcddceifjjddcieadcafbjfiihddbbfjifhjcgaefgbbacdgcbdigdheaheaejdfiiahedagidbhdjbdgjjcjibfcchchcgeaegfbchdcdbhjebbahjdcijjfdfhceeiidfbiicadgebghicgeacegbffdgfibebecdibhbhefjdjjcghcghbcdeejbedhbhdaabchcdgfcagdebhaifbjjgjdihjahjfhfcihjeafdafifhifiejcbhgieefffgiehifdaegebafjfhfcfhjdbhhcgeaeagbhjdhahhbgdcdjdfcgeedhfiidgcjciigdbhadehdgejhjaddchbecjfgcdeabfiieieddhbecddhaebfbjaibhhigichbcgbdcejfidfdcjddbfchhbiejgajfhabgefbddiaijidhfcgchihhaaifjihdibgaejffjejecffjahiahcgibgaccahhdfgccfahfjcdcigfchcgjhjjbdjfjdhbhcfafcejbgghaijaejjcgbgcghihafgcgggebgajdicidcdigbcgeadfagggjebgadfdgfiadabhdaediheaceahjjfaghdejchjeegfdbgjhihfcbaebffhjbgacfdjfbjcefdgjcijjgaiihcgifbcedddbgajccebhaicbecbedbaegbcgcgjagihiajbecfecbcecacdeihcahhgjcfgedihigbhjchcidgcbhjhfbhhdhbigffhihgadeaeeejidbeeaddfdebcbgbjibdhfbjebghjjgdiahebaajfifjfcidijfefiieceafbijibjhgabdbfghejgifggcjdjcfbehbejhcgeefidedhdicghjehdifeehdbgaecaadcjgfegffjicehheebihaddjjbgbdifaajcdgacdcehagjabfjdeheihgbeidbeigbjgigigefgegigahebfgigcjggjegejjbcbejgejfdfhhcbffaaehdghfejjjhbjeaagchcicgiggeggghjdeghdeaibbeedhjcjhihfahghibdfdidjghjiaagdhbgbcieddbddggjaecghechejfahgigajdegdafjjgedjjbieheeafbhaedccabjhfjfgfjijhabeaadfacgedjegjhighhfchjbbjejiadbfajeeeiabddfbeacijifbigjajcjhcaagjjabggcgaiejiihadjigaiaigjdeiaefhhibejfhcgcajaceaecahehegecgehaaihjihbeaedabaeecbhegeiihefiihbdjaifdfcidejhibecibghjhaibgeeabbiedcdfijeaecefghccagifejadcjggajibjffcegjgejhfbdhfhecgdjfdabgbcjgabgibffeaajchcjgideaigjgcchdcdidibbehjjhacdifajiccgdfgfedcdccceiejiaadijccfhhahjdhgfhjhcgehhdbgfdjbdcjddecbegiabgebdhgadcfbadbibjdjifieidjgedhcebjjaajeadbgacjcdchjefdbfbfagdbagdgijfdejedebaffgfbddciddcbhbheiifahdacgfgchifbhbbbhgijgdhggfdggghhddjeadjaiiffehhijbhehjfifbjfhbcgiijhdagbbegfjfdeighfeiifcjcfdgaiijbejfaahbieicdchacjdgdeeijhggcdgfejeffgbgcdhdfjcaajdjdeaghdigdhaeefbjifggbajadjfgbjagcbiegacbbcajjjhbcaijgcccdeiaciegcgcbahdahiibjdjehbhcbfbahjibgacfehgjjadjccdjijaddcdgdjcbbhjbidehfgdidbidgjicadddhjigeedafcbfcbajefbheaagbhdjfjhbeiibiehbejfbcdjfiaeaadgegdcffifcffjgjeibbcfjjbjgdjjabfjgbffaefaficgeiihcjbcaacbefjagfadjgjfdjeghgagifdibcahddejffggfjaijhjifbgdjabhdecdiihjibcjbehbggbiibhadbfjhiadbgjfaeiejhggigjfejfgfadcchhdghedjgcaajbijhagbicdeagcifibdfgbdjffcadahejjicfgjfgfbfiechghhaejbjbhffecahigffeiffdgjdffhbccddbjheeehggijeagjcfajjhibhjefjfjabihgeeiihegjhdcjadjccffgaejchbeeghahbihjaahggjacaafbadchifiifcfeidbiggaggfdadafdigedbidbfcaaheeffdhiachiaddidchbibifaccjbjfhdhiabfgeagfdjgjbdcegdjihdgcaacjdeccecjcjfgiggafeadjdcgfieedaihcjdhgcageehecijfigadideahejbfcgdfdfiebbfgiegcaacgdiffbdjeghdhcfhijcdehdgaghegjehghjhaebbhcifgiehhdggdjbcjbdefhgdiejbidebgfjdgjfcijajbeajhhdhfbehgfgdahhhbedcfahgbifcebfhfhbhcdfddgdjaeajdjegbjchfiahjhagjjhadgajfbhacbbjgedbaibbbfiehjhadhfgiahbciaccabjaghdiijaebdagebbighjbbbbdahcjbcegbcihfaeehjhgdfdgbbfgbbcihhdcfbhfcdeeidgfcfaididdchccdhdjijhbjfafgjdgdgigfieiecbcchhiheedhjciieggeagcgahffcdajbgdbhegdjidbdidjhdadfhebcaccabejbjggijaccfjdibfcdhdahejachcifbbdicgdjafadddgjigdjggiijhafghcbhaiebibfjhgdchhjeiebcggccaaicggiedfdcafcgaffadbgbcibdhgedhdjejhjcebbbaecfbeegjdbaagahdddeahdccefafaibeheagiaifdhbfbhhaebfjbdjcahgfhhicghjbjfbaiaciigjbejhigjfdgegchjgaihhbibihfifedcchcaaefbibeicgdjjijhgecifhdedfeifihjechccdjdbaibddeieiggaahdgdgcjgichgibhcbcjhddegdahaehjgcdbgbdhdbbbejhjchadfjgcefahhchecdbihgedafaiegjcdfjiedhfjjbijcgihbeahcjebcdchddghgiabgbhidjacgbigbedfgbhghaihhjaijchceibhabchdbiddcddffaaiediciejebjjgbjciiaehdhcijiigbegdihdgjjdgeiafdiececjfdjhfjagcjdiedjjbcacbeiaggbfibfgfficbjgddghacdjiagdegfdgehbjdgcafgahfieegjgfbedidcejhaieccbgegaecfeifaehghchdffcfeagdgbcdjfhiieabbgjecfiefgecbcicbcedbeeffidihciijbcgibhddiajfachcefejdbjeceafeibdhbaffjijjihbaafbhjjfejgagehefdjfbaeaibcgcfffbhfcfgggjidbafbdhfcahbbhifbfdjcjjcaigjgdgdhgfebhfgjhfhcjchaigegdfdjgiifiaddebibcchbijficefhijafhaggdhfcabcafbcijbcjebhibbaigcighfjcdabdggejbdjbhfgghgjadfbgaiebbbbbddcdacaheaggeiidecejijiccfgbjabhidfdfhcebcgcebjfegcfdcbjdbbdffjfggbdhbibecgdeafijgdcbdccihacfebcijfijgabhgdeecefejhdehifafhbhjbheahgdejbdabjafebifjbbadcecgjeaejhdhciaecjgibcafdiegdbdhbgjafhbegefdahajbbcjbbifaajeggcdfigjdaijjfjffgcghbheaedihaedcdbdhbgbedfcjcfdiigfegjjhfidhhghbiiggefebaedfagjcccjhcfdgibbfajhdgbadecdfaabgbcagfcebjdcifgeehijdggdgjbffhhehbbhdbaihjeffaigefhdcahcbjegcfeifgfgagcicjccbhdgibegjdejjabcdjcahdidhjghbihddcjadbhjjjbfcighggjigbcdfjjhjehdcdeiaagaiffajjbegchjgadijedgffbifeifghejcgcghigfbaffigdiihffghbcfbedicdhcgigheeadcaafbhihjgccjaiaaggfaigcehggghghhifgafabegjgddicbhjhhdcbdhdhadbeeaaejaadhdghfgacbhgdgdbifabjbigifcfeejhbdeggejhidfaegacajgiebcihfafheejaijecjiahihbbfcgieahhbbgedeihjdhfbhaeghbgijjjaeffceijgdahacgdidbjdgifaheahadfbidacgjbegadigihegjfifghbbjgcihafdcfeacgibigfbjfjdceeedjehaaggjehbdfbiabigaiajfiigcjchfaaejjjeccgjcdgaihdgcbefedgchhdgahhgcaadjaehbcdaeaciajfacfafabeihbahjcejcjjjebhiihfeihiahjcddfbjffihifhibjfhfbcdaebgieejfbiiiiaieghajbceefgfjjfjfgfbffhhgcdjedjgajccdggdjcegbidhgjhieieijjiggbafgfiahihabceaejegddcfeecjjiiigbbfaifafeeffcjcgefigaejfcdejffiiaggcbgfdhgjdeiadebfdfgcbhffhdjefjfagdfeghdadjhbjicefefgfibjajcdbacjjdfjgdjjhfehjfbighjddjeccdgiiahheejgjjhcajigeabhggfdhhfejjbaedaddhjcdjedhgebidicgecgccdjggfaahbdgfgchbjhgdhijhgbijchddegbgigdhbfjediegfebdgcdiiifjdaggabegafgchbjfijgeidacdjbjjhbedafigebfebiiadcdjjjagaibccaggcgdeaicbijahichchcddidgaidachiegddcaejejddiigfihfaifgdfddbfaidcjiaajifgjfdddhejiijhchecdbbjchhfdigdhadbeifcghghcchbfbacheijbcgejbhccabdccbfgahhfggjigdaccefjidhchjigjdhgcchigheehbcjgffigfjfdfbcgfghhaghdciacjfidgghgdcijcgeiecggbfbjihfdjjdifbjahgfgjjgjbjcdcghfaafbjjjjcbcidfgicbjedjdbegadiefdcicegjibicjeajcjcciaigadbgbcehfbbdjidccddbjegebaggjcgcjfjfafcbiecggdebfhbajeagifaeaieabbbddabiecdcdeeechhafachfcejggcbbbhcegjbbgccfhjiejhfehcefbadgjeffcjjidecgahfdfcchejijajebcjfcbbifihciibccgbcbjbbeahcihhddjhcaijdfabcejdhacfcgjiaceiaebdfgecfjchecdgfddcjbcjdheeeahbfjajdfdfbgbfiaddeebehjjjagjbeefcciahdgebfajbafiegjideahfjibiggajgejcedgccciehhefehdaejfefahbjieadhcaiahejeeegbfddbcfbdcheedadejeaejhhdachidbgbchcbgiiegghdiihagighdhjaaccheeebaagcjadfbjjcihdjfcchdjcjjebahighbcbggbbbhgibfffcjgjfdafifcjhbafigdiejajecafajhbeiiehdcjbhbbbbcffbdffhdgfjjiiihihdaeidjifdicjcgadgccfjihjjhagebibgjbbhhbjeddjjejidcchjidaaddbfihffigifhcecihcigjaehcfaffedbgbjajgdjfcfifcgdidcjccgieaiedcacgegebhiacicebegbjaidcjfggbcdgjhcfihgcibcccejbicigbccgigdhfaabgibigicddfbegbbhjeedbdgedcbbibgfgcahajfbgiheffdeidcjfbefejjhcafdjfjfiifadabgeifchfhjccicdfhghidefafcadiiibhhegdjhbfbddceeajhbcbhdhihbhjcdbghibciceghcejidcghcihhadibddficigbgfbijihcfgiddhedbdfaggcbebihhehaahicjfegffbefffcdbabececiacihaedbdddaddgjgejgdgafhaedbbfiahajcjdajadbcghhdejajhafjgjjhjbbdbgcacffjbcbiaciejbgjffjaabhjciibfdcecaffafifcihjdgafgiijedadhfhceiechebhfigaageadjhheafihhgachgcafeedahdiaehiheiffijecjahafadfejdbaafgcedacigfeibjffgbddbgcgicaeehggihgiidifhhigeihccafehacacdihbgddafcaggaifdcbgbeijfdddegdgjfcidbjhcfgeffbefdhbehagjahgbbhiicdcfijjifdibfadeaicebdjeddichdghhijbhiaedfeabebbagggafeaiahggjacjbhjdcgcgfjbcjgiidddhefcffacdafgdgbegfbggbdihgabagdcbfcfbebajiefbaacjiiggiiacaafcjecabibaagfaahaggbjadijjihgbhicjdjgjgahafiedjegdabecjaajaeegbcbefigbhahfhgcdiddchjgaacehgjdhaehbjbjiieaidefiajafdgbadgedabhiiffdhjeibgcagafddahhihfdejeaaafgaighdgaaabcadigcigbdadbedcefidjacjjhdbedfehijigchceifefgeifihccbegbcfgjgabcegdceiahbccajgejdadjdajgjjhgfjgahciiajjjijbgfffffjbbcgjbaedcjjbhgebfjgfgjjghhaiaajehbcaieeaedgfehaajifigffijefabaaebbcedbbjebbcdhceahcdgbdhgebifbcaghagfcbidgfeehadbfhggbfdbcciggjfeaijjccfceiaijafdfagjadahjeabfhccibhddcjieijgaghcjcjchdjfjgaadicghjgfajcabajbhecgajbiiaefbbjibfgjedhijachhfiecdbeedhadcdiihdhccjaaaigjdcecbfjadccaejjbhfbibceaachdcdgffhjfdichgffjgeajgjdbjfedgceehafjbfdbdjieceifbaicbbjgddajihegcaicbcfhfgjajjgfbbhhhdhefcfaghhfhcifdcaafiifdcgjjccajciijideeccjbegaahjehiggadfijdefbaidhebfcjibcchebidbbffdiecbfiebedcjhaehjbcgjcbicibchibbdbhghhdjifaghifefgdhcdjcabgggcfhchjadfcaedbjhihhhgejdbhfbhagaifabbfcdbiceaafifddhjaciehjdeigehiagaaebfifegdecegbccgecdcbajgadajfdgfbjdcbafijdhdbabgajfdiagagfdcdchbagfdeafehhifhcabfciechjfiagdebadjeahcadfcahaagacjiehahacejaccegfhghiggfibfbhfffidbahcijhfbfdcciaajgjjjjadjjbjdgcediahhhjgcjhfddejfjbibeaiebhgjbjgigbacdiihjgcbegdgeibihbfffccfgicgifajafdeafheiigddhjaiieibhdfidfbbdbgicajeeiecdidhaibfaefbhjfadbfaadbhafghdijdegchegfigaaaeajcjhjdfjgcadbhdibhfgdffbeeggjdjdcbigfgheddhhcghficdiedciighdgaidfgbchhabjegfjddhegigbcadedihcbfdgajdbjjiegbicbhhiedhagccagcbdhhbgbfihiagefhaiaaigiaijjdabhiecejcbciajefggaceheiiaecdechiaefdcijffdfgdchedbbdhciiadaebbdgdhccfgdiaggcgffaigadecbiecbdhfedaehhbaejaeidgjdfacehaaeicbifggjaacfgcjgfjhiaeehahdicbfidgahehchfigajcbafahhjbhihfhcgdhihbijidahfgfjeiiabhagdbgcdffhajcdchjdedeeabhgecfgcbfccabgjbhdjddfigbcfachhdebajeidhjadccheadfjdgjaagedahhjefidfdciheechciebgfghaihhdhgiieaijgbfdjghejeeiejchgbfjhijfbfdjhjbbhahcecdcjidgggfgbdjbdhgeacdgbfjbhbeeegdgceigjidjhbbfjaggbbbjfabfijcefbagbjdcdiigbghhgejhacjecahbbbicicedbigbfghbhgbdjgceiibijhgbjbejifhjcejdjhaeejeghedjhibihfffbjbgiedcafgebaadgccbabcgfcjgbigfgfjahcadibffgfdjhgbgjcbaficgcihiehghhgggejadfghhebhhdfgcgcaacdedjheehdbddacgiijaiaiebbjiifihajhgajbififdcijgfcbgieidadiefhfefchfbfjdadibgcecfbaejjhfchedcgjdeggfjbebiaihihccefgibdafgfddhbgeghhgdcdfceajfbfibeieehbhcgjiddghfgagchefbeaegfbajcihjbihbgcgfgfeaegebbhhfcgcfahjffifghhhbbaiiigejcjafigcjbadjefgafccajccjffhfgcidchabfbbfiedcgcdbaiaaebjcjjfdhjaicbhdcifcdbfhhgcfabijciedhiejeacjhfjchddcjgfibghijcdeehbjcgijgfdfaedbeiicbfjjecfhebdbhiiefcgcbcbjbhhbcgbdhfjejaecibgbagcjjeffjbcedifbdddifahahgebceacbjjgacgjbhhchgecbjhiegebdhadcieegjfgaigfaceidiabhifghbjihjfjgjjafabjcigchjijadgiaibghfhgjjfdffbfagaededjiifijeggaffdbgidhacbeheajjeiaeigbihcajcbajchhdgdccbccfecejbbfhcaghbagffjcjicdcachjggdcdjhhigbbffhhbjccjbfgdhieaadfhgfhabcjfhhafiacbeaaicigcdhecchiebcaajaiedbghffiacijfebeahgchhheecaejdcibefbjheidhffefbgfieibaffgidifabghbifhfbcecccjihijecffhjaggdbbfffejfeihdjdhiidbaehaechhdfidggjicfahjiigfjgahjebadhjbjbjcacjehfjjfhecffighjfdjdchjdijbcibddbgdeffhjaccigcfbeihciaffifggbdabbbgiiecfcjhgedajghfbhcheecejegdeheicbdiieecdfcidicbhhdgddcfeiaajefjifjghgdjfgcijjfhihiigicdcjagfdabcaehajeaebcchbifbgcdbabcjhbjcegihefafchdgeabgdcccjdgidbibdfaifiejjhehdfaecifhghhjacacaijeajcehbgcjadcgigddifidfghgcbecaeidcfagjcbbjaaccdbacgbjcciadceigfadajgbadcchhgbjbccedeejbifjjidcjbaegcdgidigffcgedaajjffhhajeiiiffcfgjbfdhiccddieideehejccjefeidfeebiighabiehdehdfggbjcdecjfcffjbggbgbfcfdahccigbbibejbjhjcjdcijgebfiafiibgcafecegccjfcefddeifheddeiahcbicbafgcbhbgcgcijjbacdigicfghifbaddjheeiiicdfjeeejhaibigcicgecgechbhbffhfgbdbgjdcdhijibahbggagejccjbfhfhdcjcdbgbehigbbfbcfcdaeadggjgaadjhgeicefhahiafbhgjaajeibbafhbeifgfcgdbhjcbbjbiifhecgfcbjdhjhhgdjdajeeebghgjcbeegbciddchihcecjbdebjiaabaiidccjccchecdeeffccgjajfihibiaagihbjbghjfjdfbfeccgdgebdhbefhfifjgajabjdbchfjiiaihecibajgicfijbgfebbeghdjfigfbiadefccfcgafabgbcjgjjfdahhjihafibcgacdcejfiffihbegcggadeegfigjhfcgdaidaefaicgddfcdibdbifbjbbddiahghagjefdaegiciihheegjfhgebhfiddjaaajgagcafgahgagjijhfagiabjiiicdfjejebeegbgbbaifeaeghgeejajfhibgggjdhdbfedeadciheggjbdahegchibffdbhdfbhgcddebhafjicheghgcaajgjjebcceahabgigbgadaeiejfhfcgjfciidgfafibijjiadihffdciiaeegacjiiiijfdhbhfbbfabigigehijeiidieeedaahgcgeeicgaccffcaabhgbjgegibggbcbhebgcahgicfggghaigdehgjachfihcbaifjgbafjdjfahcecehcegbaedidggadbjajjfeeedidgiaeffhcaagabdbhhfgbjafedaajjffdagejcfgfgbdbijcdaiaebcafjccicjgcdbiehcbieeaeijdfiiaecceiijjdcbgieggciiceeeahgjacffhcedhaajccidfjafdigbbgcdchibeijhccdccciffjedcediehcfhffiageeffdcgfihjbijghaififjhgheabejghjgdjabhjgbigffbabicfbbgadhbccijfijgjfihfgjeccjjbdagjgchdiggefdhhcafaajiccdhidjgggadfehhgecfgdgaghhbjdhcdbabhjdcigbedcbgbhgdahhbebaifeecjhcjcgfcjehfghigjjagaaceccjcifeibbbcjdcjbdiibdgaacaeedeccgabecbeigdfhjajdbaibffjdchedcbbgbbaaffeaifejdeefcejdgdhhjicbdcdjigjccfjccbhefbbggajeahcidfajaifcggedbihdcacbbjcecdhbigjdifdbdhdbafeifagefhjjbifeaagcjicecaagehbcijegjediacdhjagcgdjihihicefdhjcadcigicfadggjfjggbcbehgejfjgbeahbjiabcgehficcagigefjbjaeiddjjdaigcbbgiiebhfhbhbcghgcefgjgjeaabghhgjdhicedfcgfdiajbedcbcfeiaddhagaaccdciibebadgbieagdgefgbgeeagefaehcbeichhfaebgbddgadcbghcgeiccjcciaifbegegfjajjdjdcgbhcjcjgihcjajehhbhjjdighdcagafffgehbbedbaidegghfgigidhijcbdgdcadgcefebjagdhjfeabbcjbfdgjgcdjfgfjdffajeaeddbfbigddjibcehafiedabaecdedfafacbgdbjiigbdefabdhdcbjbefaeedhchbecjifgaggcjjafchdegfdfgjfjjjjcfaiaddibebebfbbebdiaacgjafcjjhfhhfgbdbebbgajcffjcgabcjfeehgadhcdhbifeceiheiahajchhchcicbjahbbbjidfdahhjcdhibbddhbcbddjcchfdicgbaheabjefjgdjeddeiigjfccgdajdfiibbdjgdfehbhhcdejjfdjacffijhbaihfjddejafbfaedfefdecidjacdhheefdcdbcfgibbg"
		;
	canConstruct(a, b);
}

/*
判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

示例 1:
输入: 121
输出: true

示例 2:
输入: -121
输出: false
解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。

示例 3:
输入: 10
输出: false
解释: 从右向左读, 为 01 。因此它不是一个回文数。

进阶:
你能不将整数转为字符串来解决这个问题吗？
*/
bool isPalindrome(int x) {

	if (x < 0)
		return false;
	else
	{
		int temp = x;
		int k = 0, dest[12] = { 0 };
		while (temp)
		{
			printf("%d %d \n", temp, temp % 10);
			dest[k++] = temp % 10;
			temp = temp / 10;
		}
		printf("k = %d \n", k);
		for (int i = 0; i < k/2; i++)
		{
			if (dest[i] != dest[k - i - 1])
			{
				printf("false \n");
				return 0;
			}
		}
	}
	printf("true \n");
	return 1;
}


/*
字符串相乘  -- 小数据
*/
char* multiply1(char* num1, char* num2) {

	int n1 = strlen(num1), n2 = strlen(num2);
	int i = 0, j = 0, n = 0;
	int sum = 0;

	for (i = n1-1; i >= 0; i--)
	{
		int t = 0, k = 0, s = 0;
		for (j = n2-1; j >= 0; j--)
		{
			t = (num1[i] - '0')*(num2[j] - '0');
			s = s + t * pow(10.0, k);
			k++;
			printf("%d %d \n", t, s);
		}
		
		sum = sum + s * pow(10.0, n);
		n++;
		printf("%d \n", sum);
	}
	char * dest = (char *)malloc(sizeof(char) * 12);
	sprintf_s(dest, 12, "%d", sum);

	printf("%s \n", dest);

	return dest;
}

void ID1000()
{
	char *num1 = "123456789";
	char *num2 = "987654321";

	multiply1(num1, num2);
}


/*
121. 买卖股票的最佳时机

给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。
注意你不能在买入股票前卖出股票。

示例 1:
输入: [7,1,5,3,6,4]
输出: 5
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。

示例 2:
输入: [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
*/

int maxProfit1(int* prices, int pricesSize) {

	int i = 0, j = 0, k = 0, min = INT_MAX, max = 0;

	printf("pricesSize = %d \n", pricesSize);

	for (i = 0; i < pricesSize; i++)
	{
		if (min > prices[i])
		{
			min = prices[i];
			j = i;
		}
	}
	for (i = j; i < pricesSize; i++)
	{
		if (max < prices[i])
		{
			max = prices[i];
			k = i;
		}
	}

	printf("j = %d, k = %d, min = %d, max = %d,  \n",j ,k, min, max);

	if (j == pricesSize - 1)
		return 0;

	return (max - min);
}

int maxProfit(int* prices, int pricesSize) {

	int i = 0, j = 0, k = 0, min = INT_MAX, max = 0;

	for (i = 0; i < pricesSize; i++)
	{
		for (j = i; j < pricesSize; j++)
		{
			if (prices[i] >= prices[j]) continue;
			else
			{
				if (prices[j] - prices[i] > max)
					max = prices[j] - prices[i];
			}
		}
	}

	printf("max = %d \n", max);

	return max;
}
/*  //别人提交的代码，时间复杂度小
int maxProfit(int* prices, int n) {

	int res = 0, buy = INT_MAX;

	for (int i = 0; i < n; ++i) {
		buy = buy > prices[i] ? prices[i] : buy;
		res = res > prices[i] - buy ? res : prices[i] - buy;
	}
	return res;
}*/

void ID121(void)
{
	int prices[] = { 7,1,5,3,6,4 };
	int pricesSize = 6;

	maxProfit(prices, pricesSize);
}

/*
917. 仅仅反转字母

给定一个字符串 S，返回 “反转后的” 字符串，其中不是字母的字符都保留在原地，而所有字母的位置发生反转。

示例 1：
输入："ab-cd"
输出："dc-ba"

示例 2：
输入："a-bC-dEf-ghIj"
输出："j-Ih-gfE-dCba"

示例 3：
输入："Test1ng-Leet=code-Q!"
输出："Qedo1ct-eeLg=ntse-T!"

提示：
S.length <= 100
33 <= S[i].ASCIIcode <= 122
S 中不包含 \ or "
*/
char* reverseOnlyLetters(char* S) {

	char temp[100] = { 0 };
	char *dest = (char *)malloc(sizeof(char) * 100);
	int i = 0, j = 0, k = 0;
	int length = strlen(S);

	for (i = 0; i < length; i++)
	{
		if ((S[i] >= 'a' && S[i] <= 'z') || (S[i] >= 'A' && S[i] <= 'Z'))
		{
			temp[j++] = S[i];
		}
	}
	//temp[j] = '\0';
	printf("[%d], %s \n", j, temp);
	j--;
	for (i = 0; i < length; i++)
	{
		if ((S[i] >= 'a' && S[i] <= 'z') || (S[i] >= 'A' && S[i] <= 'Z'))
		{
			dest[i] = temp[j--];
		}
		else
			dest[i] = S[i];

		//printf("%c", dest[i]);
	}
	dest[length] = '\0';
	printf("%s \n", dest);

	return dest;
}

void ID917()
{
	char * string = 
		//"Test1ng-Leet=code-Q!"
		"KH^,tteaTRgL$`P.n/C*11#!A$zVZU;8<b!4v`X%ypk+#'CpJc2)<0%^z0v+oGax+>@A:53dKo#,o5FT*Oz`6fgSpaDvzU:u$0g7"
		;

	reverseOnlyLetters(string);
}

/*
13. 罗马数字转整数

罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。
字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。
数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。
同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：

I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。

给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。

示例 1:
输入: "III"
输出: 3

示例 2:
输入: "IV"
输出: 4

示例 3:
输入: "IX"
输出: 9

示例 4:
输入: "LVIII"
输出: 58
解释: L = 50, V= 5, III = 3.

示例 5:
输入: "MCMXCIV"
输出: 1994
解释: M = 1000, CM = 900, XC = 90, IV = 4.
*/
int romanToInt(char* s) {

	int d = 0, i = 0;

	for (i = 0; i < strlen(s); i++)
	{
		char c = s[i];
		switch (c)
		{
			case 'I':
				i++;
				if (s[i] == 'V') d = d + 4;
				else if (s[i] == 'X') d = d + 9;
				else { d = d + 1; i--; }
				break;

			case 'X':
				i++;
				if (s[i] == 'L') d = d + 40;
				else if (s[i] == 'C') d = d + 90;
				else { d = d + 10; i--; }
				break;

			case 'C':
				i++;
				if (s[i] == 'D') d = d + 400;
				else if (s[i] == 'M') d = d + 900;
				else { d = d + 100; i--; }
				break;

			case 'V': d = d + 5;
				break;

			case 'L': d = d + 50;
				break;

			case 'D': d = d + 500;
				break;

			case 'M': d = d + 1000;
				break;
		}
		printf("%d \n", d);
	}
	
	return d;
}

void ID13()
{
	char * s =
		"LVIII"
		//"MCMXCIV"
		;
	romanToInt(s);
}

/*788. 旋转数字*/
int rotatedDigits(int N) {

	int sum = 0;

	for (int i = 1; i <= N; i++)
	{
		int f = 0, n = i;
		//printf("%d \n", n);
		while (n > 0)
		{
			int t = n % 10;
			if (t == 3 || t == 4 || t == 7)
			{
				f = 0; break;
			}
			if (t == 2 || t == 5 || t == 6 || t == 9)
				f = 1;
			n = n / 10;
		}
		if (f) sum++;
	}

	return sum;
}

void ID788()
{
	printf("j = %d \n", rotatedDigits(1345));
}

/*
930. 和相同的二元子数组

在由若干 0 和 1  组成的数组 A 中，有多少个和为 S 的非空子数组。

示例：
输入：A = [1,0,1,0,1], S = 2
输出：4
解释：
如下面黑体所示，有 4 个满足题目要求的子数组：
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]

提示：
A.length <= 30000
0 <= S <= A.length
A[i] 为 0 或 1
*/
int numSubarraysWithSum(int* A, int ASize, int S) {

	int i = 0, j = 0;
	int sum = 0, count = 0;

	for (i = 0; i < ASize; i++)
	{
		sum = 0;
		for (j = i; j < ASize; j++)
		{
			sum = sum + A[j];
			if (sum == S)
			{
				count++;
				printf("[%d][%d] \n", i, j);
			}
			else if (sum > S)
				break;
		}
	}
	printf("%d \n", count);
	return count;
}

void ID930()
{
	int A[] = { 1,0,1,0,1,3,0,2,1 };
	int ASize = sizeof(A) / sizeof(A[0]);
	numSubarraysWithSum(A, ASize, 3);
}

/*
925. 长按键入

你的朋友正在使用键盘输入他的名字 name。偶尔，在键入字符 c 时，按键可能会被长按，而字符可能被输入 1 次或多次。
你将会检查键盘输入的字符 typed。如果它对应的可能是你的朋友的名字（其中一些字符可能被长按），那么就返回 True。

示例 1：
输入：name = "alex", typed = "aaleex"
输出：true
解释：'alex' 中的 'a' 和 'e' 被长按。

示例 2：
输入：name = "saeed", typed = "ssaaedd"
输出：false
解释：'e' 一定需要被键入两次，但在 typed 的输出中不是这样。

示例 3：
输入：name = "leelee", typed = "lleeelee"
输出：true

示例 4：
输入：name = "laiden", typed = "laiden"
输出：true
解释：长按名字中的字符并不是必要的。

提示：
name.length <= 1000
typed.length <= 1000
name 和 typed 的字符都是小写字母。
*/
bool isLongPressedName(char* name, char* typed) {

	int nlong = strlen(name), tlong = strlen(typed);
	int i = 0, j = 0, k = 0, f = 0;

	while (1)
	{
		if (name[i] == typed[j])
		{
			printf("(%c %c)", name[i], name[j]);
			j++;
			k = 0;
			f++;
			if (f > 1) {
				f = 0;
				i++;
			}
		}
		else
		{
			k++;
			if (k > 1) {
				printf(" (false) \n");
				return 0;
			}
			i++; 
			f = 1;
		}

		//if (j == tlong) break;
	}
	if(k) printf(" (true) %d \n", j);
	return 1;
}

bool isLongPressedName1(char* name, char* typed) {

	int nlong = strlen(name), tlong = strlen(typed);
	int i = 0, j = 0, k = 0;

	char d1[100][2] = { 0 }, d2[100][2] = { 0 };

	for (i = 0; i < nlong; i++)
	{
		d1[i][0] = name[i];
	}
}

void ID925(void)
{
	char *name =
		"saeed"
		;
	char *typed =
		"ssaaeed"
		;
	isLongPressedName(name, typed);
}

/*
881. 救生艇

第 i 个人的体重为 people[i]，每艘船可以承载的最大重量为 limit。
每艘船最多可同时载两人，但条件是这些人的重量之和最多为 limit。
返回载到每一个人所需的最小船数。(保证每个人都能被船载)。

示例 1：
输入：people = [1,2], limit = 3
输出：1
解释：1 艘船载 (1, 2)

示例 2：
输入：people = [3,2,2,1], limit = 3
输出：3
解释：3 艘船分别载 (1, 2), (2) 和 (3)

示例 3：
输入：people = [3,5,3,4], limit = 5
输出：4
解释：4 艘船分别载 (3), (3), (4), (5)

提示：
1 <= people.length <= 50000
1 <= people[i] <= limit <= 30000
*/
int numRescueBoats(int* people, int peopleSize, int limit) {

	int i = 0, j = 0;
	int max = 0, count = 0;
	int temp = 0, x = 0;

	for (i = 0; i < peopleSize; i++)
	{
		max = 0,x = i;
		if (people[i] == limit) {
			//people[i] = INT_MIN;
			printf("[%d] \n", i);
			count++;
			continue;
		}
		else if (people[i] == INT_MIN) continue;
		else if (i == peopleSize - 1 && people[i] != INT_MIN)
		{
			printf("([%d]) \n", i);
			count++;
		}
		for (j = i + 1; j < peopleSize; j++)
		{
			//if (people[j] == INT_MIN) continue;
			temp = people[i] + people[j];
			if (temp == limit)
			{
				printf("[%d]-[%d] \n", i, j);
				people[j] = INT_MIN;
				count++;
				break;
			}
			else if (temp < limit && temp > max)
			{
				max = temp;
				x = j;
			}

			if (j == peopleSize - 1)
			{
				count++;
				if (i != x) {
					printf("=====[%d]-[%d] \n", i, x);
					//people[i] = INT_MIN;
					people[x] = INT_MIN;
				}
				else
				{
					printf("=====[%d] \n", i);
					people[x] = INT_MIN;
				}
				printf("max = %d \n", max);
			}
		}
	}
	printf("count = %d \n", count);
	return count;
}

void ID881()
{
	int people[] = //{ 2,2 };//{ 7,1,2,4,5,2,6,7 }; //{ 3, 5, 3, 4 };//
	//{ 15884, 8649, 19228, 26920, 893, 16651, 6897, 29403, 16458, 10251, 5589, 10047, 21871, 6893, 308, 28039, 28987, 9719, 9600, 11221, 16630, 23596, 26838, 7877, 25532, 11875, 27047, 6697, 18571, 26746, 17857, 8792, 26350, 13077, 5177, 10817, 25671, 27332, 14731, 24916, 6369, 2456, 28953, 26872, 7762, 21838, 2874, 18387, 24178, 16863, 20134, 12025, 19672, 25904, 8767, 10977, 3887, 12620, 24717, 17503, 8925, 28470, 19065, 18493, 19175, 14737, 19936, 1684, 7079, 14683, 12809, 11119, 9732, 12976, 12990, 28426, 27877, 29895, 20705, 15988, 10330, 23177, 1175, 22606, 18118, 2358, 16026, 3675, 14047, 25804, 26944, 22280, 21154, 13833, 18367, 29275, 28134, 655, 9214, 19852, 28656, 12650, 2678, 10890, 28325, 26786, 14660, 11010, 16969, 28269, 21760, 16712, 18315, 19565, 21076, 926, 12206, 15085, 2280, 7950, 3870, 23570, 8555, 13470, 11420, 24677, 7923, 11803, 17275, 23085, 26261, 7511, 7496, 18443, 27053, 5708, 27533, 29222, 20993, 5021, 27408, 138, 14893, 10038, 10208, 15000, 22858, 21208, 11852, 20858, 19891, 26476, 9862, 22444, 13203, 685, 14740, 23309, 28612, 14600, 8710, 10252, 11030, 15456, 24349, 10417, 3656, 4454, 28161, 11059, 3226, 9910, 15860, 3279, 2631, 25435, 892, 27405, 18527, 13639, 29567, 7670, 8587, 16358, 7140, 2547, 27620, 5545, 10281, 17724, 13858, 6364, 26560, 13353, 7734, 4047, 23038, 19645, 17512, 2936, 11591, 2307, 2785, 18786, 24080, 29226, 6714, 24560, 2576, 22605, 22825, 12667, 27271, 12291, 1917, 18016, 3699, 24393, 25685, 12719, 9800, 1324, 11542, 21027, 26519, 28563, 25769, 20927, 7206, 14828, 5570, 12116, 27879, 28764, 11370, 1062, 27518, 24307, 6448, 3661, 20188, 14389, 24169, 10173, 18354, 8880, 24260, 6797, 7481, 5148, 19355, 11256, 22177, 22428, 15137, 10087, 1136, 21077, 27176, 27750, 26568, 12353, 2167, 9171, 6404, 22232, 7695, 26472, 11571, 19147, 20622, 18340, 27753, 28412, 744, 13254, 10404, 21991, 27149, 5503, 19675, 12792, 26375, 29886, 11806, 11065, 12699, 22301, 16212, 9889, 28941, 5553, 3812, 24047, 20508, 11753, 27485, 29140, 20515, 24161, 26111, 5552, 17278, 26363, 5445, 6151, 16656, 3179, 944, 7583, 20600, 24354, 6250, 20966, 4458, 15521, 9458, 17462, 20396, 7286, 7047, 5271, 4982, 20598, 15, 6922, 22543, 28594, 20654, 5895, 19042, 14416, 955, 12551, 25084, 9607, 15287, 28219, 7750, 23654, 22972, 21220, 10680, 7379, 19407, 2088, 923, 25614, 5658, 14246, 20990, 16403, 24472, 18789, 7734, 16806, 26545, 787, 15403, 12869, 13216, 25323, 14572, 24158, 18442, 18256, 9974, 10975, 12600, 27266, 26051, 28914, 9273, 28077, 5928, 9509, 8568, 4417, 2314, 12993, 3436, 15739, 28978, 24266, 10875, 22424, 18480, 557, 18584, 2449, 10251, 27023, 13967, 28618, 16850, 22069, 5540, 3491, 28524, 28812, 15434, 20952, 1470, 1076, 347, 4509, 29395, 10400, 16499, 5893, 3851, 3721, 24291, 11322, 20721, 25038, 29317, 10702, 7593, 9019, 13553, 9046, 11490, 3141, 1007, 23586, 7174, 4071, 26793, 12722, 6049, 27532, 15811, 9428, 19784, 582, 5905, 1791, 13579, 4790, 11720, 4232, 20630, 20157, 27222, 1958, 23907, 26246, 27861, 6648, 69, 25814, 29518, 3407, 17880, 22650, 12652, 18643, 2886, 8227, 29633, 13004, 2040, 12457, 13791, 25156, 2965, 21222, 10978, 19658, 1356, 24117, 19517, 29027, 2036, 24499, 5905, 11739, 26299, 19646, 4858, 20023, 16154, 696, 25633, 26115, 27496, 6468, 9283, 4801, 17565, 9659, 15324, 24973, 3277, 4156, 16910, 28445, 18756, 6709, 18904, 27857, 7614, 3270, 22225, 1137, 20924, 18924, 10425, 29432, 13735, 17178, 5440, 22302, 21618, 27087, 21033, 29308, 5247, 3055, 29425, 4313, 26976, 27194, 5478, 9765, 6407, 20090, 24485, 25028, 3580, 2275, 10572, 11546, 7720, 22673, 9295, 23831, 7914, 14807, 22966, 7567, 16002, 25374, 3971, 5388, 18717, 14700, 27658, 1691, 17714, 29234, 18178, 3153, 26848, 21498, 22145, 5788, 18048, 11589, 29649, 29000, 12957, 6396, 578, 21276, 2026, 3024, 2463, 5267, 14804, 18444, 24375, 4254, 20803, 18579, 19840, 13406, 19347, 4384, 18909, 2000, 13708, 21956, 28045, 24389, 20703, 11758, 7668, 600, 4951, 747, 775, 7283, 8694, 27034, 17689, 25817, 290, 7674, 14024, 22738, 20910, 13219, 28702, 1466, 7987, 4902, 9632, 21534, 2800, 25226, 17550, 341, 15411, 19192, 28421, 10409, 29992, 7719, 16677, 17643, 8521, 13132, 9725, 25279, 7040, 5814, 17169, 652, 11895, 27545, 3127, 6755, 19150, 5356, 17209, 21444, 11413, 17536, 2995, 13357, 23592, 6817, 12417, 9565, 9065, 29614, 22283, 12020, 27521, 6864, 16605, 27723, 16885, 6497, 28446, 17640, 28392, 24760, 3587, 21745, 3892, 3635, 24100, 7211, 12514, 17203, 25485, 28014, 13851, 10465, 12222, 8322, 12249, 16327, 92, 17886, 20170, 23041, 11124, 28462, 25181, 15574, 2498, 16361, 6918, 152, 7688, 19387, 23898, 7298, 24146, 21260, 451, 19970, 13469, 769, 27299, 6668, 13498, 14425, 5116, 10604, 15458, 4600, 14747, 18617, 21056, 29034, 4119, 10063, 3309, 2715, 29007, 4879, 9609, 20997, 22698, 17843, 18816, 11751, 8745, 19378, 3114, 5112, 12943, 212, 19099, 8991, 16671, 627, 29852, 20043, 26772, 5229, 28581, 27622, 17650, 20153, 13017, 7236, 14206, 25184, 326, 25913, 7774, 7932, 12314, 9027, 8956, 15527, 330, 1946, 19962, 26955, 8467, 25718, 27807, 27691, 2309, 5751, 21230, 6161, 20109, 5711, 6678, 1380, 22658, 26584, 19425, 28515, 938, 4391, 2794, 9752, 5492, 7748, 21435, 26919, 1629, 13688, 1005, 14847, 8476, 17269, 12592, 5467, 17076, 25794, 11283, 132, 6290, 26024, 29137, 15152, 19340, 7884, 13925, 28256, 17102, 24513, 27148, 17477, 22679, 28487, 22128, 29997, 18095, 11416, 22513, 10663, 2971, 11917, 23729, 24101, 5239, 11042, 9757, 18417, 2744, 2361, 24069, 18747, 27396, 12408, 16242, 27829, 1633, 8739, 2699, 26331, 4569, 6493, 26495, 4454, 16731, 3828, 15089, 22500, 2125, 24638, 349, 23536, 19754, 12789, 1880, 13068, 15435, 10764, 19862, 25587, 13065, 10390, 18749, 24305, 24331, 5424, 9016, 21404, 3256, 19690, 2274, 2085, 21449, 27242, 6678, 19008, 21743, 24136, 27590, 1174, 17490, 26857, 23661, 23743, 20208, 20891, 11798, 25256, 6248, 6372, 13877, 19716, 19671, 7042, 24697, 13489, 27663, 26977, 822, 27581, 10752, 28584, 6489, 10916, 10507, 26104, 13093, 8100, 2371, 21851, 13925, 1644, 27780, 19743, 14136, 22827, 21331, 26480, 19128, 18802, 2202, 22682, 20958, 17878, 5559, 20790, 5444, 17785, 27514, 12800, 10610, 361, 23190, 15868, 16596, 17058, 5741, 9039, 11895, 23106, 20238, 25592, 22421, 7164, 8318, 2089, 17891, 15797, 25716, 26906, 339, 22381, 12049, 17113, 27633, 12429, 1948, 18142, 19328, 27789, 17544, 12659, 21562, 18762, 14359, 17586, 23139, 28205, 2217, 8416, 25514, 25213, 86, 25830, 26015, 22370, 28197, 13077, 241, 20767, 9453, 2614, 23053, 10350, 27942, 15057, 5229, 11057, 17778, 24061, 5175, 13774, 12888, 25486, 17396, 24317, 14872, 20137, 20827, 24854, 20094, 6878, 28465, 23054, 25733, 28607, 20617, 18996, 12988, 19201, 7001, 25909, 6512, 22149, 10248, 28415, 1992, 3569, 25851, 29700, 17576, 29479, 25570, 705, 5527, 27253, 12699, 9230, 6676, 20266, 28908, 18011, 2763, 26887, 28006, 14135, 19966, 19686, 18015, 28125, 19797, 1989, 16138, 28515, 27207, 2228, 27414, 10977, 22429, 9477, 26639, 19621, 22221, 8231, 26180, 11870, 8979, 14173, 12381, 21375, 20490, 17149, 6801, 27410, 3290, 19867, 17235, 26058, 11230, 6675, 3108, 7990, 19898, 20145, 20142, 14391, 15516, 24748, 5609, 18252, 25833, 10894, 9957, 14234, 9846, 431, 18483, 28267, 12571, 22013, 10641, 11649, 8148, 10506, 13549, 12388, 10188, 9536, 26002, 21591, 18038, 10924, 15523, 5490, 15957, 9879, 4735, 7729, 11882, 19386, 660, 25044, 18536, 10124, 22129, 3068, 11199, 10448, 17727, 2372, 22192, 12782, 15930, 28905, 23099, 28257, 15638, 5833, 8765, 16236, 27361, 16877, 12436, 124, 3386, 21763, 11690, 16314, 6869, 5501, 8774, 22190, 5966, 15625, 26691, 19251, 16433, 21279, 12094, 2011, 3365, 27957, 14561, 12985, 24588, 9846, 14147, 14881, 8973, 29411, 14143, 1871, 7048, 13825, 7823, 19546, 23636, 28079, 22835, 19944, 6851, 12822, 2486, 19318, 24728, 10610, 13937, 16401, 22327, 28902, 1868, 24671, 17287, 29329, 22942, 17706, 26923, 9732, 21777, 26902, 26648, 13990, 10466, 18500, 17608, 17682, 6229, 6434, 19874, 16684, 7945, 14867, 20736, 26547, 16071, 28070, 5797, 24461, 12864, 3615, 2691, 4869, 14415, 8069, 1062, 7520, 12532, 15825, 1889, 3526, 9918, 10672, 1413, 4168, 9779, 5539, 4603, 24152, 15766, 24299, 4085, 11237, 7775, 677, 4730, 7444, 29403, 26631, 15409, 5090, 4775, 3694, 10682, 22134, 15549, 22811, 17235, 29718, 4443, 29619, 11854, 17687, 18392, 21628, 7566, 16694, 29787, 8092, 8081, 23981, 228, 19508, 24756, 2338, 4444, 1145, 19109, 24453, 2231, 23863, 14374, 26862, 22875, 10009, 22038, 20075, 10630, 10607, 6766, 2706, 8847, 5224, 28753, 18075, 15449, 1481, 10028, 5133, 22294, 9555, 10699, 9166, 20415, 29113, 3746, 1363, 13397, 15586, 18456, 26167, 20949, 16843, 16847, 27367, 14624, 13401, 17634, 28262, 11650, 13349, 3769, 12976, 29681, 24419, 9661, 5976, 27726, 1387, 25143, 23802, 4649, 19139, 1846, 20513, 28473, 2529, 11594, 7145, 28214, 29629, 11334, 2626, 7311, 13715, 14960, 24888, 845, 20331, 7061, 11651, 16836, 9782, 13137, 5325, 14751, 11630, 4372, 25901, 5961, 25373, 27000, 11264, 25670, 3820, 6963, 14313, 3497, 27381, 16650, 14447, 4235, 13485, 193, 332, 6032, 1177, 27938, 10942, 5366, 21476, 25107, 9796, 4216, 11902, 25106, 12836, 24483, 6820, 21229, 1666, 17733, 25220, 6822, 12314, 10240, 17064, 28023, 24479, 29173, 28106, 3421, 27503, 22433, 17044, 4690, 21401, 8649, 10891, 4362, 21611, 23423, 2620, 15310, 13220, 22154, 11572, 14176, 12192, 21809, 15318, 21272, 12373, 12226, 12801, 10722, 25530, 6627, 8599, 9694, 18969, 22292, 3053, 29881, 19038, 2202, 18919, 7847, 16555, 1908, 18497, 22226, 24219, 22771, 27648, 21557, 2706, 22241, 9341, 14163, 1443, 20788, 22653, 16033, 7089, 6501, 6995, 9198, 6219, 16372, 1216, 15056, 4332, 21988, 19414, 17982, 19081, 12749, 25017, 9369, 26221, 4282, 14246, 21256, 18975, 11843, 2644, 22045, 9096, 3483, 3776, 6428, 25660, 8148, 26875, 25170, 14549, 19797, 13556, 3408, 12505, 16215, 13068, 23754, 12632, 14776, 25178, 19437, 13607, 5091, 19238, 5772, 6056, 20051, 19652, 25619, 27908, 23396, 4446, 17100, 7190, 23160, 14027, 881, 14105, 9631, 22770, 20391, 15771, 29090, 5851, 5747, 10781, 21114, 21883, 7420, 25745, 972, 29710, 19655, 3328, 19704, 29324, 6131, 7582, 21542, 5587, 3018, 79, 28711, 22735, 14918, 6454, 4573, 23889, 7533, 29517, 24971, 13735, 6720, 7840, 509, 1844, 15063, 8104, 606, 19721, 29571, 13070, 1912, 29103, 21814, 18655, 28716, 3850, 9717, 15369, 167, 17559, 18494, 19558, 9092, 6524, 10722, 7638, 14251, 10936, 28112, 16467, 27150, 15404, 21124, 27078, 2640, 18631, 3264, 7621, 14172, 12881, 5215, 13534, 4971, 28829, 12904, 17173, 20762, 27963, 994, 11422, 11686, 221, 22925, 29636, 27482, 12035, 29202, 27515, 22419, 7352, 16737, 6372, 12014, 11469, 29511, 781, 3189, 27196, 25600, 24994, 26205, 25220, 14780, 8465, 14166, 11560, 22036, 4853, 19768, 12934, 16122, 6140, 16640, 14204, 16727, 23671, 24908, 7885, 12587, 6587, 29275, 2387, 9987, 8307, 26605, 831, 23628, 5514, 22987, 15767, 20336, 1006, 29484, 3596, 24634, 29506, 4439, 2122, 2615, 17515, 25211, 28267, 18213, 12634, 29073, 1595, 24185, 23536, 17680, 14528, 11548, 6098, 16803, 8766, 18955, 25656, 2452, 13364, 26592, 5031, 1971, 10670, 27724, 6260, 729, 10928, 3115, 21366, 3652, 4971, 22262, 24230, 3875, 4187, 7634, 13103, 18592, 27804, 22852, 4209, 15335, 13022, 21128, 11480, 27689, 27318, 22650, 1056, 9787, 15959, 15494, 622, 7554, 7327, 2991, 13612, 1301, 20776, 23598, 9123, 10103, 19589, 24066, 12422, 5267, 879, 20717, 18104, 15092, 23011, 13084, 17585, 26638, 16923, 6663, 20593, 21985, 18305, 28021, 8385, 28868, 6352, 14905, 4792, 19864, 29270, 8137, 24723, 28174, 24217, 11282, 21508, 9211, 28580, 28003, 8507, 18971, 22905, 1983, 27530, 15026, 17411, 14585, 4579, 23660, 29234, 4504, 28250, 23279, 3449, 7969, 17930, 11604, 15712, 18543, 20929, 13345, 27981, 11429, 6111, 12139, 5719, 2107, 13100, 3229, 1209, 2757, 8663, 16804, 7821, 11171, 17636, 27148, 19558, 20363, 4256, 12037, 14460, 6726, 4456, 10333, 13202, 4374, 28020, 903, 152, 2302, 23298, 11897, 13697, 27728, 21048, 14779, 2808, 15942, 24260, 12526, 19778, 10544, 19681, 3601, 15985, 16561, 19687, 25970, 7257, 15235, 1885, 18381, 25396, 3123, 22088, 25453, 23377, 1162, 19759, 9068, 29344, 11148, 25750, 250, 27479, 29674, 15361, 24469, 3295, 11104, 4148, 18636, 16272, 25804, 28857, 27099, 19213, 15127, 21554, 21462, 3814, 11350, 5631, 15259, 17131, 29280, 3407, 1755, 24733, 7500, 4502, 21770, 13477, 3590, 5974, 13876, 23271, 24757, 23050, 26694, 20726, 1091, 24436, 20147, 25017, 12449, 5351, 18913, 27977, 7509, 11206, 15061, 10768, 16601, 6991, 26635, 5665, 9526, 19898, 25192, 5701, 1377, 9407, 1178, 23371, 6909, 3599, 9934, 12497, 3588, 494, 3804, 6832, 5677, 17871, 28372, 23470, 19465, 18091, 26344, 8951, 25561, 20929, 28162, 16435, 26653, 23351, 26006, 23831, 22097, 1771, 12759, 5167, 17395, 16933, 28199, 22740, 19642, 14045, 15995, 26697, 29446, 11415, 24580, 987, 20873, 10987, 3775, 26068, 14815, 6041, 14499, 16434, 17247, 20770, 6802, 12001, 25326, 1917, 9355, 16900, 22207, 18557, 3673, 10357, 15984, 12172, 29537, 707, 13960, 28143, 16110, 12790, 12095, 376, 23422, 29555, 604, 5579, 29080, 11672, 19838, 12352, 4953, 26179, 19177, 28195, 12984, 960, 19604, 19692, 8018, 29214, 26776, 15905, 12019, 12608, 19560, 14594, 18552, 6617, 17619, 17225, 9473, 11598, 10347, 23687, 10240, 26812, 2233, 23826, 17516, 11, 21939, 16959, 27123, 7443, 366, 12008, 1238, 2427, 27086, 11476, 852, 2928, 15831, 6218, 18783, 29328, 24518, 29366, 13334, 26293, 6030, 12690, 15486, 11167, 15472, 28915, 15078, 17412, 25952, 6281, 17822, 24282, 6703, 20861, 27730, 25988, 12854, 12171, 23320, 24482, 7035, 5394, 25073, 15914, 16768, 20913, 1094, 7975, 19274, 14086, 4680, 21268, 21552, 10262, 5133, 13290, 15719, 76, 15191, 14757, 23513, 1915, 28256, 1153, 3146, 22530, 24938, 5004, 26565, 22982, 3781, 13447, 2225, 23685, 8401, 22698, 27096, 14191, 1561, 9689, 13514, 21266, 25340, 13975, 14980, 21837, 10612, 20193, 27327, 23139, 5174, 13471, 10462, 4590, 29732, 27839, 19076, 28557, 17823, 24995, 5895, 1616, 7726, 29765, 9784, 6643, 15162, 25159, 6853, 4417, 16729, 3476, 29176, 506, 20695, 16714, 13137, 21647, 25483, 10038, 2501, 15338, 4190, 27826, 29702, 24172, 7395, 15159, 22419, 15831, 19423, 27697, 12748, 2633, 10868, 8400, 26167, 15122, 26001, 9658, 9790, 23791, 22242, 10062, 1680, 17855, 14683, 19371, 29362, 24455, 12688, 12037, 25610, 13677, 21559, 28827, 27788, 21726, 29844, 9883, 17097, 19704, 5117, 26530, 533, 27593, 2184, 14158, 25061, 17746, 26305, 20667, 4328, 24995, 6987, 18555, 19784, 6240, 2169, 4262, 7672, 6327, 21284, 10396, 19869, 4819, 28035, 22612, 12689, 15248, 28995, 26741, 9194, 10750, 5012, 23798, 11765, 9259, 27152, 10198, 6164, 9864, 2010, 29942, 7024, 17455, 21776, 13227, 9547, 9004, 8011, 23771, 8636, 11672, 14864, 7419, 5625, 9748, 20742, 14863, 12287, 12964, 10887, 1040, 19998, 9373, 10444, 24813, 12153, 15725, 4251, 5132, 14, 29360, 2795, 16618, 12843, 8054, 27953, 21775, 11803, 4569, 16879, 22021, 2137, 11267, 11542, 1280, 12323, 3614, 11627, 27675, 29487, 1150, 24606, 16664, 25072, 19350, 19192, 14428, 4835, 1393, 12424, 10505, 19402, 9621, 19238, 25855, 20727, 823, 7264, 12974, 4070, 21791, 16586, 16410, 22075, 3326, 17191, 22753, 20945, 16319, 12341, 28112, 22402, 26546, 4081, 3383, 25474, 25732, 4732, 28909, 15462, 28945, 28125, 15792, 21548, 15763, 22458, 19869, 9931, 5836, 3972, 26053, 17980, 10649, 13153, 16145, 3333, 22089, 20424, 17391, 20939, 10988, 21356, 2414, 1782, 3335, 14641, 12689, 901, 1980, 21334, 23800, 24970, 18573, 9364, 7618, 6821, 6007, 21330, 4496, 10037, 5576, 28320, 16845, 15310, 7102, 28926, 16714, 26085, 3020, 17162, 6197, 6879, 6612, 9495, 13989, 27675, 7567, 19296, 28427, 15055, 15728, 14513, 28067, 26865, 23160, 19554, 4480, 23304, 23301, 16873, 4005, 4198, 13067, 16705, 16161, 25799, 2521, 28750, 2302, 8987, 23661, 652, 3564, 5312, 4067, 5951, 4430, 22665, 16130, 29175, 9057, 21323, 11841, 23359, 5065, 7406, 6189, 8198, 20528, 4777, 20868, 23515, 11453, 2026, 13344, 8468, 3853, 16384, 13629, 3992, 13074, 25246, 8201, 14443, 29879, 3392, 11506, 27124, 4803, 17383, 14970, 18218, 22103, 16880, 26415, 17648, 10544, 3553, 23146, 29040, 24880, 16532, 5777, 1650, 14153, 17361, 27266, 2769, 18249, 11157, 11500, 28937, 27981, 5260, 8516, 15538, 26528, 8659, 21588, 8228, 29380, 11477, 2823, 13756, 16361, 23566, 23390, 28677, 28898, 26797, 23553, 27257, 4472, 20998, 1492, 14534, 6311, 824, 1484, 14943, 25180, 27086, 10140, 24112, 28457, 14443, 27440, 6328, 10658, 23275, 10700, 27202, 1302, 15515, 18167, 26567, 9668, 5414, 14049, 21162, 27126, 19979, 2022, 4828, 1687, 14199, 20532, 11116, 7643, 23646, 7428, 127, 17197, 19115, 28559, 5915, 3479, 15886, 9575, 24274, 23644, 24281, 27502, 23527, 28864, 3, 18503, 15635, 22221, 16288, 2295, 10922, 6997, 7245, 27362, 5563, 25309, 12200, 24645, 22267, 22689, 26023, 27119, 10607, 18469, 2555, 6974, 3263, 5847, 9379, 1445, 23821, 10013, 2262, 6900, 24639, 2746, 5030, 1996, 17552, 28712, 19161, 21847, 20793, 14297, 20781, 20892, 14479, 7221, 22660, 17269, 19077, 19525, 9596, 19025, 25960, 12183, 4301, 9999, 4978, 3830, 15139, 22897, 20238, 12519, 19285, 7194, 975, 23677, 2806, 23106, 23144, 247, 27566, 14011, 23762, 13979, 15791, 16428, 930, 8051, 18544, 10743, 17482, 16778, 20151, 804, 19736, 2403, 14007, 24295, 20615, 14906, 18802, 5977, 12092, 27516, 8323, 22039, 15234, 27602, 26993, 2045, 29252, 20290, 28479, 13349, 21304, 6484, 7145, 6739, 28519, 6748, 16123, 10059, 8046, 7967, 12997, 26406, 1946, 8181, 26434, 8538, 27567, 76, 205, 10452, 22621, 7483, 12197, 19697, 8519, 29849, 4786, 2879, 25610, 22815, 17586, 28885, 27538, 19154, 11791, 24533, 549, 25924, 27952, 814, 6858, 16949, 14139, 22438, 28837, 6596, 24465, 6455, 17929, 25205, 306, 13633, 19274, 22767, 11067, 10562, 17197, 24244, 6307, 21091, 15664, 17836, 11060, 14128, 3740, 4762, 4042, 531, 17333, 6995, 2291, 25242, 24720, 829, 25364, 26984, 10042, 26026, 24883, 21484, 3390, 10812, 24772, 2929, 15948, 13761, 11777, 22895, 4975, 28188, 24448, 13354, 15650, 3140, 3829, 11108, 29121, 23880, 27064, 10781, 7902, 22891, 21267, 8985, 1549, 7585, 23256, 10700, 27115, 16047, 27611, 26848, 23980, 21850, 7049, 26237, 13049, 27625, 4676, 22138, 21498, 12657, 25504, 27364, 1885, 18965, 21104, 20882, 25843, 28472, 9819, 10010, 2627, 22954, 7537, 9490, 10502, 16523, 2469, 9111, 27289, 22760, 19933, 27474, 12188, 29400, 29786, 18098, 2629, 9268, 1878, 8374, 25856, 20198, 16103, 15027, 16311, 26758, 12376, 29238, 15230, 25327, 25990, 29557, 11175, 3698, 7642, 12004, 21701, 3076, 10951, 10491, 672, 24623, 12875, 11310, 12298, 10294, 22605, 28016, 4536, 16762, 11708, 3876, 29224, 26029, 15685, 859, 4509, 17450, 10668, 19295, 11070, 25184, 18001, 13374, 17612, 29243, 19668, 9147, 805, 21190, 25639, 10447, 25833, 12928, 22006, 14817, 17217, 3876, 18713, 6186, 11623, 18203, 26617, 28422, 12155, 21531, 13571, 3696, 29290, 29680, 13923, 2280, 17108, 24467, 5247, 22874, 23681, 5087, 22834, 11517, 26453, 858, 15588, 23220, 16863, 29337, 12823, 2123, 23570, 7437, 2144, 513, 8517, 3152, 9176, 19555, 8193, 7539, 27179, 27951, 12153, 15696, 6960, 11292, 28948, 6108, 29908, 6927, 5128, 27533, 29398, 3401, 24896, 20298, 3678, 26788, 27771, 3803, 15639, 27754, 13219, 10279, 18874, 6712, 5813, 22885, 9591, 15077, 21168, 9987, 5928, 10653, 11158, 16024, 26692, 18672, 27311, 11529, 24333, 9457, 24813, 5764, 3601, 5440, 14800, 3050, 3911, 29172, 19008, 22517, 13658, 27288, 1397, 12703, 9507, 26722, 3711, 5883, 13453, 1570, 26194, 15494, 2503, 5085, 18974, 26043, 25047, 8430, 17004, 4354, 13216, 13248, 19750, 388, 1961, 27645, 2578, 13764, 25855, 20556, 1955, 9116, 29855, 16602, 7057, 8711, 16145, 5811, 23493, 26265, 14659, 20346, 11960, 15107, 721, 4662, 11138, 17367, 27473, 18172, 3532, 12220, 12619, 14957, 1347, 28548, 22760, 9394, 23700, 7868, 21597, 17810, 28541, 19113, 20890, 22028, 10848, 8255, 14575, 2510, 11103, 23993, 8685, 10322, 19568, 28986, 11012, 774, 5344, 21565, 15654, 21502, 11712, 29948, 4481, 2226, 11177, 3087, 27066, 3999, 8613, 9664, 27962, 20502, 4559, 23953, 26708, 13617, 15757, 13636, 8556, 2671, 1024, 4925, 24694, 19881, 6259, 10020, 18408, 2398, 26993, 1307, 165, 3089, 17692, 3448, 27640, 2209, 10727, 21850, 24733, 14918, 21254, 24855, 16313, 15229, 28119, 21293, 29322, 9212, 25052, 21797, 15602, 17224, 10899, 2174, 21468, 27772, 25566, 6707, 4884, 25060, 16030, 25440, 26367, 10296, 4827, 22764, 22295, 15888, 17338, 2930, 27754, 2535, 8621, 19438, 26473, 20009, 28691, 22103, 11083, 23370, 16305, 27579, 7341, 20607, 15624, 13723, 18765, 6507, 781, 18834, 2419, 29960, 6568, 10118, 25086, 8805, 10423, 10722, 28495, 2031, 14403, 26187, 6525, 20534, 25184, 25251, 3137, 16475, 28433, 12492, 2028, 7910, 4849, 17392, 16737, 5442, 9896, 29954, 22709, 11570, 6521, 19958, 7704, 14305, 28821, 9239, 27115, 8823, 8524, 15165, 2291, 24922, 14705, 16218, 22133, 10521, 9618, 27914, 10803, 3935, 16488, 9432, 16995, 15186, 14742, 11079, 24084, 7709, 11799, 6949, 1538, 16710, 4008, 4065, 24123, 3037, 29898, 7847, 28612, 18701, 22613, 28782, 24263, 28514, 23577, 29480, 20727, 23570, 22838, 16826, 15655, 73, 19019, 9948, 7245, 25508, 10602, 19917, 22235, 2794, 688, 6916, 19360, 17874, 16787, 21808, 28094, 13706, 4717, 29444, 1210, 4090, 24877, 23237, 26894, 25590, 5762, 24728, 20690, 8481, 2966, 18415, 3304, 20043, 17243, 13829, 8137, 10351, 5715, 5951, 14411, 2655, 8069, 6271, 5325, 22367, 2118, 26627, 3235, 25530, 8911, 5888, 12526, 22537, 7590, 8858, 16284, 27737, 16367, 28882, 13173, 12203, 24113, 11680, 3623, 2312, 29019, 23997, 1090, 10307, 17109, 8810, 7188, 24683, 5626, 28009, 22140, 6796, 28278, 26691, 16707, 11796, 1315, 19608, 16774, 13961, 4186, 5893, 1827, 4419, 13365, 6961, 10200, 17502, 4497, 10818, 19333, 27991, 9620, 19015, 13125, 12400, 16741, 12424, 5609, 7959, 27155, 29386, 1864, 5521, 21705, 21314, 11513, 9717, 11684, 4100, 17864, 11139, 16738, 3304, 20080, 17631, 9023, 29135, 20883, 12095, 22934, 12337, 4170, 26111, 22188, 27269, 19836, 12851, 10175, 9460, 8729, 3860, 18457, 16203, 17626, 12222, 18210, 27493, 16452, 31, 21179, 12360, 15461, 22991, 26639, 23574, 5177, 2568, 834, 1453, 23677, 11243, 24502, 2956, 21700, 22380, 9838, 29613, 15965, 12627, 7060, 16861, 11450, 1726, 28993, 22281, 5558, 18709, 8540, 21647, 23012, 1206, 14125, 27230, 8516, 1409, 4344, 26447, 27484, 1498, 11078, 4346, 8420, 1178, 21197, 23086, 29218, 19086, 3852, 9178, 14998, 10634, 3584, 3335, 27881, 3698, 540, 1515, 29382, 15380, 19082, 12361, 26011, 13991, 7809, 18080, 25789, 28175, 18539, 15319, 5136, 27009, 19008, 601, 22472, 3281, 7343, 9348, 26878, 11811, 13822, 21939, 9166, 26328, 339, 23914, 18163, 14033, 4662, 12488, 17592, 11218, 3185, 7149, 28865, 26363, 10865, 20190, 25287, 22468, 19364, 12506, 5088, 7326, 21748, 5247, 13271, 5681, 27001, 6718, 29293, 178, 23555, 14923, 206, 26353, 29177, 28090, 4837, 21290, 5650, 6680, 14090, 6680, 21282, 27415, 10051, 9589, 26441, 5571, 17792, 18097, 9282, 12413, 28944, 14825, 1980, 4955, 14606, 25529, 18810, 9214, 13012, 23464, 29110, 22782, 17209, 10155, 2564, 18470, 6730, 26128, 28877, 15384, 15198, 21847, 29311, 866, 8520, 9290, 18384, 22255, 5716, 6644, 15679, 18563, 14203, 8584, 10122, 2306, 13596, 2756, 6502, 2754, 20301, 12299, 17375, 12103, 22542, 17333, 25103, 29545, 27654, 1658, 26358, 12748, 19107, 3033, 4414, 20822, 8050, 2459, 205, 732, 17827, 22409, 6741, 6167, 22971, 13705, 7826, 5312, 25327, 2444, 142, 16868, 24215, 8927, 9708, 4933, 11458, 23069, 13647, 5826, 22729, 6697, 25778, 18319, 29482, 6925, 16120, 27935, 9932, 506, 2330, 15208, 2859, 16820, 18588, 5022, 23596, 11703, 9164, 21520, 9859, 18950, 8942, 24184, 9275, 16223, 795, 18138, 19312, 7938, 9969, 3516, 8463, 14347, 24967, 20463, 4270, 4469, 20803, 8909, 23859, 10810, 20414, 21927, 492, 23828, 8002, 15524, 6780, 6454, 27534, 5881, 2318, 2900, 26481, 9608, 4455, 965, 18690, 9014, 2048, 24955, 158, 28149, 14667, 16560, 25830, 350, 24415, 15858, 5740, 15232, 18775, 5522, 25246, 9335, 22237, 10288, 626, 27499, 16740, 12786, 26698, 2478, 8484, 26202, 24391, 10870, 20460, 1345, 21243, 10349, 25786, 15428, 24620, 7641, 24406, 18435, 7391, 24022, 2279, 16707, 27028, 14230, 27348, 26012, 16069, 7898, 9033, 14163, 27795, 19383, 23073, 13852, 233, 28133, 18976, 11994, 10146, 28468, 5103, 22474, 19803, 22823, 25186, 541, 27814, 4336, 20490, 3295, 5526, 17396, 11656, 13641, 15154, 20236, 2021, 12090, 70, 8678, 14346, 503, 13378, 4377, 26058, 7976, 10537, 18563, 29294, 26690, 3672, 11924, 11621, 10956, 29944, 18276, 27011, 15223, 24018, 22783, 15688, 29810, 5097, 10364, 5831, 11836, 1687, 6333, 15978, 22896, 13534, 18204, 25610, 24215, 22323, 4707, 3327, 28330, 6388, 18875, 19502, 6129, 10331, 10065, 27892, 28731, 18790, 9775, 7236, 24183, 12698, 17013, 29876, 24375, 29547, 14373, 7501, 21603, 22031, 5432, 5234, 29594, 18602, 17092, 17134, 15470, 21711, 22713, 4096, 24248, 18059, 12741, 28754, 7889, 19228, 4551, 5487, 8611, 11899, 28887, 12853, 19849, 8357, 22675, 23387, 7506, 14713, 2271, 16583, 1315, 24401, 11298, 20073, 29549, 3575, 20607, 27725, 8364, 20134, 5147, 22193, 29086, 26035, 340, 17122, 2182, 290, 6007, 4593, 7680, 21514, 12134, 8233, 12003, 21507, 22156, 4046, 11198, 12061, 23153, 11656, 1499, 24914, 29961, 10541, 28211, 28823, 23022, 4890, 9480, 25293, 26131, 8899, 930, 1842, 8085, 15364, 28432, 8937, 10534, 18360, 25170, 18435, 1084, 25698, 7518, 24645, 12667, 26168, 23476, 10623, 29965, 15285, 5584, 18281, 2963, 19658, 2264, 26072, 5916, 8935, 29246, 12173, 23739, 3056, 7388, 19648, 22760, 10903, 23645, 19938, 4835, 28754, 21848, 9075, 16070, 26782, 18601, 4418, 2858, 20842, 17708, 19341, 13355, 1495, 14009, 29130, 14620, 5687, 16513, 17767, 6176, 20330, 11279, 1639, 20434, 17113, 5986, 13442, 23358, 4254, 8117, 16531, 8490, 16457, 13943, 27314, 10348, 21361, 28856, 11081, 29498, 7171, 902, 29367, 25230, 12458, 13089, 9218, 5154, 27555, 7388, 7876, 3657, 2225, 5663, 28657, 24210, 6883, 15775, 28991, 9725, 14913, 15387, 23160, 22250, 13453, 1691, 11889, 25924, 9770, 15903, 26871, 26005, 6243, 17183, 4359, 13898, 10950, 19063, 24651, 27364, 11068, 10512, 6384, 25160, 10858, 14970, 21328, 6730, 24785, 2081, 16899, 20157, 14241, 28582, 10441, 3798, 4397, 24948, 14450, 17369, 1124, 5489, 9715, 9836, 1507, 4059, 20589, 17519, 18412, 9431, 20691, 10119, 524, 18386, 8824, 26288, 26173, 2635, 1428, 4164, 15031, 24894, 10602, 29670, 6609, 22214, 25429, 11885, 10989, 29247, 19756, 8667, 901, 6960, 23954, 29334, 9914, 25225, 23612, 23822, 19194, 27073, 28949, 22896, 1407, 881, 5083, 29968, 4750, 3421, 3991, 15521, 17979, 15063, 22433, 8903, 17681, 18261, 24308, 23706, 29687, 12764, 27722, 25362, 13191, 2314, 15666, 15465, 5811, 23138, 21226, 5352, 10972, 687, 22049, 16458, 29832, 5548, 23102, 5080, 13652, 9679, 18889, 20444, 15145, 14325, 2413, 9035, 12101, 10183, 23100, 7425, 3723, 6800, 16801, 15404, 14814, 5265, 11996, 27722, 25960, 9148, 24426, 29860, 15847, 26249, 10150, 3403, 8387, 14199, 14164, 17838, 12712, 3941, 23503, 19140, 11878, 26136, 21670, 16512, 9373, 3680, 26084, 26498, 27805, 9238, 12000, 10246, 17926, 27342, 7972, 15640, 11674, 15187, 25198, 11372, 2046, 4348, 1384, 28627, 13863, 2293, 20320, 17242, 1496, 27249, 9502, 17900, 5543, 18516, 17472, 26160, 6125, 12538, 29316, 12550, 26200, 20272, 5041, 696, 28481, 29421, 22509, 10972, 25404, 12819, 22425, 18580, 8722, 10509, 23579, 19372, 26673, 24458, 7241, 17750, 29083, 5843, 9534, 12888, 9220, 27062, 13271, 20650, 11022, 27673, 7159, 3226, 5563, 1640, 9886, 11356, 13849, 3407, 25875, 3233, 17638, 22144, 14276, 13232, 10399, 8334, 12982, 23176, 4744, 28285, 19177, 27834, 2611, 12076, 27345, 1689, 13109, 11679, 3666, 18740, 25811, 17322, 23568, 1428, 8508, 12563, 8116, 4861, 4472, 791, 18587, 3221, 2863, 12012, 18540, 5763, 24690, 19918, 19515, 16711, 24734, 17204, 24738, 271, 11947, 1933, 13956, 25773, 1685, 15968, 15230, 5711, 20873, 17843, 16640, 12721, 1239, 373, 2092, 2767, 20017, 13433, 23977, 14359, 22230, 13600, 2722, 7686, 3363, 16982, 14418, 12848, 2129, 9170, 9789, 3549, 27962, 7163, 9797, 9718, 9112, 4787, 6385, 6512, 11811, 3296, 24976, 1057, 14988, 454, 5186, 8733, 28517, 8075, 4963, 11061, 15593, 23979, 8182, 13968, 7137, 16445, 29519, 6173, 29766, 5891, 21794, 18756, 10301, 14951, 15864, 6301, 17676, 8342, 2684, 7224, 19176, 22364, 7170, 15930, 23576, 5603, 65, 5451, 17910, 19628, 2437, 12428, 25556, 29902, 17238, 21008, 21179, 7489, 16026, 7248, 29592, 28215, 22685, 5073, 11258, 11002, 28371, 16959, 28982, 8659, 28746, 25383, 21318, 27323, 8137, 1636, 14470, 25662, 25473, 18823, 20285, 2387, 5308, 1243, 1005, 27537, 13866, 19758, 20297, 1621, 19039, 29596, 18801, 15765, 13654, 29632, 23358, 8170, 23830, 10422, 14513, 13424, 9249, 17495, 2477, 26020, 13634, 25240, 5476, 6286, 26677, 17504, 10556, 7808, 329, 19365, 14215, 2639, 26837, 17438, 24324, 27769, 7166, 20656, 29996, 6959, 11107, 19058, 8240, 807, 17429, 29749, 10262, 15703, 15521, 5662, 20932, 5096, 21674, 11606, 25212, 1712, 24098, 2014, 24479, 28046, 12768, 19790, 12477, 18138, 15127, 4594, 6732, 20567, 23881, 19838, 27362, 28731, 28499, 18820, 1259, 9151, 20201, 16257, 3873, 5245, 18007, 20475, 20844, 29355, 1096, 22767, 27214, 22381, 5258, 8599, 25111, 19791, 21974, 7716, 15719, 622, 21883, 24458, 25485, 1492, 859, 5952, 17969, 17032, 23405, 22488, 3427, 18031, 25046, 25970, 686, 27416, 16550, 10828, 8562, 28250, 18643, 9726, 284, 17736, 1012, 19766, 8233, 22122, 6167, 12608, 23048, 1911, 22903, 18347, 1190, 17269, 23172, 1531, 16489, 29448, 8809, 7843, 19192, 15602, 19341, 8624, 20655, 26858, 23912, 7008, 15506, 21086, 15258, 22741, 6390, 10052, 21927, 2920, 19516, 20653, 14092, 18356, 2356, 4476, 20941, 19283, 13224, 8813, 23592, 16740, 25032, 25058, 4949, 10243, 2110, 20130, 26086, 5425, 22493, 17295, 24198, 12353, 17689, 18227, 16419, 1865, 11665, 2706, 14231, 10430, 12114, 10560, 25616, 24935, 20562, 7862, 20914, 7272, 15365, 21385, 29553, 9365, 10643, 19048, 11265, 29716, 4899, 13209, 4783, 1981, 28601, 4196, 1661, 21099, 15134, 27324, 19722, 14580, 26073, 6848, 24858, 15152, 5176, 25304, 13525, 28646, 26481, 16968, 2774, 67, 1826, 23809, 19392, 2196, 1214, 15978, 10790, 1603, 19086, 4274, 29987, 6054, 9682, 5770, 20593, 15211, 13044, 4027, 5750, 6616, 21191, 22500, 6378, 24625, 4405, 19967, 940, 15617, 6139, 4297, 19998, 2288, 4025, 19800, 25174, 3802, 29581, 23592, 3072, 1827, 19062, 10872, 27654, 5351, 24145, 12649, 2248, 26818, 27075, 27331, 18183, 26204, 19309, 5848, 2782, 9860, 924, 20391, 27573, 314, 19936, 23710, 24541, 12151, 23606, 16897, 5714, 12855, 4236, 2316, 25868, 2439, 22976, 28532, 1289, 23491, 7536, 555, 15841, 15186, 21225, 12013, 3074, 1210, 4331, 820, 1031, 19777, 709, 17264, 10492, 719, 11482, 9609, 7268, 27971, 29234, 1518, 1015, 9841, 4159, 10794, 26607, 16646, 3532, 9338, 13636, 21179, 15029, 21039, 27121, 13029, 10025, 17994, 20303, 20314, 26855, 20355, 6113, 24942, 22388, 27534, 1186, 18683, 29347, 23124, 9169, 12221, 26646, 23648, 20161, 11918, 7636, 5797, 25428, 15775, 27001, 28696, 9564, 19122, 11969, 3412, 16747, 15176, 10122, 3779, 20041, 5853, 28317, 2550, 2950, 28821, 28763, 1771, 14135, 22328, 7726, 9004, 11733, 7991, 15388, 21568, 12720, 24436, 62, 13399, 18755, 2975, 17169, 3589, 4285, 17752, 24754, 795, 16967, 23349, 21836, 29916, 23873, 21225, 16482, 14714, 22963, 1869, 25777, 20388, 15832, 3687, 23322, 5288, 812, 7558, 26170, 20748, 28303, 4041, 8845, 29254, 21947, 7851, 18634, 4617, 20428, 11389, 5473, 19334, 10093, 16026, 1284, 2369, 12671, 15007, 25943, 7912, 19666, 16717, 21755, 19699, 5230, 9823, 4453, 27570, 25170, 7554, 28663, 20161, 5706, 13096, 9839, 9986, 26145, 21682, 15965, 23491, 67, 29758, 23816, 23031, 28264, 4762, 13267, 25208, 13245, 4757, 21447, 8107, 25386, 5524, 26667, 12495, 5034, 18629, 5282, 11134, 502, 13360, 27041, 29971, 21506, 13914, 28952, 26346, 29295, 20986, 22911, 18469, 6182, 7566, 21942, 15163, 13465, 10028, 8957, 26089, 3065, 14750, 18231, 19840, 20079, 3808, 20608, 22792, 21316, 4370, 1058, 6060, 6773, 27023, 13714, 20456, 17480, 9525, 23660, 27636, 23927, 4805, 16611, 24587, 12285, 17277, 28945, 7073, 17095, 3383, 1885, 11276, 8972, 23960, 28186, 28932, 5576, 15776, 28740, 10435, 7776, 1831, 19234, 6620, 5424, 16798, 11315, 29196, 9004, 28663, 26884, 12831, 10004, 26087, 4104, 12005, 3654, 2607, 29962, 10018, 2670, 16220, 23367, 3012, 6644, 25611, 19725, 24425, 20011, 6664, 22761, 5385, 15692, 22006, 17447, 23194, 23416, 6251, 4935, 12069, 18792, 21602, 7410, 12935, 27824, 6432, 16209, 7915, 28348, 15636, 6568, 9651, 21513, 850, 29001, 12456, 11762, 5028, 5185, 9230, 8769, 3721, 430, 6834, 23525, 21416, 4589, 29256, 6542, 5601, 7154, 27137, 15771, 16935, 1165, 22252, 14183, 2843, 15273, 13446, 23735, 7016, 25305, 13278, 14598, 10512, 896, 7404, 22975, 6189, 3725, 2634, 23139, 24974, 16207, 27612, 9833, 4100, 12235, 7671, 5952, 8236, 23522, 19746, 23439, 5841, 14194, 19996, 8661, 17067, 1014, 19462, 5195, 9193, 12669, 6429, 3239, 15694, 9847, 16713, 13949, 19212, 3757, 5752, 27091, 15027, 25141, 21413, 14995, 4738, 8577, 20799, 16402, 11229, 10545, 28052, 28724, 13442, 2498, 26496, 15467, 14621, 9741, 8443, 544, 26961, 14325, 11747, 29545, 5352, 18696, 14683, 20388, 15965, 27418, 23559, 7982, 10339, 27752, 20609, 4658, 23077, 26973, 27269, 9547, 13739, 21184, 9937, 1403, 15702, 18750, 17900, 3183, 11703, 15528, 23432, 11106, 24916, 7853, 27735, 4267, 28466, 26576, 24423, 27590, 25785, 13499, 10595, 28621, 28871, 26093, 17291, 16818, 28949, 16616, 5610, 20166, 835, 26185, 14567, 10028, 25964, 21447, 16608, 22459, 12517, 26134, 1031, 21070, 20552, 4565, 1435, 24019, 26213, 22377, 25672, 28332, 1001, 22010, 3145, 19961, 10086, 21215, 26132, 12045, 28270, 1419, 1818, 16991, 9213, 19183, 10711, 2360, 10001, 14224, 3938, 20990, 7676, 4984, 21374, 11087, 15000, 7632, 6796, 26430, 19770, 19229, 24425, 16084, 24420, 5298, 24098, 10669, 9343, 2236, 10251, 8084, 19381, 11944, 9311, 20092, 29161, 25022, 23556, 23418, 28097, 26977, 7810, 2366, 15056, 13444, 17713, 25526, 14142, 15514, 2226, 7213, 10550, 29087, 14133, 24646, 23257, 7319, 27373, 3089, 1929, 26631, 20615, 15393, 6701, 3010, 1977, 19747, 2901, 9005, 7884, 18391, 14046, 10941, 18638, 14776, 768, 28444, 7696, 3320, 19162, 13958, 27978, 11158, 8441, 27822, 4214, 6506, 6112, 13337, 25931, 1559, 7954, 14705, 27358, 26707, 15571, 14336, 15972, 933, 4992, 25981, 10042, 19936, 11275, 1441, 22056, 1174, 25674, 2083, 11003, 7667, 3887, 265, 3707, 960, 2063, 1362, 13082, 3997, 29839, 8659, 2011, 21963, 9216, 11762, 24071, 28511, 24849, 13361, 1347, 9390, 5515, 15455, 4000, 27241, 20235, 18947, 25350, 4406, 3838, 3826, 27115, 10267, 10376, 29560, 12768, 29764, 4604, 1441, 9124, 12739, 4415, 17707, 14805, 13888, 18421, 18055, 28238, 3598, 6523, 2334, 4286, 11417, 7458, 24883, 17192, 8745, 5113, 63, 20715, 22365, 21722, 20072, 11092, 14138, 7747, 7748, 21629, 14934, 17860, 17795, 22250, 7651, 20320, 22057, 6134, 3224, 28414, 16305, 16435, 6237, 20377, 25553, 17329, 23420, 22178, 24151, 8303, 12816, 10331, 20748, 12317, 8935, 9171, 7286, 9795, 10120, 10415, 29666, 29529, 29367, 4530, 20327, 12721, 9278, 5997, 19790, 22098, 5069, 13052, 27484, 13670, 21405, 29779, 25015, 9327, 16118, 22750, 26793, 7842, 29677, 5475, 21194, 18771, 1478, 9467, 27629, 10066, 22408, 28660, 3481, 16424, 14939, 4726, 27353, 23879, 23309, 26978, 3037, 17770, 1708, 807, 12774, 12195, 21676, 2888, 21669, 8416, 2053, 20710, 15360, 8427, 7615, 12089, 15355, 8496, 13957, 29609, 22107, 15929, 27183, 8659, 28777, 13566, 7687, 14675, 25023, 7624, 2842, 23959, 14608, 22723, 17617, 29830, 2092, 7938, 24221, 18493, 3056, 26406, 27646, 20158, 16353, 6662, 19293, 13016, 26372, 21594, 6253, 27205, 6884, 25725, 11637, 15792, 7182, 26426, 19043, 6868, 16909, 20648, 3860, 28175, 19256, 24092, 28191, 2046, 15288, 20201, 28720, 15912, 6878, 14580, 7975, 17093, 26716, 14556, 5058, 2848, 24558, 22685, 25153, 24834, 13082, 12641, 19293, 12325, 16162, 25677, 13206, 20783, 3091, 567, 2057, 27384, 8236, 24579, 8607, 14504, 3914, 8178, 13850, 20654, 16677, 18531, 2041, 2053, 27517, 18510, 20702, 7288, 8084, 24337, 6939, 2484, 24209, 5209, 7025, 8032, 25101, 27723, 20096, 24599, 29826, 20951, 6286, 4579, 11123, 18086, 22684, 18877, 29848, 5129, 16226, 5727, 16194, 4607, 27214, 20862, 3944, 21790, 69, 6387, 27104, 12312, 21381, 9543, 4265, 29570, 7550, 26024, 27090, 28697, 6003, 25240, 5100, 17032, 24830, 27795, 8601, 26691, 23645, 20809, 28639, 7166, 16193, 23626, 18176, 15726, 19328, 21858, 1449, 14995, 9334, 20636, 5918, 7017, 12664, 12089, 2543, 25867, 24392, 12, 1278, 24103, 18905, 23772, 7655, 13000, 1574, 27141, 29337, 20589, 28648, 19406, 17143, 20328, 21888, 19516, 22753, 26133, 16691, 11809, 22805, 15092, 7081, 1320, 1683, 23619, 8801, 15933, 11845, 21404, 28618, 2331, 7078, 10390, 15706, 20381, 16768, 8077, 14486, 28009, 29626, 2631, 22981, 22565, 24059, 6951, 29387, 3891, 1602, 4055, 20206, 10713, 26198, 28642, 15356, 8719, 14745, 8183, 27159, 16039, 25063, 18691, 1447, 28419, 7089, 1712, 11552, 21340, 10988, 19893, 703, 26271, 4439, 5801, 2896, 10891, 23970, 5200, 15838, 12656, 12914, 29367, 2369, 21840, 24986, 1595, 18219, 27912, 20538, 28197, 15882, 9801, 3114, 7087, 18305, 28248, 27162, 24801, 10530, 29431, 12862, 24558, 23434, 22544, 9469, 29408, 18307, 27690, 2098, 5366, 22576, 2923, 4604, 26158, 16012, 14119, 17158, 11643, 21972, 18809, 12566, 12237, 6814, 19149, 17938, 1989, 6912, 608, 14055, 26325, 2409, 153, 3571, 25267, 728, 6950, 5824, 28050, 9316, 18424, 11769, 21863, 23559, 2838, 29810, 4890, 15286, 11719, 1178, 16261, 15164, 24590, 13725, 18859, 3652, 25149, 13912, 22448, 6301, 26428, 17400, 449, 14602, 7271, 7571, 5591, 6572, 8802, 11753, 12248, 21466, 17281, 1460, 25935, 12873, 8663, 18608, 5919, 13056, 5957, 7605, 19447, 14393, 9501, 28891, 15620, 13799, 9924, 16798, 24741, 16619, 6692, 17462, 8802, 15299, 4867, 17286, 15408, 23461, 21022, 19192, 20086, 16224, 4843, 7801, 7788, 22004, 15441, 19474, 14981, 25061, 29972, 24190, 24572, 23455, 6137, 20535, 3038, 28013, 28098, 17692, 18522, 3682, 14832, 13031, 23964, 26184, 8606, 29414, 9203, 29141, 22132, 24706, 16014, 16602, 16885, 6084, 1194, 14657, 4431, 19394, 7857, 28847, 24578, 11663, 16942, 1039, 4445, 18777, 16192, 1238, 4261, 4342, 27101, 26825, 5945, 18055, 8049, 16164, 10268, 1512, 10067, 20903, 3915, 7652, 5339, 15113, 29025, 13139, 25604, 7795, 5253, 29434, 5558, 2268, 27130, 21613, 29993, 16389, 10756, 2423, 20675, 16602, 25799, 26176, 29015, 3368, 6415, 3621, 16593, 18535, 29052, 27420, 10647, 27971, 20294, 8798, 3213, 26804, 16818, 501, 20672, 20550, 15972, 18687, 21464, 4396, 20787, 16596, 17629, 3224, 13603, 8613, 917, 19472, 799, 8545, 21001, 8238, 23587, 26749, 12712, 2181, 18644, 16971, 1090, 10063, 7591, 7524, 24511, 23656, 16421, 10489, 23725, 22309, 7776, 17923, 8586, 25532, 27343, 2681, 8179, 23143, 25529, 8668, 10037, 24121, 6051, 18912, 16261, 10902, 13801, 7505, 13357, 15437, 24663, 26957, 17507, 23998, 17423, 17142, 19323, 11458, 4385, 15708, 21978, 13511, 3786, 29325, 13447, 4339, 8036, 19081, 18222, 10401, 12814, 20655, 9434, 17774, 3992, 25738, 15776, 16713, 26697, 5063, 1553, 999, 12966, 8360, 7036, 11348, 28916, 159, 3755, 808, 26522, 17777, 17302, 16614, 11932, 16915, 21625, 16121, 19990, 24128, 16233, 27376, 10238, 29186, 27865, 9658, 8839, 3837, 3727, 813, 16994, 22710, 8044, 18467, 6455, 29831, 28926, 23963, 14473, 15193, 3264, 29600, 3169, 23979, 26135, 43, 29667, 25091, 13030, 2665, 15640, 2804, 29242, 8134, 20465, 8289, 14331, 25360, 8632, 11694, 19500, 20939, 27326, 7380, 2576, 7803, 9671, 466, 8180, 28818, 13242, 29283, 26072, 4098, 2321, 28310, 7422, 17692, 15507, 18945, 26893, 18935, 20967, 28813, 13961, 1758, 28943, 20420, 19631, 13986, 28411, 7601, 11317, 13485, 25999, 23084, 17369, 19644, 22117, 19275, 8516, 7249, 2715, 6076, 13622, 8334, 15971, 1865, 26910, 9750, 10795, 4035, 2197, 1001, 3165, 2982, 13248, 8518, 718, 10809, 4807, 335, 7142, 11610, 10546, 7196, 20779, 14993, 29084, 3432, 19092, 4683, 26218, 19678, 18393, 11232, 26460, 4868, 27412, 23148, 20, 25466, 26601, 29597, 6665, 19456, 12493, 21955, 27887, 28254, 14507, 709, 20016, 765, 23198, 27305, 16498, 638, 16012, 21725, 6869, 6637, 21414, 11310, 24689, 25361, 1774, 22442, 23824, 21158, 29503, 9680, 14340, 2033, 16915, 22035, 15036, 9258, 22255, 2272, 8237, 21162, 19904, 3912, 14459, 4330, 13399, 22210, 25824, 12217, 21258, 5748, 10367, 18677, 655, 26547, 21561, 14643, 10195, 18852, 29084, 4975, 9827, 18097, 16740, 15239, 19240, 2260, 9073, 13229, 15914, 14176, 9820, 15044, 22416, 1186, 11362, 6502, 17002, 13737, 23105, 27755, 9398, 16879, 20587, 24776, 28580, 9573, 12544, 14587, 2098, 8583, 5836, 9475, 711, 9342, 24167, 5143, 2165, 10049, 20949, 21325, 28633, 4833, 3854, 23689, 20463, 3103, 21251, 11131, 5672, 5039, 8431, 27549, 11849, 8153, 6479, 9389, 22478, 21036, 4598, 10491, 4149, 25987, 25909, 16601, 4056, 24791, 28327, 12820, 23884, 10047, 9100, 16080, 27515, 25055, 10336, 8102, 23151, 18831, 29174, 23993, 13297, 3691, 5903, 18246, 10703, 16280, 19890, 22130, 7784, 29281, 7254, 3765, 5504, 6982, 21291, 1627, 28083, 19768, 24587, 7096, 26532, 695, 9078, 18324, 23027, 19638, 6123, 9926, 26076, 24146, 17411, 20249, 7178, 24900, 22271, 11563, 11339, 14805, 9664, 24851, 3819, 15040, 23782, 29487, 16750, 20860, 29571, 11675, 28648, 23884, 2577, 15616, 28731, 21633, 3667, 5884, 9218, 22046, 29388, 28115, 28932, 13029, 7443, 17578, 27844, 14733, 16728, 26970, 11220, 6955, 2431, 12786, 26749, 2103, 13376, 1413, 21271, 982, 9637, 4893, 21171, 27918, 3754, 10727, 29621, 3997, 15898, 24492, 23534, 29843, 8628, 4477, 3298, 14068, 23804, 6669, 13810, 8873, 1873, 16836, 17789, 15680, 14032, 21676, 29976, 21776, 9589, 217, 12204, 1350, 14356, 2470, 4489, 25439, 12964, 28063, 18346, 16982, 29174, 18528, 18134, 10785, 24017, 7963, 7570, 15256, 10780, 5919, 8034, 7270, 29687, 24447, 21309, 24970, 19060, 7774, 5924, 2660, 23104, 27926, 16747, 17093, 26686, 5012, 10345, 27855, 15197, 198, 17723, 3670, 24061, 23429, 25718, 3622, 1330, 29300, 17252, 22582, 18753, 27400, 22083, 5554, 3757, 8955, 11945, 28053, 19679, 20456, 1875, 14963, 24538, 3773, 27344, 3582, 25150, 29229, 29832, 11433, 18078, 20832, 17707, 15382, 5117, 13944, 17722, 24270, 9208, 2420, 20745, 3632, 17107, 20608, 8025, 5173, 10506, 21992, 15627, 939, 1913, 20186, 11520, 5135, 23514, 18340, 15681, 8634, 20931, 26004, 26504, 17933, 15470, 7796, 9308, 11448, 8467, 12345, 19451, 6354, 3996, 5777, 22039, 23717, 21954, 16546, 2186, 18945, 4436, 6388, 5898, 1349, 23145, 7893, 19411, 15361, 21708, 5502, 17496, 23118, 24937, 25673, 20641, 21143, 29000, 5626, 24510, 1074, 29288, 21992, 29429, 7706, 12398, 7893, 16216, 19081, 25881, 2529, 22787, 196, 29510, 13606, 4654, 14513, 16263, 4928, 5804, 29078, 27467, 21911, 4494, 26368, 17288, 1430, 10575, 20596, 12318, 3940, 15011, 26754, 25892, 2408, 26648, 22773, 15315, 1249, 7528, 10147, 28854, 25180, 23228, 20784, 23853, 2366, 5457, 16309, 18713, 25619, 8548, 26289, 7332, 6363, 27509, 8279, 12778, 29012, 24951, 18679, 18979, 19376, 27755, 25000, 15595, 26952, 1021, 27959, 19556, 25600, 4101, 18461, 7796, 14052, 11004, 20427, 6899, 14323, 4212, 12142, 7859, 5744, 9754, 28660, 26250, 5789, 22035, 29857, 19196, 27722, 26165, 18762, 20585, 23499, 16231, 18790, 13121, 20563, 27072, 19569, 11063, 18660, 9402, 7416, 17767, 15677, 8515, 24743, 13688, 14932, 23702, 12378, 13811, 1285, 29241, 28535, 15132, 27086, 4062, 16192, 29579, 23443, 19729, 13675, 13341, 14357, 2668, 26761, 24162, 23696, 84, 24301, 16478, 5871, 26193, 3101, 14861, 24174, 14015, 16908, 14598, 11394, 4685, 18082, 2718, 28029, 24185, 8152, 4150, 17832, 25223, 18313, 6030, 14076, 5670, 7002, 10676, 11643, 26033, 8241, 14233, 1368, 28785, 8692, 18259, 19960, 7790, 21752, 25101, 25643, 22829, 17217, 14086, 18651, 2716, 10722, 16004, 3716, 22038, 426, 3272, 15492, 23920, 238, 11954, 6676, 28925, 12372, 25322, 27726, 10374, 14005, 23618, 12962, 19785, 21378, 5669, 8041, 195, 15909, 20429, 18749, 1177, 28357, 18148, 2565, 14768, 10276, 14135, 12425, 243, 27925, 27265, 27209, 15389, 24277, 17804, 4218, 11393, 10559, 21057, 26920, 19260, 19815, 13535, 22224, 27548, 23865, 16385, 17975, 5183, 6736, 1695, 26516, 18531, 24439, 7169, 12177, 17636, 15670, 24625, 17883, 20525, 25396, 11677, 26109, 864, 14905, 24423, 19172, 18834, 6376, 12150, 2022, 5473, 18459, 24271, 25240, 25405, 21955, 24353, 14819, 20977, 1529, 7244, 25269, 2513, 24789, 2012, 27891, 18171, 27833, 6912, 25343, 14561, 26067, 9655, 19007, 23667, 22162, 319, 5475, 16072, 15068, 9630, 1555, 20369, 4722, 29707, 12738, 19891, 10272, 25879, 27355, 25403, 6090, 23499, 7416, 25709, 6630, 23844, 19828, 21344, 9702, 10000, 5057, 4660, 15356, 12329, 28437, 8085, 24416, 19056, 13826, 25560, 3112, 28111, 8156, 25445, 13079, 29444, 13873, 1627, 19653, 21414, 22419, 27202, 6360, 14394, 16613, 17504, 28085, 15066, 24518, 15368, 14056, 9153, 20213, 16878, 7867, 119, 13729, 19699, 2922, 27418, 16749, 17320, 23619, 18470, 12735, 10190, 12401, 11697, 11536, 29490, 21308, 23175, 22998, 14491, 3746, 22672, 28157, 8845, 19597, 2827, 29044, 13641, 25171, 27556, 23355, 15788, 24272, 11636, 21500, 10226, 29447, 12793, 21570, 19507, 13712, 18044, 14703, 5270, 27728, 10341, 10771, 19049, 10004, 3898, 20012, 20561, 20235, 17653, 16286, 10961, 21472, 27792, 22132, 63, 18944, 9113, 11913, 10548, 13910, 18452, 9032, 19075, 28023, 15295, 18984, 20433, 28192, 23286, 4488, 3271, 20369, 26983, 1259, 9252, 16397, 12054, 27913, 29790, 3718, 1449, 15058, 25619, 18028, 14513, 5182, 28334, 13352, 19957, 1673, 7087, 18636, 27314, 20791, 16286, 9326, 16311, 21362, 8655, 16811, 29997, 5086, 23789, 542, 7517, 29675, 10730, 29238, 22713, 12981, 19430, 564, 19662, 22815, 7684, 29002, 13391, 13788, 20881, 28455, 8803, 5780, 29862, 4163, 11153, 9443, 2270, 10760, 9148, 1239, 26155, 18841, 17267, 2195, 26311, 17401, 28383, 9705, 105, 367, 8577, 26051, 20383, 5586, 14426, 27139, 1526, 27969, 9103, 28353, 4165, 22917, 3606, 4813, 8444, 28016, 27954, 29212, 20917, 3412, 2144, 7087, 7085, 8993, 18367, 24298, 21234, 16899, 29942, 12294, 2387, 11715, 23268, 28628, 24757, 12627, 22567, 17688, 10587, 12760, 26843, 27596, 16635, 1518, 29543, 7260, 5376, 6686, 9624, 26530, 36, 7094, 13403, 27560, 279, 18600, 11981, 25162, 11812, 16518, 15659, 12847, 9618, 7763, 2500, 3457, 10474, 2210, 24926, 26251, 39, 5199, 19253, 14695, 18983, 2113, 2774, 24165, 28067, 11144, 3131, 22859, 10761, 29702, 433, 14978, 29250, 22750, 18456, 7871, 24557, 2212, 18207, 24639, 29793, 28971, 13797, 10386, 5470, 5617, 19502, 20314, 10052, 11435, 27243, 26357, 12577, 7887, 1981, 23862, 19320, 15387, 8614, 9718, 22908, 9911, 28223, 14760, 8754, 3857, 27687, 9922, 19441, 32, 26200, 11109, 5030, 10846, 3042, 3781, 12876, 3855, 19732, 23736, 136, 16557, 6699, 11242, 10796, 4893, 27220, 14108, 14584, 12872, 4443, 14257, 19900, 3497, 5993, 26010, 2528, 28781, 28926, 21136, 19166, 24159, 791, 17520, 16171, 21928, 10537, 1163, 1910, 5379, 6231, 4677, 24042, 14901, 841, 23251, 28841, 28743, 16267, 22625, 23031, 22508, 4141, 19191, 11586, 10248, 21459, 12889, 28544, 21955, 23189, 22455, 3640, 3927, 25810, 7112, 27105, 23854, 1862, 10799, 2666, 8060, 6446, 1163, 15835, 28762, 6332, 9494, 17239, 23653, 26629, 6483, 20324, 17589, 15057, 16734, 20139, 29698, 2866, 17016, 4718, 2035, 3023, 27452, 29492, 14536, 16195, 1136, 23133, 19164, 26249, 21355, 17765, 12123, 23069, 1035, 21981, 29268, 5886, 3010, 7721, 13845, 19947, 3182, 16668, 18283, 1845, 2444, 18038, 15538, 3680, 17479, 26282, 10539, 5663, 980, 19390, 4767, 19843, 13699, 619, 1822, 5713, 15810, 8084, 23355, 8712, 22787, 9953, 29321, 4297, 20859, 29646, 19301, 15130, 2638, 10384, 26354, 7402, 14661, 25517, 23984, 13601, 27804, 8497, 12014, 16527, 29796, 2697, 22207, 5361, 4194, 3280, 10218, 12732, 15333, 10312, 6393, 25605, 18146, 517, 22907, 7398, 26480, 29715, 7182, 3593, 11545, 8136, 27254, 20693, 7778, 7757, 18689, 19466, 12062, 28740, 23203, 16463, 20124, 22318, 8001, 22274, 17788, 6780, 2068, 7142, 1554, 11761, 29376, 3339, 12117, 3396, 17538, 10253, 21554, 661, 633, 8646, 23496, 26642, 973, 14214, 11757, 29822, 20357, 4165, 2693, 11058, 13265, 21141, 20499, 3484, 28551, 14504, 2835, 22270, 11601, 22985, 20508, 6385, 21674, 3637, 8929, 10790, 28346, 11740, 27954, 10036, 61, 27160, 15414, 14174, 25755, 29888, 18647, 7310, 14392, 6618, 3510, 11984, 6991, 15788, 13417, 24662, 27156, 5587, 23675, 19749, 9324, 29761, 18574, 1067, 9692, 9763, 14282, 17870, 25206, 18305, 22664, 26273, 14105, 16911, 18604, 4667, 6777, 1737, 4581, 23051, 28336, 11652, 26137, 10532, 20550, 26478, 5499, 9145, 17818, 12266, 12496, 6839, 971, 27446, 15429, 8277, 9319, 12400, 16486, 25096, 15036, 13943, 16659, 10034, 6161, 7597, 4532, 13291, 12499, 10140, 3731, 15666, 27524, 10010, 21925, 18840, 27115, 10254, 24372, 17161, 8599, 25539, 993, 24475, 21163, 13693, 2789, 17729, 4781, 28580, 13221, 10620, 21761, 11459, 7338, 24030, 3916, 24149, 21434, 27426, 2034, 6809, 233, 21793, 5739, 7529, 29312, 12787, 1306, 29289, 5194, 4959, 5569, 4910, 17295, 8855, 20536, 28534, 4895, 7553, 5569, 17482, 28023, 13995, 19367, 25427, 23609, 6557, 11436, 14505, 14801, 22974, 10884, 1637, 5235, 11662, 88, 6887, 29405, 3334, 23714, 20716, 5198, 10154, 15765, 9666, 1562, 17778, 24235, 1410, 12300, 9834, 21629, 24687, 7172, 16496, 8377, 10327, 6919, 28828, 21565, 16201, 6963, 9999, 28698, 5941, 9385, 11408, 1469, 14317, 11888, 14956, 17771, 28234, 9785, 29899, 9572, 19657, 19797, 365, 2423, 11484, 26121, 13054, 16963, 28172, 27313, 10115, 12001, 19651, 23828, 16320, 25732, 22605, 16180, 26659, 8280, 3825, 26663, 20217, 19983, 24971, 11085, 12606, 25307, 10324, 6742, 28833, 20557, 23790, 22744, 1343, 24453, 18948, 1762, 15624, 10848, 21342, 20886, 10323, 12478, 8376, 6422, 1859, 591, 26067, 5545, 24870, 27987, 8084, 3505, 26191, 793, 20557, 3211, 5515, 8501, 25406, 17796, 28494, 7832, 12199, 17423, 17042, 14154, 19023, 16114, 19017, 27057, 20636, 12739, 12767, 7590, 1916, 14185, 25567, 16129, 25951, 24504, 5385, 4662, 4583, 29661, 26437, 2397, 8479, 25709, 2534, 90, 10603, 21506, 9167, 1290, 15211, 16294, 3529, 25583, 29148, 28385, 16718, 2941, 27468, 13515, 9160, 22200, 12410, 835, 27843, 7395, 24990, 11488, 2925, 5883, 24665, 16592, 12890, 13301, 15516, 29309, 29895, 10768, 8526, 15250, 9742, 6638, 6343, 4151, 27487, 4716, 5237, 9663, 5078, 26498, 7848, 24372, 352, 4595, 17253, 27332, 18309, 5775, 8531, 662, 27488, 15575, 18734, 16804, 27049, 11155, 5340, 10427, 28862, 457, 8002, 16568, 18163, 6096, 10229, 25535, 12940, 2300, 3258, 8925, 19021, 15725, 13937, 22425, 3605, 15795, 21800, 19694, 17290, 3959, 17566, 23161, 17085, 12072, 2222, 2095, 8701, 15388, 2333, 13218, 10382, 29525, 4990, 14860, 5123, 24124, 23972, 20175, 27795, 6739, 17610, 11439, 8358, 14279, 4566, 19000, 16486, 19655, 11265, 12551, 26418, 6424, 1436, 527, 20812, 15654, 22634, 966, 5782, 28462, 8226, 28012, 28489, 17361, 830, 571, 6339, 1227, 5824, 13907, 1543, 18045, 7952, 28021, 25456, 28008, 21292, 19810, 6653, 12778, 2747, 7749, 29583, 713, 14758, 1589, 17809, 19017, 12045, 27061, 4894, 27421, 22076, 6568, 2379, 17179, 5714, 13662, 7480, 29733, 6397, 27962, 23155, 10764, 8700, 28027, 29657, 29190, 21197, 26587, 12634, 27418, 7308, 4830, 29155, 18034, 18623, 2830, 12256, 27012, 8786, 28663, 2788, 4326, 28879, 2241, 17117, 5302, 6430, 18948, 23300, 22494, 14486, 9945, 14577, 9596, 2213, 566, 16224, 29755, 5636, 9143, 22984, 24161, 26643, 3992, 21974, 9288, 25057, 12322, 11590, 16262, 6433, 17925, 24345, 1614, 314, 27873, 26367, 20303, 27292, 11523, 6991, 16484, 6762, 29362, 24708, 5006, 25386, 4717, 24406, 4060, 19009, 21490, 23150, 16981, 15214, 21064, 12453, 29933, 12930, 10895, 17172, 14859, 3296, 8842, 22741, 13853, 120, 18552, 14553, 29590, 17087, 10812, 15459, 22965, 9832, 17461, 763, 2095, 1296, 2716, 11358, 1022, 18886, 13523, 26064, 1207, 19109, 25261, 6346, 21617, 20203, 13381, 18482, 23899, 7220, 2364, 18460, 7156, 17002, 12423, 21538, 5569, 17266, 16075, 2575, 29118, 2744, 2191, 28442, 28113, 19170, 11092, 6500, 9005, 19488, 7548, 3531, 20414, 27108, 18794, 23973, 26396, 22533, 29040, 16737, 27630, 26343, 6640, 15245, 2901, 21041, 9282, 29576, 9994, 11292, 7986, 18222, 6233, 29662, 15361, 18764, 17633, 28187, 22240, 8551, 23940, 7995, 26819, 20598, 25775, 17105, 16928, 5641, 21501, 27800, 27301, 6408, 5411, 12670, 5860, 24481, 10734, 9110, 3239, 3788, 28421, 2799, 24810, 2912, 11158, 15565, 6808, 12611, 5642, 28993, 1051, 17311, 23001, 5196, 18758, 9021, 11921, 25509, 22237, 11342, 7826, 5993, 26221, 3775, 18519, 6340, 10375, 8861, 1597, 10551, 29210, 21102, 1251, 9851, 24215, 20625, 6601, 23561, 11771, 6814, 26348, 23793, 25493, 1643, 1946, 5582, 21039, 14889, 11642, 6568, 5984, 27682, 14988, 12572, 24950, 3640, 19049, 3724, 397, 4874, 5465, 17723, 12582, 9223, 3754, 3619, 16929, 25032, 17204, 19321, 23118, 10146, 23398, 21309, 2874, 1823, 23312, 7926, 8559, 104, 642, 9486, 2407, 6559, 28399, 24955, 21637, 2955, 13351, 26461, 20214, 3027, 9128, 3999, 2501, 10980, 15095, 24811, 20742, 22379, 3267, 13600, 20035, 26139, 8008, 14656, 12786, 10943, 13488, 29314, 26151, 4616, 20934, 20084, 20468, 24603, 28798, 22145, 2499, 20337, 23468, 19156, 21095, 696, 1873, 3078, 7590, 24655, 4647, 23103, 21691, 21980, 22617, 23564, 16490, 8825, 25497, 27852, 24272, 3912, 27887, 18537, 3646, 21708, 11434, 4248, 19421, 3820, 20407, 5601, 22189, 24846, 26730, 28869, 21334, 26800, 28065, 15983, 28444, 19265, 5786, 26659, 435, 19312, 20163, 11839, 17196, 26392, 1675, 24871, 21463, 18909, 16980, 27448, 3377, 15962, 12934, 29480, 11855, 24250, 15265, 10119, 23536, 17261, 27453, 14043, 23760, 25770, 3792, 12118, 8952, 27225, 28674, 17957, 2109, 16546, 25070, 3116, 8376, 3884, 2611, 17640, 1265, 19472, 7946, 9389, 25312, 19640, 23212, 20119, 14414, 6234, 29663, 7815, 15457, 17354, 2588, 24773, 6260, 8970, 28238, 12380, 14394, 10331, 1458, 13567, 8328, 19815, 3854, 911, 25615, 8896, 2901, 11359, 20874, 16589, 15085, 21283, 27401, 4269, 5486, 13954, 13695, 22788, 29432, 19490, 13668, 20273, 17650, 5736, 18799, 1816, 20672, 11606, 3282, 4604, 26276, 13362, 20144, 16043, 24056, 7126, 3759, 19854, 23395, 10691, 10850, 13676, 9304, 25266, 26195, 12603, 16499, 23498, 27587, 13177, 25071, 20097, 13775, 24765, 22218, 3904, 23375, 24918, 28754, 1116, 24818, 13714, 19237, 22363, 6093, 1148, 2356, 10701, 27096, 28062, 13847, 20109, 27316, 1836, 25326, 24463, 18558, 29024, 7884, 20424, 3674, 1374, 4966, 26671, 21316, 28001, 3826, 17107, 8256, 19465, 19793, 4961, 12000, 14587, 17993, 10226, 22767, 7277, 13238, 10408, 20220, 15828, 10123, 3918, 23427, 28292, 22995, 15236, 9820, 20162, 26520, 23968, 1581, 7905, 10578, 1399, 25269, 15003, 2392, 23511, 5686, 390, 10005, 14812, 16814, 1476, 13727, 20408, 27176, 11906, 961, 2322, 17569, 17813, 29934, 18632, 9621, 6764, 18637, 29365, 24493, 19822, 20545, 16586, 27340, 25073, 5867, 1228, 6068, 9698, 11007, 12438, 3189, 18557, 28285, 2916, 10684, 14136, 21489, 23638, 27469, 10752, 26827, 1819, 4083, 15712, 17154, 4494, 24799, 23752, 3724, 6580, 19827, 16376, 7550, 11071, 16410, 19139, 4291, 10490, 20545, 26649, 18606, 18774, 6554, 26734, 9166, 17550, 15965, 2464, 11665, 5376, 5406, 10918, 16485, 24403, 10286, 22636, 28026, 15880, 17768, 5754, 18449, 26471, 19220, 18468, 27753, 2478, 8657, 20270, 22197, 10582, 4175, 8098, 11688, 13253, 3524, 11232, 10698, 18346, 16400, 16594, 13062, 3992, 8876, 8396, 1084, 10492, 28236, 19577, 20701, 24185, 2514, 3363, 10232, 7128, 7046, 8782, 21222, 6060, 10321, 12616, 12724, 12153, 24327, 20510, 29153, 8609, 2442, 19117, 25645, 23223, 23489, 21376, 10948, 19830, 728, 21902, 15439, 25997, 16736, 2707, 29555, 21949, 24689, 22602, 384, 15439, 6202, 12270, 19699, 3076, 25111, 7895, 10645, 15313, 11222, 15221, 16699, 10671, 10874, 13690, 2983, 6723, 6476, 16550, 22715, 5542, 29943, 1716, 25756, 21917, 11263, 10501, 24249, 27379, 28172, 23010, 23743, 8034, 29867, 3132, 17925, 5758, 5038, 27622, 18802, 2066, 8311, 28127, 24886, 1813, 5205, 23653, 6662, 17215, 103, 8313, 29882, 10545, 1309, 11175, 6090, 10422, 17972, 28485, 13999, 22224, 15875, 5614, 27621, 28027, 11245, 3178, 4646, 6276, 14711, 3032, 27277, 22230, 18366, 8753, 1535, 26781, 19777, 14823, 8562, 4151, 1600, 29925, 23756, 18489, 7382, 20693, 24587, 21876, 584, 20554, 5030, 16956, 395, 4617, 6874, 4232, 24812, 23084, 12936, 12656, 17381, 7047, 4975, 15434, 6434, 27364, 17735, 28998, 3686, 17384, 14186, 25056, 28455, 2406, 18136, 2455, 23798, 10729, 9317, 446, 4821, 13431, 29441, 7722, 19301, 8136, 3624, 8974, 9148, 13261, 4582, 29102, 2173, 2805, 16152, 17287, 3114, 11009, 18437, 26720, 19116, 3652, 925, 1467, 10041, 6950, 7550, 29301, 6194, 17539, 28725, 10115, 6418, 7167, 28627, 11637, 22029, 954, 24221, 23475, 23812, 27185, 12626, 19218, 22430, 1193, 6247, 19258, 21682, 19341, 22979, 70, 10106, 14081, 15226, 6221, 18473, 9730, 6999, 5765, 7585, 21102, 5832, 16694, 8566, 10609, 21713, 12985, 11142, 14042, 5069, 17624, 1313, 8900, 29816, 13688, 22349, 12702, 8163, 851, 25188, 24994, 299, 20982, 1946, 19682, 28090, 17705, 23680, 632, 14428, 27059, 25192, 18200, 26705, 10054, 3066, 5172, 18139, 25523, 26020, 14531, 1318, 6047, 21953, 19222, 13637, 25946, 4506, 3059, 21278, 7556, 20972, 1890, 469, 22249, 19221, 26384, 28859, 14753, 26899, 3492, 6283, 159, 12901, 21084, 8740, 5130, 17566, 11821, 8351, 20213, 7706, 23281, 10594, 16781, 18922, 15958, 14544, 11982, 3979, 1827, 9616, 23546, 21286, 21133, 8215, 10965, 11119, 15475, 27883, 3124, 25742, 17749, 28778, 5832, 24437, 19411, 3565, 22380, 19409, 18044, 23712, 29618, 12653, 10021, 19639, 9152, 3208, 11337, 28226, 21334, 28473, 5276, 3112, 25263, 22948, 9721, 20620, 14517, 13484, 6909, 17736, 17878, 5457, 8556, 16941, 2894, 3356, 8612, 8647, 21378, 507, 765, 20314, 8777, 13839, 17417, 3672, 25061, 12067, 13755, 27935, 8823, 5651, 16847, 4636, 13458, 6359, 18201, 3095, 4353, 18396, 9402, 15172, 28291, 12990, 7229, 23334, 18260, 15625, 25284, 29273, 19383, 24928, 10669, 18332, 8797, 13010, 28562, 12776, 16653, 1023, 2948, 10358, 23083, 21383, 5242, 28756, 14924, 20340, 26295, 7554, 16115, 20368, 7188, 16947, 18093, 4832, 15184, 15396, 17474, 3551, 28823, 6705, 12100, 25208, 25364, 21818, 16568, 5809, 3665, 27896, 13887, 25965, 18534, 22965, 27123, 3389, 14630, 3477, 8189, 27591, 19031, 27895, 15066, 10505, 15291, 12663, 1497, 21891, 4917, 8215, 28365, 27720, 26505, 22602, 29382, 5956, 4036, 21103, 19800, 15318, 11340, 20971, 13349, 7040, 28905, 12438, 14151, 24963, 26557, 21809, 20552, 19813, 12305, 7181, 13682, 9034, 3219, 1040, 9015, 17951, 20094, 21675, 24935, 3756, 12338, 12009, 10080, 25187, 263, 17139, 24587, 20562, 19528, 10561, 11810, 24037, 325, 28912, 2306, 11377, 9880, 18895, 23596, 26173, 14361, 1683, 28163, 29945, 25726, 9949, 18887, 26262, 1732, 7375, 1844, 8513, 14620, 959, 9455, 20106, 9312, 29296, 14869, 10610, 4138, 18874, 27318, 28540, 16769, 18727, 16375, 26086, 2112, 23343, 21988, 15864, 16926, 26381, 5194, 17172, 13446, 20031, 16043, 26166, 16028, 2797, 10777, 1487, 19815, 13287, 28324, 15297, 12735, 27691, 26783, 17051, 11001, 27190, 10085, 6165, 16020, 22449, 10991, 25260, 2384, 10270, 1128, 1382, 27247, 11777, 18501, 9767, 15177, 2685, 21346, 16505, 20797, 17032, 27176, 27419, 26051, 13537, 21388, 11047, 27092, 7659, 26575, 5588, 28231, 5810, 1483, 3783, 20174, 5355, 9743, 1801, 25345, 12278, 11995, 1131, 3681, 11981, 3422, 3638, 4541, 18983, 24709, 8678, 14091, 2551, 15138, 1843, 23213, 14692, 6855, 664, 962, 10236, 23329, 15628, 6577, 10619, 24588, 12746, 27403, 20793, 14425, 13068, 1647, 20464, 3900, 19315, 1545, 10066, 7857, 18171, 218, 1798, 8941, 3603, 24568, 17899, 24935, 7186, 4214, 16171, 5956, 13331, 9887, 16139, 19668, 20119, 6461, 3051, 13386, 2968, 1765, 19703, 14509, 16097, 3836, 12425, 27035, 25906, 21066, 17263, 28185, 18573, 13010, 16888, 6492, 19961, 17141, 14608, 34, 22404, 19921, 26270, 27217, 16722, 25055, 10022, 25279, 23503, 7966, 17280, 18365, 21892, 9068, 21500, 6253, 17789, 9294, 24133, 19197, 11102, 14409, 16312, 11615, 28578, 27180, 12622, 7330, 6276, 29994, 20657, 6594, 21058, 10801, 20344, 23549, 10322, 17236, 8264, 1461, 21384, 19285, 13637, 7042, 1802, 24231, 24406, 5872, 24377, 15152, 3179, 22849, 16000, 7785, 8865, 10675, 18217, 14593, 13540, 5088, 5844, 7020, 9940, 15017, 5116, 3350, 11463, 28942, 9117, 1319, 4321, 20409, 16069, 1644, 17882, 15494, 11906, 4850, 26954, 21381, 12353, 13998, 19880, 23972, 28209, 24850, 11467, 12144, 13316, 18180, 12601, 23424, 11317, 28786, 10364, 419, 5229, 4862, 29845, 11473, 1685, 10410, 5427, 6007, 29444, 5492, 18767, 8704, 6162, 29215, 19713, 17314, 12477, 25978, 7792, 14088, 26353, 1294, 19223, 24584, 9561, 412, 17006, 5426, 6381, 23649, 19071, 10731, 28294, 25887, 4400, 12348, 3437, 18872, 10374, 24879, 2798, 23470, 18684, 14593, 10948, 20174, 7234, 2544, 6857, 24856, 17217, 1266, 24133, 2115, 5577, 8189, 6845, 26714, 6523, 24707, 17012, 23931, 15299, 28450, 314, 11848, 16103, 7629, 2929, 28741, 26879, 15079, 20726, 26132, 3045, 2575, 17625, 12922, 26325, 10045, 4156, 19745, 3466, 25044, 14856, 4383, 7151, 7861, 10110, 8174, 10138, 13818, 479, 11022, 15206, 16424, 5440, 5254, 23506, 7333, 11952, 19253, 1743, 4527, 17622, 29272, 29607, 21148, 9285, 10394, 19613, 14383, 15538, 20792, 17714, 15620, 17686, 6094, 29141, 23337, 26303, 28353, 5869, 14450, 16711, 23727, 13391, 20158, 12389, 6200, 2436, 29581, 22345, 12459, 25334, 11688, 15496, 18270, 11807, 9113, 5471, 22531, 23444, 25219, 2175, 335, 10140, 19, 4322, 24449, 27736, 23428, 26337, 18040, 21769, 12195, 22005, 21367, 397, 774, 707, 12725, 26183, 9616, 9330, 1078, 6376, 18496, 27909, 21613, 11185, 15938, 11674, 7045, 26094, 19034, 22651, 10646, 26691, 25175, 27750, 61, 367, 15122, 12739, 2131, 6776, 18220, 18411, 23643, 14980, 441, 25351, 3406, 26856, 24057, 16877, 29758, 4211, 16140, 20168, 5727, 10207, 25339, 14926, 11968, 20438, 11609, 156, 2378, 5288, 5886, 27378, 20120, 5952, 2184, 9553, 7598, 12060, 6282, 18028, 19350, 2900, 3540, 15606, 4626, 23580, 21710, 7201, 19063, 27366, 14664, 27856, 9976, 8848, 7592, 20043, 17452, 21556, 29750, 22907, 7745, 926, 24979, 2319, 12910, 7867, 1252, 14322, 8407, 24993, 26656, 21796, 20652, 17546, 21391, 20741, 25302, 19328, 6275, 5127, 5728, 27157, 27150, 16763, 1237, 14554, 24005, 25611, 16136, 15907, 8619, 13407, 4406, 23477, 2704, 26046, 22526, 1132, 10436, 22958, 16423, 29726, 28689, 10759, 25823, 1183, 12268, 4436, 11461, 12358, 26149, 29817, 18812, 20881, 11324, 2042, 7315, 10891, 8832, 8594, 20061, 26546, 15670, 17186, 29100, 7883, 20472, 8304, 6770, 7098, 5794, 21625, 22662, 29675, 1223, 29908, 20987, 28314, 24535, 13658, 25248, 24644, 19960, 22759, 12471, 10888, 3711, 2510, 5472, 10940, 24497, 18163, 13335, 10962, 9754, 5203, 4021, 29203, 29299, 27400, 27341, 29395, 6444, 6246, 27719, 20158, 26713, 11264, 24080, 16334, 5707, 26543, 21597, 2891, 4282, 10329, 16449, 13048, 3706, 18581, 25876, 11285, 2393, 22572, 20971, 3316, 17782, 11293, 17037, 28398, 27747, 16222, 6932, 15301, 26662, 23402, 111, 19144, 29605, 27972, 9887, 24045, 888, 11907, 12328, 14070, 23934, 1938, 21677, 16132, 15139, 20896, 7965, 4844, 5040, 3141, 25907, 16835, 10781, 3093, 29954, 14356, 5894, 6381, 23317, 16023, 4966, 548, 27744, 8670, 26260, 21313, 2828, 4470, 2097, 16292, 9354, 4513, 11074, 10937, 11717, 10460, 13394, 1881, 12913, 6381, 23180, 13077, 4593, 11180, 1665, 22188, 26865, 24060, 1457, 23470, 3945, 23813, 29808, 2767, 25265, 17201, 14845, 15504, 12554, 19882, 11057, 16635, 10031, 14417, 10257, 20103, 9856, 10668, 12592, 6211, 737, 24114, 29629, 5845, 1643, 23445, 20911, 7043, 4965, 8597, 16885, 13533, 1565, 1156, 9525, 10241, 884, 11770, 16526, 2214, 10033, 25437, 5740, 19080, 17160, 4158, 27747, 15194, 8289, 28476, 237, 26028, 14982, 13469, 935, 1162, 22316, 12303, 7263, 4523, 1850, 23424, 1074, 25205, 8886, 136, 15840, 27593, 25280, 3926, 12312, 23137, 28773, 13482, 24813, 19495, 28644, 29647, 4720, 3252, 18084, 5442, 21927, 8314, 8938, 24501, 17964, 21470, 2472, 13537, 10046, 6564, 10713, 27619, 9903, 10370, 6372, 9820, 5119, 4582, 13219, 12677, 26489, 967, 24707, 11620, 22959, 24895, 15272, 20456, 26825, 11388, 21199, 12251, 667, 20139, 6197, 11415, 673, 17557, 25307, 22061, 4540, 29426, 20507, 24028, 8203, 6149, 22484, 13476, 15872, 27222, 8663, 9166, 14119, 16364, 10159, 11579, 7139, 3991, 23287, 7908, 11811, 26670, 595, 19634, 26980, 19372, 17816, 27524, 17812, 509, 9075, 27386, 26751, 6900, 17116, 3767, 7510, 22042, 9611, 20670, 22064, 20158, 20662, 4398, 3409, 26578, 16180, 23063, 12834, 733, 12458, 12454, 1830, 9344, 28501, 22447, 11047, 27874, 3392, 11101, 1332, 13277, 29455, 15230, 15353, 6410, 6315, 21137, 15906, 28772, 22795, 9617, 27899, 15356, 1943, 25304, 16673, 25337, 5945, 21544, 17649, 17561, 13199, 12220, 18217, 18161, 8749, 15352, 18810, 4685, 7446, 19421, 7866, 4458, 14542, 21550, 28497, 29502, 13609, 3808, 26414, 4996, 26100, 4797, 11080, 16889, 15807, 17891, 4910, 634, 6686, 23937, 1077, 5295, 10773, 1826, 4604, 5454, 29793, 15850, 5641, 12475, 16141, 27522, 3581, 981, 7449, 660, 26465, 8447, 19633, 2182, 10288, 20467, 2414, 5614, 27074, 6041, 14516, 11867, 7435, 26195, 15674, 17874, 2680, 18972, 21451, 8954, 15307, 12220, 17710, 11436, 26489, 10756, 25777, 14459, 9208, 16252, 27334, 23152, 20848, 13764, 29703, 5013, 1845, 26231, 21330, 10154, 25465, 4535, 24909, 22791, 27619, 11657, 13341, 19623, 14301, 20216, 12855, 25178, 2352, 24567, 7382, 25752, 28696, 24852, 29212, 3284, 26164, 24547, 27873, 7407, 19716, 2824, 8870, 374, 22008, 563, 22332, 9563, 21937, 24355, 22017, 4838, 28288, 14716, 26583, 11458, 21447, 29957, 1142, 7560, 6507, 21059, 29976, 27634, 3950, 20673, 8057, 19201, 1735, 11770, 23339, 7414, 1809, 26252, 7297, 9353, 27898, 27099, 11691, 11745, 18144, 29015, 933, 23906, 17941, 11896, 17244, 10146, 2965, 9941, 20927, 16437, 3739, 21280, 9234, 17114, 29774, 17250, 12996, 4256, 22527, 3362, 26866, 2606, 18326, 3045, 17152, 11871, 17353, 15218, 4071, 19653, 8084, 2153, 6575, 21093, 1332, 3364, 25903, 19623, 23751, 8408, 10714, 2770, 18326, 13921, 4161, 18571, 15621, 18677, 4357, 28610, 9454, 28808, 25516, 924, 23758, 22008, 21295, 28307, 22381, 5192, 8069, 20302, 8473, 26131, 27597, 8508, 7816, 13134, 13192, 13019, 26561, 29518, 21871, 28056, 20926, 28708, 22514, 8058, 161, 26583, 25555, 8793, 17506, 15543, 5914, 10677, 13086, 3569, 22207, 14010, 22618, 22714, 23101, 12555, 9397, 14849, 18630, 9534, 5909, 22147, 23457, 2780, 2445, 16253, 27480, 11237, 21175, 5515, 18882, 20716, 9896, 8931, 14213, 21700, 20977, 20506, 17757, 9894, 3893, 3911, 23875, 1991, 16191, 1944, 6736, 6846, 20928, 11417, 262, 11037, 27228, 8303, 18604, 22014, 18389, 28265, 16262, 22827, 11456, 17238, 6479, 28806, 15864, 20966, 19295, 6378, 8131, 2018, 7382, 17054, 12849, 6905, 17677, 1457, 23896, 23748, 731, 28784, 21168, 13400, 17966, 26050, 25294, 26764, 9428, 1196, 15442, 16025, 2142, 7411, 2216, 2932, 4339, 2381, 14670, 21088, 25382, 6122, 26721, 26047, 18517, 8612, 25879, 14813, 14526, 12880, 18597, 14892, 6394, 19104, 2187, 22837, 14289, 15678, 8591, 21849, 7524, 25081, 28209, 12744, 29064, 18697, 1217, 81, 13962, 6196, 5527, 11064, 19835, 2436, 9535, 27830, 2960, 18952, 12563, 19510, 21737, 7106, 6377, 8478, 27083, 2667, 2326, 8165, 3366, 11946, 6786, 11021, 9633, 1417, 29187, 26183, 17095, 16910, 20686, 15112, 28984, 28048, 29282, 20183, 23890, 27063, 21573, 26104, 12884, 4452, 24943, 9700, 15109, 25449, 27635, 11389, 24032, 2856, 17162, 14877, 15838, 6598, 1937, 29282, 6829, 15324, 9547, 24209, 25488, 4149, 13551, 23428, 16905, 5062, 22602, 25156, 796, 13211, 7598, 11396, 2793, 12447, 24694, 4557, 9632, 14338, 18205, 10520, 5882, 943, 28091, 15361, 11173, 8326, 23894, 921, 62, 7783, 16798, 18485, 7073, 25539, 12162, 16704, 12338, 3923, 4555, 22507, 7105, 27529, 26045, 3480, 26526, 29273, 5394, 17282, 933, 18658, 15692, 2577, 22536, 12101, 9403, 14693, 11696, 14463, 27624, 17721, 29496, 11844, 5336, 5512, 3648, 1927, 822, 13342, 16395, 26959, 6794, 27073, 13836, 22929, 2419, 14483, 7648, 2625, 8329, 16975, 24219, 13508, 15342, 20046, 5787, 22027, 15937, 23621, 24218, 23403, 6383, 8139, 14650, 19441, 18367, 10347, 18530, 21727, 10204, 9905, 21997, 24360, 16508, 8808, 19088, 14093, 15692, 810, 15203, 19647, 13836, 24718, 27553, 29191, 9862, 4660, 3714, 9634, 9524, 4424, 16911, 14501, 17920, 12846, 14541, 13731, 8702, 29021, 9758, 26792, 12969, 1351, 28518, 22680, 17756, 9023, 3657, 22916, 18683, 7040, 13835, 26436, 9862, 26761, 2289, 19636, 2405, 20414, 13756, 1003, 15218, 21671, 6757, 4153, 6619, 20280, 3537, 14635, 2520, 13148, 7035, 17844, 6212, 1690, 19193, 4562, 4977, 1544, 13175, 9185, 23204, 1691, 7262, 9082, 15032, 16668, 29983, 6084, 71, 14809, 4754, 24452, 2048, 13211, 13610, 1075, 17456, 20217, 13267, 23675, 15366, 29455, 13297, 18528, 29292, 12434, 23989, 17050, 16057, 17472, 5606, 5769, 1894, 28762, 28021, 15530, 2831, 7252, 8029, 23759, 19906, 17836, 8255, 22935, 9558, 27955, 8406, 5751, 28878, 23997, 16531, 11080, 27241, 16537, 22642, 13185, 26376, 23008, 18849, 28186, 17580, 10525, 14349, 26670, 21437, 11935, 3288, 864, 1610, 495, 15690, 27579, 9026, 13522, 24122, 20127, 20369, 1972, 13258, 4367, 23820, 3742, 5775, 1344, 12246, 10842, 11103, 27549, 25768, 9122, 12167, 13028, 13714, 21687, 573, 21717, 21666, 11775, 5262, 6254, 16863, 26998, 1133, 12837, 826, 20784, 6326, 14405, 1618, 26508, 23212, 12633, 15085, 7285, 14538, 16627, 7160, 27192, 22792, 4292, 7384, 25717, 17676, 10283, 23397, 10319, 25547, 18328, 15731, 12536, 3375, 18061, 25684, 140, 13158, 14139, 24, 19873, 5551, 1541, 6041, 11689, 26132, 6103, 12728, 16267, 4108, 27403, 1296, 18270, 14761, 20024, 24347, 4265, 15570, 21433, 14366, 22908, 18716, 16672, 23048, 18371, 15591, 24983, 29029, 20244, 9935, 19424, 22975, 4743, 8735, 29488, 5407, 13364, 842, 5731, 28164, 22582, 19169, 29478, 19624, 19480, 9374, 1596, 6500, 23598, 13810, 8071, 21197, 6385, 16124, 26372, 21209, 9355, 4804, 887, 7739, 20129, 13675, 11235, 16721, 3889, 14227, 1685, 10397, 11732, 1547, 18401, 20437, 22421, 19978, 13863, 5503, 20072, 2983, 28431, 5883, 28680, 4771, 5489, 29415, 4653, 11336, 17317, 21102, 23478, 18396, 18898, 12598, 23577, 3424, 11827, 22859, 8702, 14685, 7538, 12351, 14679, 26434, 8334, 25051, 25106, 28085, 23260, 27823, 10153, 3057, 22670, 8998, 22980, 23777, 17476, 24095, 25522, 5812, 22255, 15900, 4776, 22055, 17251, 13555, 1749, 7399, 23148, 4241, 22520, 3286, 29290, 22938, 27140, 1160, 15564, 8707, 19570, 24958, 8149, 11874, 21218, 26397, 3437, 7839, 4898, 29653, 28863, 29009, 2574, 1036, 7983, 22169, 9153, 20693, 4861, 27113, 4592, 15686, 10117, 8638, 5321, 4721, 11776, 20792, 11672, 27650, 14857, 8773, 28131, 24198, 9497, 15869, 9390, 3337, 28973, 642, 10028, 2648, 24966, 2860, 27808, 7628, 28134, 16906, 23032, 14300, 14961, 22145, 10904, 26598, 6658, 6574, 23354, 6373, 10409, 17841, 12509, 25428, 22627, 23835, 2967, 2296, 13698, 12178, 13503, 2975, 8092, 23211, 1739, 25380, 850, 21014, 7877, 29397, 10849, 2365, 18209, 25189, 12442, 20139, 20156, 13770, 8721, 26031, 17135, 19291, 22725, 11331, 6555, 109, 9577, 16480, 15005, 25549, 429, 15685, 13253, 21267, 8487, 5659, 24910, 22056, 17149, 25648, 2043, 11887, 20081, 21717, 7593, 7389, 22893, 1579, 4227, 14592, 21455, 17735, 14333, 19079, 16828, 3323, 9701, 10963, 17372, 23630, 22435, 22447, 20415, 9081, 27243, 9566, 29086, 24678, 3758, 29009, 19464, 8442, 11240, 7735, 19359, 9448, 26100, 19615, 26631, 5580, 373, 6339, 7181, 23138, 26144, 290, 7802, 22254, 23212, 28568, 4013, 26741, 5120, 11871, 14798, 15355, 6550, 9392, 14794, 18016, 27444, 960, 21500, 9100, 8133, 29795, 1000, 18729, 27056, 14662, 11450, 22013, 120, 17892, 8847, 5632, 9045, 17499, 11686, 23804, 17622, 10126, 5794, 5024, 14725, 25968, 10139, 2036, 18776, 20716, 9846, 12785, 23866, 26655, 1895, 4285, 19790, 3472, 10488, 9824, 20070, 7134, 27196, 12247, 13236, 8630, 2710, 7369, 10453, 16587, 15801, 13001, 19452, 19507, 14934, 5928, 11058, 27326, 17318, 793, 15755, 3192, 4538, 24763, 26203, 21576, 28725, 4772, 28184, 3604, 7863, 247, 9477, 21392, 20447, 17679, 14797, 17724, 22682, 18909, 11236, 2346, 2416, 26880, 17479, 25947, 23193, 16992, 8961, 7773, 19410, 16874, 25834, 5543, 24888, 11050, 26491, 5609, 4026, 10945, 10621, 24090, 6506, 25654, 9908, 20095, 10411, 3116, 12864, 26559, 27358, 20797, 10051, 18527, 10228, 14573, 5828, 17235, 16151, 29880, 28774, 16200, 21985, 4268, 10851, 17902, 16194, 2583, 11036, 678, 15523, 28707, 27282, 23839, 7689, 1772, 25884, 29476, 2972, 10894, 28531, 25892, 24335, 21540, 6724, 29695, 2399, 2533, 13571, 12376, 4943, 626, 18507, 29101, 22280, 28764, 2152, 25120, 21294, 7871, 21303, 21542, 602, 4105, 11600, 17232, 22566, 11711, 19470, 11119, 14939, 7299, 20688, 4580, 15085, 15232, 12799, 1447, 17854, 28147, 24151, 12416, 5226, 18450, 12478, 21282, 5602, 2853, 20140, 2225, 14807, 6282, 20558, 18262, 27379, 27521, 14094, 6059, 6102, 28362, 28053, 13618, 4583, 10813, 19825, 8306, 25278, 6613, 9726, 25031, 3807, 10634, 9096, 235, 9765, 1009, 11555, 27335, 17177, 7691, 29804, 27515, 23662, 21648, 25760, 15023, 574, 12970, 2748, 10702, 9177, 5876, 11683, 11495, 11952, 10604, 29259, 28653, 23452, 11767, 5658, 10724, 4979, 26650, 3962, 1921, 23758, 8379, 2757, 29476, 3813, 1146, 13877, 24499, 20692, 2628, 386, 29042, 5043, 15774, 23145, 14297, 9734, 5349, 27539, 23180, 23712, 16347, 27777, 25928, 15893, 9753, 500, 19251, 4239, 27137, 2575, 14777, 7661, 5057, 4993, 2743, 29653, 11712, 28698, 24547, 18524, 25348, 7459, 431, 16611, 12167, 2659, 14946, 27928, 16120, 9983, 17207, 2652, 20803, 9035, 20434, 21196, 11260, 19714, 5131, 4302, 3255, 8622, 17152, 24439, 21160, 380, 4045, 6345, 6954, 29837, 21516, 14923, 23940, 4962, 13186, 22439, 11690, 11058, 3351, 23856, 11393, 17324, 11337, 8123, 17742, 945, 4681, 19856, 3428, 19240, 29854, 3611, 1683, 22623, 17213, 457, 19359, 19038, 20698, 6568, 21427, 13699, 10902, 10012, 21016, 9563, 11685, 16632, 12115, 469, 29951, 18439, 23942, 11968, 12652, 17103, 6942, 5736, 27435, 27749, 5043, 10045, 4154, 28932, 24492, 26769, 2882, 27839, 16703, 3790, 2980, 10565, 14832, 1261, 14356, 26902, 2303, 13989, 3022, 6870, 11274, 14933, 456, 2005, 20830, 2474, 16240, 17912, 3803, 15640, 12141, 18089, 4793, 27343, 10939, 18075, 3065, 20647, 12492, 7721, 11813, 14861, 15769, 10281, 26545, 11891, 12479, 27722, 4959, 10409, 26893, 6261, 20385, 26656, 15622, 23062, 20692, 3455, 14841, 24679, 24365, 20393, 28070, 10091, 4362, 11283, 4451, 14124, 23995, 2853, 16549, 7764, 11687, 8910, 8378, 19970, 15786, 21196, 16379, 28267, 809, 10075, 22380, 5226, 8390, 22990, 11842, 12184, 18042, 13219, 11619, 2178, 6475, 9512, 5232, 29610, 3463, 10594, 11740, 27792, 3676, 23155, 5686, 2310, 21663, 11733, 22374, 21985, 24217, 15713, 1712, 5975, 21034, 6940, 24609, 19577, 15580, 5993, 2800, 12861, 19708, 19244, 5828, 5422, 19041, 17361, 28718, 6104, 10178, 16929, 27413, 27834, 16383, 7408, 20469, 25249, 12209, 28966, 15852, 22098, 13121, 4230, 947, 17482, 5549, 5559, 11250, 17924, 5561, 24343, 8547, 8329, 17929, 21000, 2736, 7368, 3133, 20338, 3730, 26087, 23888, 24215, 20077, 17409, 19484, 7578, 17589, 9708, 21925, 5304, 13577, 27927, 26458, 10715, 1093, 7348, 22013, 26677, 9081, 6982, 10565, 9396, 4253, 23059, 8608, 12255, 22085, 20044, 3076, 4903, 11492, 25591, 26263, 2852, 5464, 4308, 148, 23027, 22108, 24473, 22418, 24856, 2624, 12081, 13077, 27295, 15912, 20072, 22250, 14516, 2569, 8894, 27540, 11242, 9709, 8104, 5249, 1353, 16307, 23607, 17325, 14583, 25554, 4947, 2086, 7645, 2069, 21292, 11613, 4781, 2528, 15340, 2211, 20765, 24292, 13380, 2844, 22174, 15353, 14836, 28719, 11747, 25086, 16719, 28551, 11325, 18491, 28667, 1622, 10888, 16156, 5949, 17637, 15017, 25766, 29886, 6748, 27557, 10331, 4036, 3117, 11395, 3162, 9827, 7465, 9089, 23748, 21773, 16120, 6180, 11435, 20954, 29398, 6284, 27996, 25198, 7236, 4516, 17105, 25741, 9238, 6400, 20106, 23434, 12760, 2068, 14710, 20608, 14505, 12213, 407, 105, 16061, 12766, 22963, 29765, 15798, 29970, 1323, 4731, 11940, 1188, 2531, 5170, 14177, 15641, 26291, 20661, 28019, 29015, 5614, 26498, 15904, 19549, 21323, 2958, 4470, 12655, 90, 14997, 9285, 29997, 6033, 18601, 4513, 14672, 26790, 577, 12501, 25045, 3629, 8195, 19356, 27110, 2317, 25224, 6459, 9325, 15306, 26128, 9380, 3747, 3610, 23982, 18766, 14539, 12947, 10694, 24272, 8801, 15638, 2519, 1223, 1592, 10643, 10594, 16851, 2324, 29148, 26480, 4932, 24381, 19450, 25417, 17343, 3953, 7199, 12978, 14606, 21349, 4004, 11436, 24491, 6632, 20238, 20975, 28383, 7729, 9312, 26204, 26834, 18835, 22157, 27504, 13470, 11973, 6447, 15201, 17569, 4964, 6776, 1964, 18529, 12045, 2486, 19501, 4886, 11555, 10604, 23094, 22483, 2690, 27565, 7931, 14460, 14885, 3258, 16201, 8461, 7918, 18222, 11104, 17599, 387, 11100, 241, 17721, 11330, 2974, 26414, 23748, 13275, 24908, 12079, 26611, 8909, 25023, 26120, 9052, 23849, 2108, 7280, 21083, 13726, 25945, 9122, 23771, 14508, 25599, 17807, 18317, 12045, 15669, 22727, 24951, 10115, 24350, 16152, 28753, 28120, 6944, 21901, 2319, 27978, 24791, 6036, 28033, 3659, 20206, 18968, 13128, 4497, 11880, 2788, 23768, 19699, 26331, 584, 8216, 17979, 11934, 6782, 7610, 11576, 26397, 18840, 12976, 13923, 7957, 13499, 20773, 12788, 15715, 15525, 25929, 28323, 25193, 12718, 22871, 14069, 9844, 17952, 8059, 22709, 24915, 394, 329, 9851, 13848, 24355, 1734, 1852, 10927, 5258, 11811, 25905, 18039, 856, 6854, 6520, 2802, 17190, 28218, 27373, 8894, 11510, 12976, 16443, 14498, 28843, 1939, 29651, 14417, 11183, 15912, 29195, 372, 28001, 5318, 7071, 3417, 15657, 9057, 20138, 25220, 7166, 1636, 11020, 12186, 21868, 19785, 25204, 14994, 23135, 10233, 26087, 25063, 7038, 27199, 23060, 23434, 7677, 14834, 23613, 2278, 12344, 20115, 19967, 4038, 6623, 25097, 18536, 15638, 15462, 10273, 4462, 19151, 3225, 3746, 14645, 7533, 4066, 3939, 28885, 28994, 20030, 19494, 14936, 5758, 12378, 10007, 722, 21876, 8933, 13987, 28295, 22683, 14574, 12625, 3073, 20535, 10719, 16303, 6101, 15157, 11481, 23398, 15400, 4695, 12537, 17371, 24488, 1871, 2467, 26972, 11103, 22856, 8965, 8289, 6973, 26170, 22872, 28652, 29150, 6352, 24513, 25193, 16451, 17668, 21496, 13822, 6080, 10886, 7330, 24588, 18665, 23189, 10925, 10049, 28481, 7571, 3547, 29778, 7585, 18774, 20112, 10898, 13732, 24806, 11635, 21890, 24469, 12192, 2656, 27235, 12981, 15080, 22087, 9106, 29556, 1117, 24062, 29551, 10641, 1439, 19840, 12697, 7360, 14381, 8029, 6845, 27270, 15197, 20436, 13614, 6811, 25307, 19776, 22746, 18015, 6226, 5544, 12617, 7144, 9173, 18779, 16394, 6459, 28836, 28869, 17134, 17062, 12377, 28731, 24026, 29351, 26176, 9389, 3674, 40, 25376, 15622, 6231, 6107, 18866, 29719, 9910, 20484, 9461, 17122, 20556, 2856, 13115, 20801, 17049, 15629, 12885, 11691, 10466, 20345, 17745, 6031, 3985, 14758, 19436, 10903, 3340, 16221, 24159, 12521, 1092, 5287, 20256, 22767, 8472, 15409, 22262, 25981, 15279, 4154, 29179, 21330, 29948, 12568, 21685, 13368, 29900, 11707, 23518, 4454, 19892, 26580, 7057, 8240, 4652, 18651, 8372, 28387, 19185, 29470, 13391, 13468, 361, 6501, 29433, 24885, 13983, 29020, 28943, 18640, 8363, 19524, 8298, 1398, 15849, 19079, 11157, 2124, 3119, 15842, 16951, 12888, 5300, 23381, 23717, 18868, 25653, 28415, 17190, 5432, 8828, 24440, 11678, 17517, 5647, 9713, 14728, 9132, 19998, 4565, 3225, 11302, 26185, 11879, 2023, 9738, 1713, 20685, 2556, 20092, 3143, 18058, 18303, 1700, 12622, 7801, 14806, 22577, 16303, 22220, 22587, 14329, 10143, 18100, 27031, 6874, 1313, 18651, 6885, 24831, 9613, 20003, 19854, 15100, 17785, 20437, 4986, 26038, 16388, 27460, 5337, 15512, 7587, 28891, 24182, 22813, 26846, 3603, 23988, 3052, 23969, 21978, 20442, 5335, 7961, 24948, 3206, 10433, 16754, 1106, 27370, 16258, 29275, 14005, 8623, 27314, 21935, 67, 15989, 26410, 20065, 25972, 7175, 22028, 907, 10732, 2114, 7380, 19641, 25989, 27189, 21338, 25115, 1738, 8779, 4442, 13728, 14078, 4913, 10880, 4714, 11555, 26823, 20312, 2141, 19394, 14936, 28669, 9509, 14466, 7866, 16390, 25737, 24877, 23916, 16535, 16382, 6006, 11335, 24599, 27585, 24142, 24359, 9174, 17260, 25908, 1948, 5773, 17818, 14069, 27295, 12649, 24765, 23862, 13984, 18335, 2506, 16027, 20200, 10818, 11574, 974, 28928, 10941, 20928, 2060, 118, 18145, 7043, 2670, 7965, 15135, 14617, 14433, 4071, 4154, 22689, 774, 23224, 12480, 22081, 8528, 28755, 25134, 24467, 19147, 9124, 15758, 9130, 17876, 26982, 8384, 5898, 28701, 10966, 7354, 29020, 14769, 7027, 24915, 13065, 8066, 24417, 14830, 28315, 4371, 9543, 15735, 24525, 21861, 8050, 25205, 15845, 12590, 3892, 8290, 4990, 21275, 24357, 26197, 5318, 25627, 828, 10923, 25525, 20326, 9180, 9175, 2126, 8083, 17393, 1481, 18001, 3008, 28169, 15339, 25226, 28323, 10107, 21092, 17823, 24796, 14803, 5151, 23057, 10272, 25330, 1677, 17645, 22280, 2296, 29815, 7661, 17671, 19433, 2589, 17583, 7910, 6402, 7169, 24966, 26856, 19099, 4578, 3500, 5322, 13393, 25782, 2650, 20890, 17651, 22690, 5669, 12047, 22916, 5335, 19106, 5698, 18706, 4757, 15539, 4006, 9625, 17217, 14085, 29065, 12981, 14912, 19166, 12396, 21267, 20178, 29415, 23372, 12336, 21146, 3836, 8560, 6147, 7918, 26136, 19453, 19530, 24471, 6530, 17970, 1613, 21428, 205, 8380, 5099, 10712, 9577, 29810, 8785, 13614, 26956, 21571, 26375, 10884, 4531, 12181, 4389, 13948, 27697, 9130, 11973, 7738, 8136, 16099, 19488, 9132, 13160, 10390, 22687, 5783, 21065, 4328, 23057, 21796, 17382, 9446, 27950, 10608, 2479, 25279, 10240, 16390, 6453, 25925, 21325, 152, 10491, 23002, 29366, 25692, 4475, 22608, 28364, 13313, 10663, 27453, 21244, 2633, 3818, 27659, 4579, 14598, 24084, 11487, 711, 19682, 23630, 3608, 634, 18471, 5861, 24869, 4614, 9463, 2828, 5024, 802, 15966, 13952, 5288, 20654, 22053, 6706, 6269, 27877, 14291, 29878, 19355, 7294, 9020, 4641, 3376, 27251, 24108, 19435, 26204, 26280, 25062, 17604, 6869, 25680, 15905, 4360, 27560, 18451, 24172, 22230, 25763, 28460, 880, 5829, 19342, 11657, 22676, 52, 24432, 2699, 2788, 27382, 23340, 21987, 1738, 29380, 10559, 11221, 20531, 26638, 19044, 23007, 26021, 12728, 27737, 26840, 14021, 13961, 13511, 20719, 24369, 417, 29751, 21013, 29162, 13341, 24624, 27585, 16539, 16968, 9911, 22967, 15471, 12348, 2801, 1922, 1839, 24719, 25131, 25075, 7130, 25743, 23981, 22539, 11110, 23225, 3883, 9092, 3766, 9319, 10118, 24488, 24583, 28510, 269, 11437, 13398, 15664, 23646, 15662, 23201, 27947, 15951, 25982, 17212, 2258, 12791, 15155, 22969, 2524, 12681, 4505, 841, 5477, 11824, 12265, 8344, 28352, 21158, 14439, 22879, 8027, 3032, 12419, 17788, 22194, 9168, 16424, 27889, 10584, 18834, 18560, 1394, 17766, 16134, 23375, 15633, 1136, 9236, 18385, 9482, 10454, 2588, 3499, 25612, 12867, 25109, 5920, 3240, 28245, 19134, 3026, 12164, 625, 17963, 14846, 1674, 3205, 29197, 745, 9509, 12859, 26097, 26558, 20271, 13814, 6253, 23133, 3350, 27019, 26338, 23668, 10430, 8815, 6527, 11039, 21006, 8742, 25842, 22238, 12238, 17622, 20496, 12025, 8951, 7702, 12596, 7236, 26795, 26866, 6866, 26641, 18922, 15814, 16786, 21374, 12497, 25199, 3511, 623, 24698, 14373, 5735, 26303, 2841, 19863, 9331, 6945, 24346, 12593, 26310, 18939, 23753, 22790, 17480, 28727, 623, 18657, 18306, 21741, 2532, 3898, 10052, 26971, 16724, 21619, 9348, 17165, 16976, 27640, 2358, 4834, 22462, 29525, 92, 14954, 18123, 25989, 12368, 20403, 19762, 24048, 8114, 14599, 16988, 26921, 8475, 19618, 17137, 4019, 12706, 12179, 5628, 22177, 10981, 28245, 22038, 10495, 20667, 433, 6474, 25572, 14808, 15841, 14129, 16688, 28253, 17330, 9909, 4421, 5987, 19317, 5688, 12749, 2666, 19914, 26363, 1774, 28719, 19928, 26248, 28963, 26735, 11324, 6119, 11159, 22729, 3859, 29465, 21806, 18594, 13605, 22806, 28402, 19352, 22648, 27199, 12792, 23307, 6408, 237, 9432, 15320, 4088, 11031, 3749, 23854, 8533, 24938, 27576, 10925, 10947, 11553, 18534, 16781, 29791, 28525, 23138, 23140, 18916, 4677, 12894, 1036, 13965, 22533, 29859, 16682, 17489, 4962, 29774, 4257, 28257, 5696, 5949, 4360, 4952, 12067, 17970, 9663, 29404, 21565, 10676, 5417, 17610, 14757, 1450, 4000, 16994, 26160, 14304, 10193, 15260, 15668, 28506, 25262, 20318, 22718, 20894, 28684, 28763, 9006, 1447, 25095, 10578, 14513, 25433, 20243, 22610, 2850, 24859, 25212, 12566, 13519, 26284, 29294, 22933, 12653, 184, 12319, 2656, 14997, 10308, 23637, 14415, 26295, 13206, 1540, 11829, 23622, 15171, 3663, 12111, 680, 20652, 13167, 26383, 15082, 27210, 8514, 3167, 27278, 13415, 5815, 5763, 2664, 28884, 23419, 2820, 7064, 21283, 2196, 9633, 13094, 10915, 25726, 7326, 9166, 17726, 16191, 7500, 9313, 9048, 26995, 8502, 25677, 25432, 9043, 22573, 13603, 21516, 24162, 22453, 8595, 29177, 28924, 25778, 2811, 8779, 6659, 9048, 9255, 19829, 2395, 27338, 21744, 17933, 15130, 6700, 3218, 17176, 8308, 28314, 18797, 7973, 24932, 1586, 23930, 17303, 18720, 20106, 29487, 4961, 808, 27963, 15509, 15734, 21167, 21594, 26254, 28152, 20067, 18937, 6989, 20631, 18848, 1972, 18203, 1639, 22099, 19099, 26415, 19931, 1789, 19334, 21496, 15141, 582, 5797, 3929, 24842, 14193, 2251, 27171, 21160, 5159, 13992, 26615, 23618, 17217, 988, 15437, 17416, 17294, 913, 15322, 12046, 26256, 29022, 5198, 22818, 13904, 7837, 3037, 25301, 29509, 11196, 15010, 13932, 408, 10110, 1579, 20708, 16288, 8622, 2243, 26772, 2429, 28111, 24990, 24109, 29830, 26677, 8981, 24252, 26393, 4207, 19218, 227, 28580, 10100, 16991, 13072, 23458, 1503, 6402, 6813, 24265, 19069, 2708, 29684, 21016, 13108, 863, 24025, 16014, 7657, 25698, 4210, 10076, 9548, 18693, 16479, 9271, 29466, 3209, 10640, 10053, 6728, 28538, 23293, 11643, 20858, 23501, 8045, 23311, 26843, 3624, 7767, 7907, 20033, 3456, 21559, 8465, 19539, 2729, 29685, 21412, 28467, 29301, 7406, 16185, 22141, 2182, 13760, 17214, 488, 12662, 10575, 18503, 13758, 28684, 2908, 6840, 16867, 19587, 13659, 11876, 6918, 4628, 23300, 17044, 18166, 26582, 27908, 23039, 10172, 21995, 670, 5502, 2611, 8433, 915, 29964, 6561, 274, 5878, 15989, 1445, 4015, 11371, 8782, 14822, 1388, 2511, 24642, 3648, 22915, 12084, 19017, 9585, 27228, 6944, 11343, 7852, 3883, 12298, 4754, 25717, 16632, 19828, 23458, 18407, 29086, 15, 27983, 1311, 26415, 23186, 9799, 20639, 15385, 14961, 633, 22124, 9698, 29129, 21252, 11041, 1133, 27282, 28148, 12491, 1553, 18057, 67, 20139, 28713, 7727, 307, 7075, 28543, 4640, 5890, 4965, 16434, 22574, 4939, 18988, 6161, 9180, 22561, 6239, 16077, 24311, 12265, 3824, 15206, 21822, 26192, 19765, 24526, 28485, 15938, 22284, 9832, 20180, 21958, 29675, 18205, 29072, 29386, 7116, 3761, 20681, 28674, 18571, 29748, 25286, 27625, 11622, 10495, 10449, 23502, 6887, 5894, 20397, 23123, 8473, 15473, 21318, 9468, 28797, 16504, 3337, 21091, 15826, 21688, 26582, 23567, 24706, 18846, 15317, 24309, 1656, 27372, 12541, 20507, 13127, 5675, 27971, 2098, 18724, 24042, 20268, 22134, 1954, 807, 29957, 29964, 28634, 27575, 29551, 6259, 7331, 4337, 9243, 24360, 1790, 8283, 19187, 2878, 10455, 24195, 11712, 16987, 9919, 28713, 18764, 6667, 24724, 1000, 19963, 25624, 16104, 27485, 23898, 18988, 13395, 29913, 11858, 22916, 3153, 13447, 2118, 15423, 9675, 4091, 26099, 5408, 24409, 13140, 19560, 17276, 9757, 28510, 17435, 1247, 6852, 13440, 13352, 18765, 7850, 14400, 9719, 27110, 19918, 21633, 8107, 13416, 25659, 4397, 2102, 13805, 2782, 19100, 25107, 13115, 23248, 14439, 11189, 3052, 20489, 10460, 26253, 3119, 27720, 4652, 11163, 8383, 3326, 22061, 11858, 11599, 13713, 9527, 13125, 9637, 2663, 21979, 28669, 18359, 7419, 25189, 18406, 14079, 21002, 10309, 3663, 22717, 7449, 14543, 18950, 3915, 20450, 24621, 9134, 9944, 8816, 2959, 22516, 3299, 6869, 4953, 931, 7226, 11098, 16178, 1369, 21963, 2763, 10993, 13080, 20828, 13690, 17589, 12360, 11433, 4375, 28750, 15026, 22426, 22811, 4302, 865, 7111, 26489, 16289, 2977, 11118, 659, 12810, 22216, 2020, 12507, 26867, 3279, 16399, 2642, 3964, 21538, 3864, 19980, 22568, 28615, 19156, 2489, 4609, 12049, 23644, 14611, 3446, 7732, 29476, 1480, 28359, 2747, 19412, 15513, 10884, 26817, 26002, 11338, 29901, 4927, 15018, 9190, 4730, 29343, 26223, 24150, 21396, 6280, 27559, 14043, 18301, 17897, 29698, 18357, 1858, 29861, 1290, 22398, 16468, 10395, 13918, 1030, 6979, 1192, 22272, 16613, 8401, 15830, 22715, 1657, 19838, 920, 29912, 17438, 9899, 4609, 21030, 9154, 16892, 12763, 7594, 29952, 4777, 17081, 3408, 12735, 2372, 27227, 8054, 8450, 29765, 17525, 6862, 16043, 16088, 13999, 1822, 25718, 22738, 581, 22719, 8545, 13789, 15532, 26296, 27409, 27865, 5819, 12899, 18003, 23081, 6133, 9075, 11606, 12868, 1441, 13453, 10449, 21146, 19576, 609, 12193, 21938, 12688, 21967, 15499, 9537, 20264, 5269, 23925, 17976, 18829, 18625, 23577, 7266, 2923, 14353, 1912, 15345, 2890, 8118, 15734, 4349, 21111, 8179, 15100, 10321, 24632, 21562, 26125, 20135, 24951, 3772, 17350, 964, 27376, 8390, 9993, 11061, 4752, 21326, 14646, 21581, 16593, 22969, 17248, 21704, 14635, 6063, 15175, 16024, 13289, 14876, 13803, 17381, 12719, 23501, 13004, 13375, 12349, 2086, 17980, 19279, 5073, 14169, 3038, 9374, 15156, 23480, 11266, 25936, 21555, 14665, 740, 29331, 24010, 13758, 12798, 7048, 1538, 5042, 8481, 15820, 15369, 15368, 20016, 10309, 29994, 28894, 2668, 9224, 6456, 12517, 24726, 19192, 3216, 4152, 12714, 16373, 14273, 22851, 19298, 12784, 1180, 28734, 678, 20196, 10679, 13495, 11790, 9260, 11034, 21398, 14206, 22240, 24148, 15968, 17002, 2926, 28571, 18279, 9401, 13126, 2580, 19592, 7198, 13359, 14562, 6078, 18695, 9409, 19405, 17077, 11567, 5772, 2647, 28909, 20326, 12053, 25537, 19042, 4242, 347, 2481, 17091, 11355, 8197, 20602, 20706, 12784, 15269, 22597, 11518, 18380, 12710, 18447, 3072, 10017, 26669, 13216, 1781, 9585, 10632, 14344, 20678, 8035, 15038, 3062, 16569, 5438, 17887, 1926, 10573, 19146, 28007, 16381, 25350, 12904, 14476, 5182, 3213, 16128, 8169, 18550, 9721, 3753, 23346, 26411, 4927, 21930, 29504, 21924, 29544, 10459, 29414, 1605, 302, 14909, 5782, 7802, 19501, 22846, 13964, 8737, 89, 15449, 28542, 17983, 10719, 26238, 9196, 19025, 20913, 28610, 23952, 23806, 6130, 24565, 15160, 17038, 19572, 4920, 21702, 19177, 13384, 24466, 9080, 21598, 17146, 10868, 21165, 20739, 1647, 10239, 28609, 8919, 14267, 6301, 4689, 13192, 2339, 25534, 21493, 26095, 1992, 21569, 8076, 22848, 7857, 26028, 6580, 5757, 11496, 1247, 5313, 14528, 9049, 1255, 4765, 1998, 21142, 2102, 12758, 267, 1906, 27678, 8761, 21338, 15789, 13502, 10014, 27101, 9511, 5519, 23606, 4636, 7880, 12726, 11181, 1570, 18286, 27187, 18432, 28562, 22775, 8702, 29490, 1152, 28573, 7776, 16418, 17826, 2318, 3426, 4796, 28899, 17211, 17454, 18907, 19290, 11657, 16955, 28137, 7777, 9602, 18419, 6031, 21017, 12015, 16943, 10249, 5429, 15837, 12863, 27067, 403, 17828, 29142, 10452, 9588, 12261, 11630, 25849, 25061, 8525, 28778, 15857, 7961, 3019, 826, 5547, 18418, 1249, 24545, 28526, 27326, 17812, 9564, 28890, 10724, 10949, 11378, 17480, 825, 27788, 15938, 3685, 19515, 25855, 28632, 4587, 16382, 1193, 20753, 7913, 24066, 17971, 16466, 12546, 16677, 18459, 13624, 13108, 29615, 25169, 9593, 5791, 10369, 6496, 19646, 395, 11099, 24754, 10513, 15983, 945, 22782, 19672, 27757, 27147, 16018, 19224, 29324, 29427, 27151, 27650, 13426, 26448, 24433, 21154, 19488, 2326, 11909, 11749, 26645, 9048, 2439, 28773, 9637, 16830, 18811, 23693, 3344, 11399, 20504, 10065, 7603, 14262, 6859, 7265, 24135, 17677, 4513, 74, 13051, 20913, 24265, 13536, 24087, 3635, 29826, 4372, 2492, 11646, 2475, 19586, 26789, 4837, 4187, 7743, 19612, 24402, 18237, 267, 7621, 2504, 9823, 9872, 9492, 19836, 2834, 22460, 13491, 11073, 14653, 17226, 18523, 11084, 20050, 14684, 1836, 15562, 23600, 11040, 24738, 12661, 22562, 26250, 15835, 3094, 23255, 17285, 28508, 22808, 25622, 28896, 28825, 20494, 22273, 26423, 15360, 26544, 7086, 6677, 24213, 24281, 29704, 14312, 9293, 20451, 20689, 6161, 27148, 7297, 11900, 26380, 15724, 24115, 22686, 27159, 9752, 19749, 26625, 27436, 24716, 2628, 5641, 17896, 3769, 19201, 14486, 10904, 23812, 3933, 5649, 25620, 7893, 11391, 22021, 24600, 14662, 4612, 2929, 15429, 7741, 14724, 20750, 9574, 15537, 20873, 28605, 21931, 17492, 21142, 10135, 4787, 680, 24363, 25398, 19982, 16717, 24874, 26786, 24848, 27250, 21668, 27731, 9851, 16945, 5240, 20800, 24860, 5554, 1266, 29969, 6336, 2716, 7136, 19568, 26565, 2984, 11845, 12550, 24386, 28595, 5182, 9136, 26284, 2303, 8487, 6330, 2389, 29847, 14103, 18430, 1496, 3375, 19859, 15218, 1239, 22770, 22193, 10359, 17264, 9338, 11402, 27172, 14281, 14573, 20266, 11352, 5730, 12968, 19958, 17539, 16265, 26610, 2224, 9488, 1797, 1917, 15322, 204, 12832, 28361, 1407, 4966, 6309, 27895, 17270, 22631, 16221, 22456, 9968, 10501, 26273, 557, 29062, 10872, 24822, 7890, 18396, 26738, 3316, 12546, 18293, 10670, 26579, 13763, 10604, 7466, 3021, 29387, 28198, 21871, 15820, 5098, 15973, 20593, 9531, 16538, 13781, 3944, 7931, 24722, 1202, 372, 8998, 1688, 14726, 475, 4166, 6563, 1330, 8958, 14233, 29216, 27203, 20713, 2262, 14427, 21154, 3647, 23383, 5725, 10085, 19480, 18457, 21459, 27775, 16682, 25355, 20763, 19543, 14953, 19035, 22816, 18020, 26726, 13738, 5481, 2205, 11987, 13905, 5811, 6625, 3799, 4407, 7358, 26467, 4970, 16267, 16799, 839, 14553, 24621, 9774, 11229, 21507, 5968, 25197, 13279, 24538, 9749, 28141, 3316, 2834, 23798, 21375, 23268, 6578, 5167, 591, 601, 27778, 3969, 20423, 28315, 7347, 20066, 1245, 22093, 15652, 1373, 26791, 21461, 13419, 22578, 17819, 6349, 7724, 21465, 5054, 3498, 4870, 20798, 4408, 26921, 23050, 1525, 3567, 24034, 6389, 18037, 4477, 28684, 13733, 1805, 11162, 1882, 28979, 6096, 18186, 11031, 16733, 27668, 20740, 13580, 2787, 25727, 14682, 26023, 7604, 22363, 23354, 2789, 18319, 6646, 8146, 2159, 9349, 16476, 16553, 17611, 23178, 29580, 24381, 24209, 20585, 14361, 17184, 13180, 15707, 27129, 2561, 7724, 13473, 16720, 26874, 16505, 23126, 9574, 17559, 10484, 16316, 7217, 13336, 1061, 2290, 16755, 9031, 25582, 13318, 8707, 12947, 4316, 29503, 19401, 5406, 24736, 26913, 11135, 17311, 3905, 2249, 13359, 486, 15955, 9608, 7729, 19450, 28280, 2198, 4351, 18916, 14267, 15824, 8653, 27546, 8023, 17958, 20725, 20827, 18489, 24262, 751, 1369, 21538, 1759, 2286, 9729, 10050, 9693, 27669, 484, 1328, 4236, 7094, 18425, 17709, 11108, 17314, 10966, 10807, 6718, 7604, 3606, 23129, 21709, 8287, 26833, 7126, 8221, 883, 5444, 8803, 28739, 3658, 8198, 6818, 1440, 10367, 164, 26982, 15629, 10408, 18310, 3510, 5927, 1001, 14955, 22029, 25136, 6697, 16840, 9974, 3071, 4023, 17662, 29423, 17212, 4935, 21128, 24540, 8750, 25753, 24909, 19077, 19852, 8728, 5427, 22811, 9545, 16903, 1125, 14169, 20588, 6959, 3817, 5968, 5381, 6133, 6564, 19263, 18716, 1629, 23295, 2592, 17023, 1583, 4711, 6035, 23467, 7786, 24225, 18308, 16214, 19680, 8670, 11942, 22198, 17752, 7883, 485, 3290, 24501, 6240, 5901, 14777, 2181, 6764, 11676, 1717, 29462, 25888, 7593, 25620, 21885, 28528, 23499, 18135, 27721, 5845, 9307, 21902, 16926, 12162, 10502, 18193, 658, 10114, 28996, 27582, 17437, 9398, 16397, 5639, 28544, 16803, 14529, 27407, 28438, 25111, 12336, 3871, 8109, 29732, 13825, 6982, 7247, 6477, 4523, 1758, 8535, 25848, 15959, 5414, 14900, 2012, 26369, 15078, 28560, 2554, 6027, 23271, 571, 23436, 15595, 2924, 21766, 15723, 18963, 7467, 1738, 24525, 15483, 9279, 17884, 10872, 16253, 17090, 20983, 27379, 24287, 22868, 25018, 24158, 13407, 23781, 11309, 20973, 25288, 1321, 26448, 28776, 14634, 10902, 28648, 28782, 8062, 690, 4121, 29535, 796, 21972, 26452, 9178, 27846, 2863, 8943, 5490, 24228, 23781, 26750, 9292, 5919, 5235, 14145, 9184, 20976, 7211, 7944, 6572, 7180, 28587, 19001, 22480, 18247, 7563, 12670, 25540, 6393, 7073, 21701, 23100, 15999, 21897, 8137, 19063, 8824, 16095, 2702, 20308, 17101, 22191, 2120, 21146, 17231, 1313, 29524, 19634, 10667, 8792, 9824, 6595, 13427, 9912, 14401, 5846, 1055, 22629, 17713, 17262, 8210, 9438, 3541, 15802, 11362, 13704, 10000, 9926, 24419, 2765, 13206, 20653, 16604, 6305, 24179, 16741, 24257, 399, 18353, 20786, 7701, 24949, 24922, 20187, 18788, 13023, 4548, 16551, 4450, 11825, 18267, 27325, 11528, 24143, 16202, 28171, 21316, 25330, 18549, 26160, 29988, 25548, 15893, 15306, 26864, 23820, 19607, 29975, 22624, 23094, 15393, 20578, 1096, 5871, 9992, 12812, 3481, 20079, 29304, 6555, 24768, 26587, 20790, 29942, 7413, 26665, 2986, 13077, 2012, 24570, 20813, 20796, 29737, 17733, 29633, 6612, 5121, 28601, 5824, 261, 17464, 11965, 16095, 18835, 20342, 1560, 19102, 20642, 4003, 15548, 29787, 12864, 20311, 10723, 12614, 1568, 25371, 2847, 14170, 26891, 5609, 16398, 4033, 25562, 20693, 29965, 6599, 17345, 15619, 8967, 9019, 3292, 4890, 12422, 7467, 5937, 20547, 21568, 17018, 6132, 20171, 11403, 9221, 23647, 27886, 3136, 21555, 25036, 24604, 24909, 25029, 789, 15561, 17570, 25390, 14636, 8472, 27496, 19199, 2326, 25291, 24686, 7188, 4353, 18180, 14142, 8980, 13129, 21255, 27663, 16364, 21879, 12009, 6082, 3530, 25113, 13796, 26651, 15356, 13793, 9286, 11063, 9482, 6219, 12007, 12856, 9224, 9921, 17096, 28367, 17972, 23133, 24933, 8188, 25199, 26527, 8199, 4417, 29561, 24043, 13676, 29472, 3301, 2359, 24793, 29753, 6991, 21462, 1231, 2894, 21034, 1914, 12840, 11067, 11965, 4134, 15447, 26721, 2441, 7145, 29730, 20183, 17732, 16623, 3505, 8010, 8303, 27857, 20524, 21272, 1245, 7784, 11511, 15448, 18152, 533, 19771, 2639, 26864, 23116, 11870, 1776, 18348, 21108, 10037, 18571, 5657, 14973, 17416, 13400, 4230, 29846, 25251, 29317, 12318, 17241, 6034, 17034, 12275, 8700, 18375, 18120, 13015, 21682, 15185, 20710, 16573, 13301, 16614, 2461, 29254, 21129, 127, 29920, 19866, 16997, 8687, 1003, 7568, 21412, 2136, 25926, 13299, 11784, 22304, 8581, 1484, 21420, 6005, 20174, 14988, 27508, 28404, 5795, 2554, 3886, 12580, 9651, 28878, 24608, 17626, 2872, 133, 19029, 19695, 3951, 20314, 3339, 13730, 6288, 12444, 24349, 14133, 4057, 26456, 8729, 24001, 16416, 22473, 11036, 27308, 20910, 21887, 25803, 13883, 1951, 9488, 7534, 28841, 452, 23633, 3640, 15568, 18851, 19616, 19799, 27353, 9406, 26396, 14716, 4969, 15672, 2914, 20133, 11334, 14601, 27798, 23146, 998, 76, 1615, 10650, 83, 9465, 13571, 1234, 8726, 3998, 14285, 16048, 4695, 20314, 2942, 6046, 20440, 13219, 24259, 12647, 3203, 17561, 6246, 4145, 18185, 7647, 24797, 1374, 3723, 20156, 11283, 26058, 23630, 23842, 10881, 28025, 26031, 17395, 15066, 14378, 20623, 17699, 26159, 12892, 29724, 25055, 25676, 21067, 29549, 13731, 27147, 12777, 17981, 22764, 20910, 26197, 8471, 12592, 20799, 1240, 20491, 10379, 21022, 3012, 18029, 18931, 8486, 25110, 10547, 8873, 8415, 24769, 8541, 11190, 1674, 21129, 21362, 29267, 14387, 12499, 20588, 20421, 29168, 14864, 24233, 995, 1286, 1273, 5123, 4235, 28571, 21254, 29700, 25940, 19417, 21013, 6550, 12442, 27030, 28939, 24589, 22761, 18214, 3547, 28664, 26550, 22275, 27611, 2313, 14029, 25326, 10171, 7221, 23004, 4526, 22554, 6052, 22101, 18552, 8918, 18890, 21226, 21709, 16177, 17879, 9465, 6936, 3138, 11526, 27473, 27503, 24092, 14788, 7915, 21199, 24052, 14184, 3704, 13211, 24509, 1906, 29247, 18158, 27298, 24083, 19774, 17126, 25134, 20666, 5819, 3108, 7375, 21808, 4352, 13457, 7267, 12092, 26044, 9328, 22509, 23277, 17370, 3291, 21756, 4956, 11366, 20787, 29944, 1636, 12301, 27869, 626, 24163, 25913, 13364, 16012, 4046, 7709, 14268, 29575, 4135, 15335, 28342, 24336, 28295, 18201, 21605, 23873, 26305, 6831, 17351, 19478, 15614, 13432, 8964, 26744, 8989, 15317, 10859, 15263, 3777, 25038, 4860, 16677, 17401, 8502, 13864, 7334, 16131, 22309, 20318, 16266, 27574, 4924, 8456, 3964, 3918, 10998, 7057, 13186, 20598, 29080, 21364, 1555, 18942, 6595, 24130, 5546, 11942, 7609, 23351, 20990, 22132, 10896, 4863, 17697, 18529, 18319, 25083, 18396, 3600, 24379, 6404, 18296, 798, 268, 2946, 6597, 6375, 22935, 29030, 21573, 11565, 10192, 27067, 9833, 27286, 2368, 7994, 25798, 22405, 22265, 6017, 9744, 17083, 24463, 26201, 13960, 22572, 18365, 24817, 10048, 7707, 19661, 16846, 19880, 15465, 16624, 2142, 3900, 23478, 8153, 4132, 15580, 12700, 23374, 7354, 23969, 14660, 2707, 28439, 25283, 21880, 25162, 13759, 15620, 28130, 21589, 29723, 26070, 7983, 23525, 3703, 9658, 15729, 4034, 10353, 11607, 25426, 28529, 7377, 17630, 3886, 11427, 4510, 11709, 14572, 13783, 18280, 9839, 9841, 7231, 8139, 16304, 16079, 26823, 27800, 28120, 10319, 24519, 19944, 18291, 16512, 22087, 6377, 5185, 23516, 27295, 6805, 23525, 5359, 28830, 18192, 12043, 11707, 21476, 20499, 13309, 1748, 21356, 26530, 6644, 3139, 28994, 11811, 8862, 27333, 627, 3472, 26771, 7067, 14570, 22449, 18340, 12641, 1122, 27471, 2574, 10098, 28040, 22368, 28801, 28327, 28806, 26904, 13431, 16398, 4822, 10242, 14374, 8047, 28392, 22420, 14726, 20437, 8436, 19149, 16397, 23613, 23274, 2618, 8330, 8850, 12050, 18868, 6698, 12177, 28112, 18214, 24474, 15762, 15785, 218, 19599, 6375, 23703, 2323, 19555, 17696, 5729, 9382, 21448, 17456, 28507, 12471, 17982, 8944, 9317, 28634, 1827, 3401, 22528, 23481, 25732, 1294, 21101, 9250, 18979, 32, 16446, 5436, 22111, 28862, 29561, 1979, 21975, 10463, 9875, 24450, 19203, 25182, 13689, 13275, 6326, 377, 5880, 7163, 11297, 95, 12211, 19653, 4673, 14864, 9565, 10061, 14569, 24746, 29233, 20848, 26240, 7360, 23782, 2234, 16037, 583, 9314, 12477, 1342, 22720, 23091, 704, 23352, 5348, 28578, 18938, 22461, 2729, 8275, 9802, 13024, 3017, 27312, 25547, 22869, 3905, 26248, 23420, 11288, 17632, 20519, 27281, 6290, 2747, 3642, 4824, 24240, 18736, 7129, 24383, 26341, 9714, 18284, 11652, 29290, 20711, 9994, 24091, 14287, 3035, 19221, 2341, 19188, 7671, 7307, 10129, 6727, 19519, 13519, 20585, 24166, 25238, 25313, 14552, 14600, 28558, 13091, 2373, 1234, 22228, 14136, 17377, 5208, 5360, 11050, 7232, 1934, 10708, 23431, 7422, 25970, 9364, 1031, 29501, 22199, 10493, 18036, 16036, 3761, 1736, 11678, 11887, 20137, 29778, 11111, 6223, 10945, 19820, 15160, 15568, 5759, 24946, 12196, 2976, 12018, 7380, 26451, 10908, 21382, 28224, 10021, 13504, 4435, 14954, 3975, 23371, 25622, 19215, 8595, 13180, 7102, 25329, 25826, 9263, 22682, 19658, 29776, 25698, 14686, 17918, 25697, 10593, 25323, 11202, 11026, 10421, 15803, 19695, 13351, 9513, 24149, 12295, 11508, 27154, 14984, 1560, 26498, 6686, 13389, 6700, 7091, 21752, 25010, 7714, 5436, 6332, 16238, 9174, 11, 29089, 16638, 5287, 2767, 5900, 26561, 17830, 6903, 3566, 9903, 10464, 28534, 26310, 4104, 23752, 29278, 1205, 25356, 10667, 17333, 21513, 8307, 27065, 7850, 2162, 21506, 14781, 17822, 14494, 29770, 4388, 10390, 16121, 16318, 29393, 20353, 23273, 27682, 21202, 14388, 16606, 12070, 9386, 13729, 20907, 6539, 1839, 17056, 14542, 25159, 26819, 14823, 23827, 17897, 21637, 20756, 27384, 29304, 10585, 15864, 6783, 11009, 18752, 22736, 7293, 20361, 21490, 22967, 12187, 12408, 28850, 26129, 27011, 16262, 15694, 23682, 24834, 17952, 9741, 14218, 10725, 21272, 25018, 708, 28936, 10636, 25993, 28589, 2939, 22056, 21736, 190, 26780, 11928, 10405, 14558, 23047, 17273, 4035, 23534, 24231, 20018, 10960, 6143, 19360, 16848, 29426, 24938, 18866, 27193, 21316, 2324, 5439, 671, 29016, 2566, 28341, 12343, 357, 3290, 9520, 18750, 12048, 1248, 27995, 19145, 29133, 19205, 20463, 27127, 19126, 27551, 29409, 29540, 9925, 8177, 21062, 11775, 16248, 13618, 12534, 28937, 28224, 1839, 19369, 2062, 10442, 224, 25565, 25279, 12288, 28870, 23233, 22175, 13674, 5197, 14219, 10601, 1310, 20227, 20176, 6059, 20790, 13517, 9338, 13135, 29652, 4056, 943, 25003, 10044, 27243, 15844, 17349, 21198, 1863, 1032, 20706, 17683, 10574, 9353, 19776, 2071, 27900, 29643, 9282, 18382, 21911, 19429, 22041, 16453, 13404, 471, 10195, 29415, 1118, 5350, 13783, 9424, 12276, 18079, 10413, 17420, 15819, 498, 7790, 20095, 4967, 17405, 5392, 29457, 27508, 28896, 12751, 4419, 26709, 22419, 7288, 765, 2944, 10003, 24300, 19685, 10887, 4511, 19516, 27087, 9737, 21532, 28863, 3116, 12423, 28589, 21836, 5972, 29354, 22602, 9586, 8770, 20176, 27028, 15721, 8493, 27660, 7673, 6325, 19489, 9717, 28771, 21974, 1671, 10190, 10825, 15895, 24639, 28773, 5747, 5910, 14313, 8245, 21233, 23082, 25025, 18416, 25615, 425, 6233, 18817, 27343, 27788, 15118, 8904, 13958, 20354, 2405, 27827, 19895, 21194, 19184, 22405, 1252, 17441, 21706, 27674, 28264, 25789, 13375, 6894, 15708, 12876, 15822, 15214, 3724, 12982, 2675, 5067, 4766, 3971, 2953, 11303, 15887, 10218, 7952, 6929, 9153, 1216, 29118, 12629, 9804, 23094, 4182, 484, 1984, 7606, 7084, 27823, 11282, 12010, 7157, 12747, 5828, 3130, 12139, 14997, 8965, 1984, 22629, 29152, 15063, 9560, 1208, 4206, 7040, 8712, 28429, 28026, 27333, 29265, 4413, 17581, 23291, 18532, 7094, 25894, 2757, 1193, 2979, 4914, 972, 23004, 28187, 4241, 27905, 7795, 8287, 16073, 1538, 7182, 10537, 12169, 9523, 2159, 23205, 2936, 8684, 20457, 16707, 23660, 22668, 19921, 6527, 13783, 18315, 15835, 10593, 26630, 21645, 12702, 6908, 15011, 24989, 80, 11366, 7785, 10609, 16759, 26640, 23463, 10457, 3774, 17636, 20656, 5335, 23780, 243, 14620, 19895, 29017, 26277, 14252, 3712, 18403, 19207, 5883, 20827, 27257, 12231, 11337, 25807, 12803, 11340, 29289, 1425, 17349, 26730, 15073, 21163, 1851, 26541, 26394, 22525, 10403, 18139, 17866, 11332, 514, 27277, 2665, 17854, 6259, 6097, 1987, 12624, 25822, 25191, 23386, 29022, 198, 4896, 29515, 10788, 7487, 11710, 14630, 12107, 21547, 6943, 18882, 28342, 24505, 13016, 22719, 23939, 1006, 28801, 21914, 12386, 8604, 7848, 4839, 21075, 29989, 13273, 10601, 1694, 21670, 11001, 20227, 3704, 4679, 26549, 19994, 13810, 26343, 24065, 21125, 21515, 15124, 3377, 23870, 23079, 17520, 15929, 13061, 16481, 26960, 8784, 19668, 15171, 22931, 12467, 12846, 6435, 25716, 20038, 8869, 13686, 13379, 16636, 16210, 27047, 20529, 2283, 18935, 19147, 19391, 9760, 27256, 16651, 3371, 10017, 20738, 28314, 19017, 25000, 10454, 6217, 708, 18279, 14783, 14396, 21554, 7836, 16844, 19826, 13132, 15785, 20036, 16184, 23520, 22799, 22517, 13656, 10432, 20646, 22321, 24312, 25690, 10532, 6861, 12493, 27046, 19301, 8473, 25551, 9878, 19970, 7308, 1758, 23183, 22364, 12874, 2500, 18097, 9372, 2933, 12869, 3017, 29527, 13667, 13669, 21908, 9098, 13574, 6497, 22604, 20453, 26854, 28804, 1257, 15379, 17418, 16625, 27887, 25958, 3541, 16886, 22640, 28324, 24144, 22562, 14119, 21977, 7492, 3514, 8735, 27191, 11143, 6082, 22556, 5210, 2125, 18620, 2541, 644, 29899, 10527, 25639, 18578, 14549, 17926, 10437, 9432, 13432, 16102, 13909, 7440, 21099, 27745, 18404, 26510, 27576, 29656, 4871, 29579, 17149, 29488, 2118, 27155, 29659, 3253, 11031, 28132, 1286, 20711, 8194, 10648, 12840, 25004, 16920, 21314, 9026, 563, 16008, 27075, 29463, 13233, 19799, 96, 23720, 29952, 13559, 11189, 616, 4493, 5503, 25798, 28837, 4416, 27373, 20107, 8335, 15158, 20656, 18505, 28917, 18481, 14463, 27666, 19517, 25219, 10529, 21633, 5344, 8345, 26006, 1371, 25135, 29893, 6068, 27214, 1392, 15132, 9271, 17282, 8007, 21250, 1574, 13222, 12120, 9159, 10940, 3787, 2426, 11536, 9225, 4585, 24152, 9760, 6253, 25866, 11759, 20472, 16786, 528, 13222, 24742, 18808, 27025, 5466, 28687, 13389, 7284, 917, 10279, 28598, 27692, 6753, 8976, 1463, 8040, 12716, 6231, 24073, 12322, 5506, 18148, 28805, 7863, 14963, 10241, 25045, 4972, 3542, 23256, 27624, 29238, 7418, 11128, 1415, 13471, 21782, 17407, 17886, 4754, 4304, 26088, 8248, 5157, 12402, 29448, 540, 7323, 6737, 3138, 21713, 24895, 20012, 18359, 13004, 9577, 6074, 8795, 24266, 23345, 12776, 6562, 14008, 28611, 14197, 19355, 26026, 2721, 25667, 4008, 21235, 7599, 19820, 17643, 29928, 17192, 11120, 17008, 13061, 5071, 5797, 8977, 25117, 28503, 8015, 19583, 26204, 20777, 13311, 23139, 29652, 7350, 5963, 8555, 18641, 24265, 20280, 26372, 29111, 20614, 26867, 18234, 14896, 25939, 29087, 12049, 22138, 18058, 15919, 9762, 27775, 20252, 22007, 24831, 4898, 8337, 27629, 19000, 12055, 9969, 13452, 27789, 22006, 9543, 25497, 1174, 23024, 27678, 12042, 1600, 2383, 2266, 17315, 20241, 16696, 27836, 6219, 14468, 28631, 9462, 11359, 6632, 23829, 6800, 16731, 9648, 8202, 17963, 15701, 13748, 16136, 6835, 9760, 25525, 10379, 24726, 27120, 13764, 3481, 7107, 19921, 7153, 28038, 10424, 17728, 28790, 5460, 10382, 29871, 26939, 2121, 6389, 11766, 29450, 4083, 28682, 6750, 29548, 20973, 28808, 18812, 9269, 21478, 16222, 17711, 9726, 3204, 20179, 22093, 16466, 25832, 9212, 27633, 950, 21512, 28054, 28594, 3304, 20066, 17874, 18977, 29840, 28273, 13073, 667, 6325, 16169, 14412, 11048, 1119, 5719, 643, 894, 28035, 10589, 6893, 29056, 22093, 418, 24599, 22912, 2686, 20412, 2111, 29961, 21233, 165, 6041, 20903, 28793, 29422, 1361, 22763, 9628, 18149, 27478, 18710, 25662, 17500, 9572, 28189, 2302, 8636, 29787, 9839, 2985, 21333, 1942, 7895, 22949, 6866, 10653, 1549, 15026, 26005, 16424, 14810, 2885, 12762, 19238, 26104, 2231, 6419, 5938, 9336, 18421, 10917, 7459, 3739, 328, 8281, 13612, 7434, 13166, 23830, 22399, 8071, 29595, 11373, 4092, 2302, 2392, 22297, 23141, 10263, 22537, 9321, 25437, 4507, 2231, 29053, 29399, 14281, 18370, 5485, 7671, 13474, 8594, 27504, 8729, 28060, 19706, 23404, 17784, 24925, 3836, 15514, 25235, 5992, 23186, 13315, 29801, 3303, 20284, 22893, 19734, 18390, 7264, 4675, 10977, 89, 6495, 1391, 371, 16898, 10286, 17851, 28471, 21588, 21012, 27442, 5582, 27257, 8741, 5309, 23817, 14246, 123, 17064, 977, 26355, 29975, 7110, 26208, 25202, 26051, 5566, 14945, 16175, 10237, 7887, 7294, 28640, 29738, 17137, 21240, 20250, 26752, 23960, 16878, 14505, 26852, 27208, 9053, 25992, 14299, 9728, 5574, 9206, 3489, 7917, 24834, 1537, 13173, 27605, 119, 16827, 21021, 26449, 27958, 24829, 13804, 11410, 13164, 24016, 19208, 10739, 8972, 2084, 2869, 25347, 15210, 2375, 4159, 15077, 14642, 24005, 26601, 18050, 10886, 8604, 9935, 18103, 29179, 11841, 7656, 28541, 13873, 26251, 5355, 17017, 7686, 28177, 22037, 752, 12666, 9148, 403, 10346, 2321, 24028, 27879, 29921, 24946, 17563, 6581, 25845, 12466, 19473, 1916, 1015, 24701, 10038, 21408, 18899, 1880, 24822, 22308, 2557, 21873, 28165, 18966, 19543, 14213, 14626, 15291, 28435, 11495, 9575, 12775, 29865, 20959, 25212, 5118, 8151, 2976, 12909, 9995, 20742, 22026, 203, 19990, 18681, 3946, 14685, 27642, 12739, 7385, 29887, 14914, 10697, 11464, 8014, 588, 7990, 1385, 6351, 28292, 26591, 5601, 23866, 8571, 18165, 5884, 1164, 15390, 22251, 11081, 14000, 5015, 24166, 18931, 26801, 2440, 19616, 18783, 12094, 9051, 8798, 16616, 3315, 13546, 11628, 21862, 12006, 24250, 24400, 15747, 4089, 15618, 7765, 5384, 15798, 2578, 19036, 1889, 20825, 25833, 4109, 11710, 27980, 4102, 9620, 24168, 250, 27029, 11632, 17488, 16054, 28517, 27640, 17926, 29856, 29987, 21678, 27627, 8430, 5822, 10076, 3810, 1057, 18293, 3485, 15085, 17267, 89, 11217, 5369, 14498, 2425, 6814, 4673, 24532, 2956, 27467, 791, 5563, 536, 3189, 12275, 519, 202, 27310, 7745, 17591, 13614, 20339, 25938, 25485, 6212, 12780, 13432, 22332, 27250, 6058, 10245, 11412, 21306, 12953, 13438, 20291, 12607, 8857, 18528, 5432, 13053, 9470, 28462, 29555, 18257, 8191, 9539, 6949, 12330, 9429, 6664, 17554, 24616, 17370, 12728, 20818, 2969, 25392, 16767, 6211, 6803, 16927, 920, 3643, 955, 26571, 12300, 23081, 25669, 11022, 21633, 5038, 12032, 12304, 26625, 8336, 29670, 15298, 27138, 23832, 7157, 16648, 2217, 29549, 25897, 26245, 25211, 15096, 5731, 155, 13384, 5419, 26714, 25332, 25337, 27634, 12958, 16630, 17784, 29236, 19663, 12551, 22605, 9680, 12118, 25595, 14846, 8093, 13995, 10717, 19622, 923, 25988, 8780, 20146, 23894, 8291, 12604, 25495, 21821, 22148, 6910, 16052, 10254, 27649, 5462, 25871, 23642, 23661, 27515, 22719, 8111, 22947, 10312, 8883, 12554, 13610, 8526, 21600, 16776, 26726, 29328, 29218, 16028, 2134, 7590, 12767, 26285, 10739, 8748, 29823, 3502, 6767, 24792, 8297, 7720, 25664, 24734, 28683, 14500, 46, 19086, 10342, 11113, 18052, 9642, 8627, 5902, 20313, 3980, 27785, 16322, 8032, 5834, 21647, 7521, 25251, 2587, 1575, 3598, 12690, 1338, 24685, 4502, 1707, 27186, 19039, 14339, 13583, 20420, 2110, 3354, 18285, 6379, 26083, 2184, 6299, 1265, 5165, 21928, 25902, 26037, 2050, 16262, 27704, 20946, 13766, 7250, 28049, 17513, 4637, 3393, 11795, 28176, 21835, 29612, 23472, 21769, 18607, 21394, 2675, 6642, 1832, 12002, 3989, 2381, 9973, 21091, 11912, 29469, 9198, 16416, 3213, 3535, 14764, 22137, 4869, 9017, 161, 16401, 21059, 21764, 10967, 29948, 18702, 12863, 27581, 18474, 15250, 9084, 24008, 16175, 26733, 8842, 9794, 15527, 8974, 8247, 9604, 27019, 167, 16981, 25414, 4542, 13872, 29663, 12053, 4797, 13780, 6553, 23719, 11483, 6828, 8966, 7497, 16317, 19947, 572, 25565, 26280, 19674, 9114, 2307, 11600, 17083, 24617, 15968, 3282, 2612, 9234, 4758, 3928, 4470, 25355, 28814, 3364, 8893, 46, 12787, 26854, 25415, 19452, 22700, 29813, 25078, 21616, 27807, 15316, 643, 27000, 7224, 14667, 16648, 11363, 12456, 9078, 11222, 11288, 15404, 27469, 26076, 17605, 12523, 24931, 27142, 24449, 8726, 13497, 2647, 9183, 20913, 29455, 8662, 17546, 21197, 18745, 7315, 26736, 4508, 2283, 23854, 22362, 29065, 13093, 17874, 15873, 4888, 20750, 17983, 14329, 23921, 9506, 16871, 8018, 19691, 5258, 25271, 11880, 377, 26804, 26573, 17020, 29066, 21109, 27407, 11430, 26954, 21149, 19355, 12733, 7683, 6714, 1603, 19322, 23185, 6932, 21970, 3308, 5805, 2432, 1397, 20630, 21940, 2101, 1383, 5343, 10292, 6973, 27126, 14413, 25895, 15475, 3943, 22241, 18213, 1989, 20746, 27209, 20736, 13692, 9997, 25155, 12787, 786, 6871, 14288, 14473, 29701, 4714, 26108, 8795, 14188, 13641, 13587, 24072, 22822, 22016, 18126, 12967, 5064, 18847, 12158, 21099, 17478, 12814, 14268, 26001, 11076, 7607, 28667, 11780, 14442, 25961, 3275, 7642, 29428, 3546, 1545, 22624, 22936, 18453, 23046, 18716, 3647, 1763, 1636, 7009, 20808, 25072, 22211, 22013, 12261, 6286, 10972, 22686, 18787, 3372, 12326, 25926, 13308, 21690, 28098, 14032, 28160, 23611, 9999, 5312, 29737, 22505, 22072, 26023, 22922, 1133, 11163, 25117, 29126, 13723, 25666, 29521, 13555, 22054, 14337, 7062, 21937, 13377, 1404, 5079, 23180, 4745, 9895, 26223, 9317, 7286, 28475, 29959, 20712, 27740, 6020, 4521, 17505, 8581, 28189, 18074, 17829, 15824, 6749, 18312, 8178, 13622, 7304, 12154, 2047, 18510, 410, 25031, 13563, 1847, 5585, 22876, 12378, 11447, 3229, 25608, 1220, 18816, 2118, 27347, 23204, 901, 29543, 23672, 25708, 7750, 4072, 20968, 11410, 17961, 3102, 6759, 11597, 7357, 6524, 4668, 9557, 29669, 27638, 1447, 5963, 8260, 26224, 3130, 28258, 7292, 6408, 19848, 1940, 10373, 18886, 21864, 11261, 28616, 601, 21444, 23068, 5896, 20409, 20604, 28325, 7985, 15557, 803, 2151, 25540, 2280, 25848, 23088, 18534, 22431, 10003, 19040, 9871, 5718, 23837, 3101, 11802, 29370, 11998, 14808, 3502, 19591, 14293, 20277, 15859, 20138, 20360, 20032, 15351, 19941, 2567, 9569, 23238, 22065, 8850, 11396, 12185, 17494, 22094, 28804, 28351, 7083, 521, 22975, 28111, 5789, 23973, 22276, 15572, 17661, 20183, 16110, 187, 54, 15497, 5789, 29523, 15387, 7099, 4089, 8486, 16352, 25004, 3479, 18596, 8387, 16103, 22622, 29091, 3205, 5019, 24007, 16873, 15858, 18339, 24600, 3394, 14032, 5327, 27883, 6745, 22209, 22528, 3593, 14248, 28269, 13007, 23692, 25918, 23483, 18694, 24355, 5269, 5737, 3134, 3070, 10180, 7636, 6259, 10186, 7217, 18932, 1992, 2477, 26146, 1872, 25147, 27567, 29315, 5943, 13966, 27769, 8363, 17660, 12476, 35, 6614, 27681, 28592, 2538, 26454, 27958, 2507, 17789, 28051, 24489, 12031, 23716, 22889, 20942, 15360, 12854, 29432, 4485, 2457, 13186, 17000, 21467, 23433, 2657, 26988, 8716, 5950, 3965, 1011, 15199, 10824, 5637, 6960, 26271, 21551, 2290, 22941, 7573, 9747, 21349, 18991, 3535, 16810, 6959, 7277, 15642, 5843, 25562, 16314, 1400, 2389, 17162, 8595, 20251, 21669, 26586, 17391, 376, 23104, 15897, 5687, 27760, 23924, 9940, 17724, 7137, 22236, 15315, 6892, 6955, 6998, 10270, 7619, 14693, 27989, 21768, 8981, 6383, 10905, 16488, 12466, 19959, 7138, 11683, 4312, 8670, 7894, 23115, 26924, 5901, 22202, 16487, 23099, 27815, 29893, 2026, 14998, 28092, 22021, 4081, 23065, 14570, 26931, 26889, 13529, 21867, 8797, 12255, 14967, 15406, 14640, 28435, 2195, 3706, 8937, 3472, 20203, 29966, 15281, 10839, 17815, 27409, 1549, 6073, 25404, 8523, 28163, 414, 2698, 5685, 28886, 6267, 4717, 14025, 16598, 1964, 9358, 770, 22555, 4164, 23300, 18116, 168, 25192, 14318, 25823, 3484, 13462, 17730, 23461, 18823, 1167, 11212, 5551, 24753, 2018, 25000, 5674, 2661, 20594, 17097, 10731, 26713, 4030, 7688, 21930, 10581, 7936, 29591, 29935, 9405, 3736, 14506, 26042, 26883, 18257, 15956, 29165, 15865, 22691, 956, 6853, 20396, 18010, 3480, 25173, 27332, 12107, 4388, 26811, 7202, 20962, 13750, 9045, 9990, 26052, 17355, 22534, 14734, 11921, 24348, 10495, 12808, 25072, 266, 15361, 7169, 25365, 17297, 18362, 23300, 15071, 9704, 13937, 8569, 20322, 23355, 4043, 181, 2203, 14214, 15913, 3667, 13865, 8066, 4148, 23517, 3699, 9807, 14890, 22716, 6797, 8464, 10831, 1156, 17664, 23021, 9604, 9893, 522, 1668, 27127, 1018, 28025, 17618, 23042, 14704, 7950, 1449, 23148, 19707, 28203, 15631, 26004, 14946, 3072, 15270, 17028, 29671, 26422, 24753, 2514, 8625, 5960, 16496, 26707, 9023, 4489, 16835, 23245, 22665, 23291, 14503, 8506, 7849, 956, 18682, 8663, 599, 16229, 26686, 14553, 15303, 10304, 27998, 13851, 23260, 4699, 11013, 12234, 184, 17570, 13486, 20403, 19739, 3500, 18624, 11578, 10725, 27628, 16675, 13226, 10244, 3061, 8394, 15050, 18005, 4194, 28236, 7686, 17141, 29969, 17050, 27171, 4084, 17931, 27674, 15388, 19532, 27451, 26482, 8776, 299, 9511, 26643, 2777, 10851, 2804, 20099, 20482, 18863, 3453, 7630, 22764, 18854, 10474, 14891, 19644, 18492, 13661, 25530, 8223, 22737, 2508, 3521, 16014, 25783, 5610, 27412, 26616, 27756, 21346, 21708, 9778, 20209, 19155, 6186, 9710, 17553, 20683, 2221, 11038, 10473, 5679, 9951, 27186, 29493, 3080, 20337, 16012, 27488, 15620, 25861, 4474, 860, 9281, 21824, 21745, 25125, 13284, 19294, 9591, 15244, 28471, 26215, 19890, 14781, 18612, 21542, 10779, 28966, 26674, 6383, 28237, 6940, 12745, 16731, 13740, 6243, 5432, 19448, 21176, 23685, 14829, 9588, 16986, 10729, 11933, 4958, 28618, 17680, 23577, 230, 13118, 20925, 11054, 21790, 2648, 12662, 162, 2610, 10825, 11712, 13346, 369, 9433, 29013, 6723, 3521, 28864, 27381, 18594, 8000, 4920, 6944, 4990, 13909, 10196, 2357, 26783, 13806, 23986, 5725, 9805, 18395, 5461, 13033, 9124, 11212, 2972, 16822, 15930, 3770, 20458, 4427, 5968, 22169, 2314, 18960, 21563, 17601, 25426, 1103, 27210, 11104, 6656, 22598, 325, 519, 20749, 23985, 11584, 2151, 3054, 16179, 22054, 5433, 26677, 26887, 14245, 12551, 252, 4754, 19316, 26582, 12534, 27355, 2620, 23430, 20643, 5821, 10818, 18878, 20144, 8368, 26422, 1581, 28193, 20367, 2073, 17277, 24045, 1366, 19802, 21573, 20742, 10667, 28068, 18885, 17401, 11250, 25494, 15922, 21278, 13021, 17982, 17010, 1616, 14012, 27837, 6269, 29734, 21364, 24858, 23211, 22897, 27697, 15320, 7576, 11360, 8660, 20328, 2995, 22749, 7934, 21903, 24343, 14208, 13964, 5857, 18617, 22473, 25896, 4761, 27379, 17498, 1171, 19049, 8845, 7976, 25687, 386, 25822, 9643, 22061, 3722, 25246, 25643, 18390, 16883, 15031, 975, 23990, 26551, 299, 14809, 15662, 18366, 17464, 24342, 7990, 29640, 11182, 2077, 21169, 23490, 24194, 26480, 20444, 26105, 22555, 13214, 10606, 10036, 19414, 27890, 21004, 27857, 19925, 19645, 22716, 10772, 3231, 13924, 23500, 21917, 7151, 27581, 20344, 28952, 12037, 25685, 10601, 11506, 20019, 11089, 20027, 24971, 28584, 19580, 3590, 3221, 29425, 23348, 2848, 5430, 8503, 29087, 9796, 3111, 14199, 16145, 29199, 622, 26614, 22672, 18024, 27476, 20402, 20861, 27136, 965, 24245, 27799, 24102, 14960, 18612, 23550, 13488, 17084, 25991, 7301, 14741, 15079, 12242, 20465, 25995, 22125, 24237, 15046, 16584, 16741, 2387, 8441, 1134, 2757, 15091, 2380, 20697, 23444, 20655, 13750, 5163, 11415, 23032, 828, 1076, 1019, 4769, 18555, 21865, 17984, 15898, 5140, 15020, 23643, 25277, 5342, 19979, 7808, 242, 19002, 16813, 15686, 12883, 16112, 944, 4261, 25267, 1449, 3749, 22404, 6971, 9271, 29628, 28745, 21363, 24478, 25985, 21928, 16713, 17201, 26928, 7805, 27113, 9993, 5301, 24261, 11187, 17138, 23688, 9314, 1849, 13749, 13869, 14042, 19358, 26464, 7057, 22382, 22204, 29508, 23714, 25141, 5910, 5547, 27472, 28474, 16381, 4010, 17828, 3667, 6159, 16448, 28991, 29186, 22152, 12106, 27236, 8622, 22605, 5271, 27343, 23368, 1620, 27630, 8164, 2415, 16418, 18456, 27825, 13446, 1762, 17962, 22013, 18037, 1951, 20599, 178, 18737, 27942, 6278, 21687, 2940, 14721, 11753, 23329, 1645, 19143, 20310, 25143, 24735, 26319, 21453, 27753, 8147, 21568, 21099, 18423, 12712, 19388, 15359, 17345, 24662, 11341, 11169, 9046, 19817, 19055, 6300, 1027, 11448, 24461, 29640, 10605, 1546, 26037, 12324, 12545, 29738, 12727, 2292, 22087, 27303, 9198, 19626, 6387, 170, 25437, 28862, 16684, 10622, 487, 11446, 27910, 12199, 23089, 8925, 24460, 3323, 615, 18811, 15677, 17503, 6824, 18257, 6456, 8269, 5525, 25679, 528, 15694, 24415, 5770, 20708, 18843, 14277, 25012, 7403, 23919, 24629, 3682, 15646, 10041, 17390, 27656, 24616, 22847, 21257, 22299, 12869, 14707, 4944, 29321, 25429, 4469, 27405, 11409, 25272, 8855, 23506, 16657, 14065, 813, 20840, 2080, 26775, 2299, 21772, 26311, 23898, 19321, 13631, 8054, 18279, 10775, 25568, 21167, 12547, 8897, 9959, 23961, 13871, 23652, 1405, 20127, 15273, 9420, 2586, 12234, 3853, 28215, 13968, 2030, 13395, 26478, 10025, 20459, 5238, 8179, 9932, 473, 6429, 19843, 3388, 11217, 2512, 6566, 28937, 5531, 15325, 13006, 29266, 19707, 13066, 4618, 20493, 14874, 16981, 4471, 29903, 20389, 23497, 24419, 5201, 28550, 27468, 25424, 29422, 24421, 16005, 3202, 28169, 11490, 29658, 27856, 11123, 7502, 8609, 29353, 13945, 24673, 24873, 2770, 9087, 14968, 13232, 28440, 16119, 27028, 24235, 21120, 27919, 28813, 28749, 1438, 20661, 16966, 28837, 18195, 10417, 4000, 10393, 29560, 8817, 26350, 24803, 6070, 14040, 15031, 3096, 19667, 14557, 15333, 15281, 2619, 25692, 1436, 13107, 20037, 19082, 18011, 11722, 2317, 9563, 3412, 20534, 26762, 4356, 21400, 13483, 20102, 17464, 29661, 8718, 9591, 11150, 22004, 22756, 1107, 22336, 11587, 18444, 1810, 21316, 14409, 6527, 25873, 28002, 22414, 23453, 19081, 7628, 4526, 7301, 28273, 6501, 18057, 11577, 19849, 97, 18993, 29178, 25592, 12226, 1867, 18231, 13146, 10834, 28493, 17818, 7375, 3450, 1117, 5999, 11057, 18434, 7246, 7310, 2033, 15869, 19430, 12845, 17913, 1148, 22779, 9045, 5582, 8712, 21544, 23408, 19266, 21795, 21142, 10859, 25162, 16890, 25202, 25494, 13381, 16190, 14317, 2484, 16943, 4185, 18485, 8642, 17758, 1198, 29813, 8743, 17, 29344, 2070, 9259, 9769, 4161, 13660, 29423, 25248, 29339, 26353, 16104, 17940, 2676, 24510, 25732, 24992, 8666, 849, 20020, 25737, 20654, 23332, 10881, 8027, 11616, 29728, 17630, 5502, 5200, 8459, 16761, 21870, 27505, 21771, 11461, 1829, 29093, 16097, 9962, 19233, 23351, 19062, 21489, 17887, 1068, 126, 18314, 28736, 12710, 28911, 13544, 27105, 21600, 25122, 11746, 2412, 7758, 21948, 1701, 12348, 7545, 24579, 4505, 24289, 1043, 21931, 2494, 12646, 19705, 19648, 24681, 7739, 2837, 1804, 4934, 757, 10303, 9714, 10687, 4319, 8006, 27250, 4864, 2893, 23291, 3113, 17689, 18382, 111, 24432, 18047, 8705, 20958, 10169, 15643, 24655, 4892, 10409, 10874, 8748, 24937, 29553, 14458, 9754, 12787, 11361, 13055, 8389, 19088, 14156, 10682, 26468, 25379, 7459, 7609, 24307, 17720, 20956, 12155, 29734, 26480, 17188, 5770, 28091, 8653, 5732, 3861, 182, 2448, 24301, 2195, 25029, 5896, 138, 15617, 24760, 820, 11119, 1055, 15663, 17102, 22706, 6576, 4974, 25700, 12202, 3962, 9763, 25829, 12343, 23772, 19003, 15316, 22923, 15846, 7919, 882, 605, 10984, 7719, 19461, 6308, 7281, 19687, 18964, 20274, 22026, 24219, 27533, 6204, 2244, 16097, 25966, 24944, 15363, 14705, 7401, 28129, 21244, 21195, 4426, 15934, 21198, 23190, 17411, 7997, 27332, 6775, 3373, 20859, 915, 7331, 13608, 312, 4895, 10345, 18134, 25082, 16717, 23994, 4428, 22907, 28879, 28816, 12747, 27932, 23666, 26636, 27801, 1418, 26787, 20539, 9198, 21590, 13866, 10885, 20813, 2645, 26536, 10971, 7668, 7270, 4256, 23207, 9228, 8547, 13491, 1929, 25252, 22186, 19040, 7014, 19948, 3500, 5524, 16671, 1949, 19791, 29713, 27906, 9948, 29528, 27515, 18446, 17342, 14830, 28974, 11390, 26789, 15208, 14471, 14984, 24435, 12115, 27855, 20141, 9073, 4442, 22266, 20327, 28164, 20967, 6127, 23850, 16540, 13384, 20250, 12951, 10802, 20696, 7103, 20451, 12846, 25119, 17707, 18516, 4441, 6720, 20264, 2494, 15376, 6623, 16743, 11560, 1076, 29777, 24307, 15570, 19816, 25555, 25697, 8482, 13936, 7418, 12795, 24768, 13279, 14170, 18322, 7885, 13382, 17807, 2008, 6067, 20874, 1557, 4307, 22820, 8523, 20132, 11767, 13645, 29076, 19527, 4963, 13830, 12348, 14682, 26019, 412, 5553, 16306, 29778, 8328, 15493, 16372, 10078, 19940, 3387, 554, 26246, 11966, 4417, 3488, 21959, 24809, 1614, 10262, 20126, 16089, 9164, 26397, 3173, 13999, 8207, 11404, 14762, 571, 25816, 3629, 861, 5249, 16650, 18825, 7996, 7649, 22543, 16910, 7139, 21867, 7325, 5805, 6042, 22597, 23194, 17495, 29913, 17662, 25686, 7652, 1020, 21620, 4582, 2244, 22641, 14337, 10186, 3245, 9628, 27283, 11301, 25177, 19682, 2670, 25191, 13354, 12148, 14604, 27648, 29454, 19069, 28966, 7864, 19630, 5870, 15519, 2477, 27099, 2347, 3823, 13757, 2924, 12691, 20622, 23142, 27811, 1239, 11611, 24830, 23781, 1137, 28645, 16277, 21178, 21940, 23784, 20577, 9679, 17206, 18397, 26861, 27412, 28033, 1084, 9687, 13996, 159, 6912, 5269, 15792, 28596, 28969, 12255, 27788, 17244, 241, 18608, 7850, 9661, 25037, 4981, 842, 16004, 29319, 14194, 12243, 27048, 23932, 27226, 17151, 26371, 23946, 20005, 21370, 15059, 6682, 19571, 786, 8421, 13253, 24652, 21353, 12301, 9, 10285, 24832, 9223, 17121, 23139, 25281, 16312, 18990, 20789, 1910, 28338, 11883, 17268, 28795, 24630, 17458, 10764, 25642, 6625, 19745, 16805, 1923, 12167, 6456, 17124, 7100, 12388, 7233, 11948, 20887, 24292, 1557, 2185, 11194, 15104, 16678, 26185, 11004, 20772, 22181, 17178, 22114, 16018, 26882, 13236, 29188, 2955, 12543, 439, 11437, 23382, 25008, 8416, 18390, 26040, 2919, 19098, 11335, 17700, 1289, 6367, 21790, 12773, 11849, 14663, 29287, 24500, 15464, 12832, 14934, 8197, 7437, 8674, 14582, 14970, 855, 20527, 20691, 3605, 10231, 7336, 6744, 26719, 19476, 1563, 16636, 24293, 8665, 19523, 25533, 20707, 13315, 25720, 1851, 10434, 15926, 9964, 11242, 19467, 26536, 5690, 17396, 5211, 3683, 24059, 23313, 10025, 22434, 16814, 3996, 23584, 223, 19326, 4242, 15501, 29134, 10518, 27354, 25927, 15601, 19904, 19559, 22958, 20753, 2352, 13681, 5423, 824, 8392, 11294, 9692, 24035, 28407, 1195, 29178, 19735, 20696, 817, 29946, 22224, 26646, 27856, 19014, 9812, 21531, 16292, 19433, 5116, 28844, 3542, 6481, 12257, 15842, 27218, 29501, 20364, 16511, 3241, 29127, 6118, 28817, 2537, 16322, 4391, 24142, 3408, 27708, 29573, 27062, 4936, 6800, 5851, 27073, 7186, 3370, 24156, 18269, 8825, 17522, 16597, 19448, 27598, 5445, 21079, 13628, 5761, 20011, 23588, 11982, 27965, 8255, 7705, 18935, 557, 24161, 21071, 21612, 27932, 16511, 14801, 3410, 21273, 29456, 7390, 1285, 19901, 22168, 19576, 2168, 25257, 19718, 13100, 1837, 18242, 24981, 26082, 20672, 7116, 26325, 29514, 5071, 27373, 25011, 7965, 23934, 12683, 14588, 1866, 23468, 13363, 10357, 16510, 16319, 8555, 1417, 22438, 10243, 15142, 15818, 22859, 13118, 16864, 2415, 3061, 23595, 17976, 23218, 23810, 840, 27184, 29273, 26539, 5182, 17114, 7222, 8412, 25415, 1290, 1599, 3245, 14670, 20478, 9892, 5275, 11840, 23284, 22401, 3040, 7509, 11086, 7876, 27802, 28604, 5632, 3549, 5189, 29978, 23686, 13915, 15050, 27097, 15593, 16419, 26993, 4665, 28764, 24265, 20736, 17477, 12856, 13577, 29008, 21147, 29521, 2962, 25578, 27326, 9506, 18453, 27352, 8156, 15155, 4764, 1028, 27476, 8521, 22705, 2523, 22910, 3161, 28227, 6437, 9272, 25000, 1829, 1927, 28152, 10737, 3091, 22430, 11161, 27045, 12080, 15805, 15208, 10092, 15395, 23527, 678, 25558, 9724, 9880, 27982, 5878, 1686, 12010, 28934, 27327, 19720, 29756, 2030, 29507, 10467, 5040, 10465, 24496, 29, 28043, 16944, 4000, 12144, 11217, 6369, 8934, 14586, 6815, 3662, 24633, 7931, 20465, 20995, 16907, 22868, 17461, 21286, 3533, 14572, 1469, 26885, 6745, 4251, 19144, 8964, 9020, 27819, 8573, 855, 9662, 21891, 11725, 12797, 25285, 17047, 19260, 1251, 23129, 18922, 11248, 18862, 17226, 25687, 12000, 4163, 3107, 4017, 20945, 17591, 19902, 26813, 15211, 1760, 29076, 10430, 4101, 17803, 29385, 26489, 18809, 25419, 1367, 13616, 22616, 13973, 20313, 3527, 18774, 6965, 14558, 5019, 24789, 17140, 675, 3037, 8169, 15231, 17642, 25140, 29350, 9521, 21753, 2081, 11523, 27028, 27808, 21138, 10759, 15140, 8017, 21546, 11467, 12577, 20017, 25282, 13864, 16818, 27003, 12889, 16492, 1114, 22139, 28254, 23024, 20749, 7861, 24838, 22011, 24561, 8284, 16334, 24418, 17338, 10185, 26454, 1194, 5383, 22928, 18864, 3629, 5832, 20180, 27816, 5236, 24180, 8245, 798, 11760, 26038, 28339, 6581, 11952, 18262, 7399, 12242, 10310, 54, 2077, 23418, 20806, 21174, 29008, 8785, 29900, 19173, 125, 29468, 8546, 9328, 8236, 26049, 11212, 18052, 3895, 15265, 27813, 14998, 3630, 27873, 3738, 28855, 3987, 5096, 29162, 28595, 17682, 10178, 17865, 21877, 14132, 9442, 13845, 6599, 10399, 26165, 4833, 4869, 4453, 19766, 15022, 7742, 1715, 9241, 17468, 26572, 5954, 7862, 6, 27258, 7202, 7432, 14240, 8518, 10567, 27484, 16789, 6777, 5189, 22115, 12206, 11538, 485, 3351, 1077, 22352, 24874, 10043, 29834, 143, 2124, 3724, 18625, 164, 15797, 28212, 19175, 26714, 20347, 28218, 26316, 14566, 21142, 4644, 374, 11526, 15387, 6056, 15483, 7421, 20415, 11866, 8715, 19421, 28152, 19402, 29023, 21388, 6897, 19542, 11991, 26765, 27863, 27864, 11771, 9803, 14819, 22862, 978, 6771, 15136, 13973, 8469, 19532, 18980, 7710, 29059, 7293, 26903, 24995, 28616, 12915, 16227, 347, 16238, 3827, 20649, 22713, 22810, 10259, 2802, 22227, 25456, 7930, 20926, 10004, 12791, 11606, 28958, 23350, 22715, 15400, 29228, 25428, 28026, 22283, 10841, 9829, 21905, 6717, 29151, 25084, 14313, 8727, 3371, 10511, 11984, 9978, 5683, 21106, 9587, 26759, 8322, 15147, 3245, 22412, 1859, 20432, 15316, 9366, 16829, 10002, 24609, 274, 10535, 23615, 17514, 2400, 7091, 14731, 1759, 4940, 26118, 12633, 7968, 8138, 7521, 6421, 17189, 18679, 28026, 25624, 25555, 10423, 16744, 11491, 26397, 7529, 22916, 8138, 4501, 24637, 27125, 6745, 2394, 12378, 18862, 6117, 8788, 13402, 925, 2847, 9646, 12856, 25875, 2502, 14186, 2361, 3015, 18570, 5717, 9868, 5581, 14153, 13947, 3936, 18219, 22975, 22528, 27159, 25848, 27098, 12380, 7248, 26597, 28034, 15684, 22943, 25847, 15654, 24276, 3919, 18539, 6020, 27578, 29461, 19366, 24825, 25350, 26784, 2185, 25694, 1698, 29156, 15512, 22218, 10564, 13413, 23300, 1586, 10604, 22759, 16549, 11485, 9679, 18230, 17719, 21989, 19485, 1483, 13117, 27857, 29899, 21255, 29377, 1131, 5277, 14032, 6316, 1015, 25510, 17327, 8929, 27115, 25237, 6234, 24043, 3481, 9607, 29590, 21800, 21355, 1670, 7594, 2112, 26834, 1639, 12893, 1354, 16043, 29159, 4205, 22806, 27790, 9255, 22040, 16598, 17526, 1523, 14607, 10112, 968, 11990, 25511, 28139, 5703, 25074, 877, 9338, 21252, 13258, 23000, 19237, 13644, 9117, 20291, 13538, 26345, 2359, 8066, 18287, 8772, 22081, 10843, 24456, 12618, 25401, 1410, 21348, 12062, 21672, 24285, 7933, 2083, 2274, 24247, 24157, 12814, 1445, 22112, 4172, 28746, 13999, 251, 5531, 26580, 12182, 8487, 3619, 16593, 22217, 26039, 9148, 17991, 24833, 27301, 15460, 24042, 10259, 18064, 26705, 7161, 4373, 21943, 8911, 2429, 7601, 6976, 4904, 16292, 21807, 23789, 14685, 24496, 18523, 23655, 19150, 20736, 20732, 14882, 10740, 22733, 5513, 308, 21169, 24361, 13947, 18707, 11624, 9053, 21479, 28178, 10153, 24943, 12674, 5989, 9685, 16696, 25793, 21421, 17416, 1610, 25110, 17800, 18951, 23596, 10806, 20132, 4068, 6947, 7583, 22813, 28492, 25133, 13248, 29887, 29527, 21354, 11185, 22839, 5839, 25630, 17081, 21189, 7570, 20335, 11240, 21188, 25866, 28967, 7919, 5023, 3837, 12832, 3043, 10302, 20171, 21093, 9029, 27933, 23662, 723, 26199, 25209, 9798, 10396, 6913, 8546, 8018, 28220, 21731, 27514, 11984, 11323, 20591, 269, 19735, 29254, 26954, 2829, 5221, 19584, 400, 12643, 21733, 10830, 17414, 8677, 24809, 5754, 23759, 2268, 25322, 15427, 16090, 15619, 766, 20964, 17849, 18570, 22035, 27610, 6706, 21582, 18964, 15129, 2999, 12645, 14495, 15598, 20425, 16, 2289, 7373, 21084, 13867, 16039, 17633, 10872, 3217, 20648, 20233, 14303, 17965, 20071, 22201, 18411, 27154, 18740, 2359, 15328, 967, 5166, 2477, 8464, 25816, 336, 4202, 14362, 4200, 9791, 422, 15460, 2697, 11587, 28379, 20712, 11092, 9262, 16047, 26621, 29125, 16484, 8309, 14113, 20824, 2913, 4558, 6123, 4212, 21446, 15269, 24374, 22252, 27726, 24247, 11566, 15219, 15135, 20162, 27998, 18977, 580, 2319, 6700, 2132, 7840, 12965, 27612, 2479, 17108, 27874, 14460, 1603, 19717, 15540, 2021, 3100, 26603, 10759, 26264, 20596, 7144, 27471, 29809, 26531, 4028, 12898, 22388, 16711, 19765, 5883, 26217, 19585, 7866, 9406, 17991, 21851, 247, 19085, 9918, 20025, 24089, 13235, 29291, 27909, 10823, 13297, 20158, 13092, 12812, 6935, 16004, 20522, 28436, 17530, 18770, 17696, 350, 8662, 22174, 23291, 24345, 14214, 14921, 1435, 10727, 5143, 21056, 26041, 16420, 16348, 8069, 29264, 25381, 27841, 36, 3975, 4859, 4668, 23421, 11107, 5726, 11941, 11514, 17243, 19843, 16937, 2602, 1298, 16350, 25319, 18745, 29094, 26331, 12999, 6238, 9692, 9806, 15259, 17169, 21217, 22755, 19985, 25558, 29863, 17980, 4564, 23906, 7261, 24591, 29050, 14941, 21793, 27086, 24643, 10410, 26817, 20363, 8177, 24131, 26431, 14447, 1135, 9790, 15724, 15023, 4357, 27507, 652, 169, 25223, 24819, 12935, 1658, 29142, 13666, 785, 21722, 28881, 21332, 15536, 22502, 17522, 14746, 7537, 675, 12008, 14743, 3261, 5279, 21756, 12823, 11435, 16411, 28420, 8604, 25471, 13430, 19156, 26561, 25370, 4859, 24230, 11606, 23836, 6258, 2655, 23395, 3287, 1902, 14236, 10157, 23175, 14833, 9041, 12692, 195, 29665, 19949, 7940, 25719, 9744, 1971, 11956, 1885, 903, 3887, 11933, 20612, 22810, 20749, 17813, 22556, 16464, 27398, 20782, 4624, 1322, 8331, 29284, 17099, 10111, 22227, 24175, 26311, 26280, 21541, 10458, 21353, 14146, 25008, 26085, 13192, 20110, 18174, 10554, 25745, 20399, 876, 10525, 12688, 3573, 20056, 11251, 17027, 23619, 955, 25955, 12967, 20335, 22682, 9619, 18084, 20633, 19011, 16998, 3636, 7259, 11657, 11035, 20375, 9893, 17380, 17542, 16326, 9516, 29264, 13265, 25468, 17855, 26106, 12117, 5983, 28261, 7312, 20951, 21369, 29539, 941, 3689, 12646, 12076, 1635, 10854, 24090, 12032, 23682, 9481, 12340, 8695, 32, 15747, 24917, 12820, 29169, 22237, 26201, 9471, 27746, 3547, 12372, 19853, 4792, 19915, 8729, 1753, 23706, 12672, 15957, 24052, 1333, 21842, 25173, 29176, 2310, 4188, 7581, 12017, 21306, 25823, 10936, 6913, 3756, 5738, 2775, 27400, 25880, 28402, 14995, 9983, 28668, 9530, 24109, 28120, 8601, 17988, 11670, 27948, 18798, 21449, 7222, 27632, 17384, 10476, 14645, 7324, 16224, 11011, 2346, 5574, 6397, 16096, 24892, 19885, 14867, 24219, 12884, 29409, 16446, 215, 20231, 28373, 19031, 216, 15464, 23995, 22581, 1399, 14901, 15418, 18406, 14812, 15752, 9322, 4205, 13495, 14214, 2924, 1843, 3456, 14722, 14050, 28407, 3113, 6838, 15132, 19799, 23959, 11781, 21139, 4620, 22657, 2867, 19636, 16436, 15176, 10079, 11840, 10146, 5888, 24055, 9117, 17170, 23506, 21302, 15517, 7128, 15042, 24155, 27490, 25410, 15670, 19742, 4104, 12052, 1408, 27970, 24869, 29289, 5670, 29842, 24683, 10367, 4078, 26554, 27782, 3003, 23919, 18347, 23737, 4032, 12664, 66, 4262, 16389, 14, 17254, 14901, 14691, 26893, 1386, 28267, 26110, 21427, 16571, 29092, 1218, 25114, 429, 8865, 4810, 12129, 28384, 29118, 16455, 19269, 26009, 17581, 4830, 5565, 2440, 13963, 24167, 12199, 17162, 1073, 16002, 23733, 5558, 3871, 2352, 20914, 3405, 22670, 8571, 15027, 17568, 2425, 23698, 22218, 20038, 19781, 11166, 16768, 9242, 2646, 4678, 5725, 27341, 756, 13255, 10920, 16585, 29890, 6369, 12178, 21872, 12066, 25006, 10416, 6255, 12595, 16389, 23258, 10536, 20205, 8319, 5603, 17705, 10208, 6849, 7750, 16760, 15992, 28061, 3917, 22306, 19625, 1345, 7569, 26035, 13995, 8547, 27539, 4106, 9950, 20693, 4264, 14847, 2393, 26217, 4794, 25472, 19331, 4261, 28547, 17352, 4006, 18582, 3880, 29998, 28214, 7547, 17742, 16913, 15783, 29237, 18765, 28470, 493, 16391, 17643, 11060, 24516, 8383, 11477, 10640, 16872, 25692, 26958, 25340, 13657, 11178, 116, 21279, 28259, 8116, 12203, 9634, 14070, 12218, 16448, 5480, 16748, 9872, 22645, 18346, 28635, 8145, 11451, 18051, 17822, 6968, 24879, 15630, 9191, 20646, 9483, 6969, 16241, 15641, 2966, 19014, 25676, 24715, 7400, 2866, 11542, 12744, 10918, 9403, 16081, 1505, 932, 16207, 14515, 29426, 14245, 10778, 15332, 12701, 7510, 27433, 27158, 25350, 10284, 18196, 3679, 9542, 6733, 29492, 2386, 4465, 4231, 8715, 8853, 2742, 10037, 20232, 13008, 7076, 10799, 19027, 9124, 5598, 19714, 24955, 3260, 25835, 10483, 8178, 27663, 10326, 11764, 22046, 25981, 9751, 22224, 24567, 12114, 82, 14518, 2896, 4438, 1748, 10601, 10684, 29934, 28392, 28394, 3770, 25127, 14981, 11038, 3319, 11061, 7954, 22659, 1107, 2046, 17241, 7344, 17435, 3158, 3551, 702, 8823, 6845, 5224, 21675, 17156, 13464, 1405, 4736, 22636, 28885, 8921, 8018, 2789, 9104, 2918, 2362, 10228, 25513, 8155, 9281, 24293, 7472, 20995, 1646, 27153, 22255, 28506, 20255, 12556, 12790, 18432, 27784, 21425, 23267, 7821, 5415, 25958, 19307, 23069, 7775, 6714, 18526, 3652, 19191, 17337, 25758, 385, 26872, 14354, 13823, 21524, 18150, 14607, 6749, 11683, 6293, 15511, 6978, 13007, 3687, 16905, 1440, 11293, 455, 28230, 20444, 9005, 16570, 21177, 15217, 16426, 5822, 6364, 12552, 14227, 20681, 2597, 26009, 8588, 2965, 21715, 9905, 26287, 1992, 28653, 3608, 24938, 14749, 5874, 25480, 3068, 29703, 4278, 27093, 19041, 27803, 607, 7919, 4210, 28974, 21728, 11193, 15613, 17809, 12594, 22108, 6095, 16117, 29646, 28677, 22742, 9075, 14368, 21289, 16767, 23010, 1584, 24823, 356, 4146, 28535, 16257, 8902, 16792, 266, 27815, 17595, 19927, 28758, 14365, 403, 14592, 18721, 26014, 28174, 27002, 28780, 1158, 25911, 1433, 2255, 5376, 16404, 14192, 6698, 8544, 5367, 12288, 26508, 2779, 18480, 29016, 6986, 2225, 21095, 2231, 5589, 9690, 20778, 1654, 10268, 5374, 14333, 4358, 22798, 21357, 11407, 12850, 13783, 29989, 2760, 6955, 7250, 14847, 7476, 11168, 23218, 266, 6302, 22026, 17753, 29652, 14736, 15012, 5132, 1281, 15706, 21995, 3485, 16744, 3434, 26010, 9509, 24978, 24096, 1911, 18607, 21415, 28327, 13496, 29815, 5079, 6772, 26313, 15517, 13494, 4196, 13433, 3289, 8160, 9832, 7159, 18596, 25474, 11935, 15793, 16040, 1678, 10009, 24856, 18630, 8893, 27581, 17512, 12393, 16802, 2050, 16228, 25440, 6928, 25106, 3245, 16261, 29612, 11905, 28099, 20497, 19364, 27562, 9325, 28365, 17262, 9156, 10819, 5610, 5745, 22014, 3206, 7779, 27480, 20981, 14831, 10741, 1327, 7257, 286, 20099, 29212, 28795, 27688, 1916, 23466, 16598, 3007, 10328, 3932, 8972, 25327, 27392, 22437, 22104, 22932, 23804, 22604, 21504, 450, 1218, 21832, 23926, 18777, 2738, 24057, 3891, 21269, 20344, 4614, 21903, 27125, 21404, 23880, 22295, 19242, 29842, 4548, 3696, 570, 14263, 14423, 1376, 9818, 7478, 13233, 11946, 27192, 28719, 1613, 9087, 27176, 4584, 23445, 18492, 26693, 627, 26772, 20178, 2146, 1449, 29372, 1498, 13702, 22670, 27589, 27520, 4246, 8589, 7812, 11547, 14762, 1157, 23218, 25173, 11406, 29663, 8408, 5707, 6626, 21083, 15710, 5127, 10213, 6857, 17714, 16058, 3581, 12402, 27829, 28533, 2554, 26096, 149, 10627, 21206, 22188, 25207, 27235, 27032, 3355, 13786, 29389, 7957, 16128, 20842, 1609, 21416, 19183, 5157, 29618, 18927, 10521, 20331, 26049, 17564, 20033, 10019, 26678, 20434, 19066, 26482, 6717, 18013, 9582, 3245, 2336, 4327, 19605, 26914, 11893, 29183, 20928, 16093, 15763, 15600, 20664, 17920, 13956, 28194, 5338, 21754, 28497, 11585, 11935, 22458, 6521, 15058, 23639, 23011, 18695, 24949, 430, 5698, 5909, 24096, 20750, 15035, 7784, 20469, 14237, 23853, 6341, 1982, 16697, 29203, 18422, 19496, 18182, 3980, 14152, 248, 6608, 5130, 24392, 6809, 9616, 17249, 18404, 7806, 28930, 10612, 5371, 12042, 23206, 27503, 7106, 11442, 27644, 9092, 16056, 21428, 25322, 25642, 12763, 11727, 4149, 15262, 4346, 12464, 1271, 21671, 8625, 7460, 2362, 15777, 21081, 11528, 11953, 2044, 20917, 253, 13503, 26420, 12126, 12037, 23291, 26182, 6087, 7669, 5986, 13050, 104, 12337, 14094, 22425, 14090, 22330, 14924, 6104, 25598, 1327, 5949, 21947, 23228, 4667, 14101, 11397, 14266, 25985, 24406, 13225, 29311, 23387, 24138, 22602, 17942, 11390, 29135, 6399, 7679, 9248, 5021, 26509, 4559, 2235, 14716, 21874, 25553, 4148, 24395, 23222, 15007, 10040, 23840, 23055, 18741, 25817, 12776, 26811, 20942, 1457, 17299, 7663, 22429, 4653, 14797, 7201, 24565, 27215, 19032, 13999, 8569, 10936, 17934, 7057, 9115, 28802, 11885, 2405, 14481, 24052, 7712, 10441, 15813, 27482, 10356, 27776, 29014, 5579, 1634, 25597, 17646, 17095, 9440, 17574, 7515, 4046, 13918, 14528, 19954, 3134, 23885, 6765, 26382, 4962, 20715, 789, 605, 13798, 16073, 837, 4170, 29706, 19154, 10038, 19094, 9543, 17065, 11291, 26358, 29273, 26352, 7897, 27263, 12919, 27324, 15244, 27379, 26642, 19940, 9602, 29028, 19889, 27346, 5326, 28323, 29930, 29466, 7109, 29918, 25854, 23355, 12645, 5345, 19414, 11841, 13503, 3390, 18920, 27144, 16740, 7288, 15289, 16086, 16072, 23956, 25708, 24436, 9848, 12270, 11746, 21079, 13905, 10723, 10425, 16478, 20897, 5301, 10775, 19129, 23147, 9273, 1085, 10819, 17270, 28679, 26284, 17942, 29964, 2759, 18980, 14508, 24752, 4528, 11220, 4446, 7330, 13232, 11010, 22122, 29293, 7269, 1538, 26779, 6844, 6900, 14623, 18667, 15946, 8863, 15193, 14263, 20916, 16339, 7349, 26107, 19165, 699, 8200, 10461, 27120, 17895, 21345, 20461, 20005, 29218, 18454, 13341, 8512, 9895, 27307, 2520, 26397, 19617, 26421, 10152, 25759, 26553, 15895, 11886, 3898, 15733, 16211, 27849, 17443, 789, 26835, 24282, 20156, 17279, 21908, 29822, 2039, 17243, 229, 9053, 12679, 2222, 12170, 4860, 27372, 12900, 10325, 24833, 12139, 24476, 21582, 11918, 19085, 3257, 21369, 732, 1426, 4289, 2008, 6128, 11765, 3151, 26433, 631, 17595, 16632, 1241, 29767, 2967, 4242, 11392, 19336, 28796, 15002, 28745, 8579, 29550, 11366, 2058, 10028, 13866, 10907, 738, 20980, 18888, 24864, 16841, 11710, 11842, 16996, 4516, 18397, 11097, 29416, 10385, 19758, 9834, 10042, 12205, 28125, 15882, 24773, 6138, 25553, 4050, 144, 2927, 16989, 18186, 23845, 14323, 11528, 24433, 19317, 4517, 18990, 22828, 22428, 24430, 9824, 17046, 16760, 26716, 15201, 28560, 22264, 3031, 25534, 29252, 2026, 23746, 22716, 12919, 15139, 6985, 2374, 19361, 5053, 28419, 21248, 17071, 16512, 27464, 10069, 15932, 5921, 5295, 4343, 28156, 28731, 4760, 24612, 5778, 20113, 27120, 26495, 12802, 6982, 12361, 15315, 8970, 11751, 17071, 1485, 26005, 21494, 25467, 1305, 12951, 9795, 17755, 17098, 21316, 3774, 5565, 17308, 26746, 18578, 2713, 5770, 1371, 16647, 1418, 10656, 13550, 5103, 11408, 8448, 29971, 4975, 29981, 7454, 24564, 17633, 3611, 8154, 12650, 3858, 17775, 19983, 29442, 17390, 11079, 1048, 23455, 19784, 20321, 10952, 16943, 28027, 11036, 12992, 14989, 6024, 5049, 25999, 16233, 14549, 25216, 24869, 24451, 7690, 19325, 5070, 10649, 20806, 28986, 15819, 21394, 5935, 26565, 15781, 26834, 12540, 29742, 27790, 12687, 4836, 7723, 13414, 27575, 12625, 11969, 23363, 1985, 1029, 18400, 14331, 20426, 29149, 26480, 22527, 6529, 18692, 6024, 550, 1539, 27920, 26906, 2793, 1235, 12583, 14925, 1495, 4275, 5771, 23936, 5639, 2152, 26997, 5372, 4520, 16718, 11226, 11025, 17076, 11370, 11505, 29667, 4508, 20333, 1067, 45, 6581, 29406, 15744, 29636, 24496, 324, 13660, 3998, 4740, 21788, 9979, 10690, 8531, 13643, 7714, 25658, 10307, 2838, 16292, 5437, 14140, 14763, 14916, 3633, 8818, 7933, 26883, 19487, 19694, 19614, 1146, 6710, 26211, 24768, 2832, 17345, 19807, 9101, 12709, 18593, 25749, 18510, 11490, 27920, 7227, 8604, 28834, 21197, 16487, 29193, 28925, 9672, 10019, 27583, 12443, 9228, 27827, 6413, 22100, 10105, 3627, 1125, 25242, 28462, 10820, 21405, 1538, 9626, 23933, 18651, 14395, 18593, 24826, 22455, 12559, 20042, 25713, 19161, 17711, 18486, 12480, 14204, 13970, 18701, 7620, 4222, 27519, 1198, 2116, 6983, 5214, 2496, 11118, 27823, 19029, 10003, 16645, 525, 27495, 2269, 15309, 11369, 11593, 5298, 11673, 16306, 24013, 6383, 21080, 1715, 26404, 25570, 18328, 2875, 9233, 11663, 12254, 1726, 14621, 8384, 29595, 12915, 376, 23877, 11917, 26688, 3677, 23440, 10199, 7680, 20593, 9986, 7762, 20648, 7824, 22599, 4356, 8394, 27887, 14099, 22394, 6488, 15691, 24791, 4292, 20342, 11309, 591, 12362, 29562, 17684, 22700, 28117, 9401, 21413, 4319, 16430, 4179, 23201, 6594, 29923, 3900, 29817, 2108, 7195, 4895, 21406, 15998, 8061, 3843, 11972, 4488, 26864, 5629, 2484, 7344, 8596, 21777, 23452, 19132, 24092, 9117, 24351, 4011, 20075, 14543, 9865, 1619, 27912, 11508, 4241, 1098, 31, 16514, 20245, 28542, 29178, 5628, 26673, 25037, 23031, 28264, 22042, 8146, 28060, 8457, 16906, 15277, 9064, 3106, 22059, 11871, 3107, 3254, 23462, 9103, 7541, 10217, 12788, 13265, 10767, 5697, 29464, 26029, 9781, 3217, 12434, 9260, 15000, 7047, 18842, 23270, 1162, 23149, 22250, 8847, 23236, 27573, 21929, 1358, 6480, 22892, 15685, 273, 7886, 24122, 10196, 22449, 3525, 9149, 8746, 12770, 28335, 24232, 10728, 23975, 3305, 26563, 15211, 21431, 2902, 25440, 12556, 5863, 24593, 10151, 4207, 3877, 12024, 16393, 21246, 3617, 29850, 62, 26357, 6140, 3706, 18765, 8529, 3752, 24241, 26580, 28474, 18067, 24781, 11346, 24909, 8104, 18426, 24571, 25515, 7885, 6320, 27555, 22906, 24828, 7883, 3976, 8186, 27322, 17809, 29598, 7240, 15869, 7565, 10170, 29785, 9827, 29234, 25819, 4651, 11618, 12139, 18512, 4290, 25236, 24404, 6607, 4861, 11284, 4443, 11120, 17293, 6806, 16415, 25214, 24544, 23241, 7228, 14725, 23008, 2191, 6991, 21160, 10524, 28721, 3523, 9218, 17736, 5495, 28666, 16134, 12712, 17320, 11323, 23604, 379, 25911, 13282, 16891, 7698, 13669, 11741, 19240, 23162, 28408, 14971, 20572, 17129, 19838, 19668, 23443, 24923, 29398, 27352, 14952, 7626, 25462, 1848, 4716, 21400, 21880, 26832, 27358, 13161, 6278, 4319, 15268, 27530, 13786, 18930, 19492, 18810, 6439, 26627, 4225, 15374, 17699, 15713, 19756, 1854, 29626, 15338, 15314, 16698, 11087, 25778, 10946, 1685, 14655, 20866, 26206, 384, 12405, 24380, 16991, 25910, 5771, 24927, 18915, 21956, 24853, 10235, 16811, 1882, 17213, 25407, 15542, 1621, 8564, 24343, 2792, 2592, 24281, 21209, 6730, 1125, 20707, 18363, 1113, 17976, 24313, 4670, 20220, 23605, 879, 17474, 5314, 14590, 22764, 22094, 10956, 12103, 21248, 26796, 10071, 5143, 11511, 20338, 8340, 25821, 4132, 2156, 20706, 383, 7105, 1409, 23430, 24173, 13211, 5107, 10568, 7282, 16009, 18071, 19018, 21550, 24933, 10980, 3591, 28739, 2439, 11568, 989, 22644, 24508, 23808, 14630, 14961, 25231, 29812, 729, 27137, 28878, 24992, 10343, 16775, 24437, 21027, 28683, 19690, 12223, 17800, 6178, 13638, 2395, 17332, 29196, 29961, 20036, 2826, 28854, 28292, 27844, 6302, 11869, 5457, 27737, 6096, 14872, 3020, 18806, 7147, 25198, 16991, 28450, 19127, 8745, 27563, 6488, 11963, 18121, 17919, 25471, 448, 14408, 14627, 19169, 29375, 1871, 15512, 9220, 23788, 25874, 11469, 6216, 19839, 22335, 19862, 22575, 3242, 26001, 18108, 19352, 13387, 13353, 5649, 3143, 8346, 1579, 10156, 7182, 25144, 25867, 9136, 25547, 24605, 20002, 4707, 11920, 1865, 2692, 9212, 22627, 16188, 16342, 4516, 6462, 4602, 21266, 8406, 20697, 11489, 8696, 23052, 21523, 1246, 26928, 6588, 18071, 26186, 22077, 259, 4110, 5189, 5921, 13440, 13861, 10658, 27522, 21585, 15672, 21424, 5221, 29279, 5725, 4770, 24639, 23585, 23941, 19423, 21377, 3001, 12526, 23374, 10239, 561, 20871, 19272, 8300, 12100, 3218, 16034, 25114, 5701, 29824, 17993, 22964, 11788, 23952, 21399, 24403, 11457, 3401, 27577, 11520, 18250, 23467, 23585, 16512, 16860, 16746, 24891, 5374, 16749, 21429, 27865, 6676, 20265, 28927, 13275, 13259, 2516, 7344, 19344, 13052, 7163, 2040, 21032, 16359, 23360, 17611, 12464, 6481, 29676, 13566, 9198, 2294, 22795, 5935, 29610, 16036, 12364, 4535, 17508, 4916, 8644, 18133, 22663, 11454, 1856, 21716, 12566, 14409, 14080, 21555, 11803, 6205, 9079, 10295, 12766, 11744, 10343, 1553, 248, 22656, 15753, 26300, 10821, 8705, 1711, 14054, 9241, 15423, 11315, 17745, 1669, 24433, 20553, 23095, 20435, 6416, 29571, 15485, 5736, 14305, 2299, 4718, 403, 23523, 6086, 26650, 29540, 1714, 1966, 15596, 25840, 11871, 9416, 6635, 6593, 19524, 14471, 20657, 28261, 11618, 8274, 23405, 19480, 6231, 19403, 6166, 11528, 6002, 8237, 10026, 14327, 17323, 14105, 25191, 26372, 5254, 7972, 16066, 1480, 5806, 18384, 23724, 9299, 19432, 9864, 4753, 18660, 1584, 26828, 12024, 17734, 703, 16251, 13748, 18166, 16920, 23575, 2172, 7874, 11939, 28525, 26042, 11985, 17957, 23551, 3526, 22984, 13396, 29189, 15734, 27930, 4652, 18172, 16003, 273, 966, 5806, 29397, 16846, 314, 16899, 24887, 25035, 11758, 10533, 9607, 27746, 846, 26044, 2294, 9539, 19112, 23363, 22111, 17103, 4467, 1528, 16147, 19207, 1922, 12558, 16559, 1390, 25237, 13208, 8697, 24720, 27857, 17884, 18733, 7146, 29843, 10200, 4270, 3105, 22152, 1311, 24253, 26611, 6169, 17501, 7442, 2565, 25677, 3358, 20526, 25515, 7109, 1035, 16647, 15759, 21584, 26721, 22040, 29575, 8472, 1622, 15260, 27948, 28118, 2906, 21236, 27014, 13354, 18415, 12781, 23328, 18709, 728, 27122, 27732, 15147, 259, 28365, 4667, 11353, 3377, 24511, 17613, 14678, 16817, 18119, 2914, 28456, 26186, 25178, 23794, 8862, 15172, 18191, 18016, 21875, 23963, 4161, 16659, 13317, 4080, 14351, 9365, 8070, 19362, 4565, 28579, 162, 22677, 12143, 29940, 25155, 25868, 3387, 21414, 2501, 8734, 20700, 14594, 24576, 27224, 13177, 225, 22432, 14061, 13277, 11245, 9458, 13984, 17385, 10931, 1026, 5938, 7894, 14573, 6601, 8165, 8224, 20402, 6895, 7448, 11415, 19272, 17599, 25900, 27368, 27818, 452, 25807, 294, 8993, 5107, 7693, 20722, 19049, 4683, 3466, 6914, 15716, 3157, 24596, 28494, 16432, 7719, 129, 18566, 14872, 24064, 20836, 5853, 15578, 13176, 20828, 9527, 7184, 10930, 23234, 25109, 27426, 23917, 19480, 26098, 17474, 2590, 21295, 19067, 25571, 1798, 1038, 4410, 15, 22254, 18775, 7368, 16977, 5387, 11009, 29550, 6968, 7443, 4663, 15225, 21468, 14941, 22264, 4484, 3606, 8825, 18746, 4228, 27703, 19777, 20321, 7178, 23748, 14046, 24850, 17146, 10899, 28792, 25904, 18878, 15841, 5453, 12666, 5630, 15623, 13816, 27549, 10151, 10219, 4289, 25739, 8650, 17950, 17717, 8084, 20365, 18662, 10916, 18130, 27501, 1751, 9452, 24646, 6685, 3809, 18184, 17022, 1519, 20637, 22454, 1206, 2466, 9272, 23750, 29383, 19201, 11490, 3882, 17478, 6825, 16988, 23117, 24404, 10843, 25794, 9400, 2947, 9706, 18145, 7747, 11878, 19925, 13630, 5379, 3256, 16592, 16285, 24519, 2401, 19337, 12274, 3126, 29990, 15605, 27457, 16333, 26188, 14667, 15501, 14521, 15224, 22219, 6008, 16337, 21223, 4009, 2135, 22726, 11530, 3972, 8367, 2143, 17968, 29664, 21159, 7720, 17361, 9601, 13383, 12934, 621, 3253, 3891, 5165, 21234, 11320, 12604, 13363, 8116, 9280, 24543, 14170, 715, 9739, 22131, 22417, 27269, 2244, 9344, 10891, 19965, 19526, 29741, 14976, 1309, 8295, 28252, 25538, 25037, 4451, 309, 29512, 28386, 6600, 2466, 19080, 4033, 29520, 27229, 22487, 24559, 28368, 28926, 28501, 25602, 19502, 7220, 10219, 25483, 10417, 27088, 18799, 29376, 8058, 10744, 12858, 14361, 10355, 19326, 4189, 16218, 15394, 23319, 2163, 13212, 28101, 14079, 12659, 22138, 13187, 24442, 15475, 16987, 29146, 25254, 569, 5863, 21475, 27896, 21266, 4758, 19521, 17175, 5430, 13632, 16597, 18450, 19676, 24157, 3314, 8913, 23638, 8135, 20599, 19500, 29556, 24, 18959, 4425, 1408, 10458, 11464, 14556, 5963, 21210, 9196, 12147, 21863, 12107, 14525, 18342, 4278, 4756, 28502, 13784, 15744, 3508, 17808, 14775, 23373, 17300, 871, 14647, 27068, 29934, 21285, 3180, 8285, 4359, 20339, 5347, 5215, 26189, 9665, 10465, 7933, 25780, 28797, 5395, 25293, 9832, 3820, 15720, 24189, 2100, 12409, 11704, 5400, 25934, 14788, 21949, 911, 21542, 20325, 15329, 25715, 8574, 21057, 9338, 20584, 23555, 1027, 23338, 27678, 1582, 23042, 13194, 25882, 29138, 16963, 3511, 19074, 28891, 761, 29375, 21846, 23277, 10064, 11113, 12129, 21485, 4655, 3499, 16737, 23812, 14837, 453, 18181, 29643, 27478, 23012, 21537, 403, 25630, 24920, 27659, 4989, 5951, 6865, 10744, 29931, 7231, 13687, 19597, 91, 14637, 1879, 16854, 19469, 6607, 10020, 19953, 12441, 27308, 16191, 17836, 6818, 7408, 18262, 9656, 19502, 16011, 16924, 23228, 9567, 28095, 10793, 16025, 10000, 16784, 5932, 16607, 6000, 2205, 26259, 10172, 16447, 26462, 10015, 359, 837, 29164, 3010, 7391, 4400, 9657, 5015, 19861, 28167, 10397, 20184, 24568, 24928, 15312, 3689, 27301, 28487, 24244, 14346, 27986, 14620, 26002, 9091, 29246, 6131, 11701, 7210, 10510, 23400, 28710, 17594, 19410, 15662, 11810, 13978, 27784, 23891, 5151, 16823, 20004, 7761, 2237, 9934, 22780, 17297, 27767, 28470, 8100, 11161, 22701, 29196, 17397, 9735, 12586, 25584, 19031, 18809, 26322, 9081, 2266, 28318, 976, 23913, 20044, 28393, 10836, 13142, 10851, 21456, 13259, 17729, 27267, 27560, 5302, 28359, 14813, 23850, 11480, 24690, 27145, 4190, 25623, 11548, 2534, 2658, 17082, 13843, 28476, 9170, 16726, 18416, 23038, 11232, 3954, 29556, 20877, 1372, 23497, 25936, 16802, 8198, 27403, 7321, 16055, 22252, 17177, 7694, 4803, 10450, 19976, 25039, 15621, 26472, 19001, 17057, 11207, 9089, 8931, 22844, 25270, 27772, 8718, 3013, 28074, 20133, 14752, 293, 11079, 4490, 22433, 22557, 21600, 11362, 24614, 12023, 2374, 11238, 22870, 19362, 1889, 11362, 26087, 22480, 29106, 28062, 11527, 24099, 2370, 8624, 16410, 27661, 244, 21477, 15190, 13073, 21267, 8017, 21052, 2753, 28915, 20843, 15453, 18948, 18855, 14702, 19816, 21900, 5479, 3016, 13552, 19114, 17949, 1746, 19418, 26861, 4653, 7270, 283, 15928, 14214, 17990, 14884, 8187, 29157, 19004, 24695, 5261, 2779, 27485, 2093, 8630, 22094, 3831, 28624, 19936, 26961, 17173, 4401, 8895, 22348, 8391, 13970, 17373, 2111, 26170, 14814, 18577, 4400, 4052, 3722, 1798, 15112, 22913, 24041, 22182, 25179, 22965, 19281, 8904, 2161, 21879, 4393, 15786, 1680, 22332, 24077, 699, 17800, 17420, 4336, 3469, 29909, 29693, 17280, 1737, 26448, 29981, 17438, 21839, 20729, 17250, 3795, 23315, 17360, 21578, 17231, 24803, 7921, 3508, 3792, 13364, 740, 13637, 6579, 25288, 25066, 1948, 9803, 17021, 19397, 22922, 8031, 8998, 22678, 13340, 9559, 27526, 25386, 12329, 6861, 28923, 4265, 25834, 9453, 27282, 22641, 25890, 18722, 5567, 28821, 1036, 11728, 25187, 15202, 29029, 11382, 21908, 7309, 10365, 3395, 12725, 12416, 11237, 13688, 15275, 17698, 13562, 411, 17234, 10292, 25794, 5876, 14235, 7254, 11163, 11103, 26958, 19764, 14188, 342, 28604, 3771, 20392, 10613, 23192, 11603, 17631, 4439, 12165, 13257, 4642, 4869, 8793, 7544, 2920, 10142, 789, 9034, 16351, 27774, 5273, 2226, 7664, 2802, 12174, 25448, 22331, 14604, 20090, 10127, 3686, 11719, 12083, 7133, 29372, 4017, 20927, 7632, 6220, 181, 10838, 11966, 10286, 13025, 11741, 21063, 17043, 6056, 8832, 9855, 20307, 14459, 18472, 22357, 26717, 7867, 17989, 20354, 9679, 19251, 20524, 3141, 3217, 6453, 5830, 1242, 9075, 14010, 5901, 29699, 28937, 2000, 8788, 19311, 3841, 15324, 27763, 18054, 28204, 255, 8604, 20833, 18260, 3095, 27162, 4004, 18059, 13641, 21551, 17866, 6728, 19722, 10620, 1284, 14824, 25027, 16742, 28661, 14059, 8709, 5647, 2332, 7248, 19735, 21882, 22201, 3134, 10000, 11593, 17206, 3417, 17055, 13364, 23785, 4318, 25272, 11568, 11718, 21230, 10770, 9788, 12159, 28541, 5671, 28607, 12580, 4608, 24977, 24226, 653, 24427, 27754, 12927, 25826, 10850, 7976, 12310, 26162, 4531, 10097, 22168, 6297, 23573, 28210, 3587, 12255, 27146, 21245, 14821, 7519, 12796, 16701, 6926, 19097, 14472, 12493, 99, 3076, 28109, 4008, 27574, 15987, 1216, 9110, 8159, 9667, 12274, 9589, 23925, 25783, 14648, 11273, 267, 12776, 29634, 4583, 23544, 1881, 18794, 24639, 23432, 385, 8447, 3285, 11103, 26820, 7607, 11810, 14161, 1108, 15149, 13911, 17365, 19459, 19723, 21533, 1417, 6890, 28933, 10218, 8111, 20297, 29415, 12428, 3128, 24392, 12328, 10273, 13873, 28181, 21072, 26879, 14218, 15360, 9144, 12252, 21295, 10926, 1163, 20796, 329, 21342, 10926, 9515, 902, 23513, 1265, 3210, 25142, 22906, 17413, 29631, 12923, 18605, 21430, 16529, 17471, 4334, 17337, 26131, 12048, 12607, 951, 17675, 14901, 7619, 19111, 12068, 25353, 5490, 14879, 12665, 13582, 27221, 9324, 17261, 3132, 20269, 13695, 15291, 3497, 22084, 10842, 15930, 12093, 22192, 20640, 50, 16925, 25634, 12506, 24902, 20638, 6762, 23065, 21884, 9543, 22526, 15952, 5666, 18039, 11812, 6828, 17794, 27039, 15182, 11832, 19708, 5369, 6194, 20657, 11018, 28127, 14785, 124, 16991, 13936, 6077, 22211, 15841, 619, 7559, 25764, 12606, 11588, 24476, 24714, 5374, 20606, 26857, 15475, 17671, 16650, 27606, 4377, 20136, 22257, 16354, 27107, 12942, 20726, 29524, 84, 14059, 408, 832, 8430, 29128, 8141, 21277, 10655, 21609, 20985, 1232, 14491, 24791, 14428, 26676, 12140, 22474, 13018, 11892, 19537, 12263, 21702, 17389, 27620, 4464, 23327, 1062, 23571, 18296, 2893, 23039, 20301, 6956, 29272, 14815, 19505, 10842, 20333, 28890, 2014, 16634, 18623, 26500, 15938, 2635, 28568, 23856, 5979, 16006, 21447, 22880, 5521, 9150, 17980, 21223, 4941, 8892, 3005, 21414, 14579, 25549, 26292, 2527, 23249, 9835, 339, 12553, 29682, 17351, 10326, 7821, 17930, 24107, 28490, 15323, 11092, 11512, 17142, 3181, 5338, 23224, 3646, 5021, 16089, 21373, 7457, 27210, 16205, 3158, 1645, 18625, 16931, 14722, 7425, 25901, 28322, 15347, 29016, 22491, 17736, 20502, 15246, 2064, 1921, 27349, 21329, 26167, 27759, 21959, 21760, 26335, 19740, 24105, 601, 20865, 745, 26457, 19864, 28122, 2037, 19908, 25622, 7057, 6146, 14047, 25191, 5345, 6610, 7248, 20667, 3088, 16991, 19261, 22072, 12578, 25846, 14560, 18185, 20, 13930, 16799, 17900, 20935, 22975, 23658, 25290, 2641, 12768, 17933, 9753, 870, 29727, 20930, 25663, 29122, 16497, 16340, 2496, 5882, 2797, 11889, 20472, 2046, 9421, 15569, 27438, 16431, 12762, 20071, 11828, 20091, 16105, 6967, 976, 23793, 20140, 26069, 4931, 16228, 15449, 27011, 19679, 10606, 24579, 12767, 10562, 9603, 10517, 17120, 14029, 5204, 27990, 21932, 26864, 27547, 12358, 26749, 12375, 12128, 28402, 16445, 19579, 22045, 22465, 29433, 12144, 10286, 27324, 25791, 15169, 21093, 20304, 23816, 9095, 3846, 24747, 16341, 11415, 5149, 13084, 9502, 13710, 2584, 3992, 7702, 28415, 29877, 29603, 18128, 12840, 18161, 5398, 25114, 18622, 16637, 19922, 26272, 19907, 2108, 12820, 10611, 21079, 29115, 29407, 24654, 19939, 29869, 14681, 9312, 26905, 22362, 18106, 17558, 3892, 13200, 653, 1649, 15741, 26005, 4864, 24659, 3972, 18095, 17207, 27317, 11157, 21942, 8195, 6115, 22964, 16762, 20521, 26912, 11871, 644, 28895, 17219, 4504, 24975, 12133, 23449, 12230, 9430, 27448, 21188, 5636, 22376, 1586, 14593, 21313, 11426, 5029, 11335, 21354, 14580, 18405, 6150, 14731, 16181, 4931, 27000, 12203, 18436, 5028, 12316, 13476, 4127, 27973, 17688, 17827, 4756, 11019, 27880, 26938, 20201, 16472, 29091, 9995, 11091, 27418, 2542, 422, 16851, 2578, 13772, 8790, 22940, 25057, 12708, 29918, 9140, 12176, 26291, 22073, 27445, 506, 12378, 4095, 28249, 21702, 26752, 21811, 24290, 10175, 5523, 13447, 2102, 23766, 19159, 9089, 29307, 14894, 29212, 24484, 16623, 6895, 16131, 10753, 9924, 23992, 22730, 25968, 19640, 27341, 1418, 22187, 24054, 15332, 12769, 9173, 27676, 17856, 8139, 6050, 29328, 26194, 14630, 13654, 27287, 7833, 9024, 18010, 20557, 9560, 28011, 9803, 3487, 1168, 5201, 6483, 19792, 16560, 23114, 11250, 9479, 24881, 17578, 13253, 2261, 17343, 5931, 19569, 1944, 15878, 28604, 2817, 20040, 22767, 22847, 19316, 21183, 11812, 28358, 23809, 29650, 18002, 1095, 3173, 13116, 13855, 22268, 24739, 22344, 22508, 9574, 13931, 27578, 13918, 8527, 20823, 6519, 13949, 322, 1420, 20189, 12634, 3090, 27831, 29733, 2658, 29029, 28597, 8847, 21753, 6645, 22218, 7436, 25628, 20833, 3015, 4839, 6338, 27073, 7716, 28699, 10060, 21965, 28569, 27474, 3485, 16608, 28935, 26800, 16611, 16425, 22584, 12609, 3836, 1285, 930, 861, 19387, 19625, 19584, 25437, 17719, 17991, 29661, 9256, 16747, 8472, 17098, 23066, 9480, 2417, 14469, 5927, 21817, 28913, 17547, 6223, 6119, 7988, 2124, 24806, 25133, 16927, 22534, 18634, 4356, 23220, 10138, 7002, 20908, 19856, 2347, 19869, 17799, 24156, 15499, 29273, 3816, 16256, 11155, 24604, 2974, 6482, 26778, 14933, 26573, 8199, 17867, 8630, 21467, 6928, 1359, 14950, 4309, 12882, 10423, 22833, 24519, 28053, 2181, 26163, 21611, 14536, 24782, 3326, 11584, 1177, 10038, 37, 22443, 26567, 2876, 19419, 24966, 20585, 283, 9641, 5960, 2174, 17812, 9334, 22855, 8432, 16012, 12501, 19851, 10380, 25406, 22200, 1378, 5687, 22277, 29504, 29891, 29536, 10209, 27131, 8815, 14926, 19012, 26940, 19531, 17303, 25354, 26229, 266, 16396, 29654, 5088, 25416, 16388, 11477, 20102, 24566, 1837, 19631, 12207, 17130, 22108, 22396, 15984, 4518, 25423, 9864, 2244, 21195, 1807, 23598, 9925, 18298, 10159, 23106, 12233, 18466, 21147, 9079, 19124, 845, 29351, 26131, 3010, 8049, 23949, 11242, 16306, 7259, 2874, 20142, 5396, 24881, 29045, 20645, 13816, 2656, 29931, 19062, 23544, 13961, 14589, 6221, 581, 7719, 6083, 3347, 26535, 6459, 17378, 15792, 22435, 1671, 26581, 11078, 1896, 6144, 4112, 25974, 24055, 9549, 28699, 2070, 23613, 343, 10628, 9913, 5662, 28958, 7819, 3750, 6288, 3828, 700, 11351, 6634, 17497, 15290, 9567, 10824, 16267, 25917, 17896, 24059, 24095, 18202, 23276, 22274, 2317, 15185, 28825, 6997, 7823, 1016, 14876, 22318, 11795, 9331, 11590, 15473, 7728, 5116, 20447, 13695, 8057, 19446, 29242, 27452, 16253, 5287, 15484, 17838, 3109, 12492, 8822, 19971, 7925, 20244, 9771, 27665, 4881, 25544, 27744, 17791, 19472, 27131, 23854, 19980, 11534, 22543, 16370, 13519, 8105, 28729, 12880, 6782, 3287, 15084, 9498, 14566, 2813, 2963, 8611, 25753, 21176, 28712, 14850, 11487, 22093, 10319, 11157, 13435, 1179, 16550, 6520, 5713, 19660, 17869, 5052, 5935, 714, 15776, 27842, 9880, 13064, 9191, 16979, 20390, 25025, 28995, 2337, 6011, 24850, 14057, 17477, 6458, 8940, 783, 16156, 3192, 27019, 20044, 9187, 16364, 1882, 19798, 19228, 1423, 9655, 25669, 19189, 8399, 17247, 26838, 6293, 15200, 14304, 26983, 11602, 9062, 25992, 17660, 9140, 24224, 17642, 24620, 25455, 6625, 29465, 18337, 17637, 14963, 11935, 27582, 11432, 2899, 18175, 21412, 7126, 424, 12561, 21122, 21477, 14770, 16389, 3536, 19679, 15955, 29907, 11801, 7976, 15300, 15373, 29000, 6640, 29567, 16326, 24254, 27381, 9193, 28575, 24745, 1168, 27125, 747, 28214, 26354, 23775, 21644, 21397, 20521, 2440, 23133, 22696, 15466, 18122, 11597, 25066, 13644, 20865, 21929, 12612, 19816, 12166, 13250, 20148, 23083, 27584, 22095, 12960, 9667, 2142, 17525, 28300, 26693, 16287, 19341, 20129, 11133, 21524, 24489, 27268, 18761, 12074, 25362, 23062, 8684, 4478, 25097, 28798, 2748, 26351, 1875, 14498, 29501, 25293, 15561, 8219, 24490, 13061, 15415, 19680, 1953, 23337, 124, 28795, 1055, 21844, 9234, 29223, 23965, 12601, 18407, 6220, 16609, 29755, 20515, 3263, 9446, 5715, 27992, 8127, 5203, 26903, 7763, 21653, 11727, 2990, 9327, 18881, 16040, 6683, 26557, 10230, 2107, 1088, 25605, 29753, 3402, 5433, 14992, 17425, 8622, 4701, 23678, 24721, 12716, 8482, 2889, 2078, 20347, 6557, 1049, 19143, 15977, 6539, 4552, 11369, 14240, 11617, 24081, 22058, 14642, 9830, 21314, 8376, 1490, 27761, 5877, 26292, 3510, 9658, 25610, 11211, 20521, 14727, 14864, 14140, 15733, 24363, 6918, 6408, 5372, 11449, 7387, 27225, 28465, 343, 21145, 13639, 6495, 17898, 14078, 29981, 28666, 19347, 131, 15604, 16230, 25358, 14379, 28505, 21304, 672, 2745, 19114, 11892, 14093, 12046, 2789, 5195, 1211, 14072, 3137, 24566, 28197, 14310, 27947, 18496, 17174, 24345, 19235, 16653, 4469, 14022, 15654, 4832, 15380, 29476, 5321, 10868, 9148, 16225, 22296, 5634, 15015, 22683, 25039, 9158, 7053, 6383, 28454, 22192, 17805, 5431, 1703, 11798, 28292, 17453, 1767, 8812, 27220, 6332, 5729, 11882, 19410, 25678, 27166, 9701, 25011, 20998, 11432, 6994, 10694, 3845, 11262, 16366, 23208, 24861, 6180, 3645, 7743, 1103, 17502, 11741, 3650, 25953, 13165, 9354, 19472, 14155, 21452, 24103, 19958, 9144, 14235, 24116, 23964, 14307, 23482, 5619, 6607, 27750, 29700, 25052, 4637, 19572, 21695, 10075, 11655, 22623, 18720, 2612, 12009, 2639, 3454, 24712, 28589, 24755, 3275, 25025, 4810, 4280, 11070, 29667, 13877, 31, 10270, 27783, 22194, 21664, 21356, 26009, 3113, 9732, 16161, 2759, 24438, 26889, 27056, 26739, 7228, 22522, 20372, 9049, 18484, 25407, 1174, 6277, 26660, 11888, 25167, 8283, 19893, 16798, 23909, 25792, 4930, 8427, 11356, 29998, 24598, 2893, 29107, 21769, 2962, 10556, 12615, 6315, 13691, 21295, 22671, 2124, 9246, 14881, 7254, 25849, 6759, 14190, 17098, 20243, 8154, 11405, 4654, 1978, 15177, 18839, 17295, 19324, 10467, 29411, 76, 6364, 23188, 28710, 3970, 15351, 24472, 12213, 20256, 10874, 1164, 5217, 13465, 14833, 27696, 9894, 7659, 12035, 29907, 12317, 5817, 8963, 28506, 3898, 18593, 18555, 22667, 10339, 12872, 8022, 23257, 29921, 25450, 18282, 20364, 19017, 28870, 7212, 4595, 21912, 27350, 27345, 12967, 25248, 2872, 17861, 3185, 14482, 1330, 25932, 25134, 29754, 26746, 25811, 12993, 17566, 3987, 19606, 28073, 7869, 29162, 907, 3858, 3095, 14073, 9494, 15478, 28841, 3770, 4459, 23456, 23301, 15536, 25802, 16365, 15778, 2384, 14312, 10259, 13105, 16286, 24164, 11794, 29056, 12561, 12894, 6265, 2334, 26658, 6549, 6515, 15350, 1565, 15761, 11187, 20101, 22217, 6049, 10521, 3669, 15665, 4293, 19534, 3443, 11676, 14666, 16991, 22259, 17976, 14585, 28081, 12206, 19396, 29195, 17964, 27035, 10536, 22972, 10132, 26193, 20188, 19125, 4164, 4199, 9036, 28073, 22510, 17121, 9207, 17606, 701, 17227, 3555, 2275, 19327, 3877, 14443, 22578, 29433, 9655, 8388, 22554, 5297, 27073, 13889, 16853, 10441, 5558, 23647, 458, 1040, 9636, 7157, 15982, 17584, 11135, 9850, 22559, 5315, 19079, 4596, 3908, 12746, 16211, 17704, 5219, 23104, 29749, 20237, 8385, 6992, 3123, 10384, 27849, 2502, 25577, 25312, 24437, 21554, 3179, 21416, 16848, 1966, 6248, 18247, 15502, 9108, 8767, 26076, 11161, 8, 4145, 8313, 5611, 12626, 459, 10376, 17818, 28828, 23406, 23262, 25818, 15977, 27107, 7572, 8272, 25632, 786, 6512, 23031, 10643, 9420, 29981, 26953, 28047, 16364, 20457, 414, 1015, 13969, 2534, 20891, 15446, 26357, 15604, 13095, 15238, 6058, 12265, 6286, 374, 13533, 23952, 16512, 2854, 21205, 622, 727, 12870, 20378, 16027, 1052, 17851, 27762, 3315, 8504, 13171, 12828, 8949, 9365, 26713, 21247, 21433, 12896, 25663, 13223, 18247, 1888, 26315, 22706, 22244, 16059, 29795, 16968, 23975, 6723, 9704, 29107, 6798, 11864, 6100, 9729, 1572, 970, 3408, 15023, 1255, 910, 14083, 12911, 4440, 27227, 25128, 12435, 24825, 14446, 9791, 29341, 11325, 15502, 5283, 15725, 20885, 1486, 17913, 26754, 8538, 7105, 25413, 8807, 10103, 28877, 27323, 14116, 4426, 25003, 23663, 7627, 17346, 5263, 12654, 28279, 984, 1059, 3825, 26703, 17190, 28398, 23772, 19822, 7036, 8605, 15717, 8137, 25511, 9328, 8186, 20195, 13614, 7426, 8875, 18153, 21547, 13424, 10660, 22220, 27139, 14767, 13138, 24408, 13167, 22959, 17811, 21038, 7667, 3021, 5354, 2912, 10887, 20438, 29373, 29784, 16574, 17156, 13055, 12112, 2831, 18353, 668, 11735, 5659, 3209, 1401, 11178, 26003, 20574, 19605, 29178, 15339, 7636, 13776, 10219, 6606, 3950, 20560, 27964, 17535, 15867, 510, 26893, 25074, 12556, 10927, 21999, 29699, 26668, 6028, 11715, 4471, 7776, 27622, 2386, 13800, 15376, 15733, 19983, 9771, 16332, 17785, 20852, 21745, 9282, 8360, 11709, 155, 4806, 12633, 26753, 18549, 11391, 826, 28590, 10570, 12033, 25220, 10407, 13782, 8045, 13759, 7243, 988, 9268, 21121, 12534, 24207, 7252, 26588, 16899, 2975, 20938, 22897, 12625, 22071, 23904, 28905, 25569, 337, 2440, 18745, 22097, 27090, 16579, 25586, 10562, 29897, 262, 6696, 21113, 24558, 20624, 9900, 11650, 12025, 16770, 6970, 8393, 1155, 28224, 20461, 19512, 10151, 7639, 13308, 27510, 1835, 24502, 21877, 599, 16202, 26763, 6938, 14177, 13030, 809, 26397, 23341, 9194, 13988, 19717, 8682, 18153, 1172, 7736, 21919, 9036, 4503, 24502, 12488, 28715, 7883, 21027, 29033, 6450, 12558, 5880, 26058, 14290, 17248, 2924, 28920, 21121, 3295, 7128, 20799, 11832, 12125, 16698, 7210, 2257, 10855, 2684, 431, 28339, 1869, 17888, 15385, 22255, 28759, 17620, 13036, 4867, 3727, 8183, 17891, 24271, 9058, 19098, 17569, 4543, 27353, 21291, 15776, 17168, 22464, 21419, 5455, 6812, 18342, 28302, 22768, 2651, 8499, 18159, 5813, 15820, 16482, 7313, 22964, 23286, 27564, 21397, 18186, 22562, 24123, 2282, 11735, 10318, 16706, 360, 21989, 29823, 2907, 18442, 5685, 23481, 19970, 2913, 27151, 27678, 13957, 2168, 18296, 1713, 8253, 19030, 21389, 29341, 14194, 10568, 24280, 13194, 10927, 27406, 23063, 21212, 29495, 16003, 22289, 19721, 16218, 24984, 2320, 453, 22126, 18129, 9668, 27424, 13742, 1409, 15130, 17139, 29, 17259, 24103, 12286, 6254, 11247, 29659, 5683, 29531, 2548, 26762, 20095, 3039, 15850, 25975, 5961, 10487, 2462, 20372, 13525, 14103, 9815, 16889, 4068, 1523, 17215, 29990, 4901, 15525, 20558, 5875, 12007, 5320, 21713, 19974, 27491, 10811, 19462, 10663, 6627, 10573, 20136, 14644, 13613, 1991, 1801, 7954, 4790, 2557, 4532, 5568, 20482, 17577, 608, 18637, 870, 6988, 11861, 4595, 16391, 5104, 6469, 8666, 1549, 6977, 4455, 10269, 24267, 7246, 8669, 4717, 23838, 3461, 23656, 9007, 1270, 16067, 10469, 24550, 19071, 9578, 26407, 17002, 28941, 12674, 20358, 20874, 19701, 12646, 13478, 29616, 22723, 25182, 28837, 14169, 18309, 20673, 18407, 20251, 21015, 18394, 13118, 22304, 2498, 13188, 7327, 4441, 7762, 6034, 2874, 28146, 4852, 26985, 26967, 14279, 28607, 3735, 2489, 17475, 10619, 23919, 16753, 13731, 19459, 28661, 572, 9527, 10334, 17840, 24535, 17706, 7780, 25976, 15118, 29459, 21809, 4602, 2049, 9854, 14234, 16043, 18932, 22365, 26873, 1812, 16732, 10106, 6824, 14443, 19227, 16379, 12848, 25943, 23552, 29788, 1832, 20712, 24057, 434, 6262, 4703, 26137, 23023, 11016, 27922, 2620, 5340, 23284, 10881, 3902, 17794, 23911, 22327, 20235, 17464, 15929, 3502, 13804, 10127, 17580, 11809, 5912, 4775, 16581, 9266, 8879, 9332, 15021, 15482, 27994, 25122, 6137, 3418, 5335, 28436, 26140, 27498, 12881, 14589, 27766, 1833, 25186, 18025, 27139, 10505, 6818, 29845, 6335, 18189, 16426, 25299, 25004, 21554, 23716, 10478, 6938, 12666, 18293, 17813, 8730, 25314, 20509, 26491, 3395, 16218, 8180, 11429, 5971, 28614, 6519, 19509, 18605, 6349, 7765, 23815, 14792, 28772, 9483, 28266, 3345, 23320, 15590, 205, 6873, 7010, 13165, 16870, 1915, 6138, 21016, 8886, 13041, 5816, 11620, 10717, 4070, 959, 4767, 8807, 15981, 4604, 4184, 25172, 674, 22111, 2781, 18773, 20383, 3667, 13987, 28305, 11570, 7448, 14422, 18385, 1, 11486, 10747, 23096, 22114, 15011, 28694, 2401, 16791, 6811, 19882, 12310, 7811, 5075, 6530, 26423, 17373, 14502, 18570, 18815, 10254, 19047, 20174, 3651, 16818, 10649, 1018, 19654, 22167, 9873, 1736, 20468, 9787, 3893, 20330, 11231, 26535, 20799, 17125, 14798, 24008, 18395, 25317, 1167, 16677, 7670, 26585, 6913, 24969, 1945, 25450, 22100, 22276, 8251, 8219, 29912, 4345, 650, 29343, 29971, 5569, 2244, 17334, 26496, 3625, 6433, 26344, 21579, 27504, 21102, 20553, 22550, 883, 28263, 13723, 2514, 10910, 822, 13965, 22041, 16614, 15021, 22305, 11332, 6899, 38, 23254, 22600, 22840, 1173, 27947, 21261, 8126, 19665, 13036, 9042, 18663, 22348, 9963, 18455, 859, 28848, 5834, 27397, 15478, 11485, 15203, 11043, 21942, 4570, 13871, 6039, 18160, 13888, 23491, 10671, 25328, 2683, 28702, 13419, 27878, 6622, 17896, 4302, 3996, 5767, 26001, 16949, 3381, 26144, 10072, 23214, 6163, 20371, 5469, 27142, 17374, 16782, 3648, 15320, 12839, 5999, 14957, 15436, 12745, 4185, 570, 24205, 10431, 16280, 11259, 21212, 10381, 4198, 20882, 19436, 4206, 20407, 884, 7015, 13370, 15140, 28875, 25596, 5051, 14645, 3584, 8104, 6303, 3590, 24375, 9932, 10950, 22052, 9692, 18101, 20167, 11161, 189, 12199, 21748, 27092, 27645, 27260, 17839, 15838, 18048, 13767, 7605, 5822, 1396, 7013, 12990, 10845, 26866, 21525, 9956, 19421, 23995, 22503, 8870, 18114, 15294, 28308, 8556, 26570, 18978, 5735, 2875, 25804, 13060, 28748, 11605, 16138, 12861, 20044, 9537, 6008, 29876, 2077, 7473, 4784, 24995, 4550, 18011, 28308, 11211, 21110, 9742, 1624, 20908, 14556, 24537, 13777, 22452, 5053, 11515, 27711, 7955, 7471, 22172, 5589, 11785, 21148, 26132, 7396, 28167, 13542, 19769, 24422, 18101, 12577, 14419, 27350, 8943, 23400, 13272, 8436, 16585, 17944, 27325, 8191, 20255, 8107, 7795, 4500, 3688, 2643, 17739, 7271, 19631, 13253, 24793, 22478, 13521, 27245, 15395, 1651, 15264, 2244, 29691, 11963, 14905, 9339, 1054, 3719, 15069, 17194, 8354, 17380, 9757, 12397, 3543, 28477, 14170, 10024, 13227, 26228, 17863, 810, 12888, 26614, 20402, 20003, 18661, 28336, 29476, 14516, 17231, 213, 23134, 27328, 16107, 6582, 8049, 12428, 16417, 12299, 29481, 6817, 22077, 27850, 19483, 10127, 25262, 3841, 18086, 29047, 2805, 15212, 24471, 12532, 14560, 20722, 23500, 2373, 28649, 9400, 52, 10035, 28366, 7129, 20112, 2028, 19202, 7902, 5239, 11194, 28576, 20905, 18830, 14218, 9300, 9564, 2588, 404, 12267, 25430, 8582, 7533, 20417, 22831, 5266, 17528, 23074, 26050, 13019, 18976, 25240, 4087, 15376, 49, 17002, 5581, 28432, 16121, 21056, 18084, 26966, 21709, 14162, 29776, 10573, 6399, 14669, 7673, 28047, 7203, 14887, 656, 21298, 29302, 4415, 5581, 8061, 939, 3624, 4841, 8137, 8570, 13319, 19038, 25168, 3988, 2606, 25304, 9131, 23817, 13346, 3015, 10781, 16757, 495, 16841, 5654, 4832, 17691, 13193, 11434, 25701, 19187, 15549, 22225, 8420, 5912, 8605, 5004, 28010, 18363, 16774, 13026, 8948, 12610, 15402, 2316, 11360, 27515, 8458, 24843, 27090, 26243, 18952, 7455, 20433, 5306, 25151, 26160, 25832, 429, 1973, 27238, 16256, 11300, 3917, 19943, 48, 698, 4281, 3743, 28692, 22258, 1734, 14, 25402, 23959, 20717, 1765, 28550, 16033, 24388, 5823, 28031, 29650, 15582, 9170, 21926, 8695, 26253, 15674, 23777, 6223, 24756, 29672, 28805, 17012, 13206, 26305, 12478, 23869, 25208, 13101, 24459, 22009, 22112, 4473, 7325, 18134, 13821, 12600, 24712, 10849, 151, 25857, 5229, 5556, 8958, 2837, 13757, 23310, 21128, 2820, 26943, 12097, 24484, 24090, 23785, 17, 464, 25015, 8208, 1282, 14954, 28333, 298, 13814, 23258, 11546, 7335, 22675, 4539, 19112, 8311, 5389, 29722, 21633, 18332, 15162, 7786, 17973, 6500, 27335, 6683, 26430, 1, 10976, 19125, 25068, 240, 26177, 4177, 9034, 21477, 10833, 23435, 23432, 12107, 4885, 10088, 21024, 16162, 23914, 21135, 26454, 6493, 12578, 9775, 24163, 4495, 24453, 5252, 8692, 18005, 13433, 6751, 8090, 18101, 25345, 16949, 9316, 13521, 8844, 18635, 9809, 23059, 20487, 20079, 24737, 2243, 1203, 10249, 12026, 11236, 2219, 14000, 25646, 1829, 868, 29497, 29348, 29542, 5656, 790, 15430, 11204, 11353, 10201, 28328, 26561, 10725, 15643, 8345, 13856, 8785, 8411, 13900, 19857, 17088, 29196, 24658, 11820, 2793, 11624, 18123, 7416, 8014, 24709, 19894, 14386, 23454, 5527, 28520, 13425, 25930, 1377, 7786, 27506, 17284, 19049, 3112, 2645, 8650, 17425, 17585, 27848, 15180, 29690, 27415, 12034, 25530, 13385, 4842, 7083, 21204, 12869, 15899, 13802, 17304, 25558, 15015, 18166, 9855, 20688, 20611, 25250, 5736, 1934, 15018, 10732, 28943, 3062, 23436, 28709, 28847, 20150, 22048, 20765, 11321, 20631, 25252, 14828, 1348, 11313, 12267, 1651, 12549, 5163, 8738, 3161, 24371, 1607, 14906, 7122, 6264, 1126, 18690, 29600, 3014, 21296, 18984, 16573, 15958, 10693, 26960, 3218, 21445, 23981, 8788, 13507, 14544, 28032, 16529, 29963, 27392, 18718, 24304, 13287, 5847, 3555, 16134, 15119, 12098, 17768, 15420, 2939, 25334, 21553, 7282, 18405, 1790, 27354, 18191, 13142, 7164, 16701, 4793, 29367, 12192, 20169, 11403, 26523, 11036, 12879, 3545, 23255, 24080, 17861, 7805, 18059, 24044, 10542, 15284, 25865, 20769, 10530, 29352, 1409, 26882, 8057, 12054, 28523, 10949, 2215, 2791, 27142, 9267, 10579, 25220, 20107, 18319, 18002, 2037, 3399, 21321, 29956, 12994, 7866, 18166, 23034, 10417, 12676, 17315, 26207, 15060, 20416, 4160, 13706, 21381, 26462, 22188, 19299, 5097, 11788, 2998, 7454, 27107, 19369, 19335, 16205, 13603, 14611, 11894, 25980, 16730, 17894, 21975, 29467, 22037, 9819, 20636, 20974, 12557, 13349, 10817, 21826, 12471, 9702, 9603, 28551, 14865, 29438, 18027, 7986, 10326, 18823, 21139, 24166, 23910, 18453, 4147, 6352, 14755, 606, 10528, 9888, 19421, 13761, 8515, 1362, 5082, 7574, 24215, 23738, 543, 13257, 25199, 24194, 14091, 13705, 20520, 19671, 21374, 27282, 20837, 16922, 2379, 22832, 10810, 25192, 17983, 16811, 28296, 24083, 10990, 20227, 28439, 12301, 20861, 9441, 3574, 8489, 2982, 6959, 1416, 3872, 5630, 1834, 11056, 28687, 16417, 21735, 23974, 17316, 25024, 53, 1478, 27252, 29961, 6696, 16976, 11051, 5193, 25842, 9837, 11586, 5586, 3447, 6303, 17986, 10399, 5386, 12521, 10390, 17148, 8018, 9954, 3217, 5882, 6603, 7230, 4168, 14189, 26548, 16675, 19587, 5245, 12346, 28191, 29045, 13780, 29412, 23277, 26395, 11912, 23896, 19899, 13661, 10658, 27352, 4013, 5151, 13573, 5864, 14636, 2114, 14912, 15944, 21001, 23619, 26237, 24941, 9384, 8005, 26226, 2488, 7683, 24843, 8161, 8373, 16074, 6191, 28533, 3336, 24370, 22815, 28865, 18581, 23014, 1740, 27313, 6894, 21546, 27718, 8551, 4426, 25314, 4658, 13067, 20240, 26146, 13506, 27321, 6058, 8988, 795, 15274, 24474, 19336, 15416, 25299, 18452, 15413, 20658, 28968, 19953, 21600, 7012, 795, 26658, 22880, 21771, 20703, 18029, 12579, 27861, 24873, 19298, 18830, 19227, 19907, 10985, 19965, 4193, 17244, 2908, 10124, 1733, 6647, 29168, 29911, 1904, 4263, 26284, 28986, 23610, 11530, 2704, 3629, 13906, 2532, 8312, 27334, 20646, 26309, 23942, 19250, 3478, 25568, 14104, 17508, 15563, 9061, 15065, 23479, 10317, 15856, 27352, 26035, 22958, 16542, 18878, 20622, 6570, 21214, 4775, 12031, 29589, 19453, 19651, 21285, 26510, 1778, 11132, 29717, 10010, 24353, 25899, 5828, 26377, 11336, 23556, 6893, 7314, 3347, 15536, 27690, 10402, 24346, 21284, 29145, 8477, 15659, 23179, 455, 28132, 14927, 27097, 14553, 7554, 3411, 7184, 744, 1860, 7578, 29815, 1818, 20937, 9139, 10989, 17696, 12122, 18977, 15570, 24163, 26775, 5460, 17635, 661, 27945, 10601, 2867, 24621, 6763, 29433, 5277, 2521, 19896, 10812, 7517, 24273, 26334, 16810, 10356, 23778, 21692, 1618, 15964, 21183, 23744, 7708, 14714, 27591, 11676, 16146, 2029, 8135, 25253, 20812, 17660, 16289, 1914, 4143, 2476, 29856, 16076, 16991, 7328, 24220, 3961, 9788, 22047, 2406, 2747, 17203, 4896, 25881, 9629, 28774, 8286, 15166, 28615, 24538, 995, 12196, 15728, 9054, 2836, 4733, 25275, 15779, 7688, 8946, 27528, 627, 11044, 9947, 22924, 27407, 5290, 27052, 9317, 25768, 23054, 2341, 25325, 26456, 23344, 3680, 28573, 25609, 7184, 12513, 16609, 19269, 2479, 10534, 27111, 11702, 10152, 15847, 16136, 8403, 3434, 9569, 27438, 22532, 4076, 3547, 465, 2279, 5504, 29230, 22658, 4966, 3482, 4483, 14471, 8495, 10421, 7267, 161, 4566, 28788, 25715, 15845, 24432, 23336, 21068, 18187, 16227, 25672, 5923, 3740, 9900, 25614, 2093, 12765, 8622, 25598, 28654, 18712, 7759, 22898, 15174, 21734, 15197, 9588, 9027, 11459, 18977, 15378, 2061, 16810, 11281, 3497, 19863, 24037, 14225, 10281, 12910, 3239, 13548, 19630, 24846, 422, 21755, 3147, 2602, 6893, 22487, 19269, 9380, 8107, 2921, 11436, 15034, 13885, 28790, 17405, 25537, 6685, 11212, 20065, 12436, 22106, 20354, 12068, 21536, 1392, 26579, 29470, 413, 29423, 25088, 11931, 15439, 21009, 12836, 12879, 20464, 22849, 25957, 7334, 28176, 20633, 6756, 7656, 25902, 27252, 20191, 19053, 1347, 3594, 23379, 9369, 20065, 4553, 11831, 29032, 19068, 4410, 5771, 20318, 14117, 14740, 3795, 14860, 29896, 19433, 19353, 793, 3785, 10029, 19284, 10808, 28434, 11772, 22347, 7011, 16037, 17990, 4786, 19506, 24907, 22064, 21797, 20503, 18457, 15795, 23068, 18274, 21598, 21782, 7911, 27891, 765, 7396, 27560, 19516, 17299, 20080, 7426, 24905, 5247, 9229, 26823, 28843, 18253, 12771, 412, 19424, 13931, 19306, 5332, 7458, 3503, 13805, 7528, 180, 20649, 25408, 17472, 16414, 20433, 22159, 29420, 10315, 5613, 7747, 8759, 11332, 7121, 15605, 12967, 8969, 14205, 29832, 10366, 3380, 23616, 14447, 21861, 1854, 14599, 12235, 11004, 27417, 26202, 3757, 21498, 27202, 21633, 23448, 20222, 1691, 28352, 29314, 19562, 11737, 23201, 941, 21902, 10718, 75, 25138, 19625, 26363, 22213, 28656, 25736, 524, 245, 16748, 20425, 15123, 12394, 28530, 6691, 12805, 27813, 14898, 4425, 19346, 15040, 27793, 21421, 11396, 24468, 16136, 25612, 19482, 21880, 26647, 919, 27000, 23580, 12174, 19446, 11935, 3607, 18637, 26246, 22231, 9425, 23052, 29729, 12729, 16086, 12132, 1267, 17277, 2423, 26656, 3345, 8304, 23075, 21565, 13799, 9780, 5805, 14387, 10478, 20876, 27458, 27781, 3090, 22606, 17106, 258, 28187, 7724, 5191, 23195, 10143, 22261, 21953, 17060, 13353, 9308, 12982, 18479, 12481, 12195, 12909, 23295, 21857, 16188, 26246, 21648, 22275, 8209, 21894, 11458, 28900, 312, 21076, 12805, 1080, 15548, 6584, 7087, 3334, 5384, 2973, 22797, 17328, 8585, 23209, 18099, 8679, 12960, 13312, 17003, 11593, 2293, 1976, 7342, 12806, 10144, 159, 11016, 17152, 801, 17185, 2229, 16118, 18921, 5334, 9137, 2476, 1819, 21036, 7558, 28726, 22832, 23714, 14507, 10586, 26153, 16242, 21989, 29055, 289, 21925, 17961, 27207, 15700, 4624, 13676, 28821, 21580, 20060, 24971, 16894, 8143, 18573, 14058, 5300, 1939, 410, 28154, 5511, 14923, 5736, 6285, 28892, 18296, 7485, 15938, 26244, 28040, 10752, 2891, 14390, 19371, 3622, 178, 8158, 11129, 20911, 7539, 12992, 20799, 9871, 22274, 6264, 16913, 19385, 3358, 2788, 8386, 11025, 3648, 6310, 24837, 1025, 21423, 28015, 17908, 5437, 25738, 16939, 20095, 16029, 28791, 11215, 1592, 10995, 26392, 24513, 8357, 3915, 24627, 4860, 4654, 7049, 8749, 905, 21894, 17375, 21568, 13611, 7973, 22491, 12700, 15464, 15366, 18447, 3164, 20183, 19963, 5074, 19066, 26644, 23307, 2051, 24500, 21623, 21272, 14575, 28195, 9515, 26815, 24518, 20835, 6625, 10897, 2721, 25063, 28478, 10014, 9635, 29983, 5700, 7936, 18196, 15581, 10898, 21135, 19171, 13570, 25075, 21788, 16612, 27349, 13532, 7665, 9562, 2672, 16521, 10928, 28812, 9082, 11798, 1684, 22195, 16728, 24014, 26920, 15393, 566, 27047, 29257, 9941, 3011, 1721, 28917, 10066, 8642, 5914, 12080, 27551, 14513, 25445, 7890, 8361, 1358, 19387, 28646, 18596, 7465, 10171, 20, 7726, 27781, 21847, 15512, 23243, 26823, 6820, 10797, 25754, 19581, 7875, 8309, 3789, 1631, 17062, 18930, 25607, 1897, 18280, 4227, 14397, 29469, 27943, 22522, 12956, 17054, 12342, 8926, 20771, 21696, 8047, 13710, 585, 28509, 29250, 11049, 23687, 16572, 3704, 26091, 12020, 240, 22753, 26720, 18624, 11106, 27724, 1725, 6681, 5084, 19645, 25942, 20167, 24181, 25631, 24524, 28850, 26493, 17150, 11520, 23714, 14732, 5158, 3450, 19669, 7155, 2602, 3724, 12005, 16411, 6090, 21015, 26619, 11363, 14404, 1325, 9735, 25663, 8107, 12803, 11893, 9598, 26459, 3759, 24834, 21985, 13277, 6876, 12941, 6735, 1243, 16899, 25724, 17178, 21207, 3582, 21123, 8000, 28554, 27968, 9612, 22818, 3812, 29369, 9967, 18858, 3101, 17224, 2512, 15490, 16725, 3891, 14269, 17456, 19967, 7091, 24629, 10988, 7787, 27597, 28210, 21933, 25683, 14168, 4028, 13771, 14036, 18888, 16365, 12857, 23060, 25045, 24909, 7890, 3240, 24283, 17372, 17392, 8328, 28259, 29870, 16188, 17511, 3423, 24392, 13174, 7189, 22523, 327, 24468, 12812, 17254, 7812, 6666, 1606, 10272, 13043, 11766, 18685, 15747, 24140, 324, 28337, 19095, 26861, 26967, 1958, 9807, 17563, 6731, 28679, 9000, 16950, 9395, 794, 1618, 13764, 15741, 4672, 4351, 15458, 4881, 13493, 662, 15872, 18483, 29787, 1522, 17211, 1011, 19994, 16040, 6558, 3149, 1870, 10617, 11487, 13473, 29473, 12507, 12496, 22034, 808, 2389, 17622, 13397, 23157, 6830, 22844, 3631, 18997, 2395, 6493, 1324, 4379, 7863, 8276, 2697, 2175, 3765, 25634, 1286, 21616, 26790, 25900, 20695, 23260, 4738, 19765, 1493, 29535, 17007, 4106, 10449, 6380, 1638, 7708, 7101, 23210, 16758, 23196, 29894, 8981, 15550, 14014, 2095, 23075, 8695, 3480, 1360, 18937, 25583, 7919, 28642, 29909, 2582, 13350, 17103, 14105, 8766, 16060, 24159, 5310, 7741, 11138, 28086, 26204, 23468, 29170, 18306, 23823, 17391, 8282, 2533, 20930, 12525, 7882, 26690, 172, 19143, 11809, 8521, 753, 3859, 28274, 21590, 26242, 17587, 28005, 6265, 11280, 1892, 13015, 27677, 5247, 15091, 14443, 24822, 4704, 25774, 9038, 29236, 20988, 8000, 1463, 24506, 22010, 5000, 24927, 13116, 2333, 9590, 13049, 6180, 13280, 29763, 17350, 19255, 8885, 24418, 26136, 21569, 2298, 10646, 14413, 20766, 20107, 1218, 3221, 883, 551, 5953, 26174, 26936, 7670, 19701, 23518, 14111, 18380, 14671, 27486, 29801, 27801, 21735, 24892, 25227, 9343, 3876, 1731, 13014, 25877, 9151, 29327, 15149, 5874, 22938, 5056, 10358, 3290, 23836, 10446, 4896, 23630, 26051, 19442, 29088, 27380, 24116, 8856, 3715, 6256, 13435, 11378, 17957, 8748, 6551, 25333, 16041, 11213, 9429, 27504, 8308, 3197, 2824, 25344, 11603, 18632, 14, 15191, 17854, 15186, 7576, 502, 24305, 26856, 19298, 10849, 26427, 25927, 26223, 27546, 566, 2716, 2837, 27925, 6095, 9648, 11244, 26228, 8156, 18044, 1155, 21697, 17811, 11417, 6448, 28237, 20162, 16423, 12430, 12234, 17433, 6905, 18769, 3891, 5070, 8087, 17560, 9319, 6885, 29740, 22597, 10328, 6362, 4884, 9737, 22135, 12581, 3305, 9948, 4405, 24013, 12250, 28592, 27727, 20962, 172, 10618, 25603, 16856, 23745, 28714, 21393, 458, 27293, 29342, 4578, 19419, 12626, 12992, 1872, 3147, 20877, 26373, 7725, 2131, 20127, 25226, 20581, 27800, 25049, 3510, 17240, 1326, 22954, 10499, 4793, 27666, 26488, 8141, 21930, 8819, 2675, 12822, 7306, 15968, 1090, 19973, 6280, 2648, 12295, 7122, 26094, 14404, 2336, 19706, 23928, 29635, 13349, 22991, 4878, 29774, 14217, 21314, 14272, 29113, 21713, 16837, 25952, 2345, 23046, 27473, 22504, 27336, 20248, 11944, 10557, 25958, 7770, 295, 2100, 23036, 18963, 1098, 735, 10032, 281, 5550, 24722, 5146, 5429, 28337, 17881, 28664, 24491, 9078, 14184, 1552, 15119, 27754, 1270, 24936, 11895, 1875, 24030, 17, 9911, 24291, 1314, 12476, 14725, 27217, 10245, 14625, 29697, 2760, 24252, 3794, 26168, 23779, 9018, 11483, 4619, 4205, 25923, 7524, 22173, 1011, 9642, 17660, 19298, 17467, 17676, 11002, 18487, 23286, 9302, 6042, 24780, 27841, 10846, 15920, 781, 14650, 8223, 29032, 13543, 15959, 9059, 1600, 9249, 22198, 28886, 2566, 28097, 5757, 1547, 17080, 6410, 22931, 28287, 12465, 20498, 5696, 6093, 18803, 27871, 3101, 13860, 9523, 21004, 15949, 7266, 2316, 5234, 996, 8577, 5037, 4051, 9950, 21967, 29720, 17800, 29425, 14314, 1038, 12530, 3700, 19062, 21410, 16184, 13210, 9294, 24200, 20236, 17828, 25104, 11457, 25326, 12468, 9828, 21343, 24349, 1128, 3436, 29908, 8072, 15989, 21822, 14642, 26692, 4514, 17362, 12447, 14172, 16057, 13054, 8624, 19232, 15522, 10255, 4344, 22704, 10409, 4474, 11218, 24810, 17747, 16353, 20904, 7094, 1616, 15188, 10838, 2598, 19819, 22882, 25220, 10053, 25897, 13324, 3211, 81, 24821, 9850, 8124, 13758, 27544, 4183, 1315, 29795, 27466, 3090, 22499, 6238, 4903, 22208, 16029, 23233, 25929, 29318, 10202, 27526, 18306, 6778, 21339, 19634, 18475, 21260, 22752, 18840, 12834, 20933, 29885, 21619, 24188, 1133, 17433, 22150, 28020, 4564, 170, 3757, 17695, 5232, 683, 17481, 6845, 22961, 25019, 18597, 20304, 27595, 11627, 12149, 15921, 14219, 7124, 20024, 29087, 4925, 1456, 24660, 4526, 23353, 9994, 2589, 17063, 588, 21549, 10964, 7071, 4294, 8581, 20460, 14318, 18302, 9976, 3169, 21334, 15480, 29935, 14461, 5464, 26342, 8427, 22620, 29235, 24259, 3355, 12975, 27040, 13333, 16076, 23485, 22041, 18531, 6978, 10944, 12877, 6867, 14041, 18069, 5476, 3813, 25831, 27026, 26117, 23220, 17851, 22499, 23369, 27679, 17091, 15839, 27812, 27699, 26837, 9436, 16595, 3849, 28889, 26915, 18862, 22418, 7176, 13403, 19108, 25314, 26937, 1164, 9875, 18141, 15223, 2489, 24497, 16883, 21943, 16837, 22630, 2977, 9976, 18479, 10358, 1194, 19416, 13267, 26909, 2440, 24957, 5965, 21814, 10045, 25478, 11665, 14098, 23393, 7751, 1272, 2813, 1406, 3259, 11699, 14006, 25499, 9891, 15786, 18323, 12487, 14721, 10594, 27946, 23306, 24976, 9806, 23717, 9915, 13136, 14370, 21384, 6273, 1965, 20470, 16618, 13397, 17777, 12279, 14090, 12102, 13793, 12359, 2125, 15962, 101, 16780, 28227, 1973, 13709, 10301, 28693, 27552, 27383, 4835, 10900, 12464, 11984, 4040, 10614, 17479, 9797, 28760, 4212, 26456, 18722, 9027, 12617, 14471, 16995, 6348, 26907, 12251, 15102, 11520, 29361, 11609, 9922, 9333, 23132, 26011, 20589, 13024, 10539, 5473, 20779, 18534, 18755, 24593, 18423, 13399, 15564, 8875, 6273, 28520, 27498, 28478, 20509, 997, 17983, 13859, 21810, 15814, 23840, 11529, 7133, 28411, 15956, 24398, 11713, 10776, 3974, 8623, 2039, 9305, 5090, 24620, 2863, 24952, 15795, 15337, 8008, 14408, 26746, 7462, 6634, 24469, 3506, 188, 12843, 1825, 14779, 2596, 28463, 15913, 1976, 11232, 1123, 10798, 17764, 17167, 23141, 14481, 28001, 13958, 19823, 18741, 29501, 26027, 19699, 22492, 2499, 12415, 17230, 11453, 18924, 14697, 24912, 10108, 5314, 2848, 13159, 18119, 11915, 766, 4763, 19436, 1007, 24792, 27405, 4203, 1608, 13286, 18759, 17027, 14513, 19848, 9214, 23006, 23597, 3160, 27199, 8003, 16081, 26022, 16694, 22404, 27087, 6811, 26061, 19907, 18482, 11205, 2215, 18248, 24756, 3825, 4298, 28213, 23831, 17488, 28103, 8432, 22125, 3353, 17480, 569, 23664, 9735, 26967, 13206, 10169, 14169, 25231, 21558, 7899, 6544, 5109, 28258, 16054, 10726, 11811, 9856, 17814, 6291, 18972, 15211, 25592, 29450, 16086, 16735, 26117, 20296, 18808, 20513, 14899, 14020, 25582, 6718, 24059, 2685, 12151, 3349, 25142, 29540, 3446, 20056, 7867, 14719, 591, 10434, 13224, 24216, 16542, 3574, 20797, 13809, 15737, 13541, 7025, 9340, 2114, 16759, 29146, 1814, 10074, 8048, 27388, 7255, 7250, 20148, 4682, 19730, 3345, 14716, 24182, 20039, 2740, 5675, 15956, 18181, 12895, 22434, 11050, 2937, 25954, 17031, 16824, 22824, 14715, 17621, 21421, 11822, 10438, 26652, 10490, 13648, 16759, 1302, 17212, 29258, 13560, 23283, 24412, 1653, 25190, 16324, 9757, 5186, 10201, 271, 14247, 4027, 8576, 13785, 26817, 12435, 9344, 12093, 15871, 19116, 18119, 795, 14832, 25793, 5273, 25280, 11383, 13298, 23049, 3026, 28922, 1139, 29225, 27030, 25162, 9559, 15999, 29192, 16910, 9980, 17193, 26520, 9014, 27625, 12908, 29182, 9339, 23351, 9603, 8487, 6502, 21220, 14837, 8864, 10738, 2842, 19718, 16075, 15385, 4963, 5178, 21382, 18276, 27084, 28828, 21119, 28022, 26873, 24077, 18815, 16275, 28451, 14259, 27742, 10079, 22497, 343, 9905, 20805, 2065, 3918, 28969, 25741, 3399, 14876, 22447, 853, 28044, 23420, 6622, 4049, 13675, 11399, 24408, 11232, 1469, 1906, 25029, 17718, 20418, 26981, 25238, 27915, 1233, 27098, 18715, 12064, 26926, 1912, 11881, 14616, 12249, 13175, 16404, 12171, 7470, 20146, 26335, 22210, 23582, 12999, 5052, 6785, 29240, 22097, 28194, 6470, 23713, 7172, 27079, 16286, 11747, 7018, 17483, 11477, 17545, 14031, 7053, 8674, 15515, 24739, 25954, 26679, 27808, 15570, 23516, 29609, 2265, 24389, 2964, 13690, 12608, 1398, 4362, 16210, 7407, 25159, 10936, 29605, 24439, 16306, 23923, 28775, 26779, 12778, 14286, 22734, 18803, 22234, 3183, 1327, 16942, 10929, 15294, 5320, 12331, 19810, 8737, 2529, 16542, 17088, 13319, 9713, 18837, 8897, 11947, 26174, 16414, 8396, 25406, 13778, 9899, 18555, 10067, 976, 19283, 7460, 14179, 18360, 9005, 8389, 24250, 25273, 11974, 3038, 9005, 1856, 3233, 24593, 3665, 21069, 13745, 2203, 439, 11950, 10469, 2460, 3919, 21933, 23446, 29240, 14323, 21166, 27982, 26665, 26932, 7422, 13258, 25718, 15478, 4084, 25746, 7365, 21103, 9452, 27531, 12476, 17723, 17279, 22863, 13074, 4554, 16981, 7880, 22047, 6725, 24352, 9525, 12392, 21655, 4710, 14275, 19939, 20177, 25811, 18537, 17035, 20806, 23157, 11527, 13128, 7896, 20013, 11348, 17645, 7657, 19257, 8927, 17152, 25472, 18640, 17084, 3804, 12895, 11937, 24990, 12277, 29192, 5213, 29305, 6257, 10871, 21045, 14889, 24916, 2582, 24676, 957, 27137, 6628, 3834, 13052, 2079, 22715, 6422, 28575, 6453, 18567, 21496, 17451, 12156, 26450, 26533, 15943, 19005, 4619, 19393, 11956, 21929, 13780, 4852, 24360, 20451, 27578, 29658, 10757, 21564, 11824, 8761, 18238, 28884, 28736, 6557, 557, 19674, 25820, 20966, 2649, 23781, 25389, 13503, 12275, 6449, 20012, 5507, 2212, 16631, 19884, 19020, 16039, 5622, 13381, 7880, 3871, 22471, 10616, 16741, 20785, 359, 11893, 1673, 20363, 16795, 20576, 8752, 27725, 26353, 444, 26170, 12380, 8505, 22561, 18669, 27259, 12034, 6964, 5546, 24066, 16610, 14752, 7757, 15337, 11803, 19841, 7725, 15916, 21570, 9578, 13368, 18957, 22691, 29805, 11958, 6874, 26889, 10399, 9099, 9560, 4304, 29856, 29592, 3803, 4205, 24365, 8337, 29789, 11502, 13489, 9874, 24558, 28903, 25061, 5390, 19740, 9359, 28036, 17855, 9483, 25340, 27365, 11562, 14405, 7346, 18071, 14412, 5840, 20346, 11945, 27282, 4668, 14480, 5023, 7746, 18857, 7786, 14421, 11595, 48, 25990, 8351, 20119, 17184, 4307, 25341, 9394, 15373, 4626, 21291, 27857, 4619, 3406, 17876, 914, 21060, 9502, 25006, 28416, 24178, 26111, 4301, 1956, 27454, 1642, 3331, 25407, 14272, 7805, 28416, 836, 4031, 5751, 8814, 21157, 21891, 12303, 2467, 26999, 29195, 13795, 25785, 19567, 16170, 6661, 15307, 7273, 22556, 13746, 10131, 15599, 29958, 16760, 23027, 5743, 16993, 1922, 9554, 3168, 19702, 9385, 9707, 3196, 16170, 27667, 11537, 26924, 9744, 14412, 18065, 18082, 13651, 6532, 7140, 8353, 3627, 11173, 28921, 8106, 519, 13990, 8074, 1239, 1128, 17136, 11995, 11323, 20318, 29962, 27809, 1773, 25765, 25955, 28123, 7523, 29339, 12348, 283, 1490, 12282, 8085, 3407, 26304, 2637, 22946, 29461, 29801, 17133, 8181, 13811, 17883, 19634, 24486, 13143, 26492, 18085, 3830, 5596, 26402, 22453, 17019, 2254, 13782, 12957, 8667, 4297, 20135, 5579, 12316, 1872, 23659, 24076, 15091, 19454, 7163, 26426, 3863, 24769, 22817, 17419, 3932, 25692, 25947, 20318, 5779, 28293, 27035, 14394, 15917, 1391, 7813, 2315, 6313, 20343, 17666, 18784, 7987, 3399, 7193, 7991, 16738, 9691, 7416, 18014, 19514, 17934, 27709, 177, 29919, 4724, 26889, 3739, 14067, 29465, 29946, 7075, 22394, 8796, 735, 18573, 10094, 25949, 17649, 24831, 7043, 2158, 22025, 6101, 8237, 15623, 16872, 6952, 21545, 14598, 5015, 29015, 20201, 8841, 11571, 17114, 8868, 10272, 12997, 19489, 5640, 15351, 29753, 883, 21038, 23097, 12828, 2712, 4505, 7988, 29467, 24376, 28079, 29462, 7486, 17235, 3883, 162, 20943, 27247, 23020, 22470, 27810, 9034, 25655, 13520, 16560, 13861, 8306, 17555, 554, 17992, 5064, 29661, 25104, 14935, 16634, 25224, 18592, 17603, 25501, 4439, 26858, 29944, 23151, 24500, 8676, 24438, 22457, 23207, 23192, 3164, 11216, 8194, 10121, 29674, 1978, 494, 6624, 870, 20959, 824, 4783, 17334, 10513, 25104, 175, 2644, 23863, 27359, 6224, 19388, 21762, 21073, 11863, 458, 23775, 22575, 21057, 6125, 4970, 20462, 16811, 19754, 4462, 5815, 8669, 8149, 19835, 2389, 5073, 28022, 15173, 23175, 15789, 20623, 27926, 29419, 27584, 10837, 2808, 14929, 18081, 25928, 3291, 26422, 23108, 22652, 9257, 2305, 12248, 18911, 27059, 2091, 21193, 18860, 12544, 19189, 9511, 10949, 13693, 16906, 9356, 7580, 28043, 23640, 6499, 7113, 18581, 28094, 7690, 24236, 28562, 2119, 19153, 12353, 14952, 12047, 12357, 23978, 24258, 29840, 25306, 16659, 16476, 26552, 12634, 22302, 8218, 28782, 6465, 10085, 22561, 9022, 29311, 22440, 27350, 15233, 3238, 2219, 24970, 6625, 9568, 8075, 16279, 3672, 28746, 7413, 22060, 6220, 14003, 21234, 17440, 18291, 24603, 8646, 18137, 4249, 15768, 17168, 20794, 4297, 8205, 24323, 3358, 22888, 19982, 16671, 6290, 6320, 5604, 3689, 4996, 21713, 22502, 12353, 15592, 7835, 28797, 21286, 23241, 5100, 28747, 8547, 12041, 6554, 16565, 24492, 10727, 18428, 15447, 2255, 6572, 8790, 23168, 12318, 671, 10924, 13919, 27427, 28992, 1200, 22851, 10573, 2947, 12398, 28738, 7040, 15127, 28238, 23044, 11396, 9106, 24686, 12216, 27801, 1528, 10560, 13333, 19732, 26910, 12757, 12028, 21397, 25089, 22412, 2530, 14506, 25362, 11900, 22845, 16736, 9687, 22123, 26256, 25950, 6723, 21245, 23646, 19293, 18523, 5266, 5355, 7676, 29107, 14004, 19707, 17992, 26239, 20198, 13127, 3691, 28441, 16493, 28532, 27760, 27695, 13961, 12289, 2367, 9521, 13433, 22093, 10504, 11701, 13600, 28446, 7957, 11956, 4763, 13479, 9929, 20602, 20821, 21273, 27756, 28586, 6334, 15179, 15039, 11619, 3130, 19485, 18132, 13196, 26131, 22083, 28074, 25291, 2072, 10676, 10530, 14160, 1524, 26156, 28949, 1881, 23464, 259, 29372, 12119, 4572, 3137, 15990, 27913, 2761, 5053, 2559, 6702, 9683, 17905, 22402, 22448, 12078, 18241, 100, 2436, 7007, 15878, 16881, 14515, 25932, 4774, 5599, 12733, 28612, 24828, 26533, 26157, 1968, 11846, 14979, 25949, 8243, 8227, 8943, 2623, 4489, 18421, 18904, 7793, 23286, 1352, 10042, 10506, 14530, 16738, 19444, 21042, 27477, 12175, 2013, 29949, 29744, 14537, 23313, 2622, 24194, 21864, 5323, 8733, 388, 17548, 17291, 4709, 29135, 10461, 3825, 14237, 385, 20268, 24419, 26866, 2833, 3070, 322, 911, 13213, 4981, 18125, 26015, 3205, 17082, 23594, 11696, 15495, 20569, 11926, 24204, 15080, 14917, 17168, 22928, 18618, 23076, 26428, 5382, 21945, 19730, 18009, 29193, 5711, 23673, 11198, 13072, 27978, 19017, 21243, 1113, 7011, 17162, 27043, 22072, 9006, 12292, 29358, 29578, 23871, 12721, 15867, 21605, 18108, 26537, 8361, 3032, 28159, 21969, 22780, 8420, 11215, 7004, 5342, 9503, 9266, 18849, 3769, 22078, 29873, 20671, 27541, 20802, 23983, 17854, 9918, 19675, 5427, 3387, 20368, 25412, 4146, 19034, 18683, 17963, 29802, 10627, 17219, 9734, 19084, 18996, 6604, 22730, 5306, 24718, 17733, 25724, 679, 26372, 19319, 2979, 3114, 26252, 12782, 8765, 8056, 29956, 24334, 2149, 28905, 28995, 16546, 8958, 17947, 17268, 12288, 17045, 10391, 10530, 4572, 1824, 10162, 27067, 10962, 23244, 21335, 16290, 20159, 1988, 1241, 18115, 13031, 11447, 2904, 28256, 19995, 11121, 11906, 820, 296, 25292, 29540, 11905, 27852, 2473, 11240, 15792, 22112, 12249, 12574, 21958, 27043, 17380, 13353, 13284, 16388, 29783, 19973, 18558, 18740, 18452, 3405, 20371, 7277, 8247, 29122, 14892, 6176, 16096, 1177, 14947, 25461, 16260, 13956, 4980, 3952, 1186, 26460, 9823, 2855, 14536, 29353, 13396, 11186, 10552, 29599, 9564, 22633, 24579, 13946, 29397, 21646, 29112, 4635, 16350, 10582, 10965, 1411, 15403, 8617, 6037, 16477, 20691, 25746, 704, 16336, 22221, 2773, 16951, 9903, 6662, 19020, 15033, 4271, 28839, 29555, 24223, 12081, 17023, 22727, 6437, 606, 2736, 25584, 26487, 17276, 23617, 3684, 3379, 6975, 20418, 17524, 10293, 18666, 20719, 27024, 25602, 25269, 17150, 5669, 12978, 18590, 19891, 988, 5309, 17967, 794, 27683, 24817, 20096, 18306, 3181, 11393, 434, 17352, 26462, 2585, 16364, 1130, 20509, 9599, 25565, 592, 3037, 16584, 26957, 3754, 2889, 10307, 28210, 6248, 19949, 24743, 15142, 24822, 2256, 2266, 5644, 29560, 326, 937, 18037, 3639, 19611, 28119, 370, 2599, 18255, 6201, 15274, 4597, 21976, 23844, 26503, 18056, 26546, 14418, 29886, 13690, 26396, 8514, 19400, 29672, 25773, 14425, 20845, 13758, 21797, 24896, 1335, 3153, 23342, 34, 4827, 6144, 8084, 18511, 19344, 28399, 13935, 15572, 14997, 28694, 19500, 8462, 3183, 24805, 25479, 20592, 19382, 17859, 3769, 1450, 17126, 21355, 2937, 6696, 25413, 6781, 22009, 17564, 8126, 13419, 18722, 2808, 4805, 3405, 9493, 8139, 9312, 25626, 19754, 13844, 17512, 1410, 16936, 3854, 1079, 7574, 23067, 14096, 2735, 3047, 8332, 25540, 13528, 15474, 27214, 9419, 14437, 26399, 23680, 14174, 4436, 18799, 11511, 21347, 7238, 7451, 435, 11622, 8800, 21371, 15424, 7295, 12429, 25028, 16839, 1990, 14812, 6498, 23757, 18136, 12209, 4496, 21169, 22839, 20814, 19592, 11598, 8585, 12053, 29497, 23141, 17878, 3826, 7805, 27980, 25407, 8599, 13463, 20467, 22373, 8080, 15557, 15698, 11844, 19960, 4633, 15483, 455, 11857, 4911, 24144, 5748, 27448, 506, 1833, 29286, 14068, 8796, 15830, 13879, 25774, 8271, 14631, 5306, 13499, 22493, 27111, 18026, 12457, 18441, 2042, 24363, 8306, 4446, 4767, 23087, 5325, 21176, 7024, 16618, 3976, 2801, 20483, 16378, 9425, 9036, 26932, 12213, 14650, 19163, 9922, 4822, 17827, 1441, 162, 892, 8197, 27464, 22342, 27737, 27354, 11064, 5885, 6870, 28559, 24033, 10914, 11403, 8804, 18441, 13107, 11737, 5708, 8966, 11865, 9095, 18665, 22034, 21402, 11065, 15093, 11219, 11876, 10154, 24122, 8800, 26288, 21690, 23784, 11227, 22844, 25948, 26253, 27991, 29631, 12847, 8016, 6732, 23009, 18846, 27216, 21563, 5967, 10720, 822, 7178, 15057, 25447, 19809, 17804, 24993, 21125, 29451, 5803, 2057, 9159, 27291, 13840, 7892, 1413, 4744, 21267, 28523, 29961, 12017, 5882, 4051, 10082, 16437, 10425, 21576, 15859, 15336, 10323, 11273, 11445, 3345, 9132, 13506, 890, 25452, 29021, 11746, 22909, 4564, 12550, 17619, 21212, 13728, 22135, 17212, 16909, 9091, 13897, 22019, 3384, 4323, 3062, 14815, 13844, 23880, 4323, 9484, 12857, 15711, 19984, 27555, 25586, 13212, 3386, 26100, 15634, 205, 26131, 24132, 18776, 17463, 17016, 28817, 7016, 19381, 18037, 4472, 17476, 8063, 6899, 10497, 18658, 17701, 13804, 9929, 18422, 26305, 26522, 21516, 18546, 29318, 26191, 11272, 12034, 15794, 381, 23544, 232, 18475, 4871, 24496, 1734, 363, 15278, 10504, 5193, 14952, 522, 25804, 5274, 16751, 14062, 17907, 13545, 29745, 7036, 17157, 6146, 4371, 22006, 13843, 5127, 16265, 14528, 28067, 15646, 18369, 27246, 27932, 20181, 4954, 431, 8320, 12749, 28290, 17162, 23931, 1653, 22255, 1511, 11055, 29883, 25080, 21740, 12142, 24993, 9095, 28788, 20203, 28474, 8467, 14912, 15103, 4621, 14984, 12397, 11630, 6769, 22751, 20388, 14158, 12455, 671, 10963, 7919, 26185, 28339, 3129, 7840, 11874, 24351, 9561, 28435, 26708, 13481, 10283, 8411, 321, 23568, 28164, 16017, 15384, 7894, 12626, 467, 22420, 19363, 16974, 14022, 19935, 20865, 23367, 10124, 4892, 9821, 5366, 25214, 17508, 23981, 28388, 23113, 6806, 5784, 17852, 3175, 22126, 8202, 21051, 21055, 26870, 21659, 1116, 15389, 20483, 7414, 18089, 9332, 25480, 18162, 16681, 27249, 20553, 17751, 29372, 28511, 9552, 14163, 4796, 6399, 7960, 24671, 3808, 25124, 21113, 19887, 8452, 24745, 6181, 499, 14984, 12657, 4808, 3494, 10995, 5543, 10668, 16035, 12003, 7754, 20739, 430, 8765, 28858, 19322, 1745, 1756, 9757, 2657, 6634, 25211, 23550, 12052, 25369, 29459, 7669, 26479, 28149, 23408, 27770, 22285, 21983, 24293, 6982, 17554, 20772, 13487, 3795, 16733, 4862, 7740, 28599, 4240, 6659, 2422, 7596, 5849, 16536, 4069, 9687, 26809, 17019, 19963, 19842, 26820, 11872, 7437, 10099, 13413, 7512, 11988, 14175, 20224, 1819, 24120, 598, 27043, 2846, 21717, 12626, 4978, 24650, 11420, 3511, 19636, 4308, 26808, 8379, 29243, 3838, 11132, 22325, 14606, 5696, 477, 1095, 6847, 24668, 2568, 14117, 2762, 696, 23304, 18251, 7428, 20700, 29541, 21207, 6065, 25939, 13642, 7137, 14545, 28150, 16321, 961, 22959, 6258, 19131, 23566, 11226, 192, 1802, 28685, 9022, 583, 28846, 9116, 29972, 7711, 16580, 18576, 5032, 11743, 8602, 22316, 12080, 22048, 23464, 27124, 15971, 28452, 15818, 4312, 9666, 14799, 8262, 7968, 8589, 20407, 7437, 3733, 13971, 994, 2959, 22091, 20772, 22576, 27454, 23188, 28083, 18705, 12095, 7527, 20392, 9447, 4042, 14813, 9328, 12937, 28663, 22165, 20200, 4803, 18711, 21063, 8359, 23723, 1498, 26595, 12580, 15230, 22452, 14701, 1686, 21103, 28813, 26187, 16409, 28110, 9253, 27917, 3982, 20548, 26286, 24466, 3525, 117, 29219, 23163, 2736, 2668, 28394, 5697, 27769, 14367, 25753, 21897, 5998, 12597, 28501, 12377, 17280, 27659, 25749, 22899, 14613, 19653, 8197, 26407, 28976, 27007, 20386, 1096, 18495, 28971, 9281, 16849, 2974, 15565, 29367, 25943, 20939, 12233, 3673, 19293, 12722, 27842, 14043, 4929, 24136, 20199, 7411, 26874, 12124, 24302, 12032, 10897, 955, 27916, 10829, 18472, 11143, 16659, 3901, 11684, 11458, 17548, 15018, 1553, 21013, 13326, 6887, 12095, 28299, 26507, 29018, 5583, 6870, 5564, 2355, 8087, 6784, 1816, 9679, 13096, 23168, 17892, 3377, 22636, 5367, 2880, 28140, 4472, 15074, 18394, 12832, 19435, 24144, 25531, 7681, 7107, 18601, 12203, 22722, 2916, 7639, 4204, 2203, 8555, 1185, 27361, 18376, 10461, 3233, 22667, 2910, 3388, 15114, 8834, 23416, 15871, 10845, 26438, 5374, 18444, 22461, 1505, 5101, 2908, 21498, 6184, 5029, 22934, 12969, 13519, 21872, 2664, 20155, 24940, 10618, 16720, 20415, 3174, 1121, 18047, 22522, 13896, 25739, 5292, 18735, 8127, 134, 12490, 27706, 29413, 320, 24525, 13915, 19899, 19834, 27236, 7780, 1580, 22309, 4951, 14006, 13643, 5164, 1232, 24268, 21321, 24160, 19477, 29737, 1428, 25529, 25582, 7622, 20734, 27051, 28923, 22356, 1313, 26283, 635, 13008, 15794, 15870, 20595, 23421, 25354, 910, 13256, 2410, 14616, 6159, 12149, 19336, 9953, 12195, 18286, 22615, 17980, 9954, 10835, 12461, 5706, 1454, 3676, 9097, 3839, 6871, 25751, 15520, 14020, 21322, 6010, 314, 25972, 29780, 6923, 14472, 20437, 8894, 27687, 29824, 14265, 17293, 28366, 27604, 5470, 3371, 5677, 4127, 21677, 23999, 18649, 22009, 17410, 21806, 21866, 23167, 6155, 4601, 18213, 17122, 10081, 6197, 10013, 29171, 29610, 23167, 14024, 14091, 2110, 6050, 25579, 13008, 29942, 1858, 17292, 25056, 29827, 23639, 17418, 28231, 1921, 20998, 26967, 3405, 4195, 18716, 14241, 19365, 4173, 13774, 4072, 27732, 17184, 10678, 25814, 17976, 21757, 25818, 17254, 21449, 14677, 23527, 23932, 637, 28239, 15529, 106, 5502, 12714, 15171, 15395, 27262, 14445, 26168, 29363, 28972, 11536, 5117, 22850, 27771, 11105, 21152, 9150, 2445, 24810, 27937, 5434, 15628, 10220, 4818, 5718, 22521, 11167, 22823, 11422, 28559, 18351, 26311, 16179, 25660, 24940, 23356, 7365, 5682, 8026, 13290, 14582, 7507, 18771, 19374, 4332, 28718, 1943, 18951, 3231, 23400, 13142, 24320, 8830, 9172, 15559, 11614, 28982, 10105, 25680, 18557, 22337, 8847, 15490, 4732, 8870, 19226, 9493, 19989, 28043, 16280, 5369, 20791, 10758, 14065, 11220, 2385, 24031, 9231, 4046, 22209, 20622, 701, 24750, 12341, 23592, 23566, 534, 11427, 15867, 13133, 3574, 29277, 20667, 8638, 7767, 18168, 27422, 19027, 23748, 21623, 11642, 14534, 12728, 6102, 6032, 29974, 10750, 11688, 15305, 4792, 21206, 21653, 25119, 17863, 5859, 23257, 24330, 13308, 14638, 26931, 1684, 26814, 29763, 3069, 7693, 26711, 4935, 19477, 4489, 9903, 20193, 28499, 18009, 7396, 27966, 26518, 3330, 20812, 5732, 29723, 17363, 4582, 2424, 18961, 14038, 12440, 25043, 14288, 24730, 28452, 6704, 22256, 1618, 25683, 27764, 29589, 13262, 13591, 3627, 23850, 2668, 22469, 26477, 4815, 14096, 20368, 22511, 25664, 25811, 18003, 13590, 12598, 11785, 19707, 5539, 28480, 24257, 5742, 23802, 20198, 1785, 395, 3352, 4453, 18315, 23741, 1707, 8748, 28701, 19973, 15077, 26900, 22245, 18541, 10879, 7211, 20675, 29241, 17239, 8326, 22522, 20050, 19455, 14170, 24571, 19955, 14491, 701, 18107, 8679, 127, 20623, 93, 14009, 10688, 24622, 14878, 13010, 17556, 17437, 23126, 12770, 66, 25720, 16787, 1344, 29126, 27357, 11, 22238, 24351, 4627, 19678, 24268, 27775, 8757, 6157, 23051, 18282, 28403, 10488, 14013, 24565, 26589, 23075, 24338, 11750, 5735, 2540, 8999, 23909, 5574, 14484, 23738, 24565, 5723, 28221, 11306, 8660, 11026, 19602, 25580, 21084, 17647, 13879, 22556, 2873, 22961, 29256, 25937, 7238, 23284, 27240, 7753, 19865, 6399, 4616, 4067, 19127, 25387, 2094, 27038, 24753, 26161, 20769, 17787, 18001, 13423, 20619, 12956, 1814, 1595, 19842, 13346, 16634, 26319, 21127, 7456, 29121, 2076, 15372, 23854, 24542, 25107, 24196, 26469, 3120, 4307, 1118, 20034, 6856, 21568, 10666, 25944, 14999, 12203, 19157, 16624, 23448, 28406, 20118, 16317, 14703, 5429, 26290, 28014, 26923, 28235, 7258, 10685, 5779, 9374, 13786, 16999, 8131, 14200, 26482, 19627, 20744, 17990, 23521, 3054, 27143, 22254, 15696, 28290, 16193, 23557, 8238, 11742, 11101, 8065, 23243, 28811, 8012, 25141, 2676, 20946, 6397, 5325, 21107, 25572, 27079, 26817, 12265, 7627, 22844, 4454, 1888, 20604, 12191, 29835, 430, 5025, 12983, 3948, 9691, 10784, 22885, 18129, 29361, 16549, 17729, 6458, 10142, 7016, 17496, 1390, 18943, 616, 5948, 7105, 13769, 2723, 11491, 2204, 22796, 11336, 15829, 8406, 10338, 21693, 3606, 21146, 14631, 16675, 20810, 8719, 29324, 3314, 5213, 3954, 23023, 3769, 21858, 20960, 23161, 23460, 7603, 5704, 25251, 11899, 1802, 231, 17455, 25292, 10669, 18642, 17746, 12417, 7954, 8617, 28619, 1460, 9332, 523, 19778, 1476, 14334, 10469, 6958, 26527, 4736, 21539, 10933, 12305, 6431, 1290, 15914, 6475, 26249, 7329, 17985, 24406, 7196, 9813, 18142, 13545, 23060, 18233, 29869, 354, 21502, 5476, 20550, 10630, 14111, 19223, 9340, 26953, 6128, 21125, 11628, 869, 15009, 10410, 26570, 6085, 25783, 11321, 8104, 9601, 21382, 2571, 16995, 23335, 14436, 13483, 2912, 3893, 29793, 17968, 29028, 23658, 4003, 27565, 15521, 3671, 13947, 17302, 13389, 7015, 19155, 10534, 23234, 7286, 7715, 8035, 10309, 22870, 6980, 7230, 19720, 24124, 2720, 12786, 10941, 1420, 10022, 19883, 19845, 17839, 29740, 2517, 24062, 27332, 20355, 17219, 24499, 13887, 12807, 18914, 28944, 9242, 20524, 25309, 652, 16827, 17644, 4271, 10686, 1131, 20193, 22415, 23449, 7124, 22019, 7971, 28318, 12504, 21268, 6350, 5898, 13706, 2516, 23861, 14172, 7259, 10792, 26625, 20209, 29224, 26903, 14324, 25588, 5177, 13150, 11616, 18839, 16254, 27728, 5082, 14720, 24381, 15373, 20832, 9690, 8861, 10880, 20335, 21025, 28783, 1738, 11868, 22258, 25918, 24082, 4022, 11424, 7000, 4229, 11683, 16773, 1184, 29441, 9427, 14124, 17488, 3356, 4825, 5953, 21125, 23804, 20110, 3662, 24724, 21957, 1180, 17190, 14365, 20636, 23013, 28876, 2764, 28578, 26473, 2255, 10583, 3919, 3460, 5205, 23349, 26530, 26444, 4772, 13017, 19523, 16859, 18008, 8324, 599, 1099, 21781, 28418, 8714, 23248, 29684, 24123, 23724, 23824, 18117, 16456, 207, 9838, 11608, 2698, 17162, 12104, 12389, 24089, 600, 1064, 23106, 24488, 8760, 22392, 4726, 16959, 259, 13492, 13563, 7538, 9641, 6750, 18627, 4625, 5496, 28342, 27765, 9204, 29942, 22414, 8925, 3327, 843, 23522, 26069, 6466, 14950, 28645, 9835, 25262, 14724, 9128, 2932, 15224, 25044, 21569, 12383, 20681, 29402, 21278, 16004, 7397, 2153, 4395, 2455, 22302, 6524, 22552, 23275, 28476, 11049, 17925, 18217, 15669, 16608, 6677, 18717, 22936, 7581, 9452, 12692, 327, 917, 22902, 7208, 14407, 4701, 27055, 11384, 25510, 3563, 10939, 22384, 2181, 24414, 18388, 2224, 25309, 16979, 22649, 7636, 1996, 21780, 10537, 21720, 575, 9907, 820, 5843, 10412, 7596, 4546, 4405, 15696, 5840, 18785, 20765, 27678, 2800, 22486, 28623, 19540, 1128, 12852, 508, 12404, 9797, 9660, 16392, 2174, 28610, 11062, 10958, 24293, 10819, 24875, 8206, 26695, 15313, 10955, 8060, 25512, 28138, 4323, 6659, 5546, 22180, 3543, 26646, 4115, 1315, 21663, 7904, 16586, 19149, 11804, 22623, 25518, 28892, 20917, 4539, 17040, 26437, 17707, 15507, 8823, 12967, 26546, 29125, 6346, 17962, 6877, 5518, 3933, 6507, 12547, 24918, 3611, 4235, 6519, 11243, 21005, 24630, 1737, 3494, 21715, 17785, 28772, 10238, 6852, 9337, 14241, 23033, 12596, 24917, 9482, 140, 27813, 27148, 13462, 3669, 24709, 4753, 19496, 5524, 17588, 17825, 5581, 21673, 6258, 6880, 26805, 21839, 27730, 8617, 14989, 29123, 24784, 9664, 26056, 6235, 5843, 25640, 4416, 23562, 28422, 448, 25787, 4166, 4932, 14209, 21881, 21190, 12161, 12927, 5184, 6818, 4202, 20564, 2423, 17156, 21767, 22917, 27187, 12387, 24621, 4245, 6514, 18887, 10144, 9287, 436, 24413, 310, 2685, 24424, 15628, 24380, 20672, 13854, 19510, 25230, 8315, 26021, 14475, 484, 17826, 18669, 29085, 27667, 24864, 20489, 16320, 21183, 5324, 27201, 17088, 20409, 1696, 13432, 6582, 22003, 26921, 9107, 13742, 13796, 27300, 4838, 8678, 5790, 4931, 27750, 23232, 22000, 702, 22984, 4914, 13163, 9187, 27046, 6650, 8273, 2961, 25627, 13723, 14050, 20705, 24181, 24498, 13690, 28599, 5154, 6124, 1436, 15276, 12277, 14737, 18598, 25266, 29021, 20770, 9570, 8805, 3701, 28867, 3931, 12502, 13095, 20940, 18895, 5856, 2866, 22010, 10844, 6204, 27617, 10177, 13910, 8030, 28457, 1922, 11830, 19135, 26047, 24593, 7740, 21543, 29309, 21604, 27675, 49, 22072, 24700, 13644, 23418, 9256, 5427, 3319, 5952, 8247, 15195, 9740, 11466, 15190, 19967, 27500, 22198, 11157, 17879, 14343, 12478, 28794, 29616, 13679, 27630, 27712, 3616, 24799, 22609, 11068, 17060, 15580, 12562, 19793, 5364, 20451, 28874, 5588, 12588, 26994, 29212, 24870, 8004, 8010, 27083, 12884, 1005, 10678, 331, 688, 11823, 20434, 21973, 3617, 29959, 24278, 3425, 24391, 15189, 18645, 7491, 26413, 1300, 11012, 12944, 29872, 17391, 4733, 6740, 15324, 1919, 11705, 18614, 26498, 19573, 27332, 29911, 6535, 10622, 15004, 1353, 16473, 781, 9502, 26955, 9392, 20089, 13748, 26275, 8297, 6571, 25533, 1109, 23274, 11717, 6673, 19874, 18124, 9301, 25927, 13599, 4171, 3076, 8145, 2969, 6044, 7722, 22546, 17874, 11104, 20755, 4101, 21146, 22321, 507, 13122, 7838, 973, 25788, 10018, 16993, 344, 24811, 23384, 7746, 15431, 4585, 23187, 3839, 6356, 13869, 17181, 27119, 6972, 21098, 7193, 16371, 9853, 28437, 1796, 20869, 14413, 13310, 7983, 22914, 12195, 9486, 14676, 282, 171, 26426, 6348, 22896, 6041, 17702, 1229, 9397, 23720, 16539, 1470, 11669, 27410, 27953, 13604, 13323, 13023, 24386, 7903, 17818, 13804, 26641, 9890, 25875, 29610, 21875, 2042, 353, 28018, 20133, 11193, 2631, 23808, 18290, 16711, 5598, 10024, 1504, 24345, 8148, 28587, 24595, 27332, 24893, 5401, 13455, 16706, 27090, 4960, 24915, 20539, 3758, 24791, 15801, 29526, 14363, 8955, 13389, 27148, 11638, 18390, 2021, 20322, 23474, 5032, 1395, 22755, 10907, 27723, 25129, 27302, 573, 23235, 22109, 27265, 10034, 19186, 21249, 18925, 13857, 29302, 11992, 1210, 23953, 18674, 4384, 10857, 21456, 21232, 22371, 24188, 11538, 4906, 25259, 1851, 28617, 17509, 10389, 21569, 10741, 17987, 1605, 24952, 2571, 24895, 4255, 5917, 16735, 22443, 11731, 16986, 11835, 26324, 18184, 16276, 8740, 4663, 368, 21243, 17833, 13845, 14125, 18006, 24858, 4509, 28973, 5323, 5351, 15359, 190, 19360, 17184, 9741, 26774, 10765, 19499, 14950, 16287, 21560, 23909, 29179, 7480, 12058, 20293, 25156, 5677, 8068, 23242, 22974, 9656, 13919, 23631, 28135, 14245, 26250, 27706, 25327, 14976, 26914, 22063, 22238, 22001, 12219, 5500, 25129, 18196, 29252, 20182, 6804, 22351, 16367, 20325, 29974, 25215, 4597, 13649, 5878, 20554, 12857, 21346, 26593, 1587, 7660, 9598, 15722, 14079, 16362, 21824, 5280, 28817, 13992, 721, 23516, 4406, 14721, 7253, 17229, 29184, 23918, 11226, 6529, 20718, 3633, 26984, 9152, 14927, 21386, 21915, 27240, 3643, 18793, 9190, 3155, 21206, 21289, 29242, 22020, 14308, 29856, 28526, 20555, 18518, 27681, 8904, 9941, 24480, 24572, 13151, 12817, 17024, 5517, 19325, 19339, 26503, 24974, 21096, 2042, 815, 25363, 4981, 5502, 9422, 15699, 461, 17330, 1800, 9711, 9413, 25741, 10130, 25104, 8639, 3684, 26270, 7834, 1922, 5636, 3332, 27135, 13881, 22264, 11060, 27188, 7961, 20687, 18992, 25476, 26485, 15932, 8071, 10075, 11764, 10939, 26457, 10643, 6935, 9533, 26598, 8606, 18272, 25973, 22649, 998, 16405, 29648, 27099, 12507, 23457, 102, 20364, 24011, 6063, 5875, 13706, 25143, 6667, 22469, 2299, 12021, 2981, 5398, 27292, 7574, 21066, 9231, 29796, 13517, 18666, 6558, 23420, 1046, 23481, 17011, 15441, 14579, 5315, 1117, 948, 3282, 25573, 19935, 19064, 677, 25164, 17816, 22183, 17789, 14492, 23876, 18808, 29303, 5242, 15805, 5432, 17822, 5669, 11988, 19425, 7035, 23780, 16905, 15671, 26517, 9859, 13821, 7862, 2665, 29680, 640, 1125, 11245, 16178, 15337, 3348, 26982, 23871, 22229, 5533, 28110, 21620, 14222, 26889, 16127, 27172, 827, 28700, 26786, 29616, 6399, 4937, 3055, 11596, 25108, 23079, 7994, 27929, 8978, 22351, 27306, 2649, 14501, 11172, 21796, 24673, 19499, 24996, 12008, 6268, 15076, 5394, 11672, 6425, 22881, 19725, 23944, 24926, 7913, 6736, 10317, 6260, 7575, 16753, 22046, 6468, 6247, 25372, 23333, 15743, 22926, 9298, 8172, 25433, 2195, 22823, 12268, 14997, 27475, 28937, 4268, 29460, 2131, 15555, 18650, 20975, 1406, 9227, 24402, 6578, 27951, 13976, 24277, 27723, 7874, 1031, 20227, 10316, 244, 5839, 1132, 17113, 2015, 24119, 3197, 23814, 29932, 933, 5515, 11601, 27502, 6237, 12541, 4862, 8391, 36, 15234, 22923, 8882, 29542, 13055, 26134, 7750, 3628, 26071, 11727, 12280, 7125, 3434, 26791, 16387, 905, 29431, 19401, 19111, 19711, 9385, 12930, 12921, 7172, 1360, 1822, 24349, 9884, 7254, 19879, 17179, 16688, 6806, 29455, 29863, 17507, 10524, 19857, 21395, 15167, 24971, 4194, 1097, 15778, 2182, 13780, 2743, 14979, 28971, 5874, 27092, 5578, 3914, 11562, 23510, 29599, 27924, 28863, 11030, 9127, 12225, 22064, 10047, 10247, 24162, 26594, 29800, 12787, 4276, 18156, 23826, 11486, 14456, 3775, 650, 21909, 23175, 22124, 11120, 29376, 16737, 22420, 8433, 16617, 14035, 4687, 19605, 27797, 20726, 17339, 21938, 211, 7306, 19764, 13191, 12765, 18308, 12752, 19538, 29142, 13513, 17917, 29509, 19075, 714, 7284, 11148, 3414, 5163, 12356, 2877, 9633, 17574, 7455, 11313, 23939, 4985, 5842, 29417, 23020, 22468, 8686, 8060, 16136, 8854, 29167, 17233, 10706, 12943, 29793, 3940, 10734, 4466, 3183, 3862, 25038, 4543, 13232, 10217, 4321, 25123, 15521, 18769, 24820, 17482, 857, 1670, 2441, 14287, 19806, 11294, 4116, 26456, 25670, 11742, 27467, 12245, 26631, 21014, 12167, 3972, 8454, 5300, 26303, 19533, 6249, 26688, 9249, 13057, 24494, 18725, 3234, 23356, 2733, 25996, 16101, 5379, 621, 6485, 1660, 6718, 13240, 13241, 10631, 5370, 10214, 2438, 9778, 29612, 29633, 16723, 3280, 7599, 9969, 12493, 28431, 15248, 20333, 19892, 24102, 2945, 11435, 17684, 6799, 16793, 11774, 19012, 19661, 8512, 3786, 8200, 11606, 26812, 21929, 729, 12585, 9637, 11140, 5100, 8676, 2303, 20448, 12335, 4558, 20158, 29650, 2633, 29386, 14261, 20306, 7621, 3030, 20587, 29622, 26621, 10411, 26789, 7309, 20480, 8352, 14774, 28248, 8004, 23743, 5480, 27883, 28604, 7648, 1749, 25950, 16867, 10663, 21293, 3695, 20295, 22614, 1936, 11942, 24964, 21377, 2815, 10930, 11372, 22227, 7789, 10958, 25066, 1893, 8355, 26139, 8622, 4981, 11241, 16982, 21625, 13687, 13297, 10154, 13925, 15237, 7746, 29891, 16472, 14899, 21762, 5062, 27629, 29914, 11001, 779, 6318, 5876, 5843, 19862, 29156, 12173, 9442, 18754, 11010, 11137, 29181, 7057, 6312, 19500, 21520, 7682, 22427, 15682, 1286, 1894, 21196, 4611, 8547, 25397, 5698, 28649, 6001, 21419, 6449, 10592, 2605, 8787, 5964, 20425, 16512, 17337, 12657, 26529, 10352, 4475, 21876, 22395, 26097, 13533, 29416, 18100, 25076, 25238, 9271, 18370, 25261, 26889, 22398, 18643, 18456, 15839, 15366, 3833, 18457, 27644, 28637, 1901, 23318, 5728, 2747, 15209, 19621, 7618, 25521, 20007, 772, 29809, 6844, 1158, 16940, 29808, 4133, 10439, 15637, 16596, 14416, 8021, 18953, 4147, 15485, 16724, 7098, 3029, 14708, 16291, 15639, 12466, 6575, 6785, 1382, 10429, 9368, 8214, 270, 6176, 12627, 6549, 18139, 29266, 29419, 11891, 9457, 14208, 4603, 23662, 25069, 29722, 18628, 24500, 17964, 3679, 20896, 15824, 5659, 21678, 20151, 5429, 19902, 15036, 17486, 18645, 22265, 12242, 9435, 16803, 23127, 10170, 21586, 26948, 21961, 5418, 14523, 21687, 3190, 24475, 21205, 4292, 4009, 22898, 4722, 7344, 20204, 11850, 29847, 9240, 16136, 6887, 25614, 2620, 28240, 3710, 18424, 6520, 3046, 656, 28078, 23588, 14708, 793, 10398, 5349, 20707, 25968, 12336, 29871, 22155, 22414, 28357, 4083, 3635, 23048, 6301, 9662, 13391, 16512, 1988, 19463, 12583, 12223, 18212, 7029, 3990, 6882, 8279, 25871, 28899, 28788, 2576, 4765, 1499, 14160, 9271, 3862, 21499, 11791, 19904, 9485, 21455, 4725, 16406, 25966, 19108, 26573, 4309, 25729, 23200, 28688, 11020, 16792, 15681, 19676, 11610, 578, 24512, 13410, 22747, 6400, 4949, 17849, 5855, 10580, 11137, 25734, 13109, 13822, 7258, 13560, 12828, 10513, 2731, 23600, 6332, 11339, 28280, 2805, 14899, 13203, 22802, 15143, 22810, 22704, 14061, 14523, 26009, 484, 26770, 29547, 26629, 1487, 19610, 29349, 13286, 7087, 18753, 2633, 7298, 19541, 24735, 12846, 3382, 24233, 4745, 21756, 25522, 14109, 12270, 8010, 28895, 17045, 13630, 397, 2145, 2797, 1567, 5192, 29456, 24953, 3683, 26920, 5976, 20570, 15407, 23353, 11553, 7640, 8930, 14045, 22662, 1097, 20391, 28417, 28941, 17836, 17009, 7616, 21468, 9885, 13851, 18613, 1376, 15169, 10095, 15269, 3470, 16367, 18639, 4678, 18973, 3680, 3437, 12632, 8988, 25810, 19835, 22632, 12719, 25831, 29599, 14562, 4009, 20396, 14054, 28549, 24926, 8914, 20323, 24620, 27788, 13856, 16123, 5135, 19059, 1849, 18097, 14393, 11167, 25282, 13832, 13364, 4923, 2100, 28865, 20183, 616, 10088, 23389, 8753, 23471, 29002, 16130, 23053, 15602, 8838, 18072, 16566, 29882, 13843, 13504, 18789, 10409, 4535, 12669, 10823, 27823, 2515, 5275, 17145, 2001, 12734, 10511, 18672, 23949, 10356, 15530, 7089, 23046, 10152, 13844, 2136, 29813, 28040, 20136, 18598, 1941, 27118, 11440, 13420, 17267, 29365, 26161, 11222, 9288, 4831, 3721, 19768, 16954, 14439, 24271, 4601, 11826, 2616, 26517, 22165, 6662, 3297, 17894, 28148, 18894, 24728, 11391, 7551, 14507, 12014, 27543, 27873, 9557, 14763, 27147, 2753, 5596, 6840, 769, 18047, 1845, 28645, 12980, 17775, 11507, 15820, 25200, 1515, 3522, 23542, 15749, 17207, 16115, 3686, 12789, 16700, 15324, 26734, 26179, 18887, 13637, 6783, 21203, 17540, 6900, 11070, 10242, 20067, 11660, 4621, 24451, 22910, 17521, 83, 12637, 21650, 9919, 5228, 11215, 3916, 7521, 21390, 12639, 5905, 18782, 4924, 28382, 21784, 16813, 14, 14110, 14594, 26715, 11808, 1176, 20113, 19820, 8378, 9009, 12945, 21161, 13437, 28431, 6960, 26130, 9651, 22251, 356, 11388, 902, 9295, 23118, 25797, 17603, 7607, 18872, 29027, 3188, 12185, 10010, 16748, 27653, 6562, 10125, 19854, 8797, 29184, 6082, 24542, 10550, 2722, 10364, 8655, 11215, 13621, 4910, 28359, 15963, 14650, 1953, 27930, 28720, 10812, 23806, 23995, 6971, 3082, 1813, 8656, 19606, 28132, 7488, 1519, 6112, 8533, 27390, 5729, 4161, 11277, 20334, 23175, 25997, 26580, 5565, 27908, 7277, 8795, 13406, 989, 11871, 27017, 25361, 3157, 5871, 16479, 1844, 24129, 25501, 28556, 17051, 12051, 7646, 23663, 2406, 28446, 1314, 29898, 10898, 2992, 23179, 19097, 16374, 3938, 8781, 5693, 12044, 15087, 23024, 21521, 22434, 27843, 10061, 24408, 6692, 22768, 18278, 1964, 9384, 28921, 29534, 12074, 24520, 19610, 16096, 4146, 18073, 5634, 21156, 19307, 1819, 24675, 5260, 7178, 22765, 26962, 25849, 22953, 26184, 11468, 15, 22140, 18827, 26643, 11166, 16835, 4844, 2060, 27890, 23065, 12876, 24116, 9281, 9488, 12089, 17733, 17792, 5006, 5233, 4742, 23527, 17629, 16923, 29527, 10312, 20050, 22015, 11790, 14127, 28030, 11154, 1234, 15955, 25097, 17697, 3485, 29581, 9232, 317, 26838, 641, 28302, 21647, 6294, 29837, 12784, 8992, 8089, 15196, 19281, 29879, 20254, 18137, 7417, 2967, 4636, 3939, 6802, 23533, 10679, 10176, 10804, 11404, 24025, 27782, 14505, 24656, 3525, 6372, 8957, 12712, 19881, 15685, 10310, 17158, 4911, 29178, 17574, 6559, 8385, 25599, 27906, 10666, 23458, 4101, 19680, 26094, 9946, 15474, 5211, 10463, 25394, 2943, 2816, 14849, 27277, 829, 3681, 29264, 27231, 9559, 13826, 16223, 19007, 4462, 18404, 18875, 22711, 1362, 2326, 15367, 23553, 28291, 8440, 14104, 15977, 28497, 4039, 25144, 16934, 5484, 25150, 2363, 25940, 25423, 26615, 11233, 26083, 12116, 9934, 4659, 1421, 1009, 18705, 15601, 2896, 2902, 28447, 23965, 3237, 17898, 19664, 474, 26541, 9764, 1743, 23775, 9152, 13832, 28620, 16834, 4924, 28868, 13987, 23706, 5384, 11567, 6480, 15298, 8312, 22141, 11040, 4578, 23804, 29326, 21576, 459, 19645, 27036, 5558, 26981, 9329, 18856, 10789, 4606, 9783, 28508, 12761, 21602, 8327, 7238, 15446, 3269, 28448, 21431, 11564, 10311, 20289, 23767, 6593, 13704, 9240, 6042, 12662, 1744, 5454, 28249, 22525, 23444, 18749, 11058, 14256, 11645, 7213, 19417, 22736, 18952, 5083, 13112, 23507, 13418, 13540, 1294, 3950, 15395, 7797, 18529, 26988, 2431, 12824, 18443, 7774, 12177, 27317, 9999, 24273, 15464, 19520, 15342, 12091, 16404, 23717, 2035, 21334, 10791, 23408, 18743, 24730, 3221, 25051, 13194, 4974, 15468, 18542, 3863, 6731, 4941, 28479, 1852, 26367, 6879, 21077, 1453, 25666, 8403, 6948, 4796, 24374, 21433, 4286, 4478, 10014, 17020, 5567, 9644, 17209, 20435, 20702, 26607, 15998, 15285, 9373, 39, 13285, 11185, 26966, 161, 24369, 10220, 4836, 2362, 4547, 19410, 20438, 18607, 12560, 15951, 14664, 6629, 10143, 10096, 26571, 14800, 21008, 15230, 10299, 10655, 10743, 27750, 27261, 11250, 4087, 14022, 12491, 15389, 18298, 11551, 29479, 3397, 1945, 16787, 3793, 16851, 12751, 27407, 24120, 25660, 14205, 4753, 4, 22717, 11193, 24074, 8156, 24864, 14660, 12814, 29785, 7031, 1793, 25940, 27416, 1610, 6056, 15812, 1935, 25539, 12813, 8804, 15713, 6342, 17049, 24607, 2255, 8527, 12477, 29455, 11670, 4721, 23868, 17074, 26821, 16853, 10767, 12567, 2522, 25673, 18017, 4830, 1991, 2697, 25195, 29675, 23995, 3349, 27348, 18981, 1381, 15890, 22587, 23949, 23726, 21131, 8940, 29985, 26279, 17113, 9881, 23776, 8920, 27437, 21784, 16504, 5810, 14025, 20088, 3451, 24964, 18107, 19109, 16545, 11067, 13591, 7664, 29163, 12075, 18174, 16382, 9936, 14595, 883, 3756, 13666, 19519, 23516, 12279, 24280, 6291, 9979, 26128, 10309, 23062, 22640, 16298, 26616, 25414, 9871, 20501, 3444, 22320, 10824, 2250, 5152, 28685, 23785, 20264, 9063, 26439, 18510, 9820, 21863, 22693, 11881, 26288, 11526, 10955, 22786, 27275, 436, 8455, 2977, 23057, 29070, 22038, 15616, 23303, 18938, 27748, 10469, 9996, 15602, 17286, 11966, 5661, 24921, 12482, 22541, 5457, 14586, 10404, 17138, 26891, 12334, 13910, 18099, 2988, 8655, 12109, 18533, 17284, 9343, 19773, 29371, 14892, 16062, 12315, 3738, 1030, 11589, 28774, 10027, 17243, 28238, 1175, 24000, 22697, 13554, 21733, 14374, 21965, 28741, 2910, 8332, 3041, 42, 23181, 21910, 12916, 3933, 19654, 21304, 17215, 8876, 4707, 3134, 21132, 7170, 26366, 13451, 17079, 24050, 18094, 21823, 18913, 5942, 27905, 18283, 27742, 6762, 8544, 11287, 2418, 16868, 4520, 11109, 23995, 16318, 15045, 9179, 3610, 14125, 6166, 6244, 19431, 21013, 2194, 27483, 26423, 4184, 26562, 24999, 19261, 28021, 26643, 15173, 14734, 3642, 2568, 23171, 21025, 4877, 24024, 20001, 16805, 20084, 25876, 1678, 8471, 10317, 10363, 17329, 27454, 21475, 17620, 24736, 9071, 18296, 21995, 1501, 4348, 24159, 9705, 24680, 23635, 25863, 23290, 10860, 17988, 21398, 19532, 12479, 9151, 24076, 5848, 821, 23845, 27825, 5631, 6147, 21815, 6755, 3324, 26695, 679, 8828, 7371, 7068, 4035, 9569, 319, 7112, 9724, 10390, 24277, 6675, 24461, 8023, 27181, 20846, 10383, 17826, 15418, 14805, 23145, 19239, 24448, 13002, 18289, 23632, 5471, 19236, 2595, 14926, 1640, 23828, 15437, 2190, 8684, 16123, 18368, 16245, 18713, 23657, 11316, 11173, 782, 29047, 25398, 6446, 23572, 27020, 19899, 12219, 16098, 12121, 2908, 25059, 27740, 21737, 4970, 9045, 15168, 3825, 12372, 5738, 3814, 28819, 20123, 2870, 28881, 8298, 364, 8674, 2074, 26574, 22010, 11084, 7452, 4695, 29891, 24894, 15821, 28789, 7588, 25584, 26475, 22051, 10763, 9858, 18173, 14228, 19411, 20812, 25120, 3030, 22599, 25447, 11688, 26158, 8141, 11454, 27526, 637, 27513, 11039, 7267, 20273, 8130, 20954, 23283, 9022, 8664, 947, 18802, 18142, 25157, 12595, 7778, 11889, 13662, 25885, 25670, 26116, 20715, 18765, 29345, 3955, 23199, 15729, 579, 25125, 20198, 8772, 8887, 3069, 7519, 22504, 10129, 19712, 2662, 24141, 11682, 29662, 19156, 520, 8791, 27700, 19360, 10044, 5441, 19433, 8984, 10474, 8160, 5773, 20729, 23284, 1644, 5001, 19571, 8035, 8354, 3593, 17202, 23577, 15650, 10845, 553, 26771, 24213, 20167, 23777, 2457, 23283, 29470, 22490, 4694, 14150, 2368, 17389, 22148, 2643, 26030, 25923, 7748, 3732, 20854, 15767, 17654, 29132, 588, 19722, 21518, 5295, 1885, 10244, 16848, 9503, 24624, 4278, 5516, 28088, 7780, 6929, 21186, 13463, 13298, 23012, 22965, 7042, 19625, 1641, 23456, 18045, 12881, 27363, 10086, 15933, 7097, 14368, 12394, 15957, 13898, 6959, 23875, 11749, 4104, 28339, 24606, 18226, 12860, 1781, 29896, 21817, 5205, 22806, 27418, 20904, 20750, 24080, 9702, 477, 14406, 10558, 11913, 18294, 19707, 10678, 2780, 13834, 15538, 28377, 11528, 27868, 17112, 9257, 20920, 13938, 29660, 21174, 3624, 6737, 9301, 18394, 22142, 792, 28937, 14912, 12607, 25960, 6639, 26265, 17581, 13577, 22581, 5254, 14298, 24700, 309, 10255, 8164, 19443, 9251, 10213, 29043, 29627, 8570, 6915, 16681, 1957, 28628, 7338, 25160, 16142, 13140, 26945, 28230, 20827, 7774, 28877, 15811, 7965, 17787, 7721, 25574, 20764, 25597, 14024, 14667, 5659, 15074, 17610, 5814, 29281, 27834, 2822, 5498, 28098, 5616, 409, 21716, 13885, 16913, 26681, 23536, 23157, 18585, 8128, 16602, 16785, 1733, 21441, 14348, 6186, 16657, 7088, 6337, 27929, 29358, 7023, 4269, 9528, 22521, 5923, 5358, 11362, 10765, 26185, 10641, 12435, 11366, 24398, 2831, 9376, 20914, 4201, 18724, 17434, 3635, 14787, 24263, 14075, 23013, 26704, 9918, 1969, 10258, 377, 6692, 26105, 24610, 7236, 9082, 24860, 16972, 5171, 6772, 8863, 24031, 17274, 8273, 875, 9777, 3361, 29660, 25693, 24356, 11344, 2158, 26844, 6956, 10693, 28059, 26212, 19972, 11216, 27811, 26127, 10603, 27799, 3447, 793, 11006, 26237, 14986, 5080, 28789, 15914, 16055, 14523, 18231, 5985, 3280, 150, 24263, 28745, 22932, 1047, 29259, 4058, 10391, 14328, 12853, 11049, 6877, 14591, 9003, 3777, 21799, 22393, 4615, 24787, 537, 22066, 23304, 26681, 11093, 26773, 4755, 13930, 29824, 773, 654, 1144, 25729, 29781, 25153, 4106, 11800, 19922, 29129, 24314, 8692, 14087, 5394, 12161, 4994, 17999, 10362, 1529, 8888, 758, 11149, 19971, 6952, 22636, 17815, 8967, 5365, 9487, 21724, 1535, 21138, 20871, 28640, 8447, 9866, 12747, 21882, 25851, 10901, 18363, 16181, 29816, 26927, 11291, 10458, 5553, 9323, 737, 27906, 11134, 10200, 21650, 17391, 4986, 18553, 98, 10497, 17197, 7903, 7077, 22529, 24216, 13900, 17064, 6121, 18714, 19201, 5891, 10883, 27474, 28084, 8731, 2472, 11799, 18442, 24610, 8876, 21331, 28350, 26556, 18312, 8912, 18476, 25914, 7411, 21642, 6772, 15908, 1438, 18790, 7813, 23248, 22053, 20785, 29943, 14802, 21652, 2043, 18412, 29671, 19239, 23979, 18267, 14193, 24891, 26059, 27145, 11816, 24194, 19566, 1423, 12157, 9101, 29639, 27395, 14815, 14899, 27649, 797, 27319, 20874, 11953, 19822, 21644, 10169, 21933, 8122, 4185, 16204, 23097, 11752, 2659, 29356, 3618, 25432, 8287, 24803, 13546, 16799, 26714, 17262, 722, 24893, 11958, 24401, 13715, 22959, 3192, 10400, 15900, 26677, 1553, 19919, 8435, 26334, 5817, 28260, 17004, 5294, 20157, 5389, 22389, 27426, 11412, 19440, 23064, 16514, 15980, 26177, 12866, 17418, 9548, 18015, 11734, 10370, 19716, 18834, 24012, 28404, 29392, 28835, 15303, 21492, 18326, 13301, 11334, 7539, 587, 19499, 27188, 11429, 3806, 3000, 9068, 2974, 14839, 27485, 64, 4274, 26297, 8699, 27496, 18266, 15922, 24727, 21446, 5367, 23682, 28008, 26120, 21100, 13867, 21471, 24967, 27389, 17711, 22232, 19833, 18947, 27821, 4871, 10092, 16074, 29084, 27507, 28341, 23157, 3499, 19287, 2510, 23348, 13446, 16571, 8628, 14167, 24866, 11839, 25933, 13691, 23506, 27123, 23382, 10721, 24437, 7088, 609, 28406, 20329, 12782, 5433, 28486, 9722, 12038, 26376, 29056, 1479, 21001, 25337, 13670, 15042, 14523, 3024, 9637, 13212, 7319, 9535, 26335, 18427, 14481, 20065, 22891, 17283, 18858, 29612, 24990, 23921, 13444, 8626, 27178, 9670, 4923, 3200, 25690, 26852, 15373, 17301, 29275, 9858, 3773, 26395, 1671, 4565, 16737, 23314, 18791, 28857, 471, 19469, 27278, 22304, 24728, 9501, 5519, 8875, 27368, 4468, 15913, 10891, 24430, 805, 27180, 12041, 9389, 29346, 685, 2796, 7760, 9434, 16370, 3241, 1321, 19593, 5917, 12447, 26153, 711, 19367, 26831, 18073, 18531, 8376, 8589, 17834, 2851, 14011, 6356, 8034, 6827, 13441, 371, 1387, 5368, 24082, 9308, 11426, 3072, 13485, 12284, 4995, 10673, 5079, 10973, 8124, 593, 15612, 12872, 23221, 9784, 2703, 14390, 4237, 19195, 6754, 11158, 23333, 22795, 1568, 18374, 15049, 13658, 22135, 1571, 8199, 29930, 8273, 28290, 6761, 544, 25470, 15064, 19529, 23815, 17828, 14335, 18643, 15950, 17375, 16427, 11222, 25903, 17647, 19242, 27180, 7645, 4087, 27489, 13293, 1215, 13534, 25120, 19184, 15143, 7898, 7320, 22216, 3380, 8556, 2185, 5244, 28330, 22397, 7300, 20507, 19645, 25176, 16161, 18851, 8763, 28760, 2588, 4703, 12848, 19109, 13875, 20095, 3515, 29921, 9041, 16205, 27203, 16443, 21995, 6680, 386, 23882, 17746, 14768, 13372, 12063, 15559, 6695, 11074, 1396, 7697, 1885, 15837, 214, 29222, 3757, 827, 25484, 29794, 26864, 17990, 7460, 18036, 19583, 3613, 7659, 2845, 7652, 19450, 17883, 5594, 11330, 10188, 16143, 16274, 27180, 4812, 26456, 9520, 4659, 23713, 14675, 15651, 11953, 8339, 6909, 26539, 21881, 2461, 24667, 24574, 21601, 17330, 18244, 17862, 963, 26915, 22317, 26344, 17046, 7796, 8798, 27351, 17800, 16448, 26169, 9765, 21188, 18576, 22101, 3037, 24516, 25337, 17879, 12467, 21870, 4312, 27648, 3077, 16554, 25682, 15311, 2518, 18369, 181, 13817, 28282, 29250, 10054, 12332, 2219, 21856, 21766, 18636, 8711, 14531, 19281, 29434, 9596, 9930, 5807, 26486, 18027, 7754, 23035, 9092, 20263, 27798, 18404, 7440, 2325, 11687, 9256, 9925, 26818, 25985, 6571, 20965, 19100, 3340, 26242, 12540, 14818, 15690, 26764, 201, 10121, 22652, 13457, 3326, 14568, 21517, 18146, 16637, 11813, 21432, 25260, 28345, 26864, 17157, 4205, 17578, 28234, 13902, 29418, 24827, 21639, 25420, 11150, 2508, 12201, 8035, 28245, 27724, 5586, 14424, 6876, 3710, 12437, 6090, 6120, 29417, 12012, 1510, 4897, 10505, 21288, 137, 28649, 2807, 11653, 23248, 18327, 29428, 5035, 9853, 22118, 7539, 5856, 28756, 8960, 10938, 11670, 28614, 21656, 1113, 13627, 27148, 28281, 16518, 29008, 47, 19655, 26674, 3999, 15501, 21948, 1002, 23066, 29816, 1601, 14619, 4228, 14098, 9674, 24664, 13013, 18912, 14946, 22354, 2857, 5182, 21959, 14741, 24384, 6277, 6496, 10052, 701, 3689, 27951, 14457, 19787, 28777, 23291, 2978, 6421, 8598, 29284, 22716, 68, 213, 25593, 28576, 12136, 20854, 25116, 17855, 2915, 27625, 22979, 9996, 25302, 2974, 7859, 4929, 12758, 11772, 4610, 4234, 17427, 7795, 16111, 15482, 3650, 5695, 9117, 11438, 6916, 13150, 18058, 2224, 9925, 9794, 22483, 6311, 16521, 25262, 12290, 1183, 9606, 11661, 80, 1279, 13970, 21576, 25294, 23657, 9702, 29987, 13682, 27911, 28792, 12457, 11540, 52, 3673, 3746, 10513, 4935, 17269, 19384, 12014, 8105, 24435, 257, 25029, 1273, 1586, 27066, 28376, 1342, 9069, 21786, 14623, 16, 20224, 2057, 19086, 1551, 11131, 5293, 28264, 19310, 21303, 19376, 24192, 21265, 19301, 14088, 13202, 24920, 23394, 26169, 16290, 21212, 9234, 10625, 24268, 22138, 8715, 3416, 12103, 29073, 16845, 21111, 29790, 25962, 11773, 6761, 22103, 22374, 17536, 27326, 13997, 1420, 1304, 14705, 3913, 21943, 6963, 5572, 26040, 256, 16528, 20691, 6562, 23739, 19405, 10017, 27446, 12523, 1507, 29992, 6256, 24566, 18404, 10589, 19523, 24642, 19639, 17180, 3044, 19628, 6631, 18669, 19457, 23232, 17597, 9867, 28735, 13615, 12136, 24813, 5770, 4828, 13094, 16509, 25791, 2703, 14736, 24785, 3851, 14308, 9966, 29146, 28186, 15189, 27690, 12308, 8946, 6337, 17494, 20357, 25024, 23005, 17977, 23318, 27498, 23552, 19448, 23273, 19759, 19038, 24603, 25200, 5312, 9801, 1334, 27675, 16181, 20803, 20968, 8285, 13567, 21516, 18457, 13734, 5763, 4856, 23916, 26386, 5768, 24822, 27095, 18243, 9817, 9937, 1378, 14662, 163, 23110, 110, 8777, 9217, 29388, 26463, 23759, 16791, 3366, 22158, 14849, 22950, 29795, 14312, 16525, 10645, 26803, 98, 25979, 23969, 26033, 19600, 2855, 14164, 16169, 27968, 25026, 25623, 17065, 24887, 18295, 18077, 11802, 14519, 8404, 2209, 12305, 20494, 3821, 13590, 3494, 22197, 23314, 15146, 3540, 17994, 29110, 14583, 18931, 17915, 26067, 23177, 24394, 11399, 22895, 19016, 16926, 6999, 18073, 23992, 8797, 2155, 15380, 8543, 19235, 3286, 24239, 20029, 9691, 15952, 2542, 28002, 4972, 5401, 20670, 22035, 5977, 13140, 25078, 17670, 1882, 4291, 17224, 1339, 23491, 28910, 481, 10239, 19720, 1190, 20991, 22278, 9492, 28517, 870, 10246, 8804, 15533, 28806, 15333, 7691, 3053, 27710, 7699, 19931, 10502, 16814, 29878, 28545, 5025, 7468, 25591, 11756, 24982, 17013, 24968, 12902, 12140, 28161, 10563, 15309, 23179, 17544, 5600, 3974, 5766, 4576, 6340, 20135, 28747, 4101, 16215, 14551, 24110, 11012, 9448, 24396, 9274, 20343, 19629, 15976, 19486, 17323, 23570, 6438, 6241, 12385, 8677, 27796, 27863, 22682, 29087, 26249, 8571, 27676, 4936, 14728, 5657, 21453, 16386, 26950, 22221, 2665, 20592, 20167, 25078, 24514, 20647, 11901, 27550, 3261, 20912, 27126, 9449, 23620, 16691, 25403, 13047, 1362, 29778, 2264, 28867, 4963, 6351, 8585, 19166, 13866, 20592, 25253, 19972, 27550, 1061, 8500, 10265, 10281, 8963, 10067, 18689, 29004, 18923, 27533, 422, 8724, 23254, 6134, 3062, 12328, 14175, 8464, 19085, 1423, 28893, 1798, 26284, 20179, 5898, 19029, 8999, 22085, 8337, 16016, 22677, 13992, 11035, 6624, 4777, 11402, 12258, 18949, 21185, 23599, 173, 17512, 22709, 24593, 18840, 26338, 8510, 20744, 18611, 24787, 24304, 23668, 4010, 14867, 25633, 20931, 6817, 15383, 18341, 12638, 25799, 23212, 5205, 12940, 25325, 22891, 20291, 3032, 4060, 7933, 23732, 29535, 6425, 19375, 7874, 17223, 26161, 19235, 14893, 6618, 25815, 4286, 29905, 8541, 28496, 17224, 23996, 15292, 15170, 8665, 25703, 3106, 23973, 17492, 13275, 14220, 28640, 28926, 29941, 25758, 19112, 4066, 27221, 24794, 892, 5531, 27041, 6018, 24873, 2381, 8190, 10176, 3552, 3092, 2174, 175, 16256, 15010, 18545, 14820, 15587, 25351, 8757, 4899, 4866, 6276, 8421, 2786, 24970, 6183, 23190, 21024, 11302, 1690, 9031, 21615, 22348, 9776, 8771, 22644, 13975, 18295, 28318, 4160, 5140, 15821, 25362, 29818, 12110, 7058, 7702, 26606, 28601, 22930, 6681, 22478, 16692, 7719, 18446, 15385, 29426, 3484, 428, 18850, 29580, 16389, 20681, 22033, 4581, 3863, 944, 7674, 4690, 22782, 18892, 2194, 4368, 16425, 25286, 25083, 17598, 29413, 2259, 15561, 25709, 20727, 29073, 14032, 21434, 1116, 13044, 14395, 29776, 28968, 10187, 7232, 8547, 6509, 2085, 7512, 28926, 3860, 2042, 22984, 19927, 562, 10074, 7926, 12570, 621, 20608, 23499, 2740, 9561, 18849, 26160, 1484, 21662, 8491, 27767, 28065, 19060, 19480, 19192, 6152, 6752, 17000, 12793, 18267, 19708, 15855, 29075, 3527, 5716, 18673, 7719, 26507, 25746, 20523, 20730, 29274, 9466, 24225, 14879, 8860, 20157, 10070, 14151, 12734, 19708, 8541, 27369, 25817, 27935, 27267, 334, 1108, 6986, 5227, 29893, 4468, 29752, 22645, 24435, 1502, 22440, 12563, 956, 28908, 23224, 6054, 4351, 27077, 21353, 21429, 16466, 11432, 6325, 15894, 19823, 12422, 9715, 17140, 19014, 13130, 10332, 2028, 15627, 10312, 11455, 17, 16207, 21207, 19537, 7237, 9157, 26857, 16329, 19553, 17899, 15348, 28038, 16564, 660, 15116, 4124, 19318, 24486, 22084, 10726, 10335, 22645, 13212, 27939, 3244, 5147, 18516, 26154, 19850, 963, 25311, 13992, 22420, 6531, 9670, 19581, 4786, 2841, 8334, 18749, 9375, 4934, 728, 5564, 22200, 29054, 9592, 13891, 11793, 3282, 3407, 29900, 21940, 22941, 6870, 24618, 2234, 10017, 12608, 27690, 16555, 26981, 21566, 4867, 12250, 20081, 16576, 21689, 10200, 15592, 23543, 8545, 17233, 14294, 16303, 12498, 28765, 4850, 25562, 20096, 421, 1370, 12907, 8844, 13467, 2555, 7196, 15825, 20412, 3624, 16032, 1581, 1709, 6223, 22763, 23922, 22343, 11237, 24295, 18697, 28962, 6386, 17979, 481, 7768, 308, 20420, 8422, 19810, 15338, 21098, 7219, 15336, 17442, 3616, 19964, 9002, 9218, 25655, 27757, 7967, 22880, 3696, 11080, 13358, 29068, 18554, 5564, 20665, 11045, 11301, 2380, 13487, 28451, 3752, 24679, 29970, 13974, 15707, 12669, 15687, 12587, 2228, 19552, 22505, 17226, 1692, 21700, 535, 1343, 28749, 18958, 2592, 877, 25161, 1194, 11485, 22404, 713, 6700, 4559, 17440, 21173, 9392, 26583, 14037, 23313, 10132, 13170, 4546, 2685, 6304, 24943, 18487, 17964, 2703, 22350, 11884, 19854, 6799, 16398, 14388, 24694, 24987, 6557, 3463, 23704, 13782, 8033, 5616, 12331, 22345, 26771, 27145, 24191, 11584, 17433, 24135, 16146, 1854, 27812, 23774, 11540, 25067, 10592, 12498, 11323, 9310, 8649, 12580, 13169, 19651, 11715, 16887, 9338, 3577, 1054, 18690, 4155, 844, 1547, 11781, 22758, 15901, 15551, 19519, 22385, 10033, 24260, 860, 22308, 28072, 28347, 12074, 13803, 17276, 5993, 21160, 4038, 21168, 4552, 1630, 5541, 23050, 343, 6662, 26591, 6082, 17426, 21791, 27399, 7783, 15328, 10430, 862, 11949, 27060, 12050, 3835, 21027, 18071, 14891, 29237, 5009, 15947, 23611, 2661, 26271, 27705, 21187, 6211, 17633, 2433, 4824, 12644, 13244, 9167, 10275, 24132, 21718, 848, 13320, 11923, 1980, 3634, 10239, 7156, 28875, 12007, 9973, 14275, 4165, 14411, 7209, 19471, 7694, 27305, 1699, 14482, 19128, 18846, 24029, 16722, 17772, 10506, 4921, 3165, 15672, 26259, 15867, 4087, 21122, 20035, 22855, 1817, 17835, 6483, 20136, 20414, 14463, 12780, 6122, 11990, 28258, 18539, 16438, 3493, 15291, 16078, 18010, 21713, 14333, 12986, 5707, 23498, 959, 6156, 4252, 26563, 22300, 2838, 11477, 23040, 17597, 21456, 28883, 11466, 28763, 29260, 2957, 27290, 530, 20230, 1545, 17304, 9050, 21066, 5897, 394, 29240, 2487, 1243, 8956, 11525, 24031, 3704, 6076, 19544, 19800, 10466, 10687, 11452, 25264, 27292, 28254, 23675, 25951, 4634, 16851, 19153, 7470, 27730, 8571, 18768, 21251, 1286, 12635, 5458, 17198, 23471, 21141, 22226, 18179, 5379, 5800, 24543, 18680, 5672, 16876, 10836, 18151, 24551, 22812, 21111, 4703, 26791, 18001, 10964, 17888, 9550, 24730, 14864, 21894, 11965, 15180, 16423, 20722, 20706, 9734, 4733, 1475, 5237, 23065, 17306, 9756, 13633, 7577, 15817, 13961, 17825, 13885, 28847, 12820, 11315, 13225, 22680, 14808, 24205, 6138, 15048, 12829, 1359, 4491, 28900, 5620, 22399, 5927, 10353, 222, 7006, 13313, 28924, 13553, 17828, 26905, 28997, 23991, 15803, 25949, 1729, 18567, 18069, 14123, 6423, 95, 22902, 18251, 864, 27376, 10994, 24184, 24525, 23784, 8025, 13063, 7722, 24472, 3848, 23398, 26127, 8666, 976, 1421, 25156, 1521, 2156, 4277, 23253, 4365, 9249, 22408, 28803, 10649, 4237, 8317, 6724, 20617, 16738, 17616, 26890, 28451, 23757, 3846, 577, 4828, 16429, 20593, 294, 16098, 12315, 20107, 5025, 10301, 2491, 1884, 11437, 21311, 21388, 28513, 4189, 7837, 21642, 21079, 22564, 8084, 21015, 9067, 13533, 29937, 12245, 18835, 25193, 22738, 14831, 24242, 10831, 27780, 8355, 28444, 24120, 7676, 23562, 18318, 11972, 22142, 23161, 28178, 20729, 22598, 14547, 6180, 24786, 3340, 26483, 17435, 669, 17602, 10810, 915, 1908, 28520, 7402, 20268, 9889, 6862, 18280, 12033, 15878, 24140, 19483, 19903, 26013, 13917, 11827, 27066, 22206, 1250, 6917, 13971, 11642, 16547, 8271, 27893, 25524, 19788, 1850, 14968, 3703, 29598, 685, 29293, 29096, 21146, 8430, 12703, 29173, 10030, 12147, 8935, 17914, 2312, 27859, 23005, 14782, 8690, 23503, 18075, 24431, 3679, 326, 21161, 5014, 22918, 27966, 25746, 11865, 21615, 20479, 12142, 3890, 20770, 23979, 20267, 12863, 25525, 8156, 27996, 19753, 560, 14693, 20066, 7725, 12861, 14383, 4660, 19446, 2951, 22763, 23420, 4792, 29566, 15422, 6458, 29166, 14479, 7627, 16311, 11753, 14828, 27642, 10269, 2931, 2415, 23414, 13141, 3765, 2872, 6622, 4812, 20224, 8446, 21700, 6143, 4532, 10678, 9950, 29634, 5319, 5781, 3522, 16525, 4720, 1749, 28008, 7167, 22441, 26002, 12477, 29164, 23523, 14229, 12347, 14366, 22604, 1841, 9013, 20367, 21567, 21531, 8241, 17238, 15950, 20991, 22602, 9780, 10381, 12337, 23386, 27994, 20598, 18810, 1488, 7288, 20348, 10460, 25148, 5728, 6385, 22250, 25985, 11141, 12427, 13202, 16113, 23818, 1614, 926, 25482, 28654, 3998, 27326, 5633, 12642, 21923, 2806, 26211, 6399, 18900, 29774, 23666, 26114, 17503, 3354, 6426, 16175, 22070, 13658, 3959, 8508, 9979, 9177, 20584, 22436, 713, 29983, 27952, 5189, 17313, 17657, 22909, 12010, 15849, 21846, 3137, 23243, 7953, 7266, 26230, 16911, 3567, 9943, 17128, 7754, 18113, 11582, 2000, 17500, 25226, 24672, 27888, 16631, 29997, 27159, 15575, 27092, 14552, 17886, 18953, 15091, 19523, 2917, 19367, 1403, 239, 6402, 28647, 12374, 5263, 10273, 8521, 14879, 9140, 12731, 22900, 20308, 15555, 25820, 20329, 29567, 27367, 11006, 25011, 5261, 9186, 27726, 25683, 9943, 12189, 27685, 18211, 28008, 24802, 18323, 16655, 9244, 55, 124, 1186, 3454, 15876, 22495, 26642, 20623, 2157, 8283, 12422, 8533, 22448, 25434, 17550, 27515, 26223, 17265, 10577, 28346, 18812, 28858, 20870, 14122, 19684, 14416, 29707, 22516, 12387, 21999, 25973, 12691, 21580, 21260, 3684, 7486, 9512, 3195, 16258, 24561, 26857, 7368, 7774, 16215, 24085, 25666, 2147, 13599, 23074, 20617, 74, 26092, 28160, 14906, 14671, 8569, 2765, 20820, 15872, 27400, 14031, 11800, 19207, 3248, 25909, 11274, 25029, 153, 16041, 1493, 12978, 14962, 2654, 25829, 11070, 11815, 12935, 14460, 1054, 14868, 22772, 27567, 6972, 27463, 3022, 22140, 6458, 25745, 15467, 21843, 10545, 1092, 25593, 21994, 11979, 3140, 23430, 7925, 21493, 792, 7826, 22634, 16330, 1895, 7326, 18451, 19327, 27721, 7348, 27456, 11791, 23719, 12476, 12052, 15463, 4183, 13260, 2371, 8822, 294, 24096, 729, 24596, 1056, 7486, 20155, 27546, 19145, 12853, 12497, 16057, 13493, 8755, 9899, 3200, 4759, 22140, 19245, 587, 17644, 14752, 13896, 22576, 5231, 19350, 9523, 16815, 12194, 16329, 6731, 21010, 21095, 26151, 23262, 1500, 26970, 1481, 878, 9155, 13502, 10565, 23684, 26318, 15543, 20546, 19264, 1219, 3729, 19690, 28291, 9277, 17683, 4156, 17479, 25550, 15886, 8371, 22596, 11698, 7836, 24296, 18299, 1830, 1406, 21865, 27121, 22596, 27755, 2131, 13540, 23209, 14427, 3675, 11250, 18772, 24543, 26984, 7178, 8589, 26028, 19811, 18652, 28659, 14362, 1012, 1962, 24589, 22789, 3960, 13175, 15688, 9179, 5047, 10086, 23542, 3836, 7737, 15626, 15492, 16494, 8626, 11158, 7600, 24017, 24158, 25471, 19071, 26998, 16167, 22109, 26170, 13300, 24031, 18582, 1712, 19932, 9058, 20552, 22257, 5609, 2850, 22476, 12830, 25147, 23958, 1916, 11938, 17785, 13549, 6352, 8264, 15035, 3543, 681, 1821, 16458, 154, 9296, 28563, 6214, 24543, 6307, 17953, 8256, 24382, 19663, 28209, 9547, 26116, 9273, 2978, 9241, 10667, 20897, 3943, 28156, 21963, 5, 6443, 28355, 105, 799, 13836, 12750, 23449, 11706, 6884, 23837, 19825, 15793, 13465, 5139, 3004, 21596, 23064, 9118, 1468, 11218, 7233, 28796, 23604, 4870, 956, 13410, 14497, 13263, 3875, 4120, 17776, 29939, 7360, 27728, 7363, 15349, 17411, 16435, 28750, 24200, 15183, 28539, 20049, 14126, 20365, 18219, 6588, 8778, 15986, 3639, 12563, 23415, 6569, 24533, 13858, 16803, 16494, 12292, 24700, 24283, 3646, 678, 9898, 21508, 19025, 29977, 12012, 15845, 9361, 12539, 7850, 28001, 26769, 17613, 25315, 15134, 16380, 26399, 24260, 19119, 4071, 6289, 1884, 5372, 10414, 13299, 8407, 22484, 447, 10146, 13172, 7803, 1841, 28852, 8750, 29687, 16125, 5718, 18488, 24172, 1265, 19719, 20323, 16432, 26394, 29864, 2019, 25932, 26999, 16183, 6274, 12657, 7948, 5169, 1948, 17631, 12761, 10727, 9160, 22936, 2446, 18162, 3550, 20132, 2685, 20650, 13154, 3003, 24337, 25496, 6089, 7894, 22206, 7701, 14230, 7571, 29352, 12376, 16120, 14296, 18519, 5740, 14848, 23251, 3950, 17675, 9327, 9466, 10627, 22555, 21083, 26152, 6973, 6722, 11393, 29826, 4190, 756, 10261, 25494, 29944, 22275, 6811, 18573, 21302, 26408, 12282, 17469, 17201, 21976, 26726, 24322, 13783, 9006, 888, 524, 10182, 23878, 6097, 28041, 23417, 7408, 15440, 4513, 28838, 9050, 26688, 10839, 22717, 29316, 942, 7197, 6493, 11138, 20364, 10088, 15388, 28622, 1697, 4562, 23277, 10876, 26821, 25110, 14200, 13100, 23829, 29198, 11669, 1234, 14497, 24159, 23883, 24616, 3090, 1381, 6796, 29417, 3308, 8358, 4255, 10250, 28901, 22780, 15929, 26713, 10362, 28635, 15617, 22398, 3327, 23545, 27434, 24287, 2551, 616, 28241, 18796, 9130, 21344, 3992, 28437, 26489, 6788, 20406, 25621, 16937, 15283, 12430, 11431, 24408, 10242, 11037, 12306, 21217, 26078, 8570, 12357, 2887, 20187, 16350, 429, 19125, 12962, 22525, 24296, 14733, 11751, 19209, 11441, 7919, 25997, 29, 14513, 12948, 2348, 27146, 5326, 22426, 24602, 1314, 3261, 8060, 13269, 21144, 20683, 17205, 5493, 24195, 15058, 13292, 8, 23251, 4190, 17291, 15, 28953, 10489, 24090, 14618, 25542, 25466, 11351, 19519, 4797, 8700, 16983, 17080, 29261, 16964, 18689, 7671, 25042, 10782, 9782, 25602, 11752, 43, 16988, 27177, 13747, 20916, 3286, 25451, 6887, 15886, 5839, 1769, 19152, 11676, 29306, 22729, 24840, 396, 18334, 22376, 500, 14226, 12752, 18735, 20247, 16158, 2923, 1295, 2994, 29663, 18559, 3136, 12609, 12941, 2216, 13881, 9192, 27201, 28535, 13613, 20847, 4387, 25143, 11111, 20982, 4157, 13780, 3188, 26275, 800, 1041, 27506, 9616, 23126, 12999, 2417, 18565, 11745, 22966, 26744, 20151, 9739, 6185, 10740, 13285, 24870, 10, 29645, 3998, 22197, 19064, 14002, 4382, 10720, 9861, 4877, 9586, 3910, 12120, 3234, 12780, 26748, 17595, 6226, 5374, 2679, 16243, 15442, 11723, 27321, 16062, 11341, 29485, 2788, 6060, 11177, 28832, 25418, 16268, 9875, 20090, 12126, 3416, 24949, 17536, 14659, 7332, 5852, 14714, 28843, 8455, 3890, 6448, 10832, 21774, 298, 14371, 16938, 11487, 4392, 20011, 265, 25642, 7007, 22600, 7012, 15970, 22934, 22301, 17423, 25753, 387, 9230, 6769, 6719, 21499, 29351, 6270, 28122, 27790, 6060, 14232, 530, 29006, 14088, 18962, 14715, 17955, 2595, 21278, 14348, 12240, 6996, 11526, 9019, 18085, 28638, 5251, 9024, 22506, 23516, 20996, 13422, 659, 18794, 25625, 23224, 24365, 8411, 21706, 13203, 15756, 20454, 16420, 12667, 1704, 15161, 26298, 16898, 21933, 21488, 28915, 21766, 5693, 22845, 15177, 15372, 14613, 3948, 27264, 18254, 26874, 16420, 16864, 18813, 21001, 12231, 28139, 27203, 19714, 4836, 11803, 11644, 7724, 10528, 8754, 8170, 24209, 7512, 502, 23046, 29483, 10093, 19501, 14820, 19420, 27319, 26066, 26732, 21217, 18506, 18441, 12998, 20415, 19155, 2173, 17964, 9814, 732, 12150, 28760, 11478, 14322, 969, 15571, 3138, 7374, 29907, 10641, 13989, 3249, 19732, 22976, 13427, 20589, 18245, 9803, 27447, 29459, 26170, 12251, 4276, 12779, 23258, 13298, 3378, 21476, 24067, 2232, 25707, 14956, 22562, 15452, 8990, 3379, 27163, 20391, 6002, 6547, 21826, 18105, 25315, 19082, 10191, 10304, 4787, 638, 6242, 28112, 22382, 26034, 23531, 15738, 11410, 8347, 6685, 15507, 9337, 9342, 15733, 22088, 3238, 10583, 2498, 27554, 29497, 4984, 358, 8110, 29019, 4087, 29308, 21654, 18920, 23565, 13901, 22661, 23130, 26161, 4281, 26590, 22962, 6408, 29249, 2299, 4124, 15939, 8441, 11088, 8159, 3925, 6531, 19386, 19412, 26965, 16709, 28089, 27938, 19045, 29681, 11952, 8370, 24940, 13489, 6617, 8624, 13764, 10294, 4075, 17827, 11394, 27026, 16786, 26033, 29937, 5810, 20999, 788, 28840, 11526, 29266, 11505, 1752, 13363, 5027, 9218, 20300, 1228, 9168, 11083, 26330, 556, 12835, 2230, 2207, 7683, 15583, 26994, 4105, 9802, 28395, 14286, 19459, 24678, 18397, 2521, 26695, 14588, 4054, 171, 22951, 4196, 11371, 1566, 21140, 6411, 16408, 8263, 21073, 22146, 20733, 2595, 22603, 25877, 19209, 27624, 18323, 24228, 6812, 10460, 26036, 13154, 29876, 16867, 22359, 12471, 19085, 23210, 850, 4954, 14589, 21430, 9693, 1981, 20370, 106, 10582, 11812, 13594, 17422, 15021, 9833, 3140, 29476, 25528, 923, 6141, 18092, 18047, 5262, 4628, 16518, 9999, 1415, 7086, 7112, 11426, 26391, 25259, 24616, 16726, 7384, 24750, 21358, 14243, 3123, 19388, 9219, 19689, 4816, 12414, 17840, 8636, 5984, 1025, 25549, 19162, 13087, 7939, 523, 3728, 1863, 4045, 10985, 12505, 14432, 3887, 24650, 3771, 26026, 2344, 6577, 3821, 17694, 19700, 7772, 17250, 27149, 23270, 26024, 5275, 1223, 17259, 22548, 20011, 2782, 7585, 24771, 16423, 12369, 18019, 27803, 24556, 7146, 18403, 6165, 14627, 28632, 22517, 21144, 12339, 5086, 7219, 26901, 27153, 22239, 17944, 15550, 27892, 5231, 23818, 23532, 19488, 19259, 15193, 4625, 29499, 20553, 17530, 21686, 5002, 1824, 23943, 27610, 24010, 18864, 24392, 8825, 29760, 19571, 19357, 1020, 7808, 16111, 19671, 19261, 7675, 11246, 23023, 14067, 4975, 3156, 14428, 9698, 24300, 15428, 21980, 7350, 23947, 18772, 15291, 1894, 25941, 29904, 17531, 12024, 19871, 26481, 22229, 1150, 29085, 21266, 24251, 13866, 18159, 17086, 4740, 18283, 23295, 18257, 14574, 4959, 20661, 2228, 4279, 11516, 4133, 19516, 24512, 27045, 23657, 7724, 18517, 3020, 557, 4175, 22592, 24117, 27645, 25385, 18580, 3235, 3548, 26237, 16680, 948, 17519, 3677, 3227, 19679, 25040, 26644, 3041, 24143, 7824, 18852, 28625, 1046, 21810, 25551, 25313, 28026, 27078, 10874, 28103, 5109, 12523, 3611, 2084, 24688, 15737, 13659, 14941, 20971, 7387, 9926, 17377, 27858, 1836, 18201, 785, 14320, 24841, 6660, 28865, 22224, 14996, 25021, 28463, 11451, 29570, 13188, 11493, 9189, 26743, 19578, 14362, 25260, 29281, 9186, 9752, 26811, 12694, 15586, 3259, 28245, 14071, 15873, 13515, 15406, 4881, 15643, 28613, 5735, 22186, 16566, 10276, 5113, 21760, 749, 8890, 29469, 16660, 21237, 23869, 14957, 27552, 13968, 843, 1494, 721, 26722, 1694, 15202, 8615, 22127, 17991, 20798, 20434, 25604, 11936, 20160, 27933, 10392, 18598, 29707, 14104, 3004, 18944, 13100, 7015, 15013, 24413, 2364, 21947, 15227, 305, 429, 3791, 17685, 6618, 7868, 3829, 20793, 1188, 7464, 19670, 26602, 26950, 9665, 2188, 15772, 12143, 22570, 1998, 7752, 4606, 6561, 11266, 21322, 11750, 20573, 11267, 23122, 18484, 14409, 18705, 952, 22563, 17281, 1836, 14029, 20621, 26192, 13417, 24171, 3782, 12340, 8280, 17409, 29456, 10531, 22166, 7695, 21781, 22334, 24637, 343, 6651, 28445, 21133, 27301, 13628, 9439, 17060, 25550, 6617, 27040, 20253, 28727, 28579, 22709, 13212, 13969, 19230, 12750, 17628, 10667, 16288, 24632, 18139, 15655, 8762, 5997, 20105, 26135, 3607, 25295, 27068, 27215, 28928, 534, 13724, 10550, 5991, 23941, 27670, 22300, 21462, 24362, 22893, 13492, 11659, 4608, 7140, 17310, 2993, 20783, 23277, 9477, 25325, 26141, 21737, 2227, 4512, 13579, 1235, 29684, 24547, 5476, 27653, 17518, 29723, 25714, 17557, 8337, 9253, 10070, 13814, 4886, 11149, 7456, 8644, 9410, 9815, 2362, 8994, 29948, 12859, 15676, 17411, 25030, 7747, 6863, 12679, 22285, 1977, 29428, 10365, 15035, 26630, 29269, 3769, 13057, 728, 22823, 22290, 20680, 24377, 5521, 12064, 13441, 5592, 7504, 4365, 10615, 12621, 1207, 10051, 8780, 22307, 5505, 28806, 18777, 25454, 11879, 2559, 10289, 12041, 20441, 29656, 29915, 2944, 28414, 6266, 18878, 25508, 29416, 25156, 12733, 2775, 4870, 28238, 11615, 3521, 29845, 14676, 13466, 6118, 25727, 29233, 15315, 28832, 8505, 13167, 29845, 8605, 11940, 2256, 28000, 11148, 21320, 15294, 1300, 21443, 9206, 20315, 14571, 5024, 1543, 20014, 24934, 3230, 25507, 4830, 29182, 10355, 20354, 24799, 2148, 7575, 11616, 10850, 24178, 13697, 5831, 5310, 5079, 11425, 7468, 19069, 2238, 19467, 11577, 24910, 5910, 6966, 6167, 25669, 28786, 26710, 5584, 23672, 16442, 10650, 4338, 18986, 640, 5316, 29472, 24232, 375, 9067, 18192, 3211, 16669, 7214, 17760, 27240, 25275, 9898, 1389, 20078, 7978, 1342, 14941, 508, 24187, 7308, 22406, 17897, 1525, 14084, 18069, 342, 14922, 28870, 5785, 16137, 13893, 203, 9674, 7443, 18922, 24339, 17062, 23509, 18856, 8593, 12942, 25920, 28318, 9987, 8235, 5507, 12094, 27673, 10079, 21659, 24528, 455, 3837, 13594, 6792, 15373, 7240, 3406, 16591, 20221, 21918, 17029, 16487, 10857, 10190, 18163, 4173, 8271, 22056, 17252, 14324, 18258, 17046, 13337, 18601, 25181, 27546, 11847, 22266, 28289, 26970, 11096, 23346, 351, 9433, 11189, 7343, 15406, 15811, 12852, 22230, 12985, 23227, 11453, 24365, 8060, 16387, 7157, 19265, 3067, 28859, 27092, 27883, 24931, 21979, 25494, 7014, 27558, 5561, 6294, 8354, 23900, 16717, 18872, 9037, 23166, 21007, 15568, 24233, 20291, 6830, 24831, 19505, 28565, 26070, 3487, 28488, 23058, 26912, 14765, 13327, 23004, 11430, 26340, 20369, 163, 5235, 6427, 18199, 8119, 1232, 1906, 6776, 23153, 16402, 8935, 9835, 14226, 20024, 20902, 8973, 16599, 17386, 27518, 6933, 16727, 17552, 10244, 27899, 5745, 26029, 7531, 302, 28229, 29164, 8275, 14541, 27090, 18835, 22069, 8466, 5097, 3046, 22018, 25831, 10111, 23990, 13067, 22063, 20603, 26080, 15847, 2902, 17984, 18357, 4962, 18508, 25864, 923, 14801, 4499, 16032, 11494, 2925, 18330, 16800, 29007, 20394, 8026, 4339, 20716, 16181, 2215, 4129, 13105, 13247, 26231, 24596, 10282, 12364, 21309, 24416, 1451, 20583, 18261, 11888, 20612, 21206, 13730, 3752, 10485, 1623, 4195, 16590, 26814, 24626, 4175, 3116, 360, 2110, 4582, 12175, 11977, 13375, 28608, 11997, 8762, 25360, 28345, 25767, 17030, 29776, 27258, 22459, 1013, 19156, 23580, 13141, 19931, 4268, 20094, 13769, 27540, 17654, 8358, 1281, 1939, 2896, 24170, 14970, 2575, 20601, 2378, 20226, 29643, 11610, 1935, 22530, 10659, 20781, 12046, 5328, 2603, 25992, 10665, 18064, 27908, 8590, 3007, 12884, 19824, 11103, 23730, 27266, 22316, 22628, 9140, 4959, 19297, 11901, 4510, 27941, 457, 24924, 11207, 478, 29031, 25727, 28695, 17233, 12486, 20935, 23196, 22491, 27464, 2968, 27394, 26401, 28831, 19426, 19000, 21606, 25002, 24589, 13386, 5321, 23727, 19757, 201, 2671, 26866, 22862, 7837, 13565, 22993, 12858, 10082, 23107, 21646, 28335, 25067, 15125, 26395, 24281, 19796, 14538, 3374, 26306, 1503, 26777, 6828, 5427, 846, 15951, 29959, 20520, 9364, 20465, 1502, 12683, 27975, 25189, 6157, 27137, 4526, 29638, 26195, 12612, 6417, 4927, 17966, 11543, 2601, 26343, 8136, 5956, 4210, 655, 18180, 2939, 5411, 22533, 9902, 21504, 29393, 28196, 11174, 8764, 12408, 19337, 26433, 3495, 15406, 17819, 3644, 6506, 21218, 20628, 426, 23883, 11845, 17024, 6055, 1409, 4710, 22072, 16012, 23393, 2825, 29014, 27510, 9305, 29880, 5050, 4433, 15402, 26717, 10360, 26557, 12966, 28323, 21737, 6423, 24584, 29870, 5707, 28565, 5802, 11401, 2988, 16151, 14273, 15800, 10405, 26369, 17450, 23779, 16875, 4980, 13566, 24770, 19142, 21636, 27803, 16718, 14537, 5861, 283, 29115, 15091, 18721, 2553, 12849, 10048, 21901, 23429, 18318, 10129, 29711, 22128, 14394, 7243, 18851, 3969, 25203, 7477, 28331, 24533, 27524, 14274, 14739, 2386, 18203, 4967, 18417, 6063, 8428, 16501, 27788, 12197, 24879, 26649, 711, 27269, 739, 14291, 28254, 11501, 19494, 24497, 17568, 7336, 18620, 24055, 11931, 7920, 5552, 23835, 19810, 28599, 9934, 14529, 12240, 16295, 28380, 24972, 1003, 22170, 8509, 21899, 18933, 13174, 20714, 27265, 26700, 10315, 22234, 6071, 10640, 22957, 40, 25129, 11537, 23247, 12718, 5149, 15392, 24611, 8973, 17, 11663, 1843, 22064, 21246, 28300, 17501, 18759, 12981, 18170, 20468, 18597, 13243, 12915, 7877, 27338, 11552, 16000, 9959, 20637, 24191, 12037, 8389, 9772, 18521, 7596, 25707, 29701, 6136, 16968, 29996, 18, 7185, 23859, 4778, 11198, 3167, 7007, 15085, 13446, 4155, 834, 1740, 22279, 19070, 14633, 12132, 23200, 333, 5865, 25170, 1857, 3973, 9541, 21520, 10134, 11437, 6409, 4790, 17524, 11855, 7871, 12446, 12772, 3538, 26957, 2801, 23701, 6337, 11018, 7838, 14509, 16292, 29620, 485, 1903, 4664, 4618, 21161, 10071, 22305, 7315, 24009, 7072, 29857, 20604, 8515, 29015, 18929, 2116, 13537, 11848, 14956, 12245, 26172, 5412, 26700, 2308, 13544, 24599, 7110, 14758, 187, 2753, 17599, 1095, 2007, 24087, 7878, 4898, 21649, 18034, 14766, 9250, 26916, 2236, 29776, 28687, 10507, 14628, 24865, 16223, 11935, 9537, 11904, 24178, 20357, 26950, 7191, 10206, 207, 19105, 21032, 7974, 28696, 17580, 11417, 21566, 17529, 13707, 26346, 8501, 19248, 9059, 4392, 20977, 17649, 10529, 22123, 28240, 14052, 9800, 330, 4841, 24047, 26467, 21008, 7168, 19579, 17842, 1739, 24345, 26799, 9137, 23443, 12642, 13783, 15097, 22537, 7228, 19505, 5497, 18144, 14183, 24621, 882, 13222, 28311, 5652, 18755, 29890, 4670, 18170, 13152, 20183, 11635, 7851, 3870, 21318, 12179, 9513, 10767, 2079, 4382, 20067, 18798, 8892, 453, 27210, 10971, 534, 3795, 7629, 9461, 707, 28600, 17205, 29428, 12114, 5714, 7429, 21648, 11131, 11942, 4328, 17320, 29710, 7673, 3775, 19138, 8581, 25765, 1055, 1608, 10571, 6079, 1761, 3419, 21125, 7000, 26113, 20950, 15683, 26386, 16549, 8615, 11267, 10674, 15330, 4843, 26090, 24227, 21784, 28237, 25145, 13662, 50, 8412, 4669, 6020, 25598, 15911, 5948, 12041, 12946, 22745, 18015, 13056, 7442, 1787, 23797, 13399, 13916, 16448, 20186, 8735, 13576, 11826, 15924, 5151, 8766, 29807, 10104, 12821, 27891, 7854, 9441, 29122, 28625, 29672, 9968, 6281, 24151, 14509, 3161, 3509, 28887, 10196, 1710, 8970, 24654, 15258, 11220, 2878, 14529, 3282, 11766, 15060, 11780, 1718, 5285, 2210, 24334, 15874, 643, 9751, 2994, 8011, 546, 21050, 27682, 29839, 23492, 27706, 4488, 15091, 2598, 13900, 276, 28651, 17706, 2297, 25688, 13452, 8761, 28371, 24249, 21029, 5337, 9912, 24803, 27868, 11607, 5848, 3857, 4019, 27706, 7997, 3811, 5691, 8923, 19408, 17423, 10288, 27173, 23238, 21543, 10853, 4207, 27667, 29205, 24864, 9231, 10654, 18042, 28649, 26708, 10173, 23107, 22675, 21244, 21124, 20019, 25753, 2385, 15962, 15394, 1081, 181, 5319, 24558, 17848, 25170, 16796, 22035, 29089, 6386, 28886, 21374, 13268, 26247, 8669, 9402, 17530, 15413, 16176, 6367, 21208, 1475, 582, 22736, 20342, 27638, 18870, 9905, 26041, 7541, 27587, 25277, 16433, 10894, 27097, 20870, 15877, 25543, 8682, 1490, 24797, 28555, 1425, 29965, 1762, 800, 293, 23748, 3723, 12859, 13421, 19988, 8697, 9357, 21876, 18295, 9132, 10879, 24269, 22334, 7646, 13001, 11971, 6064, 22495, 359, 16965, 15686, 28505, 19746, 16054, 20508, 29783, 5384, 3606, 13059, 22694, 26201, 14333, 6641, 10154, 29493, 14980, 6819, 6310, 13407, 16135, 18204, 21123, 10961, 3228, 13811, 9746, 26154, 25434, 835, 2769, 13550, 6095, 17287, 19179, 2125, 13170, 4059, 9989, 22079, 18435, 28443, 21635, 22683, 20206, 18965, 21652, 24008, 23399, 19903, 6612, 16053, 10309, 28669, 15503, 12293, 7893, 17297, 16213, 17646, 12675, 10190, 13873, 28352, 5394, 9200, 4177, 13180, 2862, 8321, 24330, 1224, 18278, 19071, 26759, 19323, 12799, 9429, 24698, 11702, 10548, 29272, 19053, 8297, 21942, 3001, 22762, 22304, 24850, 8089, 22708, 27286, 17236, 10030, 1508, 24759, 4944, 23804, 19302, 6863, 2609, 3821, 27613, 6386, 21074, 2161, 25087, 25414, 24934, 24335, 10006, 26978, 17014, 27745, 5711, 24180, 9982, 885, 28768, 26680, 1473, 23188, 26943, 10050, 26949, 2554, 785, 8284, 12073, 10753, 4212, 29496, 4137, 23091, 19901, 29388, 1803, 24965, 17320, 17211, 15399, 9104, 18737, 28974, 9884, 20282, 12841, 18797, 3316, 18857, 26958, 22113, 13664, 22228, 19089, 2858, 24775, 25833, 5234, 17780, 27328, 868, 9868, 7479, 12004, 20746, 12741, 21011, 11573, 8799, 15573, 9319, 1426, 28345, 3332, 27583, 14478, 27694, 12168, 23068, 9708, 12110, 19530, 17884, 8410, 26194, 7433, 16503, 22754, 1419, 20348, 25999, 10400, 21514, 7478, 18585, 18460, 9702, 715, 17450, 2689, 9429, 29371, 26634, 369, 5687, 18332, 14559, 24810, 23477, 17010, 29562, 15690, 17214, 8160, 1119, 29303, 25920, 24289, 26813, 12807, 1208, 20528, 22532, 2160, 8788, 27766, 21962, 6697, 27260, 10156, 12266, 10522, 3352, 3549, 14700, 4855, 27345, 27770, 11846, 9985, 2640, 25335, 17303, 10524, 15904, 1583, 8588, 24306, 28201, 21244, 20956, 14172, 5251, 24569, 17462, 8002, 1470, 16774, 25836, 23380, 16084, 21995, 6045, 24759, 2181, 16240, 10001, 14736, 27167, 10338, 27118, 27866, 11052, 28258, 27851, 23013, 12709, 15303, 3817, 25665, 16249, 1825, 27114, 4751, 28675, 23480, 4145, 20950, 9166, 19134, 23308, 15404, 23278, 11848, 24593, 26339, 22892, 675, 19552, 16419, 1500, 7528, 2185, 24599, 13850, 10151, 22291, 15304, 22100, 21745, 24424, 16688, 23979, 3831, 8215, 29518, 21727, 28402, 8288, 14465, 24057, 25946, 26788, 6125, 21311, 9958, 6561, 19421, 23092, 4445, 8217, 1533, 13897, 25736, 11713, 17120, 4078, 18917, 7770, 16300, 4925, 19486, 10885, 1080, 22812, 1467, 17635, 21364, 5297, 8872, 5485, 17930, 13971, 26151, 2135, 28554, 4809, 20140, 9690, 17076, 4793, 3875, 26897, 14120, 13189, 23650, 15158, 18213, 19743, 15305, 26824, 14175, 16280, 14198, 28388, 3570, 23526, 5102, 26695, 1027, 18280, 28908, 4943, 14611, 1870, 12005, 12173, 4997, 8228, 12144, 3673, 18747, 27594, 18558, 8825, 14837, 10495, 21721, 14007, 10551, 12388, 7243, 9345, 8374, 4656, 2146, 19980, 3426, 7983, 4889, 6432, 18622, 25446, 13877, 22992, 20082, 17513, 11555, 2293, 594, 29612, 27177, 28156, 4134, 27745, 3225, 26655, 11993, 19468, 17836, 29036, 23629, 7181, 11460, 11502, 19074, 13205, 17360, 13514, 24296, 487, 5003, 1115, 4538, 12481, 8495, 17597, 12636, 29781, 28613, 29269, 21354, 28740, 587, 21370, 9688, 8881, 14725, 26324, 19061, 8235, 28696, 25036, 17253, 10779, 22062, 9874, 21283, 10077, 17138, 1299, 8183, 8504, 25944, 23502, 29940, 13062, 27613, 25896, 5544, 6606, 19515, 15152, 21634, 6075, 25724, 29019, 7394, 13422, 14051, 23667, 12921, 25893, 24587, 14525, 17046, 21794, 10354, 196, 12251, 23690, 27732, 29459, 15524, 8038, 11094, 24773, 24228, 3804, 20368, 8094, 1948, 2179, 16645, 17162, 4162, 28468, 29123, 4422, 14926, 20242, 8338, 1647, 10677, 23775, 29159, 14222, 19, 22113, 6071, 26612, 18857, 17185, 29814, 11552, 7385, 28775, 19125, 6924, 10321, 5815, 15931, 22121, 8270, 21110, 9860, 11540, 28825, 1885, 24640, 6784, 24279, 23980, 8781, 29269, 17129, 19072, 11168, 27671, 26001, 4005, 17936, 29564, 21562, 11788, 26994, 9990, 3337, 1733, 19023, 28901, 6070, 13101, 6622, 4971, 13488, 1500, 27747, 448, 6370, 23651, 11926, 15066, 13429, 28406, 21106, 11606, 14489, 16970, 13594, 10986, 25480, 25354, 12053, 6608, 13161, 6564, 18589, 24512, 14691, 29886, 27743, 28715, 14081, 22595, 3724, 2421, 27237, 19463, 24796, 10138, 13304, 19054, 19424, 14414, 28843, 13992, 27065, 11831, 12263, 7316, 14016, 23768, 24055, 26374, 2946, 25386, 21858, 16210, 14548, 27267, 25569, 3025, 13165, 10175, 11083, 27767, 5698, 5213, 5834, 21342, 17952, 17592, 4262, 20326, 24802, 19275, 7400, 22988, 14867, 28130, 26717, 7675, 17639, 27090, 21630, 19359, 6600, 7579, 16693, 7174, 11873, 16609, 5251, 22848, 5943, 4869, 1765, 12407, 6559, 22687, 881, 26449, 29586, 4278, 11531, 2027, 17609, 23746, 6869, 3201, 15996, 2573, 14390, 23444, 22240, 27570, 3687, 379, 28112, 28575, 1289, 11961, 13964, 7180, 22246, 24131, 21049, 15164, 17349, 11507, 22622, 8514, 11333, 8928, 5704, 16286, 24527, 13775, 15421, 8280, 11260, 22228, 551, 19757, 26885, 7578, 8165, 29657, 5953, 10878, 26289, 21627, 12559, 27904, 19956, 11140, 6916, 21424, 5569, 22848, 29651, 27003, 2557, 11380, 6464, 17764, 18894, 16642, 7570, 7071, 18380, 17376, 11020, 6198, 5263, 25105, 26232, 29864, 16778, 16176, 245, 23216, 8616, 15317, 27625, 19335, 10795, 6675, 9571, 25536, 8892, 3822, 14040, 29025, 3773, 4049, 13466, 20002, 24557, 13052, 28809, 23939, 8061, 28658, 22573, 15477, 25345, 16591, 14013, 22088, 10371, 10682, 6525, 15848, 14685, 28843, 22415, 18940, 18276, 2668, 174, 13206, 8848, 7868, 29469, 22982, 12865, 19184, 3845, 16753, 4492, 8688, 12562, 24511, 15932, 12838, 6536, 29445, 14799, 6161, 28247, 20815, 3688, 23628, 15329, 1762, 22270, 16570, 6838, 1247, 6311, 29102, 16615, 6051, 25280, 20712, 16609, 12077, 16040, 17959, 13254, 27456, 5192, 4496, 10205, 2270, 6951, 21115, 6355, 26545, 18274, 21842, 1429, 23666, 27184, 2750, 18298, 2626, 6269, 4742, 388, 672, 14691, 2860, 546, 23951, 7588, 4735, 2847, 23815, 12725, 23637, 29038, 19735, 18960, 11913, 4956, 5964, 1370, 29433, 8182, 23216, 13745, 9181, 22153, 27709, 14178, 10608, 29027, 5272, 3100, 19514, 14270, 7763, 15024, 10979, 17593, 2324, 13350, 28696, 7364, 27192, 6156, 16949, 6280, 8478, 28608, 28394, 26057, 17785, 27867, 20474, 21346, 18333, 21927, 1589, 8708, 29873, 17968, 20223, 18767, 25183, 17807, 11548, 21769, 25336, 28116, 28706, 21800, 22853, 4445, 24755, 24928, 14991, 24153, 400, 8078, 14500, 26072, 27368, 28358, 21193, 8568, 3512, 7294, 7249, 26680, 12163, 27884, 20266, 11027, 27792, 17212, 6388, 2563, 2031, 4682, 1750, 28088, 135, 6812, 17010, 17216, 23402, 18794, 6424, 24481, 28026, 21301, 22243, 2311, 25575, 20547, 19833, 16340, 14521, 1876, 6479, 19619, 13715, 27038, 28807, 1052, 13419, 3952, 16040, 17092, 29778, 8975, 28598, 15520, 20743, 239, 10622, 7033, 27542, 9270, 20896, 15921, 15762, 17769, 17487, 9624, 7416, 27901, 12398, 24673, 9470, 5680, 10106, 28512, 16522, 2401, 21575, 26124, 14964, 13288, 26311, 5892, 28678, 7818, 29943, 11896, 3302, 5219, 22910, 13124, 27546, 23274, 27042, 15758, 23800, 22577, 29127, 22684, 5821, 29795, 4142, 4620, 22682, 25542, 4847, 4177, 29038, 7778, 7535, 26770, 23702, 14993, 7541, 3024, 29526, 22944, 27029, 5170, 12250, 13274, 4394, 10217, 8768, 10087, 9506, 19333, 2568, 17843, 11338, 3646, 29925, 27918, 29460, 16358, 4025, 1193, 7238, 11716, 14544, 16218, 22678, 18462, 16146, 21874, 14350, 3468, 12711, 22716, 24943, 27454, 17680, 17152, 23540, 13731, 22238, 10520, 771, 14591, 19683, 24237, 11207, 222, 14355, 1948, 15542, 12624, 23762, 15823, 16604, 2981, 8452, 9919, 17194, 13965, 20359, 18697, 10407, 29136, 23869, 17607, 15793, 16132, 5519, 2943, 2361, 9484, 7552, 23545, 28917, 10416, 9124, 22469, 21553, 19410, 26895, 16737, 6566, 18325, 6572, 4833, 17439, 8988, 3264, 14121, 13227, 28826, 24038, 23257, 29557, 3670, 13150, 19065, 2850, 23951, 12119, 7920, 27540, 13722, 360, 14232, 6176, 4483, 12616, 15796, 28279, 17694, 2503, 1678, 21598, 17652, 7246, 7800, 15760, 1862, 19205, 19680, 23509, 27545, 23349, 18637, 20163, 17641, 18726, 23164, 14678, 2880, 1789, 16323, 24197, 28460, 9633, 4143, 13712, 27638, 21348, 3055, 5209, 7926, 1600, 10218, 23553, 18338, 14350, 28756, 21689, 11648, 8663, 8763, 9202, 20452, 14794, 10268, 18200, 19204, 9357, 24971, 28578, 9934, 814, 11788, 6144, 904, 11818, 23008, 3456, 2754, 2405, 22081, 11520, 20218, 26593, 13614, 23357, 17703, 1956, 17407, 6596, 2745, 21868, 2459, 23878, 11984, 6391, 23574, 2472, 17393, 15155, 1320, 5188, 29337, 23445, 25212, 12934, 19193, 693, 5011, 19565, 12104, 1736, 4511, 9631, 21386, 15241, 21910, 13565, 10463, 5972, 3953, 7513, 12890, 1649, 9025, 5128, 24276, 28520, 17146, 19020, 25491, 9634, 19342, 1278, 12560, 6712, 26705, 27486, 26214, 8692, 13252, 26642, 4923, 2726, 19874, 25244, 11369, 22743, 16820, 234, 21984, 20648, 8704, 24901, 20311, 25179, 17258, 235, 7902, 27338, 17058, 16654, 21518, 22235, 13170, 16302, 2333, 13301, 1251, 10728, 21551, 17536, 23938, 1030, 5807, 1803, 4301, 2700, 18733, 5759, 13627, 10292, 24727, 9183, 4076, 7094, 20868, 21720, 19276, 6471, 27343, 26820, 11333, 24140, 26294, 13983, 17622, 15417, 10657, 13610, 19203, 13470, 3740, 9638, 17789, 7071, 22870, 29382, 21, 3957, 18447, 15876, 12110, 16758, 21571, 27408, 3339, 12855, 9570, 20072, 11086, 4456, 25313, 19978, 7282, 12934, 26135, 41, 22860, 12215, 17270, 15941, 6236, 7115, 14194, 21306, 27045, 13300, 28115, 11245, 20363, 26321, 16913, 10234, 11282, 773, 16140, 16581, 509, 3611, 10391, 27527, 29019, 9315, 25508, 5082, 13443, 939, 18168, 23843, 14486, 5478, 23766, 18292, 5813, 8145, 29722, 9892, 17777, 13531, 15318, 3264, 3842, 22062, 18739, 12097, 14459, 17584, 14151, 7154, 1498, 2785, 3450, 21803, 27551, 26594, 18423, 812, 3035, 7057, 17432, 8504, 6147, 1858, 4987, 16141, 8349, 20837, 24994, 27257, 23765, 5603, 28999, 19793, 24834, 9555, 9344, 17623, 19828, 24509, 22931, 25588, 15776, 13608, 6347, 29613, 24005, 29452, 5297, 18669, 15107, 22920, 7121, 3113, 2239, 5510, 6331, 5314, 3296, 6168, 23572, 8384, 7950, 27093, 9526, 158, 1913, 10568, 13937, 8600, 29, 23458, 9696, 28230, 2567, 18475, 19803, 24856, 26789, 13266, 22448, 22452, 21585, 648, 9041, 13952, 13611, 25449, 11646, 10718, 27426, 8296, 17704, 22785, 8191, 28734, 18193, 9874, 22896, 6472, 10757, 9399, 1244, 16312, 8745, 3609, 12137, 1541, 17182, 1359, 15544, 22639, 1853, 26047, 27346, 26210, 28963, 28380, 21675, 19084, 24088, 28501, 23160, 21759, 22381, 17031, 6998, 10154, 14153, 6995, 25328, 19072, 10151, 2536, 13655, 17486, 9473, 5988, 22893, 3375, 6288, 89, 21332, 24474, 9981, 4567, 14850, 28700, 14587, 12027, 2449, 19757, 14785, 3904, 5849, 27025, 6101, 19841, 12549, 20438, 2854, 13204, 1820, 11665, 14805, 23125, 104, 8945, 2032, 18873, 16527, 1814, 13883, 25162, 24676, 18525, 26233, 2830, 2529, 13162, 12594, 27259, 14271, 28207, 21435, 26507, 24361, 5689, 720, 17701, 8270, 20431, 23759, 3881, 5867, 43, 7238, 9752, 26254, 5901, 4165, 21154, 15957, 6682, 27685, 10681, 28039, 16481, 13067, 3045, 12255, 11238, 16748, 21520, 24003, 908, 8137, 13134, 7637, 8980, 4294, 5840, 11966, 7076, 25026, 12419, 10561, 20729, 9986, 3926, 460, 14149, 12379, 14364, 2943, 13717, 29191, 21219, 19333, 3018, 10784, 24299, 6955, 25951, 4331, 769, 11536, 4626, 1855, 20839, 775, 29232, 11831, 21774, 10308, 24534, 22199, 7544, 18996, 21397, 3410, 15606, 1716, 25315, 22567, 18727, 25058, 13658, 2511, 6304, 9768, 23778, 6660, 4728, 29385, 24714, 2532, 26578, 18999, 11554, 18425, 16088, 5774, 5333, 15998, 26944, 28183, 27510, 20968, 4647, 9567, 25111, 221, 4462, 12184, 12766, 28355, 10928, 24233, 28363, 23543, 23207, 26745, 1118, 22465, 16308, 16524, 15499, 3567, 15663, 17229, 16491, 20640, 27857, 22789, 27751, 1537, 13534, 28961, 20082, 19044, 26576, 25179, 22040, 11678, 10428, 1944, 1554, 23476, 20831, 11083, 22557, 8966, 3037, 29230, 24951, 19710, 1162, 19547, 534, 139, 17492, 13889, 16519, 18118, 1733, 28870, 23417, 7020, 3415, 21431, 8055, 4609, 23963, 20796, 21580, 11673, 16240, 21228, 16051, 16149, 29537, 5418, 1581, 29800, 19728, 8093, 15259, 3759, 15094, 16665, 14964, 19894, 24584, 7286, 29627, 27353, 29802, 26645, 7968, 15990, 15566, 29057, 7926, 3752, 5504, 12928, 14528, 2346, 18369, 24244, 18556, 1616, 24466, 17299, 27059, 4587, 28404, 26360, 5925, 10482, 941, 23112, 17230, 17003, 21395, 26845, 21634, 19717, 9254, 10674, 11118, 10404, 492, 14352, 8260, 25249, 10508, 11720, 14785, 16837, 9823, 26231, 20362, 11273, 2117, 19310, 26204, 16928, 3343, 4782, 2844, 24174, 26647, 2190, 4831, 26106, 8100, 24457, 4449, 28350, 13887, 10242, 10908, 4932, 2684, 4304, 7106, 25258, 8600, 1748, 29431, 22257, 3945, 18283, 17612, 736, 14103, 4722, 24744, 28049, 13212, 19564, 9621, 5222, 8682, 28848, 837, 26069, 5174, 13548, 17414, 20610, 21392, 25492, 1150, 7180, 15716, 10681, 6444, 29790, 29463, 26022, 17275, 15311, 22652, 27629, 14185, 28134, 6071, 22337, 7358, 24098, 10113, 6280, 10799, 22651, 1537, 25293, 5708, 6777, 25957, 26879, 25351, 3616, 15337, 6566, 21577, 20424, 4974, 9749, 27687, 13958, 13392, 26510, 3919, 2295, 14916, 14955, 12977, 13360, 23560, 4476, 11402, 12736, 5796, 22131, 16418, 7647, 16446, 3460, 20428, 13740, 948, 21616, 21027, 18207, 4009, 23136, 18708, 11179, 18158, 2560, 22907, 3072, 8528, 29559, 24125, 15478, 10132, 19515, 9482, 9827, 9198, 10716, 21256, 1406, 19298, 17157, 377, 7187, 4266, 24470, 15179, 16530, 6094, 3717, 29769, 22791, 17696, 17678, 20905, 24392, 11181, 16460, 2179, 7741, 6901, 7204, 1765, 17758, 5986, 12163, 29095, 14570, 17456, 17235, 25864, 9515, 3581, 29592, 29189, 18175, 16162, 4995, 29226, 14923, 1915, 21749, 5247, 3871, 4911, 12619, 14400, 26555, 12320, 15081, 3646, 19800, 27312, 10790, 11751, 9256, 29356, 639, 29306, 3359, 29497, 4004, 7500, 13015, 13214, 19007, 1024, 21550, 28106, 1221, 9614, 11230, 18654, 4696, 11662, 22929, 19722, 3801, 9961, 2704, 21121, 369, 1174, 16888, 6692, 8886, 11672, 18890, 4958, 16392, 27518, 2457, 29425, 29670, 5143, 3279, 27636, 27025, 5314, 3441, 28367, 8806, 29446, 1641, 29267, 12738, 1250, 25562, 15893, 26952, 19941, 7994, 16066, 7757, 16543, 27420, 8173, 526, 11831, 18486, 19143, 12403, 435, 6516, 29898, 7355, 26172, 27198, 10550, 24573, 21434, 2195, 7761, 23546, 21524, 7290, 16197, 20993, 25659, 22711, 10843, 19596, 14248, 26665, 26792, 7915, 10807, 25034, 27074, 19140, 20830, 6840, 6812, 16463, 4540, 26459, 23447, 10582, 4256, 21125, 17198, 24626, 26434, 23031, 273, 19294, 25700, 1966, 5349, 1310, 6277, 25868, 3817, 26944, 17360, 27115, 6514, 8513, 12979, 27999, 3483, 10044, 9081, 24854, 12332, 19072, 24276, 26029, 23930, 23806, 12692, 22402, 12057, 15693, 4786, 4917, 5777, 15556, 27678, 1270, 21881, 12228, 18368, 3619, 29933, 27764, 21559, 9442, 5700, 17577, 19792, 26490, 18784, 15632, 12964, 12758, 29876, 24906, 14469, 675, 7003, 13084, 2242, 3049, 13354, 5769, 25907, 6533, 1289, 2212, 13769, 5063, 11917, 9213, 3505, 1186, 25066, 19288, 22205, 11067, 2872, 11557, 21451, 6438, 27243, 23902, 14755, 23977, 28398, 5983, 28086, 12830, 5121, 3103, 3633, 21423, 21498, 12955, 28484, 22563, 2773, 5998, 25277, 16042, 17061, 24034, 10875, 11284, 14295, 24294, 3298, 9988, 2315, 3048, 3069, 7022, 21041, 5108, 16169, 15169, 8929, 28873, 10937, 4758, 17224, 20605, 25747, 21089, 2118, 10165, 17642, 9446, 7806, 6471, 24482, 11178, 28504, 8246, 17279, 5829, 3221, 19433, 8576, 25762, 9916, 9927, 8459, 11815, 10375, 5041, 8759, 6378, 16451, 18659, 8053, 718, 13710, 3476, 12928, 11555, 3612, 6163, 3790, 17610, 26188, 4733, 7101, 10159, 18065, 8316, 6956, 25158, 19321, 19234, 6787, 4105, 18421, 28748, 21363, 18847, 1622, 18330, 17686, 21462, 9390, 13786, 22458, 21104, 18286, 21183, 18358, 3422, 415, 21611, 26893, 29074, 27894, 3335, 23764, 4519, 28142, 24997, 5001, 3582, 17172, 28514, 27287, 16118, 579, 15736, 7977, 25969, 5761, 28509, 12874, 3014, 12897, 29659, 7257, 20917, 3929, 10112, 25065, 24666, 12047, 2246, 17431, 8305, 19573, 6750, 22048, 5042, 4605, 18971, 10258, 29876, 15200, 9312, 3404, 2648, 9884, 23930, 29489, 24487, 2218, 22491, 6289, 17699, 2229, 8773, 14317, 23802, 20277, 13856, 1395, 14471, 21478, 10711, 24312, 7529, 12642, 22301, 11260, 5618, 6590, 12060, 26025, 21887, 7211, 10838, 22985, 24129, 7655, 9535, 15577, 9242, 10829, 16446, 24683, 1907, 18272, 5535, 2060, 11023, 3125, 1620, 29215, 2601, 8248, 19423, 14468, 24311, 6328, 27762, 24402, 8107, 29172, 19970, 7711, 20883, 9228, 15527, 11947, 2723, 9976, 15815, 17335, 24084, 25321, 12303, 16044, 19582, 21540, 197, 17951, 13297, 11648, 5961, 28946, 3426, 19537, 4078, 21075, 2919, 22176, 27785, 18350, 9181, 26751, 21081, 28092, 11569, 26658, 26048, 25510, 693, 27456, 362, 16143, 27825, 3923, 6712, 13969, 9785, 13183, 5756, 13610, 21075, 4713, 18840, 20219, 24111, 26526, 6356, 6817, 14933, 23774, 27970, 26352, 13964, 13695, 23622, 17210, 27172, 29368, 5310, 15576, 8750, 25083, 1929, 27714, 28647, 5443, 15568, 25886, 21687, 25938, 3424, 26872, 4427, 13492, 7302, 18706, 12022, 13162, 9911, 865, 8588, 23403, 17062, 7957, 5533, 19572, 12583, 2731, 17908, 29202, 15933, 10104, 9964, 26961, 20249, 11739, 14817, 10884, 29420, 15414, 15797, 26865, 20656, 17095, 10366, 25976, 20371, 15543, 16694, 21359, 16726, 21671, 23821, 21535, 27414, 16547, 19342, 16955, 4757, 2709, 27562, 2625, 11531, 29399, 6034, 5434, 8063, 28066, 27061, 27344, 1608, 25061, 3898, 13097, 7598, 15603, 11298, 5610, 3081, 15708, 12017, 9580, 16874, 13072, 10379, 2695, 23345, 21190, 28818, 16187, 12544, 25329, 17100, 16800, 15203, 14599, 28758, 10996, 21714, 27332, 26253, 17303, 26916, 24306, 2299, 243, 4277, 19219, 13862, 6291, 8107, 7696, 26479, 246, 9057, 1066, 20542, 19322, 3176, 14024, 28783, 14808, 21587, 23804, 16559, 15061, 21010, 10089, 26448, 15010, 7728, 1847, 15582, 3558, 1003, 18223, 24577, 21456, 22542, 27890, 11677, 2748, 4813, 8277, 19342, 12944, 9830, 27620, 12997, 10083, 12751, 20964, 26073, 11791, 25744, 809, 22369, 14232, 10652, 28888, 21501, 16820, 20353, 7216, 29713, 24518, 8341, 13706, 14177, 13096, 19076, 23950, 1700, 4550, 16349, 10612, 785, 13841, 19664, 1077, 10437, 1548, 165, 22958, 24400, 17321, 20130, 10188, 25725, 6754, 15538, 15746, 20644, 20992, 16977, 3618, 15221, 9309, 24435, 23942, 24981, 9875, 1583, 23773, 13644, 12256, 15673, 12912, 19279, 12943, 7588, 18586, 18609, 11050, 1912, 23982, 21445, 26557, 22482, 8050, 27958, 9461, 24520, 15696, 22480, 25752, 2915, 24230, 19931, 9416, 13301, 6274, 17730, 10172, 8526, 24893, 9422, 6264, 21067, 25579, 21297, 23672, 23994, 7837, 20184, 24483, 7459, 1154, 2087, 22091, 25061, 22270, 25675, 21541, 20322, 26105, 19699, 22684, 22855, 9375, 26844, 19676, 22499, 23424, 11013, 776, 27670, 17291, 27304, 14444, 17834, 5469, 19205, 29349, 20882, 6240, 19786, 4265, 15628, 23068, 1617, 15939, 4094, 3523, 27909, 443, 15282, 20756, 15614, 19488, 16195, 3749, 5206, 1406, 16765, 14471, 23985, 260, 5292, 9997, 12519, 29249, 28809, 24596, 11610, 25391, 16252, 17979, 15288, 3354, 11982, 28431, 17599, 19128, 1520, 23918, 10300, 29720, 4110, 25585, 3270, 11372, 6055, 21135, 149, 25362, 13939, 4288, 2633, 17416, 8441, 27687, 12616, 2755, 9545, 12507, 10172, 13938, 7459, 4326, 28046, 15188, 22717, 12571, 527, 26348, 25606, 6595, 22703, 10573, 15772, 5888, 25361, 14875, 22187, 15819, 5480, 22646, 10314, 21988, 21877, 24928, 366, 10833, 12523, 7818, 11003, 11719, 16338, 5301, 5106, 23805, 23481, 22848, 21926, 28998, 24849, 5547, 18509, 12621, 6310, 14065, 25660, 24506, 13243, 638, 4559, 25, 27749, 3587, 4702, 9000, 14048, 29482, 26570, 20666, 13777, 17044, 12183, 29037, 12527, 466, 16398, 20269, 2907, 13396, 21401, 16728, 2292, 25543, 1854, 23570, 21146, 27940, 15286, 5399, 24215, 78, 12668, 7233, 28231, 623, 5098, 29405, 15232, 2482, 7846, 23394, 1017, 22607, 16396, 8936, 21097, 16814, 6660, 21470, 16678, 22848, 11415, 18525, 4596, 20085, 7551, 5740, 9616, 10075, 1016, 14380, 26223, 24477, 22751, 28382, 29157, 16276, 28533, 18725, 13789, 11324, 14401, 20265, 6850, 23831, 20484, 3626, 3493, 9938, 18551, 17991, 27477, 8147, 20821, 21098, 17426, 20560, 17206, 10943, 9641, 8440, 23052, 1081, 2582, 8518, 7865, 13331, 23188, 22031, 16060, 17447, 9783, 12572, 11213, 7572, 6546, 16807, 4088, 26000, 7728, 20433, 20005, 11131, 27028, 19904, 13687, 15044, 28920, 19837, 29247, 20710, 1871, 17499, 20535, 22176, 8908, 27416, 12558, 5294, 3834, 14826, 22777, 29230, 16821, 14355, 3442, 20301, 5920, 6091, 17699, 8960, 22228, 7122, 29323, 5706, 2591, 25072, 26423, 11829, 7087, 21453, 14663, 26835, 1746, 15338, 15566, 26205, 17956, 21082, 11259, 28576, 4680, 5956, 21917, 13349, 3529, 15650, 6547, 5994, 2370, 15053, 19902, 24447, 3714, 20190, 18630, 12490, 11121, 9420, 3800, 1427, 18556, 10567, 17240, 15308, 22573, 23364, 2345, 5889, 9706, 20287, 28229, 28097, 13551, 20083, 4768, 8376, 4128, 23338, 2671, 25767, 4383, 361, 3250, 13535, 16560, 12967, 10840, 19512, 24484, 3838, 19414, 28562, 29421, 17322, 60, 22207, 27934, 19867, 13241, 741, 6057, 26656, 24263, 9605, 15726, 4492, 3970, 517, 3108, 12447, 17219, 15539, 13340, 3043, 29887, 24778, 1962, 26554, 14228, 11779, 3744, 26506, 19933, 10736, 26002, 8089, 28479, 11674, 3937, 7036, 9632, 10255, 9601, 6146, 8062, 20572, 16737, 21303, 19547, 6397, 9837, 25126, 13583, 27891, 22340, 7742, 18526, 5573, 9309, 13143, 1906, 23927, 16434, 27339, 17091, 23033, 3856, 4940, 4224, 21485, 29665, 13808, 26832, 5078, 5994, 27905, 19200, 28132, 8416, 2964, 332, 17152, 4691, 2725, 18964, 28705, 15281, 14293, 28192, 20497, 18698, 13414, 19912, 23839, 14489, 13778, 6457, 20839, 29501, 25286, 26101, 9467, 71, 17456, 22909, 5557, 15198, 8619, 10075, 14411, 22285, 17589, 18080, 14753, 2618, 11297, 16126, 27719, 2563, 12077, 29036, 11488, 23951, 10597, 26470, 15749, 22392, 21414, 6938, 17569, 21971, 21846, 6164, 1410, 4472, 19546, 19693, 18096, 9667, 2599, 8189, 14295, 13941, 14069, 29875, 29583, 27708, 12567, 25598, 11628, 23985, 11178, 6066, 25712, 9807, 16922, 12478, 827, 21796, 13888, 114, 14121, 4557, 24425, 14468, 3560, 1732, 16783, 14351, 4034, 27411, 21931, 22920, 19463, 13683, 8652, 1228, 11799, 20254, 16616, 12105, 19583, 23854, 9814, 15071, 9758, 22212, 17723, 15283, 4143, 8794, 3558, 24175, 3075, 9159, 23780, 15011, 29099, 18785, 7791, 27401, 29084, 6696, 26390, 18760, 10032, 6329, 3844, 20555, 8429, 29913, 13582, 25854, 7047, 13084, 1844, 19656, 7980, 13185, 25631, 7796, 28846, 15919, 17824, 15649, 26275, 7095, 7426, 12366, 10346, 3398, 11794, 21825, 20908, 8466, 13267, 125, 8989, 8907, 9057, 8995, 2837, 21068, 25974, 22244, 2983, 10528, 20638, 17137, 10321, 21820, 1589, 22488, 6956, 22598, 14174, 19285, 4225, 3968, 16503, 25287, 8070, 17689, 3707, 1501, 21703, 176, 28387, 18616, 15024, 16128, 17161, 13300, 21554, 22119, 2712, 27931, 18167, 11975, 14017, 15259, 13422, 3891, 4210, 16600, 8608, 13255, 18780, 6177, 29538, 28400, 1227, 6317, 11938, 12230, 1342, 4254, 7129, 12030, 5773, 26509, 29385, 619, 10344, 5512, 1927, 22168, 27623, 11005, 16548, 23974, 3473, 29038, 10486, 25295, 7258, 27295, 19541, 6583, 17876, 7434, 21309, 9231, 12945, 10641, 22954, 2135, 829, 12033, 15207, 19750, 5230, 5001, 849, 13532, 6603, 14342, 29580, 22550, 69, 29858, 23285, 22918, 4184, 13591, 523, 21267, 21439, 12803, 9171, 8823, 10757, 19201, 25319, 29154, 9644, 13753, 20394, 10236, 12383, 17839, 18454, 12167, 22113, 22112, 8744, 21451, 13510, 5813, 1761, 3189, 21430, 748, 23145, 12046, 4829, 4413, 22756, 9104, 19389, 21727, 29391, 12300, 15534, 24547, 22011, 3869, 17589, 13823, 20681, 18266, 2623, 22783, 8763, 17266, 21725, 24922, 12883, 6856, 5937, 22867, 14735, 16160, 9081, 24791, 7154, 17803, 12101, 27892, 8831, 21135, 841, 15064, 15397, 10756, 434, 19878, 24687, 28679, 2249, 21845, 8048, 21812, 8264, 4246, 29311, 11118, 17142, 22105, 4869, 341, 17126, 23794, 5341, 26268, 2932, 22463, 8612, 19331, 9638, 28625, 26122, 15294, 11750, 12060, 21101, 28392, 22473, 4362, 20103, 9878, 15020, 21003, 6626, 13623, 7126, 20797, 18022, 4161, 13177, 29990, 415, 6833, 8753, 18333, 28921, 2115, 292, 2017, 26732, 21594, 5728, 17829, 19028, 10771, 21368, 23484, 24646, 21592, 20324, 1861, 3746, 23390, 25302, 20540, 22560, 8730, 29031, 22269, 17827, 29095, 25948, 29338, 11836, 26132, 11860, 27164, 3282, 15562, 28022, 9421, 24942, 13091, 21040, 14283, 17815, 14304, 28087, 4346, 2563, 27233, 14390, 18219, 24533, 29742, 22388, 22411, 19268, 8161, 29884, 19317, 6735, 10928, 25505, 25256, 9769, 1129, 14934, 28797, 28790, 12060, 20344, 14262, 18892, 6300, 28198, 8126, 5580, 23448, 111, 1148, 3396, 6955, 23285, 7415, 28341, 3901, 13501, 3306, 427, 20264, 7153, 1795, 632, 24523, 24989, 17844, 21398, 12006, 1650, 9786, 3973, 5960, 11925, 14101, 7501, 18789, 12166, 21224, 26932, 27014, 13185, 8555, 2276, 7069, 29206, 16650, 5945, 18953, 8234, 20723, 12627, 27215, 11254, 9868, 2828, 20267, 12374, 29991, 26761, 14103, 14271, 19, 23353, 10008, 20755, 7034, 6477, 28476, 21455, 1760, 15268, 6455, 26239, 16521, 18667, 23162, 18074, 13157, 9172, 18205, 21189, 23827, 7851, 103, 13871, 18525, 19893, 5681, 27519, 5004, 3723, 310, 15101, 19826, 26399, 11881, 4445, 4897, 14764, 24622, 4042, 57, 25327, 18168, 25518, 6791, 11090, 11700, 9278, 592, 3980, 7172, 23686, 4576, 20850, 14073, 11681, 20515, 8431, 6396, 28346, 26967, 11154, 11307, 26130, 13195, 11417, 21703, 2682, 10136, 5264, 26427, 29485, 19973, 12223, 11753, 7280, 4648, 29836, 22237, 27676, 4742, 27473, 13840, 4268, 28388, 23092, 23448, 18226, 16938, 3897, 17563, 11348, 21788, 13815, 23831, 11747, 7319, 28187, 22642, 25307, 19965, 6350, 1709, 13090, 8779, 2261, 13309, 5281, 26758, 26975, 71, 23633, 1379, 7808, 1626, 12673, 24972, 10159, 25594, 27901, 5394, 26519, 19324, 9792, 17254, 27622, 8236, 10344, 18034, 1937, 20750, 24194, 28969, 5703, 931, 7236, 18324, 14323, 8752, 29240, 14763, 2243, 10332, 879, 12101, 24073, 9846, 20017, 20996, 3635, 22497, 24301, 25058, 24006, 25696, 20050, 9344, 6537, 8657, 5693, 27380, 28801, 14904, 15285, 23480, 18164, 6685, 20291, 11583, 27373, 15264, 16600, 7919, 13161, 16283, 14247, 19868, 9012, 5442, 10948, 15560, 8800, 28603, 24301, 23046, 16483, 28113, 7616, 3729, 10889, 17187, 20838, 7177, 19786, 12115, 17092, 27565, 21902, 13216, 5959, 10459, 17315, 19919, 25650, 27159, 8834, 3627, 15415, 25932, 28515, 26709, 17384, 372, 14740, 9342, 8320, 12483, 28867, 6171, 18651, 29158, 6364, 24716, 12441, 29781, 24483, 22600, 19235, 3242, 20010, 1382, 27090, 8879, 22094, 1581, 6588, 18000, 11505, 18527, 25766, 13070, 15041, 14474, 14984, 29761, 1032, 27201, 28884, 9265, 28491, 2106, 24227, 20165, 11277, 29348, 25686, 2233, 8259, 23518, 27333, 22666, 24391, 29809, 22381, 23559, 26669, 6508, 19318, 29211, 19025, 21103, 29787, 9490, 4181, 12384, 27630, 14811, 21009, 6820, 13813, 7302, 10523, 10412, 28057, 16878, 25058, 19791, 1398, 8654, 12043, 13816, 29547, 14893, 16428, 16782, 12189, 10689, 27502, 10247, 29831, 25103, 4387, 23832, 10694, 26523, 22681, 24364, 12691, 20312, 11428, 15067, 25215, 24829, 23256, 9313, 29787, 18956, 22508, 10211, 17555, 24459, 19628, 7077, 18194, 14507, 18915, 2078, 29172, 13095, 11669, 16586, 27358, 13704, 10134, 1168, 17849, 21679, 1771, 11635, 14056, 25227, 16020, 28042, 13201, 7471, 8898, 2989, 27770, 13941, 10768, 9004, 6317, 26030, 21304, 765, 14092, 868, 27876, 4137, 11170, 20257, 11491, 11522, 21727, 19267, 28547, 25823, 4824, 14697, 6323, 14140, 1483, 29707, 26218, 1570, 3403, 8334, 2733, 2468, 20880, 29365, 8065, 14584, 11211, 20976, 8721, 25033, 6394, 19110, 25854, 19010, 25446, 21528, 6290, 9377, 28787, 6911, 11697, 29450, 8653, 15987, 7231, 9274, 3256, 28384, 4154, 26284, 13821, 25793, 6223, 12799, 15301, 18689, 17581, 2637, 21011, 7786, 6964, 26205, 28954, 28911, 20699, 2167, 23165, 1159, 7481, 5460, 12320, 1159, 21468, 6096, 22497, 16840, 5473, 3586, 20288, 15472, 21585, 10426, 10627, 24174, 20279, 2147, 29428, 5888, 8307, 1613, 18419, 19485, 22982, 9722, 25037, 8695, 8003, 15780, 17622, 1787, 28355, 24492, 4045, 15764, 27651, 5447, 22710, 23587, 3476, 2103, 17390, 17035, 19430, 12272, 9117, 19012, 15970, 2463, 17700, 877, 3956, 11121, 5467, 16168, 9807, 20022, 21814, 13350, 8372, 20195, 20469, 7016, 27932, 5483, 27447, 23892, 2004, 29325, 28897, 5415, 715, 3991, 25928, 26785, 1142, 20762, 12618, 13484, 25154, 16791, 18235, 24334, 22242, 19541, 1068, 9618, 23793, 1834, 7401, 19876, 2550, 7363, 15278, 4475, 19171, 14082, 5844, 17062, 15957, 7459, 21628, 11531, 10483, 13878, 13426, 3735, 15947, 29543, 14711, 135, 8553, 17220, 16383, 12039, 7553, 12865, 6602, 17901, 11167, 7983, 20463, 27898, 2719, 28900, 675, 18594, 9514, 2230, 15560, 18664, 16557, 19417, 1371, 719, 27251, 10013, 25936, 23273, 14240, 5051, 23090, 26580, 26436, 8340, 4782, 14531, 2827, 21587, 22719, 3115, 29360, 380, 29136, 5226, 12690, 1845, 8554, 19069, 16869, 4516, 28091, 2649, 12360, 220, 11055, 15532, 3474, 11708, 4059, 6046, 26242, 16326, 6138, 4305, 28127, 548, 29931, 21148, 8893, 8483, 13758, 15211, 12468, 17192, 5539, 28862, 9894, 11862, 18214, 20753, 3221, 417, 5477, 17253, 28026, 18760, 2041, 1744, 3114, 28116, 21649, 258, 10394, 6187, 27953, 17989, 11106, 20984, 11284, 8704, 5890, 9635, 15581, 11695, 23040, 26770, 23802, 22169, 27165, 8408, 5217, 21612, 8656, 12233, 17715, 23565, 6649, 15904, 24583, 26430, 17146, 19475, 13098, 16773, 10883, 15311, 19700, 20660, 25510, 11536, 13510, 14531, 23413, 26801, 24475, 29065, 4644, 25345, 15393, 16695, 1035, 19952, 19518, 9802, 13651, 16883, 19109, 20171, 5570, 8856, 5786, 21409, 6770, 18961, 3909, 18840, 24148, 17400, 821, 8242, 1468, 26102, 29720, 29394, 3505, 29449, 25255, 28736, 924, 13801, 27324, 19282, 13581, 17976, 25379, 28597, 4367, 21300, 18874, 16146, 7163, 1543, 23238, 6346, 29750, 19211, 28428, 23205, 7262, 29806, 22457, 13131, 16117, 26396, 12042, 27019, 19436, 18796, 22003, 2046, 15046, 4497, 8864, 20425, 14215, 28364, 7599, 10990, 6033, 27905, 29024, 15588, 21207, 18313, 14753, 9824, 19501, 1253, 7208, 14517, 24891, 20815, 28989, 10430, 19587, 7215, 3243, 14281, 18620, 4483, 7752, 21488, 12340, 24488, 28626, 22164, 27478, 23858, 19220, 22510, 17211, 24157, 9114, 14481, 11711, 28296, 26663, 24491, 25123, 25196, 19043, 28823, 8117, 697, 26660, 4446, 8264, 11910, 11423, 21314, 9875, 2898, 22739, 5995, 21826, 11086, 2803, 23329, 25632, 23327, 29571, 18371, 15144, 10908, 1674, 8978, 28581, 19388, 2154, 17021, 26532, 28933, 27155, 16522, 20798, 11240, 21248, 6068, 2399, 16608, 18291, 26129, 9743, 3464, 13691, 21230, 13074, 10575, 9498, 21673, 130, 6934, 23274, 19070, 5299, 16104, 13448, 318, 9227, 18874, 17232, 22295, 10420, 1188, 5498, 3772, 25637, 638, 202, 11887, 12391, 5863, 22301, 20462, 14831, 6704, 13629, 18930, 7101, 16935, 7164, 27412, 27399, 11107, 22937, 4092, 28063, 24575, 11373, 20986, 28120, 26954, 1665, 4249, 5466, 22580, 12488, 23939, 7883, 12605, 13029, 8906, 7253, 20586, 26507, 20741, 20980, 12689, 18018, 24233, 7158, 6478, 25023, 17577, 11059, 7233, 12349, 27089, 27600, 9096, 9864, 23717, 13699, 1337, 25875, 13977, 25886, 18439, 16209, 10402, 17449, 12134, 8078, 6652, 14754, 28322, 15638, 8549, 10674, 14983, 16777, 18327, 22568, 18878, 7765, 24694, 24449, 21459, 4514, 25733, 21759, 28311, 17761, 16737, 10617, 17843, 15306, 12889, 15868, 4207, 17283, 25911, 11036, 5019, 9415, 9126, 7265, 27434, 12484, 6745, 24001, 23899, 9671, 2341, 14297, 24138, 18865, 11969, 26052, 20138, 23397, 17576, 20504, 23962, 10301, 6325, 10474, 28972, 383, 2595, 19375, 6984, 16497, 13748, 19607, 20350, 23859, 3095, 7763, 27778, 27002, 16569, 7495, 7609, 5231, 4380, 27740, 21270, 20894, 11061, 18507, 24672, 28269, 18346, 29339, 3403, 20, 7218, 17348, 28897, 2066, 16653, 4171, 10223, 12050, 22778, 3256, 26083, 1433, 2651, 29649, 14126, 23545, 2051, 26828, 24304, 26297, 28724, 21188, 22366, 16791, 22709, 5440, 8540, 1308, 10222, 13757, 2029, 25220, 22169, 14750, 13946, 16239, 8270, 26994, 16661, 26958, 27004, 1348, 12141, 13290, 16007, 20180, 20850, 4211, 15181, 20338, 22934, 10139, 12306, 28649, 676, 6197, 24170, 12726, 12521, 29808, 22102, 26120, 10628, 14686, 34, 20010, 16135, 7549, 16713, 16047, 11431, 409, 25430, 19358, 9785, 22729, 11563, 26932, 8684, 1707, 12092, 20016, 21815, 6834, 24749, 17768, 22546, 15869, 11919, 8438, 17194, 15629, 9806, 4538, 13066, 19789, 23701, 11389, 6438, 26152, 26928, 11437, 6595, 9781, 2528, 19503, 6413, 12597, 4052, 13957, 564, 18340, 7375, 27041, 2851, 14235, 16905, 11229, 28911, 27419, 11255, 5987, 26567, 19443, 19455, 19078, 5364, 23394, 11808, 18123, 14025, 23643, 7829, 14845, 11140, 3195, 24361, 13853, 16433, 22043, 17093, 5425, 27544, 8879, 21322, 1363, 15355, 28310, 15841, 12847, 9748, 26756, 10567, 4150, 13398, 6666, 26531, 2164, 22559, 6743, 18344, 3117, 11810, 10862, 11707, 6624, 18988, 17019, 10810, 29591, 3229, 6214, 9931, 27017, 5649, 1574, 2608, 12138, 26626, 28426, 27237, 6201, 23520, 5707, 6169, 19748, 29695, 23893, 16084, 1980, 29225, 19077, 27889, 20290, 12678, 11168, 26777, 21380, 24856, 17587, 10557, 15329, 25561, 24256, 6365, 20729, 10840, 28056, 3971, 10608, 885, 14828, 9032, 21745, 29895, 4768, 5271, 10241, 16526, 23929, 5182, 29215, 28805, 25375, 20978, 22685, 2499, 9702, 19463, 14532, 27055, 1394, 21397, 6523, 29781, 3036, 5739, 5565, 14521, 7879, 13288, 25393, 15130, 17121, 7092, 13540, 12516, 11, 2747, 24277, 12418, 26572, 7817, 27955, 9967, 15287, 3282, 4015, 2080, 1546, 10604, 29447, 8278, 1166, 24775, 18668, 407, 28217, 25137, 11086, 5458, 6535, 12807, 20548, 4063, 10700, 24026, 23549, 7033, 4320, 9573, 27431, 26627, 19545, 681, 6292, 20177, 12470, 17931, 10698, 23827, 13604, 16488, 26850, 7260, 4094, 23403, 18360, 10049, 22227, 4064, 24160, 11254, 17341, 25688, 22026, 28417, 10411, 19877, 20715, 9987, 5662, 24755, 23164, 4618, 27124, 10519, 3608, 9294, 1643, 349, 15588, 19018, 13730, 16325, 10862, 212, 5794, 24003, 19911, 8358, 22146, 12439, 8598, 13929, 18138, 28599, 19513, 4703, 996, 10277, 7920, 11829, 4890, 5186, 15443, 15437, 23719, 19387, 23031, 18593, 29840, 2311, 10631, 744, 21345, 7052, 199, 22862, 11260, 16288, 24427, 15903, 770, 4979, 970, 9323, 28454, 26067, 22386, 11023, 14329, 14888, 29661, 18451, 12049, 12780, 29317, 29948, 4290, 29028, 12464, 9317, 6527, 17673, 7076, 29463, 24422, 10640, 17907, 2457, 13057, 29688, 16537, 27267, 11528, 21532, 11049, 10780, 4800, 13604, 23076, 16697, 7667, 29214, 21948, 17567, 11270, 16153, 24907, 23899, 11623, 2400, 18999, 7339, 15221, 6086, 2397, 19031, 555, 9748, 19282, 26074, 19251, 29784, 24400, 20195, 4917, 11710, 22627, 15030, 20649, 19432, 24373, 7181, 22025, 22822, 18154, 11987, 6170, 6551, 4498, 7045, 395, 14129, 23500, 28783, 16815, 25049, 17057, 4456, 27024, 24016, 5496, 18812, 21676, 13882, 8971, 15026, 5948, 17988, 22924, 17698, 28367, 6810, 17971, 12186, 3533, 10691, 16188, 14644, 16966, 20889, 16640, 74, 13041, 3871, 29592, 27938, 8000, 8591, 997, 6080, 24612, 10319, 23867, 21891, 8153, 25336, 24311, 10093, 23691, 28783, 14784, 11016, 26960, 17003, 26614, 13316, 25067, 16232, 1952, 20134, 23965, 29716, 4211, 2841, 1117, 11964, 28108, 22700, 8618, 26159, 17995, 12094, 4169, 10099, 15596, 3775, 27491, 22606, 13999, 8287, 29114, 7620, 27662, 21327, 15298, 9463, 9673, 1836, 1587, 15621, 25656, 20578, 18859, 735, 17321, 5082, 29416, 1791, 4732, 24130, 23187, 29225, 7322, 20453, 8820, 18221, 6470, 8074, 23689, 28696, 11018, 11886, 20327, 77, 7594, 7959, 4658, 491, 361, 25842, 21785, 27813, 5816, 25451, 18106, 645, 1605, 22188, 15552, 26292, 19959, 1404, 6462, 11295, 7850, 26732, 9784, 6297, 27950, 24129, 15576, 3817, 6748, 16291, 17926, 14104, 21828, 21844, 817, 16131, 22040, 13255, 14306, 27785, 20601, 11963, 13860, 6193, 28150, 5383, 5527, 5736, 8008, 28815, 29859, 28559, 14182, 22012, 11447, 22421, 22128, 27036, 701, 12754, 337, 22754, 22617, 29623, 6481, 4905, 16563, 11363, 15228, 16874, 16486, 5927, 11214, 19927, 19596, 29134, 26925, 18838, 22767, 5539, 23343, 20910, 11048, 10106, 3231, 21149, 23692, 14106, 28879, 26260, 18303, 1496, 21960, 26841, 13473, 8739, 10836, 26396, 16987, 27330, 15493, 4402, 27035, 5114, 11351, 26755, 10479, 21369, 25546, 15403, 10153, 19922, 19694, 21343, 3670, 21778, 16827, 20169, 9028, 10266, 14436, 15635, 8223, 28064, 27993, 28337, 13803, 7967, 9428, 26163, 16130, 2290, 26776, 9573, 11578, 29674, 27782, 20141, 23102, 24339, 3987, 13187, 8606, 1999, 27234, 21888, 24576, 29022, 19233, 4794, 8198, 14816, 19527, 8710, 5690, 3316, 12603, 26117, 8710, 6442, 21135, 20950, 1004, 26431, 19599, 9383, 26693, 13833, 1322, 2304, 3995, 23893, 11772, 7619, 23482, 8406, 9295, 6131, 16080, 971, 8406, 6689, 15489, 5345, 10243, 16696, 11641, 2714, 9283, 10973, 27107, 16504, 28144, 8117, 25149, 17885, 13124, 867, 9573, 25914, 28370, 10974, 26219, 9573, 1578, 11568, 3482, 18522, 1568, 5456, 2656, 20012, 24307, 1621, 16645, 3447, 406, 18276, 29116, 25643, 15450, 13022, 27065, 18889, 24078, 11237, 23354, 28565, 3639, 27245, 21562, 23593, 11592, 17237, 21721, 6454, 27986, 5256, 23910, 7286, 29694, 14098, 21641, 16571, 859, 13415, 22801, 9508, 27705, 22408, 735, 10512, 4589, 21387, 15609, 22740, 20064, 8329, 22698, 1518, 3191, 23882, 11824, 29413, 15728, 26734, 6969, 26786, 26437, 13345, 9272, 7712, 15819, 3558, 22440, 25386, 5921, 24697, 1000, 21172, 13591, 23746, 20754, 17286, 8615, 14518, 4248, 7886, 27805, 28697, 13374, 5967, 94, 23670, 3452, 29354, 9940, 11816, 2928, 1178, 12319, 1084, 14369, 19346, 19690, 1348, 12754, 16450, 9723, 3210, 19531, 24999, 23913, 630, 14994, 19037, 5877, 28953, 13372, 23905, 1024, 1660, 2366, 14737, 29852, 12510, 1982, 22564, 9441, 14256, 27585, 24416, 25076, 11368, 12156, 14751, 9341, 8603, 9286, 6054, 8436, 14364, 18192, 16459, 17527, 18069, 6979, 2809, 10463, 19201, 23973, 9966, 11413, 17307, 13328, 3185, 8080, 28932, 23364, 4687, 24654, 9636, 20761, 25367, 25462, 7745, 10875, 26158, 25685, 7199, 18054, 3368, 14934, 3080, 21756, 4452, 28238, 884, 4170, 7127, 4809, 18934, 26090, 28008, 23455, 28320, 25002, 17976, 1913, 814, 1137, 7725, 28763, 7374, 11959, 6086, 2728, 13333, 13257, 14156, 5479, 8923, 1348, 19329, 1434, 6823, 8512, 5678, 9895, 5711, 24665, 2686, 9076, 17328, 15277, 23355, 12499, 25141, 13920, 26086, 28932, 4065, 10993, 16904, 14438, 8761, 20886, 4971, 8952, 17066, 21316, 13981, 26074, 19447, 969, 9066, 23804, 8924, 10687, 2910, 4283, 13655, 15646, 1969, 1988, 29899, 8329, 7881, 8932, 8474, 22050, 24361, 24119, 7533, 20700, 23385, 17372, 21618, 7877, 13158, 19532, 13866, 23696, 8627, 17713, 7779, 6301, 12936, 7389, 14447, 6006, 25892, 23172, 23399, 11638, 20915, 22795, 16186, 16288, 2167, 20709, 6340, 21593, 28128, 17654, 24185, 23161, 1514, 18862, 4899, 13344, 1222, 15317, 17603, 18768, 8585, 26498, 9812, 14709, 6962, 13719, 4581, 10831, 4194, 28572, 26294, 15349, 10084, 20314, 17678, 8678, 7894, 26910, 2877, 4401, 8405, 10714, 1453, 11662, 6715, 2088, 22125, 10194, 2832, 8882, 10236, 10102, 16340, 5263, 41, 26839, 26150, 4082, 18600, 24560, 10360, 21344, 11456, 29966, 28698, 8630, 12561, 10736, 5380, 18614, 25246, 8105, 25983, 19383, 2713, 2440, 2495, 21464, 16563, 21402, 18649, 22938, 1306, 12419, 11102, 20577, 20221, 22528, 9428, 15136, 28891, 28802, 23093, 18563, 5564, 14535, 26429, 9374, 10014, 16634, 4164, 464, 10275, 24683, 13380, 6491, 2742, 19053, 27207, 29771, 657, 13821, 28644, 13166, 7554, 3132, 18000, 16345, 29419, 25370, 10638, 4569, 13964, 4651, 16769, 1635, 10428, 24332, 9710, 18370, 4529, 22103, 8563, 12364, 17400, 6185, 24107, 2834, 11846, 21742, 21619, 15597, 12131, 13400, 21238, 11633, 9755, 19556, 25570, 14879, 20247, 6876, 11239, 22713, 16820, 23943, 16626, 14018, 18185, 6162, 26479, 26388, 717, 4404, 24895, 14842, 21421, 11291, 25890, 20290, 21751, 7005, 3678, 15047, 23642, 13837, 9502, 23415, 12183, 24020, 26824, 956, 1111, 24253, 18601, 17671, 11927, 22487, 9268, 29090, 4684, 21072, 13531, 28592, 17831, 27515, 9319, 6869, 21155, 13329, 1293, 25373, 18571, 16981, 15714, 8036, 7324, 9556, 5991, 8860, 29372, 26831, 9911, 11604, 27567, 702, 21, 915, 15964, 5065, 16704, 10340, 16427, 14331, 20713, 20097, 6066, 12017, 27473, 18715, 24300, 8393, 21918, 15981, 3406, 6672, 28515, 29924, 7591, 8647, 9850, 17923, 17991, 13548, 14282, 7235, 22812, 12563, 25601, 15019, 18204, 11576, 23355, 4518, 26286, 12940, 16802, 25168, 15510, 3710, 24909, 10006, 1129, 13712, 12432, 1896, 8161, 2779, 8870, 1174, 29335, 11617, 21614, 19660, 5731, 24666, 744, 11133, 29170, 26356, 10041, 3994, 13532, 12550, 12665, 12923, 23660, 9318, 18488, 13942, 29486, 28890, 22931, 12489, 12595, 7521, 18862, 8353, 29969, 19492, 1973, 6420, 6577, 6387, 16705, 14632, 28608, 27361, 20833, 17955, 20532, 10724, 21653, 23491, 2406, 8753, 4875, 25496, 29472, 12498, 26897, 29423, 4747, 13078, 13406, 26690, 26502, 14381, 3880, 5767, 22620, 28882, 19189, 15161, 23208, 629, 12954, 11361, 11141, 378, 1784, 433, 6139, 12044, 21394, 16926, 17333, 22031, 5138, 29759, 8491, 5492, 3583, 24084, 16176, 27397, 6876, 10294, 995, 16717, 25988, 29946, 7041, 10395, 12326, 25590, 21433, 28213, 5755, 7601, 9742, 24438, 1635, 5217, 25395, 18139, 15062, 28461, 22618, 5263, 14631, 24426, 8892, 5846, 19112, 27389, 16186, 24643, 17076, 8463, 3903, 17175, 13923, 7008, 5251, 25028, 15601, 23228, 22473, 20000, 20098, 21848, 4201, 28503, 630, 13913, 25648, 15734, 26667, 2292, 29941, 23114, 3148, 8042, 10720, 9900, 5989, 21040, 17372, 5333, 28484, 11095, 20429, 11347, 17181, 4046, 22194, 3237, 92, 1288, 29345, 3682, 15494, 22612, 12022, 5440, 5451, 14024, 22185, 10731, 23796, 22690, 14244, 28080, 7564, 15492, 25896, 19923, 6043, 12968, 6203, 27220, 18289, 8771, 23052, 9528, 22161, 9392, 2464, 29634, 5735, 4247, 19544, 26571, 13470, 25827, 2478, 21848, 18131, 27092, 11806, 20389, 22758, 14044, 1517, 17536, 15925, 18316, 25016, 12856, 19104, 23875, 19679, 2348, 8726, 28398, 13704, 4646, 4728, 13288, 6258, 9976, 27055, 15107, 6388, 25272, 15966, 29987, 13921, 4803, 5469, 13788, 26042, 18707, 18653, 1096, 23134, 18257, 11525, 22369, 27615, 22099, 5943, 27589, 25370, 27994, 22904, 8378, 23929, 9625, 15126, 21911, 13181, 1772, 1791, 13888, 8889, 4742, 5164, 13734, 21273, 10115, 21658, 7642, 20862, 270, 2871, 26620, 9504, 23345, 17265, 12412, 27793, 19808, 22853, 22272, 1111, 10759, 4972, 16931, 1050, 17004, 23919, 1394, 10822, 11286, 24881, 3223, 9690, 7083, 27533, 22855, 8315, 15954, 15866, 24001, 10833, 8738, 1911, 17964, 28233, 26094, 4136, 18423, 28307, 7980, 1737, 19267, 21189, 7588, 100, 9180, 14060, 2513, 14784, 16375, 7599, 11828, 15122, 29989, 15504, 3066, 22963, 2752, 5402, 14311, 6622, 15075, 8883, 25422, 4054, 10676, 27668, 19181, 10217, 21136, 6558, 14253, 24542, 13731, 26559, 19956, 21214, 17163, 26579, 13652, 29517, 8271, 28156, 22080, 3092, 9750, 25138, 15404, 15086, 12267, 13794, 26902, 18722, 17377, 26616, 18286, 26437, 13538, 15793, 13836, 8687, 15646, 18304, 11930, 7050, 563, 27607, 15858, 2754, 11192, 10605, 18378, 2579, 14900, 15447, 29895, 27047, 18031, 5009, 29160, 16687, 13387, 11526, 7683, 28393, 27156, 15264, 26276, 5078, 606, 19718, 10434, 25322, 1768, 11554, 12121, 3536, 29935, 19461, 23228, 12874, 8860, 13569, 20005, 15843, 15740, 15869, 23382, 24319, 5188, 9609, 4627, 27904, 22316, 24921, 28886, 3619, 29366, 21186, 22826, 11295, 3448, 19102, 27501, 3218, 27119, 8719, 5877, 28793, 11889, 27187, 28886, 2793, 21239, 24030, 3598, 350, 27933, 4585, 10355, 12358, 29328, 21413, 27252, 35, 2775, 13786, 11784, 12455, 12240, 18247, 24081, 791, 14248, 7650, 1547, 24218, 29669, 23320, 27476, 19816, 16410, 7941, 26492, 20117, 28554, 12325, 11745, 25950, 29079, 5322, 2934, 5530, 19114, 22439, 11791, 15761, 28053, 20407, 15685, 24250, 24283, 23259, 19783, 23186, 24219, 12188, 3444, 6575, 3830, 6349, 28760, 17553, 22212, 6432, 4547, 21772, 13983, 1465, 6459, 28381, 13336, 16384, 14597, 13613, 13552, 27018, 7634, 29877, 19156, 22847, 651, 27337, 8507, 9772, 18940, 26374, 12007, 9939, 3436, 8201, 11912, 17495, 9542, 20031, 1852, 21261, 4066, 19090, 29327, 22963, 5961, 10055, 7536, 12012, 20855, 14959, 4990, 19411, 5553, 14104, 28888, 20286, 25743, 1166, 10682, 29189, 14621, 4504, 26330, 11244, 7834, 6736, 5959, 22675, 1323, 17777, 7663, 12271, 6359, 13825, 22080, 15331, 23886, 21371, 28928, 19313, 26700, 9443, 23091, 12697, 18060, 12120, 13325, 9004, 26636, 14026, 25217, 2752, 10256, 20488, 22646, 183, 14366, 3633, 17772, 18950, 12795, 24211, 12710, 26901, 27158, 27949, 1274, 27476, 22526, 8256, 14087, 24228, 14848, 23580, 28594, 16497, 17706, 15059, 9917, 13183, 5452, 17877, 23141, 17783, 18475, 24709, 25807, 23216, 12990, 14925, 27433, 19105, 7020, 1106, 10022, 8429, 29375, 23539, 1922, 23641, 763, 19522, 18962, 7065, 18335, 2145, 18553, 29510, 185, 1649, 16280, 9859, 25120, 26357, 14917, 22781, 20199, 7946, 14152, 14785, 4490, 5676, 20678, 29597, 27100, 24069, 21270, 18801, 3587, 10205, 15838, 3060, 11488, 8041, 707, 21509, 15851, 11159, 21866, 13097, 13086, 28108, 9169, 12133, 23094, 17811, 27819, 8432, 13569, 24811, 6810, 3845, 2336, 26476, 18131, 19991, 20698, 3373, 22233, 10735, 24078, 16321, 6993, 5151, 17423, 25069, 3343, 15739, 9361, 14161, 14256, 19160, 25142, 27274, 4190, 2100, 28282, 27832, 28101, 8054, 17286, 4247, 22129, 21449, 28815, 8703, 28567, 28757, 13180, 11023, 1462, 7465, 28995, 19409, 6692, 15313, 20380, 18844, 6013, 29542, 21737, 25106, 11345, 20754, 20612, 24881, 7802, 24193, 21881, 21900, 13286, 18407, 11857, 11424, 9782, 17955, 23865, 5838, 22545, 24161, 4035, 25474, 24066, 16598, 13409, 26219, 4510, 24909, 15988, 7183, 28302, 26361, 10792, 5033, 29263, 7355, 8134, 22553, 5940, 4428, 1832, 25706, 21962, 12728, 10112, 3743, 15388, 20406, 26736, 8850, 14493, 2211, 22842, 23529, 22627, 5227, 16020, 10377, 28690, 27664, 13808, 1991, 23320, 2721, 22122, 1617, 20059, 23042, 22258, 6151, 5309, 772, 22506, 11980, 15370, 26631, 20773, 18952, 19551, 27291, 4579, 29108, 16437, 1394, 28759, 4676, 20634, 7665, 21144, 5090, 9409, 13652, 29991, 14135, 27917, 2922, 25611, 12332, 14388, 26090, 11451, 23884, 14748, 2208, 560, 8969, 21190, 20688, 18698, 8929, 17093, 17888, 26204, 24860, 79, 5905, 16504, 27925, 10345, 1110, 28936, 10307, 17910, 5059, 14454, 20660, 2667, 25938, 7393, 11203, 9469, 4185, 16042, 4185, 9242, 28476, 12216, 20058, 26650, 15818, 24638, 8146, 19626, 21706, 13536, 5852, 15789, 21558, 14274, 5214, 23658, 976, 18989, 15545, 19503, 27501, 23414, 5511, 24256, 20904, 2470, 973, 22659, 20740, 23074, 26872, 13135, 7847, 14258, 19208, 22988, 28469, 3623, 17751, 10817, 140, 14068, 20416, 25855, 7657, 23401, 17021, 11116, 4745, 7112, 79, 21433, 16419, 8926, 22184, 19969, 10216, 13211, 23633, 8587, 4599, 25157, 9932, 16597, 895, 9289, 9314, 13182, 2297, 14792, 13315, 17546, 22118, 15629, 982, 21167, 25570, 27836, 16551, 26306, 23352, 2133, 28060, 10070, 13991, 25874, 7173, 24561, 28773, 10984, 22310, 26117, 29546, 20728, 28844, 9300, 677, 17941, 653, 18652, 29823, 15284, 3320, 2148, 24723, 12307, 8488, 5661, 21063, 22832, 6015, 22660, 18649, 13023, 29488, 26855, 19714, 3272, 13004, 28165, 7691, 10608, 14193, 17429, 18737, 19895, 12561, 12664, 7840, 9383, 25244, 26513, 19494, 13451, 7303, 26279, 22005, 18097, 19981, 22000, 20088, 6841, 24714, 15337, 22546, 6693, 25486, 12448, 10872, 8383, 12309, 28472, 10846, 6327, 25139, 6013, 19528, 2238, 8845, 27791, 691, 24466, 4568, 9787, 25360, 25475, 25180, 27101, 10457, 26257, 10822, 24807, 12582, 19905, 22711, 8488, 25890, 4182, 17345, 24014, 20533, 6643, 25365, 6393, 1725, 17151, 16073, 29108, 16925, 4234, 27781, 29977, 28905, 8801, 28101, 7992, 6908, 13910, 10761, 20941, 6027, 17210, 8292, 22420, 19548, 26014, 17275, 19763, 982, 20703, 14085, 501, 24107, 14113, 21993, 17225, 15993, 18175, 21787, 3158, 5931, 3808, 9835, 23182, 27198, 7808, 21622, 9433, 2749, 23746, 16863, 21348, 23859, 14796, 7322, 4171, 14914, 867, 23654, 27654, 6547, 5980, 20287, 27710, 1541, 2424, 222, 10753, 24157, 19631, 2489, 5583, 13089, 2817, 8248, 4664, 24248, 28827, 3642, 4402, 19948, 24885, 24513, 14904, 22678, 24933, 29322, 2552, 23897, 16496, 27464, 6367, 7051, 25956, 22206, 15356, 23018, 11422, 13400, 27811, 28853, 22773, 25428, 4353, 17516, 13061, 19966, 23194, 4996, 844, 23135, 12147, 29881, 17852, 22555, 2307, 2412, 5550, 26356, 5448, 6115, 28275, 3211, 15051, 17892, 3427, 1501, 6530, 14455, 13164, 10447, 19222, 25193, 11975, 22059, 19339, 7263, 25898, 26696, 20603, 4938, 16689, 26889, 22808, 28260, 22186, 1390, 8860, 19362, 11989, 15886, 13934, 18862, 28124, 20148, 9473, 14114, 21912, 2410, 7082, 23614, 11711, 3114, 22899, 14877, 29192, 20161, 3936, 6957, 16281, 20179, 16637, 7930, 9323, 10657, 19680, 25312, 8591, 987, 11241, 13429, 28672, 8543, 26378, 28488, 555, 17563, 12494, 14085, 26939, 13260, 19816, 26662, 15167, 2378, 9824, 16702, 2128, 9741, 26870, 16230, 3660, 26429, 18379, 14134, 9108, 23067, 8045, 19298, 1994, 4213, 28477, 13373, 1561, 15571, 14741, 29637, 21038, 3389, 28906, 24227, 12424, 14749, 16884, 16216, 5155, 4675, 8053, 18255, 5204, 9215, 17631, 26471, 19319, 8004, 447, 16733, 14731, 26868, 5472, 8417, 6456, 19693, 13053, 9986, 11162, 17787, 26580, 23277, 27322, 18436, 6435, 16329, 17784, 7764, 14011, 2255, 25425, 5712, 10523, 18445, 12274, 10334, 1780, 454, 22095, 23301, 22614, 627, 4206, 3281, 27369, 2640, 25665, 17559, 24174, 27499, 1829, 18385, 4749, 21723, 8792, 8944, 28765, 18831, 26832, 23585, 9361, 1797, 27582, 19970, 10940, 7993, 16019, 13346, 1640, 6093, 29784, 27457, 2051, 22739, 15968, 28807, 21889, 19244, 1365, 20310, 19912, 15665, 12412, 10809, 22746, 1497, 7481, 6417, 5175, 21704, 218, 10198, 101, 25273, 8316, 17012, 22289, 9053, 28569, 27607, 2951, 21079, 4951, 28857, 25567, 16056, 4550, 11468, 20807, 5665, 24115, 15638, 4025, 17201, 26353, 22165, 24962, 9509, 24565, 1685, 7388, 25851, 20883, 4472, 18000, 10618, 26525, 1354, 24519, 27576, 24320, 6714, 14546, 27934, 8639, 12890, 9233, 27527, 21934, 18486, 1536, 25700, 28381, 3320, 10734, 10884, 12494, 9176, 2793, 10137, 3932, 18876, 29140, 28818, 28160, 29726, 1001, 7197, 21210, 18378, 269, 10219, 15051, 8949, 26446, 18757, 4715, 29538, 20121, 16655, 2500, 18705, 7508, 18958, 15580, 18771, 13208, 11070, 29018, 2480, 10754, 6917, 21469, 25121, 29917, 4537, 27521, 7223, 27022, 2699, 3614, 1596, 8832, 28627, 17826, 5350, 21645, 5533, 9348, 29101, 25053, 18359, 17566, 25096, 17515, 8630, 25657, 23711, 1509, 25592, 26740, 15073, 25685, 22425, 18849, 24321, 9395, 28822, 8087, 25754, 1908, 22702, 28248, 26884, 27341, 17238, 6471, 27700, 4162, 7307, 24730, 5509, 18030, 28613, 28860, 413, 4235, 26202, 22949, 12430, 21999, 16793, 7656, 14434, 6820, 4886, 11937, 9184, 28435, 6822, 26366, 27989, 7237, 9049, 27844, 5279, 13791, 8094, 13375, 8026, 10948, 11929, 20464, 21136, 3730, 1165, 19625, 5879, 27217, 8525, 27064, 26782, 23307, 23308, 17890, 5118, 5315, 16152, 15958, 20557, 8590, 6516, 11388, 19663, 18182, 23580, 18799, 28807, 2326, 297, 3461, 24306, 23317, 12861, 17113, 5069, 10192, 624, 22038, 24053, 12156, 20856, 13789, 5974, 4907, 7078, 11239, 11848, 21369, 17879, 18920, 15365, 6160, 2866, 11535, 28175, 12848, 19693, 13756, 11006, 29175, 28126, 16680, 23735, 13554, 29875, 15554, 13734, 15966, 25163, 4377, 26143, 27872, 19201, 12242, 24638, 3214, 12470, 27990, 17237, 1210, 18434, 23220, 9013, 24669, 11414, 6252, 13758, 29771, 29405, 15872, 21488, 6396, 29667, 2243, 24300, 26656, 21878, 25207, 15668, 2733, 27410, 25861, 26752, 7771, 26965, 15046, 7281, 357, 20861, 13727, 26148, 23913, 221, 21364, 9732, 5453, 26826, 13089, 26466, 21658, 25762, 27260, 26329, 17014, 16857, 12136, 11942, 21098, 3812, 28187, 23565, 10102, 22007, 1578, 104, 26957, 19614, 22272, 4604, 27432, 21557, 27388, 9152, 946, 29794, 21103, 1270, 2725, 27875, 5653, 5541, 22521, 594, 4365, 24903, 28370, 25897, 22334, 1818, 15938, 21717, 1674, 989, 10369, 13128, 1100, 19698, 1733, 21238, 28221, 22490, 16160, 7295, 3604, 23460, 9109, 10862, 24849, 7363, 12183, 18402, 8033, 1431, 29971, 20169, 24618, 8065, 13959, 5974, 1393, 18036, 9268, 23559, 28779, 22433, 5351, 9009, 9865, 19837, 9935, 28300, 992, 12931, 13508, 6079, 3249, 8704, 3630, 23663, 493, 15930, 18586, 3028, 28555, 814, 3125, 3197, 28402, 27503, 25716, 13638, 5981, 8865, 26122, 18129, 20728, 28373, 1656, 19652, 2187, 7129, 13262, 1021, 27064, 11367, 26148, 16261, 4455, 24144, 18657, 19059, 6605, 14134, 15744, 17577, 7821, 8537, 28446, 20962, 29657, 4748, 10838, 29255, 10371, 17739, 6369, 604, 25148, 11909, 10639, 18158, 17586, 8947, 26114, 7491, 9839, 17743, 14429, 21860, 18119, 8050, 27459, 18420, 28261, 22130, 15511, 11224, 13907, 7384, 15155, 12380, 6321, 27150, 5389, 11963, 7489, 13986, 6858, 12296, 1198, 3586, 6382, 1796, 9185, 13842, 19669, 2970, 25069, 9125, 27786, 6387, 22369, 11311, 13917, 29539, 25837, 19558, 1583, 2988, 464, 3097, 3828, 6239, 6394, 21380, 14487, 16696, 615, 2942, 14039, 9877, 7827, 22010, 23864, 27756, 19600, 13121, 12104, 8757, 10777, 26685, 1071, 10364, 18384, 18847, 7925, 8410, 6554, 23206, 26802, 11685, 12488, 7771, 2675, 10510, 1893, 23764, 4885, 28677, 16755, 27011, 72, 3909, 809, 24306, 17229, 4247, 19475, 23359, 22818, 19050, 26833, 4356, 12788, 27865, 22915, 13908, 26500, 26480, 13497, 12129, 1777, 782, 27396, 25371, 24027, 3015, 237, 11537, 28167, 20942, 1004, 22927, 27318, 9429, 4392, 29366, 27899, 4145, 27092, 11259, 4963, 17074, 17976, 28793, 21802, 1404, 25888, 29110, 28214, 414, 6646, 27331, 15797, 21473, 21629, 459, 12038, 22262, 24036, 1838, 27954, 21711, 10656, 28271, 24979, 29899, 20348, 14945, 2332, 15283, 2357, 25047, 29829, 25576, 24309, 21836, 18970, 21320, 4492, 20919, 26035, 20279, 27502, 29320, 2458, 2976, 21509, 25406, 28444, 26269, 11219, 21980, 21101, 25962, 3486, 26155, 15206, 16985, 25525, 13333, 5189, 22939, 7870, 27369, 16715, 22518, 21034, 18361, 29353, 24981, 12587, 22923, 24967, 7332, 5413, 29670, 9614, 18033, 2590, 9815, 27564, 20465, 21080, 15955, 19049, 16790, 5746, 3323, 19317, 26250, 26636, 12918, 16318, 12739, 14729, 12967, 20340, 29981, 13496, 18145, 8641, 20303, 2917, 16112, 21966, 1328, 9528, 11445, 28628, 28982, 27681, 7051, 16956, 11307, 15481, 23790, 28660, 608, 24185, 16185, 20612, 6571, 982, 3598, 10036, 5025, 1451, 22674, 13097, 29893, 3095, 11467, 1709, 14395, 8564, 18297, 4410, 4529, 22788, 24738, 19020, 18508, 25758, 5927, 6626, 28219, 20742, 10567, 14465, 17457, 28836, 21413, 14626, 28288, 29951, 6075, 10975, 24365, 19750, 10546, 21547, 3383, 20535, 12519, 3487, 1979, 28599, 20167, 12984, 26256, 14384, 880, 4585, 8210, 23524, 13068, 27807, 11067, 11210, 26974, 28119, 248, 22324, 1629, 79, 20898, 9921, 12111, 9137, 25717, 16045, 28801, 22893, 663, 3016, 19046, 19331, 11026, 8718, 23661, 17789, 20163, 2283, 28642, 27103, 8763, 28713, 15195, 13975, 18346, 22116, 7975, 26871, 26647, 10303, 19871, 3690, 3666, 17896, 26832, 2744, 15528, 9360, 13869, 27936, 24744, 20049, 24840, 18981, 11447, 21060, 18650, 15362, 12930, 9789, 27328, 20892, 15672, 23704, 18037, 16484, 27793, 14843, 23985, 1710, 10569, 13966, 15960, 25518, 12631, 12190, 14879, 16110, 6551, 26129, 928, 5922, 17329, 1994, 832, 3778, 15880, 22798, 5228, 25930, 4854, 21452, 8793, 27834, 28175, 23796, 6417, 9301, 12923, 7516, 19206, 22775, 26750, 26773, 23815, 12721, 22980, 13583, 20886, 26461, 9132, 9126, 16360, 23096, 7021, 1363, 11602, 14449, 4662, 21423, 21459, 17585, 7243, 28432, 402, 29782, 18666, 7039, 15319, 29909, 13034, 25395, 20939, 23209, 25377, 13944, 25524, 10653, 7453, 2379, 21514, 17736, 19504, 28971, 29171, 27905, 13230, 15029, 21190, 2876, 7676, 7232, 4672, 19386, 6593, 12346, 3827, 15713, 7072, 27334, 21270, 8074, 26665, 27830, 3431, 8597, 25484, 15901, 19387, 21922, 27825, 11529, 1356, 28489, 26479, 5116, 10062, 29741, 7753, 24253, 27184, 24059, 14820, 24269, 29492, 24455, 3836, 24117, 7843, 2976, 4767, 24930, 22830, 28717, 18032, 6374, 14393, 1067, 28782, 24346, 5596, 26928, 24080, 27861, 25237, 13998, 11076, 3396, 20764, 29976, 154, 27648, 29226, 22812, 16191, 16237, 8542, 10654, 16024, 21705, 19568, 17241, 23582, 4911, 29320, 14475, 17934, 23550, 19999, 19657, 5871, 6948, 19587, 28937, 348, 20301, 16408, 10358, 28994, 29327, 22819, 4306, 1075, 17246, 21795, 21728, 10616, 4605, 16113, 21722, 23016, 7157, 18950, 15059, 27275, 13766, 27913, 11484, 27428, 26150, 4115, 402, 16371, 992, 24421, 26252, 29411, 25166, 20908, 27339, 7688, 26760, 3946, 4180, 24727, 9904, 26033, 3833, 7369, 1206, 13988, 15006, 4592, 1226, 13441, 15161, 28760, 23629, 17234, 2721, 1621, 21461, 8244, 14797, 27769, 3566, 15822, 29270, 4125, 6311, 12157, 13182, 27498, 11470, 12760, 28937, 22524, 4567, 24060, 28752, 21492, 16219, 7100, 557, 1185, 23866, 15771, 12671, 5469, 20425, 27821, 27650, 24816, 16328, 28429, 25108, 20589, 29735, 23262, 10791, 14441, 16426, 17916, 19011, 26449, 27948, 25871, 16992, 20122, 27452, 17713, 7811, 16077, 1663, 12829, 10407, 17693, 25723, 11884, 3978, 23464, 24809, 28128, 450, 29937, 6744, 20570, 7078, 20868, 22847, 4202, 13717, 9535, 18017, 26360, 6477, 6257, 13386, 17669, 5313, 7201, 8784, 20370, 29933, 22530, 6438, 25498, 7071, 19458, 3099, 721, 1503, 28415, 10404, 19279, 10982, 15653, 13085, 13950, 12742, 8424, 16429, 29069, 5389, 23611, 7340, 19215, 18345, 7325, 11314, 8213, 11075, 1574, 15127, 16868, 28615, 2825, 18058, 4665, 6563, 12376, 21726, 15906, 18127, 24688, 26387, 8255, 7504, 14075, 21994, 5389, 26085, 21599, 24141, 29080, 12329, 25864, 10320, 10937, 12201, 27743, 2211, 22238, 22803, 2307, 29469, 15341, 4796, 501, 1351, 21250, 4898, 14151, 14353, 24743, 18285, 1482, 21358, 9593, 7870, 13517, 22719, 13002, 12123, 28301, 21825, 13947, 5526, 5660, 21811, 4982, 11023, 16973, 11451, 21269, 17135, 19865, 14223, 16318, 5830, 11766, 8440, 21875, 7111, 29404, 3515, 15961, 6141, 16635, 18257, 20975, 4687, 16204, 20396, 10988, 13415, 17475, 11412, 28566, 22135, 25699, 3552, 27059, 24949, 28534, 4458, 24253, 12666, 1689, 23184, 25164, 9466, 14703, 26654, 15290, 12601, 1617, 13805, 12277, 7322, 19729, 22071, 25450, 6417, 10686, 17634, 19045, 11632, 20467, 9723, 13059, 3414, 18454, 18310, 5163, 3460, 40, 23226, 27519, 838, 5786, 20288, 11646, 1075, 12699, 12932, 19254, 1305, 25301, 615, 14969, 26221, 7394, 28874, 27913, 11440, 4324, 9231, 9527, 7324, 13331, 10386, 17193, 28490, 9411, 5765, 3893, 26162, 7841, 11692, 21162, 16650, 4265, 14474, 11937, 12462, 5712, 784, 25611, 11962, 12529, 13029, 18288, 17981, 8158, 11708, 16634, 14520, 5765, 1031, 26015, 23780, 3210, 1192, 29247, 4295, 18448, 362, 2648, 10479, 18966, 22633, 19685, 26886, 11189, 11082, 20538, 7665, 11932, 15698, 28592, 12456, 2712, 12137, 9612, 4588, 24184, 22345, 26045, 390, 2054, 25713, 29596, 17936, 18104, 10314, 28766, 17238, 15189, 20661, 21787, 3308, 15550, 16840, 4486, 24461, 20517, 19787, 27785, 26316, 18114, 14573, 25238, 24784, 28538, 18461, 26920, 3974, 24855, 27255, 27916, 25676, 21041, 21957, 13896, 12259, 8181, 13642, 21270, 4330, 1604, 19560, 22836, 13993, 27527, 1872, 8547, 17241, 132, 28207, 27663, 1932, 3718, 2848, 23881, 15616, 15654, 3262, 1618, 27793, 14936, 7442, 17669, 20321, 10235, 14083, 4467, 20700, 22927, 12416, 5915, 23866, 11043, 7714, 28437, 19725, 4782, 6801, 24523, 22649, 15995, 28168, 2709, 23239, 14205, 16490, 1478, 24411, 3176, 23177, 9550, 9341, 1636, 8727, 21117, 24731, 4346, 360, 28199, 23329, 12217, 14514, 939, 29755, 15773, 23101, 5952, 29702, 9088, 11832, 1301, 16297, 343, 20883, 6361, 17625, 25982, 23239, 9203, 27120, 21764, 6377, 16200, 17588, 177, 16509, 24484, 10420, 11187, 22498, 28366, 27142, 3501, 806, 14849, 21661, 18392, 7270, 5034, 21168, 23973, 10505, 132, 7221, 10148, 21529, 16919, 27545, 15724, 27479, 18272, 12440, 26253, 20068, 17167, 23458, 662, 7746, 8931, 28176, 18070, 1588, 15563, 1170, 6995, 10131, 11736, 7659, 23547, 25993, 21495, 318, 14773, 2395, 14884, 4996, 19110, 24748, 577, 27302, 28370, 1654, 8023, 24353, 22557, 7612, 20238, 19570, 7021, 419, 1436, 19955, 25273, 27922, 4854, 25585, 27750, 21328, 494, 5068, 26287, 29904, 8147, 26372, 6857, 3726, 13106, 23907, 477, 516, 18516, 25260, 17402, 4396, 25770, 8100, 4664, 11863, 3147, 7901, 27380, 10782, 29383, 14608, 6915, 6511, 13854, 10706, 6103, 5629, 3779, 28393, 20153, 4817, 23007, 11521, 16816, 6691, 16568, 20365, 17290, 27140, 3220, 21162, 5708, 29826, 21764, 4381, 2587, 20014, 27746, 29958, 5804, 14142, 27483, 21665, 26997, 19883, 3722, 22784, 21580, 14011, 17994, 13845, 18723, 21486, 351, 14249, 24576, 12041, 24602, 21675, 19295, 9938, 15853, 25924, 2814, 26010, 29775, 24621, 23421, 16517, 11008, 29140, 20985, 27751, 20816, 19814, 6222, 14554, 2702, 15147, 5855, 901, 18497, 22742, 14394, 7103, 24099, 1961, 24693, 4003, 10807, 25090, 21793, 3782, 2047, 25075, 27522, 28958, 16311, 18419, 9822, 20667, 621, 18606, 2637, 10300, 25770, 26186, 26626, 29622, 21075, 2289, 5245, 17621, 2018, 22092, 16345, 3789, 24713, 3766, 6655, 29619, 15083, 20867, 6323, 9442, 21434, 2936, 5048, 4237, 8842, 5012, 5614, 22417, 18066, 1779, 16146, 26143, 17367, 26030, 4312, 16536, 25251, 1166, 27712, 27563, 10597, 28658, 27182, 18866, 3707, 23593, 17843, 27574, 5964, 22094, 11837, 8346, 9533, 19444, 2255, 22443, 7785, 2346, 3943, 18583, 11633, 19598, 21188, 2737, 10242, 128, 1541, 5538, 694, 20894, 10098, 22822, 11322, 12451, 893, 10365, 21949, 3461, 13450, 11688, 4826, 24439, 8957, 2885, 25230, 17249, 15187, 3037, 6410, 25172, 4139, 19503, 1363, 6586, 28773, 17097, 6662, 21399, 7615, 14797, 13506, 1966, 15404, 16953, 22064, 5355, 27471, 25946, 14837, 3963, 5455, 13932, 15618, 2867, 29145, 699, 7374, 29276, 7975, 13463, 28537, 1215, 5182, 10888, 5270, 2905, 17601, 1308, 17526, 23774, 29818, 26148, 29339, 15335, 28774, 10167, 15509, 22897, 3723, 10831, 8928, 1373, 14478, 10, 21697, 29791, 13495, 26296, 5690, 26773, 26385, 8226, 25642, 7565, 17039, 7934, 28891, 28500, 15092, 27385, 28239, 28870, 22202, 13352, 20890, 14695, 26920, 20198, 6530, 11282, 15653, 24855, 19778, 18283, 4521, 27015, 20828, 16928, 5411, 28544, 26124, 22140, 5015, 7310, 908, 23022, 24746, 15318, 17848, 17097, 6812, 20945, 27238, 19085, 1831, 28714, 14807, 3351, 11348, 22278, 21224, 17917, 7178, 22773, 29731, 521, 21395, 2470, 13990, 22327, 12592, 25120, 22579, 24856, 4775, 7683, 14595, 24060, 29883, 8882, 23373, 18242, 12054, 26438, 4564, 23062, 7743, 10350, 13494, 19251, 28405, 27533, 12873, 21606, 25015, 12932, 12471, 29521, 7363, 4782, 22553, 9270, 1642, 13325, 29806, 27464, 23513, 9689, 28174, 13802, 26918, 4226, 17563, 9112, 2462, 1953, 15008, 23029, 21165, 17141, 827, 13795, 8992, 26449, 22242, 14328, 19071, 2903, 28346, 2557, 26188, 4751, 19792, 4280, 6640, 24506, 18777, 9499, 20810, 23729, 15189, 11581, 19625, 15487, 368, 20808, 29967, 7758, 20531, 9016, 13167, 13167, 6696, 6260, 26348, 7686, 4781, 10737, 21526, 27836, 6691, 29061, 2007, 27876, 22585, 11430, 28929, 1372, 14091, 15464, 12521, 21190, 818, 5015, 6286, 21334, 18807, 4914, 16330, 15998, 10187, 10755, 7037, 9517, 19514, 22937, 6897, 28505, 20374, 15966, 9816, 3748, 16848, 22279, 1272, 5528, 9317, 26323, 16204, 16001, 15144, 27667, 22942, 9478, 2035, 22405, 12838, 10394, 2396, 4913, 1291, 4676, 19598, 3047, 10676, 22314, 26638, 11531, 27245, 225, 10204, 22899, 6212, 25202, 24724, 9439, 3897, 20399, 3561, 11761, 21433, 1184, 27439, 29778, 17384, 877, 13044, 19630, 27394, 11805, 20611, 2383, 26895, 29757, 7614, 13729, 3037, 24229, 902, 28309, 26094, 22318, 3980, 4477, 25641, 937, 12088, 115, 7109, 24688, 8547, 2013, 24211, 9313, 20097, 25337, 12362, 8168, 6579, 26051, 14417, 723, 2495, 24105, 11474, 21566, 8073, 10608, 14497, 27112, 16779, 28145, 26810, 15615, 25117, 15749, 23648, 14523, 5264, 2458, 13457, 7735, 12995, 14622, 22023, 11090, 13872, 26532, 18120, 15711, 10410, 26397, 16116, 11187, 14273, 1835, 20200, 12603, 29803, 26006, 26458, 27293, 1676, 1119, 4424, 6256, 14224, 27509, 4201, 8401, 12051, 20895, 13093, 29959, 29397, 11145, 12383, 16146, 23930, 5285, 23966, 15112, 27810, 20070, 10542, 2765, 46, 15836, 24754, 3602, 10614, 19241, 26940, 3741, 25375, 3217, 19696, 20388, 12260, 2776, 25041, 2827, 20903, 15822, 5259, 13496, 14528, 24834, 26430, 18291, 11433, 24016, 27004, 13983, 11567, 23062, 11122, 8054, 24800, 2102, 11344, 29046, 26004, 8204, 25360, 10554, 7844, 10107, 21053, 2514, 5939, 14832, 26722, 12233, 14980, 19338, 21306, 22744, 18337, 4399, 6379, 15622, 19151, 15964, 10480, 29692, 8753, 4763, 9478, 11207, 10893, 578, 6700, 1929, 7900, 27390, 5341, 27487, 2570, 12567, 29481, 16325, 1070, 5732, 27091, 2601, 29083, 14462, 24531, 11230, 21600, 3195, 6362, 3110, 8536, 12479, 27755, 14329, 3212, 23251, 5145, 5322, 7982, 18741, 20260, 18269, 28609, 14278, 4193, 19329, 28085, 10953, 10233, 16239, 10747, 14665, 28917, 6513, 22488, 2368, 15311, 8252, 27585, 28084, 22512, 7977, 5635, 4307, 22649, 7254, 19950, 17624, 27043, 16365, 17670, 27218, 4946, 28238, 25826, 23891, 24428, 7552, 22734, 10213, 28629, 25959, 321, 22879, 28298, 12687, 27963, 17639, 28735, 25494, 15274, 12060, 17445, 3582, 10879, 9216, 20226, 15231, 7330, 10010, 27728, 5353, 12927, 22797, 23184, 28329, 7032, 10437, 5348, 23453, 19551, 9985, 5156, 15526, 18788, 16669, 29285, 19792, 21313, 7123, 19579, 5143, 11304, 13424, 9977, 21612, 28899, 1691, 21334, 1698, 8884, 24033, 8827, 19060, 9554, 2299, 23835, 15226, 18231, 19633, 347, 20976, 13389, 18987, 25258, 16466, 21298, 16921, 11681, 4045, 3744, 10367, 19606, 8126, 19332, 119, 17506, 16387, 3082, 24796, 28254, 24413, 2299, 3904, 25262, 21773, 16728, 20411, 14950, 17410, 27448, 5365, 23624, 5301, 23941, 13979, 21713, 10041, 29162, 8272, 8431, 9768, 4570, 8961, 12302, 26014, 8482, 7123, 29059, 18046, 23903, 89, 14878, 8288, 4098, 2057, 19986, 7639, 17355, 14324, 21287, 6388, 22857, 4736, 12487, 24551, 6627, 27978, 1411, 29741, 16451, 14757, 16691, 673, 29749, 23173, 3063, 19960, 2462, 12581, 15112, 4113, 21095, 8287, 6466, 19860, 5516, 3107, 15891, 16621, 20885, 7997, 28343, 28283, 19246, 11587, 24420, 18664, 24633, 6177, 11271, 20178, 7187, 15281, 5786, 12954, 16972, 8376, 6521, 26500, 24526, 23425, 15986, 29076, 3734, 17255, 12915, 14079, 12218, 26633, 29011, 11313, 8698, 13422, 29732, 19060, 6963, 4310, 3422, 343, 3518, 9287, 9031, 14244, 8205, 22281, 4309, 19162, 17845, 3564, 9773, 27710, 25560, 24152, 28371, 1008, 8201, 21969, 23292, 20877, 4522, 29609, 8171, 27530, 5794, 23688, 215, 7299, 22496, 7135, 16499, 21429, 10885, 26605, 22977, 22225, 4471, 16425, 15695, 17223, 27276, 8551, 9497, 5817, 27610, 16393, 17639, 9422, 14839, 15162, 22644, 11877, 8412, 23795, 26280, 12654, 19657, 4550, 27044, 1229, 5817, 25607, 5147, 19531, 13743, 16479, 4526, 16595, 3754, 12662, 3794, 10207, 7258, 15101, 9294, 26412, 25520, 17698, 17443, 18327, 22833, 4312, 16357, 5361, 6940, 15670, 22262, 2955, 5167, 9212, 3078, 22340, 19312, 18027, 24208, 15554, 5863, 16343, 25950, 5169, 25830, 25296, 11365, 24592, 20676, 1119, 28197, 13163, 24595, 18579, 13817, 15309, 17848, 29930, 3515, 5547, 9261, 24006, 28597, 10804, 17623, 18848, 15235, 29108, 16551, 23835, 24664, 1671, 15114, 13329, 26863, 7965, 20710, 2658, 13988, 4753, 16648, 25343, 29784, 3522, 13639, 8159, 7659, 14365, 19655, 26724, 25982, 5409, 16876, 22531, 8980, 1321, 13956, 22149, 24360, 14444, 10595, 11649, 29190, 22602, 23740, 16940, 5078, 24837, 7931, 17968, 16192, 13150, 6985, 26951, 14309, 730, 20369, 9519, 289, 20553, 15392, 29190, 13645, 20878, 9809, 27820, 16522, 591, 26638, 18583, 18238, 3052, 13160, 12641, 19752, 26473, 6687, 2277, 1915, 2199, 28989, 19240, 9929, 21063, 6300, 4103, 19237, 7616, 29879, 27296, 20918, 21167, 3109, 800, 5547, 25058, 2740, 7279, 27424, 4591, 3150, 1640, 18957, 5346, 11055, 4543, 11985, 13022, 28329, 12455, 14676, 6404, 11092, 9220, 13914, 9022, 14327, 14740, 20205, 14815, 4274, 8795, 25959, 2394, 21355, 3930, 17231, 18711, 2214, 11885, 12627, 4488, 8863, 3838, 15405, 1674, 24951, 28291, 26535, 11452, 7944, 22342, 14596, 22714, 15199, 2764, 21410, 24751, 20156, 12257, 9093, 16462, 27373, 25027, 12734, 3943, 2815, 5366, 16917, 8597, 29067, 22532, 19709, 3167, 29869, 2325, 958, 2894, 10233, 16791, 3676, 16894, 4842, 6757, 9801, 21501, 22972, 6815, 7143, 9903, 19999, 5593, 28460, 21900, 6109, 19004, 21647, 9176, 19324, 22663, 2506, 10809, 3, 3306, 8135, 15670, 4895, 21942, 21103, 14347, 28217, 25010, 244, 27154, 29005, 16116, 2614, 4937, 26854, 15074, 8564, 21163, 25787, 22448, 19901, 21218, 14828, 18186, 12368, 2985, 8792, 17962, 6809, 25616, 21127, 13163, 27963, 2596, 19095, 21412, 22264, 5644, 1287, 2000, 13926, 16775, 25402, 23094, 14953, 27036, 21967, 3256, 13645, 13703, 9154, 8828, 935, 9860, 24716, 29583, 50, 15516, 14114, 12028, 23626, 5838, 26448, 4686, 15830, 4584, 14031, 6889, 10889, 21521, 6074, 7118, 28644, 9247, 14856, 13458, 4423, 20413, 5075, 6608, 14720, 15209, 18671, 6526, 23912, 25386, 8033, 20527, 19014, 11586, 24545, 17384, 10520, 22492, 2383, 11724, 22296, 10298, 8836, 25938, 23047, 7649, 1515, 6195, 27968, 11493, 21137, 29092, 5680, 21079, 11339, 7559, 16404, 19298, 27490, 3232, 27273, 16633, 27272, 22838, 1913, 15371, 7454, 18847, 24003, 14756, 13113, 25405, 7220, 9175, 11296, 691, 24508, 21348, 10307, 27845, 18615, 3630, 5673, 6845, 4370, 2176, 12095, 9045, 27948, 16, 13998, 8406, 12409, 24990, 15242, 7754, 14975, 11884, 5366, 29233, 6647, 11000, 4977, 18517, 16654, 20552, 10390, 27903, 28516, 27753, 22878, 18415, 13758, 6713, 13641, 15498, 21384, 25209, 23199, 1928, 16874, 13709, 1808, 8080, 11741, 2893, 16778, 15089, 6526, 9796, 1182, 24217, 25472, 13834, 878, 17420, 15348, 18459, 18470, 27844, 29215, 22939, 317, 8921, 24817, 24085, 11020, 5870, 8489, 8782, 17984, 18720, 9371, 29008, 457, 22583, 21722, 24124, 28485, 23979, 22085, 2968, 13357, 25765, 29267, 17444, 26514, 5535, 22518, 1193, 4700, 1440, 27136, 28957, 21331, 103, 4580, 19631, 23326, 28319, 28281, 15915, 10089, 4622, 6249, 11000, 7921, 8603, 25528, 13999, 25388, 27051, 8185, 18786, 13487, 8820, 10363, 4023, 19943, 10924, 27682, 4511, 12203, 28927, 15039, 18880, 27679, 1911, 8130, 5098, 19139, 18187, 2791, 6852, 14814, 9567, 26702, 12290, 9766, 4848, 8507, 2738, 7817, 463, 22633, 17511, 1991, 10386, 6990, 4144, 27099, 18506, 5238, 15113, 26729, 7517, 29817, 4539, 20568, 1817, 349, 14491, 2043, 15592, 13684, 19049, 28199, 5518, 15902, 6695, 22481, 8467, 5234, 15614, 16378, 24028, 13196, 11827, 1468, 4947, 25793, 20322, 19576, 518, 7960, 16069, 5091, 28541, 25596, 20452, 10158, 12705, 27117, 3692, 6781, 12674, 23757, 1825, 1302, 14580, 16148, 29990, 7425, 19019, 7460, 17224, 4185, 27241, 21729, 416, 2890, 26492, 22281, 16901, 21784, 22425, 29042, 6780, 15305, 26796, 4108, 26726, 1771, 2788, 6421, 23235, 7795, 26485, 11834, 26621, 19656, 3522, 8222, 9600, 25181, 28169, 21049, 13363, 15594, 20096, 7459, 14470, 1611, 19513, 15783, 11072, 16114, 26209, 5063, 25328, 19097, 15766, 16992, 21771, 11561, 26537, 15255, 4914, 19485, 6820, 7318, 3490, 29421, 15137, 21129, 22666, 23867, 6737, 29790, 27040, 13282, 27306, 23892, 19847, 8988, 10478, 7451, 11145, 10889, 7375, 6660, 5714, 2008, 24118, 23161, 12782, 16740, 23707, 23475, 6424, 10186, 5896, 6766, 23154, 15599, 5157, 6021, 29977, 3050, 13244, 11223, 26969, 18431, 3157, 14115, 25697, 21809, 4826, 10745, 18970, 13782, 17493, 10790, 13891, 4000, 23443, 18836, 8688, 12481, 7644, 18279, 9749, 9866, 16305, 671, 19515, 19294, 2295, 25000, 1801, 16184, 20349, 3035, 24983, 5384, 14093, 3581, 29797, 15817, 6810, 26218, 5857, 16115, 24622, 28261, 24854, 25421, 10101, 773, 22999, 11425, 7964, 25112, 3955, 28547, 124, 11711, 22657, 6623, 8014, 7945, 23191, 13785, 23109, 26364, 18597, 28410, 15901, 11633, 19788, 1583, 13877, 25568, 17669, 24376, 27910, 27027, 15641, 20266, 17599, 23540, 26942, 18282, 20451, 23044, 22272, 4038, 20271, 579, 25136, 17636, 28648, 15173, 5787, 15005, 26882, 65, 22913, 24624, 21968, 23510, 20746, 18984, 28467, 13235, 19112, 16858, 22610, 28027, 22180, 17047, 7587, 11925, 24577, 29299, 8081, 28150, 11902, 19016, 10158, 28351, 15739, 12253, 24159, 29444, 27101, 20228, 3552, 16818, 27026, 10115, 1065, 16400, 11406, 6282, 11418, 28599, 29547, 5725, 26929, 25827, 24555, 28428, 9175, 29688, 4470, 19972, 12079, 24152, 27032, 4750, 18466, 15619, 3063, 10892, 9426, 4058, 9820, 24214, 9048, 10985, 4119, 11216, 14890, 14364, 4856, 17339, 21265, 11197, 4726, 23629, 29548, 12013, 8219, 29526, 3414, 20549, 13686, 26919, 16945, 19707, 9516, 3954, 5167, 4053, 27594, 14661, 24003, 492, 5334, 3517, 6354, 21485, 22812, 23920, 22660, 21012, 22278, 12039, 7443, 29011, 3327, 11733, 8323, 18581, 4012, 5477, 25784, 24645, 24636, 17435, 21700, 23446, 16739, 27902, 20956, 24634, 16088, 4526, 20484, 5332, 14281, 24873, 4748, 24767, 13680, 12590, 24035, 12435, 20785, 1121, 12005, 14557, 7791, 16026, 20825, 25853, 18695, 25216, 5199, 19695, 17837, 20020, 25595, 21146, 3597, 11267, 11115, 28346, 14759, 9788, 25018, 28823, 5201, 18903, 3713, 22169, 22848, 21574, 10807, 24230, 6714, 20370, 17612, 26808, 16535, 1311, 1989, 21468, 10446, 15488, 4425, 19419, 16902, 14802, 9699, 29591, 16378, 10276, 14923, 19853, 27863, 557, 12426, 26966, 1904, 25941, 10999, 16593, 19618, 28493, 24078, 25217, 27932, 15210, 10104, 11123, 6247, 8397, 25540, 17959, 18369, 21161, 28027, 21943, 27659, 14298, 26581, 3674, 23001, 22189, 13497, 29762, 5311, 7606, 3719, 4092, 2307, 11728, 23245, 17399, 23666, 27260, 25921, 5880, 8499, 6093, 25669, 24003, 11586, 12149, 25213, 21410, 10377, 8155, 22363, 20276, 26195, 14477, 19287, 6606, 21719, 12297, 20833, 23318, 29784, 20212, 15642, 11320, 24756, 2910, 1419, 5178, 20617, 4508, 29259, 23541, 17869, 14735, 13314, 16260, 934, 6028, 24556, 8783, 29843, 3453, 14160, 9299, 892, 9580, 25918, 17967, 4372, 26610, 25112, 9072, 23122, 1619, 17508, 18878, 26721, 29164, 17661, 21228, 14958, 23815, 18016, 10071, 14671, 26291, 4631, 4576, 20872, 24474, 11045, 8866, 15129, 17532, 21914, 4742, 10949, 5231, 5587, 25026, 25211, 10698, 1611, 15833, 2944, 3094, 26873, 20880, 27674, 17594, 12845, 23163, 11608, 25132, 13726, 11978, 13670, 15322, 23667, 11940, 2846, 14267, 28773, 1047, 2444, 1609, 13112, 27173, 2009, 11356, 9682, 1348, 24100, 11967, 9994, 19853, 1192, 6597, 1980, 7563, 14618, 10542, 21528, 29637, 6428, 18135, 685, 6067, 17531, 3941, 25442, 17243, 2298, 27202, 9143, 27238, 5281, 7060, 15142, 28116, 18954, 19033, 2418, 2009, 17744, 27150, 22997, 26094, 4680, 9409, 2950, 13214, 21528, 4393, 17554, 29909, 16235, 23420, 18994, 22495, 11547, 5179, 21115, 28695, 7727, 28943, 28859, 12324, 5506, 18476, 5096, 10389, 23537, 18187, 29307, 5661, 27259, 16466, 12006, 11344, 19324, 17183, 17146, 10089, 23685, 7592, 26949, 28799, 6041, 11832, 25992, 294, 1734, 22774, 27761, 24772, 29801, 5549, 4333, 21988, 599, 28721, 27825, 13939, 23146, 22884, 21068, 25914, 24470, 5225, 13097, 10882, 7063, 1014, 2341, 7138, 24297, 2843, 23316, 16626, 18950, 6759, 16624, 5776, 9218, 13225, 23848, 8949, 9063, 5128, 8495, 12092, 7591, 15126, 22666, 12342, 6515, 11528, 3056, 27359, 6758, 1892, 16273, 24030, 17379, 23738, 13131, 4421, 3126, 17747, 5813, 24983, 26073, 6783, 14464, 21486, 18659, 1192, 18971, 3801, 12691, 9387, 12299, 8791, 6810, 17945, 9159, 15797, 23437, 21356, 5507, 11704, 11363, 4331, 20348, 21575, 1931, 26907, 27359, 725, 8030, 15387, 3692, 15272, 8864, 29418, 19295, 28350, 12915, 23793, 18197, 8623, 21383, 20216, 1117, 7676, 21379, 26806, 7460, 20733, 16715, 8824, 1162, 15743, 20488, 27449, 8354, 29800, 17007, 28845, 19069, 1121, 15352, 15451, 16703, 22859, 26180, 18899, 900, 23977, 26191, 10153, 16452, 17395, 23783, 5835, 22960, 12730, 7899, 15258, 3443, 26554, 18270, 18766, 25983, 3107, 15181, 15531, 4470, 11126, 3635, 20355, 13089, 21393, 27308, 2244, 18069, 28584, 19777, 27998, 16775, 8918, 1891, 5882, 6357, 9822, 6000, 12831, 10303, 21993, 24433, 24362, 16916, 29737, 28501, 28082, 19977, 4997, 23292, 14215, 13106, 22466, 14184, 7404, 18529, 10188, 3680, 5698, 21066, 14499, 10578, 1451 };
	{ 3,2,2,1 };
	int limit = 3;//29998;// 6;// 8; //5;//
	int peopleSize = sizeof(people) / sizeof(people[0]);

	numRescueBoats(people, peopleSize, limit);
}

/*
28. 实现strStr()

实现 strStr() 函数。
给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

示例 1:
输入: haystack = "hello", needle = "ll"
输出: 2

示例 2:
输入: haystack = "aaaaa", needle = "bba"
输出: -1

说明:
当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
对于本题而言，当 needle 是空字符串时我们应当返回 0 。
这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
*/
int strStr(char* haystack, char* needle) {

	int h = strlen(haystack);
	int n = strlen(needle);
	int i = 0, j = 0, f = 0, k = 0;

	for (i = 0; i < h; i++)
	{
		if (haystack[i] == needle[j])
		{
			printf("[%d] %c %c \n", i, haystack[i], needle[j]);
			if (j == 0) k = i;
			j++;
		}
		else
		{
			if (j > 0 && j != n)
			{
				i = k;
				j = 0;
			}
		}
	}
	if (j == n)
	{
		printf("%d \n", k);
		return k;
	}
	else
	{
		printf("error\n");
		return -1;
	}
}

void ID28()
{
	char *haystack =
	"mississippi";//"hellox";
	char *needle =
		"issip";// ;// "ll"; //"pi"; //

	strStr(haystack, needle);
}

/*
227. 基本计算器 II

实现一个基本的计算器来计算一个简单的字符串表达式的值。
字符串表达式仅包含非负整数，+， - ，*，/ 四种运算符和空格  。 整数除法仅保留整数部分。

示例 1:
输入: "3+2*2"
输出: 7

示例 2:
输入: " 3/2 "
输出: 1

示例 3:
输入: " 3+5 / 2 "
输出: 5

说明：
你可以假设所给定的表达式都是有效的。
请不要使用内置的库函数 eval。
*/
int calculate(char* s) {

	int l = strlen(s);
	int i = 0, j = 0, k = 0, n = 0, m = 0;
	char temp[10] = { 0 };
	int cal[10] = { 0 };
	int cal_ = 0;
	char control[10] = { 0 };
	char sum2[10] = { 0 };

	for (i = 0; i <= l; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			temp[j++] = s[i];
		}
		else if (s[i] == ' ')
			continue;
		else
		{
			control[n++] = s[i];
			cal[k++] = (int)atof(temp);
			printf("%d%c", cal[k-1], control[n-1]);
			memset(temp, 0x00, 10);
			j = 0;
		}
	}
	for (i = 0; i < n; i++)
	{
		//printf("%d ",)
		int t[10] = { 0 };
		if (control[i] == '*')
		{

		}
		else if(control[i] == '/')
		{

		}
	}
}

void ID227()
{
	char * s =
		"334+51 / 29";
	calculate(s);
}

/*
345. 反转字符串中的元音字母

编写一个函数，以字符串作为输入，反转该字符串中的元音字母。

示例 1:

输入: "hello"
输出: "holle"

示例 2:

输入: "leetcode"
输出: "leotcede"

说明:
元音字母不包含字母"y"。
*/

char* reverseVowels(char* s) {//测试：输入字符串太大，malloc出错

	int s_size = strlen(s);
	char *dest = malloc(sizeof(char) * s_size);
	int i = 0, j = 0, k = 0;
	char temp[20] = { 0 };

	for (i = 0; i < s_size; i++)
	{
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
		{
			temp[j++] = s[i];
		}
	}
	j--;
	for (i = 0; i < s_size; i++)
	{
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
		{
			dest[i] = temp[j--];
		}
		else
			dest[i] = s[i];
	}
	dest[s_size] = '\0';
	printf("%s \n", dest);
	return dest;
}

void ID345()
{
	char *s =
		//"leetcode";
		"\"Revolt love!\" raved Eva. \"Revolt lover!\" ";
	reverseVowels(s);
}

/*
657. 机器人能否返回原点

在二维平面上，有一个机器人从原点 (0, 0) 开始。给出它的移动顺序，判断这个机器人在完成移动后是否在 (0, 0) 处结束。
移动顺序由字符串表示。字符 move[i] 表示其第 i 次移动。机器人的有效动作有 R（右），L（左），U（上）和 D（下）。如果机器人在完成所有动作后返回原点，则返回 true。否则，返回 false。
注意：机器人“面朝”的方向无关紧要。 “R” 将始终使机器人向右移动一次，“L” 将始终向左移动等。此外，假设每次移动机器人的移动幅度相同。


示例 1:
输入: "UD"
输出: true
解释：机器人向上移动一次，然后向下移动一次。所有动作都具有相同的幅度，因此它最终回到它开始的原点。因此，我们返回 true。

示例 2:
输入: "LL"
输出: false
解释：机器人向左移动两次。它最终位于原点的左侧，距原点有两次 “移动” 的距离。我们返回 false，因为它在移动结束时没有返回原点。
*/

bool judgeCircle(char* moves) {

	int moves_long = strlen(moves);
	int i = 0;
	int U = 0, D = 0, L = 0, R = 0;

	for (i = 0; i < moves_long; i++)
	{
		if (moves[i] == 'U')
			U++;
		else if (moves[i] == 'D')
			D++;
		else if (moves[i] == 'L')
			L++;
		else if (moves[i] == 'R')
			R++;
	}
	printf("U=%d, D=%d, L=%d, R=%d \n", U, D, L, R);

	if (U == D && L == R)
		return true;
	else
		return false;
}

void ID657()
{
	char *moves =
		"UD";
	judgeCircle(moves);
}

/*
5. 最长回文子串

给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为1000。

示例 1：
输入: "babad"
输出: "bab"
注意: "aba"也是一个有效答案。

示例 2：
输入: "cbbd"
输出: "bb"
*/
char* longestPalindrome(char* s) {

	int s_long = strlen(s);
	int i = 0, n = 0, m = 0, j = 0, k = 0, max = 0;
	char *dest = (char *)malloc(sizeof(char) * s_long);

	for (i = 1; i < s_long; i++)
	{
		n = i;
		m = i;
		k = 0;
		while (1)
		{
			if (n < 1 || m>s_long - 1)
				break;
			if (s[n] == s[m])
			{
				n--;
				m++;
				k++;
			}
			else
				break;
		}
		if (2 * k - 1 > max)
		{
			max = 2 * k - 1;
			memcpy(dest, &s[n + 1], max);
			dest[max] = '\0';
			printf("%s :", dest);
			printf("max = %d [n,m]=[%d,%d] \n", max, n, m);
		}
	}
	return dest;
}

void ID5()
{
	char *s =
		"cbbd";
		//"babad";
		//"babadabedsfghdbj";
	longestPalindrome(s);
}

/*
397. 整数替换

给定一个正整数 n，你可以做如下操作：

1. 如果 n 是偶数，则用 n / 2替换 n。
2. 如果 n 是奇数，则可以用 n + 1或n - 1替换 n。
n 变为 1 所需的最小替换次数是多少？

示例 1:
输入:
8
输出:
3
解释:
8 -> 4 -> 2 -> 1

示例 2:
输入:
7
输出:
4
解释:
7 -> 8 -> 4 -> 2 -> 1
或
7 -> 6 -> 3 -> 2 -> 1
*/
int integerReplacement(int n) {

   int dest = n, time = 0;

   if (n == INT_MAX) return 32;

	while (dest > 1)
	{
		if (dest % 2 == 0)
			dest = dest / 2;
		else if (dest == 3)
			dest = dest - 1;
		else if ((dest + 1) / 2 % 2 == 0)
			dest = dest + 1;
		else
			dest = dest - 1;
		printf("%d  ", dest);
		time++;
	}
	printf("time = %d \n", time);
	return time;
}

void ID397()
{
	INT_MAX;
	integerReplacement(2147483647);// 103);
}

/*
414. 第三大的数

给定一个非空数组，返回此数组中第三大的数。如果不存在，则返回数组中最大的数。要求算法时间复杂度必须是O(n)。

示例 1:
输入: [3, 2, 1]
输出: 1
解释: 第三大的数是 1.

示例 2:
输入: [1, 2]
输出: 2
解释: 第三大的数不存在, 所以返回最大的数 2 .

示例 3:
输入: [2, 2, 3, 1]
输出: 1
解释: 注意，要求返回第三大的数，是指第三大且唯一出现的数。
存在两个值为2的数，它们都排第二。
*/
int thirdMax(long* nums, int numsSize) {

	int a = INT_MIN, b = INT_MIN, c = INT_MIN;
	int i = 0, j = 0;
	printf("numsSize = %d \n", numsSize);

	for (i = 0; i < numsSize; i++)
	{
		if (nums[i] > a)
		{
			a = nums[i];
		}
	}
	for (i = 0; i < numsSize; i++)
	{
		if (nums[i] > b && nums[i] != a)
			b = nums[i];
	}
	for (i = 0; i < numsSize; i++)
	{
		if (nums[i] > c && nums[i] != a && nums[i] != b)
			c = nums[i];
	}
	printf("a = %d, b = %d, c = %d \n", a, b, c); 

	return c;
}

void ID414()
{
	int nums[] =
	{ -1,-2,-3 };
	//{ 1, 2, -2147483648 };
	//{1,2,2,2,2};
		//{ 1,2,3,4,4,5,6 };
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	thirdMax(nums, numsSize);
}

/*
693. 交替位二进制数
*/
bool hasAlternatingBits(int n) {

	int i = 0, j = 0;
	int dest = n;
	int c[32] = { 0 };

	while(dest > 0)
	{
		if (dest % 2 == 0)
			c[j] = 0;
		else
			c[j] = 1;
		printf("%d ", c[j]);
		j++;
		//printf("%d ", dest);
		dest = dest / 2;
	}
	for (i = 0; i < j; i++)
	{
		if (c[i] == c[i + 1])
			return 0;
	}
	return 1;
}

void ID693()
{
	printf("\n%d\n",hasAlternatingBits(345));
}

/*
268. 缺失数字

给定一个包含 0, 1, 2, ..., n 中 n 个数的序列，找出 0 .. n 中没有出现在序列中的那个数。

示例 1:
输入: [3,0,1]
输出: 2

示例 2:
输入: [9,6,4,2,3,5,7,0,1]
输出: 8

说明:
你的算法应具有线性时间复杂度。你能否仅使用额外常数空间来实现?
*/
int missingNumber(int* nums, int numsSize) {

	if (numsSize == 1 && nums[0] == 1) return 0;

	int i = 0, sum = 0, max = -1;
	for (i = 0; i < numsSize; i++)
	{
		if (nums[i] > max)
			max = nums[i];
		sum = sum + nums[i];
	}
	if (numsSize == max + 1) return numsSize;
	return ((1 + max)*max / 2) - sum;
}

void ID268()
{
	int nums[] =
	{ 1,2 };
	//{ 9,6,4,2,3,5,7,0,1 };
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	printf("%d \n",missingNumber(nums, numsSize));
}

/*
413. 等差数列划分

如果一个数列至少有三个元素，并且任意两个相邻元素之差相同，则称该数列为等差数列。

例如，以下数列为等差数列:
1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9

以下数列不是等差数列。
1, 1, 2, 5, 7

数组 A 包含 N 个数，且索引从0开始。数组 A 的一个子数组划分为数组 (P, Q)，P 与 Q 是整数且满足 0<=P<Q<N 。
如果满足以下条件，则称子数组(P, Q)为等差数组：
元素 A[P], A[p + 1], ..., A[Q - 1], A[Q] 是等差的。并且 P + 1 < Q 。
函数要返回数组 A 中所有为等差数组的子数组个数。


示例:
A = [1, 2, 3, 4]
返回: 3, A 中有三个子等差数组: [1, 2, 3], [2, 3, 4] 以及自身 [1, 2, 3, 4]。
*///通过
int numberOfArithmeticSlices(int* A, int ASize) {

	int i = 0, j = 0;
	int count = 0, f = 0;

	for (i = 0; i < ASize-2; i++)
	{
		j = i;
		while (1)
		{
			if (A[j + 2] - A[j + 1] == A[j + 1] - A[j])
			{
				f = 1;
				j++;
				if(j > ASize -2)
				break;
			}
			else break;
			if (f) {
				f = 0;
				count++;
			}
		}
	}
	printf("count = %d \n", count);
	return count;
}

void ID413()
{
	int A[] =
	{ 1,2,3,4,5,6 };
	numberOfArithmeticSlices(A, sizeof(A) / sizeof(A[0]));
}

/*
537. 复数乘法

给定两个表示复数的字符串。
返回表示它们乘积的字符串。注意，根据定义 i2 = -1 。

示例 1:
输入: "1+1i", "1+1i"
输出: "0+2i"
解释: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i ，你需要将它转换为 0+2i 的形式。

示例 2:
输入: "1+-1i", "1+-1i"
输出: "0+-2i"
解释: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i ，你需要将它转换为 0+-2i 的形式。

注意:
输入字符串不包含额外的空格。
输入字符串将以 a+bi 的形式给出，其中整数 a 和 b 的范围均在 [-100, 100] 之间。输出也应当符合这种形式。
*/
char* complexNumberMultiply(char* a, char* b) {

	int a_long = strlen(a), b_long = strlen(b);
	int i = 0, j = 0;
	int a1 = 0, a2 = 0, b1 = 0, b2 = 0;

	for (i = 0; i < a_long; i++)
	{
		if (a[i] != '+');
	}
}

void ID537()
{
	char *a =
		"1+1i";
	char *b =
		"1+1i";

	complexNumberMultiply(a, b);
}

/*
125. 验证回文串

给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
说明：本题中，我们将空字符串定义为有效的回文串。

示例 1:
输入: "A man, a plan, a canal: Panama"
输出: true

示例 2:
输入: "race a car"
输出: false
*/
bool isPalindrome125(char* s) {

	int s_long = strlen(s);
	int i = 0, j = 0, f = 0;
	//printf("%d %d %d\n", s_long, 'a', 'A');
	char * dest = (char *)malloc(sizeof(char)*(s_long+1));

	for (i = 0; i < s_long; i++)
	{
		if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
			 dest[j++] = s[i];
		else if(s[i] >= 'A' && s[i] <= 'Z')
			dest[j++] = s[i]+32;
	}
	//dest[j] = '\0';printf("%s\n (%d) \n", dest,j);
	j = j - 1;
	for (i = 0; i <= j; i++,j--)
	{
		//printf("%c %c \n", dest[i], dest[j]);
		if (dest[i] != dest[j])
		{
			f = 1;
			break;
		}
		if (i == j) break;
	}
	printf("\n%d %d %d \n", f,i,j);
}

void ID125()
{
	char *s =
		//"A man, a plan, a canal: Panama";
		//"race a car";
		"QZrD2 7UL91z,i`O2ef:6e'2\"yP !:,U.:pX90PU3CXo'i!;3 `j 0?\"'hK8 ? BAjM2\"DBw?7!4R3?U2E8F2y!?3 R2!fw 6e!:0  ErCi98KM`,8`8648,mi3P0`,!5 E.?00J3A 52\"x8,tHy!'2!DLBbK'j!tt1C' 7`JPulW\"\"uRTbr\"',\",U`ZOW5'\"LMDQDMJ\"'5WOZ`U,\",'\"rbTRu\"\"WluPJ`7 'C1tt!j'KbBJD!2'!yHt,8x\"25 A3J00?.E 5!,`0P3im,8468`8,`MK89iCrE  0:!e6 wf!2R 3?!y2F8E2U?3R4!7?wBD\"2MjAB ? 8Kh'\"?0 j` 3;!i'oXC3UP09Xp:.U,:! Py\"2'e6:fe2O`i,z19LU7 2DrZQ";
	isPalindrome125(s);
}

/*
583. 两个字符串的删除操作

给定两个单词 word1 和 word2，找到使得 word1 和 word2 相同所需的最小步数，每步可以删除任意一个字符串中的一个字符。

示例 1:
输入: "sea", "eat"
输出: 2
解释: 第一步将"sea"变为"ea"，第二步将"eat"变为"ea"

说明:
给定单词的长度不超过500。
给定单词中的字符只含有小写字母。
*/
int minDistance(char* word1, char* word2) {

	int word1_long = strlen(word1), word2_long = strlen(word2);
	int i = 0, j = 0;

	while (1)
	{
		if (word1[i] != word2[j])
		{
			i++;
		}
	}
}

/*
41. 缺失的第一个正数

给定一个未排序的整数数组，找出其中没有出现的最小的正整数。

示例 1:
输入: [1,2,0]
输出: 3

示例 2:
输入: [3,4,-1,1]
输出: 2

示例 3:
输入: [7,8,9,11,12]
输出: 1

说明:
你的算法的时间复杂度应为O(n)，并且只能使用常数级别的空间。
*/
int firstMissingPositive1(int* nums, int numsSize) {

	int i = 0;
	int min = INT_MAX;

	for (i = 0; i < numsSize; i++)
	{
		if (nums[i] > 0 && nums[i] < min)
		{
			min = nums[i];
		}
	}
	printf("min = %d \n", min);
}

int firstMissingPositive(int* nums, int numsSize) {

	int i = 0, j = 0, f = 0;
	for (i = 1; i < 1000; i++)
	{
		f = 0;
		for (j = 0; j < numsSize; j++)
		{
			if (nums[j] == i)//nums[j] > 0 && 
			{
				f = 1;
				break;
			}
		}
		if (f==0) {
			printf("min = %d \n", i);
			break;
		}
	}
	return i;
}

void ID41()
{
	int nums[] =
	//{ 3,4,-1,1 };
	{ 0,-1,7,8,9,11,12 };
	int numsSize = sizeof(nums) / sizeof(nums[0]);

	firstMissingPositive(nums, numsSize);
}

/*
11. 盛最多水的容器

给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器，且 n 的值至少为 2。
图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。


示例:
输入: [1,8,6,2,5,4,8,3,7]
输出: 49
*/

#define _min(a, b) (((a) < (b)) ? (a) : (b))

int maxArea(int* height, int heightSize) {

	int i = 0, j = 0;
	int temp = 0, max = 0;
	//if (heightSize == 2) return (_min(height[0], height[1]));
	for (i = 0; i < heightSize; i++)
	{
		for(j = i + 1; j < heightSize; j++)
		{
			temp = (_min(height[i], height[j])) *(j - i);
			if (temp > max)
				max = temp;
		}
	}
	printf("max = %d \n", max);
	return max;
}

void ID11()
{
	int *height[] =
		//{ 1,8,6,2,5,4,8,3,7 };
	//{1,1};
	{ 2,3,4,5,18,17,6 };
	int heightSize = sizeof(height) / sizeof(height[0]);

	maxArea(height, heightSize);
}

/*
3. 无重复字符的最长子串

给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:
输入: "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

示例 2:
输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

示例 3:
输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
*/
int xlengthOfLongestSubstring(char* s) {

	int s_long = strlen(s);
	int i = 0, j = 0;
	char search[26] = { 0 };
	for (i = 0; i < s_long; i++)
	{
		j = s[i] - 'a';
		search[j]++;
		if (search[j] > 1)
			break;
	}
	printf("%d \n", i);
}

void xID3()
{
	char *s = "pwwkew";
	lengthOfLongestSubstring(s);
}

/*
69. x 的平方根

实现 int sqrt(int x) 函数。

计算并返回 x 的平方根，其中 x 是非负整数。

由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

示例 1:
输入: 4
输出: 2

示例 2:
输入: 8
输出: 2
说明: 8 的平方根是 2.82842...,
由于返回类型是整数，小数部分将被舍去。
*/
int mySqrt(int x) {

	int i = 0;
	for (i = x/2; i < x; i++)
	{
		if (i*i == x) break;
		if (i*i < x && (i + 1)*(i + 1) > x)
		{
			break;
		}
	}
	printf("%d \n", i);
	return i;
}

void ID69()
{
	mySqrt(INT_MAX);
}

/*
202. 快乐数

编写一个算法来判断一个数是不是“快乐数”。

一个“快乐数”定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，
然后重复这个过程直到这个数变为 1，也可能是无限循环但始终变不到 1。
如果可以变为 1，那么这个数就是快乐数。

示例:
输入: 19
输出: true
解释:
1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1
*/
bool isHappy(int n) {

}

void ID202()
{
	isHappy(19);
}

/*
128. 最长连续序列

给定一个未排序的整数数组，找出最长连续序列的长度。

要求算法的时间复杂度为 O(n)。

示例:
输入: [100, 4, 200, 1, 3, 2]
输出: 4
解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。
*/
int longestConsecutive(int* nums, int numsSize) {

}

void ID128()
{
	int nums[] = { 100, 4, 200, 1, 3, 2 };
	longestConsecutive(nums, sizeof(nums) / sizeof(nums[0]));
}

/*
97. 交错字符串

给定三个字符串 s1, s2, s3, 验证 s3 是否是由 s1 和 s2 交错组成的。

示例 1:
输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
输出: true

示例 2:
输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
输出: false
*/
bool isInterleave(char* s1, char* s2, char* s3) {

	int s1_long = strlen(s1), s2_long = strlen(s2), s3_long = strlen(s3);
	int i = 0, j = 0, k = 0;

	for (i = 0; i < s3_long; i++)
	{
		if (s3[i] == s1[j++])
		{

		}
		else if (s3[i] == s2[k++])
		{
			
		}
	}
}

void ID97()
{
	char *s1 = "aabcc";
	char *s2 = "dbbca";
	char *s3 = "adabbbcacc";
	isInterleave(s1, s2, s3);
}

/*
696. 计数二进制子串

给定一个字符串 s，计算具有相同数量0和1的非空(连续)子字符串的数量，
并且这些子字符串中的所有0和所有1都是组合在一起的。重复出现的子串要计算它们出现的次数。

示例 1 :
输入: "00110011"
输出: 6
解释: 有6个子串具有相同数量的连续1和0：“0011”，“01”，“1100”，“10”，“0011” 和 “01”。

请注意，一些重复出现的子串要计算它们出现的次数。
另外，“00110011”不是有效的子串，因为所有的0（和1）没有组合在一起。

示例 2 :
输入: "10101"
输出: 4
解释: 有4个子串：“10”，“01”，“10”，“01”，它们具有相同数量的连续1和0。

注意：
s.length 在1到50,000之间。
s 只包含“0”或“1”字符。
*/
int countBinarySubstrings(char* s) {

	int s_long = strlen(s);
	int i = 0, j = 0, k = 0;
	printf("long = %d \n", s_long);
	int count = 0;

	for (i = 0; i < s_long; i++)
	{
		int a = 0, b = 0, c = 0, d = 0;
		for (j = i; j < s_long; j++)
		{
			if (s[j] == '0'&& b == 0 && c == 0)
			{
				a++;
			}
			else if (s[j] == '1' && a == 0 && d == 0)
			{
				b++;
			}
			else if (s[j] == '1' && b == 0 && a > 0)
			{
				c++;
			}
			else if (s[j] == '0' && a == 0 && b > 0)
			{
				d++;
			}
			else if ((c > 0 && a > 0) || (d > 0 && b > 0))
			{
				break;
			}
		}
		
		if ((a > c) || (b > d)) continue;
		if ((c > 0 && a > 0) || (d > 0 && b > 0))
		{
			  //一段段计算，跳过一组的前面部分，将一组中小的值递加为次数
			if (c > 0 && a > 0) {
				i = i + a-1; count += min(a, c);
			}
			else { 
				i = i + b-1; count += min(b, d);
			}
			//count++;
		}
		printf("%d %d %d %d  [count = %d]\n", a, b, c, d, count);
	}
}
/*  //别人的算法。将连续的个数统计到数组中，然后取两者的最小值，递加。
int countBinarySubstrings(char* s) {
int count = 0, index = 0;
int group[50000];
int len = strlen(s);
group[0] = 1;
for (int i = 0; i < len-1; i++)
{
if (s[i] != s[i + 1])
group[++index] = 1;
else
group[index]++;
}
for (int i = 1; i <= index; i++)
{
count += min(group[i], group[i - 1]);
}
return count;
}
*/
void ID696()
{
	char s[] =
		//"00110011"
		//"10101"
		//"00110"
		//"11001"
		"1011001001"
		//"001001"
		//"000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000011111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111100000000000000000000000000000000000000000000000000000000000001111111111111111111111111111111111111111111111111111111111111000000000000000000000000000000000000000000000000000000000000000000000000000000000011111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110000000000000000000000000000000000000000000000000000000001111100000010011"
		;
	countBinarySubstrings(s);
}

/*
949. 给定数字能组成的最大时间

给定一个由 4 位数字组成的数组，返回可以设置的符合 24 小时制的最大时间。
最小的 24 小时制时间是 00:00，而最大的是 23:59。从 00:00 （午夜）开始算起，过得越久，时间越大。
以长度为 5 的字符串返回答案。如果不能确定有效时间，则返回空字符串。

示例 1：
输入：[1,2,3,4]
输出："23:41"

示例 2：
输入：[5,5,5,5]
输出：""

提示：
A.length == 4
0 <= A[i] <= 9
*/
char* largestTimeFromDigits(int* A, int ASize) 
{
	int i = 0, j = 0, k = 0, l = 0, n = 0;
	int max = 0;

	char *r = (char *)malloc(sizeof(char) * 6);
	for (i = 0; i < ASize; i++)
	{
		for (j = 0; j < ASize; j++)
		{
			for (k = 0; k < ASize; k++)
			{
				for (l = 0; l < ASize; l++)
				{
					if (i == j || i == k || i == l || j == k || j == l || k == l) continue;
					int temp = A[i] * 1000 + A[j] * 100 + A[k] * 10 + A[l];
					printf("temp = %04d \n", temp);
					if (temp > max && temp <= 2359)
						max = temp;
					//n++;printf("[%d]: %d %d %d %d \n",n, i, j, k, l);
				}
			}
		}
	}
	printf("max = %d \n", max);
	sprintf_s(r, 6, "%02d", max/100);
	r[2] = ':';
	sprintf_s(r + 3, 6, "%02d", max%100);
	return r;
}

char* largestTimeFromDigits1(int* A, int ASize) {

	char *r = (char *)malloc(sizeof(char)*20);
	int i = 0, j = 0;
	int max_m = -1, max_h =-1, max_i = 0, max_j = 0;

	printf("s = %s \n", A);

	if (A[0] == 0 && A[1] == 0 && A[2] == 0 && A[3] == 0)
	{
		r[0] = '0'; r[1] = '0'; r[2] = ':'; r[3] = '0'; r[4] = '0';
		return r;
	}

	for (i = 0; i < ASize; i++)
	{
		for (j = i + 1; j < ASize; j++)
		{
			int temp1 = A[i] * 10 + A[j], temp2 = A[j] * 10 + A[i];
			if (temp1 > 23) temp1 = -1;
			if (temp2 > 23) temp2 = -1;
			int temp = temp1 > temp2 ? temp1 : temp2;
			if (temp > max_h)
			{
				max_h = temp; max_i = i; max_j = j;
			}
			printf("temp1 = %d, temp2 = %d temp = %d [%d][%d] \n", temp1, temp2, temp, i, j);
		}
	}
	printf("max_h = %d, max_i = %d, max_j = %d \n", max_h, max_i, max_j);

	int a = -1, b = -1;
	for (i = 0; i < ASize; i++)
	{
		if (i == max_i || i == max_j) continue;
		if (a == -1) a = A[i]; else b = A[i];
	}
	int t1 = a * 10 + b, t2 = b * 10 + a;
	if (t1 > 59) t1 = -1;
	if (t2 > 59) t2 = -1;
	max_m = t1 > t2 ? t1 : t2;
	/*
	if (t1 >= t2 && t1 <= 59)
		max_m = t1;
	else if( t2 <= 59)//t2 > t1 &&
		max_m = t2;
		*/
	printf("max_m = %d \n", max_m);

	if (max_h == -1 || max_m == -1)
		return "";
	else
	{
		sprintf_s(r, 20,"%02d", max_h);
		r[2] = ':';
		sprintf_s(r+3, 17,"%02d", max_m);
		return r;
	}
}

void ID949()
{
	int A[] =
		//{2,2,5,5};
		//{ 1,2,3,4 };
		//{ 5,5,5,5 };
		//{ 0,0,0,0 };;
	//{ 0,0,1,0 };
	//{ 1,9,6,0 };
	//{ 7,3,6,0 };
	{ 2,0,6,6 };
    printf("%s \n",largestTimeFromDigits(A, sizeof(A)/sizeof(A[0])));
}

/*
728. 自除数

自除数 是指可以被它包含的每一位数除尽的数。

例如，128 是一个自除数，因为 128 % 1 == 0，128 % 2 == 0，128 % 8 == 0。
还有，自除数不允许包含 0 。
给定上边界和下边界数字，输出一个列表，列表的元素是边界（含边界）内所有的自除数。

示例 1：
输入：
上边界left = 1, 下边界right = 22
输出： [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]

注意：
每个输入参数的边界满足 1 <= left <= right <= 10000。

/*
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/ 
int num_selfdiv(int num)
{
	int temp = num, one = 0;
	while (temp)
	{
		one = temp % 10;
		if (one == 0) return false;
		if (num%one == 0 ) temp = temp / 10;
		else return false;
	}
	return true;
}

int* selfDividingNumbers(int left, int right, int* returnSize) {

	int *r = (int *)malloc(sizeof(int) * 1000);

	//printf("left = %d, ringht = %d \n", left, right);
	int i = 0, j = 0;
	for (i = left; i < right; i++)
	{
		if (num_selfdiv(i))
		{
			//printf("[%d] %d \n", i, t);
			r[j++] = i;
		}
	}

	*returnSize = j-1;
	return r;
}

void ID728(void)
{
	int b = 0;
	selfDividingNumbers(10, 1000, &b);
	printf("%d \n", b);
}

/*
168. Excel表列名称

给定一个正整数，返回它在 Excel 表中相对应的列名称。

例如，
1 -> A
2 -> B
3 -> C
...
26 -> Z
27 -> AA
28 -> AB
...

示例 1:
输入: 1
输出: "A"

示例 2:
输入: 28
输出: "AB"

示例 3:
输入: 701
输出: "ZY"
*/
char* convertToTitle(int n) {

	char * r = (char *)malloc(sizeof(char) * 10);
	int i = 0, j = 0, temp = n;

	while (temp)
	{
		if (temp % 26 == 0)
		{
			r[j++] = 'Z'; temp = temp - 1;
		}
		else
			r[j++] = temp % 26 + 'A' -1;
		if (temp <= 26) break;
		temp = temp / 26;
	}
	printf("%s \n", r);
	for (i = 0; i < j / 2; i++)
	{
		char t = r[i];
		r[i] = r[j - i-1];
		r[j - i-1] = t;
	}
	printf("%s \n", r);
	return r;
}

void ID168(void)
{
	convertToTitle(17576);
}

/*
171. Excel表列序号

给定一个Excel表格中的列名称，返回其相应的列序号。

例如，
A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28
...

示例 1:
输入: "A"
输出: 1

示例 2:
输入: "AB"
输出: 28

示例 3:
输入: "ZY"
输出: 701
*/
int titleToNumber(char* s) {

	int i = 0, s_long = strlen(s), dest = 0;
	for (i = 0; i < s_long; i++)
	{
		printf("%d ", s_long - 1 - i);
		if (i == s_long - 1) dest = dest + s[i] - 'A' + 1;
		else dest = dest + pow(26.0, (double)(s_long - 1 - i))*(s[i] - 'A'+1);
	}
	printf("dest = %d \n", dest);
	return dest;
}

void ID171()
{
	char *s =
		//"RFU";
		//"BMK";
		//"ZY";
		"AZ";
	titleToNumber(s);
}

/*
869. 重新排序得到 2 的幂

从正整数 N 开始，我们按任何顺序（包括原始顺序）将数字重新排序，注意其前导数字不能为零。
如果我们可以通过上述方式得到 2 的幂，返回 true；否则，返回 false。

示例 1：
输入：1
输出：true

示例 2：
输入：10
输出：false

示例 3：
输入：16
输出：true

示例 4：
输入：24
输出：false

示例 5：
输入：46
输出：true

提示：
1 <= N <= 10^9
}
*/
bool isTWOtimes(int N)
{
	int temp = N;
	while (temp)
	{
		if (temp % 2 != 0) break;
		else temp = temp / 2;
	}
	if (temp == 1) return true;
	else return false;
}

bool reorderedPowerOf2(int N) {

	int n[10] = { 0 };
	printf("%d \n", isTWOtimes(N));
	return 1;
}

void ID869()
{
	reorderedPowerOf2(163);
}

/*
878. 第 N 个神奇数字

如果正整数可以被 A 或 B 整除，那么它是神奇的。
返回第 N 个神奇数字。由于答案可能非常大，返回它模 10^9 + 7 的结果。

示例 1：
输入：N = 1, A = 2, B = 3
输出：2

示例 2：
输入：N = 4, A = 2, B = 3
输出：6

示例 3：
输入：N = 5, A = 2, B = 4
输出：10

示例 4：
输入：N = 3, A = 6, B = 4
输出：8

提示：
1 <= N <= 10^9
2 <= A <= 40000
2 <= B <= 40000
*/
int nthMagicalNumber(int N, int A, int B) {

	int i = 0, j = 0;
	for (i = 1; i < INT_MAX; i++)
	{
		if (A*i%B == 0)
		{
			j = j + 1; continue;
		}
		else
			j=j+2;

printf("[%d] = %d,%d \n", j, A*i, B*i);

		if (j >= N) break;
	}
	printf("dest = %d,%d \n", A*i, B*i);
	return 1;
}

void ID878()
{
	nthMagicalNumber(5,2,4);
}

/*
50. Pow(x, n)

实现 pow(x, n) ，即计算 x 的 n 次幂函数。

示例 1:
输入: 2.00000, 10
输出: 1024.00000

示例 2:
输入: 2.10000, 3
输出: 9.26100

示例 3:
输入: 2.00000, -2
输出: 0.25000
解释: 2^-2 = (1/2)^2 = 1/4 = 0.25

说明:
-100.0 < x < 100.0
n 是 32 位有符号整数，其数值范围是 [−231, 231 − 1] 。
*/
double myPow(double x, int n) {

	int i = 0;
	double dest = 1.0;
	int flag = n;
	if (n < 0) n = -n;
	if (x == 1.0) return x;
	for (i = 0; i < n; i++)
	{
		dest = dest * (double)x;
		if (dest < 0.000001 && dest > 0) break;
		if (dest > INT_MAX)break;
	}
	if (n<0 && dest>INT_MAX) return 0.0;
	
	if (n<0) dest = 1.0/ dest;
	
	printf("dest = %f \n", dest);
	return dest;
}

void ID50()
{
	double x = 2.00000;
	int n = 2147483647;
	myPow(x, n);
	//0.00001 2147483647
	//1.00000 2147483647
	//2.00000 -2147483648

}

/*
343. 整数拆分

给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。

示例 1:
输入: 2
输出: 1
解释: 2 = 1 + 1, 1 × 1 = 1。

示例 2:
输入: 10
输出: 36
解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。

说明: 你可以假设 n 不小于 2 且不大于 58。

There is a simple O(n) solution to this problem.
You may check the breaking results of n ranging from 7 to 10 to discover the regularities.
*/
int integerBreak(int n) {
	
	int t1 = 0, t2 = 0;
	if (n == 2) return 1;
	if (n == 3) return 2;
	if (n % 3 == 1)
	{
		t1 = n / 3 - 1;
		t2 = 4;
	}
	else
	{
		t1 = n / 3;
		if (n % 3 == 0)
			t2 = 1;
		else
			t2 = n % 3;
	}
	printf("t1 = %d, t2 = %d \n", t1, t2);
	return pow(3.0, t1)*t2;
}

void ID343()
{
	integerBreak(49);
}

/*
423. 从英文中重建数字

给定一个非空字符串，其中包含字母顺序打乱的英文单词表示的数字0-9。按升序输出原始的数字。

注意:
输入只包含小写英文字母。
输入保证合法并可以转换为原始的数字，这意味着像 "abc" 或 "zerone" 的输入是不允许的。
输入字符串的长度小于 50,000。

示例 1:
输入: "owoztneoer"
输出: "012" (zeroonetwo)

示例 2:
输入: "fviefuro"
输出: "45" (fourfive)
*/
#define Ord(c) (c - 'a')
char* originalDigits(char* s) {

	int i = 0, s_long = strlen(s);
	int temp[26] = { 0 };
	int dest[11] = { 0 };
	char *r = (char *)malloc(sizeof(char) * 10000);

	for (i = 0; i < s_long; i++)
	{
		temp[s[i] - 'a']++;
	}
	for (int j = 0; j < 26; j++)
	{
		if (temp[j] < 1) continue;
		printf("dest[%c] = %d \n", j + 'a', temp[j]);
	}

	int t = 0;
	if (temp[Ord('z')] > 0)//zero
	{
		t = temp[Ord('z')];
		temp[Ord('e')] -= t;
		temp[Ord('r')] -= t;
		temp[Ord('o')] -= t;
		dest[0]+= t;
	}

	if (temp[Ord('w')] > 0)//two
	{
		t = temp[Ord('w')];
		temp[Ord('t')] -= t;
		temp[Ord('o')] -= t;
		dest[2] += t;
	}

	if (temp[Ord('u')] > 0)//four
	{
		t = temp[Ord('u')];
		temp[Ord('f')] -= t;
		temp[Ord('o')] -= t;
		temp[Ord('r')] -= t;
		dest[4] += t;
	}

	if (temp[Ord('x')] > 0)//six
	{
		t = temp[Ord('x')];
		temp[Ord('s')] -= t;
		temp[Ord('i')] -= t;
		dest[6] += t;
	}

	if (temp[Ord('g')] > 0)//eight
	{
		t = temp[Ord('g')];
		temp[Ord('e')] -= t;
		temp[Ord('i')] -= t;
		temp[Ord('h')] -= t;
		temp[Ord('t')] -= t;
		dest[8] += t;
	}

	if (temp[Ord('s')] > 0)//seven
	{
		t = temp[Ord('s')];
		temp[Ord('e')] -= t;
		temp[Ord('v')] -= t;
		temp[Ord('e')] -= t;
		temp[Ord('n')] -= t;
		dest[7] += t;
	}

	if (temp[Ord('f')] > 0)//five
	{
	    t = temp[Ord('f')];
		temp[Ord('i')] -= t;
		temp[Ord('v')] -= t;
		temp[Ord('e')] -= t;
		dest[5] += t;
	}

	if (temp[Ord('t')] > 0)//three
	{
		t = temp[Ord('t')];
		temp[Ord('h')] -= t;
		temp[Ord('r')] -= t;
		temp[Ord('e')] -= t;
		temp[Ord('e')] -= t;
		dest[3] += t;
	}

	if (temp[Ord('i')] > 0)//nine
	{
		t = temp[Ord('i')];
		temp[Ord('n')] -= t;
		temp[Ord('n')] -= t;
		temp[Ord('e')] -= t;
		dest[9] += t;
	}

	if (temp[Ord('o')] > 0)//one
	{
		t = temp[Ord('o')];
		temp[Ord('n')] -= t;
		temp[Ord('e')] -= t;
		dest[1] += t;
	}

	for (int j = 0; j<10; j++)
		printf("\n dest[%d] = %d \n", j, dest[j]);

	int k = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < dest[i]; j++)
		{
			r[k++] = i + '0';
		}
	}

	printf("%s \n", r);
	return r;
}

char* originalDigits1(char* s) {

	int i = 0, s_long = strlen(s);
	int j = 0, k = 0;
	char temp[5] = { 0 };
	int dest[100] = { 0 };
	int f_one = 0, f_three = 0, f_five = 0, f_seven = 0, f_nine = 0;

	for (i = k; i < s_long; i++)
	{
		
		if (s[i] == 'z')//zero
		{
			dest[0]++;
			k = k + 4; f_one = 0, f_three = 0, f_five = 0, f_seven = 0, f_nine = 0;
		}
		else if (s[i] == 'w')//two
		{
			dest[2]++;
			k = k + 3; f_one = 0, f_three = 0, f_five = 0, f_seven = 0, f_nine = 0;
		}
		else if (s[i] == 'x')//six
		{
			dest[6]++;
			k = k + 3; f_one = 0, f_three = 0, f_five = 0, f_seven = 0, f_nine = 0;
		}
		else if (s[i] == 'g')//eight
		{
			dest[8]++;
			k = k + 5; f_one = 0, f_three = 0, f_five = 0, f_seven = 0, f_nine = 0;
		}
		else if (s[i] == 'u')//four
		{
			dest[4]++;
			k = k + 4; f_one = 0, f_three = 0, f_five = 0, f_seven = 0, f_nine = 0;
		}
		else if (s[i] == 'o')//one
		{
			if (f_one == 1) f_one = 2;
			else if(f_one == 0) f_one = 1;
		}
		else if (s[i] == 'n')
		{
			if (f_one == 1) f_one = 2;
			else if (f_one == 0)  f_one = 1;
		}
		else if (s[i] == 't')//three
		{
			if (f_three == 1) f_three = 2;
			else if (f_three == 0) f_three = 1;
		}
		else if (s[i] == 'h')
		{
			if (f_three == 1) f_three = 2;
			else if (f_three == 0)  f_three = 1;
		}
		else if (s[i] == 'f')//five
		{
			if (f_five == 1) f_five = 2;
			else if (f_five == 0) f_five = 1;
		}
		else if (s[i] == 'i')
		{
			if (f_five == 1) f_five = 2;
			else if (f_five == 0)  f_five = 1;
		}
		else if (s[i] == 's')//seven
		{
			if (f_seven == 1) f_seven = 2;
			else if (f_seven == 0) f_seven = 1;
		}
		else if (s[i] == 'e')
		{
			if (f_seven == 1) f_seven = 2;
			else if (f_seven == 0)  f_seven = 1;
		}
		else if (s[i] == 'n')//nine
		{
			if (f_nine == 1) f_nine = 2;
			else if (f_nine == 0) f_nine = 1;
		}
		else if (s[i] == 'i')
		{
			if (f_nine == 1) f_nine = 2;
			else if (f_nine == 0)  f_nine = 1;
		}
		if (f_nine == 2)
		{
			dest[9]++;
			k = k + 4;
			f_nine = 0;
		}
		if (f_seven == 2)
		{
			dest[7]++;
			k = k + 5;
			f_seven = 0;
		}
		if (f_five == 2)
		{
			dest[5]++;
			k = k + 4;
			f_five = 0;
		}
		if (f_three == 2)
		{
			dest[3]++;
			k = k + 5;
			f_three = 0;
		}
		if (f_one == 2)
		{
			dest[1]++;
			k = k + 3;
			f_one = 0;
		}
	}

	for(int j = 0;j<10;j++)
	printf("dest[%d] = %d \n", j, dest[j]);
}

void ID423()
{
	char *s =
		"towzorexisoneneosixfiveotwonesiegithxthrezero";
		//"owoztneoer";
		//"fviefuro";
		//"vseotoronoteteieuhtrneoeveehgowheohothoeefiwgfoihonesesiegehiviefrvrtunteseotnetrruonferrueheofeohetivtfntvvirfvrfvtntevgohvzsnveftfoooeeoiutethwtooiveneffhohsnifresgetftriueoeeovevownifeogtheuvfeoitovriguivnseeetrigenhoouohvttfreofteuheovwinsonnghoirofewvewnowowoegeneeefregnieviiugreeneinffeffeofiooowtoteereoefeohieoeoovhvrwgretvroevehowrvrrvreerrteensoeeeeofwfehsfhwwtirirghfovwineeonettvozregweetfoootooufiiovennewowiutfhnvefeeiroseehsioeofohoohosrsoofgenfhwvofeefretnrtvhsftfteeogrehetunrefeveernuoeeotsofnefrefeotrihettortoefnutifnehnhseiofnvieheeewtvotetntnoffsuoohtreoweneeheweiferettohgonewoffinesvrnegwrgngooetwhevnooioteosohreuretfnvonnhgugttiveoortzfeseiehzwiiehtteuoeuwvvtorwzohoereftnegvohuuireeueneeviivoeueeuohouornhuefwuootvfeurroifueuwrtsohvuttntzteefeweneuoufstnntvnorttehgnwoorrgsfigeovhtrffzhsttertothvorogeonitsoenioeffnnrfehieeeeesnfiroersoeweiiieougeusoewesteevwgorfeiorrenusvfefforeeeoewwifttnhgnoeffttefioffntoneinrishhowieonroevooteehegentusntheeiiienuhiwevoreevhetovreeurighfvhfnvuruverfstfronwtrhisviroeueiteeoouvieovoeuweeioohefvetvhtnuoeehfoerhiefunnhfvvohteetnttstheetevhetiniuozurvowgrtvtuvwufoffrhorntgsfnrvwfgoenehornhrheevnotoeifnunnifeoofetgeheewfuriuowihitgoreouiroufeuuthvfsunvenwgvtttoreveweeuznwrnefiooeewogoohiofonfonvtuooeogtvwweineeoveontteevfuwwvtirrwgtzioehitwzuvnoheovzefeetofrrheefeeoevueeeteogwhwffwtefenevwttweoneerfhttvegeiffveeiownftrfwnrfeotfheoofotwvreheweitfehgevvietfooorvnevhwuvtnewfngofwottfnroieoihneotetrhefifetoisooiewtohoeewhnneerfeeoeeehvogerfuenurffnwgnhteeogntnoiewehguttoovntffoeeehtoovwuutergwoesennorieoghfiffveieirwiefooeotvsnesroggwvoonsuoihgnvueortfsivnhniuwfwfevrhgeeoeoonuheeroeioriooiwoeweeeefntiteioesesrstithneeeoeturewvogwiroiesfnffueefwuoigvinrtototngenrrefhhehofvgoorfnennhunweethhtvfhffeeieootegihgevireffitofiiownntogthoruervvtttefreeeeieoseesgewohognrenontrishtinteeroroeftgttrforinntveortefheovegheottgvfouofozeouihoioveostwenguwveeewtvrreiturtoexivvrereoieoeotnngutnrnioegoweeveuteveehfioeeezihteurnfefoeenneofhnnoefihhizveineooetreewtetetrwnnueireneefifveofeewfohrrwffnoowtehiefevrrnnerorteefehvnshigoeiteitggnevhezeefrovfreewhvgeeeftiehehoevheizerefnfvtrortehtuighoovnisntsreufnzroeehetsetivuuntteuwnwoerhhiuoeosnigfhrwvwsevterivoieteowosouuzevweeeettvfritoerueetnfgfoheeotesvigertshrwetsveetfoftsietouutiuorehoognegitewrohreonoetietefiienorenoioonovotnevrhinoorihzienenhogrvueuttihoniutnrutowrhrtnoeuooouvsohoiunzttfvuvgnevifeougisieneeononovgtefewffevherviivvsfeeiwrnuneenoifhhrezroureeegnorfhewsooftnfeenneuniegfseweeoofveifnoetsovfeeerwiuherftrhgirereeeitiftoeeienhsorteioeehnreenteeoihoitoiooihhnnietfoeesgwonieouvrvieewoeihextgwroefrtoerweionnioviufeeugufihnwhoegwehhveeeeehevegeeggfofeevhttffzfhugtewhooothwwughoeweooetohwgiotevrtfeivnsooftueoffrhtneeoofnotogtereeurooenwrvwhseuitofuuvgeeieeeteeeutieoveghehnetiwgiiffowivvnotnvvveefnerwvegnrnvfffhfoeohtseeoistgionevirfnntzenirvretfrioovugewnetuwotrwoseivgfenoeneeweefrveefhoiiigeeenfhiofiovenfveoieowofueufeonieeegefetiteoetihutewotenrfehzrnfsvfeffniefegteovohrtwenurrrtnfwwegtrrowiouneieeewtowriwfeusrnvrveowizveeweorigotioetoeuveeoionefefnetefuhgvzrheffgetsoeghgtoeegtioizefotfnieveegewutorwtvwotsvrtvteuevfivhegggitheignffoeeeoevtrivtteitufroeeuuhfoueevsevffeeiowstrfoevoevvienoegtoetoefforeeevtnviogwseerfrshitoteoweiftoovnsztunnehrsohhetttfetrwwveeneefsovfrntrrhneefirweunfofoeoouoteeergonisnniteeooeuuehoeustoesrreregeihoereonntiefeieveteheheinfeefreefsrhttotnoetofotofigereeogtnerrgtovsrniehvsnoweoogtorgirrhohiehehwzierrnroveetttvtvtfeeneronvfotooeoeneufofegotoffownreerteoeovteuefgwnzvertetotottfwfseofwvrteftgooeioieuoogoeeeztteozoeteuvvheseeinoofevuvhrueewneeesoevtovooevuhtvweeefggvowfntovgnreotnvittiutfeoeioeniofveohthovhoeorfofvntfhtotohvuoutteeunheieftesrnogfoeeoofeessvieeehsrtviottveenswhhrhvfiesiteotowfzoonhonohhohriigeeieftwuvohofouwtoznoegoouwnoetewnweovoehstehfuutrhrheoviiotvrfieeiwhitweeffhufngvueoiioitfionttoewonhteegohehvrfwzrthroseritnserwtfveistownsetheeotwezhenfhhfoeotvreotueorvrouurvtiehgureoeoevtoegfrrgeeeeofioenfweroeoehowioofeoerfoiergweeoeoogeovevuouvfnroifvvertunteeeuhnvtnztunwroonhftrioeweietrrhfetnetwfienheuhhgtvfveeefrwestiteoereteiroheeehtfohiewweuehefeieeuogeeiofshftgsofeevorvoegristovoeerievftooegiogwinooigrhetrefueeevoroetfitwsoitoterneenteeerewietuweftshroonoenoeewnesirgetosftgeneentterrouvnttxgffwfefghosthwnitefehroheuoutoefnheenoisrreignrooreetnetueenvfiohotieohoureeetfiieoweoegotewrnetooonghrvihnivoeooeihoeeetotwhhfeiooerfeeennuhronotitfenfeoteoeeefeweeuennfeieieeeotfnvehiheeizeeruitfhuforeiioehrererttistfnffieertrorntthertunfhoeeeerrevovewuoeesvgtrworsionitwoierrhfeoiwhvsfuwtigrhnwoofssouwofuesueeeethggvnteegiegoveefonfzononsereoonfiufuiiiwutvvoowewsgefieowosevfttwtnfehohieoewsotsioeoitneohnvhtoiftrghtfivwefeeeinswfsvgfiueievfehoiowriruiirsveofsuzetersneveoetgtorernvofnzntrhsieovoenffsgosotneeongeefeteoeiwhtuotiiofoitieeitfeunhnnorzgenfeffttruvitrrhoiveetifwgnntwtgfwtgwufwweguegeeosvsvhtiteffiousfthrfertitugwngeuotoiirtuozewitsveeihfewoofrtetriofueoorneevenetsoeoorgooeegusrhhnneeiueesehsrffrefntreottwntewwtoretroeeiueuvwnroeoenoeneirenoeeetghifeegrtfnnfetsowhuhntrtifotosteinuntsiefeneveoevgnougneveorsivteeooffsenneeteewefownrtorvruvvhuiowgtoeewgnieieeerffvnvrieefrefovovoeggftttuwhfouvihertseorsitnvrffifoeoheongvhrnsiorotethtfterteehoonoieofertetgowreivenrseztunoesittntfngegshionoevffefvofoetveiuworefoutiooefnretfvoruwtorneirervfiorroiotrehfweotnreeooenrwffeotneigwegseeohniexnninrnefitutvthneeeehhgeerirehevngtifreerseefneohtirorihfioohwtovoeenefgtzefftuvgnthtrwstvwguohefghuroeuewfoertfsrsfoteentotueewzstotusniievewnoooffovoefvhvfeeenferwhuheffroeungnuontioooirnovrttsnieeenweneteongiufeheoffutgoeownrfhrgeoerftoiofrirhtueohfrinooenowswiteevohoieeruifuvwserhefteeistggsreoestoerhieifsnvngvnnovgsttegreteheoutehovtrtoehirhroeteevvwhehhogeingeiiutetoezeenesehgenneuowsnftnzeheentfeovtwotnioetohehtnouofeeuohtofvetfreiiseofineftehonewuteoerwieoofutofeorsegnrwnotoetghiuihtuoegivrzhgeevghriefuzwofunvfgutenshtfoettetoooizosroeeoutiihvofgefigensoeheetrnrrfrfoeeufverenevfewennfutooffitieoooiivueeoinuetsehrtwegvtnoneirthftihioteigviesowufeohffninohostoteeetweootuttvwiefeettfeogehneevshoionehiefuuheenooeofvfwuthoeoeiehsoweoieovihnwngoonttunurgtvonrhohvutevvrgeengfwvoooefeeenviveoeioveetrewfsfvevoieeehweretegieerfoifnehzvfutwehregtteoetwroeeihhtisgeorsrehoehnowritooevtuhufwingrseeovrroiwwgtowegewgueoonhrftfshneeoteeefziweriwhfefeotihtriewevxnnthwuieoswseieregrthefvoeihheeevwhhhfweourirohthiooieithoowerietevofhfotzevuttevhsenwinthoeeeeoeevhvgetvhhgootviiroerevreeenvneuoheezfriffvfooenfoeteeneevegvteouotoeftftooteresnovevnefwnteoneghfiehiioereorvuhnnonetrffhsovouetivieohhrvituesteooiuoeivsteewnoefsrevgtifhoroostvhseotetwhesfnnunutwnveefiwihoirihttetrtreeoefhvnseifufenonzefuzoeteogwvehseeevtontffrrefrweoeonferefeirreonufveresffuterfogrinfxrttieivtfrurerhoitevhiowoehuvevvvorrngteevteoerewongoteeveegtenwvifeetfoeweoufoeeitnoeweongeetuvvontfrhroueiievoeeisvnevnuesoievfvvoriwfosueniwvgehoinvhenieogtvffoietehevhfswefesiveeeforfteirestnrettfrirtoihoteeooiereueneefevfhowtttuoowgeheueoovfetfhesveefewevriuheehehfrevonnohigfethsrensohsigeneeonerteseegeeinvroeogtoeeenfhhvehfrzeioetefgiuventsiweeeosieighreevevoohwfofoegiuvtifffeeoeheteirgoivehevesrgooowwohfvvetiietvststgeenunorewwonirrouwetnvotwroroefoivereuttvnrrutnheonesisvieetfvgfrorwewhwvoreoiofitnoitrtoieowsggvsvgfntioerteeuhntngtntrieoeoewivrwuegvffogvoeereoioihgwuoveghennovtsniorfvrsnttnenwgvfvoeeootnurvihnoneoetioertheewheeouosgofotewihvhoigegogiotouthioongntihruoieefgtofsvooovtneeetivtftinonhoivfhethnootttretfoestrehifoheheitefennftoirniutfwewoertvfsufgvouehvtrrfgrrvfurifootewefnnneuerhwreigfnsiriooetooithrwuirfteoetooevnveeeowheowrgefheoetioeenweigvoiiwueengwnefioreutessorhnetohheoowieoeetwuongnoeveostehvwgreofewtsreteheoefuroroevtihnnooeoftovifentfeohiehvoeeetestiveosueeoheneteheontefvfueetsnueeiwnzshtsrfteeehueiionethesntheoturrhtewegnheiweohhveifozhfvoeueeovozevzevufueoewvfnewrewnvvotesevetwsununivtunoognfeowvfegeniegenieonwnouvfwervheheoefwofunfwowvfneineoeethuunuoreowehgfrrehetosveievteeftwifextteseiheeovotnftefiivetfifhufvnfntitrwhroooeiihvorvntnshorwontoeieneeeootehehwgiotowteeeosfevrorrtftufuweefeeeeeoeirttfhofehetrevzehifiergrgseheefhnooreeeeeewwfeevutfrstffihwehroheftretzftifnruheievouefoievfnresueuffnorhtvteuhtotfoviufiehoirnetvogftwttestfeftnrnsfoffsehhnuiiteooevssvoiniofeffronruefisnhgftoseegiioonoowuisvonigfrtshiehfieenouzieuognrrottnnhozunofrhetefozeefusoffforneeesoneveorvetreieeofwfeisegneniehngfefreosoowerthnnuoeitfvhfveeuoeftihhoieenirgvnweofiiuigwnoorieeouensftuhvieuteeoheehnvviuteertesvneiuenwntfggonfoiovffennigovenwieovrhghoftotnnneeroruietnereeifrerionoernfvgeefgteivehnfeorfoirsiuntveuteezevotertnehhtteofhresoehfenshoweofonrftieoiooetoorrhtrteefetiresisfrtuwgefonetgfveteftfheehefeeovrnefrvrgtooiohhziowfhfffevorfsstevntuosroeuorhghtnhurweirtnerrteoixovnroifogehewihisfowiteuuufweonehevzfseeunhvhrgtesetoefvegwgtzguehnteefftfnefgotniivheegtetovgegovrivestvhewteteovoereneoteetoittttgevfevvvhgegoirnuiwetnfvgenentotrtefitniiieuevehhsfweriteefefftvfernentrnsteeifhfrruserveiegrnnioieoirenifegreeetrseoetoeerfsevruerfehsurguoenoievwoeuerwonreottignveenowshegeenvoteurnnitrnfwertitveeuueisntneotuxesofurnrfoorrftuehrreunvuefeowieieeesgwhrfgroonthoiugefuiotittzowreouittunooefeeousnotvegireeiiireruroeeohniuveeoeegnnewohurorugnuowinueirheeoregorsfsethfrifffteererfffurgenenwohiihenetennrorfowvttertitewguretronottioegoefoeniintnfeeoeefrosevfehigfogvgnugewtorhtonitwireeevheuueefhtfotovvhewhoerweeotiofhefntueeotuitefnevheoioererrvohoffsshfehosenregerffwviewfgeoesrhnwefoetvotreteoufrntwoehfiootseehrntfirfeeohttvotvererfvrtoeeeweeitneffftweevehxrrtvrfirfotvshtuhrenrtwtirrtffeeergheiounfhftnweeioieiteixtfntefwihihtouiuefetteotnnihwietvrfvvuvunitreeehwwuveegeoettreoueeoervwrguerergufwugoeztetfvtgreenoeoefeerttozeohhetooeofehheineiofvrseoweheveritteguvoeerroieogrgefretoffinifttsvvvhnwnesvieogvvottfnntgeozgeigvnwoveuvezeionrtwsfifouitfivesoegeeverheginhittnfitnnreewogrtfoeuetfovteonefterninrugutnnteovnougreoeevnreuerietzoneotznerotrtrereeernterwfegveinusrhsvevfeenuvteeuonfvhetogifrztofnthrnevrgeefvgehwvotowzgvoetvfuoevftfgnoovenvtiivezeetuvtfrhvesreereieehvseohnehiovuteogrfhrvirhhevrrirgfontwuothtnfhftotfgnewgreoeoeotignrshifrfneewenegioougwevozeehntnrenifergefwhiniotnhtoterfrrooefroteoirheitiirzeeieuinhvootevoenernhfhrrwireenrerutfoofeeseeffhrrfohuovirnrvetventnnogenfensuftowfevrtonevgfihiersnwhwtuoeehievtueioehreveeertsrrnuzneeregrvwoefehhrruegfeererfethofioenneeutrvgsorntiogioteeiesesgottwgeieueunfnnnoritevoirteeonuvhghorvtefeihrnevvfoouheeveteutheererooeefrefoetivufefhngfessoenfeheeieuweifrveitvnosiofrrgfinnieefgieiieeronevverfeinotetsuoetvoegnewevvfrrreuhetehoueefiitfoeosfhoionftesihrhvisfnetrfevgeifrrorgffonithgetweouwnootneereuioisefivesontiienegnenivfifffirsenettrgeoiioeeferovfwttnfsfvvvfheooueeeooeoeghutouuiruhhiervveefnvtrtzetetfrreeneenrnotefvooiwweethiuihiuontefrzgieeiigvieewneehheffhneoeegeninrihiihttewrnotnevsneetenfswfreufffnsfieohgstuhrnwffronueowgieeoteotfnvivsrostuosttoohtrssuuneoorvoweneoneuretotefefefrtvueteesvoroetfuutrtousnetnnverhtiseovuroehttefhrrvoesrhhhtonoiftioonfftoiorehinrfgeneuveeosvoeefertezoofieenriueeuenoriegveeeotevitefghvrrveeeeeheooeervovuivgeutevtzrovgrreegoiesiefvwffrsehtfogsighveuwfwvnrigeutheohesgozetwegoseutotgeefeeootrsneiohvononvutotrfotefvvsvfefeoegeeoshfeeiewehtfstnefeeonnfronieertonoiirifoegioereffgentrinntohsotuivtiennoheveoeoettegnrvoohvevhvreeozftfirtgguveeioffenwoeetznsruetgntnohntroeeeeifrvefrnoeeneeveostiihsegtofhttovvieftoerevtosvftviihhnfttewieoeietugeorifrfourighvfvueniwnovfeefteesotioetefoeuerrfetinutneeoefieoevieevenrofihhefiheehtgeotenenfrsoeeresrtnhnvhoonrfroheefveuefthhrovoveieooewteuetifonieehurhvhfeinvnriveruueithofinfgrorrnfoteeowrrnehoueeitrnoiitenitiifeohehgeefetfsieseouhinefnhhhefrtoshtegeroroiwveeshiwveteniwinigeigvgweufeeeivofnfeffveevooueieinftouggeereznertsnevooreveitnreoovheewvgtnooueforefuevrfvnfiehseeuetengneeufesnfiehgonenghehhgfhueoehttgggfvfteiiueorsesissioeirvieoreveonreeteueevvtvogohooeeietntnvvorevoethttgtoneiuirneeroevgngvfueetoootftgenefhveehueuehfeetvzhfwetntnrunttvhfttonrrvnorieiniweenvneuotigvehfhehrhviehuentrnrevuhvivgeiotieifhnittntuvsihuowrieeefeergtiioernreseerofwerhvtroroeehewegeiwnoeeeifegiozeeefeieuheenoftgititnettoofohtfunenotfoevoeugsetfreeroueotnrottheoogeghsuuofgtffsetrfffinffeteoenugeeehowesvifreieerietzgtnuoeewntrerfeerrehgoeffeeehnnetowngeeeeerhnnrffiovoenronvoeitruronnshtiewoofseheervooeffezgeenieeeefrewvtuttiietrooutetugtoeeiohrhoeevuosiuitoerhgzoiihuhnvefghonvenftnfvteeeoevuoeegnvnvewfruhnuwhevvreoesveoftuntsruneiuerifeeeneuoeegfitwewnoruooewoeevtovfioiwtroshifttrvoeurrvienvfeeuwfvvoiuhvhhnieteertoengorseenrvefrvfeefterrrzifefihrtuhoouevieeenfuioeewgohueirtvetuegfeeohwiveitvisvzeeneghetffoettiirivfihrfneotfevefovvreefrhixnfeeuefwifnnieevrhtowvefetgovfevvngtefuofwvuvswfovosisoeeenefffhwegzhvefnvotuuroeeefeeeeooigteirweevonothtrnteetewtvhiwewoehinfewsefooiturieeegeneonoooneiivuvirvfrerewwgrheuohitzfferviofovefvenifewvfveervovzeghneehveeningetintrvoeeiofoervfsieorittefvtoeiueeevwiusgroetofoetieeuoreseereroeguosohfnoioneuiovittgeheievtwroteofvtszeterefoeoehfeofeueuusrtwvetesfeohwwvttirtvrnetiwvoiitoneowofwifgvunffoseunttonhfegnoeoeiefeenvsoefefhtroereeuotiteeohorinoiieetoirotvhivhwiinohesnueeginutooefhuvretfheeovoeiooniteuerterieeivoenefifennwvrnuoituoneewfsonsuhveszoevtreeffnsrneneiewurwsehheireegotfeznouovefrnwuiovsovuehheferiouvvoreugeoefhveethneeeeeuttrtfenenenrrotesnettteizuveineegeowvfuiterrueivfetneeoeeneftnveregvfeouvenornrfsterethithfoevffgutsteveiioevsreeoooteeegforofwoverehveentoiettrvvtittueeneehneueeovoeeegotreuneesuhvhnhuenfsiofsstvnewefvvetruveegffrnrweetteuvfesrhtnrievnfnuserrneftgtiioefoovehohihvotregfivsnvnuvioiihivrfgfeuneoveeeoerfehehfohhvfuseroveinnvfeufsgtrtvuetetnoruevnofogoeuehferweerwhgeogotovvioiteoeeiihsotnnoevrioooehuvoofteenevnowzeufefzigehftnvvtweuoertvozotvgfhufeeuieeoeeeiwgerhiiuveovieenfiheheehsosoeeueegfhfttwrgievgegfhnnfnofotoiveuueiesrgeeiewvugrffhtgffrstrviwefuioneeiehieeunwtovrrnsteeootrtweeoevrtftfoegetfoffvzrvohffffturfehfsereeoetvignzosvhhvffienhezgoeoefehwweisvgunhoerfnefoeogtvvhrfeeeooeoouwetroovuefvrveeeiettftuzsoiroofvnetwuteiuefvueueeooiiioueeieioeonwohesorfofoniroeenetftrheinvothvtrheoiefvoroeseffouroftsftwrioeeeeootexourrrostrueewusovuonnreeteennfoeroewifeweehoeionrifheeuogevofvrtteegefeieffnegsvhtfutrsfhetttnsfgfeooovotnutfioonvehtwovinitetioinoevrftteteevevfgsnghgfeeeeohuterogrsseowvffwvnetestevfvtwfesftinnueetiggfoeoitrrnvitsofefeuvnrirvenrosrrioiofteuhveiiteinheeethtfetvenniivustengggiovrheiwtoohioofeonhufutrugirtnrtnovifurnevrgforgeinroernerttstreriuiuivsvenvififtfreufursruteugohehteotertereeengzvttifooeteeteterwehortuteteerurogvtneteehooeoweftveteerushetngeveengeiztegnhefheffotrfsvenuntneetevgvtfvrivnvfwoowewzgtvvtruiwvoinooiwtregrovirfrherovoeueeehnveeefiiitiuvnuioeueoeegegevnnowteihfteeeeroneureeeehewiegreurotrsioeetoeheenhenitfviitofotoehvethwtorgroniuuoeoerufgehehtituoeitieronetnitteionnviisunznuofregoenntfeoeeforgninnhefwuerowtoennteevtuenvwfeenothhsoetoovfvegoznvnvovrviginhgoohfnoioteenneevfthhfvuuwnohsfteteofvfovooheoeeouvreterooeiehetegeffegveostfeooorinvuweootwereitofnttrvoengvneeevnehneoontinneevfghsgfovtovgezotfneruweotvoioehgewiougenietnfrtgweefeotoiegeenwioziiehheiowesrwereofeoheeevteurvnnoeetvrteeievhhorfnneetwreitouhutvtotgtreientovnvfrefvviuweevuffffonuntoientevrtgehuwgeweftvvrftehvfoftueeesteereiofrfsohevonvneifvefrfnhontfftioetuvnesununeuetevetetuetgherhosoutffooeutufoosvgvonuinnihetteoeeoveoeerenfrooineewooeeeheniitueivhueroeihoreteverfteiisuiennnurefeohrouerugirritefouwtngtewhwvrtegheevneegrofrnvesnoevovheegrorsggutoeooiivfnewveheoieterregoenrenhvnvootftgtheterrrotonrteeeefhegsgfnioozieogwzoegissserewgnrgtiniueeeerentrohefveiifeeetvwwfeernegnnuuegfueioeofeouniitesifteeseinissfsorrteewfeesuoveeefirfuoofufeereivoeeowefofseeowvtieoeuseeoefhvwefvggeofenefohtfheivfhuieissounfntureigeugfveeiveegietrotvvooheeeuufgeerirvnngveoeehoeigovewhhferotienieugoefewnrteitofoifeohteuifrgeeefuheeiwrveeihniutioeeeurftveuhrveehfuuitstenfheeoeorftozzufeigstowrrrhowwosofzortifeveiegeeseeneeewitsofuooeogvnnfouogroeegnftheoefvefenoeotoeewnoffoevifuiouoreoeuforoevtiseiuioteosrrneroeevrvoeeewegretettewifooengvetnuffwrewetssuioteoreeerffneiruhugnoezorieguogsfeitgnuoveoneserzwnsohgffwrhreetrsfvsiortoefnwvruerihfoeoiieohrisfevseefiwfwuntennrsuihgvsusheiiwevhhhhtteveotinieoofwhfwwuveenesirezsguizrftnwfgvenoteeriewoheinfutheoteehovowgtwneoeeruhtusieoeoutnfneevogfositrerofnweeuttrgiwehvuetevhesueefioegoeoufezoerefifteeofttzorriihietnreioueinegefnhieseeonetenuuheuiesrheevrgohooohnuiwfforenenifuevervufoheeovueeffeteiseovuwoehtowneeuieseofuoteeuferffrnuteoegewtoesgiivftrfiesevofuontisrvvggvtnhertoevweowetfvgvontrteurrfsohovtgrefewhwewfinneoervofvtfeehotuonevotteureovewiuouiruovgeittefwiheniitoutteetsuefhovfeteesifhnffeoenrerrvfoteevoreehvvtnieeifnfeotishnusesenoogrteefothovfvofwwonuhrtrootueterhieuwwovinegvtnteitfreegroofwtfowvhwefttffeeoeiniheonhteeweuiwwevitsgenrwntuneorsotvesieheeosifunofnenevensefnfwvgontnsfrwtiootorferzgungooeisewheeeneugrufheivtfroenuireoefroeofengsohveowvuuhvveffiionofertffvoennfoovirwuuuosohiiwhtvivwnefteoeetfenvewewrnrvnewzfszrigeheowthferrgeoonotnfnsvhnsefvtseifnesfffeonovoffewfeeeeeuvuuieeerfnnsohoeftfuoteifwfeifvgtntveenteeeeveeheuzuneefreruiiteuwovhvehigsoeooenoteenurevsuivwerhofgggetruvesttfefweeehetiesiererifsoreneefgesniwvrhreuefreiehvtinnfooveftfrnviowieeouieietsineeeeeeegeteoiiheungienefhtfhroereiveoeevoiottifhguefweotvrexseffvrseeorvoneoosvetoeeregotennefifhwiehhoeeivtruwntenooeeouueztuivenueofigheefownosfztoirvhrvifeiettrrzenvhfrtohivefnheoernuvfoviuevotfnoefhgsverovrrfiirvnoenvweetrvsettsttoseiteeiueitoofeveofiiueuioutuivtfftfsugfeviteineeofeoetttneshifsuofetienfvtvtsioigefvsonhstvhvgfhforogrfooseeoiieoeoenwuogoovueeowtuottvwftsnesttrvveenunroufftwuetheoiieoevenrotitrreuriihiotivernoeorwonfovvostouitgwenehsioeeoenrufigtfgffosgvuogneorgfeegrfutrheongioooreeuwnnitoftefunesnhfhivtvfoieeofenfteuoeeitivuosgwereruenesfsihefgiwrgfroutvefeevgusfiooetieowfeifeteueereoeesoieffgufeveegvvvigiwenteofwevhhgfoigoofisgtefveegfisfwneturettfwfnieeeeirvwiwrnvwvesofeegiivtvfgifovnftieurvheefevfnirftoeshtoneeeefovteegrfewgewvnhnosfeiwnhteoofgtiiesohverfvtgtigrrseuetutrvwtneenwoszergoeenefrooeweftifehgvoernoinegfvioveeeesevvuvoonovofttoouohehneveefoivouoreiwtroitterhnuerneovrfhvegfeoreteweotiigvhriwnhfoireottrfifievovretovhrrfotewteeheogteteornehtveineriuvreutofewveihfooffeeeuohvnwffhwvofweieeeefhseigefhoneteowfrrvegeiforvowifneotregogevhvoirfeeeofeoinvfttffrsghfveegeoioheuwvovohtnhrtogfvoirvhovreghetfieeuevunfrsnivefvehhegvnffeueiottwtrefouhtefiguneehwhuitttoeuvvnieirzheonvztverienenenrgtnfvreftwgitugnfsengvefrrsrehnhnovtentfvgiifrtnvgvouehvghunufeegvoxvuwfoeiogoeiioeterriiieftfitfevnnweoounonsehfhoeeriurrosintheneoifuiuivotuetfwevooeffreuefenoeefeotroftetvtvortnoeoeeofovnerfegfufgtffuoeineoeenffenvthntieotwofwwinheeoietoisoehwotoeerefiseetowgienteteevofvuehonnrvvvsstxfegesewthotoeufunfoonhttoinvhtoohtneneeroosfhvrthgfhoiifheoehhfegigrreeoeoefhzuegweesevnvvgnevogegthfureesvrifgsiohvsogiuiheetneveonuifstotieeiuhhuientoeheofnttnuvfotihnvthneenheonieeoengfeernottehituteoutertwnnfworiwhofefunweuineoioiguirveeertwseveehuifoeefgivffeznetoihgevoontroerotrnifeiohhoeiurrnnrigrrrihtveoefuoetwwoeiuhovoseuforsntireooeweefogvvfuinfvieeretwtgnorohvuifesehesgrfeotefvvvereefivfhotenrihhitoeuneieeoeetvtnuvunrfoueestvevfifihooiheweiroeeouewoetevooonvowvwisterteevurgerisfeirghohnvheeiseiooeteoeteevtveofsefeeeowgwifurfgvevzghnerofwnerwvtotzeonhfrsrvveownfeffoheuhonfweeioetifrtferonrneeioonwueoifvotnteetnetufeeeeuiivhenutgethrrioeweoeeefnnfefteoinigreheifohwruutfernufehiweeireoeetgrhsenueevefvvtnereeevueereozriftegtoinufhunhifiefoihvhgthorsfirveeivoittoouisweeniftgrfirnefffretevvvttnnvrsehgeofteheerirrehnegworviorotsvozheohrvonvtveeteireiiinswfieeeueegoeiooitveooeevhswoevsneeiegeeevetrroroftootveeinennnvtowofhtfveotwretiwtnooeewrfenervgoehhenvwtiotefiefeiootsotveeogeeefnignterorttsieengeoohirvtgfnfiuioevinieesiuoieuwuoioiehneewnrtrenfufotrnueerreruneoeungiifwfwthfehoitutzhfieewhvitggivenfthwiwoefsfuevfnvvoffuheuwienouvuensfvtvevfvnuvveruvfrenrvnnifunieintfhhrzivvroehfwosrnwhweueeeffheiftvtonsvnfehntruiegviiieshvfownustfeoosgfufeeeenoeeortenrfwwhtnoifeeutfvtotiwzirnnouooingvvsetoifthgeezrgrrerethohrttwenffgnffffwhtfroereeuvioregugfritofouovogieeohoerueuneohewuwrvrohnoewfotreinofwntefereoehfewveveetfrrtheinwoefosnfhfhuoeetfenriuhvtefoeseoriuontieseoeinerhoeufonfnfftunvovhtthreeiworzinonfeofiwevefiviergshffforwtsvfgesvvtnvfeeefeittshevhrfuofeoiornvveoirfrvoveonnteehrroeestnooneuieetzosneorfnonfftotorvoiuivoerrweeineoeevreorsuwgsroftoeftreiovreetevvefffseieoohfoehuvneohooigneentteiitigeefgehfieieneohheinoevrfffousnovgntefvierevhnifotoveeifeorftohenfrfenfhoeisfgeoenvteeoigeveoteoevuhetiefevhwhrousfhnrhonvirureuonreeteeeoeiioghegeswnfitrsereeorhurngeefroeewoonhrvhufeefosfioevheevsfefhovohifwrfehevitivoewrovgntfggtoneegwiegteuuirwfgwstegnontfroirretuefovrntnoreeesrovenfhfifhnreotifwnnitrnrhrsvrvosfntfosherevvsntiueeuhoegrfugvetueonfefevhnvetouognirohogrtseirtuveevuevsevigghwooenfintitvntteswweetgoegfttsenieeoeenheesiftgonevgrteiootoeiteironeotffwoeovgsinnwurettfieeehiiehsohneeviifoeiseuiieggshrinngteossieewffeeonenisiiveietireeotneertgtwiehfhwoeteweuoivenwefihofwrfsuowvzetnnnvoneeewoeeetreisezrswvwnwhiefteeeofeetetoonovivrgewerrefngwereneinuinnfuifeoiifnreootnseeheeieehvonvnweehfwneetgteuoeneufsooroeeresrovienohoefrevofotvssoovsieoghefuiorieweuehvzwwiitnttrtetwreehornnoofrtfnteeverttrfnsieirnteseufvunrgfowooitvooegfiiwwonrtrehfegnfsneireeoireeveehvvuefterornezufigogusviefewgooeewiehegohhefffvvrewntfoteehfeofwofsinvihonovnheizeetuwoeeeeferttunvowvouooeeovestsviievvvtfuvetwteegrovfvffvretiereheeeiveinoenhfrgwifnsrtrevonvuefheoiiiroiehretfetogrieittveovogofiorneenihgozerorreoteoevoeoitiweewnorrghonuoohhhtsfgfusresntooisseeennetoeeeovzttiuoorihegefofenuefeegeereeionoetituioiveinereotrewfohieeeevengvetefeevfuuovvinfvoevtehfgeefnfffooiihteeerghveienhoivrvwtointnfugteoiiihevhennugefwgennifeevfteirtesvvuvgngeeutvtfirfwfzneeeithoioreiwoevefvvetrenrtvfnhtvneofrrnwgheriwgoteeenfftevnrsvvegtiorrurfurufhftfertotiixvotuoefetoiotozuefehnwgiogessugtigvntitefenewieegoegreesteowrvnroivvezhftnrnuusontfiniiinotsetenewevnetefvohesrvhesnwiorfiovenvtfiessreteeohitonuoevnstvueeegotirfowostnrowuoegrfhftreeefwiwstttournvevogroteeoftthnetefeeetfunernefewoeethzhegevhietvohvennveovtetiereeniotfnesevvvfenstovnxhewvsetwiestefftwevionehoinnrhneeeirfvegievfiivihneveveetrteoivnnsveooooioeeoeoofvrueoehgeenesiwegtvefehtthgeooenoeiofonoerihfiehfgeevehgstnuneixuvteuwiiienotfowrnornefhinnsweinsefrunevettorieofofwzitgeewegtuvhgiteoteinnnrverifhhteneeewrsrvvroihnfuiiwfrewofvnveesteiuvgevheogwvnonsuerfeveiooeevheiovvfeettoeooofoevvwviefrhnetunueowtevfevvhrorvsrieuiewrortsevroreerzoetoeivsiegvetetgeiroeithhiouvvvnivoeinfthtihnvvevfeneehrievrwewvtweeovneftftvoshrevteeuteiteftritnenrooeiesviwsifoenoovegefevosoveftswfornveveetiegwewhvfoeouvtngeeovgfeviwehttfoeifvneovurhhwfhiieefvtvuvihegnfhervooetehntzeenhgsiweeeteoretuutrheoteetgtittinrhvotoevofeveioeosohvfeeeiogevirrhowgvtroevtrntiuteotsvwrrengifnwreseiveeifnowhoevrrfihrifvowfwerrfeoroohortotrvtuntuenrehneoferoefvsoeifrhfooiheieeeterveivnergfthrevruvoreoniigereeetufehneethsooheienvieuffeheevwefwzowwnnthreisuvhufoetneinieeoenneitftetegeonehsefonfefwivsgioveietveiretnrtunsevveeiseuizhhoeeutzvofnnotsirnutfvoertueiuevetinowittooewhfesoehivevorfuofevugeugozeeweggogvwnouesugvotvtffihrvoeehfguifnfunonrrirvfheoftvfoeofvonogiiieovueueoveugiufeeseneifogieetieeeoifenuovsteheoeeswvrfrnronerszfnorifnrthhfieteenorfhnuhhsrnueorhntefevgotoeerhifefvueternsnhettfveiveeoteeneotigueesooheegnvevreeofereenfisvfhfoneninefvvtnnwsefvsrfrvfvrinwoeffnoiihtetsevovhneerteitnferevotesetsvtgowtfvnitettirregovtfhtoeinhiigvorghteotgsgshrohevezfzreesehnvoeeioehehtoeegoeioeeneuotefrtsseeeuennrnihnenrigsiteewieniheifeifefvveenewoeinhrttehnneuohoonivreinguefohrernfirnhvveoeirowoeohewgoeeoutrvnevooofwtfoiuhehueeeiesooehgvuosotwweeovrewifioneeeeiiuoeifoivoveoirhnszvtvfuvhifeonweeovreifieefenefffeoroioftvwrefhufvervtewohuvwogweevnivztiunowrtisueeisgfgvvevuifetoefoeenhoesueegeefuerhnesesntegooeefvioezeefhtevgtwvvvrihvenereiooneofnoeohntveowehfvfevseeoigwosruvgvefvosieoheeivovruvinnhottueeheohgtenuvetvztuevvreerhfrthtnvieeeuhvvtnioruenuioeennhvioeoevenifvsetefrreveeieroeizeiongrieihneosniooiziinezenoseneeeveueoeeeeithrfeewsenvrveeeveeenthoirtvfioifwnowieorwgieoeeohehwuefeuvnornesntioneosnithfnovehtohfoerueoehetoounreeehwhfhfnhtoeftgtveoonoeggooizoivruftrofetenvgvsiesevftitftefvenoihreitogehnsgssithfrenthgeeotvwsweeoeuvvfrvinfoewutgevevnehwereuewetntoefouiisfnoitniwwosiiteitivvenneiiuoorfoewennsowhoewsniutfuutsfgguotezvfogrotttiwggfnvoneurewwehiothovvveitohiegetggtenosweenfneoufesvoiheefeeieetrivewoviuswegeggsoonrssewigevgehgfhtotiseeovoefehieiffotoeegeiheertooteoeehnetghwvrhgetiiehtweethteetieoiseohtrfrgehhegneoioeefeueeirihifiveooeofrfoiufeseiunheivfnesoiugioeoegsthrntoeohnrwtttsovwtotfverfrgtrrwervhivoewvtrevnifrooeheeeorgteotnuseorteieevwgeueeoeorhevovntrgsnohtvthtoouetinrooienvtioeieoitnfetrehoeinnhefreotrfivhfrvfirhwfsehtetgeofegfoerfgvwseteoeifehrfhwvenrfsnvuhriehfenirvhgefxteoievhreerveivefvwevsueuuuehoinoeohevhoooeieeohrheueroevoiwfetonnneseitttnnfviiovnufeesfrtnivnginnzetszuietoeeteehfigonwiewiferhhnennsooeeerheeveuoetihtrorhtohvfnteeeseofnihovvwofehvzeneettorrfvnevohftseegwseeinoooroeorzfouhenrehwnvetuofgswonneihviohneegugfioeeohegsooeereueeoveevgvshziosewehvseteietefvouhvrreovsneoeeotgetgnivfeeiefivinvhefeewwoehoseetfvehenwhrurrtegeftvsnohetogtoeenneeeeohwerevvesteoguuetfofrnsutrofetwhfsiuffnteesrtgvnhgefehgvfeeroieiviooevreowzftotownnonfgfstheieoroeoevofieiffgeeouneerewghtetnovnriiovfeverteesveuneheenhfersttevevffvexntvtrtefrvenrseogtneeioegnooioiggtoetsshfhuoffeiveoiowvvtnrofrwroiiiufhihutouweeotnnnrrgerortgfreooirovfoveiesnoevitfuowtvteeenioeefeiofoiheeguwezrwerhrnornveueeenseitonnftteeffivefrwnevoewnfgttrievrfrfvntoeefweiiontsnfreseooewehiotetieonvftistiffzrtfooireutttrforteiznnoeowteoefehnertitgegiueoievnetffnrneohfstoivteheeotnfeevoeffeftooeioovregwfrvwofetgteessoweneeeeieefrveovoneofetosuteeoetvoieneoeveitivfunngfegtnihttfvewsuhergevetfniheienshwwriefzgotternresoehntoheneoihtrtennoeirteehveguotevgnfooehihetevefeteroieustreueehtgugvwgtetrotishenriurehniroeegwfwtftgrhnioogioergtoifrfrggfehegseesgivrfevvgwheennfnnnesvifveevenrwtseorgrfisehrereeteoseihvveweeorettogtrorveeuwveettetnfwitoofnfuwewsotoitftugthhvfoeheevieieuosteetghvtworeriivstsvoievesgeogswitoeeheenheifentefvsieineeoervoggevnhevznoieiieisfisnfsoroeehigtoeegeuegforvttrrttttiuosrvretfgresvgrurioetgfreoeheevweiressffoeegtvnoeegofenuheeiheetesotnfwrvvheeistgiofwtoewiefigneonefiveuevoneieehorhitrufvvweosvteoziehiireoetvreeiieeivtofeftneovseoiofgeteigiewsovefhegsuoeuniueofnwizwreheeffsgeehevoofhuieteirhounoeiteewtnftreiuuvzfeoeevtufzeeetvewfzwuvgronrerrtivnertvgsefeeeentowrvsvetneevsvhgeioeuwoueetofowoeoviienetveeeferutethrenfhuhvoefgroenogefenrthontveeoshnfueegsthehievhieohuurufvisfteoewtehveehoofewuouuwvenrveeuihrveefnvvoessivoinfeisehwvfeotetgtvevgetrigtvrrrnttgroifegsrivoeeovrtwewtteogenineotorohvnrotfwefeuvieitirghenovhiovneuoevnognvoesvweneeuioifeevgonhgeeeennoeiieuvsretwoervotsetreeenhvrovzitfvoiuvevfoohnfwgtthefnfouefefwovnifhesvoeutuwhvevgeeonoegtorvoeistvsvitrrfewtteeeeuttevsriinhvneeteieenetrzefeeengtuitthgetehheeoeutsfntifetrorerieithvtgenvethtiweoeogiveheriesrsneeveoieeeoeteuvfresreoevtohverregittvevoigonsvsxvwoieeihstvwugothtfeieeooofeieeinvonitevssteoeewerseonototoeouoevfnuegwwewhivothhtenrfnioevfettreooeeeeufeefirievnetfweosoestoovgoiuivvitonessnetrigevoeiuoeneiohefetireitrihehuvguwvifenogfvetsvegnofeegwfieioexeheogrretgeehuhoehnesveeesfueeosntofeofroivehenoehorvfnerewovofntihhvetefenofeeenewnhevihffotevoofvntuigoftnuthefnvfenghneffuveowoieuooteeehofvsuevvfreenofeietegetefofegreeffinoieeeohewrreetetuirrroonhwroeevetrfiewrenevnofnvovnfsiofnotoweweeuhftvohhivieieevnroieezgffeifthefvttnutsfotfvniesweoftinneeohsehtftonreenvefoehovogrgrnwttvuernnwvfoiwirnsoiiowheftoeoefoegftihsovenioeiuohtehrishvtrfwoeeeitnruvuteuhftethofreonewunvoeznohogurieonfeirerrrheftteneontoouteriiutgeuoiftensnvnfeeeiiggeeoefwwtefrnehfnhezeitfinoteehotohnnvornvhuriiweefeeewintsoffwiventftnoooevtietiovnvereerhewiotieiuwvtiinisrtiosesnreoffehueofoieszeofvseorneorftvetfeoeetfveuntoooooeiwnseioonhfnieefveiouhrnosohonneeowwgoftevnengniinruehvoefhiotueesreetrhiftrusevhetoeowuvuzonghrgiveesfvwrervergsvwtesftsuiufvevfutettrtniiefhvoeeoioworeeototwfoiotitonivftishgtefgreefnosegontfwrhirwtnntiturrorutneeisoetsivehnovroetoestewfutuoiruhonowsegevftfoesroriiirgefioeheotireooefffusteeeeuetnneefehrthvoiweofefutnowfnwiivfffhfeinsffoushstingfoenoteovueifeitnhowgutnfotvefeihovwutetheeeotofieeetieinhhnvrennfoevneogesrroietvntvoetooevvheehefgoiginenttihteeisoevetieofhifonieussotvnufrenozoioeweeeeffoietnrveeevfsoifveefivgvvvstieoiotefftehoviehohiriweregtrwgunnnuoeevtiienhterfurvevviviiefuifswenfninghfeivievsneioutfrohfwieovoggtgihoesneoefheveeeusnngeeuerteteeevieuugohestiwioneneeroonenvreehitieeoetogetivueneoveiefssowiwvgooeitofsofiititeeiueevettvosrhiiehrnionfiowrefweusfeofosteoisifhotvnoneeftvofoetnnshftsteohennoeogguwurtzfeoteinggefehtgvteetifweetvtereeoeooegsffstveeuoeizhnghtveeevueoitonevfnithnoeuieetrueiosoheeowoheonhgoottfgtteiwwhhgnotfnfreeerfegteenvetetrueeihouiegvhirihwtefwetgevoehnhonoehtwowoeeootiwniveioewtoerwewoezioftuuhifirewoehtfeefenentfoenuiveferesnvhovueuoehrtneuzvogeeuttvffroeuerefeiofeeostthsioguooggveuegvvneevenwiftofrenueeuvvtiufufhesvswhstfhoegnuvxsoeusvgoviefuuvvenfftnoethfnstgteeouetnnnofivgtenretegisnhefgoorerrtgewfeeuvrefsvtoeoetitfoeettstoifteonisefreoootnseeesgeufferteoothrgesihtroesogiooouvsontsoereieiiheivgievrohtewfvirnrozeoeeofitneuetnegongorrviuffgrouiezhffsehoieeiunoeoiierooushtvineoeosttxegeeotwzohnghtthefveenvttoooirsfnewftsioernrevnfeooheoiffeoivnevwowfvtrffoiweveeeioweuhtvuwhgthuehfutftottngffenserhotfvgsfregvoooshrootefiutetfevoerrnwuvrrrtfnsireeesvguhfefvneofeeiiueethnnnttefefnrfeewwuwoooheototteionnhhornevfonvorfiuheneeetsiournouieeeenvszoueeeteoeeirfnehogeoetuefhewteehrineiggfertieteeffoweftthnhhfrrvesivifeereeehfiivwehrotnfgtvegveoievhehgrinfgstieuivtetriovegevvfeefisnvneeovhfoeneoihohtigfwtnetotfoegtftfrovoofeohreoegoeguiieiheworeueeoneeehfwivtsfftotivteiuewigefegirnnwofgihieevhgiewwooinvuiottihentnghshogereetetoinesoeoeieheteeefeoeerevitrevhovnhieftortevuvhnneetiifeeeeuusinvgiveiiftneeoeewwtevwvthgfnesetgguttoefevoeuenoftigoeieghunorufhefiivwvffheorehhfizotufenohenvhvoehfhvsnvhttoeneiieeeffeeievnonoeowfieeevnreeosuwoefwusooignwtorvfieifweoonvorouwwetntesfrovheevfohwgggnothonvnvtonuiteoeonhohunugvreoowvxvwoweeosefftfvetevrorrefregsefhfegfngtiheonihiotfzoieiivegfoitoehszniitgeghthgetetfwueeheieengeenuzitoieshnuotonevoooeunnsnosegwonhtriwoiwviieoeteuzfeeewftthinvhtotwunvihefgoteettwshirritgihwitwgnovrnssowoirevwotvvhunttrthihgvifoentoowogritenwwefgeuovvuorfntnhneefeuneniwwirgvetwehevefiteeueeorvseoufeghsoieuvvfrusrfwreofeieoooottizteeverveoneosneneeenrwvoreerttnenogeooefhooeeeifeerernggvnuneogohfrovgiferfntevnvtfonnhovssvreeothtttervrgeiieeuiouiferwinsgiuirhhrwreshteerweweiofetnvtwgvfeetrretwohtfhrnunesteeeeotefznoneenotueefvorefeeiwootertneonioeteeietovuvfietooseehigefewoogetinonrteteufneretznfhgveteiortoiueeseefienitiuvononohhwuzuoeefsothhsuozrvfovnighsevgiiweiweoetfeeiwfteofwttutnngohewtuugotooowffoveuofoiezfeoeoenewusneuniewvtierrfeeevehvffztegsfnohvewvnfvrgnreeeeeeveeornfrgroiiwvetsneonrnnsovioeohreeenvetstuntfihwuvurnftrthfioehefueoihrvgrnifotneetvseigweoevhooevtvetwtnieeehrgfvoveeervetntnioofotvrvongoviteenintfiovrwhhguonuvnottevrtveoirvwuveseeeetreooroieetntnergehottnteeeruowvivnteiweefnovohsffevenrznozeizetwiteffrovshgeeuhfineitnirfhwhrsuivevsetrsvoisuirnveoohhehfrrrietoesgehfieofvueoeeeeueeeeoffeffohoeooitffseooeffutgoternvvteewgnoeeteiguewriuvvvgfeffviotettoniowenouioehnieootegogeninueeroiiohhervovufforvfgfreirhotetniheiwrfesorneoethteohevrtthigvvvngonwehetifwgvrwwnrgefvfoerorveeesiwuzinrrtfueuoenrseioifrortfrirfuesrioefruuihvwvrrvegvrfrsfhveiwogozenrsuouwnewoefieovoeveevfvetieefitvteonerefiftfrzstttwrseeetfreffvewhoefoinroueeiitoveeoifreeoewotesnnvnenoeineneestniztteehevwneheseoeehuteieenuoswtuithvteffieegeetzvnivwevooegnnovhfuoufhutgfeieweioweoiifuvthotwrefetghtisoivonvhsefenvvriotwroteeunrveefreuifeurresnoegoeefvrhtihrhogfeeoneoeihontvfinsteotevuefeneewnisgvreogernfevoihrfesggetofoieeneotervwnfeteehevfiiehtvtefnhhgrinttorseitwgrgseiheornorefutenehwereteeioerheoiieeehvzwnteeeroesotiseorirtefhihhveeivvrtrgosiifernrrefeneehfieeeeowoszniivrhnoozhtheeonnothenwennteteihveeofirfrhrereforugetrtewegfniuiufnoegetefvfeoffeeoowsnrewtefeethwrefuweenuofswhveeotnreeeontorwnnterurfihrturoeenhiunnrvveeiueiihtswfivftttseuvheonifsnuunvtseeetneoffveosirvoeontoeiooievtgwureertrtonewfwgtiooeoowtweneteioehointgturneuneeotegrreevveihhtoogfzhtotheoheorohuieussuzfhvnenwfnrotveurehieernhieoifoveoeouoooreuevtouurenreoueeewnoieefnehovotiierhuonevefuohofnhnfzeiffoswifueieneoheeiohfshoohigeooethwvuevoehieroeeuihghtotrovnstooetnfeweeeonhtftituvfetewhirofertiwteevirfotnwenuooovowenvewefeinthvteunufsiowneofwseroovottttvtfforuweefohoorwrorvotswiovisvwioinevouvironoruefenoouohnrrowfnrooieffeuetofrfefehftioorrweoerwheeuvruretefffueofrzrewnorveirohoevserotirievffoeiereenhveunoiffvnhfeforenieiooeteoewenfvuzffotetfwnosfffnrooootwovwoowrnstoiutiufzoooreoetovfeofioefsffoeonootrhnthofftfetvonooffroweueutveeefeoeeereeevovtfiuroneftvfeioeowrriutnerioewurortetnnehffonosuveoetvewftrweiwortrffenrfuewnntoeewotrtoertvueorwuooosztueinrrfufeeirftoosforveoetouenureowereehoovieweotvefuvovvrvhterrneswfeuvouwetturenezofoftofeoeioorrwvvweerfootfetoounrewuooofeevwetoevetrroevnefuzswhninwooorefrnehnoeizwoffvveeeeeoorefufottfzoefeuritheeeiieeefoeowuoeeivrefrevoefrnsfnreewzfuwwevneeuonifewtnruoeiovioifrweoviwenrerovvzteeftieweffoeeurutseoiuwouowetooueftruetewuooruooiofztifffvrhovvewtoueoeisrifeeouvrrruouferovutrfveeenffiuifroufuovfereoouoertufveooevfeviefoontonuenfvwofweewewsrnooevuonooovfhtfuvrexeosntoeofovtffeorstineorteoortuztoirfoewufurveoevteenvfeeviwenenetooofsetnrewwehvuofvfrioofoviehovfovuvrieeoefeovrtoeuesreiottztwteefueofwnretveefrvretfrorutuofrhfzuoroooresioooeonrefewhfoieehuouerinwnoeetnouvenrvroiofrnfvroouwuwesfretieorneevrrwtrowunnseesrsefiffoorvefeoiufoheoefeostenouettovontoevrsenevoefoutwrourtohenrwtefnestrteeoefrwueevfvnvoefrzerfowehooeufsvfhofwtofeonoonofiferfeznestvuefervouorweefuoufrrfwnviwvteefrwfeffttenfvirrtiroofeeveueoieooseeotwvoewoorfffnoferiwhewusioernfnueriveneonuisneeivouesorrerrireffnoooeutfffiftwroeowvrosexwurtviorosnrtowufenoetovenfowvtoueeefevevevefoisefieurrnrwriewovfevtneotesfsrveieorsniereweoorfreveeoeoeorovnnnxfferhvreoeentwottrhreeoutorvrttoweewvwriwfoonreontewoerononoriereureetvoeusorreiovfufuittvrteeefniovenuvsvrzsneiiweeeeewfetneufneeioeeefeveufrtroeefoefrsrvwofwtveouefnnforwriuttouenutenuffnefefefovrennfhwfenoeetwofwttwiotrvwovoneseweenztnoneireoeneiefootfrneftuosvvotoioneeteewserfseeeoterrneehsznteoueonrrthvnstrvnoievvoueoenveotwfoseofvzfeenrvetnfuvvroztorwweftetotwwoihoueifeuerhfwwvseuffeeennofefsentewhttwiteetvveeeurnethzozownesouoftwehooeovfefsweonrerfozovnrhwtfwfoteoevnviuvvitvueeooerfsffofheewvreonoofrihrfuunnfwuvorutwfoietfvfeoezfrrnofeneeseovoterefroowoefohiwonefwuvnnefreworoeuszsenoootoertfunfnfeewoozooeirfowfheioeztowfoxrofhnuvrortitohuuntreeeeotvrtesieireorfezrersntorseeeffveteuoevitiroehiereeisoreooneutuoeutehsvhotetfoeeweoorouonwtneetttuieriirronfhfewznroifoveeotwourtovehrerutsrovuefretvuserhhnoeeoerfrfuvoefirfweeoihifrnvezoetenvtevvfootinotnennnwfowenesrnertfoeutueeirfhvfuieewueuiurrouufvwnierwioffreototexerneosuvfeouovwrtrnovneroiortweoeeteteosoerrvfonffrewnrfrfvoeeoeeewfznfoefhrewffeeooreeovtnnvzeioizrutweorrovevosoorreeonneowuieufvueuweueotrtonootrfvieeefweevzrufoewfeieehhtrvvnoovifeewiorriouifveoewentnwtzsvfwehrenfuhnsttrnfoeoftotfiheeiifvohesvehensfronreeoezzfwntniooeewrhfofesrvrooienttnevoniruneoeooveftfnetfouveniwinnrovvuoeooneoensrorreoftufvneooeftivreroioeevueeeeueovfftineoioeorevfofeoefovtfieuetvvfiroiteenoehvnneoevuevnotfvfoovtoefftnfeovnfhfeurvfrioofevvteforeotferoworeuoseoroeewuznsfvneitzruvtvfevoehoeettwrtnfwzuofowrtseehtoownfevtrnfuveefovoevtoevonvunwoeevrtoreuuufesteewtienvuteoofhfooinztfiorihheentvzwoffvvronfheeoooerrvofeeifeefietoionsihvieoevveferoovevooioeerhoenieuehvfevetneifefzuoveeooiietxrnerrfwttvfffovvoeefweriitieeivfouwovrnfewreireenoufuifzuenotetoefuervvefnefoutveersevziitefeoofofersriweeoenwostfftreehrhxifeotroonefrteouufzerhfewveeooioorirenrfotoeoewtoreervftoouxisurvonrefvfevuovehtuoverfuftoeevsifiwwreeevneiuvurrueweeotefofefuufvftrtstnveeeiuvfernsooeueoenieeweoeesifeueefeessozveeoveureofeooutfuviirtfoestorrtvuveeveenevffvezffonfeevffostwnvhonsenotirfreorweoieuuhzeeeeeoruxfonortofiotifhvfeeneowfveeweeonezoieeirteuoesuweosvwteuswteoeoteonvsfuswofvffeeesofevosieeieueehnnevfeetreofxuenrtofoffutionsntifefnreeiffeotswefiuhereereesrtueveofnoietefueefirnernewteiteestrovfooetfoveuefsttntvfneovneuesevtvovoofoezretnteeeverffetvewvnettvoonrfwfhesvrftfhrnrteeeefrfrffeeeonvtevfewonvorszuenreriioefnsrffreonvfvevrsrowninureetefeeoeeteooeeovzovhrotuwoioernfoottevvufeniozveferevtvefeftreneuentofeuetetoeiuruvvvnefnetfefoefrherefofozusrevounfeosfternnonvofzuowvoetzfrteewiesnufeofetfiuzroreeehifhenieouvfoezfoorweoeeeifstoosoreonestiwveffovhewwefivroootffieeoseofhozewerweonvtuetovenvrwztrrfeefeusfevntfnwwuenueeoeretnrfvevefueononwonrfnevrueroernrooofsfrsstesuesfvefworhfenerneerefesneeootorwrerfffonnnfvfiteovvonrsnrrotvooeezufvwfvfxvweuowwrorefefvswfeetfehueuwntorviewonoeoiietotwnhshfnewnvtnrtreseovnhitenfsnoovifrinonreeettvtorteotrvfsrvvvoerrewvtuvuvfoeofurneufoeeveonreuueessetvfvniofsofhreuseffuonrowertrrvoefseuthssofgerhofrntfthewwewoeivwwvuohnorfoeueiwfrzeesoneereftinhnihvooeffivoiornsnnftonveevoftvvnvfeoweoeenwvuetvhnseoeeseooenuznnieneooroetvevivnvretettwtefnwuuerorooereetressueevotevrihhweefvneotervnveeeeroooonevfvusrivnvsioeorntevnnvffvourfveiwfoneteoetirfnwfenvtfeirevtteeonrrhfvwvfwnwtunereeeoefsgeeeiotouhfovreesvetstrwieeosfeenorrnohueoroevvnweovneonternooeorvvhovionnetsrontofnotetwrfteevooenvhrsvfhovteifvinereveofofnwirnrornensovehnevexsoutoioofvftuesiiefeftofneoueofhtoifeozfvztvuneruoteueteeeneosnevwnwteeofvoennewfgefrenfstteorofvovfhtsreenvwonofieeeeofrfonvonwvrvtusofeovfehtususvveoeerurrrneoowerunnoeoihntvwstsoerefsenrhotufoteeehheowvthufeernnwvneefovrurewnounvveourwvstetezuhfnieeuewtohvwowrvetioienefoferiwowfunehtoviotfrthsewvnfoeiovoerorfwietritootvvewerhtfrernfovtofofneenetrtrfoeouvoffeevionnieiueiefreoesffnvowwouoeiufrwvvsoeuiffeeinuttowffrrseoerveeerfovwheeivetueoswvehwswufooitorwivowfhrrnnnivtwtttvfftnfevveiretfseeeeeosseerzonntewuufnvevetoowwfevvvoeevrnoovoeoviforvvoffereeooeieiffeseeofefentoeivnforstteerfnneifeurreeenhwrweoutenvvoiseohftvntnfvwhntsoefzfriereitoowooiweevvoetnntrtezefsfefovnofttoveieoetvnoeroirutternieretevuroeoeninefneouuutfrnnohirvrrvotrueefvrezhuoesfnuveefounnhenrveftesoneowotoeotvwrfrrtseftvwohtzeueoiusfheoiveorretfvfteseuwoeeshwouhniffesroosefehvoerfovrzwftrnfeeoruvzreewvrerervsrfvztvetvveveeeoefeetehvetsefeeoevvuonfeevvnorfninhfeninvifhvhruffeuoueueeseisueffheoneovveeeffunersefoosuteerneteveeirnfoireoetreivnrtvofonhenrsvnntssveoeoohvezrfwiruvvuseooeeeusvesoeeowiuousoeezonnheueonewesefvnrtreefenroitefeefwvheeueofuoefuetinvofhvosetwftvworrntrinfhweofoeeeeieroeonrefshhfteoeohegwoosroeitrrztofowrfohetovervnteneseuefesegetorrfnveeirivfvenenoeotniufsiretrhehvhoeowioireveufeifretrforseeoereievoftrheoiozooonefffvrivroeueefowunreeirereftnenvnrositrvzeteevtveeiournnotfveeewneurvooseeehnrehoweotweeovoefttovuoovrzevvvsoernveotweesurrehootrugehfsvuoevetrseotffefeevwvenhetesnuetteeefetonhveeervwetsferfruteivuwrstrefstnofeenveewezriooosofnetnewuveeheieewezfoefeotrotieuteunefvrotuietfefoeverofzfntrftofoefneooefeoeveosonfefffoevirusgnnvenvtvenvuutnvfwsnuifeineonetoovrofuoeeeuefutvnoriouiinnwuntettteeotfnrrfvvgeetreeviehvenietneftuwvefetoreosoosfeheerhnuhfoereiwteevvrervoteeevrtnuehrheoeueferurteeewgnezooointvunsensoueeefrwfoohehfgoevurrrivfhowviriiovooorfoetettsvehnerwotertuovtoevtetuuintiohehiuvoewfweehesurewfretftfnsvunwefnvrtrveruvfeeenneueowinthevvhtevertwwwnhefenroenforvoeevootghoovtefeoffvwfoiooeisfsuuzeftvwueeneizthohvoeoftewtusweoeuuetiornrwotufonenurnevitevteuinnhftwsennertnoeifvvveovveewhheutirvoiotvoseonotftesohefnhoffignietonseofteefofufieuveveunfnnvufofrooftvoovevftorivenuneooeteweusetertrwetnhezfnfoeoevoiehirwfvovftnffthenrftferuigfvotgteerenonhetheehteofetoftfwrrnwehvhtnotehfseesvstvoeihssithshehfoonteooerfoefsrtrsoseogtotnrvounoewffsfoeinvigeefreuooenheohoitfieetwirsroofrnnerernstfeeevtfuoiosvieovrwovfisnrerefefietugfwotrohofefrrohnrtrooenwnevooeeourfsoneesfoeeeosnrhfogetneooiefirforrroueseoftfeeeiwrrnurnegtorogorfefnortneutrwinotsogfregvrwoeeeunhffnszeeioiighieeetveiieeoeffvvfvestefefsvtrueefeerrnenooeerosreoveofizoorvntxfieefenvnhsinhoneetnenhgftefeeohueheteioifoiovhfesoevfuffuoeogfovgerrfotifvrtiiofeeuovuwhowouteuovnehtswtozoeffeevrohruuvwovtneevzewnreerftonesneheoeetrzrnuiowgotoirnfeoosvreoeeevftretvnitseofffienuofvovirishsueoofeveoeovufiogtovvonrozsefvefgotfoefttnrehvieivrwethnnseueeiviiewewiehwfehfertnoitvvrnwvunerefefeoonvoguthvesitvheeooguourtznwesoeeotefnrofgewonoovuenteiowureheweuenrrvitivifvoneishfeirtfeeooueotovtwohvivnnroesrfoewrvfeetuotuovoetetgtvfnoeefonoegurffthgeonvtehfvneorsortwfnuereehvetshowhevntttoeeonovoiforvforeheooiohtuvzweeeigotsotefofhuivfforeezieeouoowifvofvfteehohnutofoeeosroegsevthrgeehotwiiffsewnteeetveoooeniweoterniehoewtutetuttoetrvteevvoeerofnvowouhveoiewvesreertnowvihgeetiieifosthioeovttowezrfnotooovtetveouuoiouvtoreftsfnvesfevrennevuveoerrefonehoenzwtfewererwhteornotivewerthgoeivrefeotiehnfnweegrortnteveethhnutwnvvvoeovoowtowveoivrhoeeefenfnivnieefreuvveeerfhfrittovofeensnsesvigeeetivtnroonziteotwsegueowtgituforfreoerefetevvshnriffefvewhetorfhiifuvenonoorherrntevohrevrofhoeueeitttottfrufogeovtvwooifufunvhnifwrfroeesiirtvsftoihiirreuteoiewforvozgfvsefteuehfrsetwruvfwneiournwgeteetenrheernvftntevrvunesuienetueergooitoooegwvreorrwoieftvovifggffoetrrtornveretfuerenrongenuenuffneowrefnvvhvuthftioivvonotvvefotroswwevsefwegonengeieoezhoeoivozroeeefehseveevtefeofsweroefvioneohtvfugevertroteerrvhrunvetefrefetzoffeuetvteinnreeefoeofwiohovnwfiowotifnevetuoooetevheneigrwhoeennhwoegfitfheohiuetvueehfeunweurseeevtreefehevugosivnorhufitneoeefweerftgfrefuezeerrtveeeoerotiiuefgnweuerifetherheegoeuhstverwvgehieeiffnisnfvtoosventrhoeoenteevoieteioeeoovwvffiefotffofvhoohfohwesseoisgehteeffsttrtteoneufeenefverioniowrgoftvwoorfroofiuveeffifeevothngntueinfenvieofoouseneovoeeozetotvteisefresfeeeeffeeoesfewfeeorieneoeivhfhtettewonreuerertnfffveeeettteohvesotsvsfegwntffetevuseeiteooetuftethrhefsevnieoiiiooetnitvefgwweveeovvnfverusivnfevoenufovonueewieooroneniowuenovororniroerrhetwerievhoovrfweeonfwoenvuwofvtirhivetofiofeeirnntsthhiizeoierereetftttererofutviitioroevionfroitouugeroeeenseeunerfeoofrovgvgetvhfwguiooiooohfghfrtehwvztoehhenoeveenioefoioefsnenzeeniouefseonteeehuetoerniurnerrvfeettotovfenvuevrveogseueoeugrhrureoeteftotfotuvnooufghosoovweueteoeeeievuoferueueentnisiehfeonuhufenooerfgrovinuherfifohttrevevrvovenfsgttivoguvseteeirergiuszevueiuhwuoviteuovhunsstehurvrwwftrietotehthneeferhutnotninvoeestehooofvifoeuoegivfevthvrfvrnnfuotheiggvstohffhveofneongweeheonetiegttohvtieteefenetrvonerrnroosfstoeesvfofnvzvenintfroegeisevenovrhetgotfroieensuoeevnviifrhvtoeegufwzoveoihonoetineoinffvetroierigfurtegvgeoovuriereitsntorneunrhfrieeriseeewheeffteihiffrowevoeoohrffoenvetftiirwoutofeuenoehunfevtgenotrvtenoteevvveoteueevieetzvfeuuteeoeieoiwefswegnhnooevvnisozefuveveiegethrewfnwefgteosoeievnhfeoteettitfrnhuieitteihofvowfetfootetengoufefoitnotetgeefeiftefvewfefrfuuegnrwonvroxeigwntfrroororherwsergosnihoiohoereeegeoirtfeugsnenrhevnrvvtnoheotrewtfsrevrefovffrefftugshueifreofeooennorereetffrwhneevvftforerentnosvfhnzssontvoftooertoeigufitoeteeihteueiiieoinoeethoisunofeorfeoefhoruugfhroettrtenoeefuefteuffhootfoofwnoterftosewrevtehntvoieoefeuohiieohgouoitsiioieoitvniuteofwntothiifzienrvwefffeotvftooeueorovhenhttoefvhtgoeiofoheerntwoiioethtgtsosnerneunersfvivttoittutngrwhootoseooteefostnthoveeeewuietiotrifneufnortiirsnsetoetiwteefrofinivoeitesenonowtsvvgvtruftnoierweoefieswierfrvhooieiuurhhnereuetneuotieeugsvrtnreeeewufheuttinieteeivtohffeohoenftnzhgsuetorehghrsenftonetgnhvtrwwrreoeoeofeotweevteowgineitivrooehtnorurootfevifterngieeefrtteotrwfieefhiginorerefvoutoonfefhiunewwirhwohiitnrrtieuhefrsneivewniwrieethgfweethivuvvetrvroitfrhourgtiteeevofutfoiuifeeveohtveeusetofosivvverrenrforewesetvzroiosgrgiuooeeieouveefgvegotifeosetrrefvoinewzgeofuoonegooevstniieeteeeenu";
		//"ertfsxvxttiorseenivsoiwosefeinoinwoioousiieihtfirrnioeenwiortwsefwnnniseoisontieiitnvsovthrenwfitfenoiwouwtrtnxneisieinovhuieenrveenoiuoireooieiuittefotnoeeftfsetooeniuvrsnvetwieetvoneeoiieeiiirhftnrntihenseveeorioriononnuhweixefoiotowxreossentetresvzoerfeonvhfoestveooxesintstvefewrifsneeexveefoxonvueituwoieefvofwrfistixeesooxoeweteortfevtsuffohnfruiwitnuxexrevrhfenwenofnzfvsiofeneesoshoefxoefieiieeoueofoivshvtrsoneenenwiexnifttfeoooetesnouewtneisfeenwiiwnvuntnwuesniffweeoretviftseeexeoetzntefnfoxesfforvrwrrhrewtegwsnvinotonitvxeerwooeefswxxtfixenwfxioevierefevinviwvxonfitouevwxnshiewuntwunniennvunvfnnxinovfsvohrresenffintfissstnrfwinsegrrnesentoitoieneiiinuenrtssgosetoufnniuesneseonesetnstiofieeosvoowooeueietrheiienstifweeueitioretiwefwvonsernsxrtteeiisofttwnorovenoisnrsoxseoeeoeeovnoweeowhfirovesxeutisnnviieneetvuxnreoenxinfnrvxntooeonroewxeoirxenfeeehietriuoofxiexwntotointhwvtnfwtnrieeofifinevsfxioninsvntenrhwiwovfenwfrffiofeiehuriieeeswooeofienuoeifoffrfetewoofeusoeiireootseisouvoofntexsnorovrersoovnoovtvvreineerrieeooxtoeseeowixtfeoettiornofunintonsrenoooosxifsrviuitonnetosfwnewnetoznvfhueovwrnnooexnnfeieninetihvwnrexiinvnieevexnwnvtfewexftixiernoonfeinffisofoefevviownoeionforfevufoefreisetvovixxoehuiniivvirewsrsoxoiohtoovvveioertfhveoitoxoiexniieneteiwerngfiesiiifwehsifrteieiwoueenwssnrtxnoevefrtxtoesnferxveeoeifoxuivononeeentsohofwexinrweuovoutoenhnnxenveoihfstturoeeeitrwiirisiinuhrosooiinffnoriweixeiuuenxtoouwosnnshiixnnefgereothioiinrfnneioeenitofieerwtreniortiweoinniewinxeerxtneeneoofutiiirrnsvoefoetssxonfxenowirutohnxerisweewuntnwfwounnentnohevnooxwwiifsoooevtviwsfeounfeitfxostgfgtnnfsounireiiingofxwesfroeofsxefirstrfnerfonitorneneiuifvhnninfvwsiffrffowxetvnfsrwweruiirfoooeeneetuioveoiioowxwsihvowfsrefifvetnwnzfoesnnevfoitrioniehtovwhreonensnhixsifnioeuushswtnnnfnofvneeetooeenheinurowzvftsoofwwgewsunnioffwersrtttohsrfxsoooitvnnsgruieuvteznwrueiisrineoewnxooiwnrreeofnxtuieesrnvtwotfiiewtoteriifwoofieriesoteofterverrroievoitnnnoweineehiowwvsweruooioffovoonrxvsresitrsnfinnostheeffosieeewntewotwfehonvfonrwrennwxeouontwxroitefnveneessrneeiiioeufeevofnxiifxwhefevxxtiosieonoexfrnvtfntnonereioiiferoutwtweouxoeneiirwotenrexvoouiooztnnvreotweeetveefwzeiueseiittitivsenrfseeisieosinnsreifeewnffiiffisfoiwfirtevewwuforiroteiefetiexwioenshneiiooesirhnonnnoriieoioruevroesntoffnuvievtinierfroxveriutofiovweivnifuwrwniteneefoeirxtnfiovogvfoinnrnnitviwiointtwneitnhetihuetnogwvfvevtxwefooiihevxnvxefftnnihfrrieoeortsseeoetnoioeiisowixnfowioseffexvoiwtteouieoexrfeeefeioxotniintoxwtfnofvxoenneoxowwoviionefnnssoifeoxrssovteeietoiirfeeretnerhoegoiesfvenwnnovzonifetorititohrtoixsinvieivfeivueufnisfoeinetioeoeonwiustxnstenwisnownornsievevtuwnontsntuonseeeneeeeheorivoeigoxtnwessuvfviniuuivoeeoetwvnxixxrnuvfweosofseohivuvvofivowiveinwvouueoeettwoxswnervtnovtfxionosweuisooiwnewwxnruowootisinrveowieoonewroefnsietfeentxoonoxvezroeutvefnueioihhxeoeeuxxifotwneeihewuefwexnftsnonofvfveoufniegionswreotrwfeowfeexxeofxtnuevieffoeeeeivteeeseofeniorevrftenrtnrnotfworsvifuesfvofxweoffvienitnonfeiotwnofnruswfonwottoenxorntfnxeoeeveotnouwetnfteuifnoxnvnnffssxfnuwiefveowexwiioffeewuwnewroiegnwzsniiinoixxeiitstsiztoeoefeesnvfniehotxouwtsrieernouwueuovfwreernovniwofrsvenioevnwoeotnuenfxientsooneexwioueioeeneouoeouteeweiitrreuioheonteuweroewiuiooftooutfeueesfenuwvniueniniforotviewinwxnhnteeftotfnoxiruonutofvrevvsutvrtnexeovoxffoxnfeiiirevesrooueeonnwnxetfofseoioenwnoxeeiwiofxnfteottufnfowseteeeeofwnxreevnvovuurroeefefenuwtoriofxwuiestonhreeuieeoonirefieeostieeeeossnveueerosinweefrsihrnveuiwnesoeetwvietoretzxonnuseixhsrtgnofnietseoenwvonnoieftvoefotwrooetxetueinruizotwuooiooveonoiftuevvenhroerenrfhfsfifwreoewwrtsesoewtvtfueiszviewieourioeinurnsrethertivnsenswenffhnrsvosuftffetwfoenneseffrenfnewsneneeisfwfoettfsstnnweteffotnfitsriotoswsuiioeenternsvfxivtiiwtnfosrwwretsfitsoioohfveosfovtifneeieuivtnexfuoeeiewirioruzonrenvitrsovoovvterswfweiiioorewhsefrieinerenexsirivifrxrsnsexoosveexvotoiofitiexfoioiveteitroizeisiehoeeoniuiewooeisuifxtotitehoswvtfntiiwseouxnhvfnteiwvrooioisnhesowreosiswenrnseeiweisieiewfsxfoxtreeinxxixueuunhwoetosxnvrfeeewhtxeuufiowifefnnneesonfxitveeeooiivetnovtiwtneoortoioeuroosfxfewnxeeinnetnnrfwrfhvnieniwtivxteussoieeotetuooxnuseioiwxsorroeuenrentnsnvosrufioeonteofiniiexfuisseooeiownsnvutwsrfeeieeseiiwvfxrivnfhhteftuvfuexifweentfoovsooveruutoinsofeswuxofiowififnsennsrixveovowfeeueevtinvifrooftirofwvuoutnuxwifweteoiosieeusesoiirneuiusnnxiiwxontverxferuefxsnnorrenrzeruxxnsvooetfxiiseirrneetnnniioovnxieesweewfieeuftzoovnoifofwheexofxsurweesinweooxnnoeeownieiisoowteiofonewxwreoeevrswretotvnewetvxtutufeoeoieeuhnoiieuiheweiteeniftxerntsenoxrittievosineuuxesrwfeneeineruxiosiveeeenftenvinivveroxhtetfwnttgftvninhnonesteoexnoooriowoisenoofowwrtwowffttfrrtervfvufeotffhnxfeueftwwfotrifwenfrfetennisftefeiewvnniiowveooiirorwivvxftieoweeufotorsnrorveiftsirvofoontixfnooteoneeiorneosurnhnxfioiiteoieineeerwftxviiwnteotefesutreeenenvutxieiohvhzrironixovonrsiiteefeeeiiotwfrnhutouitfreiresefeofofiniifnennowoifuevteoioiixtnweeveroeeunetoeeeteesewewfxunioeufoefroreofwnrznvifewoeeouxxetoirnoinnsttwiiigrnoufrerhovfiveefreteoswsfvsrseietneewtwsionisxotortnsvfsvfriioisnfuuvifiwssfofnxienxftisxeheoffesveioiitnseowfoeniofeetfesninfvusiootetixfwewwvvxniurefwioheriiooiwfvsoveifenetroeosonhfvfwooeononfghuonesefoofnfstxeevoenieeuofuvonniueoooinizxfieexutwxvnosroorfovtoruoetenrsfexnweiinxotfnvfieiiinixitvwwweoevnhveftrrorseeeetouefiuxoewtxnuotvoieesivefrvivfweeihwwxiexnwotffnxiwerxtwnwiixufeoeenrieeoeouseftifxensioiiegornezonxenuxwotvrsiivsowffnwoinhfooxriuninioownftoewvsoeteuefxorexfeevnfinnineitwtiietiufitntoowiutthrtoiefsewsuonvveetefoeixiexovriiitnfrfeuntwwnsgiuworuosvenoniswitrernnerfvoftihonhoxwfosevirfnwftseghxrsitiirvfvvefhvvufiooerowtunewthfvfeoeoiwouvefffiftietvnsoinforoegsrsexiowefoeoufeofiinoiioifgvoiteieorenevieteeitwuuienoioxvriowoewioenrrxooseexiuzeewoeirwotozetvoreortxefuvewofeftnueisoneeivroniewuwniveheoohsinonnfnvofovxetveiifniuiwvwfieoseseisveitsghtteeeiottsivovonveinvwtteofifevwnexieevfvvefhniwiueurieefeifoevnnexwivieewnoeerinewoeefofeoohnteneeenofoewvifvixnoetvtitoiwovsifxeeueoexeeiwioeeeonxnotriveionseioxvewnfvxfsrnstwwvivvehvnesevereivfftonrvoviosethueevhientinxvefiintvisoiefeiteexfsuonotieniievereeinexrvstnoosnrwhexoffrweuehonuetoutrsxisthrrfwixueeuurvnseiefeifrtenivtonovrontesnrouenweiisreetunwonvethifewesegiifwnevfotihwinenffnxtnirgownxhifiiwfeewfienrviixnitoufeoiiwioueovueungvoxeienuffifroxfifninoxetteetioxwoxexwfevswtvonrtrsentierusuuitiotevnonootriioivoonwvxiewivwotetuevnefentxfivwxxrwivrwevuheueeuohsfesxnivonwnsonriteirwehfehtrhunioofverwssuvstssenxifneriienneretevowererfnifnnriewfwsiriffseuvvvforisxvosntetrixofffewiiuurnerninurfhsfvxonforeexoeirxtneeifvootxnioewfettfeiseninwuxtutsnrfeonewioioiufutvviweuoennowfvtieiuuunnitttxoinitnwtoiiiifxnftenoioterfofofnhofxitvvisvuinnuveeefrowhioouioisxoenevthuinfeifixesrherienftfsiuvereuooetofsiofeuhxvnhsrirtvuwxtrnisstxtnoioewixfieootovefintegtieioeftifrnnextgeeirnfhoiznesxefrvvinnosetoiftennoonnxenwwhtiuwshoxirfefeeeeneoivoifnfvwsneeotnueuusohxwvnnweosinefefeoeoeeoovnwifeunfwfooosoostiroertosfvtetxixffertxvnrnxetfnunehwsxtirnueviowuffrureufuieiiefweneritrufxxnronresussnueiwetxxiofxntvrtxinfuuesroivnntiieosoffiroohtetoroeotfirfvnhoffieuonexewsxnssrvottexiifweohfeeevtfewonotnhixeiintetzrtweeeevenwunoonfefnontnsvviunxvritfohtenuuvoioouroeieovnesoeotnsevffvueuonwneeeoutioeieeoeeitwieuiteoesesheinvouffrerinnnoonesiwreoietfxeirforotninfonnvttfnvooenessnsuhnonnoxnterifwxefrfiruwvseshrwressufifoeixtentnsneuninivnioeonwxsoofnvrenwsoifrivvewnosreweewreveetfiinhtifeoxuoienosovoffexoinwnvieeoteneosuoeeisfnoeotooeveeiitfeonifesnineeeriiiwffeovuoofrwwevioisftstwveowetwsrusefhriexnfnwewsevenneinvxoiswefesetffonioxsowwveefsneeeooerxnefxiovsvoesewiifvxeeoxxxuteofoeosinifiestoroffosswwuinroixvoeiirzeesfsfvfreffifwveiroeiisieeeifwexfewhewxuwnofftihwovevstvisnnzorefnoteneiirirfffiuonuuuveoexiiotefoneevsfonsrifueoerfonneteoostieiiitfuuoeuufveuerorxtvnnfentreoofunfieoessxosfwotonuxsfwniounwuwiwioxoierfewioirvtseutooostnifreesofinefefnnoeneesioinfhoeuieoeweueoonstutentnffoesvfoneoeixrffuivrnooeiewieenfvieeiowrroiirrseoeieiiovneoiroetetooeexovositwneuvetiotxvtentursoethwiievreeixoiieieeerwieviuefefowvewoerxeivffntriouonveoinsvotfienneietfinutoovexennvinieofxoveixvoettvxeoewsfsiisxefuegsooiniieuffoveoewfnoxefoewuisgtnessnetftifvwfeftxfwtnenzvtnrinofeteinvxuftoueisofitixrweixvviounenvsgtfnnietnufohvrfxrfesrfoixeievxtseioeieeoesseetxeioiswnuseoofsefenfeitewottoiutofssreniextevsreiesfrvwnifhfueeuitfxoneivnrvhfiwxoiiinxoneiosvwuevverehexinsnoonsreuietnoeouiiwitwfvutovitsuienriifeotirxvnieenfoftooxovorvstetfoeontexfnnnhtrvniooohtewxooruiuhsfnerexvosnnotwvvoeeowvtiiiuiviisonroxffwooetevneeeuotntofwvietotsseeusuevnosutswoeirofeietvitvfonneuouuiseriixurooforvnneeefgvurivfgxfierfwwoveoootxnefefwssvvvisoohevfnowntuniseieewunofentxieoiiseonexnxofuefeniiixttwtesioifsenevtoontreevwwrveefeeenooerensooeetovivvvineiuisfofnfrwnvfvonsefvexwvtntifueveswwfxiennrnwfegiishniinesenuweieeofonsvnesvfrwnexweetooeteuxovnrowwsenoxunfwntonithwnenfifnsrnffisnwneeirhnuvfurroewoeeeoroteoxoxifwxerrfvrnefoixeeweooiohitnnnesrnisositsesfuuisvovfretgxivvofeuefvniisveenuoreenwswtwnvewuevwurfevfennoveoixeuuuifnfronverieivsntthrorhoroxootzoonoriofisiueenoievseveffoffunvfftiwofnnessfevuerevuinenffntsooftnoieirnoioshtnnoionoewritoinfseheoweoitiesneiusrinvifnieouohexnrtsintxooninrseoexrfsniefvexoeirxorwtefoefexovewwoftetrtixfxeuwtfefsrnntoiteifiewxoioveeviftefoiirinivwnitswxifvuieonvworstofoeovoienxnwfwuesoonviuivuniwnwrrwrfiexunnerofnnxoovezvosneeeftoeowewooegoenwoevowfttniifoosneweixsoenttrtutftsreenioerroovewenfetovrrfeefwitseoeevhfifsiioeerrftxowexfrrseevtheisefonofofneifutfeseenwrsswoovetfxofvroevxnnrtviowxvtssriwinfnhoonsfsifwewornuehfnrnvsnffiohoneoufnreiertfueenifofeoxtowiiivnioreouexfhnvsiosnnsifxfoeeooofeefnneotionhieinvhhniefxtsinxeneerinterrnfnvniionsviniroheositifuisiienvisntenininxeoiifnrruineowsiveewtieieurvhuteioeinnoovreeeiexiiffieufetiiossvtnosotesxifofitevusrforunrffniintfefnwiefxwiieoufooneiiusnoiwvohoivuiufuosiennnffnztiirnxetiiiieifotviiowfiveexnoivenfnitfoinrivtvtuiffstwxvfofwfiefxfnowroofveeeftoegrwsetfixtnefoouurionitonnrvsvwouirittoeefiooietifurrnfinwfvivewxuoxxftionrnrowinuuietnenriunwfiefoutnroxtewhotinvoritnvnoeerwnffveuiorixeoefefeiiniueiowxsosexortfreevtoxnfiwvnorzsiuoiiioftevhieerxeoisneneeutfgoitwftoeiervneessoreooviuusfioonsxtroviroxoenovrnowntienooiiuitroxortsfueinuwiwfofnoevveorvweixvefnfsnronhirrfrevonevsvviioieiiviireovffeeetiutevsnowoetsfevfnuxetxtnfssswxetftueirfefnrwixixxvtoieeninxofvooiveeooxteseeveeneenexeeoxtoieinoowuofoexveeiotosexosffrnexoernuvoiniohiivinoirwntstniriieiooeeeioietrxxeshooetienxeefneotifnnevriefnnsfouvvenfeoeotisienweneexufffffwntffutnnsuennxnotinrvooisfesweeoiownvxvwroeehrirotehoveorviwenxeuexhfrxwovsivonuvifiinfweeefoonoexhnefoxserxvoxovoeeettfoinevvfesoeonffiifieneuneheeiirueowsuvtefiovinoneowxeiveieoifieoieirnrenefnetevtoteowusrweiiioisrvrewtssgoeisxwfueewneeefiseexfntnfxtiirtiweservxtsxwnixvwniruotentgtxozouooruivfniihweuireizoenssevurfiniorueneuifoeonenoooiwxxewtfeewoxifiiosoifeeunuinfxvinfuovfwiuvnxnoxsonxsrteiitnrvneewrnefsufeovorowenoouretrsgotinvveeesotoeieissnuisenffvnouovssoooitntifeiioseosrfnotnsunrxeveitviiihoivfirxroreisiwovwfsoowosuwrsssnvuoninssnxreoenetfuifnoeoozoiroxeowinieeuhvsoixostzftefwxxeuxiusowsuseoeesevefseieexnorevsniiitwoiitttixvirirorfwveovwnnttuivrivtvuovuvitnnrsrseefeewnnvoifieniusonvfosnxeivixrifttreeotefsvitoneenivisovsineototvfvfnrnivovieiixnuhteirootixousetvfvenenveoevhtoviensretiioinionifoswffnriifhixevifuennivsxeeisfnotvrofrtooerxwvheitiuoitrrnueeoereenfitsnneiugtffoeenoeswxiowfnvivfnefxwusuretvesngiuuoensruxhnvnfwietwitfixernvwfntuioiiwiftrsfoifntinotfufinwuhtefoooiitvuoivoneieowntesrfioitnwuwtoinitioeonefxufsreersonnixxenftvueoeesfiefuifxnnfverixriiorxstwstofttffonwnvnsnehfeefxtnsvootvftwixneieoiiueennofeontoefrwioefeosrwnifrtixotwerffniunxoeositeneffeevtewisisosvsenzeinovtesoxoerefssoennwiestoxfexinfftnheouxtihirexeuewoouixihwfeviffiiftietsseneweooviofonnifiohswrfoxoveesiovxxeviveoneeeoifinennvefvrfvwoxnufrfuewfruitnhsirinvffohweoeenxifxeirnoientfiuuwnitfnrfnuivvsevwneerievrtontunoneienexuwtnuuioiofttiunvxevieevierxoixosnwiofrffnsevnoiexoffsntfftnoewnsefnoieeeonxxxviuefshterenotioonfzuuristrioeniwhreevusfnnroooverneieifrvtitnnntiotuurofsfxfuerxesefrehexefniffofotnxiinexortizffwiosfusuoteusesesxvinewoeofnvseiseinnxeeofneeoeuirioiievirffiisefrftioewrutnivsoeefwexfxorhvfeensnnnxvgvsrvvxvxeeeewufuivfvsisfsveiirftxooefrfesfiifrxooerevooentrotisshnixeitftovxfveusnreietfeueieinwienuivirfwsfvneerfeioesissvvvsrtfonvnsfffiveeieonviihtgsoroewnwfohxexhnirsoowinexiiiiooieisohiunwnofennfvsswneoeeioionieoxwowitfofofriefxevnsrowieuistfnixtuxniwseiuwixotstiientfvoeorosntextonsexnsiitiffrovonionnoftevehewuirwtsfnuifiiiveoifrfoeexfsneeionnersrnioiueuoteonortiftthnoueivnrwisxuonieofervieohrfxhvnetsnnfxirernxesnotoenshofvfvoxevvouononhxroresiivreriesoeiueuffifiivtieihihurtweesfnsieffntnvvieineufnxnnoinneivseoisneifnononfteoofifsnuntwfooorrsifunoixueuenivifeofroswinhwrsrfiwswuoronnevexxvxonsvieeeteinsovtwoxieievoxfsteeeheweeensnshenvvftnoivwihnnxveeooxofierisnhnnuxeninnvoerxisersethhnztxouexutefxuxztrexrorintnivufxenwfsrxruxuxexxooneotvrsifwiuvwwnuxufefvtifsfeiitsiuxnwfietoeffernwiniteeeserswxooueonzvinefuowvneiexoestneeoigsoofwiovveoiviirwnnntoffovonieeeotwfnwvtevfevfinwworeehetfxiixtxnievoveifofnsvwooxvxerewnfeuuifiwinoouovifwvwtrfeoieiisnfvnnfsvoenenxvfftswivxowfiuherisnssrnseionsosxsfofevouneenifeefieuexfefnorrhoeetuoweveunwnevseoouevwrxnrwesnensxefeofeitfiewxveoniesiiosnwifnenesnsrnwnvfvowrxsxixfenriffoxroxrinoiweviotofiiufnwwfeotsnihexvvorinnewvoseixovnetisefrfohhveeeteoofosetteereotfwnneieeiivrfrtnihxfeeirrifuerfrusofsefesrooovritrrxxfwsevtviinfoseouofitnnewfoffowiseeitiottvegvnvvieseixoirofnerwfvoneeiiofroeronehovfrnweofworonxoexroenoeseoweoinfveeenegrsxenettxfoofieoinesftfoxnirszeoifeesoixtonntevixesevoitenfntnurvtnftiooeniueirnifftiweeienfoiixviinsuefzfwovnvwtvwfefuiefnoineeveeeiwvtoooevnisfienninoutvesfvneeisxeoeovoesfeheuriieuotugesvvninnvrusrteonifhszoofnioniefwxtioisneuzuxnfseveovvenewoevitfvnstniewtxwoefeeuoevvoiresewieivsitvixrfienooeuurwvitonretfenvowetohontnixteeufesniinseeufixxfowxxxvvvfvoeoeoertieieeeoeeftfvsoefioieirsfrseotiuexiiisefrotonoenownwufeerwheeonxwsisiienwiootiefnxtiefizuvivovereefonsenovfnofiweewoornevofieoxinnixietfuxreiinfxexevfoenvteosfrstrufvtvrvvievxiiffftoiefvhisofeonihwwftenvoieveeinftoweouefteinfeetnoffrwtiseinrnivexosunfeohotoevnoiooisegvseniivsniozieoueufroeiveoenesfsonnvnfteshnfxnionwuixooeioxiroivheiihoeeeouooixieetvvfsieeuhnegfeteeeofrifofevteeeosvoveuwietusvxtonrteiteehsnofsefetsionnfiioiiiexefiveuixiofnnsisviuxhsfxwteoftwureuninrniwexunsvivvivofeunfesxofonsxwefisxvnfnefsivoxiotsfeefiitnsefviftrtovoenifirvifoshfuxeetgreenoneoeefoxonfhofixfeiietnsstvsseenuoiweouisfftfwiiwoosreresnoneuriiunoffoftivvetiiineftznszsfisveoovinenssfeeesoseehfnfvnvnsoetvxsewerireenonwfnfftoveiesseeniztownietwtoniroosefextreifieososexxefnevivfninexeienhvehrsvnetewefowetoiinfiiuxoetfnnxirxnioesfnvieuifouwnvufiinniviwnfesnonnwwefieoxoewiuoinsreoiffsennxowovxieixiewnovfgisunfvfntrieoossonsietoeitifteovinfnveeeevoieeofeesserefoxrisfeoienitvievtifweiexitunirefurnvwnvotnfoononhxeeisehoovnieieesiwwuetufnnvefeeeoeinevefoioeitivovniriiinxosivfeftoiieofriofouoweuxiofifveeeenizeoxxveeneovwtonifeooiiirinixnifosfvioisfvthevxnnvessuzffntsiwiinftiiwoeexsrrneoxiveonxeoeeonifseesfxtsisoiiooiefoieotntenoswhfsxnssewseuftfeeifevsftvrxnosfweionxeonfoevofixesvsefoovoveenfveiwonofsetnefeenzofossronwftnefeetoetvnitrivsoinrnuwgiinssveiteseoosfnveteinieefnwttefveiewiiuenfusutfiniseiowfiiginietreusvenoewwofvwitfeefrxrtfoivioeninoooivsfetoinxfswtinoviroiixtefoextooriewoiesofesvvvesitixernofixnxteeeiehohtiivteexoosnooeninieuxeefvowenortofwefooieefexfrenisezenswivotsusfffivoneofvwninnirfiesouwrowiiftsvewwuottoenveeiriivevienfvnfnuwxenwtffstevhovitnioiirnonierivorhnfniewnnviiffixtefteenoiiosfeotfnxwrivenoinfnxnnieeffheeeweetvexnrofivxortuftfsnetxwwtfioisirinnniseeiehvofueishtwnoooftooewisesoirnusoixeinioxreseuenrsstrevvxsiwfvsvoenwveisuveeizusxftwvioiiveoerweusfehefouwvunwixieeixfwuovinvintvontvenvrueieoooxnufsxevevxrevnivnievrirnrevxewxforviitieoiiosnwfioisixuixefeersxhfvrrrioeeeoeooveuienoofisoxefrxenviorfneoivifeeostnfeeorswnxouvnevieorxwioehoifiohieftufttrxnexfitruoneheexerwrtnseuenvtesrioeveuivfseoouvevnrttetrofswxuiexnetoefionoinegeooionevrevteivevoewefxreierseevnffrfeworhooiiesxeiguwesnsoosoeeotvevreoznfhoiwxouefrthiiixiiiifiosiunrxfniexstsoeeeiofuforveitsnnxinhsoxevnvxvnxwngxneofvefrroxfvsvfnisniooxefuunisvtnuvexxssieseiiexefxuuiostfoewnnoofonovoufuwovsxovnsihiixvnieosieewistsiovwuooweesefounefruwtoifhvsestennrosruetreeftfionwtenvtfeiesfeovfeeiiivtifsufirfnwevgtreeuiixievxnonfninvoiiutteioesrtvuovvrvfsowrineoteiiisuizvtisitoivosenieeiiieoittreoowfsoeffnenxosowvrnvswnnensfexeuwwwutwuefhffxienviontiwfffneioeonsrenxixeihouisiifsowoneexrewvsfgfswfssfotinsxneienfeeinerweoetesiosofeeonoswuitfvneeisetitofiohgninvwinuhrieownveiufetxvensifvftenrieoxorfnsfoexnoesenxnotfeovxorioeouvviexnsvvvsnfiooeuoeiineosuiohxiixgteivifwihofriooeonneoeuioxftonvsrwnixftsvviinfroeirfiexeiowfineseneiowwtexoeoxsnieufneuiteifxifxieorwesznnwnfeoueiiuvexotexrnosvxinrruveeivfnieniexsnnfiexeeeresorvveoonwwissiuruxeishxveiwtonxfeivnnviffeixifowtositwwxrfieiisitewsoesoeinioihxewfiovffxsevvowifftoeieeneinttneixiioteiixeeiofiottoofeoxferneettnftesrnuievfouoruntiiernoheosroxtonfwhrhitinoowonfiresounoirwiwixttfssxwieoerertfiswsfnenvnewofeeotnuuirntvutesxtixfuonexivfrxfrutfthoiiiovunfeonsiinxieiooioeuwuoeznixvnffgeresueiereiweofusttttnxnrvnenfxzieosftoiuwesoxonnnoixsixivxvixferststiefiztitoiefsxnnetuxnnunfoeooioiooiewrtwtionntisoretrovniseonvivrofnutioewriieiefnwrsretuevogfeuiffworiioointtnsinewehfsuoesneonituinvetofineifienteivtiwereosffontstxesfitxwieirotsxrriihuiexuvuffnrovhnthsfotwxhiniiornueoritntfvexsonfusfetnuofeirfewnovwfifwsorioossezftwvfuteuieivxnenffeitreeetnvfetfrrnvoeervnvsefeofroooenovorvfoiinuinrxoeeeoisixevwxtzisewiesoeiiiuisoenexitsriosizwsiwseroiiixunfreontxeixineeffnrtiiioeonsoswuiioerruwxinevewxiiienfnifnvrxnvnnnsnvexeuoneoniunvtenxtorfeewsvnevxvoesiosuvtonvisweuotioeooeonnfvoforontnooxnxrfiuihisufnitsnffxteeeoenwwinwxettiioirevuveitfvovovnueeifxffwfieoeiisovenoieioonfinesoooeiiournfvooveethnnenvsienovvunseeitiffxsirfeonttwofeeinfnevriuvtneenneeriirhxwfnoeewvosrvssnvntiossxtvevwniwfoxsoiuefiuwieeiiirioteewegovineorvtnoinnuffrvtnntensxofvvruivrifftfieintruooioevsivrwiesoxisnrsrgosfxoenosxirnoierowiivfexxeeiseiierfiefnoefiineiveitfxwxiewvtwwueneinssvinstnvfniwxnivooeeeinvvniegvsvsioxineeeofeeneennvhitxeetioseezgnsuutoiveeitenstsnirreseroevenwissfinnnzirierrevuwerfefiiovfnniiioirirninfrnfnefnnvftvuerveooftoxniiifoieiviufrfnoxwxnornfhxeeiexenineifnnvtftsweeiuioosoioofeveexixonuifuinrowioeixeitrxxnswioeonissefnxeueinexnvesioitonevieirzvorexoeooxeisiioiieofvnxwiinexfieiifsneoifituefrixwnxoefvuiifeeffsiirfuntiiegieoisiufiwiexnnoifxfroeffoforvooivvtoeieesxttnuiwffeeexueiesotifiefvofniiueoixrnitsnefosvroxieenerowsevnwvswiexnisxnseouxtrsntrrooeeofriofofwivnseivrhvteiiooexetusrvnvtffentieenfnvxtnfofifwueffnfteeheoeiweiefuniehnneituevieiiiereowifvonuohvvrtsofeeovifoiixsefuwsesierfiensohewsfefsvinvifxfeietiwofinnoxssfofeihnifivtfniewiensenrvoreefovxeeioofewifniieovwrernontrrfrtsiotoixnvifivnrousouwsiiueitsfeihnfwrxrntsttviwxunwoexuufuoerofeerfnheenvneiitfverefiirseeostehteswufesfuetexivfeevfofieesfeineevfvnosehfoiovwnsirnerevieouxfuuniefnfhuowontninnowoernffxistrisrioeueiofevursxeewotosxfertxseoinsnnefithnenxrotevtieonnxeoissitieuoeniteefnnxenxnesnsfevefffxniteertitnoreenfzexfsxxfsivenxoeevswntxeiwvfoiheetneuohnsnoerefwexewoieneeooviiinhrfwxvoeixiinnitfowifrieetvivxtxsvfftovneooexoheeosnwroorowiisuuensrsiesnrviwiirevifeffeirnrfnniwtxioonoetfsvwuswewseiushneseionnisrvxrixtnrfuettfeitutheetfexnereiforestournefweseiuwtinfwsrotiofiennunseuuiteuuhfxosnwrwvewwserfnriifieoswihstsefvvnexnwieueesewsuooniixuootirsvusxwfeunoinxexesnnnfvvizrrwiffteoenfevetxnsegffienexsotenextiefuxienxtfsoioeuoxeehifixteftnioeintnrieeortivwfitxtieenefetxntioixegsinrosxxrnnoofeovooihterfonvusiissnuseentoeozosffueixwnhrfewiioinnorovennvhxvxsrvswntosinrfiierieneriitonxivtsevesnoroviwxitnfeniivefesietovsxuiwnnuwsfosiiufuifiiefoeetveofxnvioefrsvnnfeeeososnvxnentxrvxoithunrnrsfwtoeveeeoeexoiueiftiveifofsrriesneovntsviueztettxinoiohiinfuiewefeeeufvvweiinfeseveeiifuhhoeivisevuueoeifinhrfxerxitxfnnssuvrvfentesteuswesnsffeoinevniirtseonisvivowtfivxifiotifiiexuwirsfnvtnrfeeiiwotnuixosovoniovnvzvttseuesvvnseirsewffrofxfeetsotvwoefneinsosoifiixeniowtrnnxeewfefvefoohxewfeuxxnsveewievozseoofhtonfnniiutvzxsxnroeofexovewxxfsetenxresoivsfiexfigfevoexifeneotsrfsefovsneusiewronwivuwveeionsrroffroerfzweetthniefuoetivhinnexieinewnfoovnirhweoetntitfxooneouvrifneteeniestfntfooxveotinresusoffiiivsisffvefnefnnffwiiriiixrensifxvuiiievewinwxvexosrrnoeoitterniseeuteftnniezeneewviosefnevionsnnfosirenxeneeniverioefxoerwosvowvonseteoenxinftsensetvisnongoennfutixeorrtevnxitxnowutnswiftviinwoewtzwnoeetfniiwvioonveevwrewxsenoiiennrfeiteisfezefoivififitxeorunrttiinxsniotinotretsegeoniiieeotouroiotovwfiirxiiwieoexrxnivetfinienieotirnwfxeevftnoohstsveoiniionsosireiethrexoeuhhvofeeexeoizvtvsfvvvnsvtovevooiierhoniwoiiougexwrneowshriixinoofvnunientoiixsfiioestoiintoixioruesrwuonenineieefnnuiveoixixesetofexhoeiuenteezoeerinsiiniosusfvftvxoevewitfinfvwtnreixoftnnnososiovionfhveoxeueoonxoxiioitnfoorntnennnefffsesnnovuffrxvunreexewretuenxwonisofnfxxwvtrnerwriitvnefexfteennixvientxunfonoottoetsenwofefvitwnefiweotvsoohxwseiiftwotftinxsnniefenfixeieoveeooonoofeioenevesoifiieoirrorxoxteneionvtntiersoixftnxvsihoxuosowrevoteeniigwsinrisvostniniiureoniuxoezfexvnosniuxttwitroeeuseexosoiofvunottxfforsnotreesewoersnireoivsrusvsixnrvoferrxiuretevenevixooetheiotwiustxwneeitxoivereeeoofevhnoinetneeenxfnwfiofxniwnieoeseixotrveiexorfsxwwivxnooovfrstoiehsonfvsrioififttfeehxuoeveieogntoieerseeffieiixxxoieotreioirxfseisxxvregneossostiooxuousteetoxfwoxiofngtniivnrnentnxfsonnseuivisevsevooiieerxivovxeixoeotuonifwtisewtsooeetuxoennsewxsifxttviietxovxoxxnwsoeteiieefevtnoiteihswsihoxoiofwveooiwoosowrninfntenrnisvieiiseniwxvuxixewroeeoniufeuvnuetwosfeseeeristovssiroeftrxirwwrfwneoffeieeeoeneornseniveoineernfswfttntiinntowtnowxtttetenonoeexsneineeneivnvtxisiwefefnehonoosrunsxssvsonnxtneteeseuxeoixrnsrwfnowsfioiiissioweesfonsroinxoseriuoninfnwuwuxtoixsfnnfevrreoitfoefnnrswiixfeofswwivzrniixfoutveoesennewvenefnvfexitfosvtefsvwvnstvverifnorioehvtevooroiiexeruwfsrxewunxiwxwnithfnvtotefoieiewiwisvfwtoxoiniivsenxnssoteeenfnxrteievseevoeueonnuteesfwvrnfeiuuwoirrvnnvovoenownfotoeooeewrwueseeroosveoeefsfnnixvieivrrnnfnnfeutenewxofnensoonvofxxfeinireinverooevsoeiirrosoevuenotrvitoserstivsfvoixvvfitenieftfteinoienesuvhnxvtotwoeorffeneoinoxtiwioitoxneneeontwxvsvnetrveoesieethixfeiossohiixoonsoirxtiesrwzwnesneotritwonsuneofiiofxiiueeoiinirvfuutrhtreiieeeevfeeswrvovovuiwioeefnwffooefoeiesiiiiinneveoxxoxxonttfxfeionnesgiinnwfniiefwntswteonwiiwterioosnenrinernvfheveirfsvnerwfesnwfvseifxevnrieveesetvhsisrnxfeistewxstfooniwruxsoifnhoirinsrneersirgfneoirithvieeftuunevvroerueustnfuewethonxtivuvitvfwneisttioxioinetivstfforwfinerxioieexrixtrneneeeeieviiineisevexewrhwiittixrnwvoiesseoesweortfvfxitofuwvivninwsnweeevfronotneeozwrwrxoneereneveiiofieffvfriivvweifnuiwefoxgefrfneiiiownsnnerisoxssvreoeotfnfxxirfwreeivioswovnnxxvneeoieoostievixnseooioessvooiuruxfoueroooessioeiiffwrwnfenwhfeihitfennoiiwoigsorrrwwotftxevxwvenxfvroovotssixtwoieuotioisnonrxnsnnvesntofvioesioovretonwitvsvxthovfwevfuwofrxnfexxnitronxwnsnueooxeeoxoeetveotwiooinioxviixefiovreinioivxxsnoeihuefotsrfrtieeetesxisoeneuwennfneieisnweneonhiefniihorfswefrnoseowrveeoieftowsoffvxnxtveervewoesvessesiswiwrntnwifwuuierfoiivetxeetetretnfnnnwrofensxwnwxseseesixeifereeihonffwsowntvihntioeorvovinoieeetsisfftgoofexfnwsivxievofeisiesretvezuiwifxihevtievtonniweixniriseessoooonxvirfitxuoeoeowvoontiuowterxeruofxetisuffroitfieeefxefoovtfxwxioxniifvxounvxeioiifoengixutsstnoixeifeivifxnrvsnftsfioritefosiozowenetexsnowwieonrfvnoxfueownrstnifsievvortoofinereeonneieseiinreetesrfrxxniexvvnnsfxxtwoiefwxniowiursrrttreunsforisernsvffinvexrrftseionixiesnixfoersentiteioiiierneienfssrinirxvwtovtifurneseneonnrsonsvrwrnoievieiowwvootnnfootiouotvtnnfeeefexrnhrninsoriounneoveiteessnutnxhtsovtfusxonovnrsuxrsxviinioonvoinniuussfrtennnonvevtooffrsonxvvrtrwovetesoteonougnuefnnioosfoexrxtorfnxeewteeiiiofvotenxseeezwrwitxhhxefrtfiinofvhiioeftsittwifhxvoeoitntfswwnuoititreeoeveseeriowviifnzexeefwvefssnsxesinonixxxsieerefxenfeeuiuefifwvxoniowenetorsnoxuosoinwiieweineeifesxewieixrhfteoiiszooiexfevioefwxvxetehnuuifextvfoiitntioviorutsowenoitrxnntxwsrvnouseiwifeiteeeennneeoffeoevvtuihtiwnuifniefioorxrfnfexsevntxnnsewosetutnxseseextonvvsiuxieivnoniiihoxxtextssirwowvoxfsvsirhoitrwvxifeoenoesoixenfruivtniweoxivsnfieniorwnesfviiservoeooeeonenehsnirieixofsieeiirfnoeioxfssftfwtiousiofwooeinsfnrvfvteeseievfffvowsesveviixxiretiieoewhvrovowienenvifreowsfvouteeiohsnxnirffnfsxeoeeiestfviiosoiohntwneifhfrfeniefnieeeixioiifrsoswxesofnwsietentoioifneniseuioeswroeiowwexvtwtnstrfgoeigiiwwiierwiexneefiswsxeewiuhvsefvsveoneietsxeiirxsiieuiefeissrieuoonreewtiooiwinrfuvuvsoersssovnvxonwiifvrroeoxuseoovfietxoteenvivtosofiorxxsernsexwnfeefihnseseoifrewfofossirieeivostwiugnoeeoifresntvixooieunfwuxrnxwivntsnfsnefeeorxnusrwexiefovvweneietfxvfeneesoxxeiioeiuutxeetexiuooiifeuieswnfiensewftfotsnuenrfoerszxrufvexxnoexniownotrnoftifnvrivinnnsxiioxosorwihsfninieetrfgefntfeeswfnrxssevseveennfnifgfetefhuitsenfnxsiefsooneivseoeoohesixesnotwwwivixxintfnixonftswwrerweetoxxnixosowuronenivhrsfutenfnuweeenioehneifntseeexreifeeftetwneexixeiesfennonnneoetoionfvnrenxeutiexunvoxwvriifvsoxsuxxnfvuxoiniroinesuioirusfurvstesrioewseixneowoineeveinevivtoeinsevtiwwswioriosfviveifrxoriisvioofosnornivfvonftnixfefvfwofnofevnfevvhnsieowiseonxrrsnxrifesioixxsuveotieixenffreoivxgofofnooroiisoteuuevefvisisfonoovtsefxneezsivvfrheeiteisuieivfnixfneounvfixfnervenfntesnsteototieeoiotvnvervxerrwewowsisxisrsuieuexxoeexoistiwirvwtfefnresfiifteoefviseussivexixteoewivouefoeuxfoexeotfiiiuevvewziexneefnonifveoihworexeunietnvvxnosoeoonrieovevoinoisvwionfrnvtfifeeooeiietintsosswenoeeetnvxuxfzrufeeinwwevwoiuusuueiviswfeznrsereuowsuwsirnznsvxfoeueruioeofeeeowsvetounixsvvvewiouxueeewevennxftwvfivniwufsxuoenewifeoeeewxtfxeoswvtisveovsivurwexfxeeotfxnwxtsvvsftesroeeiowfitoinunfnvwnwnswsiefivxttrveseivoxiinuntefenuewitfftxnrwsixsoheinxeenvetoownxeefneenwsoeoxoofoweohfrtexnsnviigiienefvxnveioiitttooviiooohsiiiwtsieinowretixniieorfofoeenrufhzxisisvonsnxeexxrwnxreresensitfeiohxihwesnuouwevtntioteofexxixorviioooxxtxoiwosuinvesisnethfneniwtxfiiuxihroiwvteentuoxoeseeesfweevixivvoeivetnswxishooioinexevxrreirerfntvfioresowursznoeneoeesihsvensenonswuvsfnsionovvrwfsffneeeixnofiuxtrxvnninhnstiownnefnnheiweieioixiiseeefsvvxeoonuofrniswxzuneeffteewhwofuesrrttseeoeonnoeesxirnfefigeveefiififvnuoinssfervxrrenesewniienoexfsiiiivvnineisinuwwsinsiveeewhisuxnineuufxrorntxtnxwewneexeewioeetoosieirxoinexieiefevofnstoonfstftfiseinexsneiesinetveftefeefneoeoxsfvxuironuvtevnesfvtwvrfvnfsooeeosfeeiotteoserfvwfivseinuoietofvhnxhsifonioowoowvosiffoseooefeeotewuortioionrrrussvvosxieiteniifroenuvotuonnseertnsfoxnweffsongswoxreievtxfrnhrtsssnoievfzwnnwiixrerfixrtioesneweeioooeevvenveuooigtwroxioontriwsewuewroeniorstneftrvoeeeseiirnxuvivxnfewxnnnsfnfuneeoevveiffnswviiwwieinnteoxvierefeioxnwonnxotrxenetxertsnfonntwtfwxxessreiesxoeixihxihnsnnxieuioifvnvirnsrusnnnivennihixtiinfeiiinonvgsiseiuieoesvreffwunutionsernstrfrvweivovtzritieoserevoonowfiieieviriivviinneouxfvnuvvrzoiieovnfwizeefwxnfwoewsnoweesftefhtheioiinnreeesxosxreexeevexieefeseifoifgooeensnfiifwwvteeeoonnexwrvioxossfwhzinixsoieevnnuvertrriiwvriwnuntftvnssesuntneifeeefewseexoierwsesnixxofitrhewxiiieizeiieiiissosnnxoeoewneviffwnoeoesontvnfgifiiiiwewiieiifevrvtrzifnovfennifiiinwfsefnssonvweooiweeoufwxeifisiieewevifovtwofvseirnonovrfninennvuuiofifsusnnnoivonrwesueeoirueiofuwrvvnovtiuxtnevtnoivfwivnsistsouffiouvtvnenuowvvsthrfniiwisxriinnefuresosisenfnsoreefuinixotioienoiwntovrewfiisonenetosovrfvotwenvsefowrvounvxihwnefunienrowenueeesieoeffsntvexnsnssoeniieevennxtunovevnevexenieifiinotsifofvissufewxotreeisnivxnfsveveefnosnhwefxxwniieiuevxutneiwtowniieoeieifwevtetssenovfnvtoiriseonooxtininwffewoifehwvitnwefwieonvefetveeetftesszefxioerftusrwxeefsverooisiwswsrinnsrunrrsetsvewrevoiesgoxreioieowveovoteiriefwnesoiiuinoneooeswsosiieuwtooeisueofefeeneuxovntxrnrxwworweoesffoeneoiossroefinoreritseeeixwisfisetrnwtfvrifesieereoinwxrifsostfveerxivrosofeiftfieisonvnnvwuieeiieixxsoieentsfnootuwvronsuooenrornxenunfntetnssftieeniineuvixifeeooihfvsfeeoinwereetinsoufsenefiisfrsfeneewtxeotnntooofexhixswenfevftvonixiifufintniviievfeoowveotvtexronrtesegtwuvsneennifxineohxwrionvtionoeinewnxrviseetegsoetexnunweienevveiexnoofietoofxvoirirothrfiennorienoneffoefsfveewwsfiweoetfeorooriieviwnotfutnnrsertrviwooefeoworefeureoenvwxrnneuntvevinoeereeoenrvnheexsnttrsnniveerenvueuovosxxuooefnesfrextenieonrsxeetowehnonsiieeietrenhfxeeresveiringefttowuxifovseooewiiuostixvsewrnevvogoiufirssfwnfisonroeewsvvoonexwvfowintetvnsrietxrexrvfwnxwfnwneieennrreffenureefitoeffrotxoxoenoteeenviootffoxrevifeoeiivtrrtvwiofsovssnonuosiiirstxtewfieotovsioetntinoovnitvfsoeeswvotnisinitoeietefvtxfofixsgefevwotixvoeswfvnferevfooioffseeoiifnefvwguioevofxxuovfvsuenotviuvxseeshfoxroixifvoweoesoxesiwtefvneueoeeiievwnvoitnrvtifeeifoeninvertxteriieeoxinuouhuiesvinihisfrnfoxxfwintrevnenfeeeosonffnxxentioitrretihiewszowoffeensrooeooisrexnsxeesfxufereirrntiiunfhzrhvxszeenoeniferfssnisnonxreoifsooxeinizfsefeefeioxvnoitiiefsninfifoeoenwueoeuingeeeusvnwruooxwsfoenwitiriitivsefheifoewxetrofswnoexntvvfhsiwtsonoooniwexeenfiiuitveeexwifntnniwvrufeofoioneevgsifoowoifevihoteuuongtfiuewesonvxiweusvuoooeiineehsfxssneisnoootstshfuirtsfierveiivewfniooioeenornufewevofinonifxvfwuveuutwnwtgnoetssoitiwninnwfnseonxehrxefesoiefveswnixtexefxexxxtenieefonhrrsisitfewnfwvwreswetexsusxhswvtnotwwiwvfeoiutiinrnoxxneoiueenwsiireehtvxwsreeeefvteoeievnnxfevforofooiwefvovwofvosxrntevnoeeitieoetniiittoiheieethfffxvrfeonnsrfeossetoxnvfehvnteiiioufixhftssniohnowfnfovnhtftiitureieonfeiesnwvnotuehutefsenntvwvuoffoeeewuitnorienrereeeefsvsextsonifgxszefiiertefhnroteiisxtoweifeexeoerevesriuxexosowiefffenoiienenoosieeotugunevuenfffsiivftnennsiivxnrxwfsoiestoeuvoieonnxivoeeneeivrveoefxtnoefxtsnrxsnhoiennoveitnoefxffieievieuseeorenhixoievinenertetfrnifrserosueeenwtwhiunhowtfinenssisnwrtefrnnxgxnetieiovwosoiiiirinevwovffwnrniiifivwtvtnesievnortennnffnvwsosorxentiofteehirirsotreoosevoxsvtewinovnenoinnvxwfxfxnoeeiinvefvnoxnznxfonniwoeeuetnerernfootrfeooiievireoseixotriehefonfvrhootioforvfweetfexfrninftntorotfeitixfeeneheiwinnrinretoetiofwinevxehrrxoswvtewroniiuxienevoifunouxefonfotsfioiteuietesfeinfvrsiivetrnxevoveirtfoevunseuufirvsnurteuoweuigreetovtvieonnenifsiooonnefntnnoovssnveennssvvfuntiiefixiixnveiseiseewinnowffneiwvviesittontesevxvtnvoieoentienenserwnniefxitnwevneiwonxeieeroeftoeiovtteriniennsiesnfrnnnxniofnheeeevnsnonnfwxetvnntnehiestfrioiwxnuwexseinfvoeftnvhiersexfisneieziexnexufwxtehenwieiuenowneinfirsxuovoieifrusieswieefofiwfoousiuevtsivvieeseoxtvtstuorfrfexeneneeieooneivieeewefntiviuhtvfeftooxewuwintfxeorosiiwonrefsxnonoiwenrstrnernfenienowteverfseeofwiwrteetweofoxseervwteethsivvnoviweowoieerhionvfoosoeowfiwhrsufooirweeewniuunrwsenrxoeoxfeoevnitiztreufxtuoettvoiefioeheineoeetitnnefntxwvixfiiiunexvniewxoniviftfifxivtenhvsftufninnosuoeeoeoionvennneinerieresostostwoovzwohoftreioeoixoxeininessneeetnntetieoieueiwrruieooowfsixeienefexehfuxxnhisosoeevevioinfoexniooefeinivfnviioneinofoeinsffifvesoooeonovtrterhewiisfvnoteutesetuooueiiufhnoitvotisovsieieovtoiwsieueieeosefouitevoertnotfoxonoetrnxoivhixisweoteonreiooffhivfesfwshueriwonowenseveoxftsivefihoeoofnoewtiorofuveofrnsinewvwtesvnrtsitiuouoeexweoenveiwothoowoeowexiioovvenierfxineiwxwxerenoetenieenenninsfineetnfnnsffvetsiitoffsssneseeeevftxoiiorwforznfestunurinvofevoeefenertovefiiofftreiooevxisuseosroeexsefisrsovftihfnsxttuforenoueosnonterounonfssntouieenesurewfieiovtsnoxteweenienuirfvitnonenwoeortnwiseutxestwiwuseetuefeuetwoevorinefnixsiseenstttovewireeooererotfiveoieinfnvvnevwsnsioxtvsnsterxereftnteeoeesfrxwneerfwtenrxifroeenexfonnsxovouiuroefvtofnneioeeessetntewvtxeifhvonewvnrinheneeeoifxwiffheszsnxonwifsfnfeoxxfeoiiefsfoxsxneeuieteveeeseieswoefzeeeofxownfeneeerxnufxextxwwierfiiifwineterwffifriurvoeofvwtrnronfrsrfieotfsseovsusfioexnsrenfnfsiiiwoeeiefifoxnenixnniefiesuxuvifeuwxuosfieosxfhnwfnfvvfexeinnntixwfohsoeenrheueieeeveotnvzoiwuoroxnoefsfovesiifewxxnsztevienvorovfseineofoofsvfooeriniooivessrxwfonwnveeuvsssiewxorsioveintnetetoiifsteeienooonisvnfrnttwieheinfifssorxnovoetonrroeswiutiosiuerwteitfweeroovfserneenofiionfiioteoievzeviieffoesowiwnoxoetssotteeeuvfneixnuzvetntivfrgeuerfxnxnifeftrntirvenefvsuivivnwiwfrvnoixxtrveefisizorrioeeitohesvuefnsotvtfrooowxfvonrovetosxiroeevoifoxfseevnfnoienetoenrsiineoessireoeroiifousfxerftswiievuiwrneisfinwonigfofwoxoiexionieroooetoiveefrwtovsfisexeonrnneiofuvewnusounnoffofvrieizoosnteswnfnofesifteuivnueisivrfxoofrutnitxwwnftxiuwxsouwfooxowiefruosooxiixvtrvotegntiosrveffhroieitxnetnfsiuifesfionevfsfoirefiviffittrwwevturooixfvinevhrtswneetritvteosttesineueoovoiexotufivutuoooofiuvwhfsviuteehoffofewoviwefooeivexuofvhiieienwfuwsehsriuntienrweoivoxvwouevsoifeeoixsnioeoenunofiexrixuexteereoovvurvvoreorftfneoftisesefowswrtfoorrxhifuivoveetfirseixfvituriwvwrreiioifevtixeionwffeeouisotfvfniwnfowrifftvneitooeevsvwwsoifueioxosutronenesnssiritoifffexfrnitetvrxveeufvtserzviseoneroossxrnuitteonnouinxrtiseettefrxvfxfinfoiieeivwrweenwerswxioefeetioivfwewtswvewvinfteeueofioohueseoootoorhufxownexirnoiiifisffiteofhxsreffeotiftiwieoxxevihusffsosrniviuwuxoexerosoievisiioeoetowtxostfrsfeefussoffwithihxtwrfifioououwensrisewesofroefuseresooxsooxvxtsixtosxgxeofieuoovfiwieoxuoenissieoouuifhuvuvwierrrsfosioieiseoioivioeefefonsfvxiifvweoorotuevofvotroresewffuieunseftvoexereofetneuifsxoviettxoxesxrvriesvvvfnwroioifvrhreffxueunentvueeeoivfoweeeeoosufrefrxextifexxfhsutefifwsievihirvsioiiiotffersetieweeioreiirfviefiriseeifvwottfvsweuneffhvfoewtioteoiooerxswioesivfetxeixvsoetexwxsuoorenrvoiortrefifixsfvoervvtrevnonsoovntoiievfrxsoivesvivisrewshuoetennsxexeoiorvgwoouuefvifstfriirveseriooeevvioxrzvtttieifhrohvtirrsiwvrfrosfwxxxfwsextesiriveiseiirsunwoinefwiwsexirusoowwufoesruxiesuvtssvwoufeneifenfwegoiovtvtooixifreeoonshnxwrhorotofewrnfwvenoxwweheshehetxvvneoittisvsewvsiwnwwuofovvwexiofonnfetrivwrftsowrhotroiuerxeiizsoeswxofehuviotenevthoessuofntoterneiowrtooreeivwezooivtvfuwifinisfttrvxvexunerewioretfrtissoevienuievofssueowniewwvovrfeeoxetvissxouxunwueivhewoorrtixseinofiexneentieeooeifetiiexreftfifeieoooeonfoetiihreninfifhtfesfoosisoirtruwfneesuwixxerxiriofiizgxiteixwrofneunvfvffxtrsreexfxirnhrwhsofnwveiiffrxfferifwiwnnxnsutvxffuevoeeerivtfthiiouieweiheeiioneusfenittvofxezrnehxotenehoewwiifiitenwisenvifxveeinitervifrseooiiveesutifrvewxntvneiifnfeoiootesnwutexihefgwniteohhoorfefixsefoexoioewvnveisviihsweofstrsioennfiwisiffixoeeuoisnfoeenusorfofenxowrrwiniifvuefortnrenfwwereetfrfterueeoetxnesieiwioxefteventrorrvieuovoxtffiretioxursnzovovoxtoefenevrrusesehtifnntvovsftuoviuoihvniiivxtoooneoeuufeixfeefxosowfnuetsinitfvsoonxsfxnxetheiuvifeoxosvniiesvifexsxvotouienvhneseofeoitovnuvfsisforwuifteserifrtxohnnoourhffexfoeotvtfsohofooeoxwrwstteinxursftsioesinnrsfrnitfiwieiosefsiooorxnevioieiisoeeuoeoinfuvtfefxwonttnvixorxtoveifenwsnnooovsiefwfieoeeeeneweexohiuefsvtxenrereestiofsofsofnettorzroxsiffewofseoeoxoiitostonvfvsxtverisovtvewwrsetehetwfeiuffniirirteeifrxerrvsgnteosettieiuoeveuwosvftsnwririueeoeeznnoovinwitetnvtvfuwsifieveionfoixrnhefrfefvevotohveievntxxeeuohfsvstterefuefxtoeoruoxxeeioosoevfifnfinosvivoteriivfosuehxtrnoteeiifosovfoentnnstrtsiievoiixooiinfosuvsfoonvxtvuoozouefeieetxhrnxixoxiereoenitefiehetenowviooihfxeeewivioofinftxtowoorneffeeonofoxeeihvniewxuiivrsinvrihftiiiihvotnwfeoonfweeinoriotofiwuxsuiinsieewhwnefeehwisrieenvieeriteiiiroesfeferofvwovfixowfwefevovrfvxeeeootnfrioreititrfvohoitoreiovotvfnnvnseusfxeoeinrotueooeuvxfoeofosxstetxsftonrvtesftfsovexotxronvieifeeueewiervuoeonuesxefienowoonfvntoufvewvietiiioorsnrhnfevefoowoixeefesexsttenwieuttnxoouootfiweofeoooxneutfiveonshxovwioetoisnxftohrusoeouhtfnevhxsfifuesfnihoofwexsovnerweoiezwxeueixiwvfwoeorffeefxrvexenrirviuueiruxovoeneioxuuiiuotttfvtxvsnevsisxftwestffnnsxonofnoifitoeiwintieisevsesgieorxonooxvhofusfuoteofonhvevovsenienoeerfoisffiiuinoeehnenoxtwnxwevwtufteusftvnsntxooesiweostvoerxitoxsnesefunioivnsesvzfofrgsirerefowfnsvvsferiveiofrofwssvneowoehoofiriouefovesvfeuonrwnineseuhfirvtetnivnefxeevwiofrhtenzeivoneinntwxevituostfeiowsweniivitnntooenerssoeriuoeitftfwevxruusuvowurexosvutowrffxoeneswoeifeoiioevehotuwuewnnwwintiuntfontovifffwfofivvenevhrrenfixeieweusevrfzohuovrtisooeexioonorioorvtfnnfteseirtuefestsweouxtxvvnrefwoitiefooveihsnweswnxniewffeexnrnvhsxeenhtizeiitzvivifeefoxwosifwfxeiixwosunttesvvrxrwesxioeeeexferohetoixtvtosereitfnerrwshuonhwoieeiofeeiioieefrfeixhexevnfosestfnnxvnsresowvwnunennietiiwototeunrissouoveitotnewroofeotfoonewfewxifvuefnrnnvseosffexfisetttuvrweovuzittiivtowvoiiofvoeevefxoisnwxneoooiiweeetwfvituofxvttfteweeifnreiisooreitotniwenonetffenvhzteviioinnoioixewnieefuwtfvnireefrfxennooesvuuwnesisvxfxfeoneonfoewoosneoooiiefuxnezxfvvffsteierovoneiunewrfeeiouuwtwooifiernetsooefxifoxeinzrieuieeunrienvnnroeioxvxweonxsennsxeuhzerwseewnoefsinnuxvovswevieuffsexieeewoifoennssioooufniixesensxnftegetnuiieeivfteoervxiinxeinfetsnnetixnewifnvieinnotroerwfessuooiewfrtooxofetivrnsohosoeseweseffnrxsneeintrfneoieioeixwneervvxxitewufiieeniieftsffisefooitxeteeenurvieefhieorneivvheunewevfxuoonfseffofrfnnfxwxsueffnirsiftirnfiwonoonoieonzeivheivfsxuoeerrtoiooeeszvweitnevstrxfeurtsrooevfiseonhnetnnxoinfeeixtvtrfrziieeenineevenftwirnixwuenwenteiiieufoffounfesfehuxiveinoifiofwfeiiexnfixivnetoixrieiueeeofoowteenrtoxunoenffisnefivvnosfvwewwexvoveovitrvnxoofnireovvfeeihierexntihinresexwnontteexrveeefeoneissswwfnsooisxevwfiivosonuusuowenusoennowiersorirrefufixueewofoeerioevnoinvietfnifxvsssnntoxeeeteniiiiehoefixnereiioefeoufifieesioseveviinwriiosoiuivesrnrwwsxoeiiiotnxnevsxrusoeeefiorihsoewxoifeuietexsweixfifowsefeifofowtfnevnfhvfotwsnevwifon";
		originalDigits(s);
}

/*
365. 水壶问题

有两个容量分别为 x升 和 y升 的水壶以及无限多的水。请判断能否通过使用这两个水壶，从而可以得到恰好 z升 的水？

如果可以，最后请用以上水壶中的一或两个来盛放取得的 z升 水。

你允许：
装满任意一个水壶
清空任意一个水壶
从一个水壶向另外一个水壶倒水，直到装满或者倒空

示例 1: (From the famous "Die Hard" example)
输入: x = 3, y = 5, z = 4
输出: True

示例 2:
输入: x = 2, y = 6, z = 5
输出: False
*/
bool canMeasureWater(int x, int y, int z) {


}


void swap(int *a, int *b)
{
	int m;
	m = *a;
	*a = *b;
	*b = m;
}
void perm(int list[], int k, int m, int *n)
{
	int i;
	if (k == m)
	{
		/*
		for (i = 0; i <= m; i++)
			printf("%d ", list[i]);
		printf("\n");*/
		(*n)++;
	}
	else
	{
		for (i = k; i <= m; i++)
		{
			swap(&list[k], &list[i]);
			perm(list, k + 1, m, n);
			swap(&list[k], &list[i]);
		}
	}
}
void softall(void)
{
	int list[] = { 1,2,3,4,5,6,7,8,9 };
	int n = 0;
	perm(list, 0, 9, &n);
	printf("total:%d\n", n);
	system("pause");
	return 0;
}

/*
908. 最小差值 I

给定一个整数数组 A，对于每个整数 A[i]，我们可以选择任意 x 满足 -K <= x <= K，并将 x 加到 A[i] 中。
在此过程之后，我们得到一些数组 B。
返回 B 的最大值和 B 的最小值之间可能存在的最小差值。

示例 1：
输入：A = [1], K = 0
输出：0
解释：B = [1]

示例 2：
输入：A = [0,10], K = 2
输出：6
解释：B = [2,8]

示例 3：
输入：A = [1,3,6], K = 3
输出：0
解释：B = [3,3,3] 或 B = [4,4,4]

提示：
1 <= A.length <= 10000
0 <= A[i] <= 10000
0 <= K <= 10000
*/
int smallestRangeI(int* A, int ASize, int K) {

	int i = 0;
	printf("K = %d \n", K);
	for (i = 0; i < ASize; i++)
	{

	}

	int a = A[ASize - 1] - A[0];
	if (a < 2 * K)
	{
		return 0;
	}
	else
	{
		return a - 2 * K;
	}
}

/*
754. 到达终点数字

在一根无限长的数轴上，你站在0的位置。终点在target的位置。
每次你可以选择向左或向右移动。第 n 次移动（从 1 开始），可以走 n 步。
返回到达终点需要的最小移动次数。

示例 1:
输入: target = 3
输出: 2
解释:
第一次移动，从 0 到 1 。
第二次移动，从 1 到 3 。

示例 2:
输入: target = 2
输出: 3
解释:
第一次移动，从 0 到 1 。
第二次移动，从 1 到 -1 。
第三次移动，从 -1 到 2 。

注意:
target是在[-10^9, 10^9]范围中的非零整数。
*/
int reachNumber(int target) {

	int i = 0;
	int temp = 0;
	int step = 0;
	if (target < 0) target = -target;

	for (i = 1; i <= target; i++)
	{
		temp = i *(i + 1) / 2;
		if (temp > target)
			break;
		else if(temp == target)
			return i;
	}
	printf("i = %d \n", i);
	if ((temp - target) % 2 == 0)
	{
		step = i;
	}
	else
	{
		if (i % 2 == 0)
			step = i + 1;
		else
			step = i + 2;
	}
	return step;
}

void ID754()
{
	printf("n = %d \n", reachNumber(1));
}

/*
592. 分数加减运算

给定一个表示分数加减运算表达式的字符串，你需要返回一个字符串形式的计算结果。 这个结果应该是不可约分的分数，即最简分数。 如果最终结果是一个整数，例如 2，你需要将它转换成分数形式，其分母为 1。所以在上述例子中, 2 应该被转换为 2/1。

示例 1:
输入:"-1/2+1/2"
输出: "0/1"

示例 2:
输入:"-1/2+1/2+1/3"
输出: "1/3"

示例 3:
输入:"1/3-1/2"
输出: "-1/6"

示例 4:
输入:"5/3+1/3"
输出: "2/1"

说明:
输入和输出字符串只包含 '0' 到 '9' 的数字，以及 '/', '+' 和 '-'。
输入和输出分数格式均为 ±分子/分母。如果输入的第一个分数或者输出的分数是正数，则 '+' 会被省略掉。
输入只包含合法的最简分数，每个分数的分子与分母的范围是  [1,10]。 如果分母是1，意味着这个分数实际上是一个整数。
输入的分数个数范围是 [1,10]。
最终结果的分子与分母保证是 32 位整数范围内的有效整数。
*/
char* fractionAddition(char* expression) {

	int e_long = strlen(expression);
	int i = 0, j = 0, k = 0;
	int f1 = 0, f2 = 0;
	int ex1[10] = { 0 }, ex2[10] = { 0 };

	for (i = 0; i < e_long; i++)
	{
		char c = expression[i];
		if (c == '-' || c == '+')
			f1 = 1;
		else if (c == '/')
			f2 = 1;
		else if (c >= '0' && c <= '9')
		{
			if (f1) {
				if (expression[i - 1] == '-')
					ex1[k] = -(c - '0');
				else
					ex1[k] = c - '0';
				f1 = 0;
			}
			if (f2) {
					ex2[k] = c - '0';f2 = 0;k++;
			}
		}
	}
	/*
	for (i = 0; i < k; i++)
	{
		printf("%d/%d \n", ex1[i], ex2[i]);
	}
	*/
	int fz = 0, fm = 1;
	for (i = 0; i < k; i++)
	{
		fm = fm * ex2[i];
		int sum = ex1[i];
		for (j = 0; j < k; j++)
		{
			if (i == j) continue;
			sum = sum * ex2[j];
		}
		fz = fz + sum;
		printf("%d  %d  %d\n", sum, fz, fm);
	}
	printf("(%f)\n", (float)fz / (float)fm);

	//for (i = fm; i >0 ; i--)
}

void ID592()
{
	char *expression = "-1/2+1/2+1/3-1/2-5/3+1/3";
	fractionAddition(expression);
}

/*
970. 强整数

给定两个非负整数 x 和 y，如果某一整数等于 x^i + y^j，其中整数 i >= 0 且 j >= 0，那么我们认为该整数是一个强整数。
返回值小于或等于 bound 的所有强整数组成的列表。
你可以按任何顺序返回答案。在你的回答中，每个值最多出现一次。

示例 1：
输入：x = 2, y = 3, bound = 10
输出：[2,3,4,5,7,9,10]
解释：
2 = 2^0 + 3^0
3 = 2^1 + 3^0
4 = 2^0 + 3^1
5 = 2^1 + 3^1
7 = 2^2 + 3^1
9 = 2^3 + 3^0
10 = 2^0 + 3^2

示例 2：
输入：x = 3, y = 5, bound = 15
输出：[2,4,6,8,10,14]

提示：
1 <= x <= 100
1 <= y <= 100
0 <= bound <= 10^6

* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
int* powerfulIntegers(int x, int y, int bound, int* returnSize) {

	int xx[100] = { 1 }, yy[100] = { 1 }, rreturn[1000] = { 0 };
	int i = 0, j = 0, k = 0, n = 1, m = 1;
	int t = 1;
	for (i = 0; i < bound; i++)
	{
		t = t * x;
		xx[n++] = t;
		if (t > bound) break;
	}
	t = 1;
	for (j = 0; j < bound; j++)
	{
		t = t * y;
		yy[m++] = t;
		if (t > bound) break;
	}
	n--; m--;
	//printf("i = %d, j = %d \n", i, j);
	printf("n = %d, m = %d \n", n, m);
	//n = i; m = j;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			//printf("xx[%d] = %d, yy[%d] = %d \n", i, xx[i], j, yy[j]);
			if (xx[i] + yy[j] <= bound)
			{
				printf("xx[%d] = %d, yy[%d] = %d, total = %d \n", i, xx[i], j, yy[j], xx[i] + yy[j]);
				rreturn[k++] = xx[i] + yy[j];
			}
		}
	}

	for (i = 0; i < k; i++)
	{
		printf("%d ", rreturn[i]);
	}
}

void ID970()
{
	int x = 2, y = 5;
	int bound = 100000;
	powerfulIntegers(x, y, bound, NULL);
}


int removeDuplicates(int* nums, int numsSize) {

	int i = 0, j = 0, k = 0;
	for (i = 0; i < numsSize-1; i++)
	{
		if (nums[i] == nums[i + 1])
		{
			nums[i] = -INT_MAX;
		}
	}

	//for (i = 0; i < numsSize; i++) printf("[%d] = %d \n", i, nums[i]);

	for (i = 0; i < numsSize; i++)
	{
		if (nums[i] == -INT_MAX)
		{
			j++;
		}
		if ((j > 0 || i == numsSize-1) && nums[i] != -INT_MAX)
		{
			nums[k++] = nums[i];
			j = 0;
		}
		else
		{
			if (nums[i] != -INT_MAX)
				nums[k++] = nums[i];
		}
	}

	for (i = 0; i < k; i++) printf("[%d] = %d \n", i, nums[i]);
}

//官方解法：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/solution/
void ID26()
{
	int nums[] =
		//{1,1,2};
		//{ 1,2,3,44,44 };
		//{ 0,0,1,1,1,2,2,3,3,4 };
		//{ 0, 0, 1, 1, 1, 2, 2, 3, 3, 4,4,5,5,5,5,6,7,7 };
	{ -1,0,0,0,0,3,3 };
	int numsSize = sizeof(nums) / sizeof(nums[0]);

	removeDuplicates(nums, numsSize);

	//测试
	char str[32] = "hello"; char *pstr = str;
	printf("%d %d\n", sizeof(pstr), sizeof(str));//一个是指针大小，一个是数组大小
}

/*
1002. 查找常用字符

给定仅有小写字母组成的字符串数组 A，返回列表中的每个字符串中都显示的全部字符（包括重复字符）组成的列表。
例如，如果一个字符在每个字符串中出现 3 次，但不是 4 次，则需要在最终答案中包含该字符 3 次。

示例 1：
输入：["bella","label","roller"]
输出：["e","l","l"]

示例 2：
输入：["cool","lock","cook"]
输出：["c","o"]

提示：
1 <= A.length <= 100
1 <= A[i].length <= 100
A[i][j] 是小写字母
*/

/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
char** commonChars(char** A, int ASize, int* returnSize) {

	char once[26] = { 0 }, all[26] = { 0 };

}

void ID1002()
{

}

/*
553. 最优除法

给定一组正整数，相邻的整数之间将会进行浮点除法操作。例如， [2,3,4] -> 2 / 3 / 4 。
但是，你可以在任意位置添加任意数目的括号，来改变算数的优先级。
你需要找出怎么添加括号，才能得到最大的结果，并且返回相应的字符串格式的表达式。你的表达式不应该含有冗余的括号。

示例：
输入: [1000,100,10,2]
输出: "1000/(100/10/2)"
解释:
1000/(100/10/2) = 1000/((100/10)/2) = 200
但是，以下加粗的括号 "1000/((100/10)/2)" 是冗余的，
因为他们并不影响操作的优先级，所以你需要返回 "1000/(100/10/2)"。

其他用例:
1000/(100/10)/2 = 50
1000/(100/(10/2)) = 50
1000/100/10/2 = 0.5
1000/100/(10/2) = 2

说明:
输入数组的长度在 [1, 10] 之间。
数组中每个元素的大小都在 [2, 1000] 之间。
每个测试用例只有一个最优除法解。
*/

char* optimalDivision(int* nums, int numsSize) {
	//解法：第一个数为分子，第二个之后累除即可
}

/*
976. 三角形的最大周长

给定由一些正数（代表长度）组成的数组 A，返回由其中三个长度组成的、面积不为零的三角形的最大周长。
如果不能形成任何面积不为零的三角形，返回 0。

示例 1：
输入：[2,1,2]
输出：5

示例 2：
输入：[1,2,1]
输出：0

示例 3：
输入：[3,2,3,4]
输出：10

示例 4：
输入：[3,6,2,3]
输出：8

提示：
3 <= A.length <= 10000
1 <= A[i] <= 10^6
*/
//超时算法。正确做法是，先排好序，从最大的部分开始判断
int largestPerimeter(int* A, int ASize) {

	int i = 0, j = 0, k = 0;
	int max = 0;
	int ii = 0, jj = 0, kk = 0;

	for (i = 0; i < ASize; i++)
	{
		for (j = i + 1; j < ASize; j++)
		{
			for (k = j + 1; k < ASize; k++)
			{
				printf("%d %d %d\n", A[i], A[j], A[k]);
				if ((A[i] + A[j] > A[k]) && (A[i] + A[k] > A[j]) && (A[k] + A[j] > A[i]))
				{
					int t = A[i] + A[j] + A[k];
					if (t > max)
					{
						max = t;
						ii = i; jj = j; kk = k;
					}
				}
			}
		}
	}
	printf("[%d,%d,%d] max = %d\n", A[ii],A[jj],A[kk],max);

	return max;
}

void ID976()
{
	int A[] = 
	//{ 3,6,2,3 };
	{ 16,5,41,11,48,3,27,7,50,26,24,1,9,19,11,47,11,36,18,50,48,2,151,43,74,24,20,33,9,11,34,41,4,5,44,7,34,27,34,48,26,10,21,6,17,44,33,23,12,15,43,11,16,50,2,17,42,46,42,1,10,30,39,22,48,12,13,27,5,23,8,31,26,15,27,4,12,27,38,4,50,30,16,16,48,44,25,18,30,45,50,20,27,34,41,20,24,13,44,32,4}
	;
	int ASize = sizeof(A) / sizeof(A[0]);

	largestPerimeter(A, ASize);
}

/*
3. 无重复字符的最长子串

给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:
输入: "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

示例 2:
输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

示例 3:
输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
*/

int lengthOfLongestSubstring(char* s) {

	int s_long = strlen(s);
	if (s_long < 1) return 0;
	int i = 0, j = 0;
	int ii = 0, jj = 0; 
	int max = 0;

	for (i = 0; i < s_long; i++)
	{
		int com[128] = { 0 }, k = 0, num = 0;//为了处理空字符情况
		for (j = i; j < s_long; j++)
		{
			num = s[j];// -'a'; //为了处理空字符情况
			com[num]++;
			k++;
			if (com[num] > 1) {
				k--; break;
			}
		}
		if (k > max)
		{
			printf("k = %d\n", k);
			max = k;
			ii = i;jj = j;
		}
	}

	printf("i = %d, j = %d, max = %d\n", ii, jj, max);

	for (int f = ii; f < jj; f++)
		printf("%c", s[f]);
}

void ID3()
{
	char *s =
		//"abcabcbb";
		//"pwwkew";
		//"bbbbb";
		//"  ";
		"alqebriavxoo";
	lengthOfLongestSubstring(s);
}

/*
991. 坏了的计算器

在显示着数字的坏计算器上，我们可以执行以下两种操作：

双倍（Double）：将显示屏上的数字乘 2；
递减（Decrement）：将显示屏上的数字减 1 。

最初，计算器显示数字 X。

返回显示数字 Y 所需的最小操作数。
*/
int brokenCalc(int X, int Y) {

}

void ID991()
{

}

int main(void)
{
	//printf("%s\n", decodeString("a"));

	//addStrings("12345", "45");
	//printf("%s\n", addStrings("11","99"));
	//printf("%s\n", multiply( "999", "999"));

	//ID836();
	//ID853();
	//ID855();
	//ID67();
	//ID860();
	//ID854();
	//ID844();
	//ID434();
	//ID557();
	//ID541();
	//ID8();
	//lengthOfLastWord("hello world ");
	//firstUniqChar("leetcode"); //"loveleetcode");
	//frequencySort("cccaaa");
	//isPowerOfFour(16777216);
	//printf("%c\n",findTheDifference("abcdw", "abcdhw"));
	//singleNumber("a",1);
	//majorityElement("a", 1);
	//reverseBits(43261596);
	//hammingWeight(128);
	//ID888();
	//ID20();
	//printf("%d\n", findNthDigit(2147483647));
	//isPerfectSquare(4);
	//ID831();
	//consecutiveNumbersSum(1299105);
	//for(int i = 1;i<100;i++) printf("[%d] %d \n", i, isUgly(i));
	//nthUglyNumber(102);
	//kthPrimeNumber(1100);
	//ID840();
	//ID856();
	//ID1();
	//ID767();
	//ID459();
	//ID866();
	//ID859();
	//ID441();
	//ID35();
	//ID172();
	//ID258();
	//ID326();
	//ID231();
	//ID413();
	//ID7();
	//ID201();
	//ID371();
	//ID383();
	//isPalindrome(2069009602);
	//ID1000();
	//ID121();
	//ID917();
	//ID13();
	//ID788();
	//ID930();
	//ID925();
	//ID881();
	//ID28();
	//ID227();
	//ID345();
	//ID657();
	//ID5();
	//ID397();
	//ID414();
	//ID693();
	//ID268();
	//ID125();
	//ID41();
	//ID11();
	//ID3();
	//ID69();
	//ID696();
	//ID949();
	//ID728();
	//ID413();
	//ID168();
	//ID171();
	//ID869();
	//ID878();
	//ID50();
	//ID343();
	//ID423();
	//softall();
	//ID754();
	//ID592();
	//ID970();
	//ID26();
	//ID976();
	ID3();

	return 0;
}
