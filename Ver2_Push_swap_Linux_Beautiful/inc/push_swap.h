/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 09:07:26 by yussaito          #+#    #+#             */
/*   Updated: 2024/09/22 13:21:36 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/libft.h"

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

typedef struct s_args
{
	char	**split_argv;
	char	**new_argv;
}	t_args;

int				ft_printf(const char *fmt, ...);
int				error_syntax(char *str_n);
int				error_duplicate(t_stack_node *a, int n);
void			free_errors(t_stack_node **a, t_args *args);
void			free_stack(t_stack_node	**stack);

char			**split(char *str, char delimiter);
void			free_split(char **split);

void			sort_stacks(t_stack_node **a, t_stack_node **b);
void			sort_three(t_stack_node **a);
void			min_on_top(t_stack_node **a);
void			rotate_both(t_stack_node **a,
					t_stack_node **b, t_stack_node *cheapest_node);
void			rev_rotate_both(t_stack_node **a,
					t_stack_node **b,
					t_stack_node *cheapest_node);

void			check_argv(t_stack_node **a, char **argv, t_args *args);
int				stack_len(t_stack_node *stack);
bool			stack_sorted(t_stack_node *stack);
t_stack_node	*find_last(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);

t_stack_node	*get_cheapest(t_stack_node *stack);
void			ready_for_push(t_stack_node **stack,
					t_stack_node *top_node, char stack_name);
void			current_index(t_stack_node *stack);
void			init_nodes_a(t_stack_node *a, t_stack_node *b);
void			init_nodes_b(t_stack_node *a, t_stack_node *b);

void			pa(t_stack_node **a, t_stack_node **b, bool print);
void			pb(t_stack_node **b, t_stack_node **a, bool print);
void			ra(t_stack_node **a, bool print);
void			rb(t_stack_node **b, bool print);
void			rr(t_stack_node **a, t_stack_node **b, bool print);
void			rra(t_stack_node **a, bool print);
void			rrb(t_stack_node **b, bool print);
void			rrr(t_stack_node **a, t_stack_node **b, bool print);
void			sa(t_stack_node **a, bool print);
void			sb(t_stack_node **b, bool print);
void			ss(t_stack_node **a, t_stack_node **b, bool print);

#endif