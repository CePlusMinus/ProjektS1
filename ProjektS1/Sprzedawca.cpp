#include <iostream>
#include "includes/Sprzedawca.h"
#include <regex>

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
	if (validate(noweImie, std::regex("^[A - Z][a - z] + $")))
		imie = noweImie;
	else
		throw "Niepoprawne imiê sprzedawcy";
}

void Sprzedawca::setNazwisko(std::string noweNazwisko) {
	if (validate(noweNazwisko, std::regex("^[A - Z][a - z] + $")))
		imie = noweNazwisko;
	else
		throw "Niepoprawne imiê sprzedawcy";
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
	std::string wynik = "Sprzedawca[ID: " + idString + ", Imiê: " + imie + ", Nazwisko: " + nazwisko + ", Email: "+email+ ", Numer telefonu:"+ numer+"]";

	return wynik;
}

