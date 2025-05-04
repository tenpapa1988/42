/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 10:59:55 by yussaito          #+#    #+#             */
/*   Updated: 2025/05/04 09:38:29 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main() {
	FragTrap frag("FR4G-TP");

	frag.attack("Enemy");
	frag.takeDamage(42);
	frag.beRepaired(20);
	frag.highFivesGuys();

	return 0;
}
