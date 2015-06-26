#include "Span.hpp"

#define ABS(n) (n < 0 ? -n : n)
#define DIF(x, y) (x > y ? x - y : y - x)

Span::Span( unsigned int const & N ) : _size(N), _pos(0)	{
	_content.resize(N);
}

Span::Span( Span const & cpy ) : _size(cpy.getSize())	{
	*this = cpy;
}

Span::~Span( void )	{
}

void	Span::addNumber( int const & value ) {
	if (_pos >= _size)
		throw Span::AddOutOfRange();
	_content[_pos++] = value;
}

unsigned int	Span::getSize( void ) const	{
	return _size;
}

unsigned int	Span::getPos( void ) const	{
	return _pos;
}

int				Span::getElement( unsigned int position ) const {
	return _content[position];
}

std::ostream& operator<<(std::ostream& out, Span const & element)	{
	unsigned int i = 0;
	unsigned int size = element.getSize();

	out << "{ ";
	while (i != size)
		out << element.getElement(i++) << " ";
	out << "}";
	return (out);
}

int				Span::shortestSpan( void ) const {
	if (_pos <= 1)
		throw Span::TooLittle();

	int	span = DIF(_content[0], _content[1]);
	int	tmp;
	for (unsigned int x = 0; x < _size; ++x) {
		for (unsigned int y = 0; y < _size; ++y) {
			if (x == y)
				continue;
			if ((tmp = DIF(_content[x], _content[y])) == 0)
				return (0);
			if (tmp < span)
				span = tmp;
		}
	}
	return (span);
}

int				Span::longestSpan( void ) const {
	if (_pos <= 1)
		throw Span::TooLittle();
	
	int	min = _content[0];
	int	max = _content[0];
	for (unsigned int i = 1; i < _pos; ++i) {
		if (_content[i] > max)
			max = _content[i];
		else if (_content[i] < min)
			min = _content[i];
	}
	return (ABS(max - min));
}

Span&			Span::operator=(Span const & cpy)	{
	_content.resize(_size);
	_pos = cpy.getPos();
	for (unsigned int i = 0; i < _size; ++i)
		_content[i] = cpy.getElement(i);
	return *this;
}

	//	Exception AddOutOfRange
const char *Span::AddOutOfRange::what( void ) const throw() {return ("addNumber used with already full span.");}
Span::AddOutOfRange::AddOutOfRange( void ) : std::exception() {}
Span::AddOutOfRange::AddOutOfRange( Span::AddOutOfRange const & cpy ) : std::exception() {*this = cpy;}
Span::AddOutOfRange::~AddOutOfRange( void ) throw() {}
Span::AddOutOfRange& Span::AddOutOfRange::operator=(Span::AddOutOfRange const & cpy)	{(void)cpy;return *this;}

	//	Exception AddOutOfRange
const char *Span::TooLittle::what( void ) const throw() {return ("Span function used with too little span.");}
Span::TooLittle::TooLittle( void ) : std::exception() {}
Span::TooLittle::TooLittle( Span::TooLittle const & cpy ) : std::exception() {*this = cpy;}
Span::TooLittle::~TooLittle( void ) throw() {}
Span::TooLittle& Span::TooLittle::operator=(Span::TooLittle const & cpy)	{(void)cpy;return *this;}
