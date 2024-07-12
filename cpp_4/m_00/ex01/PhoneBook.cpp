/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:11:00 by joaocard          #+#    #+#             */
/*   Updated: 2024/07/12 13:48:25 by joaocard         ###   ########.fr       */
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
		if (first_name.empty()) {std::cout << "Invalid first name" << std::endl; return;}
		else 					{PhoneBook::contacts[PhoneBook::contact_count].SetFirstName(first_name);}
		

		std::cout << "Enter last name: ";
		std::getline(std::cin, last_name);
		if (last_name.empty()) {std::cout << "Invalid last name" << std::endl; return;}
		else				   {PhoneBook::contacts[PhoneBook::contact_count].SetLastName(last_name);}

		std::cout << "Enter nickname: ";
		std::getline(std::cin, nickname);
		if (nickname.empty()) {std::cout << "Invalid nickname" << std::endl; return;}
		else 				  {PhoneBook::contacts[PhoneBook::contact_count].SetNickname(nickname);}

		std::cout << "Enter phone number: ";
		std::getline(std::cin, phone_number);
		if (IsNumber(phone_number) && !phone_number.empty())
			PhoneBook::contacts[PhoneBook::contact_count].SetPhoneNumber(phone_number);
		else {std::cout << "Invalid phone number" << std::endl; return;}

		std::cout << "Enter darkest secret ;P : ";
		std::getline(std::cin, darkest_secret);
		if (darkest_secret.empty()) {std::cout << "Invalid darkest secret" << std::endl; return;}
		else 						{PhoneBook::contacts[PhoneBook::contact_count].SetDarkestSecret(darkest_secret);}
		
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
	
	std::cout << "You reached the maximum amount of contacts. You are about to replace the last contact" << std::endl;
	
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

bool	PhoneBook::IsNumber(std::string str)
{
	for (int i = 0; str[i]; i++)
	{
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

void	PhoneBook::Search()
{
	int index;
	std::string input;
	
	for (int i = 0; i < PhoneBook::contact_count; i++)
	{
		std::cout << std::setw(10) << i << "|";
		if (PhoneBook::contacts[i].GetFirstName().length() > 10)
			std::cout << PhoneBook::contacts[i].GetFirstName().substr(0, 9) << ".|";
		else
			std::cout << std::setw(10) << PhoneBook::contacts[i].GetFirstName() << "|";
		if (PhoneBook::contacts[i].GetLastName().length() > 10)
			std::cout << PhoneBook::contacts[i].GetLastName().substr(0, 9) << ".|";
		else
			std::cout << std::setw(10) << PhoneBook::contacts[i].GetLastName() << "|";
		if (PhoneBook::contacts[i].GetNickname().length() > 10)
			std::cout << PhoneBook::contacts[i].GetNickname().substr(0, 9) << ".|";
		else
		std::cout << std::setw(10) << PhoneBook::contacts[i].GetNickname() << std::endl;
	}
	std::cout << "ENTER CONTACT INDEX OR ENTER TO GO BACK TO MENU: ";
	while (std::getline(std::cin, input))
	{
		if (input.empty())
		{
			std::cout << "RETURNING TO MENU" << std::endl;	
			break;
		}
		std::istringstream string(input);
		if (string >> index)
		{
			if (index >= 0 && index < PhoneBook::contact_count)
			{
				// Display contact information
				std::cout << "FIRST NAME    | " << PhoneBook::contacts[index].GetFirstName() << std::endl;
				std::cout << "LAST NAME     | " << PhoneBook::contacts[index].GetLastName() << std::endl;
				std::cout << "NICKNAME      | " << PhoneBook::contacts[index].GetNickname() << std::endl;
				std::cout << "PHONE NUMBER  | " << PhoneBook::contacts[index].GetPhoneNumber() << std::endl;
				std::cout << "DARKEST SECRET| " << PhoneBook::contacts[index].GetDarkestSecret() << std::endl;
				std::cout << "ENTER CONTACT INDEX OR ENTER TO GO BACK TO MENU: ";
			}
			else
				std::cout << "INVALID INDEX. SELECT A VALID INDEX OR PRESS ENTER TO GO BACK TO MENU: ";
		}
		else
			std::cout << "INVALID INPUT. PLEASE ENTER A NUMBER OR PRESS ENTER TO GO BACK TO MENU: ";
	}
}
