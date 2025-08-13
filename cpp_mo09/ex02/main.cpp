/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 13:48:32 by yussaito          #+#    #+#             */
/*   Updated: 2025/08/12 10:43:46 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc < 2) {
       std::cerr << "Not enough arguments provided" << std::endl;
       return 1;
   }

    // 1) std::vector
    {
        std::cout << "using std::vector" << std::endl;
        clock_t start = clock();
        std::vector< std::pair<int,int> > vecty;
        std::vector<int> main_chain;
        int additional_value = -1;

        try {
            print_before(argv);
            create_pairs(&vecty, argv, &additional_value);
            sort_pairs(&vecty);
            mergeSort(vecty.begin(), vecty.end(), 0);
            init_main_chain(&main_chain, vecty);
            insert_into_main_chain(vecty, &main_chain, additional_value);
            print_after(main_chain);

            clock_t end = clock();
            std::cout << "Time to process a range of " << main_chain.size()
                      << " elements with std::vector: "
                      << static_cast<double>(end - start) / 1000 << " millisec"
                      << std::endl << std::endl;
        } catch (const std::exception& e) {
            std::cerr << e.what() << '\n';
        }
    }

    // 2) std::deque
    {
        std::cout << "using std::deque" << std::endl;
        clock_t start = clock();
        std::deque< std::pair<int,int> > dequey;
        std::deque<int> main_chain;
        int additional_value = -1;

        try {
            print_before(argv);
            create_pairs2(&dequey, argv, &additional_value);
            sort_pairs2(&dequey);
            mergeSort2(dequey.begin(), dequey.end(), 0);
            init_main_chain2(&main_chain, dequey);
            insert_into_main_chain2(dequey, &main_chain, additional_value);
            print_after2(main_chain);

            clock_t end = clock();
            std::cout << "Time to process a range of " << main_chain.size()
                      << " elements with std::deque: "
                      << static_cast<double>(end - start) / 1000 << " millisec"
                      << std::endl;
        } catch (const std::exception& e) {
            std::cerr << e.what() << '\n';
        }
    }

    return 0;
}
