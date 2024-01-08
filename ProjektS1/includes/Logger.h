#pragma once
#include <string>

class Logger {
private:
	static std::string raport;

public:
	static void log(const std::string& powiadomienie);
	static void flush();
};

