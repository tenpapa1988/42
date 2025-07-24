/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:15:11 by yussaito          #+#    #+#             */
/*   Updated: 2025/07/25 08:17:48 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    Intern someRandomIntern;
    AForm* form;

    const std::string formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon",
        "invalid form"
    };

    for (int i = 0; i < 4; ++i) {
        std::cout << "Requesting form: " << formNames[i] << std::endl;
        form = someRandomIntern.makeForm(formNames[i], "TestTarget");

        if (form) {
            Bureaucrat high("HighRanker", 1);
            try {
                form->beSigned(high);
                high.executeForm(*form);
            } catch (std::exception& e) {
                std::cerr << "Exception: " << e.what() << std::endl;
            }
            delete form;
        }
        std::cout << std::endl;
    }

    return 0;
}
