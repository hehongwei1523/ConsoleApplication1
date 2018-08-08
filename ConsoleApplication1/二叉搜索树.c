#include <stdio.h>
#include <stdlib.h>

#define MAX 21

typedef struct TreeNode {
	int value;
	struct TreeNode * parent;
	struct TreeNode * left;
	struct TreeNode * right;
}TreeNode;                              //�����ṹ�壬�������ݡ����Ҷ��ӽ��ָ�롢�����ָ��

typedef struct {
	TreeNode * root;
}Tree;                                  //���ṹ�壬����һ�������

void Tree_Insert(Tree *T, int key);     //���뺯��

void Tree_Delete(TreeNode *Root, TreeNode *x);  //ɾ������

TreeNode * Tree_Search(TreeNode *x, int key);   //���Һ���

void Inorder_Tree_Walk(TreeNode *Root);         //�������

void Inorder_Tree_Walk_Iterative(TreeNode *Root);

TreeNode * Tree_Minimum(TreeNode *x);           //����Сֵ

TreeNode * Tree_Maximum(TreeNode *x);           //�����ֵ

TreeNode * Tree_Successor(TreeNode *x);         //�Һ��

TreeNode * Tree_Predecessor(TreeNode *x);       //��ǰ��

void free_mem(TreeNode *x);                     //�ͷ��ڴ�


/*
* ���뺯����ע����������������ж�Ӧ�ĸ��������ӣ���Ҫ��¼����㣩��
* �Ӹ�����������ͣ�õ�ǰ���������ֵ�Ƚϣ������ǰ����ֵ�Ƚϴ������ǰ����������ߣ��෴�����Ҷ����ߣ�ֱ����ǰ���Ϊ�գ�
* �ڹ����м�¼��ǰ���ĸ���㡣
* ����ʱ��ΪO(h),hΪ���ĸ߶ȡ���Ϊ����������һ�����Ÿ�����½���·����
*/
void Tree_Insert(Tree *T, int key) {
	TreeNode *x;
	x = (TreeNode *)malloc(sizeof(TreeNode));           //�½���㣬����keyֵ������������
	x->value = key;
	x->parent = x->left = x->right = NULL;

	if (T->root == NULL)
		T->root = x;                                    //�����Ϊ�գ�x���Ϊ��
	else {
		TreeNode *y = T->root;                          //y���������¼��ǰ���
		TreeNode *z = NULL;                             //z���������¼��ǰ���ĸ����
		while (y != NULL) {
			z = y;
			if (y->value > x->value)
				y = y->left;
			else
				y = y->right;
		}
		x->parent = z;                                  //��x������丸�������
		if (z->value > x->value)
			z->left = x;
		else
			z->right = x;                               //x���ĸ��ڵ���x�������
	}
}

/*
* ���Һ��������غ��ؼ�ֵ��Ӧ�Ľ��ָ��
*/
TreeNode * Tree_Search(TreeNode *x, int key) {
	if (x == NULL || x->value == key)
		return x;

	if (x->value > key)
		Tree_Search(x->left, key);
	else
		Tree_Search(x->right, key);
}

/*
* ����Сֵ����������Сֵ��Ӧ�Ľ��ָ��
*/
TreeNode * Tree_Minimum(TreeNode *x) {
	TreeNode *r = x;
	while (r->left != NULL)
		r = r->left;
	return r;
}

/*
* �����ֵ�����������ֵ��Ӧ�Ľ��ָ��
*/
TreeNode * Tree_Maximum(TreeNode *x) {
	TreeNode *r = x;
	while (r->right != NULL)
		r = r->right;
	return r;
}

/*
* ��ĳ�����ĺ�̣��ؼ��ִ��ڸý������С���Ǹ���㣩
* ����ý������Ҷ��ӣ�����Ϊ�����Ҷ���Ϊ������������Сֵ��Ӧ�Ľ��
* ���û���Ҷ��ӣ�����x������͵����Ƚ�㲢��x��㴦��������Ƚ�������������������Ҷ��������x����ֵ�����Ƚ���ֵ��
*/
TreeNode * Tree_Successor(TreeNode *x) {
	TreeNode *z = x;
	if (z->right != NULL)
		return Tree_Minimum(z->right);
	TreeNode *y = z->parent;
	while (y != NULL && z == y->right) {
		z = y;
		y = y->parent;
	}
	return y;
}

/*
* ��ĳ������ǰ�����ؼ���С�ڸý���������Ǹ���㣩
* �����෴
*/
TreeNode * Tree_Predecessor(TreeNode *x) {
	TreeNode *z = x;
	if (z->left != NULL)
		return Tree_Maximum(z->left);
	TreeNode *y = z->parent;
	while (y != NULL && z == y->left) {
		z = y;
		y = y->parent;
	}
	return y;
}

/*
* �������
* ������˳��������е����йؼ���
*/
void Inorder_Tree_Walk(TreeNode *x) {
	if (x != NULL) {
		Inorder_Tree_Walk(x->left);
		printf("%d ", x->value);
		Inorder_Tree_Walk(x->right);
	}
}

void Inorder_Tree_Walk_Iterative(TreeNode * Root)
{
}

/*
* ɾ����㺯��������Ҫȷ������ɾ���Ľ�����Ǹ���
* ���xû���ӽ�㣬ֱ�ӽ�x�ĸ�����Ӧ��ָ��ָ��NULL
* ���xֻ��һ���ӽڵ㣬ֱ�ӽ�x�ĸ�����Ӧ��ָ��ָ��x���ӽ��
* ���x�������ӽ�㣬ʵ����Ҫɾ���Ĳ���x������x�ĺ�̣�������x�ĺ�̵����ݴ���x������
*/
void Tree_Delete(TreeNode *Root, TreeNode *x) {
	TreeNode *y;
	TreeNode *z;
	if (x->left == NULL || x->right == NULL)
		y = x;
	else
		y = Tree_Successor(x);

	if (y->left != NULL)
		z = y->left;
	else
		z = y->right;

	if (z != NULL)
		z->parent = y->parent;
	if (y->parent == NULL)
		Root = z;
	else if (y == y->parent->left)
		y->parent->left = z;
	else
		y->parent->right = z;
	if (y != x)
		x->value = y->value;

	free(y);
}

void free_mem(TreeNode *x) {
	if (x != NULL) {
		free_mem(x->left);
		free_mem(x->right);
		free(x);
	}
}

int tree_main(void)
{
	int V[] = {4,9,10,6,13,7,0,5,20,2,3,11};
	int n, value, i;
	scanf_s("%d", &n);

	Tree *T = malloc(sizeof(TreeNode));//NULL;
	T->root = NULL;

	for (i = 1; i <= n; i++) {
		//scanf_s("%d", &value);
		Tree_Insert(T, V[i]);// value);
	}
	TreeNode *s = Tree_Search(T->root, 5);
	if (s != NULL)
		printf("%d\n", s->value);
	Inorder_Tree_Walk(T->root);

	printf("\r\n");
	printf("%d\n", Tree_Minimum(T->root)->value);
	printf("%d\n", T->root->value);
	printf("%d\n", Tree_Maximum(T->root)->value);

	printf("%d\n", Tree_Successor(s)->value);
	printf("%d\n", Tree_Predecessor(s)->value);
	Tree_Delete(T->root, s);
	Inorder_Tree_Walk(T->root);
	printf("\n");

	free_mem(T->root);
	return 0;
}

int mainc(void)
{
	tree_main();
}
