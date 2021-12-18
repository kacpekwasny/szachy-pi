//
// Created by jarek on 17.12.2021.
//
#include "board.hpp"

Board::Board(){}

void Board::runInput (std::string inp){
    if ( Board::isKomenda(inp) ){
        runCmd(inp); // wyjdż albo reset planszy?
        return;
    }
    // Poprzez return linijkę wyżej program dojdzie do tego miejsca wyłącznie,
    // jeżeli if się nie wykona. Więc działa to praktycznie jak if/else,
    // ale kod jest ładniejszy
    if (chooseOrMove == choose){ // wybieramy pionek
        bool ok = choosePawn(inp);
    }
}

bool Board::choosePawn(std::string inp){
    return true;
}
//...
