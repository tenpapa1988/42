/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:00:50 by yussaito          #+#    #+#             */
/*   Updated: 2025/06/26 15:00:52 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

Base* generate();
void identify(Base* p);
void identify(Base& p);

int main() {
    Base* obj = generate();
    std::cout << "Pointer identification: ";
    identify(obj);

    std::cout << "Reference identification: ";
    identify(*obj);

    delete obj;
    return 0;
}
