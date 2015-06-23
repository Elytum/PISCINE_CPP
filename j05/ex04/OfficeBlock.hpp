#ifndef OFFICEBLOCK_HPP
# define OFFICEBLOCK_HPP

#include "Intern.hpp"
#include "Bureaucrat.hpp"

class OfficeBlock
{
	public:
		OfficeBlock( void );
		OfficeBlock( Intern &intern, Bureaucrat &signer, Bureaucrat &executer );
		~OfficeBlock();

		void	setIntern(Intern &ptr);
		void	setSigner(Bureaucrat &ptr);
		void	setExecutor(Bureaucrat &ptr);
		void	doBureaucracy(std::string const & name, std::string const & target) const;

		class UnknownForm : public std::exception
		{
		public:
			virtual const char * what() const throw();
			UnknownForm( void );
			UnknownForm( OfficeBlock::UnknownForm const & cpy );
			~UnknownForm( void ) throw();
			UnknownForm&	operator=(OfficeBlock::UnknownForm const & cpy);
		};

		class CantSign : public std::exception
		{
		public:
			virtual const char * what() const throw();
			CantSign( void );
			CantSign( OfficeBlock::CantSign const & cpy );
			~CantSign( void ) throw();
			CantSign&	operator=(OfficeBlock::CantSign const & cpy);
		};

		class CantExec : public std::exception
		{
		public:
			virtual const char * what() const throw();
			CantExec( void );
			CantExec( OfficeBlock::CantExec const & cpy );
			~CantExec( void ) throw();
			CantExec&	operator=(OfficeBlock::CantExec const & cpy);
		};

	
	private:
		OfficeBlock(OfficeBlock const & cpy);
		OfficeBlock&	operator=(OfficeBlock const & cpy);
		Intern		*intern;
		Bureaucrat	*signer;
		Bureaucrat	*executer;
};

#endif