#include "Bomb.h"

void Bomb::activateBomb() //after you decide the location this is actual bombing
{
    int counter = 0;
    for(int i = 0; i < Board::getRows(); i++)
    {
        for(int j = 0; j < Board::getCols(); j++)
        {
            if(inBombRadius(i, j))
            {
                counter++;
                board.resetBoardPosition(i, j);
                gotoxy(i+board.getInitialX(), j+board.getInitialY());
                std::cout << ' ';
                board.updateScreen();
            }
        }
    }
}

bool Bomb::inBombRadius(int i, int j) const //checks if the current (x,y) is in the bomb's radius so it would delete it
{
    return ((i <= currY-4 || i >= currY+4) && (j <= currX-4 || j >= currY+4));
}

void Bomb::setCurrX(int currX)
{
    Bomb::currX = currX;
}

void Bomb::setCurrY(int currY)
{
    Bomb::currY = currY;
}

void Bomb::draw()//draws a bomb
{
    gotoxy(board.getInitialX() + getCurrX() + this->xOffset, board.getInitialY() + getCurrY() + this->yOffset);
    std::cout << figure;
    this->currX = board.getInitialX() + getCurrX() + this->xOffset; // saves the block x
    this->currY = board.getInitialY() + getCurrY() + this->yOffset;// saves the block y
}