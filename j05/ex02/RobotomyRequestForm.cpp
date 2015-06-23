#include <stdlib.h>
#include <sys/timeb.h>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( const std::string target ) :
	Form( "RobotomyRequestForm", 72, 45 ), target(target) {
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & cpy) :
	Form( "RobotomyRequestForm", 72, 45 ), target(cpy.getTarget()) {
}

RobotomyRequestForm::RobotomyRequestForm( void ) :
	Form( "RobotomyRequestForm", 72, 45 ), target("Nobody") {
}

RobotomyRequestForm::~RobotomyRequestForm( void ) {
}

void	RobotomyRequestForm::launch( void ) const {
	bool	initialized = false;

	if (initialized == false) {
		initialized = true;
		
		timeb tb;
		
		ftime(&tb);
		int nCount = tb.millitm + (tb.time & 0xfffff) * 1000;
		srand(nCount);
	}
	system("say \"aaaaaaaaaaaaaaaaaaaaaaaatttttttttttttttttttttttttttttttttttttttttttttttttttttttttttooooooooooooooooooooooooooo\"");
	if (rand() % 2 == 0)
		std::cout << target << " has been robotomized successfully." << std::endl;
	else
		std::cout << target << " robotomization failed." << std::endl;

}

const std::string	RobotomyRequestForm::getTarget( void ) const {
	return target;
}
