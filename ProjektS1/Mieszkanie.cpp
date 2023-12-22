#include "includes/Mieszkanie.h"

std::string Mieszkanie::getUlica() const
{
    return ulica;
}

std::string Mieszkanie::getNumerMieszkania() const
{
	return numer_mieszkania;
}

bool Mieszkanie::getCzyWyposazenie() const
{
	return czy_wyposazenie;
}

double Mieszkanie::getWielkoscMieszkania() const
{
	return wielkosc_mieszkania;
}

double Mieszkanie::getCenaMieszkania() const
{
    return cena_mieszkania;
}

long Mieszkanie::getWlasciciel() const
{
    return wlasciciel;
}

void Mieszkanie::setUlica(std::string p_ulica)
{
    if (p_ulica.length() < 1)
        throw "Mieszkanie musi byc umieszczone na ulicy";
    else
        ulica = p_ulica;
}

void Mieszkanie::setNumerMieszkania(std::string p_numermieszkania)
{
	if (p_numermieszkania.length() < 1)
		throw "Mieszkanie musi posiadaæ numer mieszkania";
	else
		numer_mieszkania = p_numermieszkania;
}

void Mieszkanie::setCzyWyposazenie(bool p_czywyposazenie)
{
    czy_wyposazenie = p_czywyposazenie;
}

void Mieszkanie::setWielkoscMieszkania(double p_wielkoscmieszkania)
{
    if (p_wielkoscmieszkania <= 0)
        throw "Mieszkanie musi mieæ okreœlon¹ wielkoœæ";
    else
        wielkosc_mieszkania = p_wielkoscmieszkania;
}

void Mieszkanie::setCenaMieszkania(double p_cenamieszkania)
{
    if (p_cenamieszkania <= 0)
        throw "Mieszkanie musi mieæ swoj¹ cenê";
    else
        cena_mieszkania = p_cenamieszkania;
}

void Mieszkanie::setWlasciciel(long p_wlasciciel)
{
    if (p_wlasciciel <= 0)
        throw "Mieszkanie musi mieæ swojego w³aœciciela";
    else
        wlasciciel = p_wlasciciel;
}

Mieszkanie::Mieszkanie(std::string ulica, std::string numer_mieszkania, bool czy_wyposazenie, double wielkosc_mieszkania, double cena_mieszkania, long wlasciciel)
{
    setUlica(ulica);
    setNumerMieszkania(numer_mieszkania);
    setCzyWyposazenie(czy_wyposazenie);
    setWielkoscMieszkania(wielkosc_mieszkania);
    setCenaMieszkania(cena_mieszkania);
    setWlasciciel(wlasciciel);
}

std::string Mieszkanie::toString()
{
    std::string idString = id == -1 ? "[NIE USTAWIONO]" : std::to_string(id);
    std::string wynik = "Mieszkanie[ID: " + idString + ", Ulica: " + ulica + ", Numer mieszkania: " + numer_mieszkania + ", Czy wyposa¿one: " + (czy_wyposazenie ? "TAK" : "NIE") + ", Wielkoœæ mieszkania: " + std::to_string(wielkosc_mieszkania) + ", Cena mieszkania: " + std::to_string(cena_mieszkania) + " W³aœciciel mieszkania: " + std::to_string(wlasciciel) + "]";

    return wynik;
}