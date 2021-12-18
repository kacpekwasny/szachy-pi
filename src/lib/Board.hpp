#include "pion.hpp" //zmiana z <> na "", cudzysłowia są do lokalnych bibliotek
#include <string>
#include <iostream>

/* Zwraca
    ok = false                              // jeżeli wystąpił błąd, np nie ma pionka na danym polu
    info = "Nie ma pionka na danym polu"    // informacja co poszło nie tak, dla użytkownika do wyświetlenia
*/
struct Info {
    bool ok;
    std::string info;
};

class Pole{
public:
    bool isZajete=false;
    int typBierki;
    int x;
    int y;
    Pole(int,int);

    Pole(){}
};

// Board - plansza
class Board {
    private:
    enum chooseOrMoveEnum {choose, move};
        chooseOrMoveEnum chooseOrMove = choose; // zawiera informacje o przeznaczeniu kolejnego inputu
        std::string infoText = "Welcome to out program!";
        Pole ** plansza;


public:

    Board();
    ~Board();


    // TODO
    void runInput(std::string inp);
        /*
            tutaj wchodzi tekst np.: "D5", "E1"
            albo komenda typu "reset"
        */

    // TODO
    bool isKomenda(std::string); // jeżeli jest komendą, to zwraca true. Patrz docs.md

    // TODO
    bool choosePawn(std::string inp); //

    // TODO
    void runCmd(std::string);

    // TODO
    void render();
        // STWORZENIE PLANSZY NA SAMYM POCZ ĄTKU PROGRAMU TABLICA DWUWYMIAROWA 24x24 PO 3 "POLA" NA JEDNO POLE SZACHOWE COŚ TAKIEGO: 
       // W KODZIE CHAR SĄ FAJNE ZNACZKI DO ZROBIENIA TABLICY

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
            
            Gdzieś musi się wyświetlać tekst zwrotnyn np.: co można wpisać, jak aplikacja działa?
                Nie istnieje pionek na polu które wybrałeś, nie można się ruszyć tam gdzie wybrał użytkownik
                
        */


    


/*
        figures                             // figury
    move(figura, miejsce_na_planszy)    // 
    render()                            //
    */
};