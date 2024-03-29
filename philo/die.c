/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrettsc <mbrettsc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:29:52 by mbrettsc          #+#    #+#             */
/*   Updated: 2023/04/11 18:24:04 by mbrettsc         ###   ########.fr       */
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

void	die_check(t_table *table)
{
	int	i;

	if (table->number_of_philos == 1)
	{
		print(table->philos, DIE);
	}
	while (table->number_of_philos > 1)
	{
		i = -1;
		while (++i < table->number_of_philos)
		{
			pthread_mutex_lock(&table->is_dying);
			if ((current_time() - table->philos[i].last_eat)
				>= table->time_to_die)
			{
				print(table->philos + i, DIE);
				table->stop = 1;
				return ;
			}
			pthread_mutex_unlock(&table->is_dying);
		}
		if (must_eat_check(table))
			break ;
	}
	table->stop = 1;
}
