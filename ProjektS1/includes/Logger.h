#pragma once
#include <string>
#include <fstream>

class Logger {
private:
	static std::string raport;

public:
	static void log(const std::string& powiadomienie);
	~Logger();
};
