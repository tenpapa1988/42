/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 07:55:04 by yussaito          #+#    #+#             */
/*   Updated: 2025/04/29 13:02:24 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0) {}
Fixed::Fixed(const int intVal) {
	_fixedPointValue = intVal << _fractionalBits;
}
Fixed::Fixed(const float floatVal) {
	_fixedPointValue = roundf(floatVal * (1 << _fractionalBits));
}
Fixed::Fixed(const Fixed& other) {
	_fixedPointValue = other._fixedPointValue;
}
Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other)
        _fixedPointValue = other._fixedPointValue;
    return *this;
}
Fixed::~Fixed() {}

int Fixed::getRawBits(void) const {
	return _fixedPointValue;
}
void Fixed::setRawBits(int const raw) {
	_fixedPointValue = raw;
}
float Fixed::toFloat(void) const {
	return (float)_fixedPointValue / (1 << _fractionalBits);
}
int Fixed::toInt(void) const {
	return _fixedPointValue >> _fractionalBits;
}

bool Fixed::operator>(const Fixed& other) const {
	return _fixedPointValue > other._fixedPointValue;
}
bool Fixed::operator<(const Fixed& other) const {
	return _fixedPointValue < other._fixedPointValue;
}
bool Fixed::operator>=(const Fixed& other) const {
	return _fixedPointValue >= other._fixedPointValue;
}
bool Fixed::operator<=(const Fixed& other) const {
	return _fixedPointValue <= other._fixedPointValue;
}
bool Fixed::operator==(const Fixed& other) const {
	return _fixedPointValue == other._fixedPointValue;
}
bool Fixed::operator!=(const Fixed& other) const {
	return _fixedPointValue != other._fixedPointValue;
}

Fixed Fixed::operator+(const Fixed& other) const {
	return Fixed(this->toFloat() + other.toFloat());
}
Fixed Fixed::operator-(const Fixed& other) const {
	return Fixed(this->toFloat() - other.toFloat());
}
Fixed Fixed::operator*(const Fixed& other) const {
	return Fixed(this->toFloat() * other.toFloat());
}
Fixed Fixed::operator/(const Fixed& other) const {
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++() { 
	_fixedPointValue++;
	return *this;
}
Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	_fixedPointValue++;
	return temp;
}
Fixed& Fixed::operator--() {
	_fixedPointValue--;
	return *this;
}
Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	_fixedPointValue--;
	return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return (a < b) ? a : b;
}
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return (a < b) ? a : b;
}
Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return (a > b) ? a : b;
}
const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return (a > b) ? a : b;
}
Fixed& Fixed::max(Fixed& a, const Fixed& b) {
	return (a > b) ? a : const_cast<Fixed&>(b);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}