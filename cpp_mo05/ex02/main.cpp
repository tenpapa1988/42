/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:15:11 by yussaito          #+#    #+#             */
/*   Updated: 2025/06/18 13:26:58 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>

int main() {
    std::srand(std::time(0));  // Robotomy 用の乱数初期化

    try {
        Bureaucrat alice("Alice", 1);
        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm robot("Marvin");
        PresidentialPardonForm pardon("Ford");

        alice.signForm(shrub);
        alice.signForm(robot);
        alice.signForm(pardon);

        alice.executeForm(shrub);
        alice.executeForm(robot);
        alice.executeForm(pardon);
    }
    catch (std::exception& e) {
        std::cerr << "Exception caught in main: " << e.what() << std::endl;
    }

    return 0;
}

