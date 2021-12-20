#include <iostream>
#include <string>
#include <vector>

#include "def_typow.hpp"
#include "pion_pole.hpp"

// Plansza - plansza
class plansza {
   private:
    // pola[wiersze][kolumny]
    std::vector<std::vector<Pole *>> pola;
    std::vector<Pion *> pionki;

    // inicjalizacja pol planszy
    plansza(kp iloscWierszy, kp iloscKolumn);

   public:
    const std::vector<std::vector<Pole *>> wezPola() { return pola; }
    const std::vector<Pion *> wezPionki() { return pionki; }

    // plansza zawsze ma tyle samo pull
    plansza();

    // TODO
    // rozmiesc pionki przypadkowo
    // argument to np.: {'R', 'R', 'G', 'P', 'P', 'P', 'P', 'S'}
    void zapelnijPlanszeLosowo(std::vector<char>);

    // TODO
    // czyli
    void zapelnijPlanszeRegulaminowo();
    /*
        Resetuje pionki i pola tablicy
    */
    void reset();

    // void render(); -> przeniesione do `class Interfejs`
    // void setText(); -> przeniesione do `class Interfejs`
};