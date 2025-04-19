/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:12:48 by nkawaguc          #+#    #+#             */
/*   Updated: 2025/02/08 14:43:11 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/config.h"

static int	get_envp_len(char **envp);

int	init_config(t_config *config, char **envp)
{
	int		i;
	char	*equal;

	config->exit_status = 0;
	config->is_child = 0;
	i = get_envp_len(envp);
	config->envp = ft_calloc(i + 1, sizeof(t_env));
	if (config->envp == NULL)
		return (EXIT_FAILURE);
	config->envp_capacity = i + 1;
	config->envp_num = i;
	i = 0;
	while (envp[i])
	{
		equal = ft_strchr(envp[i], '=');
		if (equal == NULL)
			continue ;
		config->envp[i].key = ft_substr(envp[i], 0, equal - envp[i]);
		config->envp[i].value = ft_strdup(equal + 1);
		if (config->envp[i].key == NULL || config->envp[i].value == NULL)
			return (free_config(config), EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

//環境変数の数を取得
static int	get_envp_len(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
		i++;
	return (i);
}
