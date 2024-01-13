#include <iostream>
#include <vector>
#include "includes/Menu.h"
#include "includes/Klient.h"
#include "includes/Sprzedawca.h"
#include "includes/Mieszkanie.h"
#include "includes/Zamowienie.h"
#include "includes/BazaDanych.h"
#include "includes/Logger.h"
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
	cout << "[1] - Wyświetl Kategorie Z Bazy Danych" << endl;
    cout << "[2] - Operacje na zamówieniach" << endl;
	cout << "[3] - Wyjście" << endl;
	cout << "Wybierz jedną z opcji podanych [1-3]" << endl << endl;
}

void MenuKategorie_z_bazy_dannych()
{
	int wyborOpcji;

    do {
        cout << "Opcje kategorii do odczytu" << std::endl;
        cout << "[1] - Wyświetl Klientów" << std::endl;
        cout << "[2] - Wyświetl Sprzedawców" << std::endl;
        cout << "[3] - Wyświetl Mieszkania" << std::endl;
        cout << "[4] - Wyświetl Zamówienia" << endl;
        cout << "[5] - Powrót do Menu Głównego" << std::endl;
        cout << "Wybierz jedną z opcji (1-5): ";

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
        {
            cout << "Wyswietlanie Listy Zamówień"<<endl;

            for (Zamowienie k : Baza_Zamowienia.getCurrentAllByValue()) {
                std::cout << k.toString() << "\n";
            }
            break;
        }

        case 5:
            break;

        default:
            std::cout << "Podany numer nie ma odzwierciedlenia w menu. Proszę wybierz numer w przedziale 1-5." << std::endl;
            break;
        }

    } while (wyborOpcji != 5);
}

void MenuOperacjenaZamownieniach()
{
    int wyboropcji;
    do {
        cout << "Menu Wyswielania Zamowien:" << endl;
        cout << "[1] - Dodawanie Zamówienia" << endl;
        cout << "[2] - Usuwanie Zamówienia" << endl;
        cout << "[3] - Zmiana Zamówienia" << endl;
        cout << "[4] - Powrót do Menu Głównego" << endl;
        cout << "Wybierz jedną z opcji podanych (1-4)" << endl << endl;

        cin >> wyboropcji;

        switch (wyboropcji)
        {
        case 1:
        {
            int cyfraZamowienia;
            long IdMieszkania, IdSprzedawcy, IdKlienta;
            cout << "Dodawanie Zamówienia" << endl;
            cout<< "Podaj Status Zamówienia" <<endl;
            do {
                cout << "Podaj numer od 0 do 1" << endl << "[0]-W Trakcie Zamówienia" << "\n [1]-Zamówione" << endl;
                cin >> cyfraZamowienia;
            } while (cyfraZamowienia != 0 && cyfraZamowienia != 1);

            Zamowienie::StatusZamowienia status = (Zamowienie::StatusZamowienia)cyfraZamowienia;

            cout << "Podaj Id Mieszkania" << endl;
            cin >> IdMieszkania;
            cout << "Podaj Id Sprzedawcy" << endl;
            cin >> IdSprzedawcy;
            cout << "Podaj Id Klienta" << endl;
            cin >> IdKlienta;

            Zamowienie* zamowienie = new Zamowienie(IdMieszkania, IdSprzedawcy, IdKlienta, status);
            Baza_Zamowienia.save(*zamowienie);
                cout << "Dodano nowe zamówienie"<<endl;
                Logger::log("Dodano zamówienie o Id " + to_string(zamowienie->getId()));
            break;
        }
        case 2:
        {
            cout << "Usuwanie Zamówienia" << endl;
            do {
                long IdZamowienia;
                cout << "Podaj Id Zamówienia, które chcesz usunąć" << endl;
                cin >> IdZamowienia;
                try {
                    Zamowienie& zamowienie = Baza_Zamowienia.getById(IdZamowienia);
                    Logger::log("Usunieto zamówienie o Id " + to_string(IdZamowienia));
                    Baza_Zamowienia.remove(zamowienie);
                    break;
                }
                catch(...){
                    cout << "Takiego zamówienia nie ma w bazie, podaj poprawne ID"<<endl;
                }
            } while (true);
            
            cout << "Zamowienie zostało usunięte" << endl;
            break;
        }
        case 3:
        {
            int cyfraZamowienia;
            cout << "Zmiana statusu" << endl;
            do {
                long IdZamowienia;
                cout << "Podaj Id Zamówienia, którego status chcesz zmienić" << endl;
                cin >> IdZamowienia;
                try {
                    Zamowienie& zamowienie = Baza_Zamowienia.getById(IdZamowienia);
                    cout << "Podaj Status Zamówienia" << endl;
                    do {
                        cout << "Podaj Numer od 0 do 1" << endl << "[0]-W Trakcie Zamówienia" << "\n [1]-Zamówione" << endl;
                        cin >> cyfraZamowienia;
                    } while (cyfraZamowienia != 0 && cyfraZamowienia != 1);

                    Zamowienie::StatusZamowienia status = (Zamowienie::StatusZamowienia)cyfraZamowienia;
                    zamowienie.setStatusZamowienia(status);
                    Logger::log("Zmieniono status zamówienia " + to_string(IdZamowienia)+" na "+ to_string(int(status)));

                    break;
                }
                catch (...) {
                    cout << "Takiego zamówienia nie ma w bazie, podaj poprawne ID"<<endl;
                }
            } while (true);

            cout << "Status został zauktualizowany" << endl;
            break;
        }
        case 4:
            break;
        default:
        {
            cout << "Podany numer nie ma swojego odzwierciedlenia w menu. Prosze wybierz numer w przedziale 1-4"<<endl;
            break;
        }
        }
    }while (wyboropcji != 4);
}


