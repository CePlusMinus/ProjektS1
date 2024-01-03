#pragma once
#include "KlasaBazowa.h"

class Zamowienie : public KlasaBazowa
{
public:
enum class StatusZamowienia
{
    DOSTEPNE,
    W_TRAKCIE,
    ZAMOWIONE
};
private:
    std::string id_mieszkania;
    std::string id_sprzedawcy;
    std::string id_klienta;
    StatusZamowienia status_zamowienia;

public:
    Zamowienie(std::string id_mieszkania, std::string id_sprzedawcy, std::string id_klienta, StatusZamowienia status_zamowienia);

    std::string getMieszkanie() const;
    std::string getSprzedawca() const;
    std::string getKlient() const; 
    std::string getStatusZamowienia() const;
    void setMieszkanie(std::string p_mieszkanie);
    void setSprzedawca(std::string p_sprzedawca);
    void setKlient(std::string p_klient); 
    void setStatusZamowienia(StatusZamowienia status);

    std::string toString() const; 

    std::string serialize() override;
    static Zamowienie& deserialize(std::string input);
};