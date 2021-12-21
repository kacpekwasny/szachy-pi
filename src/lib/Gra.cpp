/*
    Kacper Kwasny
    20.12.2021
*/
#include "Gra.hpp"

#include <map>
#include <vector>

void Gra::poWykonanymRuchu() {
    // 1. sprawdza, czy na wierszu o indexie 7 stoi bialy oraz czy na wierszu o indexie 0 stoi czarny pionek
    for (kp kolumna = 0; kolumna < 8; ++kolumna) {
        // czy czarny jest na poczatku
        Pole *p0 = this->wezPola()[0][kolumna];
        if (p0->jestZajete && p0->pionek->wezTypPionka() == PIONEK && !p0->pionek->jestBialy) {
            this->pionekNaKoncu(p0->pionek);
            break;
        }
        // czy bialy jest na koncu
        Pole *p7 = this->wezPola()[7][kolumna];
        if (p7->jestZajete && p7->pionek->wezTypPionka() == PIONEK && p0->pionek->jestBialy) {
            this->pionekNaKoncu(p7->pionek);
            break;
        }
    }

    this->ruchBialych = !this->ruchBialych;
}

void Gra::pionekNaKoncu(Pion *p) {
    switch (this->zachowaniaPoDojscuPionkaNaKoniec) {
        case NA_POCZATEK:
            p->pole->zdejmijPionekZPola(false);
            // ustaw pionek po drugiej stronie planszy w tej samej kolummnie
            p->ustawPionekNaPolu(this->wezPola()[p->pole->wiersz_ == 0 ? 7 : 0][p->pole->kolumna_]);
            return;
        case DOWOLNY_TYP:
            this->pionekDoZmianyTypu = p;
            this->ruchZwrocWybierzPionek = true;
            return;
        case ZBITY_PIONEK:
            this->pionekDoZmianyTypu = p;
            this->ruchZwrocWybierzPionek = true;
            return;
    }
}

void Gra::ustawConfigGry(zachowaniaPoDojscuPionkaNaKoniecEnum z, bool bialeICzarne, bool zbijanieWlaczone) {
    this->zachowaniaPoDojscuPionkaNaKoniec = z;
    this->bialeICzarne = bialeICzarne;
    this->zbijanieWlaczone = zbijanieWlaczone;
    // nie wiem czy to odkomentowac, nie patrzylem jak dziala interfejs // this->ustawPlansze(8, 8);
}

void Gra::ustawKlasycznyTrybGry() {
    this->ustawPlansze(8, 8);
    this->usunWszystkiePionki();
    this->zapelnijPlanszeRegulaminowo();
}

ruchZwrotneStany Gra::ruch(kp wierszPionka, kp kolumnaPionka, kp wierszDocelowy, kp kolumnaDocelowa) {
    if (!(0 <= wierszDocelowy && wierszDocelowy < this->rozmiarPlanszyWiersze
          && 0 <= kolumnaDocelowa && kolumnaDocelowa < this->rozmiarPlanszyKolumny)) {
        // Pole docelowe nie jest na planszy
        return ZLE_POLE_DOCELOWE;
    }

    Pole *polePionka = this->wezPola()[wierszPionka][kolumnaPionka];
    Pole *poleDocelowe = this->wezPola()[wierszDocelowy][kolumnaDocelowa];

    // sprawdz czy pole pionka jest puste
    if (!polePionka->jestZajete) {
        return POLE_PIONKA_PUSTE;
    }

    // jezeli gra jest na bialeICzarne a uzytkownik probuje ruszyc sie nie swoim pionkiem
    if (this->bialeICzarne && (this->ruchBialych != polePionka->pionek->jestBialy)) {
        return ZLE_POLE_PIONKA;
    }

    // jezeli taki ruch NIE jest dozwolony dla pionka
    if (!polePionka->pionek->ruchDozwolony(wierszPionka, kolumnaPionka)) {
        return ZLE_POLE_DOCELOWE;
    }

    // czy droga ruchu dla danego pionka NIE jest wolna
    if (!polePionka->pionek->drogaPionkaWolna(wierszDocelowy, kolumnaDocelowa, this->wezPola())) {
        return DROGA_ZAJETA;
    }

    // pole docelowe zajete
    if (poleDocelowe->jestZajete) {
        // zbijanieWlaczone
        if (this->zbijanieWlaczone) {
            // gra na kolory && pionekZrodlowy.color == pionekDocelowy.color
            if (this->bialeICzarne && polePionka->pionek->jestBialy == poleDocelowe->pionek->jestBialy) {
                return POLE_DOCELOWE_ZAJETE;
            }
            // Pozostale mozliwe opcje:
            // 1. gra nie jest na kolory
            // 2. pionki sa roznych kolorow
            // obie pozwalaja na ruch

            // usuwamy pionek z planszy
            poleDocelowe->zdejmijPionekZPola(true);
            polePionka->zdejmijPionekZPola(false);
            polePionka->pionek->ustawPionekNaPolu(poleDocelowe);
            this->poWykonanymRuchu();
            if (this->ruchZwrocWybierzPionek) {
                this->ruchZwrocWybierzPionek = false;
                return WYBIERZ_NOWY_PIONEK;
            }
            return OK;
        }
        return POLE_DOCELOWE_ZAJETE;
    }
    // pole docelowe jest puste, droga wolna, ruch dozwolony

    this->poWykonanymRuchu();
    if (this->ruchZwrocWybierzPionek) {
        this->ruchZwrocWybierzPionek = false;
        return WYBIERZ_NOWY_PIONEK;
    }
    return OK;
}


const std::vector<typyPionkaEnum> Gra::jakiePionkiSaDoWyboru() {
    std::vector<typyPionkaEnum> zbitePionkiV;
    switch (this->zachowaniaPoDojscuPionkaNaKoniec) {
        case NA_POCZATEK:
            return zbitePionkiV;
        case DOWOLNY_TYP:
            zbitePionkiV.push_back(KROLOWA);
            zbitePionkiV.push_back(GONIEC);
            zbitePionkiV.push_back(WIEZA);
            zbitePionkiV.push_back(SKOCZEK);
            zbitePionkiV.push_back(KROL);
            zbitePionkiV.push_back(PIONEK);
            return zbitePionkiV;
        case ZBITY_PIONEK:
            std::map<typyPionkaEnum, bool> zbitePionkiMap;
            for (auto p: this->wezPionki()) {
                // !this->ruchBialych - wartosc zanegowana poniewaz funkcja poWykonanymRuchu()
                // ustawila ja na przeciwna dla kolejnego ruchu, ale my potrzebujemy wartosci z poprzedniego
                // ruchu. Dlatego ja negujemy.
                if (this->bialeICzarne ? p->jestBialy == (!this->ruchBialych) : p->zbity)
                    zbitePionkiMap.insert(std::pair<typyPionkaEnum, bool>(p->wezTypPionka(), true));
            }
            std::map<typyPionkaEnum, bool>::iterator it;
            for (it = zbitePionkiMap.begin(); it != zbitePionkiMap.end(); ++it) {
                zbitePionkiV.push_back(it->first);
            }
            return zbitePionkiV;
    }
}

void Gra::wybierzNowyPionek(typyPionkaEnum typPionka) {
    switch (this->zachowaniaPoDojscuPionkaNaKoniec) {
        case ZBITY_PIONEK:
            this->plansza->zamienPionekZeZbitym(this->pionekDoZmianyTypu, typPionka);
            return;
        case DOWOLNY_TYP:
            this->pionekDoZmianyTypu->ustawTypPionka(typPionka);
            return;
        default:
            // do tego nie dojdzie, poniewaz ostatnia wartosc, czyli NA_POCZATEK
            // nie wlacza tej funkcji
            return;
    }
}

