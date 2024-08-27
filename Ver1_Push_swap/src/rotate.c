/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:28:10 by yussaito          #+#    #+#             */
/*   Updated: 2024/08/13 12:23:48 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last(*stack);
	last_node->next = *stack;//Assign last_node's next to the top of the node's pointer. So, now the last node becomes the previoud top node
	*stack = (*stack)->next;//Assign the second node's pointer to the top of node
	(*stack)->prev = NULL;//Assign NULL to the previous second node's prev. Now the second node becomes the top
	last_node->next->prev = last_node;//Assign last node pointer to the new last node prev. The new last node equals the prevous top node
	last_node->next->next = NULL;//Assign NULL to the new last node's next
}

void	ra(t_stack_node **a, bool print)
{
	rotate(a);
	if (!print)
		ft_printf("ra\n");
}

void	rb(t_stack_node **b, bool print)
{
	rotate(b);
	if (!print)
		ft_printf("rb\n");
}

void	rr(t_stack_node **a, t_stack_node **b, bool print)
{
	rotate(a);
	rotate(b);
	if (!print)
		ft_printf("rr\n");
}
