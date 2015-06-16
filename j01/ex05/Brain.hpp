#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain {


public:

	typedef Brain	t;

	Brain( void );
	~Brain( void );

	std::string		identify( void ) const;
	
};

#endif