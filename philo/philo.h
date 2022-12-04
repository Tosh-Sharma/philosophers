/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:44:11 by tsharma           #+#    #+#             */
/*   Updated: 2022/12/04 16:04:27 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_input
{
	int	monk_count;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	run_count;
}	t_input;

int	ft_superatoi(const char *str, int *flag);

#endif
