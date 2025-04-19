/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 09:53:07 by yussaito          #+#    #+#             */
/*   Updated: 2025/04/16 10:25:36 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
	if (N <= 0)
		return NULL;
	
	Zombie* horde = new Zombie[N];
	int	i = 0;
	while (i < N) {
		horde[i].setName(name);
		i++;
	}
	return horde;
}
