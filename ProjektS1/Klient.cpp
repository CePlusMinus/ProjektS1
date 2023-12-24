#include "includes/Klient.h"
#include "includes/Utils.h"

std::string Klient::getImie() const{
	return imie;
}

std::string Klient::getNazwisko() const{
	return nazwisko;
}

void Klient::setImie(std::string noweImie) {
	if (noweImie.length() < 1)
		throw "Imię klienta nie może być pustym napisem!";
	else
		imie = noweImie;
}

void Klient::setNazwisko(std::string noweNazwisko) {
	if (noweNazwisko.length() < 1)
		throw "Nazwisko klienta nie może być pustym napisem!";
	else
		nazwisko = noweNazwisko;
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

std::string Klient::serialize() {
	return std::to_string(id) + ';' + imie + ';' + nazwisko;
}

Klient& Klient::deserialize(std::string input) {
	std::vector<std::string> parsed = Utils::tokenizeString(input, ';');

	Klient* klient = new Klient(parsed[1], parsed[2]);
	klient->setId(stol(parsed[0]));

	return *klient;
}