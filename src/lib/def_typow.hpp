/*
17.12.2021
Kacper Kwaśny

Plik jest przeznaczony do utworzenia typów, które będą używane globalnie.

Przykład to wytłumaczy, aktualnie wszędzie do wprowadzania koordynatów na
planszy planuje używać `unsigned int` ale gdyby się okazało, że jest to
niepoprawny typ do tego przeznaczenia to wystarczy, że tutaj zmienie.
*/

// Koordynat planszy - używany do X albo Y w koordynatach na planszy
// pełna informacja identyfikująca pole będzie zawierała dwie zmienne `bc`
// jedną do X'ów i jedną do Y'ów


// nie bede tego tlumaczyl, ale trzeba sobie wygooglowac
// te komendy zaczynajace sie od '#'
#ifndef DEF_TYPOW_HPP_GUARD
#define DEF_TYPOW_HPP_GUARD

typedef int kp;
enum typyPionkaEnum { KROL,KROLOWA, WIEZA, GONIEC,SKOCZEK, PIONEK };
/**
 * typy pionków przeniesione tam gdzie powinny być typy
 * potrzebuje zmienić kolejność z tej na nową
 * (stara kolejność PIONEK, SKOCZEK, WIEZA, GONIEC, KROL, KROLOWA)
 */

//tłumaczenie komend na wejsciu
struct Input{
    int x;
    int y;
    bool isKnownStart;
    int X;
    int Y;
    char name;
};

#endif
