/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:03:44 by yussaito          #+#    #+#             */
/*   Updated: 2025/04/30 15:43:25 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: name("Unnamed"), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
	: name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap parameter constructor called for " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	*this = other;
	std::cout << "ClapTrap copy constructor called for " << name << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	if (this != &other) {
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	std::cout << "ClapTrap assignment operator called for " << name << std::endl;
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destructor called for " << name << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (energyPoints <= 0 || hitPoints <= 0) {
		std::cout << "ClapTrap " << name << " can't attack. No energy or hit points left!" << std::endl;
		return;
	}
	--energyPoints;
	std::cout << "ClapTrap " << name << " attacks " << target
	          << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	hitPoints -= amount;
	if (hitPoints < 0)
		hitPoints = 0;
	std::cout << "ClapTrap " << name << " takes " << amount
	          << " points of damage! Remaining HP: " << hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (energyPoints <= 0 || hitPoints <= 0) {
		std::cout << "ClapTrap " << name << " can't be repaired. No energy or hit points left!" << std::endl;
		return;
	}
	--energyPoints;
	hitPoints += amount;
	std::cout << "ClapTrap " << name << " repairs itself for "
	          << amount << " hit points! Current HP: " << hitPoints << std::endl;
}
