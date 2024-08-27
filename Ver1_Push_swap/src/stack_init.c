/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 07:58:27 by yussaito          #+#    #+#             */
/*   Updated: 2024/08/26 12:04:53 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_long_max(int sign)
{
	if (sign > 0)
		return ((int)LONG_MAX);
	else
		return ((int)LONG_MIN);
}

//Charをlong_intに変換する
static long	ft_atol(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || ('\t' <= *str && *str <= '\r'))//すべてのタブをスキップする
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
		if (result > (LONG_MAX - (*str - '0')) / 10)//result（strを数字に変換した変数）がLONG_MAXを超えるか？チェック
			return (ft_long_max(sign));//超えた場合には、LONG_MAXの値を返すようにする。LONG_MAXの値は固定値で、それ以上の数字は返さない
		result = result * 10 + (*str - '0');
		str++;
	}
	return (sign * result);
}

//双方向リンクリスト（doubly linked list）に新しいノードを追加する関数
static void	append_node(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL;//まずは初期化
	node->nbr = n;//値を代入
	if (!(*stack))//最初のときにはstackが空なので、個々に入る
	{
		*stack = node;
		node->prev = NULL;//この処理をすることで、prev/nextがNULLになって1つだけになる
	}
	else
	{
		last_node = find_last(*stack);//2巡目だと仮定すると、stackには1巡目の数字が入ってる。それをlast_nodeに設定。
		last_node->next = node;//last_node->nextに2巡目のnodeを接続
		node->prev = last_node;//2巡目の値のnode->prevに1巡目のノードを接続。これでリンクリストが接続される
	}
}

//check_argv checks the arrays are all numbers or not. Even they are numbers, we have to check they are in INT_MAX and IN_MIN
void	check_argv(t_stack_node **a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))//Check if there is only numbers
			free_errors(a);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)//nはatol関数で作られた数字が入るので、この数字がINT_MAXとINT_MINを超えたらエラーを返す（LONG_MAXではなく、INT_MAXである点に注意！）
			free_errors(a);
		if (error_duplicate(*a, (int)n))//Check if there is no duplicate
			free_errors(a);
		append_node(a, (int)n);//If no errors, 
		i++;
	}
}
