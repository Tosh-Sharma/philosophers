/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:16:00 by tsharma           #+#    #+#             */
/*   Updated: 2022/12/04 19:44:48 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	initialize(t_input i);
int	run_simulation(t_input i);
int	print_n_return(char *str, int ret_value);

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
		if (flag == 1)
			return (print_n_return("Incorrect input\n", 128));
		ret_val = initialize(i);
		system("leaks philo");
		return (ret_val);
	}
	return (print_n_return("Number of input arguments is incorrect\n", 128));
}

int	initialize(t_input i)
{
	pthread_t		*monk;
	pthread_mutex_t	*fork;

	monk = (pthread_t *)malloc(i.monk_count * (sizeof(pthread_t)));
	fork = (pthread_mutex_t *)malloc(i.monk_count * (sizeof(pthread_mutex_t)));
	if (!monk || !fork)
	{
		printf("Could not allocate memory correctly. Retry!\n");
		return (1);
	}
	return (run_simulation(i));
}

// TODO: Below code is currently all experimental and needs to be worked on.
int	run_simulation(t_input i)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	printf("seconds : %ld\nmicro seconds : %d", current_time.tv_sec,
		current_time.tv_usec);
	return (0);
}

int	print_n_return(char *str, int ret_value)
{
	printf("%s", str);
	return (ret_value);
}
