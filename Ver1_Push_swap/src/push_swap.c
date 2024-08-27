/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 10:16:08 by yussaito          #+#    #+#             */
/*   Updated: 2024/08/26 12:22:55 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//https://bussorenre.hatenablog.jp/entry/2014/07/02/103959 <- Check what is "envp"?
// int	main(int argc, char **argv, char **envp)
// {
// 	t_stack_node	*a;
// 	t_stack_node	*b;
// 	char			**split_argv;
// 	size_t			max_agrgs;
// 	size_t			arg_count;

// 	a = NULL;
// 	b = NULL;
// 	split_argv = NULL;
// 	max_agrgs = cal_max_args(envp);
// 	if (argc == 1 || (argc == 2 && !argv[1][0])
// 		|| ((size_t)argc > max_agrgs + 1))//argv[1][0] is like ./push_swap "". This example show there is nothing in the argv[1]
// 		return (1);
// 	else if (argc == 2)
// 	{
// 		split_argv = split(argv[1], ' ');
// 		arg_count = 0;
// 		while (split_argv[arg_count])
// 			arg_count++;
// 		if (arg_count > max_agrgs)
// 		{
// 			free_split(split_argv);
// 			return (1);
// 		}
// 		argv = split_argv;
// 	}
// 	check_argv(&a, argv + 1);//Now argv becomes arrays even though the argv is 2 and the array is like "42 98 90"
// 	if (!stack_sorted(a))//Check if the stack is not sorted
// 	{
// 		if (stack_len(a) == 2)
// 			sa(&a, false);
// 		else if (stack_len(a) == 3)
// 			sort_three(&a);
// 		else
// 			sort_stacks(&a, &b);
// 	}
// 	free_stack(&a);
// 	if (split_argv)
// 		free_split(split_argv);
// 	return (0);
// }

//https://chatgpt.com/share/72329b51-8089-4ee5-92e4-0b940c09a0f8
//上のmainはargv == 2の時にargvを更新しているが、下のmainでは新しい配列（new_argv)を作って更新している

// int	main(int argc, char **argv, char **envp)
// {
// 	t_stack_node	*a;
// 	t_stack_node	*b;
// 	char			**split_argv;
// 	char			**new_argv;
// 	size_t			max_agrgs;
// 	size_t			arg_count;
// 	size_t			i;

// 	a = NULL;
// 	b = NULL;
// 	split_argv = NULL;
// 	max_agrgs = cal_max_args(envp);
// 	new_argv = NULL;
// 	if (argc == 1 || (argc == 2 && !argv[1][0])
// 		|| ((size_t)argc > max_agrgs + 1))
// 		return (1);
// 	else if (argc == 2)
// 	{
// 		split_argv = split(argv[1], ' ');
// 		arg_count = 0;
// 		while (split_argv[arg_count])
// 			arg_count++;
// 		if (arg_count > max_agrgs)
// 		{
// 			free_split(split_argv);
// 			return (1);
// 		}
// 		new_argv = malloc(sizeof(char *) * (arg_count + 2));// argc + 1 for NULL termination
// 		new_argv[0] = argv[0];// Program name
// 		i = 0;
// 		while (i < arg_count)
// 		{
// 			new_argv[i + 1] = split_argv[i];
// 			i++;
// 		}
// 		new_argv[arg_count + 1] = NULL;// NULL termination
// 		argv = new_argv;
// 		argc = arg_count + 1;
// 	}
// 	check_argv(&a, argv + 1);// Now argv[1] is "4", etc.
// 	if (!stack_sorted(a))
// 	{
// 		if (stack_len(a) == 2)
// 			sa(&a, false);
// 		else if (stack_len(a) == 3)
// 			sort_three(&a);
// 		else
// 			sort_stacks(&a, &b);
// 	}
// 	free_stack(&a);
// 	if (split_argv)
// 		free_split(split_argv);
// 	if (new_argv)
// 		free(new_argv);
// 	return (0);
// }

// int	main(int argc, char **argv)
// {
// 	t_stack_node	*a;
// 	t_stack_node	*b;
// 	char			**split_argv;
// 	char			**new_argv;
// 	size_t			arg_count;
// 	size_t			i;

// 	a = NULL;
// 	b = NULL;
// 	split_argv = NULL;
// 	new_argv = NULL;
// 	if (argc == 1 || (argc == 2 && !argv[1][0]))
// 		return (1);
// 	else if (argc == 2)
// 	{
// 		split_argv = split(argv[1], ' ');
// 		arg_count = 0;
// 		while (split_argv[arg_count])
// 			arg_count++;
// 		new_argv = malloc(sizeof(char *) * (arg_count + 2));// argc + 1 for NULL termination
// 		new_argv[0] = argv[0];// Program name
// 		i = 0;
// 		while (i < arg_count)
// 		{
// 			new_argv[i + 1] = split_argv[i];
// 			i++;
// 		}
// 		new_argv[arg_count + 1] = NULL;// NULL termination
// 		argv = new_argv;
// 		argc = arg_count + 1;
// 	}
// 	check_argv(&a, argv + 1);// Now argv[1] is "4", etc.
// 	if (!stack_sorted(a))
// 	{
// 		if (stack_len(a) == 2)
// 			sa(&a, false);
// 		else if (stack_len(a) == 3)
// 			sort_three(&a);
// 		else
// 			sort_stacks(&a, &b);
// 	}
// 	free_stack(&a);
// 	if (split_argv)
// 		free_split(split_argv);
// 	if (new_argv)
// 		free(new_argv);
// 	return (0);
// }

// 関数1: 初期化と引数のチェック
static void	initialize_and_check_args(int argc, char **argv, t_stack_node **a, t_stack_node **b, char ***split_argv, char ***new_argv)
{
	*a = NULL;
	*b = NULL;
	*split_argv = NULL;
	*new_argv = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		exit(1);
}

// 関数2: 引数を分割し、新しいargvを構築
static size_t	split_and_prepare_argv(int argc, char **argv, char ***split_argv, char ***new_argv)
{
	size_t arg_count;
	size_t i;

	arg_count = 0;
	i = 0;
	if (argc == 2)
	{
		*split_argv = split(argv[1], ' ');
		while ((*split_argv)[arg_count])
			arg_count++;
		*new_argv = malloc(sizeof(char *) * (arg_count + 2));//arg_countは初期値が０なので、最初の値で＋１、最後のNULLで＋１、合計＋２になる
		if (new_argv == NULL)
		{
			free_split(*split_argv);
			return (0);
		}
		(*new_argv)[0] = argv[0];
		while (i < arg_count)//ここでargvの中身をnew_argvに入れていく
		{
			(*new_argv)[i + 1] = (*split_argv)[i];
			i++;
		}
		(*new_argv)[arg_count + 1] = NULL;//最後にNULLを入れる
	}
	return (arg_count);
}

// 関数3: スタックを初期化しソート
static void	initialize_stack_and_sort(t_stack_node **a, t_stack_node **b, char **argv)
{
	check_argv(a, argv + 1);
	if (!stack_sorted(*a))
	{
		if (stack_len(*a) == 2)//stackの長さが2つで、ソートされていない場合には、saすればOK
			sa(a, false);
		else if (stack_len(*a) == 3)//stackの長さが3つだったら、sort_threeを実行
			sort_three(a);
		else
			sort_stacks(a, b);
	}
}

// 関数4: メモリを解放
static void	free_memory(t_stack_node **a, char **split_argv, char **new_argv)
{
	free_stack(a);
	if (split_argv)
		free_split(split_argv);
	if (new_argv)
		free(new_argv);
}

// 関数5: メイン関数
int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**split_argv;
	char			**new_argv;
	size_t			arg_count;

	initialize_and_check_args(argc, argv, &a, &b, &split_argv, &new_argv);
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
