#include <iostream>
#include "includes/Menu.h"
#include "fstream"

using namespace std;
void Wyswietl_MenuGlowne()
{
	cout << "Menu G³ówne:" << endl;
	cout << "[1] - Wyœwietl Kategorie Z Bazy Dannych" << endl;
	cout << "[2] - Dodaj Zamówienie" << endl;
	cout << "[3] - Usuñ Zamówienie" << endl;
	cout << "[4] - Wyswietl Liste Zamówieñ" << endl;
	cout << "[5] - Wygeneruj Raport z dzia³ania programu" << endl;
	cout << "[6] - Wyjscie" << endl;
	cout << "Wybierz jedn¹ z opcji podanych [1-6]" << endl << endl;
}

void MenuKategorie_z_bazy_dannych()
{
	int wyboropcji;
	cout << "Opcje kategori do odczytu" << endl;
	cout << "[1] - Wyœwietl Klentów" << endl;
	cout << "[2] - Wyœwietl Sprzedawców "<< endl;
	cout << "[3] - Wyœwietl Mieszkaia" << endl;
	cout << "[4] - Powrót do Menu G³ównego" << endl;
	cout << "Wybierz jedn¹ z opcji podanych (1-4)" << endl << endl;

	cin >> wyboropcji;

	switch (wyboropcji)
	{
	case 1:
	{
		cout << "Wyswietlanie listy Klientów" << endl;
		//kod
	}
	case 2:
	{
		cout << "Wyswietlanie listy Sprzedawców" << endl;
		//kod
	}
	case 3:
	{
		cout << "Wyswietlanie listy Mieszkañ" << endl;
		//kod
	}
	case 4:
		break; //Powrót do Menu G³ównego
	default:
		cout << "Podany numer nie ma swojego odzwierciedlenia w menu. Prosze wybierz numer w przedziale 1-4";
		break;
	}
}
void MenuZamownien()
{
	int wyboropcji;
	cout << "Menu Wyswielania Zamowien:" << endl;
	cout << "[1] - Wyœwietl Zamówienie" << endl;
	cout << "[2] - Powrót do Menu G³ównego" << endl;
	cout << "Wybierz jedn¹ z opcji podanych (1-2)" << endl << endl;

	cin >> wyboropcji;

	switch (wyboropcji)
	{
	case 1:
	{
		cout << "Wyswietlanie Zamówienia";
		//kod
	}
	case 2:
		break; //Powrót do Menu G³ównego

	default:
		cout << "Podany numer nie ma swojego odzwierciedlenia w menu. Prosze wybierz numer w przedziale 1-2";
		break;
	}
}

void menuDodawanie_Zamowienia()
{
	int wyboropcji;
	cout << "Menu Dodawania Zamówienia:" << endl;
	cout << "[1] - Dodaj Zamówienie" << endl;
	cout << "[2] - Powrót do Menu G³ównego" << endl;
	cout << "Wybierz jedn¹ z opcji podanych (1-2)" << endl << endl;

	cin >> wyboropcji;

	switch (wyboropcji)
	{
	case 1:
	{
		cout << "Dodawanie Zamówienia";
		//kod
	}
	case 2:
		break; //Powrót do Menu G³ównego

	default:
		cout << "Podany numer nie ma swojego odzwierciedlenia w menu. Prosze wybierz numer w przedziale 1-2";
		break;
	}
}

void menuUsuwanie_Zamowienia()
{
	int wyboropcji;
	cout << "Menu Dodawania Zamówienia:" << endl;
	cout << "[1] - Usuwanie Zamówienia" << endl;
	cout << "[2] - Powrót do Menu G³ównego" << endl;
	cout << "Wybierz jedn¹ z opcji podanych (1-2)" << endl << endl;

	cin >> wyboropcji;

	switch (wyboropcji)
	{
	case 1:
	{
		cout << "Usuwanie Zamówienia";
		//kod
	}
	case 2:
		break; //Powrót do Menu G³ównego

	default:
		cout << "Podany numer nie ma swojego odzwierciedlenia w menu. Prosze wybierz numer w przedziale 1-2";
		break;
	}
}

void menuGenerowanie_Raportu()
{
	cout << "Menu Wygenerowania Raportu:" << endl;
	cout << "[1] - Wyœwietl Raport" << endl;
	cout << "[2] - Powrót do Menu G³ównego" << endl;
	cout << "Wybierz jedn¹ z opcji podanych (1-2)" << endl << endl;

	cin >> wyboropcji;

	switch (wyboropcji)
	{
	case 1:
	{
		cout << "Wyœwietl Raport";
		//kod
	}
	case 2:
		break; //Powrót do Menu G³ównego

	default:
		cout << "Podany numer nie ma swojego odzwierciedlenia w menu. Prosze wybierz numer w przedziale 1-2";
		break;
	}
}