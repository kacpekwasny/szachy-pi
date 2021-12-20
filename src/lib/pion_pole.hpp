#include <cmath>
#include <string>
#include <vector>

#include "def_typow.hpp"

// Pole przesuniete do tego pliku bo byla petla include
class Pole {
   public:
    bool jestZajete = false;
    bool jestBiale = false;
    Pion* pionek;
    kp wiersz_;
    kp kolumna_;

    Pole(kp wiersz, kp kolumna, bool jestBiale);
};

class Pion {
   private:
    typyPionkaEnum typPionka;

    // koordynaty pionka, oczywiscie plansza przechowuje go w nested array
    // w odpowiedniej komorce, ale w celach praktycznych, Pion rowniez bedzie ta
    // informacje przechowywal

    // ~~ UWAGA ~~
    // kp wiersz_ = 0;
    // kp kolumna_ = 0;
    // zamiast tych koordynatów to mamy wskaźnik na pole, a ono ma koordynaty, bo pionek czescie przestawiamy z pola na pole,
    // i bez sensu bedzie ciagle zmienianie wartosci wiersza i kolumny, a tak to tylko zmienimy ptr i juz wiemy gdzie pionek sie znajduje
    // Czyli teraz uzywamy:
    // this->pole->wiersz_
    // this->pole->kolumna_

    // na jakim pol
    Pole* pole;

    bool zbity = false;
    bool jestBialy = true;

    /*
        Jeden komentarz do wszystkich poniższych funkcji:
        mają one wziąć wiersz i kolumne i stwierdzić,
        czy mogą się tam ruszyć według zasad obowiązujących dany pionek.
    */
    // DONE
    bool ruchPionkiemDozwolony(kp wiersz, kp kolumna);
    bool ruchKrolemDozwolony(kp wiersz, kp kolumna);
    bool ruchSkoczkiemDozwolony(kp wiersz, kp kolumna);
    bool ruchWiezaDozwolony(kp wiersz, kp kolumna);
    bool ruchKrolowaDozwolony(kp wiersz, kp kolumna);
    bool ruchGoncemDozwolony(kp wiersz, kp kolumna);

   public:
    Pion(bool jestBialy, typyPionkaEnum typ);
    bool ustawZbity(bool zbity);

    // DONE
    bool ruchDozwolony(kp wiersz, kp kolumna);
    void ustawPionekNaPolu(Pole* p);

    // DONE 2
    // H-Krolowa
    // G-Goniec
    // S-Skoczek
    // W-Wieza
    // K-Krol
    // P-Pionek
    char wezLitere();
    // H-Krolowa
    // G-Goniec
    // S-Skoczek
    // W-Wieza
    // K-Krol
    // P-Pionek
    bool ustawTypPionkaPoLiterze(char);
    void ustawTypPionka(typyPionkaEnum t) { typPionka = t; };
};
