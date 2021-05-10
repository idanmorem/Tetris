#include "Tetromino.h"
#include "TheGame.h"

// matrix defining all the tetromino pieces and their rotation
char mTetrominoes[PIECES_KINDS][ROTATION][XRANGE][YRANGE] =
{
                // Square
                {
                        {
                                {0, 0, 0, 0},
                                {0, 0, 0, 0},
                                {1, 1, 0, 0},
                                {1, 1, 0, 0}
                        },
                        {
                                {0, 0, 0, 0},
                                {0, 0, 0, 0},
                                {1, 1, 0, 0},
                                {1, 1, 0, 0}
                        },
                        {
                                {0, 0, 0, 0},
                                {0, 0, 0, 0},
                                {1, 1, 0, 0},
                                {1, 1, 0, 0}
                        },
                        {
                                {0, 0, 0, 0},
                                {0, 0, 0, 0},
                                {1, 1, 0, 0},
                                {1, 1, 0, 0}
                        }
                },

// I
                {
                        {
                                {0, 0, 0, 0},
                                {0, 0, 0, 0},
                                {0, 0, 0, 0},
                                {1, 1, 1, 1}
                        },
                        {
                                {1, 0, 0, 0},
                                {1, 0, 0, 0},
                                {1, 0, 0, 0},
                                {1, 0, 0, 0}
                        },
                        {
                                {0, 0, 0, 0},
                                {0, 0, 0, 0},
                                {0, 0, 0, 0},
                                {1, 1, 1, 1}
                        },
                        {
                                {1, 0, 0, 0},
                                {1, 0, 0, 0},
                                {1, 0, 0, 0},
                                {1, 0, 0, 0}
                        }
                }
                ,
// L
                {
                        {
                                {0, 0, 0, 0},
                                {1, 0, 0, 0},
                                {1, 0, 0, 0},
                                {1, 1, 0, 0}
                        },
                        {
                                {0, 0, 0, 0},
                                {0, 0, 0, 0},
                                {1, 1, 1, 0},
                                {1, 0, 0, 0}
                        },
                        {
                                {0, 0, 0, 0},
                                {1, 1, 0, 0},
                                {0, 1, 0, 0},
                                {0, 1, 0, 0}
                        },
                        {
                                {0, 0, 0, 0},
                                {0, 0, 0, 0},
                                {0, 0, 1, 0},
                                {1, 1, 1, 0}
                        }
                },
// L mirrored
                {
                        {
                                {0, 0, 0, 0},
                                {0, 1, 0, 0},
                                {0, 1, 0, 0},
                                {1, 1, 0, 0}
                        },
                        {
                                {0, 0, 0, 0},
                                {0, 0, 0, 0},
                                {1, 0, 0, 0},
                                {1, 1, 1, 0}
                        },
                        {
                                {0, 0, 0, 0},
                                {1, 1, 0, 0},
                                {1, 0, 0, 0},
                                {1, 0, 0, 0}
                        },
                        {
                                {0, 0, 0, 0},
                                {0, 0, 0, 0},
                                {1, 1, 1, 0},
                                {0, 0, 1, 0}
                        }
                },
// N
                {
                        {
                                {0, 0, 0, 0},
                                {0, 1, 0, 0},
                                {1, 1, 0, 0},
                                {1, 0, 0, 0}
                        },
                        {
                                {0, 0, 0, 0},
                                {0, 0, 0, 0},
                                {1, 1, 0, 0},
                                {0, 1, 1, 0}
                        },
                        {
                                {0, 0, 0, 0},
                                {0, 1, 0, 0},
                                {1, 1, 0, 0},
                                {1, 0, 0, 0}
                        },
                        {
                                {0, 0, 0, 0},
                                {0, 0, 0, 0},
                                {1, 1, 0, 0},
                                {0, 1, 1, 0}
                        }
                },
// N mirrored
                {
                        {
                                {0, 0, 0, 0},
                                {1, 0, 0, 0},
                                {1, 1, 0, 0},
                                {0, 1, 0, 0}
                        },
                        {
                                {0, 0, 0, 0},
                                {0, 0, 0, 0},
                                {0, 1, 1, 0},
                                {1, 1, 0, 0}
                        },
                        {
                                {0, 0, 0, 0},
                                {1, 0, 0, 0},
                                {1, 1, 0, 0},
                                {0, 1, 0, 0}
                        },
                        {
                                {0, 0, 0, 0},
                                {0, 0, 0, 0},
                                {0, 1, 1, 0},
                                {1, 1, 0, 0}
                        }
                },
// T
                {
                        {
                                {0, 0, 0, 0},
                                {1, 0, 0, 0},
                                {1, 1, 0, 0},
                                {1, 0, 0, 0}
                        },
                        {
                                {0, 0, 0, 0},
                                {0, 0, 0, 0},
                                {1, 1, 1, 0},
                                {0, 1, 0, 0}
                        },
                        {
                                {0, 0, 0, 0},
                                {0, 1, 0, 0},
                                {1, 1, 0, 0},
                                {0, 1, 0, 0}
                        },
                        {
                                {0, 0, 0, 0},
                                {0, 0, 0, 0},
                                {0, 1, 0, 0},
                                {1, 1, 1, 0}
                        }
                }
};

//matrix defining every tetromino type and rotation the starting (x,y) coordinate on borad
int mInitPos [PIECES_KINDS][ROTATION][POSITION] =
{
        /* Square */
        {
                {1, -3},
                {1, -3},
                {1, -3},
                {1, -3}
        },
/* I */
        {
                {1, -3},
                {1, -3},
                {1, -3},
                {1, -3}
        },
/* L */
        {
                {1, -3},
                {1, -3},
                {1, -3},
                {1, -3}
        },
/* L mirrored */
        {
                {1, -3},
                {1, -3},
                {1, -3},
                {1, -3}
        },
/* N */
        {
                {1, -3},
                {1, -3},
                {1, -3},
                {1, -3}
        },
/* N mirrored */
        {
                {1, -3},
                {1, -3},
                {1, -3},
                {1, -3}
        },
/* T */
        {
                {1, -3},
                {1, -3},
                {1, -3},
                {1, -3}
        },
};

// draws a tetromino
void Tetromino::draw()
{
    int k = 0;
    yOffset += yPos; // if a keyboard hit than updates the y offset
    xOffset += xPos;// if a keyboard hit than updates the x offset
    for(int i = 0; i < YRANGE; i++)
    {
        for (int j = 0; j < XRANGE; j++)
        {
            if(mTetrominoes[piece][rotation][i][j] != 0) {
//                if (j > this->xOffset)
//                    this->xOffset++; // updates the offset to prevent crashing borders
                gotoxy(board.getInitialX() + getXInitPos(piece, rotation) + j + this->xOffset, board.getInitialY() + getYInitPos(piece, rotation) + i + this->yOffset);
                std::cout << figure;
                this->currX[k] = board.getInitialX() + getXInitPos(piece, rotation) + j + this->xOffset; // saves the block x
                this->currY[k] = board.getInitialY() + getYInitPos(piece, rotation) + i + this->yOffset;// saves the block y
                k++;
                if (k == NUMOFBLOCKS) // if already printed four blocks return
                    return;
            }
        }
    }
}

//gets the leftmost block of tetromino x coordinate
int Tetromino::getLeftmostX()const
{
    int min = currX[0];
    for(int i = 1; i < NUMOFBLOCKS; i++)
        if(currX[i] < min)
            min = currX[i];

    return min;
}

//gets the rightmost block of tetromino x coordinate
int Tetromino::getRightmostX()const
{
    int max = currX[0];
    for(int i = 1; i < NUMOFBLOCKS; i++)
        if(currX[i] > max)
            max = currX[i];

    return max;
}

// the function returns 1 if the specific block in the tetromino matrix is filled
int Tetromino::getSquareType(int pPiece, int pRotation, int pX, int pY)const
{
    return mTetrominoes[pPiece][pRotation][pX][pY];
}

//deletes the tetromino last position
void Tetromino::clearTetromino()
{
    for(int i = 0; i < NUMOFBLOCKS; i++)
    {
        gotoxy(getCurrX(i), getCurrY(i));
        std::cout << ' ';
    }
}
int Tetromino::getXInitPos(int tPiece, int tRotation)const
{
    return mInitPos[tPiece][tRotation][0];
}
int Tetromino::getYInitPos(int tPiece, int tRotation)const
{
    return mInitPos[tPiece][tRotation][1];
}

// moves the tetromino down the board
void Tetromino::down()
{
    if(getOffsetY() < board.getRows()-1)
    {
        if (!isPossible(getXlogicCoord(getOffsetX()),getOffsetY() + 1, getBlockType(), getBlockRotation()))
        {
            storePiece(getXlogicCoord(getOffsetX()), getOffsetY(), getBlockType(), getBlockRotation());
            stored = true;
            drop[numBoard] = false;
            initOffsetX();
            initOffsetY();
            //draws a new random tetromino
            draw();
        } else {
            clearTetromino();
            yOffset++;
            draw();
            if(drop[numBoard])
                Sleep(1);
            else
                Sleep(400); // TEST
        }
    }
    else
    {
        storePiece(getXlogicCoord(getOffsetX()),getOffsetY(), getBlockType(),getBlockRotation());
        stored = true;
        drop[numBoard] = false;
        //draws a new random tetromino
        initOffsetX();
        initOffsetY();
        draw();
    }
}

void Tetromino::move(int dir)
{
    switch (dir) {
        case Board::LEFT_KEY :
            xOffset--;
            moveLeftRight(-1);
            break;
        case Board::RIGHT_KEY :
            xOffset++;
            moveLeftRight(1);
            break;
        case Board::ROTATE_CLOCKWISE :
            rotation++;
            rotate(1);
            break;
        case Board::ROTATE_COUNTERCLOCKWISE:
            rotate(-1);
            break;
        case Board::DROP :
        {
            dropIt();
            break;
        }
    }
}
//TODO:: missing right border check
void Tetromino::moveLeftRight(int newOffset) {
    if (getLeftmostX() > (board.getInitialX() + 1)) {
        if(isPossible(getXlogicCoord(getOffsetX()) + newOffset, getOffsetY(), getBlockType(), getBlockRotation())) {
            xOffset += newOffset;
            clearTetromino();
            draw();
        }
    }
}

void Tetromino::rotate(int newOffset) {
    if(isPossible(getXlogicCoord(getOffsetX()), getOffsetY(), getBlockType(), (getBlockRotation() + newOffset) % ROTATION)) {
        rotation = (rotation + newOffset) % ROTATION;
        clearTetromino();
        draw();
    }
}

void Tetromino::dropIt() {
    drop[numBoard] = true;
//            while(!stored)
    while(drop[numBoard])
    {
        down();
        over = board.isGameOver(); //TEST
        board.deletePossibleLines(); //TEST
        if(over)
            return;
        if(esc_hit)
            return;
        else
            //TODO: this is a wrong recursion
            gameLoop();
    }
}

int Tetromino::getXlogicCoord(int console_x_offset)const
{
    return (console_x_offset + 4);
}

void Tetromino::init(int kind, int rotate) {
    setPiece(kind);
    setRotation(rotate);
}

void Tetromino::keyboardHit(int dir)
{
    move(dir);
    over = board.isGameOver();
    board.deletePossibleLines();
}

const int Tetromino::getNumBoard() const {
    return numBoard;
}

bool Tetromino::isPossible(int pivX, int pivY, int pPiece, int pRotation)const
{
    // This is just to check the 4x4 blocks of a piece with the appropriate area in the board
    for (int i1 = pivX, i2 = 0; i1 < pivX + NUMOFBLOCKS; i1++, i2++)
    {
        for (int j1 = pivY - MATRIX_Y_OFFSET, j2 = 0; j1 < (pivY - MATRIX_Y_OFFSET)  + NUMOFBLOCKS ; j1++, j2++)
        {
            if(j1 >= 0)
                if ((getSquareType(pPiece, pRotation,j2,i2) != 0)  && !board.isFreeBlock(i1,j1) )
                    return false;
            // Check if the piece have collision with a block already stored in the map
        }
    }
    // No collision
    return true;
}

void Tetromino::storePiece(int pivX, int pivY, int pPiece, int pRotation)
{
    int counter = 0;
    for (int i1=pivX,i2 = 0; i1 < pivX+ NUMOFBLOCKS ;i1++,i2++)
    {
        for (int j1 = pivY-MATRIX_Y_OFFSET,j2 = 0; j1 < (pivY-MATRIX_Y_OFFSET) +NUMOFBLOCKS; j1++,j2++)
        {
            if(j1 >= 0)
            {
                if ( getSquareType(pPiece, pRotation,j2,i2) != 0 )
                {
                    board.setBoardPosition(i1, j1);
                    counter++;
                }
                if(counter == NUMOFBLOCKS)
                    return;
            }
        }
    }
}
