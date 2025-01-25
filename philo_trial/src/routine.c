/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:26:15 by yussaito          #+#    #+#             */
/*   Updated: 2025/01/26 08:23:16 by yussaito         ###   ########.fr       */
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

// void	take_forks(t_philo *philo)
// {
// 	if (philo->num_of_philos == 1)
// 	{
// 		message_print("has taken a fork", philo, philo->id);
// 		ft_usleep(philo->time_to_die);
// 		return;
// 	}

// 	if (philo->id % 2 == 0) // 偶数 ID の哲学者
// 	{
// 		pthread_mutex_lock(philo->r_fork);
// 		message_print("has taken a fork", philo, philo->id);
// 		pthread_mutex_lock(philo->l_fork);
// 		message_print("has taken a fork", philo, philo->id);
// 	}
// 	else // 奇数 ID の哲学者
// 	{
// 		pthread_mutex_lock(philo->l_fork);
// 		message_print("has taken a fork", philo, philo->id);
// 		pthread_mutex_lock(philo->r_fork);
// 		message_print("has taken a fork", philo, philo->id);
// 	}
// }

// void	eat(t_philo *philo)
// {
// 	take_forks(philo);

// 	if (philo->num_of_philos == 1)
// 		return;

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

void eat(t_philo *philo) {
    // フォークを取得する前に死亡フラグをチェック
    if (dead_loop(philo))
        return;

    // 左フォークを先に取得
    pthread_mutex_lock(philo->l_fork);
    message_print("has taken a fork", philo, philo->id);

    // 右フォークを次に取得
    pthread_mutex_lock(philo->r_fork);
    message_print("has taken a fork", philo, philo->id);

    // 食事処理
    philo->eating = 1;
    message_print("is eating", philo, philo->id);

    pthread_mutex_lock(philo->meal_lock);
    philo->last_meal = get_current_time();
    philo->meals_eaten++;
    pthread_mutex_unlock(philo->meal_lock);

    // 食事中の時間
    ft_usleep(philo->time_to_eat);

    // 食事完了後の処理
    philo->eating = 0;

    // フォークを返す
    pthread_mutex_unlock(philo->l_fork);
    pthread_mutex_unlock(philo->r_fork);
}
