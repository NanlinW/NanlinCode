//0-1�������⶯̬�滮�ⷨ
#include<iostream>
#include<time.h>
#include<map>
using namespace std;
int main()
{
	//��5��12������4��3������7��10������2��3������6��6����������15
	int f[6][16] = { 0 };
	int application[6][16];
	int weight[5] = { 5,4,7,2,6 };
	int value[5] = { 12,3,10,3,6 };
	clock_t start, end;
	int n = 10000;
	start = clock();
	while (n--)
	{
		for (int i = 1; i < 6; i++)
		{
			for (int j = 1; j < 16; j++)
			{
				if (j - weight[i - 1] >= 0)
				{
					if (f[i - 1][j] > f[i - 1][(j - weight[i - 1])] + value[i - 1])
					{
						f[i][j] = f[i - 1][j];//����
						application[i][j] = 0;
					}
					else
					{
						f[i][j] = f[i - 1][(j - weight[i - 1])] + value[i - 1];
						application[i][j] = 1;
					}
					//f[i][j] = f[i - 1][j] > f[i - 1][(j - weight[i - 1])] + value[i - 1] ? f[i - 1][j] : f[i - 1][(j - weight[i - 1])] + value[i - 1];
				}
				else
				{
					f[i][j] = f[i - 1][j];//����
					application[i][j] = 1;
				}

			}
		}
	}

	cout << "��̬�滮����" << endl;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			cout << f[i][j] << " ";
		}
		cout << endl;
	}
	cout << "���뱳������Ʒ�У�" << endl;
	int j = 15;
	//��һ�ֵõ����巽���ķ�����
	for (int i = 5; i > 0; i--)
	{
		if (f[i][j] != f[i - 1][j])
		{
			cout << "��Ʒ" << i << "���뱳��" << endl;
			j = j - weight[i - 1];
		}
	}

	return 0;
}