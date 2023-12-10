#include <iostream>
#include <locale>
#include "includes/Klient.h"

int main()
{
	std::setlocale(LC_CTYPE, "Polish");

	Klient klient("Grzegorz", "Brzêczyszczykiewicz");

	//Przyk³ad polimorfizmu: mo¿emy uznaæ, ¿e "Klient" to jakby siê zastanowiæ odmiana "KlasaBazowa", wiêc tak mo¿emy go traktowaæ
	KlasaBazowa* baza = &klient;

	std::cout << baza -> toString();
}