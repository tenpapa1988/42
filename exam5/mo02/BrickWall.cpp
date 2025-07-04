/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BrickWall.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 12:59:17 by ncolomer          #+#    #+#             */
/*   Updated: 2025/07/04 09:40:32 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BrickWall.hpp"

BrickWall::BrickWall():
    ATarget("Inconspicuous Red-brick Wall") {}

BrickWall::~BrickWall() {}

ATarget *BrickWall::clone(void) const {
	return (new BrickWall(*this));
}
