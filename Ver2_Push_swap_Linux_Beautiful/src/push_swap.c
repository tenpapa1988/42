/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 10:16:08 by yussaito          #+#    #+#             */
/*   Updated: 2024/09/22 13:29:37 by yussaito         ###   ########.fr       */
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
						t_stack_node **b, char **argv, t_args *args)
{
	check_argv(a, argv + 1, args);
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
	(void) new_argv;
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
	t_args			args;
	size_t			arg_count;

	a = NULL;
	b = NULL;
	args.split_argv = NULL;
	args.new_argv = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		exit(1);
	arg_count = split_and_prepare_argv(argc, argv,
			&args.split_argv, &args.new_argv);
	if (arg_count > 0)
	{
		argv = args.new_argv;
		argc = arg_count + 1;
	}
	initialize_stack_and_sort(&a, &b, argv, &args);
	free_memory(&a, args.split_argv, args.new_argv);
	return (0);
}
