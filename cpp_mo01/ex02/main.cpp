/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 22:23:14 by yussaito          #+#    #+#             */
/*   Updated: 2025/04/16 23:14:08 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main() {
	std::string str = "HI THIS IS BRAIN";

	std::string* stringPTR = &str;
	std::string& stringREF = str;

    std::cout << "Memory address of str:        " << &str << std::endl;
    std::cout << "Memory address held by PTR:   " << stringPTR << std::endl;
    std::cout << "Memory address held by REF:   " << &stringREF << std::endl;

	std::cout << "Value of str:                 " << str << std::endl;
    std::cout << "Value pointed to by PTR:      " << *stringPTR << std::endl;
    std::cout << "Value pointed to by REF:      " << stringREF << std::endl;

	return 0;
}
