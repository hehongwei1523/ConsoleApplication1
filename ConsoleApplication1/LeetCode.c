
#include "stdafx.h"
#include <stdlib.h>
#include "string.h"
#include "stdio.h"
//#include "boolean.h"
#include "math.h"

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
	return 0;
}
