//
// Created by jarek on 17.12.2021.
//
#include "pion.hpp"

#include <cmath>
#include <iostream>

#include "def_typow.hpp"

bool Pion::ruchDozwolony(kp wiersz, kp kolumna) { return false; }

bool Pion::ruchPionkiemDozwolony(kp wiersz, kp kolumna) {
    if (kolumna_ - this->kolumna_ != 0 || wiersz - this->wiersz_ != 1) {
        /* wykluczam mozliwosc poruszania sie po przekatnych, na boki,
         * do tylu lub o wiecej niz jedno pole do przodu */
        return false;
    }
    return true;
}

bool Pion::ruchWiezaDozwolony(kp wiersz, kp kolumna) {
    if (this->kolumna_ - kolumna != 0 && this->wiersz_ - wiersz != 0) {
        /* wykluczam mozliwosc poruszania sie po przekatnych */
        return false;
    }
    return true;
}

bool Pion::ruchSkoczkiemDozwolony(kp wiersz, kp kolumna) {
    if (abs(this->kolumna_ - kolumna) == 3 && abs(this->wiersz_ - wiersz) == 1) {
        return true;
    } else if (abs(this->wiersz_ - wiersz) == 3 && abs(this->kolumna_ - kolumna) == 1) {
        return true;
    }
    return false;
}
