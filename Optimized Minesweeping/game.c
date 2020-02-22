#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void Init(char board[ROWS][COLS], int row, int col, char ch)
{
	memset(&board[0][0], ch, row * col * sizeof(board[0][0]));
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;

	//��ӡ������
	printf("0 ");
	for (i = 1; i < row - 1; i++)
	{
		printf("%d ", i);
	}
	printf("\n");

	for (i = 1; i < row - 1; i++)
	{
		printf("%d ", i);

		for (j = 1; j < col - 1; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");

	}
}

void setMine(char mine[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int count = EASY_MODE;


	while (count)
	{
		//������Ҫ9�����֣����%10��������0~8�� 9������
		//����������Ҫ1~9��������%9����8�����֣��ټ�1�ͺ�
		x = rand() % 9 + 1;
		y = rand() % 9 + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}

//�ȵ��׷���1��û�вȵ��׷���0
int FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int count = 0;


	printf("��������ѡ������꣺");
	scanf("%d%d", &x, &y);

	if (x < 1 && x > COL && y < 1 && y > ROW)
	{
		printf("����������곬����ǰ��ͼ�����������룡\n");

	}
	else
	{
		if (mine[x][y] == '0')
		{
			char ch = GetCount(mine, x, y);
			show[x][y] = ch + '0';
			book[x][y] = 1;
			open(mine, show, x, y);
			if (CountShow(show, row, col) == EASY_MODE)
			{
				return 0;
			}
		}
		else if (mine[x][y] == '1')
		{
			return 1;
		}

	}
	return 0;
}

int GetCount(char mine[ROWS][COLS], int x, int y)
{
	int count = 0;
	//�ֱ��(x,y)������Χ8�����ӽ����жϣ����������count + 1
	//��󷵻�count����(x,y)��Χ�ĵ��׸���
	if (mine[x - 1][y] == '1')
		count++;
	if (mine[x - 1][y - 1] == '1')
		count++;
	if (mine[x][y - 1] == '1')
		count++;
	if (mine[x + 1][y - 1] == '1')
		count++;
	if (mine[x + 1][y] == '1')
		count++;
	if (mine[x + 1][y + 1] == '1')
		count++;
	if (mine[x][y + 1] == '1')
		count++;
	if (mine[x - 1][y + 1] == '1')
		count++;

	return count;
}

//SafeMove�����Ǳ�֤��������һ������ʱ����ը��
void SafeMove(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int flag = 1;
	int count = 0;
	char ch = 0;

	while (1)
	{
		printf("��������Ҫѡ������꣺");
		scanf("%d%d", &x, &y);

		if (x < 1 && x > COL && y < 1 && y > ROW)
		{
			printf("����������곬����ǰ��ͼ�����������룡\n");
			continue;
		}

		if (mine[x][y] == '1')
		{
			//�����������������1����ǿ�а���������Ϊ0
			mine[x][y] = '0';
			char ch = GetCount(mine, x, y);
			show[x][y] = ch + '0';
			book[x][y] = 1;
			open(mine, show, x, y);
			//��һ�����׸�Ϊ�˿յأ�����Ҫ�������һ����
			while (flag)
			{
				x = rand() % 9 + 1;
				y = rand() % 9 + 1;
				if (mine[x][y] == '0')
				{
					mine[x][y] = '1';
					flag--;
					break;
				}
			}break;
		}
		else if (mine[x][y] == '0')
		{
			char ch = GetCount(mine, x, y);
			show[x][y] = ch + '0';
			book[x][y] = 1;
			open(mine, show, x, y);
			break;
		}

	}

}

//��������������������չ��
void open(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{

	int tx = 0;
	int ty = 0;
	int k = 0;
	//����next���飬�������ĸ������������
	int next[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };

	//��չ����ʱ�����GetCount�������صĲ���0�����show���鸳���ص�ֵ
	if (GetCount(mine, x, y) != 0)
	{
		show[x][y] = GetCount(mine, x, y) + '0';
	}
	//�����0����show�����Ǹ�λ�ø��ո�
	else if (GetCount(mine, x, y) == 0)
	{
		show[x][y] = ' ';
	}

	for (k = 0; k <= 3; k++)
	{
		tx = x + next[k][0];
		ty = y + next[k][1];

		if (tx < 1 || tx > ROW || ty < 1 || ty > COL)
		{
			continue;
		}
		if (mine[tx][ty] == '0' && book[tx][ty] == 0 && GetCount(mine, tx, ty) < 1)
		{

			book[tx][ty] = 1;
			open(mine, show, tx, ty);

		}
		//��һ���ܹؼ�����չ��ʱ��������ͣ������һ��
		if (mine[tx][ty] == '0' && book[tx][ty] == 0 && GetCount(mine, tx, ty) > 0)
		{
			show[tx][ty] = GetCount(mine, tx, ty) + '0';
			continue;
		}

	}
	return;
}

//ͳ�������ʣ�µ�'*'
int CountShow(char show[ROWS][COLS], int row, int col)//�ж�ʣ��δ֪����ĸ���������Ϊ����ʱ���Ӯ
{
	int count = 0;
	int i = 0;
	int j = 0;
	for (i = 1; i < row - 1; i++)
	{
		for (j = 1; j < col - 1; j++)
		{
			if (show[i][j] == '*')
			{
				count++;
			}
		}

	}
	return count;
}