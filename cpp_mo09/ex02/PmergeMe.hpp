/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 13:48:41 by yussaito          #+#    #+#             */
/*   Updated: 2025/08/07 09:16:47 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();
    void run(const std::vector<std::string>& args);

private:
    std::vector<int> _vectorInput;
    std::deque<int> _dequeInput;

    void parseInput(const std::vector<std::string>& args);
    void printContainer(const std::string& label, const std::vector<int>& container) const;
    void printContainer(const std::string& label, const std::deque<int>& container) const;

    void mergeInsertSort(std::vector<int>& vec, int left, int right);
    void mergeInsertSort(std::deque<int>& deq, int left, int right);

    void insertionSort(std::vector<int>& vec, int left, int right);
    void insertionSort(std::deque<int>& deq, int left, int right);

    void merge(std::vector<int>& vec, int left, int mid, int right);
    void merge(std::deque<int>& deq, int left, int mid, int right);
};

#endif
