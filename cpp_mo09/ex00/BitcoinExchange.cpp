/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 13:17:57 by yussaito          #+#    #+#             */
/*   Updated: 2025/08/14 09:17:24 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <limits>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string& dbFile) {
   loadDatabase(dbFile);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    this->_rateMap = other._rateMap;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other)
        this->_rateMap = other._rateMap;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::isValidDate(const std::string& date) const {
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    int y, m, d;
    char dash1, dash2;
    std::istringstream ss(date);
    ss >> y >> dash1 >> m >> dash2 >> d;
    return !ss.fail() && dash1 == '-' && dash2 == '-' &&
           y >= 2009 && m >= 1 && m <= 12 && d >= 1 && d <= 31;
}

bool BitcoinExchange::isValidValue(const std::string& valueStr, float& value) const {
    char* end;
    value = std::strtof(valueStr.c_str(), &end);
    return *end == '\0' && value >= 0.0f && value <= 1000.0f;
}

void BitcoinExchange::loadDatabase(const std::string& dbFile) {
    std::ifstream file(dbFile.c_str());
    if (!file)
        throw std::runtime_error("Could not open database file.");

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string date, rateStr;
        if (!std::getline(ss, date, ',') || !std::getline(ss, rateStr))
            continue;

        float rate = std::atof(rateStr.c_str());
        _rateMap[date] = rate;
    }
}

std::string BitcoinExchange::getClosestDate(const std::string& date) const {
    std::map<std::string, float>::const_iterator it = _rateMap.lower_bound(date);
    if (it != _rateMap.end() && it->first == date)
        return date;
    if (it == _rateMap.begin())
        return "";
    --it;
    return it->first;
}

void BitcoinExchange::evaluateFile(const std::string& inputFile) const {
    std::ifstream file(inputFile.c_str());
    if (!file) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string date, valueStr;
        if (!std::getline(ss, date, '|') || !std::getline(ss, valueStr)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        date = date.substr(0, date.find_last_not_of(" \t") + 1);
        valueStr = valueStr.substr(valueStr.find_first_not_of(" \t"));

        if (!isValidDate(date)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        float value;
        if (!isValidValue(valueStr, value)) {
            if (value < 0)
                std::cerr << "Error: not a positive number." << std::endl;
            else
                std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        std::string refDate = getClosestDate(date);
        if (refDate.empty()) {
            std::cerr << "Error: no data available before " << date << std::endl;
            continue;
        }

        float rate = _rateMap.find(refDate)->second;
        std::cout << date << " => " << value << " = " << value * rate << std::endl;
    }
}
