/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrettsc <mbrettsc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:42:54 by mbrettsc          #+#    #+#             */
/*   Updated: 2023/02/24 18:07:11 by mbrettsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*die_check(void *obj)
{
	int	i;
	t_philo *philo;

	i = -1;
	philo = (t_philo *)obj;
	while (1)
	{
		if (philo->table->number_of_philos == 1
			|| (current_time() - philo->last_eat) >= philo->table->time_to_die)
		{
			philo->table->stop = 1;
			print_dead(philo, DIE);
		}
		if (must_eat_check(philo->table))
			philo->table->stop = 1;
		if (philo->table->stop == 1)
			exit(1);
		usleep(100);
		//usleep(10000);
	}
	return (NULL);
}

void	_eat(t_philo *philo)
{
	sem_wait(philo->forks);
	print(philo, TAKEN_FORK);
	sem_wait(philo->forks);
	print(philo, TAKEN_FORK);
	print(philo, IS_EATING);
	time_usleep(philo->table->time_to_eat);
	//die_check(philo);
	philo->last_eat = current_time();
	philo->num_eat++;
	sem_post(philo->forks);
	sem_post(philo->forks);
}

void	_sleep(t_philo *philo)
{
	print(philo, IS_SLEEPING);
	time_usleep(philo->table->time_to_sleep);
	//die_check(philo);
}

void	_think(t_philo *philo)
{
	print(philo, IS_THINKING);
}

void	philo_routine(t_philo *philo)
{
	if (philo->id % 2 == 0)
		usleep(250);
	//time_usleep(5);
	//die_check(philo);
	pthread_t a;
	pthread_create(&a, NULL, die_check, philo);
	while (1)
	{
		_eat(philo);
		_sleep(philo);
		_think(philo);
		usleep(8900);
	}
}
