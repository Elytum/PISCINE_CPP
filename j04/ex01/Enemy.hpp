#ifndef ENEMY_HPP
# define ENEMY_HPP

#include <iostream>

class Enemy
{
	private:
		int				hp ;
		std::string		type;

		Enemy	( void );

	public:
		Enemy( int hp, std::string const & type );
		Enemy	( Enemy const & cpy );
		~Enemy( void );

		std::string		getType() const;
		int				getHP() const;
		virtual void	takeDamage( int );
		Enemy&			operator=( Enemy const & arg );
};

std::ostream &operator<<(std::ostream& flux, const Enemy& arg);

#endif