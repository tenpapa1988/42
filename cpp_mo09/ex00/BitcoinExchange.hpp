/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 13:17:35 by yussaito          #+#    #+#             */
/*   Updated: 2025/07/11 13:17:36 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange {
public:
    BitcoinExchange(const std::string& dbFile);
    ~BitcoinExchange();

    void evaluateFile(const std::string& inputFile) const;

private:
    std::map<std::string, float> _rateMap;

    bool isValidDate(const std::string& date) const;
    bool isValidValue(const std::string& valueStr, float& value) const;
    std::string getClosestDate(const std::string& date) const;
    void loadDatabase(const std::string& dbFile);
};

#endif
