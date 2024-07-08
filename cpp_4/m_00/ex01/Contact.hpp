/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:08:46 by joaocard          #+#    #+#             */
/*   Updated: 2024/07/08 16:00:47 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
		
	public:
		Contact() : first_name(""), last_name(""), nickname(""), phone_number(""), darkest_secret("") {};
		Contact(std::string first_name_in, std::string last_name_in, std::string nickname_in, std::string phone_number_in, std::string darkest_secret_in) : first_name(first_name_in), last_name(last_name_in), nickname(nickname_in), phone_number(phone_number_in), darkest_secret(darkest_secret_in) 
		{first_name = first_name_in; last_name = last_name_in; nickname = nickname_in; phone_number = phone_number_in; darkest_secret = darkest_secret_in;};
		~Contact() {std::cout << "Contact destroyed" << std::endl;};
		
		void SetFirstName(std::string first_name_in) { first_name = first_name_in; };
		void SetLastName(std::string last_name_in) { last_name = last_name_in; };
		void SetNickname(std::string nickname_in) { nickname = nickname_in; };
		void SetPhoneNumber(std::string phone_number_in) { phone_number = phone_number_in; };
		void SetDarkestSecret(std::string darkest_secret_in) { darkest_secret = darkest_secret_in; };
		
		std::string GetFirstName() const { return first_name; };
		std::string GetLastName() const { return last_name; };
		std::string GetNickname() const { return nickname; };
		std::string GetPhoneNumber() const { return phone_number; };
		std::string GetDarkestSecret() const { return darkest_secret; };
};
