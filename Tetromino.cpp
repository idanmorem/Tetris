#include "Tetromino.h"

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
void Tetromino::draw(int xPos, int yPos, int mPiece, int mRotation, int boardNum)
{
    int k = 0;
    yOffset += yPos; // if a keyboard hit than updates the y offset
    xOffset += xPos;// if a keyboard hit than updates the x offset
    for(int i = 0; i < YRANGE; i++)
    {
        for (int j = 0; j < XRANGE; j++)
        {
            if(mTetrominoes[mPiece][mRotation][i][j] != 0) {
//                if (j > this->xOffset)
//                    this->xOffset++; // updates the offset to prevent crashing borders
                gotoxy(STARTBOARD1 + getXInitPos(piece, rotation) + j + boardNum*(STARTBOARD2-STARTBOARD1) + this->xOffset, INITIALY + getYInitPos(piece, rotation) + i + this->yOffset);
                std::cout << figure;
                this->currX[k] = STARTBOARD1 + getXInitPos(piece, rotation) + j + boardNum*(STARTBOARD2-STARTBOARD1) + this->xOffset; // saves the block x
                this->currY[k] = INITIALY + getYInitPos(piece, rotation) + i + this->yOffset;// saves the block y
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