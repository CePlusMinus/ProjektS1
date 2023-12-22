#include <iostream>
#include <locale>
#include "includes/Klient.h"
#include "includes/BazaDanych.h"

int main()
{
	std::setlocale(LC_CTYPE, "Polish");

	Klient klient("Grzegorz", "Brz�czyszczykiewicz");
	BazaDanych<Klient> bazaKlientow; //Obiekt, zarz�dzaj�cy list� obiekt�w danego typu

	std::cout << klient.toString() << "\n";

	bazaKlientow.save(klient); //Dodajemy referencj� obiektu do listy, je�li co� pozmieniamy to w li�cie te� si� zmieni

	klient.setImie("Pawe�");
	klient.setNazwisko("Gaw�owski");

	//Zmienili�my dane w kliencie, ale w li�cie te� si� zmieni bo tam mamy referencj� do obiektu klient
	std::cout << bazaKlientow.getById(1).toString() << "\n";

	bazaKlientow.remove(klient); //Usuwamy klienta z listy, nie zapisze si� w pliku
}