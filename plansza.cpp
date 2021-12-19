//
// Created by mateusz on 16.12.2021.
//

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#include "plansza.hpp"

// ZNAKI CHAR DO PLANSZY
// 179 pionowa kreska
// 180 pionowa kreska ze środkiem prawa
// 195 pionowa kreska ze środkiem lewa
// 197 krzyżyk środek
// 196 pozioma kreska
// 191 prawy górny róg
// 193 pozioma kreska dolna
// 194 pozioma kreska górna
// 192 lewy dolny róg
// 217 prawy dolny róg
// 218 lewy górny róg

char plansza[17][33] = { ' ' };

int tabPozycjaX[4];
int tabX[4];
int tabPozycjaY[4];
int tabY[4];

int tabPosition[8];
int tab[8];

void pionowe(int w) {

    for (int i = 0; i < 33; i += 4) {
        plansza[w][i] = char(179);
    }

    for (int i = 1; i < 33; i += 4) {
        plansza[w][i] = char(32);
        plansza[w][i + 1] = char(32);
        plansza[w][i + 2] = char(32);
    }
}

void krzyze(int w) {

    plansza[w][0] = char(195);

    for (int i = 1; i < 33; i += 4) {
        plansza[w][i] = char(196);
        plansza[w][i + 1] = char(196);
        plansza[w][i + 2] = char(196);
    }

    for (int i = 4; i < 33; i += 4) {
        plansza[w][i] = char(197);
    }

    plansza[w][32] = char(180);
}

void createBoard() {

    //ZEROWY RZĄD (GÓRA)
    plansza[0][0] = char(218);

    for (int i = 1; i < 31; i += 2) {
        plansza[0][i] = char(196);
        i++;
        plansza[0][i] = char(196);
        i++;
        plansza[0][i] = char(196);
    }

    for (int i = 4; i < 31; i += 4) {
        plansza[0][i] = char(194);
    }

    plansza[0][32] = char(191);

    for (int i = 1; i <= 14; i+=2) {
        pionowe(i);
        krzyze(i + 1);
    }
    pionowe(15);

    //OSTATNI RZĄD (DÓŁ)
    plansza[16][0] = char(192);

    for (int i = 1; i < 33; i += 4) {
        plansza[16][i] = char(196);
        plansza[16][i + 1] = char(196);
        plansza[16][i + 2] = char(196);
    }

    for (int i = 4; i < 33; i += 4) {
        plansza[16][i] = char(193);
    }

    plansza[16][32] = char(217);
}

void showBoard() {

    //WSPÓŁRZĘDNE GÓRNE (A-H)
    std::cout << std::endl;
    std::cout << char(32) << char(32);
    for (int i = 65; i < 73; i++) {
        std::cout << char(32) << char(32) << char(32) << char(i);
    }
    std::cout << std::endl;

    //PIONOWE WSPÓŁRZĘDNE PLANSZY (1-8) & CAŁA TABLICA
    int licznik = 1; 
    for (int w = 0; w < 17; w++) {
        if (w % 2 != 0) {
            std::cout << char(32) << licznik << " ";
            licznik++;
        }
        else
            std::cout << char(32) << char(32) << " ";
        for (int k = 0; k < 33; k++) {
            std::cout << plansza[w][k];
        }
        std::cout << std::endl;
    }
}
/*
void generatePositionY() {
    // 0123456789......................32
    // │   │   │   │   │   │   │   │   │

    srand(time(NULL));

    for (int i = 0; i < 4; i++) {
        tabY[i] = (rand() % 8) + 1;
        tabPozycjaY[i] = tabY[i] + (tabY[i] - 1) * 3 + 1;
    }
}

void generatePositionX() {
    // 1 3 5 7 ...
    srand(time(NULL));

    for (int i = 0; i < 4; i++) {
        tabX[i] = (rand() % 8) + 1;
        tabPozycjaX[i] = tabX[i] + (tabX[i] - 1);
    }
}
*/
void generatePositions() {

    srand(time(NULL));
    //x 1 3 5 7 ...
    for (int i = 0; i < 4; i++) {
        tab[i] = (rand() % 8) + 1;
        tabPosition[i] = tab[i] + (tab[i] - 1);
    }
    //y 2 6 10 ...
    for (int i = 4; i < 8; i++) {
        tab[i] = (rand() % 8) + 1;
        tabPosition[i] = tab[i] + (tab[i] - 1) * 3 + 1;
    }
}

void setFigures() {

    plansza[tabPosition[0]][tabPosition[4]] = 'W';
    plansza[tabPosition[1]][tabPosition[5]] = 'S';
    plansza[tabPosition[2]][tabPosition[6]] = 'P';
    plansza[tabPosition[3]][tabPosition[7]] = 'K';
}