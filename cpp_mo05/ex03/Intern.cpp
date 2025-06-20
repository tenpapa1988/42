/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:15:11 by yussaito          #+#    #+#             */
/*   Updated: 2025/06/20 15:14:01 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string& name, const std::string& target) {
    const std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm* forms[3] = {
        new ShrubberyCreationForm(target),
        new RobotomyRequestForm(target),
        new PresidentialPardonForm(target)
    };

    for (int i = 0; i < 3; ++i) {
        if (name == formNames[i]) {
            std::cout << "Intern creates " << name << std::endl;
            for (int j = 0; j < 3; ++j)
                if (j != i) delete forms[j];
            return forms[i];
        }
    }

    std::cout << "Error: Unknown form name \"" << name << "\"" << std::endl;
    for (int i = 0; i < 3; ++i)
        delete forms[i];
    return NULL;
}
