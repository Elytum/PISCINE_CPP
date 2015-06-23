#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class RobotomyRequestForm : public Form
{
	public:

		RobotomyRequestForm( const std::string target );
		RobotomyRequestForm( RobotomyRequestForm const & cpy);
		virtual ~RobotomyRequestForm( void );

	private:

		RobotomyRequestForm( void );
		const std::string	target;
		virtual void		launch( void ) const;
		const std::string	getTarget( void ) const;
	
};

#endif