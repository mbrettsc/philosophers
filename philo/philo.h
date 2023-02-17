/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrettsc <mbrettsc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:00:49 by mbrettsc          #+#    #+#             */
/*   Updated: 2023/02/16 01:50:22 by mbrettsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

struct timeval	current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time);
}

typedef struct s_philo
{
	pthread_t		thread;
	pthread_mutex_t	*rfork;
	pthread_mutex_t	*lfork;
	int				id;
	int				sleeping;
	int				eating;
	int				last_eat;
}					t_philo;

typedef struct s_table
{
	pthread_mutex_t	*forks;
	t_philo			*philos;
	int				number_of_philos;
	int				time_to_sleep;
	int				time_to_eat;
	int				time_to_die;
	int				number_of_must_eat;
	int				*time;
	int				stop;
}					t_table;

unsigned int	unsigned_atoi(char *str);
t_table			*parse(int ac, char **av);
int				is_digit(char *str);
int				err_msg(char *msg);

#endif