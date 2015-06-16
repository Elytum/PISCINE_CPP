#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact
{
public:
	Contact();
	Contact(const Contact &copy);
	~Contact();
	Contact& operator= (const Contact &copy);
	std::string		format_string(std::string src) const;
	void			put_field(void) const;
	void			print(void) const;
	void			print(std::ostream &flux) const;

//			Getters
	size_t		get_i(void) const;
	std::string	get_first_name(void) const;
	std::string	get_last_name(void) const;
	std::string	get_nickname(void) const;
	std::string	get_login(void) const;
	std::string	get_postal_address(void) const;
	std::string	get_email_address(void) const;
	std::string	get_phone_number(void) const;
	std::string	get_birthday_date(void) const;
	std::string	get_favorite_meal(void) const;
	std::string	get_underwear_color(void) const;
	std::string	get_darkest_secret(void) const;

//			Setters
	void		set(const size_t i);
	void		set_i(const size_t i);
	void		set_first_name(const std::string first_name);
	void		set_last_name(const std::string last_name);
	void		set_nickname(const std::string nickname);
	void		set_login(const std::string login);
	void		set_postal_address(const std::string postal_address);
	void		set_email_address(const std::string email_address);
	void		set_phone_number(const std::string phone_number);
	void		set_birthday_date(const std::string birthday_date);
	void		set_favorite_meal(const std::string favorite_meal);
	void		set_underwear_color(const std::string underwear_color);
	void		set_darkest_secret(const std::string darkest_secret);

private:
	int				i;
	std::string		first_name;
	std::string		last_name;
	std::string		nickname;
	std::string		login;
	std::string		postal_address;
	std::string		email_address;
	std::string		phone_number;
	std::string		birthday_date;
	std::string		favorite_meal;
	std::string		underwear_color;
	std::string		darkest_secret;
};

std::ostream &operator<<(std::ostream &flux, const Contact &contact);

#endif
