//////#include<stdio.h>
//////#include<stddef.h>
//////
//////typedef struct BiTNode
//////{
//////	int data;
//////	struct BiTNode* lchild, * rchild;
//////}BiTNode, * BiTree;
//////
//////void preOrder(BiTNode* root)
//////{
//////	if (root == NULL)
//////		return;
//////	printf("%d ", root->data);
//////
//////	preOrder(root->lchild);
//////
//////	preOrder(root->rchild);
//////}
//////
//////
//////void inOrder(BiTNode* root)
//////{
//////	if (root)
//////	{
//////		inOrder(root->lchild);
//////		printf("%d ", root->data);
//////		inOrder(root->rchild);
//////	}
//////}
//////
//////void postOrder(BiTNode* root)
//////{
//////	if (root)
//////	{
//////		postOrder(root->lchild);
//////		postOrder(root->rchild);
//////		printf("%d ", root->data);
//////	}
//////}
//////int main()
//////{
//////
//////	return 0;
//////}
////
/////*
////* ������������������ǵݹ����
////* C/C++ ����
////*
////* @author Erice_s
////* binbin_Erices@163.com
////* @date 2017/10/28
////*
////*/
//////#define _CRT_SECURE_NO_WARNINGS
//////#include <iostream>
//////#include <stack>
//////#define   MAX_STACK  50
//////
//////using namespace std;
////
//////typedef struct BiTNode
//////{
//////	int data;
//////	struct BiTNode* lchild, * rchild;
//////}BiTNode, * BiTree;
//////
////////����������  �Ӽ��̽������� ��������ݹ��㷨
//////BiTree CreateBT()
//////{
//////	char ch;
//////	BiTree T;
//////
//////	scanf("%c", &ch);
//////	if (ch == '#')
//////		return NULL;
//////	else
//////	{
//////		T = (BiTree)malloc(sizeof(BiTNode));
//////		T->data = ch;
//////		T->lchild = CreateBT();
//////		T->rchild = CreateBT();
//////	}
//////
//////	return T;
//////}
////////��������ǵݹ�����㷨
//////void preOrder(BiTree T)
//////{
//////	BiTree STACK[MAX_STACK], p = T;
//////	int top = -1;
//////	while (p != NULL || top != -1)
//////	{
//////		while (p != NULL)
//////		{
//////			printf("%c ", p->data);
//////			STACK[++top] = p;
//////			p = p->lchild;
//////		}
//////		p = STACK[top--];
//////		p = p->rchild;
//////	}
//////}
////

////#define _CRT_SECURE_NO_WARNINGS
////#include <iostream>
////#include <stack>
////#define   MAX_STACK  50
////
////using namespace std;
////
////typedef struct BiTNode
////{
////	int data;
////	struct BiTNode* lchild, * rchild;
////}BiTNode, * BiTree;
////
////BiTree CreateBT()
////{
////	char ch;
////	BiTree T;
////
////	scanf("%c", &ch);
////	if (ch == '#')
////		return NULL;
////	else
////	{
////		T = (BiTree)malloc(sizeof(BiTNode));
////		T->data = ch;
////		T->lchild = CreateBT();
////		T->rchild = CreateBT();
////	}
////
////	return T;
////}
////
////void preOrder(BiTNode* root)
////{
////	if (root == NULL)
////		return;
////	printf("%d ", root->data);
////
////	preOrder(root->lchild);
////
////	preOrder(root->rchild);
////}
////
////int main(void)
////{
////	BiTree root;
////	cout << "���ʼ������";
////	root = CreateBT();
////
////	cout << "��������ǵݹ������";
////	preOrder(root);
////	return 0;
////}
////
//
//#include<iostream>
//#include<stack>
//#include<queue>
//using namespace std;
//
//typedef struct node
//{
//	int data;
//	struct node* lchild;
//	struct node* rchild;
//}Btree;
////�ǵݹ��㷨
//void PreOrder1(Btree* b)
//{
//	stack<node*>s;
//	Btree* p;
//	//if (b) s.push(b);
//	if (b)
//	{
//		while (b || !s.empty())
//		{
//			while (b)
//			{
//				cout << b->data << " ";
//				s.push(b);
//				b = b->lchild;
//			}
//			if (!s.empty())
//			{
//				p = s.top();
//				s.pop();
//				if (p->rchild) s.push(p->rchild);
//			}
//		}
//	}
//}
//void PreOrder2(Btree* b)
//{
//	stack<Btree*>s;
//	Btree* p;
//	if (b)
//	{
//		s.push(b);
//		while (!s.empty())
//		{
//			p = s.top();
//			s.pop();
//			cout << p->data << " ";
//			if (p->rchild) s.push(p->rchild);
//			if (p->lchild) s.push(p->lchild);
//		}
//	}
//}
////��������ķǵݹ����
//void InOrder(Btree* b)
//{
//	Btree* p;
//	stack<Btree*>s;
//	if (b)
//	{
//		while (b || !s.empty())
//		{
//			while (b)
//			{
//				s.push(b);
//				b = b->lchild;
//			}
//			if (!s.empty())
//			{
//				p = s.top();
//				s.pop();
//				cout << p->data << " ";
//				if (p->rchild) s.push(p->rchild);
//			}
//		}
//	}
//}
////��������ķǵݹ��㷨
//void PostOrder(Btree* b)
//{
//	Btree* p, * r;
//	stack<Btree*>s;
//	p = b;
//	bool flag;
//	do
//	{
//		while (p)
//		{
//			s.push(p);
//			p = p->lchild;
//		}
//		r = NULL;
//		flag = true;//flag == true ��ʾ���ڴ���ջ�����
//		while (!s.empty() && flag)
//		{
//			p = s.top();
//			if (p->rchild == r)//���������Ϊ�ջ����Ѿ������ʹ�
//			{
//				cout << p->data << " ";
//				s.pop();
//				r = p;
//			}
//			else
//			{
//				p = p->rchild;
//				flag = false;
//			}
//		}
//
//	} while (!s.empty());
//}
////��α���
//void LevelOrder(Btree* b)
//{
//	queue<Btree*>q;
//	Btree* p;
//	if (b)
//	{
//		q.push(b);
//		while (!q.empty())
//		{
//			p = q.back();
//			q.pop();
//			cout << p->data << " ";
//			if (p->lchild) q.push(p->lchild);
//			if (p->rchild) q.push(p->rchild);
//		}
//	}
//}
//void CreateTree(Btree*& b)
//{
//	b = new Btree;
//	b->lchild = b->rchild = NULL;
//	int x;
//	cin >> x;
//	if (x != 0)
//	{
//		b->data = x;
//		CreateTree(b->lchild);
//		CreateTree(b->rchild);
//	}
//	else b = NULL;
//}
//int main()
//{
//	Btree* b;
//	CreateTree(b);
//	cout << "��������㷨1���£�" << endl;
//	PreOrder1(b);
//	cout << "��������㷨2���£�" << endl;
//	PreOrder2(b);
//	cout << "��������㷨���£�" << endl;
//	InOrder(b);
//	cout << "����������㷨����:" << endl;
//	PostOrder(b);
//	cout << "��α������㷨���£�" << endl;
//	LevelOrder(b);
//	return 0;
//}


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include<queue>
#include<stdlib.h>
#include<stddef.h>

using namespace std;

typedef struct BiTNode
{
	int data;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;

//����������  �Ӽ��̽������� ��������ݹ��㷨
BiTree CreateBT()
{
	char ch;
	BiTree T;

	scanf("%c", &ch);
	if (ch == '#')
		return NULL;
	else
	{
		T = new BiTree;
		T->data = ch;
		T->lchild = CreateBT();
		T->rchild = CreateBT();
	}

	return T;
}

//����һ����
void  BiTree_Free(BiTNode* T)
{
	if (T != NULL)
	{
		if (T->rchild != NULL) BiTree_Free(T->rchild);
		if (T->lchild != NULL) BiTree_Free(T->lchild);
		if (T != NULL)
		{
			delete T;
			T = NULL;
		}
	}
}


//һֱ�������ҵ�������������
BiTNode* goL(BiTNode* T, stack<BiTNode*>& s)
{
	if (T == NULL)
		return NULL;
	while (T->lchild)
	{
		s.push(T);
		T = T->lchild;
	}
	return T;
}

void inOrder2(BiTNode* T) //�ǵݹ�����
{
	BiTNode* t = NULL;
	stack<BiTNode*>s;

	t = goL(T, s);

	while (t)
	{
		printf("%c ", t->data);
		//���t�������� �ظ�����
		if (t->rchild)
		{
			t = goL(t->rchild, s);  //��������������������
		}
		else if (!s.empty())  //���û��������   ����ջ��ָʾ
		{
			t = s.top();
			s.pop();
		}
		else //���t û��������   ����ջ��Ϊ��
		{
			t = NULL; //����ѭ��
		}
	}
}


//��������ݹ�
void inOrder(BiTNode* root)
{
	if (root)
	{
		inOrder(root->lchild);
		printf("%c ", root->data);
		inOrder(root->rchild);
	}
}

int main(void)
{
	BiTree root;
	root = CreateBT();

	inOrder(root);
	cout << endl;

	inOrder2(root);
	BiTree_Free(root);

	return 0;
}