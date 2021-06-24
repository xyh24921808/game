#define _CRT_SECURE_NO_DEPRECATE 1
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<conio.h>
#include<stdbool.h>
int P = 0;
int map1size = 7;
int map[7][7] =
{ 1,2,2,2,2,0,2,
  0,0,2,0,2,2,2,
  2,0,2,0,2,2,0,
  2,0,0,2,2,2,2,
  2,2,0,2,2,2,2,
  2,2,0,2,2,2,2,
  2,2,0,0,0,0,0
};

void printfmap()
{
	for (int i = 0; i < map1size; i++)
	{
		for (int j = 0; j < map1size; j++)
		{
			switch (map[i][j])
			{
			case 2:
			{
				printf("|-|");
				break;
			}
			case 0:
			{
				printf("000");;
				break;
			}
			case 1:
			{
				printf("awa");
				break;
			}
			}
		}
		printf("\n");
	}
	printf("   体力值:>%d\n", P);
	printf("   提示:>每次移动体力值会消耗掉3\n");
}

void eumn()
{
	printf("-------------------------------\n");
	printf("-------------------------------\n");
	printf("------1.paly--------0.exit-----\n");
	printf("-------------------------------\n");
	printf("-------------------------------\n");
}
void eumn2()
{
	printf("-------------------------------\n");
	printf("------1.简单---------2.中等-----\n");
	printf("------3.困难---------4.地狱-----\n");
	printf("-------------------------------\n");
}

bool maptf(int row,int col)
{
	if (row >= 0 && row < map1size && col >= 0 && col < map1size && map[row][col] == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


void easymap()
{
	P = 50;
	int row = 0;
	int col = 0;
	printfmap();
	while (P >= 0 && map[map1size-1][map1size-1] != 1)
	{
		char getchar_ = 0;
		getchar_ = _getch();
		switch (getchar_)
		{
		case 'W':
		case 'w':
		case 72:
		{
			if (maptf(row-1,col))
			{
				map[row][col] = 0;
				map[--row][col] = 1;
				P -= 3;
			}
			system("cls");
			printfmap();
			break;
		}
		case 'A':
		case 'a':
		case 75:
		{
			if (maptf(row , col-1))
			{
				map[row][col] = 0;
				map[row][--col] = 1;
				P -= 3;
			}
			system("cls");
			printfmap();
			break;
		}
		case 'D':
		case 'd':
		case 77:
		{
			if (maptf(row, col + 1))
			{
				map[row][col] = 0;
				map[row][++col] = 1;
				P -= 3;
			}
			system("cls");
			printfmap();
			break;
		}
		case 'S':
		case 's':
		case 80:
		{
			if (maptf(row+1, col))
			{
				map[row][col] = 0;
				map[++row][col] = 1;
				P -= 3;
			}
			system("cls");
			printfmap();
			break;
		}
		default:
			break;
		}
	}
	if (P >= 0)
	{
		system("cls");
		printf("\n");
		printf("           you win\n");
		Sleep(2000);
	}
	else
	{
		system("cls");
		printf("\n");
		printf("           wasted\n");
		Sleep(2000);
	}
	map[0][0] = 1;
	map[map1size - 1][map1size - 1] = 0;
}


void game()
{
	int intpu = 0;
	do
	{
		eumn();
		printf("请选择:>");
		scanf("%d", &intpu);
		switch (intpu)
		{
		case 1:
		{
			system("cls");
			int test = 0;
			eumn2();
			printf("请选择难度:>");
			scanf("%d", &test);
			switch (test)
			{
			case 1:
			{
				system("cls");
				easymap();
				break;
			}
			default:
				printf("难度选择错误\n");
				break;
			}
		}
		case 0:
			printf("退出\n");
			break;
		default:
			printf("选择错误，请重选\n");
			break;
		}
	} while (intpu);
}

int main(void)
{

	game();
	return 0;
}