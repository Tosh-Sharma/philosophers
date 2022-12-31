/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prechecks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshsharma <toshsharma@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:20:21 by toshsharma        #+#    #+#             */
/*   Updated: 2022/12/31 23:08:43 by toshsharma       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	should_we_stop(t_philo *i)
{
	int			counter;
	long long	time;

	time = get_time(&i->current_time);
	counter = 0;
	while (counter < i->monk_count)
	{
		if (i->eat_count[counter] == 0)
		{
			if (time - i->time_zero > i->time_to_die)
				return (-1);
		}
		else if (time - i->eat_time[counter] > i->time_to_die)
			return (-1);
		counter++;
	}
	return (0);
}

int	meals_done(t_philo *i, int j)
{
	if (i->eat_count[j] != i->run_count)
		return (0);
	return (1);
}
