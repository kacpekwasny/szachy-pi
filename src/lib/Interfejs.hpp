/*
    Interfejs.hpp
    Kacper Kwaśny

    W celu uporządkowania zadań, pomiędzy clasami:
*/
#include <string>

#include "Plansza.hpp"

class Interfejs {
   private:
    enum chooseOrMoveEnum { choose, move };
    chooseOrMoveEnum chooseOrMove = choose;  // zawiera informacje o przeznaczeniu kolejnego inputu

    //
    void setText(std::string);

    std::string polaZPionkami() {
        std::string pola = "";
        for (auto p : plansza->pionki) {
        }
    }

   public:
    // input, rysowanie, output
    void glownaPetla();
};