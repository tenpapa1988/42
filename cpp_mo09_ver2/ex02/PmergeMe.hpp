/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 13:48:41 by yussaito          #+#    #+#             */
/*   Updated: 2025/08/18 14:58:17 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <sstream>
#include <ctime>
#include <sys/time.h>

class PmergeMe {
private:
    std::vector<int> _inputData;
    
    // Jacobsthal sequence generation (using basic loops, no algorithm header)
    std::vector<int> generateJacobsthalSequence(int n) const;
    std::vector<int> generateInsertionOrder(int n) const;
    
    // Binary search implementation (no algorithm header)
    int binarySearchVector(const std::vector<int>& vec, int value, int left, int right) const;
    int binarySearchDeque(const std::deque<int>& deq, int value, int left, int right) const;
    
    // Ford-Johnson algorithm implementations
    std::vector<int> fordJohnsonVector(const std::vector<int>& arr) const;
    std::deque<int> fordJohnsonDeque(const std::deque<int>& arr) const;
    
    // Utility functions
    bool isValidNumber(const std::string& str) const;
    double getTimeInMicroseconds() const;

public:
    // Orthodox Canonical Form
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();
    
    // Main functionality
    bool parseInput(int argc, char** argv);
    void execute();

};

#endif
