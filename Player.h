#ifndef TETRIS_PLAYER_H
#define TETRIS_PLAYER_H
#include "Tetromino.h"

//Player.h - General player class
class Player {
protected:
    Board& board;
    Tetromino& t;
public:
    Player(Board& board, Tetromino& t) : board(board), t(t) {}
    virtual void makeTurn()  = 0;
};

#endif //TETRIS_PLAYER_H