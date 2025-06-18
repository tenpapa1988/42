/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:15:09 by yussaito          #+#    #+#             */
/*   Updated: 2025/06/18 12:59:25 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <stdexcept>
#include <string>

class Bureaucrat;

class AForm {
private:
	const std::string name;
	bool isSigned;
	const int gradeToSign;
	const int gradeToExecute;

public:
	AForm();
	AForm(const std::string& name, int gradeToSign, int gradeToExecute);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	virtual ~AForm();

	const std::string& getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	void beSigned(const Bureaucrat& b);

	virtual void execute(Bureaucrat const& executor) const = 0;

	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw();
	};

	class NotSignedException : public std::exception {
	public:
		const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif
