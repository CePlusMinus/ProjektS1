#pragma once
#include "Klasa_Bazowa.h"

class Zamowienia : public Klasa_Bazowa
{
private:
    std::string id_mieszkania;
    std::string id_sprzedawcy;
    std::string id_klienta;
    std::string zamowione;

public:
    Zamowienia(std::string id_mieszkania, std::string id_sprzedawcy, std::string id_klienta, std::string zamowione);

    std::string getMieszkanie() const;
    std::string getSprzedawca() const;
    std::string getKlient() const; 
    std::string getZamowione() const;
    void setMieszkanie(std::string p_mieszkanie);
    void setSprzedawca(std::string p_sprzedawca);
    void setKlient(std::string p_klient); 
    void setZamowione(std::string p_zamowione);

    std::string toString() const; 
};