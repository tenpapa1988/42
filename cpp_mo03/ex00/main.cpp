/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:03:37 by yussaito          #+#    #+#             */
/*   Updated: 2025/04/30 15:44:06 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main() {
	ClapTrap a("Clappy");

	a.attack("Target Dummy");
	a.takeDamage(3);
	a.beRepaired(5);
	a.attack("Another Dummy");
	a.takeDamage(8);
	a.beRepaired(2);
	a.attack("Final Boss");

	return 0;
}