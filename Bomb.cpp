#include "Bomb.h"

void Bomb::activateBomb() //after you decide the location this is actual bombing
{
    for(int i = 0; i < Board::getRows(); i++)
    {
        for(int j = 0; j < Board::getCols(); j++)
        {
            if(inBombRadius(i, j))
                board.resetBoardPosition(i, j);
        }
    }
}

bool Bomb::inBombRadius(int i, int j) const
{
    return ((i <= currY-4 || i >= currY+4) && (j <= currX-4 || j >= currY+4));
}

void Bomb::draw(int xPos, int yPos, int mPiece, int mRotation, int boardNum) {
    int k = 0;
    yOffset += yPos; // if a keyboard hit than updates the y offset
    xOffset += xPos;// if a keyboard hit than updates the x offset
    for (int i = 0; i < YRANGE; i++) {
        for (int j = 0; j < XRANGE; j++) {
            if (mTetrominoes[mPiece][mRotation][i][j] != 0) {
//                if (j > this->xOffset)
//                    this->xOffset++; // updates the offset to prevent crashing borders
                gotoxy(STARTBOARD1 + getXInitPos(piece, rotation) + j + boardNum * (STARTBOARD2 - STARTBOARD1) +
                       this->xOffset, INITIALY + getYInitPos(piece, rotation) + i + this->yOffset);
                std::cout << figure;
                this->currX =
                        STARTBOARD1 + getXInitPos(piece, rotation) + j + boardNum * (STARTBOARD2 - STARTBOARD1) +
                        this->xOffset; // saves the block x
                this->currY = INITIALY + getYInitPos(piece, rotation) + i + this->yOffset;// saves the block y
                k++;
                if (k == NUMOFBLOCKS) // if already printed four blocks return
                    return;
            }
        }
    }
}