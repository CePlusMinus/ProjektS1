#include "includes/Zamowienie.h"
#include <iostream>

class Zamowienie
{
private:
    long id_mieszkania;
    long id_sprzedawcy;
    long id_klienta;
    StatusZamowienia status_zamowienia;

public:
    enum class StatusZamowienia
    {
        DOSTEPNE,
        W_TRAKCIE,
        ZAMOWIONE
    };

    Zamowienie(long id_mieszkania, long id_sprzedawcy, long id_klienta, StatusZamowienia status)
        : id_mieszkania(id_mieszkania), id_sprzedawcy(id_sprzedawcy), id_klienta(id_klienta), status_zamowienia(status) {}

    long getMieszkanie() const 
    {
        return id_mieszkania;
    }

    long getSprzedawca() const 
    {
        return id_sprzedawcy;
    }

    long getKlient() const 
    {
        return id_klienta;
    }

    StatusZamowienia getStatusZamowienia() const 
    {
        return status_zamowienia;
    }

    void setMieszkanie(long p_mieszkanie) 
    {
        id_mieszkania = p_mieszkanie;
    }

    void setSprzedawca(long p_sprzedawca) 
    {
        id_sprzedawcy = p_sprzedawca;
    }

    void setKlient(long p_klient) 
    {
        id_klienta = p_klient;
    }

    void setStatusZamowienia(StatusZamowienia status) 
    {
        status_zamowienia = status;
    }

    std::string toString() const 
    {
        std::string idString = id == -1 ? "[NIE USTAWIONO]" : std::to_string(id);
        std::string wynik = "Zamowienie[ID:" + idString + ",
            ID mieszkania: " + std::to_string(id_mieszkania) +
            ", ID sprzedawcy: " + std::to_string(id_sprzedawcy) +
            ", ID klienta: " + std::to_string(id_klienta) +
            ", Status zamowienia: ";

        switch (status_zamowienia) 
        {
        case StatusZamowienia::DOSTEPNE:
            wynik += "DOSTEPNE";
            break;
        case StatusZamowienia::W_TRAKCIE:
            wynik += "W_TRAKCIE";
            break;
        case StatusZamowienia::ZAMOWIONE:
            wynik += "ZAMOWIONE";
            break;
        }

        wynik += "]";
        return wynik;
    }
    std::string Zamowienie::serialize() const {
        std::string statusStr;
        switch (status_zamowienia) {
        case StatusZamowienia::DOSTEPNE:
            statusStr = "DOSTEPNE";
            break;
        case StatusZamowienia::W_TRAKCIE:
            statusStr = "W_TRAKCIE";
            break;
        case StatusZamowienia::ZAMOWIONE:
            statusStr = "ZAMOWIONE";
            break;
        }

        return std::to_string(id) + ";" + std::to_string(id_mieszkania) + ';' + std::to_string(id_sprzedawcy) + ';' + std::to_string(id_klienta) + ';' + statusStr;
    }

    Zamowienie& Zamowienie::deserialize(std::string input) 
    {
        std::vector<std::string> parsed = Utils::tokenizeString(input, ';');

        long id = stol(parsed[0]);
        long mieszkanieId = stol(parsed[1]);
        long sprzedawcaId = stol(parsed[2]);
        long klientId = stol(parsed[3]);
        StatusZamowienia status = StatusZamowienia::DOSTEPNE; 

        // Przetwarzanie statusu zamówienia
        if (parsed.size() > 3) {
            std::string statusStr = parsed[4];
            if (statusStr == "W_TRAKCIE") {
                status = StatusZamowienia::W_TRAKCIE;
            }
            else if (statusStr == "ZAMOWIONE") {
                status = StatusZamowienia::ZAMOWIONE;
            }
        }

        Zamowienie* zamowienie = new Zamowienie(mieszkanieId, sprzedawcaId, klientId, status);
        zamowienie->setId(id);

        return *zamowienie;
    }
};