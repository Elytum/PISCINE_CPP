#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
	public:

		PresidentialPardonForm( const std::string target );
		PresidentialPardonForm( PresidentialPardonForm const & cpy);
		virtual ~PresidentialPardonForm( void );
		virtual void		launch( void ) const;

	private:

		PresidentialPardonForm( void );
		const std::string	target;
		const std::string	getTarget( void ) const;
	
};

#endif