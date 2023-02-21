/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrettsc <mbrettsc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 01:43:31 by mbrettsc          #+#    #+#             */
/*   Updated: 2023/02/20 18:47:02 by mbrettsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint64_t	current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

uint64_t	time_from_start(t_table *table)
{
	return (current_time() - table->time);
}

void	time_usleep(uint64_t micsec)
{
	uint64_t	current;

	current = current_time();
	while (micsec > current_time() - current)
		usleep(micsec * 10);
}
