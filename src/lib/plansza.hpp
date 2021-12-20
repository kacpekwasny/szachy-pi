#pragma once
//
// Created by mateusz on 19.12.2021.
//

void pionowe(int w);

	//funkcja wstawiaj¹ca pionowe kreski z planszy na szerokoœæ tablicy - budowa planszy.

void krzyze(int w);

	//funkcja wstawia krzyzyki do planszy - budowa planszy.

void createBoard();

	//tworzy tablice, czyli plansze wykorzystujac dwie poprzednie funkcje.

void showBoard();

	//funckja pokazujaca aktualny stan planszy - renderuje ja od nowa z figurami na odpowiednich polach.

void generatePositions();

	//losuje miejsca dla figur w tablicy - funkcja tylko na uzywana na poczatku programu.

void setFigures();

	//wpisuje w odpowiednie miejsca w tablicy, czyli na planszy, figury.
