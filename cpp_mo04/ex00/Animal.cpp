/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:59:41 by yussaito          #+#    #+#             */
/*   Updated: 2025/05/06 10:59:42 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal") {
    std::cout << "[Animal] Default constructor called" << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type) {
    std::cout << "[Animal] Copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    std::cout << "[Animal] Copy assignment operator called" << std::endl;
    if (this != &other)
        type = other.type;
    return *this;
}

Animal::~Animal() {
    std::cout << "[Animal] Destructor called" << std::endl;
}

void Animal::makeSound() const {
    std::cout << "* Generic animal sound *" << std::endl;
}

std::string Animal::getType() const {
    return type;
}
