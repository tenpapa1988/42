/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 21:26:15 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/11/24 17:31:03 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/builtin.h"

static void	del_env(int k, t_config *config);

void	bi_unset(t_exec exec, t_config *config)
{
	int	i;
	int	j;

	i = 1;
	if (!exec.argv[i])
	{
		config->exit_status = EXIT_SUCCESS;
		return ;
	}
	while (exec.argv[i])
	{
		j = 0;
		while (j < config->envp_num)
		{
			if (ft_strcmp(exec.argv[i], config->envp[j].key) == 0)
			{
				del_env(j, config);
				break ;
			}
			j++;
		}
		i++;
	}
	config->exit_status = EXIT_SUCCESS;
}

static void	del_env(int k, t_config *config)
{
	free(config->envp[k].key);
	free(config->envp[k].value);
	while (k < config->envp_num - 1)
	{
		config->envp[k] = config->envp[k + 1];
		k++;
	}
	config->envp_num--;
	config->envp[config->envp_num].key = NULL;
	config->envp[config->envp_num].value = NULL;
}
