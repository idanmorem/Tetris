#ifndef TETRIS_TETROMINO_H
#define TETRIS_TETROMINO_H
#include "IO.h"
#include "Board.h"

#define XRANGE 5
#define YRANGE 5
#define PIECES_KINDS 7
#define ROTATION 4
#define POSITION 2



class Tetromino
{
    const char figure = (char)254;
    Color color = BLACK;
    int direction = 5;

public:
    void getTetromino();
    void setColor(Color c);
    void move();

//    int getKindOfBlock (int pPiece, int pRotation, int pX, int pY);
//    int getXInitPos (int pPiece, int pRotation);
//    int getYInitPos (int pPiece, int pRotation);
};



#endif //TETRIS_TETROMINO_H
