#pragma once //nie wiem co to robi, ale Visual to dodaje z automatu wi�c niech zostanie
#include <string>
class KlasaBazowa
{
protected:
	//Domy�lnie id jest ustawione na -1, aby program wiedzia�, �e obiekt nie ma jeszcze przyznanego unikatowego id
	long id = -1;
public:
	//Metody kt�re maj� nie zmienia� warto�ci zmiennych, mo�na oznaczy� jako "const" (wtedy kompilator nie pozwoli im zmienia� warto�ci zmiennych)
	long getId() const;
	void setId(int noweId);

	//Metoda abstrakcyjna (wirtualna), klasy kt�re dziedzicz� po "KlasaBazowa" musz� j� zaimplementowa�, a ona sama domy�lnie nie ma implementacji
	virtual std::string toString() = 0;
};