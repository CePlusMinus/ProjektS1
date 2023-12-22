#include <iostream>
#include <locale>
#include "includes/Klient.h"

int main()
{
	std::setlocale(LC_ALL, "Polish.UTF-8");

	Klient klient("Grzegorz", "Brzęczyszczykiewicz");

	//Przykład polimorfizmu: możemy uznać, że "Klient" to jakby się zastanowić odmiana "KlasaBazowa", więc tak możemy go traktować
	KlasaBazowa* baza = &klient;

	std::cout << baza -> toString();
}