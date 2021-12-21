//
// Created by jarek on 17.12.2021.
//
#include "plansza.hpp"

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
            pole->pionek->zbity = true;
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
        Pion *pionek = &Pion(true, PIONEK);
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
        Pion *pionB = &Pion(true, PIONEK);           // pion bialy
        Pion *pionC = &Pion(false, PIONEK);          // pion czarny
        Pole *poleB = this->pola.at(1).at(kolumna);  // pole dla bialego
        Pole *poleC = this->pola.at(6).at(kolumna);  // pole dla czarnego
        pionB->ustawPionekNaPolu(poleB);             // parujemy pole-pionek
        pionC->ustawPionekNaPolu(poleC);             // parujemy pole-pionek
    }

    // Krol
    Pion *pionB = &Pion(true, KROL);       // pion bialy
    Pion *pionC = &Pion(false, KROL);      // pion czarny
    Pole *poleB = this->pola.at(0).at(4);  // pole dla bialego
    Pole *poleC = this->pola.at(7).at(3);  // pole dla czarnego
    pionB->ustawPionekNaPolu(poleB);       // parujemy pole-pionek
    pionC->ustawPionekNaPolu(poleC);       // parujemy pole-pionek

    // Krolowa
    pionB = &Pion(true, KROLOWA);     // pion bialy
    pionC = &Pion(false, KROLOWA);    // pion czarny
    poleB = this->pola.at(0).at(3);   // pole dla bialego
    poleC = this->pola.at(7).at(4);   // pole dla czarnego
    pionB->ustawPionekNaPolu(poleB);  // parujemy pole-pionek
    pionC->ustawPionekNaPolu(poleC);  // parujemy pole-pionek

    // Gonce po prawej
    pionB = &Pion(true, GONIEC);      // pion bialy
    pionC = &Pion(false, GONIEC);     // pion czarny
    poleB = this->pola.at(0).at(5);   // pole dla bialego
    poleC = this->pola.at(7).at(5);   // pole dla czarnego
    pionB->ustawPionekNaPolu(poleB);  // parujemy pole-pionek
    pionC->ustawPionekNaPolu(poleC);  // parujemy pole-pionek
    // Gonce po lewej
    pionB = &Pion(true, GONIEC);      // pion bialy
    pionC = &Pion(false, GONIEC);     // pion czarny
    poleB = this->pola.at(0).at(2);   // pole dla bialego
    poleC = this->pola.at(7).at(2);   // pole dla czarnego
    pionB->ustawPionekNaPolu(poleB);  // parujemy pole-pionek
    pionC->ustawPionekNaPolu(poleC);  // parujemy pole-pionek

    // Skoczek po prawej
    pionB = &Pion(true, SKOCZEK);     // pion bialy
    pionC = &Pion(false, SKOCZEK);    // pion czarny
    poleB = this->pola.at(0).at(6);   // pole dla bialego
    poleC = this->pola.at(7).at(6);   // pole dla czarnego
    pionB->ustawPionekNaPolu(poleB);  // parujemy pole-pionek
    pionC->ustawPionekNaPolu(poleC);  // parujemy pole-pionek
    // Skoczek po lewej
    pionB = &Pion(true, SKOCZEK);     // pion bialy
    pionC = &Pion(false, SKOCZEK);    // pion czarny
    poleB = this->pola.at(0).at(1);   // pole dla bialego
    poleC = this->pola.at(7).at(1);   // pole dla czarnego
    pionB->ustawPionekNaPolu(poleB);  // parujemy pole-pionek
    pionC->ustawPionekNaPolu(poleC);  // parujemy pole-pionek

    // Wieza po prawej
    pionB = &Pion(true, WIEZA);       // pion bialy
    pionC = &Pion(false, WIEZA);      // pion czarny
    poleB = this->pola.at(0).at(7);   // pole dla bialego
    poleC = this->pola.at(7).at(7);   // pole dla czarnego
    pionB->ustawPionekNaPolu(poleB);  // parujemy pole-pionek
    pionC->ustawPionekNaPolu(poleC);  // parujemy pole-pionek
    // Wieza po lewej
    pionB = &Pion(true, WIEZA);       // pion bialy
    pionC = &Pion(false, WIEZA);      // pion czarny
    poleB = this->pola.at(0).at(7);   // pole dla bialego
    poleC = this->pola.at(7).at(7);   // pole dla czarnego
    pionB->ustawPionekNaPolu(poleB);  // parujemy pole-pionek
    pionC->ustawPionekNaPolu(poleC);  // parujemy pole-pionek
}