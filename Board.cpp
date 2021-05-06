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
            board[i][j] = POS_FREE;
}

// update board game on the screen according to received initial x position
void Board::updateScreen()
{
    for(int ix = 0 ; ix < getCols() ; ix++ ) {
        for (int iy = 0; iy < getRows(); iy++) {
            if (board[ix][iy] == POS_FILLED) {
                gotoxy(getInitialX() + ix + 1, getInitialY() + iy );
                cout <<  Tetromino::getFigure();
            }
        }
    }
}

// return true if the game is over
bool Board::isGameOver()const
{
    for(int i = 0; i < getCols(); i++)
    {
        if (board[i][0] == POS_FILLED)
            return true;
    }
    return false;
}

// delete complete line according received Y index
void Board::deleteLine(const int tY)
{
    for(int j = tY; j > 0 ; j--) {
        for (int i = 0; i < getCols(); i++) {
            board[i][j] = board[i][j - 1];
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
            if(board[i][j] != POS_FILLED)
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

void Board::clearLine(int line)
{
    for(int i = 0; i < getCols(); i++)
    {
        gotoxy(getInitialX() + i + 1, line + getInitialY());
        std::cout << ' ';
    }
    Sleep(300);
}

bool Board::isPossible(int pivX, int pivY, int pPiece, int pRotation)const
{
    // This is just to check the 4x4 blocks of a piece with the appropriate area in the board
    for (int i1 = pivX, i2 = 0; i1 < pivX + NUMOFBLOCKS; i1++, i2++)
    {
        for (int j1 = pivY - MATRIX_Y_OFFSET, j2 = 0; j1 < (pivY - MATRIX_Y_OFFSET)  + NUMOFBLOCKS ; j1++, j2++)
        {
            if(j1 >= 0)
                if ((mTetro.getSquareType(pPiece, pRotation,j2,i2) != 0)  && !isFreeBlock(i1,j1) )
                    return false;
            // Check if the piece have collisioned with a block already stored in the map
        }
    }
    // No collision
    return true;
}

void Board::storePiece(int pivX, int pivY, int pPiece, int pRotation)
{
    int counter = 0;
    for (int i1=pivX,i2 = 0; i1 < pivX+ NUMOFBLOCKS ;i1++,i2++)
    {
        for (int j1 = pivY-MATRIX_Y_OFFSET,j2 = 0; j1 < (pivY-MATRIX_Y_OFFSET) +NUMOFBLOCKS; j1++,j2++)
        {
            if(j1 >= 0)
            {
                if ( mTetro.getSquareType(pPiece, pRotation,j2,i2) != 0 )
                {
                    board[i1][j1] = POS_FILLED;
                    counter++;
                }
                if(counter == NUMOFBLOCKS)
                    return;
            }
        }
    }
}

// drawing the limits of both player's boards
void Board::drawBoardLimits()
{
    for(int j = 0; j < getRows() + 1; j++){
        gotoxy(getInitialX(), getInitialY() + j); // left board left border
        std::cout << '|' << std::endl;
        gotoxy(getInitialX() + getCols() + 1, getInitialY() + j); //left board right border
        std::cout << '|' << std::endl;
    }
    for(int i = 0; i < getCols() + 2; i++)
    {
        gotoxy(getInitialX() + i, getInitialY() + getRows()); //left board floor
        std::cout << '*' << std::endl;
    }
}

void Board::resetBoardParameter(int i, int j)
{
    board[i][j] = 0;
}