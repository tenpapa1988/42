/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 13:48:47 by yussaito          #+#    #+#             */
/*   Updated: 2025/08/17 15:29:01 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// Orthodox Canonical Form implementation
PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) : _inputData(other._inputData) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        _inputData = other._inputData;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

// Utility function to check if string represents a valid positive integer
bool PmergeMe::isValidNumber(const std::string& str) const {
    if (str.empty()) {
        return false;
    }
    
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
        if (*it < '0' || *it > '9') {
            return false;
        }
    }
    
    // Check for leading zeros (except single zero)
    if (str.length() > 1 && str[0] == '0') {
        return false;
    }
    
    return true;
}

// Get current time in microseconds
double PmergeMe::getTimeInMicroseconds() const {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000.0 + tv.tv_usec;
}

// Generate Jacobsthal sequence
std::vector<int> PmergeMe::generateJacobsthalSequence(int n) const {
    std::vector<int> jacobsthal;
    if (n <= 0) return jacobsthal;
    
    jacobsthal.push_back(1);
    if (n == 1) return jacobsthal;
    
    jacobsthal.push_back(1);
    
    int a = 1, b = 1;
    while (true) {
        int next = b + 2 * a;
        if (next > n) break;
        jacobsthal.push_back(next);
        a = b;
        b = next;
    }
    
    return jacobsthal;
}

// Generate insertion order based on Jacobsthal sequence
std::vector<int> PmergeMe::generateInsertionOrder(int n) const {
    std::vector<int> jacobsthal = generateJacobsthalSequence(n);
    std::vector<int> order;
    
    int last = 0;
    for (std::vector<int>::size_type i = 1; i < jacobsthal.size(); ++i) {
        int current = jacobsthal[i];
        int limit = (current < n) ? current : n;
        for (int j = limit; j > last; --j) {
            order.push_back(j - 1); // Convert to 0-based index
        }
        last = current;
    }
    
    // Add remaining elements
    for (int j = n; j > last; --j) {
        order.push_back(j - 1);
    }
    
    return order;
}

// Binary search for vector
int PmergeMe::binarySearchVector(const std::vector<int>& vec, int value, int left, int right) const {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (vec[mid] <= value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

// Binary search for deque
int PmergeMe::binarySearchDeque(const std::deque<int>& deq, int value, int left, int right) const {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (deq[mid] <= value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

// Ford-Johnson algorithm for vector
std::vector<int> PmergeMe::fordJohnsonVector(const std::vector<int>& arr) const {
    std::vector<int> result = arr;
    int n = result.size();
    
    if (n <= 1) return result;
    if (n == 2) {
        if (result[0] > result[1]) {
            int temp = result[0];
            result[0] = result[1];
            result[1] = temp;
        }
        return result;
    }
    
    // Step 1: Create pairs and separate larger/smaller elements
    std::vector<std::pair<int, int> > pairs;
    std::vector<int> larger, smaller;
    
    for (int i = 0; i < n - 1; i += 2) {
        if (result[i] > result[i + 1]) {
            pairs.push_back(std::make_pair(result[i], result[i + 1]));
            larger.push_back(result[i]);
            smaller.push_back(result[i + 1]);
        } else {
            pairs.push_back(std::make_pair(result[i + 1], result[i]));
            larger.push_back(result[i + 1]);
            smaller.push_back(result[i]);
        }
    }
    
    // Handle odd element
    int oddElement = -1;
    bool hasOdd = (n % 2 == 1);
    if (hasOdd) {
        oddElement = result[n - 1];
    }
    
    // Step 2: Recursively sort larger elements
    std::vector<int> mainChain;
    if (larger.size() > 1) {
        mainChain = fordJohnsonVector(larger);
    } else if (larger.size() == 1) {
        mainChain = larger;
    }
    
    // Reorder smaller elements according to sorted larger elements
    std::vector<int> pend;
    for (std::vector<int>::size_type i = 0; i < mainChain.size(); ++i) {
        int largeVal = mainChain[i];
        for (std::vector<std::pair<int, int> >::size_type j = 0; j < pairs.size(); ++j) {
            if (pairs[j].first == largeVal) {
                pend.push_back(pairs[j].second);
                break;
            }
        }
    }
    
    // Step 3: Build result with strategic insertion
    std::vector<int> finalResult;
    
    // Insert first smaller element and first larger element
    if (!pend.empty() && !mainChain.empty()) {
        finalResult.push_back(pend[0]);
        finalResult.push_back(mainChain[0]);
    }
    
    // Add remaining larger elements
    for (std::vector<int>::size_type i = 1; i < mainChain.size(); ++i) {
        finalResult.push_back(mainChain[i]);
    }
    
    // Insert remaining smaller elements using Jacobsthal order
    if (pend.size() > 1) {
        std::vector<int> insertionOrder = generateInsertionOrder(pend.size() - 1);
        
        for (std::vector<int>::size_type i = 0; i < insertionOrder.size(); ++i) {
            int idx = insertionOrder[i];
            int actualIdx = idx + 1; // Skip first element already inserted
            if (actualIdx < static_cast<int>(pend.size())) {
                int valueToInsert = pend[actualIdx];
                
                // Find upper bound for binary search
                int limitPos = finalResult.size();
                for (std::vector<int>::size_type j = 0; j < finalResult.size(); ++j) {
                    if (finalResult[j] == mainChain[actualIdx]) {
                        limitPos = j;
                        break;
                    }
                }
                
                int pos = binarySearchVector(finalResult, valueToInsert, 0, limitPos - 1);
                finalResult.insert(finalResult.begin() + pos, valueToInsert);
            }
        }
    }
    
    // Insert odd element if exists
    if (hasOdd) {
        int pos = binarySearchVector(finalResult, oddElement, 0, 
                                   static_cast<int>(finalResult.size()) - 1);
        finalResult.insert(finalResult.begin() + pos, oddElement);
    }
    
    return finalResult;
}

// Ford-Johnson algorithm for deque
std::deque<int> PmergeMe::fordJohnsonDeque(const std::deque<int>& arr) const {
    std::deque<int> result = arr;
    int n = result.size();
    
    if (n <= 1) return result;
    if (n == 2) {
        if (result[0] > result[1]) {
            int temp = result[0];
            result[0] = result[1];
            result[1] = temp;
        }
        return result;
    }
    
    // Step 1: Create pairs and separate larger/smaller elements
    std::deque<std::pair<int, int> > pairs;
    std::deque<int> larger, smaller;
    
    for (int i = 0; i < n - 1; i += 2) {
        if (result[i] > result[i + 1]) {
            pairs.push_back(std::make_pair(result[i], result[i + 1]));
            larger.push_back(result[i]);
            smaller.push_back(result[i + 1]);
        } else {
            pairs.push_back(std::make_pair(result[i + 1], result[i]));
            larger.push_back(result[i + 1]);
            smaller.push_back(result[i]);
        }
    }
    
    // Handle odd element
    int oddElement = -1;
    bool hasOdd = (n % 2 == 1);
    if (hasOdd) {
        oddElement = result[n - 1];
    }
    
    // Step 2: Recursively sort larger elements
    std::deque<int> mainChain;
    if (larger.size() > 1) {
        mainChain = fordJohnsonDeque(larger);
    } else if (larger.size() == 1) {
        mainChain = larger;
    }
    
    // Reorder smaller elements according to sorted larger elements
    std::deque<int> pend;
    for (std::deque<int>::size_type i = 0; i < mainChain.size(); ++i) {
        int largeVal = mainChain[i];
        for (std::deque<std::pair<int, int> >::size_type j = 0; j < pairs.size(); ++j) {
            if (pairs[j].first == largeVal) {
                pend.push_back(pairs[j].second);
                break;
            }
        }
    }
    
    // Step 3: Build result with strategic insertion
    std::deque<int> finalResult;
    
    // Insert first smaller element and first larger element
    if (!pend.empty() && !mainChain.empty()) {
        finalResult.push_back(pend[0]);
        finalResult.push_back(mainChain[0]);
    }
    
    // Add remaining larger elements
    for (std::deque<int>::size_type i = 1; i < mainChain.size(); ++i) {
        finalResult.push_back(mainChain[i]);
    }
    
    // Insert remaining smaller elements using Jacobsthal order
    if (pend.size() > 1) {
        std::vector<int> insertionOrder = generateInsertionOrder(pend.size() - 1);
        
        for (std::vector<int>::size_type i = 0; i < insertionOrder.size(); ++i) {
            int idx = insertionOrder[i];
            int actualIdx = idx + 1; // Skip first element already inserted
            if (actualIdx < static_cast<int>(pend.size())) {
                int valueToInsert = pend[actualIdx];
                
                // Find upper bound for binary search
                int limitPos = finalResult.size();
                for (std::deque<int>::size_type j = 0; j < finalResult.size(); ++j) {
                    if (finalResult[j] == mainChain[actualIdx]) {
                        limitPos = j;
                        break;
                    }
                }
                
                int pos = binarySearchDeque(finalResult, valueToInsert, 0, limitPos - 1);
                finalResult.insert(finalResult.begin() + pos, valueToInsert);
            }
        }
    }
    
    // Insert odd element if exists
    if (hasOdd) {
        int pos = binarySearchDeque(finalResult, oddElement, 0, 
                                  static_cast<int>(finalResult.size()) - 1);
        finalResult.insert(finalResult.begin() + pos, oddElement);
    }
    
    return finalResult;
}

// Parse command line input
bool PmergeMe::parseInput(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error" << std::endl;
        return false;
    }
    
    _inputData.clear();
    
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        
        if (!isValidNumber(arg)) {
            std::cerr << "Error" << std::endl;
            return false;
        }
        
        std::istringstream iss(arg);
        int num;
        iss >> num;
        
        if (iss.fail() || num <= 0) {
            std::cerr << "Error" << std::endl;
            return false;
        }
        
        _inputData.push_back(num);
    }
    
    return true;
}

// Main execution function
void PmergeMe::execute() {
    // Display original sequence
    std::cout << "Before:";
    for (std::vector<int>::size_type i = 0; i < _inputData.size(); ++i) {
        std::cout << " " << _inputData[i];
    }
    std::cout << std::endl;
    
    // Sort with vector and measure time
    double startTime = getTimeInMicroseconds();
    std::vector<int> sortedVector = fordJohnsonVector(_inputData);
    double endTime = getTimeInMicroseconds();
    double vectorTime = endTime - startTime;
    
    // Sort with deque and measure time
    std::deque<int> inputDeque(_inputData.begin(), _inputData.end());
    startTime = getTimeInMicroseconds();
    std::deque<int> sortedDeque = fordJohnsonDeque(inputDeque);
    endTime = getTimeInMicroseconds();
    double dequeTime = endTime - startTime;
    
    // Display sorted sequence
    std::cout << "After: ";
    for (std::vector<int>::size_type i = 0; i < sortedVector.size(); ++i) {
        std::cout << " " << sortedVector[i];
    }
    std::cout << std::endl;
    
    // Display timing results
    std::cout << "Time to process a range of " << _inputData.size() 
              << " elements with std::vector : " << vectorTime << " us" << std::endl;
    std::cout << "Time to process a range of " << _inputData.size() 
              << " elements with std::deque  : " << dequeTime << " us" << std::endl;
}
