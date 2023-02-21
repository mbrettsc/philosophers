/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrettsc <mbrettsc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:40:12 by mbrettsc          #+#    #+#             */
/*   Updated: 2023/02/20 15:37:47 by mbrettsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_init(t_philo *philo, t_table *table, int i)
{
	philo->id = i + 1;
	philo->table = table;
	philo->eating = 0;
	philo->num_eat = 0;
	philo->sleeping = 0;
	philo->last_eat = current_time();
	pthread_mutex_init(table->forks + i, NULL);
}

void	fork_init(t_philo *philo, t_table *table, int i)
{
	if (i - 1 < 0)
		philo->rfork = table->forks + (table->number_of_philos - 1);
	else
		philo->rfork = table->forks + (i - 1);
	philo->lfork = table->forks + i;
}

void	start_threads(t_table *table)
{
	int i;
	
	i = -1;
	pthread_mutex_init(&table->is_dying, NULL);
	pthread_mutex_init(&table->is_printing, NULL);
	while (++i < table->number_of_philos)
		philo_init(table->philos + i, table, i);
	i = -1;
	while (++i < table->number_of_philos)
		fork_init(table->philos + i, table, i);
	i = -1;
	while (++i < table->number_of_philos)
		pthread_create(&table->philos[i].thread, NULL, philo_routine, table->philos + i);
	die_check(table);
}
