#include <iostream>

class Fixed
{

	public:

		Fixed( void );
		Fixed( Fixed const & cpy );
		~Fixed();

		void	operator=( const Fixed& cpy );
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

	private:

		int						rawBits;
		static const int		fractionBits = 8;
};
