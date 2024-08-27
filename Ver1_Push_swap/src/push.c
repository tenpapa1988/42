/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 09:36:34 by yussaito          #+#    #+#             */
/*   Updated: 2024/07/29 09:20:31 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void push(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node	*push_node;

	if (!*src)//Check the src is NULL or not
		return ;
	push_node = *src;//Insert the src pointer to push_node first(we'll move it later though)
	*src = (*src)->next;//Insert the second node of pointer to the top of src
	if (*src)//if src is NULL, we don't need to do anything
		(*src)->prev = NULL;//To make the second node of src top, set the prev to NULL
	push_node->prev = NULL;//To make the pre-src top to top, set its prev to NULL
	if (!*dst)
	{
		*dst = push_node;//if dst is NULL, the push_node is automatically the top of dst
		push_node->next = NULL;//if dst is NULL, there is only push_node. So, the push_node's next is NULL
	}
	else
	{
		push_node->next = *dst;//set the current dst to the second by doing push_node->next
		push_node->next->prev = push_node;//this is the same meaning of (*dst)->prev = push_node
		*dst = push_node;//set the first dst node to push_node
	}
}

void	pa(t_stack_node **a, t_stack_node **b, bool print)
{
	push(a, b);
	if (!print)
		ft_printf("pa\n");
}

void	pb(t_stack_node **b, t_stack_node **a, bool print)
{
	push(b, a);
	if (!print)
		ft_printf("pb\n");
}
	