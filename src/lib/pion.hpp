#include <vector>
#include <string>
#include "def_typow.hpp"

class Pion {
    private:
        enum typyPionkaEnum{pionek, krol, skoczek, wieza};
        typyPionkaEnum typPionka=pionek;
        
        // koordynaty pionka
        kp x_ = 0;
        kp y_ = 0;

    bool move(kp wiersz, kp kolumna);


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
};