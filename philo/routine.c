/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrettsc <mbrettsc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:42:54 by mbrettsc          #+#    #+#             */
/*   Updated: 2023/04/11 15:54:05 by mbrettsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->rfork);
	print(philo, TAKEN_FORK);
	pthread_mutex_lock(philo->lfork);
	print(philo, TAKEN_FORK);
	philo->num_eat++;
	print(philo, IS_EATING);
	time_usleep(philo->table->time_to_eat);
	philo->last_eat = current_time();
	pthread_mutex_unlock(philo->rfork);
	pthread_mutex_unlock(philo->lfork);
}

void	_sleep(t_philo *philo)
{
	print(philo, IS_SLEEPING);
	time_usleep(philo->table->time_to_sleep);
}

void	_think(t_philo *philo)
{
	print(philo, IS_THINKING);
}

void	*philo_routine(void *_philo)
{
	t_philo	*philo;

	philo = (t_philo *)_philo;
	if (philo->id % 2 == 0)
		time_usleep(10);
	while (!philo->table->stop)
	{
		_eat(philo);
		_sleep(philo);
		_think(philo);
	}
	return (NULL);
}
