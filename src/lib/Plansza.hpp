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

    // inicjalizacja pol planszy
    Plansza(kp iloscWierszy, kp iloscKolumn);

   public:
    const std::vector<std::vector<Pole *>> wezPola() { return pola; }
    const std::vector<Pion *> wezPionki() { return pionki; }

    Plansza();

    // TODO
    // usuwa dotychczasowa plansze i ustawia nowa
    void ustawPlansze(kp wiersze, kp kolumny);

    // TODO
    // ustawia wszystkie wszystkie `pionki.jestZbity = true;`
    // oraz wszystkie pola zaznacza na `pole.jestZajete = false`
    void wyczyscPlansze();

    // TODO
    // wyczysc vector z pioinkami
    // zreesetuj stan pol na jestZajete=false
    void usunWszystkiePionki();

    // TODO
    void zdejmijPionkiZPlanszy();

    // TODO
    // rozmiesc pionki przypadkowo
    // argument to np.: {'R', 'R', 'G', 'P', 'P', 'P', 'P', 'S'}
    void zapelnijPlanszeLosowo(std::vector<char>);

    // TODO
    // czyli 16 pionkami
    // gdyby plansza byla wieksza, to mozna zrobic tak, ze jakos skaluje liczbe pionkow czy cos
    // to zalezy od weny tworczej autora
    void zapelnijPlanszeRegulaminowo();

    // void render(); -> przeniesione do `class Interfejs`
    // void setText(); -> przeniesione do `class Interfejs`
};