//
// Created by jarek on 17.12.2021.
//
#include "Plansza.hpp"

#include <random>
#include <vector>

#include "def_typow.hpp"
#include "pion_pole.hpp"

void Plansza::ustawPlansze(kp iloscWierszy, kp iloscKolumn) {
    this->iloscWierszy = iloscWierszy;
    this->iloscKolumn = iloscKolumn;

    // czy tu bedzie memory leak? Nie używamy 'new' nigdzie
    this->pola.clear();

    // inicjalizacja pol (planszy de fakto)
    bool poleBiale = false;
    for (kp w = 0; w < iloscWierszy; w++) {
        std::vector<Pole *> wiersz;
        for (kp k = 0; k < iloscKolumn; k++) {
            Pole *p = &Pole(w, k, poleBiale);
            poleBiale = !poleBiale;
            wiersz.push_back(p);
        }
        pola.push_back(wiersz);
    }
}

void Plansza::zdejmijPionkiZPlanszy() {
    // wiersze w planszy
    for (auto wiersz : this->pola) {
        // pola w wierszu
        for (auto pole : wiersz) {
            pole->jestZajete = false;
            pole->pionek->ustawZbity(true);
        }
    }
}

void Plansza::usunWszystkiePionki() {
    this->pionki.clear();
    // wiersze w planszy
    for (auto wiersz : this->pola) {
        // pola w wierszu
        for (auto pole : wiersz) {
            pole->jestZajete = false;
        }
    }
}

bool Plansza::zapelnijPlanszeLosowo(std::vector<char> pionkiDoUtworzenia) {
    if (pionkiDoUtworzenia.size() >= this->iloscWierszy * this->iloscKolumn - 2) {
        // Jezeli pionkow jest wiecej niz (ilosc pol - 2)
        return false;
    }
    for (auto typPionkaChar : pionkiDoUtworzenia) {
        Pion *pionek = &Pion(true);
        pionek->ustawTypPionkaPoLiterze(typPionkaChar);
        kp wiersz;
        kp kolumna;
        Pole *pole;
        do {
            wiersz = std::rand() % this->iloscWierszy;
            kolumna = std::rand() % this->iloscKolumn;
            pole = this->pola.at(wiersz).at(kolumna);
        } while (pole->jestZajete);
        pole->pionek = pionek;
        pionek->ustawPionekNaPolu(pole);
    }
    return true;
}

void Plansza::zapelnijPlanszeRegulaminowo() {
    // plansza jest odpowiedniej wielkosci
    // zapelnij pionkami
    for (kp kolumna = 0; kolumna < 8; ++kolumna) {
        Pion *pionB = &Pion(true);                   // pion bialy
        Pion *pionC = &Pion(false);                  // pion czarny
        Pole *poleC = this->pola.at(6).at(kolumna);  // pole dla czarnego
        Pole *poleB = this->pola.at(1).at(kolumna);  // pole dla czarnego
        pionB->ustawPionekNaPolu(poleB);             // parujemy pole-pionek
        pionC->ustawPionekNaPolu(poleC);             // parujemy pole-pionek
    }
}