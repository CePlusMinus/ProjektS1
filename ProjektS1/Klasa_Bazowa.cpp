#include "includes/KlasaBazowa.h"

long KlasaBazowa::getId() const {
	return id;
}

void KlasaBazowa::setId(int noweId) {
	if (noweId < 1)
		throw "Id obiektu nie mo�e by� mniejsze od 1!";
	else
		id = noweId;
}