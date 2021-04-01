#ifndef _GOTOXY_H_
#define _GOTOXY_H_

#include <windows.h>
#include <iostream>
using namespace std;
#include <process.h>
#include "conio.h"

enum Color
{
    BLACK = 0,
    BLUE = 1,
    GREEN = 2,
    CYAN = 3,
    RED = 4,
    MAGENTA = 5,
    BROWN = 6,
    LIGHTGREY = 7,
    DARKGREY = 8,
    LIGHTBLUE = 9,
    LIGHTGREEN=10,
    LIGHTCYAN=11,
    LIGHTRED=12,
    LIGHTMAGENTA=13,
    YELLOW=14,
    WHITE=15
};

// function definition
void gotoxy(int x, int y);
void setTextColor(Color c);
void clear_screen();


#endif
