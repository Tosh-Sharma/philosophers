/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subroutines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:02:53 by tsharma           #+#    #+#             */
/*   Updated: 2023/01/16 15:31:14 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	lonely_monk(t_input *i)
{
	printf("0 ms 1 has taken a fork\n");
	printf("%d ms 1 has died\n", i->time_to_die);
	return (0);
}

int	accurate_usleep(t_philo *i, int sleep_in_msec)
{
	struct timeval	current_time;
	long			initial_time;
	long			final_time;

	gettimeofday(&current_time, NULL);
	initial_time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	final_time = initial_time + sleep_in_msec;
	while (initial_time < final_time)
	{
		usleep(100);
		if (should_we_stop(i) == -1)
		{
			pthread_mutex_unlock(&i->fork[i->fork_left]);
			pthread_mutex_unlock(&i->fork[i->fork_right]);
			return (-1);
		}
		gettimeofday(&current_time, NULL);
		initial_time = (current_time.tv_sec * 1000) + (current_time.tv_usec
				/ 1000);
	}
	return (0);
}

long long	get_time(struct timeval *holder)
{
	long long	time;

	gettimeofday(holder, NULL);
	time = (holder->tv_sec * 1000) + (holder->tv_usec / 1000);
	return (time);
}

int	eat_sleep_repeat(t_philo *i)
{
	long long	time;

	pthread_mutex_lock(&i->fork[i->fork_left]);
	printer(i, i->monk_number, "took a fork");
	pthread_mutex_lock(&i->fork[i->fork_right]);
	printer(i, i->monk_number, "took a fork");
	time = get_time(&i->current_time);
	pthread_mutex_lock(i->checker);
	i->eat_time[i->monk_number] = time;
	pthread_mutex_unlock(i->checker);
	printer(i, i->monk_number, "is eating");
	if (accurate_usleep(i, i->time_to_eat) == -1)
		return (-1);
	pthread_mutex_lock(i->checker);
	i->eat_count[i->monk_number]++;
	pthread_mutex_unlock(i->checker);
	pthread_mutex_unlock(&i->fork[i->fork_left]);
	pthread_mutex_unlock(&i->fork[i->fork_right]);
	printer(i, i->monk_number, "is sleeping");
	if (accurate_usleep(i, i->time_to_sleep) == -1)
		return (-1);
	printer(i, i->monk_number, "is thinking");
	return (0);
}
