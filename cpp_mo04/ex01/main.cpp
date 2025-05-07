/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:15:11 by yussaito          #+#    #+#             */
/*   Updated: 2025/05/07 09:27:17 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;

	std::cout << "---- Creating array ----" << std::endl;
	const int size = 4;
	Animal* animals[size];
	for (int k = 0; k < size; ++k) {
		if (k < size / 2)
			animals[k] = new Dog();
		else
			animals[k] = new Cat();
	}

	std::cout << "---- Deleting array ----" << std::endl;
	for (int k = 0; k < size; ++k)
		delete animals[k];

	std::cout << "---- Testing deep copy ----" << std::endl;
	Dog dog1;
	dog1.makeSound();
	Dog dog2 = dog1;
	dog2.makeSound();

	return 0;
}
