#pragma once //nie wiem co to robi, ale Visual to dodaje z automatu wi�c niech zostanie
#include <string>
#include <regex>
class KlasaBazowa
{
protected:
	//Domy�lnie id jest ustawione na -1, aby program wiedzia�, �e obiekt nie ma jeszcze przyznanego unikatowego id
	long id = -1;
public:
	//Metody kt�re maj� nie zmienia� warto�ci zmiennych, mo�na oznaczy� jako "const" (wtedy kompilator nie pozwoli im zmienia� warto�ci zmiennych)
	long getId() const;
	void setId(int noweId);

	//dalam to do sprawdzania poprawnosci zmiennych zeby nie trzeba bylo powtarzac w kazdej klasie
	bool validate(std::string input, std::regex pattern);

	//Metoda abstrakcyjna (wirtualna), klasy kt�re dziedzicz� po "KlasaBazowa" musz� j� zaimplementowa�, a ona sama domy�lnie nie ma implementacji
	virtual std::string toString() = 0;
};