#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class RobotomyRequestForm : public Form
{
	public:

		RobotomyRequestForm( const std::string target );
		RobotomyRequestForm( RobotomyRequestForm const & cpy);
		virtual ~RobotomyRequestForm( void );
		virtual const std::string	getTarget( void ) const;
		virtual void		launch( void ) const;

	private:

		RobotomyRequestForm( void );
		const std::string	target;
	
};

#endif