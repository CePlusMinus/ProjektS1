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
#include <limits>

using namespace std;

BazaDanych <Klient> Baza_Klientow;
BazaDanych <Sprzedawca> Baza_Sprzedawca;
BazaDanych <Mieszkanie> Baza_Mieszkanie;
BazaDanych <Zamowienie> Baza_Zamowienia;


void Wyswietl_MenuGlowne()
{
    system("cls");

    cout << "\x1B[91;3m" << "|\t|MENU GŁÓWNE|\t    |" << "\x1B[0m" << endl;
	cout <<"\x1B[91;3m"<< "[1]"<<"\x1B[0m"<<"Wyświetl kategorie z bazy danych\n";
    cout << "\x1B[91;3m"<< "[2]" << "\x1B[0m" << "Operacje na zamówieniach\n";
	cout << "\x1B[91;3m"<< "[3]" << "\x1B[0m"<< "Wyjście\n\n";
    cout << "Wybierz jedną z opcji podanych [1-3]\n\n";
}

void MenuKategorie_z_bazy_dannych()
{
	int wyborOpcji;
    

    do {
        cout <<"\x1B[91;3m" << "OPCJE KATEGORII DO ODCZYTU" << "\x1B[0m" << endl;
        cout <<"\x1B[91;3m" << "[1]" << "\x1B[0m" << "Wyświetl Klientów" <<endl;
        cout <<"\x1B[91;3m" << "[2]" << "\x1B[0m" << "Wyświetl Sprzedawców" << endl;
        cout <<"\x1B[91;3m" << "[3]" << "\x1B[0m" << "Wyświetl Mieszkania" << endl;
        cout <<"\x1B[91;3m" << "[4]" << "\x1B[0m" << "Wyświetl Zamówienia" << endl;
        cout <<"\x1B[91;3m" << "[5]" << "\x1B[0m" << "Powrót do Menu Głownego\n" << endl;
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
            system("cls");
            cout << "\x1B[91;3m" << "WYŚWIETLANIE LISTY KLIENTÓW" << "\x1B[0m" << endl;
            cout << left<<setw(3) << "ID" <<left<< setw(20) << "Imię" <<left<< setw(20) << " Nazwisko" << endl;

            for (Klient k : Baza_Klientow.getCurrentAllByValue()) {
                std::cout << k.toString()<<"\n";
            }

            break;
        }

        case 2: 
        {
            system("cls");
            cout << "\x1B[91;3m" << "WYŚWIETLANIE LISTY SPRZEDAWCÓW" << "\x1B[0m" << endl;
            cout << left << setw(3) << "ID" << left << setw(20) << "Imię" << left << setw(20) << " Nazwisko" << left<<setw(40)<<" Email"<<left<<setw(14)<<" Numer telefonu"<<endl;
            for (Sprzedawca k : Baza_Sprzedawca.getCurrentAllByValue()) {
                std::cout << k.toString() << "\n";
            }

            break;
        }

        case 3: 
        {
            system("cls");
            cout << "\x1B[91;3m" << "WYŚWIETLANIE LISTY MIESZKAŃ" << "\x1B[0m" << endl;
            cout << left << setw(3) << "ID" << left << setw(20) << "Ulica" << left << setw(17) << "Numer mieszkania" << left << setw(11) << "Wyposażone" << left << setw(10) << " Wielkość" << left << setw(10) << "  Cena" << left << "  Właściciel" << endl;
            for (Mieszkanie k : Baza_Mieszkanie.getCurrentAllByValue()) {
                std::cout << k.toString() << "\n";
            }
            break;
        }

        case 4:
        {
            system("cls");
            cout << "\x1B[91;3m" << "WYŚWIETLANIE LISTY ZAMÓWIEŃ" << "\x1B[0m" << endl;
            cout << left << setw(3) << "ID" << left << setw(15) << "ID mieszkania" << left << setw(15) << "ID sprzedawcy" << left << setw(15) << "ID klienta" << left << "Status" << endl;
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
        cout << "\x1B[91;3m" << "OPERACJE NA ZAMÓWIENIACH" << "\x1B[0m" << endl;
        cout << "\x1B[91;3m" << "[1]" << "\x1B[0m" << "Dodawanie Zamówienia" << endl;
        cout << "\x1B[91;3m" << "[2]" << "\x1B[0m" << "Usuwanie Zamówienia" << endl;
        cout << "\x1B[91;3m" << "[3]" << "\x1B[0m" << "Zmiana Statusu Zamówienia" << endl;
        cout << "\x1B[91;3m" << "[4]" << "\x1B[0m" << "Powrót do Menu Głownego\n" << endl;
        cout << "Wybierz jedną z opcji podanych (1-4)" << endl << endl;

        cin >> wyboropcji;

        switch (wyboropcji)
        {
        case 1:
        {
            system("cls");
            int cyfraZamowienia;
            long IdMieszkania, IdSprzedawcy, IdKlienta;
            cout << "\x1B[91;3m" << "DODAWANIE ZAMÓWIENIA" << "\x1B[0m" << endl;
            cout<< "Podaj Status Zamówienia" <<endl;
            do {
                cout << "Podaj numer od 0 do 1" << endl << "[0]-W Trakcie Zamówienia" << "\n[1]-Zamówione" << endl;
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
            system("cls");
            cout << "\x1B[91;3m" << "USUWANIE ZAMÓWIENIA" << "\x1B[0m" << endl;
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
            system("cls");
            int cyfraZamowienia;
            cout << "\x1B[91;3m" << "ZMIANA STATUSU ZAMÓWIENIA" << "\x1B[0m" << endl;
            do {
                long IdZamowienia;
                cout << "Podaj Id Zamówienia, którego status chcesz zmienić" << endl;
                cin >> IdZamowienia;
                try {
                    Zamowienie& zamowienie = Baza_Zamowienia.getById(IdZamowienia);
                    cout << "Podaj Status Zamówienia\n" << endl;
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


