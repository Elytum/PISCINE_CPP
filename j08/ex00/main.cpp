#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include "easyfind.hpp"

#define MAX_VALUE 100

template < typename T >
void	randomize(T & element) {
	for ( typename T::iterator current = element.begin(); current != element.end(); ++ current )
		*current = rand() % MAX_VALUE;
}

template < typename T >
void	show(T element) {
	std::cout << "{ ";
	for ( typename T::iterator current = element.begin(); current != element.end(); ++ current )
		std::cout << *current << " ";
	std::cout << "}" << std::endl;
}

int		main( void )
{
	srand(clock());

	std::cout << "\t\t>>>>> Testing vectors <<<<<<" << std::endl;
	std::vector<int> testVector(100);
	randomize(testVector);
	show(testVector);
	std::cout << "\tLooking for 10, position: " << easyfind(testVector, 10) << std::endl;
	easyfind(testVector, 10);
	std::cout << std::endl;

	std::cout << "\t\t>>>>>  Testing lists  <<<<<<" << std::endl;
	std::list<int> testList(100);
	randomize(testVector);
	show(testVector);
	std::cout << "\tLooking for 25, position: " << easyfind(testVector, 25) << std::endl;
	return (0);
}