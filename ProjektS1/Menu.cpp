#include <iostream>
#include "includes/Menu.h"
#include "fstream"

using namespace std;
void Wyswietl_MenuGlowne()
{
	cout << "Menu G��wne:" << endl;
	cout << "[1] - Wy�wietl Kategorie Z Bazy Dannych" << endl;
	cout << "[2] - Dodaj Zam�wienie" << endl;
	cout << "[3] - Usu� Zam�wienie" << endl;
	cout << "[4] - Wyswietl Liste Zam�wie�" << endl;
	cout << "[5] - Wygeneruj Raport z dzia�ania programu" << endl;
	cout << "[6] - Wyjscie" << endl;
	cout << "Wybierz jedn� z opcji podanych [1-6]" << endl << endl;
}

void MenuKategorie_z_bazy_dannych()
{
	int wyboropcji;
	cout << "Opcje kategori do odczytu" << endl;
	cout << "[1] - Wy�wietl Klent�w" << endl;
	cout << "[2] - Wy�wietl Sprzedawc�w "<< endl;
	cout << "[3] - Wy�wietl Mieszkaia" << endl;
	cout << "[4] - Powr�t do Menu G��wnego" << endl;
	cout << "Wybierz jedn� z opcji podanych (1-4)" << endl << endl;

	cin >> wyboropcji;

	switch (wyboropcji)
	{
	case 1:
	{
		cout << "Wyswietlanie listy Klient�w" << endl;
		//kod
	}
	case 2:
	{
		cout << "Wyswietlanie listy Sprzedawc�w" << endl;
		//kod
	}
	case 3:
	{
		cout << "Wyswietlanie listy Mieszka�" << endl;
		//kod
	}
	case 4:
		break; //Powr�t do Menu G��wnego
	default:
		cout << "Podany numer nie ma swojego odzwierciedlenia w menu. Prosze wybierz numer w przedziale 1-4";
		break;
	}
}
void MenuZamownien()
{
	int wyboropcji;
	cout << "Menu Wyswielania Zamowien:" << endl;
	cout << "[1] - Wy�wietl Zam�wienie" << endl;
	cout << "[2] - Powr�t do Menu G��wnego" << endl;
	cout << "Wybierz jedn� z opcji podanych (1-2)" << endl << endl;

	cin >> wyboropcji;

	switch (wyboropcji)
	{
	case 1:
	{
		cout << "Wyswietlanie Zam�wienia";
		//kod
	}
	case 2:
		break; //Powr�t do Menu G��wnego

	default:
		cout << "Podany numer nie ma swojego odzwierciedlenia w menu. Prosze wybierz numer w przedziale 1-2";
		break;
	}
}

void menuDodawanie_Zamowienia()
{
	int wyboropcji;
	cout << "Menu Dodawania Zam�wienia:" << endl;
	cout << "[1] - Dodaj Zam�wienie" << endl;
	cout << "[2] - Powr�t do Menu G��wnego" << endl;
	cout << "Wybierz jedn� z opcji podanych (1-2)" << endl << endl;

	cin >> wyboropcji;

	switch (wyboropcji)
	{
	case 1:
	{
		cout << "Dodawanie Zam�wienia";
		//kod
	}
	case 2:
		break; //Powr�t do Menu G��wnego

	default:
		cout << "Podany numer nie ma swojego odzwierciedlenia w menu. Prosze wybierz numer w przedziale 1-2";
		break;
	}
}

void menuUsuwanie_Zamowienia()
{
	int wyboropcji;
	cout << "Menu Dodawania Zam�wienia:" << endl;
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

void menuGenerowanie_Raportu()
{
	cout << "Menu Wygenerowania Raportu:" << endl;
	cout << "[1] - Wy�wietl Raport" << endl;
	cout << "[2] - Powr�t do Menu G��wnego" << endl;
	cout << "Wybierz jedn� z opcji podanych (1-2)" << endl << endl;

	cin >> wyboropcji;

	switch (wyboropcji)
	{
	case 1:
	{
		cout << "Wy�wietl Raport";
		//kod
	}
	case 2:
		break; //Powr�t do Menu G��wnego

	default:
		cout << "Podany numer nie ma swojego odzwierciedlenia w menu. Prosze wybierz numer w przedziale 1-2";
		break;
	}
}