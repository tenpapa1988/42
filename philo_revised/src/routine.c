/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:26:15 by yussaito          #+#    #+#             */
/*   Updated: 2025/01/29 14:08:43 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	think(t_philo *philo)
{
	message_print("is thinking", philo, philo->id);
}

void	dream(t_philo *philo)
{
	message_print("is sleeping", philo, philo->id);
	ft_usleep(philo->time_to_sleep);
}

void	take_forks(t_philo *philo)
{
	if (philo->num_of_philos == 1)
	{
		message_print("has taken a fork", philo, philo->id);
		ft_usleep(philo->time_to_die);
		return;
	}

	if (philo->id % 2 == 0) // 偶数 ID の哲学者
	{
		pthread_mutex_lock(philo->r_fork);
		message_print("has taken a fork", philo, philo->id);
		pthread_mutex_lock(philo->l_fork);
		message_print("has taken a fork", philo, philo->id);
	}
	else // 奇数 ID の哲学者
	{
		pthread_mutex_lock(philo->l_fork);
		message_print("has taken a fork", philo, philo->id);
		pthread_mutex_lock(philo->r_fork);
		message_print("has taken a fork", philo, philo->id);
	}
}

void	eat(t_philo *philo)
{
	take_forks(philo);

	if (philo->num_of_philos == 1)
		return;

	// 食事処理。食べ始めの時間を最後に食べた時間に設定している
	philo->eating = 1;
	message_print("is eating", philo, philo->id);
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = get_current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);

	ft_usleep(philo->time_to_eat);//最後に食べた時間＝食べはじめの時間にしてる＆ここを更新できてからtime_to_eatの時間を待つようにしている
	philo->eating = 0;//食べ終わっているので、ここで食べている状態を0にする

	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

// void	eat(t_philo *philo)
// {
// 	if (philo->num_of_philos == 1)
// 	{
// 		message_print("has taken a fork", philo, philo->id);
// 		ft_usleep(philo->time_to_die);
// 		return;
// 	}

// 	if (philo->id % 2 == 0)
// 	{
// 		pthread_mutex_lock(philo->r_fork);
// 		message_print("has taken a fork", philo, philo->id);
// 		pthread_mutex_lock(philo->l_fork);
// 		message_print("has taken a fork", philo, philo->id);
// 	}
// 	else
// 	{
// 		pthread_mutex_lock(philo->l_fork);
// 		message_print("has taken a fork", philo, philo->id);
// 		pthread_mutex_lock(philo->r_fork);
// 		message_print("has taken a fork", philo, philo->id);
// 	}

// 	// 食事処理
// 	philo->eating = 1;
// 	message_print("is eating", philo, philo->id);
// 	pthread_mutex_lock(philo->meal_lock);
// 	philo->last_meal = get_current_time();
// 	philo->meals_eaten++;
// 	pthread_mutex_unlock(philo->meal_lock);

// 	ft_usleep(philo->time_to_eat);
// 	philo->eating = 0;

// 	pthread_mutex_unlock(philo->l_fork);
// 	pthread_mutex_unlock(philo->r_fork);
// }
