/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 15:50:42 by wismith           #+#    #+#             */
/*   Updated: 2022/08/07 23:26:53 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	if_must_eat_(t_philo *p)
{
	if (p->local.must_eat)
		p->local.me_--;
}

int	truth_(pthread_mutex_t *mu, int fork)
{
	int	i;

	i = 0;
	pthread_mutex_lock(mu);
	if (!fork)
	{
		pthread_mutex_unlock(mu);
		i = 1;
	}
	else
		pthread_mutex_unlock(mu);
	return (i);
}

void	left_fork_(t_philo *p, t_data *data)
{
	pthread_mutex_lock(&data->fork_m[p->l_id]);
	data->forks[p->l_id] = 1;
	pthread_mutex_unlock(&data->fork_m[p->l_id]);
	p->last_time_eat = new_stamp(data);
	print_(p, "has taken a fork");
	if_must_eat_(p);
	alarm_clock(print_(p, "is eating"), data);
	pthread_mutex_lock(&data->fork_m[p->l_id]);
	data->forks[p->l_id] = 0;
	pthread_mutex_unlock(&data->fork_m[p->l_id]);
}

void	try_eat_(t_philo *p, t_data *data)
{
	int	r;
	int	l;

	r = 0;
	l = 0;
	while (!r || !l)
	{
		r = truth_(&data->fork_m[p->r_id], data->forks[p->r_id]);
		l = truth_(&data->fork_m[p->l_id], data->forks[p->l_id]);
	}
	pthread_mutex_lock(&data->fork_m[p->r_id]);
	data->forks[p->r_id] = 1;
	pthread_mutex_unlock(&data->fork_m[p->r_id]);
	print_(p, "has taken a fork");
	left_fork_(p, data);
	pthread_mutex_lock(&data->fork_m[p->r_id]);
	data->forks[p->r_id] = 0;
	pthread_mutex_unlock(&data->fork_m[p->r_id]);
}
