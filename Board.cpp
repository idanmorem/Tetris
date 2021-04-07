#include "Board.h"

void Board::setArrowKeys(const char *keys)
{
    arrowKeys[LEFT] = keys[0];
    arrowKeys[RIGHT] = keys[1];
    arrowKeys[ROTATE_CLOCKWISE] = keys[2];
    arrowKeys[ROTATE_COUNTERCLOCKWISE] = keys[3];
    arrowKeys[DROP] = keys[4];
}

int Board::getDirection(char key)
{
    for(int i = 0; i < 5; i++)
    {
        if(key == arrowKeys[i])
            return i;
    }
    return -1;
}

void Board::init()
{
    for(int i = 0; i < COLS; i++)
        for(int j = 0; j < ROWS; j++)
            board[i][j] = POS_FREE;
}

bool Board::isGameOver()
{
    for(int i = 0; i < COLS; i++)
        if(board[i][0] == POS_FILLED)
            return true;

    return false;
}

void Board::deleteLine(int tY)
{
    for(int j = tY; j > 0 ; j--)
        for(int i = 0; i < COLS; i++)
            board[i][j] = board[i][j-1];
}

//void Board::storePiece(int tX, int tY, int piece, int rotation)
//{
//    for(int i1 = tX, i2 = 0; i1 < tX + PIECE_BLOCKS; i1++, i2++)
//        for(int j1 = tY, j2 = 0; j1 < tY + PIECE_BLOCKS; j1++, j2++)
//            if(tetrominoes->getKindOfBlock(piece, rotation, j2, i2) != 0)
//                board[i1][j1] = POS_FILLED;
//}

void Board::deletePossibleLines()
{
    for(int j = 0; j < ROWS; j++)
    {
        int i = 0;
        while (i < COLS)
        {
            if(board[i][j] != POS_FILLED)
                break;
            i++;
        }
        if(i == COLS)
            deleteLine(j);
    }
}

bool Board::isFreeBlock(int tX, int tY)
{
    if(board[tX][tY] == POS_FREE)
        return true;
    else
        return false;
}

void Board::draw()
{
    for(int j = 0; j < ROWS + 1; j++) {
        gotoxy(INITIALX, INITIALY + j); // left board left border
        std::cout << '|' << std::endl;
        gotoxy(INITIALX + COLS + 1, INITIALY + j); //left board right border
        std::cout << '|' << std::endl;
        gotoxy(INITIALX + XSPACE + COLS + 1,INITIALY + j); //right board left border
        std::cout << '|' << std::endl;
        gotoxy(INITIALX + XSPACE + 2 * COLS + 2,INITIALY + j); //right board right border
        std::cout << '|' << std::endl;
    }
    for(int i = 0; i < COLS + 2; i++)
    {
        gotoxy(INITIALX + i, INITIALY + ROWS); //left board floor
        std::cout << '*' << std::endl;
        gotoxy(INITIALX + i + COLS + XSPACE + 1, INITIALY + ROWS) ;//right board floor
        std::cout << '*' << std::endl;
    }
}

void Board::start()
{
    tetromino.draw(6,3, 0);
    tetromino.draw(random(PIECES_KINDS), random(ROTATION), 1);
//    for(int i = 0; i < COLS; i++)
//        for(int j = 0; j < ROWS; j++)
//            tetromino.draw(piece, rotation, 0);
}

bool Board::isPossible (int pX, int pY, int pPiece, int pRotation)
{
    // Checks collision with pieces already stored in the board or the board limits
    // This is just to check the 5x5 blocks of a piece with the appropiate area in the board
    for (int i1 = pX, i2 = 0; i1 < pX + PIECE_BLOCKS; i1++, i2++)
    {
        for (int j1 = pY, j2 = 0; j1 < pY + PIECE_BLOCKS; j1++, j2++)
        {
            // Check if the piece is outside the limits of the board
            if (i1 < 0 || i1 > COLS  - 1 || j1 > ROWS - 1)
            {
                if (tetromino.GetBlockType (pPiece, pRotation, j2, i2) != 0)
                    return false;
            }

            // Check if the piece have collisioned with a block already stored in the map
            if (j1 >= 0)
            {
                if ((tetromino.GetBlockType (pPiece, pRotation, j2, i2) != 0) &&
                    (!isFreeBlock (i1, j1))	)
                    return false;
            }
        }
    }
    // No collision
    return true;
}

int Board::random(int compare)
{
    return (rand() % compare);
}
//comment
