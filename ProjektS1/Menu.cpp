﻿#include <iostream>
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
	cout << "Menu Główne:" << endl;
	cout << "[1] - Wyświetl Kategorie Z Bazy Dannych" << endl;
	cout << "[2] - Dodaj Zamówienie" << endl;
	cout << "[3] - Usuń Zamówienie" << endl;
	cout << "[4] - Wyswietl Liste Zamówień" << endl;
	cout << "[5] - Wyjscie" << endl;
	cout << "Wybierz jedną z opcji podanych [1-5]" << endl << endl;
}

void MenuKategorie_z_bazy_dannych()
{
	int wyborOpcji;

    do {
        std::cout << "Opcje kategorii do odczytu" << std::endl;
        std::cout << "[1] - Wyświetl Klientów" << std::endl;
        std::cout << "[2] - Wyświetl Sprzedawców" << std::endl;
        std::cout << "[3] - Wyświetl Mieszkania" << std::endl;
        std::cout << "[4] - Powrót do Menu Głównego" << std::endl;
        std::cout << "Wybierz jedną z opcji (1-4): ";

        while (!(std::cin >> wyborOpcji)) 
        {
            std::cout << "Podano nieprawidłową opcję. Proszę podać liczbę." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        switch (wyborOpcji) 
        {
        case 1: 
        {
            cout << "Wyswietlanie listy Klientów" << endl;

            for (Klient k : Baza_Klientow.getCurrentAllByValue()) {
                std::cout << k.toString() << "\n";
            }

            break;
        }

        case 2: 
        {
            std::cout << "Wyświetlanie listy Sprzedawców" << std::endl;

            for (Sprzedawca k : Baza_Sprzedawca.getCurrentAllByValue()) {
                std::cout << k.toString() << "\n";
            }

            break;
        }

        case 3: 
        {
            std::cout << "Wyświetlanie listy Mieszkań" << std::endl;

            for (Mieszkanie k : Baza_Mieszkanie.getCurrentAllByValue()) {
                std::cout << k.toString() << "\n";
            }
            break;
        }

        case 4:
            break;

        default:
            std::cout << "Podany numer nie ma odzwierciedlenia w menu. Proszę wybierz numer w przedziale 1-4." << std::endl;
            break;
        }

    } while (wyborOpcji != 4);
}

void MenuZamownien()
{
    int wyboropcji;
    do {
        cout << "Menu Wyswielania Zamowien:" << endl;
        cout << "[1] - Wyświetl Zamówienie" << endl;
        cout << "[2] - Powrót do Menu Głównego" << endl;
        cout << "Wybierz jedną z opcji podanych (1-2)" << endl << endl;

        cin >> wyboropcji;

        switch (wyboropcji)
        {
        case 1:
        {
            cout << "Wyswietlanie Listy Zamówień";

            for (Zamowienie k : Baza_Zamowienia.getCurrentAllByValue()) {
                std::cout << k.toString() << "\n";
            }
            break;
        }
        case 2:
            break; //Powrót do Menu Głównego

        default:
        {
            cout << "Podany numer nie ma swojego odzwierciedlenia w menu. Prosze wybierz numer w przedziale 1-2";
            break;
        }
        }
    }while (wyboropcji != 2);
}
/*
void menuDodawanie_Zamowienia()
{
    int wyborOpcji;

    do {
        cout << "Menu Dodawania Zamówienia:" << endl;
        cout << "[1] - Dodaj Zamówienie" << endl;
        cout << "[2] - Powrót do Menu Głównego" << endl;
        cout << "Wybierz jedną z opcji (1-2): ";
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
            cout << "Powrót do Menu Głównego" << endl;
            break;
        default:
            cout << "Podany numer nie ma swojego odzwierciedlenia w menu. Proszę wybierz numer w przedziale 1-2." << endl;
            break;
        }
    } while (wyborOpcji != 2);
}
*/

void menuUsuwanie_Zamowienia()
{
	int wyboropcji;
	cout << "Menu Usuwania Zamówienia:" << endl;
	cout << "[1] - Usuwanie Zamówienia" << endl;
	cout << "[2] - Powrót do Menu Głównego" << endl;
	cout << "Wybierz jedną z opcji podanych (1-2)" << endl << endl;

	cin >> wyboropcji;

	switch (wyboropcji)
	{
	case 1:
	{
		cout << "Usuwanie Zamówienia";
		//kod
	}
	case 2:
		break; //Powrót do Menu Głównego

	default:
		cout << "Podany numer nie ma swojego odzwierciedlenia w menu. Prosze wybierz numer w przedziale 1-2";
		break;
	}
}
