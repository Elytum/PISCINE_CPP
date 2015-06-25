#include <iostream>

template< typename T >
class Array	{

	public:

		Array<T>( void ) : _len(0), _content(new T[0])								{
		}

		Array<T>( int len ) : _len(len), _content(new T[len])						{
		}

		Array<T>( Array<T> const & list ) : _len(list.size()), _content(new T[list.size()])	{
		}

		~Array<T>( void )	{
			delete [] _content;
		}

		int	size( void ) const	{
			return _len;
		}

		Array<T>&			operator=(Array<T> cpy)	{
			int		max = cpy.size();

			_content = new T[max];

			int	i = 0;
			while (i < max) {
				_content[i] = cpy[i];
				++i;
			}
			_len = cpy.size();
		}

		T&			operator[](int value)		{
			if (value >= _len)
				throw std::exception();
			return _content[value];
		}
		
		const T&	operator[](int value ) const{
			if (value >= _len)
				throw std::exception();
			return _content[value];
		}

private:

	int			_len;
	T *			_content;
};
