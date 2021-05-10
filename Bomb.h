#ifndef TETRIS_BOMB_H
#define TETRIS_BOMB_H

#include "Tetromino.h"

class Bomb : public Tetromino {
    int currX = 4 , currY = 0;
public:
    using Tetromino::Tetromino;
    void setCurrX(int currX);
    void setCurrY(int currY);
    int getCurrX()const {return currX;}
    int getCurrY()const {return currY;}
    void activateBomb();
    bool inBombRadius(int i, int j) const;
    void draw() override;
    // void checkBestBombPos() for the computer player check if we get max score by bombing the board
};

#endif //TETRIS_BOMB_H