/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 01:53:19 by yussaito          #+#    #+#             */
/*   Updated: 2025/05/17 08:54:34 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int	main() {
	PhoneBook phoneBook;
	std::string command;
	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command)) {
			std::cout << "\nEOF detected. Exiting." << std::endl;
			break;
		}

		if (command == "ADD") {
			phoneBook.addContact();
		} else if (command == "SEARCH") {
			phoneBook.searchContacts();
		} else if (command == "EXIT") {
			break;
		} else {
			std::cout << "Unknown Command. Try Again." << std::endl;
		}
	}
	return 0;
}