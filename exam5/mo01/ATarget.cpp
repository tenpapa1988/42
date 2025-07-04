/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 23:26:40 by ncolomer          #+#    #+#             */
/*   Updated: 2025/07/04 09:30:45 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ATarget.hpp"

ATarget::ATarget():
	type() {}

ATarget::ATarget(std::string const &type):
	type(type) {}

ATarget::ATarget(ATarget const &other):
	type(other.type) {}

ATarget::~ATarget() {}

ATarget &ATarget::operator=(ATarget const &other) {
	this->type = other.type;
	return (*this);
}

std::string const &ATarget::getType(void) const {
	return (this->type);
}

void ATarget::getHitBySpell(ASpell const &spell) const {
	std::cout << type << " has been " << spell.getEffects() << "!" << std::endl;
}
