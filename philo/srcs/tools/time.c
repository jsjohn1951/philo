/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 14:52:22 by wismith           #+#    #+#             */
/*   Updated: 2022/08/08 20:47:35 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

unsigned long	new_stamp(t_data *data, t_philo *p)
{
	pthread_mutex_lock(&data->time);
	gettimeofday(&data->tv, NULL);
	pthread_mutex_unlock(&data->time);
	p->local.new_time = (data->tv.tv_sec * 1000) + (data->tv.tv_usec / 1000);
	p->local.res = p->local.new_time - data->init_time;
	return (p->local.res);
}

void	alarm_clock(unsigned long time, t_data *data, t_philo *p)
{
	unsigned long	res;

	res = new_stamp(data, p);
	while ((new_stamp(data, p) - res) < time)
		;
}

/* void	alarm_clock(unsigned long time, t_data *data)
{
	unsigned long	current;
	unsigned long	init;
	struct timeval	tv;

	pthread_mutex_lock(&data->time);
	gettimeofday(&tv, NULL);
	init = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	pthread_mutex_unlock(&data->time);
	current = init;
	while ((current - init) < time)
	{
		pthread_mutex_lock(&data->time);
		gettimeofday(&tv, NULL);
		current = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
		pthread_mutex_unlock(&data->time);
	}
} */
