#include <string>
#include <iostream>
#include "PhoneBook.hpp"

void printWelcome(void)
{
	std::cout << std::endl;
	std::cout << COLOR_CYAN << "     ______________" << COLOR_RESET << std::endl;
	std::cout << COLOR_CYAN << "    |  __________  |" << COLOR_RESET << std::endl;
	std::cout << COLOR_CYAN << "    | |" << COLOR_GREEN << "  PHONE   " << COLOR_CYAN << "| |" << COLOR_RESET << std::endl;
	std::cout << COLOR_CYAN << "    | |" << COLOR_GREEN << "   BOOK   " << COLOR_CYAN << "| |" << COLOR_RESET << std::endl;
	std::cout << COLOR_CYAN << "    | |__________| |" << COLOR_RESET << std::endl;
	std::cout << COLOR_CYAN << "    |   ________   |" << COLOR_RESET << std::endl;
	std::cout << COLOR_CYAN << "    |  |" << COLOR_WHITE << "1" << COLOR_CYAN << "||" << COLOR_WHITE << "2" << COLOR_CYAN << "||" << COLOR_WHITE << "3" << COLOR_CYAN << "|  |" << COLOR_RESET << std::endl;
	std::cout << COLOR_CYAN << "    |  |" << COLOR_WHITE << "4" << COLOR_CYAN << "||" << COLOR_WHITE << "5" << COLOR_CYAN << "||" << COLOR_WHITE << "6" << COLOR_CYAN << "|  |" << COLOR_RESET << std::endl;
	std::cout << COLOR_CYAN << "    |  |" << COLOR_WHITE << "7" << COLOR_CYAN << "||" << COLOR_WHITE << "8" << COLOR_CYAN << "||" << COLOR_WHITE << "9" << COLOR_CYAN << "|  |" << COLOR_RESET << std::endl;
	std::cout << COLOR_CYAN << "    |  |" << COLOR_WHITE << "*" << COLOR_CYAN << "||" << COLOR_WHITE << "0" << COLOR_CYAN << "||" << COLOR_WHITE << "#" << COLOR_CYAN << "|  |" << COLOR_RESET << std::endl;
	std::cout << COLOR_CYAN << "    |__|________|__|" << COLOR_RESET << std::endl;
	std::cout << std::endl;
	std::cout << COLOR_YELLOW;
	std::cout << "    _____  _                      ____              _    " << std::endl;
	std::cout << "   |  __ \\| |                    |  _ \\            | |   " << std::endl;
	std::cout << "   | |__) | |__   ___  _ __   ___| |_) | ___   ___ | | __" << std::endl;
	std::cout << "   |  ___/| '_ \\ / _ \\| '_ \\ / _ \\  _ < / _ \\ / _ \\| |/ /" << std::endl;
	std::cout << "   | |    | | | | (_) | | | |  __/ |_) | (_) | (_) |   < " << std::endl;
	std::cout << "   |_|    |_| |_|\\___/|_| |_|\\___|____/ \\___/ \\___/|_|\\_\\" << std::endl;
	std::cout << COLOR_RESET << std::endl;
}

void printGoodbye(void)
{
	std::cout << std::endl;
	std::cout << COLOR_MAGENTA;
	std::cout << "   ____             _ _                _ " << std::endl;
	std::cout << "  / ___| ___   ___ | | | __ _ _   _| |" << std::endl;
	std::cout << " | |  _ / _ \\ / _ \\| | |/ _` | | | | |" << std::endl;
	std::cout << " | |_| | (_) | (_) | | | (_| | |_| |_|" << std::endl;
	std::cout << "  \\____|\\___/ \\___/|_|_|\\__,_|\\__, (_)" << std::endl;
	std::cout << "                              |___/   " << std::endl;
	std::cout << COLOR_RESET << std::endl;
}

void printMenu(void)
{
	std::cout << COLOR_BOLD << COLOR_GREEN << "============================" << COLOR_RESET << std::endl;
	std::cout << COLOR_GREEN << "  " << COLOR_WHITE << "ADD" << COLOR_GREEN << "    - Add a contact" << COLOR_RESET << std::endl;
	std::cout << COLOR_GREEN << "  " << COLOR_WHITE << "SEARCH" << COLOR_GREEN << " - Search contacts" << COLOR_RESET << std::endl;
	std::cout << COLOR_GREEN << "  " << COLOR_WHITE << "EXIT" << COLOR_GREEN << "   - Exit phonebook" << COLOR_RESET << std::endl;
	std::cout << COLOR_BOLD << COLOR_GREEN << "============================" << COLOR_RESET << std::endl;
	std::cout << COLOR_YELLOW << "Enter command: " << COLOR_RESET;
}

int	main(void)
{
	std::string command;
	PhoneBook phoneBook;

	printWelcome();
	while (true)
	{
		printMenu();
		if (!std::getline(std::cin, command))
			break;
		if (command == "ADD")
			phoneBook.addContact();
		else if (command == "SEARCH")
			phoneBook.searchContact();
		else if (command == "EXIT")
			break;
		else if (!command.empty())
			std::cout << COLOR_RED << "Unknown command: " << command << COLOR_RESET << std::endl;
	}
	printGoodbye();
	return 0;
}
