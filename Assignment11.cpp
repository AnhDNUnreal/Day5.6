//#define _WIN32_WINNT 0x601
#include <windows.h>
#include <stdio.h>
#include <iostream>
using namespace std;

BOOL setxy(int x, int y)
{
	COORD c = { x,y };
	return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void DrawRect(int x, int y, int width, int height, int curPosX = 0, int curPosY = 0)
{
	setxy(x, y); cout << char(201);
	for (int i = 1; i < width; i++)cout << char(205);
	cout << char(187);
	setxy(x, height + y); cout << char(200);
	for (int i = 1; i < width; i++)cout << char(205);
	cout << char(188);
	for (int i = y + 1; i < height + y; i++)
	{
		setxy(x, i); cout << char(186);
		setxy(x + width, i); cout << char(186);
	}
	setxy(curPosX, curPosY);
}

int main() {
	// Get window handle to console, and device context
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//Here's a 5 pixels wide RED line [from initial 0,0] to 300,300
	HPEN pen = CreatePen(PS_SOLID, 5, RGB(255, 0, 0));
	SelectObject(device_context, pen);
	LineTo(device_context, 300, 300);

	ReleaseDC(console_handle, device_context);

	DrawRect(10, 10, 10, 5);

	DrawRect(20, 20, 10, 10);

	getchar();

	return 0;
}