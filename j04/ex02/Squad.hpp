#ifndef SQUAD_HPP
# define SQUAD_HPP

#include <iostream>
#include "ISpaceMarine.hpp"
#include "ISquad.hpp"

class Squad : public ISquad
{
	private:
		int						count;

	public:
		Squad( void );
		virtual ~Squad();
		virtual int				getCount() const;
		virtual ISpaceMarine*	getUnit(int) const;
		virtual int				push(ISpaceMarine*);
};

#endif
