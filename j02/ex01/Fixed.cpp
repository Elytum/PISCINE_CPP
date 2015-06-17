#include "Fixed.hpp"
#include <iostream>

#include <bitset>

void put_bin(int val)
{
	const int		max = sizeof(val) * 8 - 1;

	int i = max;
	std::cout << "0b";
	while (true) {
		if (val & 0b10000000000000000000000000000000)
			std::cout << '1';
		else
			std::cout << '0';
		if (i == 0)
			break;
		--i;
		val <<= 1;
	}
}

void Fixed::put_fixed( void )
{
	const int		max = sizeof(this->getRawBits()) * 8 - 1;

	int				val = this->getRawBits();
	int				i = max;

	std::cout << "[";
	while (true) {
		if (i == Fixed::fractionBits - 1)
			std::cout << " ";
		if (val & 0b10000000000000000000000000000000)
			std::cout << '1';
		else
			std::cout << '0';
		if (i == 0)
			break;
		--i;
		val <<= 1;
	}
	std::cout << "]";
}

Fixed::Fixed( void ) : rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( int const & value ) {
	const int	max = (sizeof(int) * 8);
	const int	signed_bit = max - 1;
	const int	middle = max - Fixed::fractionBits;


	rawBits = 0;
	int			i = 0;

	rawBits |= (1 << signed_bit);
	while (i != middle) {
		if ((value >> i) & 1) {
			rawBits |= 1 << (i + Fixed::fractionBits);
		}
		++i;
	}
					// std::cout << "value: ";
					// put_bin(value);
					// std::cout << ", rawBits: ";
					// this->put_fixed();
					// std::cout << std::endl;
}

Fixed::Fixed( float const & rawBits ) : rawBits(rawBits) {
	std::cout << "Float constructor called" << std::endl;
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
	return (this->rawBits);
}

int		Fixed::toInt( void ) const {
	const int	max = (sizeof(int) * 8) - 1;
	const int	signed_bit = max - 1;
	const int	middle = max - Fixed::fractionBits;

	int			i = 0;
	int			value = 0;

	if (rawBits >> signed_bit & 1)
		value |= 1 << signed_bit;
	while (i != middle) {
		if ((rawBits >> (i + Fixed::fractionBits)) & 1)
			value |= 1 << i;
		++i;
	}
	return (value);
}

void	Fixed::operator=(Fixed const & arg) {
	std::cout << "Assignation operator called" << std::endl;
	this->rawBits = arg.rawBits;
}

std::ostream &operator<<(std::ostream& flux, const Fixed& fix)  {
	flux << fix.toInt();
	return (flux);
}
