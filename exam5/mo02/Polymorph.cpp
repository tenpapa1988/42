/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polymorph.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 12:49:28 by ncolomer          #+#    #+#             */
/*   Updated: 2025/07/04 09:41:38 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polymorph.hpp"

Polymorph::Polymorph():
	ASpell("Polymorph", "turned into a critter") {}

Polymorph::~Polymorph() {}

ASpell *Polymorph::clone(void) const {
	return (new Polymorph(*this));
}
