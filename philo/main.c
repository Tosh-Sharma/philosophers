/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:16:00 by tsharma           #+#    #+#             */
/*   Updated: 2022/12/05 21:00:58 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		initialize(t_input i);
int		run_simulation_even(t_input i);
int		print_n_return(char *str, int ret_value);
void	routine(t_input i);

int	main(int argc, char **argv)
{
	t_input		i;
	int			flag;
	int			ret_val;

	if (argc == 5 || argc == 6)
	{
		flag = 0;
		if (argc == 5)
			i.run_count = 0;
		else
			i.run_count = ft_superatoi(argv[5], &flag);
		i.monk_count = ft_superatoi(argv[1], &flag);
		i.time_to_die = ft_superatoi(argv[2], &flag);
		i.time_to_eat = ft_superatoi(argv[3], &flag);
		i.time_to_sleep = ft_superatoi(argv[4], &flag);
		if (flag == 1 || i.monk_count > 200)
			return (print_n_return("Incorrect input\n", 128));
		ret_val = initialize(i);
		return (ret_val);
	}
	return (print_n_return("Number of input arguments is incorrect\n", 128));
}

int	initialize(t_input i)
{
	struct timeval	current_time;
	int				j;

	i.eat_count = (int *)malloc(sizeof(int) * i.monk_count);
	j = -1;
	while (++j < i.monk_count)
		i.eat_count[j] = 0;
	i.monk = (pthread_t *)malloc(i.monk_count * (sizeof(pthread_t)));
	i.fork = (pthread_mutex_t *)malloc(i.monk_count * sizeof(pthread_mutex_t));
	if (!i.monk || !i.fork)
		return (print_n_return("Could not allocate memory. Retry!\n", 1));
	j = -1;
	while (++j < i.monk_count)
		if (pthread_mutex_init(&i.fork[j], NULL) != 0)
			return (print_n_return("Could not init mutex. Retry!\n", 1));
	if (i.monk_count % 2 == 0)
		return (run_simulation_even(i));
	else
		return (run_simulation_odd(i));
	return (1);
}

// gettimeofday(&current_time, NULL);
// printf("seconds : %ld\nmicro seconds : %d", current_time.tv_sec,
// 	current_time.tv_usec);
// TODO: Need a death tracking thread.
int	run_simulation_even(t_input i)
{
	int	j;

	j = 0;
	gettimeofday(&i.current_time, NULL);
	i.time_zero = i.current_time.tv_sec;
	while (j < i.monk_count)
	{
		i.j = j;
		pthread_create(i.monk[j], NULL, &routine, &i);
		j += 2;
	}
	usleep(10000);
	j = 1;
	while (j < i.monk_count)
	{
		i.j = j;
		pthread_create(i.monk[j], NULL, &routine, &i);
		j += 2;
	}
	j = -1;
	while (++j < i.monk_count)
		pthread_join(i.monk[j], NULL);
	free_stuff(i);
	return (0);
}

int	print_n_return(char *str, int ret_value)
{
	printf("%s", str);
	return (ret_value);
}

void	routine(t_input i)
{
	while (1)
	{
		if (time_to_end(i) == 1)
			break ;
		take_forks(i, i.j);
		eating_time(i, i.j);
		return_forks_n_sleep(i, i.j);
	}
}
