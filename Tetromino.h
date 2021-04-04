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
    Color color;
    int x = 1, y = 1;
public:
    void draw(char *pieces);
    void setColor(Color c);
    int getKindOfBlock (int tPiece, int tRotation, int tX, int tY);
    int getXInitPos (int tPiece, int tRotation);
    int getYInitPos (int tPiece, int tRotation);
};



#endif //TETRIS_TETROMINO_H
