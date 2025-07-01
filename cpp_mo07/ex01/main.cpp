/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 11:26:00 by yussaito          #+#    #+#             */
/*   Updated: 2025/07/01 11:50:50 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

template<typename T>
void print(T& x) {
    std::cout << x << std::endl;
}

template<typename T>
void printConst(const T& x) {
    std::cout << x << std::endl;
}

void increment(int& x) {
    ++x;
}

int main() {
    int intArr[5] = {1, 2, 3, 4, 5};
    iter(intArr, 5, increment);
    iter(intArr, 5, print<int>);

    const std::string strArr[3] = {"hello", "world", "cpp"};
    iter(strArr, 3, printConst<std::string>); 

    return 0;
}
