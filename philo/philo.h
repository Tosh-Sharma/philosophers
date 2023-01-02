/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:44:11 by tsharma           #+#    #+#             */
/*   Updated: 2023/01/02 22:14:06 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

// Need this struct to ensure that every thread has all the information it needs
// to manipulate data further.
typedef struct s_philo
{
	int				monk_number;
	int				fork_left;
	int				fork_right;
	int				monk_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				run_count;
	long long		*eat_time;
	struct timeval	current_time;
	int				*did_anyone_die;
	int				*eat_count;
	long long		time_zero;
	pthread_t		*monk;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*printer;
	pthread_mutex_t	*death;
}	t_philo;

typedef struct s_input
{
	int				monk_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				run_count;
	int				*eat_count;
	int				*did_anyone_die;
	t_philo			*data;
	pthread_t		*monk;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*printer;
	pthread_mutex_t	*death;
	long long		*eat_time;
	long long		time_zero;
	struct timeval	current_time;
}	t_input;

int			ft_superatoi(const char *str, int *flag);
int			meals_done(t_philo *i, int j);
int			eat_sleep_repeat(t_philo *i);
int			should_we_stop(t_philo *i);
void		free_stuff(t_input i);
int			printer(t_philo *i, int j, char *action);
int			print_n_return(char *str, int ret_value);
void		*ft_calloc(size_t count, size_t size);
long long	get_time(struct timeval *holder);
int			lonely_monk(t_input *i);

#endif
