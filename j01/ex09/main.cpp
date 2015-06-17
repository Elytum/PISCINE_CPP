#include "Logger.hpp"

std::string		file_to_string(std::string path) {
	std::ifstream	ifs(path);
	std::string		content;

	content.assign( (std::istreambuf_iterator<char>(ifs) ),
	                (std::istreambuf_iterator<char>()    ) );
	ifs.close();
	return (content);
}

bool			valid_file(std::string filePath) {
	std::ofstream	file;

	file.open(filePath, std::ios_base::app);
	if (!file.good()) {
		file.close();
		std::cout << "Invalid filePath: " << strerror(errno) << std::endl;
		return false;
	} else
		return true;
}

int		main(void)
{
	std::string	kind;
	std::string	tmp;
	std::string	input;
	std::string	filePath;

	std::cout << "Please define the filePath: ";
	std::getline (std::cin, filePath);

	if (!valid_file(filePath))
		return (1);

	Logger		logger(filePath);

	std::cout << "Please enter the log kind: ";
	while (true)
	{

		std::getline (std::cin, input);
		if (std::cin.eof()) {
			std::cout << "EOF reached" << std::endl;
			break;
		} else if (std::cin.bad()) {
			std::cout << "Error with input" << std::endl;
			break;
		}
		if (kind.empty()) {
			kind = input;
			std::cout << "Please enter the log message: ";
		} else {
			logger.log(kind, input);
			kind.clear();
			std::cout << "Please enter the log kind: ";
		}
	}
	std::cout << "File content:" << std::endl << file_to_string(filePath);
	return (0);
}