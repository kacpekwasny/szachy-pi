
#include "Interfejs.hpp"

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void Interfejs::render() {
    static const std::string bierki[] = {"\u2654", "\u2655", "\u2656", "\u2657", "\u2658", "\u2659",
                                         "\u265a", "\u265B", "\u265C", "\u265D", "\u265E", "\u265F"};
    for (std::string s : bierki) {
        std::cout << s;
    }
    auto plansza=gra->wezPola();
    std::cout << "\n\t\t\tA\tB \tC \tD \tE \tF \tG \tH\n"
              << "\n";
    for (int i = 0; i < 8; i++) {
        std::cout << "\t" << i + 1 << "\t\t";
        for (int j = 0; j < 8; j++) {
            std::cout << (plansza[i][j]->isZajete ? bierki[plansza[i][j]->typBierki] + "\t" : ".\t");
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
    if (std::regex_match(s.begin(), s.end(),
                         std::regex("(^[KQBNkqbn][a-gA-G][[1-8][a-gA-G][[1-8]|["
                                    "a-gA-G][[1-8][a-gA-G][[1-8])")))
        return true;
    return false;
}
def_typow::Input Interfejs::tlumaczKomende(std::string inp) {
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
void Interfejs::startProgram() {  //zaraz po starcie programu

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
    std::cout << "info";
    SetConsoleTextAttribute(hConsole, 7); //color white
    std::cout << " - informacja o możliwych ruchach oraz krótkie wprowadzenie." << std::endl;
    std::cout << std::endl;
    std::cout << "Aby poruszac sie figurami po planszy posluguj sie notacja szachowa np. d5." << std::endl;
    std::cout << "Pamiętaj, kolejnosc wpisywania ma znaczenie - najpierw litera, potem liczba." << std::endl;
    std::cout << std::endl;
    std::cout << "Milej gry." << std::endl;
    std::cout << std::endl;
    system("pause");
    system("cls");
}
void Interfejs::setText(std::string text) {


        if("reset"==text){
            std::string decyzja;
            std::cout << std::endl;
            std::cout << "czy chcesz zresetowac i zaczac od nowa? [t/n]" << std::endl;
            std::cin >> decyzja;
            if (decyzja == "t") {

                system("cls");
                generatePositions();
                setFigures();
                render();

                std::cout << "Podaj pole figury, ktora chcesz sie ruszyc." << std::endl;
                std::string new_input;
                std::cin >> new_input;
                setText(new_input);
            }
            else {
                std::cout << "Podaj pole figury, ktora chcesz sie ruszyc." << std::endl;
                std::string new_input;
                std::cin >> new_input;
                setText(new_input);
            }
        }
        else if("exit"==text) {
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
        }
        else {

            /*

            kp=text;  //jakos sie to rozwiaze xd

            if (CzyWybranePoleNalezyDoPlanszy(kp) == true) {

                if (CzyNaPoluStoiJakasFigura(kp) == true) {
                    std::cout << "Wybierz pole, na ktore chcesz sie ruszyc. << std::endl;
                    std::cin >> kp;
                    if (CzyWybranePoleNalezyDoPlanszy(kp) == true) {

                        if (CzyNaPoluStoiJakasFigura(kp) == false) {

                            if (CzyMozeSieTamRuszyc == true ) {
                                //funkcja replace? - rusz tam figure
                            }
                            else {
                                std::cout << "Wybrana figura nie moze sie tam ruszyc, wpisz koncowa wspolrzedna jeszcze raz." << std::endl;
                            }
                        }
                        else {
                            std::cout << "Wybrane pole juz jest zajete. Wpisz koncowa wspolrzedna jeszcze raz." << std::endl;
                        }
                    }
                    else {
                        std::cout << "Wybrane pole nie nalezy do planszy. Wpisz koncowa wspolrzedna jeszcze raz." << std::endl;
                        funkcja??
                    }
                }
                else {
                    std::cout << "To pole jest puste i nie stoi na nim zadna figura, wpisz pierwsza wspolrzedna jeszcze raz." << std::endl;
                    std::string new_input;
                    std::cin >> new_input;
                    setText(new_input);
                }
            }
            else { */
            std::cout << "Wybrane pole nie nalezy do planszy. Wpisz pierwsza wspolrzedna jeszcze raz." << std::endl;
            std::string new_input;
            std::cin >> new_input;
            setText(new_input);
            //}
        }

}