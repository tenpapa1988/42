/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 12:59:09 by yussaito          #+#    #+#             */
/*   Updated: 2025/07/07 13:53:11 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"


int main() {
   try {
       std::vector<int> vec;
       for (int i = 0; i < 10; ++i)
           vec.push_back(i);

       std::vector<int>::iterator it = easyfind(vec, 5);
       std::cout << "Found: " << *it << std::endl;

       easyfind(vec, 42);
   } catch (const std::exception& e) {
       std::cerr << e.what() << std::endl;
   }

   try {
       std::list<int> lst;
       lst.push_back(3);
       lst.push_back(7);
       lst.push_back(9);

       std::list<int>::iterator it = easyfind(lst, 7);
       std::cout << "Found: " << *it << std::endl;

       easyfind(lst, 100);
   } catch (const std::exception& e) {
       std::cerr << e.what() << std::endl;
   }

   return 0;
}
