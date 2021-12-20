/*
    Kacper Kwasny
    20.12.2021
*/
#include "Gra.hpp"

#include <map>
#include <vector>

void Gra::poWykonanymRuchu() {}

void Gra::ustawConfigGry(zachowaniaPoDojscuPionkaNaKoniecEnum, bool bialeICzarne, bool zbijanieWlaczone) {}

void Gra::ustawKlasycznyTrybGry() {
    this->ustawPlansze(8, 8);
    this->usunWszystkiePionki();
    this->zapelnijPlanszeRegulaminowo();
}

ruchZwrotneStany Gra::ruch(kp wierszPionka, kp kolumnaPionka, kp wierszDocelowy, kp kolumnaDocelowa) {}

const std::vector<typyPionkaEnum> Gra::jakiePionkiSaDoWyboru() {
    std::vector<typyPionkaEnum> v;
    switch (this->zachowaniaPoDojscuPionkaNaKoniec) {
        case NA_POCZATEK:
            return v;
        case DOWOLNY_TYP:
            v.push_back(KROLOWA);
            v.push_back(GONIEC);
            v.push_back(WIEZA);
            v.push_back(SKOCZEK);
            v.push_back(KROL);
            v.push_back(PIONEK);
            return v;
        case ZBITY_PIONEK:
            std::map<typyPionkaEnum, char> zbitePionki;
            for (auto p : this->wezPionki()) {
                zbitePionki
            }

        default:
            break;
    }
    for (auto pionek : this->plansza->wezPionki()) {
    }
}

void Gra::wybierzNowyPionek(typyPionkaEnum) {}
