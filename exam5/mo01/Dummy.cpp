/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 23:16:30 by ncolomer          #+#    #+#             */
/*   Updated: 2025/07/04 09:30:13 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dummy.hpp"

Dummy::Dummy():
	ATarget("Target Practice Dummy") {}

Dummy::~Dummy() {}

ATarget *Dummy::clone(void) const {
	return (new Dummy(*this));
}
