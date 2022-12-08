/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:44:11 by tsharma           #+#    #+#             */
/*   Updated: 2022/12/08 14:49:23 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_input
{
	int				j;
	int				monk_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				run_count;
	struct timeval	current_time;
	pthread_t		*monk;
	pthread_mutex_t	*fork;
	int				*eat_count;
	time_t			time_zero;
}	t_input;

int		ft_superatoi(const char *str, int *flag);
int		time_to_end(t_input *i);
void	take_forks(t_input *i, int j);
void	eating_time(t_input *i, int j);
void	return_forks_n_sleep(t_input *i, int j);

int		run_simulation_odd(t_input i);

void	free_stuff(t_input i);

#endif
