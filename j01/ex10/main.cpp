#include <iostream>
#include <fstream>

std::string		file_to_string(std::string const & path, std::string const & programName)
{
	std::ifstream	ifs(path);
	std::string		content;

	if (!ifs.good()) {
		ifs.close();
		std::cout << programName << ": " << path << ": " << strerror(errno) << std::endl;
		return ("");
	}
	content.assign( (std::istreambuf_iterator<char>(ifs) ),
					(std::istreambuf_iterator<char>()    ) );
	ifs.close();
	return (content);
}

void			cat_entry(void)
{
	std::string		input;
	while (true)
	{
		std::getline (std::cin, input);
		if (std::cin.eof()) {
			break;
		} else if (std::cin.bad()) {
			std::cout << "Error with input" << std::endl;
			break;
		} else
			std::cout << input << std::endl;
	}
}

int		main(int ac, char **av)
{
	if (ac > 2)
		std::cout << "Wrong usage, should be : " << av[0] << "(filePath)";
	else if (ac == 1)
		cat_entry();
	else
		std::cout << file_to_string(av[1], av[0]);
}
