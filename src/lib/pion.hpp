#include <string>
#include <vector>
#include <cmath>

#include "def_typow.hpp"

class Pion {
   private:
    enum typyPionkaEnum { pionek, krol, skoczek, wieza };
    typyPionkaEnum typPionka = pionek;

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
    //DONE
    bool ruchPionkiemDozwolony(kp wiersz, kp kolumna);

    // TODO
    bool ruchKrolemDozwolony(kp wiersz, kp kolumna);

    //DONE
    bool ruchSkoczkiemDozwolony(kp wiersz, kp kolumna)

    //DONE
    bool ruchWiezaDozwolony(kp wiersz, kp kolumna);

   public:
    void ustawKoordynatyPionka(kp wiersz, kp kolumna);

    bool move(kp wiersz, kp kolumna);
};
