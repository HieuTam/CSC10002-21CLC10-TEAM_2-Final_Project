#include "Header.h"


void txtColor(int color) // khai bao bang mau
{
	HANDLE hConsoleColor;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void gotoxy(int x, int y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}

void Draw(int x) // ham dung de ke o vuong phan dang nhap
{
	gotoxy(49, x);
	cout << char(218);
	for (int i = 0; i < 30; i++)
		cout << char(196);
	cout << char(191);
	gotoxy(49, x + 1); cout << char(179);
	gotoxy(80, x + 1); cout << char(179);
	gotoxy(49, x + 2);
	cout << char(192);
	for (int i = 0; i < 30; i++)
		cout << char(196);
	cout << char(217);
}

void clear()
{
	for (int i = 2; i < 118; ++i)    // lap day khung menu = khoang trang
		for (int j = 6; j < 39; ++j)
		{
			gotoxy(i, j);
			cout << char(32);
		}
	txtColor(7);
}

void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConCurInf;

	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = CursorVisibility;

	SetConsoleCursorInfo(handle, &ConCurInf);
}

void Back() // nut tro lai
{
	gotoxy(4, 6);
	cout << "Back";
	char keycap = 0;
	while (keycap != 13)
	{
		ShowCur(0);
		keycap = getch();
	}
	ShowCur(1);
}
