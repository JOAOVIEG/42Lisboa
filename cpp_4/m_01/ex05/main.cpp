/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 19:02:41 by joaocard          #+#    #+#             */
/*   Updated: 2024/08/15 10:11:11 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <sstream>


int main()
{
	int n_tests;
	std::string tests;
	
	std::cout << "Insert the number of tests: " << std::endl;
	std::getline(std::cin, tests);
	
	std::istringstream iss(tests);
	iss >> n_tests;

	Harl harl;
	
	std::cout << "Valid answers are DEBUG, INFO, WARNING, ERROR." << std::endl << std::endl;
	for (int i = 0; i < n_tests; i++)
	{
		std::string complain;
		std::cout <<"Whats your complain Harl?: " << std::endl;
		std::getline(std::cin, complain);
		if (check_input(complain) == false)
		{
			std::cout << "Wrong input: Valid answers are DEBUG, INFO, WARNING, ERROR." << std::endl << std::endl; 
			i--;
		}
		else
			harl.complain(complain);
	}
	return (0);
}