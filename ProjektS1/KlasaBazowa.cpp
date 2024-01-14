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

bool KlasaBazowa::validate(std::string input, std::regex pattern) {
	return std::regex_match(input, pattern);
}

int KlasaBazowa::znakPol(const std::string& dana)
{
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    std::wstring wideStr = converter.from_bytes(dana);

    // Define a set of Polish characters
    std::wstring polishCharacters = L"ąćęłńóśźżĄĆĘŁŃÓŚŹŻ";

    // Count occurrences of Polish characters
    int count = 0;
    for (wchar_t ch : wideStr) {
        if (polishCharacters.find(ch) != std::wstring::npos) {
            count++;
        }
    }

    return count;
}
