/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 01:32:39 by yussaito          #+#    #+#             */
/*   Updated: 2025/04/16 09:11:53 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void	randomChump(std::string name);

int	main() {
	std::cout << "=== Heap Zombie ===" << std::endl;
	Zombie* heapZombie = newZombie("Heapster");
	heapZombie->announce();
	delete heapZombie;

	std::cout << "\n=== Stack Zombie ===" << std::endl;
	randomChump("Stacko");

	return 0;
}
