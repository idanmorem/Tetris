#include "Board.h"

void Board::setArrowKeys(char keys[KEYS_SIZE+1])
{
    if(strlen(keys) == KEYS_SIZE)
    {
        for(int i = 0; i < KEYS_SIZE; i++)
            arrowKeys[i] = keys[i];
    }
}

int Board::getDirection(const char key)const
{
    for(int i = 0; i < KEYS_SIZE; i++)
    {
        if(key == arrowKeys[i])
            return i;
    }
    return -1;
}

// set all board positions to be empty
void Board::setEmpty()
{
    for(int i = 0; i < getCols(); i++)
        for(int j = 0; j < getRows(); j++)
            logicBoard[i][j] = POS_FREE;
}

// update board game on the screen
void Board::updateScreen() const
{
    for(int ix = 0 ; ix < getCols() ; ix++ ) {
        for (int iy = 0; iy < getRows(); iy++) {
            if (logicBoard[ix][iy] == POS_FILLED) {
                gotoxy(getInitialX() + ix + 1, getInitialY() + iy );
                cout <<  getTetrominoFigure();
            }
        }
    }
}

// return true if the game is over
bool Board::isGameOver()const
{
    for(int i = 0; i < getCols(); i++)
    {
        if (logicBoard[i][0] == POS_FILLED)
            return true;
    }
    return false;
}

// delete complete line according received Y index
void Board::deleteLine(const int tY)
{
    for(int j = tY; j > 0 ; j--) {
        for (int i = 0; i < getCols(); i++) {
            logicBoard[i][j] = logicBoard[i][j - 1];
        }
    }
}

// check if there is full lines that should be deleted
void Board::deletePossibleLines()
{
    for(int j = 0; j < getRows(); j++)
    {
        int i = 0;
        while (i < getCols())
        {
            if(logicBoard[i][j] != POS_FILLED)
                break;
            i++;
        }
        if(i == getCols())
        {
            deleteLine(j);
            clearLine(j);
            updateScreen();
        }
    }
}

void Board::clearLine(int line) const
{
    for(int i = 0; i < getCols(); i++)
    {
        gotoxy(getInitialX() + i + 1, line + getInitialY());
        std::cout << ' ';
    }
    Sleep(300);
}



// drawing the limits of both player's boards
void Board::drawBoardLimits() const
{
    for(int j = 0; j < getRows() + 1; j++){
        gotoxy(getInitialX(), getInitialY() + j); //left border
        std::cout << '|' << std::endl;
        gotoxy(getInitialX() + getCols() + 1, getInitialY() + j); //right border
        std::cout << '|' << std::endl;
    }
    for(int i = 0; i < getCols() + 2; i++)
    {
        gotoxy(getInitialX() + i, getInitialY() + getRows()); //floor
        std::cout << '*' << std::endl;
    }
}

void Board::resetBoardPosition(int i, int j)
{
    logicBoard[i][j] = 0;
}

const char Board::getTetrominoFigure() {
    return tetrominoFigure;
}

void Board::setBoardPosition(int i1,int j1) {
    logicBoard[i1][j1] = POS_FILLED;
}

// return the score that the last turn gain
int Board::FindPosScore() {

    int y, x = 0,counter = 0;
    for (y = 0; y < getRows(); y++) {
        while (x < getCols()) {
            if (logicBoard[x][y] != POS_FILLED)
                break;
            x++;
        }
        if (x == getCols())
            counter++;
    }
    switch (counter) {
        case (1):
            return (y + 1) * 40;
        case (2):
            return (y + 1) * 100;
        case (3):
            return (y + 1) * 300;
        case (4):
            return (y + 1) * 1200;
        default:
            return -1;
    }
}

// dont forget to free in the next function
int* Board::GetRowGates(int row)
{
    int* res = new int[12];
    int counter = 0;
    for( int x = 11 ; x <= 0  ; x--)
    {
        if(logicBoard[x][row] == POS_FILLED)
            res[x] = ++counter;
        else{
            counter = 0;
            res[x] = counter;
        }
    }
    return res;
}
