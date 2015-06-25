#include <Array.hpp>

int	main(void)
{

	std::cout << "\t\t>>>>>>>>   Testing int    <<<<<<<<" << std::endl;
	Array<int> testInt = Array<int>(10);
	std::cout << "'" << testInt[0] << "'" << std::endl;
	testInt[0] = 42;
	std::cout << "'" << testInt[0] << "'" << std::endl;


	std::cout << std::endl << std::endl << "\t\t>>>>>>>>  Testing string  <<<<<<<<" << std::endl;
	Array<std::string> testString = Array<std::string>(10);
	std::cout << "'" << testString[0] << "'" << std::endl;
	testString[0] = "Coucou";
	std::cout << "'" << testString[0] << "'" << std::endl;

	std::cout << std::endl << std::endl << "\t\t>>>>>>>>  Testing limits  <<<<<<<<" << std::endl;
	try {
		std::cout << testString[11] << std::endl;
		testString[11] = "Coucou";
		std::cout << testString[11] << std::endl;
	} catch (std::exception & e) {
		std::cout << "Caught exception." << std::endl;
	}

	std::cout << std::endl << std::endl << "\t\t>>>>>>>>   Testing dup    <<<<<<<<" << std::endl;
	Array<int> first = Array<int>(2);
	Array<int> second = first;
	first[0] = 42;
	std::cout << first[0] << " vs " << second[0] << std::endl;
	return(0);
}