#ifndef TETRIS_BOARD_H
#define TETRIS_BOARD_H
#include "Tetromino.h"

#define COLS 12
#define ROWS 18
#define LEFT 0
#define RIGHT 1
#define ROTATE_CLOCKWISE 2
#define ROTATE_COUNTERCLOCKWISE 3
#define DROP 4
#define PIECE_BLOCKS 5

class Board {
    char arrowKeys[5];
    int direction;
    int board[COLS][ROWS];
    Tetromino tetromino;
    enum {POS_FREE, POS_FILLED};
    void deleteLine(int tY);
public:
    void draw();
    void start();
    void init();
    void setArrowKeys(const char* keys);
    int getDirection(char key);
    void setDirection(int dir) {
        direction = dir;
    }
    bool isGameOver();
    int getXPos(int pos);
    int getYPos(int pos);
    bool isFreeBlock(int tX, int tY);
    bool isPossible(int tX, int tY, int piece, int rotation);
    void storePiece(int tX, int tY, int piece, int rotation);
    void deletePossibleLines();
    int random(int compare);
};

#endif //TETRIS_BOARD_H
