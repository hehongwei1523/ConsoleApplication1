#include <stdio.h>
#include <stdlib.h>

#define RED 1
#define BLACK 0

typedef struct RB_TreeNode {
	int value;
	int color;
	struct RB_TreeNode * parent;
	struct RB_TreeNode * left;
	struct RB_TreeNode * right;
}RB_TreeNode;                       //��������ṹ��

typedef struct RB_Tree {
	RB_TreeNode * root;
}RB_Tree;                           //������ṹ�壬�����

RB_TreeNode  NILL = { -1, BLACK, NULL, NULL, NULL };
RB_TreeNode *NIL = &NILL;                               //NIL���ָ��

void Left_Rotate(RB_Tree *T, RB_TreeNode *x);

void Right_Rotate(RB_Tree *T, RB_TreeNode *x);

void RB_Insert(RB_Tree *T, int key);

void RB_Insert_Fixup(RB_Tree *T, RB_TreeNode *z);

void RB_Delete(RB_Tree *T, RB_TreeNode *z);

void RB_Delete_Fixup(RB_Tree *T, RB_TreeNode *x);

RB_TreeNode * RB_Search(RB_TreeNode *x, int key);

RB_TreeNode * RB_Tree_Minimum(RB_TreeNode *x);

RB_TreeNode * RB_Tree_Maximum(RB_TreeNode *x);

RB_TreeNode * RB_Tree_Successor(RB_TreeNode *x);

RB_TreeNode * RB_Tree_Predecesor(RB_TreeNode *x);

void Inorder_RB_Tree_Walk(RB_TreeNode *x);

void free_men(RB_TreeNode *x);


/*
* x����Ͻ�������ת��y��㣨x�����Ҷ��ӣ�������ӳ�Ϊx�������Ҷ���
* x����Ϊy��������ӵ��¸����
* x���ĸ�����Ϊy�����¸���㣬y����Ϊx�����¸����
* x����Ϊy�����������
*/
void Left_Rotate(RB_Tree *T, RB_TreeNode *x) {
	RB_TreeNode *y = x->right;       //x���Ҷ���          
	x->right = y->left;              //y��������ӻ��Ϊx�����Ҷ���
	if (y->left != NIL)
		y->left->parent = x;         //���y�������,y������ӵĸ����Ϊx
	y->parent = x->parent;
	if (x->parent == NIL)
		T->root = y;                //���x�ĸ����Ϊ�ڱ���˵��xΪ����㣬��y��Ϊ�����
	else if (x == x->parent->left)
		x->parent->left = y;
	else
		x->parent->right = y;       //�ж�xΪ�丸�������Ҷ��ӣ�y��Ϊx������Ӧ�Ķ���
	y->left = x;                    //y�������Ϊx
	x->parent = y;                  //x�ĸ����Ϊy
}

/*
* x����Ͻ�������ת��y��㣨x��������ӣ����Ҷ��ӳ�Ϊx�����������
* x����Ϊy�����Ҷ��ӵ��¸����
* x���ĸ�����Ϊy�����¸���㣬y����Ϊx�����¸����
* x����Ϊy�������Ҷ���
* PS������Ľ��Ϳɲ�������ת
*/
void Right_Rotate(RB_Tree *T, RB_TreeNode *x) {
	RB_TreeNode *y = x->left;
	x->left = y->right;
	if (y->right != NIL)
		y->right->parent = x;
	y->parent = x->parent;
	if (x->parent == NIL)
		T->root = y;
	else if (x == x->parent->left)
		x->parent->left = y;
	else
		x->parent->right = y;
	y->right = x;
	x->parent = y;
}

/*
* ���뺯����ע����������������ж�Ӧ�ĸ��������ӣ���Ҫ��¼����㣩��
* �Ӹ�����������ͣ�õ�ǰ���������ֵ�Ƚϣ������ǰ����ֵ�Ƚϴ������ǰ����������ߣ��෴�����Ҷ����ߣ�ֱ����ǰ���Ϊ�գ�
* �ڹ����м�¼��ǰ���ĸ���㡣
* ����ʱ��ΪO(h),hΪ���ĸ߶ȡ���Ϊ����������һ�����Ÿ�����½���·����
*/
void RB_Insert(RB_Tree *T, int key) {
	RB_TreeNode *z;
	z = (RB_TreeNode *)malloc(sizeof(RB_TreeNode));         //�½����
	z->value = key;
	z->color = RED;
	z->parent = z->left = z->right = NIL;
	RB_TreeNode *x = T->root;
	RB_TreeNode *y = NIL;
	while (x != NIL) {
		y = x;
		if (x->value < key)
			x = x->right;
		else
			x = x->left;
	}
	z->parent = y;
	if (y == NIL) {
		T->root = z;
		T->root->parent = NIL;
		T->root->parent->color = BLACK;
	}
	else if (z->value < y->value)
		y->left = z;
	else
		y->right = z;
	RB_Insert_Fixup(T, z);                                 //���������ά�ֺ������
}

/*
* ���������ά�ֺ������
*/
void RB_Insert_Fixup(RB_Tree *T, RB_TreeNode *z) {
	while (z->parent->color == RED) {                         //���z���ĸ����Ϊ��ɫ���Ͳ��ý���3������Ĵ���
		if (z->parent == z->parent->parent->left) {          //z�ĸ����Ϊ����ӵ����
			RB_TreeNode *y = z->parent->parent->right;
			if (y->color == RED) {                            //���1
				z->parent->color = BLACK;
				y->color = BLACK;
				z->parent->parent->color = RED;
				z = z->parent->parent;
			}
			else {
				if (z == z->parent->right) {                  //���2
					z = z->parent;
					Left_Rotate(T, z);                      //����ת�����2��Ϊ3
				}
				z->parent->color = BLACK;                   //���3
				z->parent->parent->color = RED;
				Right_Rotate(T, z->parent->parent);         //��ѡ����Υ������4
			}
		}
		else {
			RB_TreeNode *y = z->parent->parent->left;       //z�Ľ��Ϊ�Ҷ��ӵ����
			if (y->color == RED) {                            //���1
				z->parent->color = BLACK;
				y->color = BLACK;
				z->parent->parent->color = RED;
				z = z->parent->parent;
			}
			else {
				if (z == z->parent->left) {                   //���2
					z = z->parent;
					Right_Rotate(T, z);                     //����ת�����2��Ϊ���3
				}
				z->parent->color = BLACK;                   //���3
				z->parent->parent->color = RED;
				Left_Rotate(T, z->parent->parent);          //����ת���Υ������4
			}
		}
	}
	T->root->color = BLACK;                                 //��������T�ĸ����Ϊ��ɫ�ͻ��ɺ�ɫ������Ǻ�ɫ��ɺ�ɫҲûӰ��
}

/*
* ɾ����㺯��������Ҫȷ������ɾ���Ľ�����Ǹ���
* ���zû���ӽ�㣬ֱ�ӽ�z�ĸ�����Ӧ��ָ��ָ��NULL
* ���zֻ��һ���ӽڵ㣬ֱ�ӽ�z�ĸ�����Ӧ��ָ��ָ��z���ӽ��
* ���z�������ӽ�㣬ʵ����Ҫɾ���Ĳ���z������z�ĺ�̣�������z�ĺ�̵����ݴ���z������
*/

void RB_Delete(RB_Tree *T, RB_TreeNode *z) {
	RB_TreeNode *x = NULL;
	RB_TreeNode *y = NULL;

	if (z->left == NIL || z->right == NIL)
		y = z;
	else
		y = RB_Tree_Successor(z);
	if (y->left != NIL)
		x = y->left;
	else
		x = y->right;
	x->parent = y->parent;
	if (y->parent == NIL)
		T->root = x;
	else if (y == y->parent->left)
		y->parent->left = x;
	else
		y->parent->right = x;
	if (y != z)
		z->value = y->value;
	if (y->color == BLACK)
		RB_Delete_Fixup(T, x);          //��ʵ��Ҫɾ���Ľ��yΪ��ɫʱ����Ҫ���е���
}

/*
* ɾ��������ʹ�����ά�ֺ������
*/
void RB_Delete_Fixup(RB_Tree *T, RB_TreeNode *x) {
	while (x != T->root && x->color == BLACK) {               //��x���Ϊ��������x����ɫΪ��ɫ����Ϊ��ڣ� ʵ���϶����ɫû��ֱ�Ӽ���ȥ��ֻ��Ĭ��x�ڵ���һ�ض���ĺ�ɫ��
		if (x == x->parent->left) {                           //xΪ��������
			RB_TreeNode *w = x->parent->right;
			if (w->color == RED) {                            //���1
				w->color = BLACK;
				x->parent->color = RED;
				Left_Rotate(T, x->parent);                  //����ת��ʹ�����1ת�������2��3��4
				w = x->parent->right;
			}

			if (w->left->color == BLACK && w->right->color == BLACK) {      //���2
				w->color = RED;                            //�޸���ɫ
				x = x->parent;                             //����
			}
			else {
				if (w->right->color == BLACK) {               //���3
					w->left->color = BLACK;
					w->color = RED;
					Right_Rotate(T, w);                     //����ת�����3ת�������4
					w = x->parent->right;
				}
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->right->color = BLACK;
				Left_Rotate(T, x->parent);                  //����ת��ȥ��x�Ķ����ɫ
				x = T->root;                                //ʹѭ������
			}

		}
		else {                                               //xΪ�Ҷ��������PS�����ĵ�ע�Ͳο����ģ�
			RB_TreeNode *w = x->parent->left;
			if (w->color == RED) {
				w->color = BLACK;
				x->parent->color = RED;
				Right_Rotate(T, x->parent);
				w = x->parent->left;
			}

			if (w->left->color == BLACK && w->right->color == BLACK) {
				w->color = RED;
				x = x->parent;
			}
			else {
				if (w->left->color == BLACK) {
					w->right->color = BLACK;
					w->color = RED;
					Left_Rotate(T, w);
					w = x->parent->left;
				}
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->left->color = BLACK;
				Right_Rotate(T, x->parent);
				x = T->root;
			}
		}
	}
}


RB_TreeNode * RB_Search(RB_TreeNode *x, int key) {
	if (x->value == key || x == NIL)
		return x;
	if (x->value > key)
		RB_Search(x->left, key);
	else
		RB_Search(x->right, key);
}

RB_TreeNode * RB_Tree_Minimum(RB_TreeNode *x) {
	RB_TreeNode *r = x;
	while (r->left != NIL)
		r = r->left;
	return r;
}

RB_TreeNode * RB_Tree_Maximum(RB_TreeNode *x) {
	RB_TreeNode *r = x;
	while (r->left != NIL)
		r = r->left;
	return r;
}

RB_TreeNode * RB_Tree_Successor(RB_TreeNode *x) {
	RB_TreeNode *r = x;
	if (r->right != NIL)
		return RB_Tree_Minimum(r->right);
	RB_TreeNode *y = r->parent;
	while (y != NIL && r == y->right) {
		r = y;
		y = y->parent;
	}
	return y;
}
RB_TreeNode * RB_Tree_Predecesor(RB_TreeNode *x) {
	RB_TreeNode *r = x;
	if (r->left != NIL)
		return RB_Tree_Maximum(r->left);
	RB_TreeNode *y = r->parent;
	while (y != NIL && r == y->left) {
		r = y;
		y = y->parent;
	}
	return y;
}

void Inorder_RB_Tree_Walk(RB_TreeNode *x) {
	if (x != NIL) {
		Inorder_RB_Tree_Walk(x->left);
		printf("%d : ", x->value);
		if (x->color == 1)
			printf("red ");
		else
			printf("black ");
		Inorder_RB_Tree_Walk(x->right);
	}
}

void free_men(RB_TreeNode *x) {
	if (x != NIL) {
		free_men(x->left);
		free_men(x->right);
		free(x);
	}
}

int main_rb() {
	RB_Tree *T = malloc(sizeof(RB_TreeNode));
	T->root = NIL;

	int n, value, i;
	scanf_s("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf_s("%d", &value);
		RB_Insert(T, value);
		Inorder_RB_Tree_Walk(T->root);
		printf("\n");
	}
	RB_TreeNode *s = RB_Search(T->root, 3);
	if (s != NIL)
		printf("%d is exists!\n", s->value);
	/*Inorder_RB_Tree_Walk(T->root);

	printf("\n");*/
	printf("%d\n", RB_Tree_Minimum(T->root)->value);
	printf("%d\n", RB_Tree_Maximum(T->root)->value);
	printf("%d\n", RB_Tree_Successor(s)->value);
	printf("%d\n", RB_Tree_Predecesor(s)->value);
	RB_Delete(T, s);
	Inorder_RB_Tree_Walk(T->root);
	printf("\n");
	return 0;
}
