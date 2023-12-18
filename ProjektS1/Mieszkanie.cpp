#include "inludes/Mieszkanie.h"

std::string Mieszkanie::getUlica() const
{
	return ulica;
}

std::string Mieszkanie::getNumerMieszkania() const
{
	return nr_mieszkania;
}

std::string Mieszkanie::getCzyWyposazenie() const
{
	return wyposazenie;
}

std::string Mieszkanie::getWielkoscMieszkania() const
{
	return wiel_mieszkania;
}

std::string Mieszkanie::getCenaMieszkania() const
{
	return cena_mieszkania;
}

std::string Mieszkanie::getWlasciciel() const
{
	return wlasciciel;
}

void Mieszkanie::setUlica(std::string p_ulica) 
{
	if (p_ulica.length() < 1)
		throw "Mieszaknie musi byc umieszczone na ulicy";
	else
		ulica = p_ulica;
}

void Mieszkanie::setNumerMieszkania(std::string p_numermieszkania) 
{
	if (p_numermieszkania.length() < 1)
		throw "Mieszkanie musi posiadaæ numer mieszkania";
	else
		nr_mieszkania = p_numermieszkania;
}

void Mieszkanie::setCzyWyposazenie(std::string p_czywyposazenie)
{
	if (p_czywyposazenie.length() < 1)
		throw "Wyposazenie mieszkania musi byæ oznaczone";
	else
		wyposazenie = p_czywyposazenie;
}

void Mieszkanie::setWielkoscMieszkania(std::string p_wielkoscmieszkania)
{
	if (p_wielkoscmieszkania.length() < 1)
		throw "Mieszkanie musi miec okreslona wielkosc";
	else
		wiel_mieszkania = p_wielkoscmieszkania;
}

void Mieszkanie::setCenaMieszkania(std::string p_cenamieszkania)
{
	if (p_cenamieszkania.length() < 1)
		throw "Mieszkanie musi miec swoja cene";
	else
		cena_mieszkania = p_cenamieszkania;
}

void Mieszkanie::setWlasciciel(std::string p_wlasciciel)
{
	if (p_wlasciciel.length() < 1)
		throw "Mieszkanie musi miec swojego wlasciciela";
	else
		wlasciciel = p_wlasciciel;
}



Mieszkania::Mieszkania(std::string ulica, std::string numer_mieszkania, std::string czy_wyposazenie, std::string wielkosc_mieszkania, std::string cena_mieszkania, std::string wlasciciel) 
{
	setUlica(ulica);
	setNumerMieszkania(numer_mieszkania);
	setCzyWyposazenie(czy_wyposazenie);
	setWielkoscMieszkania(wielkosc_mieszkania);
	setCenaMieszkania(cena_mieszkania);
	setWlasciciel(wlasciciel);
}

//Implementacja metody abstrakcyjnej "toString" z "KlasaBazowa"
std::string Mieszkania::toString() {
	std::string idString = id == -1 ? "[NIE USTAWIONO]" : std::to_string(id);
	std::string wynik = "Mieszkania[ID: " + idString + ", Ulica: " + ulica + ", Numer mieszkania: " + numer_mieszknia + ", Czy wyposazone" + czy_wyposazone + ", Wielkosc mieszkania" + wielkosc_mieszkania + ", Cena mieszkania" + cena_mieszkania + "Wlsciciel mieszkania" +  wlasciciel+ "]";

	return wynik;
}