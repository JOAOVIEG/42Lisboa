/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:55:45 by joaocard          #+#    #+#             */
/*   Updated: 2024/04/19 14:27:41 by joaocard         ###   ########.fr       */
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

typedef enum e_state
{
	THINKING,
	NOT_THINKING,
	IS_SEATING
}	t_state;


typedef struct s_input_info
{
	int				number_of_philosophers;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start;
	int				nb_times_must_eat;
	bool			sim_end;
	pthread_mutex_t	sim_mutex;
	pthread_mutex_t	print_mutex;
}				t_input_info;

typedef	struct s_fork
{
	pthread_mutex_t	mutex;
}					t_fork;

typedef struct s_philo
{
	int				id;
	size_t				last_meal;
	t_state			state;
	t_input_info	*philo_info;
	t_fork			*own_fork;
	t_fork			*left_fork;
	pthread_t		thread;
	pthread_t		monitor_th;
}					t_philo;


t_input_info	*init_args(char **av);
t_fork			*get_forks(t_input_info *info);
t_philo			*philos_data(t_input_info *info, t_fork *forks);
void			init_dinner(t_philo *philos, t_input_info *info);
void			*routine(void *arg);
void			*monitor(void *arg);
void			take_forks(t_input_info *info, t_fork *forks);

long int		ft_atol(const char *av);
size_t			get_current_time(size_t start);
size_t			gettimeofday_ms(void);
#endif