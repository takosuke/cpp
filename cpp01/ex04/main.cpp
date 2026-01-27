#include <fstream>
#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		std::string argsauce = argv[1];
		std::string argdestiny = argsauce.append(".replace");
//		std::string s1 = argv[2];
//		std::string s2 = argv[3];
		std::ifstream sauce(argv[], std::ios::binary);
		std::ofstream destiny(argdestiny.c_str(), std::ios::binary);
		if (!sauce.is_open() || !destiny.is_open())
		{
			std::cerr << "ERRORRR opening files" << std::endl;
			return 1;
		}
		destiny << sauce.rdbuf();

		sauce.close();
		destiny.close();
	}
}
