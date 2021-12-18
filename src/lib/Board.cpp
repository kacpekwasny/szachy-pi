//
// Created by jarek on 17.12.2021.
//
#include "board.hpp"

Pole::Pole(int x, int y) {
    this->x =x;
    this->y=y;
}

void Board::render() {
    static const std::string bierki[]={"\u2654","\u2655","\u2656","\u2657","\u2658","\u2659","\u265a","\u265B","\u265C","\u265D","\u265E","\u265F"};
    for(std::string s:bierki){
        std::cout<<s;
    }
    std::cout<<"\n\t\t\tA\tB \tC \tD \tE \tF \tG \tH\n"
             <<"\n";
    for(int i =0;i<8;i++){
        std::cout<<"\t"<<i+1<<"\t\t";
        for(int j=0;j<8;j++){
            std::cout<<(plansza[i][j].isZajete?bierki[plansza[i][j].typBierki]+"\t":".\t");
        }
        std::cout<<"\t"<<i+1;
        std::cout<< std::endl;
    }
    std::cout<<"\n"
             <<"\t\t\tA \tB \tC \tD \tE \tF \tG \tH\n";
}
Board::Board(){
    plansza = new Pole*[8];
    for(int i =0;i<8;i++){
        plansza[i]= new Pole[8];
        for(int j=0;j<8;j++){
            plansza[i][j] = Pole(i+1,j+1);
        }
    }
    Pole *p=&plansza[3][3];
    p->isZajete=true;
    p->typBierki=9;
    p = &plansza[6][5];
    p->isZajete=true;
    p->typBierki=10;
    p = &plansza[6][2];
    p->isZajete=true;
    p->typBierki=11;
}

Board::~Board() {
    for(int i =0;i<8;i++){
        delete plansza[i];
    }
    delete plansza;
}
bool Board::isKomenda(std::string) {
    return false;
}
void Board::runCmd(std::string) {}
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

