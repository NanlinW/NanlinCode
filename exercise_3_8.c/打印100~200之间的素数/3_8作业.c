//��ӡ100~200֮�������
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i = 0;
	for (i = 100;i <= 200;i++)
	{
		int  j = 0;
		for (j = 2;j <= i;j++)
		{
			if (i%j == 0)
			{
				break;
			}
		}
		if (i == j)
		{
			printf("%d ", i);
		}

	}
	system("pause");
	return 0;;
}

//����˷��ھ���
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i, j, k;
	int n = 9;
	for (i = 1;i <= n;i++)
	{
		for (j = 1;j <= i;j++)
		{
			k = i * j;
			printf("%d*%d=%d\n", i, j, k);
		}
	}
	system("pause");
		return 0;
}


//�ж�1000��---2000��֮�������
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int year;
		int count = 0;
		for (year = 1000;year <= 2000;year++)
		{
			if (((year % 4) == 0 && (year % 100)!= 0) || (year %400) == 0)
			{
				printf("%d ", year);
				count++;
			}
		}
		system("pause");
		return 0;

}