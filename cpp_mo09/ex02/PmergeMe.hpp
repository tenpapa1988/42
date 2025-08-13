/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 13:48:41 by yussaito          #+#    #+#             */
/*   Updated: 2025/08/12 15:22:19 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <iostream>

/* Exception Class */
class CustomException : public std::exception {
    std::string _msg;
public:
    explicit CustomException(const std::string& m) : _msg(m) {}
    virtual ~CustomException() throw() {}
    const char* what() const throw() { return _msg.c_str(); }
};

/* Shared Function (Used in vector / deque) */
bool custom_cmp(std::pair<int,int> a, std::pair<int,int> b);
void print_before(char **argv);

/* std::vector */
void create_pairs(std::vector< std::pair<int,int> > *vecty, char **argv, int *additional_value);
void sort_pairs(std::vector< std::pair<int,int> > *vecty);
void mergeSort(std::vector< std::pair<int,int> >::iterator start,
               std::vector< std::pair<int,int> >::iterator end,
               size_t size);
void init_main_chain(std::vector<int> *main_chain, std::vector< std::pair<int,int> > vecty);
void binary_search_insertion(std::vector<int> *main_chain, std::vector<int>::iterator end, int val);
void insert_into_main_chain(std::vector< std::pair<int,int> > vecty, std::vector<int> *main_chain, int additional_value);
void print_after(std::vector<int> main_chain);

/* std::deque */
void create_pairs2(std::deque< std::pair<int,int> > *dequey, char **argv, int *additional_value);
void sort_pairs2(std::deque< std::pair<int,int> > *dequey);
void mergeSort2(std::deque< std::pair<int,int> >::iterator start,
                std::deque< std::pair<int,int> >::iterator end,
                size_t size);
void init_main_chain2(std::deque<int> *main_chain, std::deque< std::pair<int,int> > dequey);
void binary_search_insertion2(std::deque<int> *main_chain, std::deque<int>::iterator end, int val);
void insert_into_main_chain2(std::deque< std::pair<int,int> > dequey, std::deque<int> *main_chain, int additional_value);
void print_after2(std::deque<int> main_chain);

#endif
