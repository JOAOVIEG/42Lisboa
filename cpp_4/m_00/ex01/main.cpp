/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:08:42 by joaocard          #+#    #+#             */
/*   Updated: 2024/07/08 18:35:01 by joaocard         ###   ########.fr       */
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
		if (command == "ADD")
			phonebook.Add();
		// else if (command == "SEARCH")
		// 	phonebook.Search();
		// else if (command == "EXIT")
		// {
		// 	phonebook.Exi();
		// 	break;
		// }
		else
			std::cout << "Invalid command" << std::endl;
	}
	return (0);
}