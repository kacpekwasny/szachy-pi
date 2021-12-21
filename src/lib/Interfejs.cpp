
#include "Interfejs.hpp"
#include "pion_pole.hpp"
#include <regex>

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

//wewneczna funkcja
int tlumaczDoRender(typyPionkaEnum *a) {
    if (KROL == *a) return 0;
    if (KROLOWA == *a) return 1;
    if (WIEZA == *a) return 2;
    if (GONIEC == *a) return 3;
    if (SKOCZEK == *a) return 4;
    if (PIONEK == *a) return 5;
    return -100;
}

void Interfejs::render() {
    static const std::string bierki[] = {"\u2654", "\u2655", "\u2656", "\u2657", "\u2658", "\u2659",
                                         "\u265a", "\u265B", "\u265C", "\u265D", "\u265E", "\u265F"};
    for (std::string s: bierki) {
        std::cout << s;
    }
    auto plansza = gra->wezPola();
    std::cout << "\n\t\t\tA\tB \tC \tD \tE \tF \tG \tH\n"
              << "\n";
    for (int i = 0; i < 8; i++) {
        std::cout << "\t" << i + 1 << "\t\t";
        for (int j = 0; j < 8; j++) {
            std::cout << (plansza[i][j]->jestZajete ? bierki[tlumaczDoRender(
                    (typyPionkaEnum *) (plansza[i][j]->pionek))] + "\t" : ".\t");
        }
        std::cout << "\t" << i + 1;
        std::cout << std::endl;
    }
    std::cout << "\n"
              << "\t\t\tA \tB \tC \tD \tE \tF \tG \tH\n";
}

bool Interfejs::isKomenda(std::string s) {
    std::cmatch k;
    if (s.size() > 5 || s.size() < 4) return false;
    if (std::regex_match(s.begin(), s.end(),//d2d4
                         std::regex("(^[KQBNkqbn][a-gA-G][[1-8][a-gA-G][[1-8]|["
                                    "a-gA-G][[1-8][a-gA-G][[1-8])")))
        return true;
    return false;
}

Input Interfejs::tlumaczKomende(std::string inp) {
    Input i;
    if (inp.size() == 4) {
        i.x = inp[0] - 'a';
        i.y = inp[1] - '0';
        i.X = inp[2] - 'a';
        i.Y = inp[3] - '0';
        i.isKnownStart = true;
        i.name = ' ';
    } else {
        i.x = inp[1] - 'a';
        i.y = inp[2] - '0';
        i.X = inp[3] - 'a';
        i.Y = inp[4] - '0';
        i.isKnownStart = true;
        i.name = inp[0];
    }
    return i;
}

void Interfejs::help() {  //zaraz po starcie programu

    std::cout << "Komendy dostepne podczas dzialania programu: " << std::endl;
    SetConsoleTextAttribute(hConsole, 2); //color green
    std::cout << "reset";
    SetConsoleTextAttribute(hConsole, 7); //color white
    std::cout << " - zresetowanie calej planszy i zaczniecie gry od nowa; " << std::endl;
    SetConsoleTextAttribute(hConsole, 2); //color green
    std::cout << "exit";
    SetConsoleTextAttribute(hConsole, 7); //color white
    std::cout << " - zakonczenie gry i wyjscie z programu." << std::endl;
    SetConsoleTextAttribute(hConsole, 2); //color green
    std::cout << "help";
    SetConsoleTextAttribute(hConsole, 7); //color white
    std::cout << " - informacja o możliwych ruchach oraz krótkie wprowadzenie." << std::endl;
    SetConsoleTextAttribute(hConsole, 2); //color green
    std::cout << "settings";
    SetConsoleTextAttribute(hConsole, 7); //color white
    std::cout << " - zmien ustawienia gry." << std::endl;
    std::cout << std::endl;
    std::cout << "Instrukcja: " << std::endl;
    std::cout << "Aby poruszac sie figurami po planszy posluguj sie notacja szachowa np. kd5a3." << std::endl;
    std::cout << "Pamiętaj, kolejnosc wpisywania ma znaczenie - najpierw litera, potem liczba." << std::endl;
    std::cout << "Kolejnosc pol takze ma znaczenie, najpierw pole na ktorym stoi figura, " << std::endl;
    std::cout << "ktora chcesz sie ruszyc, potem pole na ktore chcesz sie nia ruszyc. " << std::endl;
    std::cout << std::endl;
    std::cout << "Milej gry." << std::endl;
    std::cout << std::endl;
    system("pause");
    system("cls");
}

void Interfejs::setText(std::string text) {

    if ("reset" == text) {
        std::string decyzja;
        std::cout << std::endl;
        std::cout << "czy chcesz zresetowac i zaczac od nowa? [t/n]" << std::endl;
        std::cin >> decyzja;
        if (decyzja == "t") {

            system("cls");
            render();

            std::cout << "Podaj pole figury, ktora chcesz sie ruszyc." << std::endl;
            std::string new_input;
            std::cin >> new_input;
            setText(new_input);
        } else {
            std::cout << "Podaj pole figury, ktora chcesz sie ruszyc." << std::endl;
            std::string new_input;
            std::cin >> new_input;
            setText(new_input);
        }
    } else if ("exit" == text) {
        system("cls");
        std::cout << std::endl;
        SetConsoleTextAttribute(hConsole, 12); //color red
        std::cout << std::setw(50) << "Game Over" << std::endl;
        SetConsoleTextAttribute(hConsole, 8);  //color light grey
        std::cout << std::endl;
        std::cout << "Thanks for playing!" << std::endl;
        std::cout << std::endl;
        std::cout << "Chess game created by: " << std::endl;
        std::cout << "Asia, Dominik, Hubert, Jarek, Julian, Kacper & Mateusz." << std::endl;;
        std::cout << std::endl;
        system("pause");
        throw "exit";
    } else if ("help" == text) {
        help();
    } else if ("settings" == text) {
        system("cls");

        std::cout
                << "Co ma sie dziac z pionkiem na koncu planszy?\nznikać [1]\nzamieniac sie w dowolna figure [2]\nma zginac [3],"
                << std::endl;
        int zmienna;
        std::cin >> zmienna;
        zachowaniaPoDojscuPionkaNaKoniecEnum a = static_cast<zachowaniaPoDojscuPionkaNaKoniecEnum>(zmienna - 1);
        std::cout << "Kolory figur: [1/2]" << std::endl;
        int kolor;
        std::cin >> kolor;
        if (kolor == 1) {

            std::cout << "Czy da sie zbijac figury? [t/n]" << std::endl;
            std::string zbicie;
            std::cin >> zbicie;
            if (zbicie == "t") {
                gra->ustawConfigGry(a, false, true);
            } else {
                gra->ustawConfigGry(a, false, false);
            }
        } else {

            std::cout << "Czy da sie zbijac figury? [t/n]" << std::endl;
            std::string zbicie;
            std::cin >> zbicie;
            if (zbicie == "t") {
                gra->ustawConfigGry(a, true, true);
            } else {
                gra->ustawConfigGry(a, true, false);
            }
        }

        std::vector<char> pionkiDoUtworzenia;
        char figura = '0';

        do {
            std::cout << "Podaj jakie figury maja sie znalezc na planszy wpisujac ich symbol: " << std::endl;
            std::cout << "H - krolowa" << std::endl;
            std::cout << "K - krol" << std::endl;
            std::cout << "S - skoczek" << std::endl;
            std::cout << "W - wieza" << std::endl;
            std::cout << "P - pionek" << std::endl;
            std::cout << "G - goniec" << std::endl;
            std::cout << "Zakoncz wpisywanie poprzez wpisanie [e]." << std::endl;

            std::vector<char> pionkiDoUtworzenia;
            std::cin >> figura;
            if ('e' != figura) {
                pionkiDoUtworzenia.push_back(figura);
            }
        } while ('e' != figura);
        gra->zapelnijPlanszeLosowo(pionkiDoUtworzenia);
        system("cls");
        render();
    } else if (
            isKomenda(text)
            ) {
        Input wspolrzedne = tlumaczKomende(text);
        gra->ruch(wspolrzedne.x, wspolrzedne.y,
                  wspolrzedne.X, wspolrzedne.Y);
    } else {
        std::cout << "Niepoprawna komenda, wpisz jeszcz raz" <<
                  std::endl;
        std::string new_input;
        std::cin >>
                 new_input;
        setText(new_input);
    }
}

void Interfejs::StartGry() {
    std::cerr<<"work\n";
    gra = new Gra();
    //gra->ustawKlasycznyTrybGry();
    gra->ustawPlansze(8,8);
    gra->ustawConfigGry(NA_POCZATEK,false,false);
    gra->zapelnijPlanszeLosowo({KROL,PIONEK,SKOCZEK,WIEZA});
    render();
    std::cerr<<"work\n";
    help();
    std::string s;
    for (;;) {
        std::cerr<<"work\n";
        try {
            std::cerr<<"work\n";
            std::cin >> s;
            setText(s);
        } catch (std::exception
                 e) {
            break;
        }
    }
}
