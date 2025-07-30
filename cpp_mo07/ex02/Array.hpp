/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:36:32 by yussaito          #+#    #+#             */
/*   Updated: 2025/07/31 08:17:38 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template<typename T>
class Array {
private:
    T* _data;
    unsigned int _size;

public:
    Array() : _data(NULL), _size(0) {}
    Array(unsigned int n) : _data(new T[n]), _size(n) {}
    Array(const Array& other) : _data(NULL), _size(0) {
        *this = other;
    }

    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] _data;
            _size = other._size;
            _data = new T[_size];
            for (unsigned int i = 0; i < _size; ++i)
                _data[i] = other._data[i];
        }
        return *this;
    }

    ~Array() {
        delete[] _data;
    }

    T& operator[](unsigned int index) {
        if (index >= _size)
            throw std::out_of_range("Index out of bounds (non-const)");
        return _data[index];
    }

    const T& operator[](unsigned int index) const {
        if (index >= _size)
            throw std::out_of_range("Index out of bounds (const)");
        return _data[index];
    }

    unsigned int size() const {
        return _size;
    }
};

#endif
