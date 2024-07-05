/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:50:34 by joaocard          #+#    #+#             */
/*   Updated: 2024/07/04 18:32:26 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include "Contact.hpp"


class PhoneBook
{
	private:
		Contact contacts[8];
		int contact_count;
		void print_contact(Contact contact);
		void print_contact_list();
		void add_contact();
		void search_contact();
	public:
		PhoneBook() : contact_count(0) {};
		~PhoneBook() {};
		void run();
};

#endif
