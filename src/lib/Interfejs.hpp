/*
    Interfejs.hpp
    Kacper Kwaśny

    W celu uporządkowania zadań, pomiędzy clasami:
*/
#include <string>
#include <windows.h>
#include <iomanip>
#include <iostream>


#include "Gra.hpp"
#include "def_typow.hpp"


class Interfejs {
   private:
    enum chooseOrMoveEnum { choose, move };
    chooseOrMoveEnum chooseOrMove = choose;  // zawiera informacje o przeznaczeniu kolejnego inputu
    Gra* gra;

    //
    void setText(std::string);

    std::string polaZPionkami() {
        std::string pola = "";
        for (auto p : gra->wezPlansze()->pionki) {
        }
    }
    def_typow::Input tlumaczKomende(std::string);
   public:
    // input, rysowanie, output
    void glownaPetla();
    void render();
    void startProgram();
};