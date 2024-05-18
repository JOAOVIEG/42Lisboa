/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:55:45 by joaocard          #+#    #+#             */
/*   Updated: 2024/05/18 13:33:43 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdbool.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>


typedef enum e_action
{
	EAT,
	THINK,
	SLEEP,
	TAKE_FORK_1,
	TAKE_FORK_2,
	DIE,
}			t_action;

typedef	struct s_fork
{
	pthread_mutex_t	lock;
}					t_fork;

typedef struct s_philo
{
	int					id;
	size_t				meals_count;
	size_t				last_meal;
	bool				full;
	pthread_t			thread_id;
	pthread_mutex_t		philo_lock;
	t_fork				*prio_fork;
	t_fork				*sec_fork;
	t_table				*table;
}						t_philo;

typedef struct s_table
{
	size_t			nbr_philos;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	size_t			nb_times_must_eat;
	size_t			start;
	size_t			nbr_threads_running;
	bool			dinner_end;
	bool			dinner_is_synchro;
	t_philo			*philos;
	t_fork			*forks;
	pthread_mutex_t dinner_lock;
	pthread_mutex_t	print_lock;
	pthread_t		monitor_th;
}					t_table;


/*parsing_and_init.c*/
int		philo_init(t_table *table);
int		parse_args(t_table *table, char **av);
int		init_table(t_table	*table);
void	give_forks(t_philo *philo, t_fork *forks, int pos);
size_t	ft_atol(const char *av);
/*philo_diner.c*/
int		dinner_init(t_table *table);
void	*dinner(void *arg);
void	sync_threads(t_table *table);
bool	get_dinner_state(pthread_mutex_t *mutex, bool is_sync);
void	set_last_meal(pthread_mutex_t *mutex, size_t	*to_set, size_t state);
void	set_dinner_state(pthread_mutex_t *mutex, bool *state, bool value);
void	de_sync_threads(t_philo *philo);
/*Time functions*/
long	gettimeofday_ms(void);
void	my_usleep(long time, t_table *table);
long	get_current_time(size_t start);
/*Action logs*/
void	print_status(t_philo *philo, t_action action);
char	*get_action(t_action action);
void	thinking_routine(t_philo *philo);
void	eating_routine(t_philo *philo);
void	use_forks(t_philo *philo);
void	disuse_forks(t_philo *philo);
#endif