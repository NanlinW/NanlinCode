//Ӳ���������⶯̬�滮�㷨
#include<stdio.h>
#include<stdlib.h>
int coin[3] = { 1, 3, 5 };			/* Ӳ������	*/
int coin_kind_num = 3;				/* Ӳ���������� */
int sum = 7;						/* ����Ǯ�� */
int min_coin_num;					/* Ӳ�������� */
int coin_kind[1000];				/* ����������ķ��� */
bool is_find = false;				/* �Ƿ��ҵ�Ӳ�� */

/*  ��������ӡ����
	��ӡ������㷽���� ����coin_kind[]
*/
bool output() {
	for (int i = 0; i < 1000; i++)
	{
		if (coin_kind[i] == -1) break;
		printf("   %d ", coin_kind[i]);

	}
	printf("\n");

	return coin_kind;
}

/* 	��������ʼ����������
	��ʼ��������㷽�������� ��ʹԪ��ȫ��Ϊ 0���Ա��ж����
*/
void initCoinKind() {
	for (int i = 0; i < 100; i++) coin_kind[i] = -1;
}

/* ���������һ�������
   �ú������ڸ��� ָ��Ӳ���� �� ָ��Ӧ�����Ǯ�������Ƿ����ҿ����õĻ��ݷ�����.
   ˼���� �����ڶ��ڸ���Ӧ�����Ǯ�� sum����������Ӳ���� num������� sum - coin[i] ( i = 0, ..., coin_kind_num - 1)
   ��Ȼ��������Ӳ���� num - 1, ������ ���·���Ǹ� dijkstra�㷨 ��

   @param   num    ָ��Ӳ����
   @param   sum    ָ��Ӧ�����Ǯ��
 */
bool findCoin(int num, int sum) {

	/* �����߼�

		�� ����ָ��Ӳ����Ϊ 0 , ����ʱ�ѵ��ڴ��߽磬����ʱӲ����
			���� 0 ��˵���Ѿ��ҿ����ҵ���������ֵ is_find = true ( ��Ϊ ����������ֹ���� )��
			���� 0 ��˵��δ�ҿ��� ��ʱʣ��Ӧ�ҿ�������0��
			С�� 0 , ˵����ʱʣ����С�� 0�������㡣
		�� ����ָ�����Ӳ���� ��Ϊ 0���� ���� 0����˵����ʱδ��Ѱ�ִ꣬��
			�������Ӳ����������� coin[]�� ����ǰ�������� ��ŵ� *ָ���±�* ��
			���㷽������ coin_kind[] �С��ݹ�ִ�� �ú�����Ӳ���� - 1��Ӧ������ - ��������Ӳ��ֵ

	*/

	if (num == 0)
	{
		if (sum == 0) {
			is_find = true;
			printf("�ҵ�����Ӳ���� %d: ", min_coin_num);
			output();
			return true;
		}
		else if (sum > 0) {

			return false;
		}
		else {

			return false;
		}
	}
	else
	{
		for (int i = 0; i < coin_kind_num; i++)
		{
			coin_kind[num - 1] = coin[i];
			findCoin(num - 1, sum - coin[i]);
		}
	}
}

/* 	������Ӳ������ + 1 ����
	���ڲ��ҷ�����������ֻ�ܸ���ָ��Ӳ���� num ��ָ�������� sum��
	���� Ӧ��ʹ��ָ��Ӳ������С���� �� 1 ��ʼ��ÿ�β�������ж� is_find ��ֵ��
	��Ϊ false �� num + 1����������
	���� �˳�ѭ��������ϡ�

 */
bool startFind() {
	int num = 1;
	while (!is_find) {
		min_coin_num = num;
		findCoin(num, sum);
		num++;
	}

	return is_find;
}
int main() {
	initCoinKind();		/* ��ʼ����ŷ��������� */
	startFind();
}
