// TIC TAC TOE Game for learning simple UI with C++
#pragma once

#include <string>
#include <array>
#include <initializer_list>


class TicTacToe{
    private:
        char _gameBoard[3][3] = {{' ',' ', ' '}, {' ', ' ', ' '}, {' ',' ',' '}};
        
        
        

    public:
        char _player = 'X';
        bool win = false;

        //Constructor and Destructor
        TicTacToe();
        ~TicTacToe();

        TicTacToe makeMove(int xAxis, int yAxis);

        bool checkAdjacent(int xAxis, int yAxis);
        bool validMove(int xAxis, int yAxis);
        void playerChange();

        void printBoard();

};