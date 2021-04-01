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
#define DOWN 5


class Board {
    const int width;
    const int height;
    char arrowKeys[5];

public:
    void setArrowKeys(const char* keys);
};

#endif //TETRIS_BOARD_H
