//#include<iostream>
//#include<string>
//using namespace std;
//
//class Solution {
//public:
//	void replaceSpace(char* str, int length)
//	{
//		for (int i = 0; i < length; i++)
//		{
//			if (arr[i] == '\0')
//			{
//				arr[i] = '%20';
//			}
//		}
//	}
//};
//
//int main()
//{
//
//
//	char arr[] = "We Are Happy";
//	len = strlen(arr);
//	replaceSpace(arr, len);
//	cout << arr[] << endl;
//	return 0;
//}

#include<stdio.h>
#include<string.h>
#include<stdlib.h>




//int main()
//	{
//		int a, b, c, m, t;
//		scanf_s("%d%d", &a, &b);
//		if (a < b)
//		{
//			t = a;
//			a = b;
//			b = t;
//		}
//		m = a * b;
//		c = a % b;
//		while (c != 0)
//		{
//			a = b;
//			b = c;
//			c = a % b;
//		}
//		printf( "%d\n",m/b);
//		return 0;
//}


#include<stdio.h>
#include<string.h>

//���ַ�����ch��n���ַ�����
void invert(char* ch, int n)
{
	int i;
	char temp;
	for (i = 0; i < n / 2; i++)
	{
		temp = ch[i];
		ch[i] = ch[n - 1 - i];
		ch[n - 1 - i] = temp;
	}
}

//�ֽ��ַ���ȫ�����ã������ú���ַ��������ַ��������á������ַ����Ļ�������Ϊ�Ƿ��пո�
void wordInvertInSentence(char* ch)
{
	int i = 0;
	int len;
	len = strlen(ch);
	invert(ch, len);//���ַ���ȫ������
	while (ch[i] != '\0')//���ַ�����ʼλ�ÿ�ʼ������ֱ�����ʵ�������
	{
		i = 0;
		while (ch[i] != ' ' && ch[i] != '\0') { i++; }//�����ǰ���ַ���Ϊ�ո���û�з��ʵ�������־����ָ����ƣ�ֱ����ǰ�ַ�Ϊ�ո�
		invert(ch, i);//�ַ���ch��i���ַ���������
		if (ch[i] != '\0')//���û�з��ʵ�������־��Ҫ�����ո��ַ������������¸�����
			ch = ch + i + 1;
		else           //�����ǰ�ַ��Ѿ��ǽ�����־�ˣ�����Ҫ�������ո��ַ�����ѭ��������
			ch = ch + i;
	}
}

int main()
{
	char str[100] = "I like beijing.";//
	wordInvertInSentence(str);
	printf("%s", str);
	printf("\n");
}
