#include <iostream>
#include "mylib.h"
#define MAX 100

using namespace std;

int s = 4;

void ve_tuong_tren()
{
	int x = 10, y = 1;
	while (x <= 100)
	{
		gotoXY(x, y);
		cout << "+";
		x++;
	}
}

void ve_tuong_duoi()
{
	int x = 10, y = 26;
	while (x <= 100)
	{
		gotoXY(x, y);
		cout << "+";
		x++;
	}
}

void ve_tuong_trai()
{
	int x = 10, y = 1;
	while (y <= 26)
	{
		gotoXY(x, y);
		cout << "+";
		y++;
	}
}

void ve_tuong_phai()
{
	int x = 100, y = 1;
	while (y <= 26)
	{
		gotoXY(x, y);
		cout << "+";
		y++;
	}
}

void ve_tuong()
{
	SetColor(11);
	ve_tuong_tren();
	ve_tuong_duoi();
	ve_tuong_trai();
	ve_tuong_phai();
	SetColor(7);
}

void khoi_tao_ran(int toadox[], int toadoy[])
{
	int x = 50, y = 13;
	for (int i = 0; i < s; i++)
	{
		toadox[i] = x;
		toadoy[i] = y;
		x--;
	}
}

void ve_ran(int toadox[], int toadoy[])
{
	for (int i = 0; i < s; i++)
	{
		gotoXY(toadox[i], toadoy[i]);
		if (i == 0)
		{
			cout << '0';
		}
		else
		{
			cout << 'o';
		}
	}
}

void xoa_du_lieu_cu(int toadox[], int toadoy[])
{
	for (int i = 0; i < s; i++)
	{
		gotoXY(toadox[i], toadoy[i]);
		cout << ' ';
	}
}

void them(int a[], int x)
{
	for (int i = s; i > 0; i--)
	{
		a[i] = a[i - 1];
	}
	s++;
	a[0] = x;
}

void xoa(int a[], int x)
{
	for (int i = x; i < s; i++)
	{
		a[i] = a[i + 1];
	}
	s--;
}

bool kt_ran_cham_tuong(int x0, int y0)
{
	if (y0 == 1 && (x0 >= 10 && x0 <= 100))
	{
		return true;
	}
	else if (y0 == 26 && (x0 >= 10 && x0 <= 100))
	{
		return true;
	}
	else if (x0 == 100 && (y0 >= 1 && y0 <= 26))
	{
		return true;
	}
	else if (x0 == 10 && (y0 >= 1 && y0 <= 26))
	{
		return true;
	}
	return false;
}

bool kt_ran_cham_duoi(int toadox[], int toadoy[])
{

	for (int i = 1; i < s; i++)
	{
		if ((toadox[0] == toadox[i]) && (toadoy[0] == toadoy[i]))
		{
			return true;
		}
	}
	return false;
}

bool kt_ran_de_qua(int xqua, int yqua, int toadox[], int toadoy[])
{
	for (int i = 1; i < s; i++)
	{
		if ((xqua == toadox[i]) && (yqua == toadoy[i]))
		{
			return true;
		}
	}
	return false;
}

void tao_qua(int& xqua, int& yqua, int toadox[], int toadoy[])
{
	do
	{
		xqua = rand() % 89 + 11;
		yqua = rand() % 24 + 2;

	} while (kt_ran_de_qua(xqua, yqua, toadox, toadoy));
	int i = rand() % 15 + 1;
	SetColor(i);
	gotoXY(xqua, yqua);
	cout << "$";
	SetColor(7);
}

bool kt_ran_an_qua(int xqua, int yqua, int x0, int y0)
{
	if ((x0 == xqua) && (y0 == yqua))
	{
		return true;
	}
	return false;
}

void xu_ly_ran(int toadox[], int toadoy[], int x, int y, int& xqua, int& yqua)
{
	them(toadox, x);
	them(toadoy, y);
	if (!kt_ran_an_qua(xqua, yqua, toadox[0], toadoy[0]))
	{
		xoa(toadox, s - 1);
		xoa(toadoy, s - 1);
	}
	else
	{
		s--;
		tao_qua(xqua, yqua, toadox, toadoy);
	}
	ve_ran(toadox, toadoy);
}

int main()
{
	ShowCur(false);
	srand(time(NULL));
	bool gameover = false;
	int toadox[MAX], toadoy[MAX];
	int x = 50, y = 13, xqua = 0, yqua = 0, check = 2;

	ve_tuong();
	khoi_tao_ran(toadox, toadoy);
	ve_ran(toadox, toadoy);
	tao_qua(xqua, yqua, toadox, toadoy);

	while (gameover == false)
	{
		xoa_du_lieu_cu(toadox, toadoy);
		if (_kbhit())
		{
			char chr = _getch();
			if (chr == -32)
			{
				chr = _getch();
				if (chr == 72 && check != 0)
				{
					check = 1;
				}
				else if (chr == 80 && check != 1)
				{
					check = 0;
				}
				else if (chr == 77 && check != 3)
				{
					check = 2;
				}
				else if (chr == 75 && check != 2)
				{
					check = 3;
				}
			}
		}

		if (check == 0)
		{
			y++;
		}
		else if (check == 1)
		{
			y--;
		}
		else if (check == 2)
		{
			x++;
		}
		else if (check == 3)
		{
			x--;
		}
		xu_ly_ran(toadox, toadoy, x, y, xqua, yqua);
		gameover = kt_ran_cham_tuong(toadox[0], toadoy[0]) || kt_ran_cham_duoi(toadox, toadoy);
		Sleep(100);
	}
	_getch();
}
