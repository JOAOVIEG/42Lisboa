/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:11:00 by joaocard          #+#    #+#             */
/*   Updated: 2024/07/08 17:15:45 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::Add()
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
	
	if (PhoneBook::contact_count >= 8)
		CheckLastContact();
	else
	{
		std::cout << "Enter first name: ";
		std::getline(std::cin, first_name);
		PhoneBook::contacts[PhoneBook::contact_count].SetFirstName(first_name);

		std::cout << "Enter last name: ";
		std::getline(std::cin, last_name);
		PhoneBook::contacts[PhoneBook::contact_count].SetLastName(last_name);

		std::cout << "Enter nickname: ";
		std::getline(std::cin, nickname);
		PhoneBook::contacts[PhoneBook::contact_count].SetNickname(nickname);

		std::cout << "Enter phone number: ";
		std::getline(std::cin, phone_number);
		PhoneBook::contacts[PhoneBook::contact_count].SetPhoneNumber(phone_number);

		std::cout << "Enter darkest secret ;P : ";
		std::getline(std::cin, darkest_secret);
		PhoneBook::contacts[PhoneBook::contact_count].SetDarkestSecret(darkest_secret);
		PhoneBook::contact_count++;
	}

}

void	PhoneBook::CheckLastContact()
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
	
	std::cout << "You reached the maximum amount of contacts. You are about to replace the last contact << std::endl";
	
	std::cout << "Enter first name: ";
	std::getline(std::cin, first_name);
	PhoneBook::contacts[7].SetFirstName(first_name);

	std::cout << "Enter last name: ";
	std::getline(std::cin, last_name);
	PhoneBook::contacts[7].SetLastName(last_name);

	std::cout << "Enter nickname: ";
	std::getline(std::cin, nickname);
	PhoneBook::contacts[7].SetNickname(nickname);
	
	std::cout << "Enter phone number: ";
	std::getline(std::cin, phone_number);
	PhoneBook::contacts[7].SetPhoneNumber(phone_number);

	std::cout << "Enter darkest secret ;P : ";
	std::getline(std::cin, darkest_secret);
	PhoneBook::contacts[7].SetDarkestSecret(darkest_secret);
}
