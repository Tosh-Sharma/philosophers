/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshsharma <toshsharma@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:28:24 by tsharma           #+#    #+#             */
/*   Updated: 2022/12/31 22:25:16 by toshsharma       ###   ########.fr       */
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
	free(i.eat_time);
}

int	printer(t_philo *i, long time, int j, char *action)
{
	pthread_mutex_lock(i->printer);
	printf("%ld ms %d %s\n", time, j + 1, action);
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
