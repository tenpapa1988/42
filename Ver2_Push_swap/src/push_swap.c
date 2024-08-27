/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 10:16:08 by yussaito          #+#    #+#             */
/*   Updated: 2024/08/27 10:27:40 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	split_and_prepare_argv(int argc, char **argv,
						char ***split_argv, char ***new_argv)
{
	size_t	arg_count;
	size_t	i;

	arg_count = 0;
	i = 0;
	if (argc == 2)
	{
		*split_argv = split(argv[1], ' ');
		while ((*split_argv)[arg_count])
			arg_count++;
		*new_argv = malloc(sizeof(char *) * (arg_count + 2));
		if (new_argv == NULL)
		{
			free_split(*split_argv);
			return (0);
		}
		(*new_argv)[0] = argv[0];
		while (i < arg_count)
		{
			(*new_argv)[i + 1] = (*split_argv)[i];
			i++;
		}
		(*new_argv)[arg_count + 1] = NULL;
	}
	return (arg_count);
}

static	void	initialize_stack_and_sort(t_stack_node **a,
						t_stack_node **b, char **argv)
{
	check_argv(a, argv + 1);
	if (!stack_sorted(*a))
	{
		if (stack_len(*a) == 2)
			sa(a, false);
		else if (stack_len(*a) == 3)
			sort_three(a);
		else
			sort_stacks(a, b);
	}
}

static void	free_memory(t_stack_node **a, char **split_argv, char **new_argv)
{
	free_stack(a);
	if (split_argv)
		free_split(split_argv);
	if (new_argv)
		free(new_argv);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**split_argv;
	char			**new_argv;
	size_t			arg_count;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		exit(1);
	split_argv = NULL;
	new_argv = NULL;
	arg_count = split_and_prepare_argv(argc, argv, &split_argv, &new_argv);
	if (arg_count > 0)
	{
		argv = new_argv;
		argc = arg_count + 1;
	}
	initialize_stack_and_sort(&a, &b, argv);
	free_memory(&a, split_argv, new_argv);
	return (0);
}
