/*
    Gra.hpp
    Kacper Kwaśny 19.12.2021
*/

#include <string>
#include <vector>

#include "plansza.hpp"
#include "pion_pole.hpp"

enum ruchZwrotneStany { OK, POLE_PIONKA_PUSTE, POLE_DOCELOWE_ZAJETE, RUCH_NIEDOZWOLONY_DLA_PIONKA, WYBIERZ_NOWY_PIONEK };

enum zachowaniaPoDojscuPionkaNaKoniecEnum {
    NA_POCZATEK,   // Pionek wraca na poczatek planszy
    DOWOLNY_TYP,   // Pionek do dojsciu na koniec planszy mozna zmiany na dowolny typ
    ZBITY_PIONEK,  // pionek po dojsciu na koniec planszy mozna zmienic jedynie na jeden z wczesniej zbitych pionkow,
                   // `if (bialeICzarne)` to wtedy mozna wybrac tyle ze zbitego o tym samym kolorze
};

class Gra {
   private:
    // config gry
    bool bialeICzarne = false;
    bool ruchBialych = true;  // if (bialeICzarne) to co ruch zmieniaj wartosc na przeciwna (ruchBialych = !ruchBialych)
    bool zbijanieWlaczone = false;
    zachowaniaPoDojscuPionkaNaKoniecEnum zachowaniaPoDojscuPionkaNaKoniec;

    // Jezeli zachowanie
    Pion* pionekDoZmianyTypu;

    kp rozmiarPlanszyWiersze;
    kp rozmiarPlanszyKolumny;

    Plansza* plansza;

    // TODO
    // funkcja majaca byc wykonywana po kadzym ruchu, na razie jedyna funkcjonalnosc to przeniesienie pionka na poczatek planszy
    void poWykonanymRuchu();

   public:
    // TODO
    void ustawConfigGry(zachowaniaPoDojscuPionkaNaKoniecEnum, bool bialeICzarne, bool zbijanieWlaczone);

    // TODO
    // usuwa dotychczasowa plansze i ustawia nowa
    void ustawPlansze(kp iloscWierszy, kp iloscKolumn);

    // TODO
    // ustawia wszystkie wszystkie `pionki.jestZbity = true;`
    // oraz wszystkie pola zaznacza na `pole.jestZajete = false`
    void zdejmijPionkiZPlanszy();

    // TODO
    void usunWszystkiePionki();

    // TODO
    // rozmiesc pionki przypadkowo
    // argument to np.: {'R', 'R', 'G', 'P', 'P', 'P', 'P', 'S'}
    void zapelnijPlanszeLosowo(std::vector<char>);

    // TODO
    // czyli 16 pionkami
    // gdyby plansza byla wieksza, to mozna zrobic tak, ze jakos skaluje liczbe pionkow czy cos
    // to zalezy od weny tworczej autora
    void zapelnijPlanszeRegulaminowo();

    // const jest tu specjalnie, zeby nie mozna bylo w zaden nieprzewidziany sposob wplywac na pola i pionki
    // jezeli chcemy je modyfikowac to nalezy napisac funkcje do tego celu przeznaczone
    // wtedy bedziemy wiedzieli co sie dzieje z pionkami i funkcjonalnosci beda bardziej przejrzyste
    const std::vector<std::vector<Pole*>> wezPola() { return plansza->wezPola(); };
    const std::vector<Pion*> wezPionki() { return plansza->wezPionki(); };

    // TODO
    // ruch nie zaklada niczego o wejsciu które dostaje
    // jezeli pionek doszedl na koniec i funkcja ma zwrocic WYBIERZ_NOWY_PIONEK, to wczesniej ten pionek ktorym sie ruszono zostaje zapisany
    // w polu Gra.pionekDoZmianyTypu
    // pole bool ruchBialych ma
    ruchZwrotneStany ruch(kp wierszPionka, kp kolumnaPionka, kp wierszDocelowy, kp kolumnaDocelowa);

    // TODO
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