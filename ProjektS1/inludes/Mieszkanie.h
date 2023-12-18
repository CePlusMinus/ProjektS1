#pragma once
#include "Klasa_Bazowa.h"
class Mieszkania : public Klasa_Bazowa
{
private:
	std::string ulica;
	std::string numer_mieszkania;
	std::string czy_wyposazenie;
	std::string wielkosc_mieszkania;
	std::string cena_mieszkania;
	std::string wlasciciel;
public:
	Mieszkania(std::string ulica, std::string numer_mieszkania, std::string czy_wyposazenie, std::string wielkosc_mieszkania,std::string cena_mieszkania,std::string wlasciciel);

	std::string getUlica() const;
	std::string getNumerMieszkania() const;
	std::string getCzyWyposazenie() const;
	std::string getWielkoscMieszkania() const;
	std::string getCenaMieszkania() const;
	void setUlica(std::string p_ulica);
	void setNumerMieszkania(std::string p_numermieszkania);
	void setCzyWyposazenie(std::string p_czywyposazenie);
	void setWielkoscMieszkania(std::string p_wielkoscmieszkania);
	void setCenaMieszkania(std::string p_cenamieszkania);
	void setWlasciciel(std::string p_wlasciciel);

	std::string toString();
};


