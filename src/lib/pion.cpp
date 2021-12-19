//
// Created by jarek on 17.12.2021.
//
#include "pion.hpp"
#include <iostream>
#include <cmath>
#include "def_typow.hpp"

bool Pion::move(kp wiersz, kp kolumna) { return false; }

bool Pion::ruchPionkiemDozwolony(kp wiersz, kp kolumna){
	if(kolumna_ - this-> kolumna != 0 || wiersz - this-> wiersz_ != 1){
		/* wykluczam mozliwosc poruszania sie po przekatnych, na boki,
		 * do tylu lub o wiecej niz jedno pole do przodu */
		return false;
	}
	return true;
}

bool Pion::ruchWiezaDozwolony(kp wiersz, kp kolumna){
	if(this->kolumna_ - kolumna != 0 && this-> wiersz_ - wiersz != 0){
		/* wykluczam mozliwosc poruszania sie po przekatnych */
		return false;
	}
	return true;
}

bool Pion::ruchSkoczkaDozwolony(kp wiersz, kp kolumna){
	if(abs(this->kolumna_ - kolumna) == 3 && abs(this->wiersz_ - wiersz) == 1){
		return true;
	} else if(abs(this->wiersz_ - wiersz) == 3 && abs(this->kolumna_ - kolumna) == 1){
		return true;
	}
	return false;
}

bool Pion::ruchGoncaDozwolony(kp wiersz, kp kolumna){
	if(abs(this->kolumna_ - kolumna) == abs(this->wiersz_ - wiersz){
		return true;
	}
	return false;
}

bool Pion::ruchKrolowejDozwolony(kp wiersz, kp kolumna){
	if(abs(this->kolumna_ - kolumna) == abs(this->wiersz_ - wiersz){
		return true;
	} else if(abs(this->kolumna_ - kolumna) == 0 || abs(this->wiersz_ - wiersz) == 0){
		return true;
	}
	return false;
}
