/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 13:48:47 by yussaito          #+#    #+#             */
/*   Updated: 2025/07/11 13:50:28 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include <climits>

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

void PmergeMe::run(const std::vector<std::string>& args) {
    parseInput(args);

    printContainer("Before:", _vectorInput);

    std::vector<int> vec = _vectorInput;
    std::deque<int> deq = _dequeInput;

    clock_t startVec = clock();
    mergeInsertSort(vec, 0, vec.size() - 1);
    clock_t endVec = clock();

    clock_t startDeq = clock();
    mergeInsertSort(deq, 0, deq.size() - 1);
    clock_t endDeq = clock();

    printContainer("After:", vec);

    double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1e6;
    double timeDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1e6;

    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : "
              << timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque : "
              << timeDeq << " us" << std::endl;
}

void PmergeMe::parseInput(const std::vector<std::string>& args) {
    for (size_t i = 0; i < args.size(); ++i) {
        const std::string& str = args[i];
        for (size_t j = 0; j < str.length(); ++j) {
            if (!isdigit(str[j]))
                throw std::runtime_error("Error");
        }

        long value = std::strtol(str.c_str(), NULL, 10);
        if (value < 0 || value > INT_MAX)
            throw std::runtime_error("Error");

        _vectorInput.push_back(static_cast<int>(value));
        _dequeInput.push_back(static_cast<int>(value));
    }
}

void PmergeMe::printContainer(const std::string& label, const std::vector<int>& container) const {
    std::cout << label;
    for (size_t i = 0; i < container.size(); ++i)
        std::cout << " " << container[i];
    std::cout << std::endl;
}

void PmergeMe::printContainer(const std::string& label, const std::deque<int>& container) const {
    std::cout << label;
    for (size_t i = 0; i < container.size(); ++i)
        std::cout << " " << container[i];
    std::cout << std::endl;
}

// ---------- VECTOR ----------
void PmergeMe::mergeInsertSort(std::vector<int>& vec, int left, int right) {
    if (left >= right)
        return;
    if (right - left <= 10) {
        insertionSort(vec, left, right);
        return;
    }

    int mid = left + (right - left) / 2;
    mergeInsertSort(vec, left, mid);
    mergeInsertSort(vec, mid + 1, right);
    merge(vec, left, mid, right);
}

void PmergeMe::insertionSort(std::vector<int>& vec, int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        int key = vec[i];
        int j = i - 1;
        while (j >= left && vec[j] > key) {
            vec[j + 1] = vec[j];
            --j;
        }
        vec[j + 1] = key;
    }
}

void PmergeMe::merge(std::vector<int>& vec, int left, int mid, int right) {
    std::vector<int> tmp(right - left + 1);
    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right) {
        if (vec[i] <= vec[j])
            tmp[k++] = vec[i++];
        else
            tmp[k++] = vec[j++];
    }
    while (i <= mid)
        tmp[k++] = vec[i++];
    while (j <= right)
        tmp[k++] = vec[j++];
    for (int l = 0; l < k; ++l)
        vec[left + l] = tmp[l];
}

// ---------- DEQUE ----------
void PmergeMe::mergeInsertSort(std::deque<int>& deq, int left, int right) {
    if (left >= right)
        return;
    if (right - left <= 10) {
        insertionSort(deq, left, right);
        return;
    }

    int mid = left + (right - left) / 2;
    mergeInsertSort(deq, left, mid);
    mergeInsertSort(deq, mid + 1, right);
    merge(deq, left, mid, right);
}

void PmergeMe::insertionSort(std::deque<int>& deq, int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        int key = deq[i];
        int j = i - 1;
        while (j >= left && deq[j] > key) {
            deq[j + 1] = deq[j];
            --j;
        }
        deq[j + 1] = key;
    }
}

void PmergeMe::merge(std::deque<int>& deq, int left, int mid, int right) {
    std::deque<int> tmp;
    int i = left, j = mid + 1;
    while (i <= mid && j <= right) {
        if (deq[i] <= deq[j])
            tmp.push_back(deq[i++]);
        else
            tmp.push_back(deq[j++]);
    }
    while (i <= mid)
        tmp.push_back(deq[i++]);
    while (j <= right)
        tmp.push_back(deq[j++]);
    for (size_t k = 0; k < tmp.size(); ++k)
        deq[left + k] = tmp[k];
}
