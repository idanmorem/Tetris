#include "GameObjects.h"

void GameObjects::move(int numBoard, int dir)
{
    switch (dir) {
        case Board::LEFT_KEY :
            moveLeftRight(numBoard, -1);
            break;
        case Board::RIGHT_KEY :
            moveLeftRight(numBoard, 1);
            break;
        case Board::ROTATE_CLOCKWISE :
            rotate(numBoard, 1);
            break;
        case Board::ROTATE_COUNTERCLOCKWISE:
            rotate(numBoard, -1);
            break;
        case Board::DROP :
        {
            dropIt(numBoard);
            break;
        }
    }
}

void GameObjects::moveLeftRight(int numBoard, int move) {
    if (tetromino[numBoard].getLeftmostX() > (board[numBoard].getInitialX + numBoard * (STARTBOARD2 - STARTBOARD1) + 1)) {
        if(board[numBoard].isPossible(getXlogicCoord(tetromino[numBoard].getOffsetX()) - 1,
                                      tetromino[numBoard].getOffsetY(),
                                      tetromino[numBoard].getBlockType(),
                                      tetromino[numBoard].getBlockRotation())) {
            tetromino[numBoard].clearTetromino();
            tetromino[numBoard].draw(move, 0, tetromino[numBoard].getBlockType(),
                                     tetromino[numBoard].getBlockRotation(), numBoard);
        }
    }
}

void GameObjects::rotate(int numBoard, int move) {
    if(board[numBoard].isPossible(getXlogicCoord(tetromino[numBoard].getOffsetX()),
                                  tetromino[numBoard].getOffsetY(), tetromino[numBoard].getBlockType(),
                                  (tetromino[numBoard].getBlockRotation() + move) % ROTATION)) {
        tetromino[numBoard].clearTetromino();
        tetromino[numBoard].draw(0, 0,tetromino[numBoard].getBlockType(),(tetromino[numBoard].getBlockRotation() + 1) % ROTATION, numBoard);
    }
}

void GameObjects::dropIt(int numBoard) {
    drop[numBoard] = true;
//            while(!stored)
    while(drop[numBoard])
    {
        down(numBoard);
        over = board[numBoard].isGameOver(); //TEST
        board[numBoard].deletePossibleLines(); //TEST
        if(over)
            return;
        if(esc_hit)
            return;
        else
            //TODO: this is a wrong recursion
            gameLoop();
    }
}