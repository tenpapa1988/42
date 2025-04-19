/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 09:52:54 by yussaito          #+#    #+#             */
/*   Updated: 2025/04/16 10:20:03 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int	main() {
	int	numZombies = 5;
	Zombie* horde = zombieHorde(numZombies, "Zombo");

	if (horde != NULL) {
		int	i = 0;
		while (i < numZombies) {
			horde[i].announce();
			i++;
		}
		delete[] horde;
	}
	return 0;
}
