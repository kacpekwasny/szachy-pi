#ifndef PLANSZA_HPP_GUARD
#define PLANSZA_HPP_GUARD

#include <iostream>
#include <string>
#include <vector>

#include "def_typow.hpp"
#include "pion_pole.hpp"

// Plansza - plansza
class Plansza {
   private:
    // pola[wiersze][kolumny]
    std::vector<std::vector<Pole *>> pola;
    std::vector<Pion *> pionki;

    kp iloscWierszy;
    kp iloscKolumn;

    // inicjalizacja pol planszy
    // Plansza(kp iloscWierszy, kp iloscKolumn); - usuwam ponieważ ta funkcjonalność
    // ma należeć do ustawPlansze()

   public:
    const std::vector<std::vector<Pole *>> wezPola() { return pola; }
    const std::vector<Pion *> wezPionki() { return pionki; }

    Plansza();
    // kasuje pola planszy

    // i tworzy nowe pola planszy o wielkosci wiersze x kolumny
    void ustawPlansze(kp wiersze, kp kolumny);

    // ustawia wszystkie wszystkie `pionki.jestZbity = true;`
    // oraz wszystkie pola zaznacza na `pole.jestZajete = false`
    void zdejmijPionkiZPlanszy();

    // void wyczyscPlansze(); -pokrywająca się funkcjonalność z zdejmijPionkiZPlanszy()

    // wyczysc vector z pioinkami
    // zreesetuj stan pol na jestZajete=false
    void usunWszystkiePionki();

    // rozmiesc pionki przypadkowo
    // argument to np.: {'R', 'R', 'G', 'P', 'P', 'P', 'P', 'S'}
    bool zapelnijPlanszeLosowo(std::vector<char>);

    //
    void zapelnijPlanszeRegulaminowo();

    // Wez pionek 'p' i zamien miejscami z pionkiem zbitym tego samego koloru o sprecyzowanym typie.
    void zamienPionekZeZbitym(Pion* p, typyPionkaEnum);
    // void render(); -> przeniesione do `class Interfejs`
    // void setText(); -> przeniesione do `class Interfejs`
};

#endif