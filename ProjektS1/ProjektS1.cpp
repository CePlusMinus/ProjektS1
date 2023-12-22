#include <iostream>
#include <locale>
#include "includes/Klient.h"
#include "includes/BazaDanych.h"

int main()
{
	std::setlocale(LC_CTYPE, "Polish");

	Klient klient("Grzegorz", "Brzêczyszczykiewicz");
	BazaDanych<Klient> bazaKlientow; //Obiekt, zarz¹dzaj¹cy list¹ obiektów danego typu

	std::cout << klient.toString() << "\n";

	bazaKlientow.save(klient); //Dodajemy referencjê obiektu do listy, jeœli coœ pozmieniamy to w liœcie te¿ siê zmieni

	klient.setImie("Pawe³");
	klient.setNazwisko("Gaw³owski");

	//Zmieniliœmy dane w kliencie, ale w liœcie te¿ siê zmieni bo tam mamy referencjê do obiektu klient
	std::cout << bazaKlientow.getById(1).toString() << "\n";

	bazaKlientow.remove(klient); //Usuwamy klienta z listy, nie zapisze siê w pliku
}