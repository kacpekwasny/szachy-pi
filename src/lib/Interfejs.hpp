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

    Plansza* plansza;

    std::string polaZPionkami() {
        for (auto p : plansza->pionki) {
        }
    }

   public:
    void uruchom() {
        for (;;) {
            std::cout << "Wybierz pionek: "
                      << "\n";  //
            std::string inp;
            std::cin >> inp;
        }
    }
};