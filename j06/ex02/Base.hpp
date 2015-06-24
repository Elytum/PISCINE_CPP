#ifndef BASE_HPP
# define BASE_HPP

class Base
{
	public:
		Base() {}
		virtual ~Base() {}
	private:
		Base(Base const & cpy);
		Base&	operator=(Base const & cpy);
};

#include <A.hpp>
#include <B.hpp>
#include <C.hpp>

#endif
