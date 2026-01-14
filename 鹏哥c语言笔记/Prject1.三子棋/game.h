#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3

//初始化棋盘
void init_board(char board[ROW][COL], int row, int col);

//打印棋盘
void display_board(char board[ROW][COL], int row, int col);

//玩家下棋
void player_move(char board[ROW][COL], int row, int col);

//电脑下棋
//找未被占的位置随机下棋
void computer_move(char board[ROW][COL], int row, int col);

//判断输赢
//玩家赢-'*'
//电脑赢-'#'
//平局-'Q'
//继续-'C'
char is_win(char board[ROW][COL], int row, int col);

