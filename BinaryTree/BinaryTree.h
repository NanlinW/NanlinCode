#pragma once
#include <assert.h>
#include <stdio.h>
#include <malloc.h>
#include"Queue.h"

typedef struct BTDataType;
typedef struct BinaryTreeNode
{
	char _data;
	struct BinaryTreeNode*_left;
	struct BinaryTreeNode*_right;
}BTNode;

//ͨ��ǰ�����������"ABD##E#E#H##CF##G##"����������
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)//������
{

}

void BinaryTreeDestory(BTNode* root)//ɾ�������
{
	if (root == NULL)
	{
		return;
	}
	if (root->_left == NULL && root->_right == NULL)
	{
		free(root);
	}
	return BinaryTreeDestory(root->_left) + BinaryTreeDestory(root->_right);
}

int BinaryTreeSize(BTNode* root)//�ڵ����
{
	if (root == NULL)
	{
		return 0;
	}
	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}

int BinaryTreeLeafSize(BTNode* root)//Ҷ�Ӹ���
{
	if (root = NULL)
	{
		return;
	}
	if (root->_left = NULL && root->_right = NULL)
	{
		return 1;
	}
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}

int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root = NULL)
	{
		return 0;
	}
	if (k = 1)
	{
		return 1;
	}
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}

BTNode* BinaryTreeFind(BTNode* root, char x)
{
	if (root = NULL)
	{
		return NULL;
	}
	if (root->_data = x)
	{
		return root;
	}
	BTDataType* lret = BinaryTreeFind(root->_left, x);
	if (lret != NULL)
	{
		return lret;
	}
	BTDataType* rret = BinaryTreeFind(root->_right, x);
	if (rret != NULL)
	{
		return rret;
	}
	return NULL;
}

