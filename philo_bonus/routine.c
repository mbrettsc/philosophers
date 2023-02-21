/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrettsc <mbrettsc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:42:54 by mbrettsc          #+#    #+#             */
/*   Updated: 2023/02/21 20:51:31 by mbrettsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	_eat(t_philo *philo)
{
	sem_wait(philo->forks);
	print(philo, TAKEN_FORK);
	sem_wait(philo->forks);
	print(philo, TAKEN_FORK);
	print(philo, IS_EATING);
	time_usleep(philo->table->time_to_eat);
	philo->last_eat = current_time();
	philo->num_eat++;
	sem_post(philo->forks);
	sem_post(philo->forks);
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

		// time_usleep(10);
void	philo_routine(t_philo *philo)
{
	if (philo->id % 2 != 0)
		time_usleep(10);
	while (!philo->table->stop)
	{
		_eat(philo);
		_sleep(philo);
		_think(philo);
	}
}
