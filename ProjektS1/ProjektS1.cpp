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
	int wyboropcji = 0;

	cin >> wyboropcji;

	switch (wyboropcji)
	{
	case 1:
		MenuKategorie_z_bazy_dannych();
	case 2:
		MenuZamownien();
	case 3:
		
	case 6:
		break;
	default:
		cout << "Podany numer nie ma swojego odzwierciedlenia w menu. Prosze wybierz numer w przedziale 1-6";
		break;
	}
}