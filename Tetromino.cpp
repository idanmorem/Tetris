#include "Tetromino.h"

void Tetromino::setColor(Color c)
{
    color = c;
}


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

int mInitPos [PIECES_KINDS][ROTATION][POSITION] = {
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

int Tetromino::getXInitPos(int tPiece, int tRotation)
{
    return mInitPos[tPiece][tRotation][0];
}

int Tetromino::getYInitPos(int tPiece, int tRotation)
{
    return mInitPos[tPiece][tRotation][1];
}

void Tetromino::draw(int piece, int rotation, int boardNum)
{
    for(int i = 0; i < YRANGE; i++)
    {
        for (int j = 0; j < XRANGE; j++)
        {
            if(mTetrominoes[piece][rotation][i][j] != 0) {
                gotoxy(STARTBOARD1 + getXInitPos(piece, rotation) + j + boardNum*(STARTBOARD2-STARTBOARD1), INITIALY + getYInitPos(piece, rotation) + i);
                std::cout << figure;
            }
        }
    }
}

int Tetromino::GetBlockType (int piece, int rotation, int x, int y)
{
    return mTetrominoes[piece][rotation][x][y];
}
