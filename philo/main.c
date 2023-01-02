/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:16:00 by tsharma           #+#    #+#             */
/*   Updated: 2023/01/02 22:11:04 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		initialize(t_input i);
int		run_simulation(t_input i);
int		print_n_return(char *str, int ret_value);
void	*routine(void *input);
void	set_values(t_input i);

int	main(int argc, char **argv)
{
	t_input		i;
	int			flag;
	int			ret_val;
	int			did_anyone_die;

	did_anyone_die = 0;
	i.did_anyone_die = &did_anyone_die;
	if (argc == 5 || argc == 6)
	{
		flag = 0;
		if (argc == 5)
			i.run_count = 2147483647;
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
	int				j;

	i.eat_count = (int *)ft_calloc(sizeof(int), i.monk_count);
	j = -1;
	while (++j < i.monk_count)
		i.eat_count[j] = 0;
	i.monk = (pthread_t *)malloc(i.monk_count * (sizeof(pthread_t)));
	i.fork = (pthread_mutex_t *)malloc(i.monk_count * sizeof(pthread_mutex_t));
	i.printer = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	i.death = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	i.data = (t_philo *)malloc(sizeof(t_philo) * i.monk_count);
	i.eat_time = (long long *)ft_calloc(i.monk_count, sizeof(long long));
	if (!i.monk || !i.fork || !i.printer || !i.data)
		return (print_n_return("Could not allocate memory. Retry!\n", 1));
	j = -1;
	while (++j < i.monk_count)
		if (pthread_mutex_init(&i.fork[j], NULL) != 0)
			return (print_n_return("Could not init mutex. Retry!\n", 1));
	if (pthread_mutex_init(i.printer, NULL) != 0)
		return (print_n_return("Could not init mutex for printer. Retry\n", 1));
	if (pthread_mutex_init(i.death, NULL) != 0)
		return (print_n_return("Could not init mutex for death checker.\n", 1));
	set_values(i);
	run_simulation(i);
	return (1);
}

// We need to set all this information inside data so as to be able to pass
// it down to individual threads with their fork numbers and monk-number
void	set_values(t_input i)
{
	int	counter;

	counter = 0;
	while (counter < i.monk_count)
	{
		i.data[counter].monk_number = counter;
		if (counter == 0)
			i.data[counter].fork_left = i.monk_count - 1;
		else
			i.data[counter].fork_left = (counter - 1);
		i.data[counter].fork_right = counter;
		i.data[counter].monk_count = i.monk_count;
		i.data[counter].time_to_die = i.time_to_die;
		i.data[counter].time_to_eat = i.time_to_eat;
		i.data[counter].time_to_sleep = i.time_to_sleep;
		i.data[counter].run_count = i.run_count;
		i.data[counter].monk = i.monk;
		i.data[counter].fork = i.fork;
		i.data[counter].printer = i.printer;
		i.data[counter].eat_count = i.eat_count;
		i.data[counter].eat_time = i.eat_time;
		i.data[counter].death = i.death;
		i.data[counter].did_anyone_die = i.did_anyone_die;
		counter++;
	}
}

int	run_simulation(t_input i)
{
	int	j;

	gettimeofday(&i.current_time, NULL);
	i.time_zero = (i.current_time.tv_sec * 1000) + (i.current_time.tv_usec
			/ 1000);
	if (i.monk_count == 1)
		return (lonely_monk(&i));
	j = 0;
	while (j < i.monk_count)
	{
		i.data[j].time_zero = i.time_zero;
		pthread_create(&i.monk[j], NULL, &routine, &i.data[j]);
		usleep(1000 / i.monk_count);
		j++;
	}
	j = -1;
	while (++j < i.monk_count)
		pthread_join(i.monk[j], NULL);
	free_stuff(i);
	return (0);
}

void	*routine(void *input)
{
	t_philo	*i;

	i = (t_philo *)input;
	while (1)
	{
		if (meals_done(i, i->monk_number) == 1)
			break ;
		if (eat_sleep_repeat(i) == -1)
			break ;
	}
	return (NULL);
}
