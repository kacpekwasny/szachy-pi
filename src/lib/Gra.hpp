/*
    Gra.hpp
    Kacper Kwaśny 19.12.2021
*/
#ifndef GRA_HPP_GUARD
#define GRA_HPP_GUARD // to jest po to zeby nie powtarzaly sie include itp.

#include <string>
#include <vector>

#include "plansza.hpp"
#include "pion_pole.hpp"

enum ruchZwrotneStany {
    OK, POLE_PIONKA_PUSTE, POLE_DOCELOWE_ZAJETE, RUCH_NIEDOZWOLONY_DLA_PIONKA, WYBIERZ_NOWY_PIONEK, DROGA_ZAJETA,
    ZLE_POLE_PIONKA, ZLE_POLE_DOCELOWE
};

enum zachowaniaPoDojscuPionkaNaKoniecEnum {
    NA_POCZATEK,   // Pionek wraca na poczatek planszy
    DOWOLNY_TYP,   // Pionek do dojsciu na koniec planszy mozna zmiany na dowolny typ
    ZBITY_PIONEK,  // pionek po dojsciu na koniec planszy mozna zmienic jedynie na jeden z wczesniej zbitych pionkow,
    // `if (bialeICzarne)` to wtedy mozna wybrac tyle ze zbitego o tym samym kolorze
};

class Gra {
private:
    // config gry
    bool bialeICzarne;
    bool ruchBialych = true;  // if (bialeICzarne) to co ruch zmieniaj wartosc na przeciwna (ruchBialych = !ruchBialych)
    bool zbijanieWlaczone;
    zachowaniaPoDojscuPionkaNaKoniecEnum zachowaniaPoDojscuPionkaNaKoniec;

    // Jezeli zachowanie
    Pion *pionekDoZmianyTypu;

    kp rozmiarPlanszyWiersze;
    kp rozmiarPlanszyKolumny;

    Plansza *plansza;

    // funkcja majaca byc wykonywana po kadzym ruchu, na razie jedyna funkcjonalnosc to przeniesienie pionka na poczatek planszy
    void poWykonanymRuchu();

    // funkcja jest prywatna poniewaz zeby dzialala, to musi byc kilka rzeczy spelnionych
    void zapelnijPlanszeRegulaminowo() { plansza->zapelnijPlanszeRegulaminowo(); }

    // poWykonanymRuchu() wywola pionekNaKoncu(), jezeli znajdzie taki pionek
    void pionekNaKoncu(Pion*);

public:
    // ustaw zasady gry, czy sa dwa kolory, czy mozna zbijac, co sie dzieje z pionkiem, ktory dojdzie do konca planszy
    void ustawConfigGry(zachowaniaPoDojscuPionkaNaKoniecEnum, bool bialeICzarne, bool zbijanieWlaczone);

    // ustaw config na Klasyczny tryb gry
    void ustawKlasycznyTrybGry();

    // usun pola planszy i stworz nowe pola planszy wielkosci iloscWierszy x iloscKolumn
    void ustawPlansze(kp iloscWierszy, kp iloscKolumn) { plansza->ustawPlansze(iloscWierszy, iloscKolumn); };

    // wszystkie pola zmieniaja status na jestZajete=false
    // a wszystkie pionki na zbite=true
    void zdejmijPionkiZPlanszy() { plansza->zdejmijPionkiZPlanszy(); }

    // czysci vector z pionkami
    void usunWszystkiePionki() { plansza->usunWszystkiePionki(); }

    // rozmiesc pionki przypadkowo
    // przykladowy argument to np.: {'R', 'R', 'G', 'P', 'P', 'P', 'P', 'S'}
    bool zapelnijPlanszeLosowo(std::vector<char> pionkiDoUtworzenia) {
        return plansza->zapelnijPlanszeLosowo(pionkiDoUtworzenia);
    };

    // const jest tu specjalnie, zeby nie mozna bylo w zaden nieprzewidziany sposob wplywac na pola i pionki
    // jezeli chcemy je modyfikowac to nalezy napisac funkcje do tego celu przeznaczone
    // wtedy bedziemy wiedzieli co sie dzieje z pionkami i funkcjonalnosci beda bardziej przejrzyste
    const std::vector<std::vector<Pole *>> wezPola() { return plansza->wezPola(); };

    const std::vector<Pion *> wezPionki() { return plansza->wezPionki(); };

    // ruch nie zaklada niczego o wejsciu które dostaje
    // jezeli pionek doszedl na koniec i funkcja ma zwrocic WYBIERZ_NOWY_PIONEK, to wczesniej ten pionek ktorym sie ruszono zostaje zapisany
    // w polu Gra.pionekDoZmianyTypu
    // pole bool ruchBialych ma
    ruchZwrotneStany ruch(kp wierszPionka, kp kolumnaPionka, kp wierszDocelowy, kp kolumnaDocelowa);

    // trzeba jakąś logikę wymyślić.
    // Generalnie ma to działąć tak:
    // Interfejs wywołuje gra.ruch(...) -> zwraca: WYBIERZ_NOWY_PIONEK
    //      (bo akurat pionek doszedł do końca, oczywiście to jest tylko i wyłącznie dla tego szeregowego pionka, czy jak on się tam nazywa)
    // Interfejs wiec wywoluje funkcje gra.jakiePionkiSaDoWyboru() i wyswietle opcje uzytkownikowi.
    // Uzytkownik wybiera, Interfejs wywouje gra.wybierzNowyPionek(typ pionka jaki uzytkownik chce)
    // wybierzNowyPionek() musi wziac pod uwage zmienne configu gry, (zobacz w private), czy pionek zamieni się ze zbitym czy tez jedynie zmieni się
    // mu typ wybierzNowyPionek() wie o który pionek chodzi poniewaz gra.ruch(...) zapisala pod zmienna Gra.pionekDoZmianyTypu pionek, który wlasnie
    // doszedl do konca planszy.
    const std::vector<typyPionkaEnum> jakiePionkiSaDoWyboru();

    void wybierzNowyPionek(typyPionkaEnum);
};

#endif