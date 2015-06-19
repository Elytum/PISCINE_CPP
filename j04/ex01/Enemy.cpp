#include "Enemy.hpp"

Enemy::Enemy( int hp, std::string const & type ) :
								hp(hp), type(type) {
}

Enemy::Enemy( void ) : hp(0), type("Unknown") {
}

Enemy::Enemy( Enemy const & cpy ) {
	(*this) = cpy;
}

Enemy::~Enemy(void) {
}

std::string		Enemy::getType() const{
	return (type);
}

int				Enemy::getHP() const{
	return (hp);
}

void			Enemy::takeDamage( int arg ) {
	if (arg < 0)
		return ;
	if (arg > hp)
		hp = 0;
	else
		hp -= arg;
}

Enemy&			Enemy::operator=(Enemy const & arg) {
	hp = arg.getHP();
	type = arg.getType();
	return (*this);
}

std::ostream	&operator<<(std::ostream& flux, const Enemy& arg) {
	flux	<< "This is a \"" << arg.getType()
			<< "\", it has " << arg.getHP() << " HP"
		<< std::endl;
	return (flux);
}
