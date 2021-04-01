#include "IO.h"

void gotoxy(int x, int y)
{
HANDLE hConsoleOutput;
COORD dwCursorPosition;
cout.flush();
dwCursorPosition.X = x;
dwCursorPosition.Y = y;
hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);
}

void setTextColor(Color c)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (int)c);
}

void clear_screen()
{
    system("cls");
}
