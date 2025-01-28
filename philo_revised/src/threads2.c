/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:57:17 by yussaito          #+#    #+#             */
/*   Updated: 2025/01/28 10:53:14 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//Check if the value of dead_flag changed
int	dead_loop(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == 1)
	{
		pthread_mutex_unlock(philo->dead_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

//Thread Routine
void	*philo_routine(void *pointer)
{
	t_philo *philo;

	philo = (t_philo *)pointer;
	if (philo->id % 2 == 0)//偶数の哲学者がフォークを取るタイミングを微妙に遅らせることでデッドロックを避ける
		ft_usleep(5);
	while (!dead_loop(philo))//課題の中で出力の例がeat, sleep, thinkなので、これに合わせている
	{
		eat(philo);
		dream(philo);
		think(philo);
	}
	return (pointer);
}
