/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 14:52:22 by wismith           #+#    #+#             */
/*   Updated: 2022/08/11 15:59:40 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	init_time_(t_philo *p)
{
	gettimeofday(&p->tv, NULL);
	p->init_time = (p->tv.tv_sec * 1000)
		+ (p->tv.tv_usec / 1000);
}

unsigned long	new_stamp_lonely(t_philo *p)
{
	gettimeofday(&p->tv, NULL);
	p->local.new_time = (p->tv.tv_sec * 1000) + (p->tv.tv_usec / 1000);
	p->local.res = p->local.new_time - p->init_time;
	return (p->local.res);
}

unsigned long	new_stamp(t_philo *p)
{
	gettimeofday(&p->tv, NULL);
	p->local.new_time = (p->tv.tv_sec * 1000) + (p->tv.tv_usec / 1000);
	p->local.res = p->local.new_time - p->init_time;
	return (p->local.res);
}

void	alarm_clock(unsigned long time, t_philo *p)
{
	unsigned long	current;
	unsigned long	init;
	struct timeval	tv;

	(void) p;
	gettimeofday(&tv, NULL);
	init = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	current = init;
	while ((current - init) < time)
	{
		gettimeofday(&tv, NULL);
		current = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	}
}
