/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:08:42 by joaocard          #+#    #+#             */
/*   Updated: 2024/07/09 23:39:30 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	PhoneBook phonebook;
	std::string command;

	while (1)
	{
		std::cout << "Enter a command: ";
		std::getline(std::cin, command);
		for (int i = 0; command[i]; i++)
			command[i] = std::toupper(command[i]);
		if (command == "ADD")
			phonebook.Add();
		else if (command == "SEARCH")
			phonebook.Search();
		else if (command == "EXIT")
		{
			std::cout << "ERASING PHONEBOOK. ALL CONTACTS WILL BE DELETED AND ITS FIELDS LOST." << std::endl;
			std::cout << "PRESS ANY KEY TO CONTINUE" << std::endl;
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			break;
		}
		else
			std::cout << "Invalid command" << std::endl;
	}
	return (0);
}