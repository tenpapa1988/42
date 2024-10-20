/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 15:20:45 by yussaito          #+#    #+#             */
/*   Updated: 2024/10/12 15:51:58 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	error_handing(int errnom)
{
	if (errnom == INPUT_ERROR)
		ft_printf("Usage: ./client [PID] [string]");
	if (errnom == PID_ERROR)
		ft_printf("PID is invalid");
	if (errnom == KILL_ERROR)
		ft_printf("Kill command error");
	exit(EXIT_FAILURE);
}

static void	send_bit(pid_t s_pid, char c)
{
	int	sig;
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c >> i & 1)
			sig = SIGUSR1;
		else
			sig = SIGUSR2;
		if (kill(s_pid, sig) == -1)
			error_handing(KILL_ERROR);
		usleep(3000);
		i--;
	}
}

static int	check_pid(char *c_pid)
{
	int	i_pid;

	i_pid = ft_atoi(c_pid);
	if (i_pid <= 1)
		error_handing(PID_ERROR);
	return (i_pid);
}

int	main(int argc, char **argv)
{
	size_t	i;
	size_t	len;
	pid_t	i_pid;

	if (argc != 3)
		error_handing(INPUT_ERROR);
	i_pid = check_pid(argv[1]);
	len = ft_strlen(argv[2]);
	i = 0;
	while (i <= len)
	{
		send_bit(i_pid, argv[2][i]);
		i++;
	}
	return (EXIT_SUCCESS);
}
