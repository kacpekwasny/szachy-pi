#include <iostream>
#include <string>
#include <vector>

#include "Pole.hpp"
#include "def_typow.hpp"
#include "pion.hpp"  //zmiana z <> na "", cudzysłowia są do lokalnych bibliotek

// Plansza - plansza
class Plansza {
   private:
    // pola[wiersze][kolumny]
    std::vector<std::vector<Pole *>> pola;
    std::vector<Pion *> pionki;

    // inicjalizacja pol planszy
    Plansza(kp iloscWierszy, kp iloscKolumn);

   public:
    const std::vector<std::vector<Pole *>> wezPola() { return pola; }
    const std::vector<Pion *> wezPionki() { return pionki; }

    // plansza zawsze ma tyle samo pull
    Plansza();

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