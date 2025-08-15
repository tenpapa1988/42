/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 13:48:32 by yussaito          #+#    #+#             */
/*   Updated: 2025/08/15 12:33:59 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char** argv) {
    PmergeMe pmerge;
    
    // Parse and validate input
    if (!pmerge.parseInput(argc, argv)) {
        return 1;
    }
    
    // Execute sorting and display results
    pmerge.execute();
    
    return 0;
}
