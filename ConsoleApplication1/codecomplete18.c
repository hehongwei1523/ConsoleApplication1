#include "stdafx.h"
#include <stdlib.h>
#include "stdafx.h"

#include "stdio.h"
#include "string.h"

/*
�����ȫ2 ��18�� ֱ�ӷ��ʱ�
*/

typedef struct _Person
{
	int Id;
	int Age;
	char Gender;
	char SmokingStatus;
	char MatitalStatus;
	double Rate;
}Person;


#define Recoder 200
Person person[Recoder];

int getId(int num)
{
	return person[num].Id;
}
void addTable(int age, char gender, char smokingstatus, char matitalstatus, double rate)
{
	static id = 0;

	person[id].Id = id;
	person[id].Age = age;
	person[id].Gender = gender;
	person[id].SmokingStatus = smokingstatus;
	person[id].MatitalStatus = matitalstatus;
	person[id].Rate = rate;

	id++;
}

enum Gender
{
	Gender_First = 0,
	Gender_Male = 0,
	Gender_Female = 1,
	Gender_Last = 1
};

enum MaritalStatus
{
	MaritalStatus_First = 0,
	MaritalStatus_Single = 0,
	MaritalStatus_Married = 1,
	MaritalStatus_Last = 1
};

enum SmokingStatus
{
	SmokingStatus_First = 0,
	SmokingStatus_Smoking = 0,
	SmokingStatus_NonSmoking = 1,
	SmokingStatus_Last = 1
};

void Table_Init()
{
	//addTable(18, Gender_Male, MaritalStatus_Single, SmokingStatus_Smoking,1000);
	//addTable(50, Gender_Female, MaritalStatus_Married, SmokingStatus_NonSmoking, 500);

	addTable(18, 0, 0, 0, 1000);
	addTable(50, 1, 1, 1, 500);
	addTable(50, 1, 1, 0, 600);
	addTable(50, 0, 1, 0, 700);
}

double rateTable(int age, char gender, char smokingstatus, char matitalstatus)
{
	double rate = 0;
	int id = 0;

	int i = 0;
	for (i = 0; i < Recoder; i++)
	{
		if (age == person[i].Age)//����ƥ��
		{
			//printf("age = %d, gender = %d, smokingstatus = %d, matitalstatus = %d \n",age, gender, smokingstatus, matitalstatus);

			if ((gender == person[i].Gender) && (smokingstatus == person[i].SmokingStatus) && (matitalstatus == person[i].MatitalStatus))
			{
				return (person[i].Rate);
			}
		}
	}
	return (-1);
}

int Find_MapTable()
{
	Table_Init();

	//printf("��Ҫ�ķ��� %f �� \n",rateTable(18, 0, 0, 0));
	printf("��Ҫ�ķ��� %.1f �� \n", rateTable(50, 1, 1, 1));
	printf("��Ҫ�ķ��� %.1f �� \n", rateTable(50, 0, 1, 0));
	return 0;
}

/*
�����ȫ2  13.3ȫ������
������ʾ��
1��ȫ�ֱ�����Ϊ��������
*/

int global_variable = 3;

void global_in(int g)
{
	g = 100;
	printf("global_variable = %d \n", global_variable);
	global_variable = 6;
}

int global_test(void)
{
	global_in(global_variable);
	printf("global_variable = %d \n", global_variable);
	return 0;
}


/*
�����ȫ2  13.2ָ��
��ʾ��
1���Ӻ���ָ�봫��
*/
void pointer_change_value_1(int *ptr)
{
	ptr = 2;
}
void pointer_change_value_2(int *ptr)
{
	*ptr = 3;
}
void pointer_change_value(void)
{
	int a = 1;
	int *b = &a;

	pointer_change_value_1(b);//bָ���ֵû��
	printf("%d \n", *b);
	pointer_change_value_2(b);//bָ���ֵ���޸�
	printf("%d \n", *b);
}


/*
��ʾ��
1��ö�����Ͷ���
*/
enum _COLOR
{
	RED = 9,
	GREEN,
	YELLOW
}COLOR;

void enum_test(void)
{
	//ö�ٱ�����ֵΪ0�� ö������Ϊ����
	printf("enum = %d,  GREEN = %d,  RED = %d \n", COLOR, GREEN, RED);
}


/*
��ʾ��
1���ṹ�����Ͷ���
*/
struct _EMPOLYEE
{
	int  id;
	char name[10];
	char gender;
	int  salary;
}EMPOLYEE, old_empolyee, new_empolyee;

struct _EMPOLYEE empolyee;

void struct_test(void)
{
	char name[] = "kevin";

	old_empolyee.id = 1;
	memcpy(old_empolyee.name, name, sizeof(name) / sizeof(char));
	old_empolyee.gender = 0;
	old_empolyee.salary = 20;

	new_empolyee = old_empolyee;

	printf("old_empolyee.name = %s \n", old_empolyee.name);
	printf("new_empolyee.name = %s \n", new_empolyee.name);
	printf("new_empolyee.salary = %d \n", new_empolyee.salary);
}


/*
�����ȫ2 12.4�� �ַ����ַ���
��ʾ��
1���ַ����Ķ���
*/
#define CONSTANT (10+1)

void string_test(void)
{
	char PtrString = 'a';//"asdf";
	char name[CONSTANT] = "abcdefghi";

	printf("%c \n", PtrString);
	printf("%s \n", name);

	char my_name[10];
	//strcpy(my_name,name);
	strncpy_s(my_name, sizeof(my_name) / sizeof(char), name, strlen(name));
	printf("%s \n", my_name);
}


/*
7.5 ���ʹ���ӳ������
 ��������-�޸�-�����˳�����в���

�����������IN  OUT�ؼ��֣��׶ˣ�
1����Ҫ��������Ŀ�б���һ��
2��������֮ǰ��IN�ظ�

���빤������
*/
#define IN
#define OUT

void PrintfPageNum(IN int PageNum, OUT int status)
{
	if (PageNum == 1)
		printf("xxx");

	status = 1;
}

int Sample(int inputVal)
{
	int workingVal = inputVal; //��������
	/*
	  �߼��������
	*/
	return workingVal;
}


/*
16.1 ����ѭ��
����foreachѭ���ж������е���ż��

void foreach_test(void)
{
	int fibonacciSequence[] = { 0,1,1,2,3,5,8,13,21,34 };
	int oddFibonacciNumbers = 0;
	int evenFibonacciNumbers = 0;

	for each (int fibonacciNumber in fibonacciSequence)
	{
		if( (fibonacciNumber % 2) == 0 )
	   {
			evenFibonacciNumbers++;
	   }
		else
		{
			oddFibonacciNumbers++;
		}
  }
}
*/

/*
17.2 ��Ҫ�õݹ�ȥ����׳� ���� 쳲���������
*/
int Fibonacci(int number)
{
	int i = 0;
	int n_num = 0;

	if (number < 1)
		return -1;
	/*��1��2��̶�Ϊ0��1*/
	else if (number == 1)
		return 0;
	else if (number == 2)
		return 1;
	else {
		/*��3�ʼ��ʹ��ͨ�ʽ f(n) = f(n-1) + f(n-2);*/
		int n1 = 0;
		int n2 = 1;
		for (i = 2; i < number; i++) {
			n_num = n1 + n2;
			n1 = n2;
			n2 = n_num;
		}
	}

	printf("n_num = %d \n", n_num);

	return n_num;
}

/*
19.1 �������ʽ
*/
#define  true  1
#define  flase (!true)

void Boolean_test(int bool)
{
	if (bool == true)
	{

	}
}

/*
19.3 �����  ���������ĺ궨��
*/
#define  DoNothing()


/*
26.1  �߼�
1����֪���𰸺�ֹͣ�ж�
2��ʹ�ò���滻�����߼�
3������æ��ѭ���������ڲ�
*/
void logic_test(int x)
{
	if ((5 < x) && (x < 10)){
		/*��x<5ʱ��������ʽ��x<10)��������ж�*/
	}

	{
	  // ���ӵ��߼���
	  int a = 0, b = 0, c = 0;
	  int category;

	  if ((a && !c) || (a && b && c)){
		  category = 1;
	  }
	  else if ((b && !a) || (a && c && !b)){
		  category = 2;
	  }
	  else if (c && !a && !b){
		  category = 3;
	  }
	  else {
		  category = 0;
	  }
	  
	  //ʹ�ò���滻�����߼�
	  static int categoryTable[2][2][2] = {
		  //!b!c   !bc   b!c   bc
			  0,    3,    2,    2, //!a
			  1,    2,    1,    1, //a
	  };

	  category = categoryTable[a][b][c];
	}

	{
		/*
		���ԸĽ���Ƕ��ѭ����  ѭ��������100 + 100*5��
		��ѭ����˳�����һ�£�ѭ��������5 + 5*100��
		*/
		int column = 0, row = 0, sum = 0;
		for (column = 0; column < 100; column++) {
			for (row = 0; row < 5; row++) {
				sum = sum + 1;
			}
		}

	}
}

/*
26.4  ���ʽ
1�������ڳ�ʼ��
2��С��ϵͳ����
*/
void expression_test(unsigned int x)
{
	/*��ϵͳ�����ͳ���ʵ�ֵ���2Ϊ�׵Ķ�������
	(unsigned int)(log(x) / log( 2 ));
	*/
	
    const double LOG2 = 0.69314718;
	(unsigned int)(log(x) / LOG2);

	/*
	��дLog2���������ؾ���Ϊ���εļ���ֵ
	*/

	/*
	��һ�ַ����� ʹ�������������2Ϊ�׵Ķ�������
	*/
	//unsigned int Log2(unsigned int x) 
	{
		unsigned int i = 0;
		while ((x = (x >> 1)) != 0) {
			i++;
		}
	}
}

/*
32.5  ע�ͼ���
ע�ʹ����ʱӦע�ء�Ϊ������why���������ǡ���ô����how����
*/

void comment_test(void)
{
/*  ��ע������������˼һ�����ظ���û�ܱ����������ͼ
	//if accout flag  is zero
	if ( accountFlag == 0 ) ...
*/

/*  �õ�ע�ͣ��ܷ�ӳ�����������
    //if establinshing a new account
	if ( acctountFlag == 0 ) ...
*/

/*  �����ڡ�Ϊ�Ρ���ע�ͣ����������ñ�����
   //if establinshing a new account
    if ( acctountType == AccountType.NewAccount ) ...
*/

/*  ʹ�á�С�ڱ��⡱ע��
//establinsh a new account
if ( acctountType == AccountType.NewAccount ) ...
*/

}


/*
�Ա�const char �� char const ���÷���

���꣺��java�ؼ���final�Աȡ�
�����������ݡ����������������࣬Ҳ�������κ�������

final���ݣ�����ʱ����
final�������޷��޸������ε����û�������
final�������̳��಻���޸ķ���
final�ࣺ���ܼ̳и���
*/
void const_test()
{
	char a[10] = { 1,2,3,4,6,4,6,8,7,5 };
	char b[2] = { 3,5 };

	char * ptr = &a;//ptr���û���ָ��ֵ���ɱ�
	*(ptr + 1) = 2;
    *(a + 3) = 5;

	const char * ptr1 = &a;//ptr�����ÿ��Ա䣬����ptr��ָ���ֵ�����Ա�

	ptr1 = &b;
	//*(ptr1 + 1) = 2; //����

	char const * ptr2 = &a;//ͬ��
	ptr2 = &b;
	
	char * const ptr3 = &a;//ptr��ָ���ֵ���Ա䣬����ptr�����ò����Ա�
	//ptr3 = &b; //����

	printf("ptr1 = %#x, ptr2 = %#x ", ptr1, ptr2);
}

void main7(void)
{
	//Find_MapTable();
	//global_test();
	//pointer_change_value();
	//enum_test();
	//struct_test();
	//string_test();
	//Fibonacci(25);
	//DoNothing();

	const_test();
}
