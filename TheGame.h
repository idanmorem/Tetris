#ifndef TETRIS_THEGAME_H
#define TETRIS_THEGAME_H

#include "Board.h"
#include "IO.h"
#include <conio.h>
#include <stdlib.h>

#define NEW_GAME '1'
#define CONTINUE_GAME '2'
#define KEYS_INSTRUCTIONS '8'
#define EXIT '9'

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
