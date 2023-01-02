/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:28:24 by tsharma           #+#    #+#             */
/*   Updated: 2023/01/02 21:53:43 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_stuff(t_input i)
{
	free(i.monk);
	free(i.fork);
	free(i.printer);
	free(i.eat_count);
	free(i.data);
	free(i.death);
	free(i.eat_time);
}

int	printer(t_philo *i, int j, char *action)
{
	long long	time;

	time = get_time(&i->current_time);
	pthread_mutex_lock(i->printer);
	printf("%lld ms %d %s\n", time - i->time_zero, j + 1, action);
	pthread_mutex_unlock(i->printer);
	return (1);
}

int	print_n_return(char *str, int ret_value)
{
	printf("%s", str);
	return (ret_value);
}

void	ft_bzero(void *b, size_t len)
{
	size_t			i;
	unsigned char	*d;

	i = 0;
	d = b;
	while (i < len)
	{
		d[i] = (unsigned char)0;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;

	if (size && ((size_t) - 1 / size) < count)
		return (NULL);
	res = malloc(count * size);
	if (!res)
		return (NULL);
	ft_bzero(res, count * size);
	return (res);
}
