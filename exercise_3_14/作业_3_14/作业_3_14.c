#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int line = 13;
	int i = 0;
	int j = 0;
	int k = 0;
	//��ӡ�ϰ벿�֣������ǣ�
	for (i = 0; i < line; i++)
	{
		//��ӡ��ʼ�Ŀո�
		for (j = 0; j < line - 1 - i; j++)
		{
			printf(" ");
		}
		//��ӡ*
		for (k = 0; k < i * 2 + 1; k++)
		{
			printf("*");
		}
		printf("\n");
	}
	//��ӡ�°벿�֣������ǣ�
	for (i = 0; i < line; i++)
	{
		//��ӡ��ʼ�Ŀո�
		for (j = 0; j <= i; j++)
		{
			printf(" ");
		}
		//��ӡ*
		for (k = 0; k < 2 * (line - 2 - i) + 1; k++)
		{
			printf("*");
		}
		printf("\n");
	}
	system("pause");
	return 0;
}


int main()

{
	int i = 0;

	int a = 0;

	int sum = 0;

	int num = 0;

	scanf("%d", &num);

	for (i = 0; i < 5; i++)

	{

		a = a * 10 + num;

		sum = sum + a;

	}

	printf("%d", sum);
	system("pause");

	return 0;

}



int main()
{
	int i = 0;
	int a = 0;
	int b = 0;
	int c = 0;
	for (i = 100;i <= 999;i++)
	{
		a = i % 10;       //��λ
		c = i / 10 % 10;  //ʮλ
		b = i / 100;      //��λ
		if (i == a * a*a + b * b*b + c * c*c)
		{
			printf("%d ", i);
		}
	}
	system("pause");
	return 0;
}