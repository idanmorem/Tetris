#ifndef TETRIS_TETROMINO_H
#define TETRIS_TETROMINO_H

#include "IO.h"
#include "Board.h"
#include <iostream>

#define XRANGE 4
#define YRANGE 4
#define PIECES_KINDS 7
#define ROTATION 4
#define POSITION 2
#define NUMOFBLOCKS 4

class Tetromino{
    int piece = 0, rotation = 0;
    int currX[NUMOFBLOCKS] = {}, currY[NUMOFBLOCKS] = {}; // saving the (x,y) of every new block piece (4 overall)
    int best_x = 0, best_r = 0;
protected:
    const int numBoard;
    char figure;
    Board &board;
    int xOffset = 4, yOffset = 0;
public:
    Tetromino(int numBoard, char figure, Board& board) : numBoard(numBoard), figure(figure), board(board) {}
    virtual void draw();
    virtual bool down();
    int getXInitPos(int tPiece, int tRotation) const;
    int getYInitPos(int tPiece, int tRotation) const;
    int getBlockType() const { return piece; }
    int getBlockRotation() const { return rotation; }
    void setPiece(int tPiece) { piece = tPiece; }
    void setRotation(int tRotation) { rotation = tRotation; }
    int getCurrX(int pos) const { return currX[pos]; }
    int getCurrY(int pos) const { return currY[pos]; }
    int getLeftmostX() const;
    int getRightmostX() const;
    int getSquareType(int pPiece, int pRotation, int pX, int pY) const;
    virtual void clearTetromino();
    virtual int getOffsetY() const { return yOffset; }
    virtual int getOffsetX() const { return xOffset; }
    virtual void initOffsetX() { xOffset = 4; }
    virtual void initOffsetY() { yOffset = 0; }
    virtual void move(int dir);
    virtual void moveLeftRight(int newOffset);
    void rotate(int newOffset);
    virtual void dropIt();
    void init(int kind, int rotation);
    bool isPossible(int newXoffset, int newYoffset, int newRotateOffset)const;
    void storePiece(int pivX, int pivY, int pPiece, int pRotation);
    void FindBestPos();
    void deletePiece(int pivX, int pivY, int pPiece, int pRotation);
    void moveWiseStep();
    void moveRandomStep();
};
#endif //TETRIS_TETROMINO_H