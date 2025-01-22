/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:26:15 by yussaito          #+#    #+#             */
/*   Updated: 2025/01/22 08:33:04 by yussaito         ###   ########.fr       */
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

// void	eat(t_philo *philo)
// {
// 	pthread_mutex_lock(philo->r_fork);
// 	message_print("has taken a fork", philo, philo->id);//ロックに成功してから、メッセージを出す
	// if (philo->num_of_philos == 1)
	// {
	// 	ft_usleep(philo->time_to_die);//哲学者が一人の場合にはフォークがないので死ぬしか無い→死ぬ時間までusleepするようにしている
	// 	pthread_mutex_unlock(philo->r_fork);
	// 	return ;
	// }
// 	pthread_mutex_lock(philo->l_fork);
// 	message_print("has taken a fork", philo, philo->id);
// 	philo->eating = 1;//ロックに成功してから状態を更新する
// 	message_print("is eating", philo, philo->id);
// 	pthread_mutex_lock(philo->meal_lock);
// 	philo->last_meal = get_current_time();
// 	philo->meals_eaten++;
// 	pthread_mutex_unlock(philo->meal_lock);
// 	ft_usleep(philo->time_to_eat);
// 	philo->eating = 0;//食べ終わったら状態を戻す
// 	pthread_mutex_unlock(philo->l_fork);
// 	pthread_mutex_unlock(philo->r_fork);
// }

void	eat(t_philo *philo)
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

	// 食事処理
	philo->eating = 1;
	message_print("is eating", philo, philo->id);
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = get_current_time();
	philo->meals_eaten++;
	// printf("[DEBUG] Philosopher %d has eaten %d times\n", philo->id, philo->meals_eaten);
	pthread_mutex_unlock(philo->meal_lock);

	ft_usleep(philo->time_to_eat);
	philo->eating = 0;

	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}
