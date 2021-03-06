//
// Created by jarek on 17.12.2021.
//
#include "plansza.hpp"

#include <vector>

#include "def_typow.hpp"
#include "pion_pole.hpp"

Plansza::Plansza() {}

void Plansza::ustawPlansze(kp iloscWierszy_, kp iloscKolumn_) {
    this->iloscWierszy = iloscWierszy_;
    this->iloscKolumn = iloscKolumn_;

    // juz uzywamy `new`, wiec poprzez petle deletuje wszystkie pola
    for (auto wiersz: this->pola) {
        for (auto pole: wiersz) {
            delete pole;
        }
    }
    this->pola.clear();


    // inicjalizacja pol (planszy de fakto)
    bool poleBiale = false;
    for (kp w = 0; w < iloscWierszy_; w++) {
        std::vector<Pole *> wiersz;
        for (kp k = 0; k < iloscKolumn_; k++) {
            Pole *p = new Pole(w, k, poleBiale);
            poleBiale = !poleBiale;
            wiersz.push_back(p);
        }
        this->pola.push_back(wiersz);
    }
}

void Plansza::zdejmijPionkiZPlanszy() {
    // wiersze w planszy
    for (auto wiersz: this->pola) {
        // pola w wierszu
        for (auto pole: wiersz) {
            pole->jestZajete = false;
            pole->pionek->zbity = true;
        }
    }
}

void Plansza::usunWszystkiePionki() {
    // this->pionki.clear(); // - teraz uzywamy `new` wiec nie mozna tego robic tak
    for (auto p: this->pionki) {
        delete p;
    }
    // wiersze w planszy
    for (auto wiersz: this->pola) {
        // pola w wierszu
        for (auto pole: wiersz) {
            pole->jestZajete = false;
        }
    }
}

bool Plansza::zapelnijPlanszeLosowo(std::vector<char> pionkiDoUtworzenia) {
    if (pionkiDoUtworzenia.size() >= this->iloscWierszy * this->iloscKolumn - 2) {
        // Jezeli pionkow jest wiecej niz (ilosc pol - 2)
        return false;
    }
    for (auto typPionkaChar: pionkiDoUtworzenia) {
        Pion *pionek = new Pion(true, PIONEK);
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
        this->pionki.push_back(pionek);
    }
    return true;
}

void Plansza::zamienPionekZeZbitym(Pion *p, typyPionkaEnum typPionka) {

    for (auto pZbity: this->pionki) {
        if (pZbity->jestBialy == p->jestBialy
            && pZbity->wezTypPionka() == typPionka) {
            pZbity->ustawTypPionka(p->wezTypPionka());
            p->ustawTypPionka(typPionka);
            return;
        }
    }
}


void Plansza::zapelnijPlanszeRegulaminowo() {
    // plansza jest odpowiedniej wielkosci
    // zapelnij pionkami
    for (kp kolumna = 0; kolumna < 8; ++kolumna) {
        Pion *pionB = new Pion(true, PIONEK);           // pion bialy
        Pion *pionC = new Pion(false, PIONEK);          // pion czarny
        Pole *poleB = this->pola.at(1).at(kolumna);  // pole dla bialego
        Pole *poleC = this->pola.at(6).at(kolumna);  // pole dla czarnego
        pionB->ustawPionekNaPolu(poleB);             // parujemy pole-pionek
        pionC->ustawPionekNaPolu(poleC);             // parujemy pole-pionek
        this->pionki.push_back(pionB);
        this->pionki.push_back(pionC);
    }

    // Krol
    Pion *pionB = new Pion(true, KROL);       // pion bialy
    Pion *pionC = new Pion(false, KROL);      // pion czarny
    Pole *poleB = this->pola.at(0).at(4);  // pole dla bialego
    Pole *poleC = this->pola.at(7).at(3);  // pole dla czarnego
    pionB->ustawPionekNaPolu(poleB);       // parujemy pole-pionek
    pionC->ustawPionekNaPolu(poleC);       // parujemy pole-pionek
    this->pionki.push_back(pionB);
    this->pionki.push_back(pionC);


    // Krolowa
    pionB = new Pion(true, KROLOWA);     // pion bialy
    pionC = new Pion(false, KROLOWA);    // pion czarny
    poleB = this->pola.at(0).at(3);   // pole dla bialego
    poleC = this->pola.at(7).at(4);   // pole dla czarnego
    pionB->ustawPionekNaPolu(poleB);  // parujemy pole-pionek
    pionC->ustawPionekNaPolu(poleC);  // parujemy pole-pionek
    this->pionki.push_back(pionB);
    this->pionki.push_back(pionC);

    // Gonce po prawej
    pionB = new Pion(true, GONIEC);      // pion bialy
    pionC = new Pion(false, GONIEC);     // pion czarny
    poleB = this->pola.at(0).at(5);   // pole dla bialego
    poleC = this->pola.at(7).at(5);   // pole dla czarnego
    pionB->ustawPionekNaPolu(poleB);  // parujemy pole-pionek
    pionC->ustawPionekNaPolu(poleC);  // parujemy pole-pionek
    this->pionki.push_back(pionB);
    this->pionki.push_back(pionC);
    // Gonce po lewej
    pionB = new Pion(true, GONIEC);      // pion bialy
    pionC = new Pion(false, GONIEC);     // pion czarny
    poleB = this->pola.at(0).at(2);   // pole dla bialego
    poleC = this->pola.at(7).at(2);   // pole dla czarnego
    pionB->ustawPionekNaPolu(poleB);  // parujemy pole-pionek
    pionC->ustawPionekNaPolu(poleC);  // parujemy pole-pionek
    this->pionki.push_back(pionB);
    this->pionki.push_back(pionC);

    // Skoczek po prawej
    pionB = new Pion(true, SKOCZEK);     // pion bialy
    pionC = new Pion(false, SKOCZEK);    // pion czarny
    poleB = this->pola.at(0).at(6);   // pole dla bialego
    poleC = this->pola.at(7).at(6);   // pole dla czarnego
    pionB->ustawPionekNaPolu(poleB);  // parujemy pole-pionek
    pionC->ustawPionekNaPolu(poleC);  // parujemy pole-pionek
    this->pionki.push_back(pionB);
    this->pionki.push_back(pionC);
    // Skoczek po lewej
    pionB = new Pion(true, SKOCZEK);     // pion bialy
    pionC = new Pion(false, SKOCZEK);    // pion czarny
    poleB = this->pola.at(0).at(1);   // pole dla bialego
    poleC = this->pola.at(7).at(1);   // pole dla czarnego
    pionB->ustawPionekNaPolu(poleB);  // parujemy pole-pionek
    pionC->ustawPionekNaPolu(poleC);  // parujemy pole-pionek
    this->pionki.push_back(pionB);
    this->pionki.push_back(pionC);

    // Wieza po prawej
    pionB = new Pion(true, WIEZA);       // pion bialy
    pionC = new Pion(false, WIEZA);      // pion czarny
    poleB = this->pola.at(0).at(7);   // pole dla bialego
    poleC = this->pola.at(7).at(7);   // pole dla czarnego
    pionB->ustawPionekNaPolu(poleB);  // parujemy pole-pionek
    pionC->ustawPionekNaPolu(poleC);  // parujemy pole-pionek
    this->pionki.push_back(pionB);
    this->pionki.push_back(pionC);
    // Wieza po lewej
    pionB = new Pion(true, WIEZA);       // pion bialy
    pionC = new Pion(false, WIEZA);      // pion czarny
    poleB = this->pola.at(0).at(7);   // pole dla bialego
    poleC = this->pola.at(7).at(7);   // pole dla czarnego
    pionB->ustawPionekNaPolu(poleB);  // parujemy pole-pionek
    pionC->ustawPionekNaPolu(poleC);  // parujemy pole-pionek
    this->pionki.push_back(pionB);
    this->pionki.push_back(pionC);
}