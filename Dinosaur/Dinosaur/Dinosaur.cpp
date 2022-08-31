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
string space = "                ";
string dino[6] =
{
	"           o-o ",
	"         /(\\_/)",
	".___.---' /`-' ",
	" `-._.  )/,,   ",
	"     //        ",
	"    ^^         ",
};

void drawDino(int x, int y)
{
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
	if (jcheck == false)
	{
		ground[0][xdino + 4 - xdat] = '^';
		ground[0][xdino + 5 - xdat] = '^';
	}
	else 
		{
		ground[0][xdino + 4 - xdat] = '_';
		ground[0][xdino + 5 - xdat] = '_';
	}
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
	drawDino(xdino, ydino);
	initGround();
	drawGround();
	int x = xdino, y = ydino;
	int check = 2;
	while (1)
	{
		if (check != 2)
		{
			drawDino(x, y);
		}
		moveGround();
		if (_kbhit())
		{
			char c = _getch();
			if (c == -32)
			{
				c = _getch();
				if (c == 72 && check == 2)
				{
					check = 1;
					jcheck = true;
				}
			}
		}
		if (check == 1)
		{
			gotoXY(x, y + h);
			cout << space;
			y--;
		}
		else if (check == 0)
		{
			gotoXY(x, y);
			cout << space;
			y++;
		}
		if (y == ydino - jump)
		{
			check = 0;
		}
		else if (y == ydino)
		{
			drawDino(x, y);
			check = 2;
			jcheck = false;
		}
		Sleep(10);
	}
}

int main()
{
	play();
	_getch();
}