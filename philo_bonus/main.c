/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrettsc <mbrettsc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:00:21 by mbrettsc          #+#    #+#             */
/*   Updated: 2023/04/11 18:31:49 by mbrettsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	end_ps(t_table *table)
{
	sem_close(table->is_dying);
	sem_close(table->is_printing);
	sem_close(table->forks);
	sem_unlink("./forks");
	sem_unlink("./printing");
	sem_unlink("./dying");
	free(table->philos);
	free(table);
}

int	main(int ac, char **av)
{
	t_table	*table;

	table = parse(ac, av);
	if (table != NULL)
	{
		start_forks(table);
		end_ps(table);
	}
	return (0);
}
