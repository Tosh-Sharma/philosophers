/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subroutines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshsharma <toshsharma@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:02:53 by tsharma           #+#    #+#             */
/*   Updated: 2022/12/14 13:00:02 by toshsharma       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	accurate_usleep(int	sleep_in_msec)
{
	struct timeval	current_time;
	struct timeval	time_to_wake_up;

	gettimeofday(&current_time, NULL);
	time_to_wake_up.tv_sec = current_time.tv_sec;
	time_to_wake_up.tv_usec = current_time.tv_usec + (sleep_in_msec * 1000);
	while (time_to_wake_up.tv_sec == current_time.tv_sec
		&& current_time.tv_usec < time_to_wake_up.tv_usec)
	{
		gettimeofday(&current_time, NULL);
		usleep(100);
	}
}

int	meal_done(t_input *i)
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
	accurate_usleep(i->time_to_eat * 1000);
}

void	return_forks_n_sleep(t_input *i, int j)
{
	pthread_mutex_unlock(&i->fork[j % (i->monk_count - 1)]);
	pthread_mutex_unlock(&i->fork[(j + 1) % (i->monk_count - 1)]);
	gettimeofday(&i->current_time, NULL);
	printf("%ld ms %d is sleeping\n", i->current_time.tv_sec - i->time_zero,
		j + 1);
	accurate_usleep(i->time_to_sleep * 1000);
	printf("%ld ms %d is thinking\n", (i->time_to_sleep + i->current_time.tv_sec)
		- i->time_zero, j + 1);
}
