/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:56:38 by wismith           #+#    #+#             */
/*   Updated: 2022/08/04 22:21:41 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	init_time_(t_data *data)
{
	gettimeofday(&data->tv, NULL);
	data->init_time = (data->tv.tv_sec * 1000)
		+ (data->tv.tv_usec / 1000);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

int	num_cmp(int num, int cmp, t_err *err)
{
	if (num > cmp)
		err->err = 2;
	return (num);
}

void	ft_put_(int fd, char *s)
{
	write(fd, s, ft_strlen(s));
}
