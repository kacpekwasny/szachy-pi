/*
17.12.2021
Kacper Kwa�ny

Plik jest przeznaczony do utworzenia typ�w, kt�re b�d� u�ywane globalnie.

Przyk�ad to wyt�umaczy, aktualnie wsz�dzie do wprowadzania koordynat�w na planszy planuje u�ywa�
`unsigned int` ale gdyby si� okaza�o, �e jest to niepoprawny typ do tego przeznaczenia to wystarczy, �e tutaj
zmienie.
*/


// Koordynat planszy - u�ywany do X albo Y w koordynatach na planszy
// pe�na informacja identyfikuj�ca pole b�dzie zawiera�a dwie zmienne `bc`
// jedn� do X'�w i jedn� do Y'�w
typedef unsigned int kp;

