#ifndef SORCERER_HPP
# define SORCERER_HPP

#include <iostream>
#include "Victim.hpp"

class Sorcerer
{

	public:

		Sorcerer( std::string name, std::string title );
		Sorcerer( Sorcerer const & cpy );
		~Sorcerer();

		std::string		getName( void ) const;
		void			setName( std::string const arg );
		std::string		getTitle( void ) const;
		void			setTitle( std::string const arg );

		void			polymorph(Victim const & arg) const;
		
		Sorcerer&		operator=( Sorcerer const & arg );

	private:

		std::string				name;
		std::string				title;
};

std::ostream &operator<<( std::ostream &flux, const Sorcerer &arg );

#endif