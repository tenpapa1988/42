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
		ft_usleep(1);
	while (!dead_loop(philo))//課題の中で出力の例がeat, sleep, thinkなので、これに合わせている
	{
		eat(philo);
		dream(philo);
		think(philo);
	}
	return (pointer);
}

//Create threads
//obseverスレッドを立ち上げて、次にそれぞれの哲学者のスレッドを作る。終えるときにはobseverスレッド（死ぬか必要回数以上食べたとき）が終了！と合図を鳴らしてから各哲学者のスレッドを閉じる必要がある
int	thread_create(t_program *program, pthread_mutex_t *forks)
{
	pthread_t	observer;
	int			i;

	if (pthread_create(&observer, NULL, &monitor, program->philos) != 0)//哲学者の脂肪や終了条件を監視するobserverスレッドを作成し、monitor関数をその中で実行
		destroy_all("Creating Threads Error", program, forks);//pthread_createがエラーだと0以外が返る
	i = 0;
	while (i < program->philos[0].num_of_philos)//哲学者の数まで回していく
	{
		if (pthread_create(&program->philos[i].thread, NULL, &philo_routine,
				&program->philos[i]) != 0)//哲学者ごとのスレッドを作成＆philo_routine関数の実行
			destroy_all("Thread creation error", program, forks);
		i++;
	}
	i = 0;
	if (pthread_join(observer, NULL) != 0)//obseverスレッドが終わるまで待つ。monitor関数が終了するまでメインスレッドがブロックされる（待つというのは本当にここから先には進まない！という意味）
		destroy_all("Joining Thread Error", program, forks);//mallocのときのエラー処理のように、ここでもエラーが発生した際にはすべてを開放するようにしている
	while (i < program->philos[0].num_of_philos)//各哲学者スレッドの終了を待機。スレッド終了までメインスレッドがブロック
	{
		if (pthread_join(program->philos[i].thread, NULL) != 0)
			destroy_all("Joing Thread Error", program, forks);
		i++;
	}
	return (0);//pthread_destroyはmain関数にて対応！
}

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
	pthread_mutex_unlock(philo->meal_lock);

	ft_usleep(philo->time_to_eat);
	philo->eating = 0;

	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

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


void	init_input(t_philo *philo, char **argv)
{
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	philo->num_of_philos = ft_atoi(argv[1]);
	if (argv[5])
		philo->num_times_to_eat = ft_atoi(argv[5]);
	else
		philo->num_times_to_eat = -1;//回数制限がない場合には、-1で特別な値を入れている
}

//Initialize the philosophers
void	init_philos(t_philo *philos, t_program *program, pthread_mutex_t *forks,
					char **argv)
{
	int i;
	
	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		philos[i].id = i + 1;//philoのIDは1からスタート（配列的には0からだけど、IDは1から）
		philos[i].eating = 0;
		philos[i].meals_eaten = 0;
		init_input(&philos[i], argv);
		philos[i].start_time = get_current_time();
		philos[i].last_meal = get_current_time();
		philos[i].write_lock = &program->write_lock;
		philos[i].dead_lock = &program->dead_lock;
		philos[i].meal_lock = &program->meal_lock;
		philos[i].dead = &program->dead_flag;
		philos[i].l_fork = &forks[i];
		if (i == 0)//最初の哲学者は右フォークは哲学者の人数-1のフォークだから
			philos[i].r_fork = &forks[philos[i].num_of_philos - 1];
		else
			philos[i].r_fork = &forks[i - 1];//2人目以降は自分の右は自分-1のフォークになる
		i++;
	}
}

//Initialize the forks
void	init_forks(pthread_mutex_t *forks, int philo_num)
{
	int	i;

	i = 0;
	while (i < philo_num)
	{
		pthread_mutex_init(&forks[i], NULL);//mutexを使用する場合には必ず初期化！
		i++;
	}
}

//Initialize the program structure
void	init_program(t_program *program, t_philo *philos)
{
	program->dead_flag = 0;
	program->philos = philos;//ポインタを渡しているだけ
	pthread_mutex_init(&program->write_lock, NULL);
	pthread_mutex_init(&program->dead_lock, NULL);
	pthread_mutex_init(&program->meal_lock, NULL);
}


//Check if the argv is only number
int	check_arg_content(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

//Check if the args are valid
int	check_val_args(char **argv)
{
	if (ft_atoi(argv[1]) > PHILO_MAX || ft_atoi(argv[1]) <= 0
		|| check_arg_content(argv[1]) == 1)
		return (write(2, "Invalid philosophers number\n", 29), 1);
	if (ft_atoi(argv[2]) <= 0 || check_arg_content(argv[2]) == 1)
		return (write(2, "Invalid time to die\n", 21), 1);
	if (ft_atoi(argv[3]) <= 0 || check_arg_content(argv[3]) == 1)
		return (write(2, "Invalid time to eat\n", 21), 1);
	if (ft_atoi(argv[4]) <= 0 || check_arg_content(argv[4]) == 1)
		return (write(2, "Invalid time to sleep\n", 23), 1);
	if (argv[5] && (ft_atoi(argv[5]) < 0 || check_arg_content(argv[5]) == 1))
		return (write(2, "Invalid number of times each philosopher must eat\n",
				51), 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_program		program;
	t_philo			philos[PHILO_MAX];
	pthread_mutex_t	forks[PHILO_MAX];

	if (argc != 5 && argc != 6)
		return (write(2, "Wrong argument count\n", 22), 1);
	if (check_val_args(argv) == 1)
		return (1);
	init_program(&program, philos);//programは構造体なので&が必須。philosは配列なので&不要。＆無くても先頭のアドレスを渡せる
	init_forks(forks, ft_atoi(argv[1]));//フォークの数はphiloの数と同値
	init_philos(philos, &program, forks, argv);//それぞれの哲学者を初期化する
	thread_create(&program, forks);//threadを作る（全体と哲学者一人ひとりで）
	destroy_all(NULL,&program, forks);//エラーに入らずに正常に動作したときにはdestroyがされないので、最後にここで行う
	return (0);
}
