#include <iostream>

class Fixed
{

	public:

		Fixed( void );
		Fixed( int const & value );
		Fixed( Fixed const & cpy );
		Fixed( float const & cpy );
		~Fixed();

		void	operator=( const Fixed& cpy );
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;

		void	print( std::ostream &flux ) const;
		void	put_fixed( void );

	private:

		int						rawBits;
		static const int		fractionBits = 8;
};

std::ostream &operator<<( std::ostream &flux, const Fixed &fixed );
