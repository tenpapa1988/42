/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:57:17 by yussaito          #+#    #+#             */
/*   Updated: 2025/01/18 10:15:03 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//Check if the value of dead_flag changed
int	dead_loop(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == 1)
		return (pthread_mutex_unlock(philo->dead_lock), 1);
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

//Thread Routine
void	*philo_routine(void *pointer)
{
	t_philo *philo;

	philo = (t_philo *)pointer;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (!dead_loop(philo))
	{
		eat(philo);
		dream(philo);
		think(philo);
	}
	return (pointer);
}

//Create threads
int	thread_create(t_program *program, pthread_mutex_t *forks)
{
	pthread_t	observer;
	int			i;

	if (pthread_create(&observer, NULL, &monitor, program->philos) != 0)//哲学者の脂肪や終了条件を監視するobserverスレッドを作成し、monitor関数をその中で実行
		destroy_all("Creating Threads Error", program, forks);//pthread_createがエラーだと0以外が返る
	i = 0;
	while (i < program->philos[0].num_of_philos)
	{
		if (pthread_create(&program->philos[i].thread, NULL, &philo_routine,
				&program->philos[i]) != 0)//哲学者ごとのスレッドを作成＆philo_routine関数の実行
			destroy_all("Thread creation error", program, forks);
		i++;
	}
	i = 0;
	if (pthread_join(observer, NULL) != 0)//obseverスレッドが終わるまで待つ。monitor関数が終了するまでメインスレッドがブロックされる
		destroy_all("Joining Thread Error", program, forks);
	while (i < program->philos[0].num_of_philos)//各哲学者スレッドの終了を待機。スレッド終了までメインスレッドがブロック
	{
		if (pthread_join(program->philos[i].thread, NULL) != 0)
			destroy_all("Joing Thread Error", program, forks);
		i++;
	}
	return (0);//pthread_destroyはmain関数にて対応！
}