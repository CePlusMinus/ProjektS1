#include "includes/Mieszkanie.h"
#include "includes/Utils.h"
#include <regex>

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
		throw "Mieszkanie musi posiadać numer mieszkania";
	else
		numer_mieszkania = p_numermieszkania;
}

void Mieszkanie::setCzyWyposazenie(bool p_czywyposazenie)
{
    czy_wyposazenie = p_czywyposazenie;
}

void Mieszkanie::setWielkoscMieszkania(double p_wielkoscmieszkania)
{
    try
    {
        wielkosc_mieszkania = p_wielkoscmieszkania;
    }
    catch (const std::invalid_argument&)
    {
        throw "Nieprawidłowy zapis wielkości";
    }
}

void Mieszkanie::setCenaMieszkania(double p_cenamieszkania) {
    try
    {
        cena_mieszkania = p_cenamieszkania;
    }
    catch (const std::invalid_argument&)
    {
        throw "Nieprawidłowy zapis ceny\n";
    }
}

void Mieszkanie::setWlasciciel(long p_wlasciciel)
{
    if (p_wlasciciel <= 0)
        throw "Mieszkanie musi mieć swojego właściciela";
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
    //std::string wynik = "Mieszkanie[ID: " + idString + ", Ulica: " + ulica + ", Numer mieszkania: " + numer_mieszkania + ", Czy wyposażone: " + (czy_wyposazenie ? "TAK" : "NIE") + ", Wielkość mieszkania: " + std::to_string(wielkosc_mieszkania) + ", Cena mieszkania: " + std::to_string(cena_mieszkania) + " Właściciel mieszkania: " + std::to_string(wlasciciel) + "]";
    std::ostringstream ss;
    int dl_ul = 20 + znakPol(ulica);
    ss << std::left << std::setw(3) << idString;
    ss << std::left << std::setw(dl_ul) << ulica;
    ss << std::left << std::setw(17) << numer_mieszkania;
    ss << std::left << std::setw(11) << (czy_wyposazenie ? "TAK" : "NIE");
    ss << std::left << std::setw(10) << wielkosc_mieszkania;
    ss << std::left << std::setw(10) << cena_mieszkania;
    ss << std::left << std::setw(3) << wlasciciel;
    ss << std::endl;
    return ss.str();

}

std::string Mieszkanie::serialize() {
    return std::to_string(id) + ';' + ulica + ";" + numer_mieszkania + ';' + (czy_wyposazenie ? '1' : '0') + ';' + std::to_string(wielkosc_mieszkania) + ';' + std::to_string(cena_mieszkania) + ';' + std::to_string(wlasciciel);
}

Mieszkanie& Mieszkanie::deserialize(std::string input) {
    std::vector<std::string> parsed = Utils::tokenizeString(input, ';');

    Mieszkanie* mieszkanie = new Mieszkanie(parsed[1], parsed[2], stoi(parsed[3]) - 0, stod(parsed[4]), stod(parsed[5]), stol(parsed[6]));
    mieszkanie->setId(stol(parsed[0]));

    return *mieszkanie;
}