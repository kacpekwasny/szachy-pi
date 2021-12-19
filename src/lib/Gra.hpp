/*
    Gra.hpp
    Kacper Kwaśny 19.12.2021
*/

#include <string>
#include <vector>

#include ""
#include "Plansza.hpp"
#include "Pole.hpp"

class Gra {
   private:
    enum chooseOrMoveEnum { choose, move };
    chooseOrMoveEnum chooseOrMove = choose;  // zawiera informacje o przeznaczeniu kolejnego inputu

    Plansza* plansza;

    // funkcja majaca byc wykonywana po kadzym ruchu, na razie jedyna funkcjonalnosc to zmiana pionka na
    void poWykonanymRuchu();

   public:
    // Wielkosc planszy
    // ilosc pionkow
    Gra();

    // zwroc plansze w formie "getPlansza"
    std::vector<std::vector<Pole*>> wezPlansze();

    // TODO
    void resetPlansze();

    // TODO
    // rozmiesc pionki przypadkowo
    void zapelnijPlanszeLosowo(std::vector<char>);

    // TODO
    //
    void zapelnijPlanszeRegulaminowo();

    std::string ruch();
};