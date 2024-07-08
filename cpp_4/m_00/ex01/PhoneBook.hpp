/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:50:34 by joaocard          #+#    #+#             */
/*   Updated: 2024/07/08 18:34:47 by joaocard         ###   ########.fr       */
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
		Contact 	contacts[8];
		int			contact_count;
		void		CheckLastContact();
	public:
		PhoneBook() : contact_count(0) {};
		~PhoneBook() {std::cout<<"PhoneBook destroyed"<<std::endl;};
		void Add();
		// void Search();
		// void Exi();
};

#endif
