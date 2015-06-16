#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie {


public:

	Zombie( void );
	Zombie( std::string name, std::string type );
	~Zombie( void );

	void	announce( void ) const;
	static std::string		randomName( void );

private:
	std::string			name;
	std::string			type;
};

#endif