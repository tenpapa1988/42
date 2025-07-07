/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 13:04:39 by yussaito          #+#    #+#             */
/*   Updated: 2025/07/07 13:04:47 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {
    {
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << sp.shortestSpan() << std::endl; // → 2
        std::cout << sp.longestSpan() << std::endl;  // → 14
    }

    {
        Span big(10000);
        std::vector<int> nums;
        for (int i = 0; i < 10000; ++i)
            nums.push_back(rand());

        big.addRange(nums.begin(), nums.end());

        std::cout << "Shortest span: " << big.shortestSpan() << std::endl;
        std::cout << "Longest span: " << big.longestSpan() << std::endl;
    }

    return 0;
}
