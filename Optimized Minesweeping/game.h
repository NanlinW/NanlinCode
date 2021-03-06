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
#define EASY_MODE 10  //雷的总数


int book[ROWS][COLS];

void DisplayBoard(char board[ROWS][COLS], int row, int col);
void Init(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
void setMine(char mine[ROWS][COLS], int row, int col);
int FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);//判断玩家踩雷没有
int GetCount(char mine[ROWS][COLS], int x, int y);
void SafeMove(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);//第一步不被炸死
void open(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y);
int CountShow(char show[ROWS][COLS], int row, int col);//算现在还有多少个雷

#endif //__GAME_H__
