
#include "stdafx.h"
#include <stdlib.h>
#include "stdafx.h"

#include "stdio.h"
#if 0
/*
һ��B���������µ����ʣ�

1��ÿ���ڵ�x���������ԣ�
����a��x.n��>�ؼ��ָ���
  ��b���ؼ��ֵ�������
    c��x.leaf��>�ڵ��Ƿ�����Ҷ�ӽڵ�

2��ÿ���ڵ���x.n+1�����ӽڵ�

3��ÿ���ڵ�ؼ��� > �����ӽڵ� < ���Һ��ӽڵ�

4��ÿ��Ҷ�ӽڵ������ͬ����ȣ������ĸ߶�h��

5��ÿ���ڵ�����С���� t ����ʾ��ؼ��ָ��������½磬���ߺ��ӽڵ㣨��֧���ӣ��ĸ��������½硣
һ�㣬ÿ���Ǹ��ڵ����������Ĺؼ��ָ��� j ���㣺

t-1 <= j <= 2*t - 1
���ڵ����ٰ���һ���ؼ��֣�����Ҷ�ӽڵ㣬�������������ӣ��� t>= 2��
*/


/* B�����ṹ */
typedef struct _btree_node_t
{
	int num;                        /* �ؼ��ָ��� */
	int *key;                       /* �ؼ��֣���ռ�ռ�Ϊ(max+1) - �������1���ռ����ڽ����ռ�ʹ�� */
	struct _btree_node_t **child;   /* �ӽ�㣺��ռ�ռ�Ϊ(max+2) - �������1���ռ����ڽ����ռ�ʹ�� */
	struct _btree_node_t *parent;   /* ����� */
}btree_node_t;

/* B���ṹ */
typedef struct
{
	int max;                        /* ����������ؼ��ָ��� - ��m=max+1 */
	int min;                        /* ���������С�ؼ��ָ��� */
	int sidx;                       /* �������� = (max+1)/2 */
	btree_node_t *root;             /* B��������ַ */
}btree_t;

/******************************************************************************
**��������: btree_creat
**��    ��: ����B��
**�������:
**     _btree: B��
**     m: �� - ȡֵ��Χm>=3
**�������: NONE
**��    ��: 0:�ɹ� -1:ʧ��
**ʵ������:
**ע������:
**     ע�⣺����max��ֵ����С��2.
**��    ��: # Qifeng.zou # 2014.03.12 #
******************************************************************************/
int btree_creat(btree_t **_btree, int m)
{
	btree_t *btree = NULL;

	if (m < 3) {
		fprintf(stderr, "[%s][%d] Parameter 'max' must geater than 2.\n", __FILE__, __LINE__);
		return -1;
	}

	btree = (btree_t *)calloc(1, sizeof(btree_t));
	if (NULL == btree) {
		fprintf(stderr, "[%s][%d] errmsg:[%d] %s!\n", __FILE__, __LINE__, errno, strerror(errno));
		return -1;
	}

	btree->max = m - 1;
	btree->min = m / 2;
	if (0 != m % 2) {
		btree->min++;
	}
	btree->min--;
	btree->sidx = m / 2;
	btree->root = NULL; /* ���� */

	*_btree = btree;
	return 0;
}

/******************************************************************************
**��������: btree_insert
**��    ��: ����ؼ��֣�����ӿڣ�
**�������:
**     btree: B��
**     key: ������Ĺؼ���
**�������: NONE
**��    ��: 0:�ɹ� -1:ʧ��
**ʵ������:
**ע������:
**��    ��: # Qifeng.zou # 2014.03.12 #
******************************************************************************/
int btree_insert(btree_t *btree, int key)
{
	int idx = 0;
	btree_node_t *node = btree->root;

	/* 1. ������һ����� */
	if (NULL == node) {
		node = btree_creat_node(btree);
		if (NULL == node) {
			fprintf(stderr, "[%s][%d] Create node failed!\n", __FILE__, __LINE__);
			return -1;
		}

		node->num = 1;
		node->key[0] = key;
		node->parent = NULL;

		btree->root = node;
		return 0;
	}

	/* 2. ���Ҳ���λ�ã��ڴ˵�ȻҲ���Բ��ö��ֲ����㷨������Ȥ�Ŀ����Լ�ȥ�Ż� */
	while (NULL != node) {
		for (idx = 0; idx<node->num; idx++) {
			if (key == node->key[idx]) {
				fprintf(stderr, "[%s][%d] The node is exist!\n", __FILE__, __LINE__);
				return 0;
			}
			else if (key < node->key[idx]) {
				break;
			}
		}

		if (NULL != node->child[idx]) {
			node = node->child[idx];
		}
		else {
			break;
		}
	}

	/* 3. ִ�в������ */
	return _btree_insert(btree, node, key, idx);
}

/******************************************************************************
**��������: _btree_insert
**��    ��: ����ؼ��ֵ�ָ�����
**�������:
**     btree: B��
**     node: ָ�����
**     key: ������Ĺؼ���
**     idx: ָ��λ��
**�������: NONE
**��    ��: 0:�ɹ� -1:ʧ��
**ʵ������:
**ע������:
**��    ��: # Qifeng.zou # 2014.03.12 #
******************************************************************************/
static int _btree_insert(btree_t *btree, btree_node_t *node, int key, int idx)
{
	int i = 0;

	/* 1. �ƶ��ؼ���:��������ײ��ĳ�����ն˽���ϲ���һ���ؼ���,��˸ý���޺��ӽ�㣬�ʲ��漰����ָ����ƶ����� */
	for (i = node->num; i>idx; i--) {
		node->key[i] = node->key[i - 1];
	}

	node->key[idx] = key; /* ���� */
	node->num++;

	/* 2. ���Ѵ��� */
	if (node->num > btree->max) {
		return btree_split(btree, node);
	}

	return 0;
}

/******************************************************************************
**��������: btree_split
**��    ��: �����Ѵ���
**�������:
**     btree: B��
**     node: ��Ҫ�����Ѵ���Ľ��
**�������: NONE
**��    ��: 0:�ɹ� -1:ʧ��
**ʵ������:
**ע������:
**��    ��: # Qifeng.zou # 2014.03.12 #
******************************************************************************/
static int btree_split(btree_t *btree, btree_node_t *node)
{
	int idx = 0, total = 0, sidx = btree->sidx;
	btree_node_t *parent = NULL, *node2 = NULL;


	while (node->num > btree->max) {
		/* Split node */
		total = node->num;

		node2 = btree_creat_node(btree);
		if (NULL == node2) {
			fprintf(stderr, "[%s][%d] Create node failed!\n", __FILE__, __LINE__);
			return -1;
		}

		/* Copy data */
		memcpy(node2->key, node->key + sidx + 1, (total - sidx - 1) * sizeof(int));
		memcpy(node2->child, node->child + sidx + 1, (total - sidx) * sizeof(btree_node_t *));

		node2->num = (total - sidx - 1);
		node2->parent = node->parent;

		node->num = sidx;
		/* Insert into parent */
		parent = node->parent;
		if (NULL == parent) {
			/* Split root node */
			parent = btree_creat_node(btree);
			if (NULL == parent) {
				fprintf(stderr, "[%s][%d] Create root failed!", __FILE__, __LINE__);
				return -1;
			}

			btree->root = parent;
			parent->child[0] = node;
			node->parent = parent;
			node2->parent = parent;

			parent->key[0] = node->key[sidx];
			parent->child[1] = node2;
			parent->num++;
		}
		else {
			/* Insert into parent node */
			for (idx = parent->num; idx>0; idx--) {
				if (node->key[sidx] < parent->key[idx - 1]) {
					parent->key[idx] = parent->key[idx - 1];
					parent->child[idx + 1] = parent->child[idx];
					continue;
				}
				break;
			}

			parent->key[idx] = node->key[sidx];
			parent->child[idx + 1] = node2;
			node2->parent = parent;
			parent->num++;
		}

		memset(node->key + sidx, 0, (total - sidx) * sizeof(int));
		memset(node->child + sidx + 1, 0, (total - sidx) * sizeof(btree_node_t *));

		/* Change node2's child->parent */
		for (idx = 0; idx <= node2->num; idx++) {
			if (NULL != node2->child[idx]) {
				node2->child[idx]->parent = node2;
			}
		}
		node = parent;
	}

	return 0;
}

/******************************************************************************
**��������: btree_creat_node
**��    ��: �½����
**�������:
**     btree: B��
**�������: NONE
**��    ��: �ڵ��ַ
**ʵ������:
**ע������:
**��    ��: # Qifeng.zou # 2014.03.12 #
******************************************************************************/
static btree_node_t *btree_creat_node(btree_t *btree)
{
	btree_node_t *node = NULL;


	node = (btree_node_t *)calloc(1, sizeof(btree_node_t));
	if (NULL == node) {
		fprintf(stderr, "[%s][%d] errmsg:[%d] %s\n", __FILE__, __LINE__, errno, strerror(errno));
		return NULL;
	}

	node->num = 0;

	/* More than (max) is for move */
	node->key = (int *)calloc(btree->max + 1, sizeof(int));
	if (NULL == node->key) {
		free(node), node = NULL;
		fprintf(stderr, "[%s][%d] errmsg:[%d] %s\n", __FILE__, __LINE__, errno, strerror(errno));
		return NULL;
	}

	/* More than (max+1) is for move */
	node->child = (btree_node_t **)calloc(btree->max + 2, sizeof(btree_node_t *));
	if (NULL == node->child) {
		free(node->key);
		free(node), node = NULL;
		fprintf(stderr, "[%s][%d] errmsg:[%d] %s\n", __FILE__, __LINE__, errno, strerror(errno));
		return NULL;
	}

	return node;
}

int main_BTree(void)
{
	int key[10] = { 34,25,1,89,63,55,23,180,450,432 };

}
#endif