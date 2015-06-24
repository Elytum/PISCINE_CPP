#include "Array.hpp"

Array::Array( void ) : len(0), content(new T[0])	{
}

Array::Array( int n ) : len(n), content(new T[n])	{
	int	i = 0;
	while (i < n)
		content[i] = 0;
}

Array::Array( T const & cpy )	{
	*this = cpy;
}

Array::~Array( void ) {
	delete [] content;
}

int			Array::size( void ) const	{
	return len;
}

T&			Array::operator=(T arg)	{
	int		max = cpy.size();

	content = new T[max];

	int	i = 0;
	while (i < max) {
		content[i] = cpy[i];
		++i;
	}
	len = arg.size();
}

T&			Array::operator[](int value)		{
	if (value >= z len)
		throw std::exception();
	return content[value];
}

const T&	Array::operator[](int value) const	{
	if (value >= z len)
		throw std::exception();
	return content[value];
}
