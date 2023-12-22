#pragma once //nie wiem co to robi, ale Visual to dodaje z automatu więc niech zostanie
#include <string>
class KlasaBazowa
{
protected:
	//Domyślnie id jest ustawione na -1, aby program wiedział, że obiekt nie ma jeszcze przyznanego unikatowego id
	long id = -1;
public:
	//Metody które mają nie zmieniać wartości zmiennych, można oznaczyć jako "const" (wtedy kompilator nie pozwoli im zmieniać wartości zmiennych)
	long getId() const;
	void setId(int noweId);

	//Metoda abstrakcyjna (wirtualna), klasy które dziedziczą po "KlasaBazowa" muszą ją zaimplementować, a ona sama domyślnie nie ma implementacji
	virtual std::string toString() = 0;
};