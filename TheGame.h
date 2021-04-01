#ifndef TETRIS_THEGAME_H
#define TETRIS_THEGAME_H

#include "Board.h"
#include "IO.h"


class TheGame{
    enum {ESC = 27};
    Board board[2];
public:
    void init();
    void run();
    void menu();
};

#endif //TETRIS_THEGAME_H
