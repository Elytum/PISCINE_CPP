#ifndef CENTRALBUREAUCRACY_HPP
# define CENTRALBUREAUCRACY_HPP

#include "OfficeBlock.hpp"
#include <iostream>
#include <sys/timeb.h>

class CentralBureaucracy
{
	public:

		CentralBureaucracy();
		~CentralBureaucracy();
		void	queueUp(std::string const & target);
		void	feed(Bureaucrat & newOne);
		void	doBureaucracy( void );

	private:

		int					pos;
		static const int	nbBlocks = 20;
		OfficeBlock			blocks[nbBlocks];
		Intern				**generatedInterns;
		int					queueLen;
		std::string			*queueContent;
};

#endif