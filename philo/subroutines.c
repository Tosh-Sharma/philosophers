/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subroutines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:02:53 by tsharma           #+#    #+#             */
/*   Updated: 2022/12/08 17:10:58 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	time_to_end(t_input *i)
{
	int	k;

	k = 0;
	while (k < i->monk_count)
	{
		if (i->eat_count[k] != i->run_count)
			return (0);
		k++;
	}
	return (1);
}

void	take_forks(t_input *i, int j)
{
	gettimeofday(&i->current_time, NULL);
	pthread_mutex_lock(&i->fork[j % (i->monk_count - 1)]);
	printf("%ld ms %d took a fork\n", i->current_time.tv_sec - i->time_zero,
		j + 1);
	pthread_mutex_lock(&i->fork[(j + 1) % (i->monk_count - 1)]);
	gettimeofday(&i->current_time, NULL);
	printf("%ld ms %d took a fork\n", i->current_time.tv_sec - i->time_zero,
		j + 1);
}

void	eating_time(t_input *i, int j)
{
	gettimeofday(&i->current_time, NULL);
	printf("%ld ms %d is eating\n", i->current_time.tv_sec - i->time_zero,
		j + 1);
	usleep(i->time_to_eat * 1000);
}

void	return_forks_n_sleep(t_input *i, int j)
{
	pthread_mutex_unlock(&i->fork[j % i->monk_count]);
	pthread_mutex_unlock(&i->fork[(j + 1) % i->monk_count]);
	gettimeofday(&i->current_time, NULL);
	printf("%ld ms %d is sleeping\n", i->current_time.tv_sec - i->time_zero,
		j + 1);
	usleep(i->time_to_sleep * 1000);
	printf("%ld ms %d is thinking\n", (i->time_to_sleep + i->current_time.tv_sec)
		- i->time_zero, j + 1);
}
