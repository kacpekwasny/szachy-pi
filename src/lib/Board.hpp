#include <iostream>
#include <string>

#include "pion.hpp"  //zmiana z <> na "", cudzysłowia są do lokalnych bibliotek

/* Zwraca
    ok = false                              // jeżeli wystąpił błąd, np nie ma
   pionka na danym polu info = "Nie ma pionka na danym polu"    // informacja co
   poszło nie tak, dla użytkownika do wyświetlenia
*/
struct Info {
    bool ok;
    std::string info;
};
/**
 * jest to pojedyńcze pole na planszt
 */
class Pole {
   public:
    bool isZajete = false;
    int typBierki;
    int x;
    int y;
    Pole(int, int);

    Pole() {}
};

// Board - plansza
class Board {
   private:
    //struktura w która sa przekształcane komendy wchodzące do programu
    // jest ona stworzenia w celu uproszczenia wprowadzonych danych danych
    struct Input {
        int x;
        int y;
        bool isKnownStart;
        int X;
        int Y;
        Pion pion;
        char name;
    };
    Input lastInput;
    enum chooseOrMoveEnum { choose, move };
    chooseOrMoveEnum chooseOrMove =
        choose;  // zawiera informacje o przeznaczeniu kolejnego inputu
    std::string infoText = "Welcome to out program!";
    Pole** plansza;

   public:
    Board();
    Board(std::string arg);

    ~Board();

    // TODO
    void runInput(std::string inp);
    /*
        tutaj wchodzi tekst np.: "D5", "E1"
        albo komenda typu "reset"
    */


    bool isKomenda(
        std::string);  // jeżeli jest komendą, to zwraca true. Patrz docs.md

    // TODO
    bool choosePawn(std::string inp);  //

    // TODO
    void runCmd(std::string);

    // TODO
    void render();
    // STWORZENIE PLANSZY NA SAMYM POCZ ĄTKU PROGRAMU TABLICA DWUWYMIAROWA 24x24
    // PO 3 "POLA" NA JEDNO POLE SZACHOWE COŚ TAKIEGO: W KODZIE CHAR SĄ FAJNE
    // ZNACZKI DO ZROBIENIA TABLICY

    /*
        Wyświetla wszystko:
            plansza,
            input,
            feedback,
    */

    // TODO
    void setText();
    /*
        Bierze text, i ustawia go do wyświetlenia.

        Gdzieś musi się wyświetlać tekst zwrotnyn np.: co można wpisać, jak
       aplikacja działa? Nie istnieje pionek na polu które wybrałeś, nie można
       się ruszyć tam gdzie wybrał użytkownik

    */

    Input tlumaczKomende(std::string basicString);
    /*
     * bierze komende nieprzetworzonego wejścia
     * zwraca przetworzone dane wejsciowe w stutkurze Inlut
     */

    /*
        figures                             // figury
        move(figura, miejsce_na_planszy)    //
        render()                            //
    */
};