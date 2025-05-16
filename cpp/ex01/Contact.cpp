/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 05:18:53 by yussaito          #+#    #+#             */
/*   Updated: 2025/05/17 08:53:03 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}

void Contact::setContact() {
    while (true) {
        std::cout << "Enter first name: ";
        if (!std::getline(std::cin, firstName)) {
            if (std::cin.eof()) {
                std::cout << "\nEOF detected. Exiting input." << std::endl;
                std::exit(0);
            }
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        std::cout << "Enter last name: ";
        if (!std::getline(std::cin, lastName)) {
            if (std::cin.eof()) {
                std::cout << "\nEOF detected. Exiting input." << std::endl;
                std::exit(0);
            }
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        std::cout << "Enter nickname: ";
        if (!std::getline(std::cin, nickname)) {
            if (std::cin.eof()) {
                std::cout << "\nEOF detected. Exiting input." << std::endl;
                std::exit(0);
            }
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        std::cout << "Enter phone number: ";
        if (!std::getline(std::cin, phoneNumber)) {
            if (std::cin.eof()) {
                std::cout << "\nEOF detected. Exiting input." << std::endl;
                std::exit(0);
            }
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        std::cout << "Enter darkest secret: ";
        if (!std::getline(std::cin, darkestSecret)) {
            if (std::cin.eof()) {
                std::cout << "\nEOF detected. Exiting input." << std::endl;
                std::exit(0);
            }
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (firstName.empty() || lastName.empty() || nickname.empty() ||
            phoneNumber.empty() || darkestSecret.empty()) {
            std::cout << "Error: All fields must be filled." << std::endl;
            continue;
        }

        break;
    }
}

void Contact::displaySummary(int index) const {
    std::cout << std::setw(10) << index << "|";

    std::string fields[3] = {firstName, lastName, nickname};
    for (int i = 0; i < 3; ++i) {
        if (fields[i].length() > 10)
            std::cout << std::setw(10) << fields[i].substr(0, 9) + ".";
        else
            std::cout << std::setw(10) << fields[i];
        std::cout << "|";
    }
    std::cout << std::endl;
}

void Contact::displayFull() const {
    std::cout << "First name: " << firstName << std::endl;
    std::cout << "Last name: " << lastName << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone number: " << phoneNumber << std::endl;
    std::cout << "Darkest secret: " << darkestSecret << std::endl;
}
