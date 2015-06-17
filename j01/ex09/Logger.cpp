#include "Logger.hpp"
#include <iostream>
#include <sstream>
#include <fstream>

#define ARRAY_LEN(array) (sizeof(array) / sizeof(*array))

typedef  void (Logger::*LoggerActions) (std::string const & message);

std::string		Logger::getTimestamp( void ) const {
	time_t		now = time(0);
	struct tm	tstruct;
	char		buf[80];

	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S]", &tstruct);
	return (buf);
}

void			Logger::append_to_file(std::string const & path, std::string const & string) const {
	std::ofstream	file;

	if (this->goodOpen) {
		file.open(path, std::ios_base::app);
		file << string;
		file.close();
	}
}

Logger::Logger( std::string const filePath ) : filePath(filePath) {
	std::ofstream	file;

	file.open(filePath, std::ios_base::app);
	if (!file.good()) {
		file.close();
		std::cout << strerror(errno) << std::endl;
		goodOpen = false;
	} else
		goodOpen = true;
}

Logger::~Logger() {
}

void			Logger::logToConsole(std::string const & message) {
	std::cout << message;
}

void			Logger::logToFile(std::string const & message) {
	append_to_file(filePath, message);
}

std::string		Logger::makeLogEntry( std::string const & origin ) const {
	static size_t		id = 0;
	std::stringstream	ss;

	ss << id++;
	std::string	str = "Log " + ss.str() + ": " + Logger::getTimestamp() + " -> \"" + origin + "\"\n";
	return (str);
}

void 			Logger::log( std::string const & dest, std::string const & message )
{
	const LoggerActions 	actions[] = { &Logger::logToConsole, &Logger::logToFile };
	const std::string		names[] = {"console", "file"};

	size_t					i = std::find(names, names + ARRAY_LEN(names), dest) - names;

	if (i != ARRAY_LEN(names))
		(this->*(actions[i]))(makeLogEntry(message));
}
