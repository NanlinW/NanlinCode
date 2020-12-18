//#include <stdio.h>
//#include <stdlib.h>
//#define NULL 0
//#define M 100 
//typedef struct node
//{
//	int data;
//	int cishu;
//	struct node* lchild;
//	struct node* rchild;  //���ڵ���cishu��Ϊ�˼����á��ں�������У������ĸ��ڵ��ڵ�һ�α�����ʱ�򲻻������ֻ���ڵڶ��α�����ʱ��������
//}bitree;
//
//
//typedef struct stack
//{
//	bitree* elements[M];
//	int top;
//}seqstack;//����һ�����������͵�ַ��ջ�����������ʱ��׷�ٵ����ĵ�ַ��
//
//bitree* root;//����һ������
//seqstack s;//����ջ
//
//void setnull()//��ʼ��ջ
//{
//	s.top = 0;
//}
//
//void push(bitree* temp)//��ջ����
//{
//	s.elements[s.top++] = temp;
//}
//
//bitree* pop()//ȡջ������ջ��
//{
//	return s.elements[--s.top];
//}
//
//int empty()//�жϿ�ջ
//{
//	return s.top == 0;
//}
//
//bitree* creat()   /*�����������ĵݹ��㷨*/
//{
//	bitree* t;
//	int x;
//	scanf_s("%d", &x);
//	if (x == 0) t = NULL; /*��x=0��ʾ�������*/
//	else {
//		t = (bitree*)malloc(sizeof(bitree));//��̬���ɽ��t,�ֱ�����t�����������Һ�����  
//		t->data = x;                  //��ֵ,�����Һ�����ֵʱ�õ��˵ݹ��˼�롣
//		t->lchild = creat();
//		t->rchild = creat();
//	}
//	return t;
//}
//
//
//void inorder(bitree* t)//��������ķǵݹ��㷨
//{
//	bitree* temp = t;
//	while (temp != NULL || s.top != 0)
//	{
//		while (temp != NULL)//�Ȱ�������ջ������������ջ����
//		{
//			push(temp);
//			temp = temp->lchild;
//		}
//		if (s.top != 0)//������ջ������ȡջ�������ջ��Ԫ�أ������Һ���
//		{
//			temp = pop();
//			printf("%4d", temp->data);
//			temp = temp->rchild;
//		}
//	}
//	printf("\n");
//}
//
//
//
//
//int main()
//{
//	bitree* root;//������
//	setnull();//�ƿ�ջ
//	printf("�봴��һ�Ŷ�������\n");
//	root = creat();//����������:�������룺1 2 3 0 0 4 0 0 5 6 0 0 7 0 0
//
//	printf("�������:\n");
//	inorder(root);
//
//	return 0;
//}

#include<stdio.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define TRUE 1
#define FALSE 0
#define SIZEINIT 10
#define INCRESIZE 5

typedef int Status;
typedef char TElemType;

typedef struct node {
	TElemType data;
	struct node* lchild, * rchild;
}BiTNode, * BiTree;

//ǰ�򴴽�������
void CreateBiTree(BiTree& T) {
	char ch;
	scanf_s("%c", &ch);
	if (ch == '#') {
		T = NULL;
	}
	else {
		T = (BiTree)malloc(sizeof(struct node));
		T->data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
}

//ǰ�����
Status PreOrderTraverse(BiTree T, Status(*Visit)(TElemType e)) {
	if (T) {
		if (Visit(T->data)) {
			if (PreOrderTraverse(T->lchild, Visit)) {
				if (PreOrderTraverse(T->rchild, Visit)) return OK;
			}
		}
		return ERROR;
	}
	return OK;
}

//�������
Status InOrderTraverse(BiTree T, Status(*Visit)(TElemType e)) {
	if (T) {
		if (InOrderTraverse(T->lchild, Visit)) {
			if (Visit(T->data)) {
				if (InOrderTraverse(T->rchild, Visit)) return OK;
			}
		}
		return ERROR;
	}
	return OK;
}

//�������
Status PostOrderTraverse(BiTree T, Status(*Visit)(TElemType e)) {
	if (T) {
		if (PostOrderTraverse(T->lchild, Visit)) {
			if (PostOrderTraverse(T->rchild, Visit)) {
				if (Visit(T->data)) return OK;
			}
		}
		return ERROR;
	}
	return OK;
}

//���ʺ���
Status Visit(TElemType e) {
	printf("%c", e);
	return OK;
}

int main() {
	BiTree T = NULL;
	printf("��ǰ�򴴽���һ����(��λ����'#'������)\n");
	CreateBiTree(T);
	printf("\n������ǰ������Ľ��\n");
	PreOrderTraverse(T, Visit);
	printf("\n��������������Ľ��\n");
	InOrderTraverse(T, Visit);
	printf("\n��������������Ľ��\n");
	PostOrderTraverse(T, Visit);
	printf("\n");
	return 0;
}
//AB#D##CE###

