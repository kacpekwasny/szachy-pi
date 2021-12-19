//
// Created by jarek on 17.12.2021.
//
#include <regex>

#include "Plansza.hpp"

Pole::Pole(int x, int y) {
    this->x = x;
    this->y = y;
}

void Plansza::render() {
    static const std::string bierki[] = {
        "\u2654", "\u2655", "\u2656", "\u2657", "\u2658", "\u2659",
        "\u265a", "\u265B", "\u265C", "\u265D", "\u265E", "\u265F"};
    for (std::string s : bierki) {
        std::cout << s;
    }
    std::cout << "\n\t\t\tA\tB \tC \tD \tE \tF \tG \tH\n"
              << "\n";
    for (int i = 0; i < 8; i++) {
        std::cout << "\t" << i + 1 << "\t\t";
        for (int j = 0; j < 8; j++) {
            std::cout << (plansza[i][j].isZajete
                              ? bierki[plansza[i][j].typBierki] + "\t"
                              : ".\t");
        }
        std::cout << "\t" << i + 1;
        std::cout << std::endl;
    }
    std::cout << "\n"
              << "\t\t\tA \tB \tC \tD \tE \tF \tG \tH\n";
}

Plansza::Plansza() {
    plansza = new Pole *[8];
    for (int i = 0; i < 8; i++) {
        plansza[i] = new Pole[8];
        for (int j = 0; j < 8; j++) {
            plansza[i][j] = Pole(i + 1, j + 1);
        }
    }
}

Plansza::Plansza(std::string arg) {
    plansza = new Pole *[8];
    for (int i = 0; i < 8; i++) {
        plansza[i] = new Pole[8];
        for (int j = 0; j < 8; j++) {
            plansza[i][j] = Pole(i + 1, j + 1);
        }
    }
    if (arg != "test") return;
    Pole *p = &plansza[3][3];
    p->isZajete = true;
    p->typBierki = 9;
    p = &plansza[6][5];
    p->isZajete = true;
    p->typBierki = 10;
    p = &plansza[6][2];
    p->isZajete = true;
    p->typBierki = 11;
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
