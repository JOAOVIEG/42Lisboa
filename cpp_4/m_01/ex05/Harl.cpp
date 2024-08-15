/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 19:02:38 by joaocard          #+#    #+#             */
/*   Updated: 2024/08/15 10:20:56 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	func[0].function = &Harl::debug;
	func[0].level = "DEBUG";
	
	func[1].function = &Harl::info;
	func[1].level = "INFO";

	func[2].function =  &Harl::warning;
	func[2].level = "WARNING";

	func[3].function = &Harl::error;
	func[3].level = "ERROR";
}

Harl::~Harl()
{
	std::cout << "Harl destructor called." << std::endl;	
}

void	Harl::complain(std::string level) {
	for (int i = 0; i < 4; ++i)
	{
		if (func[i].level == level)
		{
			HarlMbFun complain = func[i].function;
			(this->*complain)();
			break;
		}
	}
}

void	Harl::debug(void) {
	std::cout << "I love having extra bacon for my"
	"7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" <<std::endl;
}

void	Harl::info(void) {
	std::cout << "I cannot believe adding extra bacon costs more money."
	"You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" <<std::endl;
}

void	Harl::warning(void) {
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for"
	"years whereas you started working here since last month." <<std::endl;
}

void	Harl::error(void) {
	std::cout << "This is unacceptable! I want to speak to the manager now." <<std::endl;
}

bool	check_input(const std::string& input)
{
	const std::string valid_answers[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4; i++) {
        if (input == valid_answers[i]) {
            return true;
        }
    }
    return false;
}