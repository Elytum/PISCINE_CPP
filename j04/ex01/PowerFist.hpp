#ifndef POWERFIST_HPP
# define POWERFIST_HPP

#include "AWeapon.hpp"

class PowerFist : public AWeapon
{
	private:

	public:
		PowerFist( void );
		~PowerFist( void );
		virtual void attack( void ) const;
};

#endif
