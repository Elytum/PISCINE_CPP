#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie {


public:

	Zombie( void );
	Zombie( std::string name, std::string type );
	~Zombie( void );

	void	announce( void ) const;

private:
	std::string			name;
	std::string			type;
};

#endif