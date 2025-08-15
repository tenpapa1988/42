/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 13:23:08 by yussaito          #+#    #+#             */
/*   Updated: 2025/08/07 09:16:27 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <cstdlib>

RPN::RPN() {}

RPN::RPN(const RPN& other) {
    this->_stack = other._stack;
}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other)
        this->_stack = other._stack;
    return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(const std::string& token) const {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

bool RPN::isNumber(const std::string& token) const {
    return token.length() == 1 && std::isdigit(token[0]);
}

void RPN::applyOperator(const std::string& op) {
    if (_stack.size() < 2)
        throw std::runtime_error("Error");

    int rhs = _stack.top();
	_stack.pop();

    int lhs = _stack.top();
	_stack.pop();
    int result;

    if (op == "+")
        result = lhs + rhs;
    else if (op == "-")
        result = lhs - rhs;
    else if (op == "*")
        result = lhs * rhs;
    else if (op == "/") {
        if (rhs == 0)
            throw std::runtime_error("Error");
        result = lhs / rhs;
    } else {
        throw std::runtime_error("Error");
    }

    _stack.push(result);
}

int RPN::evaluate(const std::string& expression) {
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (isNumber(token)) {
            _stack.push(std::atoi(token.c_str()));
        } else if (isOperator(token)) {
            applyOperator(token);
        } else {
            throw std::runtime_error("Error");
        }
    }

    if (_stack.size() != 1)
        throw std::runtime_error("Error");

    return _stack.top();
}
