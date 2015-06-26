#include <iostream>
#include <algorithm>
#include <list>

template < typename T >
int		easyfind(T const & element, int value) {
	for ( typename T::const_iterator current = element.begin(); current != element.end(); ++current ) {
		if (*current == value)
			return (std::distance(element.begin(), current));
	}
	return (-1);
}
