#pragma once
#include <map>
#include "KlasaBazowa.h"
#include <fstream>
#include <vector>
template <typename T>
class BazaDanych
{
std::map<long, T&> baza;

public:
	BazaDanych() {
		if (!std::is_base_of<KlasaBazowa, T>::value)
			throw "Nie można utworzyć bazy danych z klasy, która nie implementuje \"KlasaBazowa\"!";

		std::string path = typeid(T).name();
		path += ".txt";
		std::ifstream input(path);

		std::string in;
		while (!input.eof()) {
			getline(input, in);

			if (in.empty())
				break;

			save(T::deserialize(in));
		}

		input.close();
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
				entity.setId(baza.rbegin()->first + 1);
		}

		baza.insert({ entity.getId(), entity });
	}

	void remove(T& entity) {
		baza.erase(entity.getId());
	}

	std::vector<T> getCurrentAllByValue() {
		std::vector<T> result;

		for (auto it : baza) {
			result.push_back(it.second);
		}

		return result;
	}

	~BazaDanych() {
		std::string path = typeid(T).name();
		path += ".txt";

		std::ofstream output(path);

		for (auto it : baza) {
			output << it.second.serialize() << std::endl;
		}

		output.close();
	}
};

