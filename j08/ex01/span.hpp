#include <iostream>
#include <vector>

class Span
{
	public:
		Span( unsigned int const & N );
		
	// template <typename T>
	// Span( T const & container ) {
	// 	for ( typename T::iterator current = container.begin(); current != container.end(); ++ current )
	// 		addNumber(*current);
	// }
		
		// Span( Span const & cpy );
		~Span( void );

		void	addNumber( int const & value );

		unsigned int	getSize( void ) const;
		int				getElement( unsigned int position ) const;
		int				shortestSpan( void ) const;
		int				longestSpan( void ) const;

		class AddOutOfRange : public std::exception
		{
		public:
			virtual const char * what() const throw();
			AddOutOfRange( void );
			AddOutOfRange( Span::AddOutOfRange const & cpy );
			~AddOutOfRange( void ) throw();
			AddOutOfRange&	operator=(Span::AddOutOfRange const & cpy);
		};

		class TooLittle : public std::exception
		{
		public:
			virtual const char * what() const throw();
			TooLittle( void );
			TooLittle( Span::TooLittle const & cpy );
			~TooLittle( void ) throw();
			TooLittle&	operator=(Span::TooLittle const & cpy);
		};

	private:
		Span( void );
		std::vector<int>	_content;
		const unsigned int	_size;
		unsigned int		_pos;
};

std::ostream& operator<<(std::ostream& out, Span const & element);