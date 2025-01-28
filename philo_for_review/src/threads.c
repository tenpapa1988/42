/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:57:17 by yussaito          #+#    #+#             */
/*   Updated: 2025/01/28 11:24:15 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	join_threads(t_program *program,
		pthread_t *observer, pthread_mutex_t *forks)
{
	int	i;

	if (pthread_join(*observer, NULL) != 0)
	{
		destroy_all("Joining Thread'Err", program, forks);
		return (1);
	}
	i = 0;
	while (i < program->philos[0].num_of_philos)
	{
		if (pthread_join(program->philos[i].thread, NULL) != 0)
		{
			destroy_all("Philo Thread'Err", program, forks);
			return (1);
		}
		i++;
	}
	return (0);
}

int	create_even_threads(t_program *program, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < program->philos[0].num_of_philos)
	{
		if (i % 2 == 0)
		{
			if (pthread_create(&program->philos[i].thread, NULL,
					&philo_routine, &program->philos[i]) != 0)
			{
				destroy_all("Creating Even Thread'Err", program, forks);
				return (1);
			}
		}
		i++;
	}
	return (0);
}

int	create_odd_threads(t_program *program, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	ft_usleep(program->philos[0].time_to_eat);
	while (i < program->philos[0].num_of_philos)
	{
		if (i % 2 != 0)
		{
			if (pthread_create(&program->philos[i].thread, NULL,
					&philo_routine, &program->philos[i]) != 0)
			{
				destroy_all("Creating Odd Thread'Err", program, forks);
				return (1);
			}
		}
		i++;
	}
	return (0);
}

int	create_philosopher_threads(t_program *program, pthread_mutex_t *forks)
{
	if (create_even_threads(program, forks) != 0)
		return (1);
	if (create_odd_threads(program, forks) != 0)
		return (1);
	return (0);
}

int	thread_create(t_program *program, pthread_mutex_t *forks)
{
	pthread_t	observer;

	if (pthread_create(&observer, NULL, &monitor, program->philos) != 0)
	{
		destroy_all("Creating Thread'Err", program, forks);
		return (1);
	}
	if (create_philosopher_threads(program, forks) != 0)
		return (1);
	if (join_threads(program, &observer, forks) != 0)
		return (1);
	return (0);
}
