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
    for(int i = 0; i < cols; i++)
        for(int j = 0; j < rows; j++)
            logicBoard[i][j] = POS_FREE;
}

// update board game on the screen
void Board::updateScreen() const
{
    for(int ix = 0 ; ix < cols ; ix++ ) {
        for (int iy = 0; iy < rows; iy++) {
            if (logicBoard[ix][iy] == POS_FILLED) {
                gotoxy(getInitialX() + ix + 1, getInitialY() + iy );
                cout <<  tetrominoFigure;
            }
            else{
                gotoxy(getInitialX() + ix + 1, getInitialY() + iy );
                cout <<  ' ';
            }
        }
    }
}

// return true if the game is over
bool Board::isGameOver()const
{
    for(int i = 0; i < cols; i++)
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
        for (int i = 0; i < cols; i++) {
            logicBoard[i][j] = logicBoard[i][j - 1];
        }
    }
}

// check if there is full lines that should be deleted
void Board::deletePossibleLines()
{
    for(int j = 0; j < rows; j++)
    {
        int i = 0;
        while (i < cols)
        {
            if(logicBoard[i][j] != POS_FILLED)
                break;
            i++;
        }
        if(i == cols)
        {
            deleteLine(j);
            clearLine(j);
            updateScreen();
        }
    }
}

void Board::clearLine(int line) const
{
    for(int i = 0; i < cols; i++)
    {
        gotoxy(getInitialX() + i + 1, line + getInitialY());
        std::cout << ' ';
    }
    Sleep(300);
}

// drawing the limits of both player's boards
void Board::drawBoardLimits() const
{
    for(int j = 0; j < rows + 1; j++){
        gotoxy(getInitialX(), getInitialY() + j); //left border
        std::cout << '|' << std::endl;
        gotoxy(getInitialX() + cols + 1, getInitialY() + j); //right border
        std::cout << '|' << std::endl;
    }
    for(int i = 0; i < cols + 2; i++)
    {
        gotoxy(getInitialX() + i, getInitialY() + rows); //floor
        std::cout << '*' << std::endl;
    }
}

void Board::resetBoardPosition(int i, int j)
{
    logicBoard[i][j] = POS_FREE;
}


void Board::setBoardPosition(int i1,int j1) {
    logicBoard[i1][j1] = POS_FILLED;
}

int Board::lineCounter(int row)
{
    int i = 0,counter=0;
    while (i < cols)
    {
        if(logicBoard[i][row] == POS_FILLED)
            counter++;
        i++;
    }
    return counter;
}
