#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
using namespace std;

namespace fix
{
	class Fixed
	{

		public:

			Fixed( void );
			Fixed( int const & value );
			Fixed( float const & value );
			Fixed( Fixed const & cpy );
			~Fixed();

			void	operator=( const Fixed& cpy );
			bool	operator>( const Fixed& cmp ) const;
			bool	operator<( const Fixed& cmp ) const;
			bool	operator>=( const Fixed& cmp ) const;
			bool	operator<=( const Fixed& cmp ) const;
			bool	operator==( const Fixed& cmp ) const;
			bool	operator!=( const Fixed& cmp ) const;
			Fixed	operator+( const Fixed& cmp ) const;
			Fixed&	operator++( void );
			Fixed	operator++( int );
			Fixed	operator-( const Fixed& cmp ) const;
			Fixed&	operator--( void );
			Fixed	operator--( int );
			Fixed	operator*( const Fixed& cmp ) const;
			Fixed	operator/( const Fixed& cmp ) const;
			int		getRawBits( void ) const;
			void	setRawBits( int const raw );
			float	toFloat( void ) const;
			int		toInt( void ) const;
			static Fixed&	min( Fixed const & a, Fixed const & b );
			static Fixed&	max( Fixed const & a, Fixed const & b );

		private:

			int						rawBits;
			static const int		fractionBits = 8;
	};

	ostream &operator<<( ostream &flux, const Fixed &fixed );
}
#endif
