#ifndef HUMAN_HPP
# define HUMAN_HPP

#include <iostream>
#include "Brain.hpp"

class Human {


public:

	typedef Human	t;

	Human( void );
	~Human( void );

	std::string		identify( void ) const;
	Brain			&getBrain( void ) ;

private:
	Brain		brain;
};

#endif