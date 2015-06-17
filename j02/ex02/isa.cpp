/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivannere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 14:23:10 by ivannere          #+#    #+#             */
/*   Updated: 2015/01/08 01:15:13 by ivannere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "isa.hpp"

Fixed::Fixed(void) : _fractbits(8)
{
	this->_n = 0;
	return ;
}

Fixed::Fixed( Fixed const & src) : _fractbits(8)
{
	*this = src;
	return ;
}

Fixed::Fixed(const int i) : _fractbits(8)
{
	this->_n = (i << this->_fractbits);
	return ;
}

Fixed::Fixed(const float f) : _fractbits(8)
{
	this->_n = roundf(f * (this->_fractbits * 32));
	return ;
}

int		Fixed::getRawBits(void) const
{
	return this->_n;
}

void	Fixed::setRawBits(int const raw)
{
	this->_n = raw;
	return ;
}

float	Fixed::toFloat(void) const
{
	float	l;
	l = (float)this->_n / (this->_fractbits * 32);
	return l;
}

int		Fixed::toInt(void) const
{
	int		l;
	l = this->_n >> this->_fractbits;
	return l;;
}

Fixed & 	Fixed::operator=( Fixed const & rhs)
{
	this->_n = rhs.getRawBits();
	return *this;
}

Fixed	 	Fixed::operator+( Fixed const & rhs) const
{
	return Fixed( this->_n + rhs.getRawBits());
}


Fixed	 	Fixed::operator-( Fixed const & rhs) const
{
	return Fixed( this->_n - rhs.getRawBits());
}


Fixed	 	Fixed::operator*( Fixed const & rhs) const
{
	return Fixed( this->toFloat() * rhs.toFloat());
}

Fixed	 	Fixed::operator/( Fixed const & rhs) const
{
	return Fixed( this->toFloat() / rhs.toFloat());
}

bool		Fixed::operator>( Fixed const & rhs) const
{
	if (this->_n > rhs.getRawBits())
		return true;
	else
		return false;
}

bool		Fixed::operator<( Fixed const & rhs) const
{
	if (this->_n < rhs.getRawBits())
		return true;
	else
		return false;
}

bool		Fixed::operator>=( Fixed const & rhs) const
{
	if (this->_n >= rhs.getRawBits())
		return true;
	else
		return false;
}

bool		Fixed::operator<=( Fixed const & rhs) const
{
	if (this->_n <= rhs.getRawBits())
		return true;
	else
		return false;
}

bool		Fixed::operator==( Fixed const & rhs) const
{
	if (this->_n == rhs.getRawBits())
		return true;
	else
		return false;
}

bool		Fixed::operator!=( Fixed const & rhs) const
{
	if (this->_n != rhs.getRawBits())
		return true;
	else
		return false;
}

Fixed &		Fixed::operator++(void)
{
	Fixed	tmp = _n;
	(_n)++;
	return *this;
}

Fixed &		Fixed::operator--(void)
{
	Fixed	tmp = _n;
	(_n)--;
	return *this;
}

Fixed		Fixed::operator++(int)
{
	Fixed tmp = *this;
	++(this->_n);
	return tmp;
}

Fixed		Fixed::operator--(int)
{
	Fixed tmp = *this;
	--(this->_n);
	return tmp;
}

Fixed &		Fixed::min(Fixed const & a, Fixed const & b)
{
	Fixed &		i = (Fixed&)a;
	if (a < b)
		return i = a;
	else if (b < a)
		return i = b;
	else
		return i = a;
}

Fixed &		Fixed::max(Fixed const & a, Fixed const  & b)
{
	Fixed &		i = (Fixed&)a;
	if (a > b)
		return i = a;
	else if (b > a)
		return i = b;
	else
		return i = a;
}


std::ostream & operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return o;
}

Fixed::~Fixed(void)
{
	return ;
}
