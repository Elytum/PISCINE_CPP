#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"

int			main(void)
{
	Intern idiotOne;
	Bureaucrat hermes = Bureaucrat("Hermes Conrad", 37);
	Bureaucrat bob = Bureaucrat("Bobby Bobson", 123);
	OfficeBlock ob;
	ob.setIntern(idiotOne);
	ob.setSigner(bob);
	ob.setExecutor(hermes);
	// try
	// {
	ob.doBureaucracy("shrubbery creation", "Pigley");
	// ob.doBureaucracy("unknown", "Pigley");
	// }
	// catch (Some::SpecificException & e)
	// {
	//  specific known error happens, say something 
	// }
	// catch (std::exception & e)
	// {
	/* oh god, unknown error, what to do ?! */
	// }
}
