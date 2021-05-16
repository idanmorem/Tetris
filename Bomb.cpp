#include "Bomb.h"

//after you decide the location this is actual bombing
void Bomb::activateBomb()
{
    for(int y = 0; y < Board::getRows(); y++)
    {
        for(int x = 0; x < Board::getCols(); x++)
        {
            if(inBombRadius(x, y) && board.getLogicVal(x, y))
            {
                board.resetBoardPosition(x, y);
            }
        }
    }
    activated = true;
    board.updateScreen();
}

//checks if the current (x,y) is in the bomb's radius so it would delete it
bool Bomb::inBombRadius(int x, int y) const
{
    return (((x <= (currX-4)) || (x >= (currX+4))) || ((y <= (currY-4)) || (y >= (currY+4))));
}

void Bomb::setCurrX(int curr)
{
    Bomb::currX = curr;
}

void Bomb::setCurrY(int curr)
{
    Bomb::currY = curr;
}

//draws a bomb
void Bomb::draw()
{
    gotoxy(board.getInitialX() + this->xOffset + 1, board.getInitialY() + this->yOffset);
    std::cout << figure;
    this->currX = board.getInitialX() + this->xOffset + 1; // saves the block x
    this->currY = board.getInitialY() + this->yOffset;// saves the block y
}

void Bomb::findBestBombPos()
{
    int blockHit, max = 0, counter = 0;
    int best_X, best_Y;
    int i, j;
    for(i = 1; i < Board::getRows(); i++)
    {
        for(j = 0; j < Board::getCols(); j++)
        {
            if(!board.getLogicVal(i, j) && counter < Board::getCols()) {
                counter++;
                blockHit = checkHowManyBombed(i - 1, j);
                if(checkBombPath(i-1, j))
                {
                    if(blockHit > max)
                    {
                        max = blockHit;
                        best_X = j;
                        best_Y = i - 1;
                    }
                }
            }
            if(counter == Board::getCols()) {
                setBestX(best_X);
                setBestY(best_Y);
                return;
            }
        }
    }
}

int Bomb::checkHowManyBombed(int row, int col) const{
    int res = 0;
    for (int i = 0; i < Board::getRows(); i++) {
        for (int j = 0; j < Board::getCols(); j++) {
            if (inBombRadius(i, j))
                res++;
        }
    }
    return res;
}

bool Bomb::checkBombPath(int x, int y)
{
    for(int i = y; i < 0; i--) {
        if (board.getLogicVal(x, i)) {
            return false;
        }
    }

    int offsetX = x-currX;
    int move = 0;
    if(offsetX < 0) {
        offsetX *= -1;
        move = 1;
    }
    int i = 0;
    int j = y+1;
    while(i < offsetX)
    {
        if(move == 0) {
            if (board.isFreeBlock(currX - i,j))
                return false;
        }
        if(move == 1)
        {
            if (board.isFreeBlock(currX - i,j))
                return false;
        }
        i++;
        j++;
    }
    return true;
}

int Bomb::getBestX() const {
    return bestX;
}

void Bomb::setBestX(int bestX) {
    Bomb::bestX = bestX;
}

int Bomb::getBestY() const {
    return bestY;
}

void Bomb::setBestY(int bestY) {
    Bomb::bestY = bestY;
}

void Bomb::move(int dir)
{
    switch (dir) {
        case Board::LEFT_KEY :
            moveLeftRight(-1);

            break;
        case Board::RIGHT_KEY :
            moveLeftRight(1);
            break;
        case Board::DROP:
            dropIt();
            break;
    }
}

void Bomb::moveLeftRight(int newOffset) {
    if (getCurrX() > (board.getInitialX())) {
        if(getCurrX() < (board.getInitialX() + Board::cols)) {
            if (!board.getLogicVal(getCurrX() + newOffset, getCurrY())) {
                xOffset += newOffset;
                clearTetromino();
                draw();
            }
        }
    }
}

//deletes the tetromino last position
void Bomb::clearTetromino()
{
        gotoxy(getCurrX(), getCurrY());
        std::cout << ' ';
}

bool Bomb::down()
{
    if(getOffsetY() < Board::getRows()-1)
    {
        if(!board.isFreeBlock(xOffset, yOffset+1) && !activated)
        {
            activateBomb();
            clearTetromino();
            return true;
        } else {
            clearTetromino();
            yOffset++;
            draw();
            return false;
        }
    }
    else {
        activateBomb();
        clearTetromino();
        return true; //if stored
    }
}

void Bomb::dropIt() {
    while(!down())
        Sleep(1);
}

bool Bomb::isActivated() const {
    return activated;
}
