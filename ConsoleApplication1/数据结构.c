#include <stdio.h>  
#include <math.h>  
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"

/*
ջ������ȳ�
���У��Ƚ��ȳ�
*/

#define MAX 20
int STACK[MAX] = { 5,3,2,4,5,6 };
static int *p = &STACK[0];

void INSERT(int a)
{


}

int STACK_EMPTY(int S[])
{
	if (S[0] == 0)
	{
		return true;
	}
	else
		return false;
}

void PUSH(int S[], int x)
{
	S[0] = S[0] + 1;
	S[S[0]] = x;
}

int POP(int S[])
{
	if (STACK_EMPTY(S))
	{
		printf("underflow \n");
		return;
	}
	else
	{
		S[0] = S[0] - 1;
		return S[S[0] + 1];
	} 
}

void show_stack(void)
{
	for (int i = 0; i < STACK[0] + 1; i++)
	{
		printf("S[%d] = %d \n", i, STACK[i]);
	}
	printf("-- \n");
}

void stack_main()
{
	PUSH(STACK, 5);
	PUSH(STACK, 8);
	show_stack();

	POP(STACK);
	show_stack();
}

/*
����
*/
typedef struct LIST {
	//struct List * prev;
	int key;
	struct List * next;
}List;

List head = {
	//NULL,
	0,
	NULL,
};

void LIST_BUILD(int S[])
{
	List *temp = NULL, *list = NULL;

	for (int i = 1; i < S[0] + 1; i++)
	{
		list = malloc(sizeof(List));
		if (i == 1)
		{
			head.next = list;
		}
		else
		{
			temp->next = list;
		}
		list->key = S[i];
		temp = list;
    }

	list->next = NULL;
}

void show_list(List *l)
{
	List *p = l;

	while (p != NULL)
	{
		printf("= %d \n", p->key);
		p = p->next;
	}
}

void list_main()
{
	LIST_BUILD(STACK);

	show_list(head.next);
}

void LIST_SEARCH(List L, int k)
{
	//int x = L.head;
}

//����������ڵ㶨�壬��ģ��
/*
typedef struct _BinarySearchTreeNode
{
	T key;//�ڵ�ֵ������ֻ��һ���ؼ�Ԫ��ֵ��û�и������ݣ��������ݣ�
	BinarySearchTreeNode * parent;//ָ��˫�׽ڵ�ָ��
	BinarySearchTreeNode * left;//ָ�����ӽڵ�ָ��
	BinarySearchTreeNode * right;//ָ���Һ��ӽڵ�ָ��
}BinarySearchTreeNode;

int key[] = {};
int TREE_SEARCH(int x, int k)
{
	if (x == NULL || k == key[x])
	{
		return x;
	}
	if (k < key[x])
	{
		return TREE_SEARCH(left[x], k);
	}
	else
	{
		return TREE_SEARCH(right[x], k);
	}
}
*/

int main_data(void)
{
	//stack_main();
	list_main();

	return 0;
}