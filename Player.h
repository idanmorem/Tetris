#ifndef TETRIS_PLAYER_H
#define TETRIS_PLAYER_H
#include "Tetromino.h"
#include "Bomb.h"

//Player.h - General player class
class Player {

protected:
    bool stored = false;
    bool bombInHand = false;
    Board& board;
    Tetromino& t;
    Bomb& b;

public:
    Player(Board& board, Tetromino& t, Bomb &b) : board(board), t(t), b(b) {}
    virtual int makeTurn()  = 0;
    bool isStored() const {
        return stored;
    }

    void setStored(bool stored) {
        Player::stored = stored;
    }

    bool isBombInHand() const {
        return bombInHand;
    }

    void setBombInHand(bool _bombInHand) {
        Player::bombInHand = _bombInHand;
    }
};

#endif //TETRIS_PLAYER_H