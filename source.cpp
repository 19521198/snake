#include "source.h"

#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <ctime>
#include <iomanip>
#include <string.h>

#include <io.h>
#include <fcntl.h>
#include <string>
#include <windows.h>
#include <mmsystem.h>


void gotoXY(int x, int y)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD CursorPosition;
    CursorPosition.X = x; // Locates column
    CursorPosition.Y = y; // Locates Row
    SetConsoleCursorPosition(console, CursorPosition); // Sets position for next thing to be printed
}

void changColor(int k)
{
    HANDLE hConsoleColor;
    hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsoleColor, 240);
}
/*
void resizeConsole(int width, int height)
{
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, width, height, TRUE);
}

void setFontSize(int FontSize)
{
    CONSOLE_FONT_INFOEX info = { 0 };
    info.cbSize = sizeof(info);
    info.dwFontSize.Y = FontSize; // leave X as zero
    info.FontWeight = FW_NORMAL;
    wcscpy_s(info.FaceName, L"Lucida Console");
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), NULL, &info);
}
*/