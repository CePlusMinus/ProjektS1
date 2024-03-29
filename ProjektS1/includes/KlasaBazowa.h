﻿#pragma once
#include <string>
#include <regex>
#include <codecvt>
#include <locale>

class KlasaBazowa
{
protected:
	//Domyślnie id jest ustawione na -1, aby program wiedział, że obiekt nie ma jeszcze przyznanego unikatowego id
	long id = -1;
public:
	//Metody które mają nie zmieniać wartości zmiennych, można oznaczyć jako "const" (wtedy kompilator nie pozwoli im zmieniać wartości zmiennych)
	long getId() const;
	void setId(int noweId);

	//dalam to do sprawdzania poprawnosci zmiennych zeby nie trzeba bylo powtarzac w każdej klasie
	bool validate(std::string input, std::regex pattern);

	int znakPol(const std::string& dana);

	//Metoda abstrakcyjna (wirtualna), klasy które dziedziczą po "KlasaBazowa" muszą ją zaimplementować, a ona sama domyślnie nie ma implementacji
	virtual std::string toString()  = 0;

	//Metoda do zamiany klasy na format, który damy radę odczytać z pliku
	virtual std::string serialize() = 0;
};