//
// Created by jarek on 17.12.2021.
//
#include "pion.hpp"

#include "def_typow.hpp"

bool Pion::ruchDozwolony(kp wiersz, kp kolumna) {
    switch (this->typPionka) {
        case PIONEK:
            return this->ruchPionkiemDozwolony(wiersz, kolumna);
        case SKOCZEK:
            return this->ruchSkoczkiemDozwolony(wiersz, kolumna);
        case KROL:
            return this->ruchKrolemDozwolony(wiersz, kolumna);
        case WIEZA:
            return this->ruchWiezaDozwolony(wiersz, kolumna);
        default:
            // nie powinno dojsc do tego poniewaz, typ pionka nie moze miec innej wartosci niz te wymienione powyzej
            break;
    };
}
