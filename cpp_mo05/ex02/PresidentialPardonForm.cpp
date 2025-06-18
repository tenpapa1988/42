/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:15:11 by yussaito          #+#    #+#             */
/*   Updated: 2025/06/18 13:04:56 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("PresidentialPardonForm", 25, 5), target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
    if (!getIsSigned())
        throw NotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();

    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
