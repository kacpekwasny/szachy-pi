//
// Created by jarek on 17.12.2021.
//
#include "board.hpp"

Board::Board(){}

void Board::runInput (std::string inp){
        if ( Board::isKomenda(inp) ){
        runCmd(inp); // wyjdż albo reset planszy?
        //return;
    }
    // samego else nie trzeba bo powyżej jest 'return', więc technicznie działa tak samo,
    // a nie trzeba zagnieżdżać
    // else, czyli inp zawiera pole (np.: "D5"...)
    if (chooseOrMove == choose){ // wybieramy pionek
        bool ok = choosePawn(inp);
    }
}

bool Board::choosePawn(std::string inp){
    return true;
}
//...
