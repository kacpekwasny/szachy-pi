//
// Created by jarek on 17.12.2021.
//
#include "Plansza.hpp"
#include <regex>

Pole::Pole(int x, int y) {
    this->x = x;
    this->y = y;
}


Plansza::Plansza(kp iloscWierszy, kp iloscKolumn) {
    // inicjalizacja pol (planszy de fakto)
    for (kp w = 0; w < iloscWierszy; w++) {
        std::vector<Pole *> wiersz;

        for (kp k = 0; k < iloscKolumn; k++) {
            Pole *p;
            p->isZajete = false;
            p->kolumna = k;
            p->wiersz = w;
            wiersz.push_back(p);
        }
        pola.push_back(wiersz);
    }
}

Plansza::~Plansza() {
    for (int i = 0; i < 8; i++) {
        delete plansza[i];
    }
    delete plansza;
}
bool Plansza::isKomenda(std::string s) {
    std::cmatch k;
    if (s.size() > 5 || s.size() < 4) return false;
    if (std::regex_match(s.begin(), s.end(),
                         std::regex("(^[KQBNkqbn][a-gA-G][[1-8][a-gA-G][[1-8]|["
                                    "a-gA-G][[1-8][a-gA-G][[1-8])")))
        return true;
    return false;
}
void Plansza::runCmd(std::string) {}
void Plansza::runInput(std::string inp) {
    // komendy mają strukture Kd3de, e2e3
    // pola mogą mieć abcdefg
    // bierki moga mieć KQB
    if (Plansza::isKomenda(inp)) {
        Plansza::tlumaczKomende(inp);
        runCmd(inp);  // wyjdż albo reset planszy?
        return;
    }
    // Poprzez return linijkę wyżej program dojdzie do tego miejsca wyłącznie,
    // jeżeli if się nie wykona. Więc działa to praktycznie jak if/else,
    // ale kod jest ładniejszy
    if (chooseOrMove == choose) {  // wybieramy pionek
        bool ok = choosePawn(inp);
    }
}

bool Plansza::choosePawn(std::string inp) { return true; }

Plansza::Input Plansza::tlumaczKomende(std::string inp) {
    Input i;
    if (inp.size() == 4) {
        i.x = inp[0] - 'a';
        i.y = inp[1] - '0';
        i.X = inp[2] - 'a';
        i.Y = inp[3] - '0';
        i.isKnownStart = true;
        i.name = ' ';
    } else {
        i.x = inp[1] - 'a';
        i.y = inp[2] - '0';
        i.X = inp[3] - 'a';
        i.Y = inp[4] - '0';
        i.isKnownStart = true;
        i.name = inp[0];
    }
    return i;
}
