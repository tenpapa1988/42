/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 23:57:39 by yussaito          #+#    #+#             */
/*   Updated: 2025/04/09 01:22:33 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp() {
	std::time_t now = std::time(nullptr);
	std::tm* t = std::localtime(&now);
	std::cout << "[" << (t->tm_year + 1990)
			  << std::setw(2) << std::setfill('0') << (t->tm_mon + 1)
			  << std::setw(2) << std::setfill('0') << t->tm_mday << "_"
			  << std::setw(2) << std::setfill('0') << t->tm_hour
			  << std::setw(2) << std::setfill('0') << t->tm_min
			  << std::setw(2) << std::setfill('0') << t->tm_sec
			  << "] ";
}

Account::Account(int initial_deposit)
	: _accountIndex(_nbAccounts),
	  _amount(initial_deposit),
	  _nbDeposits(0),
	  _nbWithdrawals(0) {
		_nbAccounts++;
		_totalAmount += initial_deposit;
		_displayTimestamp();
		std::cout << "index" << _accountIndex
				  << ";amount:" << _amount
				  << ";created" << std::endl;
}

Account::~Account() {
	_displayTimestamp();
	std::cout << "index" << _accountIndex
			  << ";amount:" << _amount
			  << ";closed" << std::endl;
}

int	Account::getNbAccounts() { return _nbAccounts; }
int	Account::getTotalAmount() { return _totalAmount; }
int	Account::getNbDeposits() { return _totalNbDeposits; }
int	Account::getNbWithdrawals() { return _totalNbWithdrawals; }

void	Account::displayAccountsInfos() {
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts()
			 << ";total:" << getTotalAmount()
			 << ";deposits:" << getNbDeposits()
			 << ";withdrawals" << getNbWithdrawals()
			 << std::endl;
}

void	Account::makeDeposit(int deposit) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";p_amount:" << _amount
			  << ";deposit:" << deposit;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << ";amount:" << _amount
			  << ";nb_deposits:" << _nbDeposits
			  << std::endl;
}
