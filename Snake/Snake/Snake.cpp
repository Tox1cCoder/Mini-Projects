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
	ve_tuong_tren();
	ve_tuong_duoi();
	ve_tuong_trai();
	ve_tuong_phai();
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

void xu_ly_ran(int toadox[], int toadoy[], int x, int y)
{
	them(toadox, x);
	them(toadoy, y);
	xoa(toadox, s - 1);
	xoa(toadoy, s - 1);
	ve_ran(toadox, toadoy);
}

int main()
{
	int toadox[MAX], toadoy[MAX];
	ve_tuong();
	khoi_tao_ran(toadox, toadoy);
	ve_ran(toadox, toadoy);
	int x = 50, y = 13;
	int check = 2;
	while (true)
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
		xu_ly_ran(toadox, toadoy, x, y);
		Sleep(150);
	}
	_getch();

	return 0;
}
