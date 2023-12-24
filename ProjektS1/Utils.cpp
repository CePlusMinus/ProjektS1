#include "includes/Utils.h"

std::vector<std::string> Utils::tokenizeString(std::string input, char delim) {
    std::vector<std::string> tokens;
    std::string temp = "";
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == delim) {
            tokens.push_back(temp);
            temp = "";
        }
        else
            temp += input[i];
    }
    tokens.push_back(temp);
    return tokens;
}
