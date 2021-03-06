#pragma once
#include <stdio.h>
#include <malloc.h>
#include <assert.h>

typedef int LTDataType;

typedef struct ListNode
{
	LTDataType _data;
	struct ListNode* _next;
	struct ListNode* _prev;
}ListNode;

typedef struct List
{
	ListNode* _head;
}List;

void ListInit(List* plt);
void ListDestroy(List* plt);

void ListPushBack(List* plt, LTDataType x);
void ListPushFront(List* plt, LTDataType x);
void ListPopBack(List* plt);
void ListPopFront(List* plt);

ListNode* ListFind(List* plt, LTDataType x);
// 在pos之前插入x
void ListInsert(ListNode* pos, LTDataType x);
// 删除pos位置的节点
void ListErase(ListNode* pos);

void ListPrint(List* plt);


