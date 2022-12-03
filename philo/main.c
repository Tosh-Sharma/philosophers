/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:16:00 by tsharma           #+#    #+#             */
/*   Updated: 2022/12/03 16:51:37 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	initialize(t_input i);
void	run_simulation(t_input i);

int	main(int argc, char **argv)
{
	t_input		i;

	if (argc != 4 || argc != 5)
	{
		printf("Number of input arguments is incorrect\n");
		return ;
	}
	else
	{
		if (argc == 4)
			i.run_count = 0;
		else
		{
			i.monk_count = ft_superatoi(argv[1]);
			i.time_to_die = ft_superatoi(argv[2]);
			i.time_to_eat = ft_superatoi(argv[3]);
			i.time_to_sleep = ft_superatoi(argv[4]);
			i.run_count = ft_superatoi(argv[5]);
		}
		initialize(i);
	}
	return (0);
}

void	initialize(t_input i)
{
	if (i.monk_count == NULL || i.monk_count <= 0
		|| i.time_to_die == NULL || i.time_to_die <= 0
		|| i.time_to_eat == NULL || i.time_to_eat <= 0
		|| i.time_to_sleep == NULL || i.time_to_sleep <= 0
		|| i.run_count == NULL || i.run_count < 0)
	{
		printf("Invalid input, fix it\n");
		return ;
	}
	else
		run_simulation(i);
}

void	run_simulation(t_input i)
{
}
