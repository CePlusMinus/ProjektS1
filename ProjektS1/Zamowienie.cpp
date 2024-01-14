#include "includes/Zamowienie.h"
#include "includes/Utils.h"

    Zamowienie::Zamowienie(long id_mieszkania, long id_sprzedawcy, long id_klienta, StatusZamowienia status)
        : id_mieszkania(id_mieszkania), id_sprzedawcy(id_sprzedawcy), id_klienta(id_klienta), status_zamowienia(status) {}

    long Zamowienie::getMieszkanie() const 
    {
        return id_mieszkania;
    }

    long Zamowienie::getSprzedawca() const
    {
        return id_sprzedawcy;
    }

    long Zamowienie::getKlient() const
    {
        return id_klienta;
    }

    Zamowienie::StatusZamowienia Zamowienie::getStatusZamowienia() const
    {
        return status_zamowienia;
    }

    void Zamowienie::setMieszkanie(long p_mieszkanie)
    {
        id_mieszkania = p_mieszkanie;
    }

    void Zamowienie::setSprzedawca(long p_sprzedawca)
    {
        id_sprzedawcy = p_sprzedawca;
    }

    void Zamowienie::setKlient(long p_klient)
    {
        id_klienta = p_klient;
    }

    void Zamowienie::setStatusZamowienia(Zamowienie::StatusZamowienia status)
    {
        status_zamowienia = status;
    }

    std::string Zamowienie::toString()
    {
        std::string idString = id == -1 ? "[NIE USTAWIONO]" : std::to_string(id);
        std::string wynik;

        switch (status_zamowienia) 
        {
        case StatusZamowienia::W_TRAKCIE:
            wynik = "W TRAKCIE";
            break;
        case StatusZamowienia::ZAMOWIONE:
            wynik = "ZAMOWIONE";
            break;
        }
        std::ostringstream ss;
        ss << std::left << std::setw(3) << idString;
        ss << std::left << std::setw(15) << id_mieszkania;
        ss << std::left << std::setw(15) << id_sprzedawcy;
        ss << std::left << std::setw(15) << id_klienta;
        ss << std::left << std::setw(10) << wynik;
        ss << std::endl;
        return ss.str();
    }
    std::string Zamowienie::serialize() {
        std::string statusStr;
        switch (status_zamowienia) {
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
        StatusZamowienia status;

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