/*
    Gra.hpp
    Kacper Kwaśny 19.12.2021
*/

#include <string>
#include <vector>

#include "Plansza.hpp"
#include "Pole.hpp"

enum ruchErrorEnum { OK, POLE_PIONKA_PUSTE, POLE_DOCELOWE_ZAJETE, RUCH_NIEDOZWOLONY_DLA_PIONKA };

class Gra {
   private:
    enum chooseOrMoveEnum { choose, move };
    chooseOrMoveEnum chooseOrMove = choose;  // zawiera informacje o przeznaczeniu kolejnego inputu

    // config gry
    zbijanie

        Plansza* plansza;

    // funkcja majaca byc wykonywana po kadzym ruchu, na razie jedyna funkcjonalnosc to zmiana pionka na
    void poWykonanymRuchu();

   public:
    // Wielkosc planszy
    // ilosc pionkow
    Gra();

    // zwroc plansze
    std::vector<std::vector<Pole*>> wezPlansze();

    // TODO
    void resetPlansze();

    // TODO
    // rozmiesc pionki przypadkowo
    // argument to np.: {'R', 'R', 'G', 'P', 'P', 'P', 'P', 'S'}
    void zapelnijPlanszeLosowo(std::vector<char>);

    // TODO
    // czyli
    void zapelnijPlanszeRegulaminowo();

    // TODO
    ruchErrorEnum ruch(kp wierszPionka, kp kolumnaPionka, kp wierszDocelowy, kp kolumnaDocelowa);
};