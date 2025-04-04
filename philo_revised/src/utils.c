/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:00:55 by yussaito          #+#    #+#             */
/*   Updated: 2025/01/29 14:44:25 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *str)
{
	int	i;

	if (str == NULL)	
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	if (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (sign * res);

}

//ヘッダーファイルにてpthread_mutex_tで指定した変数をすべて解放する必要がある
//write_lock, dead_lock, meal_lockについてはt_program側で管理しているので、こちらを解放すればOK。l_forkとr_forkはt_philo側で管理しているので、これは別途解放する必要がある
void	destroy_all(char *str, t_program *program, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	if (str)
	{
		write(2, str, ft_strlen(str));
		write(2, "\n", 1);
	}
	pthread_mutex_destroy(&program->write_lock);
	pthread_mutex_destroy(&program->meal_lock);
	pthread_mutex_destroy(&program->dead_lock);
	while(i < program->philos[0].num_of_philos)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}

//usleepをそのまま使うと誤差が生じるので、正しい時間で処理できるように変換している
int	ft_usleep(size_t millisecond)
{
	size_t	start;

	start = get_current_time();
	while((get_current_time() - start) < millisecond)
		usleep(500);
	return (0);
}

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday Error\n", 20);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);//課題の中でms（ミリ秒）で単位が出ているのでミリ秒で扱う
}
//time.tv_secは秒、time.tv_usecはマイクロ秒で出力される
//1秒に1000を掛けることでミリ秒に、time.tv_usecを1000で割ることでミリ秒に単位変換している
