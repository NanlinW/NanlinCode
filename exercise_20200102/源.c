#include<stdio.h>
#include<math.h>
#pragma warning(disable:4996)

//��1��
//int main()
//{
//	float a = 0, b = 0, c = 0;
//	float temp = 0;//����b*b-4*a*c
//	float num = 0;//������
//	float x1 = 0, x2 = 0;//���̵ĸ�
//	printf("Enter a,b,c:");
//	scanf_s("%f %f %f", a, b, c);
//	temp = b * b - 4 * a * c;
//	num = sqrt(temp);
//
//	if (temp > 0) //������ͬʵ��
//	{
//		x1 = (-b + num) / (2 * a);
//		x2 = (-b - num) / (2 * a);
//		printf("x1=%0.2f, x2=%0.2f\n", x1, x2);//������λ���
//	}
//	if (temp == 0)//һ����ͬʵ��
//	{
//		x1 = x2 = (-b) / (2 * a);
//		printf("x1=x2=%0.2f\n", x1);//������λ���
//	}
//	if (temp < 0)//���������ʵ��
//	{
//		float n;
//		float m;
//		n = sqrt(-temp);
//		m = 2 * a;
//		printf("x1=-%0.2f+(%0.2fi)/%0.2f%s\n", b, n, m);
//		printf("x1=-%0.2f-(%0.2fi)/%0.2f%s\n", b, n, m);//������λ���
//	}
//}

//��2��
//void turn(int num)
//{
//	if (num <= 9)
//	{
//		printf("%d",num);
//	}
//	else
//	{
//		printf("%d", num % 10);
//		turn(num / 10);
//	}
//}
//
//int main()
//{
//	int number;
//	printf("Enter a number:");
//	scanf_s("%d", &number);
//	turn(number);
//	return 0;
//}

//��3��
void input(int* str, int len)
{
	int sum = 0;
	printf("������ɼ�������С��50������");
	scanf("%d\n", &len);
	for (int i = 0; i < len; i++)
	{
		scanf("%d\n", &sum);//�������
		str[i] = sum;
	}
	return str;
}

void swap(int* a, int* b)
{
	int c;
	c = *a;
	*a = *b;
	*b = c;
}

int sort(int* str,int len)//ð������
{
	int i=0,j=0;
	for (i = 0; i < len; i++)
	{
		for (j = i + 1; j < len; j++)
		{
			if (str[i] < str[j])//����
			{
				swap(&str[i], &str[j]);
			}
		}
	}

	return str;
}

void search(int* a,int len,int key)
{
		int  low, high, mid;
		low = 1;					
		high = len;				
		while (low <= high)
		{
			mid = (low + high) / 2;		

			if (key < a[mid])			
			{
				high = mid - 1;			
			}
			else if (key > a[mid])		
			{
				low = mid + 1;			
			}
			else
			{
				printf("�ҵ����±�Ϊ%d",mid);

			}
		}
		
		return 0;					
}

int main()
{
	int arr[50] = { 0 };//��ʼ������
	int num = 0;//�����ҵķ���
	int n = 0;
	input(arr, n);
	sort(arr,n);
	search(arr,n,num);

	return 0;
}