/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:57:17 by yussaito          #+#    #+#             */
/*   Updated: 2025/01/28 11:16:53 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int join_threads(t_program *program, pthread_t *observer, pthread_mutex_t *forks)
{
    int i;

    // 監視スレッドの終了を待機
    if (pthread_join(*observer, NULL) != 0)
	{
        destroy_all("Joining Thread'Err", program, forks);
        return (1);
    }

    // 哲学者スレッドの終了を待機
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

int create_even_threads(t_program *program, pthread_mutex_t *forks)
{
    int i = 0;

    while (i < program->philos[0].num_of_philos)
	{
        if (i % 2 == 0) {
            if (pthread_create(&program->philos[i].thread,
				NULL, &philo_routine, &program->philos[i]) != 0)
			{
                destroy_all("Creating Even Thread'Err", program, forks);
                return (1);
            }
        }
        i++;
    }
    return (0);
}
int create_odd_threads(t_program *program, pthread_mutex_t *forks) 
{
    int i = 0;

    ft_usleep(program->philos[0].time_to_eat);
    while (i < program->philos[0].num_of_philos)
	{
        if (i % 2 != 0)
		{
            if (pthread_create(&program->philos[i].thread,
				NULL, &philo_routine, &program->philos[i]) != 0)
			{
                destroy_all("Creating Odd Thread'Err", program, forks);
                return (1);
            }
        }
        i++;
    }
    return (0);
}


int create_philosopher_threads(t_program *program, pthread_mutex_t *forks)
{
    if (create_even_threads(program, forks) != 0)
        return (1);
    if (create_odd_threads(program, forks) != 0)
        return (1);
    return (0);
}

int thread_create(t_program *program, pthread_mutex_t *forks)
{
    pthread_t observer;

    // 監視スレッドの作成
    if (pthread_create(&observer, NULL, &monitor, program->philos) != 0)
	{
        destroy_all("Creating Thread'Err", program, forks);
        return (1);
    }

    // 哲学者スレッドの作成
    if (create_philosopher_threads(program, forks) != 0)
        return (1);

    // スレッドの終了を待機
    if (join_threads(program, &observer, forks) != 0)
        return (1);

    return (0);
}

//Create threads
// obseverスレッドを立ち上げて、次にそれぞれの哲学者のスレッドを作る。終えるときにはobseverスレッド（死ぬか必要回数以上食べたとき）が終了！と合図を鳴らしてから各哲学者のスレッドを閉じる必要がある
// int	thread_create(t_program *program, pthread_mutex_t *forks)
// {
// 	pthread_t	observer;
// 	int			i;

// 	if (pthread_create(&observer, NULL, &monitor, program->philos) != 0)//哲学者の脂肪や終了条件を監視するobserverスレッドを作成し、monitor関数をその中で実行
// 		destroy_all("Creating Threads Error", program, forks);//pthread_createがエラーだと0以外が返る
// 	i = 0;
// 	while (i < program->philos[0].num_of_philos)//哲学者の数まで回していく
// 	{
// 		if (pthread_create(&program->philos[i].thread, NULL, &philo_routine,
// 				&program->philos[i]) != 0)//哲学者ごとのスレッドを作成＆philo_routine関数の実行
// 			destroy_all("Thread creation error", program, forks);
// 		i++;
// 	}
// 	i = 0;
// 	if (pthread_join(observer, NULL) != 0)//obseverスレッドが終わるまで待つ。monitor関数が終了するまでメインスレッドがブロックされる（待つというのは本当にここから先には進まない！という意味）
// 		destroy_all("Joining Thread Error", program, forks);//mallocのときのエラー処理のように、ここでもエラーが発生した際にはすべてを開放するようにしている
// 	while (i < program->philos[0].num_of_philos)//各哲学者スレッドの終了を待機。スレッド終了までメインスレッドがブロック
// 	{
// 		if (pthread_join(program->philos[i].thread, NULL) != 0)
// 			destroy_all("Joing Thread Error", program, forks);
// 		i++;
// 	}
// 	return (0);//pthread_destroyはmain関数にて対応！
// }

// int thread_create(t_program *program, pthread_mutex_t *forks)
// {
//     pthread_t observer;
//     int i;

//     if (pthread_create(&observer, NULL, &monitor, program->philos) != 0)
//     {
//         destroy_all("Creating Observer Thread Error", program, forks);
//         return (1);
//     }

//     // 偶数IDの哲学者スレッドを作成
//     i = 0;
//     while (i < program->philos[0].num_of_philos)
//     {
//         if (i % 2 == 0)
//         {
//             if (pthread_create(&program->philos[i].thread, NULL, &philo_routine, &program->philos[i]) != 0)
//             {
//                 destroy_all("Creating Even Philosopher Thread Error", program, forks);
//                 return (1);
//             }
//         }
//         i++;
//     }

//     // タイミングをずらして奇数IDの哲学者スレッドを作成
//     ft_usleep(program->philos[0].time_to_eat);
//     i = 0;
//     while (i < program->philos[0].num_of_philos)
//     {
//         if (i % 2 != 0)
//         {
//             if (pthread_create(&program->philos[i].thread, NULL, &philo_routine, &program->philos[i]) != 0)
//             {
//                 destroy_all("Creating Odd Philosopher Thread Error", program, forks);
//                 return (1);
//             }
//         }
//         i++;
//     }

//     // 監視スレッドの終了を待機
//     if (pthread_join(observer, NULL) != 0)
//     {
//         destroy_all("Joining Observer Thread Error", program, forks);
//         return (1);
//     }

//     // 各哲学者スレッドの終了を待機
//     i = 0;
//     while (i < program->philos[0].num_of_philos)
//     {
//         if (pthread_join(program->philos[i].thread, NULL) != 0)
//         {
//             destroy_all("Joining Philosopher Thread Error", program, forks);
//             return (1);
//         }
//         i++;
//     }
//     return (0);
// }