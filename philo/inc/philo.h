/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:55:45 by joaocard          #+#    #+#             */
/*   Updated: 2024/04/25 15:17:42 by joaocard         ###   ########.fr       */
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
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			nb_times_must_eat;
	size_t			start;
	bool			dinner_end;
	bool			dinner_is_synchro;
	t_philo			*philos;
	t_fork			*forks;
	pthread_mutex_t dinner_lock;
	pthread_mutex_t	print_lock;
	pthread_t		monitor_th;
}					t_table;


int	parse_args(t_table *table, char **av);
size_t	ft_atol(const char *av);
int		init_table(t_table	*table);
void	give_forks(t_philo *philo, t_fork *forks, int pos);
// t_philo			*philos_data(t_input_info *info, t_fork *forks);
// void			init_dinner(t_philo *philos, t_input_info *info);
// void			*routine(void *arg);
// void			*monitor(void *arg);
// void			take_forks(t_input_info *info, t_fork *forks);

// size_t			get_current_time(size_t start);
// size_t			gettimeofday_ms(void);
#endif