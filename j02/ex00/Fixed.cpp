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

float	Fixed::toFloat( void ) const {
	return (float)rawBits / (Fixed::fractionBits * 32);
}

int		Fixed::toInt( void ) const {
	return (rawBits >> Fixed::fractionBits);
}

void	Fixed::operator=(Fixed const & arg) {
	std::cout << "Assignation operator called" << std::endl;
	this->rawBits = arg.getRawBits();
}

std::ostream &operator<<(std::ostream& flux, const Fixed& fix)  {
	flux << fix.toFloat();
	return (flux);
}