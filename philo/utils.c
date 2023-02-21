/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrettsc <mbrettsc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:56:01 by mbrettsc          #+#    #+#             */
/*   Updated: 2023/02/18 17:27:02 by mbrettsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

unsigned int	unsigned_atoi(char *str)
{
	int	i;
	int	res;

	res = 0;
	i = -1;
	if (!str || str < 0)
		return (0);
	while (*(str + ++i))
		res = (res * 10) + (*(str + i) - '0');
	return (res);
}

int	err_msg(char *msg)
{
	printf("%s", msg);
	return (0);
}

void	print(t_philo *philo,char *str)
{
	pthread_mutex_lock(&philo->table->is_printing);
	if (!philo->table->stop)
		printf("%llu %llu %s\n", time_from_start(philo->table), philo->id, str);
	pthread_mutex_unlock(&philo->table->is_printing);
}