#ifndef TETRIS_BOMB_H
#define TETRIS_BOMB_H

#include "Tetromino.h"

class Bomb : public Tetromino {
    int currX = 4 , currY = 0;
    int bestX, bestY;
    bool activated = false;
public:
    bool isActivated() const;

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
    bool inBombRadius(int x, int y) const;
    void draw() override;
    void findBestBombPos();
    int checkHowManyBombed(int row, int col) const;
    bool checkBombPath(int x, int y);
    void move(int dir) override;
    void moveLeftRight(int newOffset) override;
    void clearTetromino() override;
    bool down() override;
    void dropIt() override;
    };

#endif //TETRIS_BOMB_H