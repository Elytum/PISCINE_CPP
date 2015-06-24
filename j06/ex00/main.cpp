#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <math.h>

#define DEBUG true

enum	type
{
	CHAR = 0,
	INT = 1,
	FLOAT = 2,
	DOUBLE = 3,
	ERROR = 4
};

bool	isInt(std::string str) {
	int				value;

	std::istringstream	ss(str);
	ss >> value;
	return (!(ss.fail() || !ss.eof()));
}

bool	isFloat(std::string str) {
	float			value;

	std::istringstream	ss(str);
	ss >> value;
	return (!(ss.fail() || !ss.eof()));
}

bool	isDouble(std::string str) {
	double			value;

	std::istringstream	ss(str);
	ss >> value;
	return (!(ss.fail() || !ss.eof()));
}

type	getType(std::string & str) {
	if (str == "inff" || str == "+inff" || str == "-inff" ||
		str == "nanf" || (str.back() == 'f' && isdigit(str[str.size() - 2]))) {
		str.resize(str.size() - 1);
		if (isFloat(str))
			return FLOAT;
		return ERROR;
	}
	if (str.size() == 1 && isprint(str[0])) {
		if (str[0] >= '0' && str[0] <= '9')
			return INT;
		return CHAR;
	}
	else if (isInt(str))
		return INT;
	else if (isFloat(str))
		return FLOAT;
	else if (isDouble(str))
		return DOUBLE;
	else
		return ERROR;
}

void	printType(type detected) {
	if (detected == CHAR)
		std::cout << "Detected a char." << std::endl;
	else if (detected == INT)
		std::cout << "Detected an int." << std::endl;
	else if (detected == FLOAT)
		std::cout << "Detected a float." << std::endl;
	else if (detected == DOUBLE)
		std::cout << "Detected a double." << std::endl;
	else
		std::cout << "Detected an error." << std::endl;
}

int		main(int ac, char **av)
{
	if (ac != 2) {
		std::cout << av[0] << ": Wrong usage, should be: \"" << av[0] << " <string>\"" << std::endl;
		return (1);
	}

	std::string	input = av[1];

	type	detected = getType(input);
	if (DEBUG)
		printType(detected);
	if (detected == CHAR) {
		char	value = input[0];

		std::cout	<< "char: '" << value << "'" << std::endl
					<< "int: " << static_cast<int>(value) << std::endl
					<< "float: " << static_cast<float>(value) << ".0f" << std::endl
					<< "double: " << static_cast<double>(value) << ".0" << std::endl;
	} else if (detected == INT) {
		int				value;

		std::istringstream	ss(input);
		ss >> value;
		if (isprint(value))
			std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
		else
			std::cout << "char: Not displayable" << std::endl;
		std::cout	<< "int: " << value << std::endl
					<< "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl
					<< "double: " << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
	} else if (detected == FLOAT) {
		float				value;

		std::istringstream	ss(input);
		ss >> value;
		if (isprint(value))
			std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
		else
			std::cout << "char: Not displayable" << std::endl;
		if (value > INT_MAX || value < INT_MIN || value == INFINITY || value != value)
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(value) << std::endl;
		std::cout	<< "float: "  << std::fixed << std::setprecision(1) << value << "f" << std::endl
					<< "double: "  << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
	} else if (detected == DOUBLE) {
		double				value;

		std::istringstream	ss(input);
		ss >> value;
		if (isprint(value))
			std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
		else
			std::cout << "char: Not displayable" << std::endl;
		if (value > INT_MAX || value < INT_MIN)
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(value) << std::endl;
		if (value > FLT_MAX || value < DBL_MIN)
			std::cout << "float: impossible" << std::endl;
		else
			std::cout	<< "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;

	} else if (detected == ERROR) {
		std::cout	<< "char: impossible" << std::endl
					<< "int: impossible" << std::endl
					<< "float: impossible" << std::endl
					<< "double: impossible" << std::endl;
	}
	return (0);
}