/*
    Kacper Kwasny
    20.12.2021
*/

#include "Gra.hpp"

void Gra::ustawKlasycznyTrybGry() {
    this->ustawPlansze(8, 8);
    this->usunWszystkiePionki();
    this->zapelnijPlanszeRegulaminowo();
}