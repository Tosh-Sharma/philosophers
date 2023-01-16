/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prechecks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:20:21 by toshsharma        #+#    #+#             */
/*   Updated: 2023/01/16 16:05:31 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_death(long long time, int monk_number, t_philo *i)
{
	pthread_mutex_lock(i->death);
	if (*i->did_anyone_die == 0)
	{
		printf("%lld ms %d died\n", time, monk_number);
		*i->did_anyone_die = 1;
	}
	pthread_mutex_unlock(i->death);
	pthread_mutex_unlock(i->checker);
	return (-1);
}

// That double if cannot be reduced to a single if. That's a fact.
// Try all sorts of test cases out in case you have doubts.
int	should_we_stop(t_philo *i)
{
	int			counter;
	long long	time;

	time = get_time(&i->current_time);
	counter = 0;
	pthread_mutex_lock(i->checker);
	while (counter < i->monk_count)
	{
		if (i->eat_count[counter] == 0)
		{
			if (time - i->time_zero > i->time_to_die)
				return (print_death(time - i->time_zero, counter + 1, i));
		}
		else if (time - i->eat_time[counter] > i->time_to_die)
			return (print_death(time - i->time_zero, counter + 1, i));
		counter++;
	}
	pthread_mutex_unlock(i->checker);
	return (0);
}

int	meals_done(t_philo *i, int j)
{
	if (i->eat_count[j] != i->run_count)
		return (0);
	return (1);
}
