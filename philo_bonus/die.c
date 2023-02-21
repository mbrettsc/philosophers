/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrettsc <mbrettsc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:29:52 by mbrettsc          #+#    #+#             */
/*   Updated: 2023/02/21 20:25:08 by mbrettsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	must_eat_check(t_table *table)
{
	int	i;

	if (table->number_of_must_eat < 0)
		return (0);
	i = -1;
	while (++i < table->number_of_philos)
	{
		if (table->philos[i].num_eat < table->number_of_must_eat)
			return (0);
	}
	return (1);
}

void	killer(t_table *table)
{
	int i;

	i = -1;
	while (++i < table->number_of_philos)
		kill(table->philos[i].child, SIGKILL);
}

void	die_check(t_table *table)
{
	int	i;

	if (table->number_of_philos == 1)
		print(table->philos, DIE);
	while (table->number_of_philos > 1)
	{
		i = -1;
		while (++i < table->number_of_philos)
		{
			sem_wait(table->is_dying);
			if ((current_time() - table->philos[i].last_eat)
				>= table->time_to_die)
			{
				print(table->philos + i, DIE);
				killer(table);
				table->stop = 1;
				return ;
			}
			sem_post(table->is_dying);
		}
		if (must_eat_check(table))
			break ;
	}
	table->stop = 1;
	killer(table);
}
