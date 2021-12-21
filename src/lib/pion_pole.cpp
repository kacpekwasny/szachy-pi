//
// Created by jarek on 17.12.2021.
//
#include "pion_pole.hpp"

#include <cmath>

#include "def_typow.hpp"

// Pole przesuniete do tego pliku bo byla petla include
Pole::Pole(kp wiersz, kp kolumna, bool jestBiale) {
    this->wiersz_ = wiersz;
    this->kolumna_ = kolumna;
    this->jestZajete = false;
    this->jestBiale = jestBiale;
}

void Pole::zdejmijPionekZPola(bool zbity) {
    this->pionek->zbity = zbity;
    this->jestZajete = false;
}

Pion::Pion(bool jestBialy, typyPionkaEnum typ) {
    this->jestBialy = jestBialy;
    this->typPionka = typ;
}


bool Pion::ruchDozwolony(kp wiersz, kp kolumna) {
    switch (this->typPionka) {
        case PIONEK:
            return this->ruchPionkiemDozwolony(wiersz, kolumna);
        case SKOCZEK:
            return this->ruchSkoczkiemDozwolony(wiersz, kolumna);
        case KROL:
            return this->ruchKrolemDozwolony(wiersz, kolumna);
        case WIEZA:
            return this->ruchWiezaDozwolony(wiersz, kolumna);
        case GONIEC:
            return this->ruchGoncemDozwolony(wiersz, kolumna);
        case KROLOWA:
            return this->ruchKrolowaDozwolony(wiersz, kolumna);

        default:
            // nie powinno dojsc do tego poniewaz, typ pionka nie moze miec innej wartosci niz te wymienione powyzej
            break;
    }
};

bool Pion::ruchPionkiemDozwolony(kp wiersz, kp kolumna) {
    if (kolumna - this->pole->kolumna_ != 0 || wiersz - this->pole->wiersz_ != 1) {
        /* wykluczam mozliwosc poruszania sie po przekatnych, na boki,
         * do tylu lub o wiecej niz jedno pole do przodu */
        return false;
    }
    return true;
}

bool Pion::ruchWiezaDozwolony(kp wiersz, kp kolumna) {
    if (this->pole->kolumna_ - kolumna != 0 && this->pole->wiersz_ - wiersz != 0) {
        /* wykluczam mozliwosc poruszania sie po przekatnych */
        return false;
    }
    return true;
}

bool Pion::ruchSkoczkiemDozwolony(kp wiersz, kp kolumna) {
    if (abs(this->pole->kolumna_ - kolumna) == 3 && abs(this->pole->wiersz_ - wiersz) == 1) {
        return true;
    } else if (abs(this->pole->wiersz_ - wiersz) == 3 && abs(this->pole->kolumna_ - kolumna) == 1) {
        return true;
    }
    return false;
}

bool Pion::ruchGoncemDozwolony(kp wiersz, kp kolumna) {
    if (abs(this->pole->kolumna_ - kolumna) == abs(this->pole->wiersz_ - wiersz)) {
        return true;
    }
    return false;
}

bool Pion::ruchKrolemDozwolony(kp wiersz, kp kolumna) {
    if(abs(this->pole->kolumna_-kolumna)>1 || abs(this->pole->wiersz_-wiersz)>1){
        return true;
    }
    return false;
}

bool Pion::ruchKrolowaDozwolony(kp wiersz, kp kolumna) {
    if (abs(this->pole->kolumna_ - kolumna) == abs(this->pole->wiersz_ - wiersz)) {
        return true;
    } else if (abs(this->pole->kolumna_ - kolumna) == 0 || abs(this->pole->wiersz_ - wiersz) == 0) {
        return true;
    }
    return false;
}


char Pion::wezLitere() {
    switch (this->typPionka) {
        case KROLOWA:
            return 'H';
        case GONIEC:
            return 'G';
        case SKOCZEK:
            return 'S';
        case WIEZA:
            return 'W';
        case KROL:
            return 'K';
        case PIONEK:
            return 'P';
        default:
            // nie powinno dojsc do tego poniewaz, typ pionka nie moze miec innej wartosci niz te wymienione powyzej
            break;
    }
}

bool Pion::ustawTypPionkaPoLiterze(char letter) {
    const char toUpper = 32;
    // convert char to upper
    switch (letter > 60 ? letter - toUpper : letter) {
        case 'H':
            this->typPionka = KROLOWA;
            return true;
        case 'G':
            this->typPionka = GONIEC;
            return true;
        case 'S':
            this->typPionka = SKOCZEK;
            return true;
        case 'W':
            this->typPionka = WIEZA;
            return true;
        case 'K':
            this->typPionka = KROL;
            return true;
        case 'P':
            this->typPionka = PIONEK;
            return true;
        default:
            return false;
    }
}

void Pion::ustawPionekNaPolu(Pole *p) {
    this->pole = p;
    p->pionek = this;
    this->zbity = false;
}

/*bool Pion::naDrodzeGonca(kp wiersz, kp kolumna, std::vector<std::vector<Pole *>> pola) {
    // musi sprawdzac czy kolejne wspolrzedne, po których bedzie poruszac sie pionek nie jest
    // poczatkowymi wspolrzednymi innego pionka 
    for (kp i = 0; i < abs(this->pole->kolumna_ - kolumna); i++) {
        if (pola[this->pole->wiersz_ + i][this->pole->kolumna_ + i]->jestZajete) {
            // wystarczy jedna petla, bo goniec przemieszcza sie na skos, wiec przyrost wierszy i kolumn jest taki sam
            return true;
        }
    }
    return false;
}*/
bool Pion::drogaPionkaWolna(kp wiersz, kp kolumna, const std::vector<std::vector<Pole *>> pola) {
    switch (this->typPionka) {
        case PIONEK:
            return true;
        case SKOCZEK:
            return true;
        case KROL:
            return true;
        case KROLOWA:
            return this->naDrodzeKrolowej(wiersz, kolumna, pola);
        case GONIEC:
            return this->naDrodzeGonca(wiersz, kolumna, pola);
        case WIEZA:
            return this->naDrodzeWiezy(wiersz, kolumna, pola);
    }
}

bool Pion::naDrodzeGonca(kp wiersz, kp kolumna, const std::vector<std::vector<Pole *>> pola) {
    for (int i = 0; i < abs(this->pole->kolumna_ - kolumna); i++) {
        if (pola[this->pole->wiersz_ + i][this->pole->kolumna_ + i]->jestZajete) {
            // wystarczy jedna petla, bo goniec przemieszcza sie na skos, wiec przyrost wierszy i kolumn jest taki sam
            return true;
        }
    }
    return false;
}

bool Pion::naDrodzeWiezy(kp wiersz, kp kolumna, const std::vector<std::vector<Pole *>> pola) {
    if (this->pole->kolumna_ - kolumna != 0) {
        /* sprawdzam czy wieza porusza sie w kolumnie */
        for (int i = 0; i < abs(this->pole->kolumna_ - kolumna); i++) {
            if (pola[this->pole->wiersz_][this->pole->kolumna_ + i]->jestZajete) {
                return true;
            }
        }
    } else {
        /* jak nie w kolumnie to w wierszu */
        for (int i = 0; i < abs(this->pole->wiersz_ - wiersz); i++) {
            if (pola[this->pole->wiersz_ + i][this->pole->kolumna_]->jestZajete) {
                return true;
            }
        }
        return false;
    }
}

bool Pion::naDrodzeKrolowej(kp wiersz, kp kolumna, const std::vector<std::vector<Pole *>> pola) {
    if (this->pole->kolumna_ - kolumna != 0 && this->pole->wiersz_ - wiersz == 0) {
        /* sprawdzam czy krolowa porusza sie w kolumnie */
        for (int i = 0; i < abs(this->pole->kolumna_ - kolumna); i++) {
            if (pola[this->pole->wiersz_][this->pole->kolumna_ + i]->jestZajete) {
                return true;
            }
        }
    } else if (this->pole->wiersz_ - wiersz != 0 && this->pole->kolumna_ - kolumna == 0) {
        /* moze sie tez tyko w wierszu przemieszczac */
        for (int i = 0; i < abs(this->pole->wiersz_ - wiersz); i++) {
            if (pola[this->pole->wiersz_ + i][this->pole->kolumna_]->jestZajete) {
                return true;
            }
        }
    } else {
        /* teraz na skos */
        for (int i = 0; i < abs(this->pole->kolumna_ - kolumna); i++) {
            if (pola[this->pole->wiersz_ + i][this->pole->kolumna_ + i]->jestZajete) {
                /* wystarczy jedna petla, bo goniec przemieszcza sie na skos, wiec przyrost wierszy i kolumn jest taki sam */
                return true;
            }
        }
    }
    return false;
}