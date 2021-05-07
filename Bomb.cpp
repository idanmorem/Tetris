#include "Bomb.h"

void Bomb::activeBomb()
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