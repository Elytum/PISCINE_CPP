#include <iostream>
#include <vector>

class Span
{
	public:
		Span( unsigned int const & N );
		Span( Span const & cpy );
		~Span( void );

		void	addNumber( int const & value );

		template <typename T>
		void	addNumber( T const & container ) {
			for ( typename T::const_iterator current = container.begin(); current != container.end(); ++current )
				addNumber(*current);
		}

		unsigned int	getSize( void ) const;
		unsigned int	getPos( void ) const;
		int				getElement( unsigned int position ) const;
		int				shortestSpan( void ) const;
		int				longestSpan( void ) const;

		Span&			operator=(Span const & cpy);

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