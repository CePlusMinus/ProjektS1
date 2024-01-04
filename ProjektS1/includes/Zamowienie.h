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
    long id_mieszkania;
    long id_sprzedawcy;
    long id_klienta;
    StatusZamowienia status_zamowienia;

public:
    Zamowienie(long id_mieszkania, long id_sprzedawcy, long id_klienta, StatusZamowienia status_zamowienia);

    long getMieszkanie() const;
    long getSprzedawca() const;
    long getKlient() const; 
    StatusZamowienia getStatusZamowienia() const;
    void setMieszkanie(long p_mieszkanie);
    void setSprzedawca(long p_sprzedawca);
    void setKlient(long p_klient); 
    void setStatusZamowienia(StatusZamowienia status);

    std::string toString(); 

    std::string serialize() override;
    static Zamowienie& deserialize(std::string input);
};