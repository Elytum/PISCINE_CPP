#ifndef VICTIM_HPP
# define VICTIM_HPP

#include <iostream>

class Victim
{

	public:

		Victim( std::string name );
		Victim( Victim const & cpy );
		~Victim();

		std::string		getName( void ) const;
		void			setName( std::string const arg );
		
		Victim&			operator=(Victim const & arg);
		virtual void	getPolymorphed() const;

	protected:

		Sorcerer ( void );
		std::string				name;
};

std::ostream &operator<<( std::ostream &flux, const Victim &arg );

#endif