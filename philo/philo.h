/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrettsc <mbrettsc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:00:49 by mbrettsc          #+#    #+#             */
/*   Updated: 2023/02/20 19:55:08 by mbrettsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

# define TAKEN_FORK "has taken a fork"
# define IS_EATING "is eating"
# define IS_SLEEPING "is sleeping"
# define IS_THINKING "is thinking"
# define DIE "died"

typedef struct s_philo
{
	pthread_t		thread;
	pthread_mutex_t		*rfork;
	pthread_mutex_t		*lfork;
	uint64_t				id;
	uint64_t		last_eat;
	uint64_t		last_sleep;
	int				sleeping;
	int				eating;
	int				num_eat;
	struct s_table	*table;
}					t_philo;

typedef struct s_table
{
	pthread_mutex_t	*forks;
	t_philo			*philos;
	uint64_t		time;
	int				number_of_philos;
	int				time_to_sleep;
	int				time_to_eat;
	uint64_t				time_to_die;
	int				number_of_must_eat;
	int				stop;
	pthread_mutex_t is_dying;
	pthread_mutex_t is_printing;
}					t_table;

unsigned int	unsigned_atoi(char *str);
t_table			*parse(int ac, char **av);
uint64_t		current_time(void);
int				is_digit(char *str);
int				err_msg(char *msg);
void			start_threads(t_table *table);
void			*philo_routine(void *param);
void			die_check(t_table *table);
void			print(t_philo *philo,char *str);
uint64_t		time_from_start(t_table *table);
void			time_usleep(uint64_t micsec);

#endif