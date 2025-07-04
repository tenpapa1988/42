/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 10:31:07 by yussaito          #+#    #+#             */
/*   Updated: 2025/07/01 10:36:36 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template<typename T>
void swap(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template<typename T>
T const& min(T const& a, T const& b) {
    return (a < b ? a : b);
}

template<typename T>
T const& max(T const& a, T const& b) {
    return (a > b ? a : b);
}

#endif
