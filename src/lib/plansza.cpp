//
// Created by jarek on 17.12.2021.
//
#include "Plansza.hpp"
#include <regex>

Plansza::Plansza(kp iloscWierszy, kp iloscKolumn) {
    // inicjalizacja pol (planszy de fakto)
    for (kp w = 0; w < iloscWierszy; w++) {
        std::vector<Pole *> wiersz;

        for (kp k = 0; k < iloscKolumn; k++) {
            Pole *p;
            p->isZajete = false;
            p->kolumna = k;
            p->wiersz = w;
            wiersz.push_back(p);
        }
        pola.push_back(wiersz);
    }
}
Plansza::Plansza() :Plansza(8,8) {

}

Plansza::~Plansza() {
    for (int i = 0; i < 8; i++) {
        delete plansza[i];
    }
    delete plansza;
}
