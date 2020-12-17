#ifndef SQQUEUE_H  
#define SQQUEUE_H  

#define MAXQSIZE 10                                                     //���е���󳤶�  

typedef int QElemType;

typedef struct
{
	QElemType* base;                                                //��ʼ���Ķ�̬����洢�ռ�  
	int front;                                                              //ͷָ�룬�����в��գ�ָ�����ͷԪ��  
	int rear;                                                               //βָ�룬�����в��գ�ָ�����βԪ�ص���һ��λ��  
}SqQueue;

bool InitQueue(SqQueue& Q);                                  //��ָ����С����һ��˳��ն���Q  
int QueueLength(SqQueue& Q);                               //����Q��Ԫ�صĸ����������г���  
bool EnQueue(SqQueue& Q, QElemType e);            //����Ԫ��eΪQ���µĶ�βԪ��  
bool DeQueue(SqQueue& Q, QElemType& e);         //��ͷԪ�س�����  
void PrintSqQueue(SqQueue& Q);                           //��ӡ˳�����  
bool QueueEmpty(SqQueue& Q);                            //�жϸ����Ķ����Ƿ�Ϊ�ն���  

#endif  /* SqQueue.h */  
