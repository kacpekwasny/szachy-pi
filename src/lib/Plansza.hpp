#include <iostream>
#include <string>
#include <vector>

#include "def_typow.hpp"
#include "pion.hpp"  //zmiana z <> na "", cudzysłowia są do lokalnych bibliotek

/* Zwraca
    ok = false                              // jeżeli wystąpił błąd, np nie ma
   pionka na danym polu info = "Nie ma pionka na danym polu"    // informacja co
   poszło nie tak, dla użytkownika do wyświetlenia
*/

class Pole {
   public:
    bool isZajete = false;
    bk
};

// Plansza - plansza
class Plansza {
   private:
    std::vector<std::vector<Pole *>> pola;

   public:
    std::vector<Pion *> pionki;

    Plansza();
    Plansza(std::string arg);

    ~Plansza();

    // TODO
    void runInput(std::string inp);
    /*
        tutaj wchodzi tekst np.: "D5", "E1"
        albo komenda typu "reset"
    */

    // TODO
    bool isKomenda(std::string);  // jeżeli jest komendą, to zwraca true.
                                  // Patrz docs.md

    // TODO
    bool choosePawn(std::string inp);  //

    // TODO
    void runCmd(std::string);

    // void render(); -> przeniesione do Interfejs.cpp

    // TODO
    void setText();
    /*
        Bierze text, i ustawia go do wyświetlenia.

        Gdzieś musi się wyświetlać tekst zwrotnyn np.: co można wpisać, jak
       aplikacja działa? Nie istnieje pionek na polu które wybrałeś, nie można
       się ruszyć tam gdzie wybrał użytkownik

    */

    /*
        figures                             // figury
        move(figura, miejsce_na_planszy)    //
        render()                            //
    */
    Input tlumaczKomende(std::string basicString);
};