#ifndef TACTICALMARINE_HPP
# define TACTICALMARINE_HPP

#include <iostream>
#include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine
{
	public:
		TacticalMarine( void );
		virtual ~TacticalMarine( void );
		virtual ISpaceMarine*	clone( void ) const;
		virtual void			battleCry( void ) const;
		virtual void			rangedAttack( void ) const;
		virtual void			meleeAttack( void ) const;

		TacticalMarine&		operator=( TacticalMarine const & arg );
};

#endif
