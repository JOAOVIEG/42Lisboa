/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:55:45 by joaocard          #+#    #+#             */
/*   Updated: 2024/02/22 15:02:18 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

typedef enum e_state
{
	THINKING,
	EATING,
	SLEEPING,
	DIED
}	t_state;


typedef struct s_philo_data
{
	int			number_of_philosophers;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			nb_times_must_eat;
}				t_philo_data;

typedef struct s_philo
{
	int				id;
	int				last_meal;
	t_philo_data	*data;
	t_state			state;
	t_fork			*own_fork;
	t_fork			*left_fork;
	pthread_t		thread;
}					t_philo;

typedef	struct s_fork
{
	pthread_mutex_t	mutex;
}					t_fork;

#endif