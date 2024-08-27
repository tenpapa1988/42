/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:18:42 by yussaito          #+#    #+#             */
/*   Updated: 2024/07/29 09:14:12 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Let's name node1 & node2 & node3 and node1 is the top and node3 is the bottom
static	void swap(t_stack_node **head)
{
	if (!*head || !(*head)->next)//if stack is Null or there is only one, it returns
		return ; 
	*head = (*head)->next;//(*head)->next is node1's next which is node2. So, *head becomes node1
	(*head)->prev->prev = *head;//*head became node2. (*head)->prev is node1 since node2's prev is node1. (*head)->prev->prev is node1's prev pointer. So, node1's prev becomes node2
	(*head)->prev->next = (*head)->next;//(*head)->next is node3 since node2's next is node3. (*head)->prev is node1. (*head)->prev->next is node1's next. So, node1's next becomes node3
	if ((*head)->next)//if node2 has next...
		(*head)->next->prev = (*head)->prev;// node2's prev is node1. (*head)->next is node3. So, (*head)->next->prev is node3's prev. So, now node3 became node1
	(*head)->next = (*head)->prev;// (*head)->prev is node2's prev is node1. (*head)->next now become node1
	(*head)->prev = NULL;//Now insert NULL into (*head)->prev which is node2's prev
}

void	sa(t_stack_node **a, bool print)
{
	swap(a);
	if (!print)
		ft_printf("sa\n");
}

void	sb(t_stack_node **b, bool print)
{
	swap(b);
	if (!print)
		ft_printf("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b, bool print)
{
	swap(a);
	swap(b);
	if (!print)
		ft_printf("ss\n");
}