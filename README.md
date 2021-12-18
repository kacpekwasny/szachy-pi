# PI_2021_1440_3

#### Kod w całości piszemy po *POLSKU*
#### W plikach z kodem nie zawieramy polskich znaków. To jest plik `md` nie jest on powiązany z programem, więc można. 
#### Użuwajmy `camelCase` do nazywania zmiennych, funkcji, metod. Do `class` i `struct`'ów proponuje `PascalCase`.
Przykłady zmiennych nazwanych w odpowiednich standardach:
 - `camelCase`: `x`, `pierwiastek1`, `liczbaRuchow`, `koordynatyPionka`, `historiaPolPionka`
 - `PascalCase`: `Plansza`, `Pionek`, `GUIPlansza`, `SlowoOpisujaceCos`

#### Kiedy implementujesz funkcje to robisz to w pliku `*.cpp`.
Pliki `*.hpp` służą jedynie deklaracjom.

Robi się to tak:
Jeżeli wiesz już jaką funkcję implementujesz, to patrzysz na nazwę pliku w jakim się znajduje, powiedzmy `xyz.hpp`, szukasz więc pliku `xyz.cpp`, jeżeli takiego nie ma, to go tworzysz.
Plik z implementacją funkcji `bool mojaFunkcja(int, int);`:
``` cpp
/*
xyz.cpp
Podpis, data, itp
*/

#include "xyz.hpp"

bool mojaFunkcja(int x, int y) {
    // ...
    // implementacja
    // ... 
    // return ...;
}
```
Powiedzmy, że masz zaimplementować *metodę*, czyli funkcję w `class` i wygląda to mniej więcej tak:
```cpp
// abc.hpp

class Abc {
    // ...
    int mojaMetoda(int, int); 
    // ...
};

```
To plik z implementacją powinien wyglądać tak:
```cpp
/*
abc.cpp
Podpis, data, itp

*/

#include "abc.hpp"

int Abc::mojaMetoda(int x, int y) {
    // ...
    // implementacja
    // ...
    // return ...;
}

```


<br>
<br>
<br>

---
# Aktualności:

### 17.12.2021 22:00
Kod piszemy po **POLSKU**

