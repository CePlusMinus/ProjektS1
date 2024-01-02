#pragma once
#include "KlasaBazowa.h"
class Mieszkanie : public KlasaBazowa
{
private:
	std::string ulica;
	std::string numer_mieszkania;
	bool czy_wyposazenie;
	double wielkosc_mieszkania;
	double cena_mieszkania;
	long wlasciciel;
public:
	Mieszkanie(std::string ulica, std::string numer_mieszkania, bool czy_wyposazenie, double wielkosc_mieszkania, double cena_mieszkania, long wlasciciel);

	std::string getUlica() const;
	std::string getNumerMieszkania() const;
	bool getCzyWyposazenie() const;
	double getWielkoscMieszkania() const;
	double getCenaMieszkania() const;
	long getWlasciciel() const;
	void setUlica(std::string p_ulica);
	void setNumerMieszkania(std::string p_numermieszkania);
	void setCzyWyposazenie(bool p_czywyposazenie);
	void setWielkoscMieszkania(double p_wielkoscmieszkania);
	void setCenaMieszkania(double p_cenamieszkania);
	void setWlasciciel(long p_wlasciciel);

	std::string toString() override;
	std::string serialize() override;

	static Mieszkanie& deserialize(std::string input);
};


