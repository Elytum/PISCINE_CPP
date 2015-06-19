#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "AWeapon.hpp"
#include "Enemy.hpp"

class Character
{
	private:
		std::string		name;
		int				APPoints;
		AWeapon			*weapon;

		Character( void );

	public:
		Character(std::string const & name);
		/*[...]*/
		~Character( void );
		void			recoverAP( void );
		void			equip( AWeapon* );
		void			attack( Enemy* );
		std::string /*[...]*/ getName( void ) const;
		int				getAPPoints( void ) const;
		AWeapon*		getWeapon( void ) const;
};

std::ostream &operator<<(std::ostream& flux, const Character& arg);

#endif
