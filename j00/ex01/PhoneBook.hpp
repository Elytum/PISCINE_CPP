#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

#include <iostream>
#include <Contact.hpp>

class PhoneBook {


public:

	PhoneBook(void);
	PhoneBook(const PhoneBook &copy);
	~PhoneBook(void);
	PhoneBook& operator= (const PhoneBook &copy);
	size_t	get_n(void) const;
	void	set_n(const size_t n);
	void	add(void);
	void	search(void);
	int		full(void);

private:

	const static size_t	max = 8;
	Contact				contacts[max];
	size_t				n;
};

#endif
