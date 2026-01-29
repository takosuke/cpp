#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

std::string	replace(const std::string& text, const std::string& s1,
		    const std::string& s2)
{
	if (s1.empty())
		return text;

	std::string result;
	size_t lastPos = 0;
	size_t foundPos;

	while ((foundPos = text.find(s1, lastPos)) != std::string::npos)
	{
		result += text.substr(lastPos, foundPos - lastPos);
		result += s2;
		lastPos = foundPos + s2.length();
	}
	result += text.substr(lastPos);
	return result;
}

int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		std::string sauce_filename = argv[1];
		std::string s1 = argv[2];
		std::string s2 = argv[3];

		std::ifstream sauce(argv[1]);
		if (!sauce)
		{
			std::cerr << "ERRUUUR opening " << sauce_filename << std::endl;
			return 1;
		}

		std::stringstream buf;
		buf << sauce.rdbuf();
		std::string text = buf.str();
		sauce.close();

		std::string result = replace(text, s1, s2);
		std::ofstream destiny((sauce_filename + ".replace").c_str());
		if (!destiny)
		{
			std::cerr << "ERRORRR creating output file" << std::endl;
			return 1;
		}
		destiny << result;
		destiny.close();

		std::cout << "Finished replacing " << s1 << " with " << s2 << " in file " << sauce_filename << std::endl;
		return 0;
	}
}
