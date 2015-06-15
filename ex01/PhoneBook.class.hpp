#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

#include <iostream>
#include "Contact.class.hpp"

class PhoneBook {

public:
	PhoneBook(void);
	PhoneBook(const PhoneBook &copy);
	~PhoneBook(void);
	PhoneBook& operator= (const PhoneBook &copy);
	int		get_n(void) const;
	void	set_n(const int n);
	void	add(void);
	void	search(void);
	int		full(void);

private:
	const static int	max = 8;
	Contact				contacts[max];
	int					n;
};

#endif
