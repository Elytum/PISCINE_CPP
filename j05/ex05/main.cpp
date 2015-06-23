#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"
#include "CentralBureaucracy.hpp"

int			main(void)
{
	CentralBureaucracy	bureau;
	Bureaucrat		ArthurDent("Arthur Dent", 50);
	Bureaucrat		HummaKavula("Humma Kavula", 5);
	Bureaucrat		FordPrefect("Ford Prefect", 12);
	Bureaucrat		ZafodBeeblebrox("Zafod Beeblebrox", 2);
	
	bureau.queueUp("One");
	bureau.queueUp("Two");
	bureau.queueUp("Three");
	bureau.queueUp("Four");
	bureau.queueUp("Five");
	bureau.queueUp("Six");
	bureau.queueUp("Seven");
	bureau.queueUp("Eight");
	bureau.queueUp("Nine");
	bureau.queueUp("Ten");
	bureau.queueUp("Eleven");
	bureau.queueUp("Twelve");
	bureau.feed(ArthurDent);
	bureau.feed(HummaKavula);
	bureau.feed(FordPrefect);
	bureau.feed(ZafodBeeblebrox);
	bureau.doBureaucracy();
	// Intern idiotOne;
	// Bureaucrat hermes = Bureaucrat("Hermes Conrad", 37);
	// Bureaucrat bob = Bureaucrat("Bobby Bobson", 123);
	// OfficeBlock ob;
	// ob.setIntern(idiotOne);
	// ob.setSigner(bob);
	// ob.setExecutor(hermes);
	// try
	// {
	// ob.doBureaucracy("shrubbery creation", "Pigley");
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
