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

   public:
    std::vector<Pion *> pionki;

    // inicjalizacja pol planszy
    Plansza(kp iloscWierszy, kp iloscKolumn);

    void przypadkoweRozmieszczeniePionow() {}

    /*
        Resetuje pionki i pola tablicy
    */
    void reset();

    // void render(); -> przeniesione do `class Interfejs`

    // void setText(); -> przeniesione do `class Pion`
};