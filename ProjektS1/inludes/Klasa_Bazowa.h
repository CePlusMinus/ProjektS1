#pragma once //nie wiem co to robi, ale Visual to dodaje z automatu wiêc niech zostanie
#include <string>
class KlasaBazowa
{
protected:
	//Domyœlnie id jest ustawione na -1, aby program wiedzia³, ¿e obiekt nie ma jeszcze przyznanego unikatowego id
	long id = -1;
public:
	//Metody które maj¹ nie zmieniaæ wartoœci zmiennych, mo¿na oznaczyæ jako "const" (wtedy kompilator nie pozwoli im zmieniaæ wartoœci zmiennych)
	long getId() const;
	void setId(int noweId);

	//Metoda abstrakcyjna (wirtualna), klasy które dziedzicz¹ po "KlasaBazowa" musz¹ j¹ zaimplementowaæ, a ona sama domyœlnie nie ma implementacji
	virtual std::string toString() = 0;
};