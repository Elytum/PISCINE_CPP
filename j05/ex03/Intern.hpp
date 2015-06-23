#ifndef INTERN_HPP
# define INTERN_HPP

#include "Form.hpp"
#include <iostream>

class Intern
{
	public:
	
		Intern( void );
		~Intern( void );
		Form*	makeForm(std::string const & formKind, std::string const & target);

};

#endif