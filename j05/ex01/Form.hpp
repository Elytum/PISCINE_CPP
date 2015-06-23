#ifndef FORM_HPP
# define FORM_HPP

#include <stdexcept>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:

		Form( const std::string name, int requirementSign, int requirementExec );
		Form( Form const & cpy);
		~Form( void );

		std::string		getName( void ) const;
		bool			getWasSigned( void ) const;
		int				getRequirementSign( void ) const;
		int				getRequirementExec( void ) const;

		void			beSigned( Bureaucrat const & P_L_E_A_S_E_Agent );
		Form&			operator=(Form const & cpy);

		class GradeTooHighException : public std::exception
		{
		public:
			virtual const char * what() const throw();
			GradeTooHighException( void );
			GradeTooHighException( Form::GradeTooHighException const & cpy );
			~GradeTooHighException( void ) throw();
			GradeTooHighException&	operator=(Form::GradeTooHighException const & cpy);
		};

		class GradeTooLowException : public std::exception
		{
		public:
			virtual const char * what() const throw();
			GradeTooLowException( void );
			GradeTooLowException( Form::GradeTooLowException const & cpy );
			~GradeTooLowException( void ) throw();
			GradeTooLowException&	operator=(Form::GradeTooLowException const & cpy);
		};

	private:
		
		Form( void );
		void					checkGrade( void ) const;
		const std::string		name;
		bool					wasSigned;
		const int				requirementSign;
		const int				requirementExec;
	
};

std::ostream&		operator<<(std::ostream& flux, Form const & talking);

#endif