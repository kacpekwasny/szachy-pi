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

    // DONE
    void ustawPlansze(kp wiersze, kp kolumny);
    // ustawia wszystkie wszystkie `pionki.jestZbity = true;`
    // oraz wszystkie pola zaznacza na `pole.jestZajete = false`
    void zdejmijPionkiZPlanszy();

    // void wyczyscPlansze(); -pokrywająca się funkcjonalność z zdejmijPionkiZPlanszy()

    // TODO
    // wyczysc vector z pioinkami
    // zreesetuj stan pol na jestZajete=false
    void usunWszystkiePionki();

    // TODO
    // rozmiesc pionki przypadkowo
    // argument to np.: {'R', 'R', 'G', 'P', 'P', 'P', 'P', 'S'}
    bool zapelnijPlanszeLosowo(std::vector<char>);

    // TODO
    // czyli 16 pionkami
    // gdyby plansza byla wieksza, to mozna zrobic tak, ze jakos skaluje liczbe pionkow czy cos
    // to zalezy od weny tworczej autora
    void zapelnijPlanszeRegulaminowo();

    // void render(); -> przeniesione do `class Interfejs`
    // void setText(); -> przeniesione do `class Interfejs`
};