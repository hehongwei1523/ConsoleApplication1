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
}RB_TreeNode;                       //红黑树结点结构体

typedef struct RB_Tree {
	RB_TreeNode * root;
}RB_Tree;                           //红黑树结构体，根结点

RB_TreeNode  NILL = { -1, BLACK, NULL, NULL, NULL };
RB_TreeNode *NIL = &NILL;                               //NIL结点指针

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
* x结点上进行左旋转，y结点（x结点的右儿子）的左儿子成为x结点的新右儿子
* x结点成为y结点的左儿子的新父结点
* x结点的父结点成为y结点的新父结点，y结点成为x结点的新父结点
* x结点成为y结点的新左儿子
*/
void Left_Rotate(RB_Tree *T, RB_TreeNode *x) {
	RB_TreeNode *y = x->right;       //x点右儿子          
	x->right = y->left;              //y结点的左儿子会成为x结点的右儿子
	if (y->left != NIL)
		y->left->parent = x;         //如果y有左儿子,y的左儿子的父结点为x
	y->parent = x->parent;
	if (x->parent == NIL)
		T->root = y;                //如果x的父结点为哨兵，说明x为根结点，则y成为根结点
	else if (x == x->parent->left)
		x->parent->left = y;
	else
		x->parent->right = y;       //判断x为其父结点的左、右儿子，y成为x父结点对应的儿子
	y->left = x;                    //y的左儿子为x
	x->parent = y;                  //x的父结点为y
}

/*
* x结点上进行右旋转，y结点（x结点的左儿子）的右儿子成为x结点的新左儿子
* x结点成为y结点的右儿子的新父结点
* x结点的父结点成为y结点的新父结点，y结点成为x结点的新父结点
* x结点成为y结点的新右儿子
* PS：代码的解释可参照左旋转
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
* 插入函数，注意插入结点与其在树中对应的父结点的链接（需要记录父结点）。
* 从根结点出发，不停用当前结点与插入的值比较，如果当前结点的值比较大就往当前结点的左儿子走，相反就往右儿子走，直到当前结点为空，
* 在过程中记录当前结点的父结点。
* 运行时间为O(h),h为树的高度。因为整个过程是一条沿着根结点下降的路径。
*/
void RB_Insert(RB_Tree *T, int key) {
	RB_TreeNode *z;
	z = (RB_TreeNode *)malloc(sizeof(RB_TreeNode));         //新建结点
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
	RB_Insert_Fixup(T, z);                                 //插入调整，维持红黑性质
}

/*
* 插入调整，维持红黑性质
*/
void RB_Insert_Fixup(RB_Tree *T, RB_TreeNode *z) {
	while (z->parent->color == RED) {                         //如果z结点的父结点为黑色，就不用进入3种情况的处理
		if (z->parent == z->parent->parent->left) {          //z的父结点为左儿子的情况
			RB_TreeNode *y = z->parent->parent->right;
			if (y->color == RED) {                            //情况1
				z->parent->color = BLACK;
				y->color = BLACK;
				z->parent->parent->color = RED;
				z = z->parent->parent;
			}
			else {
				if (z == z->parent->right) {                  //情况2
					z = z->parent;
					Left_Rotate(T, z);                      //左旋转，情况2变为3
				}
				z->parent->color = BLACK;                   //情况3
				z->parent->parent->color = RED;
				Right_Rotate(T, z->parent->parent);         //右选择解决违反性质4
			}
		}
		else {
			RB_TreeNode *y = z->parent->parent->left;       //z的结点为右儿子的情况
			if (y->color == RED) {                            //情况1
				z->parent->color = BLACK;
				y->color = BLACK;
				z->parent->parent->color = RED;
				z = z->parent->parent;
			}
			else {
				if (z == z->parent->left) {                   //情况2
					z = z->parent;
					Right_Rotate(T, z);                     //右旋转，情况2变为情况3
				}
				z->parent->color = BLACK;                   //情况3
				z->parent->parent->color = RED;
				Left_Rotate(T, z->parent->parent);          //左旋转解决违反性质4
			}
		}
	}
	T->root->color = BLACK;                                 //如果红黑树T的根结点为红色就会变成黑色，如果是黑色变成黑色也没影响
}

/*
* 删除结点函数，首先要确定真正删除的结点是那个。
* 如果z没有子结点，直接将z的父结点对应的指针指向NULL
* 如果z只有一个子节点，直接将z的父结点对应的指针指向z的子结点
* 如果z有两个子结点，实际上要删除的不是z，而是z的后继，，再用z的后继的内容代替z的内容
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
		RB_Delete_Fixup(T, x);          //当实际要删除的结点y为黑色时才需要进行调整
}

/*
* 删除调整，使红黑树维持红黑性质
*/
void RB_Delete_Fixup(RB_Tree *T, RB_TreeNode *x) {
	while (x != T->root && x->color == BLACK) {               //当x结点为根结点或者x的颜色为红色（即为红黑， 实际上额外黑色没有直接加上去，只是默认x节点有一重额外的黑色）
		if (x == x->parent->left) {                           //x为左儿子情况
			RB_TreeNode *w = x->parent->right;
			if (w->color == RED) {                            //情况1
				w->color = BLACK;
				x->parent->color = RED;
				Left_Rotate(T, x->parent);                  //左旋转，使得情况1转换成情况2、3或4
				w = x->parent->right;
			}

			if (w->left->color == BLACK && w->right->color == BLACK) {      //情况2
				w->color = RED;                            //修改颜色
				x = x->parent;                             //上移
			}
			else {
				if (w->right->color == BLACK) {               //情况3
					w->left->color = BLACK;
					w->color = RED;
					Right_Rotate(T, w);                     //右旋转，情况3转换成情况4
					w = x->parent->right;
				}
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->right->color = BLACK;
				Left_Rotate(T, x->parent);                  //左旋转，去掉x的额外黑色
				x = T->root;                                //使循环结束
			}

		}
		else {                                               //x为右儿子情况（PS：下文的注释参考上文）
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
