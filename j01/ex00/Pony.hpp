#ifndef PONY_HPP
# define PONY_HPP

#include <iostream>

class Pony {


public:

	Pony( void );
	~Pony( void );

	static Pony		ponyOnTheStack( void );
	static Pony		*ponyOnTheHeap( void );
	void			print(void) const;
	void			print(std::ostream &flux) const;
	void			talk( void ) const;
	void			show( void ) const;
	void			die( void ) const;

private:
	std::string			name;
	std::string			image;
	std::string			death;
};

std::ostream &operator<<(std::ostream &flux, const Pony &pony);

#endif
