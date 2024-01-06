#include <iostream>
#include <vector>
#include "includes/Menu.h"
#include "includes/Klient.h"
#include "includes/Sprzedawca.h"
#include "includes/Mieszkanie.h"
#include "includes/Zam�wienie.h"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>

using namespace std;
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
            std::cout << "Wy�wietlanie listy Klient�w" << std::endl;

            std::ifstream plik("klienci.txt");
            if (!plik.is_open()) {
                std::cerr << "Nie mo�na otworzy� pliku: klienci.txt\n";
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
                    std::cerr << "B��d deserializacji: " << msg << std::endl;
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
            std::cout << "Wy�wietlanie listy Sprzedawc�w" << std::endl;

            std::ifstream plikSprzedawcy("sprzedawcy.txt");
            if (!plikSprzedawcy.is_open()) 
            {
                std::cerr << "Nie mo�na otworzy� pliku: sprzedawcy.txt\n";
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
                    std::cerr << "B��d deserializacji: " << msg << std::endl;
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
            std::cout << "Wy�wietlanie listy Mieszka�" << std::endl;

            std::ifstream plikMieszkania("mieszkania.txt");
            if (!plikMieszkania.is_open()) 
            {
                std::cerr << "Nie mo�na otworzy� pliku: mieszkania.txt\n";
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
                    std::cerr << "B��d deserializacji: " << msg << std::endl;
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

            std::ifstream plikZamowien("zamowienia.txt");
            if (!plikZamowien.is_open()) {
                std::cerr << "Nie mo�na otworzy� pliku: zamowienia.txt\n";
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
                    std::cerr << "B��d deserializacji zam�wienia: " << msg << std::endl;
                }
            }

            plikZamowien.close();

            for (const auto& zamowienie : listaZamowien) {
                std::cout << zamowienie.toString() << std::endl;
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

