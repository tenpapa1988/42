/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 12:10:31 by yussaito          #+#    #+#             */
/*   Updated: 2025/04/20 12:46:07 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

std::string Replace::replaceAll(const std::string& input, const std::string& s1, const std::string& s2) {
	if (s1.empty())
		return input;
	
	std::string result;
	size_t pos = 0;
	size_t found;

	while ((found = input.find(s1, pos)) != std::string::npos) {
		result += input.substr(pos, found - pos);
		result += s2;
		pos = found + s1.length();
	}

	result += input.substr(pos);
	return result;
}