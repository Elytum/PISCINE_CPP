#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
	public:
		Array( void );
		Array( int n );
		Array( T const & cpy );
		~Array( void );
		int			size( void ) const;
		T&			operator=(T arg);
		T&			operator[](int value);
		const T&	operator[](int value ) const;
	private:
		int		len;
		T*		content;
};

#endif
