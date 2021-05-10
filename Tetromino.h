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

class Tetromino {
    int piece, rotation;
    int xPos, yPos;
    int currX[NUMOFBLOCKS] = {}, currY[NUMOFBLOCKS] = {}; // saving the (x,y) of every new block piece (4 overall)
protected:
    const int numBoard;
    char figure;
    Board &board;
    int xOffset = 0, yOffset = 0;
public:
    Tetromino(int numBoard, char figure, Board& board) : numBoard(numBoard), figure(figure), board(board) {}

//    Tetromino(int piece, int rotation, int numBoard, char figure, const Board& board): piece(piece), rotation(rotation), numBoard(numBoard), figure(figure), board(board) {}
    virtual void draw();

    void down();

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

    void clearTetromino();

    virtual int getOffsetY() const { return yOffset; }

    virtual int getOffsetX() const { return xOffset; }

    void initOffsetX() { xOffset = 0; }

    void initOffsetY() { yOffset = 0; }

    char getFigure() const { return figure; }

    void move(int dir);

    void moveLeftRight(int newOffset);

    void rotate(int newOffset);

    void dropIt();

    int getXlogicCoord(int console_x_offset) const;

    void init(int kind, int rotation);

    void keyboardHit(int dir);

    virtual const int getNumBoard() const;

    bool isPossible(int pivX, int pivY, int pPiece, int pRotation)const;

    void storePiece(int pivX, int pivY, int pPiece, int pRotation);
};
#endif //TETRIS_TETROMINO_H