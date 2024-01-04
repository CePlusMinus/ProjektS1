#include "includes/Logger.h"

std::string Logger::raport = "";

void Logger::log(const std::string& powiadomienie)
{
	raport += powiadomienie + "\n";
}

void Logger::flush() {
	std::ofstream plik("log.txt");
	plik << raport;
	plik.close();
}