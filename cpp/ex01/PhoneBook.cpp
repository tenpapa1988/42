/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 01:56:37 by yussaito          #+#    #+#             */
/*   Updated: 2025/05/14 08:07:17 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <limits>

PhoneBook::PhoneBook() : contactCount(0), oldestIndex(0) {}

void	PhoneBook::addContact() {
	if (contactCount < 8) {
		contacts[contactCount].setContact();
		contactCount++;
	} else {
		std::cout << "PhoneBook is full, replacing oldest contact." << std::endl;
		contacts[oldestIndex].setContact();
		oldestIndex = (oldestIndex + 1) % 8;
	}
}

void	PhoneBook::searchContacts() const {
	std::cout << std::setw(10) << "Index" << "|"
			  << std::setw(10) << "First Name" << "|"
			  << std::setw(10) << "Last Name" << "|"
			  << std::setw(10) << "Nickname" << std::endl;
	
	for (int i = 0; i < contactCount; ++i) {
		contacts[i].displaySummary(i);
	}

	std::cout << "Enter index to display details: ";
	int	index;
	std::cin >> index;

	if (std::cin.fail() || index < 0 || index >= contactCount) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invvalid index." << std::endl;
		return;
	}
	std::cin.ignore();
	contacts[index].displayFull();
}