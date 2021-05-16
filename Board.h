#ifndef TETRIS_BOARD_H
#define TETRIS_BOARD_H

#include "IO.h"
#define PIECE_BLOCKS 4
#define MATRIX_Y_OFFSET 3

class Board {
public:
    static constexpr int cols = 12;
    static constexpr int rows = 18;
    enum {LEFT_KEY, RIGHT_KEY, ROTATE_CLOCKWISE, ROTATE_COUNTERCLOCKWISE, DROP, KEYS_SIZE};
private:
    static constexpr char tetrominoFigure = (char) 254;
    int numBoard, initialX, initialY = 20;
    int logicBoard[cols][rows] = {};
    enum {POS_FREE, POS_FILLED};
    void deleteLine(int tY);
    char arrowKeys[KEYS_SIZE];
public:
    int lineCounter(int row);
    int getLogicVal(int row,int col) { return logicBoard[row][col]; }
    void setEmpty();
    static const char getTetrominoFigure();
    void setArrowKeys(char keys[KEYS_SIZE+1]);
    int getDirection(char key)const;
    bool isGameOver()const;
    bool isFreeBlock(int tX, int tY)const {return(this->logicBoard[tX][tY] == POS_FREE);}
    void deletePossibleLines();
    void updateScreen() const;
    void clearLine(int line) const;
    void setNumBoard(int num) {numBoard = num;}
    int getInitialX() const {return initialX;}
    void setInitialX(int initial) {initialX = initial;}
    int getInitialY() const {return initialY;}
    void drawBoardLimits() const;
    static const int getCols() {return cols;}
    static const int getRows() {return rows;}
    void resetBoardPosition(int i, int j);
    void setBoardPosition(int i1,int j1);
};
#endif //TETRIS_BOARD_H