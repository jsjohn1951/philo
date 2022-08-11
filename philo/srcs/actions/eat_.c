/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 15:50:42 by wismith           #+#    #+#             */
/*   Updated: 2022/08/11 17:11:41 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	if_must_eat_(t_philo *p)
{
	if (p->local.must_eat)
		p->local.me_--;
}

int	truth_(pthread_mutex_t *mu, int fork, t_data *data, t_philo *p)
{
	p->local.rtn = 0;
	pthread_mutex_lock(mu);
	if (!data->forks[fork])
		p->local.rtn = 1;
	pthread_mutex_unlock(mu);
	return (p->local.rtn);
}

void	left_fork_(t_philo *p, t_data *data)
{
	if (truth_(&data->fork_m[p->l_id], p->l_id, data, p))
	{
		pthread_mutex_lock(&data->fork_m[p->l_id]);
		data->forks[p->l_id] = 1;
		pthread_mutex_unlock(&data->fork_m[p->l_id]);
		print_(p, "has taken a fork");
		p->eatin = 1;
		if_must_eat_(p);
		p->last_time_eat = new_stamp(p);
		alarm_clock(print_(p, "is eating"), data, p);
		pthread_mutex_lock(&data->fork_m[p->l_id]);
		data->forks[p->l_id] = 0;
		pthread_mutex_unlock(&data->fork_m[p->l_id]);
	}
}

void	try_eat_(t_philo *p, t_data *data)
{
	p->local.r_ = truth_(&data->fork_m[p->r_id], p->r_id, data, p);
	p->local.l_ = truth_(&data->fork_m[p->l_id], p->l_id, data, p);
	if (p->local.r_ && p->local.l_)
	{
		pthread_mutex_lock(&data->fork_m[p->r_id]);
		data->forks[p->r_id] = 1;
		pthread_mutex_unlock(&data->fork_m[p->r_id]);
		print_(p, "has taken a fork");
		left_fork_(p, data);
		pthread_mutex_lock(&data->fork_m[p->r_id]);
		data->forks[p->r_id] = 0;
		pthread_mutex_unlock(&data->fork_m[p->r_id]);
	}
}
