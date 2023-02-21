/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrettsc <mbrettsc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:40:12 by mbrettsc          #+#    #+#             */
/*   Updated: 2023/02/21 20:22:40 by mbrettsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_init(t_philo *philo, t_table *table, int i)
{
	philo->id = i + 1;
	philo->table = table;
	philo->num_eat = 0;
	philo->last_eat = current_time();
}

void	start_forks(t_table *table)
{
	int	i;

	sem_unlink("./forks");
	sem_unlink("./printing");
	sem_unlink("./dying");
	table->philos->forks = sem_open("./forks", O_CREAT,S_IRWXG, 0666, table->number_of_philos);
	table->is_printing = sem_open("./forks", O_CREAT,S_IRWXG, 0666, 1);
	table->is_dying = sem_open("./dying", O_CREAT,S_IRWXG, 0666, 1);
	i = -1;
	while (++i < table->number_of_philos)
		philo_init(&table->philos[i], table, i);
	i = -1;
	while (++i < table->number_of_philos)
	{
		table->philos[i].child = fork();
		if (table->philos[i].child < 0)
			print(table->philos, "Fork Init Error\n");
		else if (table->philos[i].child == 0)
		{
			philo_routine(table->philos + i);
		}
	}
	die_check(table);
}
