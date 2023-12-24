#pragma once
#include <string>
#include "KlasaBazowa.h"
class Sprzedawca : public KlasaBazowa
{
private:
	std::string imie;
	std::string nazwisko;
	std::string email;
	std::string numer;
public:
	Sprzedawca(std::string imie, std::string naziwsko, std::string email, std::string numer);

	std::string getImie() const;
	std::string getNazwisko()const;
	std::string getEmail()const;
	std::string getNumer()const;

	void setImie(std::string noweImie);
	void setNazwisko(std::string noweNazwisko);
	void setEmail(std::string nowyEmail);
	void setNumer(std::string nowyNumer);

	std::string toString() override;
	std::string serialize() override;

	static Sprzedawca& deserialize(std::string input);
};
