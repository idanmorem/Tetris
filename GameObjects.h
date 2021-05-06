#ifndef TETRIS_GAMEOBJECTS_H
#define TETRIS_GAMEOBJECTS_H

#include "Board.h"

class GameObjects {
    char figure;
    int xOffset = 0, yOffset = 0;
protected:
    Board& board;
public:
    GameObjects(Board& board, char figure): board(board), figure(figure) {}
    virtual void draw(int xPos, int yPos, int piece, int rotation, int boardNum) = 0;
    virtual int getOffsetY()const {return yOffset;}
    virtual int getOffsetX()const {return xOffset;}
    void initOffsetX() {xOffset = 0;}
    void initOffsetY() {yOffset = 0;}
};
#endif //TETRIS_GAMEOBJECTS_H
