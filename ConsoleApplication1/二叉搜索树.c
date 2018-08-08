#include <stdio.h>
#include <stdlib.h>

#define MAX 21

typedef struct TreeNode {
	int value;
	struct TreeNode * parent;
	struct TreeNode * left;
	struct TreeNode * right;
}TreeNode;                              //树结点结构体，包含数据、左右儿子结点指针、父结点指针

typedef struct {
	TreeNode * root;
}Tree;                                  //树结构体，包含一个根结点

void Tree_Insert(Tree *T, int key);     //插入函数

void Tree_Delete(TreeNode *Root, TreeNode *x);  //删除函数

TreeNode * Tree_Search(TreeNode *x, int key);   //查找函数

void Inorder_Tree_Walk(TreeNode *Root);         //中序遍历

void Inorder_Tree_Walk_Iterative(TreeNode *Root);

TreeNode * Tree_Minimum(TreeNode *x);           //找最小值

TreeNode * Tree_Maximum(TreeNode *x);           //找最大值

TreeNode * Tree_Successor(TreeNode *x);         //找后继

TreeNode * Tree_Predecessor(TreeNode *x);       //找前趋

void free_mem(TreeNode *x);                     //释放内存


/*
* 插入函数，注意插入结点与其在树中对应的父结点的链接（需要记录父结点）。
* 从根结点出发，不停用当前结点与插入的值比较，如果当前结点的值比较大就往当前结点的左儿子走，相反就往右儿子走，直到当前结点为空，
* 在过程中记录当前结点的父结点。
* 运行时间为O(h),h为树的高度。因为整个过程是一条沿着根结点下降的路径。
*/
void Tree_Insert(Tree *T, int key) {
	TreeNode *x;
	x = (TreeNode *)malloc(sizeof(TreeNode));           //新建结点，并将key值付给结点的数据
	x->value = key;
	x->parent = x->left = x->right = NULL;

	if (T->root == NULL)
		T->root = x;                                    //如果树为空，x结点为根
	else {
		TreeNode *y = T->root;                          //y结点用来记录当前结点
		TreeNode *z = NULL;                             //z结点用来记录当前结点的父结点
		while (y != NULL) {
			z = y;
			if (y->value > x->value)
				y = y->left;
			else
				y = y->right;
		}
		x->parent = z;                                  //将x结点与其父结点链接
		if (z->value > x->value)
			z->left = x;
		else
			z->right = x;                               //x结点的父节点与x结点链接
	}
}

/*
* 查找函数，返回含关键值对应的结点指针
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
* 找最小值，并返回最小值对应的结点指针
*/
TreeNode * Tree_Minimum(TreeNode *x) {
	TreeNode *r = x;
	while (r->left != NULL)
		r = r->left;
	return r;
}

/*
* 找最大值，并返回最大值对应的结点指针
*/
TreeNode * Tree_Maximum(TreeNode *x) {
	TreeNode *r = x;
	while (r->right != NULL)
		r = r->right;
	return r;
}

/*
* 找某个结点的后继（关键字大于该结点中最小的那个结点）
* 如果该结点存在右儿子，则后继为以其右儿子为根的子树的最小值对应的结点
* 如果没有右儿子，则找x结点的最低的祖先结点并且x结点处于最低祖先结点的左儿子子树里。如果在右儿子子树里，x结点的值比祖先结点的值大。
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
* 找某个结点的前趋（关键字小于该结点中最大的那个结点）
* 与后继相反
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
* 中序遍历
* 按排列顺序输出树中的所有关键字
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
* 删除结点函数，首先要确定真正删除的结点是那个。
* 如果x没有子结点，直接将x的父结点对应的指针指向NULL
* 如果x只有一个子节点，直接将x的父结点对应的指针指向x的子结点
* 如果x有两个子结点，实际上要删除的不是x，而是x的后继，，再用x的后继的内容代替x的内容
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
