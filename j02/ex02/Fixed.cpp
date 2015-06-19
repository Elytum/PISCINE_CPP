#include "Fixed.hpp"

Fixed::Fixed( void ) : rawBits(0) {
}

Fixed::Fixed( int const & value ) {
	rawBits = value << Fixed::fractionBits;
}

Fixed::Fixed( float const & value ) {
	rawBits = roundf(value * (Fixed::fractionBits * (1 << (1 + sizeof(int)))));
}

Fixed::Fixed( Fixed const & cpy ) {
	(*this) = cpy;
}

Fixed::~Fixed(void) {
}

int		Fixed::getRawBits( void ) const {
	return (rawBits);
}

void	Fixed::setRawBits( int const raw ) {
	rawBits = raw;
}

float	Fixed::toFloat( void ) const {
	return (float)rawBits / (Fixed::fractionBits * (1 << (1 + sizeof(int))));
}

int		Fixed::toInt( void ) const {
	return (rawBits >> Fixed::fractionBits);
}

Fixed&	Fixed::min( Fixed const & a, Fixed const & b ) {
	if (a > b)
		return ((Fixed &)b);
	else
		return ((Fixed &)a);
}

Fixed&	Fixed::max( Fixed const & a, Fixed const & b ) {
	if (a > b)
		return ((Fixed &)a);
	else
		return ((Fixed &)b);
}

void	Fixed::operator=( Fixed const & arg ) {
	rawBits = arg.rawBits;
}

bool	Fixed::operator>( Fixed const & cmp ) const {
	return (rawBits > cmp.getRawBits());
}

bool	Fixed::operator<( Fixed const & cmp ) const {
	return (rawBits < cmp.getRawBits());
}

bool	Fixed::operator>=( Fixed const & cmp ) const {
	return (rawBits >= cmp.getRawBits());
}

bool	Fixed::operator<=( Fixed const & cmp ) const {
	return (rawBits <= cmp.getRawBits());
}

bool	Fixed::operator==( Fixed const & cmp ) const {
	return (rawBits == cmp.getRawBits());
}

bool	Fixed::operator!=( Fixed const & cmp ) const {
	return (rawBits != cmp.getRawBits());
}

Fixed	Fixed::operator+( const Fixed& cmp ) const {
	return (Fixed (toFloat() + cmp.toFloat()));
}

Fixed&	Fixed::operator++( void ) {
	setRawBits(rawBits + 1);
	return (*this);
}

Fixed	Fixed::operator++( int ) {
	Fixed	tmp = *this;
	setRawBits(rawBits + 1);
	return (tmp);
}

Fixed	Fixed::operator-( const Fixed& cmp ) const{
	return (Fixed (toFloat() - cmp.toFloat()));
}

Fixed&	Fixed::operator--( void ) {
	setRawBits(toFloat() - 1);
	return (*this);
}

Fixed	Fixed::operator--( int ) {
	Fixed	tmp = *this;
	setRawBits(rawBits - 1);
	return (tmp);
}

Fixed	Fixed::operator*( const Fixed& cmp ) const{
	return (Fixed (toFloat() * cmp.toFloat()));
}

Fixed	Fixed::operator/( const Fixed& cmp ) const{
	return (Fixed (toFloat() / cmp.toFloat()));
}

std::ostream &operator<<(std::ostream& flux, const Fixed& fix)  {
	flux << fix.toFloat();
	return (flux);
}

int main( void ) {
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;
Fixed c(42.42f); Fixed d(3.3f);

std::cout << c / d << std::endl;
return 0;
}