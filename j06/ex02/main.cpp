#include <Base.hpp>
#include <time.h>
#include <stdlib.h>
#include <iostream>

#define DEBUG true
#define NUMBER_OF_TESTS 10

Base*	generate(void) {
	bool	initialized = false;

	if (initialized == false) {
		initialized = true;
		srand(clock());
	}

	char	seed = rand() % 3;

	if (DEBUG) {
		if (seed == 0)
			std::cout << "Returning A" << std::endl;
		else if (seed == 1)
			std::cout << "Returning B" << std::endl;
		else
			std::cout << "Returning C" << std::endl;
	}

	switch (seed) {
		case 0:
			return new A();
		case 1:
			return new B();
	}
	return new C();
}

void identify_from_pointer( Base * p ) {
	if (dynamic_cast<A*>(p) != NULL) {
		std::cout << "A" << std::endl;
	} else if (dynamic_cast<B*>(p) != NULL) {
		std::cout << "B" << std::endl;
	} else if (dynamic_cast<C*>(p) != NULL) {
		std::cout << "C" << std::endl;
	}
}

void identify_from_reference( Base & p ) {
	if (dynamic_cast<A*>(&p) != NULL) {
		std::cout << "A" << std::endl;
	} else if (dynamic_cast<B*>(&p) != NULL) {
		std::cout << "B" << std::endl;
	} else if (dynamic_cast<C*>(&p) != NULL) {
		std::cout << "C" << std::endl;
	}
}

int		main(void)
{
	int		i = NUMBER_OF_TESTS;
	Base	*ptr;

	while (i--) {
		ptr = generate();
		std::cout << "Pointer: "; identify_from_pointer(ptr);
		std::cout << "Reference: "; identify_from_reference(*ptr);
		delete ptr;
		std::cout << std::endl;
	}
	return (0);
}