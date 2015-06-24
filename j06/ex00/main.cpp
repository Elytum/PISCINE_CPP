#include <iostream>
#include <iomanip>
#include <sstream>


void	charConversion(char *str) {
	int				value;

	std::istringstream	ss(str);
	ss >> value;
	if (ss.fail() || !ss.eof() || value > CHAR_MAX || value < CHAR_MIN)
		std::cout << "char: impossible" << std::endl;
	else {
		if (isprint(value))
			std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
		else
			std::cout << "char: Not displayable" << std::endl;
	}
}

void	intConversion(char *str) {
	int				value;

	std::istringstream	ss(str);
	ss >> value;
	if (ss.fail() || !ss.eof())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << value << std::endl;

}

void	floatConversion(char *str) {
	float				value;

	std::istringstream	ss(str);
	ss >> value;
	if (ss.fail() || !ss.eof())
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) << value << "f" << std::endl;

}

void	doubleConversion(char *str) {
	double				value;

	std::istringstream	ss(str);
	ss >> value;
	if (ss.fail() || !ss.eof())
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;

}

int		main(int ac, char **av)
{
	if (ac != 2) {
		std::cout << av[0] << ": Wrong usage, should be: \"" << av[0] << " <string>\"" << std::endl;
		return (1);
	}
	charConversion(av[1]);
	intConversion(av[1]);
	floatConversion(av[1]);
	doubleConversion(av[1]);
	return (0);
}