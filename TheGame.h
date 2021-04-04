#ifndef TETRIS_THEGAME_H
#define TETRIS_THEGAME_H

#include "Board.h"
#include "IO.h"
#include <conio.h>
#include <stdlib.h>



class TheGame{
    enum {ESC = 27};
    Board board[2];
public:
    void init();
    void start_new();
    void menu(bool paused);
    int random(int compare);
    void exit();
    void resume();
};

#endif //TETRIS_THEGAME_H
