#pragma once
//��ͷ������
typedef int DataType;

typedef struct LinkNode
{
	int data;
	struct LinkNode* next;
}LinkNode;

//typedef struct LinkNode LinkNode;//������治ʹ��typedef����ͼ���

//void InitLinklist(LinkNode* head);//��ʼ������
void PushBack(LinkNode** head,DataType data);//β��
void PopBack(LinkNode** head);//βɾ
void PushFront(LinkNode** head, DataType data);//ͷ��
void PopFront(LinkNode** head);//ͷɾ

//////////////////////////
void PrintLinklist(LinkNode* head);//��ӡ����
void Testlist();//���Ժ���