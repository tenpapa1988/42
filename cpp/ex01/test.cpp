// Contact.hpp
#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iomanip>
#include <iostream>

class Contact {
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

public:
    Contact();
    void setContact();
    void displaySummary(int index) const;
    void displayFull() const;
    bool isEmpty() const;
};

#endif


// Contact.cpp
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


// PhoneBook.hpp
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
    Contact contacts[8];
    int contactCount;
    int oldestIndex;

public:
    PhoneBook();
    void addContact();
    void searchContacts() const;
};

#endif


// PhoneBook.cpp
#include "PhoneBook.hpp"
#include <iostream>
#include <limits>

PhoneBook::PhoneBook() : contactCount(0), oldestIndex(0) {}

void PhoneBook::addContact() {
    if (contactCount < 8) {
        contacts[contactCount].setContact();
        contactCount++;
    } else {
        std::cout << "PhoneBook full, replacing oldest contact." << std::endl;
        contacts[oldestIndex].setContact();
        oldestIndex = (oldestIndex + 1) % 8;
    }
}

void PhoneBook::searchContacts() const {
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;

    for (int i = 0; i < contactCount; ++i) {
        contacts[i].displaySummary(i);
    }

    std::cout << "Enter index to display details: ";
    int index;
    std::cin >> index;

    if (std::cin.fail() || index < 0 || index >= contactCount) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid index." << std::endl;
        return;
    }

    std::cin.ignore();
    contacts[index].displayFull();
}


// main.cpp
#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main() {
    PhoneBook phoneBook;
    std::string command;

    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);

        if (command == "ADD") {
            phoneBook.addContact();
        } else if (command == "SEARCH") {
            phoneBook.searchContacts();
        } else if (command == "EXIT") {
            break;
        } else {
            std::cout << "Unknown command. Try again." << std::endl;
        }
    }

    return 0;
}



