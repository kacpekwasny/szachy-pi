//
// Created by mateusz on 19.12.2021.
//

#include <string>
#include <windows.h>
#include <iomanip>
#include "def_typow.hpp"

void startProgram() {  //zaraz po starcie programu

	std::cout << "Komendy dostepne podczas dzialania programu: " << std::endl;
	std::cout << "reset - zresetowanie calej planszy i zaczniecie gry od nowa;" << std::endl;
	std::cout << "exit - zakonczenie gry i wyjscie z programu." << std::endl;
	std::cout << std::endl;
	std::cout << "Aby poruszac sie figurami po planszy posluguj sie notacja szachowa np. d5." << std::endl;
	std::cout << std::endl;
	std::cout << "Milej gry." << std::endl;
	std::cout << std::endl; 
	system("pause");
	system("cls");
}

void setText(std::string text) {

	if (text == "reset" || text == "exit") {
		if (text == "reset") {
			
			std::string decyzja;
			std::cout << std::endl;
			std::cout << "czy chcesz zresetowac i zaczac od nowa? [t/n]" << std::endl;
			std::cin >> decyzja;

			if (decyzja == "t") {
				std::cout << "resetuje plansze" << std::endl; //ta linijke mozna potem usunac, teraz tylko zeby bylo wiadomo ze resetuje :P
				//render();
			}
			else {
				std::cout << "Podaj pole figury, ktora chcesz sie ruszyc." << std::endl;
				std::string new_input;
				std::cin >> new_input;
				setText(new_input);
			}
		}

		if (text == "exit") {
			system("cls");
			std::cout << std::endl;
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, 12);
			std::cout << std::setw(50) << "GameOver" << std::endl;
			SetConsoleTextAttribute(hConsole, 8);
			std::cout << std::endl;
			std::cout << "Thanks for playing!" << std::endl;
			std::cout << std::endl;
			std::cout << "Chess game created by: " << std::endl;
			std::cout << "Asia, Dominik, Hubert, Jarek, Julian, Kacper & Mateusz." << std::endl;;
			std::cout << std::endl;
			system("pause");
		}
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


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//DO MAINA
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//
// Created by mateusz on 19.12.2021.
//

/*

#include <iostream>
#include "gameOver.hpp"
#include "def_typow.hpp"


	"Bierze text, i ustawia go do wyœwietlenia.

	Gdzieœ musi siê wyœwietlaæ tekst zwrotnyn np.: co mo¿na wpisaæ, jak aplikacja dzia³a?
		Nie istnieje pionek na polu które wybra³eœ, nie mo¿na siê ruszyæ tam gdzie wybra³ u¿ytkownik"

		~chyba napisal Jarek ten komentarz ;p
		w odpowiedzi Mateusz napisa³ to co wy¿ej :D


int main() {

	startProgram();
	//CreateBoard();    //wyswietlenie tablicy z losowymi miejscami figur / chyba ta sama funkcja co render() ??
	std::cout << "Podaj pole figury, ktora chcesz sie ruszyc." << std::endl;

	std::string input;  //tymczasowa zmienna, potem sobie ja zamienimy na t¹ kp o której pisa³ Kacper czy cos tam
	std::cin >> input;

	setText(input);
}

*/