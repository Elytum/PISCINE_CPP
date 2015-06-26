#include <iostream>

int		main( int ac, char **av )
{
	if (ac <= 1) {
		std::cout << av[0] << ": wrong format, should be: " << av[0] << " <string>" << std::endl;
		return (1);
	}
	std::string	line = "";
	char		**ptr = av + 1;

	while (--ac)
		line += *ptr++;
	std::cout << "Line: " << line << std::endl;
}