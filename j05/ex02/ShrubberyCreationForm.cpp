#include <fstream>

#define TREE \
"            .        +          .      .          .\n"\
"     .            _        .                    .\n"\
"  ,              /;-._,-.____        ,-----.__\n"\
" ((        .    (_:#::_.:::. `-._   /:, /-._, `._,\n"\
"  `                 \\   _|`\"=:_::.`.);  \\ __/ /\n"\
"                      ,    `./  \\:. `.   )==-'  .\n"\
"    .      ., ,-=-.  ,\\, +#./`   \\:.  / /           .\n"\
".           \\/:/`-' , ,\\ '` ` `   ): , /_  -o\n"\
"       .    /:+- - + +- : :- + + -:'  /(o-) \\)     .\n"\
"  .      ,=':  \\    ` `/` ' , , ,:' `'--\".--\"---._/`7\n"\
"   `.   (    \\: \\,-._` ` + '\\, ,\"   _,--._,---\":.__/\n"\
"              \\:  `  X` _| _,\\/'   .-'\n"\
".               \":._:`\\____  /:'  /      .           .\n"\
"                    \\::.  :\\/:'  /              +\n"\
"   .                 `.:.  /:'  }      .\n"\
"           .           ):_(:;   \\           .\n"\
"                      /:. _/ ,  |\n"\
"                   . (|::.     ,`                  .\n"\
"     .                |::.    {\\\n"\
"                      |::.\\  \\ `.\n"\
"                      |:::(\\    |\n"\
"              O       |:::/{ }  |                  (o\n"\
"               )  ___/#\\::`/ (O \"==._____   O, (O  /`\n"\
"          ~~~w/w~\"~~,\\` `:/,-(~`\"~~~~~~~~\"~o~\\~/~w|/~\n"\
"      ~~~~~~~~~~~~~~~~~~~~~~~\\\\W~~~~~~~~~~~~\\|/~~"

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( const std::string target ) :
	Form( "ShrubberyCreationForm", 145, 137 ), target(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & cpy) :
	Form( "ShrubberyCreationForm", 145, 137 ), target(cpy.getTarget()) {
}

ShrubberyCreationForm::ShrubberyCreationForm( void ) :
	Form( "ShrubberyCreationForm", 145, 137 ), target("Nobody") {
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {
}

void	ShrubberyCreationForm::launch( void ) const {
	std::ofstream	outputFile(target + "_shrubbery");

	outputFile << TREE << std::endl;
}

const std::string	ShrubberyCreationForm::getTarget( void ) const {
	return target;
}