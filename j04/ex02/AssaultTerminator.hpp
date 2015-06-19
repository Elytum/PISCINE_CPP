#ifndef ASSAULTTERMINATOR_HPP
# define ASSAULTTERMINATOR_HPP

#include <iostream>
#include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine
{
	public:
		AssaultTerminator( void );
		virtual ~AssaultTerminator( void );
		virtual ISpaceMarine*	clone( void ) const;
		virtual void			battleCry( void ) const;
		virtual void			rangedAttack( void ) const;
		virtual void			meleeAttack( void ) const;

		AssaultTerminator&		operator=( AssaultTerminator const & arg );
};

#endif
