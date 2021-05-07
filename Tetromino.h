#ifndef TETRIS_TETROMINO_H
#define TETRIS_TETROMINO_H

#include "GameObjects.h"
#include "IO.h"
#include <iostream>

#define XRANGE 4
#define YRANGE 4
#define PIECES_KINDS 7
#define ROTATION 4
#define POSITION 2
#define NUMOFBLOCKS 4

class Tetromino: public GameObjects {
    int piece = 0, rotation = 0;
    int currX[NUMOFBLOCKS], currY[NUMOFBLOCKS]; // saving the (x,y) of every new block piece (4 overall)
public:
    using GameObjects::GameObjects;
    void draw(int xPos, int yPos, int piece, int rotation, int boardNum) override;
    int getXInitPos(int tPiece, int tRotation)const;
    int getYInitPos(int tPiece, int tRotation)const;
    int getBlockType()const {return this->piece;}
    int getBlockRotation()const {return this->rotation;}
    int setPiece(int tPiece);
    int setRotation(int tRotation);
    int getCurrX(int pos)const {return this->currX[pos];}
    int getCurrY(int pos)const {return this->currY[pos];}
    int getLeftmostX()const;
    int getRightmostX()const;
    int getSquareType(int pPiece, int pRotation, int pX, int pY)const;
    static char getFigure() {return figure;}
    void clearTetromino();

};
#endif //TETRIS_TETROMINO_H




