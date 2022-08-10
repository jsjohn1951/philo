/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 12:15:52 by wismith           #+#    #+#             */
/*   Updated: 2022/08/10 11:10:46 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	death_(t_data *data, t_philo *p)
{
	p->current_time = new_stamp(data, p);
	if (p->current_time - p->last_time_eat
		>= (unsigned long) p->local.td_ + 9)
	{
		print_(p, "died");
		pthread_mutex_lock(&data->death);
		data->deaths = 1;
		pthread_mutex_unlock(&data->death);
		return (1);
	}
	return (0);
}

void	feeder(t_data *data, t_philo *p, int *i)
{
	try_eat_(p, data);
	if (!p->eatin)
		*i = 0;
}

void	life_(t_data *data, t_philo *philo, int *i)
{
	int	deaths;

	deaths = 0;
	pthread_mutex_lock(&data->death);
	if (data->deaths)
		deaths = 1;
	pthread_mutex_unlock(&data->death);
	if (deaths || death_(data, philo))
	{
		*i = 4;
		return ;
	}
	if (*i == 1)
		feeder(data, philo, i);
	if (*i == 2)
		alarm_clock(print_(philo, "is sleeping"), data, philo);
	if (*i == 3)
	{
		philo->eatin = 0;
		*i = print_(philo, "is thinking");
	}
}
