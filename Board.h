#ifndef TETRIS_BOARD_H
#define TETRIS_BOARD_H
#include "Tetromino.h"

#define PIECE_BLOCKS 4
#define MATRIX_Y_OFFSET 3

class Board {
    static constexpr int cols = 12;
    static constexpr int rows = 18;
    int numBoard = 0;
    int initialX, startBoard;
    const int initialY = 20;
    int board[COLS][ROWS];
    enum {POS_FREE, POS_FILLED};
    void deleteLine(int tY);
    //TODO: decide whether to handle tetromino in Board or TheGame (it is possible to have a pointer to tetromino in the other class)
    Tetromino mTetro;

public:
    enum {LEFT_KEY, RIGHT_KEY, ROTATE_CLOCKWISE, ROTATE_COUNTERCLOCKWISE, DROP, KEYS_SIZE};
    void setEmpty();
    void setArrowKeys(char keys[KEYS_SIZE+1]);
    int getDirection(char key)const;
//    void setDirection(int dir) { direction = dir; }
    bool isGameOver()const;
    bool isFreeBlock(int tX, int tY)const {return(this->board[tX][tY] == POS_FREE);}
    void storePiece(int pX, int pY, int pPiece, int pRotation);
    void deletePossibleLines();
    void updateScreen();
    bool isPossible(int pX, int pY, int pPiece, int pRotation)const;
    void clearLine(int line);
    int getNumBoard() const {return numBoard;}
    void setNumBoard(int num) {numBoard = num;}
    int getInitialX() const {return initialX;}
    void setInitialX(int initial) {initialX = initial;}
    int getStartBoard() const {return startBoard;}
    void setStartBoard(int start) {startBoard = start;}
    int getInitialY() const {return initialY;}
    void drawBoardLimits();
    static const int getCols() {return cols;}
    static const int getRows() {return rows;}
    void resetBoardParameter(int i, int j);

private:
    char arrowKeys[KEYS_SIZE];
};

#endif //TETRIS_BOARD_H