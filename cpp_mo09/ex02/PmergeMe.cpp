/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 13:48:47 by yussaito          #+#    #+#             */
/*   Updated: 2025/08/12 09:40:55 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>   // std::cout, std::endl
#include <stdexcept>  // std::runtime_error
#include <cctype>     // std::isdigit
#include <climits>    // INT_MAX
#include <cstdlib>    // std::strtol
#include <ctime>      // clock, CLOCKS_PER_SEC
#include <algorithm>  // std::find, std::lower_bound, std::inplace_merge など必要に応じて

////////////////////////// 共有関数 ///////////////////////////////////

// pairの「second（大きい方）」で比較（昇順）
bool custom_cmp(std::pair<int, int> a, std::pair<int, int> b)
{
    return a.second < b.second;
}

void print_before(char **argv)
{
    int i = 1;
    int error = 0;

    std::cout << "Before: ";
    while (argv[i])
    {
        std::string input = argv[i];
        std::cout << input << " ";
        if (input.size() > 10 || std::atol(input.c_str()) > INT_MAX || std::atol(input.c_str()) < 0)
            error = 1;
        for (size_t j = 0; j < input.size(); j++)
        {
            if (!isdigit(static_cast<unsigned char>(input[j])))
                error = 1;
        }
        i++;
    }
    std::cout << "\n";
    if (error == 1)
        throw CustomException("Error: input is invalid");
}

////////////////////////// std::vector 版 //////////////////////////////////////

// argv から pair を作る（奇数個なら最後を additional_value に退避）
void create_pairs(std::vector<std::pair<int,int> > *vecty, char **argv, int *additional_value)
{
    int i = 1;
    while (argv[i])
    {
        if (argv[i] && argv[i + 1])
        {
            std::pair<int,int> p(std::atoi(argv[i]), std::atoi(argv[i + 1]));
            vecty->push_back(p);
            i += 2;
        }
        else
        {
            *additional_value = std::atoi(argv[i]);
            i++;
        }
    }
}

// 各ペアを (小, 大) の形にそろえる
void sort_pairs(std::vector<std::pair<int,int> > *vecty)
{
    for (std::vector<std::pair<int,int> >::iterator it = vecty->begin(); it != vecty->end(); ++it)
    {
        if (it->first > it->second)
        {
            int t = it->first;
            it->first = it->second;
            it->second = t;
        }
    }
}

// 再帰 merge sort（second で並べる）※list 版のロジックをそのままvectorイテレータで
void mergeSort(std::vector<std::pair<int,int> >::iterator start,
               std::vector<std::pair<int,int> >::iterator end,
               size_t size)
{
    if (size == 0 && start != end)
        size = static_cast<size_t>(end - start);
    if (size <= 1)
        return;

    size_t firstHalf = size / 2;
    size_t secondHalf = size - firstHalf;
    std::vector<std::pair<int,int> >::iterator center = start + firstHalf;

    mergeSort(start, center, firstHalf);
    mergeSort(center, end, secondHalf);
    std::inplace_merge(start, center, end, &custom_cmp);
}

// main_chain を初期化（各pairの second を並べ、さらに先頭に最初の first を入れる）
void init_main_chain(std::vector<int> *main_chain, std::vector< std::pair<int,int> > vecty)
{
    for (std::vector<std::pair<int,int> >::iterator it = vecty.begin(); it != vecty.end(); ++it)
        main_chain->push_back(it->second);
    if (!vecty.empty())
        main_chain->insert(main_chain->begin(), vecty.begin()->first);
}

// 二分探索で [begin, end) の範囲に val を挿入
void binary_search_insertion(std::vector<int> *main_chain, std::vector<int>::iterator end, int val)
{
    std::vector<int>::iterator pos = std::lower_bound(main_chain->begin(), end, val);
    main_chain->insert(pos, val);
}

// Jacobsthal の順で pend(=pair.first) を main_chain に挿入（提出ロジックを忠実移植）
void insert_into_main_chain(std::vector< std::pair<int,int> > vecty, std::vector<int> *main_chain, int additional_value)
{
    size_t Jacobsthal[] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381,
                           174763, 349525, 699051, 1398101, 2796203, 5592405, 11184811, 22369621, 44739243,
                           89478485, 178956971, 357913941, 715827883, 1431655765};
    int jacobsthal_idx = 1;

    std::vector<int>::iterator slice_delim_it;
    std::vector< std::pair<int,int> >::iterator pair_it;
    std::vector< std::pair<int,int> >::iterator last_jacob_it = vecty.begin();

    while (Jacobsthal[jacobsthal_idx] <= vecty.size())
    {
        pair_it = vecty.begin() + (Jacobsthal[jacobsthal_idx] - 1);
        last_jacob_it = pair_it;

        int insertion_counter = 0;
        while (Jacobsthal[jacobsthal_idx] - insertion_counter > Jacobsthal[jacobsthal_idx - 1])
        {
            // pair_it->second を main_chain 内で見つけ、その**左側**を探索範囲にして first を挿入
            slice_delim_it = std::find(main_chain->begin(), main_chain->end(), pair_it->second);
            binary_search_insertion(main_chain, slice_delim_it, pair_it->first);
            pair_it--;
            insertion_counter++;
        }
        jacobsthal_idx++;
    }

    // Jacobsthal がサイズを超えた分の残りを挿入
    if (Jacobsthal[jacobsthal_idx] != vecty.size())
    {
        pair_it = vecty.end();
        if (pair_it != vecty.begin())
            pair_it--;
        while (pair_it != last_jacob_it)
        {
            slice_delim_it = std::find(main_chain->begin(), main_chain->end(), pair_it->second);
            binary_search_insertion(main_chain, slice_delim_it, pair_it->first);
            pair_it--;
        }
    }

    if (additional_value != -1)
        binary_search_insertion(main_chain, main_chain->end(), additional_value);
}

void print_after(std::vector<int> main_chain)
{
    std::cout << "After: ";
    for (std::vector<int>::iterator it = main_chain.begin(); it != main_chain.end(); ++it)
        std::cout << *it << " ";
    std::cout << '\n';
}

////////////////////////// std::deque 版（提出コードのまま） /////////////////////

void create_pairs2(std::deque<std::pair<int, int> > *dequey, char **argv, int *additional_value)
{
    int i = 1;
    while (argv[i])
    {
        if (argv[i] && argv[i + 1])
        {
            std::pair<int, int> pair_temp(std::atoi(argv[i]), std::atoi(argv[i + 1]));
            dequey->push_back(pair_temp);
            i += 2;
        }
        else
        {
            *additional_value = std::atoi(argv[i]);
            i++;
        }
    }
}

void sort_pairs2(std::deque<std::pair<int, int> > *dequey)
{
    for (std::deque<std::pair<int, int> >::iterator it = dequey->begin(); it != dequey->end(); ++it)
    {
        if (it->first > it->second)
        {
            int temp = it->first;
            it->first = it->second;
            it->second = temp;
        }
    }
}

void mergeSort2(std::deque<std::pair<int, int> >::iterator start, std::deque<std::pair<int, int> >::iterator end, size_t size)
{
    if (size == 0 && start != end)
        size = std::distance(start, end);
    if (size <= 1)
        return;

    size_t firstHalf = size / 2;
    size_t secondHalf = size - firstHalf;
    std::deque<std::pair<int, int> >::iterator center = start + firstHalf;

    mergeSort2(start, center, firstHalf);
    mergeSort2(center, end, secondHalf);
    std::inplace_merge(start, center, end, &custom_cmp);
}

void init_main_chain2(std::deque<int> *main_chain, std::deque<std::pair<int, int> > dequey)
{
    for (std::deque<std::pair<int, int> >::iterator it = dequey.begin(); it != dequey.end(); ++it)
        main_chain->push_back(it->second);
    if (!dequey.empty())
        main_chain->push_front(dequey.begin()->first);
}

void binary_search_insertion2(std::deque<int> *main_chain, std::deque<int>::iterator end, int val)
{
    std::deque<int>::iterator place_to_insert = std::lower_bound(main_chain->begin(), end, val);
    main_chain->insert(place_to_insert, val);
}

void insert_into_main_chain2(std::deque<std::pair<int, int> > dequey, std::deque<int> *main_chain, int additional_value)
{
    size_t Jacobsthal[] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381,
                           174763, 349525, 699051, 1398101, 2796203, 5592405, 11184811, 22369621, 44739243,
                           89478485, 178956971, 357913941, 715827883, 1431655765};
    int jacobsthal_idx = 1;

    std::deque<int>::iterator slice_delim_it;
    std::deque<std::pair<int, int> >::iterator pair_it;
    std::deque<std::pair<int, int> >::iterator last_jacob_it = dequey.begin();

    while (Jacobsthal[jacobsthal_idx] <= dequey.size())
    {
        pair_it = dequey.begin() + (Jacobsthal[jacobsthal_idx] - 1);
        last_jacob_it = pair_it;

        int insertion_counter = 0;
        while (Jacobsthal[jacobsthal_idx] - insertion_counter > Jacobsthal[jacobsthal_idx - 1])
        {
            slice_delim_it = std::find(main_chain->begin(), main_chain->end(), pair_it->second);
            binary_search_insertion2(main_chain, slice_delim_it, pair_it->first);
            pair_it--;
            insertion_counter++;
        }
        jacobsthal_idx++;
    }

    if (Jacobsthal[jacobsthal_idx] != dequey.size())
    {
        pair_it = dequey.end();
        if (pair_it != dequey.begin())
            pair_it--;
        while (pair_it != last_jacob_it)
        {
            slice_delim_it = std::find(main_chain->begin(), main_chain->end(), pair_it->second);
            binary_search_insertion2(main_chain, slice_delim_it, pair_it->first);
            pair_it--;
        }
    }

    if (additional_value != -1)
        binary_search_insertion2(main_chain, main_chain->end(), additional_value);
}

void print_after2(std::deque<int> main_chain)
{
    std::cout << "After: ";
    for (std::deque<int>::iterator it = main_chain.begin(); it != main_chain.end(); ++it)
        std::cout << *it << " ";
    std::cout << '\n';
}
