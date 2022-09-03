#include <iostream>
#include "mylib.h"
#include <string>
#define sl_ground 90

using namespace std;

int h = 5;
int xdino = 25, ydino = 17;
int xground = 10, yground = ydino + h;
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
	"    ^^         "
};
string tree[5]
{
	"+++",
	"+++",
	"+++",
	" + ",
	" + "
};
string die = "           X-X ";

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
		ground[0][xdino + 4 - xground] = '^';
		ground[0][xdino + 5 - xground] = '^';
	}
	else
	{
		ground[0][xdino + 4 - xground] = '_';
		ground[0][xdino + 5 - xground] = '_';
	}
	for (int i = 0; i < 3; i++)
	{
		gotoXY(xground, yground + i);
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

void drawTree(int x)
{
	int y = yground - 5;
	for (int i = 0; i < 5; i++)
	{
		gotoXY(x, y + i);
		cout << tree[i];
	}
}

void clearTree(int x)
{
	int y = yground - 5;
	for (int i = 0; i < 5; i++)
	{
		gotoXY(x + 3, y + i);
		cout << " ";
	}
}

bool checkCollide(int xtree, int x, int y)
{
	int xleft = x + 2, xright = x + 9;
	int yfoot = y + 5;
	int xtree_max = xtree + 2;
	int ytree = yground - 5;
	int ytree_max = yground;
	if ((xright >= xtree && xright <= xtree_max) || (xleft >= xtree && xleft <= xtree_max))
	{
		if (yfoot >= ytree && yfoot <= ytree_max)
			return true;
	}
	return false;
}

void deleteArray(int a[], int& n, int idx)
{
	for (int i = idx; i < n; i++)
	{
		a[i] = a[i + 1];
	}
	n--;
}

void moveTree(int tree[], int& ntree)
{
	if (tree[0] == xground)
	{
		deleteArray(tree, ntree, 0);
		clearTree(xground);
		clearTree(xground - 1);
		clearTree(xground - 2);
	}
	for (int i = 0; i < ntree; i++)
	{
		drawTree(tree[i]);
		clearTree(tree[i]);
		tree[i]--;
	}
}

void drawWall()
{
	for (int y = 2; y <= yground + 3; y++)
	{
		gotoXY(xground - 1, y);
		cout << "=";
		gotoXY(xground + sl_ground + 1, y);
		cout << "=";
	}

	for (int x = 0; x <= xground + sl_ground + 1; x++)
	{
		gotoXY(x, 2);
		cout << "=";
		gotoXY(x + 1, yground + 3);
		cout << "=";
	}
}

bool gameOver(int x, int y, int tree[], int ntree)
{
	for (int i = 0; i < ntree; i++)
	{
		if (checkCollide(tree[i], x, y))
		{
			gotoXY(x, y);
			cout << die;
			return true;
		}
	}
	return false;
}

void play()
{
	drawWall();
	int score = 0;
	int tree[100];
	int ntree = 0, cnt = 0;
	drawDino(xdino, ydino);
	initGround();
	drawGround();
	int x = xdino, y = ydino;
	int check = 2;
	while (1)
	{
		gotoXY(50, 1);
		cout << "Score: " << score++;
		if (cnt == 0)
		{
			tree[ntree++] = 95;
			cnt = rand() % 31 + 35;
		}
		if (check != 2)
		{
			drawDino(x, y);
		}
		moveTree(tree, ntree);
		if (gameOver(x, y, tree, ntree))
			break;
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
			if (check != 2)
			{
				drawDino(x, y);
				check = 2;
				jcheck = false;
			}
		}
		cnt--;
		Sleep(10);
	}
}

int main()
{
	srand(time(NULL));
	ShowCur(0);
	play();
	_getch();
}