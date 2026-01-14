#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void menu()
{
	printf("******************************\n");
	printf("**********  1.play   *********\n");
	printf("**********  0.exit   *********\n");
	printf("******************************\n");

}

void game()
{
	char mine[ROWS][COLS] = { 0 };	//存放布置的雷
	char show[ROWS][COLS] = { 0 };	//存放标记的雷
	//mine初始化为'0'
	init_board(mine, ROWS, COLS,'0');
	//show初始化为'*'
	init_board(show, ROWS, COLS, '*');

	//设置雷
	set_mine(mine, ROW, COL);
	//display_board(mine, ROW, COL);
	display_board(show, ROW, COL);

	//排查雷
	find_mine(mine, show, ROW, COL);
}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while(input);

	return 0;
}