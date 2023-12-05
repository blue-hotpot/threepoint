#ifndef _THREE_POINT__
#define _THREE_POINT__

#include<stdlib.h>
#include<time.h>
#include<stdio.h>

#define ROW 3
#define COL 3//column列

void Initboard(char board[ROW][COL],int row,int col);
// void Initboard(char board[ROW][COL]);
void Displayboard(char board[ROW][COL],int row,int col);
void playermove(char board[ROW][COL],int row,int col);
char judge(char board[ROW][COL],int row,int col);
void computermove(char board[ROW][COL],int row,int col);
int full(char board[ROW][COL],int row,int col);
#endif

