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
	if (noweImie.length() < 1)
		throw "Imię sprzedawcy nie może być pustym napisem!";
	else
		imie = noweImie;
}

void Sprzedawca::setNazwisko(std::string noweNazwisko) {
	if (noweNazwisko.length() < 1)
		throw "Imię sprzedawcy nie może być pustym napisem!";
	else
		nazwisko = noweNazwisko;
}

void Sprzedawca::setEmail(std::string nowyEmail)
{
	std::regex wzorEmail("^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\\.[a-zA-Z0-9-.]+$");
	if (std::regex_match(nowyEmail, wzorEmail))
	{
		email = nowyEmail;
	}
	else
	{
		std::cout << "Niepoprawny email";
	}
		
}

void Sprzedawca::setNumer(std::string nowyNumer)
{
	if (nowyNumer.length() < 1)
		throw "Numer nie moze byc pustym napisem!";
	else
		numer = nowyNumer;
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

