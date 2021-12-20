/*
    Gra.hpp
    Kacper Kwaśny 19.12.2021
*/

#include <string>
#include <vector>

#include "Plansza.hpp"
#include "Pole.hpp"

enum ruchErrorEnum { OK, POLE_PIONKA_PUSTE, POLE_DOCELOWE_ZAJETE, RUCH_NIEDOZWOLONY_DLA_PIONKA, WYBIERZ_NOWY_PIONEK };

class Gra {
   private:
    enum chooseOrMoveEnum { choose, move };
    chooseOrMoveEnum chooseOrMove = choose;  // zawiera informacje o przeznaczeniu kolejnego inputu

    // config gry
    bool bialeICzarne = false;
    bool zbijanieWlaczone = false;

    Plansza* plansza;

    // funkcja majaca byc wykonywana po kadzym ruchu, na razie jedyna funkcjonalnosc to zmiana pionka na
    void poWykonanymRuchu();

   public:
    // Wielkosc planszy
    // ilosc pionkow
    Gra();

    // const jest tu specjalnie, zeby nie mozna bylo w zaden nieprzewidziany sposob wplywac na pola i pionki
    // jezeli chcemy je modyfikowac to nalezy napisac funkcje do tego celu przeznaczone
    // wtedy bedziemy wiedzieli co sie dzieje z pionkami i funkcjonalnosci beda bardziej przejrzyste
    const std::vector<std::vector<Pole*>> wezPola() { return plansza->wezPola(); };
    const std::vector<Pion*> wezPionki() { return plansza->wezPionki(); };

    // TODO
    void wyczyscPlansze();

    // TODO
    // rozmiesc pionki przypadkowo
    // argument to np.: {'R', 'R', 'G', 'P', 'P', 'P', 'P', 'S'}
    void zapelnijPlanszeLosowo(std::vector<char>);

    // TODO
    // czyli 16 pionkami
    void zapelnijPlanszeRegulaminowo();

    // TODO
    ruchErrorEnum ruch(kp wierszPionka, kp kolumnaPionka, kp wierszDocelowy, kp kolumnaDocelowa);
};