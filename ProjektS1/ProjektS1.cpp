#include <iostream>
#include <locale>
#include "includes/Klient.h"
#include "includes/BazaDanych.h"

int main()
{
	std::setlocale(LC_ALL, "Polish.UTF-8");

	Klient klient("Grzegorz", "Brzęczyszczykiewicz");
	BazaDanych<Klient> bazaKlientow; //Obiekt, zarządzający listą obiektów danego typu

	std::cout << klient.toString() << "\n";

	bazaKlientow.save(klient); //Dodajemy referencję obiektu do listy, jeśli coś pozmieniamy to w liście też się zmieni

	klient.setImie("Paweł");
	klient.setNazwisko("Gawłowski");

	//Zmieniliśmy dane w kliencie, ale w liście też się zmieni bo tam mamy referencję do obiektu klient
	std::cout << bazaKlientow.getById(1).toString() << "\n";

	bazaKlientow.remove(klient); //Usuwamy klienta z listy, nie zapisze się w pliku
}