#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	public:

		Bureaucrat( const std::string & name, int grade );
		Bureaucrat( Bureaucrat const & cpy);
		~Bureaucrat( void );
		std::string			getName( void ) const;
		int					getGrade( void ) const;
		void				promote( void );
		void				demote( void );
		void				signForm( Form & formular ) const;
		Bureaucrat&			operator=(Bureaucrat const & cpy);
		void				executeForm(Form const & form);

		class GradeTooHighException : public std::exception
		{
		public:
			virtual const char * what() const throw();
			GradeTooHighException( void );
			GradeTooHighException( Bureaucrat::GradeTooHighException const & cpy );
			~GradeTooHighException( void ) throw();
			GradeTooHighException&	operator=(Bureaucrat::GradeTooHighException const & cpy);
		};

		class GradeTooLowException : public std::exception
		{
		public:
			virtual const char * what() const throw();
			GradeTooLowException( void );
			GradeTooLowException( Bureaucrat::GradeTooLowException const & cpy );
			~GradeTooLowException( void ) throw();
			GradeTooLowException&	operator=(Bureaucrat::GradeTooLowException const & cpy);
		};
		
	private:

		Bureaucrat( void );
		void				checkGrade( void ) const;
		const std::string	name;
		int					grade;
};

std::ostream&		operator<<(std::ostream& flux, Bureaucrat const & talking);

#endif