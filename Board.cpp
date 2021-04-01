#include "Board.h"

void Board::setArrowKeys(const char *keys)
{
    arrowKeys[LEFT] = keys[0];
    arrowKeys[RIGHT] = keys[1];
    arrowKeys[ROTATE_CLOCKWISE] = keys[2];
    arrowKeys[ROTATE_COUNTERCLOCKWISE] = keys[3];
    arrowKeys[DROP] = keys[4];
}
