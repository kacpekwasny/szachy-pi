/*
17.12.2021
Kacper Kwaśny

Plik jest przeznaczony do utworzenia typów, które będą używane globalnie.

Przykład to wytłumaczy, aktualnie wszędzie do wprowadzania koordynatów na planszy planuje używać
`unsigned int` ale gdyby się okazało, że jest to niepoprawny typ do tego przeznaczenia to wystarczy, że tutaj
zmienie.
*/


// Koordynat planszy - używany do X albo Y w koordynatach na planszy
// pełna informacja identyfikująca pole będzie zawierała dwie zmienne `bc`
// jedną do X'ów i jedną do Y'ów
typedef unsigned int kp; 

