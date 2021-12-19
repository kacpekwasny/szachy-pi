#include <cmath>
#include <string>
#include <vector>

#include "def_typow.hpp"


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
    // DONE 4
    bool ruchPionkiemDozwolony(kp wiersz, kp kolumna);
    bool ruchKrolemDozwolony(kp wiersz, kp kolumna);
    bool ruchSkoczkiemDozwolony(kp wiersz, kp kolumna);
    bool ruchWiezaDozwolony(kp wiersz, kp kolumna);

    // TODO
    bool ruchKrolowaDozwolony(kp wiersz, kp kolumna);

    // TODO
    bool ruchGoncemDozwolony(kp wiersz, kp kolumna);

   public:
    // DONE 2
    void ustawKoordynatyPionka(kp wiersz, kp kolumna);
    bool ruchDozwolony(kp wiersz, kp kolumna);

    // DONE 2
    // H-Krolowa
    // G-Goniec
    // S-Skoczek
    // W-Wieza
    // K-Krol
    // P-Pionek
    char wezLitere();
    bool ustawTypPionkaPoLiterze(char);
};
