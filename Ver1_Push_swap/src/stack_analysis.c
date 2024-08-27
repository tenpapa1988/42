/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_analysis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 14:22:10 by yussaito          #+#    #+#             */
/*   Updated: 2024/08/26 12:14:43 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack_node *stack)
{
	int	count;

	if (!stack)
		return (0);
	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

t_stack_node	*find_last(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}
//Check the stack is sorted in ascending order
bool	stack_sorted(t_stack_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)//上にある数字が下の数字よりも大きい時点で、falseが返る
			return (false);
		stack = stack->next;//stackを次に動かす
	}
	return (true);//falseが返らなければ、OK
}
t_stack_node	*find_max(t_stack_node *stack)
{
	long			max;
	t_stack_node	*max_node;

	if (!stack)
		return (NULL);
	max = LONG_MIN;//By setting the initial max value to LONG_MIN, any number is now bigger than max
	while (stack)
	{
		if (stack->nbr > max)//Check if the current stack number is larger than the max value
		{
			max = stack->nbr;//If so, update the max value to the current stack number
			max_node = stack;//Update the max node pointer to the current stack pointer
		}
		stack = stack->next;//Move to the next node
	}
	return (max_node);
}
//find_maxの逆をする
t_stack_node	*find_min(t_stack_node *stack)
{
	long			min;
	t_stack_node	*min_node;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->nbr < min)
		{
			min = stack->nbr;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}
