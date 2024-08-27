/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:23:43 by yussaito          #+#    #+#             */
/*   Updated: 2024/08/26 14:47:36 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	current_index(t_stack_node *stack)
{
	int	i;//To store the index of the current node
	int	median;//To store the position of the median of the stack

	i = 0;
	if (!stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)//Check if the index is above the median
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;//Move to the next node
		i++;//Increment the index
	}
}
//This function finds the target node in stack 'b'
static void	set_target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_b;
	t_stack_node	*target_node;
	long			best_match_index;

	while (a)//Find a target node of each a node
	{
		best_match_index = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->nbr < a->nbr
				&& current_b->nbr > best_match_index)
			{
				best_match_index = current_b->nbr;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == LONG_MIN)
			a->target_node = find_max(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}
static void	cost_analysis_a(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->above_median))//If a is below median, rra is faster than ra. So, we need the push_cost separately
			a->push_cost = len_a - (a->index);
		if (a->target_node->above_median)//Same idea as a about stack 'b'
			a->push_cost += a->target_node->index;
		else
			a->push_cost = len_b - (a->target_node->index);
		a = a->next;
	}
}

//This idea is almost same as set_target_a func. By comparing LONG_MAX with push_cost, decide the cheapese push_cost node.
//If the push_cost is same, the first node is taken.
//The return value is only "true" and this is like making a flag on the cheapest_node
void	set_cheapest(t_stack_node *stack)
{
	long			cheapest_value;
	t_stack_node	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}
void	init_nodes_a(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_analysis_a(a,b);
	set_cheapest(a);
}

