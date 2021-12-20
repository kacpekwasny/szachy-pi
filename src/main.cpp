//
// Created by jarek on 17.12.2021.
//

#include <iostream>
#include "def_typow.hpp"
#include "oprawaTekstowa.hpp"
#include "plansza.hpp"

int main() {

    startProgram();
    createBoard();
    generatePositions();
    // generatePositionX();
    // generatePositionY();
    setFigures();
    showBoard();

    std::cout << "Podaj pole figury, ktora chcesz sie ruszyc." << std::endl;
    std::string input;
    std::cin >> input;

    setText(input);

return 0;
}

