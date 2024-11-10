#include "TicTacToe.hpp";

#include <string>
#include <array>
#include <random>
#include <iostream>

TicTacToe::TicTacToe(){};

TicTacToe::~TicTacToe(){};

TicTacToe TicTacToe::makeMove(int xAxis, int yAxis) {
    if(!validMove(xAxis, yAxis)) return *this;

    _gameBoard[xAxis][yAxis] = _player;
    win = checkAdjacent(xAxis, yAxis);

    playerChange();

    return *this;
};

bool TicTacToe::checkAdjacent(int xAxis, int yAxis){

    if(xAxis == 1 && yAxis == 1 && _gameBoard[xAxis - 1][yAxis + 1] == _player && _gameBoard[xAxis + 1][yAxis - 1] == _player) return true;

    if(xAxis == 1 && yAxis == 1 && _gameBoard[xAxis - 1][yAxis - 1] == _player && _gameBoard[xAxis + 1][yAxis + 1] == _player) return true;

    for(size_t i = 0; i < 3; ++i){
        if (_gameBoard[i][0] == _player && _gameBoard[i][1] == _player 
            && _gameBoard[i][2] == _player) 
            return true; 
        if (_gameBoard[0][i] == _player && _gameBoard[1][i] == _player 
            && _gameBoard[2][i] == _player) 
            return true; 
    }

    return false;
};

bool TicTacToe::validMove(int xAxis, int yAxis){
    return _gameBoard[xAxis][yAxis] == ' ';
}

void TicTacToe::playerChange(){
    _player = (_player == 'X') ? _player = 'O' : _player = 'X';
};

void TicTacToe::printBoard(){
    std::cout << "-------------\n"; 
    for (int i = 0; i < 3; i++) { 
        std::cout << "| "; 
        for (int j = 0; j < 3; j++) { 
            std::cout << _gameBoard[i][j] << " | "; 
        } 
        std::cout << "\n-------------\n"; 
    } 
}




