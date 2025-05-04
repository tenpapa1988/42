/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 10:59:45 by yussaito          #+#    #+#             */
/*   Updated: 2025/05/04 09:35:13 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() {
	name = "Unnamed_Frag";
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap parameter constructor called for " << name << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << "FragTrap assignment operator called" << std::endl;
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called for " << name << std::endl;
}

void FragTrap::attack(const std::string& target) {
	if (energyPoints <= 0 || hitPoints <= 0) {
		std::cout << "FragTrap " << name << " can't attack. No energy or hit points left!" << std::endl;
		return;
	}
	--energyPoints;
	std::cout << "FragTrap " << name << " attacks " << target
	          << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << name << " requests a positive high five! ✋" << std::endl;
}
