/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 13:23:10 by yussaito          #+#    #+#             */
/*   Updated: 2025/07/11 13:23:20 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

class RPN {
public:
    RPN();
    ~RPN();

    int evaluate(const std::string& expression);

private:
    std::stack<int> _stack;

    bool isOperator(const std::string& token) const;
    bool isNumber(const std::string& token) const;
    void applyOperator(const std::string& op);
};

#endif
