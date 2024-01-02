#pragma once
#include "KlasaBazowa.h"
class Klient : public KlasaBazowa
{
private:
	std::string imie;
	std::string nazwisko;
public:
	Klient(std::string imie, std::string nazwisko);

	std::string getImie() const;
	std::string getNazwisko() const;
	void setImie(std::string noweImie);
	void setNazwisko(std::string noweNazwisko);

	std::string toString() override;
	std::string serialize() override;

	static Klient& deserialize(std::string input);
};

