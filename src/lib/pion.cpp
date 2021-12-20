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
            // TODO
            // KROLOWA
            // GONIEC
        default:
            // nie powinno dojsc do tego poniewaz, typ pionka nie moze miec innej wartosci niz te wymienione powyzej
            break;
    }
};

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

bool Pion::ruchGoncaDozwolony(kp wiersz, kp kolumna){
    if(abs(this->kolumna_ - kolumna) == abs(this->wiersz_ - wiersz){
        return true;
    }
    return false;
}

bool Pion::ruchKrolowejDozwolony(kp wiersz, kp kolumna){
    if(abs(this->kolumna_ - kolumna) == abs(this->wiersz_ - wiersz){
        return true;
    } else if(abs(this->kolumna_ - kolumna) == 0 || abs(this->wiersz_ - wiersz) == 0){
        return true;
    }
    return false;
}

void Pion::ustawKoordynatyPionka(kp wiersz, kp kolumna) {
    this->wiersz_ = wiersz;
    this->kolumna_ = kolumna;
}

char Pion::wezLitere() {
    switch (this->typPionka) {
        case KROLOWA:
            return 'H';
        case GONIEC:
            return 'G';
        case SKOCZEK:
            return 'S';
        case WIEZA:
            return 'W';
        case KROL:
            return 'K';
        case PIONEK:
            return 'P';
        default:
            // nie powinno dojsc do tego poniewaz, typ pionka nie moze miec innej wartosci niz te wymienione powyzej
            break;
    }
}

bool Pion::ustawTypPionkaPoLiterze(char l) {
    const char toUpper = 32;
    switch (l + toUpper) {
        case 'H':
            this->typPionka = KROLOWA;
            return true;
        case 'G':
            this->typPionka = GONIEC;
            return true;
        case 'S':
            this->typPionka = SKOCZEK;
            return true;
        case 'W':
            this->typPionka = WIEZA;
            return true;
        case 'K':
            this->typPionka = KROL;
            return true;
        case 'P':
            this->typPionka = PIONEK;
            return true;
        default:
            return false;
    }
}
