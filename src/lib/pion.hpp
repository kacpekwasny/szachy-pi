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
    bool ruchPionkiemDozwolony(kp wiersz, kp kolumna, kp wiersz_ , kp kolumna_){
	   if(kolumna_ - kolumna != 0 || wiersz - wiersz_ != 1){
		/* wykluczam mozliwosc poruszania sie po przekatnych, na boki,
		 * do tylu lub o wiecej niz jedno pole do przodu */
		return false;
	}
	return true;
}

    // TODO
    bool ruchKrolemDozwolony(kp wiersz, kp kolumna);

    bool ruchSkoczkiemDozwolony(kp wiersz, kp kolumna, kp wiersz_, kp kolumna){
	    if(abs(kolumna_ - kolumna) == 3 && abs(wiersz_ - wiersz) == 1){
		return true;
	} else if(abs(wiersz_ - wiersz) == 3 && abs(kolumna_ - kolumna) == 1){
		return true;
	}
	return false;
}

    bool ruchWiezaDozwolony(kp wiersz, kp kolumna, kp wiersz_, kp kolumna_){
	    if(kolumna_ - kolumna != 0 && wiersz_ - wiersz != 0){
		/* wykluczam mozliwosc poruszania sie po przekatnych */
		return false;
	}
	return true;
}

   public:
    void ustawKoordynatyPionka(kp wiersz, kp kolumna);

    bool move(kp wiersz, kp kolumna);
};
