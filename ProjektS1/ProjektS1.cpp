﻿#include <iostream>
#include <locale>
#include "includes/Klient.h"
#include "includes/BazaDanych.h"

int main()
{
	std::setlocale(LC_ALL, "Polish.UTF-8");

	//UWAGA: Ten kod zakłada, że w pliku "class Klient.txt" jest linijka, w której jest klient o id 21! np.: 21;Marco;Polo

	Klient klient("Grzegorz", "Brzeczyszczykiewicz");
	BazaDanych<Klient> bazaKlientow; //Obiekt, zarządzający listą obiektów danego typu

	std::cout << bazaKlientow.getById(21).toString() << "\n";

	std::cout << klient.toString() << "\n";

	bazaKlientow.save(klient); //Dodajemy referencję obiektu do listy, jeśli coś pozmieniamy to w liście też się zmieni

	klient.setImie("Pawel");
	klient.setNazwisko("Gawlowski");

	//Zmieniliśmy dane w kliencie, ale w liście też się zmieni bo tam mamy referencję do obiektu klient
	std::cout << bazaKlientow.getById(22).toString() << "\n";

	//bazaKlientow.remove(klient); //Usuwamy klienta z listy, nie zapisze się w pliku

	Klient& zeStringa = Klient::deserialize("20;Michael;Desanta"); //Obiekty pobrane z metody 'deserialize' MUSIMY traktować jako referencje!
	bazaKlientow.save(zeStringa);

	std::cout << klient.serialize() << "\n";
	std::cout << zeStringa.toString() << "\n";

	//Metodę "getCurrentAllByValue" najlepiej używajmy tylko do wypisywania wszystkich klientów w menu, bo nie można zmieniać danych klientów w tej liście którą zwraca
	std::cout << "WYPISANIE WSZYSTKICH W BAZIE \n \n";
	for (Klient k : bazaKlientow.getCurrentAllByValue()) {
		std::cout << k.toString() << "\n";
	}
}