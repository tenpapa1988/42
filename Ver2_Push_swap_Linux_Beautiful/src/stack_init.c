/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 07:58:27 by yussaito          #+#    #+#             */
/*   Updated: 2024/09/22 13:20:54 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_long_max(int sign)
{
	if (sign > 0)
		return (LONG_MAX);
	else
		return (LONG_MIN);
}

static long	ft_atol(const char *str, int *error)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || ('\t' <= *str && *str <= '\r'))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while ('0' <= *str && *str <= '9')
	{
		if (result > (LONG_MAX - (*str - '0')) / 10)
		{
			*error = 1;
			return (ft_long_max(sign));
		}
		result = result * 10 + (*str - '0');
		str++;
	}
	return (sign * result);
}

static void	append_node(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = n;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	check_argv(t_stack_node **a, char **argv, t_args *args)
{
	long	n;
	int		i;
	int		error;

	i = 0;
	error = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			free_errors(a, args);
		n = ft_atol(argv[i], &error);
		if (error || n > INT_MAX || n < INT_MIN)
			free_errors(a, args);
		if (error_duplicate(*a, (int)n))
			free_errors(a, args);
		append_node(a, (int)n);
		i++;
	}
}
