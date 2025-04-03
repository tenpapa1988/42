/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 05:18:53 by yussaito          #+#    #+#             */
/*   Updated: 2025/04/03 05:19:31 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}

void Contact::setContact() {
    std::cout << "Enter first name: ";
    std::getline(std::cin, firstName);
    std::cout << "Enter last name: ";
    std::getline(std::cin, lastName);
    std::cout << "Enter nickname: ";
    std::getline(std::cin, nickname);
    std::cout << "Enter phone number: ";
    std::getline(std::cin, phoneNumber);
    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, darkestSecret);

    if (firstName.empty() || lastName.empty() || nickname.empty() || phoneNumber.empty() || darkestSecret.empty()) {
        std::cout << "Error: All fields must be filled." << std::endl;
        setContact();
    }
}

bool Contact::isEmpty() const {
    return firstName.empty();
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
