#define _CRT_SECURE_NO_WARNINGS 1

#ifndef __GAME_H__
#define __GAME_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ROW 9
#define COL 9
#define ROWS (ROW+2)
#define COLS (COL+2)
#define EASY_MODE 10  //�׵�����


int book[ROWS][COLS];

void DisplayBoard(char board[ROWS][COLS], int row, int col);
void Init(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
void setMine(char mine[ROWS][COLS], int row, int col);
int FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);//�ж���Ҳ���û��
int GetCount(char mine[ROWS][COLS], int x, int y);
void SafeMove(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);//��һ������ը��
void open(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y);
int CountShow(char show[ROWS][COLS], int row, int col);//�����ڻ��ж��ٸ���

#endif //__GAME_H__
