/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 14:33:02 by joaocard          #+#    #+#             */
/*   Updated: 2024/08/14 15:30:37 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int ac, char **av){
	if (ac != 4){
		std::cout << "Invalid number of arguments" << std::endl;
		return 1;
	}
	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];
	
	std::ifstream inFile(filename.c_str());
	if (!inFile.is_open()){
		std::cout << "File not found" << std::endl;
		return 2;
	}
	std::ofstream outFile((filename + ".replace").c_str());
	if (!outFile.is_open()){
		std::cout << "Error creating file" << std::endl;
		return 3;
	}
	std::string line;
	while (std::getline(inFile, line))
	{
		std::string newLine;
		size_t pos = 0;
		size_t startPos = 0;
		while ((pos = line.find(s1, startPos)) != std::string::npos)
		{
			newLine.append(line, startPos, pos - startPos);
			newLine.append(s2);
			startPos = pos + s1.length();
		}
		newLine.append(line, startPos, std::string::npos);
	}
	inFile.close();
	outFile.close();
}