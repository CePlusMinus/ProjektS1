#include <iostream>
#include "includes/Sprzedawca.h"
#include <regex>
#include "includes/Utils.h"

std::string Sprzedawca::getImie() const {
	return imie;
}

std::string Sprzedawca::getNazwisko() const {
	return nazwisko;
}

std::string Sprzedawca::getEmail()const {
	return email;
}

std::string Sprzedawca::getNumer()const
{
	return numer;
}
void Sprzedawca::setImie(std::string noweImie) {
	if (validate(noweImie, std::regex("^[A-Z][a-z]+$")))
		imie = noweImie;
	else
		throw "Niepoprawne imię sprzedawcy";
}

void Sprzedawca::setNazwisko(std::string noweNazwisko) {
	if (validate(noweNazwisko, std::regex("^[A-Z][a-z]+$")))
		nazwisko = noweNazwisko;
	else
		throw "Niepoprawne nazwisko sprzedawcy";
}


void Sprzedawca::setEmail(std::string nowyEmail)
{
	std::regex wzorEmail("^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\\.[a-zA-Z0-9-.]+$");
	if (std::regex_match(nowyEmail, wzorEmail))
		email = nowyEmail;
	else
		throw "Niepoprawny email";
		
}

void Sprzedawca::setNumer(std::string nowyNumer)
{
	if (validate(nowyNumer,std::regex("^[0-9]+$")))
		numer = nowyNumer;
	else
		throw "Niepoprawny numer";
}

Sprzedawca::Sprzedawca(std::string imie, std::string naziwsko, std::string email, std::string numer){
	setImie(imie);
	setNazwisko(nazwisko);
	setEmail(email);
	setNumer(numer);
}

std::string Sprzedawca::toString() {
	std::string idString = id == -1 ? "[NIE USTAWIONO]" : std::to_string(id);
	std::string wynik = "Sprzedawca[ID: " + idString + ", Imię: " + imie + ", Nazwisko: " + nazwisko + ", Email: "+email+ ", Numer telefonu:"+ numer+"]";

	return wynik;
}

std::string Sprzedawca::serialize() {
	return std::to_string(id) + ';' + imie + ";" + nazwisko + ';' + email + ';' + numer;
}

Sprzedawca& Sprzedawca::deserialize(std::string input) {
	std::vector<std::string> parsed = Utils::tokenizeString(input, ';');

	Sprzedawca* sprzedawca = new Sprzedawca(parsed[1], parsed[2], parsed[3], parsed[4]);
	sprzedawca->setId(stol(parsed[0]));

	return *sprzedawca;
}

