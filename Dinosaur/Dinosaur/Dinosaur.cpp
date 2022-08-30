#include <iostream>
#include "mylib.h"
#include <string>
#define sl_ground 90

using namespace std;

int h = 5;
int xdino = 25, ydino = 17;
int xdat = 10, ydat = ydino + h;
int jump = 14;
bool jcheck = false;
char ground[3][sl_ground + 1];
string dino[6] =
{
	"           o-o ",
	"         /(\\_/)",
	".___.---' /`-' ",
	" `-._.  )/,,   ",
	"     //        ",
	"    ^^         ",
};

void drawDino()
{
	int x = xdino;
	int y = ydino;
	for (int i = 0; i < h + 1; i++)
	{
		gotoXY(x, y);
		cout << dino[i];
		y++;
	}
}

void genGround(int i)
{
	int v = rand() % 15 + 1;
	switch (v)
	{
	case 1:
	{
		ground[1][i] = '.';
		ground[2][i] = ' ';
		break;
	}
	case 2:
	{
		ground[1][i] = '-';
		ground[2][i] = ' ';
		break;
	}
	case 3:
	{
		ground[1][i] = '`';
		ground[2][i] = ' ';
		break;
	}
	case 4:
	{
		ground[1][i] = 248;
		ground[2][i] = ' ';
		break;
	}
	case 5:
	{
		ground[1][i] = ' ';
		ground[2][i] = '.';
		break;
	}
	case 6:
	{
		ground[1][i] = ' ';
		ground[2][i] = '-';
		break;
	}
	case 7:
	{
		ground[1][i] = ' ';
		ground[2][i] = '`';
		break;
	}
	default:
	{
		ground[1][i] = ' ';
		ground[2][i] = ' ';
		break;
	}
	}
}

void initGround()
{
	for (int i = 0; i < sl_ground; i++)
	{
		ground[0][i] = '_';
		genGround(i);
	}
	ground[0][sl_ground] = '\0';
	ground[1][sl_ground] = '\0';
	ground[2][sl_ground] = '\0';
}

void drawGround()
{
	for (int i = 0; i < 3; i++)
	{
		gotoXY(xdat, ydat + i);
		cout << ground[i];
	}
}

void moveGround()
{
	for (int i = 0; i < sl_ground - 1; i++)
	{
		ground[1][i] = ground[1][i + 1];
		ground[2][i] = ground[2][i + 1];
	}
	genGround(sl_ground - 1);
	drawGround();
}

void play()
{
	drawDino();
	initGround();
	drawGround();

	while (1)
	{
		moveGround();
		Sleep(10);
	}
}

int main()
{
	play();
	_getch();
}