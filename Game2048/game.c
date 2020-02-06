#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

int a[4][4];
int empty;

void board(void)//4x4�ı��
{
	int i = 0;
	int j = 0;
	for (i = 0; i < 4; ++i)
	{          // һ������������������� 
		for (j = 0; j < 4; ++j)  // ��һ������ ÿ������֮��ռ5���� 
			printf("|    ");
		printf("|\n");

		for (j = 0; j < 4; ++j) 
		{   // �ڶ������������� 
			if (a[i][j] == 0)
				printf("|    ");
			else
				printf("|%4d", a[i][j]);
		}
		printf("|\n");

		for (j = 0; j < 4; ++j)     // ���������߼ӵ��� 
			printf("|____");
		printf("|\n");
	}
}

void init(void)//��ʼ���鲢����һ�����Ԫ��*
{
	int i, j;

	for (i = 0; i < 4; ++i)
		for (j = 0; j < 4; ++j)
			a[i][j] = 0;
	srand(time(0));
	i = rand() % 4;
	j = rand() % 4;
	a[i][j] = 2;
}

void control(void) //�����ƶ�*
{
	char ch;
	ch = getch();
	switch (ch)
	{
		case 'w':    // �����ƶ� 
		case 'W':
			to_up();
			system("cls"); //����
			add_number();
			board(); 
		break;
		case 's':    
		case 'S':
			to_down();
			system("cls"); 
			add_number();
			board();
			break;
		case 'a':    
		case 'A':
			to_left();
			system("cls");
			add_number();
			board();
			break;
		case 'd':   
		case 'D':
			to_right();
			system("cls");
			add_number();
			board();
			break;
	}
}

void to_up(void) //�Ⱥϲ����ƶ�
{
	int x = 0;
	int y = 0;
	int i = 0;
	for (y = 0; y < 4; ++y)
	{     // �������ºϲ���ͬ�ķ��� 
		for (x = 0; x < 4; ++x) 
		{
			if (a[x][y] == 0)
				;
			else 
			{
				for (i = x + 1; i < 4; ++i)
				{
					if (a[i][y] == 0)
						;
					else if (a[x][y] == a[i][y]) 
					{
						a[x][y] += a[i][y];
						a[i][y] = 0;
						++empty;
						x = i;
						break;
					}
					else 
					{
						//x = i - 1;
						break;
					}
				}
			}
		}
	}

	for (y = 0; y < 4; ++y)    // �����ƶ�����
		for (x = 0; x < 4; ++x) 
		{
			if (a[x][y] == 0)
				;
			else 
			{
				for (i = x; (i > 0) && (a[i - 1][y] == 0); --i) 
				{
					a[i - 1][y] = a[i][y];
					a[i][y] = 0;
				}
			}
		}

}

void to_down(void) 
{
	int x, y, i;

	for (y = 0; y < 4; ++y)  // ���ºϲ���ͬ�ķ��� 
		for (x = 3; x >= 0; --x) {
			if (a[x][y] == 0)
				;
			else {
				for (i = x - 1; i >= 0; --i) {
					if (a[i][y] == 0)
						;
					else if (a[x][y] == a[i][y]) {
						a[x][y] += a[i][y];
						a[i][y] = 0;
						++empty;
						x = i;
						break;
					}
					else
						break;
				}
			}
		}

	for (y = 0; y < 4; ++y)  // �����ƶ����� 
		for (x = 3; x >= 0; --x) {
			if (a[x][y] == 0)
				;
			else {
				for (i = x; (i < 3) && (a[i + 1][y] == 0); ++i) {
					a[i + 1][y] = a[i][y];
					a[i][y] = 0;
				}
			}
		}
}

void to_left(void)
{
	int x, y, i;

	for (x = 0; x < 4; ++x)   // ����ϲ���ͬ�ķ��� 
		for (y = 0; y < 4; ++y) {
			if (a[x][y] == 0)
				;
			else {
				for (i = y + 1; i < 4; ++i) {
					if (a[x][i] == 0)
						;
					else if (a[x][y] == a[x][i]) {
						a[x][y] += a[x][i];
						a[x][i] = 0;
						++empty;
						y = i;
						break;
					}
					else
						break;
				}
			}
		}

	for (x = 0; x < 4; ++x)  // �����ƶ����� 
		for (y = 0; y < 4; ++y) {
			if (a[x][y] == 0)
				;
			else {
				for (i = y; (i > 0) && (a[x][i - 1] == 0); --i) {
					a[x][i - 1] = a[x][i];
					a[x][i] = 0;
				}
			}
		}
}

void to_right(void)
{
	int x, y, i;

	for (x = 0; x < 4; ++x)  // ���Һϲ���ͬ�ķ��� 
		for (y = 3; y >= 0; --y) {
			if (a[x][y] == 0)
				;
			else {
				for (i = y - 1; i >= 0; --i) {
					if (a[x][i] == 0)
						;
					else if (a[x][y] == a[x][i]) {
						a[x][y] += a[x][i];
						a[x][i] = 0;
						++empty;
						y = i;
						break;
					}
					else
						break;
				}
			}
		}

	for (x = 0; x < 4; ++x)   // �����ƶ����� 
		for (y = 3; y >= 0; --y) {
			if (a[x][y] == 0)
				;
			else {
				for (i = y; (i < 3) && (a[x][i + 1] == 0); ++i) {
					a[x][i + 1] = a[x][i];
					a[x][i] = 0;
				}
			}
		}
}

void add_number(void) //������
{
	int temp, number;
	int x, y;

	if (empty > 0) {     // �ҳ��ո� 
		srand(time(0));
		do {
			x = rand() % 4;
			y = rand() % 4;
		} while (a[x][y] != 0);

		number = rand();
		temp = number % 2;

		if (temp == 1) {  // �ж�����������2����������4
			a[x][y] = 2;
			--empty;
		}
		if (temp == 0) {
			a[x][y] = 4;
			--empty;
		}
	}
}
