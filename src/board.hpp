#include <string>
#include <./pion.hpp>


/* Zwraca
    ok = false                              // jeżeli wystąpił błąd, np nie ma pionka na danym polu
    info = "Nie ma pionka na danym polu"    // informacja co poszło nie tak, dla użytkownika do wyświetlenia
*/
struct Info {
    bool ok;
    std::string info;
};

// Board - plansza
class Board {
    private:
        enum chooseOrMoveEnum {choose, move};
        chooseOrMoveEnum chooseOrMove = choose; // zawiera informacje o przeznaczeniu kolejnego inputu
        std::string infoText = "Welcome to out program!";



    // TODO
    void runInput(std::string inp) {
        /*
            tutaj wchodzi tekst np.: "D5", "E1"
            albo komenda typu "reset"
        */

        if ( isKomenda(inp) )
            runCmd(inp); // wyjdż albo reset planszy?
            return;
        // samego else nie trzeba bo powyżej jest 'return', więc technicznie działa tak samo,
        // a nie trzeba zagnieżdżać
        // else, czyli inp zawiera pole (np.: "D5"...)
        if (chooseOrMove == choose) // wybieramy pionek
            bool ok = choosePawn(inp);

    }

    // TODO
    bool isKomenda(std::string); // jeżeli jest komendą, to zwraca true. Patrz docs.md

    // TODO
    bool choosePawn(std::string inp); //

    // TODO
    void runCmd(std::string);

    // TODO
    void render() { 
        // STWORZENIE PLANSZY NA SAMYM POCZ ĄTKU PROGRAMU TABLICA DWUWYMIAROWA 24x24 PO 3 "POLA" NA JEDNO POLE SZACHOWE COŚ TAKIEGO: 
 _      // W KODZIE CHAR SĄ FAJNE ZNACZKI DO ZROBIENIA TABLICY  

        /*
            Wyświetla wszystko:
                plansza,
                input,
                feedback,
        */;
    }
    
    // TODO
    void setText() {
        /*
            Bierze text, i ustawia go do wyświetlenia.
            
            Gdzieś musi się wyświetlać tekst zwrotnyn np.: co można wpisać, jak aplikacja działa?
                Nie istnieje pionek na polu które wybrałeś, nie można się ruszyć tam gdzie wybrał użytkownik
                
        */
    }

    
    /


        figures                             // figury
    move(figura, miejsce_na_planszy)    // 
    render()                            //
}