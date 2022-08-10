/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 14:52:22 by wismith           #+#    #+#             */
/*   Updated: 2022/08/09 18:47:45 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

unsigned long	new_stamp(t_data *data, t_philo *p)
{
	pthread_mutex_lock(&data->time);
	gettimeofday(&p->tv, NULL);
	p->local.new_time = (p->tv.tv_sec * 1000) + (p->tv.tv_usec / 1000);
	p->local.res = p->local.new_time - p->init_time;
	pthread_mutex_unlock(&data->time);
	return (p->local.res);
}

// void	alarm_clock(unsigned long time, t_data *data, t_philo *p)
// {
// 	unsigned long	res;

// 	res = new_stamp(data, p);
// 	while ((new_stamp(data, p) - res) < time)
// 		;
// }

void	alarm_clock(unsigned long time, t_data *data, t_philo *p)
{
	unsigned long	current;
	unsigned long	init;
	struct timeval	tv;

	(void) p;
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
}
