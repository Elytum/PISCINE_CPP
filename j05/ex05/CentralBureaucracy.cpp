#include "CentralBureaucracy.hpp"

CentralBureaucracy::CentralBureaucracy() : pos(0), queueLen(0), queueContent(NULL)	{
	generatedInterns = new Intern*	[CentralBureaucracy::nbBlocks];
}

CentralBureaucracy::~CentralBureaucracy() {
	if (!queueContent)
		return ;
	delete [] queueContent;
	while (true) {
		delete generatedInterns[queueLen];
		if (queueLen-- == 0)
			break ;
	}
	delete [] generatedInterns;
}

void	CentralBureaucracy::queueUp(std::string const & target) {
	std::string	*newQueueContent = new std::string[queueLen + 1];

	int	i = 0;
	while (i < queueLen) {
		newQueueContent[i] = queueContent[i];
		++i;
	}
	newQueueContent[queueLen++] = target;
	if (queueContent)
		delete [] queueContent;
	queueContent = newQueueContent;
}

void	CentralBureaucracy::feed(Bureaucrat & newOne) {
	if (pos >= CentralBureaucracy::nbBlocks * 2)
		return ;
	if (!(pos & 0b00000000000000000000000000000001)) {
		generatedInterns[pos] = new Intern();
		blocks[pos].setIntern(*generatedInterns[pos]);
		blocks[pos / 2].setSigner(newOne);
	} else {
		blocks[pos / 2].setExecutor(newOne);
	}
	pos++;
}

void	CentralBureaucracy::doBureaucracy( void ) {
	bool	initialized = false;

	if (initialized == false) {
		initialized = true;
		
		timeb tb;
		
		ftime(&tb);
		int nCount = tb.millitm + (tb.time & 0xfffff) * 1000;
		srand(nCount);
	}

	int		offices = pos / 2;
	int		officeID = 0;
	int		choice;

	if (offices == 0) {
		std::cout << "No Bureaucrats to use." << std::endl;
		return ;
	}
	
	while (true) {
		choice = rand() % 3;
		try {
		if (choice == 0)
				blocks[officeID].doBureaucracy("presidential pardon", queueContent[queueLen]);
			else if (choice == 1)
				blocks[officeID].doBureaucracy("robotomy request", queueContent[queueLen]);
			else if (choice == 2)
				blocks[officeID].doBureaucracy("shrubbery creation", queueContent[queueLen]);
		} catch (OfficeBlock::CantSign) {
		}
		if (queueLen-- == 0)
			break ;
		if (++officeID == offices)
			officeID = 0;
	}

	delete [] queueContent;
	queueContent = NULL;
}