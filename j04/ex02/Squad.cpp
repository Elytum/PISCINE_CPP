#include "Squad.hpp"

Squad::Squad( void ) : count(0), container(0) {
}

Squad::~Squad( void ) {
	while (count > 0)
		delete container[--count];
}

int				Squad::getCount( void ) const {
	return (count);
}

int				Squad::push( ISpaceMarine* marine ) {
	ISpaceMarine**		containing = new ISpaceMarine*[count + 1];
	int					len = 0;

	while (len < count) {
		containing[len] = container[len];
		++len;
	}
	if (container)
		delete [] container;
	containing[len] = marine->clone();
	container = containing;
	return (count++);
}

ISpaceMarine*	Squad::getUnit( int arg ) const {
	if (arg < 0 || arg >= count)
		return (0);
	return (container[arg]);
}