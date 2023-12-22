#include "includes/Zamowienie.h"

Zamowienie::Zamowienie(std::string id_mieszkania, std::string id_sprzedawcy, std::string id_klienta, std::string zamowione)
{
    setMieszkanie(id_mieszkania);
    setSprzedawca(id_sprzedawcy);
    setKlient(id_klienta);
    setZamowione(zamowione);
}

std::string Zamowienie::getMieszkanie() const
{
    return id_mieszkania;
}

std::string Zamowienie::getSprzedawca() const
{
    return id_sprzedawcy;
}

std::string Zamowienie::getKlient() const
{
    return id_klienta;
}

std::string Zamowienie::getZamowione() const
{
    return zamowione;
}

void Zamowienie::setMieszkanie(std::string p_mieszkanie)
{
    // Tu mo¿e byæ dodatkowa walidacja, jeœli jest potrzebna
    id_mieszkania = p_mieszkanie;
}

void Zamowienie::setSprzedawca(std::string p_sprzedawca)
{
    // Tu mo¿e byæ dodatkowa walidacja, jeœli jest potrzebna
    id_sprzedawcy = p_sprzedawca;
}

void Zamowienie::setKlient(std::string p_klient)
{
    // Tu mo¿e byæ dodatkowa walidacja, jeœli jest potrzebna
    id_klienta = p_klient;
}

void Zamowienie::setZamowione(std::string p_zamowione)
{
    // Tu mo¿e byæ dodatkowa walidacja, jeœli jest potrzebna
    zamowione = p_zamowione;
}

std::string Zamowienie::toString() const
{
    std::string idString = id == -1 ? "[NIE USTAWIONO]" : std::to_string(id);
    std::string wynik = "Zamowienie[ID: " + idString + ", ID mieszkania" + id_mieszkania + ", ID sprzedawcy" + id_sprzedawcy + ", ID klienta" + id_klienta + ", Zamówiony" + zamowione + "]";
    return wynik;
}