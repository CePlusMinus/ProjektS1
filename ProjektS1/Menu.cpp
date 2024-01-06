#include <iostream>
#include <vector>
#include "includes/Menu.h"
#include "includes/Klient.h"
#include "includes/Sprzedawca.h"
#include "includes/Mieszkanie.h"
#include "includes/Zamówienie.h"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>

using namespace std;
void Wyswietl_MenuGlowne()
{
	cout << "Menu G³ówne:" << endl;
	cout << "[1] - Wyœwietl Kategorie Z Bazy Dannych" << endl;
	cout << "[2] - Dodaj Zamówienie" << endl;
	cout << "[3] - Usuñ Zamówienie" << endl;
	cout << "[4] - Wyswietl Liste Zamówieñ" << endl;
	cout << "[5] - Wyjscie" << endl;
	cout << "Wybierz jedn¹ z opcji podanych [1-5]" << endl << endl;
}

void MenuKategorie_z_bazy_dannych()
{
	int wyborOpcji;

    do {
        std::cout << "Opcje kategorii do odczytu" << std::endl;
        std::cout << "[1] - Wyœwietl Klientów" << std::endl;
        std::cout << "[2] - Wyœwietl Sprzedawców" << std::endl;
        std::cout << "[3] - Wyœwietl Mieszkania" << std::endl;
        std::cout << "[4] - Powrót do Menu G³ównego" << std::endl;
        std::cout << "Wybierz jedn¹ z opcji (1-4): ";

        while (!(std::cin >> wyborOpcji)) 
        {
            std::cout << "Podano nieprawid³ow¹ opcjê. Proszê podaæ liczbê." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        switch (wyborOpcji) 
        {
        case 1: 
        {
            std::cout << "Wyœwietlanie listy Klientów" << std::endl;

            std::ifstream plik("klienci.txt");
            if (!plik.is_open()) {
                std::cerr << "Nie mo¿na otworzyæ pliku: klienci.txt\n";
                break;
            }

            listaKlientow.clear();

            std::string linia;
            while (std::getline(plik, linia)) {
                try {
                    Klient klient = Klient::deserialize(linia);
                    listaKlientow.push_back(klient);
                }
                catch (const char* msg) {
                    std::cerr << "B³¹d deserializacji: " << msg << std::endl;
                }
            }

            plik.close();

            for (const auto& klient : listaKlientow) {
                std::cout << klient.toString() << std::endl;
            }
            break;
        }

        case 2: 
        {
            std::cout << "Wyœwietlanie listy Sprzedawców" << std::endl;

            std::ifstream plikSprzedawcy("sprzedawcy.txt");
            if (!plikSprzedawcy.is_open()) 
            {
                std::cerr << "Nie mo¿na otworzyæ pliku: sprzedawcy.txt\n";
                break;
            }

            listaSprzedawcow.clear();

            std::string liniaSprzedawcy;
            while (std::getline(plikSprzedawcy, liniaSprzedawcy)) 
            {
                try 
                {
                    Sprzedawca sprzedawca = Sprzedawca::deserialize(liniaSprzedawcy);
                    listaSprzedawcow.push_back(sprzedawca);
                }
                catch (const char* msg) 
                {
                    std::cerr << "B³¹d deserializacji: " << msg << std::endl;
                }
            }

            plikSprzedawcy.close();

            for (const auto& sprzedawca : listaSprzedawcow) 
            {
                std::cout << sprzedawca.toString() << std::endl;
            }
            break;
        }

        case 3: 
        {
            std::cout << "Wyœwietlanie listy Mieszkañ" << std::endl;

            std::ifstream plikMieszkania("mieszkania.txt");
            if (!plikMieszkania.is_open()) 
            {
                std::cerr << "Nie mo¿na otworzyæ pliku: mieszkania.txt\n";
                break;
            }

            listaMieszkan.clear();

            std::string liniaMieszkania;
            while (std::getline(plikMieszkania, liniaMieszkania)) 
            {
                try 
                {
                    Mieszkanie mieszkanie = Mieszkanie::deserialize(liniaMieszkania);
                    listaMieszkan.push_back(mieszkanie);
                }
                catch (const char* msg) 
                {
                    std::cerr << "B³¹d deserializacji: " << msg << std::endl;
                }
            }

            plikMieszkania.close();

            for (const auto& mieszkanie : listaMieszkan) 
            {
                std::cout << mieszkanie.toString() << std::endl;
            }
            break;
        }

        case 4:
            break;

        default:
            std::cout << "Podany numer nie ma odzwierciedlenia w menu. Proszê wybierz numer w przedziale 1-4." << std::endl;
            break;
        }

    } while (wyborOpcji != 4);
}

void MenuZamownien()
{
	int wyboropcji;
    do {
        cout << "Menu Wyswielania Zamowien:" << endl;
        cout << "[1] - Wyœwietl Zamówienie" << endl;
        cout << "[2] - Powrót do Menu G³ównego" << endl;
        cout << "Wybierz jedn¹ z opcji podanych (1-2)" << endl << endl;

        cin >> wyboropcji;

        switch (wyboropcji)
        {
        case 1:
        {
            cout << "Wyswietlanie Listy Zamówieñ";

            std::ifstream plikZamowien("zamowienia.txt");
            if (!plikZamowien.is_open()) {
                std::cerr << "Nie mo¿na otworzyæ pliku: zamowienia.txt\n";
                break;
            }

            listaZamowien.clear();

            std::string liniaZamowienia;
            while (std::getline(plikZamowien, liniaZamowienia)) {
                try {
                    Zamowienie zamowienie = Zamowienie::deserialize(liniaZamowienia);
                    listaZamowien.push_back(zamowienie);
                }
                catch (const char* msg) {
                    std::cerr << "B³¹d deserializacji zamówienia: " << msg << std::endl;
                }
            }

            plikZamowien.close();

            for (const auto& zamowienie : listaZamowien) {
                std::cout << zamowienie.toString() << std::endl;
            }
            break;
        }
        case 2:
            break; //Powrót do Menu G³ównego

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
        cout << "Menu Dodawania Zamówienia:" << endl;
        cout << "[1] - Dodaj Zamówienie" << endl;
        cout << "[2] - Powrót do Menu G³ównego" << endl;
        cout << "Wybierz jedn¹ z opcji (1-2): ";
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
            cout << "Powrót do Menu G³ównego" << endl;
            break;
        default:
            cout << "Podany numer nie ma swojego odzwierciedlenia w menu. Proszê wybierz numer w przedziale 1-2." << endl;
            break;
        }
    } while (wyborOpcji != 2);
}

void menuUsuwanie_Zamowienia()
{
	int wyboropcji;
	cout << "Menu Usuwania Zamówienia:" << endl;
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

