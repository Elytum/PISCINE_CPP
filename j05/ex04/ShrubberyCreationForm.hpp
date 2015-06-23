#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
	public:

		ShrubberyCreationForm( const std::string target );
		ShrubberyCreationForm( ShrubberyCreationForm const & cpy);
		virtual ~ShrubberyCreationForm( void );
		virtual const std::string	getTarget( void ) const;
		virtual void		launch( void ) const;

	private:

		ShrubberyCreationForm( void );
		const std::string	target;
	
};

#endif