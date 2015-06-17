/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivannere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 14:23:12 by ivannere          #+#    #+#             */
/*   Updated: 2015/01/08 01:15:11 by ivannere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISA_HPP
# define ISA_HPP

# include <iostream>
# include <cmath>

class Fixed {

public :
				Fixed(void);
				Fixed( Fixed const & src);
				Fixed(const int i);
				Fixed(const float f);
				~Fixed(void);

	int			getRawBits(void) const;
	void		setRawBits(int const raw);

	float		toFloat(void) const;
	int			toInt(void) const;

	Fixed &		operator=( Fixed const & rhs);
	Fixed		operator+( Fixed const & rhs) const;
	Fixed		operator-( Fixed const & rhs) const;
	Fixed		operator*( Fixed const & rhs) const;
	Fixed		operator/( Fixed const & rhs) const;

	bool		operator>( Fixed const & rhs) const;
	bool		operator<( Fixed const & rhs) const;
	bool		operator>=( Fixed const & rhs) const;
	bool		operator<=( Fixed const & rhs) const;
	bool		operator==( Fixed const & rhs) const;
	bool		operator!=( Fixed const & rhs) const;

	Fixed &		operator++(void);
	Fixed &		operator--(void);
	Fixed		operator++(int);
	Fixed		operator--(int);

static Fixed &		min(Fixed const & a, Fixed const & b);
static Fixed &		max(Fixed const & a, Fixed const & b);
private :
	const int	_fractbits;
	int			_n;
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif