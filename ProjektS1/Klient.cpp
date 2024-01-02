#include "includes/Klient.h"

std::string Klient::getImie() const{
	return imie;
}

std::string Klient::getNazwisko() const{
	return nazwisko;
}

void Klient::setImie(std::string noweImie) {
	if (validate(noweImie, std::regex("^[A-Z][a-z]+$")))
		imie = noweImie;
	else
		throw "Niepoprawne imię klienta";
}

void Klient::setNazwisko(std::string noweNazwisko) {
	if (validate(noweNazwisko, std::regex("^[A-Z][a-z]+$")))
		nazwisko = noweNazwisko;
	else
		throw "Niepoprawne nazwisko klienta";
}

Klient::Klient(std::string imie, std::string nazwisko) {
	setImie(imie);
	setNazwisko(nazwisko);
}

//Implementacja metody abstrakcyjnej "toString" z "KlasaBazowa"
std::string Klient::toString() {
	std::string idString = id == -1 ? "[NIE USTAWIONO]" : std::to_string(id);
	std::string wynik = "Klient[ID: " + idString + ", Imię: " + imie + ", Nazwisko: " + nazwisko + "]";

	return wynik;
}