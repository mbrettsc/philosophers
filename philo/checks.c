/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrettsc <mbrettsc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:10:18 by mbrettsc          #+#    #+#             */
/*   Updated: 2023/02/16 01:07:31 by mbrettsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	must_eat_check(t_table *table)
{
	if (table->number_of_must_eat < 0)
		return (0);
	return (1);
}

int	checks(t_table *table, int ac, char **av)
{
	int i;

	i = 0;
	if (ac == 5 || ac == 6)
	{
		if (!must_eat_check(table))
			return(0);
		if (table->number_of_philos < 5)
		{
			printf("Number of philos must be at least 5\n");
			return (0);
		}
		if (!is_digit(av[1]) || !is_digit(av[2]) || !is_digit(av[3]) || !is_digit(av[4]) || (!is_digit(av[5]) && av))
		{
			printf("Arguments must be digit\n");
		 	return (0);
		}
	}
	else
		printf("Number of arguments must be 4 or 5\n");
	return (0);
}
