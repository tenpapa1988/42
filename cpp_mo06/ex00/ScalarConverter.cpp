/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:44:59 by yussaito          #+#    #+#             */
/*   Updated: 2025/06/24 11:42:54 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <climits>
#include <iomanip>
#include <cerrno>
#include <cmath>

static bool isPseudoLiteral(const std::string& str) {
    return str == "nanf" || str == "+inff" || str == "-inff";
}


void ScalarConverter::convert(const std::string& literal) {
    char c = 0;
    int i = 0;
    float f = 0.0f;
    double d = 0.0;

    bool isCharLiteral = (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'');
    if (isCharLiteral) {
        c = literal[1];
        i = static_cast<int>(c);
        f = static_cast<float>(c);
        d = static_cast<double>(c);
    } else if (isPseudoLiteral(literal)) {
        std::string stripped = literal;
        stripped = literal.substr(0, literal.length() - 1);
        d = std::strtod(stripped.c_str(), NULL);
        f = static_cast<float>(d);
    } else {
        char* endptr = NULL;
        errno = 0;
        d = std::strtod(literal.c_str(), &endptr);
        if (*endptr != '\0' && *endptr != 'f') {
            std::cerr << "Invalid input.\n";
            return;
        }
        f = static_cast<float>(d);
        i = static_cast<int>(d);
        c = static_cast<char>(i);
    }

    std::cout << "char: ";
    if (isCharLiteral)
        std::cout << "'" << c << "'\n";
    else if (std::isnan(d) || d < 0 || d > 127)
        std::cout << "impossible\n";
    else if (std::isprint(c))
        std::cout << "'" << c << "'\n";
    else
        std::cout << "Non displayable\n";

    std::cout << "int: ";
    if (std::isnan(d) || d < INT_MIN || d > INT_MAX)
        std::cout << "impossible\n";
    else
        std::cout << i << "\n";

    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f\n";

    std::cout << "double: " << std::fixed << std::setprecision(1) << d << "\n";
}
