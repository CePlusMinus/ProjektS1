#pragma once
#include <map>
#include "KlasaBazowa.h"
#include <fstream>
template <typename T>
class BazaDanych
{
std::map<long, T&> baza;

public:
	BazaDanych() {
		if (!std::is_base_of<KlasaBazowa, T>::value)
			throw "Nie można utworzyć bazy danych z klasy, która nie implementuje \"KlasaBazowa\"!";
	}


	T& getById(long id) {
		auto iter = baza.find(id);
		if (iter != baza.end())
			return iter -> second;
		else
			throw "Nie znaleziono obiektu w bazie!";
	}

	void save(T& entity) {
		if (entity.getId() == -1) {
			if (baza.empty())
				entity.setId(1);
			else
				entity.setId(baza.rbegin()->first);
		}

		baza.insert({ entity.getId(), entity });
	}

	void remove(T& entity) {
		baza.erase(entity.getId());
	}

	~BazaDanych() {
		std::string path = typeid(T).name();
		path += ".txt";

		std::ofstream output(path);

		for (auto it = baza.begin(); it != baza.end(); ++it) {
			output << it->second.toString();
		}

		output.close();
	}
};

