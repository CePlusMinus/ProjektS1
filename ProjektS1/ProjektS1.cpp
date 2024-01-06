#include <iostream>
#include <locale>
#include "includes/Klient.h"
#include "includes/BazaDanych.h"
#include "includes/Menu.h"

using namespace std;
int main()
{
	std::setlocale(LC_ALL, "Polish.UTF-8");

	Wyswietl_MenuGlowne();
	int wyboropcji;
	switch (wyboropcji)
	{
	case 1:
		MenuKategorie_z_bazy_dannych();
	case 2:
		MenuZamownien();
	case 3:
		menuDodawanie_Zamowienia();
	case 4:
		menuUsuwanie_Zamowienia();
	case 5:
		menuGenerowanie_Raprtu();
	case 6:
		break;
	default:
		cout << "Podany numer nie ma swojego odzwierciedlenia w menu. Prosze wybierz numer w przedziale 1-6";
		break;
	}
}