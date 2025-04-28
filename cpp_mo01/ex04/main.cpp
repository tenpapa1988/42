/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 12:10:29 by yussaito          #+#    #+#             */
/*   Updated: 2025/04/20 12:29:39 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"
#include <iostream>
#include <fstream>

int	main(int argc, char **argv) {
	if (argc != 4) {
		std::cerr << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	std::ifstream infile(filename.c_str());
	if (!infile) {
		std::cerr << "Error: could not open input file." << std::endl;
		return 1;
	}

	std::string outputFilename = filename + ".replace";
	std::ofstream outfile(outputFilename.c_str());
	if (!outfile) {
		std::cerr << "Error: could not create output file." << std::endl;
		return 1;
	}

	std::string line;
	while (std::getline(infile, line)) {
		outfile << Replace::replaceAll(line, s1, s2);
		if (!infile.eof())
			outfile << std::endl;
	}

	infile.close();
	outfile.close();

	return 0;
}
