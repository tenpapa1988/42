/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 22:56:17 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/11/30 11:08:41 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

int	exec_bi(t_node *node, t_exec *exec, t_config *config)
{
	const int	stdin_fd = dup(STDIN_FILENO);
	const int	stdout_fd = dup(STDOUT_FILENO);

	config->exit_status = construct_bi_exec(exec, node, config);
	if (config->exit_status != EXIT_SUCCESS)
		return (free_exec(exec), config->exit_status);
	exec_bi_command(*exec, config);
	free_exec(exec);
	dup2(stdin_fd, STDIN_FILENO);
	dup2(stdout_fd, STDOUT_FILENO);
	close(stdin_fd);
	close(stdout_fd);
	return (config->exit_status);
}
