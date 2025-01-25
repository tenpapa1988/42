/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:00:59 by yussaito          #+#    #+#             */
/*   Updated: 2025/01/25 13:18:12 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	message_print(char *str, t_philo *philo, int id)
{
	size_t	time;

	pthread_mutex_lock(philo->write_lock);//複数のスレッドが同時にメッセージ出力をすることを防ぐため
	time = get_current_time() - philo->start_time;
	if (!dead_loop(philo))//出力前に、哲学者が死んでいないか？をチェック（この関数内でチェックすることで、メッセージを出力する前には必ず死亡の哲学者がいないか？をチェックできる
		printf("%zu %d %s\n", time, id, str);//メッセージ出力
	pthread_mutex_unlock(philo->write_lock);//ロックを解除
}

//Check if any philosophers are dead
//死んでいるか？の確認は「死ぬまでの時間以上に経過してないか？」「食事中じゃないか？」を確認する
int	philosopher_dead(t_philo *philo, size_t time_to_die)
{
	pthread_mutex_lock(philo->meal_lock);
	if (get_current_time() - philo->last_meal >= time_to_die
		&& philo->eating == 0)//philo->eatingは食事中の場合に1になる。last_mealの時間が更新されるのは食後なので食事中のフラグを活用することで食事中なのに死亡と判定されないようにしている
	{
		pthread_mutex_unlock(philo->meal_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->meal_lock);
	return (0);
}

//Check if any philos are dead
int	check_if_dead(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos[0].num_of_philos)//num_of_philosは哲学者全員に共通するデータなので、philo[0]でもphilo[1]でも良いのだけど、共通データの場合には[0]にアクセスするのが通例らしい。ちなみに、philos->num_of_philosでもよいけど、現状の方が他のコードとの比較としてわかりやすいのでこうしてるっぽい
	{
		if (philosopher_dead(&philos[i], philos[i].time_to_die))
		{
			message_print("died", &philos[i], philos[i].id);
			pthread_mutex_lock(philos[0].dead_lock);
			*philos->dead = 1;
			pthread_mutex_unlock(philos[0].dead_lock);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_if_all_ate(t_philo *philos)
{
	int	i;
	int	finished_eating;

	i = 0;
	finished_eating = 0;
	if (philos[0].num_times_to_eat == -1)//食事の制限回数の指定がない場合には-1が立つ（init_input関数にて対応）
		return (0);
	while (i < philos[0].num_of_philos)//哲学者の数までiを回しながら、finished_eatingをチェック
	{
		pthread_mutex_lock(philos[i].meal_lock);
		if (philos[i].meals_eaten >= philos[i].num_times_to_eat)
			finished_eating++;
		pthread_mutex_unlock(philos[i].meal_lock);
		i++;
	}
	if (finished_eating == philos[0].num_of_philos)//finished eatingと哲学者の数が一致する場合には死亡フラグを立てる
	{
		pthread_mutex_lock(philos[0].dead_lock);
		*philos->dead = 1;
		pthread_mutex_unlock(philos[0].dead_lock);
		return (1);
	}
	return (0);
}

//Monitor thread routine
void	*monitor(void *pointer)
{
	t_philo	*philos;

	philos = (t_philo *)pointer;//void型で渡ってくるので扱いたい型にキャストする
	while (1)
	{
		if (check_if_dead(philos) == 1 || check_if_all_ate(philos) == 1)
			break;
		usleep(10);
	}
	return (pointer);
}

