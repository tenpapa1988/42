/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 10:59:55 by yussaito          #+#    #+#             */
/*   Updated: 2025/05/02 14:30:00 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main() {
	ScavTrap scav("SC4V-TP");

	scav.attack("Bandit");
	scav.takeDamage(30);
	scav.beRepaired(20);
	scav.guardGate();

	return 0;
}
