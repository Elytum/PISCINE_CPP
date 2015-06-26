#include "Span.hpp"

#define RANGE 2147000000
#define SIZE 20000

int		main( void )
{
	Span	test(SIZE);

	srand(clock());

	std::cout << "Filling span... ";
	try {
		for (;;)
			test.addNumber(rand() % RANGE);
	} catch (Span::AddOutOfRange) {
		std::cout << "Span full !" << std::endl;
	}
	std::cout << "Content: " << test << std::endl;
	std::cout << "Shortest: " << test.shortestSpan() << std::endl;
	std::cout << "Longest: " << test.longestSpan() << std::endl;
	return (0);
}
