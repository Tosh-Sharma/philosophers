/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:28:24 by tsharma           #+#    #+#             */
/*   Updated: 2022/12/08 14:53:49 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	run_simulation_odd(t_input i)
{
	(void)i;
	return (0);
}

void	free_stuff(t_input i)
{
	free(i.monk);
	free(i.fork);
	free(i.eat_count);
}
