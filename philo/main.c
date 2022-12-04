/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:16:00 by tsharma           #+#    #+#             */
/*   Updated: 2022/12/04 15:48:09 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	initialize(t_input i);
int	run_simulation(t_input i);

int	main(int argc, char **argv)
{
	t_input		i;
	int			flag;

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
		{
			printf("Incorrect input\n");
			return (128);
		}
		return (initialize(i));
	}
	printf("Number of input arguments is incorrect\n");
	return (128);
}

int	initialize(t_input i)
{
	return (run_simulation(i));
}

int	run_simulation(t_input i)
{
	printf("Inputs given are as follows:\n");
	printf("%d %d %d %d %d", i.monk_count, i.time_to_die, i.time_to_eat,
		i.time_to_sleep, i.run_count);
	return (0);
}
