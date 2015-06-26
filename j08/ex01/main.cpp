#include "Span.hpp"

// #define RANGE 5
// #define SIZE 10

#define RANGE 2147000000
#define SIZE 20000

template < typename T >
void	randomize(T & element) {
	for ( typename T::iterator current = element.begin(); current != element.end(); ++ current )
		*current = rand() % RANGE;
}

int		main( void )
{
	Span	test(SIZE);

	srand(clock());
	std::vector<int> testVector(SIZE);
	randomize(testVector);

	std::cout << "Filling span... ";
	try {
		test.addNumber(rand() % RANGE);
		test.addNumber(rand() % RANGE);
		test.addNumber(testVector);
	} catch (Span::AddOutOfRange) {
		std::cout << "Span full !" << std::endl;
	}

	Span	cpy = test;
	std::cout << "Content: " << cpy << std::endl;
	std::cout << "Shortest: " << cpy.shortestSpan() << std::endl;
	std::cout << "Longest: " << cpy.longestSpan() << std::endl;
	return (0);
}
