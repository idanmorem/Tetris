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
    static constexpr char tetrominoFigure = (char) 256;
    int numBoard, initialX, initialY = 20;
    int startBoard;
    int logicBoard[cols][rows] = {};
    enum {POS_FREE, POS_FILLED};
    void deleteLine(int tY);
    char arrowKeys[KEYS_SIZE];
public:


    int getLogicVal(int x,int y) { return logicBoard[x][y]; }
    int setLogicVal(int x,int y,int val) {  logicBoard[x][y] = val; }

    void setEmpty();
    static const char getTetrominoFigure();
    void setArrowKeys(char keys[KEYS_SIZE+1]);
    int getDirection(char key)const;
//    void setDirection(int dir) { direction = dir; }
    bool isGameOver()const;
    bool isFreeBlock(int tX, int tY)const {return(this->logicBoard[tX][tY] == POS_FREE);}
    void deletePossibleLines();
    void updateScreen() const;
    void clearLine(int line) const;
    int getNumBoard() const {return numBoard;}
    void setNumBoard(int num) {numBoard = num;}
    int getInitialX() const {return initialX;}
    void setInitialX(int initial) {initialX = initial;}
    int getStartBoard() const {return startBoard;}
    void setStartBoard(int start) {startBoard = start;}
    int getInitialY() const {return initialY;}
    void drawBoardLimits() const;
    static const int getCols() {return cols;}
    static const int getRows() {return rows;}
    void resetBoardPosition(int i, int j);
    void setBoardPosition(int i1,int j1);

    int FindPosScore();
    void FindBestPos();
    int* GetRowGates(int row);


};

#endif //TETRIS_BOARD_H