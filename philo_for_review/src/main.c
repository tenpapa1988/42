/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 08:03:05 by yussaito          #+#    #+#             */
/*   Updated: 2025/02/04 08:16:54 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_arg_content(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	const_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	print_error(const char *msg)
{
	int	ret;

	ret = write(2, msg, const_strlen(msg));
	if (ret < 0)
		return (1);
	return (1);
}

int	check_val_args(char **argv)
{
	if (ft_atoi(argv[1]) > PHILO_MAX || ft_atoi(argv[1]) <= 0
		|| check_arg_content(argv[1]) == 1)
		return (print_error("Invalid philosophers number\n"));
	if (ft_atoi(argv[2]) <= 0 || check_arg_content(argv[2]) == 1)
		return (print_error("Invalid time to die\n"));
	if (ft_atoi(argv[3]) <= 0 || check_arg_content(argv[3]) == 1)
		return (print_error("Invalid time to eat\n"));
	if (ft_atoi(argv[4]) <= 0 || check_arg_content(argv[4]) == 1)
		return (print_error("Invalid time to sleep\n"));
	if (argv[5] && (ft_atoi(argv[5]) < 0 || check_arg_content(argv[5]) == 1))
		return (print_error("Invalid must eat num\n"));
	return (0);
}

int	main(int argc, char **argv)
{
	t_program		program;
	t_philo			philos[PHILO_MAX];
	pthread_mutex_t	forks[PHILO_MAX];

	if (argc != 5 && argc != 6)
		return (print_error("Wrong arg count\n"));
	if (check_val_args(argv) == 1)
		return (1);
	init_program(&program, philos);
	init_forks(forks, ft_atoi(argv[1]));
	init_philos(philos, &program, forks, argv);
	thread_create(&program, forks);
	destroy_all(NULL, &program, forks);
	return (0);
}
