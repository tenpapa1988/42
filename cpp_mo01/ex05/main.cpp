/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:48:42 by yussaito          #+#    #+#             */
/*   Updated: 2025/04/22 16:08:38 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int	main() {
	Harl harl;

	std::cout << "=== DEBUG ===" << std::endl;
	harl.complain("DEGUG");

	std::cout << "\n=== INFO ===" << std::endl;
	harl.complain("INFO");

	std::cout << "\n=== WARNING ===" << std::endl;
	harl.complain("WARNING");

	std::cout << "\n=== ERROR ===" << std::endl;
	harl.complain("WARNING");

	std::cout << "\n=== UNKNOWN ===" << std::endl;
	harl.complain("WHATEVER");

	return 0;
}