#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP

#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon
{
	private:

	public:
		PlasmaRifle( void );
		~PlasmaRifle( void );
		virtual void attack( void ) const;
};

#endif