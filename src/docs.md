# Co zrobić? Czym się zająć?
#### `CTRL+F` i wyszukaj `TODO`, będe tym hasłem tagował miejsca, które wymagają jakiejś pracy, stworzenia funkcji itp.
#### Nie używajcie:
1. `using namespace std;` piszcie `std::xxx...`
---

### Komunikacja użytkownika z programem

Co użytkownik może wpisać?  
1. Pole na szachownicy: "A1", "B5", "F6"...  
    Będzie to interpretowane jako wybieranie figury do ruchu albo pole docelowe ruchu w zależności od kolejności. Instancja clasy `Board` będzie pamiętała, czy obecny input będzie oznaczał wybór pionka czy pole do ruchu `Board.chooseOrMove`, to pole jest zaimplementowane jako `enum`.
   
notacja szachowa działa tak:
   1. 
       jeśli jest to figura to na poczatku pojawia sie sktór jej nazwy.
       (król K wieża R skoczek N ). 
   2. następnie jest podawane pole na którym się znajuje bierka.
   3. po spacji jest podawane jest pole docelowe.
    
np. KA1 B2, e2 e3, ND3 F4
2. Może wpisać komendę:  
   1. `reset`, będzie ona ponownie rozmieszczała pionki po szachownicy i ustawiała `chooseOrMove` na `choose`.
   2. `quit`, opuszcza program.
   3. `help`, pokazuje jakieś instrukcje.

---

### Interfejs (wyświetlanie)
Musi być miejsce na pisanie, miejsce na wyświetlanie planszy, i miejsce na wyświetlanie _info_ - czyli komenda `help` powinna wyświetlić właśnie w tamtym miejscu instrukcje, jak i również kiedy wprowadzi błędne pole szachownicy, które jest puste albo na które pionek nie może się ruszyć.

---

## Sterowanie pionkami
Fajnie by było zrobić sterowanie pionkami tak, żeby się skalowało. Przykład:
```cpp
class Board {
    Pionek p;
    Krol k;
    Skoczek s;
    Wieza w;

    enum currentPawn {p, k, s, w};
    currentPawn = p; 
    ...
}
```
jeżeli zrobimy jak powyżej, to np.: funkcja `move(pole)`, będzie wyglądała tak:
```
class Board {
    ...
    bool move(std::string pole) {
        switch (currentPawn) {
            case p:
                p.move(pole);
                return;
            case k:
                k.move(pole);
                return;
            case s:
                s.move(pole);
                return;
            case w:
                w.move(pole);
                return;
            // a jezeli chce sie dodac wiecej pionkow, to trzeba dodać wiecej `case`;
        }
    }
    ...
}
```
### Lepiej zrobić.. Teraz mnie natchęło!
Zróbmy wszystkie pionki jako jedną klasę. Potem każda instancja pionka będzie miała pole enum, które będzie determinowało czy jest pionkiem, królem, skoczkiem, czy wieżą.
Będzie jedna funkcja `Pion.move(pole)`, która będzie sprawdzała inaczej w zależności od tego czy instancja jest P, K, S czy W.
Zobaczcie `board.hpp`.




