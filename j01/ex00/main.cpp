#include <iostream>
#include "Pony.hpp"

void		test_scop_delete(void) {
	Pony	ponyta = Pony::ponyOnTheStack();
	ponyta.show();

	Pony	*unicorn = Pony::ponyOnTheHeap();
	unicorn->show();
	delete unicorn;
}

void		test_scop_nodelete(void) {
	Pony	ponyta = Pony::ponyOnTheStack();
	ponyta.show();

	Pony	*unicorn = Pony::ponyOnTheHeap();
	unicorn->show();
}

int			main(void) {
	std::cout << "Beginning tests :" << std::endl;
	test_scop_delete();
	std::cout << std::endl << "Tests done" << std::endl;
	std::cout << std::endl << "Beginning tests :" << std::endl;
	test_scop_nodelete();
	std::cout << std::endl << "Tests done" << std::endl;
	return (0);
}