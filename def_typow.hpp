/*
17.12.2021
Kacper Kwaœny

Plik jest przeznaczony do utworzenia typów, które bêd¹ u¿ywane globalnie.

Przyk³ad to wyt³umaczy, aktualnie wszêdzie do wprowadzania koordynatów na planszy planuje u¿ywaæ
`unsigned int` ale gdyby siê okaza³o, ¿e jest to niepoprawny typ do tego przeznaczenia to wystarczy, ¿e tutaj
zmienie.
*/


// Koordynat planszy - u¿ywany do X albo Y w koordynatach na planszy
// pe³na informacja identyfikuj¹ca pole bêdzie zawiera³a dwie zmienne `bc`
// jedn¹ do X'ów i jedn¹ do Y'ów
typedef unsigned int kp;

