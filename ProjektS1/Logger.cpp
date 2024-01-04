#include "Logger.h"

Logger::log(const std::string& powiadomienie)
{
	raport += powiadomienie + "\n";
}

Logger::~Logger() {
	std::ofstream plik("log.txt");
	plik << raport;
	plik.close();
}