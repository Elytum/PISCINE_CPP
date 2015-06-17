#include <iostream>
#include <fstream>

#define PROOF false

std::string		replace_in_string(std::string str, std::string before, std::string after)
{
	size_t			index = 0;

	while (true) {
		index = str.find(before, index);
		if (index == std::string::npos)
			break;
		str.replace(index, before.size(), after);
		index += after.size();
	}
	return (str);
}

std::string		file_to_string(std::string path)
{
	std::ifstream	ifs(path);
	std::string		content;

	content.assign( (std::istreambuf_iterator<char>(ifs) ),
					(std::istreambuf_iterator<char>()    ) );
	ifs.close();
	return (content);
}

std::string		file_replaced(std::string path, std::string before, std::string after) {
	return (replace_in_string(file_to_string(path), before, after));
}

void			string_to_file(std::string string, std::string path) {
	std::ofstream	file;

	file.open(path);
	if (!file.good())
		std::cout << "Error: " << strerror(errno) << std::endl;
	else
		file << string;
	file.close();
}

void			show_differences(std::string path) {
	std::cout << "Differences :" << std::endl << system(("diff " + path + " " + path + ".replace").c_str()) << std::endl;
}

int		main(int ac, char **av)
{
	if (ac != 4)
		std::cout << "Wrong format : " << av[0] << " <file> <before> <after>" << std::endl;
	else {
		if (file_to_string(av[1]).empty()) {
			std::cout << av[0] << ": " << strerror(errno) << std::endl;
			return (1);
		}
		string_to_file(file_replaced(av[1], av[2], av[3]), std::string(av[1]) + ".replace");
		if (PROOF)
			show_differences(av[1]);
	}
	return (0);
}