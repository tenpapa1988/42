/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 08:03:19 by yussaito          #+#    #+#             */
/*   Updated: 2025/02/05 08:53:09 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define PHILO_MAX 200

# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eating;
	int				meals_eaten;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	int				num_of_philos;
	int				num_times_to_eat;
	int				*dead;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}					t_philo;

typedef struct s_program
{
	int				dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	t_philo			*philos;
}					t_program;

int					check_arg_content(char *arg);
int					const_strlen(const char *str);
int					print_error(const char *msg);
int					check_val_args(char **argv);
void				destroy_all(char *str, t_program *program,
						pthread_mutex_t *forks);

void				init_program(t_program *program, t_philo *philos);
void				init_forks(pthread_mutex_t *forks, int philo_num);
void				init_philos(t_philo *philos, t_program *program,
						pthread_mutex_t *forks, char **argv);
void				init_input(t_philo *philo, char **argv);

int					create_philosopher_threads(t_program *program,
						pthread_mutex_t *forks);
int					thread_create(t_program *program,
						pthread_mutex_t *forks);
int					create_odd_threads(t_program *program,
						pthread_mutex_t *forks);
int					create_even_threads(t_program *program,
						pthread_mutex_t *forks);
int					join_threads(t_program *program, pthread_t *observer,
						pthread_mutex_t *forks);
void				*monitor(void *pointer);
void				*philo_routine(void *pointer);

void				eat(t_philo *philo);
void				dream(t_philo *philo);
void				think(t_philo *philo);
void				take_forks(t_philo *philo);

int					dead_loop(t_philo *philo);
int					check_if_all_ate(t_philo *philos);
int					check_if_dead(t_philo *philos);
int					philosopher_dead(t_philo *philo, size_t time_to_die);

int					ft_atoi(char *str);
int					ft_usleep(size_t microseconds);
int					ft_strlen(char *str);
void				message_print(char *str, t_philo *philo, int id);
size_t				get_current_time(void);

#endif