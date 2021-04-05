cmake_minimum_required(VERSION 3.17)
project(Tetris)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Tetris
        Board.cpp
        Board.h
        IO.cpp
        IO.h
        main.cpp
        Tetromino.cpp
        Tetromino.h
        TheGame.cpp
        TheGame.h)
