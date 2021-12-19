#include <string>
#include <vector>

#include "def_typow.hpp"

enum typyPionkaEnum { PIONEK, KROL, SKOCZEK, WIEZA };

class Pion {
   private:
    typyPionkaEnum typPionka;

    // koordynaty pionka, oczywiscie plansza przechowuje go w nested array
    // w odpowiedniej komorce, ale w celach praktycznych, Pion rowniez bedzie ta
    // informacje przechowywal
    kp wiersz_ = 0;
    kp kolumna_ = 0;

    /*
        Jeden komentarz do wszystkich poniższych funkcji:
        mają one wziąć wiersz i kolumne i stwierdzić,
        czy mogą się tam ruszyć według zasad obowiązujących dany pionek.


    */
    // TODO
    bool ruchPionkiemDozwolony(kp wiersz, kp kolumna);

    // TODO
    bool ruchKrolemDozwolony(kp wiersz, kp kolumna);

    // TODO
    bool ruchSkoczkiemDozwolony(kp wiersz, kp kolumna);

    // TODO
    bool ruchWiezaDozwolony(kp wiersz, kp kolumna);

   public:
    void ustawKoordynatyPionka(kp wiersz, kp kolumna);

    bool ruchDozwolony(kp wiersz, kp kolumna);
};
