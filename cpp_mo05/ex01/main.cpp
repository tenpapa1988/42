/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:15:11 by yussaito          #+#    #+#             */
/*   Updated: 2025/06/14 12:36:03 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat a("Alice", 30);
        Form f("Application", 50, 40);

        std::cout << f << std::endl;
        a.signForm(f);
        std::cout << f << std::endl;

        Bureaucrat b("Bob", 60);
        b.signForm(f);

    } catch (std::exception& e) {
        std::cerr << "Main exception: " << e.what() << std::endl;
    }

    return 0;
}

