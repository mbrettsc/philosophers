/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrettsc <mbrettsc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:00:21 by mbrettsc          #+#    #+#             */
/*   Updated: 2023/04/11 18:31:38 by mbrettsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	end_threads(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->number_of_philos)
	{
		if (table->number_of_philos == 1)
			pthread_detach(table->philos[i].thread);
		pthread_join(table->philos[i].thread, NULL);
	}
	pthread_mutex_destroy(&table->is_dying);
	pthread_mutex_destroy(&table->is_printing);
	i = -1;
	while (++i < table->number_of_philos)
		pthread_mutex_destroy(&table->forks[i]);
	free(table->forks);
	free(table->philos);
	free(table);
}

int	main(int ac, char **av)
{
	t_table	*table;

	table = parse(ac, av);
	if (table != NULL)
	{
		start_threads(table);
		end_threads(table);
	}
	return (0);
}
