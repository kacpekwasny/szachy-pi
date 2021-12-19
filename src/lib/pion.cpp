//
// Created by jarek on 17.12.2021.
//
#include "pion.hpp"

#include <cmath>
#include <iostream>

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
    }
};

bool ruchPionkiemDozwolony(kp wiersz, kp kolumna, kp wiersz_, kp kolumna_) {
    if (kolumna_ - kolumna != 0 || wiersz - wiersz_ != 1) {
        /* wykluczam mozliwosc poruszania sie po przekatnych, na boki,
         * do tylu lub o wiecej niz jedno pole do przodu */
        return false;
    }
    return true;
}

bool ruchWiezaDozwolony(kp wiersz, kp kolumna, kp wiersz_, kp kolumna_) {
    if (kolumna_ - kolumna != 0 && wiersz_ - wiersz != 0) {
        /* wykluczam mozliwosc poruszania sie po przekatnych */
        return false;
    }
    return true;
}

bool ruchSkoczkaDozwolony(kp wiersz, kp kolumna, kp wiersz_, kp kolumna_) {
    if (abs(kolumna_ - kolumna) == 3 && abs(wiersz_ - wiersz) == 1) {
        return true;
    } else if (abs(wiersz_ - wiersz) == 3 && abs(kolumna_ - kolumna) == 1) {
        return true;
    }
    return false;
}
