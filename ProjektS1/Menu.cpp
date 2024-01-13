#include <iostream>
#include <vector>
#include "includes/Menu.h"
#include "includes/Klient.h"
#include "includes/Sprzedawca.h"
#include "includes/Mieszkanie.h"
#include "includes/Zamowienie.h"
#include "includes/BazaDanych.h"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>

using namespace std;

BazaDanych <Klient> Baza_Klientow;
BazaDanych <Sprzedawca> Baza_Sprzedawca;
BazaDanych <Mieszkanie> Baza_Mieszkanie;
BazaDanych <Zamowienie> Baza_Zamowienia;

void Wyswietl_MenuGlowne()
{
	cout << "Menu G��wne:" << endl;
	cout << "[1] - Wy�wietl Kategorie Z Bazy Dannych" << endl;
	cout << "[2] - Dodaj Zam�wienie" << endl;
	cout << "[3] - Usu� Zam�wienie" << endl;
	cout << "[4] - Wyswietl Liste Zam�wie�" << endl;
	cout << "[5] - Wyjscie" << endl;
	cout << "Wybierz jedn� z opcji podanych [1-5]" << endl << endl;
}

void MenuKategorie_z_bazy_dannych()
{
	int wyborOpcji;

    do {
        std::cout << "Opcje kategorii do odczytu" << std::endl;
        std::cout << "[1] - Wy�wietl Klient�w" << std::endl;
        std::cout << "[2] - Wy�wietl Sprzedawc�w" << std::endl;
        std::cout << "[3] - Wy�wietl Mieszkania" << std::endl;
        std::cout << "[4] - Powr�t do Menu G��wnego" << std::endl;
        std::cout << "Wybierz jedn� z opcji (1-4): ";

        while (!(std::cin >> wyborOpcji)) 
        {
            std::cout << "Podano nieprawid�ow� opcj�. Prosz� poda� liczb�." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        switch (wyborOpcji) 
        {
        case 1: 
        {
            cout << "Wyswietlanie listy Klient�w" << endl;

            for (Klient k : Baza_Klientow.getCurrentAllByValue()) {
                std::cout << k.toString() << "\n";
            }

            break;
        }

        case 2: 
        {
            std::cout << "Wy�wietlanie listy Sprzedawc�w" << std::endl;

            for (Sprzedawca k : Baza_Sprzedawca.getCurrentAllByValue()) {
                std::cout << k.toString() << "\n";
            }

            break;
        }

        case 3: 
        {
            std::cout << "Wy�wietlanie listy Mieszka�" << std::endl;

            for (Mieszkanie k : Baza_Mieszkanie.getCurrentAllByValue()) {
                std::cout << k.toString() << "\n";
            }
            break;
        }

        case 4:
            break;

        default:
            std::cout << "Podany numer nie ma odzwierciedlenia w menu. Prosz� wybierz numer w przedziale 1-4." << std::endl;
            break;
        }

    } while (wyborOpcji != 4);
}

void MenuZamownien()
{
	int wyboropcji;
    do {
        cout << "Menu Wyswielania Zamowien:" << endl;
        cout << "[1] - Wy�wietl Zam�wienie" << endl;
        cout << "[2] - Powr�t do Menu G��wnego" << endl;
        cout << "Wybierz jedn� z opcji podanych (1-2)" << endl << endl;

        cin >> wyboropcji;

        switch (wyboropcji)
        {
        case 1:
        {
            cout << "Wyswietlanie Listy Zam�wie�";

            for (Zamowienie k : Baza_Zamowienia.getCurrentAllByValue()) {
                std::cout << k.toString() << "\n";
            }
            break;
        }
        case 2:
            break; //Powr�t do Menu G��wnego

        default:
            cout << "Podany numer nie ma swojego odzwierciedlenia w menu. Prosze wybierz numer w przedziale 1-2";
            break;
        }
    }(wyborOpcji != 2);
}

void menuDodawanie_Zamowienia()
{
    int wyborOpcji;

    do {
        cout << "Menu Dodawania Zam�wienia:" << endl;
        cout << "[1] - Dodaj Zam�wienie" << endl;
        cout << "[2] - Powr�t do Menu G��wnego" << endl;
        cout << "Wybierz jedn� z opcji (1-2): ";
        cin >> wyborOpcji;

        switch (wyborOpcji)
        {
        case 1:
        {
            bool wpisano = false;
            Zamowienie* pNew = new Zamowienie();
            while (!wpisano)
            {
                if (pNew->uzupelnijDane())
                {
                    wpisano = true;
                }
            }

            pNew->wypisz();
            pNew->dodajZamowienie();

            delete pNew;
        }
        break;
        case 2:
            cout << "Powr�t do Menu G��wnego" << endl;
            break;
        default:
            cout << "Podany numer nie ma swojego odzwierciedlenia w menu. Prosz� wybierz numer w przedziale 1-2." << endl;
            break;
        }
    } while (wyborOpcji != 2);
}

void menuUsuwanie_Zamowienia()
{
	int wyboropcji;
	cout << "Menu Usuwania Zam�wienia:" << endl;
	cout << "[1] - Usuwanie Zam�wienia" << endl;
	cout << "[2] - Powr�t do Menu G��wnego" << endl;
	cout << "Wybierz jedn� z opcji podanych (1-2)" << endl << endl;

	cin >> wyboropcji;

	switch (wyboropcji)
	{
	case 1:
	{
		cout << "Usuwanie Zam�wienia";
		//kod
	}
	case 2:
		break; //Powr�t do Menu G��wnego

	default:
		cout << "Podany numer nie ma swojego odzwierciedlenia w menu. Prosze wybierz numer w przedziale 1-2";
		break;
	}
}

