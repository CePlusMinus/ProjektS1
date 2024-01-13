﻿#include <iostream>
#include <locale>
#include "includes/Menu.h"
#include "includes/Logger.h"

using namespace std;
int main()
{
	std::setlocale(LC_ALL, "Polish.UTF-8");

	Logger::log("Uruchomiono program");
	Wyswietl_MenuGlowne();
	int wyboropcji = 0;

	cin >> wyboropcji;

	switch (wyboropcji)
	{
	case 1:
		MenuKategorie_z_bazy_dannych();
	case 2:
		MenuOperacjenaZamownieniach();
	case 3:
		break;
	default:
		cout << "Podany numer nie ma swojego odzwierciedlenia w menu. Prosze wybierz numer w przedziale 1-3";
		break;
	}
	Logger::log("Zamknięto program");
	Logger::flush();
}