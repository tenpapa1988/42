/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 10:37:43 by yussaito          #+#    #+#             */
/*   Updated: 2024/08/24 09:17:02 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//aとbが必ずしも上から同じ位置にないので、aはcheapese_nodeが一番上に来たけど、bが来てないってことが発生しうる
//その場合は、ループを抜けて、ready_for_push関数でトップになるまでループを回すことになる
//これを考えるとこの関数は不要では？と思うのだが、（おそらく）試行回数の削減のために入れている
//つまりrrで済ませられるなら済ませる！としないと、試行回数が増えていってしまう
static void	rotate_both(t_stack_node **a,
						t_stack_node **b,
						t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node
		&& *a != cheapest_node)
		rr(a, b, false);
	current_index(*a);
	current_index(*b);
}

//This is a same idea as rotate_both func
static void	rev_rotate_both(t_stack_node **a,
								t_stack_node **b,
								t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node
		&& *a != cheapest_node)
		rrr(a, b, false);
	current_index(*a);
	current_index(*b);
}

//After checking stack 'a', let's move the stack 'a' nodes to stack 'b'
//get_cheapest関数でcheapest_nodeにcheapestなノードのポインタを格納
//次のif文〜ready_for_pushでスタックaの一番上にcheapestを、スタックbの一番上にtarget_nodeを持ってくる
//ここまで整ったらpbでスタックaの一番上をスタックbの一番上に動かす
static	void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median
		&& cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&&!(cheapest_node->target_node->above_median))
		rev_rotate_both(a, b, cheapest_node);
	ready_for_push(a, cheapest_node, 'a');
	ready_for_push(b, cheapest_node->target_node, 'b');
	pb(b, a, false);
}

//bからaへはcheapest_nodeを探す必要がないので、スタックbの上から処理していく。このときスタックaのターゲットノードが一番上に来るようにするだけ
static	void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	ready_for_push(a, (*b)->target_node, 'a');
	pa(a, b, false);
}
//スタックaの中で一番小さい値を一番上に持っていく
void	min_on_top(t_stack_node **a)
{
	while ((*a)->nbr != find_min(*a)->nbr)
	{
		if (find_min(*a)->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}

//This function is the overview of the algorithm
void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !stack_sorted(*a))//This first two pb is for to make target nodes on stack b
		pb(b, a, false);
	if (len_a-- > 3 && !stack_sorted(*a))//Same as above
		pb(b, a, false);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);//この段階ではスタックaが3つになっているはずなので（1個上のwhile文から）、ここでスタックaを昇順にする
	while (*b)//ここからスタックbからスタックaに移行する
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}
