#include "Fixed.hpp"

Fixed::Fixed( void ) : rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( int const & value ) {
	std::cout << "Int constructor called" << std::endl;

	rawBits = value << Fixed::fractionBits;
}

Fixed::Fixed( float const & value ) {
	std::cout << "Float constructor called" << std::endl;

	rawBits = roundf(value * (Fixed::fractionBits * 32));
}

Fixed::Fixed( Fixed const & cpy ) {
	std::cout << "Copy constructor called" << std::endl;
	(*this) = cpy;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits( void ) const {
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
	this->rawBits = arg.rawBits;
}

std::ostream &operator<<(std::ostream& flux, const Fixed& fix)  {
	flux << fix.toFloat();
	return (flux);
}
