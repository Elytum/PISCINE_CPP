#include <iostream>
#include <fstream>

class Logger
{

	public:

		Logger( std::string const filePath );
		~Logger();

		void			log( std::string const & dest, std::string const & message );
		void			append_to_file(std::string const & path, std::string const & string) const;

	private:

		std::string		getTimestamp( void ) const;
		std::string		makeLogEntry( std::string const & origin ) const;
		void			logToConsole(std::string const & target);
		void			logToFile(std::string const & target);

		std::string		filePath;
		bool			goodOpen;
};