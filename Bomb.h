#ifndef TETRIS_BOMB_H
#define TETRIS_BOMB_H

#include "Tetromino.h"

class Bomb : public Tetromino {
    int currX = 4 , currY = 0;
    int bestX, bestY;
public:
    int getBestX() const;
    void setBestX(int bestX);
    int getBestY() const;
    void setBestY(int bestY);
    using Tetromino::Tetromino;
    void setCurrX(int curr);
    void setCurrY(int curr);
    int getCurrX()const {return currX;}
    int getCurrY()const {return currY;}
    void activateBomb();
    bool inBombRadius(int i, int j) const;
    void draw() override;
    void findBestBombPos();
    int checkHowManyBombed(int row, int col) const;
    bool checkBombPath(int x, int y);
    bool isPossible(int pivX, int pivY)const ;
};

#endif //TETRIS_BOMB_H