#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed( void ) : rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( Fixed const & cpy ) {
	std::cout << "Copy constructor called" << std::endl;
	(*this) = cpy;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (rawBits);
}
void	Fixed::setRawBits( int const raw ) {
	rawBits = raw;
}

void	Fixed::operator=(Fixed const & arg) {
	std::cout << "Assignation operator called" << std::endl;
	rawBits = arg.getRawBits();
}

std::ostream &operator<<(std::ostream& flux, const Fixed& )  {
	flux << "Operator << called";
	return (flux);
}

int main( void ) {
	Fixed a;
	Fixed b( a );
	Fixed c;
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}