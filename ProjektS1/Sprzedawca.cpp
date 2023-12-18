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
	if (noweImie.length() < 1)
		throw "Imiê sprzedawcy nie mo¿e byæ pustym napisem!";
	else
		imie = noweImie;
}

void Sprzedawca::setNazwisko(std::string noweNazwisko) {
	if (noweNazwisko.length() < 1)
		throw "Imiê sprzedawcy nie mo¿e byæ pustym napisem!";
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

