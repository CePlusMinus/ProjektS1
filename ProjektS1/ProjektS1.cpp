#include <iostream>
#include <locale>
#include "includes/Klient.h"

int main()
{
	std::setlocale(LC_CTYPE, "Polish");

	Klient klient("Grzegorz", "Brz�czyszczykiewicz");

	//Przyk�ad polimorfizmu: mo�emy uzna�, �e "Klient" to jakby si� zastanowi� odmiana "KlasaBazowa", wi�c tak mo�emy go traktowa�
	KlasaBazowa* baza = &klient;

	std::cout << baza -> toString();
}