#include "includes/KlasaBazowa.h"

long KlasaBazowa::getId() const{
	return id;
}

void KlasaBazowa::setId(int noweId) {
	if (noweId < 1)
		throw "Id obiektu nie może być mniejsze od 1!";
	else
		id = noweId;
}