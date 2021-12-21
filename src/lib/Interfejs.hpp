/*
    Interfejs.hpp
    Kacper Kwaśny

    W celu uporządkowania zadań, pomiędzy clasami:
*/
#ifndef INTERFEJS_HPP_GUARD
#define INTERFEJS_HPP_GUARD

#include <string>
#include <windows.h>
#include <iomanip>
#include <iostream>


#include "Gra.hpp"
#include "def_typow.hpp"


class Interfejs {
   private:
    Gra* gra;
    // rename z setText() -> przyjmijWejscieUzytkownika(), ze wzgledu na nieopisowa nazwe
    void przyjmijWejscieUzytkownika(std::string);

    // rename z isKomenda() -> wejscieToRuch(), ze wzgledu na nieopisowa nazwe
    bool wejscieToRuch(std::string s);

    // rename z tlumaczKomenda() -> tlumaczWejscieRuch(), ze wzgledu na nieopisowa nazwe
    Input tlumaczWejscieRuch(std::string inp);

   public:
    void StartGry();
    // input, rysowanie, output
    void render();
    void help();
};
#endif
