﻿#include <iostream>
#include <locale>
#include "includes/Menu.h"
#include "includes/Logger.h"

using namespace std;
int main()
{
	std::setlocale(LC_ALL, "Polish.UTF-8");

	Logger::log("Uruchomiono program");
	while (true) {
		Wyswietl_MenuGlowne();
		int wyboropcji = 0;

		cin >> wyboropcji;
		system("cls");
		switch (wyboropcji)
		{
		case 1: {
			MenuKategorie_z_bazy_dannych();
			break;
		}
		case 2: {
			MenuOperacjenaZamownieniach();
			break;
		}
		case 3: {
			Logger::log("Zamknięto program");
			Logger::flush();
			exit(0);
			break;
		}
		default: {
			cout << "Podany numer nie ma swojego odzwierciedlenia w menu. Prosze wybierz numer w przedziale 1-3\n\n";
			break;
		}
		 std::cin.clear();
		 std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
}