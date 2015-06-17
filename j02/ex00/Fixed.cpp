#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed( void ) : value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( Fixed const & cpy ) {
	std::cout << "Copy constructor called" << std::endl;
	(*this) = cpy;
}

Fixed::~Fixed( void ) {
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
    this->rawBits = arg.rawBits;
}
