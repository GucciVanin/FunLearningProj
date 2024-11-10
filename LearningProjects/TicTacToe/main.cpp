#include "TicTacToe.cpp"
#include <iostream>

int main(){

    TicTacToe game = TicTacToe();
    std::cout << "Let's Begin!!! The starter will be X" << std::endl;

    while(game.win != true){
        
        game.printBoard();

        std::cout << "Type its coordinates for the input \"xAxis, yAxis\"" << std::endl;

        int xAxis, yAxis;

        std::cin >> xAxis >> yAxis;

        game.makeMove(yAxis, xAxis);
        
    }

    game.printBoard();
    game.playerChange();
    std::cout << "Congrats for the win " << game._player << std::endl;
}