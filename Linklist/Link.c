#include"Link.h"
#include<stdio.h>
#include<assert.h>
#include<malloc.h>


//void Initlist(LinkNode* head)
//{
//	assert(head);
//	head->next = NULL;
//}

LinkNode* BuyLinkNode(DataType data)//�����½ڵ�
{
	LinkNode* newNode = (LinkNode*)malloc(sizeof(LinkNode));
	if (NULL == newNode)
	{
		printf("����ڵ�ʧ��");
		assert(newNode);
	}
	newNode->data = data;
	newNode->next = NULL;

	return newNode;
}

//head�е����ݾ���&L
//���Ҫ�ı�ʵ��L��ָ��*head�������L����
//ע���������������ڵ�����
//�������������Ѿ����ڣ�û����Ч�Ľڵ�
//�������ڣ���û��ͷָ��
void PushBack(LinkNode** head, DataType data)//β��
{
	assert(head);//���������Ƿ����
	LinkNode* newNode = BuyLinkNode(data);

	//��������Ƿ�Ϊ������(û���κνڵ������)
	if (*head == NULL)
	{
		*head = newNode;//��һ���ڵ�Ĳ��뷽ʽ
	}
	else//�����ڵ�Ĳ��뷽ʽ
	{
		//1.�ҵ����һ���ڵ�
		LinkNode* tail = *head;
		while (tail->next)//�ж�tail����Ϊ��Ϊ�գ�Ϊ��������ѭ��
		{
			tail = tail->next;//��Ϊ��������������
		}

	   //2.�����һ���ڵ��next��ָ���½��
		tail->next = newNode;
	}

}

void PopBack(LinkNode** head)//βɾ
{
	assert(head);
	//�ҵ����һ���ڵ㣬free�����õ����ڶ����ڵ��next��ָ��NULL
	LinkNode* slow = *head;//�ҵ����ڶ����ڵ�
	LinkNode* fast = *head;//�����һ���ڵ�
	fast = fast->next;
	while (fast->next)
	{
		slow = slow->next;
		fast = fast->next;
	}
	slow->next = NULL;
	free(fast);
}

void PushFront(LinkNode** head, DataType data)//ͷ��
{
	assert(head);
	LinkNode* newNode = BuyLinkNode(data);
	LinkNode* front = *head;
	//�����һ���ڵ�
	if (*head == NULL)
	{
		front->next = newNode;
		newNode->next = NULL;
	}
	else
	{
		newNode->next = front->next;
		front->next = newNode;
	}
}
void PopFront(LinkNode** head)//ͷɾ
{
	assert(head);
	LinkNode* first = *head;
	LinkNode* second = *head;
	LinkNode* front = *head;
	first = first->next;
	second = second->next->next;
	front->next = second;
	free(first);
}

//////////////////////////////////////////////////
void PrintLinklist(LinkNode* head)//��ӡ����
{
	assert(head);
	LinkNode* print = head;
	while (print)
	{
		printf("%d->", print->data);
		print = print->next;
	}
	printf("NULL");
	printf("\n");
}

//////////////////////////////////////////////////
void Testlist1()
{
	LinkNode* L = NULL;
	//Initlist(L);
	PushBack(&L, 1);
	PushBack(&L, 2);
	PushBack(&L, 3);
	PushBack(&L, 4);
	PushBack(&L, 5);
	//PopBack(&L);
	//PushFront(&L, 1);
	//PopFront(&L);
	PrintLinklist(L);
}

void Testlist()
{
	Testlist1();
}